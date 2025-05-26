/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM ATOM low level drivers code
* HISTORY     : Initial version
* @file     gtm4_atom_lld.c
* @version  1.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0380,1317,1503,1296,1338,2016,2023,2024,4442,2985 EOF*/
 /*PRQA S 4404,3469 EOF*/
#include "gtm4_atom_lld.h"
#ifdef RESORUCE_SUPPORT_GTM410

/*
 * @brief ARU Read address.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] ReadAddress0  ARU Read address 0.
 * @param[in] ReadAddress1  ARU Read address 1.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SetReadAddress_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint16_t ReadAddress0,uint16_t ReadAddress1)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].RDADDR.B.RDADDR0 = (uint8_t)ReadAddress0;
    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].RDADDR.B.RDADDR1 = (uint8_t)ReadAddress1;
    if((GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].RDADDR.B.RDADDR0 != (uint8_t)ReadAddress0) || (GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].RDADDR.B.RDADDR1 != (uint8_t)ReadAddress1))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief ARU blocking mode.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable  Enable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableARUBlockMode_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.ARU_EN = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.ARU_EN != (uint8_t)IsEnable)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief One-shot mode.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable  Enable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableOneShotMode_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.OSM = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.OSM != (uint8_t)IsEnable)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] TriggerOutput  Trigger source.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SelectTriggerOutput_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_TriggerOutput_Type TriggerOutput)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.TRIGOUT = (uint8_t)TriggerOutput;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.TRIGOUT != (uint8_t)TriggerOutput)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Reset source of CCU0.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] ResetSource  Reset source.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SelectCCU0ResetSource_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_ResetSource_Type ResetSource)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.RST_CCU0 = (uint8_t)ResetSource;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.RST_CCU0 != (uint8_t)ResetSource)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP).
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] ClockSource clock source.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SelectClockSource_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_ClockSource_Type ClockSource)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.CLK_SRC_SR = (uint8_t)ClockSource;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.CLK_SRC_SR != (uint8_t)ClockSource)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief GET Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP).
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 *
 * @return ClockSource clock source.
 */
GTM_ATOM_ClockSource_Type GTM_ATOM_LLD_Channel_GetClockSource_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    return GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.CLK_SRC_SR;
}

/*
 * @brief Initial signal level after channel enable.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] SignalLevel signal level.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SelectSignalLevel_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_SignalLevel_Type SignalLevel)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.SL = (uint8_t)SignalLevel;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.SL != (uint8_t)SignalLevel)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}


/*
 * @brief CCUn compare strategy select.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] CompareStrategy compare strategy.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SelectCompareStrategy_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_CompareStrategy_Type CompareStrategy)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.CMP_CTRL = (uint8_t)CompareStrategy;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.CMP_CTRL != (uint8_t)CompareStrategy)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief ATOM Mode control bits.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] ACBbits ATOM Mode control bits.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SetACBbits_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint8_t ACBbits)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.ACB = ACBbits;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.ACB != ACBbits)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief ARU Input stream enable.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableARU_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.ARU_EN = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.ARU_EN != (uint8_t)IsEnable)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Select time base value TBU_TS1 or TBU_TS2.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] TimeBase TBU_TS1 or TBU_TS2.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SelectTB12TimeBase_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_TB12TimeBase_Type TimeBase)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.TB12_SEL = (uint8_t)TimeBase;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.TB12_SEL != (uint8_t)TimeBase)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief ATOM channel mode select.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Mode channel mode.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Mode_Type Mode)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.MODE = (uint8_t)Mode;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CTRL.B.MODE != (uint8_t)Mode)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Set Shadow Register value.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] SR0 Shadow Register0 value.
 * @param[in] SR1 Shadow Register1 value.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint32_t SR0,uint32_t SR1)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].SR0.R = SR0;
    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].SR1.R = SR1;
//    if((GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].SR0.R != SR0) || (GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].SR1.R != SR1))
//    {
//        return STATUS_ERROR;
//    }

    return STATUS_SUCCESS;
}

/*
 * @brief Set compare Register value.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] CM0 compare Register0 value.
 * @param[in] CM1 compare Register1 value.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SetCompareRegister_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint32_t CM0,uint32_t CM1)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CM0.B.CM0 = CM0;
    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CM1.B.CM1 = CM1;
    if((GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CM0.B.CM0 != CM0) || (GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CM1.B.CM1 != CM1))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Get Counter Register value.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Counter Register value.
 */
