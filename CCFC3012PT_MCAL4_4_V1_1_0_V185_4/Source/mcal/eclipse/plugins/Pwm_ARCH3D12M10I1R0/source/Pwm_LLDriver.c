/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3012PT
* DESCRIPTION : CCFC3012PT GTM TOM low level drivers code
* HISTORY     : Initial version
* @file     gtm4_tom_lld.c
* @version  1.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/

 /*PRQA S 0380,1296,1503,1317,1338,1881,2016,2023,2024,4442,4404,3469,2985 EOF*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm_LLDriver.h"
#include "Gpt_Gtm_LLDriver.h"
#include "Gpt_Gtm410_LLDriver.h"
#if (defined(CCFC3007PT) || defined (CCFC3008PT) || defined (CCFC3012PT))

#define PWM_LLD_C_VENDOR_ID                      176
#define PWM_LLD_C_AR_REL_MAJOR_VER               4
#define PWM_LLD_C_AR_REL_MINOR_VER               4
#define PWM_LLD_C_AR_REL_REV_VER                 0
#define PWM_LLD_C_SW_MAJOR_VER                   1
#define PWM_LLD_C_SW_MINOR_VER                   0
#define PWM_LLD_C_SW_PATCH_VER                   1

#if (PWM_LLD_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_LLD_C_VENDOR_ID "
#endif
#if (PWM_LLD_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_LLD_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_AR_REL_MINOR_VER "
#endif
#if (PWM_LLD_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_AR_REL_REV_VER "
#endif
#if (PWM_LLD_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_SW_MAJOR_VER "
#endif
#if (PWM_LLD_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_SW_MINOR_VER "
#endif
#if (PWM_LLD_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_SW_PATCH_VER "
#endif

/*
 * @brief Gated Counter ePwm_Mode enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableGatedCounterMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.GCM = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.GCM != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief SPE mode enable for channel.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableSPEMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SPEM = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SPEM != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief One-shot mode enable for channel.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableOneShotMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.OSM = (uint8_t)ePwm_IsEnable;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.OSM != (uint8_t)ePwm_IsEnable)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Trigger output selection.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_TriggerOutput Trigger output type.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectTriggerOutput \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_TriggerOutput_Type, AUTOMATIC) ePwm_TriggerOutput \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.TRIGOUT = (uint8_t)ePwm_TriggerOutput;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.TRIGOUT != (uint8_t)ePwm_TriggerOutput)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief CCU0 Reset Source selection.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_CCU0ResetSource CCU0 Reset Source.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectCCU0ResetSource \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_CCU0ResetSource_Type, AUTOMATIC) ePwm_CCU0ResetSource \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.RST_CCU0 = (uint8_t)ePwm_CCU0ResetSource;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.RST_CCU0 != (uint8_t)ePwm_CCU0ResetSource)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Clock source select.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_ClockSource Clock source.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectClockSource \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_TOM_ClockSource_Type, AUTOMATIC) ePwm_ClockSource \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

//    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.CLK_SRC = (uint8_t)ePwm_ClockSource;
//    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.CLK_SRC != (uint8_t)ePwm_ClockSource)
//    {
//        ePwm_ReturnValue = STATUS_ERROR;
//    }

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL_SR.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL_SR.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
    {
    	ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief GET Clock source.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return ClockSource Clock source.
 */
FUNC(GTM_TOM_ClockSource_Type, AUTOMATIC) GTM_TOM_LLD_Channel_GetClockSource \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    return (GTM_TOM_ClockSource_Type)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.CLK_SRC;
}

