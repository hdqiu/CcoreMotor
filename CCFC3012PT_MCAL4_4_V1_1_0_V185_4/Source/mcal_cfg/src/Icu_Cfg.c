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


extern void IcuSignalNotification_0(void);
extern void IcuSignalNotification_1(void);
extern void IcuSignalNotification_2(void);
extern void IcuSignalNotification_3(void);
extern void IcuSignalNotification_4(void);
extern void IcuSignalNotification_5(void);
extern void IcuSignalNotification_6(void);
extern void IcuSignalNotification_7(void);
extern void IcuSignalNotification_8(void);
extern void IcuSignalNotification_9(void);
extern void IcuSignalNotification_10(void);
extern void IcuSignalNotification_11(void);
extern void IcuSignalNotification_12(void);
extern void IcuSignalNotification_13(void);
extern void IcuSignalNotification_14(void);
extern void IcuSignalNotification_15(void);
extern void IcuSignalNotification_16(void);
extern void IcuSignalNotification_17(void);
extern void IcuSignalNotification_18(void);
extern void IcuSignalNotification_19(void);
extern void IcuSignalNotification_20(void);
extern void IcuSignalNotification_21(void);
extern void IcuSignalNotification_22(void);
extern void IcuSignalNotification_23(void);
extern void IcuSignalNotification_24(void);
extern void IcuSignalNotification_25(void);
extern void IcuSignalNotification_26(void);
extern void IcuSignalNotification_27(void);
extern void IcuSignalNotification_28(void);
extern void IcuSignalNotification_29(void);
extern void IcuSignalNotification_30(void);
extern void IcuSignalNotification_31(void);
extern void IcuSignalNotification_32(void);
extern void IcuSignalNotification_33(void);
extern void IcuSignalNotification_34(void);
extern void IcuSignalNotification_35(void);
extern void IcuSignalNotification_36(void);
extern void IcuSignalNotification_37(void);
extern void IcuSignalNotification_38(void);
extern void IcuSignalNotification_39(void);
extern void IcuSignalNotification_40(void);
extern void IcuSignalNotification_41(void);
extern void IcuSignalNotification_42(void);
extern void IcuSignalNotification_43(void);
extern void IcuSignalNotification_44(void);
extern void IcuSignalNotification_45(void);
extern void IcuSignalNotification_46(void);
extern void IcuSignalNotification_47(void);

extern void IcuTimestampNotification_0(void);
extern void IcuTimestampNotification_1(void);
extern void IcuTimestampNotification_2(void);
extern void IcuTimestampNotification_3(void);

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


