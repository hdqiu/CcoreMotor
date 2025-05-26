/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc_LLDriver.h
* @version  1.0
* @date     2023 - 09 - 01
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 1534,0779,2053 EOF*/
#ifndef SDADC_LLD_H_
#define SDADC_LLD_H_
#include "derivative.h"
#include "status.h"
#include "eDma_LLDriver.h"
#include "console.h"
#include "SDAdc_Cfg.h"

#ifdef RESOURCE_SUPPORT_SDADC_IP
#define SDADC_LLD_H_VENDOR_ID                     176
#define SDADC_LLD_H_AR_REL_MAJOR_VER              4
#define SDADC_LLD_H_AR_REL_MINOR_VER              4
#define SDADC_LLD_H_AR_REL_REV_VER                0
#define SDADC_LLD_H_SW_MAJOR_VER                  1
#define SDADC_LLD_H_SW_MINOR_VER                  0
#define SDADC_LLD_H_SW_PATCH_VER                  1

#if (SDADC_CFG_H_VENDOR_ID               != SDADC_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_LLD_H_VENDOR_ID "
#endif
#if (SDADC_CFG_H_AR_REL_MAJOR_VER    != SDADC_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_MINOR_VER    != SDADC_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_H_AR_REL_MINOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_REV_VER != SDADC_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_H_AR_REL_REV_VER "
#endif
#if (SDADC_CFG_H_SW_MAJOR_VER        != SDADC_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_H_SW_MAJOR_VER "
#endif
#if (SDADC_CFG_H_SW_MINOR_VER        != SDADC_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_H_SW_MINOR_VER "
#endif
#if (SDADC_CFG_H_SW_PATCH_VER        != SDADC_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_H_SW_PATCH_VER "
#endif

#define SDADC_DEV_ERROR             (TRUE)
#ifdef CCFC3007PT
#define ADC_SDADC_MAX_INSTANCE      (9u)
#endif

#ifdef CCFC3012PT
#define ADC_SDADC_MAX_INSTANCE      (14u)
#endif
/* @brief SDADC instance base address */
#define SDADC0_BASEADDR              ((uint32)0xFFF0C000UL)
#define SDADC1_BASEADDR              ((uint32)0xFBF0C000UL)
#define SDADC2_BASEADDR              ((uint32)0xFFF10000UL)
#define SDADC3_BASEADDR              ((uint32)0xFBF10000UL)
#define SDADC4_BASEADDR              ((uint32)0xFFF14000UL)
#define SDADC6_BASEADDR              ((uint32)0xFFF18000UL)
#define SDADC7_BASEADDR              ((uint32)0xFBF18000UL)
#define SDADC8_BASEADDR              ((uint32)0xFFF1C000UL)
#ifdef CCFC3012PT
#define SDADC5_BASEADDR              ((uint32)0xFBF14000UL)
#define SDADC9_BASEADDR              ((uint32)0xFBF1C000UL)
#define SDADC10_BASEADDR             ((uint32)0xFFF20000UL)
#define SDADC11_BASEADDR             ((uint32)0xFBF20000UL)
#define SDADC12_BASEADDR             ((uint32)0xFFF24000UL)
#define SDADC13_BASEADDR             ((uint32)0xFBF24000UL)
#endif

/* @brief EQADC instance base pointer */
#define SDADC0_PTR                   ((SDADC_TagType *) SDADC0_BASEADDR)
#define SDADC1_PTR                   ((SDADC_TagType *) SDADC1_BASEADDR)
#define SDADC2_PTR                   ((SDADC_TagType *) SDADC2_BASEADDR)
#define SDADC3_PTR                   ((SDADC_TagType *) SDADC3_BASEADDR)
#define SDADC4_PTR                   ((SDADC_TagType *) SDADC4_BASEADDR)
#define SDADC6_PTR                   ((SDADC_TagType *) SDADC6_BASEADDR)
#define SDADC7_PTR                   ((SDADC_TagType *) SDADC7_BASEADDR)
#define SDADC8_PTR                   ((SDADC_TagType *) SDADC8_BASEADDR)
#ifdef CCFC3012PT
#define SDADC5_PTR                   ((SDADC_TagType *) SDADC5_BASEADDR)
#define SDADC9_PTR                   ((SDADC_TagType *) SDADC9_BASEADDR)
#define SDADC10_PTR                  ((SDADC_TagType *) SDADC10_BASEADDR)
#define SDADC11_PTR                  ((SDADC_TagType *) SDADC11_BASEADDR)
#define SDADC12_PTR                  ((SDADC_TagType *) SDADC12_BASEADDR)
#define SDADC13_PTR                  ((SDADC_TagType *) SDADC13_BASEADDR)
#endif

#define SIUL_ISEL_SDADC0_ADDR                (0xFFFC109CUL + 55UL)
#define SIUL_ISEL_SDADC1_ADDR                (0xFFFC109CUL + 54UL)
#define SIUL_ISEL_SDADC2_ADDR                (0xFFFC109CUL + 53UL)
#define SIUL_ISEL_SDADC3_ADDR                (0xFFFC109CUL + 52UL)
#define SIUL_ISEL_SDADC4_ADDR                (0xFFFC109CUL + 59UL)
#define SIUL_ISEL_SDADC5_ADDR                (0xFFFC109CUL + 58UL)
#define SIUL_ISEL_SDADC6_ADDR                (0xFFFC109CUL + 57UL)
#define SIUL_ISEL_SDADC7_ADDR                (0xFFFC109CUL + 56UL)
#define SIUL_ISEL_SDADC8_ADDR                (0xFFFC109CUL + 63UL)
#define SIUL_ISEL_SDADC9_ADDR                (0xFFFC109CUL + 62UL)
#define SIUL_ISEL_SDADC10_ADDR               (0xFFFC109CUL + 61UL)
#define SIUL_ISEL_SDADC11_ADDR               (0xFFFC109CUL + 60UL)
#define SIUL_ISEL_SDADC12_ADDR               (0xFFFC109CUL + 67UL)
#define SIUL_ISEL_SDADC13_ADDR               (0xFFFC109CUL + 66UL)



#ifdef CCFC3012PT
/* @brief EQADC instance base address array */
#define SDADC_BASE_ADDR_ARRAY       {SDADC0_BASEADDR, SDADC1_BASEADDR, SDADC2_BASEADDR, SDADC3_BASEADDR, SDADC4_BASEADDR, \
                                     SDADC5_BASEADDR, SDADC6_BASEADDR, SDADC7_BASEADDR, SDADC8_BASEADDR, SDADC9_BASEADDR, \
                                     SDADC10_BASEADDR, SDADC11_BASEADDR, SDADC12_BASEADDR, SDADC13_BASEADDR}

