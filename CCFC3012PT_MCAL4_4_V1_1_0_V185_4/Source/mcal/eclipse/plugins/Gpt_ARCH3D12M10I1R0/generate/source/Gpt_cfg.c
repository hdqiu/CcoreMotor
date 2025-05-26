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
*   @file    Gpt_cfg.c
*   @implements     Gpt_cfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt -  GPT driver configuration source file.
*   @details GPT driver source file, containing C and XPath constructs for generating Gpt
*            configuration source file for the Post-build configuration variant.
*
*   @addtogroup GPT_MODULE
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

#include "Gpt_Cfg.h"
#include "Gpt.h"
#include "Gpt_Rtc_LLDriver.h"
[!AUTOSPACING!]

/*================================SOURCE FILE VERSION INFORMATION===================================*/
#define GPT_VENDOR_ID_OUTPUT                    176
#define GPT_CFG_AR_MAJOR_VER                    4
#define GPT_CFG_AR_MINOR_VER                    4
#define GPT_CFG_AR_PATCH_VER                    0 
#define GPT_CFG_SW_MAJOR_VER                    1
#define GPT_CFG_SW_MINOR_VER                    0
#define GPT_CFG_SW_PATCH_VER                    1
/*==================================FILE VERSION CHECKS=============================================*/
#if (MCAL_VENDOR_ID != GPT_VENDOR_ID_OUTPUT)
    #error " NON-MATCHED DATA : GPT_VENDOR_ID_OUTPUT "
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

