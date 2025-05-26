/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC 
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
*   @file    Icu_eMIOS_HAL_Wrapper.h
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
#ifndef ICU_EMIOS_HAL_WRAPPER_H
#define ICU_EMIOS_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "StandardTypes.h"
#include "intc_lld.h"
#include "Icu.h"
#include "Icu_eMIOS_LLDrivers.h"
#include "Icu_eMIOS_Types.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_EMIOS_HAL_WRAPPER_VENDOR_ID_H                   176

#define ICU_EMIOS_HAL_WRAPPER_MAJOR_VER_H                   4
#define ICU_EMIOS_HAL_WRAPPER_MINOR_VER_H                   4
#define ICU_EMIOS_HAL_WRAPPER_REVISION_VER_H                0

#define ICU_EMIOS_HAL_WRAPPER_SW_MAJOR_VER_H                1
#define ICU_EMIOS_HAL_WRAPPER_SW_MINOR_VER_H                0
#define ICU_EMIOS_HAL_WRAPPER_SW_PATCH_VER_H                1

#if (ICU_EMIOS_HAL_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_EMIOS_HAL_WRAPPER_MAJOR_VER_H != ICU_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ICU_EMIOS_HAL_WRAPPER_MINOR_VER_H != ICU_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ICU_EMIOS_HAL_WRAPPER_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_EMIOS_HAL_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_EMIOS_HAL_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_EMIOS_HAL_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
* eMIOS  channel define 
*/
#define EMIOS_CHANNEL_0                     (uint8)0
#define EMIOS_CHANNEL_1                     (uint8)1
#define EMIOS_CHANNEL_2                     (uint8)2
#define EMIOS_CHANNEL_3                     (uint8)3
#define EMIOS_CHANNEL_4                     (uint8)4
#define EMIOS_CHANNEL_5                     (uint8)5
#define EMIOS_CHANNEL_6                     (uint8)6
#define EMIOS_CHANNEL_7                     (uint8)7
#define EMIOS_CHANNEL_8                     (uint8)8
#define EMIOS_CHANNEL_9                     (uint8)9
#define EMIOS_CHANNEL_10                    (uint8)10
#define EMIOS_CHANNEL_11                    (uint8)11
#define EMIOS_CHANNEL_12                    (uint8)12
#define EMIOS_CHANNEL_13                    (uint8)13
#define EMIOS_CHANNEL_14                    (uint8)14
#define EMIOS_CHANNEL_15                    (uint8)15
#define EMIOS_CHANNEL_16                    (uint8)16
#define EMIOS_CHANNEL_17                    (uint8)17
#define EMIOS_CHANNEL_18                    (uint8)18
#define EMIOS_CHANNEL_19                    (uint8)19
#define EMIOS_CHANNEL_20                    (uint8)20
#define EMIOS_CHANNEL_21                    (uint8)21
#define EMIOS_CHANNEL_22                    (uint8)22
#define EMIOS_CHANNEL_23                    (uint8)23
#define EMIOS_CHANNEL_24                    (uint8)24
#define EMIOS_CHANNEL_25                    (uint8)25
#define EMIOS_CHANNEL_26                    (uint8)26
#define EMIOS_CHANNEL_27                    (uint8)27
#define EMIOS_CHANNEL_28                    (uint8)28
#define EMIOS_CHANNEL_29                    (uint8)29
#define EMIOS_CHANNEL_30                    (uint8)30
#define EMIOS_CHANNEL_31                    (uint8)31
/**
* eMIOS balls channel define 
*/
#define EMIOS_BALLS_CHANNEL_0               EMIOS_CHANNEL_0
#define EMIOS_BALLS_CHANNEL_1               EMIOS_CHANNEL_1
#define EMIOS_BALLS_CHANNEL_2               EMIOS_CHANNEL_2
#define EMIOS_BALLS_CHANNEL_3               EMIOS_CHANNEL_3
#define EMIOS_BALLS_CHANNEL_4               EMIOS_CHANNEL_4
#define EMIOS_BALLS_CHANNEL_5               EMIOS_CHANNEL_5
#define EMIOS_BALLS_CHANNEL_6               EMIOS_CHANNEL_6
#define EMIOS_BALLS_CHANNEL_7               EMIOS_CHANNEL_7
#define EMIOS_BALLS_CHANNEL_8               EMIOS_CHANNEL_8
#define EMIOS_BALLS_CHANNEL_9               EMIOS_CHANNEL_9
#define EMIOS_BALLS_CHANNEL_10              EMIOS_CHANNEL_10
#define EMIOS_BALLS_CHANNEL_11              EMIOS_CHANNEL_11
#define EMIOS_BALLS_CHANNEL_12              EMIOS_CHANNEL_12
#define EMIOS_BALLS_CHANNEL_13              EMIOS_CHANNEL_13
#define EMIOS_BALLS_CHANNEL_14              EMIOS_CHANNEL_14
#define EMIOS_BALLS_CHANNEL_15              EMIOS_CHANNEL_15
#define EMIOS_BALLS_CHANNEL_16              EMIOS_CHANNEL_16
#define EMIOS_BALLS_CHANNEL_17              EMIOS_CHANNEL_17
#define EMIOS_BALLS_CHANNEL_18              EMIOS_CHANNEL_18
#define EMIOS_BALLS_CHANNEL_19              EMIOS_CHANNEL_19
#define EMIOS_BALLS_CHANNEL_20              EMIOS_CHANNEL_20
#define EMIOS_BALLS_CHANNEL_21              EMIOS_CHANNEL_21
#define EMIOS_BALLS_CHANNEL_22              EMIOS_CHANNEL_22
#define EMIOS_BALLS_CHANNEL_23              EMIOS_CHANNEL_23
#define EMIOS_BALLS_CHANNEL_24              EMIOS_CHANNEL_24
#define EMIOS_BALLS_CHANNEL_25              EMIOS_CHANNEL_25
#define EMIOS_BALLS_CHANNEL_26              EMIOS_CHANNEL_26
#define EMIOS_BALLS_CHANNEL_27              EMIOS_CHANNEL_27
#define EMIOS_BALLS_CHANNEL_28              EMIOS_CHANNEL_28
#define EMIOS_BALLS_CHANNEL_29              EMIOS_CHANNEL_29
#define EMIOS_BALLS_CHANNEL_30              EMIOS_CHANNEL_30
#define EMIOS_BALLS_CHANNEL_31              EMIOS_CHANNEL_31

