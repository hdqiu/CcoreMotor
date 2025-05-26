/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc_LLDriver.c
* @version  1.0
* @date     2023 - 09 - 01
* @brief    Initial version.
*
*****************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

#include "SDAdc.h"
#include "SDAdc_LLDriver.h"        /* PRQA S 0380,4095*/
#include "intc_lld.h"
#include "eDma.h"
#include "SchM_Sdadc.h"
#include "common.h"

#ifdef RESOURCE_SUPPORT_SDADC_IP

#define SDADC_LLD_C_VENDOR_ID                     176
#define SDADC_LLD_C_AR_REL_MAJOR_VER              4
#define SDADC_LLD_C_AR_REL_MINOR_VER              4
#define SDADC_LLD_C_AR_REL_REV_VER                0
#define SDADC_LLD_C_SW_MAJOR_VER                  1
#define SDADC_LLD_C_SW_MINOR_VER                  0
#define SDADC_LLD_C_SW_PATCH_VER                  1

#if (SDADC_CFG_H_VENDOR_ID               != SDADC_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_LLD_C_VENDOR_ID "
#endif
#if (SDADC_CFG_H_AR_REL_MAJOR_VER    != SDADC_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_MINOR_VER    != SDADC_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_AR_REL_MINOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_REV_VER != SDADC_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_AR_REL_REV_VER "
#endif
#if (SDADC_CFG_H_SW_MAJOR_VER        != SDADC_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_SW_MAJOR_VER "
#endif
#if (SDADC_CFG_H_SW_MINOR_VER        != SDADC_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_SW_MINOR_VER "
#endif
#if (SDADC_CFG_H_SW_PATCH_VER        != SDADC_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_SW_PATCH_VER "
#endif


static FUNC(uint32, SDADC_CODE) SDADC_LLD_CalculateGain(CONST(Sdadc_InstanceType, SDADC_CONST) instance);
static FUNC(uint32, SDADC_CODE) SDADC_LLD_CalculateOffset(CONST(Sdadc_InstanceType, SDADC_CONST) instance, VAR(uint32, SDADC_VAR) gainVal);

static CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) Adc_SdadcBase[ADC_SDADC_MAX_INSTANCE] = SDADC_BASE_PTR_ARRAY;

FUNC(void, SDADC_CODE) SDADC_LLD_Init \
(
    CONST(Sdadc_InstanceType, SDADC_CONST) instance, \
    CONSTP2CONST(Sdadc_ConfigType, SDADC_CONST, SDADC_APPL_CONST) ConfigPtr, \
    CONST(uint16, SDADC_CONST) Trig_Sel
)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    DEV_ASSERT(ConfigPtr != NULL);

    VAR(uint8, SDADC_VAR) u8inst = (uint8)instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[u8inst];

    VAR(uint32, SDADC_VAR) gain_cal_val, offset_cal_val = 0U;
#ifdef CCFC3007PT
    P2VAR(uint32, SDADC_VAR, SDADC_APPL_CONST) SDAdc_MSCR[ADC_SDADC_MAX_INSTANCE] =
    {
        (uint32 *)(0xfffc0b88U), //SIUL2_MSCR[594] 
        (uint32 *)(0xfffc0b8cU), //SIUL2_MSCR[595] 
        (uint32 *)(0xfffc0b90U), //SIUL2_MSCR[596] 
        (uint32 *)(0xfffc0b94U), //SIUL2_MSCR[597] 
        (uint32 *)(0xfffc0b98U), //SIUL2_MSCR[598] 
        (uint32 *)(0xfffc0b9CU), //SIUL2_MSCR[599] 
        (uint32 *)(0xfffc0ba0U), //SIUL2_MSCR[600] 
        (uint32 *)(0xfffc0ba4U), //SIUL2_MSCR[601] 
        (uint32 *)(0xfffc0ba8U), //SIUL2_MSCR[602]     
    };
    VAR(Sdadc_HwTrigSourceType, SDADC_VAR) SDAdc_HwTrigMap[] =
    {
        TOM2_4_SOURCE,
        TOM2_5_SOURCE,
        TOM2_6_SOURCE,
        TOM2_7_SOURCE,
        TOM2_8_SOURCE,
        TOM2_9_SOURCE,
        TOM2_10_SOURCE,
        TOM2_11_SOURCE,
        ATOM3_0_SOURCE,
        ATOM3_1_SOURCE,
        ATOM3_2_SOURCE,
        ATOM3_3_SOURCE,
        ATOM3_4_SOURCE,
        ATOM3_5_SOURCE,
        ATOM3_6_SOURCE,
        ATOM3_7_SOURCE,
    };
#endif
#ifdef CCFC3012PT
#ifdef RESOURCE_SUPPORT_SIUL2_IP
    P2VAR(uint32, SDADC_VAR, SDADC_APPL_CONST) SDAdc_MSCR[ADC_SDADC_MAX_INSTANCE] =
    {
        (uint32 *)SIUL_ISEL_SDADC0_ADDR,  //SIUL_ISEL[13]:[0:7]
		(uint32 *)SIUL_ISEL_SDADC1_ADDR,  //SIUL_ISEL[13]:[8:15] 
		(uint32 *)SIUL_ISEL_SDADC2_ADDR,  //SIUL_ISEL[13]:[16:23] 
		(uint32 *)SIUL_ISEL_SDADC3_ADDR,  //SIUL_ISEL[13]:[24:31] 
		(uint32 *)SIUL_ISEL_SDADC4_ADDR,  //SIUL_ISEL[14]:[0:7] 
		(uint32 *)SIUL_ISEL_SDADC5_ADDR,  //SIUL_ISEL[14]:[8:15] 
		(uint32 *)SIUL_ISEL_SDADC6_ADDR,  //SIUL_ISEL[14]:[16:23] 
		(uint32 *)SIUL_ISEL_SDADC7_ADDR,  //SIUL_ISEL[14]:[24:31] 
		(uint32 *)SIUL_ISEL_SDADC8_ADDR,  //SIUL_ISEL[15]:[0:7] 
		(uint32 *)SIUL_ISEL_SDADC9_ADDR,  //SIUL_ISEL[15]:[8:15] 
		(uint32 *)SIUL_ISEL_SDADC10_ADDR, //SIUL_ISEL[15]:[16:23] 
		(uint32 *)SIUL_ISEL_SDADC11_ADDR, //SIUL_ISEL[15]:[24:31] 
		(uint32 *)SIUL_ISEL_SDADC12_ADDR, //SIUL_ISEL[16]:[0:7] 
		(uint32 *)SIUL_ISEL_SDADC13_ADDR, //SIUL_ISEL[16]:[8:15] 
    };
