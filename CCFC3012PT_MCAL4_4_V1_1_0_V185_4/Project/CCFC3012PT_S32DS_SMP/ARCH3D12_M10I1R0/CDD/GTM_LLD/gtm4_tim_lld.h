
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM TIM low level drivers h file
* HISTORY     : Initial version
* @file     gtm_tim_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0777,0779,3472 EOF*/
#ifndef GTM4_TIM_LLD_H_
#define GTM4_TIM_LLD_H_
#include "derivative.h"
#ifdef RESORUCE_SUPPORT_GTM410

#include "status.h"
#include "gtm4_lld.h"

#define GTM4_TIM_DET_ERR(x)                         DEV_ASSERT(x)

#ifdef RESORUCE_SUPPORT_GTM410_2CLS
#define GTM4_TIM_INSTANCE_NUM                       (2U)
#endif
#ifdef RESORUCE_SUPPORT_GTM410_8CLS
#define GTM4_TIM_INSTANCE_NUM                       (8U)
#endif

#define GTM4_TIM_CHANNEL_NUM                        (8U)

#define GTM4_TIM_RST_RST_CH0_OFF                    (0u)

typedef enum{
	GTM_TIM0 = 0,
	GTM_TIM1,
	GTM_TIM2,
	GTM_TIM3,
	GTM_TIM4,
	GTM_TIM5,
	GTM_TIM6,
	GTM_TIM7,
}GTM_TIM_Type;

typedef enum{
	GTM_TIM_CH0 = 0,
	GTM_TIM_CH1,
	GTM_TIM_CH2,
	GTM_TIM_CH3,
	GTM_TIM_CH4,
	GTM_TIM_CH5,
	GTM_TIM_CH6,
	GTM_TIM_CH7
}GTM_TIM_Channel_Type;


typedef enum{
	TBU_TS0  = 0,
	TBU_TS1,
	TBU_TS2,
	CNT,
}GTM_TIM_GPRInput_Type;

typedef enum{
	TIM_MODE_TPWM = 0,
	TIM_MODE_TPIM,
	TIM_MODE_TIEM,
	TIM_MODE_TIPM,
	TIM_MODE_TBCM,
	TIM_MODE_TGPS,
	TIM_MODE_TSSM,
}GTM_TIM_MODE_Type;

typedef enum{
	TIM_TCS_CMU_CLK0 = 0,
	TIM_TCS_CMU_CLK1,
	TIM_TCS_CMU_CLK2,
	TIM_TCS_CMU_CLK3,
	TIM_TCS_CMU_CLK4,
	TIM_TCS_CMU_CLK5,
	TIM_TCS_CMU_CLK6,
	TIM_TCS_CMU_CLK7
}GTM_TIM_TimeoutClock_Type;

typedef enum{
	TIM_Timeout_Disabled = 0,
	TIM_Timeout_Enabled_Rising,
	TIM_Timeout_Enabled_Falling,
	TIM_Timeout_Enabled_Both
}GTM_TIM_TimeoutControl_Type;

typedef enum{
	TIM_CLK_SEL_CMU_CLK0 = 0,
	TIM_CLK_SEL_CMU_CLK1,
	TIM_CLK_SEL_CMU_CLK2,
	TIM_CLK_SEL_CMU_CLK3,
	TIM_CLK_SEL_CMU_CLK4,
	TIM_CLK_SEL_CMU_CLK5,
	TIM_CLK_SEL_CMU_CLK6,
	TIM_CLK_SEL_CMU_CLK7
}GTM_TIM_CLK_SEL_Type;

typedef enum{
	TIM_Up_Down_Counter = 0,
	TIM_Hold_Counter
}GTM_TIM_FilterCounterMode_Type;

typedef enum{
	TIM_Immediate_Propagation = 0,
	TIM_Individual_Glitch
}GTM_TIM_FilterMode_Type;

typedef enum{
	TIM_FLT_CNT_FRQ_CMU_CLK0 = 0,
	TIM_FLT_CNT_FRQ_CMU_CLK1,
	TIM_FLT_CNT_FRQ_CMU_CLK6,
	TIM_FLT_CNT_FRQ_CMU_CLK7
}GTM_TIM_FilterCounterFrequency_Type;

typedef enum{
	TIM_IRQ_GLITCHDET = 0,
	TIM_IRQ_TODET,
	TIM_IRQ_GPROFL,
	TIM_IRQ_CNTOFL,
	TIM_IRQ_ECNTOFL,
	TIM_IRQ_NEWVAL,
}GTM_TIM_Interrupt_Type;

