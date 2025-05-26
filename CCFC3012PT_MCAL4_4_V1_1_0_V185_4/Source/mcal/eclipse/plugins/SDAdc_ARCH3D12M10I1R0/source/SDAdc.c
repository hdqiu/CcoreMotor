/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc.c
* @version  1.0
* @date     2024 - 02 - 28
* @brief    Initial version.
*
*****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

#include "SDAdc.h"
#include "SDAdc_LLDriver.h"
#include "eDma.h"
#ifdef RESOURCE_SUPPORT_SDADC_IP
#define SDADC_C_VENDOR_ID                     176
#define SDADC_C_AR_REL_MAJOR_VER              4
#define SDADC_C_AR_REL_MINOR_VER              4
#define SDADC_C_AR_REL_REV_VER                0
#define SDADC_C_SW_MAJOR_VER                  1
#define SDADC_C_SW_MINOR_VER                  0
#define SDADC_C_SW_PATCH_VER                  1

#if (SDADC_CFG_H_VENDOR_ID               != SDADC_C_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_C_VENDOR_ID "
#endif
#if (SDADC_CFG_H_AR_REL_MAJOR_VER    != SDADC_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_C_AR_REL_MAJOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_MINOR_VER    != SDADC_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_C_AR_REL_MINOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_REV_VER != SDADC_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_C_AR_REL_REV_VER "
#endif
#if (SDADC_CFG_H_SW_MAJOR_VER        != SDADC_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_C_SW_MAJOR_VER "
#endif
#if (SDADC_CFG_H_SW_MINOR_VER        != SDADC_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_C_SW_MINOR_VER "
#endif
#if (SDADC_CFG_H_SW_PATCH_VER        != SDADC_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_C_SW_PATCH_VER "
#endif

#if (STD_ON == SDADC_DEV_ERROR_DETECT)
#include "Det.h"
#endif
P2CONST(SdAdc_TotalConfigType, SDADC_CONST, SDADC_APPL_CONST) sdAdc_ConfigPtr[CORE_NUM] = {NULL_PTR};
static VAR(Sdadc_InitStateType, SDADC_VAR) Sdadc_InitState[CORE_NUM] = {SDADC_UNINIT};
VAR(Sdadc_ChannelDataType, SDADC_VAR) Sdadc_ChannelData[SDADC_INSTANCE_CDG_NUM][CORE_NUM];
CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) Adc_SdadcBase0[ADC_SDADC_MAX_INSTANCE] = SDADC_BASE_PTR_ARRAY;
VAR(Sdadc_ChannelType, SDADC_VAR) SDAdc_gIrqMapping[ADC_SDADC_MAX_INSTANCE][CORE_NUM] = {{0}};

#if (STD_ON == SDADC_DEV_ERROR_DETECT)
LOCAL_INLINE FUNC(void, SDADC_CODE) Sdadc_ReportError \
( \
    VAR(uint8, AUTOMATIC) u8Sdadc_ApiId, \
    VAR(uint8, AUTOMATIC) u8Sdadc_ErrorId \
);

LOCAL_INLINE FUNC(void, SDADC_CODE) Sdadc_ReportError \
( \
    VAR(uint8, AUTOMATIC) u8Sdadc_ApiId, \
    VAR(uint8, AUTOMATIC) u8Sdadc_ErrorId \
)
{
    (void)Det_ReportError((uint16)SDADC_MODULE_ID, (uint8)0U, u8Sdadc_ApiId, u8Sdadc_ErrorId);
}

#if (SDADC_ENABLE_MULTICORE == STD_ON)
LOCAL_INLINE FUNC(uint8, ADC_VAR) Sdadc_CoreVerify(VAR(Sdadc_ChannelType, AUTOMATIC) ChannelId)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    VAR(uint8, AUTOMATIC) CurrentCoreId = (1U << u32Sdadc_ICoreId);
    VAR(uint8, AUTOMATIC) u8Sdadc_Coreflag = 0U; 

    u8Sdadc_Coreflag = (uint32)((CurrentCoreId) & (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_CoreMapItem[ChannelId].SdAdc_CoreId));
	return u8Sdadc_Coreflag;
}
#endif
#endif

