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
*   @file    eMIOS_LLDriver.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eMIOS MCAL driver.
*
*   @addtogroup eMIOS
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "eMIOS_LLDriver.h"
#include "eMIOS_HAL_Irq.h"

#define EMIOS_LLD_C_VENDOR_ID                     176
#define EMIOS_LLD_C_AR_REL_MAJOR_VER              4
#define EMIOS_LLD_C_AR_REL_MINOR_VER              4
#define EMIOS_LLD_C_AR_REL_REV_VER                0
#define EMIOS_LLD_C_SW_MAJOR_VER                  1
#define EMIOS_LLD_C_SW_MINOR_VER                  0
#define EMIOS_LLD_C_SW_PATCH_VER                  1

#if (EMIOS_VENDOR_ID != EMIOS_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_VENDOR_ID "
#endif
#if (EMIOS_AR_REL_MAJOR_VER != EMIOS_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (EMIOS_AR_REL_MINOR_VER != EMIOS_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_AR_REL_MINOR_VER "
#endif
#if (EMIOS_AR_REL_REV_VER != EMIOS_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_AR_REL_REV_VER "
#endif
#if (EMIOS_SW_MAJOR_VER != EMIOS_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_SW_MAJOR_VER "
#endif
#if (EMIOS_SW_MINOR_VER != EMIOS_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_SW_MINOR_VER "
#endif
#if (EMIOS_SW_PATCH_VER != EMIOS_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_SW_PATCH_VER "
#endif

/*******************************************************************************
 * @brief eMIOS instance base address pointer array
 *******************************************************************************/
CONSTP2VAR(eMIOS_Type, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_BasePtr[EMIOS_INSTANCE_MAX] = EMIOS_BASE_PTR_ARRAY;

/*******************************************************************************
 * @brief Developer error judgment for eMIOS instance validation.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out] TRUE:   valid
 *              FALSE:  invalid
 *******************************************************************************/
FUNC(boolean, EMIOS_CODE) eMIOS_DevError_Instance(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    return ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) ? TRUE : FALSE);
}

/*******************************************************************************
 * @brief Developer error judgment for eMIOS channel number validation.
 *
 * @param u8eMIOS_ChanNum: channel number
 *        [out] TRUE:   valid
 *              FALSE:  invalid
 *******************************************************************************/
FUNC(boolean, EMIOS_CODE) eMIOS_DevError_ChanNum(VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(boolean, EMIOS_VAR) beMIOS_DevErrorRet = FALSE;

#if (defined(RESOURCE_SUPPORT_EMIOS0_CH0_7) || defined(RESOURCE_SUPPORT_EMIOS1_CH0_7))
    if (u8eMIOS_ChanNum <= 7U)
    {
        beMIOS_DevErrorRet = TRUE;
    }
#endif

#if (defined(RESOURCE_SUPPORT_EMIOS0_CH8_15) || defined(RESOURCE_SUPPORT_EMIOS1_CH8_15))
    if ((u8eMIOS_ChanNum >= 8U) && (u8eMIOS_ChanNum <= 15U))
    {
        beMIOS_DevErrorRet = TRUE;
    }
#endif

#if (defined(RESOURCE_SUPPORT_EMIOS0_CH16_23) || defined(RESOURCE_SUPPORT_EMIOS1_CH16_23))
    if ((u8eMIOS_ChanNum >= 16U) && (u8eMIOS_ChanNum <= 23U))
    {
        beMIOS_DevErrorRet = TRUE;
    }
#endif

#if (defined(RESOURCE_SUPPORT_EMIOS0_CH24_31) || defined(RESOURCE_SUPPORT_EMIOS1_CH24_31))
    if ((u8eMIOS_ChanNum >= 24U) && (u8eMIOS_ChanNum <= 31U))
    {
        beMIOS_DevErrorRet = TRUE;
    }
#endif
    return beMIOS_DevErrorRet;
}

