/****************************************************************************
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
*   @file    Pwm.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm.h"
#include "Det.h"
#include "Pwm_AutoSar_Wrapper.h"
#include "SchM_Pwm.h"

#define PWM_C_VENDOR_ID                      176
#define PWM_C_AR_REL_MAJOR_VER               4
#define PWM_C_AR_REL_MINOR_VER               4
#define PWM_C_AR_REL_REV_VER                 0
#define PWM_C_SW_MAJOR_VER                   1
#define PWM_C_SW_MINOR_VER                   0
#define PWM_C_SW_PATCH_VER                   1

#if (PWM_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_C_VENDOR_ID "
#endif
#if (PWM_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_C_AR_REL_MINOR_VER "
#endif
#if (PWM_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_C_AR_REL_REV_VER "
#endif
#if (PWM_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_C_SW_MAJOR_VER "
#endif
#if (PWM_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_C_SW_MINOR_VER "
#endif
#if (PWM_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_C_SW_PATCH_VER "
#endif

typedef enum
{
    PWM_STATE_UNINIT = 0x00,
    PWM_STATE_ACTIV
} Pwm_StateType;

static P2CONST(Pwm_ConfigType, PWM_VAR, PWM_APPL_CONST) pPwm_Config[PWM_CORE_NUM] = {NULL_PTR};
#define PWM_START_SEC_VAR_INIT
#include "Pwm_MemMap.h"
static VAR(Pwm_StateType, PWM_VAR) ePwm_State[PWM_CORE_NUM] = {PWM_STATE_UNINIT};
#define PWM_STOP_SEC_VAR_INIT
#include "Pwm_MemMap.h"

#if(PWM_POWER_STATE_SUPPORTED == STD_ON)
#define PWM_START_SEC_VAR_INIT
#include "Pwm_MemMap.h"
static VAR(Pwm_PowerStateType,PWM_VAR) ePwm_CurrentPowerState[PWM_CORE_NUM];
#define PWM_STOP_SEC_VAR_INIT
#include "Pwm_MemMap.h"
#define PWM_START_SEC_VAR_INIT
#include "Pwm_MemMap.h"
static VAR(Pwm_PowerStateType,PWM_VAR) ePwm_TargetPowerState[PWM_CORE_NUM];
#define PWM_STOP_SEC_VAR_INIT
#include "Pwm_MemMap.h"
#endif

/*======================================LOCAL MACROS================================================*/
#define Pwm_ReportError(Pwm_ApiId,Pwm_ErrorId)(void)Det_ReportError \
                                                    ( \
                                                        (uint16)PWM_MODULE_ID, \
                                                        PWM_INDEX, \
                                                        (uint8)(Pwm_ApiId), \
                                                        (uint8)(Pwm_ErrorId) \
                                                    );

/*****************************************************************************
**  Service Name     : Pwm_InitVerify
**
**  Description      : Check the type of error reported by the Pwm_Init
**
**  Parameters (in)  : ConfigPtr: Pointer to driver configuration.
**
**  Parameters (out) : u8Pwm_ReturnValue
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PWM_CODE) Pwm_InitVerify \
( \
    P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id


    if (PWM_STATE_UNINIT != ePwm_State[u32CoreIDn])
    {
        Pwm_ReportError(PWM_INIT_ID, PWM_E_ALREADY_INITIALIZED);
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
    }else if(ConfigPtr == NULL_PTR)
    {
#if (PWM_PRECOMPILE_SUPPORT == STD_OFF)
        Pwm_ReportError(PWM_INIT_ID, PWM_E_INIT_FAILED);
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
#endif
    }else if(ConfigPtr != NULL_PTR )
    {
#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
        Pwm_ReportError(PWM_INIT_ID, PWM_E_INIT_FAILED);
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
#endif
    }else
    {
        /* nothing */
    }
#else
    (void)ConfigPtr;