/* @brief EQADC instance base pointer array */
#define SDADC_BASE_PTR_ARRAY        {SDADC0_PTR, SDADC1_PTR, SDADC2_PTR, SDADC3_PTR, SDADC4_PTR, \
                                     SDADC5_PTR, SDADC6_PTR, SDADC7_PTR, SDADC8_PTR, SDADC9_PTR, \
                                     SDADC10_PTR, SDADC11_PTR, SDADC12_PTR, SDADC13_PTR}
#endif

#ifdef CCFC3007PT
/* @brief EQADC instance base address array */
#define SDADC_BASE_ADDR_ARRAY       {SDADC0_BASEADDR, SDADC1_BASEADDR, SDADC2_BASEADDR, SDADC3_BASEADDR, SDADC4_BASEADDR, \
                                                NULL, SDADC6_BASEADDR, SDADC7_BASEADDR, SDADC8_BASEADDR}

/* @brief EQADC instance base pointer array */
#define SDADC_BASE_PTR_ARRAY        {SDADC0_PTR, SDADC1_PTR, SDADC2_PTR, SDADC3_PTR, SDADC4_PTR, \
                                           NULL, SDADC6_PTR, SDADC7_PTR, SDADC8_PTR}
#endif

typedef enum
{
    SDADC_INSTANCE_0                = 0U,
    SDADC_INSTANCE_1                = 1U,
    SDADC_INSTANCE_2                = 2U,
    SDADC_INSTANCE_3                = 3U,
    SDADC_INSTANCE_4                = 4U,
#ifdef CCFC3012PT
    SDADC_INSTANCE_5                = 5U,
#endif
    SDADC_INSTANCE_6                = 6U,
    SDADC_INSTANCE_7                = 7U,
    SDADC_INSTANCE_8                = 8U,
#ifdef CCFC3012PT
    SDADC_INSTANCE_9                = 9U,
    SDADC_INSTANCE_10               = 10U,
    SDADC_INSTANCE_11               = 11U,
    SDADC_INSTANCE_12               = 12U,
    SDADC_INSTANCE_13               = 13U,
#endif
} Sdadc_InstanceType;

/**
 * @brief SDADC external mesh decoder clock selected.
 */
typedef enum
{
    SDADC_MESH_SEL_ADC_CORE         = 0U,
    SDADC_MESH_SEL_EXT_SIGNAL       = 1U
} Sdadc_MeshClkType;

/**
 * @brief SDADC FIR1 filter decimation rate enumeration
 */
typedef enum
{
    SDADC_FIR1_DECI_2_TO_1          = 0U,   /* Decimation 2:1 for FIR1 */
    SDADC_FIR1_DECI_NOT             = 1U    /* FIR1 filter does not decimate, 1:1 */
} Sdadc_Fir1DecimationRateType;

typedef enum
{
    SDADC_OFFSET_COMPENSATION_FILTER_DISABLED   = 0U,
    SDADC_OFFSET_COMPENSATION_FILTER_RATE_1     = 1U,
    SDADC_OFFSET_COMPENSATION_FILTER_RATE_2     = 2U,
    SDADC_OFFSET_COMPENSATION_FILTER_RATE_3     = 3U,
    SDADC_OFFSET_COMPENSATION_FILTER_RATE_4     = 4U,
    SDADC_OFFSET_COMPENSATION_FILTER_RATE_5     = 5U,
    SDADC_OFFSET_COMPENSATION_FILTER_RATE_6     = 6U,
    SDADC_OFFSET_COMPENSATION_FILTER_RATE_7     = 7U
} Sdadc_OffsetCompensationFilterEnType;

/**
 * @brief Selects the valid outputs bits from the CIC filter, depending on the chosen
 *          decimation factor (see data shifter formula).
 */
#define SDADC_CICSHIFT_USE_BITS_0_16            (0x00U)
#define SDADC_CICSHIFT_USE_BITS_1_17            (0x01U)
#define SDADC_CICSHIFT_USE_BITS_2_18            (0x02U)
#define SDADC_CICSHIFT_USE_BITS_3_19            (0x03U)
#define SDADC_CICSHIFT_USE_BITS_4_20            (0x04U)
#define SDADC_CICSHIFT_USE_BITS_5_21            (0x05U)
#define SDADC_CICSHIFT_USE_BITS_6_22            (0x06U)
#define SDADC_CICSHIFT_USE_BITS_7_23            (0x07U)
#define SDADC_CICSHIFT_USE_BITS_8_24            (0x08U)
#define SDADC_CICSHIFT_USE_BITS_9_25            (0x09U)
#define SDADC_CICSHIFT_USE_BITS_10_26           (0x0AU)
#define SDADC_CICSHIFT_USE_BITS_11_27           (0x0BU)
#define SDADC_CICSHIFT_USE_BITS_12_28           (0x0CU)
#define SDADC_CICSHIFT_USE_BITS_13_29           (0x0DU)
#define SDADC_CICSHIFT_USE_BITS_14_30           (0x0EU)
#define SDADC_CICSHIFT_USE_BITS_15_31           (0x0FU)
#define SDADC_CICSHIFT_USE_BITS_16_32           (0x10U)
#define SDADC_CICSHIFT_USE_BITS_17_33           (0x11U)
#define SDADC_CICSHIFT_USE_BITS_18_34           (0x12U)
#define SDADC_CICSHIFT_USE_BITS_19_35           (0x13U)
#define SDADC_CICSHIFT_USE_BITS_20_36           (0x14U)
#define SDADC_CICSHIFT_USE_BITS_21_37           (0x15U)
#define SDADC_CICSHIFT_USE_BITS_22_38           (0x16U)
#define SDADC_CICSHIFT_USE_BITS_23_39           (0x17U)
#define SDADC_CICSHIFT_USE_BITS_24_40           (0x18U)
#define SDADC_CICSHIFT_USE_BITS_25_41           (0x19U)
#define SDADC_CICSHIFT_USE_BITS_26_42           (0x1AU)
#define SDADC_CICSHIFT_USE_BITS_27_43           (0x1BU)
#define SDADC_CICSHIFT_USE_BITS_28_44           (0x1CU)

/**
 * @brief The initial value of 4096(0x1000) corresponds to a factor of 1.000.
 *          (Multiplication Factor for Gain Correction)
 *          (Multiplication Factor for Gain Calibration)
 */
#define SDADC_GAIN_INITIAL_VAL                  (0x1000U)

/**
 * @brief CIC Filter Decimation Factor
 *          Defines the oversampling rate of the CIC filter: OSR = CFMDF + 1.
 *          Valid values are 0x003 to 0x1ff(OSR = 4 to 512).
 */
#define SDADC_CIC_FILTER_OSR_MIN                (4U)
#define SDADC_CIC_FILTER_OSR_MAX                (512U)

