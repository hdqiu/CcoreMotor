/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM TOM low level drivers code
* HISTORY     : Initial version
* @file     gtm4_tom_lld.c
* @version  1.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0380,1296,1503,1317,1338,1881,2016,2023,2024,4442,4404,3469,2985 EOF*/

#include "gtm4_tom_lld.h"
#ifdef RESORUCE_SUPPORT_GTM410

/*
 * @brief Gated Counter Mode enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableGatedCounterMode_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.GCM = (uint8_t)IsEnable;
        if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.GCM != (uint8_t)IsEnable)
        {
            return STATUS_ERROR;
        }
    }else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief SPE mode enable for channel.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableSPEMode_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.SPEM = (uint8_t)IsEnable;
        if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.SPEM != (uint8_t)IsEnable)
        {
            return STATUS_ERROR;
        }
    }else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief One-shot mode enable for channel.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableOneShotMode_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.OSM = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.OSM != (uint8_t)IsEnable)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Trigger output selection.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] TriggerOutput Trigger output type.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_SelectTriggerOutput_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_TriggerOutput_Type TriggerOutput)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.TRIGOUT = (uint8_t)TriggerOutput;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.TRIGOUT != (uint8_t)TriggerOutput)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief CCU0 Reset Source selection.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] CCU0ResetSource CCU0 Reset Source.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_SelectCCU0ResetSource_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_CCU0ResetSource_Type CCU0ResetSource)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.RST_CCU0 = (uint8_t)CCU0ResetSource;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.RST_CCU0 != (uint8_t)CCU0ResetSource)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Clock source select.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] ClockSource Clock source.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_SelectClockSource_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_ClockSource_Type ClockSource)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.CLK_SRC = (uint8_t)ClockSource;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.CLK_SRC != (uint8_t)ClockSource)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}


/*
 * @brief GET Clock source.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 *
 * @return ClockSource Clock source.
 */
GTM_TOM_ClockSource_Type GTM_TOM_LLD_Channel_GetClockSource_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.CLK_SRC;
}
/*
 * @brief Signal level for duty cycle.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] SignalLevel Signal level.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_SelectSignalLevel_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_SignalLevel_Type SignalLevel)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.SL = (uint8_t)SignalLevel;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.SL != (uint8_t)SignalLevel)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Set Shadow Register value.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] SR0 Shadow Register0 value.
 * @param[in] SR1 Shadow Register1 value.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_SetShadowRegister_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,uint16_t SR0,uint16_t SR1)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].SR0.B.SR0 = SR0;
    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].SR1.B.SR1 = SR1;
    if((GTM4.GLS[GTM_TOMn].TOM.CH[CHn].SR0.B.SR0 != SR0) || (GTM4.GLS[GTM_TOMn].TOM.CH[CHn].SR1.B.SR1 != SR1))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Set compare Register value.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] CM0 compare Register0 value.
 * @param[in] CM1 compare Register1 value.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_SetCompareRegister_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,uint16_t CM0,uint16_t CM1)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CM0.B.CM0 = CM0;
    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CM1.B.CM1 = CM1;
    if((GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CM0.B.CM0 != CM0) || (GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CM1.B.CM1 != CM1))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Set Counter Register value.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] CN0 Counter Register0 value.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_SetCounter_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,uint16_t CN0)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CN0.B.CN0 = CN0;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CN0.B.CN0 != CN0)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Get Counter Register value.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Counter Register value.
 */
uint16_t GTM_TOM_LLD_Channel_GetCounter_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CN0.B.CN0;
}
/*
 * @brief Get Output Level.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Output Level.
 */
uint8_t GTM_TOM_LLD_Channel_GetOutputLevel_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TOMn].TOM.CH[CHn].STAT.B.OL;
}

/*
 * @brief Get Interrupt Flag.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @return Interrupt Flag status.
 */
uint8_t GTM_TOM_LLD_Channel_GetInterruptFlag_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_Interrupt_Type Interrupt)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(Interrupt == TOM_IRQ_CCU0TC)
    {
        return GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_NOTIFY.B.CCU0TC;
    }else if(Interrupt == TOM_IRQ_CCU1TC)
    {
        return GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_NOTIFY.B.CCU1TC;
    }else
    {
        return 0U;
    }
}

