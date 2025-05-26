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
*   @file    Can_176_CanFD_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFD MCAL driver.
*
*   @addtogroup CanFD
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#include "Can_176_CanFD.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_CFG_C_VENDOR_ID                     176
#define CAN_176_CANFD_CFG_C_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_CFG_C_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_CFG_C_AR_REL_REV_VER                0
#define CAN_176_CANFD_CFG_C_SW_MAJOR_VER                  1
#define CAN_176_CANFD_CFG_C_SW_MINOR_VER                  0
#define CAN_176_CANFD_CFG_C_SW_PATCH_VER                  1

#if (MCAL_VENDOR_ID != CAN_176_CANFD_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CAN_176_CANFD_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CAN_176_CANFD_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CAN_176_CANFD_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CAN_176_CANFD_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CAN_176_CANFD_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CAN_176_CANFD_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_CFG_C_SW_PATCH_VER "
#endif

[!AUTOSPACING!]

[!INDENT "0"!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]
        [!IF "(CanErrorControllerNotifEn = 'true') and (normalize-space(CanErrorControllerNotification) != 'NULL_PTR')"!]
extern FUNC(void,CAN_CODE) [!"normalize-space(CanErrorControllerNotification)"!](VAR(uint8, AUTOMATIC) u8Can_ControllerId);
        [!ENDIF!]
    [!ENDLOOP!]

static CONST(CanFd_hwObject, CAN_CONST) Canfd_HardWareObjConfigs[CAN_176_CANFD_MB_COUNT] = 
{
    [!LOOP "CanHardwareObject/*"!]
        [!INDENT "4"!]
            {
            [!INDENT "8"!]
                .CanObjectId = [!"num:i(CanObjectId)"!]U,
            [!SELECT "node:ref(CanControllerRef)"!]
                .CanControllerId = (uint32)[!"num:i(CanControllerId)"!]U,
            [!ENDSELECT!]
            [!IF "CanIdType = 'STANDARD'"!]
                .CanIdType = CANFD_STANDARD_ID,
            [!ELSEIF "CanIdType ='EXTENDED'"!]
                .CanIdType = CANFD_EXTENDED_ID,
            [!ELSE!]
                .CanIdType = CANFD_STD_AND_EXT_ID,
            [!ENDIF!]
                .mbIdex = 0U,
                .mbPayloadLength = (uint32)[!"substring-before(substring-after(node:value(node:ref(./CanControllerRef)/CanPayloadLength),'_'),'_')"!]U,
            [!IF "CanObjectType = 'TRANSMIT'"!]
                .mbType = [!"CanTransmitType"!],
            [!ELSE!]
                .mbType = CANFD_TRANS_BUF_TYPE_BUTT,
            [!ENDIF!]
            [!IF "CanHardwareObjectUsesPolling = 'true'"!]
                [!IF "CanObjectType = 'TRANSMIT'"!]
                    [!IF "node:ref(./CanControllerRef)/CanTxProcessing = 'INTERRUPT'"!]
                        [!ERROR!] CanObjectId = [!"num:i(CanObjectId)"!]. The current controller does not support polling sending [!ENDERROR!]
                    [!ENDIF!]
                    [!IF "node:ref(./CanControllerRef)/CanTxProcessing != 'INTERRUPT'"!]
                        .isPolling = 1U,
                    [!ELSE!]
                        .isPolling = 0U,
                    [!ENDIF!]
                [!ELSE!]
                    [!IF "node:ref(./CanControllerRef)/CanRxProcessing = 'INTERRUPT'"!]
                        [!ERROR!] CanObjectId = [!"num:i(CanObjectId)"!]. The current controller does not support cyclic receiving [!ENDERROR!]
                    [!ENDIF!]
                    [!IF "node:ref(./CanControllerRef)/CanRxProcessing != 'INTERRUPT'"!]
                        .isPolling = 1U,
                    [!ELSE!]
                        .isPolling = 0U,
                    [!ENDIF!]
                [!ENDIF!]
            [!ELSE!]
                .isPolling = 0U,
            [!ENDIF!]
            [!IF "CanObjectType = 'TRANSMIT'"!]
                .CanObjectType = CANFD_TRANSMIT,
            [!ELSE!]
                .CanObjectType = CANFD_RECEIVE,
            [!ENDIF!]
            .CanFdPaddingValue = [!"num:inttohex(CanFdPaddingValue,2)"!]U,
            [!IF "node:refexists(CanMainFunctionRWPeriodRef)"!]
                [!SELECT "node:ref(CanMainFunctionRWPeriodRef)"!]
                    .PeriodIndex = [!"num:i(@index)"!]U,
                [!ENDSELECT!]
            [!ELSE!]
                .PeriodIndex = 0U,
            [!ENDIF!]
            [!IF "num:i(count(CanHwFilter/*)) != num:i(0)"!]
                .filterCode = [!"num:inttohex(CanHwFilter/*[1]/CanHwFilterCode, 8)"!]U,
                .filterMask = [!"num:inttohex(CanHwFilter/*[1]/CanHwFilterMask, 8)"!]U,
            [!ELSE!]
                .filterCode = 0x0U,
                .filterMask = 0x0U,
            [!ENDIF!]
            [!ENDINDENT!]
            },
        [!ENDINDENT!]
    [!ENDLOOP!]
};
[!ENDSELECT!]
[!ENDINDENT!]

