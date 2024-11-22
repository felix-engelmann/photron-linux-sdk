// testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>

#include <string>
#include <sstream>

#include "funcs.cpp"
#include "PDCLIB.h"

#define IFACE_ID_FIELD_OFFSET 32
#define IFACE_ID_FROM_VALUES(deviceNum, childNum) ((((uint64_t)deviceNum) << IFACE_ID_FIELD_OFFSET) + childNum)
#define IFACE_ID_GET_DEV_NUM(interfaceId) ((unsigned long)(interfaceId >> IFACE_ID_FIELD_OFFSET))
#define IFACE_ID_GET_CHILD_NUM(interfaceId) ((unsigned long)(interfaceId & (((uint64_t)1 << IFACE_ID_FIELD_OFFSET) - 1)))


uint64_t PyHSCam_openDeviceByIp(const char* ipStr)
{
    unsigned long retVal;
    unsigned long errorCode;

    // Convert ip string to 32 bit int
    // Eg: "192.168.1.10" -> 0xc0a8000a
    unsigned long ipNumeric = 0;
    std::stringstream ss(ipStr);
    std::string item;
    while (getline(ss, item, '.'))
    {
        ipNumeric = (ipNumeric << 8) | std::stoi(item);
    }

    printf("check auto\n");

    printf("ip in numberc %#08x\n", ipNumeric);

    PDC_DETECT_NUM_INFO detectedNumInfo;
    unsigned long ipList[PDC_MAX_DEVICE];
    ipList[0] = ipNumeric;


    // Detect the attached device
    retVal = PDC_DetectDevice(PDC_INTTYPE_G_ETHER,  // Gigabit-ethernet interface
        ipList,
        1,                  // Max number of search devices
        PDC_DETECT_NORMAL,  // Indicate we're specifying an ip explicitly
        &detectedNumInfo,   // Output
        &errorCode);        // Output

    if (retVal == PDC_FAILED)
    {
        printf("Device search failed! %d", errorCode);
    }
    if (detectedNumInfo.m_nDeviceNum == 0)
    {
        printf("SDK reported 0 devices found!");
    }
    printf("found %d devices ", detectedNumInfo.m_nDeviceNum);
    printf("device code %d\n", detectedNumInfo.m_DetectInfo[0].m_nDeviceCode);
    if (detectedNumInfo.m_DetectInfo[0].m_nTmpDeviceNo != ipList[0])
    {
        char msgBuf[40];
        snprintf(&msgBuf[0],
            40,
            "SDK found unexpected ip = %#08x\n",
            detectedNumInfo.m_DetectInfo[0].m_nTmpDeviceNo);
        printf(msgBuf);
    }

    //return 0;
    //TODO: Should we specify the model to validate the camera?
    // eg. Fastcam 4 : (dectNumInfo.m_DetectInfo[0].m_nDeviceCode == PDC_DEVTYPE_FCAM_SA4)

    // No errors - open the located device
    // TODO: Expect only one device at a at a time. This init function will
    // need to be rearranged if we want to expect >1 device open.
    // Should also account for devices with >1 child devices
    // (devices which have multiple camera heads).
    unsigned long deviceNum;
    unsigned long childNum;
    retVal = PDC_OpenDevice(&(detectedNumInfo.m_DetectInfo[0]),
        &deviceNum,     // Output
        &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to open device! %d", errorCode);
    }

    childNum = 1; // TODO: support more than one child
    //return 1;
    // TODO: Return a list of IDs (required for supporting more than one child).

    // Enable burst transfer if possible
    char functionStatus;
    retVal = PDC_IsFunction(deviceNum,
        childNum,
        PDC_EXIST_BURST_TRANSFER,
        &functionStatus,    // Output
        &errorCode);        // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to retrieve status of library function! %d", errorCode);
    }
    if (functionStatus == PDC_EXIST_SUPPORTED)
    {
        printf("burst supported\n");
        retVal = PDC_SetBurstTransfer(deviceNum,
            PDC_FUNCTION_ON,
            &errorCode);
        if (retVal == PDC_FAILED)
        {
            printf("Failed to enable burst transfer mode! %d", errorCode);
        }
    }

    return IFACE_ID_FROM_VALUES(deviceNum, childNum);
}

