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
*   @file    eDma_Irq.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eDma MCAL driver.
*
*   @addtogroup eDma
*   @{
*/

#ifndef EDMA_IRQ_H_
#define EDMA_IRQ_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "eDma_LLDriver.h"
#include "intc_lld.h"

#define EDMA_IRQ_H_VENDOR_ID                     176
#define EDMA_IRQ_H_AR_REL_MAJOR_VER              4
#define EDMA_IRQ_H_AR_REL_MINOR_VER              4
#define EDMA_IRQ_H_AR_REL_REV_VER                0
#define EDMA_IRQ_H_SW_MAJOR_VER                  1
#define EDMA_IRQ_H_SW_MINOR_VER                  0
#define EDMA_IRQ_H_SW_PATCH_VER                  1

#if (EDMA_CFG_H_VENDOR_ID != EDMA_IRQ_H_VENDOR_ID)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_VENDOR_ID "
#endif
#if (EDMA_CFG_H_AR_REL_MAJOR_VER != EDMA_IRQ_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_AR_REL_MAJOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_MINOR_VER != EDMA_IRQ_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_AR_REL_MINOR_VER "
#endif
#if (EDMA_CFG_H_AR_REL_REV_VER != EDMA_IRQ_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_AR_REL_REV_VER "
#endif
#if (EDMA_CFG_H_SW_MAJOR_VER != EDMA_IRQ_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_SW_MAJOR_VER "
#endif
#if (EDMA_CFG_H_SW_MINOR_VER != EDMA_IRQ_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_SW_MINOR_VER "
#endif
#if (EDMA_CFG_H_SW_PATCH_VER != EDMA_IRQ_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EDMA_IRQ_H_SW_PATCH_VER "
#endif

FUNC(void, EDMA_CODE) EDMA_Ch0_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch1_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch2_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch3_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch4_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch5_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch6_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch7_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch8_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch9_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch10_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch11_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch12_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch13_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch14_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch15_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch16_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch17_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch18_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch19_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch20_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch21_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch22_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch23_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch24_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch25_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch26_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch27_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch28_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch29_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch30_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch31_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch32_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch33_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch34_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch35_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch36_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch37_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch38_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch39_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch40_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch41_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch42_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch43_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch44_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch45_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch46_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch47_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch48_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch49_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch50_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch51_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch52_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch53_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch54_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch55_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch56_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch57_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch58_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch59_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch60_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch61_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch62_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch63_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch64_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch65_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch66_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch67_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch68_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch69_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch70_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch71_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch72_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch73_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch74_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch75_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch76_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch77_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch78_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch79_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch80_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch81_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch82_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch83_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch84_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch85_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch86_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch87_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch88_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch89_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch90_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch91_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch92_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch93_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch94_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch95_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch96_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch97_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch98_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch99_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch100_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch101_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch102_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch103_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch104_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch105_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch106_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch107_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch108_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch109_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch110_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch111_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch112_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch113_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch114_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch115_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch116_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch117_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch118_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch119_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch120_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch121_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch122_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch123_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch124_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch125_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch126_IRQHandler(void);
FUNC(void, EDMA_CODE) EDMA_Ch127_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* EDMA_LLD__H_ */