typedef enum
{
    SDADC_SLEW_RATE_FILTER_STRENGTH_MIN         = 0U,   /* Minimum filter effect, early attenuation, linear operation */
    SDADC_SLEW_RATE_FILTER_STRENGTH_WEAK        = 1U,   /* Weak filter effect */
    SDADC_SLEW_RATE_FILTER_STRENGTH_MED         = 2U,   /* Medium filter effect */
    SDADC_SLEW_RATE_FILTER_STRENGTH_MAX         = 3U    /* Maximum filter effect, steep beginning, smooth end */
} Sdadc_SlewRateFilterStrengthType;

typedef enum
{
    SDADC_SLEW_RATE_FILTER_RUNTIME_2_IN_CYCLES  = 0U,
    SDADC_SLEW_RATE_FILTER_RUNTIME_4_IN_CYCLES  = 1U,
    SDADC_SLEW_RATE_FILTER_RUNTIME_8_IN_CYCLES  = 2U,
    SDADC_SLEW_RATE_FILTER_RUNTIME_16_IN_CYCLES = 3U
} Sdadc_SlewRateFilterRunTimeType;

typedef enum
{
    SDADC_STEP_DETECTION_MODE_LAST_INPUT        = 0U,
    SDADC_STEP_DETECTION_MODE_SECOND_LAST_INPUT = 1U
} Sdadc_StepDetectionModeType;

typedef enum
{
    SDADC_HW_TRIG_DISABLE                       = 0U,
    SDADC_HW_TRIG_POSEDGE                       = 1U,/* posedge: rising edge */
    SDADC_HW_TRIG_NEGEDGE                       = 2U,/* negedge: falling edge */
    SDADC_HW_TRIG_EDGE_BOTH                     = 3U
} Sdadc_HwTrigEdgeType;

typedef enum
{
    SDADC_INTEGRATOR_TRIG_MODE_BYPASSED         = 0U,
    SDADC_INTEGRATOR_TRIG_MODE_FALLING_EDGE     = 1U,
    SDADC_INTEGRATOR_TRIG_MODE_RISING_EDGE      = 2U,
    SDADC_INTEGRATOR_TRIG_MODE_ALWAYS_ACTIVE    = 3U
} Sdadc_IntegratorTrigModeType;

typedef enum
{
    SDADC_INTEGRATION_WINDOW_SIZE_INTERNAL_CTRL = 0U,   /* Internal control: stop integrator after REPVAL+1 integration cycles */
    SDADC_INTEGRATION_WINDOW_SIZE_EXTERNAL_CTRL = 1U    /* External control: stop integrator up the inverse trigger event */
} Sdadc_IntegrationWindowSizeType;

typedef enum
{
    SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_4_20   = 0U,
    SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_5_21   = 1U,
    SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_6_22   = 2U,
    SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_7_23   = 3U,
    SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_8_24   = 4U,
    SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_9_25   = 5U
} Sdadc_IntegratorShiftCtrlType;

typedef enum
{
    SDADC_FILTER_CHAIN_RESTART_ENABLE           = 0U,   /* Restart the filter chain when an integration window starts */
    SDADC_FILTER_CHAIN_RESTART_DISABLE          = 1U    /* No influence of filter chain when an integration window starts,
                                                         *  except for the integrator itself. */
} Sdadc_FilterChainRestartCtrlType;

typedef enum
{
    SDADC_PRE_GAIN_X1                           = 1U,
    SDADC_PRE_GAIN_X2                           = 2U,
    SDADC_PRE_GAIN_X4                           = 4U
} Sdadc_PreGainType;

typedef enum
{
    SDADC_INT_WATERMARKER                        = 0U,
    SDADC_INT_DATAOVERRUN                        = 1U,
    SDADC_INT_FIFOOVERRUN                        = 2U
} Sdadc_InterruptType;

/**
 * @brief SDADC Single-ended negative selection
 * @note  usable: Single-ended AC coupled capacitance sampling
 *        unusable: Single-ended DC sampling
 */
typedef enum
{
    SDADC_VCOM_SEL_HALF_OF_VREF_H               = 0U,   /* Negative: VCOM (VREF_H / 2) */
    SDADC_VCOM_SEL_VREF_L                       = 1U    /* Negative: ground */
} Sdadc_VcomSelType;

typedef enum
{
    SDADC_CLK_DIV_1                             = 0U,
    SDADC_CLK_DIV_2                             = 1U,
    SDADC_CLK_DIV_3                             = 2U,
    SDADC_CLK_DIV_4                             = 3U,
    SDADC_CLK_DIV_5                             = 4U,
    SDADC_CLK_DIV_6                             = 5U,
    SDADC_CLK_DIV_7                             = 6U,
    SDADC_CLK_DIV_8                             = 7U,
} Sdadc_ClkDivType;

typedef enum
{
    SDADC_OSR_12 = 0U,
	SDADC_OSR_16,
	SDADC_OSR_24,
	SDADC_OSR_32,
	SDADC_OSR_48,
	SDADC_OSR_64,
	SDADC_OSR_96,
	SDADC_OSR_128,
	SDADC_OSR_160,
	SDADC_OSR_192,
	SDADC_OSR_224,
	SDADC_OSR_256,
} Sdadc_OSRType;

typedef struct
{
    VAR(uint8, SDADC_VAR) ChanDefaultId;
    VAR(boolean, SDADC_VAR) DifferenceEn;
} Sdadc_ChanSelType;

/**
 * @brief SDADC FIR filters configuration structure
 */
typedef struct
{
    VAR(Sdadc_Fir1DecimationRateType, SDADC_VAR) Fir1DecimationRate;
    VAR(boolean, SDADC_VAR) CicMode;
    VAR(boolean, SDADC_VAR) OvershootCompEn;
    VAR(Sdadc_OffsetCompensationFilterEnType, SDADC_VAR) OffsetCompFilterEn;
    VAR(boolean, SDADC_VAR) CalibrationEn;
} Sdadc_FirFilterConfigType;

typedef struct
{
    VAR(uint16, SDADC_VAR) GainCorrFactor;         /* Multiplication Factor for Gain Correction */
    VAR(uint8, SDADC_VAR) GainCorrCicShift;       /* Position of the CIC Filter Output Shifter. Max: [SDADC_CICSHIFT_USE_BITS_28_44] */
    VAR(uint16, SDADC_VAR) GainCalFactor;          /* Multiplication Factor for Gain Calibration */
} Sdadc_GainConfigType;

#define SDADC_OVERSHOOT_STEP_DETECTION_THRESHOLD_MAX    (0x7FFu)