#endif
    VAR(Sdadc_HwTrigSourceType, SDADC_VAR) SDAdc_HwTrigMap[] =
    {
        SDADC_GTM_TRIG0_BIT0,
        SDADC_GTM_TRIG0_BIT1,
        SDADC_GTM_TRIG0_BIT2,
        SDADC_GTM_TRIG0_BIT3,
        SDADC_GTM_TRIG0_BIT4,
        SDADC_GTM_TRIG0_BIT5,
        SDADC_GTM_TRIG0_BIT6,
        SDADC_GTM_TRIG0_BIT7,
        SDADC_GTM_TRIG0_BIT8,
        SDADC_GTM_TRIG0_BIT9,
        SDADC_GTM_TRIG0_BIT10,
        SDADC_GTM_TRIG0_BIT11,
        SDADC_GTM_TRIG0_BIT12,
        SDADC_GTM_TRIG0_BIT13,
        SDADC_GTM_TRIG1_BIT0,
        SDADC_GTM_TRIG1_BIT1,
        SDADC_GTM_TRIG1_BIT2,
        SDADC_GTM_TRIG1_BIT3,
        SDADC_GTM_TRIG1_BIT4,
        SDADC_GTM_TRIG1_BIT5,
        SDADC_GTM_TRIG1_BIT6,
        SDADC_GTM_TRIG1_BIT7,
        SDADC_GTM_TRIG1_BIT8,
        SDADC_GTM_TRIG1_BIT9,
        SDADC_GTM_TRIG1_BIT10,
        SDADC_GTM_TRIG1_BIT11,
        SDADC_GTM_TRIG1_BIT12,
        SDADC_GTM_TRIG1_BIT13,
        SDADC_GTM_TRIG2_BIT0,
        SDADC_GTM_TRIG2_BIT1,
        SDADC_GTM_TRIG2_BIT2,
        SDADC_GTM_TRIG2_BIT3,
        SDADC_GTM_TRIG2_BIT4,
        SDADC_GTM_TRIG2_BIT5,
        SDADC_GTM_TRIG2_BIT6,
        SDADC_GTM_TRIG2_BIT7,
        SDADC_GTM_TRIG2_BIT8,
        SDADC_GTM_TRIG2_BIT9,
        SDADC_GTM_TRIG2_BIT10,
        SDADC_GTM_TRIG2_BIT11,
        SDADC_GTM_TRIG2_BIT12,
        SDADC_GTM_TRIG2_BIT13,
        SDADC_GTM_TRIG3_BIT0,
        SDADC_GTM_TRIG3_BIT1,
        SDADC_GTM_TRIG3_BIT2,
        SDADC_GTM_TRIG3_BIT3,
        SDADC_GTM_TRIG3_BIT4,
        SDADC_GTM_TRIG3_BIT5,
        SDADC_GTM_TRIG3_BIT6,
        SDADC_GTM_TRIG3_BIT7,
        SDADC_GTM_TRIG3_BIT8,
        SDADC_GTM_TRIG3_BIT9,
        SDADC_GTM_TRIG3_BIT10,
        SDADC_GTM_TRIG3_BIT11,
        SDADC_GTM_TRIG3_BIT12,
        SDADC_GTM_TRIG3_BIT13,
        SDADC_TRIG_PAD15,
        SDADC_TRIG_PAD3,
        SDADC_TRIG_PAD6,
        SDADC_TRIG_PAD9,
        SDADC_TRIG_PAD16,
        SDADC_TRIG_PAD26,
        SDADC_TRIG_PAD27,
        SDADC_TRIG_PAD28,
        SDADC_TRIG_PAD29,
        SDADC_TRIG_PAD30,
        SDADC_TRIG_PAD31,
        SDADC_TRIG_PAD17,
        SDADC_TRIG_PAD19,
        SDADC_TRIG_PAD20,
        SDADC_TRIG_PAD23,
        SDADC_TRIG_PAD44,
        SDADC_TRIG_PAD45,
        SDADC_TRIG_PAD46,
        SDADC_TRIG_PAD47,
        SDADC_TRIG_PAD38,
        SDADC_TRIG_PAD39,
        SDADC_TRIG_PAD40,
        SDADC_TRIG_PAD241,
        SDADC_TRIG_PAD242,
        SDADC_TRIG_PAD243,
        SDADC_TRIG_PAD245,
        SDADC_TRIG_PAD246,
        SDADC_TRIG_PAD247,
    };
#endif
#ifdef RESOURCE_SUPPORT_SIUL2_IP
    P2VAR(uint32, SDADC_VAR, SDADC_APPL_DATA) MSCRPtr = SDAdc_MSCR[instance];
