/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc.h
* @version  1.0
* @date     2024 - 02 - 28
* @brief    Initial version.
*
*****************************************************************************/
#ifndef SDADC_H
#define SDADC_H
#include "SDAdc_Cfg.h"
#include "SDAdc_LLDriver.h"

#ifdef RESOURCE_SUPPORT_SDADC_IP

#define SDADC_H_VENDOR_ID                     176
#define SDADC_H_AR_REL_MAJOR_VER              4
#define SDADC_H_AR_REL_MINOR_VER              4
#define SDADC_H_AR_REL_REV_VER                0
#define SDADC_H_SW_MAJOR_VER                  1
#define SDADC_H_SW_MINOR_VER                  0
#define SDADC_H_SW_PATCH_VER                  1

#if (SDADC_CFG_H_VENDOR_ID               != SDADC_H_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_H_VENDOR_ID "
#endif
#if (SDADC_CFG_H_AR_REL_MAJOR_VER    != SDADC_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_H_AR_REL_MAJOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_MINOR_VER    != SDADC_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_H_AR_REL_MINOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_REV_VER != SDADC_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_H_AR_REL_REV_VER "
#endif
#if (SDADC_CFG_H_SW_MAJOR_VER        != SDADC_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_H_SW_MAJOR_VER "
#endif
#if (SDADC_CFG_H_SW_MINOR_VER        != SDADC_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_H_SW_MINOR_VER "
#endif
#if (SDADC_CFG_H_SW_PATCH_VER        != SDADC_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_H_SW_PATCH_VER "
#endif

#define SDADC_SID_INIT                              ((uint8)0x1AU)
#define SDADC_SID_DEINIT                            ((uint8)0x1BU)
#define SDADC_SID_START_MODULATION                  ((uint8)0x1CU)
#define SDADC_SID_STOP_MODULATION                   ((uint8)0x1DU)
#define SDADC_SID_READ_STREAM_RESULTS               ((uint8)0x1EU)
#define SDADC_SID_READ_RESULT                       ((uint8)0x1FU)
#define SDADC_SID_GET_STATUS                        ((uint8)0x20U)
#define SDADC_SID_SETUP_RESULT_BUFFER               ((uint8)0x21U)
#define SDADC_SID_START_CARRIER_SIGNAL              ((uint8)0x22U) //not supported
#define SDADC_SID_STOP_CARRIER_SIGNAL               ((uint8)0x23U) //not supported
#define SDADC_SID_ENABLE_NOTIFICATIONS              ((uint8)0x24U)
#define SDADC_SID_DISABLE_NOTIFICATIONS             ((uint8)0x25U)
#define SDADC_SID_GET_TIMESTAMP                     ((uint8)0x26U) //not supported
#define SDADC_SID_START_CALIBRATION                 ((uint8)0x27U)
#define SDADC_SID_GET_CALIBRATION_STATUS            ((uint8)0x28U) //not supported
#define SDADC_SID_INITCHECK                         ((uint8)0x29U)
#define SDADC_SID_ISR                               ((uint8)0x2AU)
#define SDADC_SID_TIMERISR                          ((uint8)0x2BU)
#define SDADC_SID_GET_VERSION_INFO                  ((uint8)0x2CU)
#define SDADC_SID_RESTART_DEMODULATOR               ((uint8)0x2DU) //not supported
#define SDADC_SID_GET_IRMS_VALUE                    ((uint8)0x2EU) //not supported
#define SDADC_SID_SET_GAINCORR_REG_VALUE            ((uint8)0xF0U)
#define SDADC_SID_RESTART_INTEGRATOR                ((uint8)0xF1U)
#define SDADC_SID_GET_SDCAP_VALUE                   ((uint8)0xF2U) //not supported
#define SDADC_SID_MAIN_FUNCTION                     ((uint8)0xF3U)

