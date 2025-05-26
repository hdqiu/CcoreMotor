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
*   @file    Icu_Gtm_HAL_Wrapper.h
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

#ifndef ICU_GTM_HAL_WRAPPER_H
#define ICU_GTM_HAL_WRAPPER_H

#ifdef __cplusplus 
extern "C" {
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu.h"
#include "Gpt_Gtm_LLDriver.h"
#include "Icu_Gtm_Tim_LLDrivers.h"
#include "Icu_Gtm4_Tim_LLDrivers.h"
#include "Icu_Gtm_LLDrivers.h"
#include "Gpt_Gtm410_LLDriver.h"


/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_GTM_HAL_WRAPPER_VENDOR_ID_H                   176

#define ICU_GTM_HAL_WRAPPER_MAJOR_VER_H                   4
#define ICU_GTM_HAL_WRAPPER_MINOR_VER_H                   4
#define ICU_GTM_HAL_WRAPPER_REVISION_VER_H                0

#define ICU_GTM_HAL_WRAPPER_SW_MAJOR_VER_H                1
#define ICU_GTM_HAL_WRAPPER_SW_MINOR_VER_H                0
#define ICU_GTM_HAL_WRAPPER_SW_PATCH_VER_H                1

#if (ICU_GTM_HAL_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_HAL_WRAPPER_MAJOR_VER_H != ICU_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ICU_GTM_HAL_WRAPPER_MINOR_VER_H != ICU_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ICU_GTM_HAL_WRAPPER_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_HAL_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_HAL_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_HAL_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* declare config data indicator */
#define GTM_CONFIG_DATA_INITED              (0U)
/* used for select Mode for detecting */
#define GTM_CONFIG_DATA_MEASMODE            (1U)
/* used for ETPU CN Register Mode */
#define GTM_CONFIG_DATA_OPMODE              (2U)
#define GTM_CONFIG_DATA_DMA                 (3U)
#define GTM_CONFIG_DATA_PROPERTY            (4U)
#define GTM_CONFIG_DATA_CLEAR               (0xFFU)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#ifdef RESORUCE_SUPPORT_GTM410
#define ICU_GTM_MODULE_MAX                  (uint8)8U
#endif

#ifdef RESORUCE_SUPPORT_GTM104
#define ICU_GTM_MODULE_MAX                  (uint8)6U
#endif

#define ICU_GTM_CHANNEL_MAX                 (uint8)8U
#define ICU_GTM_HANDLE_MODULE_MASK          (uint8)(3U)
#define ICU_GTM_MODU_CHAN_COMBIN(m, c)      (uint8)(((m) << ICU_GTM_HANDLE_MODULE_MASK) | (c))

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef enum
{
    GTM_Disable = 0,
    GTM_Enable
} GTM_Enable_Type;

typedef enum
{
    ICU_GTM_TIM_EDGE_FALLING,
    ICU_GTM_TIM_EDGE_RISING,
    ICU_GTM_TIM_EDGE_BOTH
} GTM_TIM_Edge_Type;

/* Mode for detecting edges. */
#define GTM_TIM_MODE_SIGNAL_EDGE_DETECT         (uint32)0x01U
/* Mode for measuring different times between various configurable edges. */
#define GTM_TIM_MODE_SIGNAL_MEASUREMENT         (uint32)0x02U
/* Mode for capturing timer values on configurable edges. */
#define GTM_TIM_MODETIMESTAMP_NO_DMA       (uint32)0x04U
/* Mode for capturing timer values on configurable edges. */
#define GTM_TIM_MODE_TIMESTAMP_WITH_DMA         (uint32)0x10U
/* Mode for counting edges on configurable edges. */
#define GTM_TIM_MODE_EDGE_COUNTER               (uint32)0x08U

/* Signal Measurment Type */
#define GTM_TIM_MEAS_TYPE_LOW_TIME              (uint32)0x01U
#define GTM_TIM_MEAS_TYPE_HIGH_TIME             (uint32)0x02U
#define GTM_TIM_MEAS_TYPE_PERIOD_TIME           (uint32)0x04U
#define GTM_TIM_MEAS_TYPE_DUTY_CYCLE            (uint32)0x08U

typedef struct
{
    VAR(GTM_TIM_CLK_SEL_Type,                   ICU_VAR) clockSource;
    VAR(GTM_TIM_FilterMode_Type,                ICU_VAR) riseEdgeFilterMode;
    VAR(GTM_TIM_FilterCounterMode_Type,         ICU_VAR) riseCounterFilterMode;
    VAR(GTM_TIM_FilterMode_Type,                ICU_VAR) fallEdgeFilterMode;
    VAR(GTM_TIM_FilterCounterMode_Type,         ICU_VAR) fallCounterFilterMode;
    VAR(GTM_TIM_FilterCounterFrequency_Type,    ICU_VAR) filterCounterFrequency;
    VAR(uint32,                                 ICU_VAR) filterParamRiseEdge;
    VAR(uint32,                                 ICU_VAR) filterParamFallEdge;
    VAR(boolean,                                ICU_VAR) filterEnable;
    VAR(GTM_TIM_MODE_Type,                      ICU_VAR) timMode;
    VAR(GTM_TIM_GPRInput_Type,                  ICU_VAR) GPRInput;
    VAR(uint8,                                  ICU_VAR) TBU0Input;
    VAR(GTM_TIM_Edge_Type,                      ICU_VAR) startEdge;

    VAR(uint32,                                 ICU_VAR) Selection;
} Gtm_Channel_Config;

typedef union
{
	uint32 data;
    struct
    {
        volatile unsigned int inited:1;
        volatile unsigned int mode:7;
        volatile unsigned int opmode:4;
        volatile unsigned int property:4;
        volatile unsigned int dma:1;
        volatile unsigned int reserved:15;
    } bits;
} GTM_TIM_Channel_ConfigData;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Wrapper_Init \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
	P2CONST(Gtm_Channel_Config, AUTOMATIC, ICU_APPL_CONST) pGtmChannelConfig \
);