FUNC(void, SDADC_CODE) Sdadc_Init(CONSTP2CONST(SdAdc_TotalConfigType, SDADC_CONST, SDADC_APPL_CONST) ConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_INITED)
    {
        Sdadc_ReportError(SDADC_SID_INIT, (uint8)SDADC_E_ALREADY_INITIALIZED);
    }
#if (SDADC_PRECOMPILE_SUPPORT == STD_ON)
    else if(ConfigPtr != NULL_PTR)
#else
    else if(ConfigPtr == NULL_PTR)
#endif
    {
        Sdadc_ReportError(SDADC_SID_INIT, (uint8)SDADC_E_PARAM_CONFIG);
    }
    else
    {
#endif
        sdAdc_ConfigPtr[u32Sdadc_ICoreId] = ConfigPtr;
        for(uint8 u8sdadc_ChIndex = 0U; u8sdadc_ChIndex < SDADC_INSTANCE_CDG_NUM; u8sdadc_ChIndex++)
        {
#if (SDADC_ENABLE_MULTICORE == STD_ON)
            VAR(uint8, AUTOMATIC) CurrentCoreId = SDAdc_GetCoreID();  /*Get Core ID */
            if(((CurrentCoreId) & (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_CoreMapItem[u8sdadc_ChIndex].SdAdc_CoreId)) != 0U)
            {
#endif
                SDADC_LLD_Init( \
                    sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_InstanceId, \
                    sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_Config, \
                    (uint16)sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_HwTrigSrc 
                );
                Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelResBuffer = NULL_PTR;
                Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelStatus = SDADC_IDLE;
                Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes = (Sdadc_SizeType)0U;
                Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize = (Sdadc_SizeType)0U;
#if (SDADC_ENABLE_MULTICORE == STD_ON)
            }
#endif
        }
        Sdadc_InitState[u32Sdadc_ICoreId] = SDADC_INITED;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}