#endif

    return u8Pwm_ReturnValue;
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_Init
**
**  Description      : This function initializes the Pwm driver.
**
**  Service ID       : 0x00
**
**  Sync/Async       : synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : ConfigPtr: pointer to PWM top configuration structure
**
**  Parameters (out) : void
**
**  Return value     : void
**
*******************************************************************************/
FUNC(void, PWM_CODE) Pwm_Init(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC)  u8Pwm_ReturnValue;
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    u8Pwm_ReturnValue = Pwm_InitVerify(ConfigPtr);

    if((Std_ReturnType)E_OK == u8Pwm_ReturnValue)
    {
#if (PWM_PRECOMPILE_SUPPORT == STD_OFF)
        pPwm_Config[u32CoreIDn] = ConfigPtr;
#else
        if (NULL_PTR != ConfigPtr)
        {
            Pwm_ReportError(PWM_INIT_ID, PWM_E_PARAM_POINTER);
            return;
        }

        pPwm_Config[u32CoreIDn] = &Pwm_Config;
        (void)ConfigPtr; /* Prevent compiler warning */
#endif
        ePwm_State[u32CoreIDn] = PWM_STATE_ACTIV;
        Pwm_AutoSar_Wrapper_Init((const Pwm_ChConfigsType *)pPwm_Config[u32CoreIDn]);
    }
}
/*===============================================================================================*/

#if (PWM_DEINIT_API == STD_ON)
/*****************************************************************************
**  Service Name     : Pwm_DeinitVerify
**
**  Description      : Check the type of error reported by the Pwm_Deinit
**
**  Parameters (in)  : None
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PWM_CODE) Pwm_DeinitVerify(void)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id



    if(ePwm_State[u32CoreIDn] == PWM_STATE_UNINIT)
    {
        Pwm_ReportError(PWM_DEINIT_ID, PWM_E_UNINIT);
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
    }
#endif

    return u8Pwm_ReturnValue;
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_DeInit
**
**  Description      : This function deinitializes the Pwm driver.
**
**  Service ID       : 0x01
**
**  Sync/Async       : synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : void
**
**  Parameters (out) : void
**
**  Return value     : void
**
*******************************************************************************/
FUNC(void, PWM_CODE) Pwm_DeInit(void)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = Pwm_DeinitVerify();

    if((Std_ReturnType)E_OK == u8Pwm_ReturnValue)
    {
        Pwm_AutoSar_Wrapper_DeInit(pPwm_Config[u32CoreIDn]);
        pPwm_Config[u32CoreIDn] = NULL_PTR;
        ePwm_State[u32CoreIDn] = PWM_STATE_UNINIT;
    }
}
/*===============================================================================================*/
#endif

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/*****************************************************************************
**  Service Name     : Pwm_SetDutyCycleVerify
**
**  Description      : Check the type of error reported by the Pwm_SetDutyCycle
**
**  Parameters (in)  : u16ChannelNumber: Given number of PWM channel
**                     u16DutyCycle: Given the dutycycle parameters of PWM
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PWM_CODE) Pwm_SetDutyCycleVerify
(
    VAR(Pwm_ChannelType, AUTOMATIC) u16ChannelNumber,
    VAR(uint16, AUTOMATIC) u16DutyCycle
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id
    VAR(uint8, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
    	u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }

    if (PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_UNINIT);
    }else if (u16ChannelNumber >= pPwm_Config[u32CoreIDn]->nNum)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_PARAM_CHANNEL);
    }else if (u16DutyCycle > PWM_DUTY_CYCLE_100_U16)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_DUTYCYCLE_RANGE);
    }else if ((pPwm_Config[u32CoreIDn]->pPwm_CoreMap[u16ChannelNumber].nCoreId & u32CoreID) == 0U)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_PARAM_CHANNEL);
    }else if (Pwm_AutoSar_Wrapper_CheckD(u16ChannelNumber,u16DutyCycle) == 0U)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_DUTYCYCLE_RANGE);
    }
    else
    {
        /* nothing */
    }
#else
    (void)u16ChannelNumber;
    (void)u16DutyCycle;
