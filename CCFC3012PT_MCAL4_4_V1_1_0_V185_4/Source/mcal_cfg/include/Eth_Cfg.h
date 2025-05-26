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
*   @file    Eth_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifndef ETH_CFG_H
#define ETH_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "StandardTypes.h"
#include "status.h"
#include "derivative.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETH_CFG_H_VENDOR_ID                     176
#define ETH_CFG_H_AR_REL_MAJOR_VER              4
#define ETH_CFG_H_AR_REL_MINOR_VER              4
#define ETH_CFG_H_AR_REL_REV_VER                0
#define ETH_CFG_H_SW_MAJOR_VER                  1
#define ETH_CFG_H_SW_MINOR_VER                  0
#define ETH_CFG_H_SW_PATCH_VER                  1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (MCAL_VENDOR_ID != ETH_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_CFG_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != ETH_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != ETH_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != ETH_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_CFG_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != ETH_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != ETH_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != ETH_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_CFG_H_SW_PATCH_VER "
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define ETH_PRECOMPILE_SUPPORT         (STD_OFF)

#define ETH_MULTICORE_ENABLED          (STD_ON)

#define ETH_SWT_MANAGEMENT_SUPPORT_API (STD_OFF)

#define ETH_BRIDGE_SUPPORT             (STD_OFF)

#define ETH_DEM_EVENT_DETECT           (STD_ON)

#define ETH_UPDATE_PHYS_ADDR_FILTER    (STD_ON)

#define ETH_USE_MULTIBUFFER_RX_FRAMES  (STD_OFF)

#define ETH_USE_MULTIBUFFER_TX_FRAMES  (STD_OFF)

#define ETH_CTRLENABLE_MII             (STD_ON)

#define ETH_DEV_ERROR_DETECT           (STD_ON)

#define ETH_MAX_CTRLIDX                ((uint8)0U)
#define ETH_MIN_CTRLIDX                ((uint8)0U)
#define ETH_MAXCTRLS_SUPPORTED         (1U)
#define ETH_DEFAULT_COREID             (0U)
#define ETH_INFINITE_LOOP_PROTECTION   (4096U)
#define ETH_MULTICAST_POOL_SIZE        (15U)
#define ETH_MAX_CONTROLLER_CFG         (1U)
#define ETH_MAX_TXFIFO_CONFIG          (1U)
#define ETH_MAX_RXFIFO_CONFIG          (1U)
#define ETH_MAX_TX_PRIO_NUM            (8U)
 
#define ETH_GET_RXSTATS_API            (STD_ON)
#define ETH_GET_TXSTATS_API            (STD_ON)
#define ETH_GET_COUNTVAL_API           (STD_ON)
#define ETH_GET_TXERRORCOUNT_API       (STD_ON)
#define ETH_GET_VERSION_INFO_API       (STD_ON)

#define ETH_DRIVER_INSTANCE            (0U)
#define TX_BUFFER_COUNT                (1U)
#define RX_BUFFER_COUNT                (10U)
#define MAX_TX_BUFFER_SIZE             (1536U)
#define MAX_RX_BUFFER_SIZE             (128U)
#define MAX_BUFFER_SIZE                (1536U)

#define ETH_PB_CONFIG_DECLARATION   extern CONST(Eth_ConfigType, ETH_CONST) Eth_Config;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ETH_CFG_H */
/** @} */