/*
 * @brief Signal level for duty cycle.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_SignalLevel Signal level.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectSignalLevel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_SignalLevel_Type, AUTOMATIC) ePwm_SignalLevel \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SL = (uint8_t)ePwm_SignalLevel;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SL != (uint8_t)ePwm_SignalLevel)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Set Shadow Register value.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u16Pwm_SR0 Shadow Register0 value.
 * @param[in] u16Pwm_SR1 Shadow Register1 value.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetShadowRegister \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR0, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.B.SR0 = u16Pwm_SR0;
    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.B.SR1 = u16Pwm_SR1;
    if((GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.B.SR0 != u16Pwm_SR0) \
     || (GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.B.SR1 != u16Pwm_SR1))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Set compare Register value.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u16Pwm_CM0 compare Register0 value.
 * @param[in] u16Pwm_CM1 compare Register1 value.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetCompareRegister \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_CM0, \
    VAR(uint16, AUTOMATIC) u16Pwm_CM1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM0.B.CM0 = u16Pwm_CM0;
    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM1.B.CM1 = u16Pwm_CM1;
    if((GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM0.B.CM0 != u16Pwm_CM0) \
     || (GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM1.B.CM1 != u16Pwm_CM1))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Set Counter Register value.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u16Pwm_CN0 Counter Register0 value.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetCounter \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_CN0 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CN0.B.CN0 = u16Pwm_CN0;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CN0.B.CN0 != u16Pwm_CN0)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Get Counter Register value.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Counter Register value.
 */
FUNC(uint16, PWM_CODE) GTM_TOM_LLD_Channel_GetCounter \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    return GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CN0.B.CN0;
}
/*
 * @brief Get Output Level.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Output Level.
 */
FUNC(uint8, PWM_CODE) GTM_TOM_LLD_Channel_GetOutputLevel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    return GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].STAT.B.OL;
}

/*
 * @brief Get ePwm_Interrupt Flag.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt Interrupt type.
 *
 * @return Interrupt Flag status.
 */
FUNC(uint8, PWM_CODE) GTM_TOM_LLD_Channel_GetInterruptFlag \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    VAR(uint8, AUTOMATIC) u8Pwm_ReturnValue = 0U;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(ePwm_Interrupt == TOM_IRQ_CCU0TC)
    {
        u8Pwm_ReturnValue = GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_NOTIFY.B.CCU0TC;
    }else if(ePwm_Interrupt == TOM_IRQ_CCU1TC)
    {
        u8Pwm_ReturnValue = GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_NOTIFY.B.CCU1TC;
    }else
    {
        ;
    }

    return u8Pwm_ReturnValue;
}