#endif
    DEV_ASSERT((ConfigPtr->AnalogCfg.PreGain == SDADC_PRE_GAIN_X1) || \
               (ConfigPtr->AnalogCfg.PreGain == SDADC_PRE_GAIN_X2) || \
               (ConfigPtr->AnalogCfg.PreGain == SDADC_PRE_GAIN_X4));
    DEV_ASSERT((uint8)(ConfigPtr->AnalogCfg.VcomSel) <= (uint8)SDADC_VCOM_SEL_VREF_L);
    DEV_ASSERT((uint8)(ConfigPtr->AnalogCfg.ClkDiv) <= (uint8)SDADC_CLK_DIV_8);

    SchM_Enter_SDADC_EXCLUSIVE_AREA_00();

    /* Analog Module PRE configuration */
    SDADC_ATT_SetAnalogModuleCfg(BasePtr, 1U, (uint8)(ConfigPtr->AnalogCfg.VcomSel), (uint8)(ConfigPtr->AnalogCfg.ClkDiv));

    /* Calculate Gain Value */
    gain_cal_val = SDADC_LLD_CalculateGain((Sdadc_InstanceType)u8inst);

    /* Calculate Offset Value */
    offset_cal_val = SDADC_LLD_CalculateOffset((Sdadc_InstanceType)u8inst, gain_cal_val);

    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    SDADC_STCFG_ClearSoftTrig(BasePtr);

    SDADC_STCFG_SetFifoSoftReset(BasePtr);

    SDADC_ATT_SetAnalogModuleCfg(BasePtr, (uint8)(ConfigPtr->AnalogCfg.PreGain), (uint8)(ConfigPtr->AnalogCfg.VcomSel), (uint8)(ConfigPtr->AnalogCfg.ClkDiv));

    VAR(uint16, SDADC_VAR) cicFilterDecimationFactor = 0;
    VAR(uint8, SDADC_VAR) cicFilterOutputShifter = 0;
    VAR(boolean, SDADC_VAR) fir0State = TRUE, fir1State = TRUE, preFilterState = TRUE;

    switch(ConfigPtr->OsrVal)
    {
        case SDADC_OSR_12:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 5U;

                cicFilterOutputShifter = 2U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }

                fir0State = FALSE;

                preFilterState = FALSE;
            }
            else
            {
                cicFilterDecimationFactor = 2U;

                cicFilterOutputShifter = 3U;

                fir0State = FALSE;
            }

            break;
        }

        case SDADC_OSR_16:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 3U;

                cicFilterOutputShifter = 3U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }

                fir0State = FALSE;
            }
            else
            {
                cicFilterDecimationFactor = 3U;

                cicFilterOutputShifter = 4U;

                fir0State = FALSE;
            }

            break;
        }

        case SDADC_OSR_24:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 5U;

                cicFilterOutputShifter = 6U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }

                fir0State = FALSE;
            }
            else
            {
                cicFilterDecimationFactor = 2U;

                cicFilterOutputShifter = 7U;
            }

            break;
        }

        case SDADC_OSR_32:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 3U;

                cicFilterOutputShifter = 3U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 3U;

                cicFilterOutputShifter = 4U;
            }

            break;
        }

        case SDADC_OSR_48:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 5U;

                cicFilterOutputShifter = 6U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 5U;

                cicFilterOutputShifter = 7U;
            }

            break;
        }

        case SDADC_OSR_64:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 7U;

                cicFilterOutputShifter = 7U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 7U;

                cicFilterOutputShifter = 8U;
            }

            break;
        }

        case SDADC_OSR_96:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 11U;

                cicFilterOutputShifter = 10U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 11U;

                cicFilterOutputShifter = 11U;
            }

            break;
        }

        case SDADC_OSR_128:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 15U;

                cicFilterOutputShifter = 11U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 15U;

                cicFilterOutputShifter = 12U;
            }

            break;
        }

        case SDADC_OSR_160:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 19U;

                cicFilterOutputShifter = 12U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 19U;

                cicFilterOutputShifter = 13U;
            }

            break;
        }

        case SDADC_OSR_192:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 23U;

                cicFilterOutputShifter = 13U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 23U;

                cicFilterOutputShifter = 14U;
            }

            break;
        }

        case SDADC_OSR_224:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 27U;

                cicFilterOutputShifter = 14U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 27U;

                cicFilterOutputShifter = 15U;
            }

            break;
        }

        case SDADC_OSR_256:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)
            {
                cicFilterDecimationFactor = 31U;

                cicFilterOutputShifter = 15U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 31U;

                cicFilterOutputShifter = 16U;
            }

            break;
        }

        default:
        {
            /* Nothing todo */
            break;
        }
    }

    SDADC_GAINCORR_SetCorrection(BasePtr, (uint16)gain_cal_val, cicFilterOutputShifter);

    SDADC_FCFGC_SetCICFilterDecFactor(BasePtr, cicFilterDecimationFactor);

    SDADC_FCFGC_SetCICFilterStartVal(BasePtr, (uint16)(cicFilterDecimationFactor + (uint16)1U));

    SDADC_OFFCOMP_SetOffsetVal(BasePtr, (uint16)offset_cal_val);

    SDADC_FCNTC_SetCICFilterDecCounter(BasePtr, cicFilterDecimationFactor);

    SDADC_CH_WRAP_SetChannelDefault(BasePtr, ConfigPtr->ChanSel.ChanDefaultId, ConfigPtr->ChanWrap.ChanWraparoundNum);

    SDADC_GAINCAL_SetMultiFactor(BasePtr, 0x1000U);

    SDADC_FCFGM_SetFIR0FilterEnDis(BasePtr, fir0State);

    SDADC_FCFGM_SetFIR1FilterEnDis(BasePtr, fir1State);

    SDADC_FCFGM_SetOvershootCompenEnDis(BasePtr, ConfigPtr->FirFilter.OvershootCompEn);

    SDADC_FCFGM_SetFIR1FilterDecRate(BasePtr, (uint8)(ConfigPtr->FirFilter.Fir1DecimationRate));

    SDADC_FCFGM_SetCICFilterMode(BasePtr, (((ConfigPtr->FirFilter.CicMode) != FALSE) ? (uint8)1U : (uint8)0U));

    SDADC_FCFGM_SetPrefilterEnDis(BasePtr, preFilterState);

    if(ConfigPtr->Comparator.BoundaryComparatorEn == TRUE)
    {
        SDADC_FCFGM_SetBoundaryComparatorEnDis(BasePtr, TRUE);

        SDADC_BOUNDSEL_SetLowerUpperBoundaryLimit(BasePtr, ConfigPtr->Comparator.LowerBoundary, ConfigPtr->Comparator.UpperBoundary);
    }

    SDADC_FCFGM_SetExtMeshClkEnDis(BasePtr, (((uint32)(ConfigPtr->ExtMeshClkSel) != 0U) ? (boolean)TRUE : (boolean)FALSE));

    if(ConfigPtr->DCTestEn == FALSE)
    {
        SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, (uint8)(ConfigPtr->FirFilter.OffsetCompFilterEn));
        SDADC_RES_SetResistorSelChan(BasePtr, (((ConfigPtr->Res_P_En) != FALSE) ? (uint8)1U : (uint8)0U), (((ConfigPtr->Res_N_En) != FALSE) ? (uint8)1U : (uint8)0U));
    }
    else
    {
        SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, FALSE);
    }

    SDADC_FCFGM_SetChannelWraparoundEnDis(BasePtr, ConfigPtr->ChanWrap.ChanWraparoundEn);

    SDADC_FCFGM_SetDifferenceEnDis(BasePtr, ConfigPtr->ChanSel.DifferenceEn);

    SDADC_FCFGM_SetCalibEnDis(BasePtr, ConfigPtr->FirFilter.CalibrationEn);

    /* Overshoot Compensation */
    if (ConfigPtr->FirFilter.OvershootCompEn != FALSE)
    {
        DEV_ASSERT(ConfigPtr->OvershootComp.StepDetectionThreshold <= SDADC_OVERSHOOT_STEP_DETECTION_THRESHOLD_MAX);

        SDADC_OVSCFG_SetSlewRateFilterStrength(BasePtr, (uint8)(ConfigPtr->OvershootComp.SlewRateFilterStrength));

        SDADC_OVSCFG_SetSlewRateFilterRunTime(BasePtr, (uint8)(ConfigPtr->OvershootComp.SlewRateFilterRunTime));

        SDADC_OVSCFG_SetStepDetectionMode(BasePtr, (uint8)(ConfigPtr->OvershootComp.StepDetectionMode));

        SDADC_OVSCFG_SetStepDetectionThreshold(BasePtr, ConfigPtr->OvershootComp.StepDetectionThreshold);
    }

    /* Interrupt/DMA Enable Configuration */
    SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, ConfigPtr->IntDma.FifoWaterMarkerIntEn);

    SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, ConfigPtr->IntDma.FifoOverFlowIntEn);

    SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, ConfigPtr->IntDma.DataOverFlowIntEn);

    SDADC_IECFG_SetDMAReqEnDis(BasePtr, ConfigPtr->IntDma.DmaReqEn);
    /* Integration configuration */
    if(ConfigPtr->IntegratorEn == TRUE)
    {
        DEV_ASSERT((ConfigPtr->Integrator.IntegratorTrigMode) <= SDADC_INTEGRATOR_TRIG_MODE_ALWAYS_ACTIVE);
        DEV_ASSERT((ConfigPtr->Integrator.IntegratorShiftCtrl) <= SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_9_25);

        SDADC_DICFG_SetIntegratorTriggerMode(BasePtr, (uint8)(ConfigPtr->Integrator.IntegratorTrigMode));

        SDADC_IWCTR_SetIntegratorShiftCtrl(BasePtr, (uint8)(ConfigPtr->Integrator.IntegratorShiftCtrl));

        SDADC_IWCTR_SetIntegrationWindowSize(BasePtr, (uint8)(ConfigPtr->Integrator.IntegrationWindowSize));

        SDADC_IWCTR_SetFilterRestartCtrl(BasePtr, (uint8)(ConfigPtr->Integrator.FilterChainRestartCtrl));

        SDADC_IWCTR_SetIntegrationCycle(BasePtr, ConfigPtr->Integrator.NumOfIntegrationCycles);

        SDADC_IWCTR_SetNumberOfValDiscarded(BasePtr, ConfigPtr->Integrator.NumOfDiscardedVal);

        SDADC_IWCTR_SetNumberOfValAccumulated(BasePtr, ConfigPtr->Integrator.NumOfAccumulatedVal);
    }

    /* Filter Chain Discard */
    SDADC_FCDIS_SetFilterChainDiscardEnDis(BasePtr, ConfigPtr->FilterChainDiscard.FilterChainDiscardEn);

    SDADC_FCDIS_SetFilterChainDiscardNum(BasePtr, ConfigPtr->FilterChainDiscard.FilterChainDiscardNum);

    /* FIFO Configuration */
    DEV_ASSERT(ConfigPtr->FifoCfg.FifoSize <= SDADC_FIFO_SIZE_MAX);
    DEV_ASSERT(ConfigPtr->FifoCfg.FifoSize >= ConfigPtr->FifoCfg.FifoWaterMarker);

    SDADC_FCFG_SetFifoSize(BasePtr, ConfigPtr->FifoCfg.FifoSize);

    SDADC_FCFG_SetFifoWaterMarkerVal(BasePtr, ConfigPtr->FifoCfg.FifoWaterMarker);

    SDADC_FCFG_SetInfoEnDis(BasePtr, ConfigPtr->FifoCfg.InfoEn);

    SDADC_FCFG_SetSignEnDis(BasePtr, ConfigPtr->FifoCfg.SignEn);

    if(Trig_Sel < (uint16)HWTRIGSEL_SDADC0)
    {
#ifdef RESOURCE_SUPPORT_SIUL2_IP
         *MSCRPtr = (uint32)SDAdc_HwTrigMap[Trig_Sel];
#endif
#ifdef RESOURCE_SUPPORT_SIUL_IP
        switch(instance)
        {
            case SDADC_INSTANCE_0:
//                SIUL.ISEL13.B.SDADC0_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
                break;
            case SDADC_INSTANCE_1:
//				SIUL.ISEL13.B.SDADC1_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_2:
//				SIUL.ISEL13.B.SDADC2_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_3:
//				SIUL.ISEL13.B.SDADC3_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_4:
//				SIUL.ISEL14.B.SDADC4_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_5:
//				SIUL.ISEL14.B.SDADC5_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_6:
//				SIUL.ISEL14.B.SDADC6_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_7:
//				SIUL.ISEL14.B.SDADC7_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_8:
//				SIUL.ISEL15.B.SDADC8_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_9:
//				SIUL.ISEL15.B.SDADC9_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_10:
//				SIUL.ISEL15.B.SDADC10_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_11:
//				SIUL.ISEL15.B.SDADC11_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_12:
//				SIUL.ISEL16.B.SDADC12_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            case SDADC_INSTANCE_13:
//				SIUL.ISEL16.B.SDADC13_GTM_TRIG = (uint8)SDAdc_HwTrigMap[Trig_Sel];
				break;
            default:
                /*Nothing doing*/
                break;
        }
#endif
    }
    /* Hardware Trigger Configuration */
    for(uint32 i = 0U; i < SDADC_HW_TRIG_CNT; i++)
    {
        SDADC_HTCFG_SetHwTriggerEdge(BasePtr, i, (uint32)(ConfigPtr->HwTrigSel[i]));
    }

    /* Clear flag */
    SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
    SDADC_OVINTSTAT_ClearDataOverFlowIntState(BasePtr);
    SDADC_OVINTSTAT_ClearFifoOverFlowIntState(BasePtr);

    SchM_Exit_SDADC_EXCLUSIVE_AREA_00();
}

