/**
*   @file Icu_Cfg.h
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
*   @file    Icu_Cfg.h 
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

#ifndef ICU_CFG_H
#define ICU_CFG_H

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif 
#include "Mcal.h"

[!AUTOSPACING!]

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_VENDOR_ID_CFG                       176

#define ICU_AR_RELEASE_MAJOR_VERSION_CFG        4
#define ICU_AR_RELEASE_MINOR_VERSION_CFG        4
#define ICU_AR_RELEASE_REVISION_VERSION_CFG     0

#define ICU_SW_MAJOR_VERSION_CFG                1
#define ICU_SW_MINOR_VERSION_CFG                0
#define ICU_SW_PATCH_VERSION_CFG                1

/*============================================FILE VERSION CHECKS===================================*/

#if (ICU_VENDOR_ID_CFG != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : MCAL_VENDOR_ID"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MAJOR_VER"
#endif
#if (ICU_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MINOR_VER"
#endif
#if (ICU_AR_RELEASE_REVISION_VERSION_CFG != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_PATCH_VER"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_SW_MAJOR_VERSION_CFG != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MAJOR_VER"
#endif
#if (ICU_SW_MINOR_VERSION_CFG != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MINOR_VER"
#endif
#if (ICU_SW_PATCH_VERSION_CFG != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_PATCH_VER"
#endif



#define ICU_VARIANT_PRECOMPILE                  (0)
#define ICU_VARIANT_POSTBUILD                   (1)
#define ICU_VARIANT_LINKTIME                    (2)