unsigned long PyHSCam_getCurrentCapRate(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long capRate;

    retVal = PDC_GetRecordRate(IFACE_ID_GET_DEV_NUM(interfaceId),
        IFACE_ID_GET_CHILD_NUM(interfaceId),
        &capRate,
        &errorCode);
    if (retVal == PDC_FAILED)
    {
       printf("Failed to retrieve current capture rate! %d", errorCode);
    }
    return capRate;
}

void PyHSCam_CloseDev(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long capRate;

    retVal = PDC_CloseDevice(IFACE_ID_GET_DEV_NUM(interfaceId),
        &errorCode);
    if (retVal == PDC_FAILED)
    {
        printf("Failed to close dev %d", errorCode);
    }
}

void PyHSCam_GetResolution(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long width;
    unsigned long height;

    retVal = PDC_GetResolution(IFACE_ID_GET_DEV_NUM(interfaceId),
        IFACE_ID_GET_CHILD_NUM(interfaceId),
        &width,
        &height,
        &errorCode);
    if (retVal == PDC_FAILED)
    {
        printf("Failed to close dev %d", errorCode);
    }
    printf("resolution is %d x %d\n", width, height);
}



void PyHSCam_SetResolution(uint64_t interfaceId, unsigned long width, unsigned long height)
{
    unsigned long retVal;
    unsigned long errorCode;

    retVal = PDC_SetResolution(IFACE_ID_GET_DEV_NUM(interfaceId),
        IFACE_ID_GET_CHILD_NUM(interfaceId),
        width,
        height,
        &errorCode);
    if (retVal == PDC_FAILED)
    {
        printf("Failed to close dev %d", errorCode);
    }
    printf("resolution set to %d x %d\n", width, height);
}

void PyHSCam_SetRate(uint64_t interfaceId, unsigned long rate)
{
    unsigned long retVal;
    unsigned long errorCode;

    retVal = PDC_SetRecordRate(IFACE_ID_GET_DEV_NUM(interfaceId),
        IFACE_ID_GET_CHILD_NUM(interfaceId),
        rate,
        &errorCode);
    if (retVal == PDC_FAILED)
    {
        printf("Failed to set rate dev %d", errorCode);
    }
    printf("rate set to %d\n", rate);
}


void getLive(uint64_t interfaceId, unsigned long width, unsigned long height)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned char* pbuf;
    
    pbuf = (unsigned char*)malloc(width * height);
    retVal = PDC_GetLiveImageData(IFACE_ID_GET_DEV_NUM(interfaceId),
        IFACE_ID_GET_CHILD_NUM(interfaceId),
        8,
        pbuf,
        &errorCode);
    if (retVal == PDC_FAILED)
    {
        printf("Failed to close dev %d", errorCode);
    }
    printf("image %0128x\n", pbuf);
    free(pbuf);
}


int main()
{
    printf("Hello World! from C\n");

  
    unsigned long errorCode;
    unsigned long retVal = PDC_Init(&errorCode);
    if (retVal == PDC_FAILED)
    {
        printf("Init failed! %d", errorCode);
    }
    printf("init error code %d, ret val %d", errorCode, retVal);

    auto dev = PyHSCam_openDeviceByIp("192.168.2.63");

    
    printf("sleep 1s\n");
    //Sleep(1000);
    //printf("slept\n");

    //test_all(dev);

    //auto caprate = PyHSCam_getCurrentCapRate(dev);
    //printf("capture rate %d", caprate);
    
    //PyHSCam_SetRate(dev, 2000);
    
    for (int i = 0; i < 5; i++) {
        Sleep(100);
        printf("i %d\n", i);
        getLive(dev, 1024, 1024);
    }
    
    //PyHSCam_SetResolution(dev, 512,512);
    
    //Sleep(1000);
    
    //getLive(dev, 512, 512);

    //Sleep(1000);
    
    PyHSCam_CloseDev(dev);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
