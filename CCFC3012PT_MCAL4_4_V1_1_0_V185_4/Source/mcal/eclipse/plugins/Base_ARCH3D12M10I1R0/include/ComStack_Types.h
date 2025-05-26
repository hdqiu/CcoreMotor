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
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    ComStack_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of MCAL driver.
*
*   @addtogroup ComStack_Types
*   @{
*/

#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/*==============================================INCLUDE FILES=======================================*/
#include "StandardTypes.h"

/**
* @brief  Action has been successfully finished
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_OK           0x00

/**
* @brief  Message not successfully received or sent out
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_NOT_OK     0x01

/**
* @brief  Timer N_Ar/N_As has passed its time-out value N_Asmax/N_Armax
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_TIMEOUT_A  0x02

/**
* @brief  Timer N_Bs has passed its time-out value N_Bsmax
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_TIMEOUT_BS 0x03

/**
* @brief  Timer N_Cr has passed its time-out value N_Crmax
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_TIMEOUT_CR 0x04

/**
* @brief  Unexpected sequence number (PCI.SN) value received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_WRONG_SN   0x05

/**
* @brief  Invalid or unknown FlowStatus value has been received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_INVALID_FS 0x06

/**
* @brief  Unexpected protocol data unit received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_UNEXP_PDU  0x07

/**
* @brief  Flow control WAIT frame that exceeds the maximum counter N_WFTmax received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_WFT_OVRN   0x08

/**
* @brief  Flow control (FC) N_PDU with FlowStatus = OVFLW received
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_ABORT  0x09

/**
* @brief  Indicates an abort of a transmission.
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_NO_BUFFER  0x0A

/**
* @brief  Requested cancellation has been executed
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_CANCELATION_OK 0x0B

/**
* @brief  Request cancellation has not been executed
*         Due to an internal error the requested cancelation has not been executed.
*         This will happen e.g. if the to be canceled transmission has been executed already.
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_CANCELATION_NOT_OK 0x0C

/**
* @brief  The parameter change request has been successfully executed
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_PARAMETER_OK  0x0D

/**
* @brief  The request for the change of the parameter did not complete successfully
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_PARAMETER_NOT_OK  0x0E

/**
* @brief  The parameter change request not executed successfully due to an ongoing reception
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_RX_ON 0x0F

/**
* @brief  The parameter change request not executed successfully due to a wrong value
* @details   General return codes for NotifResultType
*/
#define NTFRSLT_E_VALUE_NOT_OK 0x10

/**
* @brief   There is no bus transceiver error seen or transceiver does not support the detection
*          of bus errors
* @details   General return codes for BusTrcvErrorType
*/
#define BUSTRCV_OK           0x00

/**
* @brief  Bus transceiver detected an unclassified error
* @details   General return codes for BusTrcvErrorType
*/
#define BUSTRCV_E_ERROR      0x01


/** 
* @brief   Variables of the type NetworkHandleType are used to store the identifier 
*          of a communication channel.
* @implements NetworkHandleType_type
*/
typedef uint8        NetworkHandleType;  

typedef uint16       PduIdType;
typedef uint32       PduLengthType;

typedef struct {
    P2VAR(uint8, AUTOMATIC, AUTOSAR_COMSTACKDATA) SduDataPtr;
    PduLengthType  SduLength;                                   
} PduInfoType;

typedef uint8        IcomConfigIdType;

typedef enum {
    ICOM_SWITCH_E_OK = 0,
    ICOM_SWITCH_E_FAILED = 1
} IcomSwitch_ErrorType;

typedef enum
{
  BUFREQ_OK,
  BUFREQ_E_NOT_OK,
  BUFREQ_E_BUSY,
  BUFREQ_E_OVFL
} BufReq_ReturnType;

#ifdef __cplusplus 
}
#endif
#endif 