/*===================================================================================================
*                                       LOCAL MACROS
====================================================================================================*/
[!IF "(IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime' ) and (variant:size()<=1)"!][!//
#define ICU_CONFIG_VARIANT                      (ICU_VARIANT_PRECOMPILE)
[!ELSE!][!//
#define ICU_CONFIG_VARIANT                      (ICU_VARIANT_POSTBUILD)
[!ENDIF!][!//
#define ICU_DEV_ERROR_DETECT                    ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_REPORT_WAKEUP_SOURCE                ([!IF "IcuGeneral/IcuReportWakeupSource"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ICU_DEINIT_API                          ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_SETMODE_API                         ([!IF "IcuOptionalApis/IcuSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_DISABLEWAKEUP_API                   ([!IF "IcuOptionalApis/IcuDisableWakeupApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_ENABLEWAKEUP_API                    ([!IF "IcuOptionalApis/IcuEnableWakeupApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_CHECKWAKEUP_API                     ([!IF "IcuOptionalApis/IcuWakeupFunctionalityApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_GETINPUTSTATE_API                   ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_STARTTIMESTAMP_API                  ([!IF "IcuOptionalApis/IcuTimestampApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_STOPTIMESTAMP_API                   ([!IF "IcuOptionalApis/IcuTimestampApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_GETTIMESTAMPINDEX_API               ([!IF "IcuOptionalApis/IcuTimestampApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_RESETEDGECOUNT_API                  ([!IF "IcuOptionalApis/IcuEdgeCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_ENABLEEDGECOUNT_API                 ([!IF "IcuOptionalApis/IcuEdgeCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_ENABLEEDGEDETECTION_API             ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_DISABLEEDGEDETECTION_API            ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_DISABLEEDGECOUNT_API                ([!IF "IcuOptionalApis/IcuEdgeCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_GETEDGENUMBERS_API                  ([!IF "IcuOptionalApis/IcuEdgeCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_STARTSIGNALMEASUREMENT_API          ([!IF "IcuOptionalApis/IcuSignalMeasurementApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_STOPSIGNALMEASUREMENT_API           ([!IF "IcuOptionalApis/IcuSignalMeasurementApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_GETTIMEELAPSED_API                  ([!IF "IcuOptionalApis/IcuGetTimeElapsedApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_GETDUTYCYCLEVALUES_API              ([!IF "IcuOptionalApis/IcuGetDutyCycleValuesApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_GETVERSIONINFO_API                  ([!IF "IcuOptionalApis/IcuGetVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_WAKEUP_FUNCTIONALITY_API            ([!IF "IcuOptionalApis/IcuWakeupFunctionalityApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_CAPTURERGISTER_API                  ([!IF "IcuGeneral/IcuGetCaptureRegisterValueApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


#define WKP_PS0                                 0U
#define WKP_PA4                                 1U
#define NMI_WAKEUP_PIN                          ([!IF "IcuConfigSet/IcuWakeUpPinSelection = 'PA4'"!]WKP_PA4[!ELSE!]WKP_PS0[!ENDIF!])

#define ICU_OVERFLOW_NOTIFICATION_API            ([!IF "IcuOptionalApis/IcuOverflowNotificationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!VAR "TimestampDmaEnable" = "0"!][!/*
*/!][!VAR "MeasurementDmaEnable" = "0"!][!/*
*/!][!SELECT "IcuConfigSet"!][!/*
    */!][!LOOP "./IcuChannel/*"!][!/*
    */!][!IF "IcuDMAChannelEnable = 'true'"!][!/*
        */!][!IF "IcuMeasurementMode = 'ICU_MODE_SIGNAL_MEASUREMENT'"!][!/*
            */!][!VAR "MeasurementDmaEnable" = "$MeasurementDmaEnable + 1"!][!/*
        */!][!ELSEIF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!/*
            */!][!VAR "TimestampDmaEnable" = "$TimestampDmaEnable + 1"!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
 */!][!ENDSELECT!]
#define ICU_SIGNALMEASUREMENT_USES_DMA          ([!IF "$MeasurementDmaEnable != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_TIMESTAMP_USES_DMA                  ([!IF "$TimestampDmaEnable != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_MULTI_CORE_SUPPORT                  ([!IF "IcuGeneral/IcuMulticoreSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])   
#define ICU_NONE_ECUM_WAKEUP_SOURCE_REF         (uint32)0U

[!INDENT "0"!]
[!NOCODE!]
    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
        [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!VAR "Matchcounter" = "0"!]
        [!VAR "Name" = "node:name(.)"!]
        [!LOOP "../../../*/IcuChannel/*"!]
            [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
            [!IF "($Name = node:name(.))"!]
                    [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$Matchcounter = 1"!]
                [!CODE!]
#define [!"node:name(.)"!]                            (IcuConf_IcuChannel_IcuChannel_[!"IcuChannelId"!])[!CR!]
#define IcuConf_IcuChannel_IcuChannel_[!"IcuChannelId"!]         ((Icu_ChannelType)[!"IcuChannelId"!]U) [!CR!]
                [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDINDENT!]

[!VAR "IcuChannelNum" = "0"!][!//
[!LOOP "IcuConfigSet/IcuChannel/*"!][!//
[!VAR "IcuChannelNum" = "$IcuChannelNum + 1"!][!//
[!ENDLOOP!][!//
#define ICU_MAX_CHANNEL                         ([!"num:i($IcuChannelNum)"!]U)
#define ICU_MAX_MODULE                          (3U)
#define ICU_INVALID_DMA_CHANNEL                 ((Icu_ChannelType)0xFF)

[!VAR "hasGTM" = "0"!]
[!VAR "hasEmios" = "0"!]
[!VAR "GtmCnt" = "0"!]
[!VAR "EmiosCnt" = "0"!]
[!LOOP "IcuConfigSet/IcuChannel/*"!][!//
    [!IF "IcuHwIP = 'GTM'"!][!//
        [!VAR "hasGTM" = "1"!]
        [!VAR "GtmCnt" = "$GtmCnt + 1"!]
    [!ELSEIF "IcuHwIP = 'EMIOS'"!][!//
        [!VAR "hasEmios" = "1"!]
        [!VAR "EmiosCnt" = "$EmiosCnt + 1"!]
    [!ENDIF!][!//
[!ENDLOOP!][!//

/* ICU Module Config */
#define ICU_GTM_USED                            ([!IF "$hasGTM = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define ICU_EMIOS_USED                          ([!IF "$hasEmios = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!IF "$hasGTM = 1"!]
/* Config GTM channel num */
#define ICU_GTM_CHANNEL_NUM                     ([!"num:i($GtmCnt)"!]U)
[!ENDIF!]
[!IF "$hasEmios = 1"!]
/* Config GTM channel num */
#define ICU_EMIOS_CHANNEL_NUM                   ([!"num:i($EmiosCnt)"!]U)
[!ENDIF!]

/*===================================================================================================
*                                      LOCAL CONSTANTS
====================================================================================================*/

/*===================================================================================================
*                          GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
====================================================================================================*/
[!IF "IMPLEMENTATION_CONFIG_VARIANT ='VariantPostBuild'"!][!//
#define ICU_CONFIG_DECLARATION extern CONST(Icu_ConfigType, ICU_CONST) Icu_Cfg;
[!ELSE!]
#define ICU_CONFIG_DECLARATION extern CONST(Icu_ConfigType, ICU_CONST) Icu_Cfg;
[!ENDIF!]

#ifdef __cplusplus
}
#endif
#endif /* ICU_CFG_H */