[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]
    [!VAR "CanControllerId_temp" = "num:i(@index)"!]
    [!VAR "FilterCount" = "num:i(0)"!]
    [!VAR "MaxFilterCount" = "num:i(16)"!]
    [!VAR "FilterCount_temp" = "num:i(0)"!]
    [!LOOP "../../CanHardwareObject/*"!]
        [!IF "num:i(node:ref(./CanControllerRef)/CanControllerId) = num:i($CanControllerId_temp)"!]
            [!IF "CanObjectType = 'RECEIVE'"!]
                [!VAR "FilterCount" = "$FilterCount + 1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "num:i($FilterCount) > num:i(16)"!]
        [!ERROR!] The number of receive filters exceeds 16. [!ENDERROR!]
    [!ENDIF!]
    [!VAR "FilterCount_temp" = "$MaxFilterCount - $FilterCount"!]
static CONST(CANFDFilter, CAN_CONST) Filter_[!"@index"!][[!"$MaxFilterCount"!]U] =
{
    [!INDENT "4"!]
    [!LOOP "../../CanHardwareObject/*"!]
        [!IF "num:i(node:ref(./CanControllerRef)/CanControllerId) = num:i($CanControllerId_temp)"!]
            [!IF "CanObjectType = 'RECEIVE'"!]
            {
                [!IF "num:i(count(CanHwFilter/*)) != num:i(0)"!]
                    [!INDENT "8"!]
                    .value =
                    {
                        [!INDENT "12"!]
                        [!IF "CanIdType = 'STANDARD'"!]
                            .is_extern = 0U,
                        [!ELSE!]
                            .is_extern = 1U,
                        [!ENDIF!]
                        [!IF "node:exists(node:ref(./CanControllerRef)/CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig/*)"!]
                            .is_fd_format_flag = 1U,
                            .is_bit_rate_switch = 1U,
                        [!ELSE!]
                            .is_fd_format_flag = 0U,
                            .is_bit_rate_switch = 0U,
                        [!ENDIF!]
                        .id = [!"num:inttohex(CanHwFilter/*[1]/CanHwFilterCode, 8)"!]U,
                        [!ENDINDENT!]
                    },
                    .mask =
                    {
                        [!INDENT "12"!]
                        [!IF "CanIdType = 'STANDARD'"!]
                            .is_extern = 0U,
                        [!ELSE!]
                            .is_extern = 1U,
                        [!ENDIF!]
                        [!IF "node:exists(node:ref(./CanControllerRef)/CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig/*)"!]
                            .is_fd_format_flag = 1U,
                            .is_bit_rate_switch = 1U,
                        [!ELSE!]
                            .is_fd_format_flag = 0U,
                            .is_bit_rate_switch = 0U,
                        [!ENDIF!]
                        .id = [!"num:inttohex(CanHwFilter/*[1]/CanHwFilterMask, 8)"!]U,
                        [!ENDINDENT!]
                    },
                    .ac_frame = 0U,
                    .am_frame = 0xFFFFFFFFU,
                    .is_valid = 1U
                    [!ENDINDENT!]
                [!ELSE!]
                    [!INDENT "8"!]
                    .value =
                    {
                        [!INDENT "12"!]
                        .is_extern = 0U,
                        .is_fd_format_flag = 0U,
                        .is_bit_rate_switch = 0U,
                        .id = 0U,
                        [!ENDINDENT!]
                    },
                    .mask =
                    {
                        [!INDENT "12"!]
                        .is_extern = 0U,
                        .is_fd_format_flag = 0U,
                        .is_bit_rate_switch = 0U,
                        .id = 0U,
                        [!ENDINDENT!]
                    },
                    .ac_frame = 0U,
                    .am_frame = 0U,
                    .is_valid = 0U
                    [!ENDINDENT!]
                [!ENDIF!]
            },
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "num:i($FilterCount_temp) != num:i(0)"!]
        [!FOR "i" = "0" TO "num:i($FilterCount_temp - 1)"!]
            {
                [!INDENT "8"!]
                    .value =
                    {
                        [!INDENT "12"!]
                        .is_extern = 0U,
                        .is_fd_format_flag = 0U,
                        .is_bit_rate_switch = 0U,
                        .id = 0U,
                        [!ENDINDENT!]
                    },
                    .mask =
                    {
                        [!INDENT "12"!]
                        .is_extern = 0U,
                        .is_fd_format_flag = 0U,
                        .is_bit_rate_switch = 0U,
                        .id = 0U,
                        [!ENDINDENT!]
                    },
                    .ac_frame = 0U,
                    .am_frame = 0U,
                    .is_valid = 0U
                [!ENDINDENT!]
            },
        [!ENDFOR!]
    [!ENDIF!]
    [!ENDINDENT!]
};

    [!ENDLOOP!]
