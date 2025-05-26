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
*   @file    eDma_LLDriver.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/

#ifndef EDMA_LLDRIVER_H_
#define EDMA_LLDRIVER_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "derivative.h"
#include "typedefs.h"
#include "status.h"
#include "eDma_Cfg.h"
#include "eDma_Irq.h"

/* PRQA S 1534 EOF */
/* PRQA S 3472 EOF */
/* PRQA S 3630 EOF */

#define EDMA_LLD_H_VENDOR_ID                     176
#define EDMA_LLD_H_AR_REL_MAJOR_VER              4
#define EDMA_LLD_H_AR_REL_MINOR_VER              4
#define EDMA_LLD_H_AR_REL_REV_VER                0
#define EDMA_LLD_H_SW_MAJOR_VER                  1
#define EDMA_LLD_H_SW_MINOR_VER                  0
#define EDMA_LLD_H_SW_PATCH_VER                  1

#if (EDMA_CFG_H_VENDOR_ID != EDMA_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_LLD_H_VENDOR_ID "
#endif
#if (EDMA_CFG_H_AR_REL_MAJOR_VER != EDMA_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_MINOR_VER != EDMA_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_AR_REL_MINOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_REV_VER != EDMA_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_AR_REL_REV_VER "
#endif
#if (EDMA_CFG_H_SW_MAJOR_VER != EDMA_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_SW_MAJOR_VER "
#endif
#if (EDMA_CFG_H_SW_MINOR_VER != EDMA_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_SW_MINOR_VER "
#endif
#if (EDMA_CFG_H_SW_PATCH_VER != EDMA_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_LLD_H_SW_PATCH_VER "
#endif

#define EDMA_DEV_ERR(x)                         DEV_ASSERT(x)

#define EDMA_CH0_CH127_INT                      (1U)
#define EDMA_CH0_CH127_ERROR_INT                (1U)
#define EDMA_ERROR_INTERRUPT_LINES              (1U)

#define MODULES_EDMA_CHANNELS                   (64U)
#define EDMA_MAPPED_CHN_INTERRUPT_LINES         ((uint32)128U)

#define EDMA_TOTAL_CHANNELS                     (MODULES_EDMA_CHANNELS * EDMA_INSTANCE_COUNT)

#define TCD_SIZE_CALC(number)                   (((number) * 32U) - 1U)
#define TCD_ADDR_CALC(address)                  (((uint32)(address) + 31UL) & ~0x1FUL)

/* Physical channel number for channel configuration #0 - #127*/
#define EDMA_CHN0_NUMBER        (0U)
#define EDMA_CHN1_NUMBER        (1U)
#define EDMA_CHN2_NUMBER        (2U)
#define EDMA_CHN3_NUMBER        (3U)
#define EDMA_CHN4_NUMBER        (4U)
#define EDMA_CHN5_NUMBER        (5U)
#define EDMA_CHN6_NUMBER        (6U)
#define EDMA_CHN7_NUMBER        (7U)
#define EDMA_CHN8_NUMBER        (8U)
#define EDMA_CHN9_NUMBER        (9U)
#define EDMA_CHN10_NUMBER       (10U)
#define EDMA_CHN11_NUMBER       (11U)
#define EDMA_CHN12_NUMBER       (12U)
#define EDMA_CHN13_NUMBER       (13U)
#define EDMA_CHN14_NUMBER       (14U)
#define EDMA_CHN15_NUMBER       (15U)
#define EDMA_CHN16_NUMBER       (16U)
#define EDMA_CHN17_NUMBER       (17U)
#define EDMA_CHN18_NUMBER       (18U)
#define EDMA_CHN19_NUMBER       (19U)
#define EDMA_CHN20_NUMBER       (20U)
#define EDMA_CHN21_NUMBER       (21U)
#define EDMA_CHN22_NUMBER       (22U)
#define EDMA_CHN23_NUMBER       (23U)
#define EDMA_CHN24_NUMBER       (24U)
#define EDMA_CHN25_NUMBER       (25U)
#define EDMA_CHN26_NUMBER       (26U)
#define EDMA_CHN27_NUMBER       (27U)
#define EDMA_CHN28_NUMBER       (28U)
#define EDMA_CHN29_NUMBER       (29U)
#define EDMA_CHN30_NUMBER       (30U)
#define EDMA_CHN31_NUMBER       (31U)
#define EDMA_CHN32_NUMBER       (32U)
#define EDMA_CHN33_NUMBER       (33U)
#define EDMA_CHN34_NUMBER       (34U)
#define EDMA_CHN35_NUMBER       (35U)
#define EDMA_CHN36_NUMBER       (36U)
#define EDMA_CHN37_NUMBER       (37U)
#define EDMA_CHN38_NUMBER       (38U)
#define EDMA_CHN39_NUMBER       (39U)
#define EDMA_CHN40_NUMBER       (40U)
#define EDMA_CHN41_NUMBER       (41U)
#define EDMA_CHN42_NUMBER       (42U)
#define EDMA_CHN43_NUMBER       (43U)
#define EDMA_CHN44_NUMBER       (44U)
#define EDMA_CHN45_NUMBER       (45U)
#define EDMA_CHN46_NUMBER       (46U)
#define EDMA_CHN47_NUMBER       (47U)
#define EDMA_CHN48_NUMBER       (48U)
#define EDMA_CHN49_NUMBER       (49U)
#define EDMA_CHN50_NUMBER       (50U)
#define EDMA_CHN51_NUMBER       (51U)
#define EDMA_CHN52_NUMBER       (52U)
#define EDMA_CHN53_NUMBER       (53U)
#define EDMA_CHN54_NUMBER       (54U)
#define EDMA_CHN55_NUMBER       (55U)
#define EDMA_CHN56_NUMBER       (56U)
#define EDMA_CHN57_NUMBER       (57U)
#define EDMA_CHN58_NUMBER       (58U)
#define EDMA_CHN59_NUMBER       (59U)
#define EDMA_CHN60_NUMBER       (60U)
#define EDMA_CHN61_NUMBER       (61U)
#define EDMA_CHN62_NUMBER       (62U)
#define EDMA_CHN63_NUMBER       (63U)
#define EDMA_CHN64_NUMBER       (64U)
#define EDMA_CHN65_NUMBER       (65U)
#define EDMA_CHN66_NUMBER       (66U)
#define EDMA_CHN67_NUMBER       (67U)
#define EDMA_CHN68_NUMBER       (68U)
#define EDMA_CHN69_NUMBER       (69U)
#define EDMA_CHN70_NUMBER       (70U)
#define EDMA_CHN71_NUMBER       (71U)
#define EDMA_CHN72_NUMBER       (72U)
#define EDMA_CHN73_NUMBER       (73U)
#define EDMA_CHN74_NUMBER       (74U)
#define EDMA_CHN75_NUMBER       (75U)
#define EDMA_CHN76_NUMBER       (76U)
#define EDMA_CHN77_NUMBER       (77U)
#define EDMA_CHN78_NUMBER       (78U)
#define EDMA_CHN79_NUMBER       (79U)
#define EDMA_CHN80_NUMBER       (80U)
#define EDMA_CHN81_NUMBER       (81U)
#define EDMA_CHN82_NUMBER       (82U)
#define EDMA_CHN83_NUMBER       (83U)
#define EDMA_CHN84_NUMBER       (84U)
#define EDMA_CHN85_NUMBER       (85U)
#define EDMA_CHN86_NUMBER       (86U)
#define EDMA_CHN87_NUMBER       (87U)
#define EDMA_CHN88_NUMBER       (88U)
#define EDMA_CHN89_NUMBER       (89U)
#define EDMA_CHN90_NUMBER       (90U)
#define EDMA_CHN91_NUMBER       (91U)
#define EDMA_CHN92_NUMBER       (92U)
#define EDMA_CHN93_NUMBER       (93U)
#define EDMA_CHN94_NUMBER       (94U)
#define EDMA_CHN95_NUMBER       (95U)
#define EDMA_CHN96_NUMBER       (96U)
#define EDMA_CHN97_NUMBER       (97U)
#define EDMA_CHN98_NUMBER       (98U)
#define EDMA_CHN99_NUMBER       (99U)
#define EDMA_CHN100_NUMBER      (100U)
#define EDMA_CHN101_NUMBER      (101U)
#define EDMA_CHN102_NUMBER      (102U)
#define EDMA_CHN103_NUMBER      (103U)
#define EDMA_CHN104_NUMBER      (104U)
#define EDMA_CHN105_NUMBER      (105U)
#define EDMA_CHN106_NUMBER      (106U)
#define EDMA_CHN107_NUMBER      (107U)
#define EDMA_CHN108_NUMBER      (108U)
#define EDMA_CHN109_NUMBER      (109U)
#define EDMA_CHN110_NUMBER      (110U)
#define EDMA_CHN111_NUMBER      (111U)
#define EDMA_CHN112_NUMBER      (112U)
#define EDMA_CHN113_NUMBER      (113U)
#define EDMA_CHN114_NUMBER      (114U)
#define EDMA_CHN115_NUMBER      (115U)
#define EDMA_CHN116_NUMBER      (116U)
#define EDMA_CHN117_NUMBER      (117U)
#define EDMA_CHN118_NUMBER      (118U)
#define EDMA_CHN119_NUMBER      (119U)
#define EDMA_CHN120_NUMBER      (120U)
#define EDMA_CHN121_NUMBER      (121U)
#define EDMA_CHN122_NUMBER      (122U)
#define EDMA_CHN123_NUMBER      (123U)
#define EDMA_CHN124_NUMBER      (124U)
#define EDMA_CHN125_NUMBER      (125U)
#define EDMA_CHN126_NUMBER      (126U)
#define EDMA_CHN127_NUMBER      (127U)

#define DMAMUX_AVAILABLE
#define DMAMUX_HAS_TRIG

#define DMAMUX_CHANNELS                         (16U)
#define DMAMUX_SOURCE_NUMS                      (64U)

#define DMAMUX_CHN_REG_INDEX(x)                 (x)
#define DMAMUX_CHCFG_ENBL(x)                    (uint8)((uint32)(x) << DMAMUX_CHCFG_ENBL_SHIFT)
#define DMAMUX_CHCFG_TRIG(x)                    (uint8)((uint32)(x) << DMAMUX_CHCFG_TRIG_SHIFT)
#define DMAMUX_CHCFG_SOURCE(x)                  ((x) << DMAMUX_CHCFG_SOURCE_SHIFT)

#define DMAMUX_CH_WIDTH                         (6U)
#define DMAMUX_REQ_SRC_TO_INSTANCE(x)           ((x) >> (uint32)DMAMUX_CH_WIDTH)
#define DMAMUX_REQ_SRC_TO_CH(x)                 ((x) & ((uint32)DMAMUX_SOURCE_NUMS - 1U))
#ifdef RESOURCE_SUPPORT_DMAMUX10
LOCAL_INLINE FUNC(uint8, EDMA_CODE) DMAMUX_DMA_CH_TO_CH(VAR(uint8, AUTOMATIC) x)    /*  PRQA S 3240 */
{
    if(x < 32U)
    {
        return (x & 0x7u);
    }
    else if(x < 112U)
    {
        return (x & 0xfu);
    }
    else
    {
        return (x & 0x7u);
    }
}/*  PRQA S 0605 */
#else
#define DMAMUX_DMA_CH_TO_CH(x)                  (((x) < 32U)?((x) & (0x7U)):((x) & (15U)))
#endif

#define EDMA_CHANNELS                           (64U)
#define EDMA_CH_WIDTH                           (6U)
#define EDMA_MCH_TO_INSTANCE(x)                 ((x) >> EDMA_CH_WIDTH)
#define EDMA_MCH_TO_CH(x)                       ((x) & ((uint32)EDMA_CHANNELS - 1U))
#define EDMA_CHN_TO_DCHPRI_INDEX(x)             (x)
#define EDMA_INSTANCE_COUNT                     (2U)
#define EDMA_MAPPED_CHANNELS                    (EDMA_CHANNELS * EDMA_INSTANCE_COUNT)

typedef volatile struct eDMA_tag  DMA_Type;

#define DMA_0_BASE                              (0xFC0A0000UL)
#define DMA_0_P                                 ((DMA_Type *)DMA_0_BASE)
#define DMA_1_BASE                              (0xFC0A4000UL)
#define DMA_1_P                                 ((DMA_Type *)DMA_1_BASE)
#define DMA_BASE_ADDRS                          { DMA_0_BASE, DMA_1_BASE }
#define DMA_BASE_PTRS                           { DMA_0_P, DMA_1_P }
#define DMA_CHN_IRQS                            { DMA0_CH0_IRQn,   DMA0_CH1_IRQn,   \
                                                  DMA0_CH2_IRQn,   DMA0_CH3_IRQn,   \
                                                  DMA0_CH4_IRQn,   DMA0_CH5_IRQn,   \
                                                  DMA0_CH6_IRQn,   DMA0_CH7_IRQn,   \
                                                  DMA0_CH8_IRQn,   DMA0_CH9_IRQn,   \
                                                  DMA0_CH10_IRQn,  DMA0_CH11_IRQn,  \
                                                  DMA0_CH12_IRQn,  DMA0_CH13_IRQn,  \
                                                  DMA0_CH14_IRQn,  DMA0_CH15_IRQn,  \
                                                  DMA0_CH16_IRQn,  DMA0_CH17_IRQn,  \
                                                  DMA0_CH18_IRQn,  DMA0_CH19_IRQn,  \
                                                  DMA0_CH20_IRQn,  DMA0_CH21_IRQn,  \
                                                  DMA0_CH22_IRQn,  DMA0_CH23_IRQn,  \
                                                  DMA0_CH24_IRQn,  DMA0_CH25_IRQn,  \
                                                  DMA0_CH26_IRQn,  DMA0_CH27_IRQn,  \
                                                  DMA0_CH28_IRQn,  DMA0_CH29_IRQn,  \
                                                  DMA0_CH30_IRQn,  DMA0_CH31_IRQn,  \
                                                  DMA0_CH32_IRQn,  DMA0_CH33_IRQn,  \
                                                  DMA0_CH34_IRQn,  DMA0_CH35_IRQn,  \
                                                  DMA0_CH36_IRQn,  DMA0_CH37_IRQn,  \
                                                  DMA0_CH38_IRQn,  DMA0_CH39_IRQn,  \
                                                  DMA0_CH40_IRQn,  DMA0_CH41_IRQn,  \
                                                  DMA0_CH42_IRQn,  DMA0_CH43_IRQn,  \
                                                  DMA0_CH44_IRQn,  DMA0_CH45_IRQn,  \
                                                  DMA0_CH46_IRQn,  DMA0_CH47_IRQn, \
                                                  DMA0_CH48_IRQn, DMA0_CH49_IRQn, \
                                                  DMA0_CH50_IRQn, DMA0_CH51_IRQn, \
                                                  DMA0_CH52_IRQn, DMA0_CH53_IRQn, \
                                                  DMA0_CH54_IRQn, DMA0_CH55_IRQn, \
                                                  DMA0_CH56_IRQn, DMA0_CH57_IRQn, \
                                                  DMA0_CH58_IRQn, DMA0_CH59_IRQn, \
                                                  DMA0_CH60_IRQn, DMA0_CH61_IRQn, \
                                                  DMA0_CH62_IRQn, DMA0_CH63_IRQn, \
                                                  DMA1_CH0_IRQn,  DMA1_CH1_IRQn,  \
                                                  DMA1_CH2_IRQn,  DMA1_CH3_IRQn,  \
                                                  DMA1_CH4_IRQn,  DMA1_CH5_IRQn,  \
                                                  DMA1_CH6_IRQn,  DMA1_CH7_IRQn,  \
                                                  DMA1_CH8_IRQn,  DMA1_CH9_IRQn,  \
                                                  DMA1_CH10_IRQn, DMA1_CH11_IRQn, \
                                                  DMA1_CH12_IRQn, DMA1_CH13_IRQn, \
                                                  DMA1_CH14_IRQn, DMA1_CH15_IRQn, \
                                                  DMA1_CH16_IRQn, DMA1_CH17_IRQn, \
                                                  DMA1_CH18_IRQn, DMA1_CH19_IRQn, \
                                                  DMA1_CH20_IRQn, DMA1_CH21_IRQn, \
                                                  DMA1_CH22_IRQn, DMA1_CH23_IRQn, \
                                                  DMA1_CH24_IRQn, DMA1_CH25_IRQn, \
                                                  DMA1_CH26_IRQn, DMA1_CH27_IRQn, \
                                                  DMA1_CH28_IRQn, DMA1_CH29_IRQn, \
                                                  DMA1_CH30_IRQn, DMA1_CH31_IRQn, \
                                                  DMA1_CH32_IRQn, DMA1_CH33_IRQn, \
                                                  DMA1_CH34_IRQn, DMA1_CH35_IRQn, \
                                                  DMA1_CH36_IRQn, DMA1_CH37_IRQn, \
                                                  DMA1_CH38_IRQn, DMA1_CH39_IRQn, \
                                                  DMA1_CH40_IRQn, DMA1_CH41_IRQn, \
                                                  DMA1_CH42_IRQn, DMA1_CH43_IRQn, \
                                                  DMA1_CH44_IRQn, DMA1_CH45_IRQn, \
                                                  DMA1_CH46_IRQn, DMA1_CH47_IRQn, \
                                                  DMA1_CH48_IRQn, DMA1_CH49_IRQn, \
                                                  DMA1_CH50_IRQn, DMA1_CH51_IRQn, \
                                                  DMA1_CH52_IRQn, DMA1_CH53_IRQn, \
                                                  DMA1_CH54_IRQn, DMA1_CH55_IRQn, \
                                                  DMA1_CH56_IRQn, DMA1_CH57_IRQn, \
                                                  DMA1_CH58_IRQn, DMA1_CH59_IRQn, \
                                                  DMA1_CH60_IRQn, DMA1_CH61_IRQn, \
                                                  DMA1_CH62_IRQn, DMA1_CH63_IRQn  }
#define DMA_ERROR_IRQS                          { DMA0_ERR0_127_IRQn }

/*----------------------------------------------------------------------------
 -- DMA  Masks
 ---------------------------------------------------------------------------- */

#define DMA_CR_EDBG_MASK                        0x2u
#define DMA_CR_EDBG_SHIFT                       1u
#define DMA_CR_EDBG_WIDTH                       1u
#define DMA_CR_EDBG(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_EDBG_SHIFT)) \
                                                    &DMA_CR_EDBG_MASK)
#define DMA_CR_ERCA_MASK                        0x4u
#define DMA_CR_ERCA_SHIFT                       2u
#define DMA_CR_ERCA_WIDTH                       1u
#define DMA_CR_ERCA(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_ERCA_SHIFT)) \
                                                  &DMA_CR_ERCA_MASK)
#define DMA_CR_ERGA_MASK                        0x8u
#define DMA_CR_ERGA_SHIFT                       3u
#define DMA_CR_ERGA_WIDTH                       1u
#define DMA_CR_ERGA(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_ERGA_SHIFT)) \
                                                  &DMA_CR_ERGA_MASK)
#define DMA_CR_HOE_MASK                         0x10u
#define DMA_CR_HOE_SHIFT                        4u
#define DMA_CR_HOE_WIDTH                        1u
#define DMA_CR_HOE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_HOE_SHIFT)) \
                                                  &DMA_CR_HOE_MASK)
#define DMA_CR_HALT_MASK                        0x20u
#define DMA_CR_HALT_SHIFT                       5u
#define DMA_CR_HALT_WIDTH                       1u
#define DMA_CR_HALT(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_HALT_SHIFT)) \
                                                  &DMA_CR_HALT_MASK)
#define DMA_CR_CLM_MASK                         0x40u
#define DMA_CR_CLM_SHIFT                        6u
#define DMA_CR_CLM_WIDTH                        1u
#define DMA_CR_CLM(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_CLM_SHIFT)) \
                                                  &DMA_CR_CLM_MASK)
#define DMA_CR_EMLM_MASK                        0x80u
#define DMA_CR_EMLM_SHIFT                       7u
#define DMA_CR_EMLM_WIDTH                       1u
#define DMA_CR_EMLM(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_EMLM_SHIFT)) \
                                                  &DMA_CR_EMLM_MASK)
#define DMA_CR_GRP0PRI_MASK                     0x300u
#define DMA_CR_GRP0PRI_SHIFT                    8u
#define DMA_CR_GRP0PRI_WIDTH                    2u
#define DMA_CR_GRP0PRI(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_GRP0PRI_SHIFT)) \
                                                  &DMA_CR_GRP0PRI_MASK)
#define DMA_CR_GRP1PRI_MASK                     0xC00u
#define DMA_CR_GRP1PRI_SHIFT                    10u
#define DMA_CR_GRP1PRI_WIDTH                    2u
#define DMA_CR_GRP1PRI(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_GRP1PRI_SHIFT)) \
                                                  &DMA_CR_GRP1PRI_MASK)
#define DMA_CR_GRP2PRI_MASK                     0x3000u
#define DMA_CR_GRP2PRI_SHIFT                    12u
#define DMA_CR_GRP2PRI_WIDTH                    2u
#define DMA_CR_GRP2PRI(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_GRP2PRI_SHIFT)) \
                                                  &DMA_CR_GRP2PRI_MASK)
#define DMA_CR_GRP3PRI_MASK                     0xC000u
#define DMA_CR_GRP3PRI_SHIFT                    14u
#define DMA_CR_GRP3PRI_WIDTH                    2u
#define DMA_CR_GRP3PRI(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_GRP3PRI_SHIFT)) \
                                                  &DMA_CR_GRP3PRI_MASK)
#define DMA_CR_ECX_MASK                         0x10000u
#define DMA_CR_ECX_SHIFT                        16u
#define DMA_CR_ECX_WIDTH                        1u
#define DMA_CR_ECX(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_ECX_SHIFT)) \
                                                  &DMA_CR_ECX_MASK)
#define DMA_CR_CX_MASK                          0x20000u
#define DMA_CR_CX_SHIFT                         17u
#define DMA_CR_CX_WIDTH                         1u
#define DMA_CR_CX(x)                            (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_CX_SHIFT)) \
                                                  &DMA_CR_CX_MASK)
/* ES Bit Fields */
#define DMA_ES_DBE_MASK                         0x1u
#define DMA_ES_DBE_SHIFT                        0u
#define DMA_ES_DBE_WIDTH                        1u
#define DMA_ES_DBE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_DBE_SHIFT)) \
                                                  &DMA_ES_DBE_MASK)