status_t GTM_ATOM_LLD_Channel_SetCounter_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint32_t CN0)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    CN0 = ((uint32_t)0x00ffffff & CN0);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CN0.B.CN0 = CN0;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].CN0.B.CN0 != CN0)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Get Output Level.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Output Level.
 */
uint8_t GTM_ATOM_LLD_Channel_GetOutputLevel_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    return GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].STAT.B.OL;
}

/*
 * @brief Get Interrupt Flag.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @return Interrupt Flag status.
 */
uint8_t GTM_ATOM_LLD_Channel_GetInterruptFlag_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Interrupt_Type Interrupt)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    if(Interrupt == ATOM_IRQ_CCU0TC)
    {
        return GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_NOTIFY.B.CCU0TC;
    }else if(Interrupt == ATOM_IRQ_CCU1TC)
    {
        return GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_NOTIFY.B.CCU1TC;
    }else
    {
        return 0U;
    }
}

/*
 * @brief Clear Interrupt Flag.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_ClearInterruptFlag_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Interrupt_Type Interrupt)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    if(Interrupt == ATOM_IRQ_CCU0TC)
    {
        GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_NOTIFY.R = 1U;
    }else if(Interrupt == ATOM_IRQ_CCU1TC)
    {
        GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_NOTIFY.R = 2U;
    }else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Interrupt enable.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableInterrupt_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Interrupt_Type Interrupt,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    if(Interrupt == ATOM_IRQ_CCU0TC)
    {
        GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_EN.B.CCU0TC_IRQ_EN = (uint8_t)IsEnable;
        if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_EN.B.CCU0TC_IRQ_EN != (uint8_t)IsEnable)
        {
            return STATUS_ERROR;
        }
    }else if(Interrupt == ATOM_IRQ_CCU1TC)
    {
        GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_EN.B.CCU1TC_IRQ_EN = (uint8_t)IsEnable;
        if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_EN.B.CCU1TC_IRQ_EN != (uint8_t)IsEnable)
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
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_ForceInterrupt_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Interrupt_Type Interrupt)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    if(Interrupt == ATOM_IRQ_CCU0TC)
    {
        GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_FORCINT.B.TRG_CCU0TC = 1u;
    }else if(Interrupt == ATOM_IRQ_CCU1TC)
    {
        GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_FORCINT.B.TRG_CCU1TC = 1u;
    }else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Select Interrupt Mode.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] InterruptMode Interrupt mode.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_SelectInterruptMode_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_InterruptMode_Type InterruptMode)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_MODE.B.IRQ_MODE = (uint8_t)InterruptMode;
    if(GTM4.GLS[GTM_ATOMn].ATOM.CH[CHn].IRQ_MODE.B.IRQ_MODE != (uint8_t)InterruptMode)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Update enable.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableUpdate_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_GLB_CTRL_UPEN_CTRL0_OFF;

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.GLB_CTRL.R = (uint32_t)(IsEnable_l << shift);
    if(((GTM4.GLS[GTM_ATOMn].ATOM.AGC.GLB_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Reset Channel.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_ResetChannel_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    uint8_t  shift = ((uint8_t)CHn % 8U) + (uint8_t)GTM4_ATOM_AGC_GLB_CTRL_RST_CH0_OFF;

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.GLB_CTRL.R = (uint32_t)(1U << shift);

    return STATUS_SUCCESS;
}

/*
 * @brief TGC0 Host Trigger.
 *
 * @param[in] GTM_ATOMn submodule.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_AGC_HostTrigger_lld(GTM_ATOM_Type GTM_ATOMn)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.GLB_CTRL.B.HOST_TRIG = 1;

    return STATUS_SUCCESS;
}

/*
 * @brief TGC0 Host Select TimeBase.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] TimeBase TimeBase type.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_AGC_SelectTimeBase_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_TimeBase_Type TimeBase)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.ACT_TB.B.TBU_SEL = (uint8_t)TimeBase;
    if(GTM4.GLS[GTM_ATOMn].ATOM.AGC.ACT_TB.B.TBU_SEL != (uint8_t)TimeBase)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}


/*
 * @brief Set TGC0 Action Time.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] ActionTime Action Time.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_AGC_SetActionTime_lld(GTM_ATOM_Type GTM_ATOMn,uint32_t ActionTime)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.ACT_TB.B.ACT_TB = ActionTime;
    if(GTM4.GLS[GTM_ATOMn].ATOM.AGC.ACT_TB.B.ACT_TB != ActionTime)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Force Update enable.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableForceUpdateCN0Reset_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_FUPD_CTRL_RSTCN0_CH0_OFF;

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R = (uint32_t)(IsEnable_l << shift);
    if(((GTM4.GLS[GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

status_t GTM_ATOM_LLD_Channel_IsEnableForceUpdate_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = ((uint8_t)CHn * 2U) + (uint8_t)GTM4_ATOM_AGC_FUPD_CTRL_FUPD_CTRL0_OFF;

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R = (uint32_t)(IsEnable_l << shift);
    if(((GTM4.GLS[GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}
/*
* @brief Internal Trigger enable.
*
* @param[in] GTM_ATOMn submodule.
* @param[in] CHn Channel.
* @param[in] IsEnable IsEnable status.
*
* @return Operation status.
*/
status_t GTM_ATOM_LLD_Channel_IsEnableInternalTrigger_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = ((uint8_t)CHn * 2U) + (uint8_t)GTM4_ATOM_AGC_INT_TRIG_INT_TRIG0_OFF;

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.INT_TRIG.R = (uint32_t)(IsEnable_l << shift);
    if(((GTM4.GLS[GTM_ATOMn].ATOM.AGC.INT_TRIG.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Update Value enable.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableUpdateValue_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = ((uint8_t)CHn * 2U) + (uint8_t)GTM4_ATOM_AGC_ENDIS_CTRL_ENDIS_CTRL0_OFF;

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.ENDIS_CTRL.R = (uint32_t)(IsEnable_l << shift);
    if(((GTM4.GLS[GTM_ATOMn].ATOM.AGC.ENDIS_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Channel enable.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableChannel_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_ENDIS_STAT_ENDIS_STAT0_OFF;

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.ENDIS_STAT.R |= (uint32_t)(IsEnable_l << shift);
    if(((GTM4.GLS[GTM_ATOMn].ATOM.AGC.ENDIS_STAT.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}


/*
 * @brief OutUpdate Value enable.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableOutUpdateValue_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_OUTEN_CTRL_OUTEN_CTRL0_OFF;

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.OUTEN_CTRL.R = (uint32_t)(IsEnable_l << shift);
    if(((GTM4.GLS[GTM_ATOMn].ATOM.AGC.OUTEN_CTRL.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Out enable.
 *
 * @param[in] GTM_ATOMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable IsEnable status.
 *
 * @return Operation status.
 */
status_t GTM_ATOM_LLD_Channel_IsEnableOut_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_ATOM_DET_ERR((uint8_t)GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    uint8_t IsEnable_l = (uint8_t)IsEnable;

    if(IsEnable_l  == 1u)
    {
        IsEnable_l = 2u;
    }
    else
    {
        IsEnable_l = 1u;
    }

    uint8_t  shift = (((uint8_t)CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_OUTEN_STAT_OUTEN_STAT0_OFF;

    GTM4.GLS[GTM_ATOMn].ATOM.AGC.OUTEN_STAT.R |= (uint32_t)(IsEnable_l << shift);
    if(((GTM4.GLS[GTM_ATOMn].ATOM.AGC.OUTEN_STAT.R >> shift) & 0x3u) != ((IsEnable_l == 1u)?(0u):(3u)))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}
#endif /* RESORUCE_SUPPORT_GTM410 */
