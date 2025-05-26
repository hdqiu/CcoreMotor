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
*   @file    eDma_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "eDma.h"

#define EDMA_CFG_C_VENDOR_ID                     176
#define EDMA_CFG_C_AR_REL_MAJOR_VER              4
#define EDMA_CFG_C_AR_REL_MINOR_VER              4
#define EDMA_CFG_C_AR_REL_REV_VER                0
#define EDMA_CFG_C_SW_MAJOR_VER                  1
#define EDMA_CFG_C_SW_MINOR_VER                  0
#define EDMA_CFG_C_SW_PATCH_VER                  1

#if (MCAL_VENDOR_ID != EDMA_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != EDMA_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != EDMA_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != EDMA_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != EDMA_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != EDMA_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != EDMA_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_CFG_C_SW_PATCH_VER "
#endif

extern void SDadc_ResultCallback_Ins0(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel);
extern void SDadc_ResultCallback_Ins2(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel);
extern void SDadc_ResultCallback_Ins3(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel);
extern void SDadc_ResultCallback_Ins1(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel);
extern void SDadc_ResultCallback_Ins4(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel);
extern void SDadc_ResultCallback_Ins5(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel);
extern void Eqadc4_Adc8_RsltCallback(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel);
extern void Eqadc4_Adc9_RsltCallback(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel);



VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY1,
    .mappedChnConfig = EDMA_CHN1_NUMBER,
    .reqSource = DMAMUX0_ADC_SD_0_EOC,
    .callback = &SDadc_ResultCallback_Ins0,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_17_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY2,
    .mappedChnConfig = EDMA_CHN17_NUMBER,
    .reqSource = DMAMUX2_ADC_SD_2_EOC,
    .callback = &SDadc_ResultCallback_Ins2,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY3,
    .mappedChnConfig = EDMA_CHN2_NUMBER,
    .reqSource = DMAMUX0_ADC_SD_3_EOC,
    .callback = &SDadc_ResultCallback_Ins3,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_19_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY4,
    .mappedChnConfig = EDMA_CHN19_NUMBER,
    .reqSource = DMAMUX2_ADC_SD_1_EOC,
    .callback = &SDadc_ResultCallback_Ins1,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_52_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY5,
    .mappedChnConfig = EDMA_CHN52_NUMBER,
    .reqSource = DMAMUX5_ADC_SD_4_EOC,
    .callback = &SDadc_ResultCallback_Ins4,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_37_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY6,
    .mappedChnConfig = EDMA_CHN37_NUMBER,
    .reqSource = DMAMUX4_ADC_SD_5_EOC,
    .callback = &SDadc_ResultCallback_Ins5,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_0_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY7,
    .mappedChnConfig = EDMA_CHN22_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_CFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_1_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY8,
    .mappedChnConfig = EDMA_CHN23_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_RFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_2_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY9,
    .mappedChnConfig = EDMA_CHN20_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_CFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_3_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY10,
    .mappedChnConfig = EDMA_CHN21_NUMBER,
    .reqSource = DMAMUX2_EQADC1_ADC23_RFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_4_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY0,
    .mappedChnConfig = EDMA_CHN48_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_CFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_5_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY1,
    .mappedChnConfig = EDMA_CHN49_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_RFIFO0,
    .callback = &Eqadc4_Adc8_RsltCallback,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_6_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY2,
    .mappedChnConfig = EDMA_CHN50_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_CFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_7_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY3,
    .mappedChnConfig = EDMA_CHN51_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_RFIFO1,
    .callback = &Eqadc4_Adc9_RsltCallback,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_8_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY1,
    .mappedChnConfig = EDMA_CHN120_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_CFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_9_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY0,
    .mappedChnConfig = EDMA_CHN121_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_RFIFO0,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_10_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY2,
    .mappedChnConfig = EDMA_CHN122_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_CFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_11_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY3,
    .mappedChnConfig = EDMA_CHN123_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_RFIFO1,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_12_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY6,
    .mappedChnConfig = EDMA_CHN54_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_CFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_13_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY7,
    .mappedChnConfig = EDMA_CHN55_NUMBER,
    .reqSource = DMAMUX5_EQADC4_ADC89_RFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_14_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY4,
    .mappedChnConfig = EDMA_CHN124_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_CFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};
