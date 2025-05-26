/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*  
*****************************************************************************/

/**
*   @file    CanIf_Cbk.h
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanIf
*
*   @addtogroup CanIf
*   @{
*/

#ifndef CANIF_CBK_H
#define CANIF_CBK_H

#ifdef  __cplusplus
extern "C"
{
#endif
#include "CanIf_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_CBK_VENDOR_ID                         176
#define CANIF_CBK_MODULE_ID                         60
#define CANIF_CBK_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_CBK_AR_RELEASE_MINOR_VERSION          4
#define CANIF_CBK_AR_RELEASE_REVISION_VERSION       0
#define CANIF_CBK_SW_MAJOR_VERSION                  1
#define CANIF_CBK_SW_MINOR_VERSION                  0
#define CANIF_CBK_SW_PATCH_VERSION                  1

FUNC(void, CANIF_CODE) CanIf_TxConfirmation(VAR(PduIdType, CANIF_VAR) CanTxPduId);
FUNC(void, CANIF_CODE) CanIf_RxIndication \
( \
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_CONST) Mailbox, \
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr \
);
FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(VAR(uint8, CANIF_VAR) ControllerId);
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication \
( \
    VAR(uint8, CANIF_VAR) ControllerId, \
    VAR(Can_ControllerStateType, CANIF_VAR) ControllerMode \
);
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit \
( \
    VAR(PduIdType, CANIF_VAR) TxPduId, \
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr \
);
FUNC(boolean, COM_APPL_CODE) Can_LPduReceiveCalloutFunction \
( \
    VAR(uint8, AUTOMATIC) Hrh, \
    VAR(Can_IdType, AUTOMATIC) CanId, \
    VAR(uint8, AUTOMATIC) CanDlc, \
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr \
);
FUNC(void,CAN_CODE) CallBack_ErrorController(void);
FUNC(void,CAN_CODE) CallBack_MRAFN(void);

#ifdef __cplusplus
}
#endif

#endif                          /* CANIF_CBK_H */

/** @} */