#define DMA_ES_SBE_MASK                         0x2u
#define DMA_ES_SBE_SHIFT                        1u
#define DMA_ES_SBE_WIDTH                        1u
#define DMA_ES_SBE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_SBE_SHIFT)) \
                                                  &DMA_ES_SBE_MASK)
#define DMA_ES_SGE_MASK                         0x4u
#define DMA_ES_SGE_SHIFT                        2u
#define DMA_ES_SGE_WIDTH                        1u
#define DMA_ES_SGE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_SGE_SHIFT)) \
                                                  &DMA_ES_SGE_MASK)
#define DMA_ES_NCE_MASK                         0x8u
#define DMA_ES_NCE_SHIFT                        3u
#define DMA_ES_NCE_WIDTH                        1u
#define DMA_ES_NCE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_NCE_SHIFT)) \
                                                  &DMA_ES_NCE_MASK)
#define DMA_ES_DOE_MASK                         0x10u
#define DMA_ES_DOE_SHIFT                        4u
#define DMA_ES_DOE_WIDTH                        1u
#define DMA_ES_DOE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_DOE_SHIFT)) \
                                                  &DMA_ES_DOE_MASK)
#define DMA_ES_DAE_MASK                         0x20u
#define DMA_ES_DAE_SHIFT                        5u
#define DMA_ES_DAE_WIDTH                        1u
#define DMA_ES_DAE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_DAE_SHIFT)) \
                                                  &DMA_ES_DAE_MASK)
#define DMA_ES_SOE_MASK                         0x40u
#define DMA_ES_SOE_SHIFT                        6u
#define DMA_ES_SOE_WIDTH                        1u
#define DMA_ES_SOE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_SOE_SHIFT)) \
                                                  &DMA_ES_SOE_MASK)
#define DMA_ES_SAE_MASK                         0x80u
#define DMA_ES_SAE_SHIFT                        7u
#define DMA_ES_SAE_WIDTH                        1u
#define DMA_ES_SAE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_SAE_SHIFT)) \
                                                  &DMA_ES_SAE_MASK)
#define DMA_ES_ERRCHN_MASK                      0x3F00u
#define DMA_ES_ERRCHN_SHIFT                     8u
#define DMA_ES_ERRCHN_WIDTH                     6u
#define DMA_ES_ERRCHN(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_ERRCHN_SHIFT)) \
                                                  &DMA_ES_ERRCHN_MASK)
#define DMA_ES_CPE_MASK                         0x4000u
#define DMA_ES_CPE_SHIFT                        14u
#define DMA_ES_CPE_WIDTH                        1u
#define DMA_ES_CPE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_CPE_SHIFT)) \
                                                  &DMA_ES_CPE_MASK)
#define DMA_ES_GPE_MASK                         0x8000u
#define DMA_ES_GPE_SHIFT                        15u
#define DMA_ES_GPE_WIDTH                        1u
#define DMA_ES_GPE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_GPE_SHIFT)) \
                                                  &DMA_ES_GPE_MASK)
#define DMA_ES_ECX_MASK                         0x10000u
#define DMA_ES_ECX_SHIFT                        16u
#define DMA_ES_ECX_WIDTH                        1u
#define DMA_ES_ECX(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_ECX_SHIFT)) \
                                                  &DMA_ES_ECX_MASK)
#define DMA_ES_UCE_MASK                         0x20000u
#define DMA_ES_UCE_SHIFT                        17u
#define DMA_ES_UCE_WIDTH                        1u
#define DMA_ES_UCE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_UCE_SHIFT)) \
                                                  &DMA_ES_UCE_MASK)
#define DMA_ES_VLD_MASK                         0x80000000u
#define DMA_ES_VLD_SHIFT                        31u
#define DMA_ES_VLD_WIDTH                        1u
#define DMA_ES_VLD(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_VLD_SHIFT)) \
                                                  &DMA_ES_VLD_MASK)
/* ERQH Bit Fields */
#define DMA_ERQH_ERQ32_MASK                     0x1u
#define DMA_ERQH_ERQ32_SHIFT                    0u
#define DMA_ERQH_ERQ32_WIDTH                    1u
#define DMA_ERQH_ERQ32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ32_SHIFT)) \
                                                  &DMA_ERQH_ERQ32_MASK)
#define DMA_ERQH_ERQ33_MASK                     0x2u
#define DMA_ERQH_ERQ33_SHIFT                    1u
#define DMA_ERQH_ERQ33_WIDTH                    1u
#define DMA_ERQH_ERQ33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ33_SHIFT)) \
                                                  &DMA_ERQH_ERQ33_MASK)
#define DMA_ERQH_ERQ34_MASK                     0x4u
#define DMA_ERQH_ERQ34_SHIFT                    2u
#define DMA_ERQH_ERQ34_WIDTH                    1u
#define DMA_ERQH_ERQ34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ34_SHIFT)) \
                                                  &DMA_ERQH_ERQ34_MASK)
#define DMA_ERQH_ERQ35_MASK                     0x8u
#define DMA_ERQH_ERQ35_SHIFT                    3u
#define DMA_ERQH_ERQ35_WIDTH                    1u
#define DMA_ERQH_ERQ35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ35_SHIFT)) \
                                                  &DMA_ERQH_ERQ35_MASK)
#define DMA_ERQH_ERQ36_MASK                     0x10u
#define DMA_ERQH_ERQ36_SHIFT                    4u
#define DMA_ERQH_ERQ36_WIDTH                    1u
#define DMA_ERQH_ERQ36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ36_SHIFT)) \
                                                  &DMA_ERQH_ERQ36_MASK)
#define DMA_ERQH_ERQ37_MASK                     0x20u
#define DMA_ERQH_ERQ37_SHIFT                    5u
#define DMA_ERQH_ERQ37_WIDTH                    1u
#define DMA_ERQH_ERQ37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ37_SHIFT)) \
                                                  &DMA_ERQH_ERQ37_MASK)
#define DMA_ERQH_ERQ38_MASK                     0x40u
#define DMA_ERQH_ERQ38_SHIFT                    6u
#define DMA_ERQH_ERQ38_WIDTH                    1u
#define DMA_ERQH_ERQ38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ38_SHIFT)) \
                                                  &DMA_ERQH_ERQ38_MASK)
#define DMA_ERQH_ERQ39_MASK                     0x80u
#define DMA_ERQH_ERQ39_SHIFT                    7u
#define DMA_ERQH_ERQ39_WIDTH                    1u
#define DMA_ERQH_ERQ39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ39_SHIFT)) \
                                                  &DMA_ERQH_ERQ39_MASK)
#define DMA_ERQH_ERQ40_MASK                     0x100u
#define DMA_ERQH_ERQ40_SHIFT                    8u
#define DMA_ERQH_ERQ40_WIDTH                    1u
#define DMA_ERQH_ERQ40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ40_SHIFT)) \
                                                  &DMA_ERQH_ERQ40_MASK)
#define DMA_ERQH_ERQ41_MASK                     0x200u
#define DMA_ERQH_ERQ41_SHIFT                    9u
#define DMA_ERQH_ERQ41_WIDTH                    1u
#define DMA_ERQH_ERQ41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ41_SHIFT)) \
                                                  &DMA_ERQH_ERQ41_MASK)
#define DMA_ERQH_ERQ42_MASK                     0x400u
#define DMA_ERQH_ERQ42_SHIFT                    10u
#define DMA_ERQH_ERQ42_WIDTH                    1u
#define DMA_ERQH_ERQ42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ42_SHIFT)) \
                                                  &DMA_ERQH_ERQ42_MASK)
#define DMA_ERQH_ERQ43_MASK                     0x800u
#define DMA_ERQH_ERQ43_SHIFT                    11u
#define DMA_ERQH_ERQ43_WIDTH                    1u
#define DMA_ERQH_ERQ43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ43_SHIFT)) \
                                                  &DMA_ERQH_ERQ43_MASK)
#define DMA_ERQH_ERQ44_MASK                     0x1000u
#define DMA_ERQH_ERQ44_SHIFT                    12u
#define DMA_ERQH_ERQ44_WIDTH                    1u
#define DMA_ERQH_ERQ44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ44_SHIFT)) \
                                                  &DMA_ERQH_ERQ44_MASK)
#define DMA_ERQH_ERQ45_MASK                     0x2000u
#define DMA_ERQH_ERQ45_SHIFT                    13u
#define DMA_ERQH_ERQ45_WIDTH                    1u
#define DMA_ERQH_ERQ45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ45_SHIFT)) \
                                                  &DMA_ERQH_ERQ45_MASK)
#define DMA_ERQH_ERQ46_MASK                     0x4000u
#define DMA_ERQH_ERQ46_SHIFT                    14u
#define DMA_ERQH_ERQ46_WIDTH                    1u
#define DMA_ERQH_ERQ46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ46_SHIFT)) \
                                                  &DMA_ERQH_ERQ46_MASK)
#define DMA_ERQH_ERQ47_MASK                     0x8000u
#define DMA_ERQH_ERQ47_SHIFT                    15u
#define DMA_ERQH_ERQ47_WIDTH                    1u
#define DMA_ERQH_ERQ47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ47_SHIFT)) \
                                                  &DMA_ERQH_ERQ47_MASK)
#define DMA_ERQH_ERQ48_MASK                     0x10000u
#define DMA_ERQH_ERQ48_SHIFT                    16u
#define DMA_ERQH_ERQ48_WIDTH                    1u
#define DMA_ERQH_ERQ48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ48_SHIFT)) \
                                                  &DMA_ERQH_ERQ48_MASK)
#define DMA_ERQH_ERQ49_MASK                     0x20000u
#define DMA_ERQH_ERQ49_SHIFT                    17u
#define DMA_ERQH_ERQ49_WIDTH                    1u
#define DMA_ERQH_ERQ49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ49_SHIFT)) \
                                                  &DMA_ERQH_ERQ49_MASK)
#define DMA_ERQH_ERQ50_MASK                     0x40000u
#define DMA_ERQH_ERQ50_SHIFT                    18u
#define DMA_ERQH_ERQ50_WIDTH                    1u
#define DMA_ERQH_ERQ50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ50_SHIFT)) \
                                                  &DMA_ERQH_ERQ50_MASK)
#define DMA_ERQH_ERQ51_MASK                     0x80000u
#define DMA_ERQH_ERQ51_SHIFT                    19u
#define DMA_ERQH_ERQ51_WIDTH                    1u
#define DMA_ERQH_ERQ51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ51_SHIFT)) \
                                                  &DMA_ERQH_ERQ51_MASK)
#define DMA_ERQH_ERQ52_MASK                     0x100000u
#define DMA_ERQH_ERQ52_SHIFT                    20u
#define DMA_ERQH_ERQ52_WIDTH                    1u
#define DMA_ERQH_ERQ52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ52_SHIFT)) \
                                                  &DMA_ERQH_ERQ52_MASK)
#define DMA_ERQH_ERQ53_MASK                     0x200000u
#define DMA_ERQH_ERQ53_SHIFT                    21u
#define DMA_ERQH_ERQ53_WIDTH                    1u
#define DMA_ERQH_ERQ53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ53_SHIFT)) \
                                                  &DMA_ERQH_ERQ53_MASK)
#define DMA_ERQH_ERQ54_MASK                     0x400000u
#define DMA_ERQH_ERQ54_SHIFT                    22u
#define DMA_ERQH_ERQ54_WIDTH                    1u
#define DMA_ERQH_ERQ54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ54_SHIFT)) \
                                                  &DMA_ERQH_ERQ54_MASK)
#define DMA_ERQH_ERQ55_MASK                     0x800000u
#define DMA_ERQH_ERQ55_SHIFT                    23u
#define DMA_ERQH_ERQ55_WIDTH                    1u
#define DMA_ERQH_ERQ55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ55_SHIFT)) \
                                                  &DMA_ERQH_ERQ55_MASK)
#define DMA_ERQH_ERQ56_MASK                     0x1000000u
#define DMA_ERQH_ERQ56_SHIFT                    24u
#define DMA_ERQH_ERQ56_WIDTH                    1u
#define DMA_ERQH_ERQ56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ56_SHIFT)) \
                                                  &DMA_ERQH_ERQ56_MASK)
#define DMA_ERQH_ERQ57_MASK                     0x2000000u
#define DMA_ERQH_ERQ57_SHIFT                    25u
#define DMA_ERQH_ERQ57_WIDTH                    1u
#define DMA_ERQH_ERQ57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ57_SHIFT)) \
                                                  &DMA_ERQH_ERQ57_MASK)
#define DMA_ERQH_ERQ58_MASK                     0x4000000u
#define DMA_ERQH_ERQ58_SHIFT                    26u
#define DMA_ERQH_ERQ58_WIDTH                    1u
#define DMA_ERQH_ERQ58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ58_SHIFT)) \
                                                  &DMA_ERQH_ERQ58_MASK)
#define DMA_ERQH_ERQ59_MASK                     0x8000000u
#define DMA_ERQH_ERQ59_SHIFT                    27u
#define DMA_ERQH_ERQ59_WIDTH                    1u
#define DMA_ERQH_ERQ59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ59_SHIFT)) \
                                                  &DMA_ERQH_ERQ59_MASK)
#define DMA_ERQH_ERQ60_MASK                     0x10000000u
#define DMA_ERQH_ERQ60_SHIFT                    28u
#define DMA_ERQH_ERQ60_WIDTH                    1u
#define DMA_ERQH_ERQ60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ60_SHIFT)) \
                                                  &DMA_ERQH_ERQ60_MASK)
#define DMA_ERQH_ERQ61_MASK                     0x20000000u
#define DMA_ERQH_ERQ61_SHIFT                    29u
#define DMA_ERQH_ERQ61_WIDTH                    1u
#define DMA_ERQH_ERQ61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ61_SHIFT)) \
                                                  &DMA_ERQH_ERQ61_MASK)
#define DMA_ERQH_ERQ62_MASK                     0x40000000u
#define DMA_ERQH_ERQ62_SHIFT                    30u
#define DMA_ERQH_ERQ62_WIDTH                    1u
#define DMA_ERQH_ERQ62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ62_SHIFT)) \
                                                  &DMA_ERQH_ERQ62_MASK)
#define DMA_ERQH_ERQ63_MASK                     0x80000000u
#define DMA_ERQH_ERQ63_SHIFT                    31u
#define DMA_ERQH_ERQ63_WIDTH                    1u
#define DMA_ERQH_ERQ63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ63_SHIFT)) \
                                                  &DMA_ERQH_ERQ63_MASK)
/* ERQL Bit Fields */
#define DMA_ERQL_ERQ0_MASK                      0x1u
#define DMA_ERQL_ERQ0_SHIFT                     0u
#define DMA_ERQL_ERQ0_WIDTH                     1u
#define DMA_ERQL_ERQ0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ0_SHIFT)) \
                                                  &DMA_ERQL_ERQ0_MASK)
#define DMA_ERQL_ERQ1_MASK                      0x2u
#define DMA_ERQL_ERQ1_SHIFT                     1u
#define DMA_ERQL_ERQ1_WIDTH                     1u
#define DMA_ERQL_ERQ1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ1_SHIFT)) \
                                                  &DMA_ERQL_ERQ1_MASK)
#define DMA_ERQL_ERQ2_MASK                      0x4u
#define DMA_ERQL_ERQ2_SHIFT                     2u
#define DMA_ERQL_ERQ2_WIDTH                     1u
#define DMA_ERQL_ERQ2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ2_SHIFT)) \
                                                  &DMA_ERQL_ERQ2_MASK)
#define DMA_ERQL_ERQ3_MASK                      0x8u
#define DMA_ERQL_ERQ3_SHIFT                     3u
#define DMA_ERQL_ERQ3_WIDTH                     1u
#define DMA_ERQL_ERQ3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ3_SHIFT)) \
                                                  &DMA_ERQL_ERQ3_MASK)
#define DMA_ERQL_ERQ4_MASK                      0x10u
#define DMA_ERQL_ERQ4_SHIFT                     4u
#define DMA_ERQL_ERQ4_WIDTH                     1u
#define DMA_ERQL_ERQ4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ4_SHIFT)) \
                                                  &DMA_ERQL_ERQ4_MASK)
#define DMA_ERQL_ERQ5_MASK                      0x20u
#define DMA_ERQL_ERQ5_SHIFT                     5u
#define DMA_ERQL_ERQ5_WIDTH                     1u
#define DMA_ERQL_ERQ5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ5_SHIFT)) \
                                                  &DMA_ERQL_ERQ5_MASK)
#define DMA_ERQL_ERQ6_MASK                      0x40u
#define DMA_ERQL_ERQ6_SHIFT                     6u
#define DMA_ERQL_ERQ6_WIDTH                     1u
#define DMA_ERQL_ERQ6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ6_SHIFT)) \
                                                  &DMA_ERQL_ERQ6_MASK)
#define DMA_ERQL_ERQ7_MASK                      0x80u
#define DMA_ERQL_ERQ7_SHIFT                     7u
#define DMA_ERQL_ERQ7_WIDTH                     1u
#define DMA_ERQL_ERQ7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ7_SHIFT)) \
                                                  &DMA_ERQL_ERQ7_MASK)
#define DMA_ERQL_ERQ8_MASK                      0x100u
#define DMA_ERQL_ERQ8_SHIFT                     8u
#define DMA_ERQL_ERQ8_WIDTH                     1u
#define DMA_ERQL_ERQ8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ8_SHIFT)) \
                                                  &DMA_ERQL_ERQ8_MASK)
#define DMA_ERQL_ERQ9_MASK                      0x200u
#define DMA_ERQL_ERQ9_SHIFT                     9u
#define DMA_ERQL_ERQ9_WIDTH                     1u
#define DMA_ERQL_ERQ9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ9_SHIFT)) \
                                                  &DMA_ERQL_ERQ9_MASK)
#define DMA_ERQL_ERQ10_MASK                     0x400u
#define DMA_ERQL_ERQ10_SHIFT                    10u
#define DMA_ERQL_ERQ10_WIDTH                    1u
#define DMA_ERQL_ERQ10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ10_SHIFT)) \
                                                  &DMA_ERQL_ERQ10_MASK)
#define DMA_ERQL_ERQ11_MASK                     0x800u
#define DMA_ERQL_ERQ11_SHIFT                    11u
#define DMA_ERQL_ERQ11_WIDTH                    1u
#define DMA_ERQL_ERQ11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ11_SHIFT)) \
                                                  &DMA_ERQL_ERQ11_MASK)
#define DMA_ERQL_ERQ12_MASK                     0x1000u
#define DMA_ERQL_ERQ12_SHIFT                    12u
#define DMA_ERQL_ERQ12_WIDTH                    1u
#define DMA_ERQL_ERQ12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ12_SHIFT)) \
                                                  &DMA_ERQL_ERQ12_MASK)
#define DMA_ERQL_ERQ13_MASK                     0x2000u
#define DMA_ERQL_ERQ13_SHIFT                    13u
#define DMA_ERQL_ERQ13_WIDTH                    1u
#define DMA_ERQL_ERQ13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ13_SHIFT)) \
                                                  &DMA_ERQL_ERQ13_MASK)
#define DMA_ERQL_ERQ14_MASK                     0x4000u
#define DMA_ERQL_ERQ14_SHIFT                    14u
#define DMA_ERQL_ERQ14_WIDTH                    1u
#define DMA_ERQL_ERQ14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ14_SHIFT)) \
                                                  &DMA_ERQL_ERQ14_MASK)
#define DMA_ERQL_ERQ15_MASK                     0x8000u
#define DMA_ERQL_ERQ15_SHIFT                    15u
#define DMA_ERQL_ERQ15_WIDTH                    1u
#define DMA_ERQL_ERQ15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ15_SHIFT)) \
                                                  &DMA_ERQL_ERQ15_MASK)
#define DMA_ERQL_ERQ16_MASK                     0x10000u
#define DMA_ERQL_ERQ16_SHIFT                    16u
#define DMA_ERQL_ERQ16_WIDTH                    1u
#define DMA_ERQL_ERQ16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ16_SHIFT)) \
                                                  &DMA_ERQL_ERQ16_MASK)
#define DMA_ERQL_ERQ17_MASK                     0x20000u
#define DMA_ERQL_ERQ17_SHIFT                    17u
#define DMA_ERQL_ERQ17_WIDTH                    1u
#define DMA_ERQL_ERQ17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ17_SHIFT)) \
                                                  &DMA_ERQL_ERQ17_MASK)
#define DMA_ERQL_ERQ18_MASK                     0x40000u
#define DMA_ERQL_ERQ18_SHIFT                    18u
#define DMA_ERQL_ERQ18_WIDTH                    1u
#define DMA_ERQL_ERQ18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ18_SHIFT)) \
                                                  &DMA_ERQL_ERQ18_MASK)
#define DMA_ERQL_ERQ19_MASK                     0x80000u
#define DMA_ERQL_ERQ19_SHIFT                    19u
#define DMA_ERQL_ERQ19_WIDTH                    1u
#define DMA_ERQL_ERQ19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ19_SHIFT)) \
                                                  &DMA_ERQL_ERQ19_MASK)
#define DMA_ERQL_ERQ20_MASK                     0x100000u
#define DMA_ERQL_ERQ20_SHIFT                    20u
#define DMA_ERQL_ERQ20_WIDTH                    1u
#define DMA_ERQL_ERQ20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ20_SHIFT)) \
                                                  &DMA_ERQL_ERQ20_MASK)
#define DMA_ERQL_ERQ21_MASK                     0x200000u
#define DMA_ERQL_ERQ21_SHIFT                    21u
#define DMA_ERQL_ERQ21_WIDTH                    1u
#define DMA_ERQL_ERQ21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ21_SHIFT)) \
                                                  &DMA_ERQL_ERQ21_MASK)
#define DMA_ERQL_ERQ22_MASK                     0x400000u
#define DMA_ERQL_ERQ22_SHIFT                    22u
#define DMA_ERQL_ERQ22_WIDTH                    1u
#define DMA_ERQL_ERQ22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ22_SHIFT)) \
                                                  &DMA_ERQL_ERQ22_MASK)
#define DMA_ERQL_ERQ23_MASK                     0x800000u
#define DMA_ERQL_ERQ23_SHIFT                    23u
#define DMA_ERQL_ERQ23_WIDTH                    1u
#define DMA_ERQL_ERQ23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ23_SHIFT)) \
                                                  &DMA_ERQL_ERQ23_MASK)
#define DMA_ERQL_ERQ24_MASK                     0x1000000u
#define DMA_ERQL_ERQ24_SHIFT                    24u
#define DMA_ERQL_ERQ24_WIDTH                    1u
#define DMA_ERQL_ERQ24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ24_SHIFT)) \
                                                  &DMA_ERQL_ERQ24_MASK)
