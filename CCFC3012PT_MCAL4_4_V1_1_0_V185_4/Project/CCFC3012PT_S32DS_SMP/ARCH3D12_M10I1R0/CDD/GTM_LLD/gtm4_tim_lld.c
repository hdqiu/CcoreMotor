/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM TIM low level drivers code
* HISTORY     : Initial version
* @file     gtm4_tim_lld.c
* @version  1.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0380,1296,1503,1317,1338,2016,2023,2024,4404,3469,2985 EOF*/

#include "gtm4_tim_lld.h"
#ifdef RESORUCE_SUPPORT_GTM410

/*
 * @brief Get Edge counter.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Edge counter.
 */
uint8_t GTM_TIM_LLD_Channel_GetGPR0EdgeCounter_lld(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR0.B.ECNT;
}

/*
 * @brief Get Input signal characteristic parameter 0.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Input signal characteristic parameter 0.
 */
uint32_t GTM_TIM_LLD_Channel_GetGPR0Parameter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR0.B.GPR0;
}

/*
 * @brief Get Edge counter.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Edge counter.
 */
uint8_t GTM_TIM_LLD_Channel_GetGPR1EdgeCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR1.B.ECNT;
}

/*
 * @brief Get Input signal characteristic parameter 1.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Input signal characteristic parameter 1.
 */
uint32_t GTM_TIM_LLD_Channel_GetGPR1Parameter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR1.B.GPR1;
}

/*
 * @brief Get Actual SMU counter value.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Actual SMU counter value.
 */
uint32_t GTM_TIM_LLD_Channel_GetCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CNT.B.CNT;
}

/*
 * @brief Get Edge counter.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Edge counter.
 */
uint8_t GTM_TIM_LLD_Channel_GetEdgeCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return (uint8_t)GTM4.GLS[GTM_TIMn].TIM.CH[CHn].ECNT.B.ECNT;
}

/*
 * @brief Get Edge counter.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Edge counter.
 */
uint8_t GTM_TIM_LLD_Channel_GetCNTSEdgeCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CNTS.B.ECNT;
}

/*
 * @brief Get Counter shadow register.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Counter shadow register.
 */
uint32_t GTM_TIM_LLD_Channel_GetCNTSShadowCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CNTS.B.CNTS;
}

/*
 * @brief Get Counter shadow register.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Counter shadow register.
 */
status_t GTM_TIM_LLD_Channel_SetCNTSShadowCounter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,uint32_t CNTS)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    if((GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_MODE != (uint8_t)TIM_MODE_TIPM) && (GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_MODE != (uint8_t)TIM_MODE_TBCM))
    {
        return STATUS_ERROR;
    }
    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CNTS.B.CNTS = CNTS;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CNTS.B.CNTS != CNTS)
    {
        return STATUS_ERROR;
    }
    return STATUS_SUCCESS;
}

/*
 * @brief Get Current Timeout value.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Current Timeout value.
 */
uint8_t GTM_TIM_LLD_Channel_GetTimeoutValue(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].TDUC.B.TO_CNT;
}

