/**************************************************************************** 
* 
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
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Adc_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Adc.h"
#include "Adc_Irq.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define ADC_PB_VENDOR_ID_C                 176
#define ADC_PB_AR_MAJOR_VER_C              4
#define ADC_PB_AR_MINOR_VER_C              4
#define ADC_PB_AR_PATCH_VER_C              0
#define ADC_PB_SW_MAJOR_VER_C              1
#define ADC_PB_SW_MINOR_VER_C              0
#define ADC_PB_SW_PATCH_VER_C              1

/*============================================FILE VERSION CHECKS===================================*/

#if (ADC_VENDOR_ID != ADC_PB_VENDOR_ID_C)
#error "NON-MATCHED DATA : ADC_PB_VENDOR_ID_C"
#endif

/* Check if current file and ADC header file are of the same Autosar version */
#if (ADC_AR_REL_MAJOR_VER != ADC_PB_AR_MAJOR_VER_C)
#error "NON-MATCHED DATA : ADC_PB_AR_MAJOR_VER_C"
#endif
#if (ADC_AR_REL_MINOR_VER != ADC_PB_AR_MINOR_VER_C)
#error "NON-MATCHED DATA : ADC_PB_AR_MINOR_VER_C"
#endif
#if (ADC_AR_REL_REV_VER != ADC_PB_AR_PATCH_VER_C)
#error "NON-MATCHED DATA : ADC_PB_AR_PATCH_VER_C"
#endif