#define CH_IRQ_NOTIFY_MASK_GLITCHDET                ((uint32_t)(0x00000020U))
#define CH_IRQ_NOTIFY_MASK_TODET                    ((uint32_t)(0x00000010U))
#define CH_IRQ_NOTIFY_MASK_GPROFL                   ((uint32_t)(0x00000008U))
#define CH_IRQ_NOTIFY_MASK_CNTOFL                   ((uint32_t)(0x00000004U))
#define CH_IRQ_NOTIFY_MASK_ECNTOFL                  ((uint32_t)(0x00000002U))
#define CH_IRQ_NOTIFY_MASK_NEWVAL                   ((uint32_t)(0x00000001U))

uint8_t GTM_TIM_LLD_Channel_GetGPR0EdgeCounter_lld(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

uint32_t GTM_TIM_LLD_Channel_GetGPR0Parameter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

uint8_t GTM_TIM_LLD_Channel_GetGPR1EdgeCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

uint32_t GTM_TIM_LLD_Channel_GetGPR1Parameter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

uint32_t GTM_TIM_LLD_Channel_GetCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

uint8_t GTM_TIM_LLD_Channel_GetEdgeCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

uint8_t GTM_TIM_LLD_Channel_GetCNTSEdgeCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

uint32_t GTM_TIM_LLD_Channel_GetCNTSShadowCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

status_t GTM_TIM_LLD_Channel_SetCNTSShadowCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,uint32_t CNTS);

uint8_t GTM_TIM_LLD_Channel_GetTimeoutValue(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

status_t GTM_TIM_LLD_Channel_SelectTimeoutClock(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_TimeoutClock_Type TimeoutClock);

status_t GTM_TIM_LLD_Channel_SetTimeout(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,uint8_t Timeout);

status_t GTM_TIM_LLD_Channel_SetFilterParameterRisingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,uint32_t FilterParameter);

status_t GTM_TIM_LLD_Channel_SetFilterParameterFallingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,uint32_t FilterParameter);

status_t GTM_TIM_LLD_Channel_SelectTimeoutControl(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_TimeoutControl_Type TimeoutControl);

status_t GTM_TIM_LLD_Channel_SelectClockSource(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_CLK_SEL_Type ClockSource);

status_t GTM_TIM_LLD_Channel_SelectFilterCounterModeFallingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterCounterMode_Type FilterCounterMode);

status_t GTM_TIM_LLD_Channel_SelectFilterCounterModeRisingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterCounterMode_Type FilterCounterMode);

status_t GTM_TIM_LLD_Channel_SelectFilterModeFallingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterMode_Type FilterMode);

status_t GTM_TIM_LLD_Channel_SelectFilterModeRisingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterMode_Type FilterMode);

status_t GTM_TIM_LLD_Channel_IsEnableExternalCapture(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TIM_LLD_Channel_SetFilterCounterFrequency(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterCounterFrequency_Type FilterCounterFrequency);

status_t GTM_TIM_LLD_Channel_IsEnableFilter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TIM_LLD_Channel_SelectGPRInput(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_GPRInput_Type GPR0,GTM_TIM_GPRInput_Type GPR1);

status_t GTM_TIM_LLD_Channel_IsEnableARU(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TIM_LLD_Channel_IsEnableOneShotMode(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TIM_LLD_Channel_SetChannelMode(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_MODE_Type TIM_MODE);

status_t GTM_TIM_LLD_Channel_IsEnableChannel(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

uint8_t GTM_TIM_LLD_Channel_GetInterruptFlag(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_Interrupt_Type Interrupt);

status_t GTM_TIM_LLD_Channel_ClearInterruptFlag(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_Interrupt_Type Interrupt);

status_t GTM_TIM_LLD_Channel_IsEnableInterrupt(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_Interrupt_Type Interrupt,GTM_IsEnable_Type IsEnable);

status_t GTM_TIM_LLD_Channel_ForceInterrupt(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_Interrupt_Type Interrupt);

status_t GTM_TIM_LLD_Channel_SelectInterruptMode(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_InterruptMode_Type InterruptMode);

status_t GTM_TIM_LLD_Channel_ResetChannel(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn);

status_t GTM_LLD_SetTimsel_lld(GTM_TIM_Type GTM_TIMn, GTM_TIM_Channel_Type CHn, uint32_t TIMIN_SEL);

#endif /* RESORUCE_SUPPORT_GTM410 */
#endif /* GTM4_TIM_LLD_H_ */

