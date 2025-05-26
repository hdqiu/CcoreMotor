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
*   @file    Icu_Gtm_Tim_LLDrivers.c
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
#include "Icu_Autosar_Wrapper.h"
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_Gtm4_Tim_LLDrivers.h"
#ifdef RESORUCE_SUPPORT_GTM410
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_C                   176

#define ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_C                   4
#define ICU_GTM_TIM_LLDRIVERS_MINOR_VER_C                   4
#define ICU_GTM_TIM_LLDRIVERS_REVISION_VER_C                0

#define ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_C                1
#define ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_C                0
#define ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_C                1

#if (ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_C != ICU_GTM_TIM_LLDRIVERS_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_C != ICU_GTM_TIM_LLDRIVERS_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_MINOR_VER_C != ICU_GTM_TIM_LLDRIVERS_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_REVISION_VER_C != ICU_GTM_TIM_LLDRIVERS_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_C != ICU_GTM_TIM_LLDRIVERS_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_C != ICU_GTM_TIM_LLDRIVERS_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_C != ICU_GTM_TIM_LLDRIVERS_SW_PATCH_VER_H)
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
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR0.B.GPR0;
}



/*
 * @brief Get Input signal characteristic parameter 1.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @result = Input signal characteristic parameter 1.
 */
FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Ch_GetGPR1Parameter \
( \
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    return GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR1.B.GPR1;
}
/*
 * @brief CMU clock source select for channel.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] ClockSource CMU clock source.
 *
 * @result = Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelectClkSource \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_CLK_SEL_Type, AUTOMATIC) ClockSource \
)
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
 * @result = Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelFLCountFall \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterCounterMode_Type, AUTOMATIC) FilterCounterMode \
)
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
 * @result = Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelFLCountRise \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterCounterMode_Type, AUTOMATIC) FilterCounterMode \
)
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
 * @result = Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_ChSelFLModeFallEdge \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterMode_Type, AUTOMATIC) FilterMode \
)
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
 * @result = Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_ChSelFLModeRiseEdge \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterMode_Type, AUTOMATIC) FilterMode \
)
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

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableFL \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
)
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
 * @result = Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SelectGPRInput \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_GPRInput_Type, AUTOMATIC) GPR0, \
	VAR(GTM_TIM_GPRInput_Type, AUTOMATIC) GPR1 \
)
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
 * @brief TIM channel n mode.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 * @param[in] TIM_MODE TIM mode.
 *
 * @result = Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SetChannelMode \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_MODE_Type, AUTOMATIC) TIM_MODE \
)
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
 * @result = Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableChannel \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
)
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
 * @result = Interrupt Flag.
 */
FUNC(uint8, ICU_CODE) GTM_TIM_LLD_Ch_GetInterruptFlag \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt \
)
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
 * @result =  Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_ClearIntcFlag \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt \
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    switch(Interrupt)
    {
        case TIM_IRQ_GLITCHDET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GLITCHDET = 1u;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GLITCHDET != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_TODET:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.TODET = 1u;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.TODET != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_GPROFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GPROFL = 1u;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.GPROFL != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_CNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.CNTOFL = 1u;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.CNTOFL != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_ECNTOFL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.ECNTOFL = 1u;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.ECNTOFL != 0u)
            {
                return STATUS_ERROR;
            }
        break;
        case TIM_IRQ_NEWVAL:
            GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.NEWVAL = 1u;
            if(GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.B.NEWVAL != 0u)
            {
                return STATUS_ERROR;
            }
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
 * @result = Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntc \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_Interrupt_Type, AUTOMATIC) Interrupt, \
	VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable \
)
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
 * @brief Software reset of channel.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @result =  Operation status.
 */
FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_RstChannel \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn, \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn \
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    uint8_t  shift = (uint8_t)((uint8_t)CHn % 8U) + (uint8_t)GTM4_TIM_RST_RST_CH0_OFF;

    GTM4.GLS[GTM_TIMn].TIM.RST.R = (uint8_t)(1U << shift);

    return STATUS_SUCCESS;
}

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_SetFLCounFreq \
( \
	VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,  \
	VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn, \
	VAR(GTM_TIM_FilterCounterFrequency_Type, AUTOMATIC) FilterCounterFrequency \
)
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

/*
 * @brief Get Edge counter.
 *
 * @param[in] GTM_TIMn submodule.
 * @param[in] CHn Channel.
 *
 * @return Edge counter.
 */