#endif

    return u8Pwm_ReturnValue;
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_SetDutyCycle
**
**  Description      : sets the dutycycle for the specified Pwm channel.
**
**  Service ID       : 0x02
**
**  Sync/Async       : Asynchronous
**
**  Reentrancy       : Reentrant for different channel numbers
**
**  Parameters (in)  : ChannelNumber: pwm channel id
**                     u32DutyCycle:  pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
**
**  Parameters (out) : void
**
**  Return value     : void
**
*******************************************************************************/
FUNC(void, PWM_CODE) Pwm_SetDutyCycle \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber, \
    VAR(uint16, AUTOMATIC) u16DutyCycle \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if((Std_ReturnType)E_OK == Pwm_SetDutyCycleVerify(ChannelNumber, u16DutyCycle))
    {
        Pwm_AutoSar_Wrapper_SetDuty \
        ( \
            &(pPwm_Config[u32CoreIDn]->sPwmChConfigs[ChannelNumber]), \
            u16DutyCycle \
        );
    }
}
/*===============================================================================================*/
#endif

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/*****************************************************************************
**  Service Name     : Pwm_SetPeriodAndDutyVerify
**
**  Description      : Check the type of error reported by the Pwm_SetPeriodAndDuty
**
**  Parameters (in)  : u16ChannelNumber: Given number of PWM channel
**                     u32Pwm_Period: Given the period parameters of PWM
**                     u16Pwm_DutyCycle: Given the dutycycle parameters of PWM
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType,PWM_CODE) Pwm_SetPeriodAndDutyVerify \
( \
    VAR(Pwm_ChannelType,AUTOMATIC) u16ChannelNumber, \
    VAR(Pwm_PeriodType,AUTOMATIC) Pwm_Period, \
    VAR(uint16,AUTOMATIC) u16Pwm_DutyCycle \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
    	u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }

    if (PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETPERIODANDDUTY_ID, PWM_E_UNINIT);
    }else if (u16ChannelNumber >= pPwm_Config[u32CoreIDn]->nNum)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETPERIODANDDUTY_ID, PWM_E_PARAM_CHANNEL);
    }else if(u16Pwm_DutyCycle > PWM_DUTY_CYCLE_100_U16)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETPERIODANDDUTY_ID, PWM_E_DUTYCYCLE_RANGE);
    }else if(PWM_VARIABLE_PERIOD != (pPwm_Config[u32CoreIDn]->sPwmChConfigs[u16ChannelNumber].ePwmChannelClass))
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETPERIODANDDUTY_ID, PWM_E_PERIOD_UNCHANGEABLE);
    }else if(pPwm_Config[u32CoreIDn]->sPwmChConfigs[u16ChannelNumber].ePwmHwIP == PWM_TOM)
    {
        if (Pwm_Period > PWM_MAX_PERIOD_16BITS)
        {
            Pwm_ReportError(PWM_SETPERIODANDDUTY_ID, PWM_E_PERIODVALUE);
            u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }else if(pPwm_Config[u32CoreIDn]->sPwmChConfigs[u16ChannelNumber].ePwmHwIP == PWM_ATOM)
    {
        if (Pwm_Period > PWM_MAX_PERIOD_24BITS)
        {
            Pwm_ReportError(PWM_SETPERIODANDDUTY_ID, PWM_E_PERIODVALUE);
            u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }else if(pPwm_Config[u32CoreIDn]->sPwmChConfigs[u16ChannelNumber].ePwmHwIP == PWM_EMIOS)
    {
        if (Pwm_Period > PWM_EMIOS_MAX_PERIOD)
        {
            Pwm_ReportError(PWM_SETPERIODANDDUTY_ID, PWM_E_PERIODVALUE);
            u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
#if (defined(CCFC3007PT) || defined(CCFC3008PT) || defined(CCFC3007BC))
    else if(pPwm_Config[u32CoreIDn]->sPwmChConfigs[u16ChannelNumber].ePwmHwIP == PWM_ETPU)
    {
        if (Pwm_Period > PWM_ETPU_MAX_PERIOD)
        {
            Pwm_ReportError(PWM_SETPERIODANDDUTY_ID, PWM_E_PERIODVALUE);
            u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
#endif
    else if ((pPwm_Config[u32CoreIDn]->pPwm_CoreMap[u16ChannelNumber].nCoreId & u32CoreID) == 0U)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_PARAM_CHANNEL);
    }else if (Pwm_AutoSar_Wrapper_CheckP_D(u16ChannelNumber,Pwm_Period,u16Pwm_DutyCycle) == 0U)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_DUTYCYCLE_RANGE);
    }else{
        /* nothing */
    }
#else
    (void)u16ChannelNumber;
    (void)Pwm_Period;
    (void)u16Pwm_DutyCycle;
