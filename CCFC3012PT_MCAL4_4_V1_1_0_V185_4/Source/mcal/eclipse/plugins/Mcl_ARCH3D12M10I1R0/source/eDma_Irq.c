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
*   @file    eDma_Irq.c
*   @version 1.0.1
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

#include "eDma_Irq.h"

#define EDMA_IRQ_C_VENDOR_ID                     176
#define EDMA_IRQ_C_AR_REL_MAJOR_VER              4
#define EDMA_IRQ_C_AR_REL_MINOR_VER              4
#define EDMA_IRQ_C_AR_REL_REV_VER                0
#define EDMA_IRQ_C_SW_MAJOR_VER                  1
#define EDMA_IRQ_C_SW_MINOR_VER                  0
#define EDMA_IRQ_C_SW_PATCH_VER                  1

#if (EDMA_CFG_H_VENDOR_ID != EDMA_IRQ_C_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_VENDOR_ID "
#endif
#if (EDMA_CFG_H_AR_REL_MAJOR_VER != EDMA_IRQ_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_AR_REL_MAJOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_MINOR_VER != EDMA_IRQ_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_AR_REL_MINOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_REV_VER != EDMA_IRQ_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_AR_REL_REV_VER "
#endif
#if (EDMA_CFG_H_SW_MAJOR_VER != EDMA_IRQ_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_SW_MAJOR_VER "
#endif
#if (EDMA_CFG_H_SW_MINOR_VER != EDMA_IRQ_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_SW_MINOR_VER "
#endif
#if (EDMA_CFG_H_SW_PATCH_VER != EDMA_IRQ_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_C_SW_PATCH_VER "
#endif

#if EDMA_CH0_CH127_INT
FUNC(void, EDMA_CODE) EDMA_Ch0_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(0U);
}

FUNC(void, EDMA_CODE) EDMA_Ch1_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(1U);
}

FUNC(void, EDMA_CODE) EDMA_Ch2_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(2U);
}

FUNC(void, EDMA_CODE) EDMA_Ch3_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(3U);
}

FUNC(void, EDMA_CODE) EDMA_Ch4_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(4U);
}

FUNC(void, EDMA_CODE) EDMA_Ch5_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(5U);
}

FUNC(void, EDMA_CODE) EDMA_Ch6_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(6U);
}

FUNC(void, EDMA_CODE) EDMA_Ch7_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(7U);
}

FUNC(void, EDMA_CODE) EDMA_Ch8_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(8U);
}

FUNC(void, EDMA_CODE) EDMA_Ch9_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(9U);
}

FUNC(void, EDMA_CODE) EDMA_Ch10_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(10U);
}

FUNC(void, EDMA_CODE) EDMA_Ch11_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(11U);
}

FUNC(void, EDMA_CODE) EDMA_Ch12_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(12U);
}

FUNC(void, EDMA_CODE) EDMA_Ch13_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(13U);
}

FUNC(void, EDMA_CODE) EDMA_Ch14_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(14U);
}

FUNC(void, EDMA_CODE) EDMA_Ch15_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(15U);
}

FUNC(void, EDMA_CODE) EDMA_Ch16_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(16U);
}

FUNC(void, EDMA_CODE) EDMA_Ch17_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(17U);
}

FUNC(void, EDMA_CODE) EDMA_Ch18_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(18U);
}

FUNC(void, EDMA_CODE) EDMA_Ch19_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(19U);
}

FUNC(void, EDMA_CODE) EDMA_Ch20_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(20U);
}

FUNC(void, EDMA_CODE) EDMA_Ch21_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(21U);
}

FUNC(void, EDMA_CODE) EDMA_Ch22_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(22U);
}

FUNC(void, EDMA_CODE) EDMA_Ch23_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(23U);
}

FUNC(void, EDMA_CODE) EDMA_Ch24_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(24U);
}

FUNC(void, EDMA_CODE) EDMA_Ch25_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(25U);
}

FUNC(void, EDMA_CODE) EDMA_Ch26_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(26U);
}

FUNC(void, EDMA_CODE) EDMA_Ch27_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(27U);
}

FUNC(void, EDMA_CODE) EDMA_Ch28_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(28U);
}

FUNC(void, EDMA_CODE) EDMA_Ch29_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(29U);
}