/*
 * @brief Timeout Clock selection.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] TimeoutClock Timeout Clock.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SelectTimeoutClock(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_TimeoutClock_Type TimeoutClock)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].TDUV.B.TCS = (uint8_t)TimeoutClock;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].TDUV.B.TCS != (uint8_t)TimeoutClock)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Time out duration.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Timeout Time out duration.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SetTimeout(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,uint8_t Timeout)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].TDUV.B.TOV = Timeout;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].TDUV.B.TOV != Timeout)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Filter parameter for rising edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterParameter Filter parameter.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SetFilterParameterRisingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,uint32_t FilterParameter)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].FLT_RE.B.FLT_RE = FilterParameter;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].FLT_RE.B.FLT_RE != FilterParameter)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Filter parameter for falling edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterParameter Filter parameter.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SetFilterParameterFallingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,uint32_t FilterParameter)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].FLT_FE.B.FLT_FE = FilterParameter;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].FLT_FE.B.FLT_FE != FilterParameter)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Timeout control.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] TimeoutControl Timeout control status.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SelectTimeoutControl(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_TimeoutControl_Type TimeoutControl)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TOCTRL = (uint8_t)TimeoutControl;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TOCTRL != (uint8_t)TimeoutControl)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief CMU clock source select for channel.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] ClockSource CMU clock source.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SelectClockSource(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_CLK_SEL_Type ClockSource)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.CLK_SEL = (uint8_t)ClockSource;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.CLK_SEL != (uint8_t)ClockSource)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Filter counter mode for falling edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterCounterMode Filter counter mode.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SelectFilterCounterModeFallingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterCounterMode_Type FilterCounterMode)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CTR_FE = (uint8_t)FilterCounterMode;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CTR_FE != (uint8_t)FilterCounterMode)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Filter counter mode for rising edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterCounterMode Filter counter mode.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SelectFilterCounterModeRisingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterCounterMode_Type FilterCounterMode)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CTR_RE = (uint8_t)FilterCounterMode;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CTR_RE != (uint8_t)FilterCounterMode)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Filter mode for falling edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterMode Filter mode.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SelectFilterModeFallingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterMode_Type FilterMode)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_MODE_FE = (uint8_t)FilterMode;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_MODE_FE != (uint8_t)FilterMode)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Filter mode for rising edge.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterMode Filter mode.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SelectFilterModeRisingEdge(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterMode_Type FilterMode)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_MODE_RE = (uint8_t)FilterMode;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_MODE_RE != (uint8_t)FilterMode)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Enables external capture mode.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_IsEnableExternalCapture(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.EXT_CAP_EN = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.EXT_CAP_EN != (uint8_t)IsEnable)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Filter counter frequency select.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] FilterCounterFrequency Filter counter frequency.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SetFilterCounterFrequency(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_FilterCounterFrequency_Type FilterCounterFrequency)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CNT_FRQ = (uint8_t)FilterCounterFrequency;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_CNT_FRQ != (uint8_t)FilterCounterFrequency)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

status_t GTM_TIM_LLD_Channel_IsEnableFilter(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_EN = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.FLT_EN != (uint8_t)IsEnable)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Selection for GPR register.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] GPR0 GPR0 input type.
 * @param[in] GPR1 GPR1 input type.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SelectGPRInput(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_GPRInput_Type GPR0,GTM_TIM_GPRInput_Type GPR1)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.GPR0_SEL = (uint8_t)GPR0;
    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.GPR1_SEL = (uint8_t)GPR1;
    if((GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.GPR0_SEL != (uint8_t)GPR0) || (GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.GPR1_SEL != (uint8_t)GPR1))
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief GPR0 and GPR1 register values routed to ARU.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable Enable status..
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_IsEnableARU(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.ARU_EN = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.ARU_EN != (uint8_t)IsEnable)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief One-shot mode.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_IsEnableOneShotMode(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.OSM = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.OSM != (uint8_t)IsEnable)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief TIM channel n mode.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] TIM_MODE TIM mode.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_SetChannelMode(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_MODE_Type TIM_MODE)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_MODE = (uint8_t)TIM_MODE;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_MODE != (uint8_t)TIM_MODE)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief TIM channel n enable.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_IsEnableChannel(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_IsEnable_Type IsEnable)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_EN = (uint8_t)IsEnable;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TIM_EN != (uint8_t)IsEnable)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Get Interrupt Flag.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @return Interrupt Flag.
 */
uint8_t GTM_TIM_LLD_Channel_GetInterruptFlag(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_Interrupt_Type Interrupt)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    switch(Interrupt)
    {
        case TIM_IRQ_GLITCHDET:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GLITCHDET;

        case TIM_IRQ_TODET:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.TODET;

        case TIM_IRQ_GPROFL:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GPROFL;

        case TIM_IRQ_CNTOFL:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.CNTOFL;

        case TIM_IRQ_ECNTOFL:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.ECNTOFL;

        case TIM_IRQ_NEWVAL:
            return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.NEWVAL;

        default:
                break;
    }
    return 0U;
}