#endif

    return u8Pwm_ReturnValue;
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_SetPeriodAndDuty
**
**  Description      : sets the period and the dutycycle
**                       for the specified Pwm channel.
**
**  Service ID       : 0x03
**
**  Sync/Async       : Asynchronous
**
**  Reentrancy       : Reentrant for different channel numbers
**
**  Parameters (in)  : ChannelNumber: pwm channel id
**                     Period: pwm signal period value
**                     DutyCycle: pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
**
**  Parameters (out) : void
**
**  Return value     : void
**
*******************************************************************************/
FUNC(void, PWM_CODE) Pwm_SetPeriodAndDuty \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber, \
    VAR(Pwm_PeriodType, AUTOMATIC) Period, \
    VAR(uint16, AUTOMATIC) u16DutyCycle \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if((Std_ReturnType)E_OK == Pwm_SetPeriodAndDutyVerify(ChannelNumber, Period, u16DutyCycle))
    {
        Pwm_AutoSar_Wrapper_SetPAndD \
        ( \
            &(pPwm_Config[u32CoreIDn]->sPwmChConfigs[ChannelNumber]), \
            Period, \
            u16DutyCycle \
        );
    }
}
/*===============================================================================================*/
#endif

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/*****************************************************************************
**  Service Name     : Pwm_SetOutputToIdleVerify
**
**  Description      : Check the type of error reported by the Pwm_SetOutputToIdle
**
**  Parameters (in)  : u16ChannelNumber: Given number of PWM channel
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PWM_CODE) Pwm_SetOutputToIdleVerify \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) u16ChannelNumber \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
    	u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }

    if (PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETOUTPUTTOIDLE_ID, PWM_E_UNINIT);
    }else if (u16ChannelNumber >= pPwm_Config[u32CoreIDn]->nNum)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETOUTPUTTOIDLE_ID, PWM_E_PARAM_CHANNEL);
    }else if ((pPwm_Config[u32CoreIDn]->pPwm_CoreMap[u16ChannelNumber].nCoreId & u32CoreID) == 0U)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_PARAM_CHANNEL);
    }else
    {
        /* nothing */
    }
#else
    (void)u16ChannelNumber;
#endif

    return u8Pwm_ReturnValue;
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_SetOutputToIdle
**
**  Description      : sets the generated pwm signal to
**                        the idle value configured.
**
**  Service ID       : 0x04
**
**  Sync/Async       : Asynchronous
**
**  Reentrancy       : Reentrant for different channel numbers
**
**  Parameters (in)  : ChannelNumber: pwm channel id
**
**  Parameters (out) : void
**
**  Return value     : void
**
******************************************************************************/
FUNC(void, PWM_CODE) Pwm_SetOutputToIdle(VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if((Std_ReturnType)E_OK == Pwm_SetOutputToIdleVerify(ChannelNumber))
    {
        Pwm_AutoSar_Wrapper_SetIdle(&(pPwm_Config[u32CoreIDn]->sPwmChConfigs[ChannelNumber]));
    }
}
/*===============================================================================================*/
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/*****************************************************************************
**  Service Name     : Pwm_GetOutputStateVerify
**
**  Description      : Check the type of error reported by the Pwm_GetOutputState
**
**  Parameters (in)  : u16ChannelNumber: Given number of PWM channel
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PWM_CODE) Pwm_GetOutputStateVerify \
( \
    VAR(Pwm_ChannelType,AUTOMATIC) u16ChannelNumber \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
    	u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }

    if (PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_GETOUTPUTSTATE_ID, PWM_E_UNINIT);
    }else if (u16ChannelNumber >= pPwm_Config[u32CoreIDn]->nNum)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_GETOUTPUTSTATE_ID, PWM_E_PARAM_CHANNEL);
    }else if ((pPwm_Config[u32CoreIDn]->pPwm_CoreMap[u16ChannelNumber].nCoreId & u32CoreID) == 0U)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_PARAM_CHANNEL);
    }else
    {
        /* nothing */
    }
#else
    (void)u16ChannelNumber;
#endif

    return u8Pwm_ReturnValue;
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_GetOutputState
**
**  Description      : This function returns the signal output state.
**
**  Service ID       : 0x05
**
**  Sync/Async       : synchronous
**
**  Reentrancy       : Reentrant for different channel numbers
**
**  Parameters (in)  : ChannelNumber: pwm channel id
**
**  Parameters (out) : void
**
**  Return value     : PWM_LOW/PWM_HIGH
**
*******************************************************************************/
FUNC(Pwm_OutputStateType, PWM_CODE) Pwm_GetOutputState \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber \
)
{
    VAR(Pwm_OutputStateType, AUTOMATIC) u8Pwm_ReturnValue = (Pwm_OutputStateType)PWM_LOW;
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if((Std_ReturnType)E_OK == Pwm_GetOutputStateVerify(ChannelNumber))
    {
        u8Pwm_ReturnValue = (Pwm_OutputStateType)Pwm_AutoSar_Wrapper_GetOutput \
                            ( \
                                &(pPwm_Config[u32CoreIDn]->sPwmChConfigs[ChannelNumber]) \
                            );
    }

    return u8Pwm_ReturnValue;
}
/*===============================================================================================*/
#endif