FUNC(void, SDADC_CODE) Sdadc_DeInit(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_DEINIT, (uint8)SDADC_E_UNINIT);
    }
    else
    {
#endif
        for(uint8 u8sdadc_ChIndex = 0U; u8sdadc_ChIndex < SDADC_INSTANCE_CDG_NUM; u8sdadc_ChIndex++)
        {
#if (SDADC_ENABLE_MULTICORE == STD_ON)
            VAR(uint8, AUTOMATIC) CurrentCoreId = SDAdc_GetCoreID(); /*Get Core ID*/
            if(((CurrentCoreId) & (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_CoreMapItem[u8sdadc_ChIndex].SdAdc_CoreId)) != 0U)
            {
#endif
            SDADC_LLD_DeInit(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_InstanceId);
            Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelResBuffer = NULL_PTR;
            Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelStatus = SDADC_IDLE;
            Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes = (Sdadc_SizeType)0U;
            Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize = (Sdadc_SizeType)0U;
#if (SDADC_ENABLE_MULTICORE == STD_ON)
            }
#endif
        }
        sdAdc_ConfigPtr[u32Sdadc_ICoreId] = NULL_PTR;
        Sdadc_InitState[u32Sdadc_ICoreId] = SDADC_UNINIT;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StartModulation(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#ifdef CCFC3007PT
    VAR(uint32, SDADC_VAR) Sdadc_HwTrigSrcAddr[] =
    {
        0x00U,
        0x01U,
        0x02U,
        0x03U,
        0x04U,
        0x05U,
        0x0cU,
        0x0dU,
        0x0eU,
        0x0fU,
        0x10U,
        0x11U,
        0x12U,
        0x13U,
        0x14U,
        0x15U,
        0x16U,
        0x17U,
        0x18U,
        0x19U,
        0x1aU,
        0x1bU,
        0x1cU,
        0x1dU,
        0x1eU,
        0x1fU,
        0x40U,
        0x40U,
        0x40U,
        0x40U,
        0x40U,
        0x40U,
        0x07U,
        0x07U,
        0x60U,
        0x60U,
        0x06U, 
        0x06U,
        0x06U,
        0x20U,
        0x20U,
        0x08U,
        0x09U,
        0x10U,
        0x11U,
        0x12U,
        0x13U,
        0x14U,
        0x15U,   
    };
#endif

#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_START_MODULATION, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_START_MODULATION, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_START_MODULATION, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        if((Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize != 0U) || (Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer != NULL_PTR))
        {
            VAR(uint32, SDADC_VAR) WaterMarkerValue = 0U;
            VAR(uint32, SDADC_VAR) major_loop_time, minor_transfer_byte = 0U;
            VAR(Std_ReturnType, SDADC_VAR) DmaRet = (Std_ReturnType)E_NOT_OK;
            CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId];
//            VAR(Sdadc_InstanceType, SDADC_VAR) esdadc_Instance = SDADC_INSTANCE_0;
            WaterMarkerValue = BasePtr->FCFG.B.FIFOWM;
            if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize < (uint16)WaterMarkerValue)
            {
                BasePtr->FCFG.B.FIFOWM = (uint8)Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize;
                WaterMarkerValue = BasePtr->FCFG.B.FIFOWM;
            }

            if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_ConvMethod == SDADC_USE_INTERRUPT)
            {
                SDAdc_gIrqMapping[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId][u32Sdadc_ICoreId] = ChannelId;
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_BUSY;
            }
            else if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_ConvMethod == SDADC_USE_DMA)
            {
//                major_loop_time = (uint32)(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize);
//                minor_transfer_byte = 1U * sizeof(uint32);
                minor_transfer_byte = WaterMarkerValue * sizeof(uint32);
                major_loop_time = (uint32)(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize / WaterMarkerValue);

                VAR(eDMALoopTransferConfigType, SDADC_VAR) sdadcLoopConfig =
                {
                    .dstAddrOffsetEn    = TRUE,
                    .srcAddrOffsetEn    = FALSE,
                    .minorLpOffset      = 0,
                    .minorLpLinkEn      = FALSE,
                    .minorLpLinkChn     = 0U,
                    .majorLpLinkEn      = FALSE,
                    .majorLpLinkChn     = 0U,
                    .majorLpIterCnt     = major_loop_time
                };

                VAR(eDMATransferConfigType, SDADC_VAR) dmaConfigforsdadc =
                {
                    .srcAddr = (uint32)(&BasePtr->FDATA.R), /* Modified by function */
                    .destAddr = (uint32)Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer, /* Modified by function */
                    .srcTransDataSize = EDMA_TRANSFER_SIZE_4B,
                    .destTransDataSize = EDMA_TRANSFER_SIZE_4B,
                    .srcAddrOffset = (sint16)0,
                    .destAddrOffset = (sint16)sizeof(uint32),
                    .srcAddrAdjustLast = 0,
                    .destAddrAdjustLast = -((sint32)major_loop_time * (sint32)minor_transfer_byte), /* Modified by function */
                    .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
                    .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
                    .minorTransByte = minor_transfer_byte, /* Modified by function */
                    .featureScatterGatherEn = FALSE,
                    .featureScatterGatherNextDescriptor = 0U,
                    .completeIntEn = TRUE,
                    .lpTransConfigPtr = &sdadcLoopConfig,
                };
                DmaRet = EDMA_SetLoopTransferConfig(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_Config->DmaCfg.DmaCh, &dmaConfigforsdadc);
                if(DmaRet == (Std_ReturnType)E_OK)
                {
                    EDMA_SetChnDisRequestsOnTransferComplete \
                    (
                        sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_Config->DmaCfg.DmaCh, \
                        sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_Config->DmaCfg.DreqEn \
                    );
                    DmaRet = EDMA_SetChannelRequest(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_Config->DmaCfg.DmaCh);
                    if(DmaRet == (Std_ReturnType)E_OK)
                    {
                        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes = Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize;
                        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_RESULT_READY;
                    }
                }
            }
            else
            {
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_BUSY;
            }
            
            SDADC_LLD_ModuleEnable(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId);
            if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_SwOrHw == (uint8)SOFTWARE_TRIG)
            {
                SDADC_LLD_SetSoftTrigger(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId);
            }
            else
            {
#ifdef CCFC3007PT
                if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigRegId == SDADC_TRIGREG_DISABLE)
                {
#endif
                    if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigSrc >= (Sdadc_HwTrigChSelType)HWTRIGSEL_SDADC0)
                    {
//                        switch(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigSrc)
//                        {
//                            case HWTRIGSEL_SDADC0:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_0;
//                                break;
//                            }
//                            case HWTRIGSEL_SDADC1:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_1;
//                                break;
//                            }
//                            case HWTRIGSEL_SDADC2:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_2;
//                                break;
//                            }
//                            case HWTRIGSEL_SDADC3:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_3;
//                                break;
//                            }
//                            case HWTRIGSEL_SDADC4:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_4;
//                                break;
//                            }
//#ifdef RESOURCE_SUPPORT_SDADC5
//                            case HWTRIGSEL_SDADC5:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_5;
//                                break;
//                            }
//#endif
//                            case HWTRIGSEL_SDADC6:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_6;
//                                break;
//                            }
//                            case HWTRIGSEL_SDADC7:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_7;
//                                break;
//                            }
//                            case HWTRIGSEL_SDADC8:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_8;
//                                break;
//                            }
//#ifdef RESOURCE_SUPPORT_SDADC9
//                            case HWTRIGSEL_SDADC9:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_9;
//                                break;
//                            }
//#endif
//#ifdef RESOURCE_SUPPORT_SDADC10
//                            case HWTRIGSEL_SDADC10:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_10;
//                                break;
//                            }
//#endif
//#ifdef RESOURCE_SUPPORT_SDADC11
//                            case HWTRIGSEL_SDADC11:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_11;
//                                break;
//                            }
//#endif
//#ifdef RESOURCE_SUPPORT_SDADC12
//                            case HWTRIGSEL_SDADC12:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_12;
//                                break;
//                            }
//#endif
//#ifdef RESOURCE_SUPPORT_SDADC13
//                            case HWTRIGSEL_SDADC13:
//                            {
//                                esdadc_Instance = SDADC_INSTANCE_13;
//                                break;
//                            }
//#endif
//                            default:
//                            {
//                                /*nothing*/
//                                break;
//                            }
//                        }
//                        SDADC_LLD_SetSoftTrigger(esdadc_Instance);
                    }
