#ifndef PWM_H
#define PWM_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"
#include "Pwm_Cfg.h"

#define PWM_H_VENDOR_ID                      176
#define PWM_H_AR_REL_MAJOR_VER               4
#define PWM_H_AR_REL_MINOR_VER               4
#define PWM_H_AR_REL_REV_VER                 0
#define PWM_H_SW_MAJOR_VER                   1
#define PWM_H_SW_MINOR_VER                   0
#define PWM_H_SW_PATCH_VER                   1

#if (PWM_H_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_H_VENDOR_ID "
#endif
#if (PWM_H_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_H_AR_REL_MAJOR_VER "
#endif
#if (PWM_H_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_H_AR_REL_MINOR_VER "
#endif
#if (PWM_H_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_H_AR_REL_REV_VER "
#endif
#if (PWM_H_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_H_SW_MAJOR_VER "
#endif
#if (PWM_H_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_H_SW_MINOR_VER "
#endif
#if (PWM_H_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_H_SW_PATCH_VER "
#endif

/*============================================DEFINES AND MACROS====================================*/
#define PWM_MODULE_ID                               121
#define PWM_E_INIT_FAILED                           (0x10U)
#define PWM_E_UNINIT                                (0x11U)
#define PWM_E_PARAM_CHANNEL                         (0x12U)
#define PWM_E_PERIOD_UNCHANGEABLE                   (0x13U)
#define PWM_E_ALREADY_INITIALIZED                   (0x14U)
#define PWM_E_PARAM_POINTER                         (0x15U)
#define PWM_E_NOT_DISENGAGED                        (0x16U)
#define PWM_E_POWER_STATE_NOT_SUPPORTED             (0x17U)
#define PWM_E_TRANSITION_NOT_POSSIBLE               (0x18U)
#define PWM_E_PERIPHERAL_NOT_PREPARED               (0x19U)

#define PWM_E_PARAM_NOTIFICATION                    (0x30U)
#define PWM_E_PARAM_NOTIFICATION_NULL               (0x31U)
#define PWM_E_DUTYCYCLE_RANGE                       (0x32U)
#define PWM_E_PERIODVALUE                           (0x1AU)

#define PWM_INIT_ID                                 (0x00U)
#define PWM_DEINIT_ID                               (0x01U)
#define PWM_SETDUTYCYCLE_ID                         (0x02U)
#define PWM_SETPERIODANDDUTY_ID                     (0x03U)
#define PWM_SETOUTPUTTOIDLE_ID                      (0x04U)
#define PWM_GETOUTPUTSTATE_ID                       (0x05U)
#define PWM_DISABLENOTIFICATION_ID                  (0x06U)
#define PWM_ENABLENOTIFICATION_ID                   (0x07U)
#define PWM_GETVERSIONINFO_ID                       (0x08U)
#define PWM_SETPOWERSTATE_ID                        (0x09U)
#define PWM_GETCURRENTPOWERSTATE_ID                 (0x0AU)
#define PWM_GETTARGETPOWERSTATE_ID                  (0x0BU)
#define PWM_PREPAREPOWERSTATE_ID                    (0x0CU)
#define PWM_GETMAXDUTYCYCLE_ID                      (0x0DU)

#define PWM_DUTY_CYCLE_100_U16                      ((uint16)0x8000U)
#define PWM_DUTY_CYCLE_00_U16                       ((uint16)0x0U)

#define PWM_MAX_PERIOD_24BITS                       (0xFFFFFFU)
#define PWM_MAX_PERIOD_16BITS                       (0xFFFFU)
#define PWM_EMIOS_MAX_PERIOD                        (0xFFFFFFU-1U)
#if (defined(CCFC3007PT) || defined(CCFC3008PT) || defined(CCFC3007BC))
#define PWM_ETPU_MAX_PERIOD                         (0x7FFFFFU)
#endif

typedef enum
{
    PWM_RISING_EDGE = 1,
    PWM_FALLING_EDGE,
    PWM_BOTH_EDGES,
    PWM_WARNING
} Pwm_EdgeNotificationType;

typedef enum
{
    PWM_SERVICE_ACCEPTED = 0,
    PWM_NOT_INIT,
    PWM_SEQUENCE_ERROR,
    PWM_HW_FAILURE,
    PWM_POWER_STATE_NOT_SUPP,
    PWM_TRANS_NOT_POSSIBLE
} Pwm_PowerStateRequestResultType;

typedef enum
{
    PWM_FULL_POWER = 0,
    PWM_LOW_POWER,
    PWM_NODEFINE_POWER
} Pwm_PowerStateType;

#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
extern CONST(Pwm_ConfigType, PWM_CONST) Pwm_Config;
#endif

FUNC(void, PWM_CODE) Pwm_Init(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr);
FUNC(void, PWM_CODE) Pwm_DeInit(void);
FUNC(void, PWM_CODE) Pwm_SetDutyCycle \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber, \
    VAR(uint16, AUTOMATIC) u16DutyCycle \
);
FUNC(void, PWM_CODE) Pwm_SetPeriodAndDuty \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber, \
    VAR(Pwm_PeriodType, AUTOMATIC) Period, \
    VAR(uint16, AUTOMATIC) u16DutyCycle \
);
FUNC(void, PWM_CODE) Pwm_SetOutputToIdle(VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber);
FUNC(Pwm_OutputStateType, PWM_CODE) Pwm_GetOutputState \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber \
);
FUNC(void, PWM_CODE) Pwm_DisableNotification(VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber);
FUNC(void, PWM_CODE) Pwm_EnableNotification \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber, \
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) Notification \
);
FUNC(Std_ReturnType, PWM_CODE) Pwm_SetPowerState \
( \
    P2VAR(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) pResult \
);
FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_GetCurrentPowerState \
( \
    P2VAR(Pwm_PowerStateType, AUTOMATIC, PWM_APPL_DATA) CurrentPowerState, \
    P2VAR(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) Result \
);
FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_GetTargetPowerState \
( \
    P2VAR(Pwm_PowerStateType, AUTOMATIC, PWM_APPL_DATA) TargetPowerState, \
    P2VAR(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) Result \
);
FUNC(Std_ReturnType,PWM_PUBLIC_CODE) Pwm_PreparePowerState \
( \
    VAR(Pwm_PowerStateType, AUTOMATIC) PowerState, \
    P2VAR(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) Result \
);
FUNC(void, PWM_CODE) Pwm_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, PWM_APPL_DATA) versioninfo \
);
FUNC(void,PWM_PUBLIC_CODE) Pwm_Main_PowerTransitionManager(void);
FUNC(uint16, PWM_CODE) Pwm_GetMaxDutycycle \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber \
);

#ifdef __cplusplus
}
#endif

#endif
