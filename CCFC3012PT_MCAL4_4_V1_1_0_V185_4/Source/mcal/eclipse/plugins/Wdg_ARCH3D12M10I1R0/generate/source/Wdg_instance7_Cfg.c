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
*   @file    Wdg_instance7_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Wdg MCAL driver.
*
*   @addtogroup Wdg
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
#define SWT_MAPCONFIG                         ((uint8)0xFFU)
#include "Wdg_Cfg.h"
#include "Wdg_176_ModId7.h"



#define WDG_INST7_CFG_C_VENDOR_ID                   176
#define WDG_INST7_CFG_C_VER_MAJOR                  4
#define WDG_INST7_CFG_C_VER_MINOR                  4
#define WDG_INST7_CFG_C_VER_REVISION               0
#define WDG_INST7_CFG_C_SW_VER_MAJOR               1
#define WDG_INST7_CFG_C_SW_VER_MINOR               0
#define WDG_INST7_CFG_C_SW_VER_PATCH               1
#if (WDG_INST7_CFG_C_VENDOR_ID != WDG_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VENDOR_ID "
#endif
#if (WDG_INST7_CFG_C_VER_MAJOR != WDG_CFG_H_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_MAJOR "
#endif
#if (WDG_INST7_CFG_C_VER_MINOR != WDG_CFG_H_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_MINOR "
#endif
#if (WDG_INST7_CFG_C_VER_REVISION != WDG_CFG_H_VER_REVISION)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_REVISION "
#endif
#if (WDG_INST7_CFG_C_SW_VER_MAJOR != WDG_CFG_H_SW_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_MAJOR "
#endif
#if (WDG_INST7_CFG_C_SW_VER_MINOR != WDG_CFG_H_SW_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_MINOR "
#endif
#if (WDG_INST7_CFG_C_SW_VER_PATCH != WDG_CFG_H_SW_VER_PATCH)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_PATCH "
#endif
#if (WDG_INST7_CFG_C_VENDOR_ID != WDG_176_MOD7_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VENDOR_ID "
#endif
#if (WDG_INST7_CFG_C_VER_MAJOR != WDG_176_MOD7_H_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_MAJOR "
#endif
#if (WDG_INST7_CFG_C_VER_MINOR != WDG_176_MOD7_H_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_MINOR "
#endif
#if (WDG_INST7_CFG_C_VER_REVISION != WDG_176_MOD7_H_VER_REVISION)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_VER_REVISION "
#endif
#if (WDG_INST7_CFG_C_SW_VER_MAJOR != WDG_176_MOD7_H_SW_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_MAJOR "
#endif
#if (WDG_INST7_CFG_C_SW_VER_MINOR != WDG_176_MOD7_H_SW_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_MINOR "
#endif
#if (WDG_INST7_CFG_C_SW_VER_PATCH != WDG_176_MOD7_H_SW_VER_PATCH)
    #error " NON-MATCHED DATA : WDG_INST7_CFG_C_SW_VER_PATCH "
#endif