#define DMA_ERQL_ERQ25_MASK                     0x2000000u
#define DMA_ERQL_ERQ25_SHIFT                    25u
#define DMA_ERQL_ERQ25_WIDTH                    1u
#define DMA_ERQL_ERQ25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ25_SHIFT)) \
                                                  &DMA_ERQL_ERQ25_MASK)
#define DMA_ERQL_ERQ26_MASK                     0x4000000u
#define DMA_ERQL_ERQ26_SHIFT                    26u
#define DMA_ERQL_ERQ26_WIDTH                    1u
#define DMA_ERQL_ERQ26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ26_SHIFT)) \
                                                  &DMA_ERQL_ERQ26_MASK)
#define DMA_ERQL_ERQ27_MASK                     0x8000000u
#define DMA_ERQL_ERQ27_SHIFT                    27u
#define DMA_ERQL_ERQ27_WIDTH                    1u
#define DMA_ERQL_ERQ27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ27_SHIFT)) \
                                                  &DMA_ERQL_ERQ27_MASK)
#define DMA_ERQL_ERQ28_MASK                     0x10000000u
#define DMA_ERQL_ERQ28_SHIFT                    28u
#define DMA_ERQL_ERQ28_WIDTH                    1u
#define DMA_ERQL_ERQ28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ28_SHIFT)) \
                                                  &DMA_ERQL_ERQ28_MASK)
#define DMA_ERQL_ERQ29_MASK                     0x20000000u
#define DMA_ERQL_ERQ29_SHIFT                    29u
#define DMA_ERQL_ERQ29_WIDTH                    1u
#define DMA_ERQL_ERQ29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ29_SHIFT)) \
                                                  &DMA_ERQL_ERQ29_MASK)
#define DMA_ERQL_ERQ30_MASK                     0x40000000u
#define DMA_ERQL_ERQ30_SHIFT                    30u
#define DMA_ERQL_ERQ30_WIDTH                    1u
#define DMA_ERQL_ERQ30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ30_SHIFT)) \
                                                  &DMA_ERQL_ERQ30_MASK)
#define DMA_ERQL_ERQ31_MASK                     0x80000000u
#define DMA_ERQL_ERQ31_SHIFT                    31u
#define DMA_ERQL_ERQ31_WIDTH                    1u
#define DMA_ERQL_ERQ31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ31_SHIFT)) \
                                                  &DMA_ERQL_ERQ31_MASK)
/* EEIH Bit Fields */
#define DMA_EEIH_EEI32_MASK                     0x1u
#define DMA_EEIH_EEI32_SHIFT                    0u
#define DMA_EEIH_EEI32_WIDTH                    1u
#define DMA_EEIH_EEI32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI32_SHIFT)) \
                                                  &DMA_EEIH_EEI32_MASK)
#define DMA_EEIH_EEI33_MASK                     0x2u
#define DMA_EEIH_EEI33_SHIFT                    1u
#define DMA_EEIH_EEI33_WIDTH                    1u
#define DMA_EEIH_EEI33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI33_SHIFT)) \
                                                  &DMA_EEIH_EEI33_MASK)
#define DMA_EEIH_EEI34_MASK                     0x4u
#define DMA_EEIH_EEI34_SHIFT                    2u
#define DMA_EEIH_EEI34_WIDTH                    1u
#define DMA_EEIH_EEI34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI34_SHIFT)) \
                                                  &DMA_EEIH_EEI34_MASK)
#define DMA_EEIH_EEI35_MASK                     0x8u
#define DMA_EEIH_EEI35_SHIFT                    3u
#define DMA_EEIH_EEI35_WIDTH                    1u
#define DMA_EEIH_EEI35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI35_SHIFT)) \
                                                  &DMA_EEIH_EEI35_MASK)
#define DMA_EEIH_EEI36_MASK                     0x10u
#define DMA_EEIH_EEI36_SHIFT                    4u
#define DMA_EEIH_EEI36_WIDTH                    1u
#define DMA_EEIH_EEI36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI36_SHIFT)) \
                                                  &DMA_EEIH_EEI36_MASK)
#define DMA_EEIH_EEI37_MASK                     0x20u
#define DMA_EEIH_EEI37_SHIFT                    5u
#define DMA_EEIH_EEI37_WIDTH                    1u
#define DMA_EEIH_EEI37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI37_SHIFT)) \
                                                  &DMA_EEIH_EEI37_MASK)
#define DMA_EEIH_EEI38_MASK                     0x40u
#define DMA_EEIH_EEI38_SHIFT                    6u
#define DMA_EEIH_EEI38_WIDTH                    1u
#define DMA_EEIH_EEI38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI38_SHIFT)) \
                                                  &DMA_EEIH_EEI38_MASK)
#define DMA_EEIH_EEI39_MASK                     0x80u
#define DMA_EEIH_EEI39_SHIFT                    7u
#define DMA_EEIH_EEI39_WIDTH                    1u
#define DMA_EEIH_EEI39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI39_SHIFT)) \
                                                  &DMA_EEIH_EEI39_MASK)
#define DMA_EEIH_EEI40_MASK                     0x100u
#define DMA_EEIH_EEI40_SHIFT                    8u
#define DMA_EEIH_EEI40_WIDTH                    1u
#define DMA_EEIH_EEI40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI40_SHIFT)) \
                                                  &DMA_EEIH_EEI40_MASK)
#define DMA_EEIH_EEI41_MASK                     0x200u
#define DMA_EEIH_EEI41_SHIFT                    9u
#define DMA_EEIH_EEI41_WIDTH                    1u
#define DMA_EEIH_EEI41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI41_SHIFT)) \
                                                  &DMA_EEIH_EEI41_MASK)
#define DMA_EEIH_EEI42_MASK                     0x400u
#define DMA_EEIH_EEI42_SHIFT                    10u
#define DMA_EEIH_EEI42_WIDTH                    1u
#define DMA_EEIH_EEI42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI42_SHIFT)) \
                                                  &DMA_EEIH_EEI42_MASK)
#define DMA_EEIH_EEI43_MASK                     0x800u
#define DMA_EEIH_EEI43_SHIFT                    11u
#define DMA_EEIH_EEI43_WIDTH                    1u
#define DMA_EEIH_EEI43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI43_SHIFT)) \
                                                  &DMA_EEIH_EEI43_MASK)
#define DMA_EEIH_EEI44_MASK                     0x1000u
#define DMA_EEIH_EEI44_SHIFT                    12u
#define DMA_EEIH_EEI44_WIDTH                    1u
#define DMA_EEIH_EEI44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI44_SHIFT)) \
                                                  &DMA_EEIH_EEI44_MASK)
#define DMA_EEIH_EEI45_MASK                     0x2000u
#define DMA_EEIH_EEI45_SHIFT                    13u
#define DMA_EEIH_EEI45_WIDTH                    1u
#define DMA_EEIH_EEI45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI45_SHIFT)) \
                                                  &DMA_EEIH_EEI45_MASK)
#define DMA_EEIH_EEI46_MASK                     0x4000u
#define DMA_EEIH_EEI46_SHIFT                    14u
#define DMA_EEIH_EEI46_WIDTH                    1u
#define DMA_EEIH_EEI46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI46_SHIFT)) \
                                                  &DMA_EEIH_EEI46_MASK)
#define DMA_EEIH_EEI47_MASK                     0x8000u
#define DMA_EEIH_EEI47_SHIFT                    15u
#define DMA_EEIH_EEI47_WIDTH                    1u
#define DMA_EEIH_EEI47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI47_SHIFT)) \
                                                  &DMA_EEIH_EEI47_MASK)
#define DMA_EEIH_EEI48_MASK                     0x10000u
#define DMA_EEIH_EEI48_SHIFT                    16u
#define DMA_EEIH_EEI48_WIDTH                    1u
#define DMA_EEIH_EEI48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI48_SHIFT)) \
                                                  &DMA_EEIH_EEI48_MASK)
#define DMA_EEIH_EEI49_MASK                     0x20000u
#define DMA_EEIH_EEI49_SHIFT                    17u
#define DMA_EEIH_EEI49_WIDTH                    1u
#define DMA_EEIH_EEI49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI49_SHIFT)) \
                                                  &DMA_EEIH_EEI49_MASK)
#define DMA_EEIH_EEI50_MASK                     0x40000u
#define DMA_EEIH_EEI50_SHIFT                    18u
#define DMA_EEIH_EEI50_WIDTH                    1u
#define DMA_EEIH_EEI50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI50_SHIFT)) \
                                                  &DMA_EEIH_EEI50_MASK)
#define DMA_EEIH_EEI51_MASK                     0x80000u
#define DMA_EEIH_EEI51_SHIFT                    19u
#define DMA_EEIH_EEI51_WIDTH                    1u
#define DMA_EEIH_EEI51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI51_SHIFT)) \
                                                  &DMA_EEIH_EEI51_MASK)
#define DMA_EEIH_EEI52_MASK                     0x100000u
#define DMA_EEIH_EEI52_SHIFT                    20u
#define DMA_EEIH_EEI52_WIDTH                    1u
#define DMA_EEIH_EEI52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI52_SHIFT)) \
                                                  &DMA_EEIH_EEI52_MASK)
#define DMA_EEIH_EEI53_MASK                     0x200000u
#define DMA_EEIH_EEI53_SHIFT                    21u
#define DMA_EEIH_EEI53_WIDTH                    1u
#define DMA_EEIH_EEI53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI53_SHIFT)) \
                                                  &DMA_EEIH_EEI53_MASK)
#define DMA_EEIH_EEI54_MASK                     0x400000u
#define DMA_EEIH_EEI54_SHIFT                    22u
#define DMA_EEIH_EEI54_WIDTH                    1u
#define DMA_EEIH_EEI54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI54_SHIFT)) \
                                                  &DMA_EEIH_EEI54_MASK)
#define DMA_EEIH_EEI55_MASK                     0x800000u
#define DMA_EEIH_EEI55_SHIFT                    23u
#define DMA_EEIH_EEI55_WIDTH                    1u
#define DMA_EEIH_EEI55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI55_SHIFT)) \
                                                  &DMA_EEIH_EEI55_MASK)
#define DMA_EEIH_EEI56_MASK                     0x1000000u
#define DMA_EEIH_EEI56_SHIFT                    24u
#define DMA_EEIH_EEI56_WIDTH                    1u
#define DMA_EEIH_EEI56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI56_SHIFT)) \
                                                  &DMA_EEIH_EEI56_MASK)
#define DMA_EEIH_EEI57_MASK                     0x2000000u
#define DMA_EEIH_EEI57_SHIFT                    25u
#define DMA_EEIH_EEI57_WIDTH                    1u
#define DMA_EEIH_EEI57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI57_SHIFT)) \
                                                  &DMA_EEIH_EEI57_MASK)
#define DMA_EEIH_EEI58_MASK                     0x4000000u
#define DMA_EEIH_EEI58_SHIFT                    26u
#define DMA_EEIH_EEI58_WIDTH                    1u
#define DMA_EEIH_EEI58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI58_SHIFT)) \
                                                  &DMA_EEIH_EEI58_MASK)
#define DMA_EEIH_EEI59_MASK                     0x8000000u
#define DMA_EEIH_EEI59_SHIFT                    27u
#define DMA_EEIH_EEI59_WIDTH                    1u
#define DMA_EEIH_EEI59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI59_SHIFT)) \
                                                  &DMA_EEIH_EEI59_MASK)
#define DMA_EEIH_EEI60_MASK                     0x10000000u
#define DMA_EEIH_EEI60_SHIFT                    28u
#define DMA_EEIH_EEI60_WIDTH                    1u
#define DMA_EEIH_EEI60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI60_SHIFT)) \
                                                  &DMA_EEIH_EEI60_MASK)
#define DMA_EEIH_EEI61_MASK                     0x20000000u
#define DMA_EEIH_EEI61_SHIFT                    29u
#define DMA_EEIH_EEI61_WIDTH                    1u
#define DMA_EEIH_EEI61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI61_SHIFT)) \
                                                  &DMA_EEIH_EEI61_MASK)
#define DMA_EEIH_EEI62_MASK                     0x40000000u
#define DMA_EEIH_EEI62_SHIFT                    30u
#define DMA_EEIH_EEI62_WIDTH                    1u
#define DMA_EEIH_EEI62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI62_SHIFT)) \
                                                  &DMA_EEIH_EEI62_MASK)
#define DMA_EEIH_EEI63_MASK                     0x80000000u
#define DMA_EEIH_EEI63_SHIFT                    31u
#define DMA_EEIH_EEI63_WIDTH                    1u
#define DMA_EEIH_EEI63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI63_SHIFT)) \
                                                  &DMA_EEIH_EEI63_MASK)
/* EEIL Bit Fields */
#define DMA_EEIL_EEI0_MASK                      0x1u
#define DMA_EEIL_EEI0_SHIFT                     0u
#define DMA_EEIL_EEI0_WIDTH                     1u
#define DMA_EEIL_EEI0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI0_SHIFT)) \
                                                  &DMA_EEIL_EEI0_MASK)
#define DMA_EEIL_EEI1_MASK                      0x2u
#define DMA_EEIL_EEI1_SHIFT                     1u
#define DMA_EEIL_EEI1_WIDTH                     1u
#define DMA_EEIL_EEI1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI1_SHIFT)) \
                                                  &DMA_EEIL_EEI1_MASK)
#define DMA_EEIL_EEI2_MASK                      0x4u
#define DMA_EEIL_EEI2_SHIFT                     2u
#define DMA_EEIL_EEI2_WIDTH                     1u
#define DMA_EEIL_EEI2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI2_SHIFT)) \
                                                  &DMA_EEIL_EEI2_MASK)
#define DMA_EEIL_EEI3_MASK                      0x8u
#define DMA_EEIL_EEI3_SHIFT                     3u
#define DMA_EEIL_EEI3_WIDTH                     1u
#define DMA_EEIL_EEI3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI3_SHIFT)) \
                                                  &DMA_EEIL_EEI3_MASK)
#define DMA_EEIL_EEI4_MASK                      0x10u
#define DMA_EEIL_EEI4_SHIFT                     4u
#define DMA_EEIL_EEI4_WIDTH                     1u
#define DMA_EEIL_EEI4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI4_SHIFT)) \
                                                  &DMA_EEIL_EEI4_MASK)
#define DMA_EEIL_EEI5_MASK                      0x20u
#define DMA_EEIL_EEI5_SHIFT                     5u
#define DMA_EEIL_EEI5_WIDTH                     1u
#define DMA_EEIL_EEI5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI5_SHIFT)) \
                                                  &DMA_EEIL_EEI5_MASK)
#define DMA_EEIL_EEI6_MASK                      0x40u
#define DMA_EEIL_EEI6_SHIFT                     6u
#define DMA_EEIL_EEI6_WIDTH                     1u
#define DMA_EEIL_EEI6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI6_SHIFT)) \
                                                  &DMA_EEIL_EEI6_MASK)
#define DMA_EEIL_EEI7_MASK                      0x80u
#define DMA_EEIL_EEI7_SHIFT                     7u
#define DMA_EEIL_EEI7_WIDTH                     1u
#define DMA_EEIL_EEI7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI7_SHIFT)) \
                                                  &DMA_EEIL_EEI7_MASK)
#define DMA_EEIL_EEI8_MASK                      0x100u
#define DMA_EEIL_EEI8_SHIFT                     8u
#define DMA_EEIL_EEI8_WIDTH                     1u
#define DMA_EEIL_EEI8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI8_SHIFT)) \
                                                  &DMA_EEIL_EEI8_MASK)
#define DMA_EEIL_EEI9_MASK                      0x200u
#define DMA_EEIL_EEI9_SHIFT                     9u
#define DMA_EEIL_EEI9_WIDTH                     1u
#define DMA_EEIL_EEI9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI9_SHIFT)) \
                                                  &DMA_EEIL_EEI9_MASK)
#define DMA_EEIL_EEI10_MASK                     0x400u
#define DMA_EEIL_EEI10_SHIFT                    10u
#define DMA_EEIL_EEI10_WIDTH                    1u
#define DMA_EEIL_EEI10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI10_SHIFT)) \
                                                  &DMA_EEIL_EEI10_MASK)
#define DMA_EEIL_EEI11_MASK                     0x800u
#define DMA_EEIL_EEI11_SHIFT                    11u
#define DMA_EEIL_EEI11_WIDTH                    1u
#define DMA_EEIL_EEI11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI11_SHIFT)) \
                                                  &DMA_EEIL_EEI11_MASK)
#define DMA_EEIL_EEI12_MASK                     0x1000u
#define DMA_EEIL_EEI12_SHIFT                    12u
#define DMA_EEIL_EEI12_WIDTH                    1u
#define DMA_EEIL_EEI12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI12_SHIFT)) \
                                                  &DMA_EEIL_EEI12_MASK)
#define DMA_EEIL_EEI13_MASK                     0x2000u
#define DMA_EEIL_EEI13_SHIFT                    13u
#define DMA_EEIL_EEI13_WIDTH                    1u
#define DMA_EEIL_EEI13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI13_SHIFT)) \
                                                  &DMA_EEIL_EEI13_MASK)
#define DMA_EEIL_EEI14_MASK                     0x4000u
#define DMA_EEIL_EEI14_SHIFT                    14u
#define DMA_EEIL_EEI14_WIDTH                    1u
#define DMA_EEIL_EEI14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI14_SHIFT)) \
                                                  &DMA_EEIL_EEI14_MASK)
#define DMA_EEIL_EEI15_MASK                     0x8000u
#define DMA_EEIL_EEI15_SHIFT                    15u
#define DMA_EEIL_EEI15_WIDTH                    1u
#define DMA_EEIL_EEI15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI15_SHIFT)) \
                                                  &DMA_EEIL_EEI15_MASK)
#define DMA_EEIL_EEI16_MASK                     0x10000u
#define DMA_EEIL_EEI16_SHIFT                    16u
#define DMA_EEIL_EEI16_WIDTH                    1u
#define DMA_EEIL_EEI16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI16_SHIFT)) \
                                                  &DMA_EEIL_EEI16_MASK)
#define DMA_EEIL_EEI17_MASK                     0x20000u
#define DMA_EEIL_EEI17_SHIFT                    17u
#define DMA_EEIL_EEI17_WIDTH                    1u
#define DMA_EEIL_EEI17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI17_SHIFT)) \
                                                  &DMA_EEIL_EEI17_MASK)
#define DMA_EEIL_EEI18_MASK                     0x40000u
#define DMA_EEIL_EEI18_SHIFT                    18u
#define DMA_EEIL_EEI18_WIDTH                    1u
#define DMA_EEIL_EEI18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI18_SHIFT)) \
                                                  &DMA_EEIL_EEI18_MASK)
#define DMA_EEIL_EEI19_MASK                     0x80000u
#define DMA_EEIL_EEI19_SHIFT                    19u
#define DMA_EEIL_EEI19_WIDTH                    1u
#define DMA_EEIL_EEI19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI19_SHIFT)) \
                                                  &DMA_EEIL_EEI19_MASK)
#define DMA_EEIL_EEI20_MASK                     0x100000u
#define DMA_EEIL_EEI20_SHIFT                    20u
#define DMA_EEIL_EEI20_WIDTH                    1u
#define DMA_EEIL_EEI20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI20_SHIFT)) \
                                                  &DMA_EEIL_EEI20_MASK)
#define DMA_EEIL_EEI21_MASK                     0x200000u
#define DMA_EEIL_EEI21_SHIFT                    21u
#define DMA_EEIL_EEI21_WIDTH                    1u
#define DMA_EEIL_EEI21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI21_SHIFT)) \
                                                  &DMA_EEIL_EEI21_MASK)
#define DMA_EEIL_EEI22_MASK                     0x400000u
#define DMA_EEIL_EEI22_SHIFT                    22u
#define DMA_EEIL_EEI22_WIDTH                    1u
#define DMA_EEIL_EEI22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI22_SHIFT)) \
                                                  &DMA_EEIL_EEI22_MASK)
#define DMA_EEIL_EEI23_MASK                     0x800000u
#define DMA_EEIL_EEI23_SHIFT                    23u
#define DMA_EEIL_EEI23_WIDTH                    1u
#define DMA_EEIL_EEI23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI23_SHIFT)) \
                                                  &DMA_EEIL_EEI23_MASK)
#define DMA_EEIL_EEI24_MASK                     0x1000000u
#define DMA_EEIL_EEI24_SHIFT                    24u
#define DMA_EEIL_EEI24_WIDTH                    1u
#define DMA_EEIL_EEI24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI24_SHIFT)) \
                                                  &DMA_EEIL_EEI24_MASK)
#define DMA_EEIL_EEI25_MASK                     0x2000000u
#define DMA_EEIL_EEI25_SHIFT                    25u
#define DMA_EEIL_EEI25_WIDTH                    1u
#define DMA_EEIL_EEI25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI25_SHIFT)) \
                                                  &DMA_EEIL_EEI25_MASK)
#define DMA_EEIL_EEI26_MASK                     0x4000000u
#define DMA_EEIL_EEI26_SHIFT                    26u
#define DMA_EEIL_EEI26_WIDTH                    1u
#define DMA_EEIL_EEI26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI26_SHIFT)) \
                                                  &DMA_EEIL_EEI26_MASK)
#define DMA_EEIL_EEI27_MASK                     0x8000000u
#define DMA_EEIL_EEI27_SHIFT                    27u
#define DMA_EEIL_EEI27_WIDTH                    1u
#define DMA_EEIL_EEI27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI27_SHIFT)) \
                                                  &DMA_EEIL_EEI27_MASK)
#define DMA_EEIL_EEI28_MASK                     0x10000000u
#define DMA_EEIL_EEI28_SHIFT                    28u
#define DMA_EEIL_EEI28_WIDTH                    1u
#define DMA_EEIL_EEI28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI28_SHIFT)) \
                                                  &DMA_EEIL_EEI28_MASK)
#define DMA_EEIL_EEI29_MASK                     0x20000000u
#define DMA_EEIL_EEI29_SHIFT                    29u
#define DMA_EEIL_EEI29_WIDTH                    1u
#define DMA_EEIL_EEI29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI29_SHIFT)) \
                                                  &DMA_EEIL_EEI29_MASK)
#define DMA_EEIL_EEI30_MASK                     0x40000000u
#define DMA_EEIL_EEI30_SHIFT                    30u
#define DMA_EEIL_EEI30_WIDTH                    1u
#define DMA_EEIL_EEI30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI30_SHIFT)) \
                                                  &DMA_EEIL_EEI30_MASK)
