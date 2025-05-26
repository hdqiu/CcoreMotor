/****************************************************************************
*
* Copyright (c) 2022  C*Core -   All Rights Reserved
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
*   @file    Gpt_cfg.c
*   @implements     Gpt_cfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt -  GPT driver configuration source file.
*   @details GPT driver source file, containing C and XPath constructs for generating Gpt
*            configuration source file for the Post-build configuration variant.
*
*   @addtogroup GPT_MODULE
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

#include "Gpt_Cfg.h"
#include "Gpt.h"
#include "Gpt_Rtc_LLDriver.h"

/*================================SOURCE FILE VERSION INFORMATION===================================*/
#define GPT_VENDOR_ID_OUTPUT                    176
#define GPT_CFG_AR_MAJOR_VER                    4
#define GPT_CFG_AR_MINOR_VER                    4
#define GPT_CFG_AR_PATCH_VER                    0 
#define GPT_CFG_SW_MAJOR_VER                    1
#define GPT_CFG_SW_MINOR_VER                    0
#define GPT_CFG_SW_PATCH_VER                    1
/*==================================FILE VERSION CHECKS=============================================*/
#if (MCAL_VENDOR_ID != GPT_VENDOR_ID_OUTPUT)
    #error " NON-MATCHED DATA : GPT_VENDOR_ID_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != GPT_CFG_AR_MAJOR_VER)
    #error " NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != GPT_CFG_AR_MINOR_VER)
    #error " NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != GPT_CFG_AR_PATCH_VER)
    #error " NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != GPT_CFG_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != GPT_CFG_SW_MINOR_VER)
    #error " NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != GPT_CFG_SW_PATCH_VER)
    #error " NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER "
#endif

/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/
extern void Gpt_Pit_Cbk_Notification(void);
extern void Gpt_Stm_Cbk_Notification(void);
extern void Gpt_Gtm_Con_Cbk_Notification(void);
extern void Gpt_Stm_OneShot_Cbk_Notification(void);
extern void Gpt_Gtm_OneShot_Cbk_Notification(void);
extern void Gpt_Pit_OneShot_Cbk_Notification(void);
extern void Gpt_RTI_OneShot_Cbk_Notification(void);
extern void Gpt_Gtm_FXCLK0_Cbk_Notification(void);
extern void Gpt_Gtm_FXCLK1_Cbk_Notification(void);
extern void Gpt_Gtm_FXCLK2_Cbk_Notification(void);
extern void Gpt_Gtm_FXCLK3_Cbk_Notification(void);
extern void Gpt_Gtm_FXCLK4_Cbk_Notification(void);
extern void Gpt_Pit0Ch6_Cbk_Notification(void);
extern void Gpt_Rtc_Cbk_Notification(void);

/*======================================LOCAL MACROS================================================*/

/*=====================================LOCAL CONSTANTS==============================================*/

/*=====================================LOCAL VARIABLES==============================================*/

/*=====================================GLOBAL CONSTANTS=============================================*/




#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
static CONST(Gpt_HwPredefChannelConfig, GPT_CONST) Gpt_pInitPredefTimer_1us_16bit=
{
    (uint8)(STM_0_CH_0), /* GPT physical channel no. */
    (Gpt_Module)(GPT_MODULE_STM), /* hardware module ID */
    (boolean)(FALSE), /* Freeze Disable */
    (uint8)(49U), /* STM Clock divider */
};
static CONST(Gpt_HwPredefChannelConfig, GPT_CONST) Gpt_pInitPredefTimer_1us_24bit=
{
    (uint8)(STM_0_CH_1), /* GPT physical channel no. */
    (Gpt_Module)(GPT_MODULE_STM), /* hardware module ID */
    (boolean)(FALSE), /* Freeze Disable */
    (uint8)(49U), /* STM Clock divider */
};
static CONST(Gpt_HwPredefChannelConfig, GPT_CONST) Gpt_pInitPredefTimer_1us_32bit=
{
    (uint8)(STM_0_CH_2), /* GPT physical channel no. */
    (Gpt_Module)(GPT_MODULE_STM), /* hardware module ID */
    (boolean)(FALSE), /* Freeze Disable */
    (uint8)(49U), /* STM Clock divider */
};

