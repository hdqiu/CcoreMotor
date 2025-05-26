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

[!AUTOSPACING!]
[!VAR "Groupcount" = "0"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!LOOP "AdcGroup/*"!]
        [!VAR "Groupcount" = "$Groupcount+1"!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!FOR "DmaBufferIndex" = "0" TO "num:i($Groupcount)-1"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!LOOP "AdcGroup/*"!]
        [!IF "$DmaBufferIndex = AdcGroupId"!]
        [!IF "GroupSelIntOrDma = 'DMA'"!]
#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit[!"substring-after(string(../../AdcHwUnitId),'ADC')"!]_Group[!"AdcGroupId"!]_CmdBuf(DMA buffer) */
VAR(uint32, ADC_VAR) HwUnit[!"substring-after(string(../../AdcHwUnitId),'ADC')"!]_Group[!"AdcGroupId"!]_CmdBuf[[!"num:i(num:i(count(AdcGroupDefinition/*)) * AdcStreamingNumSamples * DmaSampleNum)"!]U] = {0U};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
/* HwUnit[!"substring-after(string(../../AdcHwUnitId),'ADC')"!]_Group[!"AdcGroupId"!]_ResultBuf(DMA buffer) */
VAR(uint16, ADC_VAR) HwUnit[!"substring-after(string(../../AdcHwUnitId),'ADC')"!]_Group[!"AdcGroupId"!]_ResultBuf[[!"num:i(num:i(count(AdcGroupDefinition/*)) * AdcStreamingNumSamples * DmaSampleNum)"!]U] = {0U};   
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

        [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDFOR!]