#define DMA_EEIL_EEI31_MASK                     0x80000000u
#define DMA_EEIL_EEI31_SHIFT                    31u
#define DMA_EEIL_EEI31_WIDTH                    1u
#define DMA_EEIL_EEI31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI31_SHIFT)) \
                                                  &DMA_EEIL_EEI31_MASK)
/* SERQ Bit Fields */
#define DMA_SERQ_SERQ_MASK                      0x3Fu
#define DMA_SERQ_SERQ_SHIFT                     0u
#define DMA_SERQ_SERQ_WIDTH                     6u
#define DMA_SERQ_SERQ(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SERQ_SERQ_SHIFT)) \
                                                  &DMA_SERQ_SERQ_MASK)
#define DMA_SERQ_SAER_MASK                      0x40u
#define DMA_SERQ_SAER_SHIFT                     6u
#define DMA_SERQ_SAER_WIDTH                     1u
#define DMA_SERQ_SAER(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SERQ_SAER_SHIFT)) \
                                                  &DMA_SERQ_SAER_MASK)
#define DMA_SERQ_NOP_MASK                       0x80u
#define DMA_SERQ_NOP_SHIFT                      7u
#define DMA_SERQ_NOP_WIDTH                      1u
#define DMA_SERQ_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_SERQ_NOP_SHIFT)) \
                                                  &DMA_SERQ_NOP_MASK)
/* CERQ Bit Fields */
#define DMA_CERQ_CERQ_MASK                      0x3Fu
#define DMA_CERQ_CERQ_SHIFT                     0u
#define DMA_CERQ_CERQ_WIDTH                     6u
#define DMA_CERQ_CERQ(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CERQ_CERQ_SHIFT)) \
                                                  &DMA_CERQ_CERQ_MASK)
#define DMA_CERQ_CAER_MASK                      0x40u
#define DMA_CERQ_CAER_SHIFT                     6u
#define DMA_CERQ_CAER_WIDTH                     1u
#define DMA_CERQ_CAER(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CERQ_CAER_SHIFT)) \
                                                  &DMA_CERQ_CAER_MASK)
#define DMA_CERQ_NOP_MASK                       0x80u
#define DMA_CERQ_NOP_SHIFT                      7u
#define DMA_CERQ_NOP_WIDTH                      1u
#define DMA_CERQ_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CERQ_NOP_SHIFT)) \
                                                  &DMA_CERQ_NOP_MASK)
/* SEEI Bit Fields */
#define DMA_SEEI_SEEI_MASK                      0x3Fu
#define DMA_SEEI_SEEI_SHIFT                     0u
#define DMA_SEEI_SEEI_WIDTH                     6u
#define DMA_SEEI_SEEI(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SEEI_SEEI_SHIFT)) \
                                                  &DMA_SEEI_SEEI_MASK)
#define DMA_SEEI_SAEE_MASK                      0x40u
#define DMA_SEEI_SAEE_SHIFT                     6u
#define DMA_SEEI_SAEE_WIDTH                     1u
#define DMA_SEEI_SAEE(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SEEI_SAEE_SHIFT)) \
                                                  &DMA_SEEI_SAEE_MASK)
#define DMA_SEEI_NOP_MASK                       0x80u
#define DMA_SEEI_NOP_SHIFT                      7u
#define DMA_SEEI_NOP_WIDTH                      1u
#define DMA_SEEI_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_SEEI_NOP_SHIFT)) \
                                                  &DMA_SEEI_NOP_MASK)
/* CEEI Bit Fields */
#define DMA_CEEI_CEEI_MASK                      0x3Fu
#define DMA_CEEI_CEEI_SHIFT                     0u
#define DMA_CEEI_CEEI_WIDTH                     6u
#define DMA_CEEI_CEEI(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CEEI_CEEI_SHIFT)) \
                                                  &DMA_CEEI_CEEI_MASK)
#define DMA_CEEI_CAEE_MASK                      0x40u
#define DMA_CEEI_CAEE_SHIFT                     6u
#define DMA_CEEI_CAEE_WIDTH                     1u
#define DMA_CEEI_CAEE(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CEEI_CAEE_SHIFT)) \
                                                  &DMA_CEEI_CAEE_MASK)
#define DMA_CEEI_NOP_MASK                       0x80u
#define DMA_CEEI_NOP_SHIFT                      7u
#define DMA_CEEI_NOP_WIDTH                      1u
#define DMA_CEEI_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CEEI_NOP_SHIFT)) \
                                                  &DMA_CEEI_NOP_MASK)
/* CINT Bit Fields */
#define DMA_CINT_CINT_MASK                      0x3Fu
#define DMA_CINT_CINT_SHIFT                     0u
#define DMA_CINT_CINT_WIDTH                     6u
#define DMA_CINT_CINT(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CINT_CINT_SHIFT)) \
                                                  &DMA_CINT_CINT_MASK)
#define DMA_CINT_CAIR_MASK                      0x40u
#define DMA_CINT_CAIR_SHIFT                     6u
#define DMA_CINT_CAIR_WIDTH                     1u
#define DMA_CINT_CAIR(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CINT_CAIR_SHIFT)) \
                                                  &DMA_CINT_CAIR_MASK)
#define DMA_CINT_NOP_MASK                       0x80u
#define DMA_CINT_NOP_SHIFT                      7u
#define DMA_CINT_NOP_WIDTH                      1u
#define DMA_CINT_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CINT_NOP_SHIFT)) \
                                                  &DMA_CINT_NOP_MASK)
/* CERR Bit Fields */
#define DMA_CERR_CERR_MASK                      0x3Fu
#define DMA_CERR_CERR_SHIFT                     0u
#define DMA_CERR_CERR_WIDTH                     6u
#define DMA_CERR_CERR(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CERR_CERR_SHIFT)) \
                                                  &DMA_CERR_CERR_MASK)
#define DMA_CERR_CAEI_MASK                      0x40u
#define DMA_CERR_CAEI_SHIFT                     6u
#define DMA_CERR_CAEI_WIDTH                     1u
#define DMA_CERR_CAEI(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CERR_CAEI_SHIFT)) \
                                                  &DMA_CERR_CAEI_MASK)
#define DMA_CERR_NOP_MASK                       0x80u
#define DMA_CERR_NOP_SHIFT                      7u
#define DMA_CERR_NOP_WIDTH                      1u
#define DMA_CERR_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CERR_NOP_SHIFT)) \
                                                  &DMA_CERR_NOP_MASK)
/* SSRT Bit Fields */
#define DMA_SSRT_SSRT_MASK                      0x3Fu
#define DMA_SSRT_SSRT_SHIFT                     0u
#define DMA_SSRT_SSRT_WIDTH                     6u
#define DMA_SSRT_SSRT(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SSRT_SSRT_SHIFT)) \
                                                  &DMA_SSRT_SSRT_MASK)
#define DMA_SSRT_SAST_MASK                      0x40u
#define DMA_SSRT_SAST_SHIFT                     6u
#define DMA_SSRT_SAST_WIDTH                     1u
#define DMA_SSRT_SAST(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SSRT_SAST_SHIFT)) \
                                                  &DMA_SSRT_SAST_MASK)
#define DMA_SSRT_NOP_MASK                       0x80u
#define DMA_SSRT_NOP_SHIFT                      7u
#define DMA_SSRT_NOP_WIDTH                      1u
#define DMA_SSRT_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_SSRT_NOP_SHIFT)) \
                                                  &DMA_SSRT_NOP_MASK)
/* CDNE Bit Fields */
#define DMA_CDNE_CDNE_MASK                      0x3Fu
#define DMA_CDNE_CDNE_SHIFT                     0u
#define DMA_CDNE_CDNE_WIDTH                     6u
#define DMA_CDNE_CDNE(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CDNE_CDNE_SHIFT)) \
                                                  &DMA_CDNE_CDNE_MASK)
#define DMA_CDNE_CADN_MASK                      0x40u
#define DMA_CDNE_CADN_SHIFT                     6u
#define DMA_CDNE_CADN_WIDTH                     1u
#define DMA_CDNE_CADN(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CDNE_CADN_SHIFT)) \
                                                  &DMA_CDNE_CADN_MASK)
#define DMA_CDNE_NOP_MASK                       0x80u
#define DMA_CDNE_NOP_SHIFT                      7u
#define DMA_CDNE_NOP_WIDTH                      1u
#define DMA_CDNE_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CDNE_NOP_SHIFT)) \
                                                  &DMA_CDNE_NOP_MASK)
/* INTH Bit Fields */
#define DMA_INTH_INT32_MASK                     0x1u
#define DMA_INTH_INT32_SHIFT                    0u
#define DMA_INTH_INT32_WIDTH                    1u
#define DMA_INTH_INT32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT32_SHIFT)) \
                                                  &DMA_INTH_INT32_MASK)
#define DMA_INTH_INT33_MASK                     0x2u
#define DMA_INTH_INT33_SHIFT                    1u
#define DMA_INTH_INT33_WIDTH                    1u
#define DMA_INTH_INT33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT33_SHIFT)) \
                                                  &DMA_INTH_INT33_MASK)
#define DMA_INTH_INT34_MASK                     0x4u
#define DMA_INTH_INT34_SHIFT                    2u
#define DMA_INTH_INT34_WIDTH                    1u
#define DMA_INTH_INT34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT34_SHIFT)) \
                                                  &DMA_INTH_INT34_MASK)
#define DMA_INTH_INT35_MASK                     0x8u
#define DMA_INTH_INT35_SHIFT                    3u
#define DMA_INTH_INT35_WIDTH                    1u
#define DMA_INTH_INT35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT35_SHIFT)) \
                                                  &DMA_INTH_INT35_MASK)
#define DMA_INTH_INT36_MASK                     0x10u
#define DMA_INTH_INT36_SHIFT                    4u
#define DMA_INTH_INT36_WIDTH                    1u
#define DMA_INTH_INT36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT36_SHIFT)) \
                                                  &DMA_INTH_INT36_MASK)
#define DMA_INTH_INT37_MASK                     0x20u
#define DMA_INTH_INT37_SHIFT                    5u
#define DMA_INTH_INT37_WIDTH                    1u
#define DMA_INTH_INT37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT37_SHIFT)) \
                                                  &DMA_INTH_INT37_MASK)
#define DMA_INTH_INT38_MASK                     0x40u
#define DMA_INTH_INT38_SHIFT                    6u
#define DMA_INTH_INT38_WIDTH                    1u
#define DMA_INTH_INT38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT38_SHIFT)) \
                                                  &DMA_INTH_INT38_MASK)
#define DMA_INTH_INT39_MASK                     0x80u
#define DMA_INTH_INT39_SHIFT                    7u
#define DMA_INTH_INT39_WIDTH                    1u
#define DMA_INTH_INT39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT39_SHIFT)) \
                                                  &DMA_INTH_INT39_MASK)
#define DMA_INTH_INT40_MASK                     0x100u
#define DMA_INTH_INT40_SHIFT                    8u
#define DMA_INTH_INT40_WIDTH                    1u
#define DMA_INTH_INT40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT40_SHIFT)) \
                                                  &DMA_INTH_INT40_MASK)
#define DMA_INTH_INT41_MASK                     0x200u
#define DMA_INTH_INT41_SHIFT                    9u
#define DMA_INTH_INT41_WIDTH                    1u
#define DMA_INTH_INT41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT41_SHIFT)) \
                                                  &DMA_INTH_INT41_MASK)
#define DMA_INTH_INT42_MASK                     0x400u
#define DMA_INTH_INT42_SHIFT                    10u
#define DMA_INTH_INT42_WIDTH                    1u
#define DMA_INTH_INT42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT42_SHIFT)) \
                                                  &DMA_INTH_INT42_MASK)
#define DMA_INTH_INT43_MASK                     0x800u
#define DMA_INTH_INT43_SHIFT                    11u
#define DMA_INTH_INT43_WIDTH                    1u
#define DMA_INTH_INT43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT43_SHIFT)) \
                                                  &DMA_INTH_INT43_MASK)
#define DMA_INTH_INT44_MASK                     0x1000u
#define DMA_INTH_INT44_SHIFT                    12u
#define DMA_INTH_INT44_WIDTH                    1u
#define DMA_INTH_INT44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT44_SHIFT)) \
                                                  &DMA_INTH_INT44_MASK)
#define DMA_INTH_INT45_MASK                     0x2000u
#define DMA_INTH_INT45_SHIFT                    13u
#define DMA_INTH_INT45_WIDTH                    1u
#define DMA_INTH_INT45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT45_SHIFT)) \
                                                  &DMA_INTH_INT45_MASK)
#define DMA_INTH_INT46_MASK                     0x4000u
#define DMA_INTH_INT46_SHIFT                    14u
#define DMA_INTH_INT46_WIDTH                    1u
#define DMA_INTH_INT46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT46_SHIFT)) \
                                                  &DMA_INTH_INT46_MASK)
#define DMA_INTH_INT47_MASK                     0x8000u
#define DMA_INTH_INT47_SHIFT                    15u
#define DMA_INTH_INT47_WIDTH                    1u
#define DMA_INTH_INT47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT47_SHIFT)) \
                                                  &DMA_INTH_INT47_MASK)
#define DMA_INTH_INT48_MASK                     0x10000u
#define DMA_INTH_INT48_SHIFT                    16u
#define DMA_INTH_INT48_WIDTH                    1u
#define DMA_INTH_INT48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT48_SHIFT)) \
                                                  &DMA_INTH_INT48_MASK)
#define DMA_INTH_INT49_MASK                     0x20000u
#define DMA_INTH_INT49_SHIFT                    17u
#define DMA_INTH_INT49_WIDTH                    1u
#define DMA_INTH_INT49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT49_SHIFT)) \
                                                  &DMA_INTH_INT49_MASK)
#define DMA_INTH_INT50_MASK                     0x40000u
#define DMA_INTH_INT50_SHIFT                    18u
#define DMA_INTH_INT50_WIDTH                    1u
#define DMA_INTH_INT50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT50_SHIFT)) \
                                                  &DMA_INTH_INT50_MASK)
#define DMA_INTH_INT51_MASK                     0x80000u
#define DMA_INTH_INT51_SHIFT                    19u
#define DMA_INTH_INT51_WIDTH                    1u
#define DMA_INTH_INT51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT51_SHIFT)) \
                                                  &DMA_INTH_INT51_MASK)
#define DMA_INTH_INT52_MASK                     0x100000u
#define DMA_INTH_INT52_SHIFT                    20u
#define DMA_INTH_INT52_WIDTH                    1u
#define DMA_INTH_INT52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT52_SHIFT)) \
                                                  &DMA_INTH_INT52_MASK)
#define DMA_INTH_INT53_MASK                     0x200000u
#define DMA_INTH_INT53_SHIFT                    21u
#define DMA_INTH_INT53_WIDTH                    1u
#define DMA_INTH_INT53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT53_SHIFT)) \
                                                  &DMA_INTH_INT53_MASK)
#define DMA_INTH_INT54_MASK                     0x400000u
#define DMA_INTH_INT54_SHIFT                    22u
#define DMA_INTH_INT54_WIDTH                    1u
#define DMA_INTH_INT54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT54_SHIFT)) \
                                                  &DMA_INTH_INT54_MASK)
#define DMA_INTH_INT55_MASK                     0x800000u
#define DMA_INTH_INT55_SHIFT                    23u
#define DMA_INTH_INT55_WIDTH                    1u
#define DMA_INTH_INT55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT55_SHIFT)) \
                                                  &DMA_INTH_INT55_MASK)
#define DMA_INTH_INT56_MASK                     0x1000000u
#define DMA_INTH_INT56_SHIFT                    24u
#define DMA_INTH_INT56_WIDTH                    1u
#define DMA_INTH_INT56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT56_SHIFT)) \
                                                  &DMA_INTH_INT56_MASK)
#define DMA_INTH_INT57_MASK                     0x2000000u
#define DMA_INTH_INT57_SHIFT                    25u
#define DMA_INTH_INT57_WIDTH                    1u
#define DMA_INTH_INT57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT57_SHIFT)) \
                                                  &DMA_INTH_INT57_MASK)
#define DMA_INTH_INT58_MASK                     0x4000000u
#define DMA_INTH_INT58_SHIFT                    26u
#define DMA_INTH_INT58_WIDTH                    1u
#define DMA_INTH_INT58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT58_SHIFT)) \
                                                  &DMA_INTH_INT58_MASK)
#define DMA_INTH_INT59_MASK                     0x8000000u
#define DMA_INTH_INT59_SHIFT                    27u
#define DMA_INTH_INT59_WIDTH                    1u
#define DMA_INTH_INT59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT59_SHIFT)) \
                                                  &DMA_INTH_INT59_MASK)
#define DMA_INTH_INT60_MASK                     0x10000000u
#define DMA_INTH_INT60_SHIFT                    28u
#define DMA_INTH_INT60_WIDTH                    1u
#define DMA_INTH_INT60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT60_SHIFT)) \
                                                  &DMA_INTH_INT60_MASK)
#define DMA_INTH_INT61_MASK                     0x20000000u
#define DMA_INTH_INT61_SHIFT                    29u
#define DMA_INTH_INT61_WIDTH                    1u
#define DMA_INTH_INT61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT61_SHIFT)) \
                                                  &DMA_INTH_INT61_MASK)
#define DMA_INTH_INT62_MASK                     0x40000000u
#define DMA_INTH_INT62_SHIFT                    30u
#define DMA_INTH_INT62_WIDTH                    1u
#define DMA_INTH_INT62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT62_SHIFT)) \
                                                  &DMA_INTH_INT62_MASK)
#define DMA_INTH_INT63_MASK                     0x80000000u
#define DMA_INTH_INT63_SHIFT                    31u
#define DMA_INTH_INT63_WIDTH                    1u
#define DMA_INTH_INT63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT63_SHIFT)) \
                                                  &DMA_INTH_INT63_MASK)
/* INTL Bit Fields */
#define DMA_INTL_INT0_MASK                      0x1u
#define DMA_INTL_INT0_SHIFT                     0u
#define DMA_INTL_INT0_WIDTH                     1u
#define DMA_INTL_INT0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT0_SHIFT)) \
                                                  &DMA_INTL_INT0_MASK)
#define DMA_INTL_INT1_MASK                      0x2u
#define DMA_INTL_INT1_SHIFT                     1u
#define DMA_INTL_INT1_WIDTH                     1u
#define DMA_INTL_INT1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT1_SHIFT)) \
                                                  &DMA_INTL_INT1_MASK)
#define DMA_INTL_INT2_MASK                      0x4u
#define DMA_INTL_INT2_SHIFT                     2u
#define DMA_INTL_INT2_WIDTH                     1u
#define DMA_INTL_INT2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT2_SHIFT)) \
                                                  &DMA_INTL_INT2_MASK)
#define DMA_INTL_INT3_MASK                      0x8u
#define DMA_INTL_INT3_SHIFT                     3u
#define DMA_INTL_INT3_WIDTH                     1u
#define DMA_INTL_INT3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT3_SHIFT)) \
                                                  &DMA_INTL_INT3_MASK)
#define DMA_INTL_INT4_MASK                      0x10u
#define DMA_INTL_INT4_SHIFT                     4u
#define DMA_INTL_INT4_WIDTH                     1u
#define DMA_INTL_INT4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT4_SHIFT)) \
                                                  &DMA_INTL_INT4_MASK)
#define DMA_INTL_INT5_MASK                      0x20u
#define DMA_INTL_INT5_SHIFT                     5u
#define DMA_INTL_INT5_WIDTH                     1u
#define DMA_INTL_INT5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT5_SHIFT)) \
                                                  &DMA_INTL_INT5_MASK)
#define DMA_INTL_INT6_MASK                      0x40u
#define DMA_INTL_INT6_SHIFT                     6u
#define DMA_INTL_INT6_WIDTH                     1u
#define DMA_INTL_INT6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT6_SHIFT)) \
                                                  &DMA_INTL_INT6_MASK)
#define DMA_INTL_INT7_MASK                      0x80u
#define DMA_INTL_INT7_SHIFT                     7u
#define DMA_INTL_INT7_WIDTH                     1u
#define DMA_INTL_INT7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT7_SHIFT)) \
                                                  &DMA_INTL_INT7_MASK)
#define DMA_INTL_INT8_MASK                      0x100u
#define DMA_INTL_INT8_SHIFT                     8u
#define DMA_INTL_INT8_WIDTH                     1u
#define DMA_INTL_INT8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT8_SHIFT)) \
                                                  &DMA_INTL_INT8_MASK)
#define DMA_INTL_INT9_MASK                      0x200u
#define DMA_INTL_INT9_SHIFT                     9u
#define DMA_INTL_INT9_WIDTH                     1u
#define DMA_INTL_INT9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT9_SHIFT)) \
                                                  &DMA_INTL_INT9_MASK)
#define DMA_INTL_INT10_MASK                     0x400u
#define DMA_INTL_INT10_SHIFT                    10u
#define DMA_INTL_INT10_WIDTH                    1u
#define DMA_INTL_INT10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT10_SHIFT)) \
                                                  &DMA_INTL_INT10_MASK)
#define DMA_INTL_INT11_MASK                     0x800u
#define DMA_INTL_INT11_SHIFT                    11u
#define DMA_INTL_INT11_WIDTH                    1u
#define DMA_INTL_INT11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT11_SHIFT)) \
                                                  &DMA_INTL_INT11_MASK)
#define DMA_INTL_INT12_MASK                     0x1000u
#define DMA_INTL_INT12_SHIFT                    12u
#define DMA_INTL_INT12_WIDTH                    1u
#define DMA_INTL_INT12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT12_SHIFT)) \
                                                  &DMA_INTL_INT12_MASK)
#define DMA_INTL_INT13_MASK                     0x2000u
#define DMA_INTL_INT13_SHIFT                    13u
#define DMA_INTL_INT13_WIDTH                    1u
#define DMA_INTL_INT13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT13_SHIFT)) \
                                                  &DMA_INTL_INT13_MASK)
#define DMA_INTL_INT14_MASK                     0x4000u
#define DMA_INTL_INT14_SHIFT                    14u
#define DMA_INTL_INT14_WIDTH                    1u
#define DMA_INTL_INT14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT14_SHIFT)) \
                                                  &DMA_INTL_INT14_MASK)
