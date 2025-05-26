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
*   @file    Adc_LLDriver.c
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

#define ADC_LLD_C_VENDOR_ID                     176
#define ADC_LLD_C_AR_REL_MAJOR_VER          	4
#define ADC_LLD_C_AR_REL_MINOR_VER          	4
#define ADC_LLD_C_AR_REL_REV_VER            	0
#define ADC_LLD_C_SW_MAJOR_VER              	1
#define ADC_LLD_C_SW_MINOR_VER              	0
#define ADC_LLD_C_SW_PATCH_VER              	1

#include "Adc.h"
#include "Adc_LLDriver.h"
#include "SchM_Adc.h"
#include "eDma.h"
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
#include "Dem.h"
#endif

#if (ADC_VENDOR_ID               != ADC_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ADC_LLD_C_VENDOR_ID "
#endif
#if (ADC_AR_REL_MAJOR_VER    != ADC_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (ADC_AR_REL_MINOR_VER    != ADC_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_AR_REL_MINOR_VER "
#endif
#if (ADC_AR_REL_REV_VER != ADC_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_AR_REL_REV_VER "
#endif
#if (ADC_SW_MAJOR_VER        != ADC_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_SW_MAJOR_VER "
#endif
#if (ADC_SW_MINOR_VER        != ADC_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_SW_MINOR_VER "
#endif
#if (ADC_SW_PATCH_VER        != ADC_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ADC_LLD_C_SW_PATCH_VER "
#endif

/*******************************************************************************
 * EQADC module *    OnChip ADC
 *  EQADCx      *       ADC0
 *              *       ADC1
 *******************************************************************************
 *******************************************************************************
 *  EQADC0      *   ADC0(RM hardware resources: AdcUnit0)
 *              *   ADC1(RM hardware resources: AdcUnit1)
 *******************************************************************************
 *  EQADC1      *   ADC0(RM hardware resources: AdcUnit2)
 *              *   ADC1(RM hardware resources: AdcUnit3)
 *******************************************************************************
 *  EQADC2      *   ADC0(RM hardware resources: AdcUnit4)
 *              *   ADC1(RM hardware resources: AdcUnit5)
 *******************************************************************************
 *  EQADC3      *   ADC0(RM hardware resources: AdcUnit6)
 *              *   ADC1(RM hardware resources: AdcUnit7)
 *******************************************************************************
 *  EQADC4      *   ADC0(RM hardware resources: AdcUnit8)
 *              *   ADC1(RM hardware resources: AdcUnit9)
 *******************************************************************************
 *  EQADC5      *   ADC0(RM hardware resources: AdcUnit10)
 *              *   ADC1(RM hardware resources: AdcUnit11)
 *******************************************************************************
 *  EQADC6      *   ADC0(RM hardware resources: AdcUnit12)
 *              *
 *******************************************************************************/

/*******************************************************************************
 * EQADC CFIFO for configuring commands
 *******************************************************************************/
#define EQADC_CFG_CMD_CFIFO_IDX             (EQADC_FIFO_0)

/************************************************************************************************
 *                                  EQADC ADC command format
 ************************************************************************************************
 * Conversion Command Format for the Standard Configuration:
 * 0     1     2     3     4     5     6     7  |  8     9     10    11    12    13    14    15
 * EOQ   PAUSE REP  (RESEDRVE)   EB(0) BN    CAL  (MESSAGE_TAG         )  (LST     )   TSR   FMT
 * 16    17    18    19    20    21    22    23 |  24    25    26    27    28    29    30    31
 * (CHANNEL_NUMBER                             )  (must be 0b00000000                          )
 ************************************************************************************************
 * Conversion Command Format for Alternate Configurations(1 - 8):
 * 0     1     2     3     4     5     6     7  |  8     9     10    11    12    13    14    15
 * EOQ   PAUSE REP  (RESEDRVE)   EB(0) BN    CAL  (MESSAGE_TAG         )  (LST     )   TSR   FFMT
 * 16    17    18    19    20    21    22    23 |  24    25    26    27    28    29    30    31
 * (CHANNEL_NUMBER                             )  (ALT_CONFIG_SEL                              )
 ************************************************************************************************
 * Write Configuration Command Format for On-Chip ADC Operation:
 * 0     1     2     3     4     5     6     7  |  8     9     10    11    12    13    14    15
 * EOQ   PAUSE REP  (RESEDRVE)   EB(0) BN  RW(0)  (ADC_REGISTER HIGH BYTE                      )
 * 16    17    18    19    20    21    22    23 |  24    25    26    27    28    29    30    31
 * (ADC_REGISTER LOW BYTE                      )  (ADC_REG_ADDRESS                             )
 ************************************************************************************************
 * Read Configuration Command Format for On-Chip ADC Operation:
 * 0     1     2     3     4     5     6     7  |  8     9     10    11    12    13    14    15
 * EOQ   PAUSE REP  (RESEDRVE)   EB(0) BN  RW(1)  (MESSAGE_TAG         )  (RESEDRVE            )
 * 16    17    18    19    20    21    22    23 |  24    25    26    27    28    29    30    31
 * (RESEDRVE                                   )  (ADC_REG_ADDRESS                             )
 ************************************************************************************************/

/* Command format: CFIFO Header */
/** EOQ Bit Fields **/
#define EQADC_ADC_CMD_EOQ_MASK              (0x80000000U)
#define EQADC_ADC_CMD_EOQ_SHIFT             (31U)
#define EQADC_ADC_CMD_EOQ(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_EOQ_SHIFT))&EQADC_ADC_CMD_EOQ_MASK)
/** PAUSE Bit Fields **/
#define EQADC_ADC_CMD_PAUSE_MASK            (0x40000000U)
#define EQADC_ADC_CMD_PAUSE_SHIFT           (30U)
#define EQADC_ADC_CMD_PAUSE(x)              (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_PAUSE_SHIFT))&EQADC_ADC_CMD_PAUSE_MASK)
/** REP Bit Fields **/
#define EQADC_ADC_CMD_REP_MASK              (0x20000000U)
#define EQADC_ADC_CMD_REP_SHIFT             (29U)
#define EQADC_ADC_CMD_REP(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_REP_SHIFT))&EQADC_ADC_CMD_REP_MASK)
/* Command format: ADC Command */
/** BN Bit Fields **/
#define EQADC_ADC_CMD_BN_MASK               (0x02000000U)
#define EQADC_ADC_CMD_BN_SHIFT              (25U)
#define EQADC_ADC_CMD_BN(x)                 (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_BN_SHIFT))&EQADC_ADC_CMD_BN_MASK)
/** CAL Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_CAL_MASK              (0x01000000U)
#define EQADC_ADC_CMD_CAL_SHIFT             (24U)
#define EQADC_ADC_CMD_CAL(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_CAL_SHIFT))&EQADC_ADC_CMD_CAL_MASK)
/** MESSAGE_TAG Bit Fields **/
#define EQADC_ADC_CMD_MESSAGE_TAG_MASK      (0x00F00000U)
#define EQADC_ADC_CMD_MESSAGE_TAG_SHIFT     (20U)
#define EQADC_ADC_CMD_MESSAGE_TAG(x)        (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_MESSAGE_TAG_SHIFT))&EQADC_ADC_CMD_MESSAGE_TAG_MASK)
/** LST Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_LST_MASK              (0x000C0000U)
#define EQADC_ADC_CMD_LST_SHIFT             (18U)
#define EQADC_ADC_CMD_LST(x)                (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_LST_SHIFT))&EQADC_ADC_CMD_LST_MASK)
/** TSR Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_TSR_MASK              (0x00020000U)
#define EQADC_ADC_CMD_TSR_SHIFT             (17U)
#define EQADC_ADC_CMD_TSR(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_TSR_SHIFT))&EQADC_ADC_CMD_TSR_MASK)
/** FMT Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_FMT_MASK              (0x00010000U)
#define EQADC_ADC_CMD_FMT_SHIFT             (16U)
#define EQADC_ADC_CMD_FMT(x)                (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_FMT_SHIFT))&EQADC_ADC_CMD_FMT_MASK)
/** FFMT Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_FFMT_MASK             (0x00010000U)
#define EQADC_ADC_CMD_FFMT_SHIFT            (16U)
#define EQADC_ADC_CMD_FFMT(x)               (((uint32)(((uint32)(((x) == TRUE) ? 1U : 0U)) << EQADC_ADC_CMD_FFMT_SHIFT))&EQADC_ADC_CMD_FFMT_MASK)
/** CHAN_NUM Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_CHAN_NUM_MASK         (0x0000FF00U)
#define EQADC_ADC_CMD_CHAN_NUM_SHIFT        (8U)
#define EQADC_ADC_CMD_CHAN_NUM(x)           (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_CHAN_NUM_SHIFT))&EQADC_ADC_CMD_CHAN_NUM_MASK)
/** ALT_CFG_SEL Bit Fields (Conversion command format) **/
#define EQADC_ADC_CMD_ALT_CFG_SEL_MASK      (0x000000FFU)
#define EQADC_ADC_CMD_ALT_CFG_SEL_SHIFT     (0U)
#define EQADC_ADC_CMD_ALT_CFG_SEL(x)        (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_ALT_CFG_SEL_SHIFT))&EQADC_ADC_CMD_ALT_CFG_SEL_MASK)
/** RW Bit Fields (RW Configuration command format) **/
#define EQADC_ADC_CMD_RW_MASK               (0x01000000U)
#define EQADC_ADC_CMD_RW_SHIFT              (24U)
#define EQADC_ADC_CMD_RW(x)                 (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_RW_SHIFT))&EQADC_ADC_CMD_RW_MASK)
/**[REG_HIGH_BYTE + REG_LOW_BYTE] Bit Fields (RW Configuration command format) **/
#define EQADC_ADC_CMD_REG_HL_BYTE_MASK      (0x00FFFF00U)
#define EQADC_ADC_CMD_REG_HL_BYTE_SHIFT     (8U)
#define EQADC_ADC_CMD_REG_HL_BYTE(x)        (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_REG_HL_BYTE_SHIFT))&EQADC_ADC_CMD_REG_HL_BYTE_MASK)
/** REG_ADDR Bit Fields (RW Configuration command format) **/
#define EQADC_ADC_CMD_REG_ADDR_MASK         (0x000000FFU)
#define EQADC_ADC_CMD_REG_ADDR_SHIFT        (0U)
#define EQADC_ADC_CMD_REG_ADDR(x)           (((uint32)(((uint32)(x)) << EQADC_ADC_CMD_REG_ADDR_SHIFT))&EQADC_ADC_CMD_REG_ADDR_MASK)

#define EQADC_DMA_MAPPED_CHAN_INVALID       (0xFFU)
#define SIUL2_REG8_RESET_VALUE_U8           (0x0U)

/* EQADC Module Configuration Register (EQADC_MCR) */
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_MCR[ADC_EQADC_MAX_INSTANCE] =
{
    (volatile uint32 *)&(EQADC0_PTR->MCR.R),
	(volatile uint32 *)&(EQADC1_PTR->MCR.R),
	(volatile uint32 *)&(EQADC2_PTR->MCR.R),
	(volatile uint32 *)&(EQADC3_PTR->MCR.R),
	(volatile uint32 *)&(EQADC4_PTR->MCR.R),
	(volatile uint32 *)&(EQADC5_PTR->MCR.R),
	(volatile uint32 *)&(EQADC6_PTR->MCR.R)
};

/* EQADC External Trigger Digital Filter Register (EQADC_ETDFR) */
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_ETDFR[ADC_EQADC_MAX_INSTANCE] =
{
	(volatile uint32 *)&(EQADC0_PTR->ETDFR.R),
	(volatile uint32 *)&(EQADC1_PTR->ETDFR.R),
	(volatile uint32 *)&(EQADC2_PTR->ETDFR.R),
	(volatile uint32 *)&(EQADC3_PTR->ETDFR.R),
	(volatile uint32 *)&(EQADC4_PTR->ETDFR.R),
	(volatile uint32 *)&(EQADC5_PTR->ETDFR.R),
	(volatile uint32 *)&(EQADC6_PTR->ETDFR.R)
};

/* EQADC Command FIFO Push Registers (EQADC_CFPR) */
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFPR[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC0_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC1_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC2_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC3_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC4_PTR->CFPR[5U].R)},
	{(volatile uint32 *)&(EQADC5_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC5_PTR->CFPR[5U].R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFPR[0U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[1U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[2U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[3U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[4U].R), (volatile uint32 *)&(EQADC6_PTR->CFPR[5U].R)}
};

/* EQADC Result FIFO Pop Registers (EQADC_RFPR) */
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_RFPR[ADC_EQADC_MAX_INSTANCE][EQADC_RFIFO_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[2U].R), \
    (volatile uint32 *)&(EQADC0_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC0_PTR->RFPR[5U].R)}, \
    {(volatile uint32 *)&(EQADC1_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[2U].R), \
    (volatile uint32 *)&(EQADC1_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC1_PTR->RFPR[5U].R)}, \
    {(volatile uint32 *)&(EQADC2_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[2U].R), \
	(volatile uint32 *)&(EQADC2_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC2_PTR->RFPR[5U].R)}, \
    {(volatile uint32 *)&(EQADC3_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[2U].R), \
	(volatile uint32 *)&(EQADC3_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC3_PTR->RFPR[5U].R)}, \
    {(volatile uint32 *)&(EQADC4_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[2U].R), \
	(volatile uint32 *)&(EQADC4_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC4_PTR->RFPR[5U].R)}, \
    {(volatile uint32 *)&(EQADC5_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[2U].R), \
	(volatile uint32 *)&(EQADC5_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC5_PTR->RFPR[5U].R)}, \
    {(volatile uint32 *)&(EQADC6_PTR->RFPR[0U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[1U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[2U].R), \
	(volatile uint32 *)&(EQADC6_PTR->RFPR[3U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[4U].R), (volatile uint32 *)&(EQADC6_PTR->RFPR[5U].R)}
};

/* EQADC CFIFO Control Registers (EQADC_CFCR) */
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFCR[ADC_EQADC_MAX_INSTANCE][3U] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFCR0.R), (volatile uint32 *)&(EQADC0_PTR->CFCR1.R), (volatile uint32 *)&(EQADC0_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFCR0.R), (volatile uint32 *)&(EQADC1_PTR->CFCR1.R), (volatile uint32 *)&(EQADC1_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFCR0.R), (volatile uint32 *)&(EQADC2_PTR->CFCR1.R), (volatile uint32 *)&(EQADC2_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFCR0.R), (volatile uint32 *)&(EQADC3_PTR->CFCR1.R), (volatile uint32 *)&(EQADC3_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFCR0.R), (volatile uint32 *)&(EQADC4_PTR->CFCR1.R), (volatile uint32 *)&(EQADC4_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC5_PTR->CFCR0.R), (volatile uint32 *)&(EQADC5_PTR->CFCR1.R), (volatile uint32 *)&(EQADC5_PTR->CFCR2.R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFCR0.R), (volatile uint32 *)&(EQADC6_PTR->CFCR1.R), (volatile uint32 *)&(EQADC6_PTR->CFCR2.R)}
};

/* EQADC Interrupt and DMA Control Registers (EQADC_IDCR) */
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_IDCR[ADC_EQADC_MAX_INSTANCE][3U] =
{
    {(volatile uint32 *)&(EQADC0_PTR->IDCR0.R), (volatile uint32 *)&(EQADC0_PTR->IDCR1.R), (volatile uint32 *)&(EQADC0_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC1_PTR->IDCR0.R), (volatile uint32 *)&(EQADC1_PTR->IDCR1.R), (volatile uint32 *)&(EQADC1_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC2_PTR->IDCR0.R), (volatile uint32 *)&(EQADC2_PTR->IDCR1.R), (volatile uint32 *)&(EQADC2_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC3_PTR->IDCR0.R), (volatile uint32 *)&(EQADC3_PTR->IDCR1.R), (volatile uint32 *)&(EQADC3_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC4_PTR->IDCR0.R), (volatile uint32 *)&(EQADC4_PTR->IDCR1.R), (volatile uint32 *)&(EQADC4_PTR->IDCR2.R)},
	{(volatile uint32 *)&(EQADC5_PTR->IDCR0.R), (volatile uint32 *)&(EQADC5_PTR->IDCR1.R), (volatile uint32 *)&(EQADC5_PTR->IDCR2.R)},
    {(volatile uint32 *)&(EQADC6_PTR->IDCR0.R), (volatile uint32 *)&(EQADC6_PTR->IDCR1.R), (volatile uint32 *)&(EQADC6_PTR->IDCR2.R)}
};

/* EQADC CFIFO Transfer Counter Registers (EQADC_CFTCR) */
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFTCR[ADC_EQADC_MAX_INSTANCE][3U] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC0_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC0_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC1_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC1_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC2_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC2_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC3_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC3_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC4_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC4_PTR->CFTCR2.R)},
	{(volatile uint32 *)&(EQADC5_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC5_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC5_PTR->CFTCR2.R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFTCR0.R), (volatile uint32 *)&(EQADC6_PTR->CFTCR1.R), (volatile uint32 *)&(EQADC6_PTR->CFTCR2.R)}
};

/* EQADC CFIFO Status Snapshot Registers (EQADC_CFSSR) */
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFSSR[ADC_EQADC_MAX_INSTANCE][2U] =
{
    {(volatile uint32 *)&(EQADC0_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC0_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC1_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC1_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC2_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC2_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC3_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC3_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC4_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC4_PTR->CFSSR1.R)},
	{(volatile uint32 *)&(EQADC5_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC5_PTR->CFSSR1.R)},
    {(volatile uint32 *)&(EQADC6_PTR->CFSSR0.R), (volatile uint32 *)&(EQADC6_PTR->CFSSR1.R)}
};

#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
/* EQADC CFIFO Trigger Delay Registers (EQADC_DLY) */
static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_DLY[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
{
    {(volatile uint32 *)&(EQADC0_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC0_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC1_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC1_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC2_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC2_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC3_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC3_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC4_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC4_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC5_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC5_PTR->DLY[5U].R)},
    {(volatile uint32 *)&(EQADC6_PTR->DLY[0U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[1U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[2U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[3U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[4U].R), (volatile uint32 *)&(EQADC6_PTR->DLY[5U].R)}
};
#endif

/**/
static eDMATransferConfigType tcdcfg =
{
    .srcAddr                  = 0,
    .destAddr                 = 0,
    .srcTransDataSize         = EDMA_TRANSFER_SIZE_1B,
	.destTransDataSize        = EDMA_TRANSFER_SIZE_1B,
    .srcAddrOffset            = 0,
    .destAddrOffset           = 0,
    .srcAddrAdjustLast        = 0,
    .destAddrAdjustLast       = 0,
    .srcAddrModulo            = EDMA_ADDRESS_MODULO_OFF,
    .destAddrModulo           = EDMA_ADDRESS_MODULO_OFF,
    .minorTransByte           = 0,
    .featureScatterGatherEn   = FALSE,
    .featureScatterGatherNextDescriptor   = 0U,
    .completeIntEn            = TRUE,
    .lpTransConfigPtr         = NULL_PTR,
};

static eDMALoopTransferConfigType looptcdcfg = 
{
    .majorLpIterCnt       = 0,
    .srcAddrOffsetEn      = FALSE,
    .dstAddrOffsetEn      = FALSE,
    .minorLpOffset        = 0,
    .minorLpLinkEn        = FALSE,
    .minorLpLinkChn       = 0U,
    .majorLpLinkEn        = FALSE,
    .majorLpLinkChn       = 0U,
};

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
 * @brief EQADC Module Configuration Register: Set ICEAx (EQADC_MCR: ICEAx)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        bAdc_EnDis: FALSE: Disable
 *                    TRUE: Enable
 *
 * @note  ICEAn enables the EQADC to abort on-chip ADCn current conversion
 *          and to start the immediate conversion command from CFIFO0 in the
 *          requested ADCn.
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_MCR_SetICEAxEnDis \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_AdcIdx, \
    CONST(boolean , ADC_CONST) bAdc_EnDis \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_ICEAxEnDis = (uint8)((u8Adc_AdcIdx << 1U) | ((bAdc_EnDis == TRUE) ? 1U : 0U));

    switch (u8Adc_ICEAxEnDis)
    {
        case 0U:
        {
            /* Disable CFIFO0 Immediate Conversion Command (ADC0) */
            *(EQADC_MCR[u8Adc_Instance]) &= ~EQADC_MCR_ICEA0_MASK;
            break;
        }
        case 1U:
        {
            /* Enable CFIFO0 Immediate Conversion Command (ADC0) */
            *(EQADC_MCR[u8Adc_Instance]) |= EQADC_MCR_ICEA0_MASK;
            break;
        }
        case 2U:
        {
            /* Disable CFIFO0 Immediate Conversion Command (ADC1) */
            *(EQADC_MCR[u8Adc_Instance]) &= ~EQADC_MCR_ICEA1_MASK;
            break;
        }
        case 3U:
        {
            /* Enable CFIFO0 Immediate Conversion Command (ADC1) */
            *(EQADC_MCR[u8Adc_Instance]) |= EQADC_MCR_ICEA1_MASK;
            break;
        }
        default:
        {
            /* Nothing to do */
            break;
        }
    }
}

/*******************************************************************************
 * @brief EQADC Module Configuration Register: Get Debug enable/disable
 *          (EQADC_MCR: DBG)
 *
 * @param u8Adc_Instance: EQADC instance
 *        [out] FALSE: Disable
 *              TRUE: Enable
 *
 * @note  The DBG field defines the EQADC response to a debug mode entry request.
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, ADC_CODE) EQADC_MCR_GetDebugEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance)
{
    return (uint8)(((*(EQADC_MCR[u8Adc_Instance]) & EQADC_MCR_DBG_MASK) == 0U) ? FALSE : TRUE);
}

/*******************************************************************************
 * @brief EQADC Module Configuration Register: Set Debug enable/disable
 *          (EQADC_MCR: DBG)
 *
 * @param u8Adc_Instance: EQADC instance
 *        bAdc_EnDis: FALSE: Disable
 *               TRUE: Enable
 *
 * @note  The DBG field defines the EQADC response to a debug mode entry request.
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_MCR_SetDebugEnDis \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(boolean , ADC_CONST) bAdc_EnDis \
)
{
    if (FALSE == bAdc_EnDis)
    {
        *(EQADC_MCR[u8Adc_Instance]) &= ~EQADC_MCR_DBG_MASK;
    }
    else
    {
        *(EQADC_MCR[u8Adc_Instance]) |= EQADC_MCR_DBG_MASK;
    }
}

LOCAL_INLINE FUNC(uint8, ADC_CODE) EQADC_ETDFR_GetDFL(CONST(uint8, ADC_CONST) u8Adc_Instance)
{
    return (uint8)(*(EQADC_ETDFR[u8Adc_Instance]) & EQADC_ETDFR_DFL_MASK);
}

/*******************************************************************************
 * @brief EQADC External Trigger Digital Filter Register (EQADC_ETDFR: DFL)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_DigiFilterLen: Digital filter length
 *
 * @note  FilterPeriod = (SystemClockPeriod * 2^DFL) + 1(SystemClockPeriod).
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_ETDFR_SetDFL \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_DigiFilterLen \
)
{
    *(EQADC_ETDFR[u8Adc_Instance]) = ((uint32)u8Adc_DigiFilterLen & EQADC_ETDFR_DFL_MASK);
}

/*******************************************************************************
 * @brief EQADC CFIFO Control Register 0: Get CFEEE0 (EQADC_CFCR0: CFEEE0)
 *
 * @param u8Adc_Instance: EQADC instance
 *        [out] FALSE: Disable
 *              TRUE: Enable
 *
 * @note  CFIFO0 Entry Number Extension Enable/Disable.
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, ADC_CODE) EQADC_CFCR0_GetCfifo0EntryExtEnDis(CONST(uint8, ADC_CONST) u8Adc_Instance)
{
    return (uint8)(((*(EQADC_CFCR[u8Adc_Instance][0U]) & EQADC_CFCR0_CFEEE0_MASK) == 0U) ? FALSE : TRUE);
}

/*******************************************************************************
 * @brief EQADC CFIFO Control Register 0: Set CFEEE0 (EQADC_CFCR0: CFEEE0)
 *
 * @param u8Adc_Instance: EQADC instance
 *        bAdc_EnDis: FALSE: Disable
 *                    TRUE: Enable
 *
 * @note  CFIFO0 Entry Number Extension Enable/Disable.
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_CFCR0_SetCfifo0EntryExtEnDis \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(boolean , ADC_CONST) bAdc_EnDis \
)
{
    if (FALSE == bAdc_EnDis)
    {
        /* CFIFO0 Entry Number Extension Disable */
        *(EQADC_CFCR[u8Adc_Instance][0U]) &= ~EQADC_CFCR0_CFEEE0_MASK;
    }
    else
    {
        /* CFIFO0 Entry Number Extension Enable */
        *(EQADC_CFCR[u8Adc_Instance][0U]) |= EQADC_CFCR0_CFEEE0_MASK;
    }
}

/*******************************************************************************
 * @brief EQADC CFIFO Control Register 0 (EQADC_CFCR0: STRME0)
 *
 * @param u8Adc_Instance: EQADC instance
 *        bAdc_EnDis: 0, 1 (Disable, Enable)
 *
 * @note  CFIFO0 Streaming Mode Operation Enable/Disable.
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_CFCR0_Cfifo0StreamModeEnDis \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(boolean , ADC_CONST) bAdc_EnDis \
)
{
    if (0U == bAdc_EnDis)
    {
        /* CFIFO0 Entry Number Extension Disable */
        *(EQADC_CFCR[u8Adc_Instance][0U]) &= ~EQADC_CFCR0_STRME0_MASK;
    }
    else
    {
        /* CFIFO0 Entry Number Extension Enable */
        *(EQADC_CFCR[u8Adc_Instance][0U]) |= EQADC_CFCR0_STRME0_MASK;
    }
}