FUNC(void, SDADC_CODE) SDADC_LLD_DeInit(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

//    uint8 i;

    /* SDADC disable */
    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    /* Flush FIFO */
    SDADC_STCFG_SetFifoSoftReset(BasePtr);

    /* Interrupt/DMA */
    BasePtr->IECFG.R    = 0UL;
    /* Control */
    BasePtr->FCFGM.R    = 0UL;
    BasePtr->DICFG.R    = 0UL;
    /* Configuration */
    BasePtr->GAINCORR.R = 0UL;
    BasePtr->GAINCAL.R  = 0UL;
    BasePtr->FCFGC.R    = 0UL;
    BasePtr->OFFCOMP.R  = 0UL;
    BasePtr->FCFG.R     = SDADC_FCFG_FIFOSIZE(SDADC_FIFO_SIZE_MAX);
    BasePtr->IWCTR.R    = 0UL;
    BasePtr->BOUNDSEL.R = 0UL;
    BasePtr->OVSCFG.R   = 0UL;
    BasePtr->HTCFG.R    = 0UL;
    BasePtr->FCDIS.R    = 0UL;
    BasePtr->CH_WRAP.R  = 0UL;

    SDADC_RES_SetResistorSelChan(BasePtr, 0U, 0U);
    SDADC_ATT_SetAnalogModuleCfg(BasePtr, 0U, 0U, 0U);

    /* Clear flag */
    SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
    SDADC_OVINTSTAT_ClearDataOverFlowIntState(BasePtr);
    SDADC_OVINTSTAT_ClearFifoOverFlowIntState(BasePtr);

    MC_RGM.PRST1.R = 0x1f000000;
    MC_RGM.PRST5.R = 0x1f000000;
    MC_RGM.PRST1.R = 0x00000000;
    MC_RGM.PRST5.R = 0x00000000;

}