/**
* eMIOS channel bus define
*/
#define EMIOS_CNTBUS_A_CHANNEL_23           (uint8)EMIOS_BALLS_CHANNEL_23
#define EMIOS_CNTBUS_B_CHANNEL_0            (uint8)EMIOS_BALLS_CHANNEL_0
#define EMIOS_CNTBUS_B_CHANNEL_7            (uint8)EMIOS_BALLS_CHANNEL_7
#define EMIOS_CNTBUS_C_CHANNEL_8            (uint8)EMIOS_BALLS_CHANNEL_8
#define EMIOS_CNTBUS_C_CHANNEL_15           (uint8)EMIOS_BALLS_CHANNEL_15
#define EMIOS_CNTBUS_D_CHANNEL_16           (uint8)EMIOS_BALLS_CHANNEL_16
#define EMIOS_CNTBUS_D_CHANNEL_23           (uint8)EMIOS_BALLS_CHANNEL_23
#define EMIOS_CNTBUS_E_CHANNEL_24           (uint8)EMIOS_BALLS_CHANNEL_24
#define EMIOS_CNTBUS_E_CHANNEL_31           (uint8)EMIOS_BALLS_CHANNEL_31

#if defined (CCFC3007PT)
#define EMIOS_HANDLE_MODULE_MASK            (3U)
#endif