#define SDADC_E_NO_ERR                              ((uint8)0x00U)
#define SDADC_E_PARAM_CONFIG                        ((uint8)0x01U)
#define SDADC_E_ALREADY_INITIALIZED                 ((uint8)0x02U)
#define SDADC_E_UNINIT                              ((uint8)0x03U)
#define SDADC_E_BUSY                                ((uint8)0x04U)
#define SDADC_E_PARAM_CHANNEL                       ((uint8)0x05U)
#define SDADC_E_PARAM_POINTER                       ((uint8)0x06U)
#define SDADC_E_INV_LINEAR_BUFFER_CONFIG            ((uint8)0x07U)
#define SDADC_E_INV_CIRCULAR_BUFFER_CONFIG          ((uint8)0x08U)
#define SDADC_E_INVALID_BUFFER_CONFIG               ((uint8)0x09U)
#define SDADC_E_UNIDLE                              ((uint8)0x0AU)
#define SDADC_E_CARRIER_ALREADY_RUNNING             ((uint8)0x0BU)
#define SDADC_E_NOTIF_CAPABILITY                    ((uint8)0x0CU)
#define SDADC_E_SINGLE_ACCESSMODE_TIMESTAMP         ((uint8)0x0DU)
#define SDADC_E_CALIB_RUNNING                       ((uint8)0x0EU)
#define SDADC_E_INV_BUFFER_SIZE                     ((uint8)0x0FU)
#define SDADC_E_INVALID_BUFFER_POINTER              ((uint8)0x10U)
#define SDADC_E_INVALID_PARAM_VALUE                 ((uint8)0x11U)
#define SDADC_E_INVALID_PARAM_DELAY                 ((uint8)0x12U)
#define SDADC_E_BUFFER_FULL                         ((uint8)0x13U)
#define SDADC_E_PARAM_ERROR                         ((uint8)0x14U)

#define SDADC_IDLE                             ((Sdadc_ChannelstatusType)0x0U)
#define SDADC_BUSY                             ((Sdadc_ChannelstatusType)0x1U)
#define SDADC_RESULT_READY                     ((Sdadc_ChannelstatusType)0x2U)

#define SDADC_READSTREAM_ERROR               (0xFFFFU)
#define SDADC_MAX_BUFFER_LENGTH              (0xFFFEU)

#define SOFTWARE_TRIG (0x0U)
#define HARDWARE_TRIG (0x1U)

#if (SDADC_ENABLE_MULTICORE == STD_ON)
    #define SDAdc_GetCoreID()     (1U << GetCoreID())
#else
    #define SDAdc_GetCoreID()     (1U << SDADC_DEFAULT_COREID)
#endif

#define CORE_NUM 6U

typedef uint8 Sdadc_ChannelType;
typedef uint16 Sdadc_SizeType;
typedef sint16 Sdadc_ResultType;
typedef uint8 Sdadc_ChannelStatusType;
typedef uint16 Sdadc_TimeStampType;
typedef uint8 Sdadc_CalibrationStatusType;
typedef uint32 Sdadc_ChannelMaskType;
typedef uint16 Sdadc_IrmsValueType;
typedef uint8 Sdadc_GainCorrType;
typedef uint32 Sdadc_DelayType;
typedef uint8 Sdadc_SdcapValueType;
typedef uint8 Sdadc_ChannelstatusType;

typedef void (*Sdadc_NotifyType)(void);

typedef enum
{
    SDADC_UNINIT = 0U,
    SDADC_INITED = 1U,
} Sdadc_InitStateType;

typedef enum
{
    SDADC_STREAM_LINEAR_BUFFER=0U,
    SDADC_CIRCULAR_BUFFER = 1U,
} Sdadc_BufferModeType;

typedef enum
{
    SDADC_USE_INTERRUPT = 0U,
    SDADC_USE_DMA = 1U,
    SDADC_USE_POLLING = 2U,
} Sdadc_ConvMethodType;