#ifdef RESOURCE_SUPPORT_SIUL2_IP
                }
                else
                {
                    switch(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigRegId)
                    {
                        case SDADC_TRIGREG_HW5:
                            SIUL2.ISEL9.B.EETSEL0ADV_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];
                            break;
                        case SDADC_TRIGREG_HW9:
                            SIUL2.ISEL5.B.CTSEL0_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];
                            break;
                        case SDADC_TRIGREG_HW11:
                            SIUL2.ISEL5.B.CTSEL1_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];
                            break;
                        case SDADC_TRIGREG_HW12:
                            SIUL2.ISEL4.B.CTSEL2_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];
                            break;
                        case SDADC_TRIGREG_HW13:
                            SIUL2.ISEL4.B.CTSEL3_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];
                            break;
                        case SDADC_TRIGREG_HW14:
                            SIUL2.ISEL4.B.CTSEL4_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];
                            break;
                        case SDADC_TRIGREG_HW15:
                            SIUL2.ISEL4.B.CTSEL5_A = Sdadc_HwTrigSrcAddr[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_HwTrigChID];
                            break;
                        default:
                            /*Nothing to do*/
                            break;
                    }
                }
#endif                
            }
            RetVal = (Std_ReturnType)E_OK;
        }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StopModulation(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_STOP_MODULATION, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_STOP_MODULATION, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_STOP_MODULATION, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId];
        if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_ConvMethod == SDADC_USE_INTERRUPT)
        {
            SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, FALSE);
        }
        SDADC_LLD_ResetFifo(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId);
        SDADC_LLD_ModuleDisable(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId);
        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_IDLE;
        SDAdc_gIrqMapping[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId][u32Sdadc_ICoreId] = 0U;
        RetVal = (Std_ReturnType)E_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Sdadc_SizeType, SDADC_CODE) Sdadc_ReadStreamResults \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId, \
    CONSTP2VAR(Sdadc_ResultType, SDADC_CONST, SDADC_APPL_CONST) ResultLinearBufferPtr \
)
{
    VAR(Sdadc_SizeType, SDADC_VAR) u16sdadc_Size = SDADC_READSTREAM_ERROR;
    VAR(Sdadc_SizeType, SDADC_VAR) u16sdadc_BufferCount;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, (uint8)SDADC_E_UNINIT);
    }
    else if(NULL_PTR == ResultLinearBufferPtr)
    {
        Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, (uint8)SDADC_E_PARAM_POINTER);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferMode == SDADC_STREAM_LINEAR_BUFFER)
        {
            if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus == SDADC_RESULT_READY)
            {
                u16sdadc_Size = Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes;
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes = (Sdadc_SizeType)0U;
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_BUSY;
                for(u16sdadc_BufferCount = 0U; u16sdadc_BufferCount < u16sdadc_Size; u16sdadc_BufferCount++)
                {
                    ResultLinearBufferPtr[u16sdadc_BufferCount] = (Sdadc_ResultType)Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer[u16sdadc_BufferCount];
                }
            }
        }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
        else
        {
            Sdadc_ReportError(SDADC_SID_READ_STREAM_RESULTS, (uint8)SDADC_E_INV_LINEAR_BUFFER_CONFIG);
        }
    }