FUNC(void, SDADC_CODE) SDADC_LLD_ModuleEnable(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_CTRL_SetSdadcEnDis(BasePtr, TRUE);
}

FUNC(void, SDADC_CODE) SDADC_LLD_ModuleDisable(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);
}

static FUNC(uint32, SDADC_CODE) SDADC_LLD_CalculateGain(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(uint32, SDADC_VAR) attValue;

    VAR(uint8, SDADC_VAR) attVcomSelValue, attClkDivValue;

    VAR(uint32, SDADC_VAR) gain_corr_p = 0x1000;

    VAR(uint32, SDADC_VAR) gain_corr_n = 0x1000;

    VAR(uint32, SDADC_VAR) gain_sft_mask = 0x1000;

    VAR(uint32, SDADC_VAR) hard_data ,gain_corr= 0;

    

    attValue = SDADC_ATT_GetAnalogModuleCfg(BasePtr);

    attClkDivValue = (uint8)((attValue & SDADC_ATT_ADC_DIV_LV_MASK) >> SDADC_ATT_ADC_DIV_LV_SHIFT);

    attVcomSelValue = (uint8)((attValue & SDADC_ATT_VCOM_SEL_LV_MASK) >> SDADC_ATT_VCOM_SEL_LV_SHIFT);

    SDADC_ATT_SetAnalogModuleCfg(BasePtr, 1U, attVcomSelValue, attClkDivValue);

    SDADC_RES_SetResistorSelChan(BasePtr, 0U, 0U);

    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    SDADC_CH_WRAP_SetChannelDefault(BasePtr, 6U, 0U);

    SDADC_GAINCORR_SetCorrection(BasePtr, 0U, 0U);

    SDADC_GAINCAL_SetMultiFactor(BasePtr, 0x1000U);

    SDADC_FCFGC_SetCICFilterDecFactor(BasePtr, 5U);

    SDADC_FCFGC_SetCICFilterStartVal(BasePtr, 7U);

    SDADC_FCNTC_SetCICFilterDecCounter(BasePtr, 5U);

    SDADC_OFFCOMP_SetOffsetVal(BasePtr, 0U);

    SDADC_FCFGM_SetFIR0FilterEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetFIR1FilterEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetOvershootCompenEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetFIR1FilterDecRate(BasePtr, 0U);

    SDADC_FCFGM_SetCICFilterMode(BasePtr, 0U);

    SDADC_FCFGM_SetPrefilterEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetBoundaryComparatorEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetExtMeshClkEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, 0U);

    SDADC_FCFGM_SetChannelWraparoundEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetDifferenceEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetCalibEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetDMAReqEnDis(BasePtr, FALSE);

    SDADC_FCFG_SetFifoSize(BasePtr, 0x40U);

    SDADC_FCFG_SetFifoWaterMarkerVal(BasePtr, 0x20U);

    SDADC_FCFG_SetInfoEnDis(BasePtr, FALSE);

    SDADC_FCFG_SetSignEnDis(BasePtr, FALSE);

    SDADC_FCDIS_SetFilterChainDiscardEnDis(BasePtr, TRUE);

    SDADC_FCDIS_SetFilterChainDiscardNum(BasePtr, 0x80U);

    SDADC_CTRL_SetSdadcEnDis(BasePtr, TRUE);





    /*GAIN_CAL_P*/
    while(gain_sft_mask != (uint32)0U)
    {
        SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);

        SDADC_GAINCORR_SetCorrection(BasePtr, (uint16)gain_corr_p, 0x07U);

        SDADC_STCFG_SetSoftTrigEn(BasePtr);

        while(SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) == 0U)
        {
            ;
        }

        hard_data = SDADC_FDATA_GetFifoData(BasePtr);

        hard_data = hard_data & 0x0000FFFFU;

        SDADC_STCFG_ClearSoftTrig(BasePtr);

        delay(0x200U);

        SDADC_STCFG_SetFifoSoftReset(BasePtr);

        if(hard_data > 0x0007000U)
        {
            gain_corr_p = (gain_corr_p & (~gain_sft_mask)) | (gain_sft_mask >> 1);

        }
        else
        {
            gain_corr_p = gain_corr_p + (gain_sft_mask >> 1);
        }

        gain_sft_mask = gain_sft_mask >> 1;
    }

    /*GAIN_CAL_N*/
    gain_sft_mask = 0x1000U;

    SDADC_CH_WRAP_SetChannelDefault(BasePtr, 7U, 0U);

    while(gain_sft_mask != (uint32)0U)
    {
        SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);

        SDADC_GAINCORR_SetCorrection(BasePtr, (uint16)gain_corr_n, 0x07U);

        SDADC_STCFG_SetSoftTrigEn(BasePtr);

        while(SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) == 0U)
        {
            ;
        }

        hard_data = SDADC_FDATA_GetFifoData(BasePtr);

        hard_data = hard_data & 0x0000FFFFU;

        SDADC_STCFG_ClearSoftTrig(BasePtr);

        delay(0x200U);

        SDADC_STCFG_SetFifoSoftReset(BasePtr);

        if(hard_data < 0x0009000U)
        {
            gain_corr_n = (gain_corr_n & (~gain_sft_mask)) | (gain_sft_mask >> 1);
        }
        else
        {
            gain_corr_n = gain_corr_n + (gain_sft_mask >> 1);
        }

        gain_sft_mask = gain_sft_mask >> 1;
    }

    gain_corr = (gain_corr_p + gain_corr_n ) >> 1;

    return gain_corr ;
}