/*******************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: SSEy)
 *          (x = 0...2, y = 0...5).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)
 *
 * @note  Writing a "1" to SSEx will set the EQADC_FISR[SSSx] field if the
 *          CFIFO is in single-scan mode. SSEx always is read as "0".
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_CFCRxSetSSE \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */

    if ((u8Adc_CfifoIdx % 2U) == 0U)
    {
        /* EQADC CfifoIdx: 0/2/4 */
        *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_SSE0_MASK;
    }
    else
    {
        /* EQADC CfifoIdx: 1/3/5 */
        *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_SSE1_MASK;
    }
}

/*******************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: SSEy)
 *          (x = 0...2, y = 0...5).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)(Synchronous: 0 & 1, 2 & 3, 4 & 5)
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_CFCRxSetSSE_Sync \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */
    /* EQADC CfifoIdx synchronous: 0 & 1, 2 & 3, 4 & 5 */
    *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= (EQADC_CFCR0_SSE0_MASK | EQADC_CFCR0_SSE1_MASK);
}

/*********************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: CFINVy)
 *          (x = 0...2, y = 0...5).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)
 *
 * @note  Writing CFINVy only invalidates commands stored in CFIFOx;
 *          previously transferred commands that are waiting for execution,
 *          that is commands stored in the CBuffers, will still be executed,
 *          and results generated by them will be stored in the appropriate RFIFO.
 *        CFINVy must not be written unless the MODEy is configured to disabled,
 *          and CFIFO status is IDLE.
 *********************************************************************************/
FUNC(void, ADC_CODE) EQADC_CFCRxSetInvalidate \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */
    if ((u8Adc_CfifoIdx % 2U) == 0U)
    {
        /* EQADC CfifoIdx: 0/2/4 */
        *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_CFINV0_MASK;
    }
    else
    {
        /* EQADC CfifoIdx: 1/3/5 */
        *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_CFINV1_MASK;
    }
}

/*******************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: MODEy)
 *          (x = 0...2, y = 0...5).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)
 *
 * @param [out]Get the current mode of CFIFO.
 *******************************************************************************/
LOCAL_INLINE FUNC(uint32, ADC_CODE) EQADC_CFCRxGetMode \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */
    VAR(uint32, AUTOMATIC) u32Adc_CfifoModeCurrent;
    if ((u8Adc_CfifoIdx % 2U) == 0U)
    {
        /* EQADC CfifoIdx: 0/2/4 */
        u32Adc_CfifoModeCurrent \
            = (*(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) & EQADC_CFCR0_MODE0_MASK) \
                >> EQADC_CFCR0_MODE0_SHIFT;
    }
    else
    {
        /* EQADC CfifoIdx: 1/3/5 */
        u32Adc_CfifoModeCurrent \
            = (*(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) & EQADC_CFCR0_MODE1_MASK) \
                >> EQADC_CFCR0_MODE1_SHIFT;
    }

    return u32Adc_CfifoModeCurrent;
}

LOCAL_INLINE FUNC(uint32, ADC_CODE) EQADC_CFCR0_GetAMode0(CONST(uint8, ADC_CONST) u8Adc_Instance)
{
    return ((*(EQADC_CFCR[u8Adc_Instance][0U]) & EQADC_CFCR0_AMODE0_MASK) \
            >> EQADC_CFCR0_AMODE0_SHIFT);
}

/*******************************************************************************
 * @brief EQADC CFIFO Control Register 0 (EQADC_CFCR0: AMODE0)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_Cfifo0AdvanceMode0: Set the advance trigger operation mode for CFIFO0
 *
 * @note  If AMODE0 is not disabled, it must not be changed to any other mode
 *          besides disabled.
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_CFCR0_SetAMode0 \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_Cfifo0AdvanceMode0 \
)
{
    *(EQADC_CFCR[u8Adc_Instance][0U]) &= ~EQADC_CFCR0_AMODE0_MASK;
    *(EQADC_CFCR[u8Adc_Instance][0U]) |= EQADC_CFCR0_AMODE0(u8Adc_Cfifo0AdvanceMode0);
}

/*******************************************************************************
 * @brief EQADC Interrupt and DMA Control Registers x (EQADC_IDCRx)(x = 0...2)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_FifoIdx: CFIFO/RFIFO Index (0...5)
 *
 * @param [out] u8Adc_IDCRx result(16 bits)
 *
 * @note  The EQADC Interrupt Control Registers (EQADC_IDCR) contain bits to
 *          enable the generation of interrupt or DMA requests when the
 *          corresponding flag bits are set in "EQADC FIFO
 *          and Interrupt Status Registers (EQADC_FISR)".
 *******************************************************************************/
LOCAL_INLINE FUNC(uint16, ADC_CODE) EQADC_IDCRx_GetFifoIntDma \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_FifoIdx \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_IDCRx = u8Adc_FifoIdx / 2U;  /* EQADC Interrupt and DMA Control Registers x */
    VAR(uint16, AUTOMATIC) u16Adc_IDCRxData = 0U;
    if ((u8Adc_FifoIdx % 2U) == 0U)
    {
        /* EQADC FifoIdx: 0/2/4 */
        u16Adc_IDCRxData = (uint16)((*(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) >> 16U) & 0xFFFFU);
    }
    else
    {
        /* EQADC FifoIdx: 1/3/5 */
        u16Adc_IDCRxData = (uint16)(*(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) & 0xFFFFU);
    }

    return u16Adc_IDCRxData;
}

#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
static FUNC(void, ADC_CODE) Adc_DemReportErrorStatus \
( \
    VAR(Dem_EventIdType, AUTOMATIC) Adc_EventId, \
    VAR(Dem_EventStatusType, AUTOMATIC) Adc_EventStatus \
)
{
	(void)Dem_SetEventStatus((Dem_EventIdType)Adc_EventId, Adc_EventStatus);
}
#endif

/*******************************************************************************
 * @brief EQADC Interrupt and DMA Control Registers x (EQADC_IDCRx)(x = 0...2)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_FifoIdx: CFIFO/RFIFO Index (0...5)
 *        u16Adc_FifoIntDmaMask: IDCRx mask(16 bits)
 *        bAdc_EnDis: 0: Disable, 1: Enable;
 *                    0: INT, 1: DMA(FifoIntDmaMask = EQADC_INT_DMA_SEL_xxx)
 *
 * @note  The EQADC Interrupt Control Registers (EQADC_IDCR) contain bits to
 *          enable the generation of interrupt or DMA requests when the
 *          corresponding flag bits are set in "EQADC FIFO
 *          and Interrupt Status Registers (EQADC_FISR)".
 *******************************************************************************/
FUNC(void, ADC_CODE) EQADC_IDCRx_FifoIntDmaEnDis \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_FifoIdx, \
    CONST(uint16, ADC_CONST) u16Adc_FifoIntDmaMask, \
    CONST(boolean, ADC_CONST) bAdc_EnDis \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_IDCRx = u8Adc_FifoIdx / 2U;  /* EQADC Interrupt and DMA Control Registers x */
    VAR(uint8, AUTOMATIC) u8Adc_IDCRxEnDis = (uint8)(((u8Adc_FifoIdx % 2U) << 1U) | ((bAdc_EnDis == TRUE) ? 1U : 0U));

    switch (u8Adc_IDCRxEnDis)
    {
        case 0U:
        {
            /* EQADC FifoIdx: 0/2/4, interrupt and DMA disable. */
            *(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) &= ~((uint32)u16Adc_FifoIntDmaMask << 16U);
            break;
        }
        case 1U:
        {
            /* EQADC FifoIdx: 0/2/4, interrupt and DMA enable. */
            *(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) |= ((uint32)u16Adc_FifoIntDmaMask << 16U);
            break;
        }
        case 2U:
        {
            /* EQADC FifoIdx: 1/3/5, interrupt and DMA disable. */
            *(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) &= ~((uint32)u16Adc_FifoIntDmaMask);
            break;
        }
        case 3U:
        {
            /* EQADC FifoIdx: 1/3/5, interrupt and DMA enable. */
            *(EQADC_IDCR[u8Adc_Instance][u8Adc_IDCRx]) |= (uint32)u16Adc_FifoIntDmaMask;
            break;
        }
        default:
        {
            /* Nothing to do */
            break;
        }
    }
}

/*******************************************************************************
 * @brief EQADC CFIFO Transfer Counter Register x (EQADC_CFTCR)(x = 0...2)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (0...5)
 *
 * @note  TC_CFx counts the number of commands which have been completely
 *          transferred from CFIFOx.
 *******************************************************************************/
LOCAL_INLINE FUNC(uint16, ADC_CODE) EQADC_CFTCRx_GetCfifoTransCount \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFTCRx = u8Adc_CfifoIdx / 2U; /* EQADC CFIFO Transfer Counter Register x */
    VAR(uint16, AUTOMATIC) u16Adc_TransCount = 0U;
    if ((u8Adc_CfifoIdx % 2U) == 0U)
    {
        /* EQADC CfifoIdx: 0/2/4 */
        u16Adc_TransCount \
            = (uint16)((*(EQADC_CFTCR[u8Adc_Instance][u8Adc_CFTCRx]) & EQADC_CFTCR0_TC_CF0_MASK) \
                >> EQADC_CFTCR0_TC_CF0_SHIFT);
    }
    else
    {
        /* EQADC CfifoIdx: 1/3/5 */
        u16Adc_TransCount = (uint16)(*(EQADC_CFTCR[u8Adc_Instance][u8Adc_CFTCRx]) & EQADC_CFTCR0_TC_CF1_MASK);
    }

    return u16Adc_TransCount;
}

/*******************************************************************************
 * @brief EQADC CFIFO Transfer Counter Register x (EQADC_CFTCR)(x = 0...2)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (0...5)
 *        u16Adc_CfifoTransCount: Transfer Counter for CFIFOx
 *
 * @note  TC_CFx counts the number of commands which have been completely
 *          transferred from CFIFOx.
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_CFTCRx_SetCfifoTransCount \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint16, ADC_CONST) u16Adc_CfifoTransCount \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFTCRx = u8Adc_CfifoIdx / 2U; /* EQADC CFIFO Transfer Counter Register x */
    if ((u8Adc_CfifoIdx % 2U) == 0U)
    {
        /* EQADC CfifoIdx: 0/2/4 */
        *(EQADC_CFTCR[u8Adc_Instance][u8Adc_CFTCRx]) = EQADC_CFTCR0_TC_CF0(u16Adc_CfifoTransCount);
    }
    else
    {
        /* EQADC CfifoIdx: 1/3/5 */
        *(EQADC_CFTCR[u8Adc_Instance][u8Adc_CFTCRx]) = EQADC_CFTCR0_TC_CF1(u16Adc_CfifoTransCount);    /* PRQA S 2985 */
    }
}

/*******************************************************************************
 * @brief EQADC CFIFO Status Snapshot Register x: TCB (EQADC_CFSSR)(x = 0...1)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (0...5)
 *        u8Adc_AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] CFIFO Status
 *
 * @note  CFIFO Status at Transfer to CBuffer0/1.
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, ADC_CODE) EQADC_CFSSRx_GetCfifoStatusAtTCB_Snapshot \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_AdcIdx \
)
{
    VAR(uint32, AUTOMATIC) u32Adc_TempVal;
    VAR(uint32, AUTOMATIC) u32Adc_Tcb = 0U;
    VAR(uint8, AUTOMATIC) u8Adc_Tcb = 0U;
    u32Adc_TempVal = (EQADC_CFSSR0_CFS0_TCB0_SHIFT - (EQADC_CFSSR0_CFS0_TCB0_WIDTH * (uint32)u8Adc_CfifoIdx));

    u32Adc_Tcb = (*EQADC_CFSSR[u8Adc_Instance][u8Adc_AdcIdx] >> u32Adc_TempVal);

    u8Adc_Tcb \
        = (uint8)(u32Adc_Tcb & (EQADC_CFSSR0_CFS0_TCB0_MASK >> EQADC_CFSSR0_CFS0_TCB0_SHIFT));
    return u8Adc_Tcb;
}

/*******************************************************************************
 * @brief EQADC CFIFO Status Snapshot Register x: LCFTCB
 *          (EQADC_CFSSR)(x = 0...1)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] CFIFO Index (0...5)
 *
 * @note  Last CFIFO to Transfer to CBuffer0/1.
 *******************************************************************************/
LOCAL_INLINE FUNC(uint8, ADC_CODE) EQADC_CFSSRx_GetLastCfifoToTCB_Snapshot \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_AdcIdx \
)
{
    return (uint8)((*(EQADC_CFSSR[u8Adc_Instance][u8Adc_AdcIdx]) \
        & EQADC_CFSSR0_LCFTCB0_MASK) >> EQADC_CFSSR0_LCFTCB0_SHIFT);
}

/*******************************************************************************
 * @brief EQADC CFIFO Status Snapshot Register x: TC_LCFTCB
 *          (EQADC_CFSSR)(x = 0...1)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_AdcIdx: 0, 1 (On-chip ADC0 / ADC1)
 *        [out] Transfer Counter
 *
 * @note  Transfer Counter for Last CFIFO to transfer commands to CBuffer0/1.
 *******************************************************************************/
LOCAL_INLINE FUNC(uint16, ADC_CODE) EQADC_CFSSRx_GetTransCountForLastCfifoToTCB_Snapshot \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_AdcIdx \
)
{
    return (uint16)((*(EQADC_CFSSR[u8Adc_Instance][u8Adc_AdcIdx]) \
        & EQADC_CFSSR0_TC_LCFTCB0_MASK) >> EQADC_CFSSR0_TC_LCFTCB0_SHIFT);
}

#ifndef CCFC3012PT
/*******************************************************************************
 * @brief EQADC Red Line Client Configuration Register (EQADC_REDLCCR)
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_ClientIdx: 0 or 1
 *        u8Adc_RedLineTbaseBitSel: Red Line TimeBase Bits Selection m (m=1,2)
 *        u8Adc_RedLineSlotSel: Red Line Server Data Slot Selector m (m=1,2)
 *
 * @note  TC_CFx counts the number of commands which have been completely
 *          transferred from CFIFOx.
 *******************************************************************************/
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_REDLCCR_SetREDBS_SRVx \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_ClientIdx, \
    CONST(uint8, ADC_CONST) u8Adc_RedLineTbaseBitSel, \
    CONST(uint8, ADC_CONST) u8Adc_RedLineSlotSel \
)
{
    /* EQADC Red Line Client Configuration Register (EQADC_REDLCCR) */
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_REDLCCR[ADC_EQADC_MAX_INSTANCE] =
    {
        (volatile uint32 *)&(EQADC0_PTR->STACCCR.R),
		(volatile uint32 *)&(EQADC1_PTR->STACCCR.R),
		(volatile uint32 *)&(EQADC2_PTR->STACCCR.R),
		(volatile uint32 *)&(EQADC3_PTR->STACCCR.R),
		(volatile uint32 *)&(EQADC4_PTR->STACCCR.R),
		(volatile uint32 *)&(EQADC5_PTR->STACCCR.R),
		(volatile uint32 *)&(EQADC6_PTR->STACCCR.R)
    };

    switch (u8Adc_ClientIdx)
    {
        case 0U:
        {
            *(EQADC_REDLCCR[u8Adc_Instance]) \
                &= ~(EQADC_STACCCR_SRV1_MASK | EQADC_STACCCR_STACBS1_MASK);
            *(EQADC_REDLCCR[u8Adc_Instance]) \
                |= (EQADC_STACCCR_STACBS1(u8Adc_RedLineTbaseBitSel) \
                    | EQADC_STACCCR_SRV1(u8Adc_RedLineSlotSel)); /* PRQA S 2985 */
            break;
        }
        case 1U:
        {
            *(EQADC_REDLCCR[u8Adc_Instance]) \
                &= ~(EQADC_STACCCR_SRV2_MASK | EQADC_STACCCR_STACBS2_MASK);
            *(EQADC_REDLCCR[u8Adc_Instance]) \
                |= (EQADC_STACCCR_STACBS2(u8Adc_RedLineTbaseBitSel) \
                    | EQADC_STACCCR_SRV2(u8Adc_RedLineSlotSel));
            break;
        }
        default:
        {
            /* Nothing to do */
            break;
        }
    }
}
#endif

LOCAL_INLINE FUNC(uint32, ADC_CODE) EQADC_CFxRw_GetCfifoData \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_EntryIdx \
)
{
    /* EQADC CFIFO Registers (EQADC_CFxRw) (x = 0, .., 5; w = 0, .., 3) */
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_CFxRw[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
    {
        {(volatile uint32 *)&(EQADC0_PTR->CF0R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->CF1R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->CF2R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->CF3R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->CF4R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->CF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC1_PTR->CF0R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->CF1R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->CF2R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->CF3R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->CF4R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->CF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC2_PTR->CF0R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->CF1R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->CF2R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->CF3R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->CF4R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->CF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC3_PTR->CF0R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->CF1R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->CF2R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->CF3R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->CF4R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->CF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC4_PTR->CF0R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->CF1R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->CF2R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->CF3R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->CF4R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->CF5R[0U].R)}, \
		{(volatile uint32 *)&(EQADC5_PTR->CF0R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->CF1R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->CF2R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->CF3R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->CF4R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->CF5R[0U].R)}, \
		{(volatile uint32 *)&(EQADC6_PTR->CF0R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->CF1R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->CF2R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->CF3R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->CF4R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->CF5R[0U].R)}
    };

    return (EQADC_CFxRw[u8Adc_Instance][u8Adc_CfifoIdx][u8Adc_EntryIdx] & EQADC_CF0R_CFIFO0_DATAW_MASK);
}

LOCAL_INLINE FUNC(uint16, ADC_CODE) EQADC_RFxRw_GetRfifoData \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_EntryIdx \
)
{
    /* EQADC RFIFO Registers (EQADC_RFxRw) (x = 0, .., 5; w = 0, .., 3) */
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_RFxRw[ADC_EQADC_MAX_INSTANCE][EQADC_RFIFO_COUNT] =
    {
        {(volatile uint32 *)&(EQADC0_PTR->RF0R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->RF1R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->RF2R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->RF3R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->RF4R[0U].R), \
		(volatile uint32 *)&(EQADC0_PTR->RF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC1_PTR->RF0R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->RF1R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->RF2R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->RF3R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->RF4R[0U].R), \
		(volatile uint32 *)&(EQADC1_PTR->RF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC2_PTR->RF0R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->RF1R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->RF2R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->RF3R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->RF4R[0U].R), \
		(volatile uint32 *)&(EQADC2_PTR->RF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC3_PTR->RF0R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->RF1R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->RF2R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->RF3R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->RF4R[0U].R), \
		(volatile uint32 *)&(EQADC3_PTR->RF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC4_PTR->RF0R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->RF1R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->RF2R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->RF3R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->RF4R[0U].R), \
		(volatile uint32 *)&(EQADC4_PTR->RF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC5_PTR->RF0R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->RF1R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->RF2R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->RF3R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->RF4R[0U].R), \
		(volatile uint32 *)&(EQADC5_PTR->RF5R[0U].R)}, \
        {(volatile uint32 *)&(EQADC6_PTR->RF0R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->RF1R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->RF2R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->RF3R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->RF4R[0U].R), \
		(volatile uint32 *)&(EQADC6_PTR->RF5R[0U].R)}
    };

    return (uint16)(EQADC_RFxRw[u8Adc_Instance][u8Adc_CfifoIdx][u8Adc_EntryIdx] & EQADC_RF0R_RFIFO0_DATAW_MASK);
}

