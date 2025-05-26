

/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3012PT
* DESCRIPTION : CCFC3012PT GTM TOM low level drivers h file
* HISTORY     : Initial version
* @file     gtm4_tom_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
#ifndef PWM_LLDRIVER_H_
#define PWM_LLDRIVER_H_

 /*PRQA S 0777,0779 EOF*/
#ifndef GTM4_TOM_LLD_H_
#define GTM4_TOM_LLD_H_

#ifdef __cplusplus
extern "C"{
#endif

#if (defined(CCFC3007PT) || defined (CCFC3008PT) || defined (CCFC3012PT))

#include "derivative.h"
#include "status.h"
#include "mcal.h"
#include "Gpt_Gtm_LLDriver.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"
#include "Gpt_Gtm410_LLDriver.h"

#define PWM_LLD_H_VENDOR_ID                      176
#define PWM_LLD_H_AR_REL_MAJOR_VER               4
#define PWM_LLD_H_AR_REL_MINOR_VER               4
#define PWM_LLD_H_AR_REL_REV_VER                 0
#define PWM_LLD_H_SW_MAJOR_VER                   1
#define PWM_LLD_H_SW_MINOR_VER                   0
#define PWM_LLD_H_SW_PATCH_VER                   1

#define GTM4_TOM_DET_ERR(x)                         DEV_ASSERT(x)

#ifdef RESORUCE_SUPPORT_GTM410_2CLS
#define GTM4_TOM_INSTANCE_NUM                       (2U)
#endif

#ifdef RESORUCE_SUPPORT_GTM410_8CLS
#define GTM4_TOM_INSTANCE_NUM                       (6U)
#endif

#define GTM4_TOM_CHANNEL_NUM                        (16U)

#define GTM4_TOM_TGC_GLB_CTRL_UPEN_CTRL0_OFF        (16u)
#define GTM4_TOM_TGC_GLB_CTRL_RST_CH0_OFF           (8u)
#define GTM4_TOM_TGC_FUPD_CTRL_RSTCN0_CH0_OFF       (16u)
#define GTM4_TOM_TGC_FUPD_CTRL_FUPD_CTRL0_OFF       (0u)
#define GTM4_TOM_TGC_INT_TRIG_INT_TRIG0_OFF         (0u)
#define GTM4_TOM_TGC_ENDIS_CTRL_ENDIS_CTRL0_OFF     (0u)
#define GTM4_TOM_TGC_ENDIS_STAT_ENDIS_STAT0_OFF     (0u)
#define GTM4_TOM_TGC_OUTEN_CTRL_OUTEN_CTRL0_OFF     (0u)
#define GTM4_TOM_TGC_OUTEN_STAT_OUTEN_STAT0_OFF     (0u)

#if (PWM_LLD_H_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_LLD_H_VENDOR_ID "
#endif
#if (PWM_LLD_H_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (PWM_LLD_H_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_H_AR_REL_MINOR_VER "
#endif
#if (PWM_LLD_H_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_LLD_H_AR_REL_REV_VER "
#endif
#if (PWM_LLD_H_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_H_SW_MAJOR_VER "
#endif
#if (PWM_LLD_H_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_H_SW_MINOR_VER "
#endif
#if (PWM_LLD_H_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_LLD_H_SW_PATCH_VER "
#endif

#if (defined(CCFC3007PT) || defined (CCFC3008PT) ||defined (CCFC3012PT))

typedef enum
{
    GTM_TOM0 = 0,
    GTM_TOM1,
    GTM_TOM2,
	GTM_TOM3,
	GTM_TOM4,
	GTM_TOM5
}GTM_TOM_Type;

typedef enum
{
    GTM_TOM_CH0 = 0,
    GTM_TOM_CH1,
    GTM_TOM_CH2,
    GTM_TOM_CH3,
    GTM_TOM_CH4,
    GTM_TOM_CH5,
    GTM_TOM_CH6,
    GTM_TOM_CH7,
    GTM_TOM_CH8,
    GTM_TOM_CH9,
    GTM_TOM_CH10,
    GTM_TOM_CH11,
    GTM_TOM_CH12,
    GTM_TOM_CH13,
    GTM_TOM_CH14,
    GTM_TOM_CH15
}GTM_TOM_Channel_Type;

typedef enum
{
    TOM_TRIGOUT_X_1 = 0,
    TOM_TRIGOUT_CCU0
}GTM_TOM_TriggerOutput_Type;

typedef enum
{
    TOM_RST_CCU0_CM0 = 0,
    TOM_RST_CCU0_TRIG
}GTM_TOM_CCU0ResetSource_Type;

typedef enum{
	TOM_CLK_SRC_CMU_FXCLK0 = 0,
	TOM_CLK_SRC_CMU_FXCLK1,
	TOM_CLK_SRC_CMU_FXCLK2,
	TOM_CLK_SRC_CMU_FXCLK3,
	TOM_CLK_SRC_CMU_FXCLK4,
	TOM_CLK_SRC_NO_CMU_FXCLK,
	TOM_CLK_SRC_RESOLUTION_0 = 12,
	TOM_CH_TRIGOUT_X_1,
	TOM_EXIT_TRIGIN_X
}GTM_TOM_ClockSource_Type;

typedef enum
{
    TOM_SL_HIGH = 0,
    TOM_SL_LOW
}GTM_TOM_SignalLevel_Type;

typedef enum
{
    TOM_TBU_TS0 = 0,
    TOM_TBU_TS1,
    TOM_TBU_TS2,
    TOM_TBU_TS3
}GTM_TOM_TimeBase_Type;

typedef enum
{
    TOM_IRQ_CCU0TC = 0,
    TOM_IRQ_CCU1TC
}GTM_TOM_Interrupt_Type;


FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableGatedCounterMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableSPEMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableOneShotMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectTriggerOutput \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_TriggerOutput_Type, AUTOMATIC) ePwm_TriggerOutput \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectCCU0ResetSource \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_CCU0ResetSource_Type, AUTOMATIC) ePwm_CCU0ResetSource \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectClockSource
(
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_TOM_ClockSource_Type, AUTOMATIC) ePwm_ClockSource \
);
FUNC(GTM_TOM_ClockSource_Type, PWM_CODE) GTM_TOM_LLD_Channel_GetClockSource \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectSignalLevel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_SignalLevel_Type, AUTOMATIC) ePwm_SignalLevel \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetShadowRegister \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR0, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR1 \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetCompareRegister \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_CM0, \
    VAR(uint16, AUTOMATIC) u16Pwm_CM1 \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetCounter \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_CN0 \
);
FUNC(uint16, PWM_CODE) GTM_TOM_LLD_Channel_GetCounter \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
);
FUNC(uint8, PWM_CODE) GTM_TOM_LLD_Channel_GetOutputLevel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
);
FUNC(uint8, PWM_CODE) GTM_TOM_LLD_Channel_GetInterruptFlag \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_ClearInterruptFlag \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableInterrupt \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);

FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_ForceInt \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
);

FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectInterruptMode\
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_InterruptMode_Type, AUTOMATIC) ePwm_InterruptMode \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableUpdate \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_ResetChannel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC0_HostTrigger \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC1_HostTrigger \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC0_SelectTimeBase \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC1_SelectTimeBase \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC0_SetActionTime \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC1_SetActionTime \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableForceUpdateCN0Reset \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableForceUpdate \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableInternalTrigger \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableUpdateValue \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableChannel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableOutUpdateValue \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableOut \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);

#ifdef __cplusplus
}
#endif

#endif /* GTM4_TOM_LLD_H_ */

#endif

/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3012PT
* DESCRIPTION : CCFC3012PT GTM ATOM low level drivers h file
* HISTORY     : Initial version
* @file     gtm4_atom_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/

#ifndef GTM4_ATOM_LLD_H_
#define GTM4_ATOM_LLD_H_

#ifdef __cplusplus
extern "C"{
#endif

 /*PRQA S 0654,0777,0779 EOF*/

#if (defined(CCFC3007PT) || defined (CCFC3008PT) || defined (CCFC3012PT))

#define GTM4_ATOM_DET_ERR(x)                         DEV_ASSERT(x)

#ifdef RESORUCE_SUPPORT_GTM410_2CLS
#define GTM4_ATOM_INSTANCE_NUM                       (2U)
#endif

#ifdef RESORUCE_SUPPORT_GTM410_8CLS
#define GTM4_ATOM_INSTANCE_NUM                       (8U)
#endif

#define GTM4_ATOM_CHANNEL_NUM                        (8U)

#define GTM4_ATOM_AGC_GLB_CTRL_UPEN_CTRL0_OFF        (16u)
#define GTM4_ATOM_AGC_GLB_CTRL_RST_CH0_OFF           (8u)
#define GTM4_ATOM_AGC_FUPD_CTRL_RSTCN0_CH0_OFF       (16u)
#define GTM4_ATOM_AGC_FUPD_CTRL_FUPD_CTRL0_OFF       (0u)
#define GTM4_ATOM_AGC_INT_TRIG_INT_TRIG0_OFF         (0u)
#define GTM4_ATOM_AGC_ENDIS_CTRL_ENDIS_CTRL0_OFF     (0u)
#define GTM4_ATOM_AGC_ENDIS_STAT_ENDIS_STAT0_OFF     (0u)
#define GTM4_ATOM_AGC_OUTEN_CTRL_OUTEN_CTRL0_OFF     (0u)
#define GTM4_ATOM_AGC_OUTEN_STAT_OUTEN_STAT0_OFF     (0u)

typedef enum
{
    GTM_ATOM0 = 0U,
    GTM_ATOM1,
    GTM_ATOM2,
    GTM_ATOM3,
    GTM_ATOM4,
	GTM_ATOM5,
	GTM_ATOM6,
	GTM_ATOM7
}GTM_ATOM_Type;

typedef enum
{
    GTM_ATOM_CH0 = 0U,
    GTM_ATOM_CH1,
    GTM_ATOM_CH2,
    GTM_ATOM_CH3,
    GTM_ATOM_CH4,
    GTM_ATOM_CH5,
    GTM_ATOM_CH6,
    GTM_ATOM_CH7
}GTM_ATOM_Channel_Type;

typedef enum
{
    ATOM_TRIGOUT_X_1 = 0U,
    ATOM_TRIGOUT_CCU0
}GTM_ATOM_TriggerOutput_Type;

typedef enum
{
    ATOM_RST_CCU0_CM0 = 0U,
    ATOM_RST_CCU0_TRIG
}GTM_ATOM_ResetSource_Type;

typedef enum
{
    ATOM_CLK_SRC_CMU_CLK0 = 0U,
    ATOM_CLK_SRC_CMU_CLK1,
    ATOM_CLK_SRC_CMU_CLK2,
    ATOM_CLK_SRC_CMU_CLK3,
    ATOM_CLK_SRC_CMU_CLK4,
    ATOM_CLK_SRC_CMU_CLK5,
    ATOM_CLK_SRC_CMU_CLK6,
    ATOM_CLK_SRC_CMU_CLK7,
    ATOM_CLK_SRC_NO_CMU_CLK
}GTM_ATOM_ClockSource_Type;

typedef enum
{
    ATOM_SL_HIGH = 0U,
    ATOM_SL_LOW
}GTM_ATOM_SignalLevel_Type;

typedef enum
{
    ATOM_CMP_GreaterOrEqual  = 0U,
    ATOM_CMP_LessOrEqual
}GTM_ATOM_CompareStrategy_Type;

typedef enum
{
    ATOM_TB12_SELTS1 = 0U,
    ATOM_TB12_SELTS2
}GTM_ATOM_TB12TimeBase_Type;

typedef enum
{
    ATOM_MODE_SOMI = 0U,
    ATOM_MODE_SOMC,
    ATOM_MODE_SOMP,
    ATOM_MODE_SOMS
}GTM_ATOM_Mode_Type;

typedef enum
{
    ATOM_TBU_TS0 = 0U,
    ATOM_TBU_TS1,
    ATOM_TBU_TS2,
    ATOM_TBU_TS3
}GTM_ATOM_TimeBase_Type;

typedef enum
{
    ATOM_IRQ_CCU0TC = 0U,
    ATOM_IRQ_CCU1TC
}GTM_ATOM_Interrupt_Type;

FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetReadAddress \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_ReadAddress0, \
    VAR(uint16, AUTOMATIC) u16Pwm_ReadAddress1 \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableARUBlockMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableOneShotMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectTriggerOutput \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_TriggerOutput_Type, AUTOMATIC) ePwm_TriggerOutput \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectCCU0ResetSource \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_ResetSource_Type, AUTOMATIC) ePwm_ResetSource \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectClockSource \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_ClockSource_Type, AUTOMATIC) ePwm_ClockSource \
);
FUNC(GTM_ATOM_ClockSource_Type, PWM_CODE) GTM_ATOM_LLD_Channel_GetClockSource \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectSignalLevel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_SignalLevel_Type, AUTOMATIC) ePwm_SignalLevel \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectCompareStrategy \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_CompareStrategy_Type, AUTOMATIC) ePwm_CompareStrategy \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetACBbits \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_ACBbits \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableARU \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectTB12TimeBase \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_TB12TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectATOMMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Mode_Type, AUTOMATIC) ePwm_Mode \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetShadowRegister \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR0, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR1 \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetCompareRegister \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_CM0, \
    VAR(uint32, AUTOMATIC) u32Pwm_CM1 \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetCounter \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_CN0 \
);
FUNC(uint8, PWM_CODE) GTM_ATOM_LLD_Channel_GetOutputLevel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn \
);
FUNC(uint8, PWM_CODE) GTM_ATOM_LLD_Channel_GetInterruptFlag \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_ClearInterruptFlag \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableInterrupt \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_ForceInterrupt \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectInterruptMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_InterruptMode_Type, AUTOMATIC) ePwm_InterruptMode \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableUpdate \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_ResetChannel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_AGC_HostTrigger \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_AGC_SelectTimeBase \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn,
    VAR(GTM_ATOM_TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_AGC_SetActionTime \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn,
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableForceUpdateCN0Reset \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableForceUpdate \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableInternalTrigger \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableUpdateValue \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableChannel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableOutUpdateValue \
( 
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableOut \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
);

#ifdef __cplusplus
}
#endif