VAR(eDMAChanConfigType, AUTOMATIC) eDmaChannelConfig_eqadc_15_Config =
{
    .chnPrioSet = EDMA_CHN_PRIORITY5,
    .mappedChnConfig = EDMA_CHN125_NUMBER,
    .reqSource = DMAMUX10_EQADC5_ADC1011_RFIFO2,
    .callback = NULL_PTR,
    .callbackParam = NULL_PTR,
    .triggerEn = FALSE,
    .chnErrIntEn = FALSE,
    .preemptionEn = FALSE,
    .preemptAbilityDisable = FALSE,
    .MasterIdReplicationEn = FALSE,
};


static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_1_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_17_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_2_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_19_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_52_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_37_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_0_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_1_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_2_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_3_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_4_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_5_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_6_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_7_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_8_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_9_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_10_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_11_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_12_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_13_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_14_State;
static VAR(eDMAChnStateType, AUTOMATIC) eDmaChannelConfig_eqadc_15_State;

CONST(eDMAModuleConfigType, EDMA_CONST) dmaconfigure_InitConfig[EDMA_INSTANCE_COUNT] = {
    {
        .setChnArbitMode = EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
        .groupArbitration = EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
        .prioGroup0 = EDMA_GRP_PRIORITY0,
        .prioGroup1 = EDMA_GRP_PRIORITY1,
        .prioGroup2 = EDMA_GRP_PRIORITY2,
        .prioGroup3 = EDMA_GRP_PRIORITY3,
        .haltOnError = FALSE
    },
    {
        .setChnArbitMode = EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
        .groupArbitration = EDMA_ARBITRATION_MODE_FIXED_PRIORITY,
        .prioGroup0 = EDMA_GRP_PRIORITY0,
        .prioGroup1 = EDMA_GRP_PRIORITY1,
        .prioGroup2 = EDMA_GRP_PRIORITY2,
        .prioGroup3 = EDMA_GRP_PRIORITY3,
        .haltOnError = FALSE
    },
};