#ifdef RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT
#define NUM_OF_EQADC_SIUL2_ISEL_MAPPED      (2U)
#define EQADC_CFIFO_TRIG_MAPPED_INVALID     (0xFFU)
#define EQADC_CFIFO0_ATRIG_MAPPED_INVALID   (0xFFU)

static VAR(uint8, AUTOMATIC) EQADC_Trig_SIUL_ISEL_Mapped[NUM_OF_EQADC_SIUL2_ISEL_MAPPED][EQADC_CFIFO_COUNT] =
{
    {
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID,
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID,
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID
    },
    {
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID,
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID,
        EQADC_CFIFO_TRIG_MAPPED_INVALID, EQADC_CFIFO_TRIG_MAPPED_INVALID
    }
};

static VAR(uint8, AUTOMATIC) EQADC_AdvanceTrig_SIUL_ISEL_Mapped[NUM_OF_EQADC_SIUL2_ISEL_MAPPED] =
{
    EQADC_CFIFO0_ATRIG_MAPPED_INVALID, EQADC_CFIFO0_ATRIG_MAPPED_INVALID
};
#endif  /* RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT */

/*******************************************************************************
 * @brief EQADC CFIFO trigger source setting.
 *******************************************************************************/
#if defined(RESOURCE_SUPPORT_SIUL2_IP)
FUNC(uint8, ADC_CODE) EQADC_ISELx_SetCfifoTrig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_TrigSourceVal \
)
{
    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_TRIG_CFIFO_01[5u] =
    {
		(volatile uint32 *)&(SIUL2_PTR->ISEL5.R),    /* EQADC0_ADC0/EQADC0_ADC1: CFIFO0/CFIFO1 */
		(volatile uint32 *)&(SIUL2_PTR->ISEL5.R),    /* EQADC1_ADC2/EQADC1_ADC3: CFIFO0/CFIFO1 */
		(volatile uint32 *)&(SIUL2_PTR->ISEL7.R),    /* EQADC2_ADC4/EQADC2_ADC5: CFIFO0/CFIFO1 */
		(volatile uint32 *)&(SIUL2_PTR->ISEL7.R),    /* EQADC3_ADC6/EQADC3_ADC7: CFIFO0/CFIFO1 */
		(volatile uint32 *)&(SIUL2_PTR->ISEL7.R)     /* EQADC4_ADC8/EQADC4_ADC9: CFIFO0/CFIFO1 */
    };

    static CONSTP2VAR(volatile uint32, ADC_CONST, ADC_APPL_CONST) EQADC_TRIG_CFIFO_2345[5u] =
    {
		(volatile uint32 *)&(SIUL2_PTR->ISEL4.R),    /* EQADC0_ADC0/EQADC0_ADC1: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
		(volatile uint32 *)&(SIUL2_PTR->ISEL4.R),    /* EQADC1_ADC2/EQADC1_ADC3: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
		(volatile uint32 *)&(SIUL2_PTR->ISEL6.R),    /* EQADC2_ADC4/EQADC2_ADC5: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
		(volatile uint32 *)&(SIUL2_PTR->ISEL6.R),    /* EQADC3_ADC6/EQADC3_ADC7: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
		(volatile uint32 *)&(SIUL2_PTR->ISEL6.R)     /* EQADC4_ADC8/EQADC4_ADC9: CFIFO2/CFIFO3/CFIFO4/CFIFO5 */
    };


    VAR(uint8, ADC_VAR) u8Adc_ret = (uint8)E_OK;

	SchM_Enter_ADC_EXCLUSIVE_AREA_10();
    if ((u8Adc_Instance < 5u) && (u8Adc_CfifoIdx < EQADC_CFIFO_COUNT))
    {
#ifdef RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT
        CONST(uint8, ADC_CONST) u8Adc_ISEL_Mapped_x = ((u8Adc_Instance > 1u) ? 1u : 0u);
        if (EQADC_Trig_SIUL_ISEL_Mapped[u8Adc_ISEL_Mapped_x][u8Adc_CfifoIdx] == EQADC_CFIFO_TRIG_MAPPED_INVALID)
        {
            EQADC_Trig_SIUL_ISEL_Mapped[u8Adc_ISEL_Mapped_x][u8Adc_CfifoIdx] = \
                    ((u8Adc_TrigSourceVal == EQADC_HW_TRIG_NOT_CONNECTED) ? EQADC_CFIFO_TRIG_MAPPED_INVALID : u8Adc_Instance);
#endif  /* RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT */
	        switch (u8Adc_CfifoIdx)
	        {
		        case 0U:
            {
                /* CFIFO_0 */
                *(EQADC_TRIG_CFIFO_01[u8Adc_Instance]) &= ~0x7F0000U;
                *(EQADC_TRIG_CFIFO_01[u8Adc_Instance]) \
                    |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 16U)) & 0x7F0000U);
                break;
            }
            case 1U:
            {
                /* CFIFO_1 */
                *(EQADC_TRIG_CFIFO_01[u8Adc_Instance]) &= ~0x7F000000U;
                *(EQADC_TRIG_CFIFO_01[u8Adc_Instance]) \
                    |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 24U)) & 0x7F000000U);
                break;
            }
            case 2U:
            {
                /* CFIFO_2 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7FU;
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) \
                    |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 0U)) & 0x7FU); /* PRQA S 2985 */
                break;
            }
            case 3U:
            {
                /* CFIFO_3 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7F00U;
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) \
                    |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 8U)) & 0x7F00U);
                break;
            }
            case 4U:
            {
                /* CFIFO_4 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7F0000U;
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) \
                    |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 16U)) & 0x7F0000U);
                break;
            }
            case 5U:
            {
                /* CFIFO_5 */
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) &= ~0x7F000000U;
                *(EQADC_TRIG_CFIFO_2345[u8Adc_Instance]) \
                    |= (((uint32)(((uint32)(u8Adc_TrigSourceVal)) << 24U)) & 0x7F000000U);
                break;
            }
            default:
            {
                /* Nothing to do */
                u8Adc_ret = (uint8)E_NOT_OK;
                break;
            }
	    }
#ifdef RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT
        }
        else
        {
            u8Adc_ret = (uint8)E_NOT_OK;
        }
#endif  /* RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT */
    }
    else
    {
        u8Adc_ret = (uint8)E_NOT_OK;
    }
    SchM_Exit_ADC_EXCLUSIVE_AREA_10();
	return u8Adc_ret;
}
#elif defined(RESOURCE_SUPPORT_SIUL_IP)
FUNC(uint8, ADC_CODE) EQADC_ISELx_SetCfifoTrig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_TrigSourceVal \
)
{
    static CONST(volatile uint32, ADC_CONST)EQADC_CfifoTrig_Offset[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
    {
        {2u,  1u,  0u , 7u , 6u , 5u }, /* EQADC0_ADC01: CFIFO0~5 */
        {11u, 10u, 9u , 8u , 15u, 14u}, /* EQADC1_ADC23: CFIFO0~5 */
        {12u, 19u, 18u, 17u, 16u, 23u}, /* EQADC2_ADC45: CFIFO0~5 */
        {21u, 20u, 27u, 26u, 25u, 24u}, /* EQADC3_ADC67: CFIFO0~5 */
        {30u, 29u, 28u, 35u, 34u, 33u}, /* EQADC4_ADC89: CFIFO0~5 */
        {39u, 38u, 37u, 36u, 43u, 42u}, /* EQADC5_ADC1011: CFIFO0~5 */
        {40u, 47u, 46u, 45u, 44u, 51u}  /* EQADC6_ADC12: CFIFO0~5 */
    };

    VAR(uint8, ADC_VAR) u8Adc_ret = (uint8)E_OK;

	SchM_Enter_ADC_EXCLUSIVE_AREA_10();

    if ((u8Adc_Instance < ADC_EQADC_MAX_INSTANCE) && (u8Adc_CfifoIdx < EQADC_CFIFO_COUNT))
    {
        (*(volatile uint8 *)(SIUL_BASEADDR + SIUL_ISEL0_OFFSET_ADDR + EQADC_CfifoTrig_Offset[u8Adc_Instance][u8Adc_CfifoIdx])) = (uint8)u8Adc_TrigSourceVal;
    }
    else
    {
        u8Adc_ret = (uint8)E_NOT_OK;
    }
    
    SchM_Exit_ADC_EXCLUSIVE_AREA_10();
    return u8Adc_ret;
}
#else
    #error "No valid IO control!"
#endif  /* RESOURCE_SUPPORT_SIUL2_IP */

#if defined(RESOURCE_SUPPORT_SIUL2_IP)
FUNC(uint8, ADC_CODE) EQADC_ISELx_SetCfifo0AdvanceTrig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_AdvanceTrigVal \
)
{
	VAR(uint8, ADC_VAR) u8Adc_ret = (uint8)E_OK;

    SchM_Enter_ADC_EXCLUSIVE_AREA_11();
#ifdef RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT
    CONST(uint8, ADC_CONST) u8Adc_ISEL_Mapped_x = ((instance > 1u) ? 1u : 0u);
    if (EQADC_AdvanceTrig_SIUL_ISEL_Mapped[u8Adc_ISEL_Mapped_x] == EQADC_CFIFO0_ATRIG_MAPPED_INVALID)
    {
        EQADC_AdvanceTrig_SIUL_ISEL_Mapped[u8Adc_ISEL_Mapped_x] = \
                ((u8Adc_AdvanceTrigVal == EQADC_ATRIG_NOT_CONNECTED) ? EQADC_CFIFO0_ATRIG_MAPPED_INVALID : u8Adc_Instance);
#endif  /* RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT */
        switch (u8Adc_Instance)
        {
            case 0U:
            case 1U:
            {
                /* EQADC0_ADC0/EQADC0_ADC1, EQADC1_ADC2/EQADC1_ADC3 */
                SIUL2.ISEL9.R &= ~0x1F0000U;
                SIUL2.ISEL9.R |= (((uint32)(((uint32)(u8Adc_AdvanceTrigVal)) << 16U)) & 0x1F0000U);
                break;
            }
            case 2U:
            case 3U:
            case 4U:
            {
                /* EQADC2_ADC4/EQADC2_ADC5, EQADC3_ADC6/EQADC3_ADC7, EQADC4_ADC8/EQADC4_ADC9 */
                SIUL2.ISEL9.R &= ~0x1FU;
                SIUL2.ISEL9.R |= (((uint32)(((uint32)(u8Adc_AdvanceTrigVal)) << 0U)) & 0x1FU); /* PRQA S 2985 */
                break;
            }
            default:
            {
                /* Nothing to do */
                u8Adc_ret = (uint8)E_NOT_OK;
                break;
            }
        }
#ifdef RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT
    }
    else
    {
        u8Adc_ret = FALSE;
    }
#endif  /* RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT */
    SchM_Exit_ADC_EXCLUSIVE_AREA_11();
	return u8Adc_ret;
}
#elif defined(RESOURCE_SUPPORT_SIUL_IP)
FUNC(uint8, ADC_CODE) EQADC_ISELx_SetCfifo0AdvanceTrig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_AdvanceTrigVal \
)
{
    static CONST(volatile uint32, ADC_CONST)EQADC_Cfifo0ATrig_Offset[ADC_EQADC_MAX_INSTANCE] =
    {
        3u, 4u, 13u, 22u, 31u, 32u, 41u /* EQADC instance 0~6 */
    };

    VAR(uint8, ADC_VAR) u8Adc_ret = (uint8)E_OK;

    SchM_Enter_ADC_EXCLUSIVE_AREA_11();

    if (u8Adc_Instance < ADC_EQADC_MAX_INSTANCE)
    {
        (*(volatile uint8 *)(SIUL_BASEADDR + SIUL_ISEL0_OFFSET_ADDR + EQADC_Cfifo0ATrig_Offset[u8Adc_Instance])) = (uint8)u8Adc_AdvanceTrigVal;
    }
    else
    {
        u8Adc_ret = (uint8)E_NOT_OK;
    }

    SchM_Exit_ADC_EXCLUSIVE_AREA_11();
    return u8Adc_ret;
}
#else
    #error "No valid IO control!"           
#endif  /* RESOURCE_SUPPORT_SIUL2_IP */

LOCAL_INLINE FUNC(void, ADC_CODE) GTM_to_EQADC_Connections
( \
    CONST(uint8, ADC_CONST) u8Adc_GtmInstance, \
    CONST(uint8, ADC_CONST) u8Adc_trigregidx, \
    CONST(uint8, ADC_CONST) u8Adc_TrigRegMemberIdx, \
    CONST(uint8, ADC_CONST) u8Adc_GTM_ADC_TRIG_OUTSEL\
)
{
    GTM4.GLS[u8Adc_GtmInstance].GTMINT.GTMMCR.R &= ~0x40000000UL; /* GTM Module Enable */

    if (u8Adc_TrigRegMemberIdx < 8u)  /* TrigRegMemberIdx: 0 ~ 7 */
    {
        GTM4.GLS[u8Adc_GtmInstance].ADCTRIG[u8Adc_trigregidx].OUT0.R &= ~(uint32_t)(GTM_ADC_TRIG_OUTSEL_MASK << (u8Adc_TrigRegMemberIdx * 4u));
        GTM4.GLS[u8Adc_GtmInstance].ADCTRIG[u8Adc_trigregidx].OUT0.R |= (uint32_t)((u8Adc_GTM_ADC_TRIG_OUTSEL & GTM_ADC_TRIG_OUTSEL_MASK) << (u8Adc_TrigRegMemberIdx * 4u));
    }
    else    /* TrigRegMemberIdx: 8 ~ 11 */
    {
        GTM4.GLS[u8Adc_GtmInstance].ADCTRIG[u8Adc_trigregidx].OUT1.R &= ~(uint32_t)(GTM_ADC_TRIG_OUTSEL_MASK << ((u8Adc_TrigRegMemberIdx - 8u) * 4u));
        GTM4.GLS[u8Adc_GtmInstance].ADCTRIG[u8Adc_trigregidx].OUT1.R |= (uint32_t)((u8Adc_GTM_ADC_TRIG_OUTSEL & GTM_ADC_TRIG_OUTSEL_MASK) << ((u8Adc_TrigRegMemberIdx - 8u) * 4u));
    }
}
/*******************************************************************************
 * Static function declaration.
 *******************************************************************************/
static FUNC(void, ADC_CODE) EQADC_WriteConfigCmdSSE \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_AdcIdx, \
    CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcAddr, \
    CONST(uint16, ADC_CONST) u16Adc_AdcRegVal\
);
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_ReadConfigCmdSSE \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_AdcIdx, \
    CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcAddr, \
    CONST(uint8, ADC_CONST) u8Adc_RfifoIdx \
);
#ifndef CCFC3012PT
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_DeinitRedLineClient \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_ClientIdx \
);
#endif
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_DeinitAdcCtrl \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_AdcIdx, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
);
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_DeinitAdcTimeConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
);
static FUNC(void, ADC_CODE) EQADC_DeinitAltConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(Eqadc_AltConfigSelType, ADC_CONST) eAdc_AltCfgSel, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
);
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultCfifoCfg \
( \
    CONSTP2VAR(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr \
);
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultRwConfigCmd \
( \
    CONSTP2VAR(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr \
);
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultConvCmd \
( \
    CONSTP2VAR(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr \
);
LOCAL_INLINE FUNC(uint32, ADC_CODE) EQADC_GetCfifoRwConfigCmd \
( \
    CONSTP2CONST(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr \
);
LOCAL_INLINE FUNC(uint32, ADC_CODE) EQADC_GetCfifoConversionCmd \
( \
    CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr \
);
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetAdcConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_AdcConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AdcConfig, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
);
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetAltConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_AlternateConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AltConfig, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
);
#ifndef CCFC3012PT
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetRedLineClientConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_RedLineClientConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_PullUpDownCfg \
);
#endif
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetDmaForCmd \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr \
);
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetDmaForResult \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_ResultDmaConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_RfifoCfgPtr \
);
LOCAL_INLINE FUNC(status_t, ADC_CODE)  EQADC_LLD_ClearRfifoAllData \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx \
);
static FUNC(Eqadc_CfifoStatusType, ADC_CODE) EQADC_LLD_GetCFifoStatus \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx \
);
static FUNC(status_t, ADC_CODE)  EQADC_DeinitCfifo \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx \
);
LOCAL_INLINE FUNC(void, ADC_CODE) GTM_to_EQADC_Connections
( \
    CONST(uint8, ADC_CONST) u8Adc_GtmInstance, \
    CONST(uint8, ADC_CONST) u8Adc_trigregidx, \
    CONST(uint8, ADC_CONST) u8Adc_TrigRegMemberIdx, \
    CONST(uint8, ADC_CONST) u8Adc_GTM_ADC_TRIG_OUTSEL\
);
/*******************************************************************************
 * @brief EQADC instance base address pointer array
 *******************************************************************************/
static CONSTP2VAR(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) Adc_EqadcBase[ADC_EQADC_MAX_INSTANCE] \
    = EQADC_BASE_PTR_ARRAY;

/*******************************************************************************
 * @brief EQADC ADC Alternate Gain Registers Address Array
 *******************************************************************************/
static CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) AGRxAddr[2U] = 
{
    EQADC_ADC_REG_AGR1,
    EQADC_ADC_REG_AGR2
};

/*******************************************************************************
 * @brief EQADC ADC Alternate Offset Registers Address Array
 *******************************************************************************/
static CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) AORxAddr[2U] =
{
    EQADC_ADC_REG_AOR1,
    EQADC_ADC_REG_AOR2
};

/*******************************************************************************
 * @brief EQADC ADC Calibration Registers Address Array
 *
 * @note  Standard Configuration or alternate configurations 3 to 8:
 *                                    EQADC_CAL_STANDARD_CONFIG
 *        Alternate configurations 1: EQADC_CAL_ALT_CONFIG_1
 *        Alternate configurations 2: EQADC_CAL_ALT_CONFIG_2
 *******************************************************************************/
#define CAL_STD_CFG_IDX         (0U)
#define CAL_ALT1_CFG_IDX        (1U)
#define CAL_ALT2_CFG_IDX        (2U)
#define ADDR_SEL_CAL_GAIN       (0U)
#define ADDR_SEL_CAL_OFFSET     (1U)

/*******************************************************************************
 * @brief EQADC FIFO DMA Channel status
 *******************************************************************************/
static VAR(uint8, AUTOMATIC) DmaMappedChanForCmd[ADC_EQADC_MAX_INSTANCE][EQADC_CFIFO_COUNT] =
{
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,\
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    }
};

static VAR(uint8, AUTOMATIC) DmaMappedChanForResult[ADC_EQADC_MAX_INSTANCE][EQADC_RFIFO_COUNT] =
{
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID, \
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    },
    {
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID,
        EQADC_DMA_MAPPED_CHAN_INVALID, EQADC_DMA_MAPPED_CHAN_INVALID
    }
};

LOCAL_INLINE FUNC(uint8, ADC_CODE) EQADC_GetAltConfigIdx(VAR(Eqadc_AltConfigSelType, AUTOMATIC) eAdc_AltConfigSel)
{
    VAR(uint8, AUTOMATIC) u8Adc_AcrIdx = 0U;

    if (eAdc_AltConfigSel != EQADC_ALT_CONFIG_DISABLE)
    {
        u8Adc_AcrIdx = (uint8)((uint8)(eAdc_AltConfigSel) - (uint8)(EQADC_ALT_CONFIG_SEL_1));
        EQADC_DET_ERR(u8Adc_AcrIdx < EQADC_ALT_CONFIG_NUM); /* PRQA S 4404 */
    }

    return u8Adc_AcrIdx;
}

LOCAL_INLINE FUNC(Eqadc_AltConfigSelType, ADC_CODE) EQADC_GetAltConfigSel(VAR(uint8, AUTOMATIC) u8Adc_AcrIdx)
{
    CONST(uint8, ADC_CONST) u8Adc_AltConfigSel = (uint8)((uint8)EQADC_ALT_CONFIG_SEL_1 + u8Adc_AcrIdx);

    return (Eqadc_AltConfigSelType)u8Adc_AltConfigSel;
}

