/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc_Cfg.c
* @version  1.0
* @date     2024 - 03 - 06
* @brief    Initial version.
*
*****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

#include "SDAdc.h"
#ifdef RESOURCE_SUPPORT_SDADC_IP
#define SDADC_CFG_C_VENDOR_ID                       176
#define SDADC_CFG_C_AR_REL_MAJOR_VER                4
#define SDADC_CFG_C_AR_REL_MINOR_VER                4
#define SDADC_CFG_C_AR_REL_REV_VER                  0
#define SDADC_CFG_C_SW_MAJOR_VER                    1
#define SDADC_CFG_C_SW_MINOR_VER                    0
#define SDADC_CFG_C_SW_PATCH_VER                    1

#if (SDADC_CFG_H_VENDOR_ID               != SDADC_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_CFG_C_VENDOR_ID "
#endif
#if (SDADC_CFG_H_AR_REL_MAJOR_VER    != SDADC_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_MINOR_VER    != SDADC_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_C_AR_REL_MINOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_REV_VER != SDADC_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_C_AR_REL_REV_VER "
#endif
#if (SDADC_CFG_H_SW_MAJOR_VER        != SDADC_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_C_SW_MAJOR_VER "
#endif
#if (SDADC_CFG_H_SW_MINOR_VER        != SDADC_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_C_SW_MINOR_VER "
#endif
#if (SDADC_CFG_H_SW_PATCH_VER        != SDADC_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_C_SW_PATCH_VER "
#endif
[!AUTOSPACING!]