FUNC(void, EDMA_CODE) EDMA_Ch30_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(30U);
}

FUNC(void, EDMA_CODE) EDMA_Ch31_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(31U);
}

FUNC(void, EDMA_CODE) EDMA_Ch32_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(32U);
}

FUNC(void, EDMA_CODE) EDMA_Ch33_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(33U);
}

FUNC(void, EDMA_CODE) EDMA_Ch34_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(34U);
}

FUNC(void, EDMA_CODE) EDMA_Ch35_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(35U);
}

FUNC(void, EDMA_CODE) EDMA_Ch36_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(36U);
}

FUNC(void, EDMA_CODE) EDMA_Ch37_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(37U);
}

FUNC(void, EDMA_CODE) EDMA_Ch38_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(38U);
}

FUNC(void, EDMA_CODE) EDMA_Ch39_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(39U);
}

FUNC(void, EDMA_CODE) EDMA_Ch40_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(40U);
}

FUNC(void, EDMA_CODE) EDMA_Ch41_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(41U);
}

FUNC(void, EDMA_CODE) EDMA_Ch42_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(42U);
}

FUNC(void, EDMA_CODE) EDMA_Ch43_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(43U);
}

FUNC(void, EDMA_CODE) EDMA_Ch44_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(44U);
}

FUNC(void, EDMA_CODE) EDMA_Ch45_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(45U);
}

FUNC(void, EDMA_CODE) EDMA_Ch46_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(46U);
}

FUNC(void, EDMA_CODE) EDMA_Ch47_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(47U);
}

FUNC(void, EDMA_CODE) EDMA_Ch48_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(48U);
}

FUNC(void, EDMA_CODE) EDMA_Ch49_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(49U);
}

FUNC(void, EDMA_CODE) EDMA_Ch50_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(50U);
}

FUNC(void, EDMA_CODE) EDMA_Ch51_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(51U);
}

FUNC(void, EDMA_CODE) EDMA_Ch52_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(52U);
}

FUNC(void, EDMA_CODE) EDMA_Ch53_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(53U);
}

FUNC(void, EDMA_CODE) EDMA_Ch54_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(54U);
}

FUNC(void, EDMA_CODE) EDMA_Ch55_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(55U);
}

FUNC(void, EDMA_CODE) EDMA_Ch56_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(56U);
}

FUNC(void, EDMA_CODE) EDMA_Ch57_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(57U);
}

FUNC(void, EDMA_CODE) EDMA_Ch58_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(58U);
}

FUNC(void, EDMA_CODE) EDMA_Ch59_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(59U);
}

FUNC(void, EDMA_CODE) EDMA_Ch60_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(60U);
}

FUNC(void, EDMA_CODE) EDMA_Ch61_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(61U);
}

FUNC(void, EDMA_CODE) EDMA_Ch62_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(62U);
}

FUNC(void, EDMA_CODE) EDMA_Ch63_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(63U);
}

FUNC(void, EDMA_CODE) EDMA_Ch64_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(64U);
}

FUNC(void, EDMA_CODE) EDMA_Ch65_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(65U);
}

FUNC(void, EDMA_CODE) EDMA_Ch66_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(66U);
}

FUNC(void, EDMA_CODE) EDMA_Ch67_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(67U);
}

FUNC(void, EDMA_CODE) EDMA_Ch68_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(68U);
}

FUNC(void, EDMA_CODE) EDMA_Ch69_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(69U);
}

FUNC(void, EDMA_CODE) EDMA_Ch70_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(70U);
}

FUNC(void, EDMA_CODE) EDMA_Ch71_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(71U);
}

FUNC(void, EDMA_CODE) EDMA_Ch72_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(72U);
}

FUNC(void, EDMA_CODE) EDMA_Ch73_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(73U);
}

FUNC(void, EDMA_CODE) EDMA_Ch74_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(74U);
}

FUNC(void, EDMA_CODE) EDMA_Ch75_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(75U);
}

FUNC(void, EDMA_CODE) EDMA_Ch76_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(76U);
}

FUNC(void, EDMA_CODE) EDMA_Ch77_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(77U);
}

FUNC(void, EDMA_CODE) EDMA_Ch78_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(78U);
}

FUNC(void, EDMA_CODE) EDMA_Ch79_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(79U);
}