[!MACRO "GetCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRef_cnt" = "num:i(count(AdcGroupEcucPartitionRef/*))"!][!//
    [!IF "$EcucPartitionRef_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!//
    [!ELSE!][!//
        [!FOR "GetCoreIdIndex" = "0" TO "num:i($EcucPartitionRef_cnt)-1"!][!//
            [!VAR "ModuEcucPartitionRef" = "string(AdcGroupEcucPartitionRef/*[$GetCoreIdIndex+1])"!][!//
            [!IF "not(node:refexists(AdcGroupEcucPartitionRef/*[$GetCoreIdIndex+1]))"!][!//
                [!ERROR!]  Node [!"$ModuEcucPartitionRef"!] not found [!ENDERROR!]
            [!ELSE!][!//
                [!VAR "OsApplication_cnt" = "num:i(count(as:modconf('Os')[1]/OsApplication/*))"!][!//
                [!IF "$OsApplication_cnt = num:i(0)"!][!//
                    [!ERROR!]  ASPath:/Os/Os/OsApplication is not configured [!ENDERROR!]
                [!ELSE!][!//
                    [!FOR "n" = "0" TO "num:i($OsApplication_cnt)-1"!][!//
                        [!VAR "OsEcucPartitionRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!][!//
                        [!IF "text:match($OsEcucPartitionRef,$ModuEcucPartitionRef)"!][!//
                            [!VAR "EcucPartitionRefMatch_cnt" = "num:i($EcucPartitionRefMatch_cnt)+num:i(1)"!][!//
                            [!IF "not(node:refexists(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1]))"!][!//
                                [!VAR "OsApplicationCoreRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!][!//
                                [!ERROR!]  [!"string(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])"!] is not configured [!ENDERROR!]
                            [!ELSE!][!//
                                [!VAR "CoreID_temp" = "node:ref(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])/EcucCoreId"!][!//
                                [!VAR "CoreID" = "bit:or($CoreID,bit:shl(1,$CoreID_temp))"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDFOR!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
        [!IF "$EcucPartitionRefMatch_cnt = num:i(0)"!][!//
            [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
 [!"$CoreID"!][!//
 [!ENDMACRO!][!//

[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!VAR "adcAlternateConfig_cnt" = "num:i(count(AlternateConfig/*))"!]
[!IF "num:i($adcAlternateConfig_cnt) != 0"!]
static CONST(Eqadc_AlternateSetType, ADC_VAR) AlternateSet_[!"substring-after(string(AdcHwUnitId),'ADC')"!] = 
{
    /* [!"AdcHwUnitId"!] */
    .AltConfigSel       = [!"AlternateConfig/*[1]/AltSelect"!],
    .ResultTransInhibit = [!WS "1"!][!IF "AlternateConfig/*[1]/ResultTransInhibit = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .AltConvResultDEST  = [!"AlternateConfig/*[1]/DestSelect"!],
    .FMTA_SignEn        = [!WS "1"!][!IF "AlternateConfig/*[1]/FMTA_SignEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .AdcPreGain         = [!"AlternateConfig/*[1]/PreGain"!]
};
[!ENDIF!]
[!ENDLOOP!]
    [!FOR "j" = "0" TO "num:i($Groupcount)-1"!]
    [!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!VAR "AdcIdx" = "0"!]
    [!IF "AdcHwUnitId = 'ADC0' or AdcHwUnitId = 'ADC2' or AdcHwUnitId = 'ADC4' or AdcHwUnitId = 'ADC6' or AdcHwUnitId = 'ADC8' or AdcHwUnitId = 'ADC10' or AdcHwUnitId = 'ADC12'"!]
        [!VAR "AdcIdx" = "0"!]
    [!ELSE!]
        [!VAR "AdcIdx" = "1"!]
    [!ENDIF!]
    [!VAR "adcAlternateConfig_cnt" = "num:i(count(AlternateConfig/*))"!]
    [!LOOP "AdcGroup/*"!]
    [!IF "$j = AdcGroupId"!]
    [!VAR "adcGroupDefinition_cnt" = "num:i(count(AdcGroupDefinition/*))"!]
    [!VAR "ChannelCount" = "0"!]
    [!LOOP "AdcGroupDefinition/*"!] 
        [!VAR "ChannelCount" = "$ChannelCount+1"!]
    [!ENDLOOP!]
    [!VAR "ChannelIndex" = "1"!]

static CONST(Eqadc_ConvCmdType, ADC_VAR) Eqadc_ConvCfg_[!"AdcGroupId"!][[!"num:i($ChannelCount)"!]U] =
{   
    [!FOR "GroupChannelIndex" = "0" TO "num:i($adcGroupDefinition_cnt)-1"!]
    [!VAR "SampTime" = "0"!]
    [!IF "node:ref(AdcGroupDefinition/*[$GroupChannelIndex+1])/AdcChannelSampTime = "SAMPLING_CYCLES_2""!]
        [!VAR "SampTime" = "0"!]
    [!ELSEIF "node:ref(AdcGroupDefinition/*[$GroupChannelIndex+1])/AdcChannelSampTime = "SAMPLING_CYCLES_8""!]
        [!VAR "SampTime" = "1"!]
    [!ELSEIF "node:ref(AdcGroupDefinition/*[$GroupChannelIndex+1])/AdcChannelSampTime = "SAMPLING_CYCLES_64""!]
        [!VAR "SampTime" = "2"!]
    [!ELSEIF "node:ref(AdcGroupDefinition/*[$GroupChannelIndex+1])/AdcChannelSampTime = "SAMPLING_CYCLES_128""!]
        [!VAR "SampTime" = "3"!]
    [!ENDIF!]
    {   /* Group_[!"AdcGroupId"!] ChannelIndex_[!"num:i($GroupChannelIndex)"!]: [!SELECT "node:ref(AdcGroupDefinition/*[$GroupChannelIndex+1])"!][!"@name"!][!ENDSELECT!] [!"substring-after(string(node:ref(AdcGroupDefinition/*[$GroupChannelIndex+1])/AdcChannelId),'EQADC_')"!] */
        .Eoq                = [!WS "1"!][!IF "num:i($ChannelIndex) = num:i($ChannelCount)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .Pause              = FALSE,
        .RepeatStart        = FALSE,
        .cBufNum            = (uint8)[!"num:i($AdcIdx)"!]U,
        .CalibConvResEn     = FALSE,
        .RfifoMsgTag        = [!"AdcGroupRFifo"!],
        .LongSampTime       = (Eqadc_LongSampTimeType)[!"num:i($SampTime)"!]U,
        .TimeStampReq       = FALSE,
        .FormatSignEn       = FALSE,
        .ChanNum            = [!"string(node:ref(AdcGroupDefinition/*[$GroupChannelIndex+1])/AdcChannelId)"!],
        .AltConfigSel       = [!WS "1"!][!IF "num:i($adcAlternateConfig_cnt) != 0"!][!"../../AlternateConfig/*[1]/AltSelect"!][!ELSE!]EQADC_ALT_CONFIG_DISABLE[!ENDIF!],
        .FlushOrFMT         = FALSE
        [!VAR "ChannelIndex" = "$ChannelIndex+1"!]
    }[!IF "num:i($GroupChannelIndex) != (num:i($ChannelCount)-1)"!],[!ENDIF!][!CR!]
    [!ENDFOR!]
};

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static CONST(Eqadc_ChannelLimitType, ADC_VAR) ChannelLimit_cfg_[!"AdcGroupId"!][[!"num:i($ChannelCount)"!]U] =
{
    [!FOR "ChannelLimitIndex" = "0" TO "num:i($adcGroupDefinition_cnt)-1"!]
    {
        .RangeSelect    = [!WS "1"!][!IF "../../../../../AdcGeneral/AdcEnableLimitCheck = 'true' and node:ref(AdcGroupDefinition/*[$ChannelLimitIndex+1])/AdcChannelLimitCheck = 'true'"!][!"node:ref(AdcGroupDefinition/*[$ChannelLimitIndex+1])/AdcChannelRangeSelect"!][!ELSE!]ADC_RANGE_ALWAYS[!ENDIF!],
        .LimitCheck     = [!WS "1"!][!IF "../../../../../AdcGeneral/AdcEnableLimitCheck = 'true'"!][!IF "node:ref(AdcGroupDefinition/*[$ChannelLimitIndex+1])/AdcChannelLimitCheck = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ELSE!]FALSE[!ENDIF!],
        .HighLimit      = [!WS "1"!][!IF "../../../../../AdcGeneral/AdcEnableLimitCheck = 'true' and node:ref(AdcGroupDefinition/*[$ChannelLimitIndex+1])/AdcChannelLimitCheck = 'true'"!][!"num:i(node:ref(AdcGroupDefinition/*[$ChannelLimitIndex+1])/AdcChannelHighLimit)"!]U[!ELSE!]0U[!ENDIF!],
        .LowLimit       = [!WS "1"!][!IF "../../../../../AdcGeneral/AdcEnableLimitCheck = 'true' and node:ref(AdcGroupDefinition/*[$ChannelLimitIndex+1])/AdcChannelLimitCheck = 'true'"!][!"num:i(node:ref(AdcGroupDefinition/*[$ChannelLimitIndex+1])/AdcChannelLowLimit)"!]U[!ELSE!]0U[!ENDIF!][!CR!]
    }[!IF "num:i($ChannelLimitIndex) != (num:i($adcGroupDefinition_cnt)-1)"!],[!ENDIF!][!CR!]
    [!ENDFOR!]
};
#endif
    [!ENDIF!]
    [!ENDLOOP!]
    [!ENDLOOP!]
    [!ENDFOR!]

static CONST(Adc_GroupConfigType, ADC_VAR) Group_Cfg[[!"num:i($Groupcount)"!]U] =
{   
    [!FOR "GroupCfgIndex" = "0" TO "num:i($Groupcount)-1"!]
    [!LOOP "AdcConfigSet/AdcHwUnit/*"!]
        [!VAR "DigFilter" = "0"!]
        [!VAR "EqAdc_InstanId" = "0"!]
        [!IF "AdcHwUnitId = 'ADC0' or AdcHwUnitId = 'ADC1'"!]
            [!VAR "DigFilter" = "num:i(../../../ExtTrigDigitalFilterLen/EQADC01_DigitalFilterLength)"!]
            [!VAR "EqAdc_InstanId" = "0"!]
        [!ELSEIF "AdcHwUnitId = 'ADC2' or AdcHwUnitId = 'ADC3'"!]
            [!VAR "DigFilter" = "num:i(../../../ExtTrigDigitalFilterLen/EQADC23_DigitalFilterLength)"!]
            [!VAR "EqAdc_InstanId" = "1"!]
        [!ELSEIF "AdcHwUnitId = 'ADC4' or AdcHwUnitId = 'ADC5'"!]
            [!VAR "DigFilter" = "num:i(../../../ExtTrigDigitalFilterLen/EQADC45_DigitalFilterLength)"!]
            [!VAR "EqAdc_InstanId" = "2"!]
        [!ELSEIF "AdcHwUnitId = 'ADC6' or AdcHwUnitId = 'ADC7'"!]
            [!VAR "DigFilter" = "num:i(../../../ExtTrigDigitalFilterLen/EQADC67_DigitalFilterLength)"!]
            [!VAR "EqAdc_InstanId" = "3"!]
        [!ELSEIF "AdcHwUnitId = 'ADC8' or AdcHwUnitId = 'ADC9'"!]
            [!VAR "DigFilter" = "num:i(../../../ExtTrigDigitalFilterLen/EQADC89_DigitalFilterLength)"!]
            [!VAR "EqAdc_InstanId" = "4"!]
        [!ELSEIF "AdcHwUnitId = 'ADC10' or AdcHwUnitId = 'ADC11'"!]
            [!VAR "DigFilter" = "num:i(../../../ExtTrigDigitalFilterLen/EQADC1011_DigitalFilterLength)"!]
            [!VAR "EqAdc_InstanId" = "5"!]
        [!ELSEIF "AdcHwUnitId = 'ADC12'"!]
            [!VAR "DigFilter" = "num:i(../../../ExtTrigDigitalFilterLen/EQADC1213_DigitalFilterLength)"!]
            [!VAR "EqAdc_InstanId" = "6"!]
        [!ENDIF!]
        [!VAR "Clk_Prescale" = "0"!]
        [!IF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "2""!]
            [!VAR "Clk_Prescale" = "0"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "4""!]
            [!VAR "Clk_Prescale" = "1"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "6""!]
            [!VAR "Clk_Prescale" = "2"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "8""!]
            [!VAR "Clk_Prescale" = "3"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "10""!]
            [!VAR "Clk_Prescale" = "4"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "12""!]
            [!VAR "Clk_Prescale" = "5"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "14""!]
            [!VAR "Clk_Prescale" = "6"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "16""!]
            [!VAR "Clk_Prescale" = "7"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "18""!]
            [!VAR "Clk_Prescale" = "8"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "20""!]
            [!VAR "Clk_Prescale" = "9"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "22""!]
            [!VAR "Clk_Prescale" = "10"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "24""!]
            [!VAR "Clk_Prescale" = "11"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "26""!]
            [!VAR "Clk_Prescale" = "12"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "28""!]
            [!VAR "Clk_Prescale" = "13"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "30""!]
            [!VAR "Clk_Prescale" = "14"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "32""!]
            [!VAR "Clk_Prescale" = "15"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "34""!]
            [!VAR "Clk_Prescale" = "16"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "36""!]
            [!VAR "Clk_Prescale" = "17"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "38""!]
            [!VAR "Clk_Prescale" = "18"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "40""!]
            [!VAR "Clk_Prescale" = "19"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "42""!]
            [!VAR "Clk_Prescale" = "20"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "44""!]
            [!VAR "Clk_Prescale" = "21"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "46""!]
            [!VAR "Clk_Prescale" = "22"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "48""!]
            [!VAR "Clk_Prescale" = "23"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "50""!]
            [!VAR "Clk_Prescale" = "24"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "52""!]
            [!VAR "Clk_Prescale" = "25"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "54""!]
            [!VAR "Clk_Prescale" = "26"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "56""!]
            [!VAR "Clk_Prescale" = "27"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "58""!]
            [!VAR "Clk_Prescale" = "28"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "60""!]
            [!VAR "Clk_Prescale" = "29"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "62""!]
            [!VAR "Clk_Prescale" = "30"!]
        [!ELSEIF "num:i(substring-after(AdcPrescale,'CLK_SEL_PS_DIV_')) = "64""!]
            [!VAR "Clk_Prescale" = "31"!]
        [!ENDIF!]
    [!LOOP "AdcGroup/*"!]
    [!IF "$GroupCfgIndex = AdcGroupId"!]
	{   /* Group [!"AdcGroupId"!], [!"../../AdcHwUnitId"!], [!IF "AdcGroupTriggSrc = 'ADC_TRIGG_SRC_SW'"!]SoftWareTrig[!ELSE!]HardWareTrig[!ENDIF!][!WS "1"!] */
		.HwUnitId            = [!"substring-after(string(../../AdcHwUnitId),'ADC')"!]U,
        .ExtTrigDigFilter    = [!"num:i($DigFilter)"!]U,
        .Clk_Prescale        = (Eqadc_ClkPrescaleType)[!"num:i($Clk_Prescale)"!]U,
        .ExtMuxEn            = [!WS "1"!][!IF "../../AdcExternalMux = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .IntDma_Sel          = (Eqadc_IntDmaFillSelType)[!IF "GroupSelIntOrDma = 'INTERRUPT'"!]0U[!ELSEIF "GroupSelIntOrDma = 'DMA'"!]1U[!ELSE!]2U[!ENDIF!],
        .DmaMappedChan       = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]0U[!ELSE!][!"node:ref(eDmaChannel)/eDmaChannelId"!][!ENDIF!],
        .DMACompleteClearERQ = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]FALSE[!ELSE!][!IF "DMACompleteClearERQ = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!][!ENDIF!],
        .Callback            = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]NULL_PTR[!ELSE!][!IF "node:ref(eDmaChannel)/eDmaChCallbaceFunction != 'NULL_PTR'"!]&[!"node:ref(eDmaChannel)/eDmaChCallbaceFunction"!][!ELSE!]NULL_PTR[!ENDIF!][!ENDIF!],
        .CallbackParam       = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]NULL_PTR[!ELSE!][!"node:ref(eDmaChannel)/eDmaChCallbaceParam"!][!ENDIF!],
        .StrPtr              = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]NULL_PTR[!ELSE!]HwUnit[!"substring-after(string(../../AdcHwUnitId),'ADC')"!]_Group[!"AdcGroupId"!]_CmdBuf[!ENDIF!],
        .ResultDmaMappedChan = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]0U[!ELSE!][!"node:ref(ResulteDmaChannel)/eDmaChannelId"!][!ENDIF!],
        .ResultIrq           = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]NULL_PTR[!ELSE!]&Eqadc[!"num:i($EqAdc_InstanId)"!]_DmaResult[!"substring-after(string(AdcGroupRFifo),'EQADC_FIFO_')"!][!ENDIF!],
        .ResultCallback      = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]NULL_PTR[!ELSE!][!IF "node:ref(ResulteDmaChannel)/eDmaChCallbaceFunction != 'NULL_PTR'"!]&[!"node:ref(ResulteDmaChannel)/eDmaChCallbaceFunction"!][!ELSE!]NULL_PTR[!ENDIF!][!ENDIF!],
        .ResultCallbackParam = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]NULL_PTR[!ELSE!][!"node:ref(ResulteDmaChannel)/eDmaChCallbaceParam"!][!ENDIF!],
		.DestPtr             = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA'"!]NULL_PTR[!ELSE!]HwUnit[!"substring-after(string(../../AdcHwUnitId),'ADC')"!]_Group[!"AdcGroupId"!]_ResultBuf[!ENDIF!],
        .DmaSampleNum        = [!WS "1"!][!IF "GroupSelIntOrDma != 'DMA' or AdcStreamingNumSamples != '1'"!]1U[!ELSE!][!"DmaSampleNum"!]U[!ENDIF!],
        .SwOrHw              = [!"AdcGroupTriggSrc"!],
		.Prio                = [!"AdcGroupPriority"!]U,
		.ConvMode            = [!"AdcGroupConversionMode"!],
		.StreamBufMode       = [!"AdcStreamingBufferMode"!],
		.AccessMode          = [!"AdcGroupAccessMode"!],
		.HwTriggerSignal     = [!"AdcHwTrigSignal"!],
		.StreamNumSamp       = [!WS "1"!][!IF "GroupSelIntOrDma = 'DMA' and DmaSampleNum != '1'"!]1U[!ELSE!][!"AdcStreamingNumSamples"!]U[!ENDIF!],
		.ChannelCount        = [!"num:i(count(AdcGroupDefinition/*))"!]U,
		.GroupNotif          = [!WS "1"!][!IF "AdcNotification != 'NULL_PTR'"!]&[!"AdcNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
        .GroupNotif_OverFlow = [!WS "1"!][!IF "(Overflow_Notification != 'NULL_PTR') and ((../../../../../AdcGeneral/EnableIntRFOF = 'true') or (../../../../../AdcGeneral/EnableIntTORF = 'true'))"!]&[!"Overflow_Notification"!][!ELSE!]NULL_PTR[!ENDIF!],
        .CFifo               = [!"AdcGroupCFifo"!],
        .HwTrigSrc           = [!WS "1"!][!IF "AdcGroupTriggSrc != 'ADC_TRIGG_SRC_HW'"!]EQADC_HW_TRIG_NOT_CONNECTED[!ELSE!][!"AdcHwTrigSrc"!][!ENDIF!],
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC
        .GtmTrigAdcOutsel    = [!"GtmTrigAdcOutsel"!],
#endif
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
        .TrigDelayEn         = [!WS "1"!][!IF "TrigDelayEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .TrigDelayVal        = [!WS "1"!][!IF "TrigDelayEn != 'true'"!]0U[!ELSE!][!"TrigDelayVal"!]U[!ENDIF!],
#endif
        .Resolution          = [!"../../Resolution"!],
		.Eqadc_ConvCmd       = Eqadc_ConvCfg_[!"AdcGroupId"!],
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        .Eqadc_ChannelLimit  = ChannelLimit_cfg_[!"AdcGroupId"!],
#endif
        .Adc_AlternatSet     = [!WS "1"!][!IF "num:i(count(../../AlternateConfig/*)) != 0"!]&AlternateSet_[!"substring-after(string(../../AdcHwUnitId),'ADC')"!][!ELSE!]NULL_PTR[!ENDIF!][!CR!]
	}[!IF "num:i($GroupCfgIndex) != (num:i($Groupcount)-1)"!],[!ENDIF!][!CR!]
    [!ENDIF!]
    [!ENDLOOP!]
    [!ENDLOOP!]    
    [!ENDFOR!]
};

static CONST(Adc_CoreMapItemType, ADC_CONST) Adc_CoreMap[ADC_CONFIG_GROUPS] =
{
[!FOR "CoreMapIndex" = "0" TO "num:i($Groupcount)-1"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
    [!LOOP "AdcGroup/*"!]
    [!IF "$CoreMapIndex = AdcGroupId"!]
    {
        .GroupId        = [!"AdcGroupId"!]U,
        .GroupCoreId    = [!CALL "GetCoreID"!]U
    }[!IF "num:i($CoreMapIndex) != (num:i($Groupcount)-1)"!],[!ENDIF!][!CR!]
    [!ENDIF!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDFOR!]
};

[!SELECT "AdcConfigSet"!]
CONST(Adc_ConfigType, ADC_CONST) Adc_Config =
{
    .Adc_GroupConfig    = Group_Cfg,
    .Adc_CoreMapItem    = Adc_CoreMap
};
[!ENDSELECT!]

#ifdef __cplusplus
}
#endif