/*******************************************************************************
 * @brief eMIOS global initialization.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        eMIOS_GlobalParamType: global parameter configuration pointer
 *******************************************************************************/
FUNC(void, EMIOS_CODE) eMIOS_LLD_InitGlobalParam \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    P2CONST(eMIOS_GlobalParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_GlobalParam \
)
{
    VAR(eMIOS_MCR_tag, EMIOS_VAR) uneMIOS_Tag;

    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPREN = 0U;
    }

    uneMIOS_Tag.R = 0U;

    uneMIOS_Tag.B.MDIS  = ((peMIOS_GlobalParam->LowPowerModeEn == TRUE) ? 1UL : 0UL);
    uneMIOS_Tag.B.FRZ   = ((peMIOS_GlobalParam->FreezeInDebugMode == TRUE) ? 1UL : 0UL);

    EMIOS_DEV_ERR((peMIOS_GlobalParam->GlobalPreClkDiv > 0U) && (peMIOS_GlobalParam->GlobalPreClkDiv <= (EMIOS_MCR_GPRE_MAX + 1U)));

    uneMIOS_Tag.B.GPRE  = ((uint32)peMIOS_GlobalParam->GlobalPreClkDiv - 1U);
    
    uneMIOS_Tag.B.ETB   = ((peMIOS_GlobalParam->ExternalTimeBaseSel == EMIOS_ETB_EN_COUNTER_BUSA_TO_STAC) ? 1UL : 0UL);
    uneMIOS_Tag.B.SRV   = (peMIOS_GlobalParam->ServerTimeSlotSel);

    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.R = uneMIOS_Tag.R;
    }
    
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetEnDisGlobal \
(\
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_EnDisGlobal \
)
{
   EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    /* Global prescaler enabled/disabled */
    eMIOS_MCR_SetGPREN(u8eMIOS_Index, beMIOS_EnDisGlobal);
    /* Global Time Base Enable Out signal asserted/negated */
    eMIOS_MCR_SetGTBE(u8eMIOS_Index, beMIOS_EnDisGlobal);
}

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetGLOTimebaseEnDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return eMIOS_MCR_GetGTBE(u8eMIOS_Index);
}

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetGLOPrescalerEnDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return eMIOS_MCR_GetGPREN(u8eMIOS_Index);
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetLowPowerMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_SwitchOnOff \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    eMIOS_MCR_SetMDIS(u8eMIOS_Index, beMIOS_SwitchOnOff);
}

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetLowPowerMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return eMIOS_MCR_GetMDIS(u8eMIOS_Index);
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetFreezeInDebugMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_FreezeStatus \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    eMIOS_MCR_SetFRZ(u8eMIOS_Index, beMIOS_FreezeStatus);
}

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetFreezeInDebugMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return eMIOS_MCR_GetFRZ(u8eMIOS_Index);
}

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetFlagSts_Ch \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return eMIOS_GFLAG_GetFLAGn(u8eMIOS_Index, u8eMIOS_ChanNum);
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetChOutputUPDEnDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateEnDis \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    if(beMIOS_OutUpdateEnDis == TRUE)
    {
        /* Transfer enabled: disabled bit -> disable */
        eMIOS_OUDIS_SetChNumOutUPDDis(u8eMIOS_Index, u8eMIOS_ChanNum, FALSE);
    }
    else
    {
        /* Transfer disable: disabled bit -> enable */
        eMIOS_OUDIS_SetChNumOutUPDDis(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);
    }
}

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetChNumOutUpdateDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return eMIOS_OUDIS_GetChNumOutUPDDis(u8eMIOS_Index, u8eMIOS_ChanNum);
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetAllChOutUPDEnDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateEnDis \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    if(beMIOS_OutUpdateEnDis == TRUE)
    {
        /* Transfer enabled: disabled bit -> disable */
        eMIOS_OUDIS_SetAllChOutUPDDis(u8eMIOS_Index, 0UL);
    }
    else
    {
        /* Transfer disable: disabled bit -> enable */
        eMIOS_OUDIS_SetAllChOutUPDDis(u8eMIOS_Index, 0xFF00FFUL);
    }
}

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetAllChOutUpdateDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return ((eMIOS_OUDIS_GetAllChOutUPDDis(u8eMIOS_Index) == 1U)?TRUE:FALSE);
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_DeInitChannel \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_LLD_UC_SetChannelClkEnDis(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);

    eMIOS_UC_Cn_SetCtrlCfg(u8eMIOS_Index, u8eMIOS_ChanNum, 0UL);
    eMIOS_UC_An_SetValue(u8eMIOS_Index, u8eMIOS_ChanNum, 0UL);
    eMIOS_UC_Bn_SetValue(u8eMIOS_Index, u8eMIOS_ChanNum, 0UL);
}