/*
 * @brief Clear ePwm_Interrupt Flag.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt Interrupt type.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_ClearInterruptFlag \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    if(ePwm_Interrupt == TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_NOTIFY.R = 1U;
    }else if(ePwm_Interrupt == TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_NOTIFY.R = 2U;
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief ePwm_Interrupt enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt Interrupt type.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableInterrupt \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(ePwm_Interrupt == TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_EN.B.CCU0TC_IRQ_EN = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_EN.B.CCU0TC_IRQ_EN != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else if(ePwm_Interrupt == TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_EN.B.CCU1TC_IRQ_EN = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_EN.B.CCU1TC_IRQ_EN != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Force ePwm_Interrupt.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt Interrupt type.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_ForceInt \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(ePwm_Interrupt == TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
    }else if(ePwm_Interrupt == TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Select ePwm_Interrupt ePwm_Mode.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_InterruptMode Interrupt mode.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectInterruptMode\
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_InterruptMode_Type, AUTOMATIC) ePwm_InterruptMode \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_MODE.B.IRQ_MODE = (uint8_t)ePwm_InterruptMode;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_MODE.B.IRQ_MODE != (uint8_t)ePwm_InterruptMode)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Update enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableUpdate \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    VAR(uint8_t, AUTOMATIC) ePwm_IsEnable_l = (uint8_t) ePwm_IsEnable;

    if(ePwm_IsEnable_l  == 1u)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8_t, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_GLB_CTRL_UPEN_CTRL0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_GLB_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_GLB_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_GLB_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_GLB_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Reset Channel.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_ResetChannel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    VAR(uint8_t, AUTOMATIC)  shift = ((uint8_t)ePwm_CHn % 8U) + (uint8_t)GTM4_TOM_TGC_GLB_CTRL_RST_CH0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_GLB_CTRL.R = (uint32_t)(1U << shift);
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_GLB_CTRL.R = (uint32_t)(1U << shift);
    }

    return STATUS_SUCCESS;
}

/*
 * @brief TGC0 Host Trigger.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC0_HostTrigger \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_GLB_CTRL.B.HOST_TRIG = 1;

    return STATUS_SUCCESS;
}

/*
 * @brief TGC1 Host Trigger.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC1_HostTrigger \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_GLB_CTRL.B.HOST_TRIG = 1;

    return STATUS_SUCCESS;
}

/*
 * @brief TGC0 Host Select ePwm_TimeBase.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_TimeBase ePwm_TimeBase type.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC0_SelectTimeBase \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ACT_TB.B.TBU_SEL = (uint8_t)ePwm_TimeBase;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ACT_TB.B.TBU_SEL != (uint8_t)ePwm_TimeBase)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief TGC1 Host Select ePwm_TimeBase.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_TimeBase ePwm_TimeBase type.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC1_SelectTimeBase \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ACT_TB.B.TBU_SEL = (uint8_t)ePwm_TimeBase;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ACT_TB.B.TBU_SEL != (uint8_t)ePwm_TimeBase)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Set TGC0 Action Time.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] u32Pwm_ActionTime Action Time.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC0_SetActionTime \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    VAR(uint32, AUTOMATIC) ActionTime_l = u32Pwm_ActionTime;
    ActionTime_l = (0x00ffffffU & ActionTime_l);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ACT_TB.B.ACT_TB = ActionTime_l;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ACT_TB.B.ACT_TB != ActionTime_l)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Set TGC1 Action Time.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] u32Pwm_ActionTime Action Time.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC1_SetActionTime \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    VAR(uint32, AUTOMATIC) ActionTime_l = u32Pwm_ActionTime;
    ActionTime_l = (0x00ffffffU & ActionTime_l);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ACT_TB.B.ACT_TB = ActionTime_l;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ACT_TB.B.ACT_TB != ActionTime_l)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Force Update for reset u16Pwm_CN0 enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableForceUpdateCN0Reset \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(ePwm_IsEnable_l  == 1u)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_FUPD_CTRL_RSTCN0_CH0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_FUPD_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_FUPD_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_FUPD_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_FUPD_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Force Update enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableForceUpdate \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(ePwm_IsEnable_l  == 1u)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_FUPD_CTRL_FUPD_CTRL0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_FUPD_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_FUPD_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_FUPD_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_FUPD_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Internal Trigger enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableInternalTrigger \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8) ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2U;
    }
    else
    {
        ePwm_IsEnable_l = 1U;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_INT_TRIG_INT_TRIG0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_INT_TRIG.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_INT_TRIG.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_INT_TRIG.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_INT_TRIG.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Update Value enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableUpdateValue \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2u;

    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_ENDIS_CTRL_ENDIS_CTRL0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ENDIS_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ENDIS_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ENDIS_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ENDIS_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Channel enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableChannel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_ENDIS_STAT_ENDIS_STAT0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ENDIS_STAT.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ENDIS_STAT.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ENDIS_STAT.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ENDIS_STAT.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}

/*
 * @brief OutUpdate Value enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableOutUpdateValue \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS; 
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_OUTEN_CTRL_OUTEN_CTRL0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_OUTEN_CTRL.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_OUTEN_CTRL.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Out enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableOut \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;
    
    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_OUTEN_STAT_OUTEN_STAT0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_STAT.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_STAT.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_OUTEN_STAT.R = (uint32_t)(ePwm_IsEnable_l << shift);
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_OUTEN_STAT.R >> shift) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}

#ifdef __cplusplus
}
#endif

#endif /* RESORUCE_SUPPORT_GTM410 */