/******************************************************************************************/
/************************************* GTM Config *****************************************/
/******************************************************************************************/
static CONST(Icu_ChannelConfig_Type, ICU_CONST) GtmChannelConfig[48] =
{
    {
        .IcuConfig_Instance = 0,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM0,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_RISING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_0,
        .IcuChannel_TimestampNotification = &IcuTimestampNotification_0,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 1,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM0,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH1,
        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_1,
        .IcuChannel_TimestampNotification = &IcuTimestampNotification_0,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_LINEAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)TRUE,
        .IcuChannel_DmaChannel = (uint8)EDMA_CHN12_NUMBER,
    },
    {
        .IcuConfig_Instance = 2,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM0,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_2,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 3,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM0,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH3,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_EDGE_DETECT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_3,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)TRUE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 4,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM0,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_EDGE_DETECT,
        .IcuChannel_DefaultStartEdge = ICU_RISING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_4,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)TRUE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 5,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM0,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_EDGE_DETECT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = &IcuSignalNotification_5,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_LINEAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)TRUE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 6,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM0,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH6,
        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_6,
        .IcuChannel_TimestampNotification = &IcuTimestampNotification_1,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_LINEAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 7,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM0,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH7,
        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_RISING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_7,
        .IcuChannel_TimestampNotification = &IcuTimestampNotification_2,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_LINEAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 8,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM1,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
        .IcuConfig_ChannelMode = ICU_MODE_TIMESTAMP,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = &IcuSignalNotification_8,
        .IcuChannel_TimestampNotification = &IcuTimestampNotification_3,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_LINEAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 9,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM1,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH1,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_9,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 10,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM1,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_RISING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_10,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 11,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM1,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH3,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_11,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_LOW_TIME,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 12,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM1,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = &IcuSignalNotification_12,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_PERIOD_TIME,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 13,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM1,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_RISING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_13,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_HIGH_TIME,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 14,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM1,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH6,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_14,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 15,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM1,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH7,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_RISING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_15,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 16,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = &IcuSignalNotification_16,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 17,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH1,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_17,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 18,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_18,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 19,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH3,
        .IcuConfig_ChannelMode = ICU_MODE_SIGNAL_MEASUREMENT,
        .IcuChannel_DefaultStartEdge = ICU_RISING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_19,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = ICU_DUTY_CYCLE,
        .IcuChannel_TimestampBufferProperty = ICU_CIRCULAR_BUFFER,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 20,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_RISING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_20,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 21,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = &IcuSignalNotification_21,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 22,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH6,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_22,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 23,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM2,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH7,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_23,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 24,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_24,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 25,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH1,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_25,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 26,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_26,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 27,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH3,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_27,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 28,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_28,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 29,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_29,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 30,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH6,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_30,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 31,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM3,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH7,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_31,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 32,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_32,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 33,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH1,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_33,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 34,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_34,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 35,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH3,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_35,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 36,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_36,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 37,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_37,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 38,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH6,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_38,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 39,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM4,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH7,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_39,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 40,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH0,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_40,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 41,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH1,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_41,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 42,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH2,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_42,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 43,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH3,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_43,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 44,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH4,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_44,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 45,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH5,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_FALLING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_45,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 46,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH6,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_BOTH_EDGES,
        .IcuChannel_Notification = &IcuSignalNotification_46,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
    {
        .IcuConfig_Instance = 47,
        .IcuConfig_ModuleId = (Icu_Module_Type)GTM_TIM5,
        .IcuConfig_ChannelId = (Icu_ChannelType)GTM_TIM_CH7,
        .IcuConfig_ChannelMode = ICU_MODE_EDGE_COUNTER,
        .IcuChannel_DefaultStartEdge = ICU_RISING_EDGE,
        .IcuChannel_Notification = &IcuSignalNotification_47,
        .IcuChannel_TimestampNotification = NULL_PTR,
        .IcuChannel_SignalMeasurementProperty = (Icu_SignalMeasurementPropertyType)0U,
        .IcuChannel_TimestampBufferProperty = (Icu_TimestampBufferType)0U,
        .IcuChannel_WakeupCapability = (boolean)FALSE, /* Wakeup capability */
    #if(ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        .IcuChannel_WakeupValue = (EcuM_WakeupSourceType)ICU_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */
    #endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        .IcuChannel_bDmaSupport = (boolean)FALSE,
        .IcuChannel_DmaChannel = (uint8)0,
    },
};

static CONST(ICU_Gtm_Config, ICU_CONST) Icu_GtmConfig =
{
    .uChannelCount = 48U,
    .pGtmChannelConfig = GtmChannelConfig
};









/******************************************************************************************/
/************************************ Hardware Map ****************************************/
/******************************************************************************************/
static CONST(ICU_HwModule_Type, ICU_CONST) Icu_HwChMap[48] =
{
    ICU_GTM_TIM0,
    ICU_GTM_TIM0,
    ICU_GTM_TIM0,
    ICU_GTM_TIM0,
    ICU_GTM_TIM0,
    ICU_GTM_TIM0,
    ICU_GTM_TIM0,
    ICU_GTM_TIM0,
    ICU_GTM_TIM1,
    ICU_GTM_TIM1,
    ICU_GTM_TIM1,
    ICU_GTM_TIM1,
    ICU_GTM_TIM1,
    ICU_GTM_TIM1,
    ICU_GTM_TIM1,
    ICU_GTM_TIM1,
    ICU_GTM_TIM2,
    ICU_GTM_TIM2,
    ICU_GTM_TIM2,
    ICU_GTM_TIM2,
    ICU_GTM_TIM2,
    ICU_GTM_TIM2,
    ICU_GTM_TIM2,
    ICU_GTM_TIM2,
    ICU_GTM_TIM3,
    ICU_GTM_TIM3,
    ICU_GTM_TIM3,
    ICU_GTM_TIM3,
    ICU_GTM_TIM3,
    ICU_GTM_TIM3,
    ICU_GTM_TIM3,
    ICU_GTM_TIM3,
    ICU_GTM_TIM4,
    ICU_GTM_TIM4,
    ICU_GTM_TIM4,
    ICU_GTM_TIM4,
    ICU_GTM_TIM4,
    ICU_GTM_TIM4,
    ICU_GTM_TIM4,
    ICU_GTM_TIM4,
    ICU_GTM_TIM5,
    ICU_GTM_TIM5,
    ICU_GTM_TIM5,
    ICU_GTM_TIM5,
    ICU_GTM_TIM5,
    ICU_GTM_TIM5,
    ICU_GTM_TIM5,
    ICU_GTM_TIM5,
};


