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
*   @file    Adc_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

#ifndef ADC_CFG_H
#define ADC_CFG_H

#include "Mcal.h"
#include "eDma_LLDriver.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define ADC_VENDOR_ID                    176
#define ADC_AR_REL_MAJOR_VER             4
#define ADC_AR_REL_MINOR_VER             4
#define ADC_AR_REL_REV_VER               0
#define ADC_SW_MAJOR_VER                 1
#define ADC_SW_MINOR_VER                 0
#define ADC_SW_PATCH_VER                 1

#define ADC_MODULE_ID                    123

/*============================================FILE VERSION CHECKS===================================*/

#if (ADC_VENDOR_ID != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : MCAL_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (ADC_AR_REL_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MAJOR_VER"
#endif
#if (ADC_AR_REL_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MINOR_VER"
#endif
#if (ADC_AR_REL_REV_VER != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (ADC_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MAJOR_VER"
#endif
#if (ADC_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MINOR_VER"
#endif
#if (ADC_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_PATCH_VER"
#endif


[!AUTOSPACING!]
/* @brief    */
[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
#define ADC_PRECOMPILE_SUPPORT              (STD_ON)
[!ELSE!][!//
#define ADC_PRECOMPILE_SUPPORT              (STD_OFF)
[!ENDIF!][!//

[!SELECT "AdcGeneral"!]
/* @brief    */
[!IF "AdcDeInitApi = 'true'"!][!//
#define ADC_DEINIT_API                      (STD_ON)
[!ELSE!][!//
#define ADC_DEINIT_API                      (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcDevErrorDetect = 'true'"!][!//
#define ADC_DEV_ERROR_DETECT                (STD_ON)
[!ELSE!][!//
#define ADC_DEV_ERROR_DETECT                (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcEnableLimitCheck = 'true'"!][!//
#define ADC_ENABLE_LIMIT_CHECK              (STD_ON)
[!ELSE!][!//
#define ADC_ENABLE_LIMIT_CHECK              (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcPriorityImplementation != 'ADC_PRIORITY_NONE'"!][!//
#define ADC_ENABLE_QUEUING                  (STD_ON)
[!ELSEIF "AdcEnableQueuing"!][!//
#define ADC_ENABLE_QUEUING                  (STD_ON)
[!ELSE!][!//
#define ADC_ENABLE_QUEUING                  (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcEnableStartStopGroupApi = 'true'"!][!//
#define ADC_ENABLE_START_STOP_GROUP_API     (STD_ON)
[!ELSE!][!//
#define ADC_ENABLE_START_STOP_GROUP_API     (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcGrpNotifCapability = 'true'"!][!//
#define ADC_GRP_NOTIF_CAPABILITY            (STD_ON)
[!ELSE!][!//
#define ADC_GRP_NOTIF_CAPABILITY            (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcHwTriggerApi = 'true'"!][!//
#define ADC_HW_TRIGGER_API                  (STD_ON)
[!ELSE!][!//
#define ADC_HW_TRIGGER_API                  (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcLowPowerStatesSupport = 'true'"!][!//
#define ADC_POWER_STATE_SUPPORTED           (STD_ON)
[!ELSE!][!//
#define ADC_POWER_STATE_SUPPORTED           (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcPowerStateAsynchTransitionMode = 'true'"!][!//
#define ADC_POWER_STATE_ASYNCH_TRANSTION    (STD_ON)
[!ELSE!][!//
#define ADC_POWER_STATE_ASYNCH_TRANSTION    (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcReadGroupApi = 'true'"!][!//
#define ADC_READ_GROUP_API                  (STD_ON)
[!ELSE!][!//
#define ADC_READ_GROUP_API                  (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcVersionInfoApi = 'true'"!][!//
#define ADC_VERSION_INFO_API                (STD_ON)
[!ELSE!][!//
#define ADC_VERSION_INFO_API                (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcMulticoreSupport = 'true'"!][!//
#define ADC_ENABLE_MULTICORE                (STD_ON)
[!ELSE!][!//
#define ADC_ENABLE_MULTICORE                (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "AdcDemReportErrorEnable = 'true'"!][!//
#define ADC_DEM_REPORT_ERROR_ENABLE         (STD_ON)
[!ELSE!][!//
#define ADC_DEM_REPORT_ERROR_ENABLE         (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "EnableIntRFOF = 'true'"!][!//
#define ADC_INT_RFOF_ENABLE                 (STD_ON)
[!ELSE!][!//
#define ADC_INT_RFOF_ENABLE                 (STD_OFF)
[!ENDIF!][!//

/* @brief    */
[!IF "EnableIntTORF = 'true'"!][!//
#define ADC_INT_TORF_ENABLE                 (STD_ON)
[!ELSE!][!//
#define ADC_INT_TORF_ENABLE                 (STD_OFF)
[!ENDIF!][!//
[!ENDSELECT!]

[!VAR "Group_cnt" = "0"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!VAR "Group_tmp" = "num:i(count(AdcGroup/*))"!]
    [!IF "num:i($Group_tmp) > num:i($Group_cnt)"!][!VAR "Group_cnt" = "$Group_tmp"!][!ELSE!][!VAR "Group_cnt" = "$Group_cnt"!][!ENDIF!]
[!ENDLOOP!]

[!VAR "channel_cnt" = "0"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!LOOP "AdcGroup/*"!]
        [!VAR "channel_tmp" = "num:i(count(AdcGroupDefinition/*))"!]
        [!IF "num:i($channel_tmp) > num:i($channel_cnt)"!][!VAR "channel_cnt" = "$channel_tmp"!][!ELSE!][!VAR "channel_cnt" = "$channel_cnt"!][!ENDIF!]
    [!ENDLOOP!]
[!ENDLOOP!]

[!VAR "Group_cfg" = "0"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!LOOP "AdcGroup/*"!]
        [!VAR "Group_cfg" = "$Group_cfg+1"!]
    [!ENDLOOP!]
[!ENDLOOP!]
/* @brief    */
#define ADC_PRIORITY_IMPLEMENTATION         ([!"substring-after(string(AdcGeneral/AdcPriorityImplementation),'ADC_')"!])

/* @brief    */
#define ADC_MAX_CHANNEL                     ([!"num:i($channel_cnt)"!]U)

/* @brief    */
#define ADC_MAX_GROUPS                      ([!"num:i($Group_cnt)"!]U)

/* @brief    */
#define ADC_CONFIG_GROUPS                   ([!"num:i($Group_cfg)"!]U)

/* @brief    */
#define ADC_CONFIG_UNIT                     ([!"num:i(count(AdcConfigSet/AdcHwUnit/*))"!]U)

/* @brief    */
#define ADC_TIMEOUT                         ([!"AdcGeneral/Timeout"!]UL)

/* @brief    */
#define ADC_QUEUE_MAX_DEPTH                 ([!"AdcGeneral/QueueMaxDepth"!]U)

/* @brief    */
#define ADC_RESULT_ALIGNMENT                ([!"AdcGeneral/AdcResultAlignment"!]) 

/* @brief    */
#define ADC_MAX_HW_UNITS                    (13U)

/* @brief    */
#define ADC_DEFAULT_COREID                  ([!"num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]U)

/** Specification of ADC Driver : [SWS_Adc_00099] **/
/* Number of channels per group configuration. */
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!]
#define ADC_GROUP_[!"AdcGroupId"!]_CHANNEL_NUM             ([!"num:i(count(AdcGroupDefinition/*))"!]U)[!//

[!VAR "ChannelCnt" = "num:i(count(AdcGroupDefinition/*))"!]
[!VAR "channelindex" = "0"!]
[!FOR "GroupChannelIndex" = "0" TO "num:i($ChannelCnt)-1"!]

/* The channel index [!"num:i($channelindex)"!] of group [!"num:i($x)"!]. */
#define GROUP_[!"$x"!]_[!SELECT "node:ref(AdcGroupDefinition/*[$GroupChannelIndex+1])"!][!"@name"!][!ENDSELECT!]                ([!"num:i($channelindex)"!]U)

[!VAR "channelindex" = "$channelindex+1"!]
[!ENDFOR!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

/** Specification of ADC Driver : [SWS_Adc_00099] **/
/* The symbolic name of the group. */
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!]
#define ADC_GROUP_[!"node:name(.)"!]                ([!"AdcGroupId"!]U)[!//

[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]

[!VAR "Groupcount" = "0"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!LOOP "AdcGroup/*"!]
        [!VAR "Groupcount" = "$Groupcount+1"!]
    [!ENDLOOP!]
[!ENDLOOP!]

[!IF "AdcGeneral/AdcGrpNotifCapability = 'true'"!]
[!FOR "i" = "0" TO "num:i($Groupcount)-1"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!LOOP "AdcGroup/*"!]
    [!IF "$i = AdcGroupId"!]
        [!IF "AdcNotification != 'NULL_PTR'"!]
/* group_[!"AdcGroupId"!]_AdcNotification */
extern FUNC(void, ADC_CODE) [!"AdcNotification"!](void);
        [!ENDIF!]
        [!IF "(Overflow_Notification != 'NULL_PTR') and ((../../../../../AdcGeneral/EnableIntRFOF = 'true') or (../../../../../AdcGeneral/EnableIntTORF = 'true'))"!]
/* group_[!"AdcGroupId"!]_Overflow_Notification */
extern FUNC(void, ADC_CODE) [!"Overflow_Notification"!](void);
        [!ENDIF!]
    [!ENDIF!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDFOR!]
[!ENDIF!]

[!FOR "i" = "0" TO "num:i($Groupcount)-1"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!LOOP "AdcGroup/*"!]
    [!IF "$i = AdcGroupId"!]
        [!IF "GroupSelIntOrDma = 'DMA'"!]
        [!IF "node:ref(eDmaChannel)/eDmaChCallbaceFunction != 'NULL_PTR'"!]
/* group_[!"AdcGroupId"!]_[!"node:ref(eDmaChannel)/eDmaChannelId"!]_CallBack */
extern FUNC(void, ADC_CODE) [!"node:ref(eDmaChannel)/eDmaChCallbaceFunction"!] \
( \
    P2CONST(void, ADC_VAR, ADC_APPL_CONST) parameter, \
    VAR(eDMAChnStatusType, ADC_VAR) status, \
    VAR(uint8, ADC_VAR) mappedChannel \
);
        [!ENDIF!]
        [!IF "node:ref(ResulteDmaChannel)/eDmaChCallbaceFunction != 'NULL_PTR'"!]
/* group_[!"AdcGroupId"!]_[!"node:ref(ResulteDmaChannel)/eDmaChannelId"!]_CallBack */
extern FUNC(void, ADC_CODE) [!"node:ref(ResulteDmaChannel)/eDmaChCallbaceFunction"!] \
( \
    P2CONST(void, ADC_VAR, ADC_APPL_CONST) parameter, \
    VAR(eDMAChnStatusType, ADC_VAR) status, \
    VAR(uint8, ADC_VAR) mappedChannel \
);
        [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDFOR!]

#endif /* ADC_CFG_H */

/** @} */