LOCAL_INLINE FUNC(Eqadc_OnChipAdcRegAddrType, ADC_CODE) EQADC_GetAltConfigRegAddr \
( \
     VAR(Eqadc_AltConfigSelType, AUTOMATIC) eAdc_AltConfigSel \
)
{
    /* EQADC ADC Alternate Configuration Control Registers Address Array */
    static CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_ACRxAddr[EQADC_ALT_CONFIG_NUM] =
    {
        EQADC_ADC_REG_ACR1,
        EQADC_ADC_REG_ACR2,
        EQADC_ADC_REG_ACR3,
        EQADC_ADC_REG_ACR4,
        EQADC_ADC_REG_ACR5,
        EQADC_ADC_REG_ACR6,
        EQADC_ADC_REG_ACR7,
        EQADC_ADC_REG_ACR8
    };
    CONST(uint8, ADC_CONST) u8Adc_AcrIdx = EQADC_GetAltConfigIdx(eAdc_AltConfigSel);

    return eAdc_ACRxAddr[u8Adc_AcrIdx];
}

FUNC(void, ADC_CODE) EQADC_CFCRx_SetCfifoxEntryExtEnDis \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(boolean, ADC_CONST) bAdc_EnDis \
)
{
    if (FALSE == bAdc_EnDis)
    {
        *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) &= ~EQADC_CFCR0_CFEEE0_MASK;
    }
    else
    {
        *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) |= EQADC_CFCR0_CFEEE0_MASK;
    }
}

void EQADC_CFCR_CfifoStreamModeEnDis \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(boolean, ADC_CONST) bAdc_EnDis \
)
{
    if (0U == bAdc_EnDis)
    {
        /* CFIFO0 Entry Number Extension Disable */
        *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) &= ~EQADC_CFCR0_STRME0_MASK;
    }
    else
    {
        /* CFIFO0 Entry Number Extension Enable */
        *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) |= EQADC_CFCR0_STRME0_MASK;
    }
}

FUNC(void, ADC_CODE) EQADC_CFCRx_SetAMode0 \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint32, ADC_CONST) u32Adc_Cfifo0AdvanceMode0 \
)
{
    *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) &= ~EQADC_CFCR0_AMODE0_MASK;
    *((EQADC_CFCR[u8Adc_Instance][0U]) + ((uint32)(u8Adc_CfifoIdx) << 1U)) \
        |= EQADC_CFCR0_AMODE0(u32Adc_Cfifo0AdvanceMode0);
}

FUNC(void, ADC_CODE) Eqadc_SetResultDmaConfig \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, \
    P2CONST(Eqadc_ResultDmaConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_ResultDmaConfig \
)
{
    EQADC_SetDmaForResult((uint8)eAdc_EqadcInst, pAdc_ResultDmaConfig);
    EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_EqadcInst, \
            (uint8)(pAdc_ResultDmaConfig->RfifoIdx), \
            EQADC_IRQDMA_REQ_SEL_RFIFODRAIN, \
            TRUE);
    EQADC_LLD_DmaEnDis(eAdc_EqadcInst, \
            (pAdc_ResultDmaConfig->RfifoIdx), \
            EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN, \
            TRUE);
}

FUNC(void, ADC_CODE) Eqadc_SetAlternateConfig \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, \
	VAR(EqadcFifoIdxType, ADC_VAR) eAdc_Cfifo_x, \
    P2CONST(Eqadc_AlternateConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AlternateConfig \
)
{
	EQADC_SetAltConfig((uint8)eAdc_EqadcInst, pAdc_AlternateConfig, (uint8)(eAdc_Cfifo_x));
	EQADC_LLD_ClearFifoIntFlag(eAdc_EqadcInst, eAdc_Cfifo_x, EQADC_FIFO_FLAG_END_OF_QUEUE);
}

FUNC(void, ADC_CODE) Eqadc_DeinitAlternateConfig \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, \
	VAR(EqadcFifoIdxType, ADC_VAR) eAdc_Cfifo_x
)
{
	uint8 u8Adc_Index =0U;
	for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ALT_CONFIG_NUM; u8Adc_Index++)
	{
		EQADC_DeinitAltConfig((uint8)eAdc_EqadcInst, EQADC_GetAltConfigSel(u8Adc_Index), (uint8)eAdc_Cfifo_x);
	}
}

FUNC(void, ADC_CODE) Eqadc_LLD_Init \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_EqadcInst, \
    CONSTP2CONST(Adc_EqadcConfigType, ADC_CONST, ADC_APPL_CONST) sAdc_ConfigPtr \
)
{
    EQADC_DET_ERR(sAdc_ConfigPtr != NULL); /* PRQA S 4404 */
    EQADC_DET_ERR(sAdc_ConfigPtr->EqadcHwInst != NULL); /* PRQA S 4404 */

    EQADC_DET_ERR((uint8)eAdc_EqadcInst < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    VAR(uint8, AUTOMATIC) u8Adc_Index;
    VAR(status_t, AUTOMATIC) eAdc_status;

    EQADC_MCR_SetDebugEnDis((uint8)eAdc_EqadcInst, sAdc_ConfigPtr->EqadcHwInst->DebugModeEn);
    EQADC_ETDFR_SetDFL((uint8)eAdc_EqadcInst, sAdc_ConfigPtr->EqadcHwInst->ExtTrigDigitalFilterLen);

    VAR(Eqadc_CfifoConfigType, AUTOMATIC) sAdc_CfifoIdxInitCfgCmd;
    EQADC_GetDefaultCfifoCfg(&sAdc_CfifoIdxInitCfgCmd);
    sAdc_CfifoIdxInitCfgCmd.CfifoIdx     = EQADC_CFG_CMD_CFIFO_IDX;
    sAdc_CfifoIdxInitCfgCmd.CfifoMode    = EQADC_CFIFO_MODE_SINGLE_SW_TRIG;

    eAdc_status = EQADC_SetCfifoConfig((uint8)eAdc_EqadcInst, &sAdc_CfifoIdxInitCfgCmd);
    if(eAdc_status == STATUS_TIMEOUT)
    {
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        Adc_DemReportErrorStatus(DME_EVENTID_INIT, DEM_EVENT_TIMEOUT);
#endif
    }

    /* Init ADC_TSCR */
    EQADC_WriteConfigCmdSSE((uint8)eAdc_EqadcInst, \
                            (uint8)sAdc_CfifoIdxInitCfgCmd.CfifoIdx, \
                            (uint8)EQADC_ADC_0, \
                            EQADC_ADC_REG_TSCR, \
                            EQADC_ADC_TSCR_TBC_CLK_PS(sAdc_ConfigPtr->EqadcHwInst->TimeBasePresDiv)); /* PRQA S 2985 */

    EQADC_DET_ERR(((sAdc_ConfigPtr->AdcConfigNum > 0U) && \
                   (sAdc_ConfigPtr->AdcConfigNum <= EQADC_ADC_NUM)) && /* PRQA S 4404 */ \
                  (sAdc_ConfigPtr->AdcConfigArray != (void *)NULL) \
                 );
#if EQADC_DET_SUPPORT
    VAR(uint8, AUTOMATIC) u8Adc_AdcIdx[EQADC_ADC_NUM] = {0U};
    VAR(uint8, AUTOMATIC) u8Adc_AdcExtMuxEnNum = 0u;
    for (u8Adc_Index = 0U; u8Adc_Index < sAdc_ConfigPtr->AdcConfigNum; u8Adc_Index++)
    {
        u8Adc_AdcIdx[u8Adc_Index] = (uint8)(sAdc_ConfigPtr->AdcConfigArray[u8Adc_Index].AdcIdx);
        u8Adc_AdcExtMuxEnNum = (uint8)(u8Adc_AdcExtMuxEnNum + ((sAdc_ConfigPtr->AdcConfigArray[u8Adc_Index].AdcExtMuxEn == TRUE) ? 1U : 0U));
    }
    if (sAdc_ConfigPtr->AdcConfigNum == EQADC_ADC_NUM)
    {
        EQADC_DET_ERR(u8Adc_AdcIdx[0U] != u8Adc_AdcIdx[1U]); /* PRQA S 4404 */
        (void)u8Adc_AdcIdx[u8Adc_Index];
    }
    /* Note: Both ADC0/1_EMUX bits must not be asserted at the same time. */
    EQADC_DET_ERR(u8Adc_AdcExtMuxEnNum <= 1U); /* PRQA S 4404 */
#endif

    for (u8Adc_Index = 0U; u8Adc_Index < sAdc_ConfigPtr->AdcConfigNum; u8Adc_Index++)
    {
        EQADC_SetAdcConfig \
        ( \
        (uint8)eAdc_EqadcInst, \
        &(sAdc_ConfigPtr->AdcConfigArray[u8Adc_Index]), \
        (uint8)(sAdc_CfifoIdxInitCfgCmd.CfifoIdx) \
        );
    }
#ifndef CCFC3012PT
    if (sAdc_ConfigPtr->RedLineClientConfigNum > 0U)
    {
        EQADC_DET_ERR(sAdc_ConfigPtr->RedLineClientConfigNum <= EQADC_RED_LINE_CLIENT_NUM); /* PRQA S 4404 */
        EQADC_DET_ERR(sAdc_ConfigPtr->RedLineClientConfigArray != NULL); /* PRQA S 4404 */
        for (u8Adc_Index = 0U; u8Adc_Index < sAdc_ConfigPtr->RedLineClientConfigNum; u8Adc_Index++)
        {
            EQADC_SetRedLineClientConfig \
            ( \
                (uint8)eAdc_EqadcInst, \
                &(sAdc_ConfigPtr->RedLineClientConfigArray[u8Adc_Index]) \
            );
        }
    }
#endif
    VAR(uint32, AUTOMATIC) u32FifoFlagMask;
    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
        u32FifoFlagMask = EQADC_FIFO_FLAG_ALL & ~EQADC_FIFO_FLAG_CFIFO_FILL;

        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_EqadcInst, u8Adc_Index) & EQADC_IRQDMA_REQ_SEL_CFIFOFILL) \
            != 0U)
        {
            u32FifoFlagMask &= ~EQADC_FIFO_FLAG_CFIFO_FILL; /* PRQA S 2984 */
        }

        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_EqadcInst, u8Adc_Index) & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) \
            != 0U)
        {
            u32FifoFlagMask &= ~EQADC_FIFO_FLAG_RFIFO_DRAIN; /* PRQA S 2984 */
        }

        EQADC_LLD_ClearFifoIntFlag(eAdc_EqadcInst, (EqadcFifoIdxType)u8Adc_Index, u32FifoFlagMask);
    }

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
        EQADC_CFTCRx_SetCfifoTransCount((uint8)eAdc_EqadcInst, u8Adc_Index, 0U);
    }
}

FUNC(void, ADC_CODE) Adc_Eqadc_LLD_DeInit(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) eAdc_status;
    VAR(uint8, AUTOMATIC) u8Adc_Index;
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfgCmdCfifoIdx = EQADC_FIFO_0;

    eAdc_status = EQADC_DeinitCfifo((uint8)eAdc_Instance, (uint8)eAdc_CfgCmdCfifoIdx);
    if(eAdc_status == STATUS_TIMEOUT)
    {
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        Adc_DemReportErrorStatus(DEM_EVENTID_DEINIT, DEM_EVENT_TIMEOUT);
#endif
    }

    VAR(Eqadc_CfifoConfigType, AUTOMATIC) sAdc_CfifoIdxInitCfgCmd;
    EQADC_GetDefaultCfifoCfg(&sAdc_CfifoIdxInitCfgCmd);
    sAdc_CfifoIdxInitCfgCmd.CfifoIdx     = eAdc_CfgCmdCfifoIdx;
    sAdc_CfifoIdxInitCfgCmd.CfifoMode    = EQADC_CFIFO_MODE_SINGLE_SW_TRIG;
    eAdc_status = EQADC_SetCfifoConfig((uint8)eAdc_Instance, &sAdc_CfifoIdxInitCfgCmd);
    EQADC_DET_ERR(eAdc_status == STATUS_SUCCESS); /* PRQA S 4404 */

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ADC_NUM; u8Adc_Index++)
    {
        EQADC_DeinitAdcCtrl((uint8)eAdc_Instance, u8Adc_Index, (uint8)eAdc_CfgCmdCfifoIdx);
    }

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_RFIFO_COUNT; u8Adc_Index++)
    {
        /* Stop eDMA channel */
        if (DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Index] != EQADC_DMA_MAPPED_CHAN_INVALID)
        {
            (void) EDMA_ClearChannelRequest(DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Index]);
            DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Index] = EQADC_DMA_MAPPED_CHAN_INVALID;
        }

        /* reset EQADC RFIFO interrupts and DMA select */
        EQADC_IDCRx_FifoIntDmaEnDis \
        ( \
            (uint8)eAdc_Instance, \
            u8Adc_Index, \
            (uint16)EQADC_IRQDMA_REQ_SEL_RFIFODRAIN, \
            FALSE \
        );
        /* reset EQADC RFIFO interrupts and DMA enable */
        EQADC_IDCRx_FifoIntDmaEnDis \
        ( \
            (uint8)eAdc_Instance, \
            u8Adc_Index, \
            (uint16)(EQADC_IRQ_EN_RFIFO_OVERFLOW|EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN), \
            FALSE \
        );

        /* Clear data for all RFIFO entries */
        eAdc_status = EQADC_LLD_ClearRfifoAllData(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index);
        if(eAdc_status == STATUS_TIMEOUT)
        {
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
            Adc_DemReportErrorStatus(DEM_EVENTID_DEINIT, DEM_EVENT_TIMEOUT);
#endif
        }
        else
        {
            EQADC_DET_ERR(eAdc_status == STATUS_SUCCESS); /* PRQA S 4404 */
        }
    }

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ALT_CONFIG_NUM; u8Adc_Index++)
    {
        EQADC_DeinitAltConfig((uint8)eAdc_Instance, EQADC_GetAltConfigSel(u8Adc_Index), (uint8)eAdc_CfgCmdCfifoIdx);
    }
#ifndef CCFC3012PT
    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_RED_LINE_CLIENT_NUM; u8Adc_Index++)
    {
        EQADC_DeinitRedLineClient((uint8)eAdc_Instance, u8Adc_Index);
    }
#endif
    EQADC_DeinitAdcTimeConfig((uint8)eAdc_Instance, (uint8)eAdc_CfgCmdCfifoIdx);

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
        eAdc_status = EQADC_DeinitCfifo((uint8)eAdc_Instance, u8Adc_Index);
        if(eAdc_status == STATUS_TIMEOUT)
        {
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
            Adc_DemReportErrorStatus(DEM_EVENTID_DEINIT, DEM_EVENT_TIMEOUT);
#endif
        }
    }

    CONST(uint32, ADC_CONST) u32Adc_FifoFlag = (EQADC_FIFO_FLAG_ALL) & (~EQADC_FIFO_FLAG_CFIFO_FILL);
    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
        EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Index, u32Adc_FifoFlag);
    }

    for (u8Adc_Index = 0U; u8Adc_Index < EQADC_CFIFO_COUNT; u8Adc_Index++)
    {
        EQADC_CFTCRx_SetCfifoTransCount((uint8)eAdc_Instance, u8Adc_Index, 0U);
    }
}

static  FUNC(uint64, ADC_CODE)  EQADC_GetGcc \
( \
    VAR(uint16, AUTOMATIC) u16Adc_RAW_RES_75P_Vref, \
    VAR(uint16, AUTOMATIC) u16Adc_RAW_RES_25P_Vref \
)
{
    /* GCC: (CAL_RES75%VREF - CAL_RES25%VREF) / (RAW_RES75%VREF - RAW_RES25%VREF); */
    CONST(uint64, ADC_CONST) u64Adc_ExpectedDiffNum_Div14 \
        = (EQADC_PCT75_VREF_CAL_RES - EQADC_PCT25_VREF_CAL_RES) << EQADC_ADC_GCC_FRAC_WIDTH;
    CONST(uint64, ADC_CONST) u64Adc_MeasuredDiffNum_Div14 \
        = ((uint64_t)u16Adc_RAW_RES_75P_Vref - (uint64_t)u16Adc_RAW_RES_25P_Vref) << EQADC_ADC_GCC_FRAC_WIDTH;
    CONST(uint64, ADC_CONST) u64Adc_ExpectedDiffNum_Div28 \
        = u64Adc_ExpectedDiffNum_Div14 << EQADC_ADC_GCC_FRAC_WIDTH; /* PRQA S 2984 */
    CONST(uint64, ADC_CONST) u64Adc_Gcc \
        = (u64Adc_ExpectedDiffNum_Div28 + (u64Adc_MeasuredDiffNum_Div14 >> 1U)) / u64Adc_MeasuredDiffNum_Div14;

    return u64Adc_Gcc;
}

#if (EQADC_ADC_OCC_FORM == EQADC_ADC_OCC_FORM1)
static FUNC(sint16, ADC_CODE) EQADC_GetOcc \
( \
    VAR(uint64, AUTOMATIC) u64Adc_GainConvCount, \
    VAR(uint16, AUTOMATIC) u16Adc_RAW_RES_75P_Vref \
)
{
    /* OCC: CAL_RES75%VREF - GCC * RAW_RES75%VREF - 2; */
    CONST(uint64, ADC_CONST) u64Adc_ExpectedValue_Div14 \
        = (EQADC_PCT75_VREF_CAL_RES - 2U) << EQADC_ADC_GCC_FRAC_WIDTH;
    CONST(sint64, ADC_CONST) s64Adc_sign64Occ_Div14 \
        = (sint64)(u64Adc_ExpectedValue_Div14 - (u64Adc_GainConvCount * ((uint64)u16Adc_RAW_RES_75P_Vref))); /* PRQA S 4446 */
    CONST(sint16, ADC_CONST) s16Adc_sign16_Occ \
        = (sint16)(s64Adc_sign64Occ_Div14 >> EQADC_ADC_GCC_FRAC_WIDTH); /* PRQA S 4533 */

    return s16Adc_sign16_Occ;
}
#else
static FUNC(sint16, ADC_CODE) EQADC_GetOcc \
( \
    VAR(uint64, AUTOMATIC) u64Adc_GainConvCount, \
    VAR(uint16, AUTOMATIC) u16Adc_RAW_RES_25P_Vref \
)
{
    /* OCC: CAL_RES25%VREF - GCC * RAW_RES25%VREF - 2; */
    CONST(uint64, ADC_CONST) u64Adc_ExpectedValue_Div14 \
        = (EQADC_PCT25_VREF_CAL_RES - 2U) << EQADC_ADC_GCC_FRAC_WIDTH;
    CONST(sint64, ADC_CONST) s64Adc_sign64Occ_Div14 \
            = u64Adc_ExpectedValue_Div14 - (u64Adc_GainConvCount * ((uint64)u16Adc_RAW_RES_75P_Vref)); /* PRQA S 4446 */
	CONST(sint16, ADC_CONST) s16Adc_sign16_Occ \
		= (sint16)(s64Adc_sign64Occ_Div14 >> EQADC_ADC_GCC_FRAC_WIDTH); /* PRQA S 4533 */

    return s16Adc_sign16_Occ;
}
#endif

FUNC(void, ADC_CODE) EQADC_LLD_InternalFuncEn(void)
{
    SSCM_VRC33_ENABLE |= (EQADC_PCT_VREF_EN_MSAK | EQADC_TSENS_EN_MSAK);
}