/*
 * @brief Clear Interrupt Flag.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @return  Operation status.
 */
status_t GTM_TIM_LLD_Channel_ClearInterruptFlag(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_Interrupt_Type Interrupt)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    switch(Interrupt)
    {
        case TIM_IRQ_GLITCHDET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_GLITCHDET;
        break;
        case TIM_IRQ_TODET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_TODET;
        break;
        case TIM_IRQ_GPROFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_GPROFL;
        break;
        case TIM_IRQ_CNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_CNTOFL;
        break;
        case TIM_IRQ_ECNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_ECNTOFL;
        break;
        case TIM_IRQ_NEWVAL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = CH_IRQ_NOTIFY_MASK_NEWVAL;
        break;
        default:
            return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief TIM_TODETn_IRQ interrupt enable.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status.
 */
status_t GTM_TIM_LLD_Channel_IsEnableInterrupt(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_Interrupt_Type Interrupt,GTM_IsEnable_Type IsEnable)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    switch(Interrupt)
    {
        case TIM_IRQ_GLITCHDET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.GLITCHDET_IRQ_EN = (uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.GLITCHDET_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_TODET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.TODET_IRQ_EN = (uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.TODET_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_GPROFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.GPROFL_IRQ_EN = (uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.GPROFL_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_CNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.CNTOFL_IRQ_EN =(uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.CNTOFL_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_ECNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.ECNTOFL_IRQ_EN = (uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.ECNTOFL_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_NEWVAL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.NEWVAL_IRQ_EN = (uint8_t)IsEnable;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.B.NEWVAL_IRQ_EN != (uint8_t)IsEnable)
            {
                return STATUS_ERROR;
            }
        break;
        default:
        break;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Force Interrupt.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] Interrupt Interrupt type.
 *
 * @return  Operation status.
 */
status_t GTM_TIM_LLD_Channel_ForceInterrupt(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_TIM_Interrupt_Type Interrupt)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    switch(Interrupt)
    {
        case TIM_IRQ_GLITCHDET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_FORCINT.B.TRG_GLITCHDET = 1u;
        break;
        case TIM_IRQ_TODET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_FORCINT.B.TRG_TODET = 1u;
        break;
        case TIM_IRQ_GPROFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_FORCINT.B.TRG_GPROFL = 1u;
        break;
        case TIM_IRQ_CNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_FORCINT.B.TRG_CNTOFL = 1u;
        break;
        case TIM_IRQ_ECNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_FORCINT.B.TRG_ECNTOFL = 1u;
        break;
        case TIM_IRQ_NEWVAL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_FORCINT.B.TRG_NEWVAL = 1u;
        break;
        default:
            return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief IRQ mode selection.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] InterruptMode Interrupt mode.
 *
 * @return  Operation status.
 */
status_t GTM_TIM_LLD_Channel_SelectInterruptMode(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn,GTM_InterruptMode_Type InterruptMode)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_MODE.B.IRQ_MODE = (uint8_t)InterruptMode;
    if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_MODE.B.IRQ_MODE != (uint8_t)InterruptMode)
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Software reset of channel.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return  Operation status.
 */
status_t GTM_TIM_LLD_Channel_ResetChannel(GTM_TIM_Type GTM_TIMn,GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    uint8_t  shift = (uint8_t)((uint8_t)CHn % 8U) + (uint8_t)GTM4_TIM_RST_RST_CH0_OFF;

    GTM4.GLS[GTM_TIMn].TIM.RST.R = (uint32_t)(1U << shift);

    return STATUS_SUCCESS;
}

status_t GTM_LLD_SetTimsel_lld(GTM_TIM_Type GTM_TIMn, GTM_TIM_Channel_Type CHn, uint32_t TIMIN_SEL)
{
    GTM4.GLS[0].TIMINSEL[GTM_TIMn].R = TIMIN_SEL << ((uint32_t)CHn * 4u);

    return STATUS_SUCCESS;
}
#endif /* RESORUCE_SUPPORT_GTM410 */