static FUNC(uint32, SDADC_CODE) SDADC_LLD_CalculateOffset(CONST(Sdadc_InstanceType, SDADC_CONST) instance, VAR(uint32, SDADC_VAR) gainVal)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(uint32, SDADC_VAR) attValue;

    VAR(uint8, SDADC_VAR) attVcomSelValue, attClkDivValue;

    VAR(uint32, SDADC_VAR) offcmp_n1 = 0;

    VAR(uint16, SDADC_VAR) off_data;

    attValue = SDADC_ATT_GetAnalogModuleCfg(BasePtr);

    attClkDivValue = (uint8)((attValue & SDADC_ATT_ADC_DIV_LV_MASK) >> SDADC_ATT_ADC_DIV_LV_SHIFT);

    attVcomSelValue = (uint8)((attValue & SDADC_ATT_VCOM_SEL_LV_MASK) >> SDADC_ATT_VCOM_SEL_LV_SHIFT);

    SDADC_ATT_SetAnalogModuleCfg(BasePtr, 1U, attVcomSelValue, attClkDivValue);

    SDADC_RES_SetResistorSelChan(BasePtr, 0U, 0U);

    /*Step 1*/
    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    SDADC_CTRL_SetSdadcEnDis(BasePtr, TRUE);

    /*Step 2*/
    SDADC_CH_WRAP_SetChannelDefault(BasePtr, 5U, 0U);

    delay(0x200U);

    SDADC_GAINCORR_SetCorrection(BasePtr, (uint16)gainVal, 7U);

    SDADC_FCNTC_SetCICFilterDecCounter(BasePtr, 5U);

    SDADC_GAINCAL_SetMultiFactor(BasePtr, 0x1000U);

    SDADC_FCFGC_SetCICFilterDecFactor(BasePtr, 5U);

    SDADC_FCFGC_SetCICFilterStartVal(BasePtr, 6U);

    SDADC_FCFGM_SetFIR0FilterEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetFIR1FilterEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetOvershootCompenEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetFIR1FilterDecRate(BasePtr, 0U);

    SDADC_FCFGM_SetCICFilterMode(BasePtr, 0U);

    SDADC_FCFGM_SetPrefilterEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetBoundaryComparatorEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetExtMeshClkEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, 0x4U);

    SDADC_FCFGM_SetChannelWraparoundEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetDifferenceEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetCalibEnDis(BasePtr, FALSE);

    SDADC_OFFCOMP_SetOffsetVal(BasePtr, 0U);

    SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetDMAReqEnDis(BasePtr, FALSE);

    SDADC_FCFG_SetFifoSize(BasePtr, 0x40U);

    SDADC_FCFG_SetFifoWaterMarkerVal(BasePtr, 0x20U);

    SDADC_FCDIS_SetFilterChainDiscardEnDis(BasePtr, TRUE);

    SDADC_FCDIS_SetFilterChainDiscardNum(BasePtr, 0xFFU);

    /*Step 3*/
    SDADC_STCFG_SetSoftTrigEn(BasePtr);

    delay(0x200U);

    /*Step 4*/
    while(1)
    {
        while(SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) == FALSE)
        {

        }

        (void)SDADC_FDATA_GetFifoData(BasePtr);

        /*Step 5*/
        off_data = (uint16)(SDADC_OFFCOMP_GetOffsetVal(BasePtr) & 0x0000FFFFU) ;

        if(abs((sint32)offcmp_n1 - (sint32)off_data) > (sint32)0x03U)
        {
            SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
            offcmp_n1 = off_data;

        }
        else
        {
            break;
        }
    }
    return off_data;
}