FUNC(status_t, ADC_CODE)  EQADC_LLD_CalibConvResult \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcAdcIdxType, ADC_CONST) eAdc_AdcIdx, \
    CONSTP2VAR(Eqadc_CalibConfigInfoType, ADC_CONST, ADC_APPL_CONST) pAdc_CalCfgPtr \
)/* PRQA S 2755 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_CalCfgPtr != NULL); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) eAdc_CalStatus = STATUS_SUCCESS;
    CONST(uint8, ADC_CONST) u8Adc_Cfifo_x = (uint8)(pAdc_CalCfgPtr->CfifoIdx);
    CONST(uint8, ADC_CONST) u8Adc_Rfifo_x = (uint8)(pAdc_CalCfgPtr->RfifoIdx);
    VAR(uint32, AUTOMATIC) u32Adc_TimeoutCal, u32Adc_FifoStatusTimeout;
    VAR(uint16, AUTOMATIC) u16Adc_RawResultPct25Vref, u16Adc_RawResultPct75Vref;    /* RAW_RES: measured result values */
    VAR(uint8, AUTOMATIC) u8Adc_CalibCfgSelIdx = 0U;

    EQADC_DET_ERR(u8Adc_Cfifo_x < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_Rfifo_x < EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    static CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) CalibAddr[3U][2U] =
    {
        {EQADC_ADC_REG_GCCR, EQADC_ADC_REG_OCCR},
        {EQADC_ADC_REG_AGR1, EQADC_ADC_REG_AOR1},
        {EQADC_ADC_REG_AGR2, EQADC_ADC_REG_AOR2}
    };

    switch (pAdc_CalCfgPtr->CalibCfgSel)
    {
        case EQADC_CAL_STANDARD_CONFIG:
        {
            u8Adc_CalibCfgSelIdx = CAL_STD_CFG_IDX;
            break;
        }
        case EQADC_CAL_ALT_CONFIG_1:
        {
            u8Adc_CalibCfgSelIdx = CAL_ALT1_CFG_IDX;
            break;
        }
        case EQADC_CAL_ALT_CONFIG_2:
        {
            u8Adc_CalibCfgSelIdx = CAL_ALT2_CFG_IDX;
            break;
        }
        default:
        {
            EQADC_DET_ERR(FALSE);
            break;
        }
    }
    /* Save Current status */
    /** Save Current RFIFO Drain request control **/
    CONST(uint16, ADC_CONST) u16Adc_IntDmaCtrl_RfifoDrain \
        = EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, u8Adc_Rfifo_x);

    if ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) != 0U)
    {
        EQADC_IDCRx_FifoIntDmaEnDis \
        ( \
            (uint8)eAdc_Instance, \
            u8Adc_Rfifo_x, \
            EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN, \
            FALSE \
        );
    }

    if ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) != (uint16)EQADC_FILL_SEL_INT)
    {
        /* Stop eDMA mapped channel */
        if (DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Rfifo_x] != EQADC_DMA_MAPPED_CHAN_INVALID)
        {
            (void) EDMA_ClearChannelRequest(DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Rfifo_x]);
        }

        EQADC_IDCRx_FifoIntDmaEnDis \
        ( \
            (uint8)eAdc_Instance, \
            u8Adc_Rfifo_x, \
            EQADC_IRQDMA_REQ_SEL_RFIFODRAIN, \
            FALSE \
        );
    }

    /** Save Current Mode **/
    CONST(uint32, ADC_CONST) u8Adc_CurrentCfifoMode \
        = EQADC_CFCRxGetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x);
    if (u8Adc_CurrentCfifoMode != (uint32)EQADC_CFIFO_MODE_SINGLE_SW_TRIG)
    {
        u32Adc_FifoStatusTimeout = EQADC_TIMEOUT_COUNT;
        /* set CFIFO mode disabled first */
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x, (uint32)EQADC_CFIFO_MODE_DISABLE);
        while ((EQADC_LLD_GetCFifoStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x) \
                != EQADC_CFIFO_STATUS_IDLE)&& (u32Adc_FifoStatusTimeout > 0UL))
        {
            u32Adc_FifoStatusTimeout--;
        }
        if (0UL == u32Adc_FifoStatusTimeout)
        {
            eAdc_CalStatus =  STATUS_TIMEOUT;
        }
        /* invalidate CFIFO all entries */
        EQADC_CFCRxSetInvalidate((uint8)eAdc_Instance, u8Adc_Cfifo_x);
        /* set target CFIFO mode */
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x, (uint32)EQADC_CFIFO_MODE_SINGLE_SW_TRIG);
    }

    u32Adc_TimeoutCal = pAdc_CalCfgPtr->TimeoutCal;
    while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x, EQADC_FISR_RFIFO_ENTRY_COUNT) != 0U) \
            && (u32Adc_TimeoutCal > 0UL))
    {
        (void) EQADC_LLD_RfifoPopData(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x);
        u32Adc_TimeoutCal--;
    }

    if (u32Adc_TimeoutCal > 0UL)
    {
        EQADC_LLD_ClearFifoIntFlag \
        ( \
            eAdc_Instance, \
            (EqadcFifoIdxType)u8Adc_Rfifo_x, \
            EQADC_FIFO_FLAG_RFIFO_DRAIN \
        );

        Eqadc_ConvCmdType ConvCmd;
        EQADC_GetDefaultConvCmd(&ConvCmd);
        ConvCmd.cBufNum         = (uint8)eAdc_AdcIdx;
        ConvCmd.RfifoMsgTag     = (EqadcFifoIdxType)u8Adc_Rfifo_x;
        ConvCmd.LongSampTime    = pAdc_CalCfgPtr->LongSampTime;
        ConvCmd.ChanNum         = EQADC_CH_VDD_PCT25_VREF;
        ConvCmd.AltConfigSel    = (Eqadc_AltConfigSelType)((uint8)(pAdc_CalCfgPtr->CalibCfgSel));
        EQADC_LLD_CfifoPushConvCmd(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x, &ConvCmd);
        EQADC_LLD_SingleScanEn(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x);

        u32Adc_TimeoutCal = pAdc_CalCfgPtr->TimeoutCal;
        while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x, EQADC_FISR_RFIFO_DRAIN) != 1U) \
                && (u32Adc_TimeoutCal > 0UL))
        {
            u32Adc_TimeoutCal--;
        }

        if (u32Adc_TimeoutCal > 0UL)
        {
            u16Adc_RawResultPct25Vref = EQADC_LLD_RfifoPopData(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x);
            EQADC_LLD_ClearFifoIntFlag \
            ( \
            eAdc_Instance, \
            (EqadcFifoIdxType)u8Adc_Rfifo_x, \
            EQADC_FIFO_FLAG_RFIFO_DRAIN \
            );
            EQADC_LLD_ClearFifoIntFlag \
            ( \
            eAdc_Instance, \
            (EqadcFifoIdxType)u8Adc_Cfifo_x, \
            EQADC_FIFO_FLAG_END_OF_QUEUE \
            );

            ConvCmd.ChanNum     = EQADC_CH_VDD_PCT75_VREF;
            EQADC_LLD_CfifoPushConvCmd(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x, &ConvCmd);
            EQADC_LLD_SingleScanEn(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x);

            u32Adc_TimeoutCal = pAdc_CalCfgPtr->TimeoutCal;
            while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x, EQADC_FISR_RFIFO_DRAIN) != 1U) \
                    && (u32Adc_TimeoutCal > 0UL))
            {
                u32Adc_TimeoutCal--;
            }

            if (u32Adc_TimeoutCal > 0UL)
            {
                u16Adc_RawResultPct75Vref = EQADC_LLD_RfifoPopData(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Rfifo_x);
                EQADC_LLD_ClearFifoIntFlag \
                ( \
                    eAdc_Instance, \
                    (EqadcFifoIdxType)u8Adc_Rfifo_x, \
                    EQADC_FIFO_FLAG_RFIFO_DRAIN \
                );
                EQADC_LLD_ClearFifoIntFlag \
                ( \
                    eAdc_Instance, \
                    (EqadcFifoIdxType)u8Adc_Cfifo_x, \
                    EQADC_FIFO_FLAG_END_OF_QUEUE \
                );

                CONST(uint64, ADC_CONST) Gcc_Div14 \
                    = EQADC_GetGcc(u16Adc_RawResultPct75Vref, u16Adc_RawResultPct25Vref);
                VAR(uint16, AUTOMATIC) GainConvCount = (uint16) Gcc_Div14;
                if (Gcc_Div14 > EQADC_ADC_GCCR_GCC_MASK)
                {
                    GainConvCount = EQADC_ADC_GCCR_GCC_MASK;
                    eAdc_CalStatus = STATUS_ERROR;
                }

#if (EQADC_ADC_OCC_FORM == EQADC_ADC_OCC_FORM1)
                CONST(sint16, ADC_CONST) OffsetConvCount \
                    = EQADC_GetOcc(Gcc_Div14, u16Adc_RawResultPct75Vref);
#else
                CONST(sint16, ADC_CONST) OffsetConvCount \
                    = EQADC_GetOcc(Gcc_Div14, u16Adc_RawResultPct25Vref);
#endif

                pAdc_CalCfgPtr->GainCalibConst   = GainConvCount;
                pAdc_CalCfgPtr->OffsetCalibConst = OffsetConvCount;

                EQADC_WriteConfigCmdSSE \
                ( \
                    (uint8)eAdc_Instance, \
					u8Adc_Cfifo_x, \
                    (uint8)eAdc_AdcIdx, \
                    CalibAddr[u8Adc_CalibCfgSelIdx][ADDR_SEL_CAL_GAIN], \
                    GainConvCount \
                );
                EQADC_WriteConfigCmdSSE \
                ( \
                    (uint8)eAdc_Instance, \
					u8Adc_Cfifo_x, \
                    (uint8)eAdc_AdcIdx, \
                    CalibAddr[u8Adc_CalibCfgSelIdx][ADDR_SEL_CAL_OFFSET], \
                    (uint16)OffsetConvCount \
                );

                EQADC_LLD_ClearFifoIntFlag \
                ( \
                    eAdc_Instance, \
                    (EqadcFifoIdxType)u8Adc_Cfifo_x, \
                    EQADC_FIFO_FLAG_END_OF_QUEUE \
                );

                EQADC_CFTCRx_SetCfifoTransCount((uint8)eAdc_Instance, u8Adc_Cfifo_x, 0U);
            }
            else
            {
                eAdc_CalStatus = STATUS_TIMEOUT;
            }
        }
        else
        {
            eAdc_CalStatus = STATUS_TIMEOUT;
        }
    }
    else
    {
        eAdc_CalStatus = STATUS_TIMEOUT;
    }

    /* Restore previous mode */
    if (u8Adc_CurrentCfifoMode != (uint32)EQADC_CFIFO_MODE_SINGLE_SW_TRIG)
    {
        u32Adc_FifoStatusTimeout = EQADC_TIMEOUT_COUNT;
        /* set CFIFO mode disabled first */
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x, (uint32)EQADC_CFIFO_MODE_DISABLE);
        while ((EQADC_LLD_GetCFifoStatus(eAdc_Instance, (EqadcFifoIdxType)u8Adc_Cfifo_x) != EQADC_CFIFO_STATUS_IDLE) \
            && (u32Adc_FifoStatusTimeout > 0UL))
        {
            u32Adc_FifoStatusTimeout--;
        }
        if (0UL == u32Adc_FifoStatusTimeout)
        {
            eAdc_CalStatus = STATUS_TIMEOUT;
        }

        /* set target CFIFO mode */
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, u8Adc_Cfifo_x, u8Adc_CurrentCfifoMode);
    }

    if ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) != (uint16)EQADC_FILL_SEL_INT)
    {
        /* start eDMA mapped channel */
        (void) EDMA_SetChannelRequest(DmaMappedChanForResult[((uint8)eAdc_Instance)][u8Adc_Rfifo_x]);

        EQADC_IDCRx_FifoIntDmaEnDis \
        ( \
            (uint8)eAdc_Instance, \
            u8Adc_Rfifo_x, \
            EQADC_IRQDMA_REQ_SEL_RFIFODRAIN, \
            TRUE \
        );
    }

    if ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) != 0U)
    {
        EQADC_IDCRx_FifoIntDmaEnDis \
        ( \
            (uint8)eAdc_Instance, \
            u8Adc_Rfifo_x, \
            EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN, \
            TRUE \
        );
    }

    return eAdc_CalStatus;
}

static FUNC(void, ADC_CODE) EQADC_LLD_SetImmediateConvCmdEnDis \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx, \
    CONST(boolean, ADC_CONST) bAdc_EnDis \
)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */

    EQADC_MCR_SetICEAxEnDis((uint8)eAdc_Instance, (uint8) eAdc_AdcIdx, bAdc_EnDis);
}

FUNC(uint8, ADC_CODE) EQADC_LLD_GetDebugEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return EQADC_MCR_GetDebugEnDis((uint8)eAdc_Instance);
}

FUNC(void, ADC_CODE) EQADC_LLD_SetDebugEnDis \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(boolean, ADC_CONST) bAdc_EnDis \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    EQADC_MCR_SetDebugEnDis((uint8)eAdc_Instance, bAdc_EnDis);
}

FUNC(uint8, ADC_CODE) EQADC_LLD_GetExtTrigDigitalFilterLength(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return EQADC_ETDFR_GetDFL((uint8)eAdc_Instance);
}

FUNC(void, ADC_CODE) EQADC_LLD_SetExtTrigDigitalFilterLength \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_DigitalFilterLen \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_DigitalFilterLen <= EQADC_ETDFR_DFL_MASK); /* PRQA S 4404 */

    EQADC_ETDFR_SetDFL((uint8)eAdc_Instance, u8Adc_DigitalFilterLen);
}

static FUNC(void, ADC_CODE) EQADC_LLD_CfifoPushConfigCmd \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, \
    CONSTP2CONST(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr \
)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_ConfigCmdPtr != NULL); /* PRQA S 4404 */

    *(EQADC_CFPR[(uint8)eAdc_Instance][(uint8)eAdc_CfifoIdx]) = EQADC_GetCfifoRwConfigCmd(pAdc_ConfigCmdPtr);
}

FUNC(void, ADC_CODE) EQADC_LLD_SetCQueueConfigCmd \
( \
    CONSTP2CONST(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr, \
    CONST(uint8, ADC_CONST) u8Adc_CmdCount, \
    CONSTP2VAR(uint32, ADC_CONST, ADC_APPL_CONST) pAdc_CQueueMemDest \
)
{
    EQADC_DET_ERR(pAdc_ConfigCmdPtr != NULL); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_CQueueMemDest != NULL); /* PRQA S 4404 */

    VAR(uint8, AUTOMATIC)u8Adc_Index;

    for (u8Adc_Index = 0U; u8Adc_Index < u8Adc_CmdCount; u8Adc_Index++)
    {
        pAdc_CQueueMemDest[u8Adc_Index] = EQADC_GetCfifoRwConfigCmd(&(pAdc_ConfigCmdPtr[u8Adc_Index]));
    }
}

FUNC(void, ADC_CODE) EQADC_LLD_CfifoPushConvCmd \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx,  \
    CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_ConvCmdPtr != NULL); /* PRQA S 4404 */

    CONSTP2VAR(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr = Adc_EqadcBase[(uint8)eAdc_Instance];

    pAdc_BasePtr->CFPR[(uint8)eAdc_CfifoIdx].R = EQADC_GetCfifoConversionCmd(pAdc_ConvCmdPtr);
}

FUNC(void, ADC_CODE) EQADC_LLD_SetCQueueConvCmd \
( \
    CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr, \
    CONST(uint8, ADC_CONST) u8Adc_CmdCount, \
	CONST(uint8, ADC_CONST) u8Adc_StreamNumSamp, \
    CONST(uint8, ADC_CONST) u8Adc_DmaSampleNum, \
    CONSTP2VAR(uint32, ADC_CONST, ADC_APPL_CONST) pAdc_CQueueMemDest \
)
{
    EQADC_DET_ERR(pAdc_ConvCmdPtr != NULL); /* PRQA S 4404 */
    EQADC_DET_ERR(pAdc_CQueueMemDest != NULL); /* PRQA S 4404 */

    VAR(uint8, AUTOMATIC) u8Adc_Index;
    VAR(uint8, AUTOMATIC) u8Adc_TempIndex = 0U;
    VAR(uint8, AUTOMATIC) u8Adc_TempStreamNumSamp = 0U;
    VAR(Eqadc_ConvCmdType, ADC_VAR) sAdc_TempConvCmd;
    for (u8Adc_Index = 0U; u8Adc_Index < u8Adc_CmdCount; u8Adc_Index++)
    {
        if((u8Adc_StreamNumSamp == 1U) && (u8Adc_DmaSampleNum != 1U))
        {
            if(u8Adc_TempStreamNumSamp >= (u8Adc_CmdCount / u8Adc_DmaSampleNum))
            {
                u8Adc_TempIndex = 0U;
                u8Adc_TempStreamNumSamp = 0U;
            }
            sAdc_TempConvCmd = pAdc_ConvCmdPtr[u8Adc_TempIndex];
            pAdc_CQueueMemDest[u8Adc_Index] = EQADC_GetCfifoConversionCmd(&sAdc_TempConvCmd);
            u8Adc_TempStreamNumSamp++;
            u8Adc_TempIndex++;
        }
        else
        {
            if(u8Adc_TempStreamNumSamp >= u8Adc_StreamNumSamp)
            {
                u8Adc_TempIndex = (uint8)(u8Adc_TempIndex + 1U);
                u8Adc_TempStreamNumSamp = 0U;
            }

            sAdc_TempConvCmd = pAdc_ConvCmdPtr[u8Adc_TempIndex];

            if(u8Adc_StreamNumSamp > 0U)
            {
                if((sAdc_TempConvCmd.Eoq == TRUE) && \
                    (((u8Adc_Index + 1U) % (u8Adc_StreamNumSamp)) != 0U))
                {
                    sAdc_TempConvCmd.Eoq = FALSE;
                }
            }

            pAdc_CQueueMemDest[u8Adc_Index] = EQADC_GetCfifoConversionCmd(&sAdc_TempConvCmd);
            u8Adc_TempStreamNumSamp++;
        }
    }
}

FUNC(uint16, ADC_CODE) EQADC_LLD_RfifoPopData \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx \
)
{
    EQADC_DET_ERR((uint8) eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_RfifoIdx < EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) uAdc_PopData;

    uAdc_PopData \
        = (uint16)((*(EQADC_RFPR[(uint8)eAdc_Instance][(uint8)eAdc_RfifoIdx])) & EQADC_RFPR_RF_POPX_MASK);

    return uAdc_PopData;
}

LOCAL_INLINE FUNC(status_t, ADC_CODE)  EQADC_LLD_ClearRfifoAllData \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx \
)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8) eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_RfifoIdx < EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) eAdc_ret = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Adc_RfifoEntryCount;
    VAR(uint32, AUTOMATIC) u32Adc_TimeoutClear = EQADC_TIMEOUT_COUNT;

    /* Save Current RFIFO Drain request control */
    CONST(uint16, ADC_CONST) u16Adc_IntDmaCtrl_RfifoDrain \
        = EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_RfifoIdx);

    if (((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) == 0U) && \
       ((u16Adc_IntDmaCtrl_RfifoDrain & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) == (uint16)EQADC_FILL_SEL_INT))
    {
        u8Adc_RfifoEntryCount \
            = EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, eAdc_RfifoIdx, EQADC_FISR_RFIFO_ENTRY_COUNT);

        while ((u8Adc_RfifoEntryCount != 0U) && (u32Adc_TimeoutClear > 0UL))
        {
            (void) EQADC_LLD_RfifoPopData(eAdc_Instance, eAdc_RfifoIdx); /* Clear Result data */

            u8Adc_RfifoEntryCount \
                = EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, eAdc_RfifoIdx, EQADC_FISR_RFIFO_ENTRY_COUNT);

            u32Adc_TimeoutClear--;
        }

        if (u32Adc_TimeoutClear == 0UL)
        {
            eAdc_ret = STATUS_TIMEOUT;
        }
        else
        {
            EQADC_LLD_ClearFifoIntFlag \
            ( \
                eAdc_Instance, \
                eAdc_RfifoIdx, \
                (EQADC_FIFO_FLAG_RFIFO_OVERFLOW | EQADC_FIFO_FLAG_RFIFO_DRAIN) \
            );
        }
    }
    else
    {
        eAdc_ret = STATUS_ERROR;
    }

    return eAdc_ret;
}

FUNC(void, ADC_CODE) EQADC_LLD_SingleScanEn \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    CONSTP2VAR(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr = Adc_EqadcBase[(uint8)eAdc_Instance];
    CONST(uint8, ADC_CONST) u8Adc_Cfifo_x = (uint8)eAdc_CfifoIdx;
    if (u8Adc_Cfifo_x < (uint8)EQADC_FIFO_2)
    {
        pAdc_BasePtr->CFCR0.R |= (((u8Adc_Cfifo_x % 2U) == 0U) ? EQADC_CFCR0_SSE0_MASK : EQADC_CFCR0_SSE1_MASK);
    }
    else if (u8Adc_Cfifo_x < (uint8)EQADC_FIFO_4)
    {
        pAdc_BasePtr->CFCR1.R |= (((u8Adc_Cfifo_x % 2U) == 0U) ? EQADC_CFCR1_SSE2_MASK : EQADC_CFCR1_SSE3_MASK);
    }
    else
    {
        pAdc_BasePtr->CFCR2.R |= (((u8Adc_Cfifo_x % 2U) == 0U) ? EQADC_CFCR2_SSE4_MASK : EQADC_CFCR2_SSE5_MASK);
    }
}

FUNC(void, ADC_CODE) EQADC_LLD_SingleScanEn_Sync \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    /* EQADC CfifoIdx synchronous: 0 & 1, 2 & 3, 4 & 5 */
    EQADC_CFCRxSetSSE_Sync((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
}

FUNC(status_t, ADC_CODE)  EQADC_LLD_SetCfifoInvalidate \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) eAdc_ret = STATUS_SUCCESS;
    VAR(Eqadc_CfifoModeType, AUTOMATIC) eAdc_CfifoModeCurrent;
    VAR(Eqadc_CfifoStatusType, AUTOMATIC) eAdc_CfifoStatusCurrent;

    eAdc_CfifoModeCurrent = (Eqadc_CfifoModeType)EQADC_CFCRxGetMode((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
    eAdc_CfifoStatusCurrent = EQADC_LLD_GetCFifoStatus(eAdc_Instance, eAdc_CfifoIdx);

    if ((eAdc_CfifoModeCurrent == EQADC_CFIFO_MODE_DISABLE) \
        && (eAdc_CfifoStatusCurrent == EQADC_CFIFO_STATUS_IDLE))
    {
        EQADC_CFCRxSetInvalidate((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
    }
    else
    {
        eAdc_ret = STATUS_ERROR;
    }

    return eAdc_ret;
}

FUNC(Eqadc_CfifoModeType, ADC_CODE) EQADC_LLD_GetCfifoMode \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(Eqadc_CfifoModeType, AUTOMATIC) eAdc_CfifoModeCurrent;

    eAdc_CfifoModeCurrent = (Eqadc_CfifoModeType)EQADC_CFCRxGetMode((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);

    return eAdc_CfifoModeCurrent;
}

FUNC(status_t, ADC_CODE)  EQADC_LLD_SetCfifoMode \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx,  \
    CONST(Eqadc_CfifoModeType, ADC_CONST) eAdc_CfifoModeTarget \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) eAdc_status = STATUS_ERROR;
    VAR(Eqadc_CfifoModeType, AUTOMATIC) eAdc_CfifoModeCurrent;
    VAR(Eqadc_CfifoStatusType, AUTOMATIC) eAdc_CfifoStatusCurrent;

    eAdc_CfifoModeCurrent = (Eqadc_CfifoModeType)EQADC_CFCRxGetMode((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
    eAdc_CfifoStatusCurrent = EQADC_LLD_GetCFifoStatus(eAdc_Instance, eAdc_CfifoIdx);

    if (eAdc_CfifoModeTarget != EQADC_CFIFO_MODE_DISABLE)
    {
        if ((EQADC_CFIFO_MODE_DISABLE == eAdc_CfifoModeCurrent) \
            && (EQADC_CFIFO_STATUS_IDLE == eAdc_CfifoStatusCurrent))
        {
            eAdc_status = STATUS_SUCCESS;
        }
    }
    else
    {
        eAdc_status = STATUS_SUCCESS;
    }

    if (STATUS_SUCCESS == eAdc_status)
    {
        EQADC_CFCRxSetMode((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, (uint32)eAdc_CfifoModeTarget);
    }

    return eAdc_status;
}

FUNC(uint8, ADC_CODE) EQADC_LLD_GetCfifo0EntryExtEnDis(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return EQADC_CFCR0_GetCfifo0EntryExtEnDis((uint8)eAdc_Instance);
}

FUNC(void, ADC_CODE) EQADC_LLD_SetCfifo0EntryExtEnDis \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(boolean, ADC_CONST) bAdc_EnDis \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    EQADC_CFCR0_SetCfifo0EntryExtEnDis((uint8)eAdc_Instance, bAdc_EnDis);
}

Eqadc_Cfifo0AModeType EQADC_LLD_GetCfifo0AdvanceMode(CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */

    return ((Eqadc_Cfifo0AModeType)EQADC_CFCR0_GetAMode0((uint8)eAdc_Instance));
}

FUNC(status_t, ADC_CODE)  EQADC_LLD_SetCfifo0AdvanceMode \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(Eqadc_Cfifo0AModeType, ADC_CONST) eAdc_AdvanceTrigMode \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_AdvanceTrigMode <= (uint8)EQADC_CFIFO0_AMODE_SINGLE_BOTH_EDGES_EXT_TRIG); /* PRQA S 4404 */

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    VAR(Eqadc_Cfifo0AModeType, AUTOMATIC) eAdc_Cfifo0AModeCurrent;
    VAR(Eqadc_CfifoStatusType, AUTOMATIC) eAdc_CfifoStatusCurrent;

    eAdc_Cfifo0AModeCurrent = (Eqadc_Cfifo0AModeType)EQADC_CFCR0_GetAMode0((uint8)eAdc_Instance);
    eAdc_CfifoStatusCurrent = EQADC_LLD_GetCFifoStatus(eAdc_Instance, EQADC_FIFO_0);

    if (eAdc_AdvanceTrigMode != EQADC_CFIFO0_AMODE_DISABLE)
    {
        if ((eAdc_Cfifo0AModeCurrent != EQADC_CFIFO0_AMODE_DISABLE) \
            || (eAdc_CfifoStatusCurrent != EQADC_CFIFO_STATUS_IDLE))
        {
            ret = STATUS_ERROR;
        }
    }

    if (STATUS_SUCCESS == ret)
    {
        EQADC_CFCR0_SetAMode0((uint8)eAdc_Instance, (uint8)eAdc_AdvanceTrigMode);
    }

    return ret;
}

FUNC(uint16, ADC_CODE) EQADC_LLD_GetIntDmaCtrlEn \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx \
)
{
    VAR(uint16, AUTOMATIC) u16Adc_IntDmaCtrl;

    u16Adc_IntDmaCtrl = EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx);

    return u16Adc_IntDmaCtrl;
}

