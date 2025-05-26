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
*   @file    Icu_Gtm_Tim_LLDrivers.h
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
#ifndef ICU_GTM4_TIM_LLDRIVERS_H
#define ICU_GTM4_TIM_LLDRIVERS_H

#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "derivative.h"
#include "status.h"
#include "Compiler.h"
#include "Gpt_Gtm410_LLDriver.h"
#ifdef RESORUCE_SUPPORT_GTM410
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_H                   176

#define ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_H                   4
#define ICU_GTM_TIM_LLDRIVERS_MINOR_VER_H                   4
#define ICU_GTM_TIM_LLDRIVERS_REVISION_VER_H                0

#define ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_H                1
#define ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_H                0
#define ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_H                1

#if (ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_H != GPT_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_H != GPT_AR_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_MINOR_VER_H != GPT_AR_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_REVISION_VER_H != GPT_AR_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_H != GPT_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_H != GPT_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_H != GPT_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef enum
{
    FLT_CNT_CMU_CLK0,
    FLT_CNT_CMU_CLK1,
    FLT_CNT_CMU_CLK6,
    FLT_CNT_CMU_CLK7
} Filter_CNT_Freq_Type;

typedef enum
{
    TBU_TS0_23_0,
    TBU_TS0_26_3
} GTM_TIME_TBU_TS0_Type;

typedef volatile struct _GTM_TIM st_GTM_TIM_tag;

#define GTM4_TIM_DET_ERR(x)                         DEV_ASSERT(x)

#ifdef RESORUCE_SUPPORT_GTM410_2CLS
#define GTM4_TIM_INSTANCE_NUM                       (2U)
#endif
#ifdef RESORUCE_SUPPORT_GTM410_8CLS
#define GTM4_TIM_INSTANCE_NUM                       (8U)
#endif

#define GTM4_TIM_CHANNEL_NUM                        (8U)

#define GTM4_TIM_RST_RST_CH0_OFF                    (0u)



typedef enum
{
    Ch_0_H = 0,
    Ch_1_H,
    Ch_2_H,
    Ch_3_H,
    Ch_4_H,
    Ch_5_H,
    Ch_6_H,
    Ch_7_H,
    Ch_8_H,
    Ch_9_H,
    Ch_A_H,
    Ch_B_H,
    Ch_C_H,
    Ch_D_H,
    Ch_E_H,
    Ch_F_H
} GTM_TIM_Channel_Input_Selection_Type;

typedef enum
{
    GTM_TIM0 = 0,
    GTM_TIM1,
    GTM_TIM2,
    GTM_TIM3,
    GTM_TIM4,
    GTM_TIM5,
    GTM_TIM6,
	GTM_TIM7,
} GTM_TIM_Type;

typedef enum
{
    GTM_TIM_CH0 = 0,
    GTM_TIM_CH1,
    GTM_TIM_CH2,
    GTM_TIM_CH3,
    GTM_TIM_CH4,
    GTM_TIM_CH5,
    GTM_TIM_CH6,
    GTM_TIM_CH7
} GTM_TIM_Channel_Type;

typedef enum
{
    TBU_TS0  = 0,
    TBU_TS1,
    TBU_TS2,
    CNT,
} GTM_TIM_GPRInput_Type;

typedef enum
{
    TIM_MODE_TPWM = 0,
    TIM_MODE_TPIM,
    TIM_MODE_TIEM,
    TIM_MODE_TIPM,
    TIM_MODE_TBCM,
    TIM_MODE_TGPS,
	TIM_MODE_TSSM,
} GTM_TIM_MODE_Type;

typedef enum
{
    TIM_TCS_CMU_CLK0 = 0,
    TIM_TCS_CMU_CLK1,
    TIM_TCS_CMU_CLK2,
    TIM_TCS_CMU_CLK3,
    TIM_TCS_CMU_CLK4,
    TIM_TCS_CMU_CLK5,
    TIM_TCS_CMU_CLK6,
    TIM_TCS_CMU_CLK7
} GTM_TIM_TimeoutClock_Type;

typedef enum
{
    TIM_Timeout_Disabled = 0,
    TIM_Timeout_Enabled_Rising,
    TIM_Timeout_Enabled_Falling,
    TIM_Timeout_Enabled_Both
} GTM_TIM_TimeoutControl_Type;