[!ENDSELECT!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]
static CONST(CANFDFuncSwitch, CAN_CONST) func_switch_[!"@index"!] =
{
    .tdc_en = 0U,
    .inner_loop_back_en = 0U,
    .outer_loop_back_en = 0U,
    .listen_only_en = 0U
};

    [!ENDLOOP!]
[!ENDSELECT!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]
/*
                            clockFrequency
    rate = -------------------------------------------------
               brp * (prop_seg + phase_seg1) + phase_seg2
*/
static CONST(CANFDPhyPara, CAN_CONST) phy_para_[!"@index"!][[!"num:i(count(CanControllerBaudrateConfig/*))"!]U] =
{
    [!INDENT "4"!]
    [!LOOP "CanControllerBaudrateConfig/*"!]
        {
            [!INDENT "8"!]
            .use_bus_clk_src = 1U,
            .baudRateConfigId = [!"num:i(CanControllerBaudRateConfigID)"!]U,
            .preamble_bit_rate =
            {
                [!INDENT "12"!]
                .seg1 = [!"num:i(num:i(CanControllerPropSeg) + num:i(CanControllerSeg1))"!]U,
                .seg2 = [!"num:i(CanControllerSeg2)"!]U,
                .sjw = [!"num:i(CanControllerSyncJumpWidth)"!]U,
                .ssp = 4U,
                .prescaler = [!"num:i(CanControllerPrescaller)"!]U,
                [!ENDINDENT!]
            },
            [!IF "num:i(count(CanControllerFdBaudrateConfig/*)) != num:i(0)"!]
                [!SELECT "CanControllerFdBaudrateConfig/*[1]"!]
                    .data_bit_rate =
                    {
                        [!INDENT "12"!]
                        .seg1 = [!"num:i(num:i(CanControllerPropSeg) + num:i(CanControllerSeg1))"!]U,
                        .seg2 = [!"num:i(CanControllerSeg2)"!]U,
                        .sjw = [!"num:i(CanControllerSyncJumpWidth)"!]U,
                        .ssp = 4U,
                        .prescaler = [!"num:i(../../CanControllerPrescaller)"!]U,
                        [!ENDINDENT!]
                [!ENDSELECT!]
            },
            [!ELSE!]
                .data_bit_rate =
                {
                    [!INDENT "12"!]
                    .seg1 = [!"num:i(num:i(CanControllerPropSeg) + num:i(CanControllerSeg1))"!]U,
                    .seg2 = [!"num:i(CanControllerSeg2)"!]U,
                    .sjw = [!"num:i(CanControllerSyncJumpWidth)"!]U,
                    .ssp = 4U,
                    .prescaler = [!"num:i(CanControllerPrescaller)"!]U,
                    [!ENDINDENT!]
            },
            [!ENDIF!]
            [!IF "num:i(count(CanControllerFdBaudrateConfig/*)) != num:i(0)"!]
                .brs_ena = TRUE,
            [!ELSE!]
                .brs_ena = FALSE,
            [!ENDIF!]
            [!ENDINDENT!]
        },
    [!ENDLOOP!]
    [!ENDINDENT!]
};

    [!ENDLOOP!]