typedef struct
{
    VAR(Sdadc_SlewRateFilterStrengthType, SDADC_VAR) SlewRateFilterStrength;
    VAR(Sdadc_SlewRateFilterRunTimeType, SDADC_VAR) SlewRateFilterRunTime;
    VAR(Sdadc_StepDetectionModeType, SDADC_VAR) StepDetectionMode;
    VAR(uint16, SDADC_VAR) StepDetectionThreshold;
} Sdadc_OvershootCompConfigType;

typedef struct
{
    VAR(boolean, SDADC_VAR) FifoWaterMarkerIntEn;
    VAR(boolean, SDADC_VAR) FifoOverFlowIntEn;
    VAR(boolean, SDADC_VAR) DataOverFlowIntEn;
    VAR(boolean, SDADC_VAR) DmaReqEn;
} Sdadc_IntDmaConfigType;

/**
 * @brief SDADC Integrator configuration structure
 */
typedef struct
{
    VAR(Sdadc_IntegratorTrigModeType, SDADC_VAR) IntegratorTrigMode;     /* Integrator Trigger Mode (DICFG.ITRMODE) */
    VAR(Sdadc_IntegrationWindowSizeType, SDADC_VAR) IntegrationWindowSize;  /* Integration Window Size (IWCTR.IWS) */
    VAR(uint8, SDADC_VAR) NumOfDiscardedVal;      /* Start the integration cycle after [NVALDIS] values (IWCTR.NVALDIS) */
    VAR(uint8, SDADC_VAR) NumOfAccumulatedVal;    /* Stop the integration cycle after [NVALINT] + 1 values (IWCTR.NVALINT) */
    VAR(uint8, SDADC_VAR) NumOfIntegrationCycles; /* Defines the number of integration cycles to be counted by REPCNT if activated(IWS=0).
                                                      The number of cycles is [REPVAL] + 1. (IWCTR.REPVAL) */
    VAR(Sdadc_IntegratorShiftCtrlType, SDADC_VAR) IntegratorShiftCtrl;    /* Integrator Shift Control
                                                                                   Controls the data shifter after the integrator that selects the portion of the integrator data for the result register.
                                                                                   Note: [ISC] selects the respective bits in register IIVAL.The lowest selected bit is used for rounding and is then removed.
                                                                                   (IWCTR.ISC) */
    VAR(Sdadc_FilterChainRestartCtrlType, SDADC_VAR) FilterChainRestartCtrl; /* Filter Chain Restart Control (IWCTR.FRC) */
} Sdadc_IntegratorConfigType;

typedef struct
{
    VAR(boolean, SDADC_VAR) FilterChainDiscardEn;
    VAR(uint8, SDADC_VAR) FilterChainDiscardNum;
} Sdadc_FilterChainDiscardConfigType;

typedef struct
{
    VAR(boolean, SDADC_VAR) ChanWraparoundEn;
    VAR(uint8, SDADC_VAR) ChanWraparoundNum;
} Sdadc_ChanWrapConfigType;

typedef struct
{
    VAR(boolean, SDADC_VAR) BoundaryComparatorEn;
    VAR(uint16, SDADC_VAR) LowerBoundary;
    VAR(uint16, SDADC_VAR) UpperBoundary;
} Sdadc_ComparatorConfigType;

#define SDADC_FIFO_SIZE_MAX             (0x40U)

typedef struct
{
    VAR(uint8, SDADC_VAR) FifoSize;   /* Max(default) is 0x40 */
    VAR(uint8, SDADC_VAR) FifoWaterMarker;
    VAR(boolean, SDADC_VAR) InfoEn;
    VAR(boolean, SDADC_VAR) SignEn;
} Sdadc_FifoDataConfigType;

/**
 * @brief SDADC Analog Configuration
 *
 * @param PreGain: Analog gain factor
 *        VcomSel: Single-ended negative selection
 *        ClkDiv: Clock frequency division
 *        ResistorChan_P: Resistance Select open channel (positive +)
 *        ResistorChan_N: Resistance Select open channel (negative -)
 *
 * @note  ResistorChan_P & ResistorChan_N:
 *          usable: Single-ended AC coupled capacitance sampling
 *          unusable: Single-ended DC sampling
 */
typedef struct
{
    VAR(Sdadc_PreGainType, SDADC_VAR) PreGain;
    VAR(Sdadc_VcomSelType, SDADC_VAR) VcomSel;
    VAR(Sdadc_ClkDivType, SDADC_VAR) ClkDiv;
} Sdadc_AnalogCfgType;

typedef struct
{
	VAR(uint8, SDADC_VAR) DmaCh;
    VAR(eDMATransferConfigType, SDADC_VAR) DmaConfigPtr;
    VAR(boolean, SDADC_VAR) DreqEn;
    VAR(eDMACallbackType, SDADC_VAR) Callback;
    P2VAR(void, SDADC_VAR, SDADC_APPL_DATA) CallbackParam;
} Sdadc_DmaCfgType;

typedef struct
{
    VAR(Sdadc_ChanSelType, SDADC_VAR) ChanSel;
    VAR(boolean, SDADC_VAR) DCTestEn;
    VAR(Sdadc_MeshClkType, SDADC_VAR) ExtMeshClkSel;  /* External mesh decoder clock selected */
    VAR(Sdadc_AnalogCfgType, SDADC_VAR) AnalogCfg;
    VAR(Sdadc_OSRType, SDADC_VAR) OsrVal;
    VAR(Sdadc_FirFilterConfigType, SDADC_VAR) FirFilter;
    VAR(Sdadc_OvershootCompConfigType, SDADC_VAR) OvershootComp;
    VAR(boolean, SDADC_VAR) Res_P_En;
    VAR(boolean, SDADC_VAR) Res_N_En;
    VAR(Sdadc_IntDmaConfigType, SDADC_VAR) IntDma;
    VAR(Sdadc_DmaCfgType, SDADC_VAR) DmaCfg;
    VAR(boolean, SDADC_VAR) IntegratorEn;
    VAR(Sdadc_IntegratorConfigType, SDADC_VAR) Integrator;
    VAR(Sdadc_FilterChainDiscardConfigType, SDADC_VAR) FilterChainDiscard;
    VAR(Sdadc_ChanWrapConfigType, SDADC_VAR) ChanWrap;
    VAR(Sdadc_ComparatorConfigType, SDADC_VAR) Comparator;
    VAR(Sdadc_FifoDataConfigType, SDADC_VAR) FifoCfg;
    VAR(Sdadc_HwTrigEdgeType, SDADC_VAR) HwTrigSel[15u];
} Sdadc_ConfigType;

