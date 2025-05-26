/**
*   @file Icu_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - contains the configuration data of the ICU driver
*   @details Contains the configuration data of the ICU driver
*
*   @addtogroup ICU_MODULE
*   @{
*/
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
*   @file    Icu_Cfg.c 
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_Cfg.h"
#include "Icu.h"
#include "Icu_Gtm_Tim_LLDrivers.h"
#include "Icu_Gtm4_Tim_LLDrivers.h"
#include "Icu_eMIOS_HAL_Wrapper.h"
#include "Icu_eMIOS_Wrapper.h"
#include "eDMA_LLDriver.h"
#include "EcuM_Cbk.h"
#include "Icu_Wkpu_LLDrivers.h"


/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define ICU_CFG_VENDOR_ID_C                 176

#define ICU_CFG_AR_MAJOR_VER_C              4
#define ICU_CFG_AR_MINOR_VER_C              4
#define ICU_CFG_AR_PATCH_VER_C              0

#define ICU_CFG_SW_MAJOR_VER_C              1
#define ICU_CFG_SW_MINOR_VER_C              0
#define ICU_CFG_SW_PATCH_VER_C              1

/*============================================FILE VERSION CHECKS===================================*/

#if (ICU_CFG_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_CFG_AR_MAJOR_VER_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION_CFG"
#endif
#if (ICU_CFG_AR_MINOR_VER_C != ICU_AR_RELEASE_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION_CFG"
#endif
#if (ICU_CFG_AR_PATCH_VER_C != ICU_AR_RELEASE_REVISION_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_REVISION_VERSION_CFG"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_CFG_SW_MAJOR_VER_C != ICU_SW_MAJOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VERSION_CFG"
#endif
#if (ICU_CFG_SW_MINOR_VER_C != ICU_SW_MINOR_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VERSION_CFG"
#endif
#if (ICU_CFG_SW_PATCH_VER_C != ICU_SW_PATCH_VERSION_CFG)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VERSION_CFG"
#endif