/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/
[!VAR "AlreadyParsedNotification"!][!ENDVAR!][!//
[!LOOP "GptChannelConfigSet/GptChannelConfiguration/*/GptNotification"!][!//
[!IF "(. != 'NULL_PTR') and (. != 'NULL')"!][!//
[!IF "contains($AlreadyParsedNotification, concat(.,'|')) = false()"!][!//
extern void [!"."!](void);
[!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,.,'|')"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

/*======================================LOCAL MACROS================================================*/

/*=====================================LOCAL CONSTANTS==============================================*/

/*=====================================LOCAL VARIABLES==============================================*/

/*=====================================GLOBAL CONSTANTS=============================================*/
[!NOCODE!][!//
[!MACRO "BuildHwPredefChannelData"!][!//
[!CODE!][!WS"4"!](uint8)([!"GptHwChannel"!]), /* GPT physical channel no. */[!CR!][!ENDCODE!][!//
    [!CODE!][!WS"4"!](Gpt_Module)(GPT_MODULE_[!"substring-before(GptHwChannel, '_')"!]), /* hardware module ID */[!CR!][!ENDCODE!]
    [!IF "GptFreezeEnable"!][!//
        [!CODE!][!WS"4"!](boolean)TRUE, /* Freeze Enable */[!CR!][!ENDCODE!]
    [!ELSE!][!//
        [!CODE!][!WS"4"!](boolean)(FALSE), /* Freeze Disable */[!CR!][!ENDCODE!]
    [!ENDIF!][!//
    [!IF "contains(GptHwChannel, 'STM')"!][!//
        [!CODE!][!WS"4"!](uint8)([!"num:i(number(GptChannelPrescaler) - 1)"!]U), /* STM Clock divider */[!CR!][!ENDCODE!]
    [!ELSE!][!//
        [!CODE!][!WS"4"!](uint8)([!"num:i(number(GptChannelPrescaler) - 1)"!]U), /* EMIOS Clock divider */[!CR!][!ENDCODE!]
    [!ENDIF!][!//
[!ENDMACRO!][!//

[!//This macros is used to build the Predef timer configuration structure.
[!MACRO "BuildHwPredefChannelConfig", "predefType"!]
[!NOCODE!]
[!VAR "path_temp" = "'GptPredefTimer_1us_16Bit'"!][!//
[!IF "$predefType = 'PREDEF_TIMER_1US_16BIT'"!][!//
    [!VAR "path_temp" = "'GptPredefTimer_1us_16Bit'"!][!//
[!ELSEIF "$predefType = 'PREDEF_TIMER_1US_24BIT'"!][!//
    [!VAR "path_temp" = "'GptPredefTimer_1us_24Bit'"!][!//
[!ELSEIF "$predefType = 'PREDEF_TIMER_1US_32BIT'"!][!//
    [!VAR "path_temp" = "'GptPredefTimer_1us_32Bit'"!][!//
[!ELSE!][!//
    [!VAR "path_temp" = "'GptPredefTimer_100us_32Bit'"!][!//
[!ENDIF!][!//

[!VAR "path_predef" = "concat('GptPredefTimerConfiguration/',$path_temp)"!]
[!SELECT "node:ref($path_predef)"!]
    [!IF "contains(GptHwChannel,'STM')"!][!//
        [!CALL "PredefTimerStmConsistencyCheck"!][!//
    [!ENDIF!][!//
    [!CALL "BuildHwPredefChannelData"!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!//This macros is used to check parameters
[!MACRO "CheckParameter" , "ModuleType", "param"!]
    [!IF "$ModuleType = 'STM'"!]
        [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Stm_Hw_Modules'))"!]
    [!ELSEIF "$ModuleType = 'PIT'"!]
        [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Pit_Hw_Modules'))"!]
    [!ELSEIF "$ModuleType = 'GTM'"!]    
            [!IF "../*/../GptGeneral/DisableGTMmodule = 'true'"!][!//
            [!ELSE!][!//
           [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Gtm_Hw_Modules'))"!]
           [!ENDIF!][!// 
    [!ELSEIF "$ModuleType = 'RTC'"!]    
           [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_RTC_Hw_Modules'))"!]
    [!ENDIF!]  
        
     [!VAR "MacErrorFlag" = "string('Invalid')"!]
    
    [!FOR "idx" = "0" TO "num:i($MacMaxModules)"!]
        [!VAR "MacErrorFlag" = "string('Invalid')"!]
        [!FOR "x" = "0" TO "num:i(count(GptChannelConfiguration/*))"!]
        [!SELECT "GptChannelConfiguration/*/GptChannelId[.=$x]/.."!]
            [!IF "contains(GptHwChannel, concat($ModuleType, '_', $idx)) and node:exists($param)"!]
                [!IF "($MacErrorFlag = string('Invalid'))"!]
                    [!VAR "MacErrorFlag" = "string(node:value($param))"!]
                [!ELSE!]
                    [!IF "($MacErrorFlag = string(node:value($param)))"!]
                    [!ELSE!]
                        [!ERROR!]
                        [!"concat('For the ',$ModuleType, '_', $idx,' module all the channels must have the same value for the ', $param, ' parameter, because this module has one general clock prescaler for all its counter channels.')"!][//
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]  
            [!ENDIF!]  
        [!ENDSELECT!]
        [!ENDFOR!]
    [!ENDFOR!]
[!ENDMACRO!]

[!MACRO "BuildHwChannel"!]
[!NOCODE!][!//
[!CODE!][!//
    .u8HwChannel = (uint8)([!"GptHwChannel"!]), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_[!"substring-before(GptHwChannel, '_')"!]), /* hardware module ID */
    .bFreezeEnable = (boolean)[!IF "GptFreezeEnable"!]TRUE[!ELSE!](FALSE)[!ENDIF!], /* Freeze Enable */
[!ENDCODE!][!//
    [!IF "contains(GptHwChannel, 'GTM_')"!][!//
[!CODE!][!//
    .u32GtmChannelRegCtrl1 = (uint32)[!"GptGTMConfiguration/GptGtmChannelClkSrc"!] | (uint32)[!IF "GptChannelMode = 'GPT_CH_MODE_CONTINUOUS'"!] GTM_CH_MODE_CONTINUOUS[!ELSE!]GTM_CH_MODE_ONESHOT[!ENDIF!], /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)[!IF "GptGtmChannelOutputPinEnable = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* Gtm register contain output pin enabled and output pin mode*/
#endif

[!ENDCODE!][!//
    [!ELSEIF "contains(GptHwChannel, 'STM_')"!][!//
[!CODE!][!//
    .u32GtmChannelRegCtrl1 = (uint32)0, /* Not used for STM */

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for STM */
#endif

[!ENDCODE!][!//
    [!ELSEIF "contains(GptHwChannel, 'PIT_')"!][!//
[!CODE!][!//
    .u32GtmChannelRegCtrl1 = (uint32)0U, /* Not used for PIT */
#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for PIT */
#endif
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains(GptHwChannel, 'STM')"!][!//
[!CODE!][!//
    .u8StmPrescaler = (uint8)([!"num:i(number(GptStmPrescaler)-1)"!]U), /* STM Clock divider */
[!ENDCODE!][!//
    [!ELSE!][!//
        [!IF "contains(GptHwChannel, 'PIT')"!][!//
[!CODE!][!//
    .u8StmPrescaler = (uint8)(0U), /* Not used for PIT */
[!ENDCODE!][!//
        [!ELSEIF "contains(GptHwChannel, 'RTC')"!][!//
[!CODE!][!//
    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
[!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!CODE!][!//
    .u32ClkFreq = [!"num:i(node:value(node:ref(node:ref(GptChannelClkSrcRef)/GptClockReference)/McuClockReferencePointFrequency))"!]U,
[!ENDCODE!][!//
[!IF "contains(GptHwChannel, 'RTC') or contains(GptHwChannel, 'API')"!][!//
[!CODE!]
    .eRtcClk = [!"GptRTCConfiguration/GptRtcClkSrc"!],
    .eRtcDiv = [!"GptRTCConfiguration/GptRtcClkDiv"!],
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!]
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "BuildChannelSet"!]
[!NOCODE!][!//
[!FOR "x" = "0" TO "num:i(count(GptChannelConfiguration/*))"!][!//
    [!SELECT "GptChannelConfiguration/*/GptChannelId[.=$x]/.."!][!//
    [!CODE!][!//
static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_[!"num:i($x)"!] =
{
    [!CALL "BuildHwChannel"!][!//
};

[!ENDCODE!]
    [!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!//This macros is used to build the configuration structure for a config set.
[!MACRO "BuildConfigSet"!]
[!//
    [!CALL "CheckParameter","ModuleType"="string('STM')", "param"="string('GptChannelTickFrequency')"!][!//
    [!CALL "CheckParameter","ModuleType"="string('STM')", "param"="string('GptChannelClkSrcRef')"!][!//

    [!FOR "x" = "0" TO "num:i(count(GptChannelConfiguration/*))"!][!//
    [!SELECT "GptChannelConfiguration/*/GptChannelId[.=$x]/.."!][!//
[!//
[!CODE!][!//
    /*[!"node:name(.)"!] configuration data*/
    {   
        .u8Instance = ([!"num:i(GptChannelId)"!]U), /* GPT instance */
        .bEnableWakeup = (boolean)[!IF "node:exists(GptEnableWakeup)"!][!IF "GptEnableWakeup"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!], /* Wakeup capability */
        .pfNotification = ([!IF "node:exists(GptNotification)"!][!IF "(GptNotification != '') and (GptNotification != 'NULL_PTR') and (GptNotification != 'NULL')"!]&[!"GptNotification"!][!ELSE!]NULL_PTR[!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!]), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)[!IF "node:exists(GptWakeupConfiguration)"!]((uint32)((uint32)1<<[!"as:ref(GptWakeupConfiguration/GptWakeupSourceRef)/EcuMWakeupSourceId"!]))[!ELSE!]0U[!ENDIF!], /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)([!"num:i(GptChannelTickValueMax)"!]U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)([!"GptChannelMode"!]), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_[!"num:i($x)"!]
    },
[!ENDCODE!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!MACRO "PredefTimerStmConsistencyCheck"!]
[!VAR "MacCurrentModule" = "substring-before(GptHwChannel,'_CH')"!]
[!VAR "MacGptChannelClkSrcRef" = "GptChannelClkSrcRef"!]
[!VAR "MacGptChannelPrescaler" = "GptChannelPrescaler"!]
[!VAR "MacGptFreezeEnable" = "GptFreezeEnable"!]
[!LOOP "../*"!]
     [!IF "substring-before(GptHwChannel,'_CH') = $MacCurrentModule"!]
        [!IF "GptChannelClkSrcRef != $MacGptChannelClkSrcRef"!]
            [!ERROR!]
                GptChannelClkSrcRef of predeftimer [!"$MacCurrentModule"!] is not consistency with other predeftimer channel
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptChannelPrescaler != $MacGptChannelPrescaler"!]
            [!ERROR!]
                GptChannelPrescaler of predeftimer [!"$MacCurrentModule"!] is not consistency with other predeftimer channel
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptFreezeEnable != $MacGptFreezeEnable"!]
            [!ERROR!]
                GptFreezeEnable of predeftimer [!"$MacCurrentModule"!] is not consistency with other predeftimer channel
            [!ENDERROR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!LOOP "../../GptChannelConfigSet/GptChannelConfiguration/*"!]
    [!IF "substring-before(GptHwChannel,'_CH_') = $MacCurrentModule"!]
        [!IF "GptChannelClkSrcRef != $MacGptChannelClkSrcRef"!]
            [!ERROR!]
                GptChannelClkSrcRef of predeftimer [!"$MacCurrentModule"!] is not consistency with Gpt channel [!"GptChannelId"!]
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptStmPrescaler != $MacGptChannelPrescaler"!]
            [!ERROR!]
                GptChannelConfiguration GptStmPrescaler is [!"GptStmPrescaler"!] GptPredefTimer is [!"$MacGptChannelPrescaler"!], [!//
                GptStmPrescaler of predeftimer [!"$MacCurrentModule"!] is not consistency with Gpt channel [!"GptChannelId"!]
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptFreezeEnable != $MacGptFreezeEnable"!]
            [!ERROR!]
                GptFreezeEnable of predeftimer [!"$MacCurrentModule"!] is not consistency with Gpt channel [!"GptChannelId"!]
            [!ENDERROR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDMACRO!]
[!ENDNOCODE!]

[!MACRO "IndexChannelList", "ModuleType", "ModuleId"!][!//
    [!VAR "ChannelPrefix" = "concat($ModuleType, '_', $ModuleId, '_CH_')"!][!//
    [!VAR "IndexList" = "text:replaceAll(text:join(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'), concat($ChannelPrefix,'.*'))), $ChannelPrefix, '')"!][!//
    [!"$IndexList"!][!//
[!ENDMACRO!][!//
[!MACRO "AllChannelsUsedUnique", "AllChannelsUnion"!][!//
    [!VAR "AllChannelsUnique" = "''"!][!//
    [!FOR "index" = "0" TO "num:i(count(text:split($AllChannelsUnion)))"!][!//
        [!IF "not(text:contains(text:split($AllChannelsUnique), text:split($AllChannelsUnion)[$index + 1]))"!][!//
            [!VAR "AllChannelsUnique" = "concat($AllChannelsUnique, ' ', text:split($AllChannelsUnion)[$index + 1])"!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
    [!"$AllChannelsUnique"!][!//
[!ENDMACRO!][!//

[!//This macros is used to build the hardware to logic map table
[!MACRO "BuildChannelMap" , "ModuleType", "LastModule", "Partition"!]
    [!IF "$ModuleType = 'STM'"!]
        [!VAR "MacMaxModules" = "num:i(ecu:list('Gpt.Num_Stm_Hw_Modules'))"!][!//
    [!ELSEIF "$ModuleType = 'PIT'"!][!//
        [!VAR "MacMaxModules" = "num:i(ecu:list('Gpt.Num_Pit_Hw_Modules'))"!][!//
    [!ELSEIF "$ModuleType = 'GTM'"!][!//
       [!VAR "MacMaxModules" = "num:i(ecu:list('Gpt.Num_Gtm_Hw_Modules'))"!][!//
    [!ELSEIF "($ModuleType = 'RTC') or ($ModuleType = 'API')"!][!//
       [!VAR "MacMaxModules" = "num:i(ecu:list('Gpt.Num_RTCAPI_Hw_Modules')) - 1"!][!//
    [!ENDIF!][!//
    [!VAR "ModuleTypeAll" = "''"!]
    [!FOR "MacModuleId" = "0" TO "num:i($MacMaxModules) - 1"!][!//
        [!VAR "TempChannelList"!][!CALL "IndexChannelList", "ModuleType" = "$ModuleType", "ModuleId" = "$MacModuleId"!][!ENDVAR!]
        [!VAR "ModuleTypeAll" = "concat($ModuleTypeAll, ' ', $TempChannelList)"!]
    [!ENDFOR!][!//
[!//Hardware to logic channel mapping
    [!VAR "UsedChannels"!][!CALL "AllChannelsUsedUnique", "AllChannelsUnion" = "$ModuleTypeAll"!][!ENDVAR!]
    [!VAR "MacMaxChannelId" = "num:i(text:split($UsedChannels)[last()] + 1)"!][!//
        [!IF "$ModuleType = 'PIT'"!][!//PIT_RTI extra channel
            [!VAR "MacMaxChannelId" = "$MacMaxChannelId + 1"!][!//
        [!ENDIF!][!//   
        
    [!FOR "MacModuleId" = "0" TO "num:i($MacMaxModules) - 1"!][!//
        [!FOR "MacChannelId" = "0" TO "num:i($MacMaxChannelId) - 1"!][!//
            [!VAR "MacChannelUsed" = "0"!][!//
            [!FOR "MacLogicChannel" = "0" TO "num:i(count(//GptChannelConfigSet/GptChannelConfiguration/*))"!][!//
                [!SELECT "//GptChannelConfigSet/GptChannelConfiguration/*/GptChannelId[.=$MacLogicChannel]/.."!][!//
[!IF "(contains(GptChannelEcucPartitionRef/*,$Partition)) or ($Partition = string(null))"!]     [!//      
                [!IF "$ModuleType = 'PIT'"!][!//  
                    [!IF "num:i($MacChannelId) = 8"!][!//  
                        [!IF "GptHwChannel = concat($ModuleType,'_',num:i($MacModuleId),'_CH_RTI')"!][!//
                            [!CODE!][!//  
        GptConf_GptChannel_[!"node:name(.)"!][!ENDCODE!]
                            [!VAR "MacChannelUsed" = "1"!][!//
                        [!ENDIF!][!//
                    [!ELSE!]
                        [!IF "GptHwChannel = concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!][!//
                            [!CODE!]
        GptConf_GptChannel_[!"node:name(.)"!][!ENDCODE!]
                            [!VAR "MacChannelUsed" = "1"!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ELSE!]
                    [!IF "GptHwChannel = concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!][!//
                        [!CODE!]
        GptConf_GptChannel_[!"node:name(.)"!][!ENDCODE!]
                        [!VAR "MacChannelUsed" = "1"!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
[!ENDIF!][!//  
                [!ENDSELECT!][!//
            [!ENDFOR!][!//
            [!IF "$MacChannelUsed = 0"!][!//
                [!CODE!]
        GPT_CHN_NOT_USED[!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "$MacModuleId = (num:i($MacMaxModules - 1)) and $MacChannelId = (num:i($MacMaxChannelId - 1)) and $LastModule = 'TRUE'"!][!//
            [!ELSE!][!//
                [!CODE!],[!ENDCODE!][!//
            [!ENDIF!][!//
            [!IF "$ModuleType = 'STM'"!][!//
                        /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i(text:split($UsedChannels)[$MacChannelId + 1]))"!]*/
            [!ELSEIF "$ModuleType = 'PIT'"!][!//
                [!IF "$MacChannelId = 8"!][!//
                        /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_RTI')"!]*/
                [!ELSE!]
                        /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!]*/
                [!ENDIF!][!//              
            [!ELSEIF "$ModuleType = 'GTM'"!][!//
                [!IF "../*/../GptGeneral/DisableGTMmodule = 'true'"!][!//
                [!ELSE!][!//
                    /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i(text:split($UsedChannels)[$MacChannelId + 1]))"!]*/    
                [!ENDIF!][!//        
            [!ELSEIF "$ModuleType = 'API'"!][!//
                        /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i(text:split($UsedChannels)[$MacChannelId + 1]))"!]*/
            [!ELSEIF "$ModuleType = 'RTC'"!][!//
                        /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i(text:split($UsedChannels)[$MacChannelId + 1]))"!]*/
            [!ENDIF!][!//
        [!ENDFOR!][!//
    [!ENDFOR!][!//  
[!ENDMACRO!][!//  

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
[!NOCODE!]
[!VAR "flag_1us_16bit" = "'false'"!][!//
[!VAR "flag_1us_16bit_24bit" = "'false'"!][!//
[!VAR "flag_1us_16bit_24bit_32bit" = "'false'"!][!//
[!VAR "flag_100us_32bit" = "'false'"!][!//
[!SELECT "GptDriverConfiguration"!][!//
    [!IF "(GptPredefTimer1usEnablingGrade = 'GPT_PREDEF_TIMER_1US_16BIT_ENABLED')"!][!//
        [!VAR "flag_1us_16bit"="'true'"!][!//
    [!ENDIF!][!//
    [!IF "(GptPredefTimer1usEnablingGrade = 'GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED')"!][!//
        [!VAR "flag_1us_16bit_24bit"="'true'"!][!//
    [!ENDIF!][!//
    [!IF "(GptPredefTimer1usEnablingGrade = 'GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED')"!][!//
        [!VAR "flag_1us_16bit_24bit_32bit"="'true'"!][!//
    [!ENDIF!][!//
    [!IF "(GptPredefTimer100us32bitEnable = 'true')"!][!//
        [!VAR "flag_100us_32bit"="'true'"!][!//
    [!ENDIF!][!//
[!ENDSELECT!][!//
[!CODE!][!//
[!IF "($flag_1us_16bit = 'true') or ($flag_1us_16bit_24bit = 'true') or ($flag_1us_16bit_24bit_32bit = 'true')"!][!//
static CONST(Gpt_HwPredefChannelConfig, GPT_CONST) Gpt_pInitPredefTimer_1us_16bit=
{
[!NOCODE!][!//
  [!CALL "BuildHwPredefChannelConfig","predefType"="string('PREDEF_TIMER_1US_16BIT')"!]
[!ENDNOCODE!][!//
};
[!ENDIF!][!//
[!//
[!IF "($flag_1us_16bit_24bit = 'true')or ($flag_1us_16bit_24bit_32bit = 'true')"!][!//
static CONST(Gpt_HwPredefChannelConfig, GPT_CONST) Gpt_pInitPredefTimer_1us_24bit=
{
[!NOCODE!][!//
  [!CALL "BuildHwPredefChannelConfig","predefType"="string('PREDEF_TIMER_1US_24BIT')"!]
[!ENDNOCODE!][!//
};
[!ENDIF!][!//
[!//
[!IF "($flag_1us_16bit_24bit_32bit = 'true')"!][!//
static CONST(Gpt_HwPredefChannelConfig, GPT_CONST) Gpt_pInitPredefTimer_1us_32bit=
{
[!NOCODE!][!//
  [!CALL "BuildHwPredefChannelConfig","predefType"="string('PREDEF_TIMER_1US_32BIT')"!]
[!ENDNOCODE!][!//
};
[!ENDIF!][!//
[!//
[!IF "$flag_100us_32bit = 'true'"!][!//
static CONST(Gpt_HwPredefChannelConfig, GPT_CONST) Gpt_pInitPredefTimer_100us_32bit=
{
[!NOCODE!][!//
  [!CALL "BuildHwPredefChannelConfig","predefType"="string('PREDEF_TIMER_100US_32BIT')"!]
[!ENDNOCODE!][!//
};
[!ENDIF!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//

static CONSTP2CONST(Gpt_HwPredefChannelConfig, GPT_CONST, GPT_APPL_CONST) Gpt_pInitPredefTimerChannel[GPT_HW_PREDEFTIMER_NUM]=
{
[!IF "($flag_1us_16bit = 'true') or ($flag_1us_16bit_24bit = 'true')or ($flag_1us_16bit_24bit_32bit = 'true')"!][!//
    &Gpt_pInitPredefTimer_1us_16bit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!IF "($flag_1us_16bit_24bit = 'true')or ($flag_1us_16bit_24bit_32bit = 'true')"!][!//
    &Gpt_pInitPredefTimer_1us_24bit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!IF "($flag_1us_16bit_24bit_32bit = 'true')"!][!//
    &Gpt_pInitPredefTimer_1us_32bit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!IF "($flag_100us_32bit = 'true')"!][!//
    &Gpt_pInitPredefTimer_100us_32bit[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
[!ELSE!][!//
    NULL_PTR
[!ENDIF!][!//
};
#endif

[!MACRO "GetCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRef_cnt" = "num:i(count(GptChannelEcucPartitionRef/*))"!][!//
    [!IF "$EcucPartitionRef_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!// 
    [!ELSE!][!//
        [!FOR "i" = "0" TO "num:i($EcucPartitionRef_cnt)-1"!][!//
            [!VAR "ModuEcucPartitionRef" = "string(GptChannelEcucPartitionRef/*[$i+1])"!][!//
            [!IF "not(node:refexists(GptChannelEcucPartitionRef/*[$i+1]))"!][!//
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
                                [!VAR "CoreID_temp" = "node:ref(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])/EcucCoreId"!][!//
                                [!VAR "CoreID" = "bit:or($CoreID,bit:shl(1,$CoreID_temp))"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDFOR!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
        [!IF "$EcucPartitionRefMatch_cnt = num:i(0)"!][!//
            [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
 [!"$CoreID"!]
[!ENDMACRO!][!//

[!LOOP "GptChannelConfigSet"!][!//
[!CALL "BuildChannelSet"!]
static CONST(Gpt_ChannelConfig, GPT_CONST) Gpt_InitChannel[[!"num:i(count(GptChannelConfiguration/*))"!]] =
{
    [!CALL "BuildConfigSet"!]
[!CODE!][!//
};
[!ENDCODE!]

[!CODE!][!//
#if (GPT_ENABLE_MULTICORE == STD_ON)
static CONST(Gpt_CoreMapItemType, GPT_CONST) Gpt_CoreMap[GPT_HW_CHANNEL_NUM]=
{
[!LOOP "(GptChannelConfiguration/*)"!]
    [!VAR "u8HwChannel" = "num:i(./GptChannelId)"!]
    {
        .u8HwChannel = [!"$u8HwChannel"!],
        .u8CoreId = [!CALL "GetCoreID"!]
    },
[!ENDLOOP!]
};
#endif
[!ENDCODE!][!//

CONST(Gpt_ConfigType, GPT_CONST) [!"@name"!];
CONST(Gpt_ConfigType, GPT_CONST) [!"@name"!] =
{
    (Gpt_ChannelType)[!"num:i(count(GptChannelConfiguration/*))"!]U,
    &Gpt_InitChannel
#if (GPT_ENABLE_MULTICORE == STD_ON)
    ,Gpt_CoreMap
#endif
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    ,Gpt_pInitPredefTimerChannel
#endif
    /*Hardware to logic channel mapping.*/
    ,{[!CODE!]
    [!CALL "BuildChannelMap","ModuleType"="string('STM')","LastModule"="string('FALSE')"!][!//
    [!CALL "BuildChannelMap","ModuleType"="string('PIT')","LastModule"="string('FALSE')"!][!//
    [!IF "../*/../GptGeneral/DisableGTMmodule = 'true'"!][!//
    [!ELSE!][!//
    [!CALL "BuildChannelMap","ModuleType"="string('GTM')","LastModule"="string('FALSE')"!][!//
    [!ENDIF!][!// 
    [!CALL "BuildChannelMap","ModuleType"="string('RTC')","LastModule"="string('FALSE')"!][!//
    [!CALL "BuildChannelMap","ModuleType"="string('API')","LastModule"="string('TRUE')"!][!//
    [!ENDCODE!]
    }
};
[!ENDLOOP!][!//

/**************************************** GTM CMU **************************************************/
#if(GPT_ENABLE_GTMCMU == STD_ON)

[!IF "GptGeneral/EnableGTM_CMU"!][!//
[!LOOP "GtmCmuConfigSet/*[1]"!][!//
static CONST(GPT_GTM_CMU_ClkConfigType, GPT_CONST) GtmCmu_clocks_Cfg[[!"num:i(count(CMUClockControl/*))"!]] =
{
[!VAR "ClockCount"="(num:i(count(CMUClockControl/*)))"!][!//
    /* for each configured clock */
[!VAR "LoopVar"="1"!][!//
[!LOOP "CMUClockControl/*"!][!//
        {
            /* CMU Clock ID */
            .clockId = (GPT_GTM_CMU_Clock_Type) (GPT_GTM_[!"CMUClockId"!]),
            /* CMU Clock control register */
            .clockControlRegister = (uint32) (
                                            [!IF "num:i(num:i(ClockDivider) - 1) > 0"!][!//
                                              (([!"num:i(num:i(ClockDivider) - 1)"!]UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                            [!ELSE!]
                                              ((0UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                            [!ENDIF!][!//
[!/*                                        */!][!IF "contains(CMUClockId,'CMU_CLK6')"!][!//
                                               | (([!IF "CLK6_Sel"!]CMU_CLK_6_CTRL_SEL_ON[!ELSE!]CMU_CLK_6_CTRL_SEL_OFF[!ENDIF!])<<CMU_CLK_6_CTRL_SEL_OFFSET)
[!/*              */!][!ENDIF!][!//
[!/*              */!][!IF "contains(CMUClockId,'CMU_CLK7')"!][!//
                                               | (([!IF "CLK7_Sel"!]CMU_CLK_7_CTRL_SEL_ON[!ELSE!]CMU_CLK_7_CTRL_SEL_OFF[!ENDIF!])<<CMU_CLK_7_CTRL_SEL_OFFSET)
[!/*              */!][!ENDIF!][!//
                                             )
        }[!IF "$LoopVar < (num:i($ClockCount))"!],[!ELSE!][!ENDIF!]

[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDLOOP!][!//

};

CONST(Gpt_GtmCmuConfigType, GPT_CONST) Gpt_Gtm_Cmu_PBCfg;
CONST(Gpt_GtmCmuConfigType, GPT_CONST) Gpt_Gtm_Cmu_PBCfg =
{
      /* CMU configuration */
      {
          /* CMU Global Clock Control Numerator */
          .global_clock_numerator = (uint32) ([!"num:i(ClockManagementUnit/Global_Clock_Control_Numerator)"!]UL),
          /* CMU Global Clock Control Denominator */
          .global_clock_denominator = (uint32) ([!"num:i(ClockManagementUnit/Global_Clock_Control_Denominator)"!]UL),
          /* CMU clock enable register */
          .cmu_clk_control_register = (uint32)(
                    ( ([!IF "ClockManagementUnit/CMU_FXCLK"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_FXCLK_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_ECLK2"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_ECLK2_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_ECLK1"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_ECLK1_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_ECLK0"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_ECLK0_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_CLK7"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_CLK7_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_CLK6"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_CLK6_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_CLK5"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_CLK5_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_CLK4"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_CLK4_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_CLK3"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_CLK3_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_CLK2"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_CLK2_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_CLK1"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_CLK1_OFFSET)|
                    ( ([!IF "ClockManagementUnit/CMU_CLK0"!]CMU_CLK_EN_ENABLE_CLOCK[!ELSE!]CMU_CLK_EN_DISABLE_CLOCK[!ENDIF!])<<CMU_CLK_EN_EN_CLK0_OFFSET)
                  ),
          /* CMU FXCLK_Sel register */
          .cmu_fxclk_sel_register = (uint32)(CMU_FXCLK_CTRL_[!"ClockManagementUnit/FXCLK_Selection"!]<<CMU_FXCLK_CTRL_FXCLK_SEL_OFFSET),
          /* number of clocks configured */
          .count_of_configured_clocks = (uint8)([!"num:i(count(CMUClockControl/*))"!]U),
          &GtmCmu_clocks_Cfg
      },

      /* TBU configuration */
      {
          /* TBU channel enable register */
          .tbu_channel0_enable_reg = (uint8)[!IF "TimeBaseUnit_CH0/TBU_CH0_Enable"!]TBU_CHEN_ENABLE_CHANNEL[!ELSE!]TBU_CHEN_DISABLE_CHANNEL[!ENDIF!],
          .tbu_channel1_enable_reg = (uint8)[!IF "TimeBaseUnit_CH1/TBU_CH1_Enable"!]TBU_CHEN_ENABLE_CHANNEL[!ELSE!]TBU_CHEN_DISABLE_CHANNEL[!ENDIF!],
          .tbu_channel2_enable_reg = (uint8)[!IF "TimeBaseUnit_CH2/TBU_CH2_Enable"!]TBU_CHEN_ENABLE_CHANNEL[!ELSE!]TBU_CHEN_DISABLE_CHANNEL[!ENDIF!],
          /* TBU channel 0 control */
          [!IF "TimeBaseUnit_CH0/TBU_CH0_Enable"!]
          .tbu_ch0_control_clk_src = (uint8)TBU_CHX_CTRL_[!"node:ref(TimeBaseUnit_CH0/TBU_CH0_CMU_Channel_Select)/CMUClockId"!],
          .tbu_ch0_control_low_res = (uint8)[!IF "TimeBaseUnit_CH0/TBU_CH0_LowRes"!]TBU_CH0_CTRL_LOW_RES[!ELSE!]TBU_CH0_CTRL_HIGH_RES[!ENDIF!],
          [!ELSE!]
          .tbu_ch0_control_clk_src = (uint8)0U,
          .tbu_ch0_control_low_res = (uint8)0U,
          [!ENDIF!]
          /* TBU channel 1 control */
          [!IF "TimeBaseUnit_CH1/TBU_CH1_Enable"!]
          .tbu_ch1_control_clk_src = (uint8)TBU_CHX_CTRL_[!"node:ref(TimeBaseUnit_CH1/TBU_CH1_CMU_Channel_Select)/CMUClockId"!],
          .tbu_ch1_control_ch_mode = (uint8)[!IF "TimeBaseUnit_CH1/TBU_CH1_Channel_mode"!]TBU_CH1_CTRL_FORWARD_MODE[!ELSE!]TBU_CH1_CTRL_FREE_RUNNING_MODE[!ENDIF!],
          [!ELSE!]
          .tbu_ch1_control_clk_src = (uint8)0U,
          .tbu_ch1_control_ch_mode = (uint8)0U,
          [!ENDIF!]
          /* TBU channel 2 control */
          [!IF "TimeBaseUnit_CH2/TBU_CH2_Enable"!]
          .tbu_ch2_control_clk_src = (uint8)TBU_CHX_CTRL_[!"node:ref(TimeBaseUnit_CH2/TBU_CH2_CMU_Channel_Select)/CMUClockId"!],
          .tbu_ch2_control_ch_mode = (uint8)[!IF "TimeBaseUnit_CH2/TBU_CH2_Channel_mode"!]TBU_CH2_CTRL_FORWARD_MODE[!ELSE!]TBU_CH2_CTRL_FREE_RUNNING_MODE[!ENDIF!]
          [!ELSE!]
          .tbu_ch2_control_clk_src = (uint8)0U,
          .tbu_ch2_control_ch_mode = (uint8)0U,
          [!ENDIF!][!CR!]
      }
};

[!ENDLOOP!][!//
[!ENDIF!][!//
#endif

#ifdef __cplusplus
}
#endif

/** @} */