typedef enum 
{
#ifdef CCFC3007PT
    HWTRIGSEL_TOM2_4 = 0U,
    HWTRIGSEL_TOM2_5 = 1U,
    HWTRIGSEL_TOM2_6 = 2U,
    HWTRIGSEL_TOM2_7 = 3U,
    HWTRIGSEL_TOM2_8 = 4U,
    HWTRIGSEL_TOM2_9 = 5U,
    HWTRIGSEL_TOM2_10 = 6U,
    HWTRIGSEL_TOM2_11 = 7U,
    HWTRIGSEL_ATOM3_0 = 8U,
    HWTRIGSEL_ATOM3_1 = 9U,
    HWTRIGSEL_ATOM3_2 = 10U,
    HWTRIGSEL_ATOM3_3 = 11U,
    HWTRIGSEL_ATOM3_4 = 12U,
    HWTRIGSEL_ATOM3_5 = 13U,
    HWTRIGSEL_ATOM3_6 = 14U,
    HWTRIGSEL_ATOM3_7 = 15U,
    HWTRIGSEL_SDADC0 = 16U,
    HWTRIGSEL_SDADC1 = 17U,
    HWTRIGSEL_SDADC2 = 18U,
    HWTRIGSEL_SDADC3 = 19U,
    HWTRIGSEL_SDADC4 = 20U,
    HWTRIGSEL_SDADC6 = 22U,
    HWTRIGSEL_SDADC7 = 23U,
    HWTRIGSEL_SDADC8 = 24U,
#endif
#ifdef CCFC3012PT
    HWTRIGSEL_GTM_TRIG0_BIT0  = 0U,
    HWTRIGSEL_GTM_TRIG0_BIT1  = 1U,
    HWTRIGSEL_GTM_TRIG0_BIT2  = 2U,
    HWTRIGSEL_GTM_TRIG0_BIT3  = 3U,
    HWTRIGSEL_GTM_TRIG0_BIT4  = 4U,
    HWTRIGSEL_GTM_TRIG0_BIT5  = 5U,
    HWTRIGSEL_GTM_TRIG0_BIT6  = 6U,
    HWTRIGSEL_GTM_TRIG0_BIT7  = 7U,
    HWTRIGSEL_GTM_TRIG0_BIT8  = 8U,
    HWTRIGSEL_GTM_TRIG0_BIT9  = 9U,
    HWTRIGSEL_GTM_TRIG0_BIT10 = 10U,
    HWTRIGSEL_GTM_TRIG0_BIT11 = 11U,
    HWTRIGSEL_GTM_TRIG0_BIT12 = 12U,
    HWTRIGSEL_GTM_TRIG0_BIT13 = 13U,
    HWTRIGSEL_GTM_TRIG1_BIT0  = 14U,
    HWTRIGSEL_GTM_TRIG1_BIT1  = 15U,
    HWTRIGSEL_GTM_TRIG1_BIT2  = 16U,
    HWTRIGSEL_GTM_TRIG1_BIT3  = 17U,
    HWTRIGSEL_GTM_TRIG1_BIT4  = 18U,
    HWTRIGSEL_GTM_TRIG1_BIT5  = 19U,
    HWTRIGSEL_GTM_TRIG1_BIT6  = 20U,
    HWTRIGSEL_GTM_TRIG1_BIT7  = 21U,
    HWTRIGSEL_GTM_TRIG1_BIT8  = 22U,
    HWTRIGSEL_GTM_TRIG1_BIT9  = 23U,
    HWTRIGSEL_GTM_TRIG1_BIT10 = 24U,
    HWTRIGSEL_GTM_TRIG1_BIT11 = 25U,
    HWTRIGSEL_GTM_TRIG1_BIT12 = 26U,
    HWTRIGSEL_GTM_TRIG1_BIT13 = 27U,
    HWTRIGSEL_GTM_TRIG2_BIT0  = 28U,
    HWTRIGSEL_GTM_TRIG2_BIT1  = 29U,
    HWTRIGSEL_GTM_TRIG2_BIT2  = 30U,
    HWTRIGSEL_GTM_TRIG2_BIT3  = 31U,
    HWTRIGSEL_GTM_TRIG2_BIT4  = 32U,
    HWTRIGSEL_GTM_TRIG2_BIT5  = 33U,
    HWTRIGSEL_GTM_TRIG2_BIT6  = 34U,
    HWTRIGSEL_GTM_TRIG2_BIT7  = 35U,
    HWTRIGSEL_GTM_TRIG2_BIT8  = 36U,
    HWTRIGSEL_GTM_TRIG2_BIT9  = 37U,
    HWTRIGSEL_GTM_TRIG2_BIT10 = 38U,
    HWTRIGSEL_GTM_TRIG2_BIT11 = 39U,
    HWTRIGSEL_GTM_TRIG2_BIT12 = 40U,
    HWTRIGSEL_GTM_TRIG2_BIT13 = 41U,
    HWTRIGSEL_GTM_TRIG3_BIT0  = 42U,
    HWTRIGSEL_GTM_TRIG3_BIT1  = 43U,
    HWTRIGSEL_GTM_TRIG3_BIT2  = 44U,
    HWTRIGSEL_GTM_TRIG3_BIT3  = 45U,
    HWTRIGSEL_GTM_TRIG3_BIT4  = 46U,
    HWTRIGSEL_GTM_TRIG3_BIT5  = 47U,
    HWTRIGSEL_GTM_TRIG3_BIT6  = 48U,
    HWTRIGSEL_GTM_TRIG3_BIT7  = 49U,
    HWTRIGSEL_GTM_TRIG3_BIT8  = 50U,
    HWTRIGSEL_GTM_TRIG3_BIT9  = 51U,
    HWTRIGSEL_GTM_TRIG3_BIT10 = 52U,
    HWTRIGSEL_GTM_TRIG3_BIT11 = 53U,
    HWTRIGSEL_GTM_TRIG3_BIT12 = 54U,
    HWTRIGSEL_GTM_TRIG3_BIT13 = 55U,
    HWTRIGSEL_TRIG_PAD15 = 56U,             /*PA15*/    
    HWTRIGSEL_TRIG_PAD3 = 57U,              /*PA3*/
    HWTRIGSEL_TRIG_PAD6 = 58U,              /*PA6*/
    HWTRIGSEL_TRIG_PAD9 = 59U,              /*PA9*/
    HWTRIGSEL_TRIG_PAD16 = 60U,             /*PB0*/  
    HWTRIGSEL_TRIG_PAD26 = 61U,             /*PB10*/ 
    HWTRIGSEL_TRIG_PAD27 = 62U,             /*PB11*/ 
    HWTRIGSEL_TRIG_PAD28 = 63U,             /*PB12*/ 
    HWTRIGSEL_TRIG_PAD29 = 64U,             /*PB13*/ 
    HWTRIGSEL_TRIG_PAD30 = 65U,             /*PB14*/ 
    HWTRIGSEL_TRIG_PAD31 = 66U,             /*PB15*/ 
    HWTRIGSEL_TRIG_PAD17 = 67U,             /*PB1*/ 
    HWTRIGSEL_TRIG_PAD19 = 68U,             /*PB3*/ 
    HWTRIGSEL_TRIG_PAD20 = 69U,             /*PB4*/ 
    HWTRIGSEL_TRIG_PAD23 = 70U,             /*PB7*/ 
    HWTRIGSEL_TRIG_PAD44 = 71U,             /*PC12*/ 
    HWTRIGSEL_TRIG_PAD45 = 72U,             /*PC13*/ 
    HWTRIGSEL_TRIG_PAD46 = 73U,             /*PC14*/ 
    HWTRIGSEL_TRIG_PAD47 = 74U,             /*PC15*/ 
    HWTRIGSEL_TRIG_PAD38 = 75U,             /*PC6*/ 
    HWTRIGSEL_TRIG_PAD39 = 76U,             /*PC7*/ 
    HWTRIGSEL_TRIG_PAD40 = 77U,             /*PC8*/ 
    HWTRIGSEL_TRIG_PAD241 = 78U,             /*PP1*/
    HWTRIGSEL_TRIG_PAD242 = 79U,             /*PP2*/
    HWTRIGSEL_TRIG_PAD243 = 80U,            /*PP3*/
    HWTRIGSEL_TRIG_PAD245 = 81U,            /*PP5*/
    HWTRIGSEL_TRIG_PAD246 = 82U,            /*PP6*/
    HWTRIGSEL_TRIG_PAD247 = 83U,            /*PP7*/
    HWTRIGSEL_SDADC0 = 84U,
    HWTRIGSEL_SDADC1 = 85U,
    HWTRIGSEL_SDADC2 = 86U,
    HWTRIGSEL_SDADC3 = 87U,
    HWTRIGSEL_SDADC4 = 88U,
    HWTRIGSEL_SDADC5 = 89U,
    HWTRIGSEL_SDADC6 = 90U,
    HWTRIGSEL_SDADC7 = 91U,
    HWTRIGSEL_SDADC8 = 92U,
    HWTRIGSEL_SDADC9 = 93U,
    HWTRIGSEL_SDADC10 = 94U,
    HWTRIGSEL_SDADC11 = 95U,
    HWTRIGSEL_SDADC12 = 96U,
    HWTRIGSEL_SDADC13 = 97U,
#endif
	NO_HWTRIG = 255U,
} Sdadc_HwTrigChSelType;