static CONST(Icu_CoreMapItemType, ICU_CONST) Icu_CoreMap[48] =
{
    {
        .nIcuChannelId=0,
        .nCoreId=1
    },
    {
        .nIcuChannelId=1,
        .nCoreId=1
    },
    {
        .nIcuChannelId=2,
        .nCoreId=1
    },
    {
        .nIcuChannelId=3,
        .nCoreId=1
    },
    {
        .nIcuChannelId=4,
        .nCoreId=1
    },
    {
        .nIcuChannelId=5,
        .nCoreId=1
    },
    {
        .nIcuChannelId=6,
        .nCoreId=1
    },
    {
        .nIcuChannelId=7,
        .nCoreId=1
    },
    {
        .nIcuChannelId=8,
        .nCoreId=1
    },
    {
        .nIcuChannelId=9,
        .nCoreId=1
    },
    {
        .nIcuChannelId=10,
        .nCoreId=1
    },
    {
        .nIcuChannelId=11,
        .nCoreId=1
    },
    {
        .nIcuChannelId=12,
        .nCoreId=1
    },
    {
        .nIcuChannelId=13,
        .nCoreId=1
    },
    {
        .nIcuChannelId=14,
        .nCoreId=1
    },
    {
        .nIcuChannelId=15,
        .nCoreId=1
    },
    {
        .nIcuChannelId=16,
        .nCoreId=1
    },
    {
        .nIcuChannelId=17,
        .nCoreId=1
    },
    {
        .nIcuChannelId=18,
        .nCoreId=1
    },
    {
        .nIcuChannelId=19,
        .nCoreId=1
    },
    {
        .nIcuChannelId=20,
        .nCoreId=1
    },
    {
        .nIcuChannelId=21,
        .nCoreId=1
    },
    {
        .nIcuChannelId=22,
        .nCoreId=1
    },
    {
        .nIcuChannelId=23,
        .nCoreId=1
    },
    {
        .nIcuChannelId=24,
        .nCoreId=1
    },
    {
        .nIcuChannelId=25,
        .nCoreId=1
    },
    {
        .nIcuChannelId=26,
        .nCoreId=1
    },
    {
        .nIcuChannelId=27,
        .nCoreId=1
    },
    {
        .nIcuChannelId=28,
        .nCoreId=1
    },
    {
        .nIcuChannelId=29,
        .nCoreId=1
    },
    {
        .nIcuChannelId=30,
        .nCoreId=1
    },
    {
        .nIcuChannelId=31,
        .nCoreId=1
    },
    {
        .nIcuChannelId=32,
        .nCoreId=1
    },
    {
        .nIcuChannelId=33,
        .nCoreId=1
    },
    {
        .nIcuChannelId=34,
        .nCoreId=1
    },
    {
        .nIcuChannelId=35,
        .nCoreId=1
    },
    {
        .nIcuChannelId=36,
        .nCoreId=1
    },
    {
        .nIcuChannelId=37,
        .nCoreId=1
    },
    {
        .nIcuChannelId=38,
        .nCoreId=1
    },
    {
        .nIcuChannelId=39,
        .nCoreId=1
    },
    {
        .nIcuChannelId=40,
        .nCoreId=1
    },
    {
        .nIcuChannelId=41,
        .nCoreId=1
    },
    {
        .nIcuChannelId=42,
        .nCoreId=1
    },
    {
        .nIcuChannelId=43,
        .nCoreId=1
    },
    {
        .nIcuChannelId=44,
        .nCoreId=1
    },
    {
        .nIcuChannelId=45,
        .nCoreId=1
    },
    {
        .nIcuChannelId=46,
        .nCoreId=1
    },
    {
        .nIcuChannelId=47,
        .nCoreId=1
    },
};

/******************************************************************************************/
/************************************* ICU Config *****************************************/
/******************************************************************************************/

CONST(Icu_ConfigType, ICU_CONST) Icu_Cfg =
{
    .Icu_NumChannels    = 48U,
    .Icu_GtmConfig      = &Icu_GtmConfig,
    .Icu_eMoisConfig    = NULL_PTR,
    .Icu_WkpuConfig     = NULL_PTR,
    .Icu_HwChMap        = &Icu_HwChMap,
    .Icu_CoreMap        = Icu_CoreMap
};


