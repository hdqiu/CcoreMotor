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

[!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild' and (variant:size()<=1))"!][!//
#define ETH_PRECOMPILE_SUPPORT         (STD_ON)
[!ELSE!][!//
#define ETH_PRECOMPILE_SUPPORT         (STD_OFF)
[!ENDIF!][!//

#define ETH_MULTICORE_ENABLED          ([!IF "EthGeneral/EthEnableMulticoreSupport = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ETH_SWT_MANAGEMENT_SUPPORT_API ([!IF "EthGeneral/EthSwtManagementSupportApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ETH_BRIDGE_SUPPORT             ([!IF "EthGeneral/EthBridgeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ETH_DEM_EVENT_DETECT           ([!IF "EthGeneral/EthDemEventDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ETH_UPDATE_PHYS_ADDR_FILTER    ([!IF "EthGeneral/EthUpdatePhysAddrFilter"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ETH_USE_MULTIBUFFER_RX_FRAMES  ([!IF "EthGeneral/EthUseMultiBufferRxFrames"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ETH_USE_MULTIBUFFER_TX_FRAMES  ([!IF "EthGeneral/EthUseMultiBufferTxFrames"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!NOCODE!][!//
  [!VAR "AllMiiDisabled" = "true()"!]
  [!LOOP "EthConfigSet/EthCtrlConfig/*"!][!//
      [!IF "EthCtrlEnableMii = 'true'"!]
        [!VAR "AllMiiDisabled" = "false()"!]
      [!ENDIF!]   
  [!ENDLOOP!][!// 
[!ENDNOCODE!][!//
[!IF "$AllMiiDisabled = 'true'"!][!//
#define ETH_CTRLENABLE_MII             (STD_OFF)
[!ELSE!][!//
#define ETH_CTRLENABLE_MII             (STD_ON)
[!ENDIF!][!//

#define ETH_DEV_ERROR_DETECT           ([!IF "EthGeneral/EthDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!NOCODE!]
    [!SELECT "EthConfigSet"!]
    [!VAR "MAX_CONTROLLER_CFG"="num:i(count(EthCtrlConfig/*))"!]
    [!VAR "TxCFGMax"="num:i(../EthGeneral/EthMaxTxQueueNum)"!]
    [!VAR "RxCFGMax"="num:i(../EthGeneral/EthMaxRxQueueNum)"!]
    [!ENDSELECT!]
[!ENDNOCODE!]
[!NOCODE!][!// Check minimum/maximum available CtrlIdx
    [!VAR "MaxCtrlIdx"="0"!]
    [!VAR "MinCtrlIdx"="EthGeneral/EthMaxCtrlsSupported"!]
    [!SELECT "EthConfigSet"!]
        [!LOOP "EthCtrlConfig/*"!]
            [!IF "EthCtrlIdx < $MinCtrlIdx "!]
                [!VAR "MinCtrlIdx"="EthCtrlIdx"!]
            [!ENDIF!]
            [!IF "EthCtrlIdx > $MaxCtrlIdx "!]
                [!VAR "MaxCtrlIdx"="EthCtrlIdx"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDSELECT!]
[!ENDNOCODE!][!//
#define ETH_MAX_CTRLIDX                ((uint8)[!"num:i($MaxCtrlIdx)"!]U)
#define ETH_MIN_CTRLIDX                ((uint8)[!"num:i($MinCtrlIdx)"!]U)
#define ETH_MAXCTRLS_SUPPORTED         [!INDENT "4"!]([!"EthGeneral/EthMaxCtrlsSupported"!]U)[!ENDINDENT!]
#define ETH_DEFAULT_COREID             ([!"num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]U)
#define ETH_INFINITE_LOOP_PROTECTION   (4096U)
#define ETH_MULTICAST_POOL_SIZE        [!INDENT "4"!]([!"num:i(EthGeneral/EthMulticastPoolSize)"!]U)[!ENDINDENT!]
#define ETH_MAX_CONTROLLER_CFG         [!INDENT "4"!]([!"num:i($MAX_CONTROLLER_CFG)"!]U)[!ENDINDENT!]
#define ETH_MAX_TXFIFO_CONFIG          [!INDENT "4"!]([!"num:i($TxCFGMax)"!]U)[!ENDINDENT!]
#define ETH_MAX_RXFIFO_CONFIG          [!INDENT "4"!]([!"num:i($RxCFGMax)"!]U)[!ENDINDENT!]
#define ETH_MAX_TX_PRIO_NUM            (8U)
 
#define ETH_GET_RXSTATS_API            ([!IF "EthGeneral/EthGetRxStatsApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ETH_GET_TXSTATS_API            ([!IF "EthGeneral/EthGetTxStatsApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ETH_GET_COUNTVAL_API           ([!IF "EthGeneral/EthGetDropCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ETH_GET_TXERRORCOUNT_API       ([!IF "EthGeneral/EthGetTxErrorCounterValuesApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ETH_GET_VERSION_INFO_API       ([!IF "EthGeneral/EthVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!VAR "TxSpaceMax" = "num:i(ceiling(num:i(EthConfigSet/EthCtrlConfig/*/EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*/EthCtrlConfigEgressFifoBufLenByte) div 64) * 64)"!][!//
[!VAR "RxSpaceMax" = "num:i(ceiling(num:i(EthConfigSet/EthCtrlConfig/*/EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*/EthCtrlConfigIngressFifoBufLenByte) div 64) * 64)"!][!//
#define ETH_DRIVER_INSTANCE            ([!"EthGeneral/EthIndex"!]U)
#define TX_BUFFER_COUNT                ([!"EthConfigSet/EthCtrlConfig/*/EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*/EthCtrlConfigEgressFifoBufTotal"!]U)
#define RX_BUFFER_COUNT                ([!"EthConfigSet/EthCtrlConfig/*/EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*/EthCtrlConfigIngressFifoBufTotal"!]U)
#define MAX_TX_BUFFER_SIZE             ([!"num:i($TxSpaceMax)"!]U)
#define MAX_RX_BUFFER_SIZE             ([!"num:i($RxSpaceMax)"!]U)
#define MAX_BUFFER_SIZE                ([!"EthGeneral/EthMaxBuffersSize"!]U)

#define ETH_PB_CONFIG_DECLARATION   extern CONST(Eth_ConfigType, ETH_CONST) Eth_Config;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ETH_CFG_H */
/** @} */