typedef enum 
{
    SOURCE_DISABLE = 0U,
#ifdef CCFC3007PT
    TOM2_4_SOURCE = 0x10U,
    TOM2_5_SOURCE = 0x11U,
    TOM2_6_SOURCE = 0x12U,
    TOM2_7_SOURCE = 0x13U,
    TOM2_8_SOURCE = 0x14U,
    TOM2_9_SOURCE = 0x15U,
    TOM2_10_SOURCE = 0x16U,
    TOM2_11_SOURCE = 0x17U,
    ATOM3_0_SOURCE = 0x18U,
    ATOM3_1_SOURCE = 0x19U,
    ATOM3_2_SOURCE = 0x1aU,
    ATOM3_3_SOURCE = 0x1bU,
    ATOM3_4_SOURCE = 0x1cU,
    ATOM3_5_SOURCE = 0x1dU,
    ATOM3_6_SOURCE = 0x1eU,
    ATOM3_7_SOURCE = 0x1fU,
#endif
#ifdef CCFC3012PT
    SDADC_GTM_TRIG0_BIT0  = 0x01U,
    SDADC_GTM_TRIG0_BIT1  = 0x02U,
    SDADC_GTM_TRIG0_BIT2  = 0x03U,
    SDADC_GTM_TRIG0_BIT3  = 0x04U,
    SDADC_GTM_TRIG0_BIT4  = 0x05U,
    SDADC_GTM_TRIG0_BIT5  = 0x06U,
    SDADC_GTM_TRIG0_BIT6  = 0x07U,
    SDADC_GTM_TRIG0_BIT7  = 0x08U,
    SDADC_GTM_TRIG0_BIT8  = 0x09U,
    SDADC_GTM_TRIG0_BIT9  = 0x0aU,
    SDADC_GTM_TRIG0_BIT10 = 0x0bU,
    SDADC_GTM_TRIG0_BIT11 = 0x0cU,
    SDADC_GTM_TRIG0_BIT12 = 0x0dU,
    SDADC_GTM_TRIG0_BIT13 = 0x0eU,
    SDADC_GTM_TRIG1_BIT0  = 0x0fU,
    SDADC_GTM_TRIG1_BIT1  = 0x10U,
    SDADC_GTM_TRIG1_BIT2  = 0x11U,
    SDADC_GTM_TRIG1_BIT3  = 0x12U,
    SDADC_GTM_TRIG1_BIT4  = 0x13U,
    SDADC_GTM_TRIG1_BIT5  = 0x14U,
    SDADC_GTM_TRIG1_BIT6  = 0x15U,
    SDADC_GTM_TRIG1_BIT7  = 0x16U,
    SDADC_GTM_TRIG1_BIT8  = 0x17U,
    SDADC_GTM_TRIG1_BIT9  = 0x18U,
    SDADC_GTM_TRIG1_BIT10 = 0x19U,
    SDADC_GTM_TRIG1_BIT11 = 0x1aU,
    SDADC_GTM_TRIG1_BIT12 = 0x1bU,
    SDADC_GTM_TRIG1_BIT13 = 0x1cU,
    SDADC_GTM_TRIG2_BIT0  = 0x1dU,
    SDADC_GTM_TRIG2_BIT1  = 0x1eU,
    SDADC_GTM_TRIG2_BIT2  = 0x1fU,
    SDADC_GTM_TRIG2_BIT3  = 0x20U,
    SDADC_GTM_TRIG2_BIT4  = 0x21U,
    SDADC_GTM_TRIG2_BIT5  = 0x22U,
    SDADC_GTM_TRIG2_BIT6  = 0x23U,
    SDADC_GTM_TRIG2_BIT7  = 0x24U,
    SDADC_GTM_TRIG2_BIT8  = 0x25U,
    SDADC_GTM_TRIG2_BIT9  = 0x26U,
    SDADC_GTM_TRIG2_BIT10 = 0x27U,
    SDADC_GTM_TRIG2_BIT11 = 0x28U,
    SDADC_GTM_TRIG2_BIT12 = 0x29U,
    SDADC_GTM_TRIG2_BIT13 = 0x2aU,
    SDADC_GTM_TRIG3_BIT0  = 0x2bU,
    SDADC_GTM_TRIG3_BIT1  = 0x2cU,
    SDADC_GTM_TRIG3_BIT2  = 0x2dU,
    SDADC_GTM_TRIG3_BIT3  = 0x2eU,
    SDADC_GTM_TRIG3_BIT4  = 0x2fU,
    SDADC_GTM_TRIG3_BIT5  = 0x30U,
    SDADC_GTM_TRIG3_BIT6  = 0x31U,
    SDADC_GTM_TRIG3_BIT7  = 0x32U,
    SDADC_GTM_TRIG3_BIT8  = 0x33U,
    SDADC_GTM_TRIG3_BIT9  = 0x34U,
    SDADC_GTM_TRIG3_BIT10 = 0x35U,
    SDADC_GTM_TRIG3_BIT11 = 0x36U,
    SDADC_GTM_TRIG3_BIT12 = 0x37U,
    SDADC_GTM_TRIG3_BIT13 = 0x38U,
    SDADC_TRIG_PAD15 = 0x39U,           /*PA15*/
    SDADC_TRIG_PAD3 = 0x3aU,            /*PA3*/
    SDADC_TRIG_PAD6 = 0x3bU,            /*PA6*/
    SDADC_TRIG_PAD9 = 0x3cU,            /*PA9*/
    SDADC_TRIG_PAD16 = 0x3dU,           /*PB0*/
    SDADC_TRIG_PAD26 = 0x3eU,           /*PB10*/
    SDADC_TRIG_PAD27 = 0x3fU,           /*PB11*/
    SDADC_TRIG_PAD28 = 0x40U,           /*PB12*/
    SDADC_TRIG_PAD29 = 0x41U,           /*PB13*/
    SDADC_TRIG_PAD30 = 0x42U,           /*PB14*/
    SDADC_TRIG_PAD31 = 0x43U,           /*PB15*/
    SDADC_TRIG_PAD17 = 0x44U,           /*PB1*/
    SDADC_TRIG_PAD19 = 0x45U,           /*PB3*/
    SDADC_TRIG_PAD20 = 0x46U,           /*PB4*/
    SDADC_TRIG_PAD23 = 0x47U,           /*PB7*/
    SDADC_TRIG_PAD44 = 0x48U,           /*PC12*/
    SDADC_TRIG_PAD45 = 0x49U,           /*PC13*/
    SDADC_TRIG_PAD46 = 0x4aU,           /*PC14*/
    SDADC_TRIG_PAD47 = 0x4bU,           /*PC15*/
    SDADC_TRIG_PAD38 = 0x4cU,           /*PC6*/
    SDADC_TRIG_PAD39 = 0x4dU,           /*PC7*/
    SDADC_TRIG_PAD40 = 0x4eU,           /*PC8*/
    SDADC_TRIG_PAD241 = 0x4fU,          /*PP1*/
    SDADC_TRIG_PAD242 = 0x50U,          /*PP2*/
    SDADC_TRIG_PAD243 = 0x51U,          /*PP3*/
    SDADC_TRIG_PAD245 = 0x52U,          /*PP5*/
    SDADC_TRIG_PAD246 = 0x53U,          /*PP6*/
    SDADC_TRIG_PAD247 = 0x54U,          /*PP7*/
#endif
} Sdadc_HwTrigSourceType;