FUNC(void, EDMA_CODE) EDMA_Ch80_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(80U);
}

FUNC(void, EDMA_CODE) EDMA_Ch81_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(81U);
}

FUNC(void, EDMA_CODE) EDMA_Ch82_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(82U);
}

FUNC(void, EDMA_CODE) EDMA_Ch83_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(83U);
}

FUNC(void, EDMA_CODE) EDMA_Ch84_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(84U);
}

FUNC(void, EDMA_CODE) EDMA_Ch85_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(85U);
}

FUNC(void, EDMA_CODE) EDMA_Ch86_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(86U);
}

FUNC(void, EDMA_CODE) EDMA_Ch87_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(87U);
}

FUNC(void, EDMA_CODE) EDMA_Ch88_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(88U);
}

FUNC(void, EDMA_CODE) EDMA_Ch89_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(89U);
}

FUNC(void, EDMA_CODE) EDMA_Ch90_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(90U);
}

FUNC(void, EDMA_CODE) EDMA_Ch91_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(91U);
}

FUNC(void, EDMA_CODE) EDMA_Ch92_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(92U);
}

FUNC(void, EDMA_CODE) EDMA_Ch93_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(93U);
}

FUNC(void, EDMA_CODE) EDMA_Ch94_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(94U);
}

FUNC(void, EDMA_CODE) EDMA_Ch95_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(95U);
}

FUNC(void, EDMA_CODE) EDMA_Ch96_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(96U);
}

FUNC(void, EDMA_CODE) EDMA_Ch97_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(97U);
}

FUNC(void, EDMA_CODE) EDMA_Ch98_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(98U);
}

FUNC(void, EDMA_CODE) EDMA_Ch99_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(99U);
}

FUNC(void, EDMA_CODE) EDMA_Ch100_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(100U);
}

FUNC(void, EDMA_CODE) EDMA_Ch101_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(101U);
}

FUNC(void, EDMA_CODE) EDMA_Ch102_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(102U);
}

FUNC(void, EDMA_CODE) EDMA_Ch103_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(103U);
}

FUNC(void, EDMA_CODE) EDMA_Ch104_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(104U);
}

FUNC(void, EDMA_CODE) EDMA_Ch105_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(105U);
}

FUNC(void, EDMA_CODE) EDMA_Ch106_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(106U);
}

FUNC(void, EDMA_CODE) EDMA_Ch107_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(107U);
}

FUNC(void, EDMA_CODE) EDMA_Ch108_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(108U);
}

FUNC(void, EDMA_CODE) EDMA_Ch109_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(109U);
}

FUNC(void, EDMA_CODE) EDMA_Ch110_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(110U);
}

FUNC(void, EDMA_CODE) EDMA_Ch111_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(111U);
}

FUNC(void, EDMA_CODE) EDMA_Ch112_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(112U);
}

FUNC(void, EDMA_CODE) EDMA_Ch113_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(113U);
}

FUNC(void, EDMA_CODE) EDMA_Ch114_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(114U);
}

FUNC(void, EDMA_CODE) EDMA_Ch115_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(115U);
}

FUNC(void, EDMA_CODE) EDMA_Ch116_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(116U);
}

FUNC(void, EDMA_CODE) EDMA_Ch117_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(117U);
}

FUNC(void, EDMA_CODE) EDMA_Ch118_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(118U);
}

FUNC(void, EDMA_CODE) EDMA_Ch119_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(119U);
}

FUNC(void, EDMA_CODE) EDMA_Ch120_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(120U);
}

FUNC(void, EDMA_CODE) EDMA_Ch121_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(121U);
}

FUNC(void, EDMA_CODE) EDMA_Ch122_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(122U);
}

FUNC(void, EDMA_CODE) EDMA_Ch123_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(123U);
}

FUNC(void, EDMA_CODE) EDMA_Ch124_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(124U);
}

FUNC(void, EDMA_CODE) EDMA_Ch125_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(125U);
}

FUNC(void, EDMA_CODE) EDMA_Ch126_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(126U);
}

FUNC(void, EDMA_CODE) EDMA_Ch127_IRQHandler(void)
{
    EDMA_LLD_IRQHandler(127U);
}
#endif

#ifdef __cplusplus
}
#endif
