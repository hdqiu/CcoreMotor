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
#define ICU_CONFIG_VARIANT                      (ICU_VARIANT_POSTBUILD)
#define ICU_DEV_ERROR_DETECT                    (STD_ON)
#define ICU_REPORT_WAKEUP_SOURCE                (STD_ON)

#define ICU_DEINIT_API                          (STD_ON)
#define ICU_SETMODE_API                         (STD_ON)
#define ICU_DISABLEWAKEUP_API                   (STD_ON)
#define ICU_ENABLEWAKEUP_API                    (STD_ON)
#define ICU_CHECKWAKEUP_API                     (STD_ON)
#define ICU_GETINPUTSTATE_API                   (STD_ON)
#define ICU_STARTTIMESTAMP_API                  (STD_ON)
#define ICU_STOPTIMESTAMP_API                   (STD_ON)
#define ICU_GETTIMESTAMPINDEX_API               (STD_ON)
#define ICU_RESETEDGECOUNT_API                  (STD_ON)
#define ICU_ENABLEEDGECOUNT_API                 (STD_ON)
#define ICU_ENABLEEDGEDETECTION_API             (STD_ON)
#define ICU_DISABLEEDGEDETECTION_API            (STD_ON)
#define ICU_DISABLEEDGECOUNT_API                (STD_ON)
#define ICU_GETEDGENUMBERS_API                  (STD_ON)
#define ICU_STARTSIGNALMEASUREMENT_API          (STD_ON)
#define ICU_STOPSIGNALMEASUREMENT_API           (STD_ON)
#define ICU_GETTIMEELAPSED_API                  (STD_ON)
#define ICU_GETDUTYCYCLEVALUES_API              (STD_ON)
#define ICU_GETVERSIONINFO_API                  (STD_ON)
#define ICU_WAKEUP_FUNCTIONALITY_API            (STD_ON)
#define ICU_CAPTURERGISTER_API                  (STD_OFF)


#define WKP_PS0                                 0U
#define WKP_PA4                                 1U
#define NMI_WAKEUP_PIN                          (WKP_PS0)

#define ICU_OVERFLOW_NOTIFICATION_API           (STD_ON)

#define ICU_SIGNALMEASUREMENT_USES_DMA          (STD_OFF)
#define ICU_TIMESTAMP_USES_DMA                  (STD_ON)
#define ICU_MULTI_CORE_SUPPORT                  (STD_ON)   
#define ICU_NONE_ECUM_WAKEUP_SOURCE_REF         (uint32)0U