static CONSTP2CONST(Gpt_HwPredefChannelConfig, GPT_CONST, GPT_APPL_CONST) Gpt_pInitPredefTimerChannel[GPT_HW_PREDEFTIMER_NUM]=
{
    &Gpt_pInitPredefTimer_1us_16bit,
    &Gpt_pInitPredefTimer_1us_24bit,
    &Gpt_pInitPredefTimer_1us_32bit,
    NULL_PTR
};
#endif


static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_0 =
{
    .u8HwChannel = (uint8)(PIT_1_CH_0), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_PIT), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)0U, /* Not used for PIT */
#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for PIT */
#endif
    .u8StmPrescaler = (uint8)(0U), /* Not used for PIT */
    .u32ClkFreq = 100000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_1 =
{
    .u8HwChannel = (uint8)(STM_1_CH_1), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_STM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)0, /* Not used for STM */

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for STM */
#endif

    .u8StmPrescaler = (uint8)(49U), /* STM Clock divider */
    .u32ClkFreq = 50000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_2 =
{
    .u8HwChannel = (uint8)(GTM_5_CH_15), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK2 | (uint32) GTM_CH_MODE_CONTINUOUS, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_3 =
{
    .u8HwChannel = (uint8)(STM_2_CH_2), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_STM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)0, /* Not used for STM */

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for STM */
#endif

    .u8StmPrescaler = (uint8)(49U), /* STM Clock divider */
    .u32ClkFreq = 50000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_4 =
{
    .u8HwChannel = (uint8)(GTM_0_CH_4), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK1 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_5 =
{
    .u8HwChannel = (uint8)(PIT_0_CH_0), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_PIT), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)0U, /* Not used for PIT */
#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for PIT */
#endif
    .u8StmPrescaler = (uint8)(0U), /* Not used for PIT */
    .u32ClkFreq = 100000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_6 =
{
    .u8HwChannel = (uint8)(PIT_0_CH_RTI), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_PIT), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)0U, /* Not used for PIT */
