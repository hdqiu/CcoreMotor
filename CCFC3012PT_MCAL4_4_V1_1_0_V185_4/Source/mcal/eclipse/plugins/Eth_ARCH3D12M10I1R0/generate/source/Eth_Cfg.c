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
*   @file    Eth_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

#include "Eth.h"
#if STD_ON == ETH_CTRLENABLE_MII
#include "EthTrcv.h"
#endif
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
#include "EthSwt.h"
#endif

#define ETH_CFG_C_VENDOR_ID                     176
#define ETH_CFG_C_AR_REL_MAJOR_VER              4
#define ETH_CFG_C_AR_REL_MINOR_VER              4
#define ETH_CFG_C_AR_REL_REV_VER                0
#define ETH_CFG_C_SW_MAJOR_VER                  1
#define ETH_CFG_C_SW_MINOR_VER                  0
#define ETH_CFG_C_SW_PATCH_VER                  1

#if (MCAL_VENDOR_ID != ETH_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != ETH_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != ETH_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != ETH_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != ETH_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != ETH_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != ETH_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_SW_PATCH_VER "
#endif
[!AUTOSPACING!][!//

[!IF "(ecu:get('Eth.EthGeneral.GigabitSupport') = 'STD_OFF')"!][!//
#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(DwmacTransmitDesc, AUTOMATIC) g_tx_desc[TX_BUFFER_COUNT] = {{{0U}, {0U}, {0U}, {0U}}};         /* PRQA S 3218 # need in .bss, not stack */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(DwmacReceiveDesc, AUTOMATIC) g_rx_desc[RX_BUFFER_COUNT] = {{{0U}, {0U}, {0U}, {0U}}};          /* PRQA S 3218 */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
[!ELSE!][!//
#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(GmacTransmitDesc, AUTOMATIC) g_tx_desc[TX_BUFFER_COUNT] = {{{0U}, {0U}, {0U}, {0U}}};         /* PRQA S 3218 # need in .bss, not stack */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(GmacReceiveDesc, AUTOMATIC) g_rx_desc[RX_BUFFER_COUNT] = {{{0U}, {0U}, {0U}, {0U}}};          /* PRQA S 3218 */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
[!ENDIF!][!//
#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(uint8, AUTOMATIC) g_tx_buf[MAX_TX_BUFFER_SIZE] = {0U};                                         /* PRQA S 3218 */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(uint8, AUTOMATIC) g_rx_buf[RX_BUFFER_COUNT * MAX_RX_BUFFER_SIZE] = {0U};                       /* PRQA S 3218 */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"

[!LOOP "EthConfigSet/EthCtrlConfig/*"!][!//
[!VAR "LoopVar1"="1"!][!//
[!VAR "ConfigCount"="(num:i(count(EthConfigSet/EthCtrlConfig/*)))"!][!//
[!IF "node:exists(./EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*)"!]
static CONST(Eth_EgressTxCfgType, ETH_CONST) Eth_EgressTxCfgType_[!"num:i(@index)"!][[!"(num:i(count(./EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*)))"!]] =
{
[!VAR "LoopVarEgress"="1"!][!//
[!VAR "EgressCount"="(num:i(count(./EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*)))"!][!//  
[!LOOP "./EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*"!][!//
    {
        .EthCtrlConfigEgressFifoIdx = [!"node:value(./EthCtrlConfigEgressFifoIdx)"!],
        .EthCtrlConfigEgressFifoBufLenByte = [!"node:value(./EthCtrlConfigEgressFifoBufLenByte)"!],
        .EthCtrlConfigEgressFifoBufTotal = [!"node:value(./EthCtrlConfigEgressFifoBufTotal)"!],
    }[!IF "$LoopVarEgress < (num:i($EgressCount))"!],
[!ELSE!][!ENDIF!]
[!VAR "LoopVarEgress"="$LoopVarEgress + 1"!]
[!ENDLOOP!][!//

};
[!ENDIF!][!//
[!IF "$LoopVar1 < (num:i($ConfigCount))"!],[!ELSE!][!ENDIF!]
[!VAR "LoopVar1"="$LoopVar1 + 1"!][!//

[!VAR "LoopVar2"="1"!][!//
[!VAR "ConfigCount"="(num:i(count(EthConfigSet/EthCtrlConfig/*)))"!][!//
[!IF "node:exists(./EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*)"!]
static CONST(Eth_IngressCfgType, ETH_CONST) Eth_IngressCfgType_[!"num:i(@index)"!][[!"(num:i(count(./EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*)))"!]] =
{
[!VAR "LoopVarEgress"="1"!][!//
[!VAR "EgressCount"="(num:i(count(./EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*)))"!][!//  
[!LOOP "./EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*"!][!//
    {
        .EthCtrlConfigIngressFifoIdx = [!"node:value(./EthCtrlConfigIngressFifoIdx)"!],
        .EthCtrlConfigIngressFifoBufLenByte = [!"node:value(./EthCtrlConfigIngressFifoBufLenByte)"!],
        .EthCtrlConfigIngressFifoBufTotal = [!"node:value(./EthCtrlConfigIngressFifoBufTotal)"!],
    }[!IF "$LoopVarEgress < (num:i($EgressCount))"!],[!ELSE!][!ENDIF!]
[!VAR "LoopVarEgress"="$LoopVarEgress + 1"!][!//
[!ENDLOOP!][!//

};
[!ENDIF!][!//
[!IF "$LoopVar2 < (num:i($ConfigCount))"!],[!ELSE!][!ENDIF!]
[!VAR "LoopVar2"="$LoopVar2 + 1"!][!//
[!ENDLOOP!][!//

[!IF "(ecu:get('Eth.EthGeneral.GigabitSupport') = 'STD_OFF')"!][!//
static VAR(DwmacCfg, ETH_VAR) Eth_ControllerConfigs[ETH_MAXCTRLS_SUPPORTED] =
[!ELSE!][!//
static VAR(GmacCfg, ETH_VAR) Eth_ControllerConfigs[ETH_MAXCTRLS_SUPPORTED] =
[!ENDIF!][!//
{
    [!LOOP "EthConfigSet/EthCtrlConfig/*"!][!//
    [!VAR "LoopVar"="1"!][!//
    [!VAR "ConfigCount"="(num:i(count(EthConfigSet/EthCtrlConfig/*)))"!][!//
    {
        [!IF "(ecu:get('Eth.EthGeneral.GigabitSupport') = 'STD_OFF')"!][!//
        .dwmac_id = [!"node:value(./EthHwChannel)"!],
        [!ELSE!][!//
        .gmac_id = [!"node:value(./EthHwChannel)"!],
        [!ENDIF!][!//
        .egress_cfg = [!IF "node:exists(./EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*)"!] (Eth_EgressTxCfgType*)Eth_EgressTxCfgType_[!"num:i(@index)"!][!ELSE!]NULL[!ENDIF!],
        .ingress_cfg = [!IF "node:exists(./EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*)"!] (Eth_IngressCfgType*)Eth_IngressCfgType_[!"num:i(@index)"!][!ELSE!]NULL[!ENDIF!],
        .buf_cfg =
        {
            .max_frame_len = MAX_BUFFER_SIZE,
            .tx_ring_cnt = TX_BUFFER_COUNT,
            .rx_ring_cnt = RX_BUFFER_COUNT,
            .tx_desc = g_tx_desc,
            .rx_desc = g_rx_desc,
            .tx_buf_addr = g_tx_buf,
            .rx_buf_addr = g_rx_buf,
            .tx_buf_size = (uint16)sizeof(g_tx_buf),
            .rx_buf_size = (uint16)sizeof(g_rx_buf)
        },
        .phy_cfg =
        {
            [!IF "EthCtrlMacLayerType = 'ETH_MAC_LAYER_TYPE_XXGMII'"!][!//
                [!ERROR!]Just support gigabit with RGMII. Can't select ETH_MAC_LAYER_TYPE_XXGMII for EthCtrlMacLayerType[!ENDERROR!][!//
            [!ENDIF!][!//
            [!IF "node:exists(EthCtrlMacLayerSpeed) = true()"!][!//
                [!IF "EthCtrlMacLayerSpeed = 'ETH_MAC_LAYER_SPEED_10G'"!][!//
                [!ERROR!]HW don't support 10G for any interfaces.[!ENDERROR!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
            [!IF "(node:exists(EthCtrlMacLayerSpeed) = true()) and (node:exists(EthCtrlMacLayerSpeed) = true()) and (node:exists(EthCtrlMacLayerSpeed) = true())"!][!//
            [!IF "(EthCtrlMacLayerType = 'ETH_MAC_LAYER_TYPE_XMII') and ((EthCtrlMacLayerSubType = 'REVERSED') or (EthCtrlMacLayerSubType = 'SERIAL') or (EthCtrlMacLayerSubType = 'UNIVERSAL_SERIAL') or (EthCtrlMacLayerSpeed = 'ETH_MAC_LAYER_SPEED_1G'))"!][!//
                [!ERROR!]Just support MII and RMII. If EthCtrlMacLayerType: ETH_MAC_LAYER_TYPE_XMII, EthCtrlMacLayerSubType just can select STANDARD or REDUCED and EthCtrlMacLayerSpeed just can select 10 or 100 Mbps[!ENDERROR!][!//
            [!ENDIF!][!//
            [!IF "(EthCtrlMacLayerType = 'ETH_MAC_LAYER_TYPE_XGMII') and (EthCtrlMacLayerSubType != 'REDUCED')"!][!//
                [!ERROR!]Just support gigabit with RGMII. If ETH_MAC_LAYER_TYPE_XGMII is selected, have to select REDUCED for EthCtrlMacLayerSubType[!ENDERROR!][!//
            [!ENDIF!][!//
            [!ENDIF!][!//
            [!IF "(ecu:get('Eth.EthGeneral.GigabitSupport') = 'STD_OFF')"!][!//
            [!IF "(./EthCtrlMacLayerType = 'ETH_MAC_LAYER_TYPE_XMII') and (./EthCtrlMacLayerSubType = 'STANDARD')"!][!//
            .transfer_mode = DWMAC_TRANS_MII_MODE,
            [!ELSEIF "(./EthCtrlMacLayerType = 'ETH_MAC_LAYER_TYPE_XMII') and (./EthCtrlMacLayerSubType = 'REDUCED')"!][!//
            .transfer_mode = DWMAC_TRANS_RMII_MODE,
            [!ENDIF!]
            [!IF "(./EthCtrlMacLayerSpeed = 'ETH_MAC_LAYER_SPEED_10M')"!][!//
            .transfer_speed = DWMAC_TRANS_SPEED_10M,
            [!ELSEIF "(./EthCtrlMacLayerSpeed = 'ETH_MAC_LAYER_SPEED_100M')"!][!//
            .transfer_speed = DWMAC_TRANS_SPEED_100M,
            [!ENDIF!]
            [!IF "./EthFullDuplexEnable"!][!//
            .transfer_duplex = DWMAC_TRANS_FULL_DUPLEX,
            [!ELSE!][!//
            .transfer_duplex = DWMAC_TRANS_HALF_DUPLEX,
            [!ENDIF!]
            [!ELSE!][!//
            [!IF "(./EthCtrlMacLayerType = 'ETH_MAC_LAYER_TYPE_XGMII') and (./EthCtrlMacLayerSubType = 'REDUCED')"!][!//
            .transfer_mode = GMAC_TRANS_RGMII_MODE,
            [!ELSEIF "(./EthCtrlMacLayerType = 'ETH_MAC_LAYER_TYPE_XMII') and (./EthCtrlMacLayerSubType = 'STANDARD')"!][!//
            .transfer_mode = GMAC_TRANS_MII_MODE,
            [!ELSEIF "(./EthCtrlMacLayerType = 'ETH_MAC_LAYER_TYPE_XMII') and (./EthCtrlMacLayerSubType = 'REDUCED')"!][!//
            .transfer_mode = GMAC_TRANS_RMII_MODE,
            [!ENDIF!]
            [!IF "(./EthCtrlMacLayerSpeed = 'ETH_MAC_LAYER_SPEED_10M')"!][!//
            .transfer_speed = GMAC_TRANS_SPEED_10M,
            [!ELSEIF "(./EthCtrlMacLayerSpeed = 'ETH_MAC_LAYER_SPEED_100M')"!][!//
            .transfer_speed = GMAC_TRANS_SPEED_100M,
            [!ELSEIF "(./EthCtrlMacLayerSpeed = 'ETH_MAC_LAYER_SPEED_1G')"!][!//
            .transfer_speed = GMAC_TRANS_SPEED_1000M,
            [!ENDIF!]
            [!IF "./EthFullDuplexEnable"!][!//
            .transfer_duplex = GMAC_TRANS_FULL_DUPLEX,
            [!ELSE!][!//
            .transfer_duplex = GMAC_TRANS_HALF_DUPLEX,
            [!ENDIF!]
            [!ENDIF!]
            [!IF "node:exists(./EthCtrlPhyAddress)"!][!//
                [!VAR "MACAddrString"="./EthCtrlPhyAddress"!][!//
                [!VAR "PhysAddress"="concat('0x',text:replaceAll($MACAddrString, ':',''))"!][!//
                [!VAR "PhysAddress"="num:hextoint($PhysAddress)"!][!//
            [!ELSE!][!//
                [!VAR "MACAddrString"="'00:00:00:00:00:00'"!][!//
                [!VAR "PhysAddress"="0"!][!//
            [!ENDIF!]
            [!VAR "MACAddrLow" = "num:i(num:div($PhysAddress,16777216))"!][!//Get first three numbers
            [!VAR "MACAddrHigh" = "num:i(num:mod($PhysAddress,16777216))"!][!//Get last three numbers
            [!VAR "MACAddrLowTemp" = "num:i(num:mod($MACAddrLow,65536))"!][!//
            [!VAR "MACAddrHighTemp" = "num:i(num:mod($MACAddrHigh,65536))"!][!//
            [!VAR "MACAddrNum1" = "num:i(num:div($MACAddrLow,65536))"!][!//Get first numbers
            [!VAR "MACAddrNum2" = "num:i(num:div($MACAddrLowTemp,256))"!][!//Get second numbers
            [!VAR "MACAddrNum3" = "num:i(num:mod($MACAddrLow,65536))"!][!//Get third numbers
            [!VAR "MACAddrNum4" = "num:i(num:div($MACAddrHigh,65536))"!][!//Get forth numbers
            [!VAR "MACAddrNum5" = "num:i(num:div($MACAddrHighTemp,256))"!][!//Get fifth numbers
            [!VAR "MACAddrNum6" = "num:i(num:mod($MACAddrHigh,65536))"!][!//Get sixth numbers
            .mac_addr = {[!"num:inttohex($MACAddrNum1,2)"!]U, [!"num:inttohex($MACAddrNum2,2)"!]U, [!"num:inttohex($MACAddrNum3,2)"!]U, [!"num:inttohex($MACAddrNum4,2)"!]U, [!"num:inttohex($MACAddrNum5,2)"!]U, [!"num:inttohex($MACAddrNum6,2)"!]U}
        },
        .func_cfg =
        {
            .inner_loop_back_en = ([!IF "../../../EthGeneral/EthInnerLoopBackEn"!]TRUE[!ELSE!]FALSE[!ENDIF!]),
            .mii_loop_back_en = (FALSE),
            .mii_echo_mode_en = (FALSE)
        },
        .EnableRxInterrupt = ([!IF "./EthCtrlEnableRxInterrupt"!]TRUE[!ELSE!]FALSE[!ENDIF!]),
        .EnableTxInterrupt = ([!IF "./EthCtrlEnableTxInterrupt"!]TRUE[!ELSE!]FALSE[!ENDIF!]),
#if STD_ON == ETH_CTRLENABLE_MII
        .Eth_EthTrcvDriverFunctionList =
        {
            &EthTrcv_[!IF "./EthEthTrcvDriverVendorIdAndApiInfix != """!][!"./EthEthTrcvDriverVendorIdAndApiInfix"!]_[!ENDIF!]ReadMiiIndication,
            &EthTrcv_[!IF "./EthEthTrcvDriverVendorIdAndApiInfix != """!][!"./EthEthTrcvDriverVendorIdAndApiInfix"!]_[!ENDIF!]WriteMiiIndication
        },
#endif
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
        .Eth_EthSwtDriverFunctionList =
        {
            &EthSwt_[!IF "./EthEthSwtDriverVendorIdAndApiInfix != """!][!"./EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxAdaptBufferLength,
            &EthSwt_[!IF "./EthEthSwtDriverVendorIdAndApiInfix != """!][!"./EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxPrepareFrame,
            &EthSwt_[!IF "./EthEthSwtDriverVendorIdAndApiInfix != """!][!"./EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxProcessFrame,
            &EthSwt_[!IF "./EthEthSwtDriverVendorIdAndApiInfix != """!][!"./EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxFinishedIndication,
            &EthSwt_[!IF "./EthEthSwtDriverVendorIdAndApiInfix != """!][!"./EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthRxProcessFrame,
            &EthSwt_[!IF "./EthEthSwtDriverVendorIdAndApiInfix != """!][!"./EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthRxFinishedIndication
        }
#endif
    }[!IF "$LoopVar < (num:i($ConfigCount))"!],[!ELSE!][!ENDIF!]
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDLOOP!][!//

};

[!MACRO "GetCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRef_cnt" = "num:i(count(EthCtrlEcucPartitionRef/*))"!][!//
    [!IF "$EcucPartitionRef_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))"!][!//
    [!ELSE!][!//
        [!FOR "i" = "0" TO "num:i($EcucPartitionRef_cnt)-1"!][!//
            [!VAR "ModuEcucPartitionRef" = "string(EthCtrlEcucPartitionRef/*[$i+1])"!][!//
            [!IF "not(node:refexists(EthCtrlEcucPartitionRef/*[$i+1]))"!][!//
                [!ERROR!]  Node [!"$ModuEcucPartitionRef"!] not found [!ENDERROR!]
            [!ELSE!][!//
                [!VAR "OsApplication_cnt" = "num:i(count(as:modconf('Os')[1]/OsApplication/*))"!][!//
                [!IF "$OsApplication_cnt = num:i(0)"!][!//
                    [!ERROR!]  ASPath:/Os/Os/OsApplication is not configured [!ENDERROR!]
                [!ELSE!][!//
                    [!FOR "n" = "0" TO "num:i($OsApplication_cnt)-1"!][!//
                        [!VAR "OsEcucPartitionRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!][!//
                        [!IF "text:match($OsEcucPartitionRef,$ModuEcucPartitionRef)"!][!//
                            [!VAR "EcucPartitionRefMatch_cnt" = "num:i($EcucPartitionRefMatch_cnt)+num:i(1)"!][!//
                            [!IF "not(node:refexists(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1]))"!][!//
                                [!VAR "OsApplicationCoreRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!][!//
                                [!ERROR!]  [!"string(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])"!] is not configured [!ENDERROR!]
                            [!ELSE!][!//
                                [!VAR "CoreID" = "node:ref(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])/EcucCoreId"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDFOR!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
        [!IF "$EcucPartitionRefMatch_cnt = num:i(0)"!][!//
            [!VAR "CoreID" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$CoreID"!]U
[!ENDMACRO!][!//
#if STD_ON == ETH_MULTICORE_ENABLED
static CONST(Eth_core_map_t, CAN_CONST) Eth_CoreMap[ETH_MAXCTRLS_SUPPORTED] =
{
    [!LOOP "EthConfigSet/EthCtrlConfig/*"!][!//
    {
        [!IF "(ecu:get('Eth.EthGeneral.GigabitSupport') = 'STD_OFF')"!][!//
        .dwmac_id = [!"node:value(./EthHwChannel)"!],
        [!ELSE!][!//
        .gmac_id = [!"node:value(./EthHwChannel)"!],
        [!ENDIF!][!//
        .CoreId = [!WS "1"!][!CALL "GetCoreID"!]
    },
    [!ENDLOOP!][!//
};
#endif

CONST(Eth_ConfigType, ETH_CONST) Eth_Config =
{
    .pController = Eth_ControllerConfigs,
#if STD_ON == ETH_MULTICORE_ENABLED
    .pEth_CoreMap = Eth_CoreMap
#endif
};

#if (ETH_DEM_EVENT_DETECT == STD_ON)
CONST(Eth_DemErrorType,AUTOMATIC) Eth_DemErr_Ctrl[ETH_MAXCTRLS_SUPPORTED][ETH_DEM_ERROR_MAX] =
{
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
[!VAR "LoopVar1"="1"!]
    {
        {[!IF "num:i(count(EthDemEventParameterRefs/*/ETH_E_ACCESS/*)) != num:i(0)"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],ETH_E_ACCESS},
        {[!IF "num:i(count(EthDemEventParameterRefs/*/ETH_E_ALIGNMENT/*)) != num:i(0)"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],ETH_E_ALIGNMENT},
        {[!IF "num:i(count(EthDemEventParameterRefs/*/ETH_E_CRC/*)) != num:i(0)"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],ETH_E_CRC},
        {[!IF "num:i(count(EthDemEventParameterRefs/*/ETH_E_LATECOLLISION/*)) != num:i(0)"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],ETH_E_LATECOLLISION},
        {[!IF "num:i(count(EthDemEventParameterRefs/*/ETH_E_MULTIPLECOLLISION/*)) != num:i(0)"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],ETH_E_MULTIPLECOLLISION},
        {[!IF "num:i(count(EthDemEventParameterRefs/*/ETH_E_OVERSIZEFRAME/*)) != num:i(0)"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],ETH_E_OVERSIZEFRAME},
        {[!IF "num:i(count(EthDemEventParameterRefs/*/ETH_E_RX_FRAMES_LOST/*)) != num:i(0)"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],ETH_E_RX_FRAMES_LOST},
        {[!IF "num:i(count(EthDemEventParameterRefs/*/ETH_E_SINGLECOLLISION/*)) != num:i(0)"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],ETH_E_SINGLECOLLISION},
        {[!IF "num:i(count(EthDemEventParameterRefs/*/ETH_E_UNDERSIZEFRAME/*)) != num:i(0)"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],ETH_E_UNDERSIZEFRAME}
    }[!IF "$LoopVar1 < (num:i($ConfigCount))"!],[!ELSE!][!ENDIF!]
[!VAR "LoopVar1"="$LoopVar1 + 1"!]
[!ENDLOOP!][!//

};
#endif


#ifdef __cplusplus
}
#endif /* __cplusplus */ 