CONST(eDMAChPriorityCfg, EDMA_CONST) dmaChPriorityCfgs[EDMA_TOTAL_CHANNELS] = {
    {
        .channel = EDMA_CHN0_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN1_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN2_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN3_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN4_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN5_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN6_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN7_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN8_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN9_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN10_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN11_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN12_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN13_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN14_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN15_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN16_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN17_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN18_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN19_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN20_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN21_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN22_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN23_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN24_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN25_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN26_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN27_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN28_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN29_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN30_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN31_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN32_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN33_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN34_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN35_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN36_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN37_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN38_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN39_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN40_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN41_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN42_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN43_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN44_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN45_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN46_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN47_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN48_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN49_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN50_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN51_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN52_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN53_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN54_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN55_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN56_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN57_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN58_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN59_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN60_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN61_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN62_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN63_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN64_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN65_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN66_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN67_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN68_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN69_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN70_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN71_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN72_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN73_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN74_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN75_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN76_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN77_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN78_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN79_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN80_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN81_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN82_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN83_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN84_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN85_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN86_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN87_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN88_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN89_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN90_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN91_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN92_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN93_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN94_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN95_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN96_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN97_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN98_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN99_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN100_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN101_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN102_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN103_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN104_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN105_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN106_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN107_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN108_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN109_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN110_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN111_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
    {
        .channel = EDMA_CHN112_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY6
        
    },
    {
        .channel = EDMA_CHN113_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY7
        
    },
    {
        .channel = EDMA_CHN114_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY8
        
    },
    {
        .channel = EDMA_CHN115_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY9
        
    },
    {
        .channel = EDMA_CHN116_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY10
        
    },
    {
        .channel = EDMA_CHN117_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY11
        
    },
    {
        .channel = EDMA_CHN118_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY12
        
    },
    {
        .channel = EDMA_CHN119_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY13
        
    },
    {
        .channel = EDMA_CHN120_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY1
        
    },
    {
        .channel = EDMA_CHN121_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY0
        
    },
    {
        .channel = EDMA_CHN122_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY2
        
    },
    {
        .channel = EDMA_CHN123_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY3
        
    },
    {
        .channel = EDMA_CHN124_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY4
        
    },
    {
        .channel = EDMA_CHN125_NUMBER,
        .isUsed = TRUE,
        .chPriority = EDMA_CHN_PRIORITY5
        
    },
    {
        .channel = EDMA_CHN126_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY14
        
    },
    {
        .channel = EDMA_CHN127_NUMBER,
        .isUsed = FALSE,
        .chPriority = EDMA_CHN_PRIORITY15
        
    },
};

CONST(EDma_ConfigType, EDMA_CONST) EDma_Config =
{
    .pEdma_DeviceConfig = dmaconfigure_InitConfig,
    .pEdma_ChStateArray = {
        &eDmaChannelConfig_1_State,
        &eDmaChannelConfig_17_State,
        &eDmaChannelConfig_2_State,
        &eDmaChannelConfig_19_State,
        &eDmaChannelConfig_52_State,
        &eDmaChannelConfig_37_State,
        &eDmaChannelConfig_eqadc_0_State,
        &eDmaChannelConfig_eqadc_1_State,
        &eDmaChannelConfig_eqadc_2_State,
        &eDmaChannelConfig_eqadc_3_State,
        &eDmaChannelConfig_eqadc_4_State,
        &eDmaChannelConfig_eqadc_5_State,
        &eDmaChannelConfig_eqadc_6_State,
        &eDmaChannelConfig_eqadc_7_State,
        &eDmaChannelConfig_eqadc_8_State,
        &eDmaChannelConfig_eqadc_9_State,
        &eDmaChannelConfig_eqadc_10_State,
        &eDmaChannelConfig_eqadc_11_State,
        &eDmaChannelConfig_eqadc_12_State,
        &eDmaChannelConfig_eqadc_13_State,
        &eDmaChannelConfig_eqadc_14_State,
        &eDmaChannelConfig_eqadc_15_State,
    },
    .pEdma_ChanelConfig = {
        &eDmaChannelConfig_1_Config,
        &eDmaChannelConfig_17_Config,
        &eDmaChannelConfig_2_Config,
        &eDmaChannelConfig_19_Config,
        &eDmaChannelConfig_52_Config,
        &eDmaChannelConfig_37_Config,
        &eDmaChannelConfig_eqadc_0_Config,
        &eDmaChannelConfig_eqadc_1_Config,
        &eDmaChannelConfig_eqadc_2_Config,
        &eDmaChannelConfig_eqadc_3_Config,
        &eDmaChannelConfig_eqadc_4_Config,
        &eDmaChannelConfig_eqadc_5_Config,
        &eDmaChannelConfig_eqadc_6_Config,
        &eDmaChannelConfig_eqadc_7_Config,
        &eDmaChannelConfig_eqadc_8_Config,
        &eDmaChannelConfig_eqadc_9_Config,
        &eDmaChannelConfig_eqadc_10_Config,
        &eDmaChannelConfig_eqadc_11_Config,
        &eDmaChannelConfig_eqadc_12_Config,
        &eDmaChannelConfig_eqadc_13_Config,
        &eDmaChannelConfig_eqadc_14_Config,
        &eDmaChannelConfig_eqadc_15_Config,
    },
    .u32Edma_ChanelCnt = 22U,
    .pEdma_ChPriorityCfgs = dmaChPriorityCfgs
};

#ifdef __cplusplus
}
#endif