// #define SDADC0_CH0                      (0U)
// #define SDADC0_CH1                      (1U)
// #define SDADC1_CH0                      (0U)
// #define SDADC1_CH1                      (1U)
// #define SDADC2_CH0                      (0U)
// #define SDADC2_CH1                      (1U)
// #define SDADC2_CH2                      (2U)
// #define SDADC2_CH3                      (3U)
// #define SDADC3_CH0                      (0U)
// #define SDADC3_CH1                      (1U)
// #define SDADC3_CH2                      (2U)
// #define SDADC3_CH3                      (3U)
// #define SDADC3_CH4                      (4U)
// #define SDADC3_CH5                      (5U)
// #define SDADC3_CH6                      (6U)
// #define SDADC3_CH7                      (7U)
// #define SDADC4_CH0                      (0U)
// #define SDADC4_CH1                      (1U)
// #define SDADC4_CH2                      (2U)
// #define SDADC4_CH3                      (3U)
// #define SDADC6_CH0                      (0U)
// #define SDADC6_CH1                      (1U)
// #define SDADC6_CH2                      (2U)
// #define SDADC6_CH3                      (3U)
// #define SDADC7_CH0                      (0U)
// #define SDADC7_CH1                      (1U)
// #define SDADC7_CH2                      (2U)
// #define SDADC7_CH3                      (3U)
// #define SDADC8_CH0                      (0U)
// #define SDADC8_CH1                      (1U)
// #define SDADC8_CH2                      (2U)
// #define SDADC8_CH3                      (3U)

#define SDADC_VREFL_MVOLT               (0U)
#define SDADC_VREFH_MVOLT               (5000U)


/**
 * @brief SDADC CIC Filter Mode
 */
#define SDADC_CIC_MODE_CIC3     (0U)

/**
 * @brief SDADC hardware trigger count
 */
#define SDADC_HW_TRIG_CNT       (15U)

/*******************************************************************************
 * @brief SDADC Control Register (SDADC_CTRL: SDADC_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_CTRL_SetSdadcEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    BasePtr->CTRL.R = ((EnDis == FALSE) ? 0UL : SDADC_CTRL_EN_MASK);
}

LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_CTRL_GetSdadcEnDis(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)(BasePtr->CTRL.R & SDADC_CTRL_EN_MASK);
}

/*******************************************************************************
 * @brief SDADC Gain Correction Register (SDADC_GAINCORR: GAINFACTOR)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_GAINCORR_SetMultiFactor \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CorrMultiFactor \
)
{
    BasePtr->GAINCORR.R &= ~SDADC_GAINCORR_GAINFACTOR_MASK;
    BasePtr->GAINCORR.R |= SDADC_GAINCORR_GAINFACTOR(CorrMultiFactor);
}

/*******************************************************************************
 * @brief SDADC Gain Correction Register (SDADC_GAINCORR: CICSHIFT)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_GAINCORR_SetCICShift \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) CICShift \
)
{
    BasePtr->GAINCORR.R &= ~SDADC_GAINCORR_CICSHIFT_MASK;
    BasePtr->GAINCORR.R |= SDADC_GAINCORR_CICSHIFT(CICShift);
}

LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_GAINCORR_SetCorrection \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CorrMultiFactor, \
    CONST(uint8, SDADC_CONST) CICShift \
)
{
    BasePtr->GAINCORR.R = SDADC_GAINCORR_GAINFACTOR(CorrMultiFactor) | SDADC_GAINCORR_CICSHIFT(CICShift);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_GAINCORR_GetCorrection(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->GAINCORR.R & (SDADC_GAINCORR_GAINFACTOR_MASK | SDADC_GAINCORR_CICSHIFT_MASK));
}

/*******************************************************************************
 * @brief SDADC Gain Calibration Register (SDADC_GAINCAL: CALFACTOR)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_GAINCAL_SetMultiFactor \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CalMultiFactor \
)
{
    BasePtr->GAINCAL.R = SDADC_GAINCAL_CALFACTOR(CalMultiFactor);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_GAINCAL_GetCalibration(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->GAINCAL.R & SDADC_GAINCAL_CALFACTOR_MASK);
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, CIC Filter (SDADC_FCFGC: CFMDF)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGC_SetCICFilterDecFactor \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CICFilterDecFactor \
)
{
    BasePtr->FCFGC.R &= ~SDADC_FCFGC_CFMDF_MASK;
    BasePtr->FCFGC.R |= SDADC_FCFGC_CFMDF(CICFilterDecFactor);
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, CIC Filter (SDADC_FCFGC: CFMSV)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGC_SetCICFilterStartVal \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CICFilterStartVal \
)
{
    BasePtr->FCFGC.R &= ~SDADC_FCFGC_CFMSV_MASK;
    BasePtr->FCFGC.R |= SDADC_FCFGC_CFMSV(CICFilterStartVal);
}

LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGC_SetFilterCfgCIC \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CICFilterStartVal, \
    CONST(uint16, SDADC_CONST) CICFilterDecFactor \
)
{
    BasePtr->FCFGC.R = SDADC_FCFGC_CFMSV(CICFilterStartVal) | SDADC_FCFGC_CFMDF(CICFilterDecFactor);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_FCFGC_GetFilterCfgCIC(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->FCFGC.R);
}

/*******************************************************************************
 * @brief SDADC Filter Counter Register, CIC Filter (SDADC_FCNTC: CFMDCNT)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCNTC_SetCICFilterDecCounter \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CICFilterDecCounter \
)
{
    BasePtr->FCNTC.R &= ~SDADC_FCNTC_CFMDCNT_MASK;
    BasePtr->FCNTC.R |= SDADC_FCNTC_CFMDCNT(CICFilterDecCounter);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_FCNTC_GetCICFilterDecCounter(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->FCNTC.R & SDADC_FCNTC_CFMDCNT_MASK);
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: FIR0EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetFIR0FilterEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_FIR0EN_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_FIR0EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: FIR1EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetFIR1FilterEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_FIR1EN_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_FIR1EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: OVCEN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetOvershootCompenEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_OVCEN_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_OVCEN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: FIR1DEC)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetFIR1FilterDecRate \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FIR1FilterDecRate \
)
{
    if (FIR1FilterDecRate == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_FIR1DEC_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_FIR1DEC_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: CICMOD)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetCICFilterMode \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) CICFilterMode \
)
{
    if (CICFilterMode == SDADC_CIC_MODE_CIC3)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_CICMOD_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_CICMOD_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: PFEN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetPrefilterEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_PFEN_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_PFEN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: COMPTR_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetBoundaryComparatorEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_COMPTR_EN_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_COMPTR_EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: EXT_MESH_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetExtMeshClkEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_EXT_MESH_EN_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_EXT_MESH_EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: OCEN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetOffsetCompenFilterEn \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) OffsetCompenFilterEn \
)
{
    BasePtr->FCFGM.R &= ~SDADC_FCFGM_OCEN_MASK;
    BasePtr->FCFGM.R |= SDADC_FCFGM_OCEN(OffsetCompenFilterEn);
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: CH_WRAP_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetChannelWraparoundEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_CH_WRAP_EN_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_CH_WRAP_EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: DIFF_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetDifferenceEnDis 
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_DIFF_EN_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_DIFF_EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: CALIB_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetCalibEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_CALIB_EN_MASK;
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_CALIB_EN_MASK;
    }
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_FCFGM_GetFilterCfgMain(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->FCFGM.R);
}

/*******************************************************************************
 * @brief SDADC Offset Compensation Register (SDADC_OFFCOMP: OFFSET)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_OFFCOMP_SetOffsetVal \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) OffsetVal \
)
{
    BasePtr->OFFCOMP.R = SDADC_OFFCOMP_OFFSET(OffsetVal);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_OFFCOMP_GetOffsetVal(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->OFFCOMP.R);
}

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SDADC_IECFG: FWM_INT_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IECFG_SetFifoWaterMarkerIntEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SDADC_IECFG_FWM_INT_EN_MASK;
    }
    else
    {
        BasePtr->IECFG.R |= SDADC_IECFG_FWM_INT_EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SDADC_IECFG: FOV_INT_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IECFG_SetFifoOverFlowIntEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SDADC_IECFG_FOV_INT_EN_MASK;
    }
    else
    {
        BasePtr->IECFG.R |= SDADC_IECFG_FOV_INT_EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SDADC_IECFG: DOV_INT_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IECFG_SetDataOverFlowIntEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SDADC_IECFG_DOV_INT_EN_MASK;
    }
    else
    {
        BasePtr->IECFG.R |= SDADC_IECFG_DOV_INT_EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SDADC_IECFG: DMA_REQ_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IECFG_SetDMAReqEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SDADC_IECFG_DMA_REQ_EN_MASK;
    }
    else
    {
        BasePtr->IECFG.R |= SDADC_IECFG_DMA_REQ_EN_MASK;
    }
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_IECFG_GetIntDMACfg(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->IECFG.R);
}

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SDADC_FCFG: FIFOSIZE)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFG_SetFifoSize
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FifoSize \
)
{
    BasePtr->FCFG.R &= ~SDADC_FCFG_FIFOSIZE_MASK;
    BasePtr->FCFG.R |= SDADC_FCFG_FIFOSIZE(FifoSize);
}

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SDADC_FCFG: FIFOWM)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFG_SetFifoWaterMarkerVal \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FifoWaterMarkerVal \
)
{
    BasePtr->FCFG.R &= ~SDADC_FCFG_FIFOWM_MASK;
    BasePtr->FCFG.R |= SDADC_FCFG_FIFOWM(FifoWaterMarkerVal);
}

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SDADC_FCFG: INFOEN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFG_SetInfoEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFG.R &= ~SDADC_FCFG_INFOEN_MASK;
    }
    else
    {
        BasePtr->FCFG.R |= SDADC_FCFG_INFOEN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SDADC_FCFG: SIGNEN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCFG_SetSignEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFG.R &= ~SDADC_FCFG_SIGNEN_MASK;
    }
    else
    {
        BasePtr->FCFG.R |= SDADC_FCFG_SIGNEN_MASK;
    }
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_FCFG_GetFifoCfg(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->FCFG.R);
}

/*******************************************************************************
 * @brief SDADC FIFO Data Register (SDADC_FDATA: DATA)
 *******************************************************************************/
LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_FDATA_GetFifoData(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->FDATA.R);
}

/*******************************************************************************
 * @brief SDADC Integrator Status Register (SDADC_ISTAT: NVALCNT)
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_ISTAT_GetNumOfValCount(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)(BasePtr->ISTAT.R & SDADC_ISTAT_NVALCNT_MASK);
}

/*******************************************************************************
 * @brief SDADC Integrator Status Register (SDADC_ISTAT: REPCNT)
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_ISTAT_GetIntegrationCycleCount(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)((BasePtr->ISTAT.R & SDADC_ISTAT_REPCNT_MASK) >> SDADC_ISTAT_REPCNT_SHIFT);
}

/*******************************************************************************
 * @brief SDADC Integrator Status Register (SDADC_ISTAT: INTEN)
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_ISTAT_GetIntegrationEn(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)((BasePtr->ISTAT.R & SDADC_ISTAT_INTEN_MASK) >> SDADC_ISTAT_INTEN_SHIFT);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_ISTAT_GetIntegrStatus(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->ISTAT.R);
}

/*******************************************************************************
 * @brief SDADC Intermediate Integration Value Register (SDADC_IIVAL: IVAL)
 *******************************************************************************/
LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_IIVAL_GetInterIntegrationVal(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->IIVAL.R);
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: ISC)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetIntegratorShiftCtrl \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) IntegratorShiftCtrl \
)
{
    BasePtr->IWCTR.R &= ~SDADC_IWCTR_ISC_MASK;
    BasePtr->IWCTR.R |= SDADC_IWCTR_ISC(IntegratorShiftCtrl);
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: IWS)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetIntegrationWindowSize \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) IntegrationWindowSize \
)
{
    if (IntegrationWindowSize == FALSE)
    {
        BasePtr->IWCTR.R &= ~SDADC_IWCTR_IWS_MASK;
    }
    else
    {
        BasePtr->IWCTR.R |= SDADC_IWCTR_IWS_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: FRC)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetFilterRestartCtrl \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FilterRestartCtrl \
)
{
    if (FilterRestartCtrl == FALSE)
    {
        BasePtr->IWCTR.R &= ~SDADC_IWCTR_FRC_MASK;
    }
    else
    {
        BasePtr->IWCTR.R |= SDADC_IWCTR_FRC_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: REPVAL)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetIntegrationCycle \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) IntegrationCycle \
)
{
    BasePtr->IWCTR.R &= ~SDADC_IWCTR_REPVAL_MASK;
    BasePtr->IWCTR.R |= SDADC_IWCTR_REPVAL(IntegrationCycle);
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: NVALDIS)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetNumberOfValDiscarded \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) NumberOfValDiscarded \
)
{
    BasePtr->IWCTR.R &= ~SDADC_IWCTR_NVALDIS_MASK;
    BasePtr->IWCTR.R |= SDADC_IWCTR_NVALDIS(NumberOfValDiscarded);
}

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: NVALINT)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetNumberOfValAccumulated \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) NumberOfValAccumulated \
)
{
    BasePtr->IWCTR.R &= ~SDADC_IWCTR_NVALINT_MASK;
    BasePtr->IWCTR.R |= SDADC_IWCTR_NVALINT(NumberOfValAccumulated);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_IWCTR_GetIntegrWindowCtrl(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->IWCTR.R);
}