#define DMA_INTL_INT15_MASK                     0x8000u
#define DMA_INTL_INT15_SHIFT                    15u
#define DMA_INTL_INT15_WIDTH                    1u
#define DMA_INTL_INT15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT15_SHIFT)) \
                                                  &DMA_INTL_INT15_MASK)
#define DMA_INTL_INT16_MASK                     0x10000u
#define DMA_INTL_INT16_SHIFT                    16u
#define DMA_INTL_INT16_WIDTH                    1u
#define DMA_INTL_INT16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT16_SHIFT)) \
                                                  &DMA_INTL_INT16_MASK)
#define DMA_INTL_INT17_MASK                     0x20000u
#define DMA_INTL_INT17_SHIFT                    17u
#define DMA_INTL_INT17_WIDTH                    1u
#define DMA_INTL_INT17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT17_SHIFT)) \
                                                  &DMA_INTL_INT17_MASK)
#define DMA_INTL_INT18_MASK                     0x40000u
#define DMA_INTL_INT18_SHIFT                    18u
#define DMA_INTL_INT18_WIDTH                    1u
#define DMA_INTL_INT18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT18_SHIFT)) \
                                                  &DMA_INTL_INT18_MASK)
#define DMA_INTL_INT19_MASK                     0x80000u
#define DMA_INTL_INT19_SHIFT                    19u
#define DMA_INTL_INT19_WIDTH                    1u
#define DMA_INTL_INT19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT19_SHIFT)) \
                                                  &DMA_INTL_INT19_MASK)
#define DMA_INTL_INT20_MASK                     0x100000u
#define DMA_INTL_INT20_SHIFT                    20u
#define DMA_INTL_INT20_WIDTH                    1u
#define DMA_INTL_INT20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT20_SHIFT)) \
                                                  &DMA_INTL_INT20_MASK)
#define DMA_INTL_INT21_MASK                     0x200000u
#define DMA_INTL_INT21_SHIFT                    21u
#define DMA_INTL_INT21_WIDTH                    1u
#define DMA_INTL_INT21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT21_SHIFT)) \
                                                  &DMA_INTL_INT21_MASK)
#define DMA_INTL_INT22_MASK                     0x400000u
#define DMA_INTL_INT22_SHIFT                    22u
#define DMA_INTL_INT22_WIDTH                    1u
#define DMA_INTL_INT22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT22_SHIFT)) \
                                                  &DMA_INTL_INT22_MASK)
#define DMA_INTL_INT23_MASK                     0x800000u
#define DMA_INTL_INT23_SHIFT                    23u
#define DMA_INTL_INT23_WIDTH                    1u
#define DMA_INTL_INT23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT23_SHIFT)) \
                                                  &DMA_INTL_INT23_MASK)
#define DMA_INTL_INT24_MASK                     0x1000000u
#define DMA_INTL_INT24_SHIFT                    24u
#define DMA_INTL_INT24_WIDTH                    1u
#define DMA_INTL_INT24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT24_SHIFT)) \
                                                  &DMA_INTL_INT24_MASK)
#define DMA_INTL_INT25_MASK                     0x2000000u
#define DMA_INTL_INT25_SHIFT                    25u
#define DMA_INTL_INT25_WIDTH                    1u
#define DMA_INTL_INT25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT25_SHIFT)) \
                                                  &DMA_INTL_INT25_MASK)
#define DMA_INTL_INT26_MASK                     0x4000000u
#define DMA_INTL_INT26_SHIFT                    26u
#define DMA_INTL_INT26_WIDTH                    1u
#define DMA_INTL_INT26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT26_SHIFT)) \
                                                  &DMA_INTL_INT26_MASK)
#define DMA_INTL_INT27_MASK                     0x8000000u
#define DMA_INTL_INT27_SHIFT                    27u
#define DMA_INTL_INT27_WIDTH                    1u
#define DMA_INTL_INT27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT27_SHIFT)) \
                                                  &DMA_INTL_INT27_MASK)
#define DMA_INTL_INT28_MASK                     0x10000000u
#define DMA_INTL_INT28_SHIFT                    28u
#define DMA_INTL_INT28_WIDTH                    1u
#define DMA_INTL_INT28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT28_SHIFT)) \
                                                  &DMA_INTL_INT28_MASK)
#define DMA_INTL_INT29_MASK                     0x20000000u
#define DMA_INTL_INT29_SHIFT                    29u
#define DMA_INTL_INT29_WIDTH                    1u
#define DMA_INTL_INT29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT29_SHIFT)) \
                                                  &DMA_INTL_INT29_MASK)
#define DMA_INTL_INT30_MASK                     0x40000000u
#define DMA_INTL_INT30_SHIFT                    30u
#define DMA_INTL_INT30_WIDTH                    1u
#define DMA_INTL_INT30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT30_SHIFT)) \
                                                  &DMA_INTL_INT30_MASK)
#define DMA_INTL_INT31_MASK                     0x80000000u
#define DMA_INTL_INT31_SHIFT                    31u
#define DMA_INTL_INT31_WIDTH                    1u
#define DMA_INTL_INT31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT31_SHIFT)) \
                                                  &DMA_INTL_INT31_MASK)
/* ERRH Bit Fields */
#define DMA_ERRH_ERR32_MASK                     0x1u
#define DMA_ERRH_ERR32_SHIFT                    0u
#define DMA_ERRH_ERR32_WIDTH                    1u
#define DMA_ERRH_ERR32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR32_SHIFT)) \
                                                  &DMA_ERRH_ERR32_MASK)
#define DMA_ERRH_ERR33_MASK                     0x2u
#define DMA_ERRH_ERR33_SHIFT                    1u
#define DMA_ERRH_ERR33_WIDTH                    1u
#define DMA_ERRH_ERR33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR33_SHIFT)) \
                                                  &DMA_ERRH_ERR33_MASK)
#define DMA_ERRH_ERR34_MASK                     0x4u
#define DMA_ERRH_ERR34_SHIFT                    2u
#define DMA_ERRH_ERR34_WIDTH                    1u
#define DMA_ERRH_ERR34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR34_SHIFT)) \
                                                  &DMA_ERRH_ERR34_MASK)
#define DMA_ERRH_ERR35_MASK                     0x8u
#define DMA_ERRH_ERR35_SHIFT                    3u
#define DMA_ERRH_ERR35_WIDTH                    1u
#define DMA_ERRH_ERR35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR35_SHIFT)) \
                                                  &DMA_ERRH_ERR35_MASK)
#define DMA_ERRH_ERR36_MASK                     0x10u
#define DMA_ERRH_ERR36_SHIFT                    4u
#define DMA_ERRH_ERR36_WIDTH                    1u
#define DMA_ERRH_ERR36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR36_SHIFT)) \
                                                  &DMA_ERRH_ERR36_MASK)
#define DMA_ERRH_ERR37_MASK                     0x20u
#define DMA_ERRH_ERR37_SHIFT                    5u
#define DMA_ERRH_ERR37_WIDTH                    1u
#define DMA_ERRH_ERR37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR37_SHIFT)) \
                                                  &DMA_ERRH_ERR37_MASK)
#define DMA_ERRH_ERR38_MASK                     0x40u
#define DMA_ERRH_ERR38_SHIFT                    6u
#define DMA_ERRH_ERR38_WIDTH                    1u
#define DMA_ERRH_ERR38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR38_SHIFT)) \
                                                  &DMA_ERRH_ERR38_MASK)
#define DMA_ERRH_ERR39_MASK                     0x80u
#define DMA_ERRH_ERR39_SHIFT                    7u
#define DMA_ERRH_ERR39_WIDTH                    1u
#define DMA_ERRH_ERR39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR39_SHIFT)) \
                                                  &DMA_ERRH_ERR39_MASK)
#define DMA_ERRH_ERR40_MASK                     0x100u
#define DMA_ERRH_ERR40_SHIFT                    8u
#define DMA_ERRH_ERR40_WIDTH                    1u
#define DMA_ERRH_ERR40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR40_SHIFT)) \
                                                  &DMA_ERRH_ERR40_MASK)
#define DMA_ERRH_ERR41_MASK                     0x200u
#define DMA_ERRH_ERR41_SHIFT                    9u
#define DMA_ERRH_ERR41_WIDTH                    1u
#define DMA_ERRH_ERR41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR41_SHIFT)) \
                                                  &DMA_ERRH_ERR41_MASK)
#define DMA_ERRH_ERR42_MASK                     0x400u
#define DMA_ERRH_ERR42_SHIFT                    10u
#define DMA_ERRH_ERR42_WIDTH                    1u
#define DMA_ERRH_ERR42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR42_SHIFT)) \
                                                  &DMA_ERRH_ERR42_MASK)
#define DMA_ERRH_ERR43_MASK                     0x800u
#define DMA_ERRH_ERR43_SHIFT                    11u
#define DMA_ERRH_ERR43_WIDTH                    1u
#define DMA_ERRH_ERR43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR43_SHIFT)) \
                                                  &DMA_ERRH_ERR43_MASK)
#define DMA_ERRH_ERR44_MASK                     0x1000u
#define DMA_ERRH_ERR44_SHIFT                    12u
#define DMA_ERRH_ERR44_WIDTH                    1u
#define DMA_ERRH_ERR44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR44_SHIFT)) \
                                                  &DMA_ERRH_ERR44_MASK)
#define DMA_ERRH_ERR45_MASK                     0x2000u
#define DMA_ERRH_ERR45_SHIFT                    13u
#define DMA_ERRH_ERR45_WIDTH                    1u
#define DMA_ERRH_ERR45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR45_SHIFT)) \
                                                  &DMA_ERRH_ERR45_MASK)
#define DMA_ERRH_ERR46_MASK                     0x4000u
#define DMA_ERRH_ERR46_SHIFT                    14u
#define DMA_ERRH_ERR46_WIDTH                    1u
#define DMA_ERRH_ERR46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR46_SHIFT)) \
                                                  &DMA_ERRH_ERR46_MASK)
#define DMA_ERRH_ERR47_MASK                     0x8000u
#define DMA_ERRH_ERR47_SHIFT                    15u
#define DMA_ERRH_ERR47_WIDTH                    1u
#define DMA_ERRH_ERR47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR47_SHIFT)) \
                                                  &DMA_ERRH_ERR47_MASK)
#define DMA_ERRH_ERR48_MASK                     0x10000u
#define DMA_ERRH_ERR48_SHIFT                    16u
#define DMA_ERRH_ERR48_WIDTH                    1u
#define DMA_ERRH_ERR48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR48_SHIFT)) \
                                                  &DMA_ERRH_ERR48_MASK)
#define DMA_ERRH_ERR49_MASK                     0x20000u
#define DMA_ERRH_ERR49_SHIFT                    17u
#define DMA_ERRH_ERR49_WIDTH                    1u
#define DMA_ERRH_ERR49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR49_SHIFT)) \
                                                  &DMA_ERRH_ERR49_MASK)
#define DMA_ERRH_ERR50_MASK                     0x40000u
#define DMA_ERRH_ERR50_SHIFT                    18u
#define DMA_ERRH_ERR50_WIDTH                    1u
#define DMA_ERRH_ERR50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR50_SHIFT)) \
                                                  &DMA_ERRH_ERR50_MASK)
#define DMA_ERRH_ERR51_MASK                     0x80000u
#define DMA_ERRH_ERR51_SHIFT                    19u
#define DMA_ERRH_ERR51_WIDTH                    1u
#define DMA_ERRH_ERR51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR51_SHIFT)) \
                                                  &DMA_ERRH_ERR51_MASK)
#define DMA_ERRH_ERR52_MASK                     0x100000u
#define DMA_ERRH_ERR52_SHIFT                    20u
#define DMA_ERRH_ERR52_WIDTH                    1u
#define DMA_ERRH_ERR52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR52_SHIFT)) \
                                                  &DMA_ERRH_ERR52_MASK)
#define DMA_ERRH_ERR53_MASK                     0x200000u
#define DMA_ERRH_ERR53_SHIFT                    21u
#define DMA_ERRH_ERR53_WIDTH                    1u
#define DMA_ERRH_ERR53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR53_SHIFT)) \
                                                  &DMA_ERRH_ERR53_MASK)
#define DMA_ERRH_ERR54_MASK                     0x400000u
#define DMA_ERRH_ERR54_SHIFT                    22u
#define DMA_ERRH_ERR54_WIDTH                    1u
#define DMA_ERRH_ERR54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR54_SHIFT)) \
                                                  &DMA_ERRH_ERR54_MASK)
#define DMA_ERRH_ERR55_MASK                     0x800000u
#define DMA_ERRH_ERR55_SHIFT                    23u
#define DMA_ERRH_ERR55_WIDTH                    1u
#define DMA_ERRH_ERR55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR55_SHIFT)) \
                                                  &DMA_ERRH_ERR55_MASK)
#define DMA_ERRH_ERR56_MASK                     0x1000000u
#define DMA_ERRH_ERR56_SHIFT                    24u
#define DMA_ERRH_ERR56_WIDTH                    1u
#define DMA_ERRH_ERR56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR56_SHIFT)) \
                                                  &DMA_ERRH_ERR56_MASK)
#define DMA_ERRH_ERR57_MASK                     0x2000000u
#define DMA_ERRH_ERR57_SHIFT                    25u
#define DMA_ERRH_ERR57_WIDTH                    1u
#define DMA_ERRH_ERR57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR57_SHIFT)) \
                                                  &DMA_ERRH_ERR57_MASK)
#define DMA_ERRH_ERR58_MASK                     0x4000000u
#define DMA_ERRH_ERR58_SHIFT                    26u
#define DMA_ERRH_ERR58_WIDTH                    1u
#define DMA_ERRH_ERR58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR58_SHIFT)) \
                                                  &DMA_ERRH_ERR58_MASK)
#define DMA_ERRH_ERR59_MASK                     0x8000000u
#define DMA_ERRH_ERR59_SHIFT                    27u
#define DMA_ERRH_ERR59_WIDTH                    1u
#define DMA_ERRH_ERR59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR59_SHIFT)) \
                                                  &DMA_ERRH_ERR59_MASK)
#define DMA_ERRH_ERR60_MASK                     0x10000000u
#define DMA_ERRH_ERR60_SHIFT                    28u
#define DMA_ERRH_ERR60_WIDTH                    1u
#define DMA_ERRH_ERR60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR60_SHIFT)) \
                                                  &DMA_ERRH_ERR60_MASK)
#define DMA_ERRH_ERR61_MASK                     0x20000000u
#define DMA_ERRH_ERR61_SHIFT                    29u
#define DMA_ERRH_ERR61_WIDTH                    1u
#define DMA_ERRH_ERR61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR61_SHIFT)) \
                                                  &DMA_ERRH_ERR61_MASK)
#define DMA_ERRH_ERR62_MASK                     0x40000000u
#define DMA_ERRH_ERR62_SHIFT                    30u
#define DMA_ERRH_ERR62_WIDTH                    1u
#define DMA_ERRH_ERR62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR62_SHIFT)) \
                                                  &DMA_ERRH_ERR62_MASK)
#define DMA_ERRH_ERR63_MASK                     0x80000000u
#define DMA_ERRH_ERR63_SHIFT                    31u
#define DMA_ERRH_ERR63_WIDTH                    1u
#define DMA_ERRH_ERR63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR63_SHIFT)) \
                                                  &DMA_ERRH_ERR63_MASK)
/* ERRL Bit Fields */
#define DMA_ERRL_ERR0_MASK                      0x1u
#define DMA_ERRL_ERR0_SHIFT                     0u
#define DMA_ERRL_ERR0_WIDTH                     1u
#define DMA_ERRL_ERR0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR0_SHIFT)) \
                                                  &DMA_ERRL_ERR0_MASK)
#define DMA_ERRL_ERR1_MASK                      0x2u
#define DMA_ERRL_ERR1_SHIFT                     1u
#define DMA_ERRL_ERR1_WIDTH                     1u
#define DMA_ERRL_ERR1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR1_SHIFT)) \
                                                  &DMA_ERRL_ERR1_MASK)
#define DMA_ERRL_ERR2_MASK                      0x4u
#define DMA_ERRL_ERR2_SHIFT                     2u
#define DMA_ERRL_ERR2_WIDTH                     1u
#define DMA_ERRL_ERR2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR2_SHIFT)) \
                                                  &DMA_ERRL_ERR2_MASK)
#define DMA_ERRL_ERR3_MASK                      0x8u
#define DMA_ERRL_ERR3_SHIFT                     3u
#define DMA_ERRL_ERR3_WIDTH                     1u
#define DMA_ERRL_ERR3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR3_SHIFT)) \
                                                  &DMA_ERRL_ERR3_MASK)
#define DMA_ERRL_ERR4_MASK                      0x10u
#define DMA_ERRL_ERR4_SHIFT                     4u
#define DMA_ERRL_ERR4_WIDTH                     1u
#define DMA_ERRL_ERR4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR4_SHIFT)) \
                                                  &DMA_ERRL_ERR4_MASK)
#define DMA_ERRL_ERR5_MASK                      0x20u
#define DMA_ERRL_ERR5_SHIFT                     5u
#define DMA_ERRL_ERR5_WIDTH                     1u
#define DMA_ERRL_ERR5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR5_SHIFT)) \
                                                  &DMA_ERRL_ERR5_MASK)
#define DMA_ERRL_ERR6_MASK                      0x40u
#define DMA_ERRL_ERR6_SHIFT                     6u
#define DMA_ERRL_ERR6_WIDTH                     1u
#define DMA_ERRL_ERR6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR6_SHIFT)) \
                                                  &DMA_ERRL_ERR6_MASK)
#define DMA_ERRL_ERR7_MASK                      0x80u
#define DMA_ERRL_ERR7_SHIFT                     7u
#define DMA_ERRL_ERR7_WIDTH                     1u
#define DMA_ERRL_ERR7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR7_SHIFT)) \
                                                  &DMA_ERRL_ERR7_MASK)
#define DMA_ERRL_ERR8_MASK                      0x100u
#define DMA_ERRL_ERR8_SHIFT                     8u
#define DMA_ERRL_ERR8_WIDTH                     1u
#define DMA_ERRL_ERR8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR8_SHIFT)) \
                                                  &DMA_ERRL_ERR8_MASK)
#define DMA_ERRL_ERR9_MASK                      0x200u
#define DMA_ERRL_ERR9_SHIFT                     9u
#define DMA_ERRL_ERR9_WIDTH                     1u
#define DMA_ERRL_ERR9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR9_SHIFT)) \
                                                  &DMA_ERRL_ERR9_MASK)
#define DMA_ERRL_ERR10_MASK                     0x400u
#define DMA_ERRL_ERR10_SHIFT                    10u
#define DMA_ERRL_ERR10_WIDTH                    1u
#define DMA_ERRL_ERR10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR10_SHIFT)) \
                                                  &DMA_ERRL_ERR10_MASK)
#define DMA_ERRL_ERR11_MASK                     0x800u
#define DMA_ERRL_ERR11_SHIFT                    11u
#define DMA_ERRL_ERR11_WIDTH                    1u
#define DMA_ERRL_ERR11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR11_SHIFT)) \
                                                  &DMA_ERRL_ERR11_MASK)
#define DMA_ERRL_ERR12_MASK                     0x1000u
#define DMA_ERRL_ERR12_SHIFT                    12u
#define DMA_ERRL_ERR12_WIDTH                    1u
#define DMA_ERRL_ERR12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR12_SHIFT)) \
                                                  &DMA_ERRL_ERR12_MASK)
#define DMA_ERRL_ERR13_MASK                     0x2000u
#define DMA_ERRL_ERR13_SHIFT                    13u
#define DMA_ERRL_ERR13_WIDTH                    1u
#define DMA_ERRL_ERR13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR13_SHIFT)) \
                                                  &DMA_ERRL_ERR13_MASK)
#define DMA_ERRL_ERR14_MASK                     0x4000u
#define DMA_ERRL_ERR14_SHIFT                    14u
#define DMA_ERRL_ERR14_WIDTH                    1u
#define DMA_ERRL_ERR14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR14_SHIFT)) \
                                                  &DMA_ERRL_ERR14_MASK)
#define DMA_ERRL_ERR15_MASK                     0x8000u
#define DMA_ERRL_ERR15_SHIFT                    15u
#define DMA_ERRL_ERR15_WIDTH                    1u
#define DMA_ERRL_ERR15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR15_SHIFT)) \
                                                  &DMA_ERRL_ERR15_MASK)
#define DMA_ERRL_ERR16_MASK                     0x10000u
#define DMA_ERRL_ERR16_SHIFT                    16u
#define DMA_ERRL_ERR16_WIDTH                    1u
#define DMA_ERRL_ERR16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR16_SHIFT)) \
                                                  &DMA_ERRL_ERR16_MASK)
#define DMA_ERRL_ERR17_MASK                     0x20000u
#define DMA_ERRL_ERR17_SHIFT                    17u
#define DMA_ERRL_ERR17_WIDTH                    1u
#define DMA_ERRL_ERR17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR17_SHIFT)) \
                                                  &DMA_ERRL_ERR17_MASK)
#define DMA_ERRL_ERR18_MASK                     0x40000u
#define DMA_ERRL_ERR18_SHIFT                    18u
#define DMA_ERRL_ERR18_WIDTH                    1u
#define DMA_ERRL_ERR18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR18_SHIFT)) \
                                                  &DMA_ERRL_ERR18_MASK)
#define DMA_ERRL_ERR19_MASK                     0x80000u
#define DMA_ERRL_ERR19_SHIFT                    19u
#define DMA_ERRL_ERR19_WIDTH                    1u
#define DMA_ERRL_ERR19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR19_SHIFT)) \
                                                  &DMA_ERRL_ERR19_MASK)
#define DMA_ERRL_ERR20_MASK                     0x100000u
#define DMA_ERRL_ERR20_SHIFT                    20u
#define DMA_ERRL_ERR20_WIDTH                    1u
#define DMA_ERRL_ERR20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR20_SHIFT)) \
                                                  &DMA_ERRL_ERR20_MASK)
#define DMA_ERRL_ERR21_MASK                     0x200000u
#define DMA_ERRL_ERR21_SHIFT                    21u
#define DMA_ERRL_ERR21_WIDTH                    1u
#define DMA_ERRL_ERR21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR21_SHIFT)) \
                                                  &DMA_ERRL_ERR21_MASK)
#define DMA_ERRL_ERR22_MASK                     0x400000u
#define DMA_ERRL_ERR22_SHIFT                    22u
#define DMA_ERRL_ERR22_WIDTH                    1u
#define DMA_ERRL_ERR22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR22_SHIFT)) \
                                                  &DMA_ERRL_ERR22_MASK)