/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3012PT
* DESCRIPTION : CCFC3012PT GTM ATOM low level drivers code
* HISTORY     : Initial version
* @file     gtm4_atom_lld.c
* @version  1.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0380,1317,1503,1296,1338,2016,2023,2024,4442,2985 EOF*/
 /*PRQA S 4404,3469 EOF*/

#ifdef __cplusplus
extern "C"{
#endif

#if (defined(CCFC3007PT) || defined (CCFC3008PT) || defined (CCFC3012PT))

/*
 * @brief ARU Read address.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u16Pwm_ReadAddress0  ARU Read address 0.
 * @param[in] u16Pwm_ReadAddress1  ARU Read address 1.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetReadAddress \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_ReadAddress0, \
    VAR(uint16, AUTOMATIC) u16Pwm_ReadAddress1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].RDADDR.B.RDADDR0 = (uint8_t)u16Pwm_ReadAddress0;
    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].RDADDR.B.RDADDR1 = (uint8_t)u16Pwm_ReadAddress1;
    if((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].RDADDR.B.RDADDR0 != (uint8_t)u16Pwm_ReadAddress0) \
     || (GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].RDADDR.B.RDADDR1 != (uint8_t)u16Pwm_ReadAddress1))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief ARU blocking mode.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable  Enable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableARUBlockMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ARU_EN = (uint8_t)ePwm_IsEnable;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ARU_EN != (uint8_t)ePwm_IsEnable)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief One-shot mode.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable  Enable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableOneShotMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.OSM = (uint8_t)ePwm_IsEnable;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.OSM != (uint8_t)ePwm_IsEnable)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_TriggerOutput  Trigger source.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectTriggerOutput \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_TriggerOutput_Type, AUTOMATIC) ePwm_TriggerOutput \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.TRIGOUT = (uint8_t)ePwm_TriggerOutput;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.TRIGOUT != (uint8_t)ePwm_TriggerOutput)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Reset source of CCU0.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_ResetSource  Reset source.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectCCU0ResetSource \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_ResetSource_Type, AUTOMATIC) ePwm_ResetSource \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.RST_CCU0 = (uint8_t)ePwm_ResetSource;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.RST_CCU0 != (uint8_t)ePwm_ResetSource)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP).
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_ClockSource clock source.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectClockSource \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_ClockSource_Type, AUTOMATIC) ePwm_ClockSource \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.CLK_SRC_SR = (uint8_t)ePwm_ClockSource;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.CLK_SRC_SR != (uint8_t)ePwm_ClockSource)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief GET Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP).
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return ClockSource clock source.
 */
FUNC(GTM_ATOM_ClockSource_Type, AUTOMATIC) GTM_ATOM_LLD_Channel_GetClockSource \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    return (GTM_ATOM_ClockSource_Type)GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.CLK_SRC_SR;
}