/*******************************************************************************
 * @brief SDADC Demodulator Input Configuration Register (SDADC_DICFG: ITRMODE)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_DICFG_SetIntegratorTriggerMode \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) IntegratorTriggerMode \
)
{
    BasePtr->DICFG.R = SDADC_DICFG_ITRMODE(IntegratorTriggerMode);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_DICFG_GetDemodulatorInputCfg(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->DICFG.R);
}

/*******************************************************************************
 * @brief SDADC Boundary Select Register (SDADC_BOUNDSEL: BOUNDARYL / BOUNDARYU)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_BOUNDSEL_SetLowerUpperBoundaryLimit \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) LowerBoundaryLimit, \
    CONST(uint16, SDADC_CONST) UpperBoundaryLimit \
)
{
    BasePtr->BOUNDSEL.R = SDADC_BOUNDSEL_BOUNDARYL(LowerBoundaryLimit) | SDADC_BOUNDSEL_BOUNDARYU(UpperBoundaryLimit);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_BOUNDSEL_GetBoundary(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->BOUNDSEL.R);
}

/*******************************************************************************
 * @brief SDADC WaterMarker Interrupt State Register (SDADC_WMINTSTAT: FWM_INT)
 *
 * @note  Read / Write 1 clear.
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_WMINTSTAT_GetWaterMarkerIntState(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)(BasePtr->WMINTSTAT.R & SDADC_WMINTSTAT_FWM_INT_MASK);
}

LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_WMINTSTAT_ClearWaterMarkerIntState(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    BasePtr->WMINTSTAT.R = SDADC_WMINTSTAT_FWM_INT_MASK;
}

/*******************************************************************************
 * @brief SDADC OverFlow Interrupt State Register
 *          (SDADC_OVINTSTAT: FOV_INT / DOV_INT)
 *
 * @note  Read / Write 1 clear.
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_OVINTSTAT_GetDataOverFlowIntState(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)((BasePtr->OVINTSTAT.R & SDADC_OVINTSTAT_DOV_INT_MASK) >> 1U);
}

LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_OVINTSTAT_ClearDataOverFlowIntState(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{															/* PRQA S 4391 */						
    BasePtr->OVINTSTAT.R = SDADC_OVINTSTAT_DOV_INT_MASK;	/* PRQA S 4391 */
}

LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_OVINTSTAT_GetFifoOverFlowIntState(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)(BasePtr->OVINTSTAT.R & SDADC_OVINTSTAT_FOV_INT_MASK);
}

LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_OVINTSTAT_ClearFifoOverFlowIntState(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{															/* PRQA S 4391 */
    BasePtr->OVINTSTAT.R = SDADC_OVINTSTAT_FOV_INT_MASK;	/* PRQA S 4391 */
}

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SDADC_OVSCFG: SRFS)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_OVSCFG_SetSlewRateFilterStrength \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) SlewRateFilterStrength \
)
{
    BasePtr->OVSCFG.R &= ~SDADC_OVSCFG_SRFS_MASK;
    BasePtr->OVSCFG.R |= SDADC_OVSCFG_SRFS(SlewRateFilterStrength);
}

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SDADC_OVSCFG: SRFRT)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_OVSCFG_SetSlewRateFilterRunTime \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) SlewRateFilterRunTime \
)
{
    BasePtr->OVSCFG.R &= ~SDADC_OVSCFG_SRFRT_MASK;
    BasePtr->OVSCFG.R |= SDADC_OVSCFG_SRFRT(SlewRateFilterRunTime);
}

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SDADC_OVSCFG: SDM)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_OVSCFG_SetStepDetectionMode \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) StepDetectionMode \
)
{
    if (StepDetectionMode == FALSE)
    {
        BasePtr->OVSCFG.R &= ~SDADC_OVSCFG_SDM_MASK;
    }
    else
    {
        BasePtr->OVSCFG.R |= SDADC_OVSCFG_SDM_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SDADC_OVSCFG: SDTH)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_OVSCFG_SetStepDetectionThreshold \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) StepDetectionThreshold \
)
{
    BasePtr->OVSCFG.R &= ~SDADC_OVSCFG_SDTH_MASK;
    BasePtr->OVSCFG.R |= SDADC_OVSCFG_SDTH(StepDetectionThreshold);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_OVSCFG_GetOvershootCompCfg(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->OVSCFG.R);
}

/*******************************************************************************
 * @brief SDADC Hardware Trigger Configuration Register
 *          (SDADC_HTCFG: HT0 ~ HT15)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_HTCFG_SetHwTriggerEdge \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint32, SDADC_CONST) HwTrigIdx, \
    CONST(uint32, SDADC_CONST) HwTrigEdge \
)
{
    if (HwTrigIdx < SDADC_HW_TRIG_CNT)
    {	
        /* PRQA S 1891 */	
        if((SDADC_HTCFG_HT0_WIDTH * HwTrigIdx) <= 32U)
        {
            BasePtr->HTCFG.R &= ~(SDADC_HTCFG_HT0_MASK  << (SDADC_HTCFG_HT0_WIDTH * HwTrigIdx));			/* PRQA S 1891 */    
        }
        if((SDADC_HTCFG_HT0_WIDTH * HwTrigIdx) <= 32U)
        {
            BasePtr->HTCFG.R |= ((HwTrigEdge & SDADC_HTCFG_HT0_MASK) << (SDADC_HTCFG_HT0_WIDTH * HwTrigIdx));	/* PRQA S 1891 */	
        }
    }
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_HTCFG_GetHwTriggerEdge(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->HTCFG.R);
}