#if (PWM_NOTIFICATION_SUPPORT == STD_ON)
/*****************************************************************************
**  Service Name     : Pwm_DisableNotification_Verify
**
**  Description      : Check the type of error reported by the Pwm_DisableNotification
**
**  Parameters (in)  : u16ChannelNumber: Given number of PWM channel
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PWM_CODE) Pwm_DisableNotification_Verify \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) u16ChannelNumber \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
    	u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }

    if (PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_DISABLENOTIFICATION_ID, PWM_E_UNINIT);
    }else if (u16ChannelNumber >= pPwm_Config[u32CoreIDn]->nNum)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_DISABLENOTIFICATION_ID, PWM_E_PARAM_CHANNEL);
    }else if ((pPwm_Config[u32CoreIDn]->pPwm_CoreMap[u16ChannelNumber].nCoreId & u32CoreID) == 0U)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_PARAM_CHANNEL);
    }else
    {
        /* nothing */
    }
#else
    (void)u16ChannelNumber;
#endif

    return u8Pwm_ReturnValue;
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_EnableNotificationVerify
**
**  Description      : Check the type of error reported by the Pwm_EnableNotification
**
**  Parameters (in)  : u16ChannelNumber: Given number of PWM channel
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PWM_CODE) Pwm_EnableNotificationVerify \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) u16ChannelNumber, \
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) Notification \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(Pwm_NotifyType, AUTOMATIC) pPwm_ChannelNotification = NULL_PTR;
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
    	u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }

    if (PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_ENABLENOTIFICATION_ID, PWM_E_UNINIT);
    }else if ((pPwm_Config[u32CoreIDn] != NULL_PTR) && (u16ChannelNumber >= pPwm_Config[u32CoreIDn]->nNum))
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_ENABLENOTIFICATION_ID, PWM_E_PARAM_CHANNEL);
    }else if ((Notification > PWM_BOTH_EDGES) || (Notification < PWM_RISING_EDGE))
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_ENABLENOTIFICATION_ID, PWM_E_PARAM_NOTIFICATION);
    }else if ((pPwm_Config[u32CoreIDn]->pPwm_CoreMap[u16ChannelNumber].nCoreId & u32CoreID) == 0U)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETDUTYCYCLE_ID, PWM_E_PARAM_CHANNEL);
    }else{

        pPwm_ChannelNotification = pPwm_Config[u32CoreIDn]->sPwmChConfigs[u16ChannelNumber].pfPwmChannelNotification;
        /* Check if Notification param is not NULL */
        if(NULL_PTR == pPwm_ChannelNotification)
        {
            Pwm_ReportError(PWM_ENABLENOTIFICATION_ID, PWM_E_PARAM_NOTIFICATION_NULL);
            u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
#else
    (void)u16ChannelNumber;
    (void)Notification;
#endif

    return u8Pwm_ReturnValue;
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_DisableNotification
**
**  Description      : This function disables the user notifications.
**
**  Service ID       : 0x06
**
**  Sync/Async       : Asynchronous
**
**  Reentrancy       : Reentrant for different channel numbers
**
**  Parameters (in)  : ChannelNumber: pwm channel id
**
**  Parameters (out) : void
**
**  Return value     : void
**
*******************************************************************************/
FUNC(void, PWM_CODE) Pwm_DisableNotification(VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if((Std_ReturnType)E_OK == Pwm_DisableNotification_Verify(ChannelNumber))
    {
        Pwm_AutoSar_Wrapper_DiNotifi(&(pPwm_Config[u32CoreIDn]->sPwmChConfigs[ChannelNumber]));
    }
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_EnableNotification
**
**  Description      : This function enables the user notifications.
**
**  Service ID       : 0x07
**
**  Sync/Async       : Asynchronous
**
**  Reentrancy       : Reentrant for different channel numbers
**
**  Parameters (in)  :ChannelNumber: pwm channel id
**                    Notification : notification type to be enabled
**
**  Parameters (out) : void
**
**  Return value     : void
**
******************************************************************************/
FUNC(void, PWM_CODE) Pwm_EnableNotification \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber, \
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) Notification \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if((Std_ReturnType)E_OK == Pwm_EnableNotificationVerify(ChannelNumber,Notification))
    {
        Pwm_AutoSar_Wrapper_EnNotifi \
        ( \
            &(pPwm_Config[u32CoreIDn]->sPwmChConfigs[ChannelNumber]), \
            Notification \
        );
    }
}
/*===============================================================================================*/
#endif

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_SetPowerState_Verify \
( \
    P2VAR(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) ePwm_176Result \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8Pwm_ReturnValue = E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id


    if (PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        Pwm_ReportError(PWM_SETPOWERSTATE_ID, PWM_E_UNINIT);
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
    }else if(NULL_PTR == ePwm_176Result)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETPOWERSTATE_ID, PWM_E_PARAM_POINTER);
    }else if(ePwm_TargetPowerState[u32CoreIDn] == ePwm_CurrentPowerState[u32CoreIDn])
    {
        *ePwm_176Result = PWM_SERVICE_ACCEPTED;
        u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
    }else if(PWM_NODEFINE_POWER == ePwm_TargetPowerState[u32CoreIDn])
    {
        *ePwm_176Result = PWM_SEQUENCE_ERROR;
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETPOWERSTATE_ID,PWM_E_PERIPHERAL_NOT_PREPARED);
    }else if((PWM_LOW_POWER != ePwm_TargetPowerState[u32CoreIDn]) && (PWM_FULL_POWER != ePwm_TargetPowerState[u32CoreIDn]))
    {
        *ePwm_176Result = PWM_POWER_STATE_NOT_SUPP;
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_SETPOWERSTATE_ID,PWM_E_POWER_STATE_NOT_SUPPORTED);
    }else
    {
        /* nothing */
    }