/*
 * @brief Initial signal level after channel enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_SignalLevel signal level.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectSignalLevel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_SignalLevel_Type, AUTOMATIC) ePwm_SignalLevel \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.SL = (uint8_t)ePwm_SignalLevel;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.SL != (uint8_t)ePwm_SignalLevel)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}


/*
 * @brief CCUn compare strategy select.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_CompareStrategy compare strategy.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectCompareStrategy \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_CompareStrategy_Type, AUTOMATIC) ePwm_CompareStrategy \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS; 
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.CMP_CTRL = (uint8_t)ePwm_CompareStrategy;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.CMP_CTRL != (uint8_t)ePwm_CompareStrategy)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief ATOM ePwm_Mode control bits.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u8Pwm_ACBbits ATOM ePwm_Mode control bits.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetACBbits \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_ACBbits \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ACB = u8Pwm_ACBbits;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ACB != u8Pwm_ACBbits)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief ARU Input stream enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable Enable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableARU \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ARU_EN = (uint8_t)ePwm_IsEnable;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ARU_EN != (uint8_t)ePwm_IsEnable)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Select time base value TBU_TS1 or TBU_TS2.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_TimeBase TBU_TS1 or TBU_TS2.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectTB12TimeBase \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_TB12TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.TB12_SEL = (uint8_t)ePwm_TimeBase;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.TB12_SEL != (uint8_t)ePwm_TimeBase)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief ATOM channel mode select.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Mode channel mode.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectATOMMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Mode_Type, AUTOMATIC) ePwm_Mode \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.MODE = (uint8_t)ePwm_Mode;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.MODE != (uint8_t)ePwm_Mode)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Set Shadow Register value.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u32Pwm_SR0 Shadow Register0 value.
 * @param[in] u32Pwm_SR1 Shadow Register1 value.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetShadowRegister \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR0, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0 = u32Pwm_SR0;
    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1 = u32Pwm_SR1;
    if((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0 != u32Pwm_SR0) \
     || (GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1 != u32Pwm_SR1))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Set compare Register value.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u32Pwm_CM0 compare Register0 value.
 * @param[in] u32Pwm_CM1 compare Register1 value.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetCompareRegister \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_CM0, \
    VAR(uint32, AUTOMATIC) u32Pwm_CM1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM0.B.CM0 = u32Pwm_CM0;
    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM1.B.CM1 = u32Pwm_CM1;
    if((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM0.B.CM0 != u32Pwm_CM0) \
     || (GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM1.B.CM1 != u32Pwm_CM1))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Get Counter Register value.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Counter Register value.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetCounter \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_CN0 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(uint32, AUTOMATIC) u32Pwm_CN0_l = u32Pwm_CN0;

    u32Pwm_CN0_l = ((uint32)0x00ffffff & u32Pwm_CN0_l);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CN0.B.CN0 = u32Pwm_CN0_l;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CN0.B.CN0 != u32Pwm_CN0_l)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Get Output Level.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Output Level.
 */
FUNC(uint8, PWM_CODE) GTM_ATOM_LLD_Channel_GetOutputLevel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    return GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].STAT.B.OL;
}

/*
 * @brief Get ePwm_Interrupt Flag.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt ePwm_Interrupt type.
 *
 * @return ePwm_Interrupt Flag status.
 */
FUNC(uint8, PWM_CODE) GTM_ATOM_LLD_Channel_GetInterruptFlag \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;

    if(ePwm_Interrupt == ATOM_IRQ_CCU0TC)
    {
        ePwm_ReturnValue = (status_t)GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_NOTIFY.B.CCU0TC;
    }else if(ePwm_Interrupt == ATOM_IRQ_CCU1TC)
    {
        ePwm_ReturnValue = (status_t)GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_NOTIFY.B.CCU1TC;
    }else
    {
        ;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Clear ePwm_Interrupt Flag.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt ePwm_Interrupt type.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_ClearInterruptFlag \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    if(ePwm_Interrupt == ATOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_NOTIFY.R = 1U;
    }else if(ePwm_Interrupt == ATOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_NOTIFY.R = 2U;
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief ePwm_Interrupt enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt ePwm_Interrupt type.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableInterrupt \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

   if(ePwm_Interrupt == ATOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_EN.B.CCU0TC_IRQ_EN = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_EN.B.CCU0TC_IRQ_EN != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else if(ePwm_Interrupt == ATOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_EN.B.CCU1TC_IRQ_EN = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_EN.B.CCU1TC_IRQ_EN != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Force ePwm_Interrupt.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt ePwm_Interrupt type.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_ForceInterrupt \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    if(ePwm_Interrupt == ATOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_FORCINT.B.TRG_CCU0TC = 1u;
    }else if(ePwm_Interrupt == ATOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_FORCINT.B.TRG_CCU1TC = 1u;
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Select ePwm_Interrupt ePwm_Mode.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_InterruptMode ePwm_Interrupt mode.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectInterruptMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_InterruptMode_Type, AUTOMATIC) ePwm_InterruptMode \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_MODE.B.IRQ_MODE = (uint8_t)ePwm_InterruptMode;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_MODE.B.IRQ_MODE != (uint8_t)ePwm_InterruptMode)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Update enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableUpdate \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2;
    }
    else
    {
        u8Pwm_IsEnable_l = 1;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_GLB_CTRL_UPEN_CTRL0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.GLB_CTRL.R = (uint32_t)(u8Pwm_IsEnable_l << shift);
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.GLB_CTRL.R >> shift) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Reset Channel.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_ResetChannel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);    

    VAR(uint8_t, AUTOMATIC)  shift = ((uint8_t)ePwm_CHn % 8U) + (uint8_t)GTM4_ATOM_AGC_GLB_CTRL_RST_CH0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.GLB_CTRL.R = (uint32_t)(1U << shift);

    return STATUS_SUCCESS;
}

