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




static CONST(eMIOS_Mc_CntChnConfigType, EMIOS_VAR) eMIOS0_Mc_CntChnConfig[1] = 
{
    {
        .eMIOSChannelId = EMIOS_CNT_BUSA_DRIVEN_CHANNEL,
        {
            .mode = EMIOS_UC_MODE_MCB_UP_COUNTER_INT_CLK,
            .period = 1000,
            .divid = 1,
            .filter = EMIOS_INPUT_FILTER_BYPASS,
            .trigger = EMIOS_TRIG_EDGE_FALLING,
        }
    },
};
static CONST(eMIOS_InstanceConfigType, EMIOS_VAR) eMIOS_InstCfg[1] = 
{
    {
        .eMIOSIntanceId = (uint8)EMIOS_INSTANCE_0,
        {
            .LowPowerModeEn = FALSE,
            .FreezeInDebugMode = FALSE,
            .GlobalPreClkDiv = 80U,
            .ExternalTimeBaseSel = EMIOS_ETB_DIS_COUNTER_BUSA_TO_UC,
            .ServerTimeSlotSel = 0U,
        },
        .eMIOS_Mc_CntChnConfig =eMIOS0_Mc_CntChnConfig,
        .eMIOSChannelNum =1,
    },
};

CONST(eMIOS_ConfigType, ADC_VAR) eMIOS_Config =
{
    eMIOS_InstCfg
};

#ifdef __cplusplus
}
#endif