FUNC(void, ADC_CODE) EQADC_LLD_IntEnDis \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, \
    VAR(uint16, AUTOMATIC) u16Adc_IntMask, \
    VAR(boolean, AUTOMATIC) bAdc_EnDis \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((u16Adc_IntMask & ~EQADC_IRQ_EN_ALL) == 0U); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) u6Adc_IntBitMask = u16Adc_IntMask;

    if ((u16Adc_IntMask & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) != 0U)
    {
        /* RFIFO Drain has selected DMA */
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) \
            != 0U)
        {
            EQADC_DET_ERR(FALSE);
            u6Adc_IntBitMask = (uint16)(u6Adc_IntBitMask & (~EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN));
        }
    }
    if ((u16Adc_IntMask & EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL) != 0U)
    {
        /* CFIFO Fill has selected DMA */
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) & EQADC_IRQDMA_REQ_SEL_CFIFOFILL) \
            != 0U)
        {
            EQADC_DET_ERR(FALSE);
            u6Adc_IntBitMask = (uint16)(u6Adc_IntBitMask & (~EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL));
        }
    }

    EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx, u6Adc_IntBitMask, bAdc_EnDis);
}

FUNC(void, ADC_CODE) EQADC_LLD_DmaEnDis \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, \
    VAR(uint16, AUTOMATIC) u16Adc_DmaMask, \
    VAR(boolean, AUTOMATIC) bAdc_EnDis \
)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((u16Adc_DmaMask & ~EQADC_DMA_EN_ALL) == 0U); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) u16Adc_DmaBitMask = u16Adc_DmaMask;

    if ((u16Adc_DmaMask & EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN) != 0U)
    {
        /* RFIFO Drain has selected Interrupt */
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) \
            & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) == 0U)
        {
            EQADC_DET_ERR(FALSE);
            u16Adc_DmaBitMask = (uint16)(u16Adc_DmaBitMask & (~EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN));
        }
    }
    if ((u16Adc_DmaMask & EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL) != 0U)
    {
        /* CFIFO Fill has selected Interrupt */
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) \
            & EQADC_IRQDMA_REQ_SEL_CFIFOFILL) == 0U)
        {
            EQADC_DET_ERR(FALSE);
            u16Adc_DmaBitMask = (uint16)(u16Adc_DmaBitMask & (~EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL));
        }
    }

    EQADC_IDCRx_FifoIntDmaEnDis((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx, u16Adc_DmaBitMask, bAdc_EnDis);
}

FUNC(uint8, ADC_CODE) EQADC_LLD_GetFifoFlagStatus \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, \
    CONST(Eqadc_FifoIntStatusType, ADC_CONST) eAdc_FifoStatusSel \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint8, AUTOMATIC)u8Adc_FifoStatus = 0U;
    CONSTP2CONST(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr \
        = Adc_EqadcBase[(uint8)eAdc_Instance];
    CONST(uint8, ADC_CONST) u8Adc_Fifo_x = (uint8)eAdc_FifoIdx;

    switch (eAdc_FifoStatusSel)
    {
        case EQADC_FISR_NON_COHERENCY:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_NCFX_MASK) \
                >> EQADC_FISR_NCFX_SHIFT);
            break;
        }
        case EQADC_FISR_TRIG_OVERRUN:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_TORFX_MASK) \
                >> EQADC_FISR_TORFX_SHIFT);
            break;
        }
        case EQADC_FISR_PAUSE:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_PFX_MASK) \
                >> EQADC_FISR_PFX_SHIFT);
            break;
        }
        case EQADC_FISR_END_OF_QUEUE:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_EOQFX_MASK) \
                >> EQADC_FISR_EOQFX_SHIFT);
            break;
        }
        case EQADC_FISR_CFIFO_UNDERFLOW:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_CFUFX_MASK) \
                >> EQADC_FISR_CFUFX_SHIFT);
            break;
        }
        case EQADC_FISR_CFIFO_SINGLE_SCAN:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_SSSX_MASK) \
                >> EQADC_FISR_SSSX_SHIFT);
            break;
        }
        case EQADC_FISR_CFIFO_FILL:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_CFFFX_MASK) \
                >> EQADC_FISR_CFFFX_SHIFT);
            break;
        }
        case EQADC_FISR_RFIFO_OVERFLOW:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_RFOFX_MASK) \
                >> EQADC_FISR_RFOFX_SHIFT);
            break;
        }
        case EQADC_FISR_RFIFO_DRAIN:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_RFDFX_MASK) \
                >> EQADC_FISR_RFDFX_SHIFT);
            break;
        }
        case EQADC_FISR_CFIFO_ENTRY_COUNT:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_CFCTRX_MASK) \
                >> EQADC_FISR_CFCTRX_SHIFT);
            break;
        }
        case EQADC_FISR_CFIFO_TRANS_NEXT_PTR:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_TNXTPTRX_MASK) \
                >> EQADC_FISR_TNXTPTRX_SHIFT);
            break;
        }
        case EQADC_FISR_RFIFO_ENTRY_COUNT:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_RFCTRX_MASK) \
                >> EQADC_FISR_RFCTRX_SHIFT);
            break;
        }
        case EQADC_FISR_RFIFO_POP_NEXT_PTR:
        {
            u8Adc_FifoStatus = (uint8)((pAdc_BasePtr->FISR[u8Adc_Fifo_x].R & EQADC_FISR_POPNXTPTRX_MASK) \
                >> EQADC_FISR_POPNXTPTRX_SHIFT);
            break;
        }
        default:
        {
            EQADC_DET_ERR(FALSE);
            break;
        }
    }

    return u8Adc_FifoStatus;
}

FUNC(uint32, ADC_CODE) EQADC_LLD_GetFifoIntFlag \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    VAR(uint32, AUTOMATIC) u32Adc_FifoFlagMask;
    CONSTP2CONST(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr \
        = Adc_EqadcBase[(uint8)eAdc_Instance];

    u32Adc_FifoFlagMask = pAdc_BasePtr->FISR[(uint8)eAdc_FifoIdx].R & EQADC_FIFO_FLAG_ALL;
    return u32Adc_FifoFlagMask;
}

FUNC(void, ADC_CODE) EQADC_LLD_ClearFifoIntFlag \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_FifoIdx, \
    VAR(uint32, AUTOMATIC) u32Adc_FifoFlagMask \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_FifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((u32Adc_FifoFlagMask & ~EQADC_FIFO_FLAG_ALL) == 0U); /* PRQA S 4404 */

    CONSTP2VAR(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr \
        = Adc_EqadcBase[(uint8)eAdc_Instance];

    VAR(uint32, AUTOMATIC) u32Adc_FifoFlagBitMask = u32Adc_FifoFlagMask;

    if ((u32Adc_FifoFlagMask & EQADC_FIFO_FLAG_CFIFO_FILL) != 0U)
    {
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) \
            & EQADC_IRQDMA_REQ_SEL_CFIFOFILL) != 0U)
        {
            EQADC_DET_ERR(FALSE);
            u32Adc_FifoFlagBitMask &= ~EQADC_FIFO_FLAG_CFIFO_FILL;
        }
    }
    if ((u32Adc_FifoFlagMask & EQADC_FIFO_FLAG_RFIFO_DRAIN) != 0U)
    {
        if ((EQADC_IDCRx_GetFifoIntDma((uint8)eAdc_Instance, (uint8)eAdc_FifoIdx) \
            & EQADC_IRQDMA_REQ_SEL_RFIFODRAIN) != 0U)
        {
            EQADC_DET_ERR(FALSE);
            u32Adc_FifoFlagBitMask &= ~EQADC_FIFO_FLAG_RFIFO_DRAIN;
        }
    }
    pAdc_BasePtr->FISR[(uint8)eAdc_FifoIdx].R = u32Adc_FifoFlagBitMask; /* w1c */
}

FUNC(uint16, ADC_CODE) EQADC_LLD_GetCfifoTransferCounter \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    return EQADC_CFTCRx_GetCfifoTransCount((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx);
}

FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoTransferCounter \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, \
    CONST(uint16, ADC_CONST) u16Adc_TransCount \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(u16Adc_TransCount <= EQADC_CFTCR0_TC_CF1_MASK); /* PRQA S 4404 */

    EQADC_CFTCRx_SetCfifoTransCount((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, u16Adc_TransCount);
}

FUNC(Eqadc_CfifoStatusType, AUTOMATIC) EQADC_LLD_GetCFifoStatusSnapshot \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, \
    CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */

    VAR(Eqadc_CfifoStatusType, AUTOMATIC) eAdc_CfifoStatus;

    eAdc_CfifoStatus = (Eqadc_CfifoStatusType)EQADC_CFSSRx_GetCfifoStatusAtTCB_Snapshot \
                  ( \
                      (uint8)eAdc_Instance, \
                      (uint8)eAdc_CfifoIdx, \
                      (uint8) eAdc_AdcIdx \
                  );

    return eAdc_CfifoStatus;
}

EqadcFifoIdxType EQADC_LLD_GetLastCFifoSnapshot \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */

    VAR(EqadcFifoIdxType, AUTOMATIC) eAdc_Cfifo_x;

    eAdc_Cfifo_x = (EqadcFifoIdxType)EQADC_CFSSRx_GetLastCfifoToTCB_Snapshot \
              ( \
                  (uint8)eAdc_Instance, \
                  (uint8) eAdc_AdcIdx \
              );

    return eAdc_Cfifo_x;
}

FUNC(uint16, ADC_CODE) EQADC_LLD_GetTransCountLastCFifoSnapshot \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8) eAdc_AdcIdx < EQADC_ADC_NUM); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) u16Adc_TransferCount;

    u16Adc_TransferCount = EQADC_CFSSRx_GetTransCountForLastCfifoToTCB_Snapshot \
                    ( \
                        (uint8)eAdc_Instance, \
                        (uint8) eAdc_AdcIdx \
                    );

    return u16Adc_TransferCount;
}

static FUNC(Eqadc_CfifoStatusType, ADC_CODE) EQADC_LLD_GetCFifoStatus \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx \
)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    VAR(uint32, AUTOMATIC) u32Adc_TempVal;
    CONSTP2CONST(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr \
        = Adc_EqadcBase[(uint8)eAdc_Instance];
    VAR(uint8, AUTOMATIC) u8Adc_CfifoStatus = (uint8)EQADC_CFIFO_STATUS_IDLE;
    VAR(uint32, AUTOMATIC) EQADC_CFSR_CFSx_MaskVal = EQADC_CFSR_CFS0_MASK;

    u32Adc_TempVal = (uint32)eAdc_CfifoIdx * 2U;
    if(u32Adc_TempVal < 32U)
    {
    	EQADC_CFSR_CFSx_MaskVal = (uint32)EQADC_CFSR_CFS0_MASK >> u32Adc_TempVal;
    }

    VAR(uint8, AUTOMATIC) EQADC_CFSR_CFSx_ShiftVal \
        = EQADC_CFSR_CFS0_SHIFT - ((uint8)eAdc_CfifoIdx * 2U);
    u8Adc_CfifoStatus = (uint8)((uint32)(pAdc_BasePtr->CFSR.R & EQADC_CFSR_CFSx_MaskVal) >> EQADC_CFSR_CFSx_ShiftVal);

    return (Eqadc_CfifoStatusType)u8Adc_CfifoStatus;
}

#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
/* EQADC CFIFO Trigger Delay */
FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoTrigDelay \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_instance, \
    CONST(EqadcFifoIdxType, ADC_CONST)  eAdc_CfifoIdx, \
    CONST(boolean, ADC_CONST)  eAdc_CfifoTrigDelayEn, \
    CONST(uint32, ADC_CONST) eAdc_CfifoTrigDelayCnt \
)
{
    EQADC_DET_ERR((uint8)eAdc_instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint32, AUTOMATIC) u32Adc_CfifoTrigDelayReg;
    u32Adc_CfifoTrigDelayReg = ((eAdc_CfifoTrigDelayEn == TRUE) ? EQADC_DLY_CFIFO_TRIG_DELAY_EN_MASK : 0UL) | \
                               (eAdc_CfifoTrigDelayCnt & EQADC_DLY_CFIFO_TRIG_DELAY_VAL_MASK);
    *(EQADC_DLY[eAdc_instance][(uint8)(eAdc_CfifoIdx)]) = u32Adc_CfifoTrigDelayReg;
}
#endif

#ifndef CCFC3012PT
FUNC(void, ADC_CODE) EQADC_LLD_SetRedLineClientConfig \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_ClientIdx, \
    CONST(Eqadc_RedLineBitsSelType, ADC_CONST) eAdc_RedLineTbaseBitSel, \
    CONST(Eqadc_RedLineServerDataSlotSelType, ADC_CONST) eAdc_RedLineSlotSel \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_ClientIdx <= EQADC_STAC_BUS_CLIENT_2); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_RedLineTbaseBitSel \
        <= (uint8)EQADC_REDLINE_BITS_SEL_TBASE_8_23); /* PRQA S 4404 */

    EQADC_REDLCCR_SetREDBS_SRVx \
    ( \
        (uint8)eAdc_Instance, u8Adc_ClientIdx, \
        (uint8)eAdc_RedLineTbaseBitSel, \
        (uint8)eAdc_RedLineSlotSel \
    );
}
#endif

FUNC(uint32, ADC_CODE) EQADC_LLD_GetCfifoEntryData \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_EntryIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_EntryIdx < EQADC_CFIFO_ENTRY_COUNT); /* PRQA S 4404 */

    return EQADC_CFxRw_GetCfifoData((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, u8Adc_EntryIdx);
}

FUNC(uint32, ADC_CODE) EQADC_LLD_GetCfifo0ExtEntryData \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_EntryIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_EntryIdx < EQADC_CFIFO_ENTRY_COUNT); /* PRQA S 4404 */

    CONSTP2CONST(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr \
        = Adc_EqadcBase[(uint8)eAdc_Instance];

    VAR(uint32, AUTOMATIC) u32Adc_Cfifo0ExtData;

    u32Adc_Cfifo0ExtData = pAdc_BasePtr->CF0ER[u8Adc_EntryIdx].R;

    return u32Adc_Cfifo0ExtData;
}

FUNC(uint32, ADC_CODE) EQADC_LLD_GetRfifoEntryData \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_EntryIdx \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_RfifoIdx < EQADC_RFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR(u8Adc_EntryIdx < EQADC_RFIFO_ENTRY_COUNT); /* PRQA S 4404 */

    return EQADC_RFxRw_GetRfifoData((uint8)eAdc_Instance, (uint8)eAdc_RfifoIdx, u8Adc_EntryIdx);
}

FUNC(void, ADC_CODE) EQADC_LLD_SetCfifoHwTrigSource \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, \
    CONST(uint8, ADC_CONST) eAdc_TrigSourceSel, \
    CONST(uint8, ADC_CONST) eAdc_GTM_ADC_TRIG_OUTSEL \
)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint8, ADC_VAR) u8Adc_Ret = (uint8)E_NOT_OK;
    VAR(uint8, ADC_VAR) u8Adc_trigregidx = 0U;
    VAR(uint8, ADC_VAR) u8Adc_TrigRegMemberIdx = 0U;
    u8Adc_Ret = EQADC_ISELx_SetCfifoTrig((uint8)eAdc_Instance, (uint8)eAdc_CfifoIdx, eAdc_TrigSourceSel);
    if ((eAdc_TrigSourceSel >= EQADC_HW_TRIG_GTM_TRIG0_MEMBER0) && (eAdc_TrigSourceSel <= EQADC_HW_TRIG_GTM_TRIG4_MEMBER11))
    {
        u8Adc_trigregidx = ((eAdc_TrigSourceSel - EQADC_HW_TRIG_GTM_TRIG0_MEMBER0) / GTM_ADC_TRIG_MEMBER_NUM);
        u8Adc_TrigRegMemberIdx = ((eAdc_TrigSourceSel - EQADC_HW_TRIG_GTM_TRIG0_MEMBER0) % GTM_ADC_TRIG_MEMBER_NUM);
        
        GTM_to_EQADC_Connections(0u, u8Adc_trigregidx, u8Adc_TrigRegMemberIdx, eAdc_GTM_ADC_TRIG_OUTSEL); //TODO
    }
    EQADC_DET_ERR(u8Adc_Ret == (uint8)E_OK);/* PRQA S 4404 */
    (void)u8Adc_Ret;
}

FUNC(void, ADC_CODE) EQADC_LLD_SetCfifo0AdvanceTrigSource \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(uint8, ADC_CONST) eAdc_AdvTrigSourceSel \
)/* PRQA S 1505 */
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE);  /* PRQA S 4404 */

    VAR(uint8, ADC_VAR) u8Adc_Ret = (uint8)E_NOT_OK;
    u8Adc_Ret = EQADC_ISELx_SetCfifo0AdvanceTrig((uint8)eAdc_Instance, eAdc_AdvTrigSourceSel);
    EQADC_DET_ERR(u8Adc_Ret == (uint8)E_OK);/* PRQA S 4404 */
    (void)u8Adc_Ret;
}

#if EQADC_ONCHIPADC_RW_LLD
FUNC(void, ADC_CODE) EQADC_LLD_SetAdcRegValueSSE \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, \
    CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcReg, \
    CONST(uint16, ADC_CONST) u16Adc_AdcRegVal \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint32, AUTOMATIC) u32Adc_TestTimeout = EQADC_TIMEOUT_COUNT;

    EQADC_WriteConfigCmdSSE \
    ( \
    (uint8)eAdc_Instance, \
    (uint8)eAdc_CfifoIdx, \
    (uint8) eAdc_AdcIdx, \
    eAdc_AdcReg, \
    u16Adc_AdcRegVal \
    );

    while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, eAdc_CfifoIdx, EQADC_FISR_END_OF_QUEUE) != 1U) \
            && (u32Adc_TestTimeout > 0UL))
    {
        u32Adc_TestTimeout--;
    }

    if(u32Adc_TestTimeout == 0U)
    {
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        Adc_DemReportErrorStatus(DEM_EVENTID_SETADCREGVALUESSE, DEM_EVENT_TIMEOUT);
#endif
    }

    /* Clear Flag */
    EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, eAdc_CfifoIdx, EQADC_FIFO_FLAG_END_OF_QUEUE);
}

FUNC(uint16, ADC_CODE) EQADC_LLD_GetAdcRegValueSSE \
( \
    CONST(EqadcInstanceType, ADC_CONST) eAdc_Instance, \
    CONST(EqadcAdcIdxType, ADC_CONST)  eAdc_AdcIdx, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_CfifoIdx, \
    CONST(EqadcFifoIdxType, ADC_CONST) eAdc_RfifoIdx, \
    CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcReg \
)
{
    EQADC_DET_ERR((uint8)eAdc_Instance < ADC_EQADC_MAX_INSTANCE); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_CfifoIdx < EQADC_CFIFO_COUNT); /* PRQA S 4404 */
    EQADC_DET_ERR((uint8)eAdc_RfifoIdx < EQADC_RFIFO_COUNT); /* PRQA S 4404 */

    VAR(uint16, AUTOMATIC) u16Adc_AdcRegVal = 0xFFFFU;
    VAR(uint32, AUTOMATIC) u32Adc_TestTimeout = EQADC_TIMEOUT_COUNT;

    EQADC_ReadConfigCmdSSE \
    ( \
        (uint8)eAdc_Instance, \
        (uint8)eAdc_CfifoIdx, \
        (uint8) eAdc_AdcIdx, \
        eAdc_AdcReg, \
        (uint8)eAdc_RfifoIdx \
    );

    while ((EQADC_LLD_GetFifoFlagStatus(eAdc_Instance, eAdc_RfifoIdx, EQADC_FISR_RFIFO_DRAIN) != 1U) \
            && (u32Adc_TestTimeout > 0UL))
    {
        u32Adc_TestTimeout--;
    }

    if (u32Adc_TestTimeout > 0UL)
    {
        /* Pop Rfifo result data */
        u16Adc_AdcRegVal = EQADC_LLD_RfifoPopData(eAdc_Instance, eAdc_RfifoIdx);
    }

    if(u32Adc_TestTimeout == 0U)
    {
#if (ADC_DEM_REPORT_ERROR_ENABLE == STD_ON)
        Adc_DemReportErrorStatus(DEM_EVENTID_GETADCREGVALUESSE, DEM_EVENT_TIMEOUT);
#endif
    }

    /* Clear Flag */
    EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, eAdc_RfifoIdx, EQADC_FIFO_FLAG_RFIFO_DRAIN);
    EQADC_LLD_ClearFifoIntFlag(eAdc_Instance, eAdc_CfifoIdx, EQADC_FIFO_FLAG_END_OF_QUEUE);

    return u16Adc_AdcRegVal;
}
#endif