FUNC(uint32_t, ICU_CODE) GTM_TIM_LLD_Channel_GetGPR0EdgeCounter(GTM_TIM_Type GTM_TIMn, GTM_TIM_Channel_Type CHn)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);


    P2CONST(st_GTM_TIM_tag, ICU_VAR, ICU_APPL_CONST) GTM_TIM_Reg_n = &GTM4.GLS[GTM_TIMn].TIM;


    return GTM_TIM_Reg_n->CH[CHn].GPR0.B.ECNT;
}
//====================================================================

FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetTBUSel
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,   \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,   \
    VAR(GTM_TIME_TBU_TS0_Type, AUTOMATIC) type   \
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.TBU0_SEL = (uint32)type;
}

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ActivationEdge
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,   \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,   \
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_IsEnable   \
)
{
    VAR(status_t, AUTOMATIC) result = (status_t)0U;
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.DSL = (uint32)u32Icu_IsEnable;
    
    if (GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.DSL != (uint32)u32Icu_IsEnable)
    {
        result = STATUS_ERROR;
    }

    return result;
}

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_CTRL_ISL
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,   \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,   \
    VAR(Icu_ValueType, AUTOMATIC) u32Icu_SingleLevel   \
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.ISL = (uint32)u32Icu_SingleLevel;

    if (GTM4.GLS[GTM_TIMn].TIM.CH[CHn].CTRL.B.ISL != (uint32)u32Icu_SingleLevel)
    {
        result = STATUS_ERROR;
    }

    return result;
}

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Channel_ClearInterruptNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,   \
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn   \
)
{
    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;
    if ((uint8_t)GTM_TIMn >= (uint8_t)GTM4_TIM_INSTANCE_NUM || (uint8_t)CHn >= (uint8_t)GTM4_TIM_CHANNEL_NUM)
    {
        result = STATUS_ERROR;
    }
    else
    {
        GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R;
    }

    return result;
}


FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntcEN
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GPT_GTM_Status_Type, AUTOMATIC) u32Icu_IsEnable
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.R = (uint8)u32Icu_IsEnable;
    
    if (GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_EN.R != (uint8)u32Icu_IsEnable)
    {
        result = STATUS_ERROR;
    }

    return result;
}

FUNC(status_t, ICU_CODE) GTM_TIM_LLD_Ch_IsEnableIntcNOTIFY
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GPT_GTM_Status_Type, AUTOMATIC) u32Icu_IsEnable
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    VAR(status_t, AUTOMATIC) result = STATUS_SUCCESS;

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R = (uint8)u32Icu_IsEnable;

    if (GTM4.GLS[GTM_TIMn].TIM.CH[CHn].IRQ_NOTIFY.R != (uint8)u32Icu_IsEnable)
    {
        result = STATUS_ERROR;
    }

    return result;
}

FUNC(uint32, ICU_CODE) GTM_TIM_LLD_Channel_GetAddress
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    VAR(uint32, AUTOMATIC) result = (uint32)&GTM4.GLS[GTM_TIMn].TIM.CH[CHn].GPR0.R;
    
    return result;
}

FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetFPFE
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(uint32, AUTOMATIC) parameter
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].FLT_FE.B.FLT_FE = parameter;
}

FUNC(void, ICU_CODE) GTM_TIM_LLD_Channel_SetFPRE
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(uint32, AUTOMATIC) parameter
)
{
    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

    GTM4.GLS[GTM_TIMn].TIM.CH[CHn].FLT_RE.B.FLT_RE = parameter;
}
FUNC(status_t, ICU_CODE) GTM_LLD_SetTimsel
(
    VAR(GTM_TIM_Type, AUTOMATIC) GTM_TIMn,
    VAR(GTM_TIM_Channel_Type, AUTOMATIC) CHn,
    VAR(GTM_TIM_Channel_Input_Selection_Type, AUTOMATIC) TIMIN_SEL
)
{
    VAR(uint32, AUTOMATIC) current_value;

    GTM4_TIM_DET_ERR((uint8_t)GTM_TIMn < (uint8_t)GTM4_TIM_INSTANCE_NUM);
    GTM4_TIM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TIM_CHANNEL_NUM);

current_value = GTM4.GLS[0].TIMINSEL[GTM_TIMn].R;

current_value &= ~(0xF << (CHn * 4u));

current_value |= (TIMIN_SEL << (CHn * 4u));

GTM4.GLS[0].TIMINSEL[GTM_TIMn].R = current_value;

    return STATUS_SUCCESS;
}

#endif /* RESORUCE_SUPPORT_GTM410 */