#else
    (void)ePwm_176Result;
#endif

    return u8Pwm_ReturnValue;
}

LOCAL_INLINE FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_GetTargetPowerState_Verify \
( \
	P2CONST(Pwm_PowerStateType, AUTOMATIC, PWM_APPL_DATA) ePwm_176TargetPowerState, \
	P2CONST(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) ePwm_176Result \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8Pwm_ReturnValue = E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if((NULL_PTR == ePwm_176Result) || (NULL_PTR == ePwm_176TargetPowerState))
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_GETTARGETPOWERSTATE_ID,PWM_E_PARAM_POINTER);
    }else if(PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        /* Specification of PWM Driver : [SWS_Pwm_00182] */
        Pwm_ReportError(PWM_GETTARGETPOWERSTATE_ID,PWM_E_UNINIT);
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
    }else
    {
        /* nothing */
    }
#else
    (void)ePwm_176TargetPowerState;
    (void)ePwm_176Result;
#endif

    return u8Pwm_ReturnValue;
}

LOCAL_INLINE FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_GetCurrentPowerState_Verify \
( \
	P2CONST(Pwm_PowerStateType, AUTOMATIC, PWM_APPL_DATA) ePwm_176CurrentPowerState, \
	P2CONST(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) ePwm_176Result \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8Pwm_ReturnValue = E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id


    if((NULL_PTR == ePwm_176Result) || (NULL_PTR == ePwm_176CurrentPowerState))
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_GETCURRENTPOWERSTATE_ID,PWM_E_PARAM_POINTER);
    }else if(PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        /* Specification of PWM Driver : [SWS_Pwm_00179] */
        Pwm_ReportError(PWM_GETCURRENTPOWERSTATE_ID,PWM_E_UNINIT);
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
    }else
    {
        /* nothing */
    }
#else
    (void)ePwm_176CurrentPowerState;
    (void)ePwm_176Result;
#endif

    return u8Pwm_ReturnValue;
}

LOCAL_INLINE FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_PreparePowerState_Verify \
( \
	P2CONST(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) ePwm_176Result \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8Pwm_ReturnValue = E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id



    if(PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        Pwm_ReportError(PWM_PREPAREPOWERSTATE_ID,PWM_E_UNINIT);
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
    }else if(NULL_PTR == ePwm_176Result)
    {
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError((uint8)PWM_PREPAREPOWERSTATE_ID,(uint8)PWM_E_PARAM_POINTER);
    }else
    {
        /* nothing */
    }
#else
    (void)ePwm_176Result;
#endif

    return u8Pwm_ReturnValue;
}