#define DMA_ERRL_ERR23_MASK                     0x800000u
#define DMA_ERRL_ERR23_SHIFT                    23u
#define DMA_ERRL_ERR23_WIDTH                    1u
#define DMA_ERRL_ERR23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR23_SHIFT)) \
                                                  &DMA_ERRL_ERR23_MASK)
#define DMA_ERRL_ERR24_MASK                     0x1000000u
#define DMA_ERRL_ERR24_SHIFT                    24u
#define DMA_ERRL_ERR24_WIDTH                    1u
#define DMA_ERRL_ERR24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR24_SHIFT)) \
                                                  &DMA_ERRL_ERR24_MASK)
#define DMA_ERRL_ERR25_MASK                     0x2000000u
#define DMA_ERRL_ERR25_SHIFT                    25u
#define DMA_ERRL_ERR25_WIDTH                    1u
#define DMA_ERRL_ERR25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR25_SHIFT)) \
                                                  &DMA_ERRL_ERR25_MASK)
#define DMA_ERRL_ERR26_MASK                     0x4000000u
#define DMA_ERRL_ERR26_SHIFT                    26u
#define DMA_ERRL_ERR26_WIDTH                    1u
#define DMA_ERRL_ERR26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR26_SHIFT)) \
                                                  &DMA_ERRL_ERR26_MASK)
#define DMA_ERRL_ERR27_MASK                     0x8000000u
#define DMA_ERRL_ERR27_SHIFT                    27u
#define DMA_ERRL_ERR27_WIDTH                    1u
#define DMA_ERRL_ERR27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR27_SHIFT)) \
                                                  &DMA_ERRL_ERR27_MASK)
#define DMA_ERRL_ERR28_MASK                     0x10000000u
#define DMA_ERRL_ERR28_SHIFT                    28u
#define DMA_ERRL_ERR28_WIDTH                    1u
#define DMA_ERRL_ERR28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR28_SHIFT)) \
                                                  &DMA_ERRL_ERR28_MASK)
#define DMA_ERRL_ERR29_MASK                     0x20000000u
#define DMA_ERRL_ERR29_SHIFT                    29u
#define DMA_ERRL_ERR29_WIDTH                    1u
#define DMA_ERRL_ERR29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR29_SHIFT)) \
                                                  &DMA_ERRL_ERR29_MASK)
#define DMA_ERRL_ERR30_MASK                     0x40000000u
#define DMA_ERRL_ERR30_SHIFT                    30u
#define DMA_ERRL_ERR30_WIDTH                    1u
#define DMA_ERRL_ERR30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR30_SHIFT)) \
                                                  &DMA_ERRL_ERR30_MASK)
#define DMA_ERRL_ERR31_MASK                     0x80000000u
#define DMA_ERRL_ERR31_SHIFT                    31u
#define DMA_ERRL_ERR31_WIDTH                    1u
#define DMA_ERRL_ERR31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR31_SHIFT)) \
                                                  &DMA_ERRL_ERR31_MASK)
/* HRSH Bit Fields */
#define DMA_HRSH_HRS32_MASK                     0x1u
#define DMA_HRSH_HRS32_SHIFT                    0u
#define DMA_HRSH_HRS32_WIDTH                    1u
#define DMA_HRSH_HRS32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS32_SHIFT)) \
                                                  &DMA_HRSH_HRS32_MASK)
#define DMA_HRSH_HRS33_MASK                     0x2u
#define DMA_HRSH_HRS33_SHIFT                    1u
#define DMA_HRSH_HRS33_WIDTH                    1u
#define DMA_HRSH_HRS33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS33_SHIFT)) \
                                                  &DMA_HRSH_HRS33_MASK)
#define DMA_HRSH_HRS34_MASK                     0x4u
#define DMA_HRSH_HRS34_SHIFT                    2u
#define DMA_HRSH_HRS34_WIDTH                    1u
#define DMA_HRSH_HRS34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS34_SHIFT)) \
                                                  &DMA_HRSH_HRS34_MASK)
#define DMA_HRSH_HRS35_MASK                     0x8u
#define DMA_HRSH_HRS35_SHIFT                    3u
#define DMA_HRSH_HRS35_WIDTH                    1u
#define DMA_HRSH_HRS35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS35_SHIFT)) \
                                                  &DMA_HRSH_HRS35_MASK)
#define DMA_HRSH_HRS36_MASK                     0x10u
#define DMA_HRSH_HRS36_SHIFT                    4u
#define DMA_HRSH_HRS36_WIDTH                    1u
#define DMA_HRSH_HRS36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS36_SHIFT)) \
                                                  &DMA_HRSH_HRS36_MASK)
#define DMA_HRSH_HRS37_MASK                     0x20u
#define DMA_HRSH_HRS37_SHIFT                    5u
#define DMA_HRSH_HRS37_WIDTH                    1u
#define DMA_HRSH_HRS37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS37_SHIFT)) \
                                                  &DMA_HRSH_HRS37_MASK)
#define DMA_HRSH_HRS38_MASK                     0x40u
#define DMA_HRSH_HRS38_SHIFT                    6u
#define DMA_HRSH_HRS38_WIDTH                    1u
#define DMA_HRSH_HRS38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS38_SHIFT)) \
                                                  &DMA_HRSH_HRS38_MASK)
#define DMA_HRSH_HRS39_MASK                     0x80u
#define DMA_HRSH_HRS39_SHIFT                    7u
#define DMA_HRSH_HRS39_WIDTH                    1u
#define DMA_HRSH_HRS39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS39_SHIFT)) \
                                                  &DMA_HRSH_HRS39_MASK)
#define DMA_HRSH_HRS40_MASK                     0x100u
#define DMA_HRSH_HRS40_SHIFT                    8u
#define DMA_HRSH_HRS40_WIDTH                    1u
#define DMA_HRSH_HRS40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS40_SHIFT)) \
                                                  &DMA_HRSH_HRS40_MASK)
#define DMA_HRSH_HRS41_MASK                     0x200u
#define DMA_HRSH_HRS41_SHIFT                    9u
#define DMA_HRSH_HRS41_WIDTH                    1u
#define DMA_HRSH_HRS41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS41_SHIFT)) \
                                                  &DMA_HRSH_HRS41_MASK)
#define DMA_HRSH_HRS42_MASK                     0x400u
#define DMA_HRSH_HRS42_SHIFT                    10u
#define DMA_HRSH_HRS42_WIDTH                    1u
#define DMA_HRSH_HRS42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS42_SHIFT)) \
                                                  &DMA_HRSH_HRS42_MASK)
#define DMA_HRSH_HRS43_MASK                     0x800u
#define DMA_HRSH_HRS43_SHIFT                    11u
#define DMA_HRSH_HRS43_WIDTH                    1u
#define DMA_HRSH_HRS43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS43_SHIFT)) \
                                                  &DMA_HRSH_HRS43_MASK)
#define DMA_HRSH_HRS44_MASK                     0x1000u
#define DMA_HRSH_HRS44_SHIFT                    12u
#define DMA_HRSH_HRS44_WIDTH                    1u
#define DMA_HRSH_HRS44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS44_SHIFT)) \
                                                  &DMA_HRSH_HRS44_MASK)
#define DMA_HRSH_HRS45_MASK                     0x2000u
#define DMA_HRSH_HRS45_SHIFT                    13u
#define DMA_HRSH_HRS45_WIDTH                    1u
#define DMA_HRSH_HRS45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS45_SHIFT)) \
                                                  &DMA_HRSH_HRS45_MASK)
#define DMA_HRSH_HRS46_MASK                     0x4000u
#define DMA_HRSH_HRS46_SHIFT                    14u
#define DMA_HRSH_HRS46_WIDTH                    1u
#define DMA_HRSH_HRS46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS46_SHIFT)) \
                                                  &DMA_HRSH_HRS46_MASK)
#define DMA_HRSH_HRS47_MASK                     0x8000u
#define DMA_HRSH_HRS47_SHIFT                    15u
#define DMA_HRSH_HRS47_WIDTH                    1u
#define DMA_HRSH_HRS47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS47_SHIFT)) \
                                                  &DMA_HRSH_HRS47_MASK)
#define DMA_HRSH_HRS48_MASK                     0x10000u
#define DMA_HRSH_HRS48_SHIFT                    16u
#define DMA_HRSH_HRS48_WIDTH                    1u
#define DMA_HRSH_HRS48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS48_SHIFT)) \
                                                  &DMA_HRSH_HRS48_MASK)
#define DMA_HRSH_HRS49_MASK                     0x20000u
#define DMA_HRSH_HRS49_SHIFT                    17u
#define DMA_HRSH_HRS49_WIDTH                    1u
#define DMA_HRSH_HRS49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS49_SHIFT)) \
                                                  &DMA_HRSH_HRS49_MASK)
#define DMA_HRSH_HRS50_MASK                     0x40000u
#define DMA_HRSH_HRS50_SHIFT                    18u
#define DMA_HRSH_HRS50_WIDTH                    1u
#define DMA_HRSH_HRS50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS50_SHIFT)) \
                                                  &DMA_HRSH_HRS50_MASK)
#define DMA_HRSH_HRS51_MASK                     0x80000u
#define DMA_HRSH_HRS51_SHIFT                    19u
#define DMA_HRSH_HRS51_WIDTH                    1u
#define DMA_HRSH_HRS51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS51_SHIFT)) \
                                                  &DMA_HRSH_HRS51_MASK)
#define DMA_HRSH_HRS52_MASK                     0x100000u
#define DMA_HRSH_HRS52_SHIFT                    20u
#define DMA_HRSH_HRS52_WIDTH                    1u
#define DMA_HRSH_HRS52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS52_SHIFT)) \
                                                  &DMA_HRSH_HRS52_MASK)
#define DMA_HRSH_HRS53_MASK                     0x200000u
#define DMA_HRSH_HRS53_SHIFT                    21u
#define DMA_HRSH_HRS53_WIDTH                    1u
#define DMA_HRSH_HRS53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS53_SHIFT)) \
                                                  &DMA_HRSH_HRS53_MASK)
#define DMA_HRSH_HRS54_MASK                     0x400000u
#define DMA_HRSH_HRS54_SHIFT                    22u
#define DMA_HRSH_HRS54_WIDTH                    1u
#define DMA_HRSH_HRS54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS54_SHIFT)) \
                                                  &DMA_HRSH_HRS54_MASK)
#define DMA_HRSH_HRS55_MASK                     0x800000u
#define DMA_HRSH_HRS55_SHIFT                    23u
#define DMA_HRSH_HRS55_WIDTH                    1u
#define DMA_HRSH_HRS55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS55_SHIFT)) \
                                                  &DMA_HRSH_HRS55_MASK)
#define DMA_HRSH_HRS56_MASK                     0x1000000u
#define DMA_HRSH_HRS56_SHIFT                    24u
#define DMA_HRSH_HRS56_WIDTH                    1u
#define DMA_HRSH_HRS56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS56_SHIFT)) \
                                                  &DMA_HRSH_HRS56_MASK)
#define DMA_HRSH_HRS57_MASK                     0x2000000u
#define DMA_HRSH_HRS57_SHIFT                    25u
#define DMA_HRSH_HRS57_WIDTH                    1u
#define DMA_HRSH_HRS57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS57_SHIFT)) \
                                                  &DMA_HRSH_HRS57_MASK)
#define DMA_HRSH_HRS58_MASK                     0x4000000u
#define DMA_HRSH_HRS58_SHIFT                    26u
#define DMA_HRSH_HRS58_WIDTH                    1u
#define DMA_HRSH_HRS58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS58_SHIFT)) \
                                                  &DMA_HRSH_HRS58_MASK)
#define DMA_HRSH_HRS59_MASK                     0x8000000u
#define DMA_HRSH_HRS59_SHIFT                    27u
#define DMA_HRSH_HRS59_WIDTH                    1u
#define DMA_HRSH_HRS59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS59_SHIFT)) \
                                                  &DMA_HRSH_HRS59_MASK)
#define DMA_HRSH_HRS60_MASK                     0x10000000u
#define DMA_HRSH_HRS60_SHIFT                    28u
#define DMA_HRSH_HRS60_WIDTH                    1u
#define DMA_HRSH_HRS60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS60_SHIFT)) \
                                                  &DMA_HRSH_HRS60_MASK)
#define DMA_HRSH_HRS61_MASK                     0x20000000u
#define DMA_HRSH_HRS61_SHIFT                    29u
#define DMA_HRSH_HRS61_WIDTH                    1u
#define DMA_HRSH_HRS61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS61_SHIFT)) \
                                                  &DMA_HRSH_HRS61_MASK)
#define DMA_HRSH_HRS62_MASK                     0x40000000u
#define DMA_HRSH_HRS62_SHIFT                    30u
#define DMA_HRSH_HRS62_WIDTH                    1u
#define DMA_HRSH_HRS62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS62_SHIFT)) \
                                                  &DMA_HRSH_HRS62_MASK)
#define DMA_HRSH_HRS63_MASK                     0x80000000u
#define DMA_HRSH_HRS63_SHIFT                    31u
#define DMA_HRSH_HRS63_WIDTH                    1u
#define DMA_HRSH_HRS63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS63_SHIFT)) \
                                                  &DMA_HRSH_HRS63_MASK)
/* HRSL Bit Fields */
#define DMA_HRSL_HRS0_MASK                      0x1u
#define DMA_HRSL_HRS0_SHIFT                     0u
#define DMA_HRSL_HRS0_WIDTH                     1u
#define DMA_HRSL_HRS0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS0_SHIFT)) \
                                                  &DMA_HRSL_HRS0_MASK)
#define DMA_HRSL_HRS1_MASK                      0x2u
#define DMA_HRSL_HRS1_SHIFT                     1u
#define DMA_HRSL_HRS1_WIDTH                     1u
#define DMA_HRSL_HRS1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS1_SHIFT)) \
                                                  &DMA_HRSL_HRS1_MASK)
#define DMA_HRSL_HRS2_MASK                      0x4u
#define DMA_HRSL_HRS2_SHIFT                     2u
#define DMA_HRSL_HRS2_WIDTH                     1u
#define DMA_HRSL_HRS2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS2_SHIFT)) \
                                                  &DMA_HRSL_HRS2_MASK)
#define DMA_HRSL_HRS3_MASK                      0x8u
#define DMA_HRSL_HRS3_SHIFT                     3u
#define DMA_HRSL_HRS3_WIDTH                     1u
#define DMA_HRSL_HRS3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS3_SHIFT)) \
                                                  &DMA_HRSL_HRS3_MASK)
#define DMA_HRSL_HRS4_MASK                      0x10u
#define DMA_HRSL_HRS4_SHIFT                     4u
#define DMA_HRSL_HRS4_WIDTH                     1u
#define DMA_HRSL_HRS4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS4_SHIFT)) \
                                                  &DMA_HRSL_HRS4_MASK)
#define DMA_HRSL_HRS5_MASK                      0x20u
#define DMA_HRSL_HRS5_SHIFT                     5u
#define DMA_HRSL_HRS5_WIDTH                     1u
#define DMA_HRSL_HRS5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS5_SHIFT)) \
                                                  &DMA_HRSL_HRS5_MASK)
#define DMA_HRSL_HRS6_MASK                      0x40u
#define DMA_HRSL_HRS6_SHIFT                     6u
#define DMA_HRSL_HRS6_WIDTH                     1u
#define DMA_HRSL_HRS6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS6_SHIFT)) \
                                                  &DMA_HRSL_HRS6_MASK)
#define DMA_HRSL_HRS7_MASK                      0x80u
#define DMA_HRSL_HRS7_SHIFT                     7u
#define DMA_HRSL_HRS7_WIDTH                     1u
#define DMA_HRSL_HRS7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS7_SHIFT)) \
                                                  &DMA_HRSL_HRS7_MASK)
#define DMA_HRSL_HRS8_MASK                      0x100u
#define DMA_HRSL_HRS8_SHIFT                     8u
#define DMA_HRSL_HRS8_WIDTH                     1u
#define DMA_HRSL_HRS8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS8_SHIFT)) \
                                                  &DMA_HRSL_HRS8_MASK)
#define DMA_HRSL_HRS9_MASK                      0x200u
#define DMA_HRSL_HRS9_SHIFT                     9u
#define DMA_HRSL_HRS9_WIDTH                     1u
#define DMA_HRSL_HRS9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS9_SHIFT)) \
                                                  &DMA_HRSL_HRS9_MASK)
#define DMA_HRSL_HRS10_MASK                     0x400u
#define DMA_HRSL_HRS10_SHIFT                    10u
#define DMA_HRSL_HRS10_WIDTH                    1u
#define DMA_HRSL_HRS10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS10_SHIFT)) \
                                                  &DMA_HRSL_HRS10_MASK)
#define DMA_HRSL_HRS11_MASK                     0x800u
#define DMA_HRSL_HRS11_SHIFT                    11u
#define DMA_HRSL_HRS11_WIDTH                    1u
#define DMA_HRSL_HRS11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS11_SHIFT)) \
                                                  &DMA_HRSL_HRS11_MASK)
#define DMA_HRSL_HRS12_MASK                     0x1000u
#define DMA_HRSL_HRS12_SHIFT                    12u
#define DMA_HRSL_HRS12_WIDTH                    1u
#define DMA_HRSL_HRS12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS12_SHIFT)) \
                                                  &DMA_HRSL_HRS12_MASK)
#define DMA_HRSL_HRS13_MASK                     0x2000u
#define DMA_HRSL_HRS13_SHIFT                    13u
#define DMA_HRSL_HRS13_WIDTH                    1u
#define DMA_HRSL_HRS13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS13_SHIFT)) \
                                                  &DMA_HRSL_HRS13_MASK)
#define DMA_HRSL_HRS14_MASK                     0x4000u
#define DMA_HRSL_HRS14_SHIFT                    14u
#define DMA_HRSL_HRS14_WIDTH                    1u
#define DMA_HRSL_HRS14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS14_SHIFT)) \
                                                  &DMA_HRSL_HRS14_MASK)
#define DMA_HRSL_HRS15_MASK                     0x8000u
#define DMA_HRSL_HRS15_SHIFT                    15u
#define DMA_HRSL_HRS15_WIDTH                    1u
#define DMA_HRSL_HRS15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS15_SHIFT)) \
                                                  &DMA_HRSL_HRS15_MASK)
#define DMA_HRSL_HRS16_MASK                     0x10000u
#define DMA_HRSL_HRS16_SHIFT                    16u
#define DMA_HRSL_HRS16_WIDTH                    1u
#define DMA_HRSL_HRS16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS16_SHIFT)) \
                                                  &DMA_HRSL_HRS16_MASK)
#define DMA_HRSL_HRS17_MASK                     0x20000u
#define DMA_HRSL_HRS17_SHIFT                    17u
#define DMA_HRSL_HRS17_WIDTH                    1u
#define DMA_HRSL_HRS17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS17_SHIFT)) \
                                                  &DMA_HRSL_HRS17_MASK)
#define DMA_HRSL_HRS18_MASK                     0x40000u
#define DMA_HRSL_HRS18_SHIFT                    18u
#define DMA_HRSL_HRS18_WIDTH                    1u
#define DMA_HRSL_HRS18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS18_SHIFT)) \
                                                  &DMA_HRSL_HRS18_MASK)
#define DMA_HRSL_HRS19_MASK                     0x80000u
#define DMA_HRSL_HRS19_SHIFT                    19u
#define DMA_HRSL_HRS19_WIDTH                    1u
#define DMA_HRSL_HRS19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS19_SHIFT)) \
                                                  &DMA_HRSL_HRS19_MASK)
#define DMA_HRSL_HRS20_MASK                     0x100000u
#define DMA_HRSL_HRS20_SHIFT                    20u
#define DMA_HRSL_HRS20_WIDTH                    1u
#define DMA_HRSL_HRS20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS20_SHIFT)) \
                                                  &DMA_HRSL_HRS20_MASK)
#define DMA_HRSL_HRS21_MASK                     0x200000u
#define DMA_HRSL_HRS21_SHIFT                    21u
#define DMA_HRSL_HRS21_WIDTH                    1u
#define DMA_HRSL_HRS21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS21_SHIFT)) \
                                                  &DMA_HRSL_HRS21_MASK)
#define DMA_HRSL_HRS22_MASK                     0x400000u
#define DMA_HRSL_HRS22_SHIFT                    22u
#define DMA_HRSL_HRS22_WIDTH                    1u
#define DMA_HRSL_HRS22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS22_SHIFT)) \
                                                  &DMA_HRSL_HRS22_MASK)
#define DMA_HRSL_HRS23_MASK                     0x800000u
#define DMA_HRSL_HRS23_SHIFT                    23u
#define DMA_HRSL_HRS23_WIDTH                    1u
#define DMA_HRSL_HRS23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS23_SHIFT)) \
                                                  &DMA_HRSL_HRS23_MASK)
#define DMA_HRSL_HRS24_MASK                     0x1000000u
#define DMA_HRSL_HRS24_SHIFT                    24u
#define DMA_HRSL_HRS24_WIDTH                    1u
#define DMA_HRSL_HRS24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS24_SHIFT)) \
                                                  &DMA_HRSL_HRS24_MASK)
#define DMA_HRSL_HRS25_MASK                     0x2000000u
#define DMA_HRSL_HRS25_SHIFT                    25u
#define DMA_HRSL_HRS25_WIDTH                    1u
#define DMA_HRSL_HRS25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS25_SHIFT)) \
                                                  &DMA_HRSL_HRS25_MASK)
#define DMA_HRSL_HRS26_MASK                     0x4000000u
#define DMA_HRSL_HRS26_SHIFT                    26u
#define DMA_HRSL_HRS26_WIDTH                    1u
#define DMA_HRSL_HRS26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS26_SHIFT)) \
                                                  &DMA_HRSL_HRS26_MASK)
#define DMA_HRSL_HRS27_MASK                     0x8000000u
#define DMA_HRSL_HRS27_SHIFT                    27u
#define DMA_HRSL_HRS27_WIDTH                    1u
#define DMA_HRSL_HRS27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS27_SHIFT)) \
                                                  &DMA_HRSL_HRS27_MASK)
#define DMA_HRSL_HRS28_MASK                     0x10000000u
#define DMA_HRSL_HRS28_SHIFT                    28u
#define DMA_HRSL_HRS28_WIDTH                    1u
#define DMA_HRSL_HRS28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS28_SHIFT)) \
                                                  &DMA_HRSL_HRS28_MASK)