typedef enum
{
    TIM_CLK_SEL_CMU_CLK0 = 0,
    TIM_CLK_SEL_CMU_CLK1,
    TIM_CLK_SEL_CMU_CLK2,
    TIM_CLK_SEL_CMU_CLK3,
    TIM_CLK_SEL_CMU_CLK4,
    TIM_CLK_SEL_CMU_CLK5,
    TIM_CLK_SEL_CMU_CLK6,
    TIM_CLK_SEL_CMU_CLK7
} GTM_TIM_CLK_SEL_Type;

typedef enum
{
    TIM_Up_Down_Counter = 0,
    TIM_Hold_Counter
} GTM_TIM_FilterCounterMode_Type;

typedef enum
{
    TIM_Immediate_Propagation = 0,
    TIM_Individual_Glitch
} GTM_TIM_FilterMode_Type;

typedef enum
{
    TIM_FLT_CNT_FRQ_CMU_CLK0 = 0,
    TIM_FLT_CNT_FRQ_CMU_CLK1,
    TIM_FLT_CNT_FRQ_CMU_CLK6,
    TIM_FLT_CNT_FRQ_CMU_CLK7
} GTM_TIM_FilterCounterFrequency_Type;

typedef enum
{
    TIM_IRQ_GLITCHDET = 0,
    TIM_IRQ_TODET,
    TIM_IRQ_GPROFL,
    TIM_IRQ_CNTOFL,
    TIM_IRQ_ECNTOFL,
    TIM_IRQ_NEWVAL
} GTM_TIM_Interrupt_Type;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Ch_GetGPR0Param \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
);

FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Ch_GetGPR1Parameter \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
);


FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelectClkSource \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_CLK_SEL_Type, AUTOMATIC) ClockSource \
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelFLCountFall \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterCounterMode_Type, AUTOMATIC) FilterCounterMode \
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelFLCountRise \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterCounterMode_Type, AUTOMATIC) FilterCounterMode \
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_ChSelFLModeFallEdge \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterMode_Type, AUTOMATIC) FilterMode \
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_ChSelFLModeRiseEdge \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterMode_Type, AUTOMATIC) FilterMode \
); 


FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableFL \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelectGPRInput \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_GPRInput_Type, AUTOMATIC) GPR0, \
    VAR(GTM_TIM_GPRInput_Type, AUTOMATIC) GPR1 \
);


FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SetChannelMode \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_MODE_Type, AUTOMATIC) TIM_MODE \
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableChannel \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
);

FUNC(uint8, ICU_CODE) GTM_TIM_LLD_Ch_GetInterruptFlag \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt \
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_ClearIntcFlag \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt \
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntc \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
);


FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_RstChannel \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SetFLCounFreq \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,  \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TIM_FilterCounterFrequency_Type, AUTOMATIC) FilterCounterFrequency \
);

FUNC(uint32_t, ICU_CODE) GTM_TIM_LLD_Channel_GetGPR0EdgeCounter \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,  \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);

FUNC(status_t, ICU_CODE) GTM_LLD_SetTimsel \
( \
	    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,  \
	    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,  \
        VAR(GTM_TIM_Channel_Input_Selection_Type, AUTOMATIC) TIMIN_SEL  \
);
//---------------------------------------------------------------------------------------------------------------------------------------
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntcEN
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GPT_GTM_Status_Type, AUTOMATIC) u32Icu_IsEnable
);

FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetFPFE
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(uint32, AUTOMATIC) parameter
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntcNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GPT_GTM_Status_Type, AUTOMATIC) u32Icu_IsEnable
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ClearInterruptNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_CTRL_ISL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_SingleLevel
);

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ActivationEdge
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_IsEnable
);

FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetTBUSel
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GTM_TIME_TBU_TS0_Type, AUTOMATIC) type
);

FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Channel_GetAddress
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
);

FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetFPRE
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(uint32, AUTOMATIC) parameter
);





#endif /* ICU_GTM_TIM_LLDRIVERS_H */

#endif /* RESORUCE_SUPPORT_GTM410 */