#endif
    return u16sdadc_Size;
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_ReadResult \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId, \
    CONSTP2VAR(Sdadc_ResultType, SDADC_CONST, SDADC_APPL_CONST) ResultPtr \
)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    VAR(uint32, AUTOMATIC) u32Sdadc_Result = 0U;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_READ_RESULT, (uint8)SDADC_E_UNINIT);
    }
    else if(NULL_PTR == ResultPtr)
    {
        Sdadc_ReportError(SDADC_SID_READ_RESULT, (uint8)SDADC_E_PARAM_POINTER);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_READ_RESULT, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_READ_RESULT, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus == SDADC_RESULT_READY)
		{
        	if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferMode == SDADC_STREAM_LINEAR_BUFFER)
			{
                u32Sdadc_Result = (SDADC_LLD_GetFifoData(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId) & 0xFFFFU);
				*ResultPtr = (Sdadc_ResultType)u32Sdadc_Result;
				Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_BUSY;
			}
        	else
        	{
        		*ResultPtr = (Sdadc_ResultType)Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer[Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes];
        	}
        	RetVal = (Std_ReturnType)E_OK;
        }
      
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Sdadc_ChannelStatusType, SDADC_CODE) Sdadc_GetStatus(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(Sdadc_ChannelstatusType, SDADC_VAR) RetVal = SDADC_IDLE;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_STATUS, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_GET_STATUS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_STATUS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        RetVal = Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_SetupResultBuffer \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId,\
	P2VAR(uint32, SDADC_VAR, SDADC_APPL_CONST) DataBufferPtr, \
    CONST(Sdadc_SizeType, SDADC_CONST) Size \
)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else if(DataBufferPtr == NULL_PTR)
    {
        Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_PARAM_POINTER);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus == SDADC_IDLE)
        {
            if((Size != (Sdadc_SizeType)0U) && (Size <= (Sdadc_SizeType)SDADC_MAX_BUFFER_LENGTH))
            {
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer = DataBufferPtr;
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize = Size;
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes = 0x0U;
                RetVal = (Std_ReturnType)E_OK;
            }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
            else
            {
                Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_INV_BUFFER_SIZE);
            }