#define DMA_HRSL_HRS29_MASK                     0x20000000u
#define DMA_HRSL_HRS29_SHIFT                    29u
#define DMA_HRSL_HRS29_WIDTH                    1u
#define DMA_HRSL_HRS29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS29_SHIFT)) \
                                                  &DMA_HRSL_HRS29_MASK)
#define DMA_HRSL_HRS30_MASK                     0x40000000u
#define DMA_HRSL_HRS30_SHIFT                    30u
#define DMA_HRSL_HRS30_WIDTH                    1u
#define DMA_HRSL_HRS30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS30_SHIFT)) \
                                                  &DMA_HRSL_HRS30_MASK)
#define DMA_HRSL_HRS31_MASK                     0x80000000u
#define DMA_HRSL_HRS31_SHIFT                    31u
#define DMA_HRSL_HRS31_WIDTH                    1u
#define DMA_HRSL_HRS31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS31_SHIFT)) \
                                                  &DMA_HRSL_HRS31_MASK)
/* GPOR Bit Fields */
#define DMA_GPOR_GPOR_MASK                      0xFFFFFFFFu
#define DMA_GPOR_GPOR_SHIFT                     0u
#define DMA_GPOR_GPOR_WIDTH                     32u
#define DMA_GPOR_GPOR(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_GPOR_GPOR_SHIFT)) \
                                                  &DMA_GPOR_GPOR_MASK)
/* DCHPRI Bit Fields */
#define DMA_DCHPRI_CHPRI_MASK                   0xFu
#define DMA_DCHPRI_CHPRI_SHIFT                  0u
#define DMA_DCHPRI_CHPRI_WIDTH                  4u
#define DMA_DCHPRI_CHPRI(x)                     (uint8)(((((uint32)(x)) \
                                                  << DMA_DCHPRI_CHPRI_SHIFT)) \
                                                  &DMA_DCHPRI_CHPRI_MASK)
#define DMA_DCHPRI_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI_GRPPRI_SHIFT                 4u
#define DMA_DCHPRI_GRPPRI_WIDTH                 2u
#define DMA_DCHPRI_GRPPRI(x)                    (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHPRI_GRPPRI_SHIFT)) \
                                                  &DMA_DCHPRI_GRPPRI_MASK)
#define DMA_DCHPRI_DPA_MASK                     0x40u
#define DMA_DCHPRI_DPA_SHIFT                    6u
#define DMA_DCHPRI_DPA_WIDTH                    1u
#define DMA_DCHPRI_DPA(x)                       (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHPRI_DPA_SHIFT)) \
                                                  &DMA_DCHPRI_DPA_MASK)
#define DMA_DCHPRI_ECP_MASK                     0x80u
#define DMA_DCHPRI_ECP_SHIFT                    7u
#define DMA_DCHPRI_ECP_WIDTH                    1u
#define DMA_DCHPRI_ECP(x)                       (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHPRI_ECP_SHIFT)) \
                                                  &DMA_DCHPRI_ECP_MASK)

/* MASTER ID */
#define DMA_DCHMID_MID_MASK                   0xFu
#define DMA_DCHMID_MID_SHIFT                  0u
#define DMA_DCHMID_MID_WIDTH                  4u
#define DMA_DCHMID_MID(x)                     (uint8)(((((uint32)(x)) \
                                                  << DMA_DCHMID_MID_SHIFT)) \
                                                  &DMA_DCHMID_MID_MASK)
#define DMA_DCHMID_PAL_MASK                     0x40u
#define DMA_DCHMID_PAL_SHIFT                    6u
#define DMA_DCHMID_PAL_WIDTH                    1u
#define DMA_DCHMID_PAL(x)                       (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHMID_PAL_SHIFT)) \
                                                  &DMA_DCHMID_PAL_MASK)
#define DMA_DCHMID_EMI_MASK                     0x80u
#define DMA_DCHMID_EMI_SHIFT                    7u
#define DMA_DCHMID_EMI_WIDTH                    1u
#define DMA_DCHMID_EMI(x)                       (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHMID_EMI_SHIFT)) \
                                                  &DMA_DCHMID_EMI_MASK)

/* TCD_SADDR Bit Fields */
#define DMA_TCD_SADDR_SADDR_MASK                0xFFFFFFFFu
#define DMA_TCD_SADDR_SADDR_SHIFT               0u
#define DMA_TCD_SADDR_SADDR_WIDTH               32u
#define DMA_TCD_SADDR_SADDR(x)                  (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_SADDR_SADDR_SHIFT)) \
                                                  &DMA_TCD_SADDR_SADDR_MASK)
/* TCD_ATTR Bit Fields */
#define DMA_TCD_ATTR_DSIZE_MASK                 0x7u
#define DMA_TCD_ATTR_DSIZE_SHIFT                0u
#define DMA_TCD_ATTR_DSIZE_WIDTH                3u
#define DMA_TCD_ATTR_DSIZE(x)                   (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_ATTR_DSIZE_SHIFT)) \
                                                  &DMA_TCD_ATTR_DSIZE_MASK)
#define DMA_TCD_ATTR_DMOD_MASK                  0xF8u
#define DMA_TCD_ATTR_DMOD_SHIFT                 3u
#define DMA_TCD_ATTR_DMOD_WIDTH                 5u
#define DMA_TCD_ATTR_DMOD(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_ATTR_DMOD_SHIFT)) \
                                                  &DMA_TCD_ATTR_DMOD_MASK)
#define DMA_TCD_ATTR_SSIZE_MASK                 0x700u
#define DMA_TCD_ATTR_SSIZE_SHIFT                8u
#define DMA_TCD_ATTR_SSIZE_WIDTH                3u
#define DMA_TCD_ATTR_SSIZE(x)                   (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_ATTR_SSIZE_SHIFT)) \
                                                  &DMA_TCD_ATTR_SSIZE_MASK)
#define DMA_TCD_ATTR_SMOD_MASK                  0xF800u
#define DMA_TCD_ATTR_SMOD_SHIFT                 11u
#define DMA_TCD_ATTR_SMOD_WIDTH                 5u
#define DMA_TCD_ATTR_SMOD(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_ATTR_SMOD_SHIFT)) \
                                                  &DMA_TCD_ATTR_SMOD_MASK)
/* TCD_SOFF Bit Fields */
#define DMA_TCD_SOFF_SOFF_MASK                  0xFFFFu
#define DMA_TCD_SOFF_SOFF_SHIFT                 0u
#define DMA_TCD_SOFF_SOFF_WIDTH                 16u
#define DMA_TCD_SOFF_SOFF(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_SOFF_SOFF_SHIFT)) \
                                                  &DMA_TCD_SOFF_SOFF_MASK)
/* TCD_NBYTES_MLNO Bit Fields */
#define DMA_TCD_NBYTES_MLNO_NBYTE_MASK          0xFFFFFFFFu
#define DMA_TCD_NBYTES_MLNO_NBYTE_SHIFT         0u
#define DMA_TCD_NBYTES_MLNO_NBYTE_WIDTH         32u
#define DMA_TCD_NBYTES_MLNO_NBYTES(x)           (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NBYTES_MLNO_NBYTE_SHIFT)) \
                                                  &DMA_TCD_NBYTES_MLNO_NBYTE_MASK)
/* TCD_NBYTES_MLOFFNO Bit Fields */
#define DMA_TCD_NBYTES_MLOFFNO_NB_MASK          0x3FFFFFFFu
#define DMA_TCD_NBYTES_MLOFFNO_NB_SHIFT         0u
#define DMA_TCD_NBYTES_MLOFFNO_NB_WIDTH         30u
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)        (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NBYTES_MLOFFNO_NB_SHIFT)) \
                                                  &DMA_TCD_NBYTES_MLOFFNO_NB_MASK)
#define DMA_TCD_NB_MLOFFNO_DMLOE_MASK           0x40000000u
#define DMA_TCD_NB_MLOFFNO_DMLOE_SHIFT          30u
#define DMA_TCD_NB_MLOFFNO_DMLOE_WIDTH          1u
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE(x)         (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFNO_DMLOE_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFNO_DMLOE_MASK)
#define DMA_TCD_NB_MLOFFNO_SMLOE_MASK           0x80000000u
#define DMA_TCD_NB_MLOFFNO_SMLOE_SHIFT          31u
#define DMA_TCD_NB_MLOFFNO_SMLOE_WIDTH          1u
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE(x)         (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFNO_SMLOE_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFNO_SMLOE_MASK)
/* TCD_NBYTES_MLOFFYES Bit Fields */
#define DMA_TCD_NB_MLOFFYES_NB_MASK             0x3FFu
#define DMA_TCD_NB_MLOFFYES_NB_SHIFT            0u  /* PRQA S 0791 */
#define DMA_TCD_NB_MLOFFYES_NB_WIDTH            10u /* PRQA S 0791 */
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)       (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFYES_NB_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFYES_NB_MASK)
#define DMA_TCD_NB_MLOFFYES_MLOFF_MASK          0x3FFFFC00u
#define DMA_TCD_NB_MLOFFYES_MLOFF_SHIFT         10u
#define DMA_TCD_NB_MLOFFYES_MLOFF_WIDTH         20u
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)        (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFYES_MLOFF_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFYES_MLOFF_MASK)
#define DMA_TCD_NB_MLOFFYES_DMLOE_MASK          0x40000000u
#define DMA_TCD_NB_MLOFFYES_DMLOE_SHIFT         30u
#define DMA_TCD_NB_MLOFFYES_DMLOE_WIDTH         1u
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE(x)        (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFYES_DMLOE_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFYES_DMLOE_MASK)
#define DMA_TCD_NB_MLOFFYES_SMLOE_MASK          0x80000000u
#define DMA_TCD_NB_MLOFFYES_SMLOE_SHIFT         31u
#define DMA_TCD_NB_MLOFFYES_SMLOE_WIDTH         1u
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE(x)        (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFYES_SMLOE_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFYES_SMLOE_MASK)
/* TCD_SLAST Bit Fields */
#define DMA_TCD_SLAST_SLAST_MASK                0xFFFFFFFFu
#define DMA_TCD_SLAST_SLAST_SHIFT               0u
#define DMA_TCD_SLAST_SLAST_WIDTH               32u
#define DMA_TCD_SLAST_SLAST(x)                  (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_SLAST_SLAST_SHIFT)) \
                                                  &DMA_TCD_SLAST_SLAST_MASK)
/* TCD_DADDR Bit Fields */
#define DMA_TCD_DADDR_DADDR_MASK                0xFFFFFFFFu
#define DMA_TCD_DADDR_DADDR_SHIFT               0u
#define DMA_TCD_DADDR_DADDR_WIDTH               32u
#define DMA_TCD_DADDR_DADDR(x)                  (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_DADDR_DADDR_SHIFT)) \
                                                  &DMA_TCD_DADDR_DADDR_MASK)
/* TCD_CITER_ELINKNO Bit Fields */
#define DMA_TCD_CITER_ELINKNO_CTR_MASK          0x7FFFu
#define DMA_TCD_CITER_ELINKNO_CTR_SHIFT         0u
#define DMA_TCD_CITER_ELINKNO_CTR_WIDTH         15u
#define DMA_TCD_CITER_ELINKNO_CITER(x)          (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CITER_ELINKNO_CTR_SHIFT)) \
                                                  &DMA_TCD_CITER_ELINKNO_CTR_MASK)
#define DMA_TCD_CITER_ELINKNO_ELK_MASK          0x8000u
#define DMA_TCD_CITER_ELINKNO_ELK_SHIFT         15u
#define DMA_TCD_CITER_ELINKNO_ELK_WIDTH         1u
#define DMA_TCD_CITER_ELINKNO_ELINK(x)          (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CITER_ELINKNO_ELK_SHIFT)) \
                                                  &DMA_TCD_CITER_ELINKNO_ELK_MASK)
/* TCD_CITER_ELINKYES Bit Fields */
#define DMA_TCD_CTR_ELKYES_CITER_MASK           0x1FFu
#define DMA_TCD_CTR_ELKYES_CITER_SHIFT          0u
#define DMA_TCD_CTR_ELKYES_CITER_WIDTH          9u
#define DMA_TCD_CITER_ELINKYES_CITER(x)         (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CTR_ELKYES_CITER_SHIFT)) \
                                                  &DMA_TCD_CTR_ELKYES_CITER_MASK)
#define DMA_TCD_CTR_ELNKYES_LNKCH_MASK          0x7E00u
#define DMA_TCD_CTR_ELNKYES_LNKCH_SHIFT         9u
#define DMA_TCD_CTR_ELNKYES_LNKCH_WIDTH         6u
#define DMA_TCD_CITER_ELINKYES_LINKCH(x)        (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CTR_ELNKYES_LNKCH_SHIFT)) \
                                                  &DMA_TCD_CTR_ELNKYES_LNKCH_MASK)
#define DMA_TCD_CTR_ELINKYES_ELK_MASK           0x8000u
#define DMA_TCD_CTR_ELINKYES_ELK_SHIFT          15u
#define DMA_TCD_CTR_ELINKYES_ELK_WIDTH          1u
#define DMA_TCD_CITER_ELINKYES_ELINK(x)         (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CTR_ELINKYES_ELK_SHIFT)) \
                                                  &DMA_TCD_CTR_ELINKYES_ELK_MASK)
/* TCD_DOFF Bit Fields */
#define DMA_TCD_DOFF_DOFF_MASK                  0xFFFFu
#define DMA_TCD_DOFF_DOFF_SHIFT                 0u
#define DMA_TCD_DOFF_DOFF_WIDTH                 16u
#define DMA_TCD_DOFF_DOFF(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_DOFF_DOFF_SHIFT)) \
                                                  &DMA_TCD_DOFF_DOFF_MASK)
/* TCD_DLASTSGA Bit Fields */
#define DMA_TCD_DLASTSGA_DLASTSGA_MASK          0xFFFFFFFFu
#define DMA_TCD_DLASTSGA_DLASTSGA_SHIFT         0u
#define DMA_TCD_DLASTSGA_DLASTSGA_WIDTH         32u
#define DMA_TCD_DLASTSGA_DLASTSGA(x)            (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_DLASTSGA_DLASTSGA_SHIFT)) \
                                                  &DMA_TCD_DLASTSGA_DLASTSGA_MASK)
/* TCD_BITER_ELINKNO Bit Fields */
#define DMA_TCD_BITER_ELINKNO_BTR_MASK          0x7FFFu
#define DMA_TCD_BITER_ELINKNO_BTR_SHIFT         0u
#define DMA_TCD_BITER_ELINKNO_BTR_WIDTH         15u
#define DMA_TCD_BITER_ELINKNO_BITER(x)          (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_BITER_ELINKNO_BTR_SHIFT)) \
                                                  &DMA_TCD_BITER_ELINKNO_BTR_MASK)
#define DMA_TCD_BITER_ELINKNO_ELK_MASK          0x8000u
#define DMA_TCD_BITER_ELINKNO_ELK_SHIFT         15u
#define DMA_TCD_BITER_ELINKNO_ELK_WIDTH         1u
#define DMA_TCD_BITER_ELINKNO_ELINK(x)          (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_BITER_ELINKNO_ELK_SHIFT)) \
                                                  &DMA_TCD_BITER_ELINKNO_ELK_MASK)
/* TCD_BITER_ELINKYES Bit Fields */
#define DMA_TCD_BTR_ELINKYES_BTR_MASK           0x1FFu
#define DMA_TCD_BTR_ELINKYES_BTR_SHIFT          0u
#define DMA_TCD_BTR_ELINKYES_BTR_WIDTH          9u
#define DMA_TCD_BITER_ELINKYES_BITER(x)         (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_BTR_ELINKYES_BTR_SHIFT)) \
                                                  &DMA_TCD_BTR_ELINKYES_BTR_MASK)
#define DMA_TCD_BTR_ELKYES_LINKCH_MASK          0x7E00u
#define DMA_TCD_BTR_ELKYES_LINKCH_SHIFT         9u
#define DMA_TCD_BTR_ELKYES_LINKCH_WIDTH         6u
#define DMA_TCD_BITER_ELINKYES_LINKCH(x)        (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_BTR_ELKYES_LINKCH_SHIFT)) \
                                                  &DMA_TCD_BTR_ELKYES_LINKCH_MASK)
#define DMA_TCD_BTR_ELKYES_ELINK_MASK           0x8000u
#define DMA_TCD_BTR_ELKYES_ELINK_SHIFT          15u
#define DMA_TCD_BTR_ELKYES_ELINK_WIDTH          1u
#define DMA_TCD_BITER_ELINKYES_ELINK(x)         (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_BTR_ELKYES_ELINK_SHIFT)) \
                                                  &DMA_TCD_BTR_ELKYES_ELINK_MASK)
/* TCD_CSR Bit Fields */
#define DMA_TCD_CSR_START_MASK                  0x1u
#define DMA_TCD_CSR_START_SHIFT                 0u
#define DMA_TCD_CSR_START_WIDTH                 1u
#define DMA_TCD_CSR_START(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CSR_START_SHIFT)) \
                                                  &DMA_TCD_CSR_START_MASK)
#define DMA_TCD_CSR_INTMAJOR_MASK               0x2u
#define DMA_TCD_CSR_INTMAJOR_SHIFT              1u
#define DMA_TCD_CSR_INTMAJOR_WIDTH              1u
#define DMA_TCD_CSR_INTMAJOR(x)                 (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_INTMAJOR_SHIFT)) \
                                                  &DMA_TCD_CSR_INTMAJOR_MASK)
#define DMA_TCD_CSR_INTHALF_MASK                0x4u
#define DMA_TCD_CSR_INTHALF_SHIFT               2u
#define DMA_TCD_CSR_INTHALF_WIDTH               1u
#define DMA_TCD_CSR_INTHALF(x)                  (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_INTHALF_SHIFT)) \
                                                  &DMA_TCD_CSR_INTHALF_MASK)
#define DMA_TCD_CSR_DREQ_MASK                   0x8u
#define DMA_TCD_CSR_DREQ_SHIFT                  3u
#define DMA_TCD_CSR_DREQ_WIDTH                  1u
#define DMA_TCD_CSR_DREQ(x)                     (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_DREQ_SHIFT)) \
                                                  &DMA_TCD_CSR_DREQ_MASK)
#define DMA_TCD_CSR_ESG_MASK                    0x10u
#define DMA_TCD_CSR_ESG_SHIFT                   4u
#define DMA_TCD_CSR_ESG_WIDTH                   1u
#define DMA_TCD_CSR_ESG(x)                      (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_ESG_SHIFT)) \
                                                  &DMA_TCD_CSR_ESG_MASK)
#define DMA_TCD_CSR_MAJORELINK_MASK             0x20u
#define DMA_TCD_CSR_MAJORELINK_SHIFT            5u
#define DMA_TCD_CSR_MAJORELINK_WIDTH            1u
#define DMA_TCD_CSR_MAJORELINK(x)               (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_MAJORELINK_SHIFT)) \
                                                  &DMA_TCD_CSR_MAJORELINK_MASK)
#define DMA_TCD_CSR_ACTIVE_MASK                 0x40u
#define DMA_TCD_CSR_ACTIVE_SHIFT                6u
#define DMA_TCD_CSR_ACTIVE_WIDTH                1u
#define DMA_TCD_CSR_ACTIVE(x)                   (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CSR_ACTIVE_SHIFT)) \
                                                  &DMA_TCD_CSR_ACTIVE_MASK)
#define DMA_TCD_CSR_DONE_MASK                   0x80u
#define DMA_TCD_CSR_DONE_SHIFT                  7u
#define DMA_TCD_CSR_DONE_WIDTH                  1u
#define DMA_TCD_CSR_DONE(x)                     (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CSR_DONE_SHIFT)) \
                                                  &DMA_TCD_CSR_DONE_MASK)
#define DMA_TCD_CSR_MAJORLINKCH_MASK            0x3F00u
#define DMA_TCD_CSR_MAJORLINKCH_SHIFT           8u
#define DMA_TCD_CSR_MAJORLINKCH_WIDTH           6u
#define DMA_TCD_CSR_MAJORLINKCH(x)              (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_MAJORLINKCH_SHIFT)) \
                                                  &DMA_TCD_CSR_MAJORLINKCH_MASK)
#define DMA_TCD_CSR_BWC_MASK                    0xC000u
#define DMA_TCD_CSR_BWC_SHIFT                   14u
#define DMA_TCD_CSR_BWC_WIDTH                   2u
#define DMA_TCD_CSR_BWC(x)                      (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CSR_BWC_SHIFT)) \
                                                  &DMA_TCD_CSR_BWC_MASK)

#define DMAMUX_CHANNEL_COUNT                    (16u)

typedef struct
{
    volatile VAR(uint8, AUTOMATIC) CHCFG[DMAMUX_CHANNEL_COUNT];   /** Control Register, offset: 0x0 */
} DMAMUX_Type, *DMAMUX_MemMapPtr; /* PRQA S 1535 */

#ifdef RESOURCE_SUPPORT_DMAMUX10
#define DMAMUX_INSTANCE_COUNT                   (11u)
#else
#define DMAMUX_INSTANCE_COUNT                   (10u)
#endif

#define DMAMUX_0_BASE                           (0xFFF6C000UL)
#define DMAMUX_1_BASE                           (0xFFF6C200UL)
#define DMAMUX_2_BASE                           (0xFFF6C400UL)
#define DMAMUX_3_BASE                           (0xFFF6C600UL)
#define DMAMUX_4_BASE                           (0xFFF6C800UL)
#define DMAMUX_5_BASE                           (0xFFF6CA00UL)
#define DMAMUX_6_BASE                           (0xFFF6CC00UL)
#define DMAMUX_7_BASE                           (0xFFF6CE00UL)
#define DMAMUX_8_BASE                           (0xFFF6D000UL)
#define DMAMUX_9_BASE                           (0xFFF6D200UL)
#ifdef RESOURCE_SUPPORT_DMAMUX10
#define DMAMUX_10_BASE                          (0xFFF6D400UL)
#endif

