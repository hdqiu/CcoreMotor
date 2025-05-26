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
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Pwm_HAL_Wrapper.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

#ifndef PWM_HAL_WRAPPER_H
#define PWM_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm.h"

#define PWM_HAL_WRA_H_VENDOR_ID                      176
#define PWM_HAL_WRA_H_AR_REL_MAJOR_VER               4
#define PWM_HAL_WRA_H_AR_REL_MINOR_VER               4
#define PWM_HAL_WRA_H_AR_REL_REV_VER                 0
#define PWM_HAL_WRA_H_SW_MAJOR_VER                   1
#define PWM_HAL_WRA_H_SW_MINOR_VER                   0
#define PWM_HAL_WRA_H_SW_PATCH_VER                   1

#if (PWM_HAL_WRA_H_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_H_VENDOR_ID "
#endif
#if (PWM_HAL_WRA_H_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (PWM_HAL_WRA_H_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_H_AR_REL_MINOR_VER "
#endif
#if (PWM_HAL_WRA_H_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_H_AR_REL_REV_VER "
#endif
#if (PWM_HAL_WRA_H_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_H_SW_MAJOR_VER "
#endif
#if (PWM_HAL_WRA_H_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_H_SW_MINOR_VER "
#endif
#if (PWM_HAL_WRA_H_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_H_SW_PATCH_VER "
#endif

#if (defined(CCFC3007PT) || defined(CCFC3008PT) || defined(CCFC3007BC))
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetEtpuOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
#endif
FUNC(void, PWM_CODE) Pwm_Wrapper_Init \
( \
    P2CONST(Pwm_ChConfigsType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfigs \
);
FUNC(void, PWM_CODE) Pwm_Wrapper_DeInit \
(
    P2CONST(Pwm_ChConfigsType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfigs \
);
FUNC(void, PWM_CODE) Pwm_Wrapper_SetPeriodAndDuty \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
); 
FUNC(void, PWM_CODE) Pwm_Wrapper_SetDutyCycle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
);
FUNC(void, PWM_CODE) Pwm_Wrapper_SetOutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
FUNC(void, PWM_CODE) Pwm_Wrapper_DisableNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
FUNC(void, PWM_CODE) Pwm_Wrapper_EnableNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) ePwm_Notification \
);
FUNC(Pwm_ChConfigsType*, PWM_CODE) Pwm_Pwm_Wrapper_Get_pChConfigs(void);
FUNC(uint8*, PWM_CODE) Pwm_Wrapper_Get_ChannelNotification(void);
FUNC(uint8*, PWM_CODE) Pwm_Wrapper_Get_ChannelNotifiClass(void);
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetEmiosOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
FUNC(Pwm_DutycycleType, PWM_CODE) Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelType id);
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetTomOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetAtomOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
FUNC(uint8, PWM_CODE) Pwm_Wrapper_Check_DutyCycle
(
    VAR(Pwm_ChannelType, AUTOMATIC) id,
    VAR(uint16, AUTOMATIC) u16Pwm_Duty
);
FUNC(uint8, PWM_CODE) Pwm_Wrapper_Check_PeriodAndDuty
(
    VAR(Pwm_ChannelType, AUTOMATIC) id, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
);
FUNC(uint32, PWM_CODE) Pwm_Wrapper_Get_MaxDutycycle
(
    VAR(Pwm_ChannelType, AUTOMATIC) id \
);
#ifdef __cplusplus
}
#endif

#endif


