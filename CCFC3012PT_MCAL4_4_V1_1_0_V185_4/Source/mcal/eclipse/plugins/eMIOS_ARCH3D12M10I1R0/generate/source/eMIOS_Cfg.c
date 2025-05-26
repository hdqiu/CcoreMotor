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
*   @file    eMIOS_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eMIOS MCAL driver.
*
*   @addtogroup eMIOS
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "eMIOS.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define EMIOS_PB_VENDOR_ID_C                 176
#define EMIOS_PB_AR_MAJOR_VER_C              4
#define EMIOS_PB_AR_MINOR_VER_C              4
#define EMIOS_PB_AR_PATCH_VER_C              0
#define EMIOS_PB_SW_MAJOR_VER_C              1
#define EMIOS_PB_SW_MINOR_VER_C              0
#define EMIOS_PB_SW_PATCH_VER_C              1

/*============================================FILE VERSION CHECKS===================================*/

#if (EMIOS_PB_VENDOR_ID_C != EMIOS_VENDOR_ID)
#error "NON-MATCHED DATA : EMIOS_PB_VENDOR_ID_C"
#endif

/* Check if current file and EMIOS header file are of the same Autosar version */
#if (EMIOS_PB_AR_MAJOR_VER_C != EMIOS_AR_REL_MAJOR_VER)
#error "NON-MATCHED DATA : EMIOS_PB_AR_MAJOR_VER_C"
#endif
#if (EMIOS_PB_AR_MINOR_VER_C != EMIOS_AR_REL_MINOR_VER)
#error "NON-MATCHED DATA : EMIOS_PB_AR_MINOR_VER_C"
#endif
#if (EMIOS_PB_AR_PATCH_VER_C != EMIOS_AR_REL_REV_VER)
#error "NON-MATCHED DATA : EMIOS_PB_AR_PATCH_VER_C"
#endif

/* Check if current file and EMIOS header file are of the same Software version */
#if (EMIOS_PB_SW_MAJOR_VER_C != EMIOS_SW_MAJOR_VER)
#error "NON-MATCHED DATA : EMIOS_PB_SW_MAJOR_VER_C"
#endif
#if (EMIOS_PB_SW_MINOR_VER_C != EMIOS_SW_MINOR_VER)
#error "NON-MATCHED DATA : EMIOS_PB_SW_MINOR_VER_C"
#endif
#if (EMIOS_PB_SW_PATCH_VER_C != EMIOS_SW_PATCH_VER)
#error "NON-MATCHED DATA : EMIOS_PB_SW_PATCH_VER_C"
#endif


[!AUTOSPACING!]

[!SELECT "eMIOSGeneral"!]
[!VAR "eMIOS0" = "0"!]
[!VAR "eMIOSIntanceNum" = "0"!]
[!IF "eMIOSInstance0 = 'true'"!]
    [!VAR "eMIOS0" = "1"!]
    [!VAR "eMIOSIntanceNum" = "$eMIOSIntanceNum + 1"!]
[!ENDIF!]
[!ENDSELECT!]

[!IF "num:i($eMIOS0) = '1'"!]
[!IF "num:i(count(eMIOSInstance0Config/eMIOSChannel/*)) != '0'"!]
static CONST(eMIOS_Mc_CntChnConfigType, EMIOS_VAR) eMIOS0_Mc_CntChnConfig[[!"num:i(count(eMIOSInstance0Config/eMIOSChannel/*))"!]] = 
{
    [!LOOP "eMIOSInstance0Config/eMIOSChannel/*"!]
    {
        [!IF "substring-after(string(eMIOSChannelIndex),'CHANNEL_') = '0'"!][!//
        .eMIOSChannelId = EMIOS_CNT_BUSB_DRIVEN_CHANNEL,
        [!ELSEIF "substring-after(string(eMIOSChannelIndex),'CHANNEL_') = '8'"!][!//
        .eMIOSChannelId = EMIOS_CNT_BUSC_DRIVEN_CHANNEL,
        [!ELSEIF "substring-after(string(eMIOSChannelIndex),'CHANNEL_') = '16'"!][!//
        .eMIOSChannelId = EMIOS_CNT_BUSD_DRIVEN_CHANNEL,
        [!ELSEIF "substring-after(string(eMIOSChannelIndex),'CHANNEL_') = '23'"!][!//
        .eMIOSChannelId = EMIOS_CNT_BUSA_DRIVEN_CHANNEL,
        [!ELSEIF "substring-after(string(eMIOSChannelIndex),'CHANNEL_') = '24'"!][!//
        .eMIOSChannelId = EMIOS_CNT_BUSE_DRIVEN_CHANNEL,
        [!ENDIF!][!//
        {
            .mode = [!"eMIOSChannelMode"!],
            .period = [!"eMIOSChannelperiod"!],
            .divid = [!"num:i(substring-after(string(eMIOSChannelprescaler),'DIV_') - 1)"!],
            .filter = [!"eMIOSChannelfilter"!],
            .trigger = [!"eMIOSChanneltrigger"!],
        }
    },
    [!ENDLOOP!]
};
[!ENDIF!]
[!ENDIF!]
static CONST(eMIOS_InstanceConfigType, EMIOS_VAR) eMIOS_InstCfg[[!"num:i($eMIOSIntanceNum)"!]] = 
{
[!IF "num:i($eMIOS0) = '1'"!][!//
    {
        .eMIOSIntanceId = (uint8)EMIOS_INSTANCE_0,
        [!SELECT "eMIOSInstance0Config"!]
        {
            .LowPowerModeEn = FALSE,
            .FreezeInDebugMode = FALSE,
            .GlobalPreClkDiv = [!"GlobalPrescaler"!]U,
            [!IF "ExternalTimeBase = 'true'"!]
            .ExternalTimeBaseSel = EMIOS_ETB_EN_COUNTER_BUSA_TO_STAC,
            [!ELSE!]
            .ExternalTimeBaseSel = EMIOS_ETB_DIS_COUNTER_BUSA_TO_UC,
            [!ENDIF!]
            .ServerTimeSlotSel = [!"ServerTimeSlot"!]U,
        },
        [!ENDSELECT!]
        .eMIOS_Mc_CntChnConfig = [!IF "num:i(count(eMIOSInstance0Config/eMIOSChannel/*)) = '0'"!]NULL_PTR[!ELSE!]eMIOS0_Mc_CntChnConfig[!ENDIF!],
        .eMIOSChannelNum = [!IF "num:i(count(eMIOSInstance0Config/eMIOSChannel/*)) = '0'"!]0[!ELSE!][!"num:i(count(eMIOSInstance0Config/eMIOSChannel/*))"!][!ENDIF!],
    },
[!ENDIF!]
[!//
};

CONST(eMIOS_ConfigType, ADC_VAR) eMIOS_Config =
{
    eMIOS_InstCfg
};

#ifdef __cplusplus
}
#endif