/*******************************************************************************
 * @brief SDADC Software Trigger Configuration Register (SDADC_STCFG: SH_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_STCFG_SetSoftTrigEn(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    BasePtr->STCFG.R = SDADC_STCFG_SH_EN_MASK;
}

/*******************************************************************************
 * @brief SDADC Software Trigger Configuration Register (SDADC_STCFG: SH_CLR)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_STCFG_ClearSoftTrig(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    BasePtr->STCFG.R = SDADC_STCFG_SH_CLR_MASK;
}

/*******************************************************************************
 * @brief SDADC Software Trigger Configuration Register (SDADC_STCFG: FSRSTN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_STCFG_SetFifoSoftReset(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    BasePtr->STCFG.R = SDADC_STCFG_FSRSTN_MASK;
}

/*******************************************************************************
 * @brief SDADC Filter Chain Discard Register (SDADC_FCDIS: FCDIS_EN)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCDIS_SetFilterChainDiscardEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCDIS.R &= ~SDADC_FCDIS_FCDIS_EN_MASK;
    }
    else
    {
        BasePtr->FCDIS.R |= SDADC_FCDIS_FCDIS_EN_MASK;
    }
}

/*******************************************************************************
 * @brief SDADC Filter Chain Discard Register (SDADC_FCDIS: FCDIS_NUM)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_FCDIS_SetFilterChainDiscardNum \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FilterChainDiscardNum \
)
{
    BasePtr->FCDIS.R &= ~SDADC_FCDIS_FCDIS_NUM_MASK;
    BasePtr->FCDIS.R |= SDADC_FCDIS_FCDIS_NUM(FilterChainDiscardNum);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_FCDIS_GetFilterChainCfg(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->FCDIS.R);
}

/*******************************************************************************
 * @brief SDADC Channel default & wrap Register (SDADC_CH_WRAP: CH_DFLT /CH_NUM)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_CH_WRAP_SetChannelDefault \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) ChannelDefault, \
    CONST(uint8, SDADC_CONST) ChannelWrap \
)
{
    BasePtr->CH_WRAP.R = SDADC_CH_WRAP_CH_DFLT(ChannelDefault) | SDADC_CH_WRAP_CH_NUM(ChannelWrap);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_CH_WRAP_GetChannelCfg(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->CH_WRAP.R);
}

/*******************************************************************************
 * @brief SDADC Data OverFlow Information Register (SDADC_DOV_INFO: DATA)
 *******************************************************************************/
LOCAL_INLINE FUNC(uint16, SDADC_CODE) SDADC_DOV_INFO_GetUnderflowOrOverflowData(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint16)(BasePtr->DOV_INFO.R & SDADC_DOV_INFO_DATA_MASK);
}

/*******************************************************************************
 * @brief SDADC Data OverFlow Information Register (SDADC_DOV_INFO: COMPTR_UVF)
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_DOV_INFO_GetDataCompareUnderFlow(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)((BasePtr->DOV_INFO.R & SDADC_DOV_INFO_COMPTR_UVF_MASK) >> SDADC_DOV_INFO_COMPTR_UVF_SHIFT);
}

/*******************************************************************************
 * @brief SDADC Data OverFlow Information Register (SDADC_DOV_INFO: COMPTR_OVF)
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_DOV_INFO_GetDataCompareOverFlow(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)((BasePtr->DOV_INFO.R & SDADC_DOV_INFO_COMPTR_OVF_MASK) >> SDADC_DOV_INFO_COMPTR_OVF_SHIFT);
}

/*******************************************************************************
 * @brief SDADC Data OverFlow Information Register (SDADC_DOV_INFO: CH_INFO)
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, SDADC_CODE) SDADC_DOV_INFO_GetChInfo(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)((BasePtr->DOV_INFO.R & SDADC_DOV_INFO_CH_INFO_MASK) >> SDADC_DOV_INFO_CH_INFO_SHIFT);
}

/*******************************************************************************
 * @brief SDADC BIAS Register (SDADC_BIAS)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_BIAS_Set \
(

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) bias_res_trim_lv, \
    CONST(uint8, SDADC_CONST) test_bias_lv \
)
{
    BasePtr->BIAS.R = SDADC_BIAS_BIAS_RES_TRIM_LV(bias_res_trim_lv) | SDADC_BIAS_TEST_BIAS_LV(test_bias_lv);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_BIAS_Get(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->BIAS.R);
}

/*******************************************************************************
 * @brief SDADC Analog Channel Resistor Select Register (SDADC_RES)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_RES_SetResistorSelChan \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) res_p_lv, \
    CONST(uint8, SDADC_CONST) res_n_lv \
)
{
    BasePtr->RES.R = SDADC_RES_RES_N_LV(res_n_lv) | SDADC_RES_RES_P_LV(res_p_lv);
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_RES_GetResistorSelChan(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->RES.R);
}

/*******************************************************************************
 * @brief SDADC Analog Module Configuration Register (SDADC_ATT)
 **************************************************************** ***************/
LOCAL_INLINE FUNC(void, SDADC_CODE) SDADC_ATT_SetAnalogModuleCfg \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) gain_lv, \
    CONST(uint8, SDADC_CONST) vcom_sel_lv, \
    CONST(uint8, SDADC_CONST) adc_div_lv \
)
{
    BasePtr->ATT.R = (SDADC_ATT_GAIN_LV(gain_lv) | SDADC_ATT_VCOM_SEL_LV(vcom_sel_lv) | \
                      SDADC_ATT_ADC_DIV_LV(adc_div_lv));
}

LOCAL_INLINE FUNC(uint32, SDADC_CODE) SDADC_ATT_GetAnalogModuleCfg(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->ATT.R);
}


/*******************************************************************************
 * Function declaration.
 *******************************************************************************/
FUNC(void, SDADC_CODE) SDADC_LLD_Init \
(
	CONST(Sdadc_InstanceType, SDADC_CONST) instance, \
	CONSTP2CONST(Sdadc_ConfigType, SDADC_CONST, SDADC_APPL_CONST) ConfigPtr, \
    CONST(uint16, SDADC_CONST) Trig_Sel
);

FUNC(void, SDADC_CODE) SDADC_LLD_DeInit(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(void, SDADC_CODE) SDADC_LLD_ModuleEnable(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(void, SDADC_CODE) SDADC_LLD_ModuleDisable(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(uint32, SDADC_CODE) SDADC_LLD_GetFifoData(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(void, SDADC_CODE) SDADC_LLD_SetSoftTrigger(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(boolean, SDADC_CODE) SDADC_LLD_GetWaterMarkerIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(void, SDADC_CODE) SDADC_LLD_ClearWaterMarkerIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(boolean, SDADC_CODE) SDADC_LLD_GetDataOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(void, SDADC_CODE) SDADC_LLD_ClearDataOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(boolean, SDADC_CODE) SDADC_LLD_GetFifoOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(void, SDADC_CODE) SDADC_LLD_ClearFifoOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(void, SDADC_CODE) SDADC_LLD_ConfigDma \
(
	CONST(Sdadc_InstanceType, SDADC_CONST) instance, \
	VAR(Sdadc_DmaCfgType, SDADC_VAR) config \
);

FUNC(uint32, SDADC_CODE) SDADC_LLD_GetRecentAccumulation(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(boolean, SDADC_CODE) SDADC_LLD_GetIntegrationEnable(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(void, SDADC_CODE) SDADC_LLD_ResetFifo(CONST(Sdadc_InstanceType, SDADC_CONST) instance);

FUNC(void, SDADC_CODE) SDADC_LLD_SetInterruptState(CONST(Sdadc_InstanceType, SDADC_CONST) instance, VAR(Sdadc_InterruptType, SDADC_VAR) intType, VAR(boolean, SDADC_VAR) intState);

#endif /*RESOURCE_SUPPORT_SDADC_IP*/

#endif /* SDADC_LLD_H_ */


