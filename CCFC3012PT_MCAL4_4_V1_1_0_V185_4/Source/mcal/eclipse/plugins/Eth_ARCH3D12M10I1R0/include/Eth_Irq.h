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
*   @file    Eth_Irq.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifndef ETH_IRQ_H
#define ETH_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "Eth_GeneralTypes.h" 

/**
****************************************************************************************
 * @brief: Eth.h Version
****************************************************************************************
*/
#define ETH_IRQ_H_VENDOR_ID                    176
#define ETH_IRQ_H_AR_REL_MAJOR_VER             4
#define ETH_IRQ_H_AR_REL_MINOR_VER             4
#define ETH_IRQ_H_AR_REL_REV_VER               0
#define ETH_IRQ_H_SW_MAJOR_VER                 1
#define ETH_IRQ_H_SW_MINOR_VER                 0
#define ETH_IRQ_H_SW_PATCH_VER                 1

/**
****************************************************************************************
 * @brief: Version Verify
****************************************************************************************
*/
#if (ETH_CFG_H_VENDOR_ID != ETH_IRQ_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_IRQ_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETH_IRQ_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETH_IRQ_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETH_IRQ_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETH_IRQ_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETH_IRQ_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETH_IRQ_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_IRQ_H_SW_PATCH_VER "
#endif

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
FUNC(void, ETH_CODE) ISR_DWMAC_0(void);
#endif
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
FUNC(void, ETH_CODE) ISR_GMAC_0(void);
#endif

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ETH_IRQ_H */