FUNC(status_t, EMIOS_CODE) eMIOS_LLD_UC_SetDebugMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_UcFreezeStatus \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    VAR(status_t, EMIOS_VAR) eeMIOS_Ret = STATUS_ERROR;

    if (beMIOS_UcFreezeStatus == TRUE)
    {
        if (eMIOS_MCR_GetFRZ(u8eMIOS_Index) == TRUE)
        {
            eMIOS_UC_Cn_SetFREN(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);
            eeMIOS_Ret = STATUS_SUCCESS;
        }
        else
        {
            eeMIOS_Ret = STATUS_EMIOS_ENABLE_GLOBAL_FRZ;
        }
    }
    else
    {
        eMIOS_UC_Cn_SetFREN(u8eMIOS_Index, u8eMIOS_ChanNum, FALSE);
        eeMIOS_Ret = STATUS_SUCCESS;
    }

    return eeMIOS_Ret;
}

/*******************************************************************************
 * @brief Enable/Disable Clock Prescaler.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        beMIOS_ClkEnDis: 0, 1 (Disable, Enable)
 *              FALSE: Disable
 *              TRUE: Enable
 *
 * @note  The UCPREN bit enables the prescaler counter.
 *          0: Prescaler disabled (no clock)
 *          1: Prescaler enabled
 *******************************************************************************/
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetChannelClkEnDis \
(\
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ClkEnDis \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Cn_SetUCPREN(u8eMIOS_Index, u8eMIOS_ChanNum, beMIOS_ClkEnDis);
}

/*******************************************************************************
 * @brief Clock Prescaler Disable status.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        [out] TRUE: Disable
 *              FALSE: Enable
 *******************************************************************************/
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_UC_GetChannelClkDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return ((eMIOS_UC_Cn_GetUCPREN(u8eMIOS_Index, u8eMIOS_ChanNum) == FALSE) ? TRUE : FALSE);
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetDMARequestEn \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Cn_SetFEN(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);
    eMIOS_UC_Cn_SetDMA(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)EMIOS_C_REQ_DMA);
}

FUNC(eMIOS_UC_IntDmaType, EMIOS_CODE) eMIOS_LLD_UC_GetDMAModeStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return ((eMIOS_UC_Cn_GetDMA(u8eMIOS_Index, u8eMIOS_ChanNum) == 1U)? EMIOS_C_REQ_DMA : EMIOS_C_REQ_INT);/*PRQA S 4342*/
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetIntcRequestEn \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Cn_SetFEN(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);
    eMIOS_UC_Cn_SetDMA(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)EMIOS_C_REQ_INT);
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetOutputLevel \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgeSel, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgePol \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Cn_SetEDSEL(u8eMIOS_Index, u8eMIOS_ChanNum, u8eMIOS_EdgeSel);
    eMIOS_UC_Cn_SetEDPOL(u8eMIOS_Index, u8eMIOS_ChanNum, u8eMIOS_EdgePol);
}

FUNC(uint8, EMIOS_CODE) eMIOS_LLD_UC_GetInputPinStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return eMIOS_UC_Sn_GetUCIN(u8eMIOS_Index, u8eMIOS_ChanNum);
}