/*====================================================================================================
                                   EXTERN CALLBACK FUNCTION
====================================================================================================*/
[!AUTOSPACING!]
[!//
[!MACRO "GetCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRef_cnt" = "num:i(count(IcuChannelEcucPartitionRef/*))"!][!//
    [!IF "$EcucPartitionRef_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!// 
    [!ELSE!][!//
        [!FOR "i" = "0" TO "num:i($EcucPartitionRef_cnt)-1"!][!//
            [!VAR "ModuEcucPartitionRef" = "string(IcuChannelEcucPartitionRef/*[$i+1])"!][!//
            [!IF "not(node:refexists(IcuChannelEcucPartitionRef/*[$i+1]))"!][!//
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


[!VAR "AlreadyParsedNotification"!][!ENDVAR!][!//
[!LOOP "IcuConfigSet/IcuChannel/*/IcuSignalEdgeDetection/IcuSignalNotification"!][!//
[!IF "(. != 'NULL_PTR') and (. != 'NULL')"!][!//
[!IF "contains($AlreadyParsedNotification, concat(.,'|')) = false()"!][!//
extern void [!"."!](void);
[!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,.,'|')"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!VAR "AlreadyParsedNotification"!][!ENDVAR!][!//
[!LOOP "IcuConfigSet/IcuChannel/*/IcuTimestampNotification/IcuTimestampNotification"!][!//
[!IF "(. != 'NULL_PTR') and (. != 'NULL')"!][!//
[!IF "contains($AlreadyParsedNotification, concat(.,'|')) = false()"!][!//
extern void [!"."!](void);
[!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,.,'|')"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/

/*===================================================================================================
*                                       LOCAL MACROS
====================================================================================================*/

/*===================================================================================================
*                                      LOCAL CONSTANTS
====================================================================================================*/

/*===================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
====================================================================================================*/
[!VAR "hasGTM" = "0"!]
[!VAR "hasEmios" = "0"!]
[!VAR "hasWAKEUP" = "0"!]
[!VAR "GtmCnt" = "0"!]
[!VAR "EmiosCnt" = "0"!]
[!VAR "WAKEUPCnt" = "0"!]
[!VAR "WAKEUPNMICnt" = "0"!]
[!LOOP "IcuConfigSet/IcuChannel/*"!][!//
    [!IF "IcuHwIP = 'GTM'"!][!//
        [!VAR "hasGTM" = "1"!]
        [!VAR "GtmCnt" = "$GtmCnt + 1"!]
    [!ELSEIF "IcuHwIP = 'EMIOS'"!][!//
        [!VAR "hasEmios" = "1"!]
        [!VAR "EmiosCnt" = "$EmiosCnt + 1"!]
    [!ELSEIF "IcuHwIP = 'WKPU'"!][!//
        [!VAR "hasWAKEUP" = "1"!]
        [!VAR "WAKEUPCnt" = "$WAKEUPCnt + 1"!]
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "num:i(count(IcuConfigSet/IcuWkpuNMIConfiguration/*)) != num:i(0)"!]
    [!VAR "hasWAKEUP" = "1"!]
[!ENDIF!]

[!AUTOSPACING!]
[!NOCODE!]
[!MACRO "ICUGtmChannelCheck"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
        [!IF "./IcuHwIP = 'GTM'"!]
            [!VAR "IcuModule" = "./IcuGtm/*/IcuGtmModule"!]
            [!VAR "ChannelName" = "@name"!]
            [!VAR "IcuChannel" = "./IcuGtm/*/IcuGtmChannel"!]
            [!VAR "ChannelIndex" = "@index"!]
            [!LOOP "../../IcuChannel/*"!]
                [!IF "$ChannelIndex != @index"!]
                    [!IF "($IcuModule = ./IcuGtm/*/IcuGtmModule) and ($IcuChannel = ./IcuGtm/*/IcuGtmChannel)"!]
                        [!ERROR!][[!"$ChannelName"!]] and [[!"@name"!]] Duplicate physical Gtm channel [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDMACRO!]

[!MACRO "ICUeMiosChannelCheck"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
        [!IF "./IcuHwIP = 'EMIOS'"!]
            [!VAR "IcuModule" = "./IcueMios/*/IcueMiosModule"!]
            [!VAR "ChannelName" = "@name"!]
            [!VAR "IcuChannel" = "./IcueMios/*/IcueMiosChannel"!]
            [!VAR "ChannelIndex" = "@index"!]
            [!LOOP "../../IcuChannel/*"!]
                [!IF "$ChannelIndex != @index"!]
                    [!IF "($IcuModule = ./IcueMios/*/IcueMiosModule) and ($IcuChannel = ./IcueMios/*/IcueMiosChannel)"!]
                        [!ERROR!][[!"$ChannelName"!]] and [[!"@name"!]] Duplicate physical eMios channel [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDMACRO!]

[!MACRO "ICUWkpuChannelCheck"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
        [!IF "./IcuHwIP = 'WKPU'"!]
            [!VAR "IcuModule" = "./IcuWkpu/*"!]
            [!VAR "ChannelName" = "@name"!]
            [!VAR "IcuChannel" = "./IcuWkpu/*/IcuWkpuChannel"!]
            [!VAR "ChannelIndex" = "@index"!]
            [!LOOP "../../IcuChannel/*"!]
                [!IF "$ChannelIndex != @index"!]
                    [!IF "($IcuModule = ./IcuWkpu/*) and ($IcuChannel = ./IcuWkpu/*/IcuWkpuChannel)"!]
                        [!ERROR!][[!"$ChannelName"!]] and [[!"@name"!]] Duplicate physical WKPU channel [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDMACRO!]
[!ENDNOCODE!]

[!IF "$hasGTM = 1"!]
    [!CALL "ICUGtmChannelCheck"!]
/******************************************************************************************/
/************************************* GTM Config *****************************************/
/******************************************************************************************/
static CONST(Icu_ChannelConfig_Type, ICU_CONST) GtmChannelConfig[[!"num:i($GtmCnt)"!]] =
{
[!LOOP "IcuConfigSet/IcuChannel/*"!][!//
[!IF "IcuHwIP = 'GTM'"!]
    [!NOCODE!][!//
    [!VAR "IcuChSignalMeasurement" = "num:i(count(IcuSignalMeasurement/*))"!]
    [!VAR "IcuChTimestampMeasurement" = "num:i(count(IcuTimestampMeasurement/*))"!]
    [!VAR "IcuChGtm" = "num:i(count(IcuGtm/*))"!]

    [!ENDNOCODE!][!//
    {
        .IcuConfig_Instance = [!"IcuChannelId"!],
        .IcuConfig_ModuleId = (Icu_Module_Type)[!"IcuGtm/*[1]/IcuGtmModule"!],
        .IcuConfig_ChannelId = (Icu_ChannelType)[!"IcuGtm/*[1]/IcuGtmChannel"!],
        .IcuConfig_Tim_Selection = [!"IcuGtm/*[1]/TIM_Channel_x_Input_Selection"!],
        .IcuConfig_ChannelMode = [!"IcuMeasurementMode"!],
        .IcuChannel_DefaultStartEdge = [!"IcuDefaultStartEdge"!],
            [!IF "(IcuSignalEdgeDetection/IcuSignalNotification != 'NULL_PTR')"!]
        .IcuChannel_Notification = &[!"IcuSignalEdgeDetection/IcuSignalNotification "!],
            [!ELSE!]
        .IcuChannel_Notification = NULL_PTR,
            [!ENDIF!]
        [!IF "(IcuTimestampNotification/IcuTimestampNotification != 'NULL_PTR')"!]
        .IcuChannel_TimestampNotification = &[!"IcuTimestampNotification/IcuTimestampNotification"!],
        [!ELSE!]
        .IcuChannel_TimestampNotification = NULL_PTR,
        [!ENDIF!]
    [!IF "num:i($IcuChSignalMeasurement) = num:i(0)"!]
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
    [!ELSE!]
        .IcuChannel_SignalMeasurementProperty = [!"IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty"!],
    [!ENDIF!]
    [!IF "num:i($IcuChTimestampMeasurement) = num:i(0)"!]
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
    [!ELSE!]
        .IcuChannel_TimestampBufferProperty = [!"IcuTimestampMeasurement/*[1]/IcuTimestampMeasurementProperty"!],
    [!ENDIF!]
        .IcuChannel_WakeupCapability = (boolean)[!IF "node:exists(IcuWakeupCapability)"!][!IF "IcuWakeupCapability"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!], /* Wakeup capability */
    [!CODE!][!//
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    [!ENDCODE!]
        [!IF "num:i(count(IcuWakeup/*)) = num:i(0)"!]
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
        [!ELSE!]
        [!LOOP "IcuWakeup/*"!]
        [!IF "(node:exists(IcuWakeupCapability) = 'true') and (node:value(IcuChannelWakeupInfo) != '')"!]
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)((uint32)1U<<(uint32)[!"as:ref(IcuChannelWakeupInfo)/EcuMWakeupSourceId"!]U), /* Wakeup Source transmitted to the Ecu State Manager (used only when Wakeup Support is true) */
        [!ELSE!]
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
        [!ENDIF!]
        [!ENDLOOP!]
        [!ENDIF!]
    [!CODE!][!//
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
    [!ENDCODE!]
        .IcuChannel_bDmaSupport = (boolean)[!IF "node:exists(IcuDMAChannelEnable)"!][!IF "IcuDMAChannelEnable"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!],
        .IcuChannel_DmaChannel = (uint8)[!IF "IcuDMAChannelEnable = 'false'"!]0[!ELSE!][!"node:refs(IcueDmaChannel)/eDmaChannelId"!][!ENDIF!],
    },
[!ENDIF!]
[!ENDLOOP!]
};

static CONST(ICU_Gtm_Config, ICU_CONST) Icu_GtmConfig =
{
    .uChannelCount = [!"num:i($GtmCnt)"!]U,
    .pGtmChannelConfig = GtmChannelConfig
};

[!ENDIF!]

[!IF "$hasEmios = 1"!]
    [!CALL "ICUeMiosChannelCheck"!]
/******************************************************************************************/
/************************************ eMIOS Config ****************************************/
/******************************************************************************************/
static CONST(ICU_eMIOS_HwConfig, ICU_CONST) IcuHwConfig_eMIOS[[!"num:i($EmiosCnt)"!]] =
{
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
    [!IF "IcuHwIP = 'EMIOS'"!]
    {
        .mode = [!"IcueMios/*[1]/eMIOS_IC_ModeType"!],
        .timebase = [!"IcueMios/*[1]/IcueMiosBusSelect"!],
        .filter = [!"IcueMios/*[1]/eMIOS_UC_InputFilterType"!],   /* Input signal filter */
        .desirednum = [!"IcueMios/*[1]/desirednum"!], /* Desired edge/pulse number. used for PEA, QDEC mode */
        .startime = [!"IcueMios/*[1]/startime"!], /* Start window time. used for PEC, WPTA */
        .endtime = [!"IcueMios/*[1]/endime"!],    /* End window time. used for PEC, WPTA */
        .masterPrescaler = [!"IcueMios/*[1]/masterPrescaler"!],   /* EMios module prescaler */
        .channelPrescaler = [!"IcueMios/*[1]/channelPrescaler"!]  /* EMios channel prescaler */
    },  
    [!ENDIF!]
    [!ENDLOOP!]
};

static CONST(ICU_eMIOS_ChannelConfig, ICU_CONST) eMiosChannelConfig[[!"num:i($EmiosCnt)"!]] =
{
    [!VAR "hwINDEX" = "num:i(0)"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
    [!VAR "IcuChSignalMeasurement" = "num:i(count(IcuSignalMeasurement/*))"!]
    [!VAR "IcuChTimestampMeasurement" = "num:i(count(IcuTimestampMeasurement/*))"!]
    [!IF "IcuHwIP = 'EMIOS'"!]
    {
        .IcuConfig_Instance = [!"IcuChannelId"!],
        .IcuConfig_ModuleId = (Icu_Module_Type)[!"IcueMios/*[1]/IcueMiosModule"!],
        .IcuConfig_ChannelId = (Icu_ChannelType)[!"IcueMios/*[1]/IcueMiosChannel"!],
        .IcuConfig_ChannelMode = [!"IcuMeasurementMode"!],
        .IcuChannel_DefaultStartEdge = [!"IcuDefaultStartEdge"!],
            [!IF "(IcuSignalEdgeDetection/IcuSignalNotification != 'NULL_PTR')"!]
        .IcuChannel_Notification = &[!"IcuSignalEdgeDetection/IcuSignalNotification "!],
            [!ELSE!]
        .IcuChannel_Notification = NULL_PTR,
            [!ENDIF!]
        [!IF "(IcuTimestampNotification/IcuTimestampNotification != 'NULL_PTR')"!]
        .IcuChannel_TimestampNotification = &[!"IcuTimestampNotification/IcuTimestampNotification"!],
        [!ELSE!]
        .IcuChannel_TimestampNotification = NULL_PTR,
        [!ENDIF!]
        [!IF "num:i($IcuChSignalMeasurement) = num:i(0)"!]
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        [!ELSE!]
        .IcuChannel_SignalMeasurementProperty = [!"IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty"!],
        [!ENDIF!]
        [!IF "num:i($IcuChTimestampMeasurement) = num:i(0)"!]
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        [!ELSE!]
        .IcuChannel_TimestampBufferProperty = [!"IcuTimestampMeasurement/*[1]/IcuTimestampMeasurementProperty"!],
        [!ENDIF!]
        .IcuChannel_WakeupCapability = (boolean)[!IF "node:exists(IcuWakeupCapability)"!][!IF "IcuWakeupCapability"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!], /* Wakeup capability */
[!CODE!][!//
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
[!ENDCODE!]
        [!IF "num:i(count(IcuWakeup/*)) = num:i(0)"!]
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
        [!ELSE!]
        [!LOOP "IcuWakeup/*"!]
        [!IF "(node:exists(IcuWakeupCapability)) and (node:value(IcuChannelWakeupInfo) != '')"!]
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)((uint32)1U<<(uint32)[!"as:ref(IcuChannelWakeupInfo)/EcuMWakeupSourceId"!]U), /* Wakeup Source transmitted to the Ecu State Manager (used only when Wakeup Support is true) */
        [!ELSE!]
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
        [!ENDIF!]
        [!ENDLOOP!]
        [!ENDIF!]
[!CODE!][!//
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        /* eMios config flag */
        .IcuChannel_bDmaSupport = (boolean)[!IF "node:exists(IcuDMAChannelEnable)"!][!IF "IcuDMAChannelEnable"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!],
        .IcuChannel_DmaChannel = (uint8)[!IF "IcuDMAChannelEnable = 'false'"!]0[!ELSE!][!"node:refs(IcueDmaChannel)/eDmaChannelId"!][!ENDIF!],
        .IcuChannel_bSignalMeasureWithoutInterrupt = (boolean)[!IF "node:exists(IcueMios/*[1]/SignalMeasureWithoutInterrupt)"!][!IF "IcueMios/*[1]/SignalMeasureWithoutInterrupt"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!]FALSE[!ENDIF!],
        .pIcuConfig_HwConfig = &IcuHwConfig_eMIOS[[!"num:i($hwINDEX)"!]]
[!ENDCODE!]
    },
    [!VAR "hwTEMP" = "num:i($hwINDEX) + 1"!]
    [!VAR "hwINDEX" = "$hwTEMP"!]
    [!ENDIF!]
    [!ENDLOOP!]
};

CONST(ICU_eMIOS_Config, ICU_CONST) Icu_eMoisConfig =
{
    .uChannelCount = [!"num:i($EmiosCnt)"!]U,
    .peMiosChannelConfig = eMiosChannelConfig
};
[!ENDIF!]
[!//
[!NOCODE!]
    [!VAR "Count" = "0"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
    [!VAR "Count" = "$Count+1"!]
    [!ENDLOOP!]
[!ENDNOCODE!]


[!IF "$WAKEUPCnt != 0"!]
    [!CALL "ICUWkpuChannelCheck"!]
/******************************************************************************************/
/************************************ WKPU Config *****************************************/
/******************************************************************************************/

static CONST(ICU_Wkpu_ChannelConfigType, ICU_CONST) WkpuChannelConfig[[!"num:i($WAKEUPCnt)"!]] =
{
    [!VAR "hwINDEX" = "num:i(0)"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
    [!IF "IcuHwIP = 'WKPU'"!]
    {
        .IcuConfig_Instance = [!"IcuChannelId"!],
        .IcuConfig_ModuleId = (Icu_Module_Type)0U,
        .IcuConfig_ChannelId = (Icu_ChannelType)[!"IcuWkpu/*[1]/IcuWkpuChannel"!],
        .IcuChannel_DefaultStartEdge = [!"IcuDefaultStartEdge"!],
            [!IF "(IcuSignalEdgeDetection/IcuSignalNotification != 'NULL_PTR')"!]
        .IcuChannel_Notification = &[!"IcuSignalEdgeDetection/IcuSignalNotification "!],
            [!ELSE!]
        .IcuChannel_Notification = NULL_PTR,
            [!ENDIF!]
        .IcuChannel_WakeupCapability = (boolean)[!IF "node:exists(IcuWakeupCapability)"!][!IF "IcuWakeupCapability"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!], /* Wakeup capability */
[!CODE!][!//
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
[!ENDCODE!]
        [!IF "num:i(count(IcuWakeup/*)) = num:i(0)"!]
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
        [!ELSE!]
        [!LOOP "IcuWakeup/*"!]
        [!IF "(node:exists(IcuWakeupCapability)) and (node:value(IcuChannelWakeupInfo) != '')"!]
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)((uint32)1U<<(uint32)[!"as:ref(IcuChannelWakeupInfo)/EcuMWakeupSourceId"!]U), /* Wakeup Source transmitted to the Ecu State Manager (used only when Wakeup Support is true) */
        [!ELSE!]
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
        [!ENDIF!]
        [!ENDLOOP!]
        [!ENDIF!]
[!CODE!][!//
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
[!ENDCODE!]
        .IcuChannel_Filter = (boolean)[!IF "node:exists(IcuWkpu/*[1]/Icu_EXT_ISR_WIFERDigitalFilter)"!][!IF "IcuWkpu/*[1]/Icu_EXT_ISR_WIFERDigitalFilter"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!]FALSE[!ENDIF!], /* ICU Wakeup Filter Enable */
    },
    [!VAR "hwTEMP" = "num:i($hwINDEX) + 1"!]
    [!VAR "hwINDEX" = "$hwTEMP"!]
    [!ENDIF!]
    [!ENDLOOP!]
};
[!ENDIF!]
[!IF "num:i(count(IcuConfigSet/IcuWkpuNMIConfiguration/*)) != num:i(0)"!]
static CONST(Wkpu_NmiCfgType, ICU_CONST) WkpuNMICfg[[!"num:i(count(IcuConfigSet/IcuWkpuNMIConfiguration/*))"!]] =
{

    [!VAR "hwINDEX" = "num:i(0)"!]
    [!LOOP "IcuConfigSet/IcuWkpuNMIConfiguration/*"!]
    {
        .core = [!"NMICoreSource"!],
        .destination = [!"DestinationSourceSelect"!],
        .wkpReqEn = (boolean)[!IF "node:exists(WakeupRequestEnable)"!][!IF "WakeupRequestEnable"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!],
        .filterEn = (boolean)[!IF "node:exists(FilterEnable)"!][!IF "FilterEnable"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!],
        .edgeEvent = [!"NMIEdgeEvents"!],
        .lockEn = (boolean)[!IF "node:exists(LockRegister)"!][!IF "LockRegister"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!],    
    },
    [!VAR "hwTEMP" = "num:i($hwINDEX) + 1"!]
    [!VAR "hwINDEX" = "$hwTEMP"!]
    [!ENDLOOP!]
};


CONST(ICU_Wkpu_NMIConfigType, ICU_CONST) WkpuNMIConfig =
{
    .NMICount = [!"num:i(count(IcuConfigSet/IcuWkpuNMIConfiguration/*))"!]U,
    .WkpuNMIConfig = WkpuNMICfg
};

[!ENDIF!]

[!IF "$hasWAKEUP = 1"!]
CONST(ICU_Wkpu_ConfigType, ICU_CONST) Icu_WkpuConfig =
{
	[!IF "num:i($WAKEUPCnt) != num:i(0)"!]
    .uChannelCount = [!"num:i($WAKEUPCnt)"!]U,
    [!IF "num:i($WAKEUPCnt) = num:i(0)"!]
    .pWkpuChannelConfig = NULL_PTR,
    [!ELSE!]
    .pWkpuChannelConfig = WkpuChannelConfig,
    [!ENDIF!]
	[!ENDIF!]
    [!IF "num:i(count(IcuConfigSet/IcuWkpuNMIConfiguration/*)) = num:i(0)"!]
    .pWkpuNMIConfig = NULL_PTR
    [!ELSE!]
    .pWkpuNMIConfig = &WkpuNMIConfig
    [!ENDIF!]
};
[!ENDIF!]



[!//
[!NOCODE!]
    [!VAR "Count" = "0"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
    [!VAR "Count" = "$Count+1"!]
    [!ENDLOOP!]
[!ENDNOCODE!]

/******************************************************************************************/
/************************************ Hardware Map ****************************************/
/******************************************************************************************/
static CONST(ICU_HwModule_Type, ICU_CONST) Icu_HwChMap[[!"num:i($Count)"!]] =
{
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
    [!IF "IcuHwIP = 'EMIOS'"!]
    ICU_[!"IcueMios/*[1]/IcueMiosModule"!],
    [!ELSEIF "IcuHwIP = 'GTM'"!]
    ICU_[!"IcuGtm/*[1]/IcuGtmModule"!],
    [!ELSEIF "IcuHwIP = 'WKPU'"!]
    ICU_[!"IcuHwIP"!],
    [!ENDIF!]
    [!ENDLOOP!]
};

[!//
[!NOCODE!]
    [!VAR "Count" = "0"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
    [!VAR "Count" = "$Count+1"!]
    [!ENDLOOP!]
[!ENDNOCODE!]

static CONST(Icu_CoreMapItemType, ICU_CONST) Icu_CoreMap[[!"num:i($Count)"!]] =
{
[!LOOP "(IcuConfigSet/IcuChannel/*)"!]
    [!VAR "nIcuChannelId" = "num:i(./IcuChannelId)"!]
    {
        .nIcuChannelId=[!"$nIcuChannelId"!],
        .nCoreId=[!CALL "GetCoreID"!]
    },
[!ENDLOOP!]
};

/******************************************************************************************/
/************************************* ICU Config *****************************************/
/******************************************************************************************/
[!VAR "IcuChannelNum" = "0"!][!//
[!LOOP "IcuConfigSet/IcuChannel/*"!][!//
[!VAR "IcuChannelNum" = "$IcuChannelNum + 1"!][!//
[!ENDLOOP!][!//

CONST(Icu_ConfigType, ICU_CONST) Icu_Cfg =
{
    .Icu_NumChannels    = [!"num:i($IcuChannelNum)"!]U,
[!IF "$hasGTM = 1"!][!//
    .Icu_GtmConfig      = &Icu_GtmConfig,
[!ELSE!][!//
    .Icu_GtmConfig      = NULL_PTR,
[!ENDIF!][!//
[!IF "$hasEmios = 1"!][!//
    .Icu_eMoisConfig    = &Icu_eMoisConfig,
[!ELSE!][!//
    .Icu_eMoisConfig    = NULL_PTR,
[!ENDIF!][!//
[!IF "$hasWAKEUP = 1"!][!//
    .Icu_WkpuConfig     = &Icu_WkpuConfig,
[!ELSE!][!//
    .Icu_WkpuConfig     = NULL_PTR,
[!ENDIF!][!//
    .Icu_HwChMap        = &Icu_HwChMap,
    .Icu_CoreMap        = Icu_CoreMap
};