static FUNC(void, ADC_CODE) EQADC_WriteConfigCmdSSE \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint8, ADC_CONST)  u8Adc_AdcIdx, \
    CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcAddr, \
    CONST(uint16, ADC_CONST) u16Adc_AdcRegVal \
)
{
    Eqadc_ConfigCmdType ConfigCmd;

    EQADC_GetDefaultRwConfigCmd(&ConfigCmd);
    ConfigCmd.cBufNum       = u8Adc_AdcIdx;
    ConfigCmd.AdcRegAddr    = eAdc_AdcAddr;
    ConfigCmd.AdcRegValue   = u16Adc_AdcRegVal;
    EQADC_LLD_CfifoPushConfigCmd \
    ( \
        (EqadcInstanceType)u8Adc_Instance, \
        (EqadcFifoIdxType)u8Adc_CfifoIdx, \
        &ConfigCmd \
    );
    EQADC_CFCRxSetSSE(u8Adc_Instance, u8Adc_CfifoIdx);
}

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_ReadConfigCmdSSE \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint8, ADC_CONST) u8Adc_AdcIdx, \
    CONST(Eqadc_OnChipAdcRegAddrType, ADC_CONST) eAdc_AdcAddr, \
    CONST(uint8, ADC_CONST) u8Adc_RfifoIdx \
)
{
    Eqadc_ConfigCmdType ConfigCmd;

    EQADC_GetDefaultRwConfigCmd(&ConfigCmd);
    ConfigCmd.cBufNum       = u8Adc_AdcIdx;
    ConfigCmd.RwCfgCmdType  = EQADC_CONFIG_CMD_READ;
    ConfigCmd.AdcRegAddr    = eAdc_AdcAddr;
    ConfigCmd.RfifoMsgTag   = (Eqadc_RfifoMsgTagType)u8Adc_RfifoIdx;
    EQADC_LLD_CfifoPushConfigCmd \
    ( \
        (EqadcInstanceType)u8Adc_Instance, \
        (EqadcFifoIdxType)u8Adc_CfifoIdx, \
        &ConfigCmd \
    );
    EQADC_CFCRxSetSSE(u8Adc_Instance, u8Adc_CfifoIdx);
}

static FUNC(status_t, ADC_CODE)  EQADC_DeinitCfifo \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx \
)
{
    VAR(uint16, AUTOMATIC) u16Adc_IntDmaMask = 0U;
    VAR(uint32, AUTOMATIC) u32Adc_Timeout;
    VAR(status_t, AUTOMATIC) eAdc_ret = STATUS_SUCCESS;
    VAR(uint8, ADC_VAR) u8Adc_ret = FALSE;

    EQADC_CFCRxSetMode(u8Adc_Instance, u8Adc_CfifoIdx, (uint32)EQADC_CFIFO_MODE_DISABLE);

    u32Adc_Timeout = EQADC_TIMEOUT_COUNT;
    while ((EQADC_LLD_GetCFifoStatus((EqadcInstanceType)u8Adc_Instance, (EqadcFifoIdxType)u8Adc_CfifoIdx) \
        != EQADC_CFIFO_STATUS_IDLE) && (u32Adc_Timeout > 0UL))
    {
        u32Adc_Timeout--;
    }

    if (0UL == u32Adc_Timeout)
    {
        eAdc_ret = STATUS_TIMEOUT;
    }

    u16Adc_IntDmaMask = (uint16)(EQADC_IRQ_EN_ALL & ~(EQADC_IRQ_EN_RFIFO_OVERFLOW \
        | EQADC_IRQ_DMA_REQ_EN_RFIFODRAIN));
    EQADC_IDCRx_FifoIntDmaEnDis(u8Adc_Instance, u8Adc_CfifoIdx, u16Adc_IntDmaMask, FALSE);
    EQADC_IDCRx_FifoIntDmaEnDis \
    ( \
    u8Adc_Instance, \
    u8Adc_CfifoIdx, \
    EQADC_IRQDMA_REQ_SEL_CFIFOFILL, \
    FALSE \
    );

    /* Stop eDMA mapped channel */
    if (DmaMappedChanForCmd[u8Adc_Instance][u8Adc_CfifoIdx] != EQADC_DMA_MAPPED_CHAN_INVALID)
    {
        (void) EDMA_ClearChannelRequest(DmaMappedChanForCmd[u8Adc_Instance][u8Adc_CfifoIdx]);

        DmaMappedChanForCmd[u8Adc_Instance][u8Adc_CfifoIdx] = EQADC_DMA_MAPPED_CHAN_INVALID;
    }

    /* invalidate CFIFO all entries */
    EQADC_CFCRxSetInvalidate(u8Adc_Instance,u8Adc_CfifoIdx);

    /* close CFIFO Trigger */
	u8Adc_ret = EQADC_ISELx_SetCfifoTrig(u8Adc_Instance, u8Adc_CfifoIdx, EQADC_HW_TRIG_NOT_CONNECTED);
	EQADC_DET_ERR(u8Adc_ret == (uint8)E_OK);

    if ((uint8)EQADC_FIFO_0 == u8Adc_CfifoIdx)
    {
        /* disable CFIFO0 EntryExt */
        EQADC_CFCR0_SetCfifo0EntryExtEnDis(u8Adc_Instance, FALSE);

        /* disable CFIFO0 AdvanceMode */
        EQADC_CFCR0_SetAMode0(u8Adc_Instance, (uint8)EQADC_CFIFO0_AMODE_DISABLE);

        /* disable CFIFO0 StreamMode */
        EQADC_CFCR0_Cfifo0StreamModeEnDis(u8Adc_Instance, FALSE);

        /* close CFIFO0 AdvanceTrig */
		u8Adc_ret = EQADC_ISELx_SetCfifo0AdvanceTrig(u8Adc_Instance, EQADC_ATRIG_NOT_CONNECTED);
		EQADC_DET_ERR(u8Adc_ret == (uint8)E_OK);
		(void)u8Adc_ret;
    }

    return eAdc_ret;
}

#ifndef CCFC3012PT
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_DeinitRedLineClient \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_ClientIdx \
)
{
    CONSTP2VAR(EQADC_TagType, ADC_CONST, ADC_APPL_CONST) pAdc_BasePtr = Adc_EqadcBase[u8Adc_Instance];
    if (u8Adc_ClientIdx == 0U)
    {
        pAdc_BasePtr->STACCCR.R &= ~(EQADC_STACCCR_SRV1_MASK | EQADC_STACCCR_STACBS1_MASK);
    }
    else
    {
        pAdc_BasePtr->STACCCR.R &= ~(EQADC_STACCCR_SRV2_MASK | EQADC_STACCCR_STACBS2_MASK);
    }
}
#endif

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_DeinitAdcCtrl \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_AdcIdx, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
)
{
    if (u8Adc_CfgCmdCfifoIdx == (uint8)EQADC_FIFO_0)
    {
        EQADC_LLD_SetImmediateConvCmdEnDis \
        ( \
            (EqadcInstanceType)u8Adc_Instance, \
            (EqadcAdcIdxType)u8Adc_AdcIdx, \
            TRUE \
        );
    }

    /* Reset ADCx_CR */
    EQADC_WriteConfigCmdSSE \
    ( \
        u8Adc_Instance, \
        u8Adc_CfgCmdCfifoIdx, \
        u8Adc_AdcIdx, \
        EQADC_ADC_REG_CR, \
        (uint16)EQADC_ADC_CR_CLK_PS_MASK \
    );

    /* Reset ADCx_GCCR */
    EQADC_WriteConfigCmdSSE \
    ( \
    u8Adc_Instance, \
    u8Adc_CfgCmdCfifoIdx, \
    u8Adc_AdcIdx, \
    EQADC_ADC_REG_GCCR, \
    0x4000U \
    );

    /* Reset ADCx_OCCR */
    EQADC_WriteConfigCmdSSE \
    ( \
    u8Adc_Instance, \
    u8Adc_CfgCmdCfifoIdx, \
    u8Adc_AdcIdx, \
    EQADC_ADC_REG_OCCR, \
    0x0000U \
    );

    if (u8Adc_CfgCmdCfifoIdx == (uint8)EQADC_FIFO_0)
    {
        EQADC_LLD_SetImmediateConvCmdEnDis \
        ( \
            (EqadcInstanceType)u8Adc_Instance, \
            (EqadcAdcIdxType)u8Adc_AdcIdx, \
            FALSE \
        );
    }
}

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_DeinitAdcTimeConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
)
{
    /* Reset ADC_TSCR */
    EQADC_WriteConfigCmdSSE \
    ( \
        u8Adc_Instance, \
        u8Adc_CfgCmdCfifoIdx, \
        (uint8)EQADC_ADC_0, EQADC_ADC_REG_TSCR, \
        0x0000U \
    );

    /* Reset ADC_TBCR */
    EQADC_WriteConfigCmdSSE \
    ( \
        u8Adc_Instance, \
        u8Adc_CfgCmdCfifoIdx, \
        (uint8)EQADC_ADC_0, \
        EQADC_ADC_REG_TBCR, \
        0x0000U \
    );
}

static FUNC(void, ADC_CODE) EQADC_DeinitAltConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(Eqadc_AltConfigSelType, ADC_CONST) eAdc_AltCfgSel, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
)
{
    VAR(uint8, AUTOMATIC)u8Adc_Index;

    /* Reset ADC_ACRx */
    EQADC_WriteConfigCmdSSE \
    ( \
        u8Adc_Instance, \
        u8Adc_CfgCmdCfifoIdx, \
        (uint8)EQADC_ADC_0, \
        EQADC_GetAltConfigRegAddr(eAdc_AltCfgSel), \
        0x0000U \
    );

    if ((EQADC_ALT_CONFIG_SEL_1 == eAdc_AltCfgSel) || (EQADC_ALT_CONFIG_SEL_2 == eAdc_AltCfgSel))
    {
        VAR(uint8, AUTOMATIC)u8Adc_AltCfgIdx = EQADC_GetAltConfigIdx(eAdc_AltCfgSel);
        for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ADC_NUM; u8Adc_Index++)
        {
            /* Reset ADCx_AGR0/1 */
            EQADC_WriteConfigCmdSSE \
            ( \
            u8Adc_Instance, \
            u8Adc_CfgCmdCfifoIdx, \
            u8Adc_Index, \
            AGRxAddr[u8Adc_AltCfgIdx], \
            0x4000U \
            );

            /* Reset ADCx_AOR0/1 */
            EQADC_WriteConfigCmdSSE \
            ( \
            u8Adc_Instance, \
            u8Adc_CfgCmdCfifoIdx, \
            u8Adc_Index, \
            AORxAddr[u8Adc_AltCfgIdx], \
            0x0000U \
            );
        }
    }
}

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultCfifoCfg \
( \
    CONSTP2VAR(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr \
)
{
    pAdc_CfifoCfgPtr->CfifoIdx       = EQADC_FIFO_0;
    pAdc_CfifoCfgPtr->CfifoMode      = EQADC_CFIFO_MODE_SINGLE_SW_TRIG;
    pAdc_CfifoCfgPtr->IntDmaFillSel  = EQADC_FILL_SEL_INT;
    pAdc_CfifoCfgPtr->DmaMappedChan  = 0U;
    pAdc_CfifoCfgPtr->DmaChanDisReqOnTransComplete  = TRUE;
    pAdc_CfifoCfgPtr->SourcePtr      = NULL;
    pAdc_CfifoCfgPtr->SourceLen      = 0UL;
    pAdc_CfifoCfgPtr->Callback       = NULL;
    pAdc_CfifoCfgPtr->CallbackParam  = NULL;
    pAdc_CfifoCfgPtr->HwTrigSel      = EQADC_HW_TRIG_NOT_CONNECTED;
#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
    pAdc_CfifoCfgPtr->CfifoTrigDelayEn   = FALSE;
    pAdc_CfifoCfgPtr->CfifoTrigDelayVal  = 0U;
#endif

    /* CFIFO0 */
    pAdc_CfifoCfgPtr->Cfifo0EntryExtensionEn = FALSE;
    pAdc_CfifoCfgPtr->Cfifo0AdvanceMode      = EQADC_CFIFO0_AMODE_DISABLE;
    pAdc_CfifoCfgPtr->Cfifo0AdvanceTrigSel   = EQADC_ATRIG_NOT_CONNECTED;
}

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultRwConfigCmd \
( \
    CONSTP2VAR(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr \
)
{
    pAdc_ConfigCmdPtr->Eoq           = TRUE;
    pAdc_ConfigCmdPtr->Pause         = FALSE;
    pAdc_ConfigCmdPtr->RepeatStart   = FALSE;
    pAdc_ConfigCmdPtr->cBufNum       = (uint8)EQADC_ADC_0;
    pAdc_ConfigCmdPtr->RwCfgCmdType  = EQADC_CONFIG_CMD_WRITE;
    pAdc_ConfigCmdPtr->AdcRegValue   = 0U;
    pAdc_ConfigCmdPtr->AdcRegAddr    = EQADC_ADC_REG_GCCR;
    pAdc_ConfigCmdPtr->RfifoMsgTag   = EQADC_MSG_TAG_RFIFO0;
}

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_GetDefaultConvCmd \
( \
    CONSTP2VAR(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr \
)
{
    pAdc_ConvCmdPtr->Eoq             = TRUE;
    pAdc_ConvCmdPtr->Pause           = FALSE;
    pAdc_ConvCmdPtr->RepeatStart     = FALSE;
    pAdc_ConvCmdPtr->cBufNum         = (uint8)EQADC_ADC_0;
    pAdc_ConvCmdPtr->CalibConvResEn  = FALSE;
    pAdc_ConvCmdPtr->RfifoMsgTag     = EQADC_FIFO_0;
    pAdc_ConvCmdPtr->LongSampTime    = EQADC_ADCLK_SAMPLING_CYCLES_128;
    pAdc_ConvCmdPtr->TimeStampReq    = FALSE;
    pAdc_ConvCmdPtr->FormatSignEn    = FALSE;
    pAdc_ConvCmdPtr->ChanNum         = EQADC_CH0;
    pAdc_ConvCmdPtr->AltConfigSel    = EQADC_ALT_CONFIG_DISABLE;
    pAdc_ConvCmdPtr->FlushOrFMT      = FALSE;
}

LOCAL_INLINE FUNC(uint32, ADC_CODE) EQADC_GetCfifoRwConfigCmd \
( \
    CONSTP2CONST(Eqadc_ConfigCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigCmdPtr \
)
{
    VAR(uint32, AUTOMATIC) u32Adc_CfgCmd = 0U;

    /* CFIFO Header */
    u32Adc_CfgCmd |= EQADC_ADC_CMD_EOQ(pAdc_ConfigCmdPtr->Eoq);
    u32Adc_CfgCmd |= EQADC_ADC_CMD_REP(pAdc_ConfigCmdPtr->RepeatStart);
    u32Adc_CfgCmd |= EQADC_ADC_CMD_PAUSE(pAdc_ConfigCmdPtr->Pause);
    /** Reserved bit(0x18000000) **/
    /** EB bit(0x04000000) must be 0 **/

    /* ADC Command */
    EQADC_DET_ERR(pAdc_ConfigCmdPtr->cBufNum < EQADC_ADC_NUM); /* PRQA S 4404  */
    u32Adc_CfgCmd |= EQADC_ADC_CMD_BN(pAdc_ConfigCmdPtr->cBufNum);  /* BN: CBuffer0->ADC0, CBuffer1->ADC1 */

    switch (pAdc_ConfigCmdPtr->RwCfgCmdType)
    {
        case EQADC_CONFIG_CMD_READ:
        {
            u32Adc_CfgCmd |= EQADC_ADC_CMD_RW(EQADC_CONFIG_CMD_READ);
            u32Adc_CfgCmd |= EQADC_ADC_CMD_MESSAGE_TAG(pAdc_ConfigCmdPtr->RfifoMsgTag);
            break;
        }
        case EQADC_CONFIG_CMD_WRITE:
        {
            u32Adc_CfgCmd |= EQADC_ADC_CMD_RW(EQADC_CONFIG_CMD_WRITE); /* PRQA S 2985 */
            u32Adc_CfgCmd |= EQADC_ADC_CMD_REG_HL_BYTE(pAdc_ConfigCmdPtr->AdcRegValue); /* PRQA S 2985 */
            break;
        }
        default:
        {
            EQADC_DET_ERR(FALSE);
            break;
        }
    }

    u32Adc_CfgCmd |= EQADC_ADC_CMD_REG_ADDR(pAdc_ConfigCmdPtr->AdcRegAddr); /* PRQA S 2985 */

    return u32Adc_CfgCmd;
}

LOCAL_INLINE FUNC(uint32, ADC_CODE) EQADC_GetCfifoConversionCmd \
( \
    CONSTP2CONST(Eqadc_ConvCmdType, ADC_CONST, ADC_APPL_CONST) pAdc_ConvCmdPtr \
)
{
    VAR(uint32, AUTOMATIC) u32Adc_ConvCmd = 0U;

    /* CFIFO Header */
    u32Adc_ConvCmd |= EQADC_ADC_CMD_EOQ(pAdc_ConvCmdPtr->Eoq);
    u32Adc_ConvCmd |= EQADC_ADC_CMD_PAUSE(pAdc_ConvCmdPtr->Pause);
    u32Adc_ConvCmd |= EQADC_ADC_CMD_REP(pAdc_ConvCmdPtr->RepeatStart);
    /** Reserved bit(0x18000000) **/
    /** EB bit(0x04000000) must be 0 **/

    /* ADC Command */
    EQADC_DET_ERR(pAdc_ConvCmdPtr->cBufNum < EQADC_ADC_NUM); /* PRQA S 4404 */
    u32Adc_ConvCmd |= EQADC_ADC_CMD_BN(pAdc_ConvCmdPtr->cBufNum);   /* BN: CBuffer0->ADC0, CBuffer1->ADC1 */
    u32Adc_ConvCmd |= EQADC_ADC_CMD_CAL(pAdc_ConvCmdPtr->CalibConvResEn);
    u32Adc_ConvCmd |= EQADC_ADC_CMD_MESSAGE_TAG(pAdc_ConvCmdPtr->RfifoMsgTag);
    u32Adc_ConvCmd |= EQADC_ADC_CMD_LST(pAdc_ConvCmdPtr->LongSampTime);
    u32Adc_ConvCmd |= EQADC_ADC_CMD_TSR(pAdc_ConvCmdPtr->TimeStampReq);
    u32Adc_ConvCmd |= EQADC_ADC_CMD_CHAN_NUM(pAdc_ConvCmdPtr->ChanNum); /* PRQA S 2985 */

    if (pAdc_ConvCmdPtr->AltConfigSel == EQADC_ALT_CONFIG_DISABLE)
    {
        /* Conversion Command Format for the Standard Configuration */
        u32Adc_ConvCmd |= EQADC_ADC_CMD_FMT(pAdc_ConvCmdPtr->FormatSignEn);
    }
    else
    {
        /* Conversion Command Format for Alternate Configurations */
        u32Adc_ConvCmd |= EQADC_ADC_CMD_ALT_CFG_SEL(pAdc_ConvCmdPtr->AltConfigSel); /* PRQA S 2985 */
        u32Adc_ConvCmd |= EQADC_ADC_CMD_FFMT(pAdc_ConvCmdPtr->FlushOrFMT);
    }

    return u32Adc_ConvCmd;
}

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetAdcConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_AdcConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AdcConfig, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
)
{
#if EQADC_DET_SUPPORT
    /* ADC CLK DET */
#endif
    VAR(uint16, AUTOMATIC) u16Adc_AdcCrVal = 0U, u16Adc_AdcGccrVal = 0U, u16Adc_AdcOccrVal = 0U;

    /* Get ADCxCR Config */
    u16Adc_AdcCrVal = EQADC_ADC_CR_EN_MASK;
    u16Adc_AdcCrVal = (uint16)(u16Adc_AdcCrVal | ((pAdc_AdcConfig->AdcExtMuxEn == TRUE) ? EQADC_ADC_CR_EMUX_MASK : 0U));

    EQADC_DET_ERR((uint8)(pAdc_AdcConfig->TimeBaseSel) <= (uint8)EQADC_TBS_STACCCR_SRV2); /* PRQA S 4404 */
    u16Adc_AdcCrVal |= EQADC_ADC_CR_TBSEL(pAdc_AdcConfig->TimeBaseSel);

    if (pAdc_AdcConfig->ClkSel == EQADC_CLK_SEL_PS_DIV)
    {
        u16Adc_AdcCrVal |= EQADC_ADC_CR_CLK_PS(pAdc_AdcConfig->ClkPrescale); /* PRQA S 2985 */
    }
#ifdef EQADC_ADC_CR_CLK_SEL_EN
    else
    {
        /* EQADC_CLK_SEL_MAX_FREQ */
        u16Adc_AdcCrVal |= EQADC_ADC_CR_CLK_SEL_MASK;
    }
#endif  /* EQADC_ADC_CR_CLK_SEL_EN */

    /* Get ADCxGCCR Config */
    u16Adc_AdcGccrVal = (pAdc_AdcConfig->AdcGainCalibConst & EQADC_ADC_GCCR_GCC_MASK);

    /* Get ADCxOCCR Config */
    u16Adc_AdcOccrVal = (uint16)(pAdc_AdcConfig->AdcOffsetCalibConst);

    /* En/Dis Immediate ConvCmd */
    EQADC_LLD_SetImmediateConvCmdEnDis \
    ( \
        (EqadcInstanceType)u8Adc_Instance, \
        pAdc_AdcConfig->AdcIdx, \
        pAdc_AdcConfig->ImmediateConvCmdEn \
    );

    /* Set ADCxCR/ADCxGCCR/ADCxOCCR Config */
    EQADC_WriteConfigCmdSSE \
    ( \
        u8Adc_Instance, \
        u8Adc_CfgCmdCfifoIdx, \
        (uint8)pAdc_AdcConfig->AdcIdx, \
        EQADC_ADC_REG_CR, \
        u16Adc_AdcCrVal \
    );
    EQADC_WriteConfigCmdSSE \
    ( \
        u8Adc_Instance, \
        u8Adc_CfgCmdCfifoIdx, \
        (uint8)pAdc_AdcConfig->AdcIdx, \
        EQADC_ADC_REG_GCCR, \
        u16Adc_AdcGccrVal \
    );
    EQADC_WriteConfigCmdSSE \
    ( \
        u8Adc_Instance, \
        u8Adc_CfgCmdCfifoIdx, \
        (uint8)pAdc_AdcConfig->AdcIdx, \
        EQADC_ADC_REG_OCCR, \
        u16Adc_AdcOccrVal \
    );
}

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetAltConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_AlternateConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_AltConfig, \
    CONST(uint8, ADC_CONST) u8Adc_CfgCmdCfifoIdx \
)
{
    VAR(uint16, AUTOMATIC) u16Adc_AdcAcrVal = 0U;
    VAR(uint8, AUTOMATIC) u8Adc_Index;

    /* Get ADC ACRx Config */
    u16Adc_AdcAcrVal = (pAdc_AltConfig->ResultTransInhibit == TRUE) ? EQADC_ADC_ACR_RET_INH_MASK : 0U;
    u16Adc_AdcAcrVal |= EQADC_ADC_ACR_DEST(pAdc_AltConfig->AltConvResultDEST);
    u16Adc_AdcAcrVal = (uint16)(u16Adc_AdcAcrVal | ((pAdc_AltConfig->FMTA_SignEn == TRUE) ? EQADC_ADC_ACR_FMTA_MASK : 0U));
    u16Adc_AdcAcrVal |= EQADC_ADC_ACR_RESSEL(pAdc_AltConfig->AdcResSel);
    u16Adc_AdcAcrVal |= EQADC_ADC_ACR_PRE_GAIN(pAdc_AltConfig->AdcPreGain); /* PRQA S 2985 */

    /* Set ADC ACRx Config */
    EQADC_WriteConfigCmdSSE \
    ( \
        u8Adc_Instance, \
        u8Adc_CfgCmdCfifoIdx, \
        (uint8)EQADC_ADC_0, \
        EQADC_GetAltConfigRegAddr(pAdc_AltConfig->AltConfigSel), \
        u16Adc_AdcAcrVal \
    );

    if ((EQADC_ALT_CONFIG_SEL_1 == pAdc_AltConfig->AltConfigSel) \
        || (EQADC_ALT_CONFIG_SEL_2 == pAdc_AltConfig->AltConfigSel))
    {
        VAR(uint8, AUTOMATIC)AltCfgIdx = EQADC_GetAltConfigIdx(pAdc_AltConfig->AltConfigSel);
        for (u8Adc_Index = 0U; u8Adc_Index < EQADC_ADC_NUM; u8Adc_Index++)
        {
            /* Set ADC AGRx Config */
            EQADC_WriteConfigCmdSSE \
            ( \
                u8Adc_Instance, \
                u8Adc_CfgCmdCfifoIdx, \
                u8Adc_Index, \
                AGRxAddr[AltCfgIdx], \
                pAdc_AltConfig->AdcAltGain[u8Adc_Index] \
            );

            /* Set ADC AORx Config */
            EQADC_WriteConfigCmdSSE \
            ( \
                u8Adc_Instance, \
                u8Adc_CfgCmdCfifoIdx, \
                u8Adc_Index, \
                AORxAddr[AltCfgIdx], \
                pAdc_AltConfig->AdcAltOffset[u8Adc_Index] \
            );
        }
    }
}
#ifndef CCFC3012PT
LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetRedLineClientConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_RedLineClientConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_PullUpDownCfg \
)
{
    EQADC_REDLCCR_SetREDBS_SRVx \
    ( \
        u8Adc_Instance, \
        pAdc_PullUpDownCfg->clientIdx, \
        (uint8)(pAdc_PullUpDownCfg->TimeBaseBitsSel), \
        (uint8)(pAdc_PullUpDownCfg->SRVnSel) \
    );
}
#endif
/*******************************************************************************
 * @brief EQADC CFIFO Control Register x (EQADC_CFCRx: MODEy)
 *          (x = 0...2, y = 0...5).
 *
 * @param u8Adc_Instance: EQADC instance
 *        u8Adc_CfifoIdx: CFIFO Index (Index = y)
 *        u32Adc_CfifoModeTarget: Set the target mode for CFIFO
 *
 * @note  If MODEy is not disabled, it must not be changed to any other mode
 *          besides disabled. If MODEy is disabled and the CFIFO status is IDLE,
 *          MODEy can be changed to any other mode.
 *******************************************************************************/
FUNC(void, ADC_CODE) EQADC_CFCRxSetMode \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONST(uint8, ADC_CONST) u8Adc_CfifoIdx, \
    CONST(uint32, ADC_CONST) u32Adc_CfifoModeTarget \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_CFCRx = u8Adc_CfifoIdx / 2U;  /* EQADC CFIFO Control Register x */
    if ((u8Adc_CfifoIdx % 2U) == 0U)
    {
        /* EQADC CfifoIdx: 0/2/4 */
        *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) &= ~EQADC_CFCR0_MODE0_MASK;
        *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_MODE0(u32Adc_CfifoModeTarget);
    }
    else
    {
        /* EQADC CfifoIdx: 1/3/5 */
        *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) &= ~EQADC_CFCR0_MODE1_MASK;
        *(EQADC_CFCR[u8Adc_Instance][u8Adc_CFCRx]) |= EQADC_CFCR0_MODE1(u32Adc_CfifoModeTarget);
    }
}