FUNC(uint8, EMIOS_CODE) eMIOS_LLD_UC_GetOutputPinStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return eMIOS_UC_Sn_GetUCOUT(u8eMIOS_Index, u8eMIOS_ChanNum);
}

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_ClearFlag \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Sn_ClearFLAG(u8eMIOS_Index, u8eMIOS_ChanNum);
}

static FUNC(boolean, EMIOS_CODE) eMIOS_DevError_McMode(VAR(uint8, AUTOMATIC) u8eMIOS_Mode)
{
    VAR(boolean, EMIOS_VAR) beMIOS_Dev_t = (((u8eMIOS_Mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UP_MASK) ||
                    ((u8eMIOS_Mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UPDOWN_MASK) ||
                    ((u8eMIOS_Mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UP_MASK) ||
                    ((u8eMIOS_Mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UPDOWN_MASK));

    return beMIOS_Dev_t;
}

FUNC(status_t, EMIOS_CODE) eMIOS_LLD_MC_Init \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    P2CONST(eMIOS_MC_ParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_ParamPtr \
)
{
    VAR(status_t, EMIOS_VAR) eeMIOS_Ret = STATUS_SUCCESS;

    VAR(uint32, EMIOS_VAR) u32eMIOS_period = 0U;

    if ((((uint8)peMIOS_ParamPtr->mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UP_MASK) || \
       (((uint8)peMIOS_ParamPtr->mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UP_MASK))
    {
        /* MC mode: A register value will be "period" */

    	u32eMIOS_period = peMIOS_ParamPtr->period;
    }
    else if (((uint8)peMIOS_ParamPtr->mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UPDOWN_MASK)
    {
        /* MCB mode: A register value will be "period"/2 +1 */
        u32eMIOS_period =  ((peMIOS_ParamPtr->period >> 1UL) + 1UL);
    }
    else if (((uint8)peMIOS_ParamPtr->mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UPDOWN_MASK)
    {
        /* MC mode: A register value will be "period"/2 */
        u32eMIOS_period =  peMIOS_ParamPtr->period >> 1UL;
    }
    else
    {
        eeMIOS_Ret = STATUS_EMIOS_WRONG_PARAMETER;
    }

    if (eeMIOS_Ret == STATUS_SUCCESS)
    {
        /* Init mc mode */
        /* Cleared UC configure registers */
        eMIOS_LLD_UC_DeInitChannel(u8eMIOS_Index, u8eMIOS_ChanNum);    /* Disable u8eMIOS_ChanNum pre-scaler (reset default) */

        eMIOS_UC_An_SetValue(u8eMIOS_Index, u8eMIOS_ChanNum, u32eMIOS_period);

        /* Setup parammeter for external clock source */
        if (((uint8)peMIOS_ParamPtr->mode & 0x01U) == 1U)
        {
            eMIOS_UC_Cn_SetEDSEL(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)((((uint32)peMIOS_ParamPtr->trigger & 0x02U) == 0U) ? 0U : 1U));
            eMIOS_UC_Cn_SetEDPOL(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)((((uint32)peMIOS_ParamPtr->trigger & 0x01U) == 0U) ? 0U : 1U));
            eMIOS_UC_Cn_SetIF(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)peMIOS_ParamPtr->filter);
            eMIOS_UC_Cn_SetFCK(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)EMIOS_C_FCK_PRESCALED_CLK);
        }
        eMIOS_UC_Cn_SetUCPREN(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);     /* Enable pre-scaler */
        eMIOS_UC_Cn_SetMode(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)peMIOS_ParamPtr->mode);            /* Modulus Counter (Up ctr) */
        eMIOS_UC_Cn_SetUCPRE(u8eMIOS_Index, u8eMIOS_ChanNum, peMIOS_ParamPtr->divid);          /* Pre-scale u8eMIOS_ChanNum clock by divid +1 */
    }

    return eeMIOS_Ret;
}

FUNC(status_t, EMIOS_CODE) eMIOS_LLD_MC_SetPeriod \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_Period \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    VAR(status_t, EMIOS_VAR) eeMIOS_Ret = STATUS_SUCCESS;

    VAR(uint32, EMIOS_VAR) u32eMIOS_PeriodTemp;
    VAR(uint8, EMIOS_VAR) u8eMIOS_Mode = eMIOS_UC_Cn_GetMode(u8eMIOS_Index, u8eMIOS_ChanNum);

    if ((((uint8)u8eMIOS_Mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UP_MASK) || \
       (((uint8)u8eMIOS_Mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UP_MASK))
    {
        /* MC mode: A register value will be "period" */

        u32eMIOS_PeriodTemp = u32eMIOS_Period;
    }
    else if ((u8eMIOS_Mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UPDOWN_MASK)
    {
        /* MC mode: A register value will be "period"/2 */
        u32eMIOS_PeriodTemp = (u32eMIOS_Period >> 1UL);
    }
    else if (((u8eMIOS_Mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UPDOWN_MASK))
    {
        /* MCB mode: A register value will be "period"/2 + 1 */
        u32eMIOS_PeriodTemp =  ((u32eMIOS_Period >> 1UL) + 1UL);
    }
    else
    {
        eeMIOS_Ret = STATUS_EMIOS_WRONG_MODE;
    }

    if (eeMIOS_Ret == STATUS_SUCCESS)
    {
        eMIOS_UC_An_SetValue(u8eMIOS_Index, u8eMIOS_ChanNum, u32eMIOS_PeriodTemp);
    }

    return eeMIOS_Ret;
}

FUNC(uint32, EMIOS_CODE) eMIOS_LLD_MC_GetPeriod \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    VAR(uint32, EMIOS_VAR) u32eMIOS_Period = 0UL;
    VAR(uint8, EMIOS_VAR) u8eMIOS_Mode = eMIOS_UC_Cn_GetMode(u8eMIOS_Index, u8eMIOS_ChanNum);
    VAR(uint8, EMIOS_VAR) u8eMIOS_ModeSw;

    if(u8eMIOS_Mode == (uint8)EMIOS_UC_MODE_SAOC)
    {
        u8eMIOS_ModeSw = (uint8)EMIOS_UC_MODE_SAOC;
    }
    else
    {
        u8eMIOS_ModeSw = u8eMIOS_Mode & EMIOS_FILTER_MC_MASK;
    }

    switch(u8eMIOS_ModeSw)
    {
        case (uint8)EMIOS_UC_MODE_SAOC:
        case EMIOS_MC_UP_MASK:
        case EMIOS_MCB_UP_MASK:
            u32eMIOS_Period = eMIOS_UC_An_GetValue(u8eMIOS_Index, u8eMIOS_ChanNum);
            break;
        case EMIOS_MC_UPDOWN_MASK:
            u32eMIOS_Period = (eMIOS_UC_An_GetValue(u8eMIOS_Index, u8eMIOS_ChanNum) << 1UL);
            break;
        case EMIOS_MCB_UPDOWN_MASK:
            u32eMIOS_Period = ((eMIOS_UC_An_GetValue(u8eMIOS_Index, u8eMIOS_ChanNum) << 1UL) - 2UL);
            break;
        default:
            EMIOS_DEV_ERR(FALSE);
            break;
    }

    return u32eMIOS_Period;
}

FUNC(uint32, EMIOS_CODE) eMIOS_LLD_MC_GetInternalCounter \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    VAR(uint8, EMIOS_VAR) u8eMIOS_Mode = eMIOS_UC_Cn_GetMode(u8eMIOS_Index, u8eMIOS_ChanNum);
    VAR(boolean, EMIOS_VAR) temp = eMIOS_DevError_McMode(u8eMIOS_Mode);
    EMIOS_DEV_ERR(temp);
    (void)temp;
    return eMIOS_UC_CNTn_GetValue(u8eMIOS_Index, u8eMIOS_ChanNum);
}


#ifdef __cplusplus
}
#endif