/*
 * @brief TGC0 Host Trigger.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_AGC_HostTrigger \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.GLB_CTRL.B.HOST_TRIG = 1;

    return STATUS_SUCCESS;
}

/*
 * @brief TGC0 Host Select ePwm_TimeBase.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_TimeBase ePwm_TimeBase type.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_AGC_SelectTimeBase \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ACT_TB.B.TBU_SEL = (uint8_t)ePwm_TimeBase;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ACT_TB.B.TBU_SEL != (uint8_t)ePwm_TimeBase)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}


/*
 * @brief Set TGC0 Action Time.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] u32Pwm_ActionTime Action Time.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_AGC_SetActionTime \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ACT_TB.B.ACT_TB = u32Pwm_ActionTime;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ACT_TB.B.ACT_TB != u32Pwm_ActionTime)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Force Update enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableForceUpdateCN0Reset \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_FUPD_CTRL_RSTCN0_CH0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R = (uint32_t)(u8Pwm_IsEnable_l << shift);
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R >> shift) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableForceUpdate \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

     uint8_t  shift = ((uint8_t)ePwm_CHn * 2U) + (uint8_t)GTM4_ATOM_AGC_FUPD_CTRL_FUPD_CTRL0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R = (uint32_t)(u8Pwm_IsEnable_l << shift);
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R >> shift) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
/*
* @brief Internal Trigger enable.
*
* @param[in] ePwm_GTM_ATOMn submodule.
* @param[in] ePwm_CHn Channel.
* @param[in] ePwm_IsEnable ePwm_IsEnable status.
*
* @return Operation status.
*/
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableInternalTrigger \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = ((uint8_t)ePwm_CHn * 2U) + (uint8_t)GTM4_ATOM_AGC_INT_TRIG_INT_TRIG0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.INT_TRIG.R = (uint32_t)(u8Pwm_IsEnable_l << shift);
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.INT_TRIG.R >> shift) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Update Value enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableUpdateValue \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = ((uint8_t)ePwm_CHn * 2U) + (uint8_t)GTM4_ATOM_AGC_ENDIS_CTRL_ENDIS_CTRL0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ENDIS_CTRL.R = (uint32_t)(u8Pwm_IsEnable_l << shift);
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ENDIS_CTRL.R >> shift) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Channel enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableChannel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2U;
    }
    else
    {
        u8Pwm_IsEnable_l = 1U;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_ENDIS_STAT_ENDIS_STAT0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ENDIS_STAT.R = (uint32_t)(u8Pwm_IsEnable_l << shift);
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ENDIS_STAT.R >> shift) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}


