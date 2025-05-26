/****************************************************************************
*
* Copyright (c) 2022  C*Core -   All Rights Reserved
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
*   @file    Gpt_Cfg.h
*   @implements    Gpt_Cfg.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt  - Gpt driver configuration header file.
*   @details GPT driver header file, containing C and XPath constructs for generating Gpt
*            configuration header file.
*
*   @addtogroup GPT_MODULE
*   @{
*/

#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Mcal.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define GPT_VENDOR_ID                           176
#define GPT_CFG_AR_MAJOR_VER                    4
#define GPT_CFG_AR_MINOR_VER                    4
#define GPT_CFG_AR_PATCH_VER                    0
#define GPT_CFG_SW_MAJOR_VER                    1
#define GPT_CFG_SW_MINOR_VER                    0
#define GPT_CFG_SW_PATCH_VER                    1


/*============================================FILE VERSION CHECKS===================================*/
#if (MCAL_VENDOR_ID != GPT_VENDOR_ID)
    #error " NON-MATCHED DATA : GPT_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != GPT_CFG_AR_MAJOR_VER)
    #error " NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != GPT_CFG_AR_MINOR_VER)
    #error " NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != GPT_CFG_AR_PATCH_VER)
    #error " NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != GPT_CFG_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != GPT_CFG_SW_MINOR_VER)
    #error " NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != GPT_CFG_SW_PATCH_VER)
    #error " NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER "
#endif

