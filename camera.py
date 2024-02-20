import asyncio
import uvicorn
import struct
from utils import bytes_to_ip
from dialog import create_response, parse_query, og_responses
import time
import pickle
import copy

from fastapi import FastAPI
from contextlib import asynccontextmanager

from starlette.requests import Request

#expno = 145

class EchoServerProtocol(asyncio.DatagramProtocol):
    def connection_made(self, transport):
        self.transport = transport
        self.data_port = None
        self.sequence = 0
        self.subsequence = 0
        self.pending_acks = []
        self.packed_camip = struct.pack(">IBBBB", 0x83, 192,168,2,220)
        self.imbuf = b'\x00'*int(1024*1024*1.5)
        self.impos = None
        self.responses = {}

    async def _send_frame(self):
        print("backougnd sending frame")
        time.sleep(0.1)
        imbuf = b'\x00'*int(1024*1024*1.5)
        pklen = 1400
        for i in range(0,len(imbuf), pklen):
            payload = imbuf[i:i+pklen]
            self.sequence += 1
            self.subsequence += 1
            stream = 0x4453
            if i+pklen >= len(imbuf):
                # last packet
                stream = 0x4445
                self.pending_acks.append((self.sequence + 1, self.subsequence + 1))
            elif self.subsequence%128 == 0:
                self.pending_acks.append((self.sequence + 1, self.subsequence + 1))
            header = struct.pack(">IHHHH", self.sequence, stream, self.subsequence, len(payload), 0x0)
            self.transport.sendto(header+payload, (self.data_ip, self.data_port))
            print("sent", self.sequence, stream, self.subsequence, len(payload))

        print("sendimg done")

    def _make_datagram(self, stream, sub, payload):
        header = struct.pack(">IHHHH", self.sequence, stream, sub, len(payload), 0x0)
        return header+payload

    def _send_ack(self, seq, payload=b''):
        print("acking", seq+1, payload.hex(), type(payload))
        header = struct.pack(">IHHHH", seq+1, 0x5252, 0, len(payload), 0x0)
        self.transport.sendto(header+payload, (self.data_ip, self.data_port))

    def datagram_received(self, data, addr):
        if len(data) < 12:
            print("invlid packet")
            return
        seq, stream, sub, length, flag = struct.unpack(">IHHHH", data[:12])
        payload = data[12:12 + length]
        print("flag is", hex(flag))
        if data[12 + length:] != b'\0' * len(data[12 + length:]):
            print("========remainder not zero", data[12 + length:].hex())
            return

        if seq == 0x01000000 and stream == 0x4351:
            # dicover message
            assert flag == 0
            print("discover", seq, hex(stream), sub, length)
            discover_port = struct.unpack(">H", payload[4:6])[0]
            print("IP, port ", bytes_to_ip(payload[0:4]), discover_port)
            discover_ip = bytes_to_ip(payload[0:4])
            ansp = self.packed_camip
            self.sequence = seq
            resp = self._make_datagram(0x5252, 0, ansp)
            self.transport.sendto(resp, (discover_ip, discover_port))
        elif seq == 0x0 and stream == 0x4351:
            print("init", seq, hex(stream), sub, length)
            assert flag == 0

            self.sequence = 0
            self.subsequence = 0
            self.pending_acks = []
            self.impos = None

            global expno
            #expno += 1
            self.responses = copy.copy(og_responses)
            #keys = list(self.responses.keys())
            #self.responses[keys[expno//3]] = [x if i!=expno%3 else x+1 for i,x in enumerate(self.responses[keys[expno//3]])]
            #with open(f"dump/{expno}.pkl","wb") as f:
            #    pickle.dump(self.responses, f)


            self.data_port = struct.unpack(">H", payload[4:6])[0]
            self.data_ip = bytes_to_ip(payload[0:4])
            print("IP, port ", bytes_to_ip(payload[0:4]), self.data_port)
            pl = self.packed_camip
            self.sequence = seq
            resp = self._make_datagram(0x5252, 0, pl)
            self.transport.sendto(resp, (self.data_ip, self.data_port))
        elif seq == 0x0 and stream == 0x4345:
            print("initial parameters", seq, hex(stream), sub, length, payload.hex())
            assert flag == 0
            self._send_ack(seq, payload=payload)
        elif stream == 0x4445:
            assert sub == 1
            self._send_ack(seq)
            print("received dialog query", seq, hex(stream), sub, length, payload.hex())
            self.sequence += 1
            regquery = parse_query(payload)
            reply = create_response(*regquery, self.responses)
            resp = self._make_datagram(stream, 1, reply)
            print("sent reply", resp.hex())
            self.pending_acks.append((self.sequence + 1, 1))

            if payload == b'@\xb7\x00\x01\x00\x00\x00\x00\x00\x01\x00\x00':
                self.impos = 0
            self.transport.sendto(resp, (self.data_ip, self.data_port))
                #asyncio.create_task(self._send_frame())

        elif stream == 0x5252 and (seq, sub) in self.pending_acks:
            self.pending_acks.remove((seq, sub))
            print("got ack with flag", hex(flag))

            # is there sth to send out?
            if self.impos is not None:
                pklen = 1400
                for i in range(128):
                    payload = self.imbuf[self.impos:self.impos+pklen]
                    self.sequence += 1
                    self.subsequence += 1
                    self.impos += pklen
                    stream = 0x4453
                    if self.impos >= len(self.imbuf):
                        # last packet
                        print("this is last packet")
                        stream = 0x4445
                        self.pending_acks.append((self.sequence + 1, 1))
                    elif self.subsequence%128 == 0:
                        self.pending_acks.append((self.sequence + 1, self.subsequence + 1))
                    header = struct.pack(">IHHHH", self.sequence, stream, self.subsequence, len(payload), 0x0)
                    self.transport.sendto(header+payload, (self.data_ip, self.data_port))
                    print("sent", self.sequence, stream, self.subsequence, len(payload))
                    if stream == 0x4445:
                        print("sendimg done")
                        self.impos = None
                        self.subsequence = 0
                        break

                print("wait for partial ack")


        elif stream == 0x4f45:
            assert seq == 0
            print("closing device")
            self._send_ack(-1)
        else:
            print("unknown data", addr, seq, hex(stream), sub, hex(flag),
                  payload.hex())



@asynccontextmanager
async def lifespan(app: FastAPI):
    # Load the ML model
    # Get a reference to the event loop as we plan to use
    # low-level APIs.
    loop = asyncio.get_running_loop()

    # One protocol instance will be created to serve all
    # client requests.
    transport, protocol = await loop.create_datagram_endpoint(
        lambda: EchoServerProtocol(),
        local_addr=('0.0.0.0', 2000))

    yield
    transport.close()
    # Clean up the ML models and release the resources


app = FastAPI(lifespan=lifespan)


@app.post("/dump")
async def set_param(request: Request) -> None:
    data = await request.body()
    print("got", data)
    #global expno
    #with open(f"dump/{expno}.dat", "wb") as f:
    #    f.write(data)