/*
 * @brief OutUpdate Value enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableOutUpdateValue \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_OUTEN_CTRL_OUTEN_CTRL0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_CTRL.R = (uint32_t)(u8Pwm_IsEnable_l << shift);
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_CTRL.R >> shift) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief Out enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableOut \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_OUTEN_STAT_OUTEN_STAT0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_STAT.R = (uint32_t)(u8Pwm_IsEnable_l << shift);
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_STAT.R >> shift) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

#ifdef __cplusplus
}
#endif

#endif /* RESORUCE_SUPPORT_GTM410 */

/********************************** add **********************************/

#ifdef __cplusplus
extern "C"{
#endif

#if (defined(CCFC3007PT) || defined (CCFC3008PT) || defined (CCFC3012PT))
FUNC(status_t, PWM_CODE) SetTomChannelSL \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SL = (uint8_t)u8Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SL != (uint8_t)u8Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) SetAtomChannelSL \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_Val \
)
{

    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.SL = (uint8_t)u8Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.SL != (uint8_t)u8Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) SetTomChannelCM0 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM0.B.CM0 = u32Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM0.B.CM0 != u32Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) SetTomChannelCM1 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM1.B.CM1 = u32Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM1.B.CM1 != u32Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) SetAtomChannelCM0 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM0.B.CM0 = u32Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM0.B.CM0 != u32Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) SetAtomChannelCM1 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM1.B.CM1 = u32Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM1.B.CM1 != u32Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetShadowRegister0 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint16, AUTOMATIC, PWM_APPL_DATA) pPwm_SR0 \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    *pPwm_SR0 = (uint16)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.B.SR0;

    return STATUS_SUCCESS;
}

FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetShadowRegister1 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint16, AUTOMATIC, PWM_APPL_DATA) pPwm_SR1 \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    *pPwm_SR1 = (uint16)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.B.SR1;

    return STATUS_SUCCESS;
}

FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetShadowRegister0 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_SR0 \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    *pPwm_SR0 = GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0;

    return STATUS_SUCCESS;
}

FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetShadowRegister1 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_SR1 \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

   *pPwm_SR1 = GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1;

    return STATUS_SUCCESS;
}

FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetEnableOut \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_IsEnable \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    (void)ePwm_CHn;

    *pPwm_IsEnable = GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_STAT.R;

    return STATUS_SUCCESS;
}

FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetEnableOut \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    (void)ePwm_CHn;

    *pPwm_IsEnable = GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_STAT.R;

    return STATUS_SUCCESS;
}

FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetShadowRegister0 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR0 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.B.SR0 = u16Pwm_SR0;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.B.SR0 != u16Pwm_SR0)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetShadowRegister1 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.B.SR1 = u16Pwm_SR1;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.B.SR1 != u16Pwm_SR1)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetShadowRegister0 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR0 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0 = u32Pwm_SR0;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0 != u32Pwm_SR0)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetShadowRegister1 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1 = u32Pwm_SR1;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1 != u32Pwm_SR1)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}

/*
 * @brief GTM HRES enable
 *
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status
 */
FUNC(Std_ReturnType, PWM_CODE) GTM_ATOM_LLD_HresEn(void)
{
    GTM4.GLS[0].GLSDLLCTRL[0].R = (0x33030000 | (uint32_t)1);
    GTM4.GLS[0].GLSDLLCTRL[1].R = (0x33030000 | (uint32_t)1);

    return (Std_ReturnType)STATUS_SUCCESS;
}

FUNC(status_t, PWM_CODE) GTM_LLD_SetToutSel \
( \
    VAR(uint32, AUTOMATIC) u32Pwm_TOUT_NUM, \
    VAR(uint32, AUTOMATIC) u32Pwm_TOUT_SEL \
)
{
    GTM4.GLS[0].TOUTSEL[u32Pwm_TOUT_NUM / 8].R |= (u32Pwm_TOUT_SEL << (0x4 * (u32Pwm_TOUT_NUM % 8)));

    return STATUS_SUCCESS;
}

#ifdef __cplusplus
}
#endif

#endif