FUNC(void, ICU_CODE) Icu_Wrapper_ConfigInit \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
	P2CONST(Gtm_Channel_Config, AUTOMATIC, ICU_APPL_CONST) pGtmChannelConfig \
);

FUNC(void, ICU_CODE) Icu_Wrapper_DeInit \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId \
);

FUNC(void, ICU_CODE) Icu_Wrapper_EnIrq \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId \
);

FUNC(void, ICU_CODE) Icu_Wrapper_DisIrq \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId \
);

FUNC(void, ICU_CODE) Icu_Wrapper_SetActivationCondition \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
    VAR(GTM_TIM_Edge_Type, AUTOMATIC) eIcu_Activation \
);

FUNC(void, ICU_CODE) Icu_Wrapper_StartTimestamp
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
    VAR(boolean, AUTOMATIC) bDmaSupport \
);

FUNC(void, ICU_CODE) Icu_Wrapper_StopTimestamp \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) eIcu_GTMIsEnable \
);

FUNC(void, ICU_CODE) Icu_Wrapper_EnableEdgeCount \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId
);

FUNC(void, ICU_CODE) Icu_Wrapper_DisableEdgeCount \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId
);

FUNC(void, ICU_CODE) Icu_Wrapper_EnableEdgeDetection \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) eIcu_GTMIsEnable \
);

FUNC(void, ICU_CODE) Icu_Wrapper_DisableEdgeDetection \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) eIcu_GTMIsEnable \
);

FUNC(void, ICU_CODE) Icu_Wrapper_StartSignalMeasurement \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
    VAR(uint16,          AUTOMATIC) nMeasProperty, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelNumber \
);

FUNC(void, ICU_CODE) Icu_Wrapper_StopSignalMeasurement \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) eIcu_GTMIsEnable \
);

FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_Wrapper_GetEdgeNumbers \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId \
);

FUNC(void, ICU_CODE) Icu_Wrapper_ResetEdgeCount \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) eIcu_GTMIsEnable \
);

FUNC(Icu_InputStateType, ICU_CODE) Icu_Wrapper_GetInputState \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId \
);

FUNC(uint32, ICU_CODE) Icu_Wrapper_GetStartAddress \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId \
);

FUNC(boolean, ICU_CODE) Icu_Wrapper_GetOverFlow \
( \
    VAR(Icu_Module_Type, AUTOMATIC) u8Icu_ModuleId, \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_ChannelId \
);

FUNC(boolean, ICU_CODE) Gtm_Channel_GetInputLevel \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);

FUNC(uint32, ICU_CODE) Gtm_Channel_GetGPR0Value \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
);
FUNC(void, ICU_CODE) Icu_Gtm_ProcessInterrupt \
( \
    VAR(GTM_TIM_Type,       AUTOMATIC)ModuleId, \
    VAR(Icu_ChannelType,    AUTOMATIC) Channel \
);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ICU_GTM_HAL_WRAPPER_H */


