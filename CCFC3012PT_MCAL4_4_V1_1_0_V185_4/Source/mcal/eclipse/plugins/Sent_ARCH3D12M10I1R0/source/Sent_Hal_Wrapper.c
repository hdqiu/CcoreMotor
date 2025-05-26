
#include "Sent_Hal_Wrapper.h"
#include "Sent_LLDriver.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define SENT_VENDOR_ID_C                 176
#define SENT_AR_MAJOR_VER_C              4
#define SENT_AR_MINOR_VER_C              4
#define SENT_AR_PATCH_VER_C              0
#define SENT_SW_MAJOR_VER_C              1
#define SENT_SW_MINOR_VER_C              0
#define SENT_SW_PATCH_VER_C              1

/*============================================FILE VERSION CHECKS===================================*/

/* Check if current file and SENT header file are of the same vendor */
#if (SENT_VENDOR_ID_C != SENT_VENDOR_ID)
#error "NON-MATCHED DATA : SENT_VENDOR_ID"
#endif

/* Check if current file and SENT header file are of the same Autosar version */
#if (SENT_AR_MAJOR_VER_C != SENT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER"
#endif
#if (SENT_AR_MINOR_VER_C != SENT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER"
#endif
#if (SENT_AR_PATCH_VER_C != SENT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER"
#endif

/* Check if current file and SENT header file are of the same Software version */
#if (SENT_SW_MAJOR_VER_C != SENT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER"
#endif
#if (SENT_SW_MINOR_VER_C != SENT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER"
#endif
#if (SENT_SW_PATCH_VER_C != SENT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER"
#endif

FUNC(void, SENT_CODE) Sent_Hal_Wrapper_Init
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId
)
{

    VAR(uint8, AUTOMATIC) u8SentModule = 0u;
    VAR(uint8, AUTOMATIC) u8SentChannel = 0u;
    uint32 u32RxPrescaler = 0u;

    u8SentModule = (uint8)(((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) >> (uint8)SENT_MODULE_SHIFT) & (uint8)0x7);
    u8SentChannel = (uint8)((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) & (uint8)0x1F);

    /* Set register time base */
    SRX_LLD_SetTimestampPrescaler(u8SentModule, (uint8)(pSent_ConfigPtr->u8TimestampPrescaler - 1u));

    /* pre-scaler and compensation */
    u32RxPrescaler = SRX_LLD_ComputeChannelPrescaler(pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8TickDuration, pSent_ConfigPtr->u32SentClkFreq);
    SRX_LLD_SetChannelPrescaler(u8SentModule, u8SentChannel, (uint16)u32RxPrescaler);

    /* Setup diagnostics */
    SRX_LLD_InitDiag(u8SentModule, u8SentChannel, &(pSent_ConfigPtr->pChanCfgPtr[ChannelId].sSentDiagCfg));

    /* Setup fast messages */
    SRX_LLD_InitFastMsg(u8SentModule, u8SentChannel, &(pSent_ConfigPtr->pChanCfgPtr[ChannelId].sSentFastMsg));/*PRQA S 0431*/

    SRX_LLD_SetSlowRxInterrupt(u8SentModule, u8SentChannel, TRUE);
    SRX_LLD_SetFastRxInterrupt(u8SentModule, u8SentChannel, TRUE);

    /* Setup fast messages */
    SRX_LLD_InitFastMsg(u8SentModule, u8SentChannel, &(pSent_ConfigPtr->pChanCfgPtr[ChannelId].sSentFastMsg));/*PRQA S 0431*/

    /* Setup slow messages */
    SRX_LLD_InitSlowMsg(u8SentModule, u8SentChannel, &(pSent_ConfigPtr->pChanCfgPtr[ChannelId].sSentSlowMsg));

    /* Enable peripheral */
    SRX_LLD_SetPeripheralStatus(u8SentModule, TRUE);

}

FUNC(void, SENT_CODE) Sent_Hal_Wrapper_SetChannel
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    VAR(Sent_StatType, AUTOMATIC) Operation
)
{

    VAR(boolean, AUTOMATIC) Flag;
    VAR(uint8, AUTOMATIC) u8SentModule = (uint8)(((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) >> (uint8)SENT_MODULE_SHIFT) & (uint8)0x7);
    VAR(uint8, AUTOMATIC) u8SentChannel = (uint8)((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) & (uint8)0x1F);
    
    Flag = ((Operation == SENT_ENABLE) ? true : false);

    /* Set channel */
    SRX_LLD_SetChannelStatus(u8SentModule, u8SentChannel, Flag);
}

FUNC(uint32, SENT_CODE) Sent_Hal_Wrapper_ReadData
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId
)
{
    srx_raw_msg_t locMsg = 
    {
        .dataField0 = 0U,
        .dataField1 = 0U,
        .dataField2 = 0U
    };

    VAR(uint8, AUTOMATIC) u8SentModule = (uint8)(((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) >> (uint8)SENT_MODULE_SHIFT) & (uint8)0x7);
    VAR(uint8, AUTOMATIC) u8SentChannel = (uint8)((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) & (uint8)0x1F);
    SRX_LLD_GetFastRawMsg(u8SentModule, u8SentChannel, &locMsg);

    return locMsg.dataField0;
}

FUNC(void, SENT_CODE) Sent_Hal_Wrapper_ReadSerialData
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2VAR(Sent_RxSerialDataType, AUTOMATIC, SENT_APPL_DATA) pDataPtr
)
{
    srx_slow_msg_t msg;
    VAR(uint8, AUTOMATIC) u8SentModule = (uint8)(((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) >> (uint8)SENT_MODULE_SHIFT) & (uint8)0x7);
    VAR(uint8, AUTOMATIC) u8SentChannel = (uint8)((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) & (uint8)0x1F);

    SRX_LLD_GetSlowMsg(u8SentModule, u8SentChannel, &msg);

    pDataPtr->Data = msg.data;
    pDataPtr->MsgId = msg.id;
    pDataPtr->Configuration = (uint8)msg.type;
    pDataPtr->CRC = msg.crc;
}

FUNC(void, SENT_CODE) Sent_Hal_Wrapper_ReadChannelStatus
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId,
    P2VAR(Sent_ChanStatusType, AUTOMATIC, SENT_APPL_DATA) pStatPtr
)
{
    srx_slow_msg_t msg;
    VAR(uint8, AUTOMATIC) u8SentModule = (uint8)(((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) >> (uint8)SENT_MODULE_SHIFT) & (uint8)0x7);
    VAR(uint8, AUTOMATIC) u8SentChannel = (uint8)((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) & (uint8)0x1F);

    SRX_LLD_GetSlowMsg(u8SentModule, u8SentChannel, &msg);

    pStatPtr->RxCRC = msg.crc;
    pStatPtr->RxTimeStamp = msg.timeStamp;
    SRX_LLD_GetEvents(u8SentModule, u8SentChannel, &(pStatPtr->ChanStat));
    pStatPtr->IntSata = SRX_HW_GetSlowRxStatus(u8SentModule, u8SentChannel);

}

FUNC(void, SENT_CODE) Sent_Hal_Wrapper_DeInit
(
    VAR(Sent_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(uint8, AUTOMATIC) u8SentModule = (uint8)(((pSent_ConfigPtr->pChanCfgPtr[ChannelId].u8ChannelId) >> (uint8)SENT_MODULE_SHIFT) & (uint8)0x7);
    SRX_LLD_Deinit(u8SentModule);
}