/*****************************************************************************
**  Service Name     : Pwm_SetPowerState
**
**  Description      : Enters the already prepared power state.
**
**  Service ID       : 0x09
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : Result          Pointer to a variable to store the result of this function.
**
**  Parameters (out) : void
**
**  Return value     : Std_ReturnType
**
*******************************************************************************/
FUNC(Std_ReturnType, PWM_CODE) Pwm_SetPowerState \
( \
    P2VAR(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) pResult \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    u8Pwm_ReturnValue = Pwm_SetPowerState_Verify(pResult);

    if(u8Pwm_ReturnValue == (Std_ReturnType)E_OK)
    {
        *pResult = PWM_SERVICE_ACCEPTED;
        ePwm_CurrentPowerState[u32CoreIDn] = ePwm_TargetPowerState[u32CoreIDn];
        ePwm_TargetPowerState[u32CoreIDn] = PWM_NODEFINE_POWER;
    }

    return u8Pwm_ReturnValue;
}


/*****************************************************************************
**  Service Name     : Pwm_GetCurrentPowerState
**
**  Description      : Get the current power state of the Pwm HW unit.
**
**  Service ID       : 0x0a
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : CurrentPowerState     The current power mode of the Pwm HW Unit is returned in this parameter
**                     Result                Pointer to a variable to store the result of this function.
**
**  Parameters (out) : void
**
**  Return value     : Std_ReturnType
**
*******************************************************************************/
FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_GetCurrentPowerState \
( \
    P2VAR(Pwm_PowerStateType, AUTOMATIC, PWM_APPL_DATA) CurrentPowerState, \
    P2VAR(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) Result \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    u8Pwm_ReturnValue = Pwm_GetCurrentPowerState_Verify(CurrentPowerState, Result);

    if(u8Pwm_ReturnValue == (Std_ReturnType)E_OK)
    {
        *CurrentPowerState = ePwm_CurrentPowerState[u32CoreIDn];
        *Result = PWM_SERVICE_ACCEPTED;
    }

    return u8Pwm_ReturnValue;
}

/*****************************************************************************
**  Service Name     : Pwm_GetTargetPowerState
**
**  Description      : Get the target power state of the Pwm HW unit.
**
**  Service ID       : 0x0b
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : TargetPowerState      The Target power mode of the Pwm HW Unit is returned in this parameter.
**                     Result                Pointer to a variable to store the result of this function.
**
**  Parameters (out) : void
**
**  Return value     : Std_ReturnType
**
*******************************************************************************/
FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_GetTargetPowerState \
( \
    P2VAR(Pwm_PowerStateType, AUTOMATIC, PWM_APPL_DATA) TargetPowerState, \
    P2VAR(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) Result \
)
{
    VAR(Std_ReturnType,AUTOMATIC) u8Pwm_ReturnValue = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    u8Pwm_ReturnValue = Pwm_GetTargetPowerState_Verify(TargetPowerState, Result);

    if ((Std_ReturnType)E_OK == u8Pwm_ReturnValue)
    {
        *TargetPowerState = ePwm_TargetPowerState[u32CoreIDn];
        *Result = PWM_SERVICE_ACCEPTED;
    }

    return u8Pwm_ReturnValue;
}

