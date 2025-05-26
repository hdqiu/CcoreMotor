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


/* @brief    */
#define ADC_PRECOMPILE_SUPPORT              (STD_OFF)

/* @brief    */
#define ADC_DEINIT_API                      (STD_ON)

/* @brief    */
#define ADC_DEV_ERROR_DETECT                (STD_ON)

/* @brief    */
#define ADC_ENABLE_LIMIT_CHECK              (STD_OFF)

/* @brief    */
#define ADC_ENABLE_QUEUING                  (STD_OFF)

/* @brief    */
#define ADC_ENABLE_START_STOP_GROUP_API     (STD_ON)

/* @brief    */
#define ADC_GRP_NOTIF_CAPABILITY            (STD_OFF)

/* @brief    */
#define ADC_HW_TRIGGER_API                  (STD_ON)

/* @brief    */
#define ADC_POWER_STATE_SUPPORTED           (STD_OFF)

/* @brief    */
#define ADC_POWER_STATE_ASYNCH_TRANSTION    (STD_OFF)

/* @brief    */
#define ADC_READ_GROUP_API                  (STD_ON)

/* @brief    */
#define ADC_VERSION_INFO_API                (STD_ON)

/* @brief    */
#define ADC_ENABLE_MULTICORE                (STD_ON)

/* @brief    */
#define ADC_DEM_REPORT_ERROR_ENABLE         (STD_OFF)

/* @brief    */
#define ADC_INT_RFOF_ENABLE                 (STD_OFF)

/* @brief    */
#define ADC_INT_TORF_ENABLE                 (STD_OFF)



/* @brief    */
#define ADC_PRIORITY_IMPLEMENTATION         (PRIORITY_NONE)

/* @brief    */
#define ADC_MAX_CHANNEL                     (1U)

/* @brief    */
#define ADC_MAX_GROUPS                      (2U)

/* @brief    */
#define ADC_CONFIG_GROUPS                   (8U)

/* @brief    */
#define ADC_CONFIG_UNIT                     (6U)

/* @brief    */
#define ADC_TIMEOUT                         (65535UL)

/* @brief    */
#define ADC_QUEUE_MAX_DEPTH                 (1U)

/* @brief    */
#define ADC_RESULT_ALIGNMENT                (ADC_ALIGN_RIGHT) 

/* @brief    */
#define ADC_MAX_HW_UNITS                    (13U)

/* @brief    */
#define ADC_DEFAULT_COREID                  (0U)

/** Specification of ADC Driver : [SWS_Adc_00099] **/
/* Number of channels per group configuration. */
#define ADC_GROUP_0_CHANNEL_NUM             (1U)

/* The channel index 0 of group 0. */
#define GROUP_0_ADC2_AdcChannel_0                (0U)

#define ADC_GROUP_1_CHANNEL_NUM             (1U)

/* The channel index 0 of group 1. */
#define GROUP_1_ADC3_AdcChannel_0                (0U)

#define ADC_GROUP_2_CHANNEL_NUM             (1U)

/* The channel index 0 of group 2. */
#define GROUP_2_ADC8_AdcChannel_0                (0U)

#define ADC_GROUP_3_CHANNEL_NUM             (1U)

/* The channel index 0 of group 3. */
#define GROUP_3_ADC9_AdcChannel_0                (0U)

#define ADC_GROUP_4_CHANNEL_NUM             (1U)

/* The channel index 0 of group 4. */
#define GROUP_4_ADC10_AdcChannel_0                (0U)

#define ADC_GROUP_5_CHANNEL_NUM             (1U)

/* The channel index 0 of group 5. */
#define GROUP_5_ADC11_AdcChannel_0                (0U)

#define ADC_GROUP_6_CHANNEL_NUM             (1U)

/* The channel index 0 of group 6. */
#define GROUP_6_ADC9_AdcChannel_8                (0U)

#define ADC_GROUP_7_CHANNEL_NUM             (1U)

/* The channel index 0 of group 7. */
#define GROUP_7_ADC10_AdcChannel_10                (0U)


/** Specification of ADC Driver : [SWS_Adc_00099] **/
/* The symbolic name of the group. */
#define ADC_GROUP_ADC2_AdcGroup_0                (0U)
#define ADC_GROUP_ADC3_AdcGroup_0                (1U)
#define ADC_GROUP_ADC8_AdcGroup_0                (2U)
#define ADC_GROUP_ADC9_AdcGroup_0                (3U)
#define ADC_GROUP_ADC10_AdcGroup_0                (4U)
#define ADC_GROUP_ADC11_AdcGroup_0                (5U)
#define ADC_GROUP_ADC9_AdcGroup_1                (6U)
#define ADC_GROUP_ADC10_AdcGroup_1                (7U)



/* group_2_EDMA_CHN49_NUMBER_CallBack */
extern FUNC(void, ADC_CODE) Eqadc4_Adc8_RsltCallback \
( \
    P2CONST(void, ADC_VAR, ADC_APPL_CONST) parameter, \
    VAR(eDMAChnStatusType, ADC_VAR) status, \
    VAR(uint8, ADC_VAR) mappedChannel \
);
/* group_3_EDMA_CHN51_NUMBER_CallBack */
extern FUNC(void, ADC_CODE) Eqadc4_Adc9_RsltCallback \
( \
    P2CONST(void, ADC_VAR, ADC_APPL_CONST) parameter, \
    VAR(eDMAChnStatusType, ADC_VAR) status, \
    VAR(uint8, ADC_VAR) mappedChannel \
);

#endif /* ADC_CFG_H */

/** @} */
