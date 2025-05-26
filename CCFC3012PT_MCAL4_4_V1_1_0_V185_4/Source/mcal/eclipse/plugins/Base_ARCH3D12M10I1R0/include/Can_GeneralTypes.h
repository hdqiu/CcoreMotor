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
*   @file    Can_GeneralTypes.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/
#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/*==============================================INCLUDE FILES=======================================*/
#include "ComStack_Types.h"

/*
    [SWS_Can_00436] Can_GeneralTypes.h shall contain all types and constants that 
    are shared among the AUTOSAR CAN modules Can, CanIf and CanTrcv.
*/
#define CAN_BUSY 2U

typedef enum
{
    CAN_T_START,
    CAN_T_STOP,
    CAN_T_SLEEP,
    CAN_T_WAKEUP,
} Can_StateTransitionType;

typedef enum {
    CAN_CS_UNINIT = 0U,
    CAN_CS_STARTED,
    CAN_CS_STOPPED,
    CAN_CS_SLEEP
} Can_ControllerStateType;

typedef enum {
    CAN_ERRORSTATE_ACTIVE = 0U,
    CAN_ERRORSTATE_PASSIVE,
    CAN_ERRORSTATE_BUSOFF
} Can_ErrorStateType;

typedef uint32 Can_IdType;

typedef struct {
    PduIdType swPduHandle;
    uint8 length;
    Can_IdType id;
    uint8 *sdu;
} Can_PduType;

typedef uint16 Can_HwHandleType;

typedef struct {
    Can_IdType CanId ;
    Can_HwHandleType Hoh;
    uint8 ControllerId;
} Can_HwType;

#ifdef __cplusplus 
}
#endif

#endif 

