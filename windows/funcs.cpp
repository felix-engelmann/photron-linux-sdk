
    #include <windows.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>

#include <string>
#include <sstream>

#include "PDCLIB.h"


#define IFACE_ID_FIELD_OFFSET 32
#define IFACE_ID_FROM_VALUES(deviceNum, childNum) ((((uint64_t)deviceNum) << IFACE_ID_FIELD_OFFSET) + childNum)
#define IFACE_ID_GET_DEV_NUM(interfaceId) ((unsigned long)(interfaceId >> IFACE_ID_FIELD_OFFSET))
#define IFACE_ID_GET_CHILD_NUM(interfaceId) ((unsigned long)(interfaceId & (((uint64_t)1 << IFACE_ID_FIELD_OFFSET) - 1)))
void test_PDC_GetRecordRateList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetRecordRateList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetRecordRateList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetRecordRateList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetResolutionList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetResolutionList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetResolutionList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetResolutionList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetShutterSpeedFpsList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetShutterSpeedFpsList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShutterSpeedFpsList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetShutterSpeedFpsList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetShutterSpeedUsecList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetShutterSpeedUsecList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShutterSpeedUsecList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetShutterSpeedUsecList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetShutterSpeedNsecList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetShutterSpeedNsecList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShutterSpeedNsecList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetShutterSpeedNsecList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetTriggerModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetTriggerModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetTriggerModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetTriggerModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetSensorGainModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetSensorGainModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetSensorGainModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetSensorGainModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetSensorGammaModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetSensorGammaModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetSensorGammaModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetSensorGammaModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetColorTempModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetColorTempModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetColorTempModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetColorTempModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetLUTModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetLUTModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetLUTModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetLUTModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetVariableRecordRateList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetVariableRecordRateList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetVariableRecordRateList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetVariableRecordRateList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetDSShutterModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetDSShutterModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetDSShutterModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetDSShutterModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetVideoOutModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetVideoOutModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetVideoOutModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetVideoOutModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetShadingModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetShadingModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShadingModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetShadingModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetAEShutterFpsList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetAEShutterFpsList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetAEShutterFpsList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetAEShutterFpsList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetAEShutterUsecList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetAEShutterUsecList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetAEShutterUsecList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetAEShutterUsecList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetAEShutterNsecList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetAEShutterNsecList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetAEShutterNsecList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetAEShutterNsecList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetEdgeEnhanceModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetEdgeEnhanceModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetEdgeEnhanceModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetEdgeEnhanceModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetSyncPriorityList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetSyncPriorityList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetSyncPriorityList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetSyncPriorityList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetExistChildDeviceList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetExistChildDeviceList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetExistChildDeviceList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetExistChildDeviceList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetOpenedDeviceList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetOpenedDeviceList( 
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetOpenedDeviceList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetOpenedDeviceList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetProgSwitchModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetProgSwitchModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetProgSwitchModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetProgSwitchModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetPixelGainModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetPixelGainModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetPixelGainModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetPixelGainModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetSyncOutTimesList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetSyncOutTimesList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetSyncOutTimesList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetSyncOutTimesList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetColorEnhanceModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetColorEnhanceModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetColorEnhanceModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetColorEnhanceModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetHeadExchangeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetHeadExchangeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetHeadExchangeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetHeadExchangeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetCameraCommandBaudRateList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetCameraCommandBaudRateList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetCameraCommandBaudRateList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetCameraCommandBaudRateList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetDownloadModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetDownloadModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetDownloadModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetDownloadModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetVideoOutSignalList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetVideoOutSignalList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetVideoOutSignalList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetVideoOutSignalList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetVideoOutHDSDIList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetVideoOutHDSDIList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetVideoOutHDSDIList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetVideoOutHDSDIList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetBlackClipLevelList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetBlackClipLevelList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetBlackClipLevelList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetBlackClipLevelList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetRecordingTypeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetRecordingTypeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetRecordingTypeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetRecordingTypeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetPartitionIncModeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetPartitionIncModeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetPartitionIncModeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetPartitionIncModeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetDeviceCode(uint64_t interfaceId)
{
    unsigned long pCode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetDeviceCode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pCode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetDeviceCode: %d\n", retVal);
        return;
    }

    printf("PDC_GetDeviceCode ; pCode,%d ; pErrorCode,%d\n",pCode,pErrorCode);
}
void test_PDC_GetDeviceID(uint64_t interfaceId)
{
    unsigned long pID;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetDeviceID(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pID,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetDeviceID: %d\n", retVal);
        return;
    }

    printf("PDC_GetDeviceID ; pID,%d ; pErrorCode,%d\n",pID,pErrorCode);
}
void test_PDC_GetVersion(uint64_t interfaceId)
{
    unsigned long pVer;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetVersion(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pVer,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetVersion: %d\n", retVal);
        return;
    }

    printf("PDC_GetVersion ; pVer,%d ; pErrorCode,%d\n",pVer,pErrorCode);
}
void test_PDC_GetColorType(uint64_t interfaceId)
{
    char pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetColorType(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetColorType: %d\n", retVal);
        return;
    }

    printf("PDC_GetColorType ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetShutterLockMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetShutterLockMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShutterLockMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetShutterLockMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetResolutionLockMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetResolutionLockMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetResolutionLockMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetResolutionLockMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetPartitionIncMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetPartitionIncMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetPartitionIncMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetPartitionIncMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetChildDeviceCount(uint64_t interfaceId)
{
    unsigned long pCount;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetChildDeviceCount(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pCount,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetChildDeviceCount: %d\n", retVal);
        return;
    }

    printf("PDC_GetChildDeviceCount ; pCount,%d ; pErrorCode,%d\n",pCount,pErrorCode);
}
void test_PDC_GetMaxChildDeviceCount(uint64_t interfaceId)
{
    unsigned long pCount;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetMaxChildDeviceCount(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pCount,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetMaxChildDeviceCount: %d\n", retVal);
        return;
    }

    printf("PDC_GetMaxChildDeviceCount ; pCount,%d ; pErrorCode,%d\n",pCount,pErrorCode);
}
void test_PDC_GetExternalCount(uint64_t interfaceId)
{
    unsigned long pIn;

unsigned long pOut;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetExternalCount(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pIn,&pOut,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetExternalCount: %d\n", retVal);
        return;
    }

    printf("PDC_GetExternalCount ; pIn,%d ; pOut,%d ; pErrorCode,%d\n",pIn,pOut,pErrorCode);
}
void test_PDC_GetIRIG(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetIRIG(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetIRIG: %d\n", retVal);
        return;
    }

    printf("PDC_GetIRIG ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetIRIGOffset(uint64_t interfaceId)
{
    long pValue;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetIRIGOffset(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pValue,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetIRIGOffset: %d\n", retVal);
        return;
    }

    printf("PDC_GetIRIGOffset ; pValue,%d ; pErrorCode,%d\n",pValue,pErrorCode);
}
void test_PDC_GetRecordRate(uint64_t interfaceId)
{
    unsigned long pRate;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetRecordRate(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pRate,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetRecordRate: %d\n", retVal);
        return;
    }

    printf("PDC_GetRecordRate ; pRate,%d ; pErrorCode,%d\n",pRate,pErrorCode);
}
void test_PDC_GetTriggerMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pAFrames;

unsigned long pRFrames;

unsigned long pRCount;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetTriggerMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pAFrames,&pRFrames,&pRCount,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetTriggerMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetTriggerMode ; pMode,%d ; pAFrames,%d ; pRFrames,%d ; pRCount,%d ; pErrorCode,%d\n",pMode,pAFrames,pRFrames,pRCount,pErrorCode);
}
void test_PDC_GetResolution(uint64_t interfaceId)
{
    unsigned long pWidth;

unsigned long pHeight;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetResolution(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pWidth,&pHeight,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetResolution: %d\n", retVal);
        return;
    }

    printf("PDC_GetResolution ; pWidth,%d ; pHeight,%d ; pErrorCode,%d\n",pWidth,pHeight,pErrorCode);
}
void test_PDC_GetShutterSpeedFps(uint64_t interfaceId)
{
    unsigned long pFps;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetShutterSpeedFps(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pFps,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShutterSpeedFps: %d\n", retVal);
        return;
    }

    printf("PDC_GetShutterSpeedFps ; pFps,%d ; pErrorCode,%d\n",pFps,pErrorCode);
}
void test_PDC_GetShutterSpeedUsec(uint64_t interfaceId)
{
    unsigned long pUsec;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetShutterSpeedUsec(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pUsec,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShutterSpeedUsec: %d\n", retVal);
        return;
    }

    printf("PDC_GetShutterSpeedUsec ; pUsec,%d ; pErrorCode,%d\n",pUsec,pErrorCode);
}
void test_PDC_GetShutterSpeedNsec(uint64_t interfaceId)
{
    unsigned long pNsec;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetShutterSpeedNsec(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pNsec,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShutterSpeedNsec: %d\n", retVal);
        return;
    }

    printf("PDC_GetShutterSpeedNsec ; pNsec,%d ; pErrorCode,%d\n",pNsec,pErrorCode);
}
void test_PDC_GetMaxPartition(uint64_t interfaceId)
{
    unsigned long pCount;

unsigned long pBlock;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetMaxPartition(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pCount,&pBlock,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetMaxPartition: %d\n", retVal);
        return;
    }

    printf("PDC_GetMaxPartition ; pCount,%d ; pBlock,%d ; pErrorCode,%d\n",pCount,pBlock,pErrorCode);
}
void test_PDC_GetCurrentPartition(uint64_t interfaceId)
{
    unsigned long pNo;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetCurrentPartition(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pNo,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetCurrentPartition: %d\n", retVal);
        return;
    }

    printf("PDC_GetCurrentPartition ; pNo,%d ; pErrorCode,%d\n",pNo,pErrorCode);
}
void test_PDC_GetAutoExposure(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetAutoExposure(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetAutoExposure: %d\n", retVal);
        return;
    }

    printf("PDC_GetAutoExposure ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetLUTMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetLUTMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetLUTMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetLUTMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetDSShutterMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetDSShutterMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetDSShutterMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetDSShutterMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetDSShutterValue(uint64_t interfaceId)
{
    unsigned long pValue;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetDSShutterValue(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pValue,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetDSShutterValue: %d\n", retVal);
        return;
    }

    printf("PDC_GetDSShutterValue ; pValue,%d ; pErrorCode,%d\n",pValue,pErrorCode);
}
void test_PDC_GetEdgeEnhanceMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetEdgeEnhanceMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetEdgeEnhanceMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetEdgeEnhanceMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetShadingTypeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetShadingTypeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShadingTypeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetShadingTypeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetPixelGainMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetPixelGainMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetPixelGainMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetPixelGainMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetMaxFrames(uint64_t interfaceId)
{
    unsigned long pFrames;

unsigned long pBlocks;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetMaxFrames(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pFrames,&pBlocks,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetMaxFrames: %d\n", retVal);
        return;
    }

    printf("PDC_GetMaxFrames ; pFrames,%d ; pBlocks,%d ; pErrorCode,%d\n",pFrames,pBlocks,pErrorCode);
}
void test_PDC_GetMaxResolution(uint64_t interfaceId)
{
    unsigned long pWidth;

unsigned long pHeight;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetMaxResolution(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pWidth,&pHeight,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetMaxResolution: %d\n", retVal);
        return;
    }

    printf("PDC_GetMaxResolution ; pWidth,%d ; pHeight,%d ; pErrorCode,%d\n",pWidth,pHeight,pErrorCode);
}
void test_PDC_GetSegmentPosition(uint64_t interfaceId)
{
    unsigned long pXPos;

unsigned long pYPos;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetSegmentPosition(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pXPos,&pYPos,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetSegmentPosition: %d\n", retVal);
        return;
    }

    printf("PDC_GetSegmentPosition ; pXPos,%d ; pYPos,%d ; pErrorCode,%d\n",pXPos,pYPos,pErrorCode);
}
void test_PDC_GetVariableChannel(uint64_t interfaceId)
{
    unsigned long pChannel;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetVariableChannel(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pChannel,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetVariableChannel: %d\n", retVal);
        return;
    }

    printf("PDC_GetVariableChannel ; pChannel,%d ; pErrorCode,%d\n",pChannel,pErrorCode);
}
void test_PDC_GetAutoExposureInfo(uint64_t interfaceId)
{
    unsigned long pWidth;

unsigned long pHeight;

unsigned long pXPos;

unsigned long pYPos;

unsigned long pValue;

unsigned long pRange;

unsigned long pLimit;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetAutoExposureInfo(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pWidth,&pHeight,&pXPos,&pYPos,&pValue,&pRange,&pLimit,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetAutoExposureInfo: %d\n", retVal);
        return;
    }

    printf("PDC_GetAutoExposureInfo ; pWidth,%d ; pHeight,%d ; pXPos,%d ; pYPos,%d ; pValue,%d ; pRange,%d ; pLimit,%d ; pErrorCode,%d\n",pWidth,pHeight,pXPos,pYPos,pValue,pRange,pLimit,pErrorCode);
}
void test_PDC_GetMaxBitDepth(uint64_t interfaceId)
{
    char pDepth;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetMaxBitDepth(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pDepth,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetMaxBitDepth: %d\n", retVal);
        return;
    }

    printf("PDC_GetMaxBitDepth ; pDepth,%d ; pErrorCode,%d\n",pDepth,pErrorCode);
}
void test_PDC_GetVariableRestriction(uint64_t interfaceId)
{
    unsigned long pWidthStep;

unsigned long pHeightStep;

unsigned long pXPosStep;

unsigned long pYPosStep;

unsigned long pWidthMin;

unsigned long pHeightMin;

unsigned long pFreePos;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetVariableRestriction(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pWidthStep,&pHeightStep,&pXPosStep,&pYPosStep,&pWidthMin,&pHeightMin,&pFreePos,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetVariableRestriction: %d\n", retVal);
        return;
    }

    printf("PDC_GetVariableRestriction ; pWidthStep,%d ; pHeightStep,%d ; pXPosStep,%d ; pYPosStep,%d ; pWidthMin,%d ; pHeightMin,%d ; pFreePos,%d ; pErrorCode,%d\n",pWidthStep,pHeightStep,pXPosStep,pYPosStep,pWidthMin,pHeightMin,pFreePos,pErrorCode);
}
void test_PDC_GetDownloadMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetDownloadMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetDownloadMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetDownloadMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetCamMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetCamMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetCamMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetCamMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetMaxFullResoRate(uint64_t interfaceId)
{
    unsigned long pRate;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetMaxFullResoRate(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pRate,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetMaxFullResoRate: %d\n", retVal);
        return;
    }

    printf("PDC_GetMaxFullResoRate ; pRate,%d ; pErrorCode,%d\n",pRate,pErrorCode);
}
void test_PDC_GetLowLightMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetLowLightMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetLowLightMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetLowLightMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetAutoExposureRestriction(uint64_t interfaceId)
{
    unsigned long pWidthStep;

unsigned long pHeightStep;

unsigned long pXPosStep;

unsigned long pYPosStep;

unsigned long pWidthMin;

unsigned long pHeightMin;

unsigned long pMaxValue;

unsigned long pMaxRange;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetAutoExposureRestriction(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pWidthStep,&pHeightStep,&pXPosStep,&pYPosStep,&pWidthMin,&pHeightMin,&pMaxValue,&pMaxRange,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetAutoExposureRestriction: %d\n", retVal);
        return;
    }

    printf("PDC_GetAutoExposureRestriction ; pWidthStep,%d ; pHeightStep,%d ; pXPosStep,%d ; pYPosStep,%d ; pWidthMin,%d ; pHeightMin,%d ; pMaxValue,%d ; pMaxRange,%d ; pErrorCode,%d\n",pWidthStep,pHeightStep,pXPosStep,pYPosStep,pWidthMin,pHeightMin,pMaxValue,pMaxRange,pErrorCode);
}
void test_PDC_GetSyncOutTimes(uint64_t interfaceId)
{
    unsigned long pRatio;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetSyncOutTimes(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pRatio,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetSyncOutTimes: %d\n", retVal);
        return;
    }

    printf("PDC_GetSyncOutTimes ; pRatio,%d ; pErrorCode,%d\n",pRatio,pErrorCode);
}
void test_PDC_GetStoreNum(uint64_t interfaceId)
{
    unsigned long pNum;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetStoreNum(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pNum,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetStoreNum: %d\n", retVal);
        return;
    }

    printf("PDC_GetStoreNum ; pNum,%d ; pErrorCode,%d\n",pNum,pErrorCode);
}
void test_PDC_GetIRIGPhaseLock(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetIRIGPhaseLock(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetIRIGPhaseLock: %d\n", retVal);
        return;
    }

    printf("PDC_GetIRIGPhaseLock ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetIRIGPhaseLockStatus(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetIRIGPhaseLockStatus(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetIRIGPhaseLockStatus: %d\n", retVal);
        return;
    }

    printf("PDC_GetIRIGPhaseLockStatus ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetBurstTransfer(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetBurstTransfer(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetBurstTransfer: %d\n", retVal);
        return;
    }

    printf("PDC_GetBurstTransfer ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetBitDepth(uint64_t interfaceId)
{
    char pDepth;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetBitDepth(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pDepth,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetBitDepth: %d\n", retVal);
        return;
    }

    printf("PDC_GetBitDepth ; pDepth,%d ; pErrorCode,%d\n",pDepth,pErrorCode);
}
void test_PDC_GetVideoOutHDSDI(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetVideoOutHDSDI(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetVideoOutHDSDI: %d\n", retVal);
        return;
    }

    printf("PDC_GetVideoOutHDSDI ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetRecordingType(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetRecordingType(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetRecordingType: %d\n", retVal);
        return;
    }

    printf("PDC_GetRecordingType ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetFactoryDefaults(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetFactoryDefaults(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetFactoryDefaults: %d\n", retVal);
        return;
    }

    printf("PDC_GetFactoryDefaults ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetStorePreset(uint64_t interfaceId)
{
    unsigned long pNo;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetStorePreset(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pNo,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetStorePreset: %d\n", retVal);
        return;
    }

    printf("PDC_GetStorePreset ; pNo,%d ; pErrorCode,%d\n",pNo,pErrorCode);
}
void test_PDC_GetStorePresetReboot(uint64_t interfaceId)
{
    unsigned long pReboot;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetStorePresetReboot(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pReboot,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetStorePresetReboot: %d\n", retVal);
        return;
    }

    printf("PDC_GetStorePresetReboot ; pReboot,%d ; pErrorCode,%d\n",pReboot,pErrorCode);
}
void test_PDC_GetInstructionSet(uint64_t interfaceId)
{
    unsigned long pInstSetCode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetInstructionSet(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pInstSetCode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetInstructionSet: %d\n", retVal);
        return;
    }

    printf("PDC_GetInstructionSet ; pInstSetCode,%d ; pErrorCode,%d\n",pInstSetCode,pErrorCode);
}
void test_PDC_GetMemoryModePartition(uint64_t interfaceId)
{
    unsigned long pNo;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetMemoryModePartition(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pNo,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetMemoryModePartition: %d\n", retVal);
        return;
    }

    printf("PDC_GetMemoryModePartition ; pNo,%d ; pErrorCode,%d\n",pNo,pErrorCode);
}
void test_PDC_GetLensControl(uint64_t interfaceId)
{
    unsigned long pType;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetLensControl(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pType,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetLensControl: %d\n", retVal);
        return;
    }

    printf("PDC_GetLensControl ; pType,%d ; pErrorCode,%d\n",pType,pErrorCode);
}
void test_PDC_GetTransferOption(uint64_t interfaceId)
{
    unsigned long p8BitSel;

unsigned long pBayer;

unsigned long pInterleave;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetTransferOption(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &p8BitSel,&pBayer,&pInterleave,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetTransferOption: %d\n", retVal);
        return;
    }

    printf("PDC_GetTransferOption ; p8BitSel,%d ; pBayer,%d ; pInterleave,%d ; pErrorCode,%d\n",p8BitSel,pBayer,pInterleave,pErrorCode);
}
void test_PDC_GetSelfSyncMode(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetSelfSyncMode(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetSelfSyncMode: %d\n", retVal);
        return;
    }

    printf("PDC_GetSelfSyncMode ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetMaxRandomTriggerCount(uint64_t interfaceId)
{
    unsigned long pMaxRandomCount;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetMaxRandomTriggerCount(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pMaxRandomCount,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetMaxRandomTriggerCount: %d\n", retVal);
        return;
    }

    printf("PDC_GetMaxRandomTriggerCount ; pMaxRandomCount,%d ; pErrorCode,%d\n",pMaxRandomCount,pErrorCode);
}
void test_PDC_GetMaxRandomEndlessTriggerCount(uint64_t interfaceId)
{
    unsigned long pMaxRandomCount;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetMaxRandomEndlessTriggerCount(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pMaxRandomCount,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetMaxRandomEndlessTriggerCount: %d\n", retVal);
        return;
    }

    printf("PDC_GetMaxRandomEndlessTriggerCount ; pMaxRandomCount,%d ; pErrorCode,%d\n",pMaxRandomCount,pErrorCode);
}
void test_PDC_GetReadAheadTransfer(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetReadAheadTransfer(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetReadAheadTransfer: %d\n", retVal);
        return;
    }

    printf("PDC_GetReadAheadTransfer ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetLowLightMode2(uint64_t interfaceId)
{
    unsigned long pMode;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetLowLightMode2(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pMode,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetLowLightMode2: %d\n", retVal);
        return;
    }

    printf("PDC_GetLowLightMode2 ; pMode,%d ; pErrorCode,%d\n",pMode,pErrorCode);
}
void test_PDC_GetFanRecReadyStop(uint64_t interfaceId)
{
    char pFlag;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetFanRecReadyStop(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pFlag,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetFanRecReadyStop: %d\n", retVal);
        return;
    }

    printf("PDC_GetFanRecReadyStop ; pFlag,%d ; pErrorCode,%d\n",pFlag,pErrorCode);
}
void test_PDC_GetTemperatureTypeList(uint64_t interfaceId)
{
    unsigned long retVal;
    unsigned long errorCode;
    unsigned long modeCnt;
    unsigned long modeList[PDC_MAX_LIST_NUMBER];

    retVal = PDC_GetTemperatureTypeList( IFACE_ID_GET_DEV_NUM(interfaceId),
                                    IFACE_ID_GET_CHILD_NUM(interfaceId),
                                    &modeCnt,       // Output
                                    modeList,       // Output
                                    &errorCode);    // Output
    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetTemperatureTypeList: %d\n", retVal);
        return;
    }

    unsigned long i;
    printf("PDC_GetTemperatureTypeList LIST:");
    for (i = 0; i < modeCnt; i++)
    {
        printf("%d ;",modeList[i]);
    }
    printf("\n");
}
void test_PDC_GetShutterSpeedPrecision(uint64_t interfaceId)
{
    long pValue;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetShutterSpeedPrecision(IFACE_ID_GET_DEV_NUM(interfaceId),
                                IFACE_ID_GET_CHILD_NUM(interfaceId),
                                &pValue,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetShutterSpeedPrecision: %d\n", retVal);
        return;
    }

    printf("PDC_GetShutterSpeedPrecision ; pValue,%d ; pErrorCode,%d\n",pValue,pErrorCode);
}
void test_PDC_GetLinkSpeed(uint64_t interfaceId)
{
    unsigned long pLinkSpeed;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetLinkSpeed(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pLinkSpeed,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetLinkSpeed: %d\n", retVal);
        return;
    }

    printf("PDC_GetLinkSpeed ; pLinkSpeed,%d ; pErrorCode,%d\n",pLinkSpeed,pErrorCode);
}
void test_PDC_GetEthernetSpeedLimit(uint64_t interfaceId)
{
    unsigned long pParam;

unsigned long pErrorCode;

    unsigned long retVal;

    retVal = PDC_GetEthernetSpeedLimit(IFACE_ID_GET_DEV_NUM(interfaceId),
                                
                                &pParam,&pErrorCode);    // Output

    if (retVal == PDC_FAILED)
    {
        printf("Failed to read PDC_GetEthernetSpeedLimit: %d\n", retVal);
        return;
    }

    printf("PDC_GetEthernetSpeedLimit ; pParam,%d ; pErrorCode,%d\n",pParam,pErrorCode);
}

    void test_all(uint64_t dev) 
{
test_PDC_GetRecordRateList(dev);
test_PDC_GetResolutionList(dev);
test_PDC_GetShutterSpeedFpsList(dev);
test_PDC_GetShutterSpeedUsecList(dev);
test_PDC_GetShutterSpeedNsecList(dev);
test_PDC_GetTriggerModeList(dev);
test_PDC_GetSensorGainModeList(dev);
test_PDC_GetSensorGammaModeList(dev);
test_PDC_GetColorTempModeList(dev);
test_PDC_GetLUTModeList(dev);
test_PDC_GetVariableRecordRateList(dev);
test_PDC_GetDSShutterModeList(dev);
test_PDC_GetVideoOutModeList(dev);
test_PDC_GetShadingModeList(dev);
test_PDC_GetAEShutterFpsList(dev);
test_PDC_GetAEShutterUsecList(dev);
test_PDC_GetAEShutterNsecList(dev);
test_PDC_GetEdgeEnhanceModeList(dev);
test_PDC_GetSyncPriorityList(dev);
test_PDC_GetExistChildDeviceList(dev);
test_PDC_GetOpenedDeviceList(dev);
test_PDC_GetProgSwitchModeList(dev);
test_PDC_GetPixelGainModeList(dev);
test_PDC_GetSyncOutTimesList(dev);
test_PDC_GetColorEnhanceModeList(dev);
test_PDC_GetHeadExchangeList(dev);
test_PDC_GetCameraCommandBaudRateList(dev);
test_PDC_GetDownloadModeList(dev);
test_PDC_GetVideoOutSignalList(dev);
test_PDC_GetVideoOutHDSDIList(dev);
test_PDC_GetBlackClipLevelList(dev);
test_PDC_GetRecordingTypeList(dev);
test_PDC_GetPartitionIncModeList(dev);
test_PDC_GetDeviceCode(dev);
test_PDC_GetDeviceID(dev);
test_PDC_GetVersion(dev);
test_PDC_GetColorType(dev);
test_PDC_GetShutterLockMode(dev);
test_PDC_GetResolutionLockMode(dev);
test_PDC_GetPartitionIncMode(dev);
test_PDC_GetChildDeviceCount(dev);
test_PDC_GetMaxChildDeviceCount(dev);
test_PDC_GetExternalCount(dev);
test_PDC_GetIRIG(dev);
test_PDC_GetIRIGOffset(dev);
test_PDC_GetRecordRate(dev);
test_PDC_GetTriggerMode(dev);
test_PDC_GetResolution(dev);
test_PDC_GetShutterSpeedFps(dev);
test_PDC_GetShutterSpeedUsec(dev);
test_PDC_GetShutterSpeedNsec(dev);
test_PDC_GetMaxPartition(dev);
test_PDC_GetCurrentPartition(dev);
test_PDC_GetAutoExposure(dev);
test_PDC_GetLUTMode(dev);
test_PDC_GetDSShutterMode(dev);
test_PDC_GetDSShutterValue(dev);
test_PDC_GetEdgeEnhanceMode(dev);
test_PDC_GetShadingTypeList(dev);
test_PDC_GetPixelGainMode(dev);
test_PDC_GetMaxFrames(dev);
test_PDC_GetMaxResolution(dev);
test_PDC_GetSegmentPosition(dev);
test_PDC_GetVariableChannel(dev);
test_PDC_GetAutoExposureInfo(dev);
test_PDC_GetMaxBitDepth(dev);
test_PDC_GetVariableRestriction(dev);
test_PDC_GetDownloadMode(dev);
test_PDC_GetCamMode(dev);
test_PDC_GetMaxFullResoRate(dev);
test_PDC_GetLowLightMode(dev);
test_PDC_GetAutoExposureRestriction(dev);
test_PDC_GetSyncOutTimes(dev);
test_PDC_GetStoreNum(dev);
test_PDC_GetIRIGPhaseLock(dev);
test_PDC_GetIRIGPhaseLockStatus(dev);
test_PDC_GetBurstTransfer(dev);
test_PDC_GetBitDepth(dev);
test_PDC_GetVideoOutHDSDI(dev);
test_PDC_GetRecordingType(dev);
test_PDC_GetFactoryDefaults(dev);
test_PDC_GetStorePreset(dev);
test_PDC_GetStorePresetReboot(dev);
test_PDC_GetInstructionSet(dev);
test_PDC_GetMemoryModePartition(dev);
test_PDC_GetLensControl(dev);
test_PDC_GetTransferOption(dev);
test_PDC_GetSelfSyncMode(dev);
test_PDC_GetMaxRandomTriggerCount(dev);
test_PDC_GetMaxRandomEndlessTriggerCount(dev);
test_PDC_GetReadAheadTransfer(dev);
test_PDC_GetLowLightMode2(dev);
test_PDC_GetFanRecReadyStop(dev);
test_PDC_GetTemperatureTypeList(dev);
test_PDC_GetShutterSpeedPrecision(dev);
test_PDC_GetLinkSpeed(dev);
test_PDC_GetEthernetSpeedLimit(dev);
}
    
    