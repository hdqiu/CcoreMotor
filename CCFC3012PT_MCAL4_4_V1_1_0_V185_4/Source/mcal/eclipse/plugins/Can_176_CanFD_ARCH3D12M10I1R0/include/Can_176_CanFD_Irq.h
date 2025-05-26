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
*   @file    Can_176_CanFD_Irq.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFd MCAL driver.
*
*   @addtogroup CanFd
*   @{
*/

#ifndef CAN_176_CANFD_IRQ_H
#define CAN_176_CANFD_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Can_176_CanFD.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_IRQ_H_VENDOR_ID                     176
#define CAN_176_CANFD_IRQ_H_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_IRQ_H_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_IRQ_H_AR_REL_REV_VER                0
#define CAN_176_CANFD_IRQ_H_SW_MAJOR_VER                  1
#define CAN_176_CANFD_IRQ_H_SW_MINOR_VER                  0
#define CAN_176_CANFD_IRQ_H_SW_PATCH_VER                  1

#if (CAN_176_CANFD_CFG_H_VENDOR_ID != CAN_176_CANFD_IRQ_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_IRQ_H_VENDOR_ID "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER != CAN_176_CANFD_IRQ_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_IRQ_H_AR_REL_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER != CAN_176_CANFD_IRQ_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_IRQ_H_AR_REL_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_REV_VER != CAN_176_CANFD_IRQ_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_IRQ_H_AR_REL_REV_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MAJOR_VER != CAN_176_CANFD_IRQ_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_IRQ_H_SW_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MINOR_VER != CAN_176_CANFD_IRQ_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_IRQ_H_SW_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_PATCH_VER != CAN_176_CANFD_IRQ_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_IRQ_H_SW_PATCH_VER "
#endif

#define CANFD_START_SEC_CODE
#include "Canfd_MemMap.h"

FUNC(void, CAN_CODE) ISR_CANFD1_0(void);
FUNC(void, CAN_CODE) ISR_CANFD9_0(void);

#define CANFD_STOP_SEC_CODE
#include "Canfd_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif

#endif