[!NOCODE!][!//

[!ENDNOCODE!][!//

/*=================================================Constants========================================*/

/*===========================================VARIABLE DECLARATIONS==================================*/

/*============================================DEFINES AND MACROS====================================*/
/* Error report support */
#define GPT_DEV_ERROR_DETECT                    ([!IF "GptDriverConfiguration/GptDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define GPT_DEV_VALID_DETECT                    (GPT_DEV_ERROR_DETECT)

/*API support */
#define GPT_VERSION_INFO_API                    ([!IF "GptConfigurationOfOptApiServices/GptVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_DEINIT_API                          ([!IF "GptConfigurationOfOptApiServices/GptDeinitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_TIME_ELAPSED_API                    ([!IF "GptConfigurationOfOptApiServices/GptTimeElapsedApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_TIME_REMAINING_API                  ([!IF "GptConfigurationOfOptApiServices/GptTimeRemainingApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_ENABLE_DISABLE_NOTIFICATION_API     ([!IF "GptConfigurationOfOptApiServices/GptEnableDisableNotificationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_WAKEUP_FUNCTIONALITY_API            ([!IF "GptConfigurationOfOptApiServices/GptWakeupFunctionalityApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_PREDEFTIMER_FUNCTIONALITY_API       ([!IF "GptConfigurationOfOptApiServices/GptPredefTimerFunctionalityApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_REPORT_WAKEUP_SOURCE                ([!IF "GptDriverConfiguration/GptReportWakeupSource"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_PIT_CHAIN_MODE                      (STD_OFF)

#define GPT_SET_CLOCK_MODE                      (STD_OFF)

#define GPT_CHANGE_NEXT_TIMEOUT_VALUE           (STD_OFF)

#define GPT_PRECOMPILE_SUPPORT                  [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size() <= 1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define GPT_ENABLE_GTMCMU                       ([!IF "GptGeneral/EnableGTM_CMU"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_ENABLE_MULTICORE                    [!IF "node:value(GptDriverConfiguration/GptMulticoreSupport) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!//This macros is used to check the same freeze to the same module channel
[!MACRO "CheckFreeze" , "ModuleType"!][!//
    [!LOOP "GptChannelConfigSet/*"!][!//
        [!VAR "MacNumChannels" = "0"!][!//
        [!VAR "MacFreezeEnabledChannels" = "0"!][!//
        [!LOOP "GptChannelConfiguration/*/GptHwChannel[contains(., $ModuleType)]/.."!][!//
            [!IF "GptFreezeEnable"!] [!VAR "MacFreezeEnabledChannels" = "$MacFreezeEnabledChannels + 1"!][!ENDIF!][!//
            [!VAR "MacNumChannels" = "$MacNumChannels + 1"!][!//
        [!ENDLOOP!][!//
[!//
        [!IF "not($MacNumChannels = $MacFreezeEnabledChannels) and not($MacFreezeEnabledChannels = 0)"!][!//
            [!ERROR !][!//
                Module [!"$ModuleType"!] has channels configured with different values for FreezeEnable. Please select the same value for FreezeEnable accross all [!"$ModuleType"!] channels[!//
            [!ENDERROR!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDMACRO!][!//
[!NOCODE!][!//
[!//PIT and STM channels have a generic FreezeEnable bit. Check that FreezeEnable is consistent.
[!FOR "Index" = "0" TO "num:i(ecu:list('Gpt.Num_Stm_Hw_Modules'))-num:i(1)"!][!//
    [!CALL "CheckFreeze","ModuleType"="concat(string('STM_'),num:i($Index))"!][!//
[!ENDFOR!][!//
[!FOR "Index" = "0" TO "num:i(ecu:list('Gpt.Num_Pit_Hw_Modules'))-num:i(1)"!][!//
    [!CALL "CheckFreeze","ModuleType"="concat(string('PIT_'),num:i($Index))"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!NOCODE!][!//
[!VAR "ModGtmUsed"="0"!][!//
[!VAR "ModPitUsed"="0"!][!//
[!VAR "ModPitRitUsed"="0"!][!//
[!VAR "ModStmUsed"="0"!][!//
[!VAR "ModGtmOutputPinUsed"="0"!][!//
[!// Loop on all Configuration Sets
[!VAR "ConfigSetIndex" = "../../@index"!][!//
[!// Loop Config Channel Type
[!LOOP "./GptChannelConfiguration/*"!][!//
    [!IF "contains(GptHwChannel, 'STM')"!][!//
        [!VAR "ModStmUsed"="1"!][!//
    [!ELSEIF "contains(GptHwChannel, 'GTM')"!][!//
        [!VAR "ModGtmUsed"="1"!][!//
        [!IF "GptGtmChannelOutputPinEnable = 'true'"!][!//
            [!VAR "ModGtmOutputPinUsed"="1"!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains(GptHwChannel, 'PIT')"!][!//
        [!VAR "ModPitUsed"="1"!]
    [!ELSEIF "contains(GptHwChannel, 'RTI')"!][!//
        [!VAR "ModPitRitUsed"="1"!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
/* Used for GTM channel */
#define GPT_GTM_OUTPUT_ENABLE_MODE              ([!IF "$ModGtmOutputPinUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_CHN_NOT_USED    (255U)

/* Define all GPT physical channel no */
[!//This macros is used to build the GPT handle
[!NOCODE!][!//
    [!VAR "channelsNum"="num:i(count(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel')))"!][!//
    [!FOR "MacModuleId" = "0" TO "$channelsNum"!]
        [!VAR "channelName"="(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'))[num:i($MacModuleId)]"!]
        [!IF "contains(substring-before($channelName, '_CH'),'GTM')"!]
            [!VAR "module" = "num:i(substring($channelName,5,1))"!]
            [!VAR "channel"="num:i(substring-after($channelName, '_CH_'))"!]
            [!VAR "handle"="num:inttohex(num:add(num:mul($module, 32),$channel))"!]
[!CODE!]
#define GTM_[!"$module"!]_CH_[!"$channel"!]                 [!"$handle"!][!ENDCODE!]
        [!ELSE!]
            [!IF "contains(substring-before($channelName, '_CH'),'PIT')"!]
                [!VAR "module" = "num:i(substring($channelName,5,1))"!]
                [!IF "num:isnumber(substring-after($channelName, '_CH_'))"!]
                        [!VAR "channel"="num:i(substring-after($channelName, '_CH_'))"!]
                        [!VAR "handle"="num:inttohex(num:add(num:mul($module, 16),$channel))"!]
                    [!ELSE!]
                        [!VAR "channel"="substring-after($channelName, '_CH_')"!]
                        [!VAR "handle"="num:inttohex(num:add(num:mul($module, 16),8))"!]
                    [!ENDIF!]
                [!CODE!]
#define PIT_[!"$module"!]_CH_[!"$channel"!]                 [!"$handle"!][!ENDCODE!]
            [!ELSE!]
                [!IF "contains(substring-before($channelName, '_CH'),'STM')"!]
                    [!VAR "module" = "num:i(substring($channelName,5,1))"!]
                    [!VAR "channel"="num:i(substring-after($channelName, '_CH_'))"!]
                    [!VAR "handle"="num:inttohex(num:add(num:mul($module, 16),$channel))"!]
                    [!CODE!]
#define STM_[!"$module"!]_CH_[!"$channel"!]                 [!"$handle"!][!ENDCODE!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDNOCODE!]
#define RTC_0_CH_0                 0x0U
#define API_0_CH_0				   0x1U

/* Config all GPT channel number */
[!NOCODE!][!//
[!VAR "NumHwChannel"="0"!]
[!LOOP "GptChannelConfigSet"!]
    [!IF "$NumHwChannel < num:i(count(GptChannelConfiguration/*))"!][!//
        [!VAR "NumHwChannel"="num:i(count(GptChannelConfiguration/*))"!]
        [!CODE!]
#define GPT_HW_CHANNEL_NUM                      ([!"num:i($NumHwChannel)"!]U)
        [!ENDCODE!]
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

#define GPT_HW_PREDEFTIMER_NUM                  (4U)
/* retry times */
#define GPT_RETRY_TIMEOUT_COUNTER               ([!"num:i(GptConfigurationOfOptApiServices/GptTimeout)"!]UL)

#define GPT_DEFAULT_COREID                      [!"num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]U
[!VAR "MacMaxModulesSTM" = "num:i(ecu:get('Gpt.Num_Stm_Hw_Modules'))"!][!//
[!VAR "MacMaxModulesPIT" = "num:i(ecu:get('Gpt.Num_Pit_Hw_Modules'))"!][!//
[!VAR "MacMaxModulesGTM" = "num:i(ecu:get('Gpt.Num_Gtm_Hw_Modules'))"!][!//
[!VAR "MacMaxModulesRTCAPI" = "num:i(ecu:get('Gpt.Num_RTCAPI_Hw_Modules'))"!][!//
[!VAR "BaseMacMaxModulesSTM" = "num:i(0)"!][!//
[!VAR "BaseMacMaxModulesPIT" = "num:i($BaseMacMaxModulesSTM) + num:i($MacMaxModulesSTM)"!][!//
[!VAR "BaseMacMaxModulesGTM" = "num:i($BaseMacMaxModulesPIT) + num:i($MacMaxModulesPIT)"!][!//
[!VAR "BaseMacMaxModulesRTCAPI" = "num:i($BaseMacMaxModulesGTM) + num:i($MacMaxModulesGTM)"!][!//
[!VAR "STMChannelsCount"="0"!][!//
[!VAR "PITChannelsCount"="0"!][!//
[!VAR "GTMChannelsCount"="0"!][!//
[!VAR "RTCAPIChannelsCount"="0"!][!//
[!VAR "LoopIdx" = "num:i(0)"!][!//
[!LOOP "text:split(ecu:get('Gpt.Num_Channels_Per_Module'), ',')"!][!//
    [!IF "$LoopIdx < $BaseMacMaxModulesPIT"!][!//
        [!VAR "STMChannelsCount" = "num:i($STMChannelsCount) + num:i(node:current())"!][!//
    [!ELSEIF "$LoopIdx < $BaseMacMaxModulesGTM"!][!//
        [!VAR "PITChannelsCount" = "num:i($PITChannelsCount) + num:i(node:current())"!][!//
    [!ELSEIF "$LoopIdx < $BaseMacMaxModulesRTCAPI"!][!//
        [!VAR "GTMChannelsCount" = "num:i($GTMChannelsCount) + num:i(node:current())"!][!//
    [!ELSE!][!//
        [!VAR "RTCAPIChannelsCount" = "num:i($RTCAPIChannelsCount) + num:i(node:current())"!][!//
    [!ENDIF!][!//
    [!VAR "LoopIdx" = "num:i($LoopIdx) + num:i(1)"!][!//
[!ENDLOOP!][!//

#define GPT_STM_MODULE_INDEX        (0U)      /* index where the STM channels start*/
#define GPT_PIT_MODULE_INDEX        ([!"num:i($STMChannelsCount)"!]U)     /* index where the PIT channels start*/
#define GPT_GTM_MODULE_INDEX        ([!"num:i($STMChannelsCount + $PITChannelsCount)"!]U)     /* index where the GTM channels start*/
#define GPT_RTC_MODULE_INDEX        ([!"num:i($STMChannelsCount + $PITChannelsCount + $GTMChannelsCount)"!]U)    /* index where the RTC channels start*/
#define GPT_API_MODULE_INDEX        ([!"num:i($STMChannelsCount + $PITChannelsCount + $GTMChannelsCount + $RTCAPIChannelsCount - 1)"!]U)    /* index where the API channels start*/

#define GPT_CHANNEL_IDX_NUM    (180U)

[!INDENT "0"!]
[!NOCODE!]
    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!LOOP "GptChannelConfigSet/GptChannelConfiguration/*"!]
        [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!VAR "Matchcounter" = "0"!]
        [!VAR "Name" = "node:name(.)"!]
        [!LOOP "../../../*/GptChannelConfiguration/*"!]
            [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
            [!IF "($Name = node:name(.))"!]
                    [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$Matchcounter = 1"!]
                [!CODE!]
#define [!"node:name(.)"!]                           (GptConf_GptChannel_[!"node:name(.)"!])[!CR!]
#define GptConf_GptChannel_[!"node:name(.)"!]        ((Gpt_ChannelType)[!"@index"!]U) [!CR!]
                [!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDINDENT!][!//

/*===================================================ENUMS==========================================*/

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

/*===============================================LOCAL FUNCTIONS====================================*/

/*==============================================GLOBAL FUNCTIONS====================================*/

#ifdef __cplusplus
}
#endif

#endif  /* GPT_CFG_H */

/** @} */
