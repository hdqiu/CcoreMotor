
#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "CanIf.h"
#include "Can_Cfg.h"
#include "Can_LLDriver.h"
#include "Can.h"
#include "cc_printf.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication \
( \
    VAR(uint8, CANIF_VAR) ControllerId,\
    VAR(Can_ControllerStateType, CANIF_VAR) ControllerMode \
)
{
    (void)ControllerId;
    if (ControllerMode == CAN_CS_STARTED)
    {
        CANIF_PRINTF("CanIf_ControllerModeIndication mode is CAN_CS_STARTED\n");
    }
    else if (ControllerMode == CAN_CS_STOPPED)
    {
        CANIF_PRINTF("CanIf_ControllerModeIndication mode is CAN_CS_STOPPED\n");
    }
    else
    {
        /*nothing to do*/
    }
}

FUNC(void, CANIF_CODE) CanIf_TxConfirmation(VAR(PduIdType, CANIF_VAR) CanTxPduId)
{
    (void)CanTxPduId;
    // do nothing
    CANIF_PRINTF("CanTxPduId[%x]\n", CanTxPduId);
}

FUNC(void, CANIF_CODE) CanIf_RxIndication \
( \
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_CONST) Mailbox, \
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr \
)
{
    VAR(Can_HwType, AUTOMATIC) MailboxInfo = {0U};
    (void)MailboxInfo;
    VAR(PduInfoType, AUTOMATIC) PduInfo = {0U};
    #if (CAN_FD_MODE_ENABLE == STD_ON)
    VAR(uint8, AUTOMATIC) SduData[64] = {0U};
    #else
    VAR(uint8, AUTOMATIC) SduData[8] = {0U};
    #endif

    CANIF_PRINTF("CanIf_RxIndication start\n");
    VAR(uint32, AUTOMATIC) index = 0U;
    MailboxInfo.CanId = Mailbox->CanId;
    MailboxInfo.ControllerId = Mailbox->ControllerId;
    MailboxInfo.Hoh = Mailbox->Hoh;
    for (index = 0U; index < PduInfoPtr->SduLength; index++) {
        SduData[index] = PduInfoPtr->SduDataPtr[index];
    }
    PduInfo.SduDataPtr = SduData;
    PduInfo.SduLength = PduInfoPtr->SduLength;
    CANIF_PRINTF("Hoh[%d] CanId[0x%x] SduLength[%d] ", MailboxInfo.Hoh, \
            MailboxInfo.CanId, PduInfoPtr->SduLength);/* polyspace RTE:IDP */
    CANIF_PRINTF("data[ ");
    for (uint8 i = 0; i < PduInfo.SduLength; i++) {
        CANIF_PRINTF("%x ", PduInfo.SduDataPtr[i]);
    }
    CANIF_PRINTF("]\n");
}

FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(VAR(uint8, CANIF_VAR) ControllerId)
{
	(void)ControllerId;
    CANIF_PRINTF("CanIf_ControllerBusOff start\n");
    // do nothing
}

FUNC(boolean, COM_APPL_CODE) Can_LPduReceiveCalloutFunction \
( \
    VAR(uint8, AUTOMATIC) Hrh, \
    VAR(Can_IdType, AUTOMATIC) CanId, \
    VAR(uint8, AUTOMATIC) CanDlc, \
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr \
)
{
    (void)Hrh;
    (void)CanId;
    (void)CanDlc;
    (void)CanSduPtr;
    CANIF_PRINTF("Can_LPduReceiveCalloutFunction start\n");
    return TRUE;
}

FUNC(void, CAN_CODE) CallBack_ErrorController(void)
{
    CANIF_PRINTF("CallBack_ErrorController start\n");
}

FUNC(void, CAN_CODE) CallBack_MRAFN(void)
{
    CANIF_PRINTF("CallBack_MRAFN start\n");
}

FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit \
( \
    VAR(PduIdType, CANIF_VAR) TxPduId, \
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr \
)
{
    (void)TxPduId;
    CANIF_PRINTF("CanIf_TriggerTransmit start\n");
    VAR(uint32, AUTOMATIC) index = 0U;
    for (index = 0U; index < PduInfoPtr->SduLength; index++)
    {
        PduInfoPtr->SduDataPtr[index] = 0x88;
    }
    return (Std_ReturnType)E_OK;
}

#ifdef __cplusplus
}
#endif

