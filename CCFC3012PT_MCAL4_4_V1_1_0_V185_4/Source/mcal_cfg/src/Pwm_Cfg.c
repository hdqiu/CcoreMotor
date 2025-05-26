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
*   @file    Pwm_Cfg.c
*   @version
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm_Cfg.h"

#define PWM_CFG_C_VENDOR_ID                      176
#define PWM_CFG_C_AR_REL_MAJOR_VER               4
#define PWM_CFG_C_AR_REL_MINOR_VER               4
#define PWM_CFG_C_AR_REL_REV_VER                 0
#define PWM_CFG_C_SW_MAJOR_VER                   1
#define PWM_CFG_C_SW_MINOR_VER                   0
#define PWM_CFG_C_SW_PATCH_VER                   1

#if (PWM_CFG_C_VENDOR_ID != MCAL_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_CFG_C_VENDOR_ID "
#endif
#if (PWM_CFG_C_AR_REL_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_CFG_C_AR_REL_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_AR_REL_MINOR_VER "
#endif
#if (PWM_CFG_C_AR_REL_REV_VER != MCAL_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_AR_REL_REV_VER "
#endif
#if (PWM_CFG_C_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_SW_MAJOR_VER "
#endif
#if (PWM_CFG_C_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_SW_MINOR_VER "
#endif
#if (PWM_CFG_C_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_SW_PATCH_VER "
#endif

static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_TomNotifyTable[PWM_TOM_MAX * PWM_TOM_CHANNEL_MAX];
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_AtomNotifyTable[PWM_ATOM_MAX * PWM_ATOM_CHANNEL_MAX];
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_EmiosNotifyTable[PWM_EMIOS_MAX * PWM_EMIOS_CHANNEL_MAX];
static CONST(Pwm_CoreMapItemType, PWM_CONST)     Pwm_CoreMap[PWM_CHANNEL_NUM];
        
CONST(Pwm_ConfigType, PWM_CONST) Pwm_Config=
{
    .nNum=PWM_CHANNEL_NUM,
    .pPwm_TomNotifyTable=Pwm_TomNotifyTable,
    .pPwm_AtomNotifyTable=Pwm_AtomNotifyTable,
    .pPwm_EmiosNotifyTable=Pwm_EmiosNotifyTable,
    .pPwm_CoreMap=Pwm_CoreMap,
    .sPwmChConfigs={
        {
            .nPwmChannelId=0,
            .ePwmHwIP=PWM_EMIOS,
            .sHwConfig={
                .nPwmHwIndex=0,
                .nPwmChIndex=0
            },
            .nPwmPeriodDefault=100,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .sEmiosChannelConfig={
                .nPwmeMiosPrescaler=DIV_1,
                .nPwmeMiosMode=EMIOS_UC_MODE_PWM_OPWFMB,
                .nPwmeMiosBus=EMIOS_COUNTER_BUS_INTERNAL,
                .nIdealDutyCycle=0,
                .nDeadtime=0,
                .nOffset=0,
                .ntrigTime=0,
                .nPwmeMiosDmaSwitch=FALSE,
            },
            .nPwmMaxDutycycle=32768,
        },
        {
            .nPwmChannelId=1,
            .ePwmHwIP=PWM_TOM,
            .sHwConfig={
                .nPwmHwIndex=0,
                .nPwmChIndex=6
            },
            .nPwmPeriodDefault=1200,
            .nPwmDutycycleDefault=16384,
            .ePwmChannelClass=PWM_VARIABLE_PERIOD,
            .ePwmPolarity=PWM_HIGH,
            .ePwmIdleState=PWM_LOW,
            .pfPwmChannelNotification=NULL_PTR,
            .nGtm4Tout=0,
            .nToutNum=0,
            .sCmuClk={
                .TOM_ClkSrc={
                    .ClkSrc=FXClk0,
                }
            },
            .nPwmMaxDutycycle=32768,
        },
    }
};

static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_TomNotifyTable[PWM_TOM_MAX * PWM_TOM_CHANNEL_MAX]=
{
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=1},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
};

static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_AtomNotifyTable[PWM_ATOM_MAX * PWM_ATOM_CHANNEL_MAX]=
{
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
};

static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_EmiosNotifyTable[PWM_EMIOS_MAX * PWM_EMIOS_CHANNEL_MAX]=
{
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
    {.pNotification=NULL_PTR,.nPwmChannelId=0},
};

static CONST(Pwm_CoreMapItemType, PWM_CONST) Pwm_CoreMap[PWM_CHANNEL_NUM]=
{
    {
        .nPwmChannelId=0,
        .nCoreId=1
    },
    {
        .nPwmChannelId=1,
        .nCoreId=1
    },
};

#ifdef __cplusplus
}
#endif