#define IcuChannel_0                            (IcuConf_IcuChannel_IcuChannel_0)
#define IcuConf_IcuChannel_IcuChannel_0         ((Icu_ChannelType)0U) 
#define IcuChannel_1                            (IcuConf_IcuChannel_IcuChannel_1)
#define IcuConf_IcuChannel_IcuChannel_1         ((Icu_ChannelType)1U) 
#define IcuChannel_2                            (IcuConf_IcuChannel_IcuChannel_2)
#define IcuConf_IcuChannel_IcuChannel_2         ((Icu_ChannelType)2U) 
#define IcuChannel_3                            (IcuConf_IcuChannel_IcuChannel_3)
#define IcuConf_IcuChannel_IcuChannel_3         ((Icu_ChannelType)3U) 
#define IcuChannel_4                            (IcuConf_IcuChannel_IcuChannel_4)
#define IcuConf_IcuChannel_IcuChannel_4         ((Icu_ChannelType)4U) 
#define IcuChannel_5                            (IcuConf_IcuChannel_IcuChannel_5)
#define IcuConf_IcuChannel_IcuChannel_5         ((Icu_ChannelType)5U) 
#define IcuChannel_6                            (IcuConf_IcuChannel_IcuChannel_6)
#define IcuConf_IcuChannel_IcuChannel_6         ((Icu_ChannelType)6U) 
#define IcuChannel_7                            (IcuConf_IcuChannel_IcuChannel_7)
#define IcuConf_IcuChannel_IcuChannel_7         ((Icu_ChannelType)7U) 
#define IcuChannel_8                            (IcuConf_IcuChannel_IcuChannel_8)
#define IcuConf_IcuChannel_IcuChannel_8         ((Icu_ChannelType)8U) 
#define IcuChannel_9                            (IcuConf_IcuChannel_IcuChannel_9)
#define IcuConf_IcuChannel_IcuChannel_9         ((Icu_ChannelType)9U) 
#define IcuChannel_10                            (IcuConf_IcuChannel_IcuChannel_10)
#define IcuConf_IcuChannel_IcuChannel_10         ((Icu_ChannelType)10U) 
#define IcuChannel_11                            (IcuConf_IcuChannel_IcuChannel_11)
#define IcuConf_IcuChannel_IcuChannel_11         ((Icu_ChannelType)11U) 
#define IcuChannel_12                            (IcuConf_IcuChannel_IcuChannel_12)
#define IcuConf_IcuChannel_IcuChannel_12         ((Icu_ChannelType)12U) 
#define IcuChannel_13                            (IcuConf_IcuChannel_IcuChannel_13)
#define IcuConf_IcuChannel_IcuChannel_13         ((Icu_ChannelType)13U) 
#define IcuChannel_14                            (IcuConf_IcuChannel_IcuChannel_14)
#define IcuConf_IcuChannel_IcuChannel_14         ((Icu_ChannelType)14U) 
#define IcuChannel_15                            (IcuConf_IcuChannel_IcuChannel_15)
#define IcuConf_IcuChannel_IcuChannel_15         ((Icu_ChannelType)15U) 
#define IcuChannel_16                            (IcuConf_IcuChannel_IcuChannel_16)
#define IcuConf_IcuChannel_IcuChannel_16         ((Icu_ChannelType)16U) 
#define IcuChannel_17                            (IcuConf_IcuChannel_IcuChannel_17)
#define IcuConf_IcuChannel_IcuChannel_17         ((Icu_ChannelType)17U) 
#define IcuChannel_18                            (IcuConf_IcuChannel_IcuChannel_18)
#define IcuConf_IcuChannel_IcuChannel_18         ((Icu_ChannelType)18U) 
#define IcuChannel_19                            (IcuConf_IcuChannel_IcuChannel_19)
#define IcuConf_IcuChannel_IcuChannel_19         ((Icu_ChannelType)19U) 
#define IcuChannel_20                            (IcuConf_IcuChannel_IcuChannel_20)
#define IcuConf_IcuChannel_IcuChannel_20         ((Icu_ChannelType)20U) 
#define IcuChannel_21                            (IcuConf_IcuChannel_IcuChannel_21)
#define IcuConf_IcuChannel_IcuChannel_21         ((Icu_ChannelType)21U) 
#define IcuChannel_22                            (IcuConf_IcuChannel_IcuChannel_22)
#define IcuConf_IcuChannel_IcuChannel_22         ((Icu_ChannelType)22U) 
#define IcuChannel_23                            (IcuConf_IcuChannel_IcuChannel_23)
#define IcuConf_IcuChannel_IcuChannel_23         ((Icu_ChannelType)23U) 
#define IcuChannel_24                            (IcuConf_IcuChannel_IcuChannel_24)
#define IcuConf_IcuChannel_IcuChannel_24         ((Icu_ChannelType)24U) 
#define IcuChannel_25                            (IcuConf_IcuChannel_IcuChannel_25)
#define IcuConf_IcuChannel_IcuChannel_25         ((Icu_ChannelType)25U) 
#define IcuChannel_26                            (IcuConf_IcuChannel_IcuChannel_26)
#define IcuConf_IcuChannel_IcuChannel_26         ((Icu_ChannelType)26U) 
#define IcuChannel_27                            (IcuConf_IcuChannel_IcuChannel_27)
#define IcuConf_IcuChannel_IcuChannel_27         ((Icu_ChannelType)27U) 
#define IcuChannel_28                            (IcuConf_IcuChannel_IcuChannel_28)
#define IcuConf_IcuChannel_IcuChannel_28         ((Icu_ChannelType)28U) 
#define IcuChannel_29                            (IcuConf_IcuChannel_IcuChannel_29)
#define IcuConf_IcuChannel_IcuChannel_29         ((Icu_ChannelType)29U) 
#define IcuChannel_30                            (IcuConf_IcuChannel_IcuChannel_30)
#define IcuConf_IcuChannel_IcuChannel_30         ((Icu_ChannelType)30U) 
#define IcuChannel_31                            (IcuConf_IcuChannel_IcuChannel_31)
#define IcuConf_IcuChannel_IcuChannel_31         ((Icu_ChannelType)31U) 
#define IcuChannel_32                            (IcuConf_IcuChannel_IcuChannel_32)
#define IcuConf_IcuChannel_IcuChannel_32         ((Icu_ChannelType)32U) 
#define IcuChannel_33                            (IcuConf_IcuChannel_IcuChannel_33)
#define IcuConf_IcuChannel_IcuChannel_33         ((Icu_ChannelType)33U) 
#define IcuChannel_34                            (IcuConf_IcuChannel_IcuChannel_34)
#define IcuConf_IcuChannel_IcuChannel_34         ((Icu_ChannelType)34U) 
#define IcuChannel_35                            (IcuConf_IcuChannel_IcuChannel_35)
#define IcuConf_IcuChannel_IcuChannel_35         ((Icu_ChannelType)35U) 
#define IcuChannel_36                            (IcuConf_IcuChannel_IcuChannel_36)
#define IcuConf_IcuChannel_IcuChannel_36         ((Icu_ChannelType)36U) 
#define IcuChannel_37                            (IcuConf_IcuChannel_IcuChannel_37)
#define IcuConf_IcuChannel_IcuChannel_37         ((Icu_ChannelType)37U) 
#define IcuChannel_38                            (IcuConf_IcuChannel_IcuChannel_38)
#define IcuConf_IcuChannel_IcuChannel_38         ((Icu_ChannelType)38U) 
#define IcuChannel_39                            (IcuConf_IcuChannel_IcuChannel_39)
#define IcuConf_IcuChannel_IcuChannel_39         ((Icu_ChannelType)39U) 
#define IcuChannel_40                            (IcuConf_IcuChannel_IcuChannel_40)
#define IcuConf_IcuChannel_IcuChannel_40         ((Icu_ChannelType)40U) 
#define IcuChannel_41                            (IcuConf_IcuChannel_IcuChannel_41)
#define IcuConf_IcuChannel_IcuChannel_41         ((Icu_ChannelType)41U) 
#define IcuChannel_42                            (IcuConf_IcuChannel_IcuChannel_42)
#define IcuConf_IcuChannel_IcuChannel_42         ((Icu_ChannelType)42U) 
#define IcuChannel_43                            (IcuConf_IcuChannel_IcuChannel_43)
#define IcuConf_IcuChannel_IcuChannel_43         ((Icu_ChannelType)43U) 
#define IcuChannel_44                            (IcuConf_IcuChannel_IcuChannel_44)
#define IcuConf_IcuChannel_IcuChannel_44         ((Icu_ChannelType)44U) 
#define IcuChannel_45                            (IcuConf_IcuChannel_IcuChannel_45)
#define IcuConf_IcuChannel_IcuChannel_45         ((Icu_ChannelType)45U) 
#define IcuChannel_46                            (IcuConf_IcuChannel_IcuChannel_46)
#define IcuConf_IcuChannel_IcuChannel_46         ((Icu_ChannelType)46U) 
#define IcuChannel_47                            (IcuConf_IcuChannel_IcuChannel_47)
#define IcuConf_IcuChannel_IcuChannel_47         ((Icu_ChannelType)47U) 

#define ICU_MAX_CHANNEL                         (48U)
#define ICU_MAX_MODULE                          (3U)
#define ICU_INVALID_DMA_CHANNEL                 ((Icu_ChannelType)0xFF)


/* ICU Module Config */
#define ICU_GTM_USED                            (STD_ON)
#define ICU_EMIOS_USED                          (STD_OFF)

/* Config GTM channel num */
#define ICU_GTM_CHANNEL_NUM                     (48U)

/*===================================================================================================
*                                      LOCAL CONSTANTS
====================================================================================================*/

/*===================================================================================================
*                          GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
====================================================================================================*/
#define ICU_CONFIG_DECLARATION extern CONST(Icu_ConfigType, ICU_CONST) Icu_Cfg;

#ifdef __cplusplus
}
#endif
#endif /* ICU_CFG_H */