FUNC(status_t, ADC_CODE)  EQADC_SetCfifoConfig \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr \
)
{
    VAR(uint32, AUTOMATIC) u32Adc_Timeout;
    VAR(status_t, AUTOMATIC) eAdc_ret = STATUS_SUCCESS;

    /* 1.Disabled CFIFO mode. */
    EQADC_CFCRxSetMode \
    ( \
    u8Adc_Instance, \
    (uint8)(pAdc_CfifoCfgPtr->CfifoIdx), \
    (uint32)EQADC_CFIFO_MODE_DISABLE \
    );

    /* 2.Waiting for the IDLE status of CFIFO */
    u32Adc_Timeout = EQADC_TIMEOUT_COUNT;
    while ((EQADC_LLD_GetCFifoStatus((EqadcInstanceType)u8Adc_Instance, pAdc_CfifoCfgPtr->CfifoIdx) \
        != EQADC_CFIFO_STATUS_IDLE) && (u32Adc_Timeout > 0UL))
    {
        u32Adc_Timeout--;
    }

    if (0UL == u32Adc_Timeout)
    {
        eAdc_ret = STATUS_TIMEOUT;
    }

    /* 3.Set CFIFO other mode. */
    EQADC_CFCRxSetMode \
    ( \
    u8Adc_Instance, \
    (uint8)(pAdc_CfifoCfgPtr->CfifoIdx), \
    (uint32)(pAdc_CfifoCfgPtr->CfifoMode) \
    );

#ifdef RESOURCE_SUPPORT_EQADC_TRIG_DELAY
    /* CFIFO Trigger Delay */
    VAR(uint32, AUTOMATIC) u32Adc_CfifoTrigDelayReg;
    u32Adc_CfifoTrigDelayReg = ((pAdc_CfifoCfgPtr->CfifoTrigDelayEn == TRUE) ? EQADC_DLY_CFIFO_TRIG_DELAY_EN_MASK : 0UL) | \
                           (pAdc_CfifoCfgPtr->CfifoTrigDelayVal & EQADC_DLY_CFIFO_TRIG_DELAY_VAL_MASK);
    *(EQADC_DLY[u8Adc_Instance][(uint8)(pAdc_CfifoCfgPtr->CfifoIdx)]) = u32Adc_CfifoTrigDelayReg;
#endif  /* RESOURCE_SUPPORT_EQADC_TRIG_DELAY */

    if (EQADC_FILL_SEL_INT == pAdc_CfifoCfgPtr->IntDmaFillSel)
    {
        EQADC_IDCRx_FifoIntDmaEnDis \
        ( \
            u8Adc_Instance, \
            (uint8)(pAdc_CfifoCfgPtr->CfifoIdx), \
            EQADC_IRQDMA_REQ_SEL_CFIFOFILL, \
            FALSE \
        );
        EQADC_LLD_IntEnDis \
        ( \
            (EqadcInstanceType)u8Adc_Instance, \
            pAdc_CfifoCfgPtr->CfifoIdx, \
            EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL, \
            FALSE \
        );
    }
    else
    {
        EQADC_SetDmaForCmd(u8Adc_Instance, pAdc_CfifoCfgPtr);
        EQADC_IDCRx_FifoIntDmaEnDis \
        ( \
            u8Adc_Instance, \
            (uint8)(pAdc_CfifoCfgPtr->CfifoIdx), \
            EQADC_IRQDMA_REQ_SEL_CFIFOFILL, \
            TRUE \
        );
        EQADC_LLD_DmaEnDis \
        ( \
            (EqadcInstanceType)u8Adc_Instance, \
            pAdc_CfifoCfgPtr->CfifoIdx, \
            EQADC_IRQ_DMA_REQ_EN_CFIFO_FILL, \
            TRUE \
        );
    }

    EQADC_DET_ERR((pAdc_CfifoCfgPtr->HwTrigSel == EQADC_HW_TRIG_NOT_CONNECTED) || /* PRQA S 4404 */ \
            ((pAdc_CfifoCfgPtr->CfifoMode != EQADC_CFIFO_MODE_SINGLE_SW_TRIG) && (pAdc_CfifoCfgPtr->CfifoMode != EQADC_CFIFO_MODE_CONT_SW_TRIG)));
#ifdef RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT
    CONST(uint8, ADC_CONST) u8Adc_ISEL_Mapped_x = ((u8Adc_Instance > 1u) ? 1u : 0u);
    if (EQADC_Trig_SIUL_ISEL_Mapped[u8Adc_ISEL_Mapped_x][(uint8)(pAdc_CfifoCfgPtr->CfifoIdx)] == EQADC_CFIFO_TRIG_MAPPED_INVALID)
    {
#endif  /* RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT */
#ifdef RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT
    }
#endif  /* RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT */

    if (EQADC_FIFO_0 == pAdc_CfifoCfgPtr->CfifoIdx)
    {
        /* CFIFO0 Entry Number Extension Enable */
        EQADC_CFCR0_SetCfifo0EntryExtEnDis(u8Adc_Instance, pAdc_CfifoCfgPtr->Cfifo0EntryExtensionEn);

        /* Set CFIFO0 Advance Trigger Operation Mode: disable mode */
        EQADC_CFCR0_SetAMode0(u8Adc_Instance, (uint8)EQADC_CFIFO0_AMODE_DISABLE);
#ifdef RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT
        if (EQADC_AdvanceTrig_SIUL_ISEL_Mapped[u8Adc_ISEL_Mapped_x] == EQADC_CFIFO0_ATRIG_MAPPED_INVALID)
        {
#endif  /* RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT */
            EQADC_LLD_SetCfifo0AdvanceTrigSource((EqadcInstanceType)u8Adc_Instance, pAdc_CfifoCfgPtr->Cfifo0AdvanceTrigSel);
#ifdef RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT
        }
#endif  /* RESOURCE_SUPPORT_SIUL2_EQADC_TRIG_SRC_LIMIT */

        if (pAdc_CfifoCfgPtr->Cfifo0AdvanceMode != EQADC_CFIFO0_AMODE_DISABLE)
        {
            EQADC_DET_ERR((pAdc_CfifoCfgPtr->CfifoMode >= \
                    EQADC_CFIFO_MODE_SINGLE_LOW_LVL_GATED_EXT_TRIG) && /* PRQA S 4404 */ \
                    (pAdc_CfifoCfgPtr->CfifoMode <= EQADC_CFIFO_MODE_SINGLE_BOTH_EDGES_EXT_TRIG));
            EQADC_DET_ERR((pAdc_CfifoCfgPtr->Cfifo0AdvanceMode != EQADC_CFIFO0_AMODE_SINGLE_SW_TRIG) || /* PRQA S 4404 */ \
                    (pAdc_CfifoCfgPtr->Cfifo0AdvanceTrigSel == EQADC_ATRIG_NOT_CONNECTED));

            /* Set CFIFO0 Advance Trigger Operation Mode */
            EQADC_CFCR0_SetAMode0(u8Adc_Instance, (uint8)(pAdc_CfifoCfgPtr->Cfifo0AdvanceMode));
            /* CFIFO0 Streaming Mode Operation Enable */
            EQADC_CFCR0_Cfifo0StreamModeEnDis(u8Adc_Instance, TRUE);
        }
        else
        {
            /* CFIFO0 Streaming Mode Operation Disable */
            EQADC_CFCR0_Cfifo0StreamModeEnDis(u8Adc_Instance, FALSE);
        }
    }

    return eAdc_ret;
}

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetDmaForCmd \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_CfifoConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_CfifoCfgPtr \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_Cfifo_x = (uint8)(pAdc_CfifoCfgPtr->CfifoIdx);
    VAR(status_t, AUTOMATIC) eAdc_ret = STATUS_SUCCESS;
    VAR(uint32, AUTOMATIC) u32Adc_srcSizeLast \
        = sizeof(pAdc_CfifoCfgPtr->SourcePtr[0U]) * pAdc_CfifoCfgPtr->SourceLen;
    VAR(Std_ReturnType, AUTOMATIC) u8Adc_ret = (Std_ReturnType)E_OK;

    DmaMappedChanForCmd[u8Adc_Instance][u8Adc_Cfifo_x] = pAdc_CfifoCfgPtr->DmaMappedChan;

    eDMATransferConfigType TcdCfg = tcdcfg;
    eDMALoopTransferConfigType LoopTcdCfg = looptcdcfg;
    TcdCfg.srcAddr                  = (uint32)pAdc_CfifoCfgPtr->SourcePtr;
    TcdCfg.destAddr                 = (uint32)(EQADC_CFPR[u8Adc_Instance][u8Adc_Cfifo_x]);
    TcdCfg.srcTransDataSize         = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.destTransDataSize        = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.srcAddrOffset            = (sint16)sizeof(pAdc_CfifoCfgPtr->SourcePtr[0U]);
    TcdCfg.srcAddrAdjustLast        = -(sint32)u32Adc_srcSizeLast;
    TcdCfg.minorTransByte           = sizeof(pAdc_CfifoCfgPtr->SourcePtr[0U]);
    TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

    LoopTcdCfg.majorLpIterCnt       = pAdc_CfifoCfgPtr->SourceLen;

    u8Adc_ret = EDMA_SetLoopTransferConfig(pAdc_CfifoCfgPtr->DmaMappedChan, &TcdCfg);
    if(u8Adc_ret == (Std_ReturnType)E_NOT_OK)
    {
    	eAdc_ret = STATUS_ERROR;
    }
    EQADC_DET_ERR(eAdc_ret == STATUS_SUCCESS); /* PRQA S 4404 */
    (void)eAdc_ret;
    EDMA_SetChnDisRequestsOnTransferComplete(pAdc_CfifoCfgPtr->DmaMappedChan, pAdc_CfifoCfgPtr->DmaChanDisReqOnTransComplete);

    if (pAdc_CfifoCfgPtr->Callback != NULL)
    {
        (void) EDMA_SetUpCallback \
        ( \
            pAdc_CfifoCfgPtr->DmaMappedChan, \
            pAdc_CfifoCfgPtr->Callback, \
            pAdc_CfifoCfgPtr->CallbackParam \
        );

        EDMA_SetInterruptConfig(pAdc_CfifoCfgPtr->DmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, TRUE);
        EDMA_SetInterruptConfig \
        ( \
            pAdc_CfifoCfgPtr->DmaMappedChan, \
            EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, \
            FALSE \
        );
        EDMA_SetInterruptConfig \
        ( \
            pAdc_CfifoCfgPtr->DmaMappedChan, \
            EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, \
            TRUE \
        );
    }
    else
    {
        EDMA_SetInterruptConfig(pAdc_CfifoCfgPtr->DmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, FALSE);
        EDMA_SetInterruptConfig \
        ( \
            pAdc_CfifoCfgPtr->DmaMappedChan, \
            EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, \
            FALSE \
        );
        EDMA_SetInterruptConfig \
        ( \
            pAdc_CfifoCfgPtr->DmaMappedChan, \
            EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, \
            FALSE \
        );
    }
    /* The start of the DMA channel is outside the EQADC low-level driver */
}

LOCAL_INLINE FUNC(void, ADC_CODE) EQADC_SetDmaForResult \
( \
    CONST(uint8, ADC_CONST) u8Adc_Instance, \
    CONSTP2CONST(Eqadc_ResultDmaConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_RfifoCfgPtr \
)
{
    VAR(uint8, AUTOMATIC) u8Adc_Rfifo_x = (uint8)(pAdc_RfifoCfgPtr->RfifoIdx);
    VAR(status_t,AUTOMATIC) eAdc_ret = STATUS_SUCCESS;
    VAR(uint32, AUTOMATIC) u32Adc_destSizeLast = sizeof(pAdc_RfifoCfgPtr->DestPtr[0U]) * pAdc_RfifoCfgPtr->DestLen;
    VAR(Std_ReturnType, AUTOMATIC) u8Adc_ret = (Std_ReturnType)E_OK;

    DmaMappedChanForResult[u8Adc_Instance][u8Adc_Rfifo_x] = pAdc_RfifoCfgPtr->ResultDmaMappedChan;

    eDMATransferConfigType TcdCfg = tcdcfg;
    eDMALoopTransferConfigType LoopTcdCfg = looptcdcfg;
    TcdCfg.srcAddr                  = (uint32)(EQADC_RFPR[ u8Adc_Instance][u8Adc_Rfifo_x]) + 2U;
    TcdCfg.destAddr                 = (uint32)pAdc_RfifoCfgPtr->DestPtr;
    TcdCfg.srcTransDataSize         = EDMA_TRANSFER_SIZE_2B;
    TcdCfg.destTransDataSize        = EDMA_TRANSFER_SIZE_2B;
    TcdCfg.destAddrOffset           = (sint16)sizeof(pAdc_RfifoCfgPtr->DestPtr[0U]);
    TcdCfg.destAddrAdjustLast       = -(sint32)u32Adc_destSizeLast;
    TcdCfg.minorTransByte           = sizeof(pAdc_RfifoCfgPtr->DestPtr[0U]);
    TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

    LoopTcdCfg.majorLpIterCnt       = pAdc_RfifoCfgPtr->DestLen;

    u8Adc_ret = EDMA_SetLoopTransferConfig(pAdc_RfifoCfgPtr->ResultDmaMappedChan, &TcdCfg);
    if(u8Adc_ret == (Std_ReturnType)E_NOT_OK)
	{
		eAdc_ret = STATUS_ERROR;
	}

    EQADC_DET_ERR(eAdc_ret == STATUS_SUCCESS); /* PRQA S 4404 */
    (void)eAdc_ret;
    if (pAdc_RfifoCfgPtr->Callback != NULL)
    {
        (void) EDMA_SetUpCallback \
        ( \
            pAdc_RfifoCfgPtr->ResultDmaMappedChan, \
            pAdc_RfifoCfgPtr->Callback, \
            pAdc_RfifoCfgPtr->CallbackParam \
        );

        EDMA_SetInterruptConfig \
        ( \
            pAdc_RfifoCfgPtr->ResultDmaMappedChan, \
            EDMA_CHN_ENABLE_ERROR_INT, \
            TRUE \
        );
        if (pAdc_RfifoCfgPtr->EnHalfDestCallback == TRUE)
        {
            EDMA_SetInterruptConfig \
            ( \
                pAdc_RfifoCfgPtr->ResultDmaMappedChan, \
                EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, \
                TRUE \
            );
        }
        else
        {
            EDMA_SetInterruptConfig \
            ( \
                pAdc_RfifoCfgPtr->ResultDmaMappedChan, \
                EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, \
                FALSE \
            );
        }
        EDMA_SetInterruptConfig \
        ( \
            pAdc_RfifoCfgPtr->ResultDmaMappedChan, \
            EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, \
            TRUE \
        );
    }
    else
    {
        EDMA_SetInterruptConfig \
        ( \
            pAdc_RfifoCfgPtr->ResultDmaMappedChan, \
            EDMA_CHN_ENABLE_ERROR_INT, \
            FALSE \
        );
        EDMA_SetInterruptConfig \
        ( \
            pAdc_RfifoCfgPtr->ResultDmaMappedChan, \
            EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT, \
            FALSE \
        );
        EDMA_SetInterruptConfig \
        ( \
            pAdc_RfifoCfgPtr->ResultDmaMappedChan, \
            EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, \
            FALSE \
        );
    }

    (void) EDMA_SetChannelRequest(pAdc_RfifoCfgPtr->ResultDmaMappedChan);
}

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