/*
 * @brief Clear Interrupt Flag.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_ClearInterruptFlag_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_Interrupt_Type Interrupt)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(Interrupt == TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_NOTIFY.R = 1U;
    }else if(Interrupt == TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_NOTIFY.R = 2U;
    }else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Interrupt enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableInterrupt_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_Interrupt_Type Interrupt,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(Interrupt == TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_EN.B.CCU0TC_IRQ_EN = (uint8_t)IsEnable;
        if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_EN.B.CCU0TC_IRQ_EN != (uint8_t)IsEnable)
        {
            return STATUS_ERROR;
        }
    }else if(Interrupt == TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_EN.B.CCU1TC_IRQ_EN = (uint8_t)IsEnable;
        if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_EN.B.CCU1TC_IRQ_EN != (uint8_t)IsEnable)
        {
            return STATUS_ERROR;
        }
    }else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Force Interrupt.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_ForceInterrupt_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_Interrupt_Type Interrupt)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(Interrupt == TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
    }else if(Interrupt == TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
    }else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Select Interrupt Mode.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] InterruptMode Interrupt mode.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_SelectInterruptMode_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_InterruptMode_Type InterruptMode)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_MODE.B.IRQ_MODE = (uint8_t)InterruptMode;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_MODE.B.IRQ_MODE != (uint8_t)InterruptMode)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Update enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableUpdate_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_GLB_CTRL_UPEN_CTRL0_OFF;

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_GLB_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC0_GLB_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_GLB_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC1_GLB_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Reset Channel.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_ResetChannel_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint8_t  shift = ((uint8_t)CHn % 8U) + (uint8_t)GTM4_TOM_TGC_GLB_CTRL_RST_CH0_OFF;

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_GLB_CTRL.R = (uint32_t)(1U << shift);
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_GLB_CTRL.R = (uint32_t)(1U << shift);
    }

    return STATUS_SUCCESS;
}

/*
 * @brief TGC0 Host Trigger.
 *
 * @param[in] GTM_TOMn submodule.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_TGC0_HostTrigger_lld(GTM_TOM_Type GTM_TOMn)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[GTM_TOMn].TOM.TGC0_GLB_CTRL.B.HOST_TRIG = 1;

    return STATUS_SUCCESS;
}

/*
 * @brief TGC1 Host Trigger.
 *
 * @param[in] GTM_TOMn submodule.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_TGC1_HostTrigger_lld(GTM_TOM_Type GTM_TOMn)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[GTM_TOMn].TOM.TGC1_GLB_CTRL.B.HOST_TRIG = 1;

    return STATUS_SUCCESS;
}

/*
 * @brief TGC0 Host Select TimeBase.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] TimeBase TimeBase type.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_TGC0_SelectTimeBase_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_TimeBase_Type TimeBase)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[GTM_TOMn].TOM.TGC0_ACT_TB.B.TBU_SEL = (uint8_t)TimeBase;
    if(GTM4.GLS[GTM_TOMn].TOM.TGC0_ACT_TB.B.TBU_SEL != (uint8_t)TimeBase)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief TGC1 Host Select TimeBase.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] TimeBase TimeBase type.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_TGC1_SelectTimeBase_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_TimeBase_Type TimeBase)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[GTM_TOMn].TOM.TGC1_ACT_TB.B.TBU_SEL = (uint8_t)TimeBase;
    if(GTM4.GLS[GTM_TOMn].TOM.TGC1_ACT_TB.B.TBU_SEL != (uint8_t)TimeBase)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Set TGC0 Action Time.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] ActionTime Action Time.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_TGC0_SetActionTime_lld(GTM_TOM_Type GTM_TOMn,uint32_t ActionTime)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    uint32_t ActionTime_l = ActionTime;
    ActionTime_l = (0x00ffffffU & ActionTime_l);

    GTM4.GLS[GTM_TOMn].TOM.TGC0_ACT_TB.B.ACT_TB = ActionTime_l;
    if(GTM4.GLS[GTM_TOMn].TOM.TGC0_ACT_TB.B.ACT_TB != ActionTime_l)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Set TGC1 Action Time.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] ActionTime Action Time.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_TGC1_SetActionTime_lld(GTM_TOM_Type GTM_TOMn,uint32_t ActionTime)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    uint32_t ActionTime_l = ActionTime;
    ActionTime_l = (0x00ffffffU & ActionTime_l);

    GTM4.GLS[GTM_TOMn].TOM.TGC1_ACT_TB.B.ACT_TB = ActionTime_l;
    if(GTM4.GLS[GTM_TOMn].TOM.TGC1_ACT_TB.B.ACT_TB != ActionTime_l)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Force Update for reset CN0 enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableForceUpdateCN0Reset_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_FUPD_CTRL_RSTCN0_CH0_OFF;

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_FUPD_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC0_FUPD_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_FUPD_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC1_FUPD_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Force Update enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableForceUpdate_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_FUPD_CTRL_FUPD_CTRL0_OFF;

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_FUPD_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC0_FUPD_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_FUPD_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC1_FUPD_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Internal Trigger enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableInternalTrigger_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_INT_TRIG_INT_TRIG0_OFF;

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_INT_TRIG.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC0_INT_TRIG.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_INT_TRIG.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC1_INT_TRIG.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Update Value enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableUpdateValue_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_ENDIS_CTRL_ENDIS_CTRL0_OFF;

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_ENDIS_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC0_ENDIS_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_ENDIS_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC1_ENDIS_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Channel enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableChannel_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_ENDIS_STAT_ENDIS_STAT0_OFF;

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_ENDIS_STAT.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC0_ENDIS_STAT.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_ENDIS_STAT.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC1_ENDIS_STAT.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * @brief OutUpdate Value enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableOutUpdateValue_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_OUTEN_CTRL_OUTEN_CTRL0_OFF;

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_OUTEN_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC0_OUTEN_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_OUTEN_CTRL.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC1_OUTEN_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Out enable.
 *
 * @param[in] GTM_TOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_TOM_LLD_Channel_IsEnableOut_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_OUTEN_STAT_OUTEN_STAT0_OFF;

    if((uint8_t)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_OUTEN_STAT.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC0_OUTEN_STAT.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_OUTEN_STAT.R = (uint32_t)(IsEnable_l << shift);
        if(((GTM4.GLS[GTM_TOMn].TOM.TGC1_OUTEN_STAT.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
        {
            return STATUS_ERROR;
        }
    }

    return STATUS_SUCCESS;
}
#endif /* RESORUCE_SUPPORT_GTM410 */