FUNC(uint32, SDADC_CODE) SDADC_LLD_GetFifoData(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    return SDADC_FDATA_GetFifoData(BasePtr);
}

FUNC(void, SDADC_CODE) SDADC_LLD_SetSoftTrigger(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_STCFG_SetSoftTrigEn(BasePtr);
}

FUNC(boolean, SDADC_CODE) SDADC_LLD_GetWaterMarkerIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(boolean, SDADC_VAR) ret;

    ret = (SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) != 0U) ? (boolean)TRUE : (boolean)FALSE;

    return ret;
}

FUNC(void, SDADC_CODE) SDADC_LLD_ClearWaterMarkerIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
}

FUNC(boolean, SDADC_CODE) SDADC_LLD_GetDataOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(boolean, SDADC_VAR) ret;

    ret = (SDADC_OVINTSTAT_GetDataOverFlowIntState(BasePtr) != 0U) ? (boolean)TRUE : (boolean)FALSE;

    return ret;
}

FUNC(void, SDADC_CODE) SDADC_LLD_ClearDataOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_OVINTSTAT_ClearDataOverFlowIntState(BasePtr);
}

FUNC(boolean, SDADC_CODE) SDADC_LLD_GetFifoOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(boolean, SDADC_VAR) ret;

    ret = (SDADC_OVINTSTAT_GetFifoOverFlowIntState(BasePtr) != 0U) ? (boolean)TRUE : (boolean)FALSE;

    return ret;
}

FUNC(void, SDADC_CODE) SDADC_LLD_ClearFifoOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_OVINTSTAT_ClearFifoOverFlowIntState(BasePtr);
}

FUNC(void, SDADC_CODE) SDADC_LLD_SetInterruptState(CONST(Sdadc_InstanceType, SDADC_CONST) instance, VAR(Sdadc_InterruptType, SDADC_VAR) intType, VAR(boolean, SDADC_VAR) intState)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    if(SDADC_INT_WATERMARKER == intType)
    {
        SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, intState);
    }
    else if(SDADC_INT_DATAOVERRUN == intType)
    {
        SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, intState);
    }
    else if(SDADC_INT_FIFOOVERRUN == intType)
    {
        SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, intState);
    }
    else
    {
        /*Null*/
    }
}

FUNC(void, SDADC_CODE) SDADC_LLD_ResetFifo(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_STCFG_SetFifoSoftReset(BasePtr);
}