#endif
        }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
        else
        {
            Sdadc_ReportError(SDADC_SID_SETUP_RESULT_BUFFER, (uint8)SDADC_E_UNIDLE);
        }
    }
#endif
    return RetVal;
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StartCarrierSignal(void) //not supported
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_START_CARRIER_SIGNAL, (uint8)SDADC_E_UNINIT);
    }
    else
    {
#endif
        //chip not support
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StopCarrierSignal(void) //not supported
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_STOP_CARRIER_SIGNAL, (uint8)SDADC_E_UNINIT);
    }
    else
    {
#endif
        //chip not support
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(void, SDADC_CODE) Sdadc_EnableNotifications(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_ENABLE_NOTIFICATIONS, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_ENABLE_NOTIFICATIONS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else if((sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_NewResultNotify == NULL_PTR)
        && (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferFullNotifyPtr == NULL_PTR))
    {
        Sdadc_ReportError(SDADC_SID_ENABLE_NOTIFICATIONS, (uint8)SDADC_E_NOTIF_CAPABILITY);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_ENABLE_NOTIFICATIONS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NotifyStatus = TRUE;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}

FUNC(void, SDADC_CODE) Sdadc_DisableNotifications(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_DISABLE_NOTIFICATIONS, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_DISABLE_NOTIFICATIONS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else if((sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_NewResultNotify == NULL_PTR)
        && (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferFullNotifyPtr == NULL_PTR))
    {
        Sdadc_ReportError(SDADC_SID_DISABLE_NOTIFICATIONS, (uint8)SDADC_E_NOTIF_CAPABILITY);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_DISABLE_NOTIFICATIONS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NotifyStatus = FALSE;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}

FUNC(Sdadc_TimeStampType, SDADC_CODE) Sdadc_GetTimestamp(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Sdadc_TimeStampType, SDADC_VAR) RetVal = 0;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_TIMESTAMP, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_GET_TIMESTAMP, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_TIMESTAMP, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#else
    (void)ChannelId;
#endif
        //chip not support
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StartCalibration(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId];
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_START_CALIBRATION, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_START_CALIBRATION, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_START_CALIBRATION, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
    if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus == SDADC_IDLE)
    {
        SDADC_FCFGM_SetCalibEnDis(BasePtr, TRUE);
        RetVal = (Std_ReturnType)E_OK;
    }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Sdadc_CalibrationStatusType, SDADC_CODE) Sdadc_GetCalibrationStatus(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Sdadc_CalibrationStatusType, SDADC_VAR) RetVal = 0U;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_CALIBRATION_STATUS, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_GET_CALIBRATION_STATUS, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_CALIBRATION_STATUS, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#else
    (void)ChannelId;
#endif
    
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_InitCheck(CONSTP2CONST(SdAdc_TotalConfigType, SDADC_CONST, SDADC_APPL_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if((ConfigPtr == NULL_PTR) || (Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}

FUNC(void, SDADC_CODE) Sdadc_GetVersionInfo(CONSTP2VAR(Std_VersionInfoType, SDADC_CONST, SDADC_APPL_CONST) versioninfo)
{
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
	VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_VERSION_INFO, (uint8)SDADC_E_UNINIT);
    }
    else if(versioninfo == NULL_PTR)
    {
        Sdadc_ReportError(SDADC_SID_GET_VERSION_INFO, (uint8)SDADC_E_PARAM_POINTER);
    }
    else
    {
#endif
        versioninfo->moduleID = (uint16)SDADC_MODULE_ID;
        versioninfo->vendorID = (uint16)SDADC_CFG_H_VENDOR_ID;
        versioninfo->sw_major_version = (uint8)SDADC_CFG_H_SW_MAJOR_VER;
        versioninfo->sw_minor_version = (uint8)SDADC_CFG_H_SW_MINOR_VER;
        versioninfo->sw_patch_version = (uint8)SDADC_CFG_H_SW_PATCH_VER;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_RestartDemodulator(CONST(Sdadc_ChannelMaskType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    (void)ChannelId;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_RESTART_DEMODULATOR, (uint8)SDADC_E_UNINIT);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify((Sdadc_ChannelType)ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_RESTART_DEMODULATOR, SDADC_E_PARAM_ERROR);
    }
#endif /* (SDADC_ENABLE_MULTICORE == STD_ON) */
    else
    {
#endif /* (STD_ON == SDADC_DEV_ERROR_DETECT) */
        RetVal = (Std_ReturnType)E_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Sdadc_IrmsValueType, SDADC_CODE) Sdadc_GetIrmsValue(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Sdadc_IrmsValueType, SDADC_VAR) RetVal = 0;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_IRMS_VALUE, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_GET_IRMS_VALUE, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_IRMS_VALUE, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#else
    (void)ChannelId;
#endif
    
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_SetGainCorrRegValue \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId, \
    CONST(Sdadc_GainCorrType, SDADC_CONST) RegValue \
)
{
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_InstanceId];
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_SET_GAINCORR_REG_VALUE, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_SET_GAINCORR_REG_VALUE, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else if(RegValue > 0x1CU)
    {
        Sdadc_ReportError(SDADC_SID_SET_GAINCORR_REG_VALUE, (uint8)SDADC_E_PARAM_ERROR);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_SET_GAINCORR_REG_VALUE, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#endif
        BasePtr->GAINCORR.B.CICSHIFT = RegValue;
        RetVal = (Std_ReturnType)E_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Std_ReturnType, SDADC_CODE) Sdadc_RestartIntegrator \
( \
    CONST(Sdadc_ChannelMaskType, SDADC_CONST) ChannelId, \
    CONST(Sdadc_DelayType, SDADC_CONST) Delay \
)
{
    VAR(uint32, SDADC_VAR) Instance_index = 0U;
    VAR(Std_ReturnType, SDADC_VAR) RetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_Maxinstance = 0U;
    u32Sdadc_Maxinstance = ((uint32)1U << ADC_SDADC_MAX_INSTANCE);
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_RESTART_INTEGRATOR, (uint8)SDADC_E_UNINIT);
    }
    else if((ChannelId == 0U) || (ChannelId >= u32Sdadc_Maxinstance))
    {
        Sdadc_ReportError(SDADC_SID_RESTART_INTEGRATOR, (uint8)SDADC_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        for(Instance_index = 0U; Instance_index < 16U; Instance_index++)
        {
            if(((uint32)((uint32)1U << Instance_index) & ChannelId) != 0U)
            {
#if (STD_ON == SDADC_DEV_ERROR_DETECT) && (SDADC_ENABLE_MULTICORE == STD_ON)
                if(Sdadc_CoreVerify((Sdadc_ChannelType)(Instance_index)) == 0U)
                {
                    Sdadc_ReportError(SDADC_SID_RESTART_INTEGRATOR, SDADC_E_PARAM_ERROR);
                }
                else
                {
#endif
                    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[Instance_index].Sdadc_InstanceId];
                    SDADC_DICFG_SetIntegratorTriggerMode(BasePtr, 0x0U);
#if (STD_ON == SDADC_DEV_ERROR_DETECT) && (SDADC_ENABLE_MULTICORE == STD_ON)
                }
#endif               
            }
        }
        for(uint32 i = 0; i < Delay; i++){}
        for(Instance_index = 0U; Instance_index < 16U; Instance_index++)
        {
        	if(((uint32)((uint32)1U << Instance_index) & ChannelId) != 0U)
            {
#if (STD_ON == SDADC_DEV_ERROR_DETECT) && (SDADC_ENABLE_MULTICORE == STD_ON)
                if(Sdadc_CoreVerify((Sdadc_ChannelType)(Instance_index)) == 0U)
                {
                    Sdadc_ReportError(SDADC_SID_RESTART_INTEGRATOR, SDADC_E_PARAM_ERROR);
                }
                else
                {
#endif
                    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[Instance_index].Sdadc_InstanceId];
                    SDADC_DICFG_SetIntegratorTriggerMode(BasePtr, (uint8)(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[Instance_index].Sdadc_Config->Integrator.IntegratorTrigMode));
#if (STD_ON == SDADC_DEV_ERROR_DETECT) && (SDADC_ENABLE_MULTICORE == STD_ON)
                }
#endif
            }
        }
        RetVal = (Std_ReturnType)E_OK;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(Sdadc_SdcapValueType, SDADC_CODE) Sdadc_GetSdcapValue(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId) //not supported
{
    VAR(Sdadc_SdcapValueType, SDADC_VAR) RetVal = 0U;
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_GET_SDCAP_VALUE, (uint8)SDADC_E_UNINIT);
    }
    else if(ChannelId >= ADC_SDADC_MAX_INSTANCE)
    {
        Sdadc_ReportError(SDADC_SID_GET_SDCAP_VALUE, (uint8)SDADC_E_PARAM_CHANNEL);
    }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    else if(Sdadc_CoreVerify(ChannelId) == 0U)
    {
        Sdadc_ReportError(SDADC_SID_GET_SDCAP_VALUE, SDADC_E_PARAM_ERROR);
    }
#endif
    else
    {
#else
    (void)ChannelId;
#endif
    
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
    return RetVal;
}

FUNC(void, SDADC_CODE) Sdadc_MainFunction(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    if(Sdadc_InitState[u32Sdadc_ICoreId] == SDADC_UNINIT)
    {
        Sdadc_ReportError(SDADC_SID_MAIN_FUNCTION, (uint8)SDADC_E_UNINIT);
    }
    else
    {
#endif
        for(uint8 u8sdadc_ChIndex = 0U; u8sdadc_ChIndex < SDADC_INSTANCE_CDG_NUM; u8sdadc_ChIndex++)
        {
            VAR(Sdadc_InstanceType, SDADC_VAR) instance = sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_InstanceId;
            VAR(uint32, SDADC_VAR) WaterMarkerValue = 0U;
            CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[instance];
            if((Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelStatus != SDADC_IDLE) && (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_ConvMethod == SDADC_USE_POLLING))
            {
                if(SDADC_LLD_GetWaterMarkerIntState(instance) == TRUE)
                {
                	WaterMarkerValue = BasePtr->FCFG.B.FIFOWM;
                	if(Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes < Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize)
                	{
                		for(uint32 i = 0U; i < WaterMarkerValue; i++)
						{
							Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelResBuffer[Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes] = (SDADC_LLD_GetFifoData(instance) & 0xFFFFU);
							Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes++;
							if((Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NotifyStatus == TRUE)
															&& (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_NewResultNotify != NULL_PTR))
							{
								sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_NewResultNotify();
							}
						}
                		SDADC_LLD_ClearWaterMarkerIntState(instance);
						if((Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize - Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes) < (uint16)WaterMarkerValue)
						{
							BasePtr->FCFG.B.FIFOWM = (uint8)(Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelBufferSize - Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes);
						}

						Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].ChannelStatus = SDADC_RESULT_READY;
                	}
                	else
                	{
                		if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_BufferMode != SDADC_STREAM_LINEAR_BUFFER)
						{
							Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NumofValidConRes = 0U;
						}
						else
						{
							if((Sdadc_ChannelData[u8sdadc_ChIndex][u32Sdadc_ICoreId].NotifyStatus == TRUE)
								&& (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_BufferFullNotifyPtr != NULL_PTR))
							{
								sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[u8sdadc_ChIndex].Sdadc_BufferFullNotifyPtr();
							}
						}
                	}
                }
            }
        }
#if (STD_ON == SDADC_DEV_ERROR_DETECT)
    }
#endif
}

#endif /*RESOURCE_SUPPORT_SDADC_IP*/

#ifdef __cplusplus
}
#endif