#if (WDGINSTANCE7_AO == STD_ON)
[!AUTOSPACING!]
[!VAR "WdgMode7Index" = "0"!]
[!LOOP "WdgSettingsConfig/*"!]
    [!IF "node:value(./SWT_ModuleID) = 'SWT7_AO'"!]
        [!VAR "WdgMode7Index" = "@index + 1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "WdgSettingsConfig/*/SWT_ModuleID = 'SWT7_AO'"!][!//

static CONST(SWT_ModeConfig_Type, WDG_CONST) Wdg_Swt_OffModeSettings_Instance7=
{
    .SWT_MAPConfig=    (uint8)                  SWT_MAPCONFIG,
    .SWT_ServiceMode=    (SWT_ServiceMode_Type) [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsOff/WDGKeyedServiceMode"!],
    .SWT_ResetonInvalidAccess=(SWT_RIA_Type)    [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsOff/WDGRIAAccess"!],
    .SWT_WindowMode=    (SWT_Status_Type)       [!WS "9"!][!IF "WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsOff/WDGWindowStatus"!]SWT_Enable,[!ELSE!]SWT_Disable,[!ENDIF!][!CR!]
    .SWT_InterruptMode= (SWT_InterMode)         [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsOff/WDGInterruptMode"!],
    .SWT_StopMode=      (SWT_StopMode_Type)     [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsOff/WDGStopMode"!],
    .SWT_DebugMode=    (SWT_DebugMode_Type)     [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsOff/WDGDebugMode"!], 
    .SWT_Lock_Mode=    (SWT_Lock_Type)          [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsOff/WDGLockMode"!],     
    .SWT_InitialSK=    (uint16)                 0x00000000,                 
    .SWT_Timeout=      (uint32)                 0x00000100   ,              
    .SWT_WindowValue=  (uint32)                 0x00000000  ,               
    .Wdg_InternalClock=(uint32)                 16000,
	.Wdg_TriggerAddr=(uint32)                   0U
} ;    
static CONST(SWT_ModeConfig_Type, WDG_CONST) Wdg_Swt_FastModeSettings_7=
{
    .SWT_MAPConfig=    (uint8)                   SWT_MAPCONFIG,
    .SWT_ServiceMode=  (SWT_ServiceMode_Type)    [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WDGKeyedServiceMode"!],
    .SWT_ResetonInvalidAccess=(SWT_RIA_Type)     [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WDGRIAAccess"!],
    .SWT_WindowMode=   (SWT_Status_Type)         [!WS "9"!][!IF "WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WDGWindowStatus"!]SWT_Enable,[!ELSE!]SWT_Disable,[!ENDIF!][!CR!]
    .SWT_InterruptMode=(SWT_InterMode)           [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WDGInterruptMode"!],
    .SWT_StopMode=     (SWT_StopMode_Type)       [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WDGStopMode"!],
    .SWT_DebugMode=    (SWT_DebugMode_Type)      [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WDGDebugMode"!],          
    .SWT_Lock_Mode=    (SWT_Lock_Type)           [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WDGLockMode"!],
    .SWT_InitialSK=    (uint16)                  [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/SWT_InitialSKValue"!],  
    .SWT_Timeout=      (uint32)                  [!"num:inttohex(num:i(node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WdgTimeoutPeriod) * node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WdgClockValue) * 1000 ),8)"!],                 
    .SWT_WindowValue=  (uint32)                  [!WS "18"!][!IF "node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WDGWindowStatus) ='true'"!][!"num:inttohex(num:i(node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WdgWindowPeriod) * node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WdgClockValue) * 1000 ),8)"!]   [!ELSE!][!"num:inttohex(num:i(node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WdgTimeoutPeriod)*0.4 * node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WdgClockValue) * 1000 ),8)"!][!ENDIF!],[!CR!]   
    .Wdg_InternalClock=(uint32)                  [!"node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WdgClockValue)"!],
	.Wdg_TriggerAddr=(uint32)                    0U
};
static CONST(SWT_ModeConfig_Type, WDG_CONST) Wdg_Swt_SlowModeSettings_7=
{
    .SWT_MAPConfig=   (uint8)                   SWT_MAPCONFIG,
    .SWT_ServiceMode= (SWT_ServiceMode_Type)    [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WDGKeyedServiceMode"!],
    .SWT_ResetonInvalidAccess=(SWT_RIA_Type)    [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WDGRIAAccess"!],
    .SWT_WindowMode=  (SWT_Status_Type)         [!WS "9"!][!IF "WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WDGWindowStatus"!]SWT_Enable,[!ELSE!]SWT_Disable,[!ENDIF!][!CR!]
    .SWT_InterruptMode=(SWT_InterMode)          [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WDGInterruptMode"!],
    .SWT_StopMode=    (SWT_StopMode_Type)       [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WDGStopMode"!],
    .SWT_DebugMode=   (SWT_DebugMode_Type)      [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WDGDebugMode"!],          
    .SWT_Lock_Mode=    (SWT_Lock_Type)          [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WDGLockMode"!],
    .SWT_InitialSK=   (uint16)                  [!"WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/SWT_InitialSKValue"!],              
    .SWT_Timeout=     (uint32)                  [!"num:inttohex(num:i(node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WdgTimeoutPeriod) * node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WdgClockValue) * 1000 ),8)"!],                 
    .SWT_WindowValue= (uint32)                  [!WS "18"!][!IF "node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WDGWindowStatus) ='true'"!][!"num:inttohex(num:i(node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WdgWindowPeriod) * node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WdgClockValue) * 1000 ),8)"!]   [!ELSE!][!"num:inttohex(num:i(node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WdgTimeoutPeriod)*0.4 * node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WdgClockValue) * 1000 ),8)"!][!ENDIF!],[!CR!]                 
    .Wdg_InternalClock=(uint32)                 [!"node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WdgClockValue)"!],
	.Wdg_TriggerAddr=(uint32)                   0U
};


static CONST(SWT_Module_Config_Type, WDG_CONST)WdgConfigSetType7 =
{
    .SWT_ModuleID = [!"node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/SWT_ModuleID)"!],
    .SWT_DefaultRunMode = [!"node:value(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgDefaultMode)"!],
    .u8Wdg_GptTimerChannel = (Gpt_ChannelType)[!"num:i(node:value(node:ref(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgExternalTriggerCounterRef)/GptChannelId))"!]U,
    .u32Wdg_TriggerSourceClock = (uint32)[!"num:i(node:value(node:ref(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgExternalTriggerCounterRef)/GptChannelTickFrequency)div 1000)"!],
    .SWT_Config = { &Wdg_Swt_OffModeSettings_Instance7, &Wdg_Swt_SlowModeSettings_7, &Wdg_Swt_FastModeSettings_7},
    .SWT_Callback =[!IF "(WdgGeneral/WdgCallbackNotification7 != '') and (WdgGeneral/WdgCallbackNotification7 != 'NULL_PTR') and (WdgGeneral/WdgCallbackNotification7 != 'NULL')"!]&[!"WdgGeneral/WdgCallbackNotification7"!][!ELSE!]NULL_PTR [!ENDIF!]

};


CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_7 =
{
			&WdgConfigSetType7,
};
[!ENDIF!]


#endif


#ifdef __cplusplus
}
#endif