FUNC(void, SDADC_CODE) SDADC_LLD_ConfigDma \
(
    CONST(Sdadc_InstanceType, SDADC_CONST) instance, \
    VAR(Sdadc_DmaCfgType, SDADC_VAR) config \
)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];
    (void)BasePtr;

    VAR(uint8, SDADC_VAR) dmaChannel;

    VAR(uint32, SDADC_VAR) sdadc_dma_src = 0;

    dmaChannel = config.DmaCh;


    switch(instance)
    {
        case SDADC_INSTANCE_0:
        {
            if(dmaChannel <= 7U)
            {
                sdadc_dma_src = (uint32)DMAMUX0_ADC_SD_0_EOC;
            }
            else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
            {
                sdadc_dma_src = (uint32)DMAMUX7_ADC_SD_0_EOC;
            }
            else
            {
                return;
            }

            break;
        }

        case SDADC_INSTANCE_1:
        {
            if((dmaChannel >= 16U)&&(dmaChannel <= 23U))
            {
                sdadc_dma_src = (uint32)DMAMUX2_ADC_SD_1_EOC;
            }
            else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
            {
                sdadc_dma_src = (uint32)DMAMUX7_ADC_SD_1_EOC;
            }
            else
            {
                return;
            }

            break;
        }

        case SDADC_INSTANCE_2:
        {
            if((dmaChannel >= 16U)&&(dmaChannel <= 23U))
            {
                sdadc_dma_src = (uint32)DMAMUX2_ADC_SD_2_EOC;
            }
            else if((dmaChannel >= 32U)&&(dmaChannel <= 47U))
            {
                sdadc_dma_src = (uint32)DMAMUX4_ADC_SD_2_EOC;
            }
            else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
            {
                sdadc_dma_src = (uint32)DMAMUX7_ADC_SD_2_EOC;
            }
            else
            {
                return;
            }

            break;
        }

        case SDADC_INSTANCE_3:
        {
            if(dmaChannel <= 7U)
            {
                sdadc_dma_src = (uint32)DMAMUX0_ADC_SD_3_EOC;
            }
            else if((dmaChannel >= 8U)&&(dmaChannel <= 15U))
            {
                sdadc_dma_src = (uint32)DMAMUX1_ADC_SD_3_EOC;
            }
            else if((dmaChannel >= 32U)&&(dmaChannel <= 47U))
            {
                sdadc_dma_src = (uint32)DMAMUX4_ADC_SD_3_EOC;
            }
            else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
            {
                sdadc_dma_src = (uint32)DMAMUX7_ADC_SD_3_EOC;
            }
            else
            {
                return;
            }

            break;
        }

        case SDADC_INSTANCE_4:
        {
            if((dmaChannel >= 48U)&&(dmaChannel <= 63U))
            {
                sdadc_dma_src = (uint32)DMAMUX5_ADC_SD_4_EOC;
            }
            else if((dmaChannel >= 96U)&&(dmaChannel <= 111U))
            {
                sdadc_dma_src = (uint32)DMAMUX8_ADC_SD_4_EOC;
            }
            else
            {
                return;
            }

            break;
        }

#ifdef RESOURCE_SUPPORT_SDADC5
        case SDADC_INSTANCE_5:
        {
            if((dmaChannel >= 32U)&&(dmaChannel <= 47U))
            {
                sdadc_dma_src = (uint32)DMAMUX4_ADC_SD_5_EOC;
            }
            else if((dmaChannel >= 48U)&&(dmaChannel <= 63U))
            {
                sdadc_dma_src = (uint32)DMAMUX5_ADC_SD_5_EOC;
            }
            else if((dmaChannel >= 112U)&&(dmaChannel <= 119U))
            {
                sdadc_dma_src = (uint32)DMAMUX9_ADC_SD_5_EOC;
            }
            else
            {
                return;
            }

            break;
        }
#endif

        case SDADC_INSTANCE_6:
        {
            if((dmaChannel >= 64U)&&(dmaChannel <= 79U))
            {
                sdadc_dma_src = (uint32)DMAMUX6_ADC_SD_6_EOC;
            }
            else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
            {
                sdadc_dma_src = (uint32)DMAMUX7_ADC_SD_6_EOC;
            }
            else
            {
                return;
            }

            break;
        }

        case SDADC_INSTANCE_7:
        {
            if((dmaChannel >= 64U)&&(dmaChannel <= 79U))
            {
                sdadc_dma_src = (uint32)DMAMUX6_ADC_SD_7_EOC;
            }
            else if((dmaChannel >= 80U)&&(dmaChannel <= 95U))
            {
                sdadc_dma_src = (uint32)DMAMUX7_ADC_SD_7_EOC;
            }
            else
            {
                return;
            }

            break;
        }

        case SDADC_INSTANCE_8:
        {
            if((dmaChannel >= 64U)&&(dmaChannel <= 79U))
            {
                sdadc_dma_src = (uint32)DMAMUX6_ADC_SD_8_EOC;
            }
            else if((dmaChannel >= 96U)&&(dmaChannel <= 111U))
            {
                sdadc_dma_src = (uint32)DMAMUX8_ADC_SD_8_EOC;
            }
            else
            {
                return;
            }

            break;
        }

#ifdef RESOURCE_SUPPORT_SDADC9
        case SDADC_INSTANCE_9:
        {
            if((dmaChannel >= 64U)&&(dmaChannel <= 79U))
            {
                sdadc_dma_src = (uint32)DMAMUX6_ADC_SD_9_EOC;
            }
            else if((dmaChannel >= 112U)&&(dmaChannel <= 119U))
            {
                sdadc_dma_src = (uint32)DMAMUX9_ADC_SD_9_EOC;
            }
            else
            {
                return;
            }

            break;
        }
#endif

#ifdef RESOURCE_SUPPORT_SDADC10
        case SDADC_INSTANCE_10:
        {
            if((dmaChannel >= 120U)&&(dmaChannel <= 127U))
            {
                sdadc_dma_src = (uint32)DMAMUX10_ADC_SD_10_EOC;
            }
            else
            {
                return;
            }

            break;
        }
#endif

#ifdef RESOURCE_SUPPORT_SDADC11
        case SDADC_INSTANCE_11:
        {
            if((dmaChannel >= 120U)&&(dmaChannel <= 127U))
            {
                sdadc_dma_src = (uint32)DMAMUX10_ADC_SD_11_EOC;
            }
            else
            {
                return;
            }

            break;
        }
#endif

#ifdef RESOURCE_SUPPORT_SDADC12
        case SDADC_INSTANCE_12:
        {
            if((dmaChannel >= 120U)&&(dmaChannel <= 127U))
            {
                sdadc_dma_src = (uint32)DMAMUX10_ADC_SD_12_EOC;
            }
            else
            {
                return;
            }

            break;
        }
#endif

#ifdef RESOURCE_SUPPORT_SDADC13
        case SDADC_INSTANCE_13:
        {
            if((dmaChannel >= 120U)&&(dmaChannel <= 127U))
            {
                sdadc_dma_src = (uint32)DMAMUX10_ADC_SD_13_EOC;
            }
            else
            {
                return;
            }

            break;
        }
#endif

        default:/*PRQA S 2016*/
                break;
    }

    (void)EDMA_LLD_SetChannelSourceConfig(dmaChannel, sdadc_dma_src, FALSE);

    (void)EDMA_LLD_SetLoopTransferConfig(dmaChannel, &config.DmaConfigPtr);

    if(config.DreqEn == TRUE)
    {
        EDMA_SetChnDisRequestsOnTransferComplete(dmaChannel, TRUE);
    }

    (void) EDMA_LLD_SetUpCallback(dmaChannel,
            config.Callback, config.CallbackParam);

    (void)EDMA_LLD_SetChannelRequest(dmaChannel);
}

FUNC(uint32, SDADC_CODE) SDADC_LLD_GetRecentAccumulation(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    return SDADC_IIVAL_GetInterIntegrationVal(BasePtr);
}

FUNC(boolean, SDADC_CODE) SDADC_LLD_GetIntegrationEnable(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
#ifdef CCFC3007PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE) && ((uint8)instance != 5U));
#endif
#ifdef CCFC3012PT
    DEV_ASSERT(((uint8)instance < ADC_SDADC_MAX_INSTANCE));
#endif
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    return ( SDADC_ISTAT_GetIntegrationEn(BasePtr) != 0U) ? (boolean)TRUE : (boolean)FALSE;
}

#endif /*RESOURCE_SUPPORT_SDADC_IP*/

#ifdef __cplusplus
}
#endif