[!ENDSELECT!]
static CONST(CANFDConfig, CAN_CONST) Canfd_ControllerConfigs[CAN_176_CANFD_CONTROLLER_COUNT] = 
{
    [!SELECT "CanConfigSet"!]
        [!LOOP "CanController/*"!]
            [!VAR "RateConfigCount"="num:i(count(CanControllerBaudrateConfig/*))"!]
            [!VAR "interconfig_temp"="num:i(0)"!]
            [!INDENT "4"!]
            {
                [!INDENT "8"!]
                .controllerId = [!"CanHwChannel"!],
                .supportPolling = 1U,
                .defaultBaudRateId = (uint16)[!"node:ref(CanControllerDefaultBaudrate)/CanControllerBaudRateConfigID"!]U,
                .baudRateConfigCount = [!"$RateConfigCount"!]U,
                .phy_para = phy_para_[!"@index"!],
                .func_switch = &func_switch_[!"@index"!],
                .filter = Filter_[!"@index"!],
                [!IF "(CanErrorControllerNotifEn = 'true') and (normalize-space(CanErrorControllerNotification) != 'NULL_PTR')"!]
                    .ErrorNotification = &[!"normalize-space(CanErrorControllerNotification)"!],
                [!ELSE!]
                    .ErrorNotification = NULL_PTR,
                [!ENDIF!]
                [!IF "CanBusoffProcessing = 'INTERRUPT'"!]
                    [!VAR "interconfig_temp" = "num:i(bit:or(num:i($interconfig_temp), num:i(bit:shl(num:i(1), num:i(16)))))"!]
                [!ENDIF!]
                [!IF "CanRxProcessing != 'POLLING'"!]
                    [!VAR "interconfig_temp" = "num:i(bit:or(num:i($interconfig_temp), num:i(bit:shl(num:i(1), num:i(28)))))"!]
                    [!VAR "interconfig_temp" = "num:i(bit:or(num:i($interconfig_temp), num:i(bit:shl(num:i(1), num:i(29)))))"!]
                    [!VAR "interconfig_temp" = "num:i(bit:or(num:i($interconfig_temp), num:i(bit:shl(num:i(1), num:i(30)))))"!]
                    [!VAR "interconfig_temp" = "num:i(bit:or(num:i($interconfig_temp), num:i(bit:shl(num:i(1), num:i(31)))))"!]
                [!ENDIF!]
                [!IF "CanTxProcessing != 'POLLING'"!]
                    [!VAR "interconfig_temp" = "num:i(bit:or(num:i($interconfig_temp), num:i(bit:shl(num:i(1), num:i(26)))))"!]
                    [!VAR "interconfig_temp" = "num:i(bit:or(num:i($interconfig_temp), num:i(bit:shl(num:i(1), num:i(27)))))"!]
                [!ENDIF!]
                [!IF "CanErrorControllerNotifEn = 'true'"!]
                    [!VAR "interconfig_temp" = "num:i(bit:or(num:i($interconfig_temp), num:i(bit:shl(num:i(1), num:i(25)))))"!]
                [!ENDIF!]
                .interconfig = [!"num:inttohex(num:i($interconfig_temp), 8)"!]UL,
                [!ENDINDENT!]
            },
            [!ENDINDENT!]
        [!ENDLOOP!]
    [!ENDSELECT!]
};