/* Check if current file and ADC header file are of the same Software version */
#if (ADC_SW_MAJOR_VER != ADC_PB_SW_MAJOR_VER_C)
#error "NON-MATCHED DATA : ADC_PB_SW_MAJOR_VER_C"
#endif
#if (ADC_SW_MINOR_VER != ADC_PB_SW_MINOR_VER_C)
#error "NON-MATCHED DATA : ADC_PB_SW_MINOR_VER_C"
#endif
#if (ADC_SW_PATCH_VER != ADC_PB_SW_PATCH_VER_C)
#error "NON-MATCHED DATA : ADC_PB_SW_PATCH_VER_C"
#endif

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit2_Group0_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit2_Group0_CmdBuf[1U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit2_Group0_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit2_Group0_ResultBuf[1U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit3_Group1_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit3_Group1_CmdBuf[1U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit3_Group1_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit3_Group1_ResultBuf[1U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit8_Group2_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit8_Group2_CmdBuf[1U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit8_Group2_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit8_Group2_ResultBuf[1U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group3_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit9_Group3_CmdBuf[1U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group3_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit9_Group3_ResultBuf[1U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit10_Group4_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit10_Group4_CmdBuf[1U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit10_Group4_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit10_Group4_ResultBuf[1U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit11_Group5_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit11_Group5_CmdBuf[1U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit11_Group5_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit11_Group5_ResultBuf[1U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group6_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit9_Group6_CmdBuf[1U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit9_Group6_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit9_Group6_ResultBuf[1U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit10_Group7_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit10_Group7_CmdBuf[1U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit10_Group7_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit10_Group7_ResultBuf[1U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"



static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_0[1U] =
{   
    {   /* Group_0 ChannelIndex_0: ADC2_AdcChannel_0 CH0 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = (Eqadc_LongSampTimeType)0U,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_0[1U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#endif

static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_1[1U] =
{   
    {   /* Group_1 ChannelIndex_0: ADC3_AdcChannel_0 CH0 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = (Eqadc_LongSampTimeType)0U,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_1[1U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#endif

static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_2[1U] =
{   
    {   /* Group_2 ChannelIndex_0: ADC8_AdcChannel_0 CH6 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = (Eqadc_LongSampTimeType)0U,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH6,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_2[1U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#endif

static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_3[1U] =
{   
    {   /* Group_3 ChannelIndex_0: ADC9_AdcChannel_0 CH10 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = (Eqadc_LongSampTimeType)0U,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_3[1U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#endif

static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_4[1U] =
{   
    {   /* Group_4 ChannelIndex_0: ADC10_AdcChannel_0 CH1 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_0,
        .LongSampTime       = (Eqadc_LongSampTimeType)0U,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH1,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_4[1U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#endif

static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_5[1U] =
{   
    {   /* Group_5 ChannelIndex_0: ADC11_AdcChannel_0 CH0 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_1,
        .LongSampTime       = (Eqadc_LongSampTimeType)0U,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH0,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_5[1U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#endif

static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_6[1U] =
{   
    {   /* Group_6 ChannelIndex_0: ADC9_AdcChannel_8 CH8 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)1U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = (Eqadc_LongSampTimeType)0U,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH8,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_6[1U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#endif

static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_7[1U] =
{   
    {   /* Group_7 ChannelIndex_0: ADC10_AdcChannel_10 CH10 */
        .Eoq                = TRUE,
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)0U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = EQADC_FIFO_2,
        .LongSampTime       = (Eqadc_LongSampTimeType)0U,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = EQADC_CH10,
        .AltConfigSel       = EQADC_ALT_CONFIG_DISABLE,
        .FlushOrFMT         = FALSE
    }
};

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_7[1U] =
{
    {
        .RangeSelect    = ADC_RANGE_ALWAYS,
        .LimitCheck     = FALSE,
        .HighLimit      = 0U,
        .LowLimit       = 0U
    }
};
#endif

static CONST(Adc_GroupConfigType, ADC_VAR) Group_Cfg[8U] =
{   
	{   /* Group 0, ADC2, HardWareTrig */
		.HwUnitId            = 2U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,
        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN22_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit2_Group0_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN23_NUMBER,
        .ResultIrq           = &Eqadc1_DmaResult0,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit2_Group0_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
		.Prio                = 0U,
		.ConvMode            = ADC_CONV_MODE_ONESHOT,
		.StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
		.AccessMode          = ADC_ACCESS_MODE_SINGLE,
		.HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
		.ChannelCount        = 1U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_0,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER5,
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_5,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif
        .Resolution          = ADC_RESOLUTION_BIT12,
		.Eqadc_ConvCmd       = Eqadc_ConvCfg_0,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_0,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 1, ADC3, HardWareTrig */
		.HwUnitId            = 3U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,
        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN20_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit3_Group1_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN21_NUMBER,
        .ResultIrq           = &Eqadc1_DmaResult1,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit3_Group1_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
		.Prio                = 0U,
		.ConvMode            = ADC_CONV_MODE_ONESHOT,
		.StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
		.AccessMode          = ADC_ACCESS_MODE_SINGLE,
		.HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
		.ChannelCount        = 1U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_1,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER6,
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_7,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif
        .Resolution          = ADC_RESOLUTION_BIT12,
		.Eqadc_ConvCmd       = Eqadc_ConvCfg_1,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_1,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 2, ADC8, HardWareTrig */
		.HwUnitId            = 8U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,
        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN48_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit8_Group2_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN49_NUMBER,
        .ResultIrq           = &Eqadc4_DmaResult0,
        .ResultCallback      = &Eqadc4_Adc8_RsltCallback,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit8_Group2_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
		.Prio                = 0U,
		.ConvMode            = ADC_CONV_MODE_ONESHOT,
		.StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
		.AccessMode          = ADC_ACCESS_MODE_SINGLE,
		.HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
		.ChannelCount        = 1U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_0,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER8,
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_11,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif
        .Resolution          = ADC_RESOLUTION_BIT12,
		.Eqadc_ConvCmd       = Eqadc_ConvCfg_2,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_2,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 3, ADC9, HardWareTrig */
		.HwUnitId            = 9U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,
        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN50_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit9_Group3_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN51_NUMBER,
        .ResultIrq           = &Eqadc4_DmaResult1,
        .ResultCallback      = &Eqadc4_Adc9_RsltCallback,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit9_Group3_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
		.Prio                = 0U,
		.ConvMode            = ADC_CONV_MODE_ONESHOT,
		.StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
		.AccessMode          = ADC_ACCESS_MODE_SINGLE,
		.HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
		.ChannelCount        = 1U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_1,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG3_MEMBER9,
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_13,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif
        .Resolution          = ADC_RESOLUTION_BIT12,
		.Eqadc_ConvCmd       = Eqadc_ConvCfg_3,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_3,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 4, ADC10, HardWareTrig */
		.HwUnitId            = 10U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,
        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN120_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit10_Group4_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN121_NUMBER,
        .ResultIrq           = &Eqadc5_DmaResult0,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit10_Group4_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
		.Prio                = 0U,
		.ConvMode            = ADC_CONV_MODE_ONESHOT,
		.StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
		.AccessMode          = ADC_ACCESS_MODE_SINGLE,
		.HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
		.ChannelCount        = 1U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_0,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER10,
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_11,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif
        .Resolution          = ADC_RESOLUTION_BIT12,
		.Eqadc_ConvCmd       = Eqadc_ConvCfg_4,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_4,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 5, ADC11, HardWareTrig */
		.HwUnitId            = 11U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,
        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN122_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit11_Group5_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN123_NUMBER,
        .ResultIrq           = &Eqadc5_DmaResult1,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit11_Group5_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
		.Prio                = 0U,
		.ConvMode            = ADC_CONV_MODE_ONESHOT,
		.StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
		.AccessMode          = ADC_ACCESS_MODE_SINGLE,
		.HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
		.ChannelCount        = 1U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_1,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG3_MEMBER11,
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_13,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif
        .Resolution          = ADC_RESOLUTION_BIT12,
		.Eqadc_ConvCmd       = Eqadc_ConvCfg_5,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_5,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 6, ADC9, HardWareTrig */
		.HwUnitId            = 9U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,
        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN54_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit9_Group6_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN55_NUMBER,
        .ResultIrq           = &Eqadc4_DmaResult2,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit9_Group6_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
		.Prio                = 0U,
		.ConvMode            = ADC_CONV_MODE_ONESHOT,
		.StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
		.AccessMode          = ADC_ACCESS_MODE_SINGLE,
		.HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
		.ChannelCount        = 1U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_2,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG3_MEMBER10,
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_13,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif
        .Resolution          = ADC_RESOLUTION_BIT12,
		.Eqadc_ConvCmd       = Eqadc_ConvCfg_6,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_6,
#endif
        .Adc_AlternatSet     = NULL_PTR
	},
	{   /* Group 7, ADC10, HardWareTrig */
		.HwUnitId            = 10U,
        .ExtTrigDigFilter    = 0U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)0U,
        .ExtMuxEn            = FALSE,
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)1U,
        .DmaMappedChan       = EDMA_CHN124_NUMBER,
        .DMACompleteClearERQ = FALSE,
        .Callback            = NULL_PTR,
        .CallbackParam       = NULL_PTR,
        .StrPtr              = HwUnit10_Group7_CmdBuf,
        .ResultDmaMappedChan = EDMA_CHN125_NUMBER,
        .ResultIrq           = &Eqadc5_DmaResult2,
        .ResultCallback      = NULL_PTR,
        .ResultCallbackParam = NULL_PTR,
		.DestPtr             = HwUnit10_Group7_ResultBuf,
        .DmaSampleNum        = 1U,
        .SwOrHw              = ADC_TRIGG_SRC_HW,
		.Prio                = 0U,
		.ConvMode            = ADC_CONV_MODE_ONESHOT,
		.StreamBufMode       = ADC_STREAM_BUFFER_LINEAR,
		.AccessMode          = ADC_ACCESS_MODE_SINGLE,
		.HwTriggerSignal     = ADC_HW_TRIG_RISING_EDGE,
		.StreamNumSamp       = 1U,
		.ChannelCount        = 1U,
		.GroupNotif          = NULL_PTR,
        .GroupNotif_OverFlow = NULL_PTR,
        .CFifo               = EQADC_FIFO_2,
        .HwTrigSrc           = EQADC_HW_TRIG_GTM_TRIG0_MEMBER11,
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = GTM_ADC_TRIG_OUTSEL_11,
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = FALSE,
        .TrigDelayVal        = 0U,
#endif
        .Resolution          = ADC_RESOLUTION_BIT12,
		.Eqadc_ConvCmd       = Eqadc_ConvCfg_7,
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_7,
#endif
        .Adc_AlternatSet     = NULL_PTR
	}
};

static CONST(Adc_CoreMapItemType, ADC_CONST) Adc_CoreMap[ADC_CONFIG_GROUPS] =
{
    {
        .GroupId        = 0U,
        .GroupCoreId    = 3U
    },
    {
        .GroupId        = 1U,
        .GroupCoreId    = 3U
    },
    {
        .GroupId        = 2U,
        .GroupCoreId    = 3U
    },
    {
        .GroupId        = 3U,
        .GroupCoreId    = 3U
    },
    {
        .GroupId        = 4U,
        .GroupCoreId    = 3U
    },
    {
        .GroupId        = 5U,
        .GroupCoreId    = 3U
    },
    {
        .GroupId        = 6U,
        .GroupCoreId    = 3U
    },
    {
        .GroupId        = 7U,
        .GroupCoreId    = 3U
    }
};

CONST(Adc_ConfigType, ADC_CONST) Adc_Config =
{
    .Adc_GroupConfig    = Group_Cfg,
    .Adc_CoreMapItem    = Adc_CoreMap
};

#ifdef __cplusplus
}
#endif