#endif /* LLD_INC_GTM_ATOM_LLD_H_ */

/********************************** add **********************************/

#ifndef PWM_LLDRIVER_H
#define PWM_LLDRIVER_H

#ifdef __cplusplus
extern "C"{
#endif

#if (defined(CCFC3007PT) || defined (CCFC3008PT) || defined (CCFC3012PT))

FUNC(status_t, PWM_CODE) SetTomChannelSL \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_Val \
);
FUNC(status_t, PWM_CODE) SetAtomChannelSL \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_Val \
);
FUNC(status_t, PWM_CODE) SetTomChannelCM0 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
);
FUNC(status_t, PWM_CODE) SetTomChannelCM1 \
(
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
);
FUNC(status_t, PWM_CODE) SetAtomChannelCM0 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
);
FUNC(status_t, PWM_CODE) SetAtomChannelCM1 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetShadowRegister0 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint16, AUTOMATIC, PWM_APPL_DATA) pPwm_SR0 \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetShadowRegister1 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint16, AUTOMATIC, PWM_APPL_DATA) pPwm_SR1 \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetShadowRegister0 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_SR0 \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetShadowRegister1 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn,\
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_SR1 \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetEnableOut \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetEnableOut \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_IsEnable \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetShadowRegister0 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR0 \
);
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetShadowRegister1 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR1 \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetShadowRegister0 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR0 \
);
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetShadowRegister1 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR1 \
);
FUNC(Std_ReturnType, PWM_CODE) GTM_ATOM_LLD_HresEn(void);
FUNC(status_t, PWM_CODE) GTM_LLD_SetToutSel \
( \
    VAR(uint32, AUTOMATIC) u32Pwm_TOUT_NUM, \
    VAR(uint32, AUTOMATIC) u32Pwm_TOUT_SEL \
);
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif

#endif

#endif

