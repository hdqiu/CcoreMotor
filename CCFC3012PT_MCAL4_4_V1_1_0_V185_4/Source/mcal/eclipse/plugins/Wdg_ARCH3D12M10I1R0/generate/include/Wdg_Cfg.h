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
*   @file    Wdg_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Wdg MCAL driver.
*
*   @addtogroup Wdg
*   @{
*/
#ifndef WDG_CFG_H
#define WDG_CFG_H
#ifdef __cplusplus
extern "C"{
#endif
#include "Mcal.h"
#include "Dem.h"
#include "Wdg_LLDriver.h"

#define WDG_CFG_H_VENDOR_ID                   176
#define WDG_CFG_H_VER_MAJOR                  4
#define WDG_CFG_H_VER_MINOR                  4
#define WDG_CFG_H_VER_REVISION               0
#define WDG_CFG_H_SW_VER_MAJOR               1
#define WDG_CFG_H_SW_VER_MINOR               0
#define WDG_CFG_H_SW_VER_PATCH               1

#if (WDG_CFG_H_VENDOR_ID != DEM_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_CFG_H_VENDOR_ID "
#endif
#if (WDG_CFG_H_VER_MAJOR != DEM_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_VER_MAJOR "
#endif
#if (WDG_CFG_H_VER_MINOR != DEM_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_VER_MINOR "
#endif
#if (WDG_CFG_H_VER_REVISION != DEM_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_VER_REVISION "
#endif
#if (WDG_CFG_H_SW_VER_MAJOR != DEM_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_SW_VER_MAJOR "
#endif
#if (WDG_CFG_H_SW_VER_MINOR != DEM_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_SW_VER_MINOR "
#endif
#if (WDG_CFG_H_SW_VER_PATCH != DEM_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_SW_VER_PATCH "
#endif
#if (WDG_CFG_H_VENDOR_ID != MCAL_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_CFG_H_VENDOR_ID "
#endif
#if (WDG_CFG_H_VER_MAJOR != MCAL_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_VER_MAJOR "
#endif
#if (WDG_CFG_H_VER_MINOR != MCAL_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_VER_MINOR "
#endif
#if (WDG_CFG_H_VER_REVISION != MCAL_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_VER_REVISION "
#endif
#if (WDG_CFG_H_SW_VER_MAJOR != MCAL_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_SW_VER_MAJOR "
#endif
#if (WDG_CFG_H_SW_VER_MINOR != MCAL_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_SW_VER_MINOR "
#endif
#if (WDG_CFG_H_SW_VER_PATCH != MCAL_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : WDG_CFG_H_SW_VER_PATCH "
#endif

#define WDG_DEV_ERROR_REPORT                 ([!IF "WdgGeneral/WdgDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define WDG_DISABLE_ALLOWED                  ([!IF "WdgGeneral/WdgDisableAllowed"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#if ( defined(CCFC3012PT))
#define OFFSET_WDG (4U)
#else
#define OFFSET_WDG (0U)
#endif
#define WDG_INSTANCES_NUM (4U + OFFSET_WDG)

#define WDG_INTERNAL_MODULE         (0U)
#define WDG_EXTERNAL_MODULE_SPI     (1U)
#define WDG_EXTERNAL_MODULE_DIO     (2U)
[!AUTOSPACING!]
#define WDG_POSTBUILD_SUPPORT[!WS "1"!][!//
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!][!//
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]
#define WDG_TYPE ([!IF "text:match('',string(WdgExternalConfiguration/WdgExternalContainerRef))"!]WDG_INTERNAL_MODULE[!ELSEIF "text:match('Spi',substring-before(substring-after(WdgExternalConfiguration/WdgExternalContainerRef,'/'),'/'))"!]WDG_EXTERNAL_MODULE_SPI[!ELSE!]WDG_EXTERNAL_MODULE_DIO[!ENDIF!])
#define WDG_DEM_REPORT_ERROR_ENABLE          ([!IF "WdgGeneral/WdgDemReportErrorEnable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])   
#define WDG_VERSION_INFO_API                  ([!IF "WdgGeneral/WdgVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define [!"node:name(WdgGeneral/WdgIndex)"!]              ((uint8)[!"num:i(WdgGeneral/WdgIndex)"!])
#define [!"node:name(WdgGeneral/WdgIndex1)"!]             ((uint8)[!"num:i(WdgGeneral/WdgIndex1)"!])
#define [!"node:name(WdgGeneral/WdgIndex2)"!]             ((uint8)[!"num:i(WdgGeneral/WdgIndex2)"!])
#define [!"node:name(WdgGeneral/WdgIndex3)"!]             ((uint8)[!"num:i(WdgGeneral/WdgIndex3)"!])
#if ( defined(CCFC3012PT))
#define [!"node:name(WdgGeneral/WdgIndex4)"!]             ((uint8)[!"num:i(WdgGeneral/WdgIndex4)"!])
#define [!"node:name(WdgGeneral/WdgIndex5)"!]             ((uint8)[!"num:i(WdgGeneral/WdgIndex5)"!])
#define [!"node:name(WdgGeneral/WdgIndex6)"!]             ((uint8)[!"num:i(WdgGeneral/WdgIndex6)"!])
#define [!"node:name(WdgGeneral/WdgIndex7)"!]             ((uint8)[!"num:i(WdgGeneral/WdgIndex7)"!])
#endif
[!IF "(WdgGeneral/WdgCallbackNotification0 != '') and (WdgGeneral/WdgCallbackNotification0 != 'NULL_PTR') and (WdgGeneral/WdgCallbackNotification0 != 'NULL')"!]
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgCallbackNotification0"!](void);
[!ENDIF!]
[!IF "(WdgGeneral/WdgCallbackNotification1 != '') and (WdgGeneral/WdgCallbackNotification1 != 'NULL_PTR') and (WdgGeneral/WdgCallbackNotification1 != 'NULL')"!]
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgCallbackNotification1"!](void);
[!ENDIF!]
[!IF "(WdgGeneral/WdgCallbackNotification2 != '') and (WdgGeneral/WdgCallbackNotification2 != 'NULL_PTR') and (WdgGeneral/WdgCallbackNotification2 != 'NULL')"!]
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgCallbackNotification2"!](void);
[!ENDIF!]
[!IF "(WdgGeneral/WdgCallbackNotification3 != '') and (WdgGeneral/WdgCallbackNotification3 != 'NULL_PTR') and (WdgGeneral/WdgCallbackNotification3 != 'NULL')"!]
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgCallbackNotification3"!](void);
[!ENDIF!]
#if ( defined(CCFC3012PT))
[!IF "(WdgGeneral/WdgCallbackNotification4 != '') and (WdgGeneral/WdgCallbackNotification4 != 'NULL_PTR') and (WdgGeneral/WdgCallbackNotification4 != 'NULL')"!]
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgCallbackNotification4"!](void);
[!ENDIF!]
[!IF "(WdgGeneral/WdgCallbackNotification5 != '') and (WdgGeneral/WdgCallbackNotification5 != 'NULL_PTR') and (WdgGeneral/WdgCallbackNotification5 != 'NULL')"!]
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgCallbackNotification5"!](void);
[!ENDIF!]
[!IF "(WdgGeneral/WdgCallbackNotification6 != '') and (WdgGeneral/WdgCallbackNotification6 != 'NULL_PTR') and (WdgGeneral/WdgCallbackNotification6 != 'NULL')"!]
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgCallbackNotification6"!](void);
[!ENDIF!]
#endif
[!VAR "hasWdg0" = "0"!]
[!VAR "hasWdg1" = "0"!]
[!VAR "hasWdg2" = "0"!]
[!VAR "hasWdg3" = "0"!]
[!VAR "hasWdg4" = "0"!]
[!VAR "hasWdg5" = "0"!]
[!VAR "hasWdg6" = "0"!]
[!VAR "hasWdg7" = "0"!]
[!LOOP "WdgSettingsConfig/*"!]
    [!IF "node:value(./SWT_ModuleID) = 'SWT0'"!]
        [!VAR "hasWdg0" = "1"!]
    [!ENDIF!]
    [!IF "node:value(./SWT_ModuleID) = 'SWT1'"!]
        [!VAR "hasWdg1" = "1"!]
    [!ENDIF!]
    [!IF "node:value(./SWT_ModuleID) = 'SWT2'"!]
        [!VAR "hasWdg2" = "1"!]
    [!ENDIF!]
    [!IF "node:value(./SWT_ModuleID) = 'SWT3'"!]
        [!VAR "hasWdg3" = "1"!]
    [!ENDIF!]
    [!IF "node:value(./SWT_ModuleID) = 'SWT4'"!]
        [!VAR "hasWdg4" = "1"!]
    [!ENDIF!]
    [!IF "node:value(./SWT_ModuleID) = 'SWT5'"!]
        [!VAR "hasWdg5" = "1"!]
    [!ENDIF!]
    [!IF "node:value(./SWT_ModuleID) = 'SWT6'"!]
        [!VAR "hasWdg6" = "1"!]
    [!ENDIF!]
    [!IF "node:value(./SWT_ModuleID) = 'SWT7_AO'"!]
        [!VAR "hasWdg7" = "1"!]
    [!ENDIF!]
[!ENDLOOP!]
#define WDGINSTANCE0 [!WS "4"!][!IF "$hasWdg0 = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define WDGINSTANCE1 [!WS "4"!][!IF "$hasWdg1 = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define WDGINSTANCE2 [!WS "4"!][!IF "$hasWdg2 = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define WDGINSTANCE3 [!WS "4"!][!IF "$hasWdg3 = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define WDGINSTANCE4 [!WS "4"!][!IF "$hasWdg4 = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define WDGINSTANCE5 [!WS "4"!][!IF "$hasWdg5 = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define WDGINSTANCE6 [!WS "4"!][!IF "$hasWdg6 = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define WDGINSTANCE7_AO [!WS "4"!][!IF "$hasWdg7 = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
[!VAR "WdgMode0Index" = "0"!]
[!VAR "WdgMode1Index" = "0"!]
[!VAR "WdgMode2Index" = "0"!]
[!VAR "WdgMode3Index" = "0"!]
[!VAR "WdgMode4Index" = "0"!]
[!VAR "WdgMode5Index" = "0"!]
[!VAR "WdgMode6Index" = "0"!]
[!VAR "WdgMode7Index" = "0"!]

[!LOOP "WdgSettingsConfig/*"!]
    [!IF "SWT_ModuleID = 'SWT0'"!]
        [!VAR "WdgMode0Index" = "@index + 1"!]
    [!ELSEIF "SWT_ModuleID = 'SWT1'"!]
        [!VAR "WdgMode1Index" = "@index + 1"!]
    [!ELSEIF "SWT_ModuleID = 'SWT2'"!]
        [!VAR "WdgMode2Index" = "@index + 1"!]
    [!ELSEIF "SWT_ModuleID = 'SWT3'"!]
        [!VAR "WdgMode3Index" = "@index + 1"!]
    [!ELSEIF "SWT_ModuleID = 'SWT4'"!]
        [!VAR "WdgMode4Index" = "@index + 1"!]
    [!ELSEIF "SWT_ModuleID = 'SWT5'"!]
        [!VAR "WdgMode5Index" = "@index + 1"!]
    [!ELSEIF "SWT_ModuleID = 'SWT6'"!]
        [!VAR "WdgMode6Index" = "@index + 1"!]
    [!ELSEIF "SWT_ModuleID = 'SWT7_AO'"!]
        [!VAR "WdgMode7Index" = "@index + 1"!]
    [!ENDIF!]
[!ENDLOOP!]

[!IF "$hasWdg0 = 1"!]
    [!IF "WdgSettingsConfig/*[num:i($WdgMode0Index)]/SWT_ModuleID = 'SWT0'"!]
        [!IF "(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )or
              (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Fixed_Addr_Exe'  )or
              (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT0 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT0 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ELSEIF "(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe' )or
                  (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
                  (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT0 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT0 must be set up and the notification handler must be SWT0_IncrementalAddr_Callbcak[!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT0 must must have callback[!ENDERROR!]
                [!ELSE!]

extern FUNC(void, WDG_CODE)[!"node:ref(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgExternalTriggerCounterRef)/GptNotification"!](void);
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT0 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsSlow/WDGInterruptMode = 'SWT_RESET_SECOND') or (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsFast/WDGInterruptMode = 'SWT_RESET_SECOND') "!]
#define USER_SWT0_IRQ
    [!ENDIF!]
    [!IF "  (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode0Index)]/WdgExternalTriggerCounterRef)/GptNotification != WdgGeneral/WdgTriggerLocation0"!]
                    [!ERROR!] callback must be identical[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The notification handler must have a callback and be the same as wdg WdgTriggerLocation0[!ENDERROR!]
            [!ENDIF!]
            
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgTriggerLocation0"!](void);
    [!ENDIF!]
[!ELSE!]
[!ENDIF!]
[!IF "$hasWdg1 = 1"!]
    [!IF "WdgSettingsConfig/*[num:i($WdgMode1Index)]/SWT_ModuleID = 'SWT1'"!]
        [!IF "(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )or
              (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Fixed_Addr_Exe'  )or
              (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT1 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT1 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ELSEIF "(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe' )or
                  (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
                  (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT1 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT1 must be set up and the notification handler must be SWT1_IncrementalAddr_Callbcak[!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT1 must must have callback[!ENDERROR!]
                [!ELSE!]

extern FUNC(void, WDG_CODE)[!"node:ref(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgExternalTriggerCounterRef)/GptNotification"!](void);
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT1 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsSlow/WDGInterruptMode = 'SWT_RESET_SECOND') or (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsFast/WDGInterruptMode = 'SWT_RESET_SECOND') "!]
#define USER_SWT1_IRQ
    [!ENDIF!]
    [!IF "  (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode1Index)]/WdgExternalTriggerCounterRef)/GptNotification != WdgGeneral/WdgTriggerLocation1"!]
                    [!ERROR!] callback must be identical[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The notification handler must have a callback and be the same as wdg WdgTriggerLocation1[!ENDERROR!]
            [!ENDIF!]
            
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgTriggerLocation1"!](void);
    [!ENDIF!]
[!ELSE!]
[!ENDIF!]
[!IF "$hasWdg2 = 1"!]
    [!IF "WdgSettingsConfig/*[num:i($WdgMode2Index)]/SWT_ModuleID = 'SWT2'"!]
        [!IF "(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )or
              (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Fixed_Addr_Exe'  )or
              (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT2 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT2 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ELSEIF "(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe' )or
                  (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
                  (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT2 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT2 must be set up and the notification handler must be SWT2_IncrementalAddr_Callbcak[!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT2 must must have callback[!ENDERROR!]
                [!ELSE!]

extern FUNC(void, WDG_CODE)[!"node:ref(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgExternalTriggerCounterRef)/GptNotification"!](void);
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT2 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsSlow/WDGInterruptMode = 'SWT_RESET_SECOND') or (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsFast/WDGInterruptMode = 'SWT_RESET_SECOND') "!]
#define USER_SWT2_IRQ
    [!ENDIF!]
    [!IF "  (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode2Index)]/WdgExternalTriggerCounterRef)/GptNotification != WdgGeneral/WdgTriggerLocation2"!]
                    [!ERROR!] callback must be identical[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The notification handler must have a callback and be the same as wdg WdgTriggerLocation2[!ENDERROR!]
            [!ENDIF!]
            
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgTriggerLocation2"!](void);
    [!ENDIF!]
[!ELSE!]
[!ENDIF!]

[!IF "$hasWdg3 = 1"!]
    [!IF "WdgSettingsConfig/*[num:i($WdgMode3Index)]/SWT_ModuleID = 'SWT3'"!]
        [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode3Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
            [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode3Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                [!ERROR!] The notification handler for SWT3 must must have callback[!ENDERROR!]
            [!ELSE!]

extern FUNC(void, WDG_CODE)[!"node:ref(WdgSettingsConfig/*[num:i($WdgMode3Index)]/WdgExternalTriggerCounterRef)/GptNotification"!](void);
            [!ENDIF!]
        [!ELSE!]
            [!ERROR!]The channel notification for SWT3 must be set up and the notification handler must must have callback[!ENDERROR!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "(WdgSettingsConfig/*[num:i($WdgMode3Index)]/WdgSettingsSlow/WDGInterruptMode = 'SWT_RESET_SECOND') or (WdgSettingsConfig/*[num:i($WdgMode3Index)]/WdgSettingsFast/WDGInterruptMode = 'SWT_RESET_SECOND') "!]
#define USER_SWT3_IRQ
    [!ENDIF!]
[!ELSE!]
[!ENDIF!]


[!IF "$hasWdg4 = 1"!]
    [!IF "WdgSettingsConfig/*[num:i($WdgMode4Index)]/SWT_ModuleID = 'SWT4'"!]
        [!IF "(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )or
              (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Fixed_Addr_Exe'  )or
              (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT4 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT4 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ELSEIF "(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe' )or
                  (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
                  (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT4 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT4 must be set up and the notification handler must be SWT4_IncrementalAddr_Callbcak[!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT4 must must have callback[!ENDERROR!]
                [!ELSE!]

extern FUNC(void, WDG_CODE)[!"node:ref(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgExternalTriggerCounterRef)/GptNotification"!](void);
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT4 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsSlow/WDGInterruptMode = 'SWT_RESET_SECOND') or (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsFast/WDGInterruptMode = 'SWT_RESET_SECOND') "!]
#define USER_SWT4_IRQ
    [!ENDIF!]
    [!IF "  (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode4Index)]/WdgExternalTriggerCounterRef)/GptNotification != WdgGeneral/WdgTriggerLocation4"!]
                    [!ERROR!] callback must be identical[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The notification handler must have a callback and be the same as wdg WdgTriggerLocation4[!ENDERROR!]
            [!ENDIF!]
            
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgTriggerLocation4"!](void);
    [!ENDIF!]
[!ELSE!]
[!ENDIF!]

[!IF "$hasWdg5 = 1"!]
    [!IF "WdgSettingsConfig/*[num:i($WdgMode5Index)]/SWT_ModuleID = 'SWT5'"!]
        [!IF "(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )or
              (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Fixed_Addr_Exe'  )or
              (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT5 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT5 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ELSEIF "(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe' )or
                  (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
                  (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT5 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT5 must be set up and the notification handler must be SWT5_IncrementalAddr_Callbcak[!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT5 must must have callback[!ENDERROR!]
                [!ELSE!]

extern FUNC(void, WDG_CODE)[!"node:ref(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgExternalTriggerCounterRef)/GptNotification"!](void);
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT5 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsSlow/WDGInterruptMode = 'SWT_RESET_SECOND') or (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsFast/WDGInterruptMode = 'SWT_RESET_SECOND') "!]
#define USER_SWT5_IRQ
    [!ENDIF!]
    [!IF "  (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode5Index)]/WdgExternalTriggerCounterRef)/GptNotification != WdgGeneral/WdgTriggerLocation5"!]
                    [!ERROR!] callback must be identical[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The notification handler must have a callback and be the same as wdg WdgTriggerLocation5[!ENDERROR!]
            [!ENDIF!]
            
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgTriggerLocation5"!](void);
    [!ENDIF!]
[!ELSE!]
[!ENDIF!]
[!IF "$hasWdg6 = 1"!]
    [!IF "WdgSettingsConfig/*[num:i($WdgMode6Index)]/SWT_ModuleID = 'SWT6'"!]
        [!IF "(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )or
              (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Fixed_Addr_Exe'  )or
              (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe' )"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT6 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT6 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ELSEIF "(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe' )or
                  (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
                  (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT6 must must have callback[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT6 must be set up and the notification handler must be SWT6_IncrementalAddr_Callbcak[!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                    [!ERROR!] The notification handler for SWT6 must must have callback[!ENDERROR!]
                [!ELSE!]

extern FUNC(void, WDG_CODE)[!"node:ref(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgExternalTriggerCounterRef)/GptNotification"!](void);
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The channel notification for SWT6 must be set up and the notification handler must must have callback[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsSlow/WDGInterruptMode = 'SWT_RESET_SECOND') or (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsFast/WDGInterruptMode = 'SWT_RESET_SECOND') "!]
#define USER_SWT6_IRQ
    [!ENDIF!]
    [!IF "  (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Fixed_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsSlow/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsFast/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or
            (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe') or (WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgSettingsOff/WDGKeyedServiceMode = 'Incremental_Addr_Exe')"!]
            [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
                [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode6Index)]/WdgExternalTriggerCounterRef)/GptNotification != WdgGeneral/WdgTriggerLocation6"!]
                    [!ERROR!] callback must be identical[!ENDERROR!]
                [!ENDIF!]
            [!ELSE!]
                [!ERROR!]The notification handler must have a callback and be the same as wdg WdgTriggerLocation6[!ENDERROR!]
            [!ENDIF!]
            
extern FUNC(void, WDG_CODE) [!"WdgGeneral/WdgTriggerLocation6"!](void);
    [!ENDIF!]
[!ELSE!]
[!ENDIF!]


[!IF "$hasWdg7 = 1"!]
    [!IF "WdgSettingsConfig/*[num:i($WdgMode7Index)]/SWT_ModuleID = 'SWT7_AO'"!]
        [!IF "node:exists(node:ref(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgExternalTriggerCounterRef)/GptNotification)"!]
            [!IF "node:ref(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgExternalTriggerCounterRef)/GptNotification = ''"!]
                [!ERROR!] The notification handler for SWT7_AO must must have callback[!ENDERROR!]
            [!ELSE!]

extern FUNC(void, WDG_CODE)[!"node:ref(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgExternalTriggerCounterRef)/GptNotification"!](void);
            [!ENDIF!]
        [!ELSE!]
            [!ERROR!]The channel notification for SWT7 must be set up and the notification handler must must have callback[!ENDERROR!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "(WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsSlow/WDGInterruptMode = 'SWT_RESET_SECOND') or (WdgSettingsConfig/*[num:i($WdgMode7Index)]/WdgSettingsFast/WDGInterruptMode = 'SWT_RESET_SECOND') "!]
#define USER_SWT7_IRQ
    [!ENDIF!]
[!ELSE!]
[!ENDIF!]
#define WDG_INITIAL_TIMEOUT_U32             ((uint32)[!"num:i(WdgGeneral/WdgInitialTimeout * 1000*1000)"!])
#define WDG_MAX_TIMEOUT_U32                  ((uint32)[!"num:i(WdgGeneral/WdgMaxTimeout * 1000*1000)"!])
[!IF "WdgGeneral/WdgRunArea = 'ROM'"!]
#define WDG_ROM
[!ELSEIF "WdgGeneral/WdgRunArea = 'RAM'"!]
#define WDG_RAM
[!ENDIF!]

[!LOOP "WdgSettingsConfig/*"!]
   [!VAR "i"="0"!]
   [!VAR "swtcntmacro_names"="node:value(./SWT_ModuleID)"!]
   [!LOOP "../../WdgSettingsConfig/*"!]
      [!IF "$swtcntmacro_names=node:value(./SWT_ModuleID)"!]
         [!VAR "i"="$i+1"!]
      [!ENDIF!]
   [!ENDLOOP!]
   [!IF "$i > 1"!]
      [!ERROR "swt module ID duplicated. swt module ID must be unique even across ports and configurations"!]
   [!ENDIF!]
[!ENDLOOP!]

extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Disable_Rejected;
extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Mode_Failed;
#if(WDGINSTANCE0 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_0 extern CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_0;
#endif
#if(WDGINSTANCE1 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_1 extern CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_1;
#endif
#if(WDGINSTANCE2 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_2 extern CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_2;
#endif
#if(WDGINSTANCE3 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_3  extern CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_3;
#endif
#if(WDGINSTANCE4 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_4  extern CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_4;
#endif
#if(WDGINSTANCE5 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_5  extern CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_5;
#endif
#if(WDGINSTANCE6 == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_6  extern CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_6;
#endif
#if(WDGINSTANCE7_AO == STD_ON)
#define WDG_PB_CONFIG_DECLARATION_7  extern CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_7;
#endif

#ifdef __cplusplus
}
#endif
#endif