[!IF "(CanGeneral/CanMulticoreSupport = 'true')"!]
    [!VAR "multcore_en" = "num:i(1)"!]
[!ELSE!]
    [!VAR "multcore_en" = "num:i(0)"!]
[!ENDIF!]
[!MACRO "GetCoreID"!]
[!NOCODE!]
    [!VAR "CoreID" = "num:i(0)"!]
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!]
    [!VAR "ModuEcucPartitionRef" = "string(CanControllerEcucPartitionRef)"!]
    [!IF "$multcore_en = num:i(1)"!]
        [!IF "not(node:refexists(CanControllerEcucPartitionRef))"!]
            [!VAR "CoreID" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]
        [!ELSE!]
            [!VAR "OsApplication_cnt" = "num:i(count(as:modconf('Os')[1]/OsApplication/*))"!]
            [!IF "$OsApplication_cnt = num:i(0)"!]
                [!ERROR!]  ASPath:/Os/Os/OsApplication is not configured [!ENDERROR!]
            [!ELSE!]
                [!FOR "n" = "0" TO "num:i($OsApplication_cnt)-1"!]
                    [!VAR "OsEcucPartitionRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!]
                    [!IF "text:match($OsEcucPartitionRef,$ModuEcucPartitionRef)"!]
                        [!VAR "EcucPartitionRefMatch_cnt" = "num:i($EcucPartitionRefMatch_cnt)+num:i(1)"!]
                        [!IF "not(node:refexists(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1]))"!]
                            [!VAR "OsApplicationCoreRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!]
                            [!ERROR!]  [!"string(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])"!] is not configured [!ENDERROR!]
                        [!ELSE!]
                            [!VAR "CoreID" = "node:ref(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])/EcucCoreId"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDFOR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$EcucPartitionRefMatch_cnt = num:i(0)"!]
        [!VAR "CoreID" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!"$CoreID"!]U
[!ENDMACRO!]
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
static CONST(CanFd_core_map_t, CAN_CONST) Canfd_CoreMap[CAN_176_CANFD_CONTROLLER_COUNT] =
{
    [!LOOP "(CanConfigSet/CanController/*)"!]
    [!VAR "CanControllerId" = "num:i(./CanControllerId)"!]
    {
        [!INDENT "8"!]
            .controllerId = [!"CanHwChannel"!],
            .CoreId = [!WS "1"!][!CALL "GetCoreID"!]
        [!ENDINDENT!]
    },
    [!ENDLOOP!]
};
#endif

CONST(Can_176_CanFD_ConfigType, CAN_CONST) Can_176_CanFd_Config =
{
    .CanFdControllerConfig = Canfd_ControllerConfigs,
    .CanFdHwObjectConfig = Canfd_HardWareObjConfigs,
    .CanFdHwObjCount = CAN_176_CANFD_MB_COUNT,
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    .CanFdCoreMap = Canfd_CoreMap
#endif
};

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#ifdef __cplusplus
}
#endif /* __cplusplus */