#ifdef CCFC3007PT
typedef enum
{
    SDADC_TRIGREG_DISABLE,
    SDADC_TRIGREG_HW5,
    SDADC_TRIGREG_HW9,
    SDADC_TRIGREG_HW11,
    SDADC_TRIGREG_HW12,
    SDADC_TRIGREG_HW13,
    SDADC_TRIGREG_HW14,
    SDADC_TRIGREG_HW15,
} Sdadc_HwTrigRegIdType;
#endif

#ifdef CCFC3007PT
typedef enum 
{
    SDADC_TRIG_DEFAULT = 0U,
    SDADC_TRIG_RTI,
    SDADC_TRIG_PIT0,
    SDADC_TRIG_PIT1,
    SDADC_TRIG_PIT2,
    SDADC_TRIG_PIT3,
    SDADC_TRIG_ETPUA28,
    SDADC_TRIG_ETPUA29,
    SDADC_TRIG_ETPUA30,
    SDADC_TRIG_ETPUA31,
    SDADC_TRIG_ETPUB28,
    SDADC_TRIG_ETPUB29,
    SDADC_TRIG_ETPUB30,
    SDADC_TRIG_ETPUB31,
    SDADC_TRIG_ETPUC28,
    SDADC_TRIG_ETPUC29,
    SDADC_TRIG_ETPUC30,
    SDADC_TRIG_ETPUC31,
    SDADC_TRIG_EMIOS0_CH16,
    SDADC_TRIG_EMIOS0_CH17,
    SDADC_TRIG_EMIOS0_CH18,
    SDADC_TRIG_EMIOS0_CH19,
    SDADC_TRIG_EMIOS0_CH20,
    SDADC_TRIG_EMIOS0_CH21,
    SDADC_TRIG_EMIOS0_CH22,
    SDADC_TRIG_EMIOS0_CH23,
    SDADC_TRIG_EMIOS1_CH2,
    SDADC_TRIG_EMIOS1_CH3,
    SDADC_TRIG_EMIOS1_CH4,
    SDADC_TRIG_EMIOS1_CH5,
    SDADC_TRIG_EMIOS1_CH6,
    SDADC_TRIG_EMIOS1_CH7,
    SDADC_TRIG_ETRIG1_ADDR7,
    SDADC_TRIG_ETRIG0_ADDR7,
    SDADC_TRIG_ETRIG1_ADDR96,
    SDADC_TRIG_ETRIG0_ADDR96,
    SDADC_TRIG_ETPUA7,
    SDADC_TRIG_ETPUA14,
    SDADC_TRIG_ETPUA22,
    SDADC_TRIG_ETPUA26,
    SDADC_TRIG_ETPUA27,
    SDADC_TRIG_ETPUA30_PIT0,
    SDADC_TRIG_ETPUA30_PIT1,
    SDADC_TRIG_ETPUC28_LSL9,
    SDADC_TRIG_ETPUC29_LSL9,
    SDADC_TRIG_ETPUC30_LSL9,
    SDADC_TRIG_ETPUC31_LSL9,
    SDADC_TRIG_EMIOS1_CH2_PIT2,
    SDADC_TRIG_EMIOS1_CH2_PIT3,
} Sdadc_HwTrigChIDType;
#endif
typedef struct
{
    P2VAR(uint32, SDADC_VAR, SDADC_APPL_CONST) ChannelResBuffer;
    VAR(Sdadc_SizeType, SDADC_VAR) NumofValidConRes;
    VAR(Sdadc_SizeType, SDADC_VAR) ChannelBufferSize;
    VAR(Sdadc_ChannelstatusType, SDADC_VAR) ChannelStatus;
    VAR(boolean, SDADC_VAR) NotifyStatus;
} Sdadc_ChannelDataType;

