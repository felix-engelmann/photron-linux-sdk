import asyncio
import socket
import struct
import time
from asyncio import DatagramTransport
from asyncio.trsock import TransportSocket
from contextlib import asynccontextmanager
from typing import Tuple, Optional, AsyncGenerator

from statemachine import StateMachine, State

from dialog import queries

from fastapi import FastAPI, Response, responses, status


def ip_to_bytes(ip):
    return struct.pack(">BBBB", *map(int,ip.split(".")))

def _make_datagram(seq, stream, sub, payload):
    header = struct.pack(">IHHHH", seq, stream, sub, len(payload), 0x0)
    return header + payload

def nextseq(seq):
    seq += 1
    if seq == 2**16:
        seq = 1
    return seq


class DiscoverProtocol:
    def __init__(self, on_con_lost):
        self.on_con_lost = on_con_lost
        self.transport = None


    def connection_made(self, transport):
        self.transport = transport
        print(transport)
        ts: TransportSocket = transport.get_extra_info('socket')
        print(ts)
        print(ts.getsockname())
        host, port = ts.getsockname()

        payload_port = struct.pack(">H", port )
        payload_ip = ip_to_bytes(host)
        ansp = payload_ip+payload_port

        message= _make_datagram( stream=0x4351, seq=0x01000000, sub=0, payload=ansp)
        self.transport.sendto(message)

    def datagram_received(self, data, addr):
        print("Received:", data.hex())

        print("Close the socket")
        self.transport.close()

    def error_received(self, exc):
        print('Error received:', exc)

    def connection_lost(self, exc):
        print("Connection closed")
        self.on_con_lost.set_result(True)


class PhotronProtocol:
    def __init__(self, sm, on_con_lost):
        self.transport = None
        self.statemachine = sm
        self.on_con_lost = on_con_lost
        self.buf = b''

    def connection_made(self, transport):
        self.transport = transport
        #print('Send:', self.message)
        #self.transport.sendto(self.message.encode())

    def datagram_received(self, data, addr):
        if len(data) < 12:
            print("invlid packet")
            self.transport.close()

        seq, stream, sub, length, flag = struct.unpack(">IHHHH", data[:12])
        payload = data[12:12 + length]
        if data[12 + length:] != b'\0' * len(data[12 + length:]):
            print("========remainder not zero", data[12 + length:].hex())
            self.transport.close()

        #print("Received:", seq, hex(stream), sub, length, hex(flag), payload.hex()[:100])

        if stream == 0x5252:
            print("got ack with flag", hex(flag))
            self.statemachine.ack(seq, sub)

        elif stream == 0x4445 and sub == 1:
            print("got dialog answer", payload.hex())
            self.statemachine.reply(seq, sub, payload)

        elif stream == 0x4445:
            print("got final image part")
            self.statemachine.final(seq, sub, payload)

        elif stream == 0x4453:
            #print("got image data answer", payload.hex()[:100])
            #if sub%128 > 2:
            #    self.buf += payload
            #    print(sub)
            #else:
            self.statemachine.data(seq, sub, payload)
        #print("Close the socket")
        #self.transport.close()

    def error_received(self, exc):
        print('Error received:', exc)

    def connection_lost(self, exc):
        print("Connection closed")
        self.on_con_lost.set_result(True)