/** Peripheral DMAMUX_0~9 base pointer */
#define DMAMUX0_P                               ((DMAMUX_Type *)DMAMUX_0_BASE)
#define DMAMUX1_P                               ((DMAMUX_Type *)DMAMUX_1_BASE)
#define DMAMUX2_P                               ((DMAMUX_Type *)DMAMUX_2_BASE)
#define DMAMUX3_P                               ((DMAMUX_Type *)DMAMUX_3_BASE)
#define DMAMUX4_P                               ((DMAMUX_Type *)DMAMUX_4_BASE)
#define DMAMUX5_P                               ((DMAMUX_Type *)DMAMUX_5_BASE)
#define DMAMUX6_P                               ((DMAMUX_Type *)DMAMUX_6_BASE)
#define DMAMUX7_P                               ((DMAMUX_Type *)DMAMUX_7_BASE)
#define DMAMUX8_P                               ((DMAMUX_Type *)DMAMUX_8_BASE)
#define DMAMUX9_P                               ((DMAMUX_Type *)DMAMUX_9_BASE)
#ifdef RESOURCE_SUPPORT_DMAMUX10
#define DMAMUX10_P                              ((DMAMUX_Type *)DMAMUX_10_BASE)
#endif

#ifdef RESOURCE_SUPPORT_DMAMUX10
#define DMAMUX_BASE_PTRS                        { DMAMUX0_P, DMAMUX1_P, DMAMUX2_P, DMAMUX3_P, \
                                                  DMAMUX4_P, DMAMUX5_P, DMAMUX6_P, DMAMUX7_P, \
                                                  DMAMUX8_P, DMAMUX9_P, DMAMUX10_P }
#else
#define DMAMUX_BASE_PTRS                        { DMAMUX0_P, DMAMUX1_P, DMAMUX2_P, DMAMUX3_P, \
                                                  DMAMUX4_P, DMAMUX5_P, DMAMUX6_P, DMAMUX7_P, \
                                                  DMAMUX8_P, DMAMUX9_P }
#endif

#define DMAMUX_CHCFG_ENBL_SHIFT                 7U
#define DMAMUX_CHCFG_ENBL_MASK                  0x80U
#define DMAMUX_CHCFG_SOURCE_SHIFT               0U
#define DMAMUX_CHCFG_SOURCE_MASK                0x3FU
#define DMAMUX_CHCFG_TRIG_SHIFT                 6U
#define DMAMUX_CHCFG_TRIG_MASK                  0x40U

typedef enum
{
    EDMA_INSTANCE_0 = 0U,
    EDMA_INSTANCE_1
} eDMAIstanceNumType;

typedef enum
{
    DMAMUX_INSTANCE_0 = 0U,
    DMAMUX_INSTANCE_1,
    DMAMUX_INSTANCE_2,
    DMAMUX_INSTANCE_3,
    DMAMUX_INSTANCE_4,
    DMAMUX_INSTANCE_5,
    DMAMUX_INSTANCE_6,
    DMAMUX_INSTANCE_7,
    DMAMUX_INSTANCE_8,
    DMAMUX_INSTANCE_9,
#ifdef RESOURCE_SUPPORT_DMAMUX10
    DMAMUX_INSTANCE_10
#endif
} DMAMUXInstanceNumType;

typedef enum
{
    EDMA_CHN_STATUS_NORMAL = 0U,           /* eDMA channel normal state. */
    EDMA_CHN_STATUS_ERROR                  /* An error occurred in the eDMA channel. */
} eDMAChnStatusType;

typedef enum
{
    EDMA_ARBITRATION_MODE_FIXED_PRIORITY = 0U,  /* Fixed Priority */
    EDMA_ARBITRATION_MODE_ROUND_ROBIN           /* Round - Robin arbitration */
} eDMASelArbitrationModeType;

typedef struct
{
    VAR(uint32, AUTOMATIC) errh;
    VAR(uint32, AUTOMATIC) errl;
} eDMAErrorRegisterType;

typedef enum
{
    EDMA_GRP_PRIORITY0 = 0U,
    EDMA_GRP_PRIORITY1 = 1U,
    EDMA_GRP_PRIORITY2 = 2U,
    EDMA_GRP_PRIORITY3 = 3U
} eDMAGroupPriorityType;

typedef struct
{
    VAR(eDMASelArbitrationModeType, AUTOMATIC) setChnArbitMode;         /* eDMA channel arbitration. */
    VAR(eDMASelArbitrationModeType, AUTOMATIC) groupArbitration;        /* eDMA group arbitration. */

    VAR(eDMAGroupPriorityType, AUTOMATIC) prioGroup0;                   /* eDMA group 0 priority. */
    VAR(eDMAGroupPriorityType, AUTOMATIC) prioGroup1;                   /* eDMA group 1 priority. */
    VAR(eDMAGroupPriorityType, AUTOMATIC) prioGroup2;                   /* eDMA group 2 priority. */
    VAR(eDMAGroupPriorityType, AUTOMATIC) prioGroup3;                   /* eDMA group 3 priority. */

    VAR(boolean, AUTOMATIC) haltOnError;
} eDMAModuleConfigType;

typedef enum
{
    EDMA_TRANSFER_SIZE_1B  = 0x0U,
    EDMA_TRANSFER_SIZE_2B  = 0x1U,
    EDMA_TRANSFER_SIZE_4B  = 0x2U,
    EDMA_TRANSFER_SIZE_16B = 0x4U,
} eDMATransferSizeType;

typedef enum
{
    EDMA_TRANSFER_TYPE_PERIPHTOMEM = 0U,   /* Transfer from peripheral to memory */
    EDMA_TRANSFER_TYPE_MEMTOPERIPH,        /* Transfer from memory to peripheral */
    EDMA_TRANSFER_TYPE_MEMTOMEM,           /* Transfer from memory to memory */
    EDMA_TRANSFER_TYPE_PERIPHTOPERIPH      /* Transfer from peripheral to peripheral */
} eDMATransferType;

typedef struct
{
    VAR(uint32, AUTOMATIC) address;
    VAR(uint32, AUTOMATIC) length;
    VAR(eDMATransferType, AUTOMATIC) type;
} eDMAScatterGatherListType;

typedef enum
{
    EDMA_CHN_PRIORITY0 = 0U,
    EDMA_CHN_PRIORITY1 = 1U,
    EDMA_CHN_PRIORITY2 = 2U,
    EDMA_CHN_PRIORITY3 = 3U,
    EDMA_CHN_PRIORITY4 = 4U,
    EDMA_CHN_PRIORITY5 = 5U,
    EDMA_CHN_PRIORITY6 = 6U,
    EDMA_CHN_PRIORITY7 = 7U,
    EDMA_CHN_PRIORITY8 = 8U,
    EDMA_CHN_PRIORITY9 = 9U,
    EDMA_CHN_PRIORITY10 = 10U,
    EDMA_CHN_PRIORITY11 = 11U,
    EDMA_CHN_PRIORITY12 = 12U,
    EDMA_CHN_PRIORITY13 = 13U,
    EDMA_CHN_PRIORITY14 = 14U,
    EDMA_CHN_PRIORITY15 = 15U,

    EDMA_CHN_PRIORITY_DEFALUT = 255U
} eDMAChannelPriorityType;

typedef enum
{
    EDMA_ADDRESS_MODULO_OFF = 0U,
    EDMA_ADDRESS_MODULO_2B,
    EDMA_ADDRESS_MODULO_4B,
    EDMA_ADDRESS_MODULO_8B,
    EDMA_ADDRESS_MODULO_16B,
    EDMA_ADDRESS_MODULO_32B,
    EDMA_ADDRESS_MODULO_64B,
    EDMA_ADDRESS_MODULO_128B,
    EDMA_ADDRESS_MODULO_256B,
    EDMA_ADDRESS_MODULO_512B,
    EDMA_ADDRESS_MODULO_1KB,
    EDMA_ADDRESS_MODULO_2KB,
    EDMA_ADDRESS_MODULO_4KB,
    EDMA_ADDRESS_MODULO_8KB,
    EDMA_ADDRESS_MODULO_16KB,
    EDMA_ADDRESS_MODULO_32KB,
    EDMA_ADDRESS_MODULO_64KB,
    EDMA_ADDRESS_MODULO_128KB,
    EDMA_ADDRESS_MODULO_256KB,
    EDMA_ADDRESS_MODULO_512KB,
    EDMA_ADDRESS_MODULO_1MB,
    EDMA_ADDRESS_MODULO_2MB,
    EDMA_ADDRESS_MODULO_4MB,
    EDMA_ADDRESS_MODULO_8MB,
    EDMA_ADDRESS_MODULO_16MB,
    EDMA_ADDRESS_MODULO_32MB,
    EDMA_ADDRESS_MODULO_64MB,
    EDMA_ADDRESS_MODULO_128MB,
    EDMA_ADDRESS_MODULO_256MB,
    EDMA_ADDRESS_MODULO_512MB,
    EDMA_ADDRESS_MODULO_1GB,
    EDMA_ADDRESS_MODULO_2GB
} eDMAModuloType;

typedef void (*eDMACallbackType) \
( \
	P2CONST(void, AUTOMATIC, EDMA_APPL_DATA) parameter, \
    VAR(eDMAChnStatusType, AUTOMATIC) status, \
    VAR(uint8, AUTOMATIC) mappedChannel \
);

typedef struct
{
    VAR(eDMAChannelPriorityType, AUTOMATIC) chnPrioSet;     /* eDMA channel priority - only used when channel
                                                               arbitration mode is 'Fixed priority'. */
    VAR(uint8, AUTOMATIC) mappedChnConfig;                  /* eDMA virtual channel number */

    VAR(eDMARequestSourceType, AUTOMATIC) reqSource;        /* Selects the source of the DMA request for this channel */

    VAR(eDMACallbackType, AUTOMATIC) callback;              /* Callback that will be registered for this channel */
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) callbackParam;   /* Parameter passed to the channel callback */
    VAR(boolean, AUTOMATIC) triggerEn;                      /* Enables the periodic trigger capability for the DMA channel. */

    VAR(boolean, AUTOMATIC) chnErrIntEn;                    /* enable/disable eDMA error channel interrupt. */
    VAR(boolean, AUTOMATIC) preemptionEn;                   /* Channel n can be temporarily suspended by the service request of a higher priority channel */
    VAR(boolean, AUTOMATIC) preemptAbilityDisable;          /* Channel n cannot suspend any channel, regardless of channel priority */
    VAR(boolean, AUTOMATIC) MasterIdReplicationEn;          /* Enable Master ID replication */
} eDMAChanConfigType;

typedef struct
{
    VAR(uint8, AUTOMATIC) channel;                          /* eDMA virtual channel number */    
    VAR(boolean, AUTOMATIC) isUsed;                         /* Mark whether the channel is in use */ 
    VAR(eDMAChannelPriorityType, AUTOMATIC) chPriority;     /* Channel priority. Unused channels are assigned a default priority */ 
} eDMAChPriorityCfg;

typedef struct
{
    VAR(uint8, AUTOMATIC) mappedChn;                        /* Virtual channel number. */
    VAR(eDMACallbackType, AUTOMATIC) callback;              /* Callback function pointer for the eDMA channel. It will
                                                               be called at the eDMA channel complete and eDMA channel error. */
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) parameter;       /* Parameter for the callback function pointer. */
    volatile VAR(eDMAChnStatusType, AUTOMATIC) status;      /* eDMA channel status. */
} eDMAChnStateType;

typedef struct
{
    VAR(uint32, AUTOMATIC) SADDR;
    VAR(uint16, AUTOMATIC) ATTR;
    VAR(sint16, AUTOMATIC) SOFF;
    VAR(uint32, AUTOMATIC) NBYTES;
    VAR(sint32, AUTOMATIC) SLAST;
    VAR(uint32, AUTOMATIC) DADDR;
    VAR(uint16, AUTOMATIC) CITER;
    VAR(sint16, AUTOMATIC) DOFF;
    VAR(sint32, AUTOMATIC) DLAST_SGA;
    VAR(uint16, AUTOMATIC) BITER;
    VAR(uint16, AUTOMATIC) CSR;
} eDMASwTcdType;

typedef struct
{
    VAR(uint32, AUTOMATIC) majorLpIterCnt;                  /* Number of major loop iterations. */
    VAR(boolean, AUTOMATIC) srcAddrOffsetEn;                /* Selects whether the minor loop offset is applied to the
                                                               source address upon minor loop completion. */
    VAR(boolean, AUTOMATIC) dstAddrOffsetEn;                /* Selects whether the minor loop offset is applied to the
                                                               destination address upon minor loop completion. */
    VAR(sint32, AUTOMATIC) minorLpOffset;                   /* Sign - extended offset applied to the source or destination address
                                                               to form the next - state value after the minor loop completes. */
    VAR(boolean, AUTOMATIC) minorLpLinkEn;                  /* Enables channel - to - channel linking on minor loop complete. */
    VAR(uint8, AUTOMATIC) minorLpLinkChn;                   /* The number of the next channel to be started by DMA
                                                               engine when minor loop completes. */
    VAR(boolean, AUTOMATIC) majorLpLinkEn;                  /* Enables channel - to - channel linking on major loop complete. */
    VAR(uint8, AUTOMATIC) majorLpLinkChn;                   /* The number of the next channel to be started by DMA
                                                               engine when major loop completes. */
} eDMALoopTransferConfigType;

typedef struct
{
    VAR(boolean, AUTOMATIC) minorLpMap;                             /* Configure minor loop map. */
    VAR(uint32, AUTOMATIC) srcAddr;                                 /* Memory address pointing to the source data. */
    VAR(uint32, AUTOMATIC) destAddr;                                /* Memory address pointing to the destination data. */
    VAR(eDMATransferSizeType, AUTOMATIC) srcTransDataSize;          /* Source data transfer size. */
    VAR(eDMATransferSizeType, AUTOMATIC) destTransDataSize;         /* Destination data transfer size. */
    VAR(sint16, AUTOMATIC) srcAddrOffset;                           /* Sign - extended offset applied to the current source address
                                                                       to form the next - state value as each source read/write
                                                                       is completed. */
    VAR(sint16, AUTOMATIC) destAddrOffset;                          /* Sign - extended offset applied to the current destination
                                                                       address to form the next - state value as each source
                                                                       read/write is completed. */
    VAR(sint32, AUTOMATIC) srcAddrAdjustLast;                       /* Last source address adjustment. */
    VAR(sint32, AUTOMATIC) destAddrAdjustLast;                      /* Last destination address adjustment. Note here it is only
                                                                       valid when scatter/gather feature is not enabled. */
    VAR(eDMAModuloType, AUTOMATIC) srcAddrModulo;                   /* Source address modulo. */
    VAR(eDMAModuloType, AUTOMATIC) destAddrModulo;                  /* Destination address modulo. */
    VAR(uint32, AUTOMATIC) minorTransByte;                          /* Number of bytes to be transferred in each service request
                                                                       of the channel. */
    VAR(boolean, AUTOMATIC) featureScatterGatherEn;                 /* Enable scatter gather feature. */
    VAR(uint32, AUTOMATIC) featureScatterGatherNextDescriptor;      /* The address of the next descriptor to be used, when
                                                                       scatter/gather feature is enabled.
                                                                       Note: this value is not used when scatter/gather
                                                                       feature is disabled. */
    VAR(boolean, AUTOMATIC) completeIntEn;                          /* Enable the interrupt request when the major loop
                                                                       count completes */
    P2VAR(eDMALoopTransferConfigType, AUTOMATIC, EDMA_APPL_DATA) lpTransConfigPtr;   /* Pointer to loop transfer configuration structure
                                                                                        (defines minor/major loop attributes)
                                                                                        Note: this field is only used when minor loop mapping is
                                                                                        enabled from DMA configuration. */
} eDMATransferConfigType;

typedef enum
{
    EDMA_CHN_ENABLE_ERROR_INT = 0U,         /* Error interrupt */
    EDMA_CHN_ENABLE_HALF_MAJOR_LOOP_INT,    /* Half major loop interrupt. */
    EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT     /* Complete major loop interrupt. */
} eDMAChannelInterruptType;

typedef struct
{
    P2VAR(eDMAChnStateType, AUTOMATIC, EDMA_APPL_DATA) volatile mapChnState[(uint32)EDMA_MAPPED_CHANNELS]; /* Pointer array storing channel state. */
} edma_state_t;

FUNC(status_t, EDMA_CODE) EDMA_LLD_SetUpCallback \
( \
    VAR(uint8, AUTOMATIC) mappedChannel,
    VAR(eDMACallbackType, AUTOMATIC) callback,
    P2VAR(void, AUTOMATIC, EDMA_APPL_DATA) parameter \
);
FUNC(void, EDMA_CODE) EDMA_HW_ClearIntStatus(VAR(uint8, AUTOMATIC) mappedChannel);
FUNC(void, EDMA_CODE) EDMA_LLD_SwRequestTriggerEn(VAR(uint8, AUTOMATIC) mappedChannel);
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetChannelSourceConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel,
    VAR(uint32, AUTOMATIC) request,
    VAR(boolean, AUTOMATIC) triggerEn \
);
FUNC(status_t, EDMA_CODE) EDMA_LLD_ChannelInit \
( \
    P2VAR(eDMAChnStateType, AUTOMATIC, EDMA_APPL_DATA) eedma_channelState, \
    P2CONST(eDMAChanConfigType, EDMA_CONST, EDMA_APPL_CONST) eedma_channelConfig \
);
FUNC(status_t, EDMA_CODE) EDMA_LLD_ModuleInit \
( \
    P2VAR(edma_state_t, AUTOMATIC, EDMA_APPL_DATA) edmaState, \
    P2CONST(eDMAModuleConfigType, EDMA_CONST, EDMA_APPL_CONST) userConfig, \
    CONSTP2VAR(eDMAChnStateType, EDMA_CONST, EDMA_APPL_CONST) chnStateArray[], \
    CONSTP2CONST(eDMAChanConfigType, EDMA_CONST, EDMA_APPL_CONST) chnConfigArray[], \
    VAR(uint32, AUTOMATIC) chnCount \
);

FUNC(void, EDMA_CODE) EDMA_LLD_NoUsedChInit \
( \
    CONSTP2CONST(eDMAChPriorityCfg, EDMA_CONST, EDMA_APPL_CONST) chPriorityCfgs \
);

FUNC(void, EDMA_CODE) EDMA_LLD_ClearSwTCDStruct \
( \
    P2VAR(eDMASwTcdType, AUTOMATIC, EDMA_APPL_DATA) swtcd \
);
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetSglTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, /* PRQA S 2755 */ \
    VAR(eDMATransferType, AUTOMATIC) type, \
    VAR(uint32, AUTOMATIC) srcAddr, \
    VAR(uint32, AUTOMATIC) destAddr, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) dataBufferSize \
);
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetMultiTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferType, AUTOMATIC) type, \
    VAR(uint32, AUTOMATIC) srcAddr, \
    VAR(uint32, AUTOMATIC) destAddr, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) blockSize, \
    VAR(uint32, AUTOMATIC) blockCount, \
    VAR(boolean, AUTOMATIC) disableReqOnCompletion \
);
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetLoopTransferConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    P2CONST(eDMATransferConfigType, EDMA_CONST, EDMA_APPL_CONST) transferConfig \
);
FUNC(void, EDMA_CODE) EDMA_LLD_CopyConfigToSwTCD \
( \
    P2CONST(eDMATransferConfigType, EDMA_CONST, EDMA_APPL_CONST) config,
    P2VAR(eDMASwTcdType, AUTOMATIC, EDMA_APPL_DATA)stcd \
);
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetScatterGatherTrfCfg \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    P2CONST(eDMASwTcdType, EDMA_CONST, EDMA_APPL_CONST) stcd, \
    VAR(eDMATransferSizeType, AUTOMATIC) transferSize, \
    VAR(uint32, AUTOMATIC) bytesOnEachRequest, \
    P2CONST(eDMAScatterGatherListType, EDMA_CONST, EDMA_APPL_CONST) srcList, \
    P2CONST(eDMAScatterGatherListType, EDMA_CONST, EDMA_APPL_CONST) destList, \
    VAR(uint8, AUTOMATIC) tcdCount \
);
FUNC(status_t, EDMA_CODE) EDMA_LLD_SetChannelRequest(VAR(uint8, AUTOMATIC) mappedChannel);
FUNC(status_t, EDMA_CODE) EDMA_LLD_ClearChannelRequest(VAR(uint8, AUTOMATIC) mappedChannel);
FUNC(void, EDMA_CODE) EDMA_LLD_ClearHwTCD(VAR(uint8, AUTOMATIC) mappedChannel);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddr \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) address \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddrOffset \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint16, AUTOMATIC) offset \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddrRdTrfSize \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSrcAddrLastAdj \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint32, AUTOMATIC) adjust \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestAddrLastAdj \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint32, AUTOMATIC) adjust \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestAddr \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) address \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestAddrOffset \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(sint16, AUTOMATIC) offset \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDestdrWrTrfSize \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMATransferSizeType, AUTOMATIC) size \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnMinorLpTrfByte \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) nbytes \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnMajorLpIterCount \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) majorLoopCount \
);
FUNC(uint32, EDMA_CODE) EDMA_LLD_GetChnRemainingIterCnt \
( \
    VAR(uint8, AUTOMATIC) mappedChannel \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnSctGthLinkMode \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(uint32, AUTOMATIC) nextTCDAddr \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetChnDisReqOnTrfComp \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(boolean, AUTOMATIC) disable \
);
FUNC(void, EDMA_CODE) EDMA_LLD_SetInterruptConfig \
( \
    VAR(uint8, AUTOMATIC) mappedChannel, \
    VAR(eDMAChannelInterruptType, AUTOMATIC) intSrc, \
    VAR(boolean, AUTOMATIC) enable \
);
FUNC(void, EDMA_CODE) EDMA_LLD_CancelExcutingChnTrf(VAR(boolean, AUTOMATIC) error);
FUNC(void, EDMA_CODE) EDMA_LLD_WaitChnTransferDone(VAR(uint8, AUTOMATIC) mappedChannel);
FUNC(eDMAChnStatusType, EDMA_CODE) EDMA_LLD_GetChnConfigStatus \
( \
    VAR(uint8, AUTOMATIC) mappedChannel \
);
FUNC(void, EDMA_CODE) EDMA_LLD_IRQHandler(VAR(uint8, AUTOMATIC) mappedChannel);
FUNC(void, EDMA_CODE) EDMA_LLD_ErrorIRQHandler(VAR(uint8, AUTOMATIC) mappedChannel);
FUNC(void, EDMA_CODE) EDMA_Ch0_Ch127_Error_IRQHandler(void);
FUNC(boolean, EDMA_CODE) EDMA_LLD_GetMasterID_PAL \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
FUNC(uint8, EDMA_CODE) EDMA_LLD_GetMasterID_MID \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
#ifdef __cplusplus
}
#endif

#endif /* EDMA_LLD__H_ */