#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for PIT */
#endif
    .u8StmPrescaler = (uint8)(0U), /* Not used for PIT */
    .u32ClkFreq = 40000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_7 =
{
    .u8HwChannel = (uint8)(GTM_0_CH_7), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK0 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_8 =
{
    .u8HwChannel = (uint8)(GTM_0_CH_8), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK1 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_9 =
{
    .u8HwChannel = (uint8)(GTM_0_CH_9), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK2 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_10 =
{
    .u8HwChannel = (uint8)(GTM_0_CH_10), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK3 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_11 =
{
    .u8HwChannel = (uint8)(GTM_0_CH_11), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK4 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_12 =
{
    .u8HwChannel = (uint8)(PIT_0_CH_6), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_PIT), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)0U, /* Not used for PIT */
#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for PIT */
#endif
    .u8StmPrescaler = (uint8)(0U), /* Not used for PIT */
    .u32ClkFreq = 100000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_13 =
{
    .u8HwChannel = (uint8)(RTC_0_CH_0), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_RTC), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 16000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV32,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_14 =
{
    .u8HwChannel = (uint8)(STM_4_CH_3), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_STM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)0, /* Not used for STM */

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for STM */
#endif

    .u8StmPrescaler = (uint8)(49U), /* STM Clock divider */
    .u32ClkFreq = 50000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_15 =
{
    .u8HwChannel = (uint8)(STM_5_CH_0), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_STM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)0, /* Not used for STM */

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for STM */
#endif

    .u8StmPrescaler = (uint8)(49U), /* STM Clock divider */
    .u32ClkFreq = 50000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_16 =
{
    .u8HwChannel = (uint8)(STM_3_CH_2), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_STM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)0, /* Not used for STM */

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Not used for STM */
#endif

    .u8StmPrescaler = (uint8)(49U), /* STM Clock divider */
    .u32ClkFreq = 50000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_17 =
{
    .u8HwChannel = (uint8)(GTM_1_CH_0), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK0 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_18 =
{
    .u8HwChannel = (uint8)(GTM_2_CH_15), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK1 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_19 =
{
    .u8HwChannel = (uint8)(GTM_3_CH_2), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK2 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_20 =
{
    .u8HwChannel = (uint8)(GTM_4_CH_15), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK3 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_21 =
{
    .u8HwChannel = (uint8)(GTM_5_CH_0), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK4 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_22 =
{
    .u8HwChannel = (uint8)(GTM_4_CH_10), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK1 | (uint32)GTM_CH_MODE_ONESHOT, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_HwChannelConfig, GPT_CONST) Instance_InitHwChannel_23 =
{
    .u8HwChannel = (uint8)(GTM_3_CH_13), /* GPT physical channel no. */
    .eHwModule = (Gpt_Module)(GPT_MODULE_GTM), /* hardware module ID */
    .bFreezeEnable = (boolean)(FALSE), /* Freeze Enable */
    .u32GtmChannelRegCtrl1 = (uint32)CLK_SOURCE_CMU_FXCLK2 | (uint32) GTM_CH_MODE_CONTINUOUS, /* Gtm_CH_CTRL1 register contain clock source and count mode*/

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    .bGtmSupportEnableOutput = (boolean)FALSE, /* Gtm register contain output pin enabled and output pin mode*/
#endif

    .u8StmPrescaler = (uint8)(0U), /* Not used for RTC */
    .u32ClkFreq = 80000000U,
    .eRtcClk = RTC_FIRC_CLK,
    .eRtcDiv = RTC_DIV512,
};

static CONST(Gpt_ChannelConfig, GPT_CONST) Gpt_InitChannel[24] =
{
        
    
        
    

    /*GptChannelConfiguration_0 configuration data*/
    {   
        .u8Instance = (0U), /* GPT instance */
        .bEnableWakeup = (boolean)TRUE, /* Wakeup capability */
        .pfNotification = (&Gpt_Pit_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_0
    },
    /*GptChannelConfiguration_1 configuration data*/
    {   
        .u8Instance = (1U), /* GPT instance */
        .bEnableWakeup = (boolean)TRUE, /* Wakeup capability */
        .pfNotification = (&Gpt_Stm_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_1
    },
    /*GptChannelConfiguration_2 configuration data*/
    {   
        .u8Instance = (2U), /* GPT instance */
        .bEnableWakeup = (boolean)TRUE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_Con_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_2
    },
    /*GptChannelConfiguration_3 configuration data*/
    {   
        .u8Instance = (3U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Stm_OneShot_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_3
    },
    /*GptChannelConfiguration_4 configuration data*/
    {   
        .u8Instance = (4U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_OneShot_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_4
    },
    /*GptChannelConfiguration_5 configuration data*/
    {   
        .u8Instance = (5U), /* GPT instance */
        .bEnableWakeup = (boolean)TRUE, /* Wakeup capability */
        .pfNotification = (&Gpt_Pit_OneShot_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_5
    },
    /*GptChannelConfiguration_6 configuration data*/
    {   
        .u8Instance = (6U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_RTI_OneShot_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_6
    },
    /*GptChannelConfiguration_7 configuration data*/
    {   
        .u8Instance = (7U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK0_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_7
    },
    /*GptChannelConfiguration_8 configuration data*/
    {   
        .u8Instance = (8U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK1_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_8
    },
    /*GptChannelConfiguration_9 configuration data*/
    {   
        .u8Instance = (9U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK2_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_9
    },
    /*GptChannelConfiguration_10 configuration data*/
    {   
        .u8Instance = (10U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK3_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_10
    },
    /*GptChannelConfiguration_11 configuration data*/
    {   
        .u8Instance = (11U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK4_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_11
    },
    /*GptChannelConfiguration_12 configuration data*/
    {   
        .u8Instance = (12U), /* GPT instance */
        .bEnableWakeup = (boolean)TRUE, /* Wakeup capability */
        .pfNotification = (&Gpt_Pit0Ch6_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_12
    },
    /*GptChannelConfiguration_13 configuration data*/
    {   
        .u8Instance = (13U), /* GPT instance */
        .bEnableWakeup = (boolean)TRUE, /* Wakeup capability */
        .pfNotification = (&Gpt_Rtc_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4095U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_13
    },
    /*GptChannelConfiguration_14 configuration data*/
    {   
        .u8Instance = (14U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Stm_OneShot_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_14
    },
    /*GptChannelConfiguration_15 configuration data*/
    {   
        .u8Instance = (15U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Stm_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_15
    },
    /*GptChannelConfiguration_16 configuration data*/
    {   
        .u8Instance = (16U), /* GPT instance */
        .bEnableWakeup = (boolean)TRUE, /* Wakeup capability */
        .pfNotification = (&Gpt_Stm_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_16
    },
    /*GptChannelConfiguration_17 configuration data*/
    {   
        .u8Instance = (17U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK0_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_17
    },
    /*GptChannelConfiguration_18 configuration data*/
    {   
        .u8Instance = (18U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK1_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_18
    },
    /*GptChannelConfiguration_19 configuration data*/
    {   
        .u8Instance = (19U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK2_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_19
    },
    /*GptChannelConfiguration_20 configuration data*/
    {   
        .u8Instance = (20U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK3_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_20
    },
    /*GptChannelConfiguration_21 configuration data*/
    {   
        .u8Instance = (21U), /* GPT instance */
        .bEnableWakeup = (boolean)FALSE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_FXCLK4_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_21
    },
    /*GptChannelConfiguration_22 configuration data*/
    {   
        .u8Instance = (22U), /* GPT instance */
        .bEnableWakeup = (boolean)TRUE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_OneShot_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_ONESHOT), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_22
    },
    /*GptChannelConfiguration_23 configuration data*/
    {   
        .u8Instance = (23U), /* GPT instance */
        .bEnableWakeup = (boolean)TRUE, /* Wakeup capability */
        .pfNotification = (&Gpt_Gtm_Con_Cbk_Notification), /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        .uWakeupSource = (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        .uChannelTickValueMax = (Gpt_ValueType)(65535U), /* Maximum ticks value*/
        .eChannelMode = (Gpt_ChannelMode)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .pHwChannelConfig = &Instance_InitHwChannel_23
    },
};

#if (GPT_ENABLE_MULTICORE == STD_ON)
static CONST(Gpt_CoreMapItemType, GPT_CONST) Gpt_CoreMap[GPT_HW_CHANNEL_NUM]=
{
    {
        .u8HwChannel = 0,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 1,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 2,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 3,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 4,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 5,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 6,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 7,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 8,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 9,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 10,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 11,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 12,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 13,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 14,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 15,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 16,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 17,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 18,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 19,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 20,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 21,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 22,
        .u8CoreId = 1
    },
    {
        .u8HwChannel = 23,
        .u8CoreId = 1
    },
};
#endif

CONST(Gpt_ConfigType, GPT_CONST) GptChannelConfigSet;
CONST(Gpt_ConfigType, GPT_CONST) GptChannelConfigSet =
{
    (Gpt_ChannelType)24U,
    &Gpt_InitChannel
#if (GPT_ENABLE_MULTICORE == STD_ON)
    ,Gpt_CoreMap
#endif
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    ,Gpt_pInitPredefTimerChannel
#endif
    /*Hardware to logic channel mapping.*/
    ,{
        
        GPT_CHN_NOT_USED,                        /*mapping of STM_0_CH_0*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_0_CH_1*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_0_CH_2*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_0_CH_3*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_1_CH_0*/
        GptConf_GptChannel_GptChannelConfiguration_1,                        /*mapping of STM_1_CH_1*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_1_CH_2*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_1_CH_3*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_2_CH_0*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_2_CH_1*/
        GptConf_GptChannel_GptChannelConfiguration_3,                        /*mapping of STM_2_CH_2*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_2_CH_3*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_3_CH_0*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_3_CH_1*/
        GptConf_GptChannel_GptChannelConfiguration_16,                        /*mapping of STM_3_CH_2*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_3_CH_3*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_4_CH_0*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_4_CH_1*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_4_CH_2*/
        GptConf_GptChannel_GptChannelConfiguration_14,                        /*mapping of STM_4_CH_3*/
        GptConf_GptChannel_GptChannelConfiguration_15,                        /*mapping of STM_5_CH_0*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_5_CH_1*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_5_CH_2*/
        GPT_CHN_NOT_USED,                        /*mapping of STM_5_CH_3*/

        
        GptConf_GptChannel_GptChannelConfiguration_5,                        /*mapping of PIT_0_CH_0*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_0_CH_1*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_0_CH_2*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_0_CH_3*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_0_CH_4*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_0_CH_5*/
        GptConf_GptChannel_GptChannelConfiguration_12,                        /*mapping of PIT_0_CH_6*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_0_CH_7*/
        GptConf_GptChannel_GptChannelConfiguration_6,                        /*mapping of PIT_0_CH_RTI*/
        GptConf_GptChannel_GptChannelConfiguration_0,                        /*mapping of PIT_1_CH_0*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_1_CH_1*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_1_CH_2*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_1_CH_3*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_1_CH_4*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_1_CH_5*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_1_CH_6*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_1_CH_7*/
        GPT_CHN_NOT_USED,                        /*mapping of PIT_1_CH_RTI*/

        
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_0*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_1*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_2*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_3*/    
        GptConf_GptChannel_GptChannelConfiguration_4,                    /*mapping of GTM_0_CH_4*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_5*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_6*/    
        GptConf_GptChannel_GptChannelConfiguration_7,                    /*mapping of GTM_0_CH_7*/    
        GptConf_GptChannel_GptChannelConfiguration_8,                    /*mapping of GTM_0_CH_8*/    
        GptConf_GptChannel_GptChannelConfiguration_9,                    /*mapping of GTM_0_CH_9*/    
        GptConf_GptChannel_GptChannelConfiguration_10,                    /*mapping of GTM_0_CH_10*/    
        GptConf_GptChannel_GptChannelConfiguration_11,                    /*mapping of GTM_0_CH_11*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_12*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_13*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_14*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_0_CH_15*/    
        GptConf_GptChannel_GptChannelConfiguration_17,                    /*mapping of GTM_1_CH_0*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_1*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_2*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_3*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_4*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_5*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_6*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_7*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_8*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_9*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_10*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_11*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_12*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_13*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_14*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_1_CH_15*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_0*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_1*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_2*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_3*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_4*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_5*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_6*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_7*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_8*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_9*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_10*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_11*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_12*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_13*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_2_CH_14*/    
        GptConf_GptChannel_GptChannelConfiguration_18,                    /*mapping of GTM_2_CH_15*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_0*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_1*/    
        GptConf_GptChannel_GptChannelConfiguration_19,                    /*mapping of GTM_3_CH_2*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_3*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_4*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_5*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_6*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_7*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_8*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_9*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_10*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_11*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_12*/    
        GptConf_GptChannel_GptChannelConfiguration_23,                    /*mapping of GTM_3_CH_13*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_14*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_3_CH_15*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_0*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_1*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_2*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_3*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_4*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_5*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_6*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_7*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_8*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_9*/    
        GptConf_GptChannel_GptChannelConfiguration_22,                    /*mapping of GTM_4_CH_10*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_11*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_12*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_13*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_4_CH_14*/    
        GptConf_GptChannel_GptChannelConfiguration_20,                    /*mapping of GTM_4_CH_15*/    
        GptConf_GptChannel_GptChannelConfiguration_21,                    /*mapping of GTM_5_CH_0*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_1*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_2*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_3*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_4*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_5*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_6*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_7*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_8*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_9*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_10*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_11*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_12*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_13*/    
        GPT_CHN_NOT_USED,                    /*mapping of GTM_5_CH_14*/    
        GptConf_GptChannel_GptChannelConfiguration_2,                    /*mapping of GTM_5_CH_15*/    

        
        GptConf_GptChannel_GptChannelConfiguration_13,                        /*mapping of RTC_0_CH_0*/

        
        GPT_CHN_NOT_USED                        /*mapping of API_0_CH_0*/
    }
};

/**************************************** GTM CMU **************************************************/
#if(GPT_ENABLE_GTMCMU == STD_ON)

static CONST(GPT_GTM_CMU_ClkConfigType, GPT_CONST) GtmCmu_clocks_Cfg[8] =
{
    /* for each configured clock */
        {
            /* CMU Clock ID */
            .clockId = (GPT_GTM_CMU_Clock_Type) (GPT_GTM_CMU_CLK0),
            /* CMU Clock control register */
            .clockControlRegister = (uint32) (
                                              ((0UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                             )
        },
        {
            /* CMU Clock ID */
            .clockId = (GPT_GTM_CMU_Clock_Type) (GPT_GTM_CMU_CLK1),
            /* CMU Clock control register */
            .clockControlRegister = (uint32) (
                                              ((2UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                             )
        },
        {
            /* CMU Clock ID */
            .clockId = (GPT_GTM_CMU_Clock_Type) (GPT_GTM_CMU_CLK2),
            /* CMU Clock control register */
            .clockControlRegister = (uint32) (
                                              ((3UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                             )
        },
        {
            /* CMU Clock ID */
            .clockId = (GPT_GTM_CMU_Clock_Type) (GPT_GTM_CMU_CLK3),
            /* CMU Clock control register */
            .clockControlRegister = (uint32) (
                                              ((3UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                             )
        },
        {
            /* CMU Clock ID */
            .clockId = (GPT_GTM_CMU_Clock_Type) (GPT_GTM_CMU_CLK4),
            /* CMU Clock control register */
            .clockControlRegister = (uint32) (
                                              ((3UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                             )
        },
        {
            /* CMU Clock ID */
            .clockId = (GPT_GTM_CMU_Clock_Type) (GPT_GTM_CMU_CLK5),
            /* CMU Clock control register */
            .clockControlRegister = (uint32) (
                                              ((3UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                             )
        },
        {
            /* CMU Clock ID */
            .clockId = (GPT_GTM_CMU_Clock_Type) (GPT_GTM_CMU_CLK6),
            /* CMU Clock control register */
            .clockControlRegister = (uint32) (
                                              ((3UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                               | ((CMU_CLK_6_CTRL_SEL_OFF)<<CMU_CLK_6_CTRL_SEL_OFFSET)
                                             )
        },
        {
            /* CMU Clock ID */
            .clockId = (GPT_GTM_CMU_Clock_Type) (GPT_GTM_CMU_CLK7),
            /* CMU Clock control register */
            .clockControlRegister = (uint32) (
                                              ((3UL) << CMU_CLK_X_CTRL_CLK_CNT_OFFSET)
                                               | ((CMU_CLK_7_CTRL_SEL_OFF)<<CMU_CLK_7_CTRL_SEL_OFFSET)
                                             )
        }

};

CONST(Gpt_GtmCmuConfigType, GPT_CONST) Gpt_Gtm_Cmu_PBCfg;
CONST(Gpt_GtmCmuConfigType, GPT_CONST) Gpt_Gtm_Cmu_PBCfg =
{
      /* CMU configuration */
      {
          /* CMU Global Clock Control Numerator */
          .global_clock_numerator = (uint32) (1UL),
          /* CMU Global Clock Control Denominator */
          .global_clock_denominator = (uint32) (1UL),
          /* CMU clock enable register */
          .cmu_clk_control_register = (uint32)(
                    ( (CMU_CLK_EN_ENABLE_CLOCK)<<CMU_CLK_EN_EN_FXCLK_OFFSET)|
                    ( (CMU_CLK_EN_DISABLE_CLOCK)<<CMU_CLK_EN_EN_ECLK2_OFFSET)|
                    ( (CMU_CLK_EN_DISABLE_CLOCK)<<CMU_CLK_EN_EN_ECLK1_OFFSET)|
                    ( (CMU_CLK_EN_DISABLE_CLOCK)<<CMU_CLK_EN_EN_ECLK0_OFFSET)|
                    ( (CMU_CLK_EN_DISABLE_CLOCK)<<CMU_CLK_EN_EN_CLK7_OFFSET)|
                    ( (CMU_CLK_EN_DISABLE_CLOCK)<<CMU_CLK_EN_EN_CLK6_OFFSET)|
                    ( (CMU_CLK_EN_DISABLE_CLOCK)<<CMU_CLK_EN_EN_CLK5_OFFSET)|
                    ( (CMU_CLK_EN_DISABLE_CLOCK)<<CMU_CLK_EN_EN_CLK4_OFFSET)|
                    ( (CMU_CLK_EN_DISABLE_CLOCK)<<CMU_CLK_EN_EN_CLK3_OFFSET)|
                    ( (CMU_CLK_EN_DISABLE_CLOCK)<<CMU_CLK_EN_EN_CLK2_OFFSET)|
                    ( (CMU_CLK_EN_ENABLE_CLOCK)<<CMU_CLK_EN_EN_CLK1_OFFSET)|
                    ( (CMU_CLK_EN_ENABLE_CLOCK)<<CMU_CLK_EN_EN_CLK0_OFFSET)
                  ),
          /* CMU FXCLK_Sel register */
          .cmu_fxclk_sel_register = (uint32)(CMU_FXCLK_CTRL_CMU_CLK0<<CMU_FXCLK_CTRL_FXCLK_SEL_OFFSET),
          /* number of clocks configured */
          .count_of_configured_clocks = (uint8)(8U),
          &GtmCmu_clocks_Cfg
      },

      /* TBU configuration */
      {
          /* TBU channel enable register */
          .tbu_channel0_enable_reg = (uint8)TBU_CHEN_ENABLE_CHANNEL,
          .tbu_channel1_enable_reg = (uint8)TBU_CHEN_ENABLE_CHANNEL,
          .tbu_channel2_enable_reg = (uint8)TBU_CHEN_ENABLE_CHANNEL,
          /* TBU channel 0 control */
          .tbu_ch0_control_clk_src = (uint8)TBU_CHX_CTRL_CMU_CLK1,
          .tbu_ch0_control_low_res = (uint8)TBU_CH0_CTRL_LOW_RES,
          /* TBU channel 1 control */
          .tbu_ch1_control_clk_src = (uint8)TBU_CHX_CTRL_CMU_CLK1,
          .tbu_ch1_control_ch_mode = (uint8)TBU_CH1_CTRL_FREE_RUNNING_MODE,
          /* TBU channel 2 control */
          .tbu_ch2_control_clk_src = (uint8)TBU_CHX_CTRL_CMU_CLK2,
          .tbu_ch2_control_ch_mode = (uint8)TBU_CH2_CTRL_FREE_RUNNING_MODE
      }
};

#endif

#ifdef __cplusplus
}
#endif

/** @} */