class PhotronMachine(StateMachine):

    def __init__(self, is_open, *args, **kwargs):
        self.is_open = is_open
        self.is_closed = None
        self.result = None
        self.image_ready=None
        self.pending_acks = []
        super().__init__()


    disconnected = State(initial=True)
    discovering = State()
    opening = State()
    open = State()

    querying = State()
    processing = State()

    acquireing = State()

    closing = State()

    discover = disconnected.to(discovering)
    ack = ( discovering.to(opening) |
            opening.to(open) |
            closing.to(disconnected) |
            querying.to(processing)
            )

    close = (open.to(closing))

    query = ( open.to(querying) )
    reply = ( processing.to(open) )

    data =( open.to(acquireing) |
               acquireing.to(acquireing))

    final = (acquireing.to(open))

    def on_discover(self, transport, *args) -> None:
        self.sequence: int = 0
        self.buffer: bytes = b""
        self.transport: Optional[DatagramTransport] = transport
        #protocol: Optional[PhotronProtocol] = None
        print("args", args)


        print(self.transport)
        ts: TransportSocket = self.transport.get_extra_info('socket')
        print(ts)
        print(ts.getsockname())
        bufsize = ts.getsockopt(socket.SOL_SOCKET,socket.SO_RCVBUF)
        print("buffer size is", bufsize)
        ts.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 10240000)
        bufsize = ts.getsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF)
        print("new buffer size is", bufsize)
        self.host, self.port = ts.getsockname()

        payload_port = struct.pack(">H", self.port)
        payload_ip = ip_to_bytes(self.host)
        ansp = payload_ip + payload_port

        message = _make_datagram(stream=0x4351, seq=self.sequence, sub=1, payload=ansp)
        print("sending discovery", message)
        self.pending_acks.append((self.sequence, 0))
        self.transport.sendto(message)

    def on_ack(self, seq, sub):
        print("got ack", seq, sub)
        self.pending_acks.remove((seq, sub))

    def on_enter_opening(self):
        print("let's open the camera")
        payload_port = struct.pack(">H", self.port)
        payload_ip = ip_to_bytes(self.host)
        ansp = payload_ip + payload_port
        init_payload = b"\x00\x00\x05\xb2" + ansp + b"\x00\x05\x00\x00\x00\x64\x00\x80\x00\x00\x00\x01"  # 22 long
        message = _make_datagram(stream=0x4345, seq=self.sequence, sub=1, payload=init_payload)  # send also with seq 0
        print("open device", message)
        self.pending_acks.append((self.sequence + 1, 0))
        self.transport.sendto(message)
        self.sequence = nextseq(self.sequence)

    def on_enter_open(self):
        if self.is_open:
            self.is_open.set_result(True)
            self.is_open = None

    def on_close(self, cb):
        print("closing")
        self.is_closed = cb
        header = struct.pack(">IHHHH", 0, 0x4f45, 1, 0, 0x0)
        self.pending_acks.append((0, 0))
        self.transport.sendto(header)

    def on_enter_disconnected(self):
        print("disconnected")
        if self.is_closed:
            self.is_closed.set_result(True)

    def on_query(self, msg, result):
        message = _make_datagram(stream=0x4445, seq=self.sequence, sub=1, payload=msg)
        print("sending", message)
        self.pending_acks.append((self.sequence+1, 0))
        self.transport.sendto(message)
        self.sequence = nextseq(self.sequence)
        self.result = result

    def _send_ack(self, seq, sub=0, payload=b''):
        print("acking", seq+1, payload.hex(), type(payload))
        header = struct.pack(">IHHHH", seq+1, 0x5252, sub+1, len(payload), 0x0)
        self.transport.sendto(header+payload)


    def on_reply(self, seq, sub, payload):
        print("got response, reply it", seq, sub)
        self.result.set_result(payload)
        self._send_ack(seq)

    def on_data(self, seq, sub, payload, source, target):
        if source == self.open:
            self.buffer = b''
        self.buffer += payload
        if sub % 128 == 0:
            print("send partial ack")
            self._send_ack(seq, sub)

    def on_final(self, seq, sub, payload):
        print("received final data", sub, seq, len(payload))
        self.buffer += payload
        self._send_ack(seq)
        if self.image_ready:
            self.image_ready.set_result(self.buffer)

global last_image
last_image = b""
stop = False
async def live_view():
    loop = asyncio.get_running_loop()
    while not stop:
        is_image = loop.create_future()
        state_machine.image_ready = is_image

        result = loop.create_future()
        state_machine.query(b"\x40\xb7\x00\x01\x00\x00\x00\x00\x00\x01\x00\x00", result)
        res = await result
        print(res)

        img = await is_image
        print("image acquired", len(img))
        hexed = img.hex()
        clean = []
        for i in range(0, len(hexed), 3):
            val = int(hexed[i:i + 3], 16)
            clean.append(val)

        msbs = [b.to_bytes(2, 'big') for b in clean]
        global last_image
        last_image = b"".join(msbs)

@asynccontextmanager
async def lifespan(app: FastAPI) -> AsyncGenerator[None, None]:
    # Load the ML model

    loop = asyncio.get_running_loop()

    ip = '192.168.2.63'
    #ip = '127.0.0.1'
    on_con_lost = loop.create_future()
    transport, protocol = await loop.create_datagram_endpoint(
        lambda: DiscoverProtocol(on_con_lost),
        remote_addr=(ip, 2000))
    # remote_addr=('192.168.2.63', 2000))

    try:
        await on_con_lost
    finally:
        transport.close()
        pass

    is_open = loop.create_future()

    global state_machine
    state_machine = PhotronMachine(is_open)
    print(state_machine)

    on_con_lost = loop.create_future()

    transport, protocol = await loop.create_datagram_endpoint(
        lambda: PhotronProtocol(state_machine, on_con_lost),
        remote_addr=(ip, 2000))

    state_machine.discover(transport)

    await is_open

    for q in queries[:-1]:
        result = loop.create_future()
        state_machine.query(q, result)
        res = await result
        print(res)

    is_image = loop.create_future()
    state_machine.image_ready = is_image

    result = loop.create_future()
    state_machine.query(b"\x40\xb7\x00\x01\x00\x00\x00\x00\x00\x01\x00\x00", result)
    res = await result
    print(res)

    img = await is_image
    print("image acquired", len(img))

    #result = loop.create_future()
    #state_machine.query(b"\x20\x20\x00\x00\x00\x0f\x42\x40\x00\x00\x00\x00", result)
    #state_machine.query(b"\x20\x20\x00\x00\x00\x00\x75\x30\x00\x00\x00\x00", result)
    #res = await result
    #print("set new rate", res)

    live_task = asyncio.create_task(live_view())

    yield

    global stop
    stop = True

    await live_task

    print("now we are open, close it")
    await asyncio.sleep(1)
    is_closed = loop.create_future()

    state_machine.close(is_closed)

    await is_closed
    # Clean up the ML models and release the resources


app = FastAPI(lifespan=lifespan)

@app.get("/v1/last_image")
async def read_img():

    data = last_image
    return Response(content=data, headers={'shape': "(1024,1024)",# "(512,1024)",
                                           'type': "uint16",
                                           'compression': 'none'},
                    media_type="image/x.detector+numpy")


@app.get("/v1/roi")
async def get_roi():
    return {"roi": None}