#if defined (CCFC3012PT)
#define EMIOS_HANDLE_MODULE_MASK            (5U)
#endif
#define EMIOS_MODU_CHAN_COMBIN(m, c)        (uint8)(((m) << EMIOS_HANDLE_MODULE_MASK) | (c))


/**
* eMIOS config bitmap define
*/
#define EMIOS_CONFIG_DATA_INITED            (0U)
/* used for select Mode for detecting */
#define EMIOS_CONFIG_DATA_MEASMODE          (1U)
/* used for EMIOS CN Register Mode */
#define EMIOS_CONFIG_DATA_OPMODE            (2U)
#define EMIOS_CONFIG_DATA_BUSCHANNEL        (3U)
#define EMIOS_CONFIG_DATA_PROPERTY          (4U)
#define EMIOS_CONFIG_DATA_DESIRED           (5U)
#define EMIOS_CONFIG_DATA_STARTTIME         (6U)
#define EMIOS_CONFIG_DATA_ENDTIME           (7U)
#define EMIOS_CONFIG_DATA_SUBMODE           (8U)
#define EMIOS_CONFIG_DATA_CLEAR             (0xFFU)

#define EMIOS_MOD_CONFIG_DATA_INITED        (0U)

/* Mode for detecting edges. */
#define EMIOS_MODE_SIGNAL_EDGE_DETECT       (uint32)0x01U
/* Mode for measuring different times between various configurable edges. */
#define EMIOS_MODE_SIGNAL_MEASUREMENT       (uint32)0x02U
/* Mode for capturing timer values on configurable edges. */
#define EMIOS_MODETIMESTAMP_WITHOUT_DMA    (uint32)0x04U
/* Mode for capturing timer values on configurable edges. */
#define EMIOS_MODE_TIMESTAMP_WITH_DMA       (uint32)0x10U
/* Mode for counting edges on configurable edges. */
#define EMIOS_MODE_EDGE_COUNTER             (uint32)0x08U

/* Signal Measurment Type */
#define EMIOS_MEAS_TYPE_LOW_TIME            (uint32)0x01U
#define EMIOS_MEAS_TYPE_HIGH_TIME           (uint32)0x02U
#define EMIOS_MEAS_TYPE_PERIOD_TIME         (uint32)0x04U
#define EMIOS_MEAS_TYPE_DUTY_CYCLE          (uint32)0x08U

#define EMIOS_COUNTER_MAX                   (uint32)0x00FFFFFFU

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* declare eMios channel callback function 
*/
typedef void (*eMios_Notification)(void);
typedef volatile uint32 vuint32;

typedef enum
{
    eMIOS_0,
#if defined(RESOURCE_SUPPORT_EMIOS1)
    eMIOS_1,
#endif
} eMIOS_Module_Types;

typedef enum
{
    ICU_EMIOS_UC_DIV0,
    ICU_EMIOS_UC_DIV1,
    ICU_EMIOS_UC_DIV2,
    ICU_EMIOS_UC_DIV3,
} eMIOS_UC_Clkdiv;

typedef enum
{
    EMIOS_SUBMODE_SINGLE,
    EMISO_SUBMODE_CONTINUE,
} eMIOS_OpSubMode;

typedef struct
{
    union
    {
        VAR(uint32, ICU_VAR) data;
        struct
        {
            volatile unsigned int inited:1;
            volatile unsigned int mode:7;
            volatile unsigned int opmode:4;
            volatile unsigned int property:4;
            volatile unsigned int bus_channel:2;
            volatile unsigned int submode:2;
            volatile unsigned int reserved:12;
        } bits;
    } config;
    /* config desire edge/pulse number. used for PEA, QDEC mode */
    VAR(uint32, ICU_VAR) desirednum;
    /* config window time. used for PEC, WPTA*/
    VAR(uint32, ICU_CONST) startime;
    VAR(uint32, ICU_CONST) endtime;
}eMIOS_Channel_ConfigData;