typedef struct 
{
    VAR(Sdadc_InstanceType, SDADC_VAR) Sdadc_InstanceId;
    P2CONST(Sdadc_ConfigType, SDADC_CONST, ADC_APPL_CONST) Sdadc_Config;
    VAR(Sdadc_BufferModeType, SDADC_VAR) Sdadc_BufferMode;
    VAR(Sdadc_ConvMethodType, SDADC_VAR) Sdadc_ConvMethod;
    VAR(Sdadc_NotifyType, SDADC_VAR) Sdadc_NewResultNotify;
    VAR(Sdadc_NotifyType, SDADC_VAR) Sdadc_BufferFullNotifyPtr;
    VAR(uint8, SDADC_VAR) Sdadc_SwOrHw;
    VAR(Sdadc_HwTrigChSelType, SDADC_VAR) Sdadc_HwTrigSrc;
#ifdef CCFC3007PT
    VAR(Sdadc_HwTrigRegIdType, SDADC_VAR) Sdadc_HwTrigRegId;
    VAR(Sdadc_HwTrigChIDType, SDADC_VAR) Sdadc_HwTrigChID;
#endif
} SdAdc_InstanceConfigType; 

typedef struct{
    VAR(uint16, SDADC_VAR) SdAdc_ChannelIndex;
    VAR(uint8, SDADC_VAR) SdAdc_CoreId;
} SdAdc_CoreMapItemType;