/*****************************************************************************
**  Service Name     : Pwm_PreparePowerState
**
**  Description      : Starts the needed process to allow the Pwm HW module to enter the requested power state.
**
**  Service ID       : 0x0c
**
**  Sync/Async       : Synchronous
**
**  Reentrancy       : Non-Reentrant
**
**  Parameters (in)  : PowerState      The target power state intended to be attained.
**                     Result          Pointer to a variable to store the result of this function.
**
**  Parameters (out) : void
**
**  Return value     : Std_ReturnType
**
*******************************************************************************/
FUNC(Std_ReturnType, PWM_PUBLIC_CODE) Pwm_PreparePowerState \
( \
    VAR(Pwm_PowerStateType, AUTOMATIC) PowerState, \
    P2VAR(Pwm_PowerStateRequestResultType, AUTOMATIC, PWM_APPL_DATA) Result \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Pwm_ReturnValue = E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    u8Pwm_ReturnValue = Pwm_PreparePowerState_Verify(Result);
    if ((Std_ReturnType)E_OK == u8Pwm_ReturnValue)
    {
        if(ePwm_CurrentPowerState[u32CoreIDn] != PowerState)
        {
            if((PWM_LOW_POWER != PowerState) && (PWM_FULL_POWER != PowerState))
            {
                #if (PWM_DEV_ERROR_DETECT == STD_ON)
                Pwm_ReportError(PWM_PREPAREPOWERSTATE_ID,PWM_E_POWER_STATE_NOT_SUPPORTED);
                #endif
                *Result = PWM_POWER_STATE_NOT_SUPP;
                u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                *Result = PWM_SERVICE_ACCEPTED;
                ePwm_TargetPowerState[u32CoreIDn] = PowerState;
            }
        }
        else
        {
            *Result = PWM_SEQUENCE_ERROR;
            u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        if(Result != NULL_PTR)
        {
            *Result = PWM_NOT_INIT;
        }
        u8Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return u8Pwm_ReturnValue;
}

FUNC(void, PWM_PUBLIC_CODE) Pwm_Main_PowerTransitionManager \
( \
    void \
)
{
    /* Do nothing */
}
/*===============================================================================================*/
#endif

#if (PWM_VERSION_INFO_API == STD_ON)
/*****************************************************************************
**  Service Name     : Pwm_GetVersionInfo
**
**  Description      : This function returns Pwm driver version details
**
**  Service ID       : 0x08
**
**  Sync/Async       : synchronous
**
**  Reentrancy       : Reentrant
**
**  Parameters (in)  : pVersioninfo: pointer to Std_VersionInfoType output variable
**
**  Parameters (out) : pVersioninfo: pointer to Std_VersionInfoType output variable
**
**  Return value     : void
**
*******************************************************************************/
FUNC(void, PWM_CODE) Pwm_GetVersionInfo(P2VAR \
( \
    Std_VersionInfoType, AUTOMATIC, PWM_APPL_DATA) versioninfo \
)
{
    if(NULL_PTR == versioninfo)
    {
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        Pwm_ReportError (PWM_GETVERSIONINFO_ID, PWM_E_PARAM_POINTER);
#endif
    }
    else
    {
        (versioninfo)->vendorID         = (uint16)PWM_CFG_H_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)PWM_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)PWM_CFG_H_SW_MAJOR_VER;
        (versioninfo)->sw_minor_version = (uint8)PWM_CFG_H_SW_MINOR_VER;
        (versioninfo)->sw_patch_version = (uint8)PWM_CFG_H_SW_PATCH_VER;
    }
}
/*===============================================================================================*/
#endif

/*****************************************************************************
**  Service Name     : Pwm_GetMaxDutycycleVerify
**
**  Description      : Check the type of error reported by the Pwm_GetMaxDutycycle
**
**  Parameters (in)  : u16ChannelNumber: Given number of PWM channel
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, PWM_CODE) Pwm_GetMaxDutycycleVerify \
( \
    VAR(Pwm_ChannelType,AUTOMATIC) u16ChannelNumber \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u16Pwm_ReturnValue = (Std_ReturnType)E_OK;
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if (PWM_STATE_UNINIT == ePwm_State[u32CoreIDn])
    {
        u16Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_GETMAXDUTYCYCLE_ID, PWM_E_UNINIT);
    }else if (u16ChannelNumber >= pPwm_Config[u32CoreIDn]->nNum)
    {
        u16Pwm_ReturnValue = (Std_ReturnType)E_NOT_OK;
        Pwm_ReportError(PWM_GETMAXDUTYCYCLE_ID, PWM_E_PARAM_CHANNEL);
    }else
    {
        /* nothing */
    }
#else
    (void)u16ChannelNumber;
#endif

    return u16Pwm_ReturnValue;
}
/*===============================================================================================*/

/*****************************************************************************
**  Service Name     : Pwm_GetMaxDutycycle
**
**  Description      : This function returns the maximum configurable duty cycle for the Pwm channel.
**
**  Service ID       : 0x05
**
**  Sync/Async       : synchronous
**
**  Reentrancy       : Reentrant for different channel numbers
**
**  Parameters (in)  : ChannelNumber: Pwm channel id
**
**  Parameters (out) : void
**
**  Return value     : PWM duty cycle
**
*******************************************************************************/
FUNC(uint16, PWM_CODE) Pwm_GetMaxDutycycle \
( \
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber \
)
{
    VAR(uint16, AUTOMATIC) u16Pwm_MaxDutycycle = 0U;

    if((Std_ReturnType)E_OK == Pwm_GetMaxDutycycleVerify(ChannelNumber))
    {
        u16Pwm_MaxDutycycle = (uint16)Pwm_AutoSar_Wrapper_MaxD(ChannelNumber);
    }

    return u16Pwm_MaxDutycycle;
}
/*===============================================================================================*/

#ifdef __cplusplus
}
#endif