typedef union
{
    uint32 data;
    struct
    {
        volatile unsigned int inited:1;
    } bits;
} eMIOS_Module_ConfigData;

typedef struct
{
    VAR(eMIOS_IC_ParamType,     AUTOMATIC) sChannelParam;
    VAR(eMIOS_EdgeTrigModeType, AUTOMATIC) eTrig;
    VAR(eMIOS_UC_Clkdiv,        AUTOMATIC) ucPrescaler;
    VAR(eMios_Notification,     AUTOMATIC) pChannelNotification;
} eMIOS_Channel_Config;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

FUNC(void, ICU_CODE) eMios_Module_Init \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint16, AUTOMATIC) u16PrescalClock \
);

FUNC(void, ICU_CODE) eMios_Channel_Init \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    P2CONST(eMIOS_Channel_Config, AUTOMATIC, ICU_APPL_CONST) peMiosChannelConfig \
);

FUNC(void, ICU_CODE) eMios_Channel_DeInit \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

FUNC(void, ICU_CODE) eMios_Channel_SetActivationCondition \
( \
    VAR(uint8,                      AUTOMATIC) u8Module, \
    VAR(uint8,                      AUTOMATIC) u8Channel, \
    CONST(eMIOS_EdgeTrigModeType,   AUTOMATIC) eActivation
);

FUNC(void, ICU_CODE) eMios_Channel_EnableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

FUNC(void, ICU_CODE) eMios_Channel_DisableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) eMios_Channel_StartTimestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bDmaSupport \
);

FUNC(void, ICU_CODE) eMios_Channel_StopTimestamp \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#endif /* ICU_TIMESTAMP_API */

FUNC(uint32, ICU_CODE) eMios_Channel_GetStartAddress \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC(void, ICU_CODE) eMios_Channel_ResetEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

FUNC(void, ICU_CODE) eMios_Channel_EnableEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

FUNC(void, ICU_CODE) eMios_Channel_DisableEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

FUNC (uint32, ICU_CODE) eMios_Channel_GetEdgeNumbers \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#endif /* ICU_EDGE_COUNT_API */

FUNC(void, ICU_CODE) eMios_Ch_StartSignalMeasurement \
( \
    VAR(uint8,                    AUTOMATIC) u8Module, \
    VAR(uint8,                    AUTOMATIC) u8Channel, \
    VAR(eMIOS_EdgeTrigModeType,   AUTOMATIC) eActivation, \
    VAR(uint16,                   AUTOMATIC) nMeasProperty, \
    VAR(boolean,                  AUTOMATIC) bDmaSupport, \
    VAR(boolean,                  AUTOMATIC) bWithoutInterrupt \
);

FUNC(void, ICU_CODE) eMios_Ch_StopSignalMeasurement \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

FUNC (boolean, ICU_CODE) eMios_Channel_GetInputState \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

FUNC (boolean, ICU_CODE) eMios_Channel_GetOverflow \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
FUNC (void, ICU_CODE) eMios_Channel_SetClockMode \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32Prescaler \
);
#endif /* ICU_DUAL_CLOCK_MODE_API */

FUNC(boolean, ICU_CODE) eMios_Channel_GetInputLevel \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);

FUNC(uint32, ICU_CODE) eMios_Channel_GetCaptureRegisterValue \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);

FUNC(void, ICU_CODE) eMios_Channel_GetPulseWidth \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);

FUNC(void, ICU_CODE) eMios_Channel_ProcessCommonIrq \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);

FUNC(void, ICU_CODE) eMios_Channel_DisIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

FUNC(void, ICU_CODE) eMios_Channel_EnIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(Icu_ValueType, ICU_CODE) eMios_GetTtBuffer \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#endif

#ifdef __cplusplus
}
#endif

#endif /* ICU_EMIOS_HAL_WRAPPER_H */