typedef struct 
{
    P2CONST(SdAdc_InstanceConfigType, SDADC_VAR, SDADC_APPL_CONST) SdAdc_InstanceConfig;
    P2CONST(SdAdc_CoreMapItemType, SDADC_CONST, SDADC_APPL_CONST) SdAdc_CoreMapItem;
} SdAdc_TotalConfigType;

FUNC(void, SDADC_CODE) Sdadc_Init(CONSTP2CONST(SdAdc_TotalConfigType, SDADC_CONST, SDADC_APPL_CONST) ConfigPtr);
FUNC(void, SDADC_CODE) Sdadc_DeInit(void);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StartModulation(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StopModulation(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(Sdadc_SizeType, SDADC_CODE) Sdadc_ReadStreamResults \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId, \
    CONSTP2VAR(Sdadc_ResultType, SDADC_CONST, SDADC_APPL_CONST) ResultLinearBufferPtr \
);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_ReadResult \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId, \
    CONSTP2VAR(Sdadc_ResultType, SDADC_CONST, SDADC_APPL_CONST) ResultPtr \
);
FUNC(Sdadc_ChannelStatusType, SDADC_CODE) Sdadc_GetStatus(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_SetupResultBuffer \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId,\
	P2VAR(uint32, SDADC_VAR, SDADC_APPL_CONST) DataBufferPtr, \
    CONST(Sdadc_SizeType, SDADC_CONST) Size \
);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StartCarrierSignal(void);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StopCarrierSignal(void);
FUNC(void, SDADC_CODE) Sdadc_EnableNotifications(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(void, SDADC_CODE) Sdadc_DisableNotifications(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(Sdadc_TimeStampType, SDADC_CODE) Sdadc_GetTimestamp(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_StartCalibration(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(Sdadc_CalibrationStatusType, SDADC_CODE) Sdadc_GetCalibrationStatus(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_InitCheck(CONSTP2CONST(SdAdc_TotalConfigType, SDADC_CONST, SDADC_APPL_CONST) ConfigPtr);
FUNC(void, SDADC_CODE) Sdadc_GetVersionInfo(CONSTP2VAR(Std_VersionInfoType, SDADC_CONST, SDADC_APPL_CONST) versioninfo);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_RestartDemodulator(CONST(Sdadc_ChannelMaskType, SDADC_CONST) ChannelId);
FUNC(Sdadc_IrmsValueType, SDADC_CODE) Sdadc_GetIrmsValue(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_SetGainCorrRegValue \
(
    CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId, \
    CONST(Sdadc_GainCorrType, SDADC_CONST) RegValue \
);
FUNC(Std_ReturnType, SDADC_CODE) Sdadc_RestartIntegrator \
( \
    CONST(Sdadc_ChannelMaskType, SDADC_CONST) ChannelId, \
    CONST(Sdadc_DelayType, SDADC_CONST) Delay \
);
FUNC(Sdadc_SdcapValueType, SDADC_CODE) Sdadc_GetSdcapValue(CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);
FUNC(void, SDADC_CODE) Sdadc_MainFunction(void);

extern CONST(SdAdc_TotalConfigType, SDADC_CONST) SdAdc_TotalConfig;
extern P2CONST(SdAdc_TotalConfigType, SDADC_CONST, SDADC_APPL_CONST) sdAdc_ConfigPtr[CORE_NUM];
extern VAR(Sdadc_ChannelDataType, SDADC_VAR) Sdadc_ChannelData[SDADC_INSTANCE_CDG_NUM][CORE_NUM];
extern CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) Adc_SdadcBase0[ADC_SDADC_MAX_INSTANCE];
extern VAR(Sdadc_ChannelType, ADC_VAR) SDAdc_gIrqMapping[ADC_SDADC_MAX_INSTANCE][CORE_NUM];

#endif /*RESOURCE_SUPPORT_SDADC_IP*/
#endif /* SDADC_H */