[!MACRO "GetCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRef_cnt" = "num:i(count(SdAdcHwunitEcucPartitionRef/*))"!][!//
    [!IF "$EcucPartitionRef_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!//
    [!ELSE!][!//
        [!FOR "GetCoreIdIndex" = "0" TO "num:i($EcucPartitionRef_cnt)-1"!][!//
            [!VAR "ModuEcucPartitionRef" = "string(SdAdcHwunitEcucPartitionRef/*[$GetCoreIdIndex+1])"!][!//
            [!IF "not(node:refexists(SdAdcHwunitEcucPartitionRef/*[$GetCoreIdIndex+1]))"!][!//
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

[!LOOP "SDAdcConfigSet"!][!//
[!LOOP "./SDAdcInstance/*"!][!// 

/* SDADC_CFG_CHANNEL_ID_[!"num:i(@index)"!] */
static CONST(Sdadc_ConfigType, SDADC_VAR) Sdadc_Config_[!"num:i(@index)"!] = 
{
    .ChanSel            = {
        .ChanDefaultId          = [!"num:i(substring-after(./SDAdcChanDefaultId,'CH'))"!]U,
        .DifferenceEn           = [!IF "./SDAdcDifferenceEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!]

    },
    .ExtMeshClkSel      = [!"./SDAdcExtMeshClkSel"!], 
	.DCTestEn           = [!IF "./SDAdcDCTestEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
	.AnalogCfg          = {
			.PreGain = [!"./SDAdcPreGain"!],
			.VcomSel = [!"./SDAdcVcomSel"!],
			.ClkDiv  = [!"./SDAdcClkDiv"!],
	},
	.OsrVal             = [!"./SDAdcOsrVal"!], 
    .FirFilter          = {
        .Fir1DecimationRate     = [!"./SDAdcFir1DecimationRate"!],
        .CicMode                = [!IF "./SDAdcCicMode = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .OvershootCompEn        = [!IF "./SDAdcOvershootCompEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .OffsetCompFilterEn     = [!"./SDAdcOffsetCompFilterEn"!], 
        .CalibrationEn          = [!IF "./SDAdcCalibrationEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!]

    },
    .OvershootComp      = {
        .SlewRateFilterStrength = [!"./SDAdcSlewRateFilterStrength"!],
        .SlewRateFilterRunTime  = [!"./SDAdcSlewRateFilterRunTime"!],
        .StepDetectionMode      =  [!"./SDAdcStepDetectionMode"!],
        .StepDetectionThreshold = [!"./SDAdcStepDetectionThreshold"!]U    /*  <= 0x7FF */
    },
	.Res_P_En           =FALSE,
	.Res_N_En           =FALSE,
    .IntDma             = {
        .FifoWaterMarkerIntEn   = [!IF "./SDAdcFifoWaterMarkerIntEn = 'true' and ./SDadcSelIntOrDma = 'INTERRUPT'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .FifoOverFlowIntEn      = FALSE,
        .DataOverFlowIntEn      = FALSE,
        .DmaReqEn               = [!IF "./SDAdcDmaReqEn = 'true'  and ./SDadcSelIntOrDma = 'DMA'"!]TRUE[!ELSE!]FALSE[!ENDIF!]

    },
	.IntegratorEn       = [!IF "./SDAdcIntegratorEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .Integrator         = {
        .IntegratorTrigMode     = [!"./SDAdcIntegratorTrigMode"!], 
        .IntegrationWindowSize  = [!"./SDAdcIntegrationWindowSize"!],
        .NumOfDiscardedVal      = [!"./SDAdcNumOfDiscardedVal"!]U,
        .NumOfAccumulatedVal    = [!"./SDAdcNumOfAccumulatedVal"!]U, 
        .NumOfIntegrationCycles = [!"./SDAdcNumOfIntegrationCycles"!]U,
        .IntegratorShiftCtrl    = [!"./SDAdcIntegratorShiftCtrl"!],  
        .FilterChainRestartCtrl = [!"./SDAdcFilterChainRestartCtrl"!]
    },
    .FilterChainDiscard = {
        .FilterChainDiscardEn   = [!IF "./SDAdcFilterChainDiscardEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .FilterChainDiscardNum  = [!"./SDAdcFilterChainDiscardNum"!]U 
    },
    .ChanWrap           = {
        .ChanWraparoundEn       = [!IF "./SDAdcChanWraparoundEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .ChanWraparoundNum      = [!"./SDAdcChanWraparoundNum"!]U 
    },
    .Comparator         = {
        .BoundaryComparatorEn   = [!IF "./SDAdcBoundaryComparatorEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .LowerBoundary          = [!"./SDAdcLowerBoundary"!]U, 
        .UpperBoundary          = [!"./SDAdcUpperBoundary"!]U 
    },
    .FifoCfg            = {
        .FifoSize               = 64U,    /* Max(default) is 0x40 */
        .FifoWaterMarker        = [!"./SDAdcFifoWaterMarker"!]U, 
        .InfoEn                 = [!IF "./SDAdcInfoEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .SignEn                 = [!IF "./SDAdcSignEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!]

    },
    .HwTrigSel          = {
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC0' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW0"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc0  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC1' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW1"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc1  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC2' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW2"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc2  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC3' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW3"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc3  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC4' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW4"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc4  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC5' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW5"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc5  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC6' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW6"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc6  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC7' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW7"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc7  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC8' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW8"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc8  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC9' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW9"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc9  */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC10' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW10"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc10 */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC11' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW11"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc11 */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC12' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW12"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc12 */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'SDADC' and ./SelectHwTrigSDADCSrc = 'SDADC13' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW13"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc13 */
        [!WS "8"!][!IF "./SelectHwTrigModule = 'GTM' and ./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!"./SDAdcHwTrigConfig/HTCFG_HW14"!][!ELSE!]SDADC_HW_TRIG_DISABLE[!ENDIF!],  /* HwTrigSrc14 */
    },
    [!IF "./SDadcSelIntOrDma = 'DMA'"!]
    .DmaCfg             = {
        .DmaCh          = [!"node:ref(SDAdcDmaCh)/eDmaChannelId"!],
        .DmaConfigPtr   =
		{
			.minorLpMap = 0U,
			.srcAddr = 0U,
			.destAddr = 0U,
			.srcTransDataSize = EDMA_TRANSFER_SIZE_4B,
			.destTransDataSize = EDMA_TRANSFER_SIZE_4B,
			.srcAddrOffset = (sint16)0U,
			.destAddrOffset = (sint16)0U,
			.srcAddrAdjustLast = (sint16)0U,
			.destAddrAdjustLast = (sint16)0U,
			.srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
			.destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
			.minorTransByte = 0U,
			.featureScatterGatherEn = FALSE,
			.featureScatterGatherNextDescriptor = 0U,
			.completeIntEn = FALSE,
		},
		.DreqEn         = [!IF "SDadcDmaCompleteClearERQ = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
		.Callback       = [!IF "node:ref(SDAdcDmaCh)/eDmaChCallbaceFunction != 'NULL_PTR'"!]&[!"node:ref(SDAdcDmaCh)/eDmaChCallbaceFunction"!][!ELSE!]NULL_PTR[!ENDIF!],
        .CallbackParam  = [!"node:ref(SDAdcDmaCh)/eDmaChCallbaceParam"!]
    }
    [!ENDIF!]
};
[!ENDLOOP!][!//

static CONST(SdAdc_InstanceConfigType, SDADC_VAR) SdAdc_InstanceConfig[[!"(num:i(count(./SDAdcInstance/*)))"!]] =
{ 
[!LOOP "./SDAdcInstance/*"!][!//
    /* SDADC_CFG_CHANNEL_ID_[!"num:i(@index)"!] */
	{
		.Sdadc_InstanceId = [!"./InstanceId"!], 
		.Sdadc_Config = &Sdadc_Config_[!"num:i(@index)"!],
		.Sdadc_BufferMode = [!"./SDAdcBufferMode"!],
        .Sdadc_ConvMethod = SDADC_USE_[!"./SDadcSelIntOrDma"!],
		.Sdadc_NewResultNotify = [!IF "./SDAdcNewResultNotify != 'NULL_PTR' and ./SDadcSelIntOrDma = 'INTERRUPT'"!]&[!"./SDAdcNewResultNotify"!][!ELSE!]NULL_PTR[!ENDIF!],
		.Sdadc_BufferFullNotifyPtr = [!IF "./SDAdcBufferFullNotify != 'NULL_PTR' and ./SDadcSelIntOrDma = 'INTERRUPT' and ./SDAdcBufferMode = 'SDADC_STREAM_LINEAR_BUFFER'"!]&[!"./SDAdcBufferFullNotify"!][!ELSE!]NULL_PTR[!ENDIF!], 
		.Sdadc_SwOrHw = [!"./SDAdcTrigMode"!],
        .Sdadc_HwTrigSrc = [!IF "./SDAdcTrigMode = 'HARDWARE_TRIG'"!][!IF "./SelectHwTrigModule = 'GTM'"!]HWTRIGSEL_[!"./SelectHwTrigGTMSrc"!][!ELSEIF "./SelectHwTrigModule = 'SDADC'"!]HWTRIGSEL_[!"./SelectHwTrigSDADCSrc"!][!ELSE!]NO_HWTRIG[!ENDIF!][!ELSE!]NO_HWTRIG[!ENDIF!],
	},
[!ENDLOOP!][!//
};
[!ENDLOOP!][!//

static CONST(SdAdc_CoreMapItemType, SDADC_CONST) SdAdc_CoreMap[SDADC_INSTANCE_CDG_NUM]=
{
[!FOR "CoreMapIndex" = "0" TO "num:i(num:i(count(SDAdcConfigSet/SDAdcInstance/*))-1)"!]
[!LOOP "SDAdcConfigSet/SDAdcInstance/*"!]
    [!IF "$CoreMapIndex = num:i(@index)"!]
    {
        .SdAdc_ChannelIndex = [!"num:i(@index)"!]U,
        .SdAdc_CoreId = [!CALL "GetCoreID"!]U
    },
    [!ENDIF!]
[!ENDLOOP!]
[!ENDFOR!]
};

CONST(SdAdc_TotalConfigType, SDADC_CONST) SdAdc_TotalConfig = 
{
    .SdAdc_InstanceConfig = SdAdc_InstanceConfig,
    .SdAdc_CoreMapItem = SdAdc_CoreMap
};

#endif /*#ifdef RESOURCE_SUPPORT_SDADC_IP*/

#ifdef __cplusplus
}
#endif



