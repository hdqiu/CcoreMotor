/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC 
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
*   @file    eTPU_HAL_Irq.c
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/


/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "eTPU_HAL_Irq.h"
#ifdef RESOURCE_SUPPORT_ETPU
#include "Icu_eTPU_LLDrivers.h"
#include "eTPU_LLDrivers.h"
#include "Icu_eTPU_HAL_Wrapper.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/

#define ETPU_HAL_IRQ_VENDOR_ID_C                   176

#define ETPU_HAL_IRQ_MAJOR_VER_C                   4
#define ETPU_HAL_IRQ_MINOR_VER_C                   4
#define ETPU_HAL_IRQ_REVISION_VER_C                0

#define ETPU_HAL_IRQ_SW_MAJOR_VER_C                1
#define ETPU_HAL_IRQ_SW_MINOR_VER_C                0
#define ETPU_HAL_IRQ_SW_PATCH_VER_C                1

#if (ETPU_HAL_IRQ_VENDOR_ID_C != ETPU_HAL_IRQ_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ETPU_HAL_IRQ_MAJOR_VER_C != ETPU_HAL_IRQ_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ETPU_HAL_IRQ_MINOR_VER_C != ETPU_HAL_IRQ_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ETPU_HAL_IRQ_REVISION_VER_C != ETPU_HAL_IRQ_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ETPU_HAL_IRQ_SW_MAJOR_VER_C != ETPU_HAL_IRQ_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ETPU_HAL_IRQ_SW_MINOR_VER_C != ETPU_HAL_IRQ_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ETPU_HAL_IRQ_SW_PATCH_VER_C != ETPU_HAL_IRQ_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTION
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) eTPU_LLD_IRQHandler
(
    VAR(uint8_t, AUTOMATIC) etpuIndex, \
    VAR(uint8_t, AUTOMATIC) ChanNum \
)
{
    /* Clear INT flag */
    if (etpuIndex == (uint8)eTPU_A)
    {
        ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_A_B, ETPU_A_CHANNLE(ChanNum));
    }
    else if (etpuIndex ==(uint8) eTPU_B)
    {
        ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_A_B, ETPU_B_CHANNLE(ChanNum));
    }
    else
    {
        ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_C, ETPU_C_CHANNLE(ChanNum));
    }

    eTpu_Channel_ProcessCommonIrq(etpuIndex, ChanNum);
}

FUNC(void, ICU_CODE) eTPUA_CH0_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 0);
}

FUNC(void, ICU_CODE) eTPUA_CH1_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 1);
}

FUNC(void, ICU_CODE) eTPUA_CH2_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 2);
}

FUNC(void, ICU_CODE) eTPUA_CH3_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 3);
}

FUNC(void, ICU_CODE) eTPUA_CH4_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 4);
}

FUNC(void, ICU_CODE) eTPUA_CH5_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 5);
}

FUNC(void, ICU_CODE) eTPUA_CH6_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 6);
}

FUNC(void, ICU_CODE) eTPUA_CH7_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 7);
}

FUNC(void, ICU_CODE) eTPUA_CH8_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 8);
}

FUNC(void, ICU_CODE) eTPUA_CH9_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 9);
}

FUNC(void, ICU_CODE) eTPUA_CH10_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 10);
}

FUNC(void, ICU_CODE) eTPUA_CH11_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 11);
}

FUNC(void, ICU_CODE) eTPUA_CH12_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 12);
}

FUNC(void, ICU_CODE) eTPUA_CH13_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 13);
}

FUNC(void, ICU_CODE) eTPUA_CH14_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 14);
}

FUNC(void, ICU_CODE) eTPUA_CH15_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 15);
}

FUNC(void, ICU_CODE) eTPUA_CH16_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 16);
}

FUNC(void, ICU_CODE) eTPUA_CH17_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 17);
}

FUNC(void, ICU_CODE) eTPUA_CH18_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 18);
}

FUNC(void, ICU_CODE) eTPUA_CH19_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 19);
}

FUNC(void, ICU_CODE) eTPUA_CH20_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 20);
}

FUNC(void, ICU_CODE) eTPUA_CH21_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 21);
}

FUNC(void, ICU_CODE) eTPUA_CH22_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 22);
}

FUNC(void, ICU_CODE) eTPUA_CH23_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 23);
}

FUNC(void, ICU_CODE) eTPUA_CH24_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 24);
}

FUNC(void, ICU_CODE) eTPUA_CH25_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 25);
}

FUNC(void, ICU_CODE) eTPUA_CH26_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 26);
}

FUNC(void, ICU_CODE) eTPUA_CH27_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 27);
}

FUNC(void, ICU_CODE) eTPUA_CH28_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 28);
}

FUNC(void, ICU_CODE) eTPUA_CH29_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 29);
}

FUNC(void, ICU_CODE) eTPUA_CH30_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 30);
}

FUNC(void, ICU_CODE) eTPUA_CH31_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_A, 31);
}

FUNC(void, ICU_CODE) eTPUB_CH0_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 0);
}

FUNC(void, ICU_CODE) eTPUB_CH1_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 1);
}

FUNC(void, ICU_CODE) eTPUB_CH2_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 2);
}

FUNC(void, ICU_CODE) eTPUB_CH3_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 3);
}

FUNC(void, ICU_CODE) eTPUB_CH4_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 4);
}

FUNC(void, ICU_CODE) eTPUB_CH5_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 5);
}

FUNC(void, ICU_CODE) eTPUB_CH6_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 6);
}

FUNC(void, ICU_CODE) eTPUB_CH7_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 7);
}

FUNC(void, ICU_CODE) eTPUB_CH8_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 8);
}

FUNC(void, ICU_CODE) eTPUB_CH9_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 9);
}

FUNC(void, ICU_CODE) eTPUB_CH10_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 10);
}

FUNC(void, ICU_CODE) eTPUB_CH11_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 11);
}

FUNC(void, ICU_CODE) eTPUB_CH12_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 12);
}

FUNC(void, ICU_CODE) eTPUB_CH13_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 13);
}

FUNC(void, ICU_CODE) eTPUB_CH14_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 14);
}

FUNC(void, ICU_CODE) eTPUB_CH15_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 15);
}

FUNC(void, ICU_CODE) eTPUB_CH16_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 16);
}

FUNC(void, ICU_CODE) eTPUB_CH17_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 17);
}

FUNC(void, ICU_CODE) eTPUB_CH18_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 18);
}

FUNC(void, ICU_CODE) eTPUB_CH19_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 19);
}

FUNC(void, ICU_CODE) eTPUB_CH20_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 20);
}

FUNC(void, ICU_CODE) eTPUB_CH21_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 21);
}

FUNC(void, ICU_CODE) eTPUB_CH22_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 22);
}

FUNC(void, ICU_CODE) eTPUB_CH23_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 23);
}

FUNC(void, ICU_CODE) eTPUB_CH24_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 24);
}

FUNC(void, ICU_CODE) eTPUB_CH25_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 25);
}

FUNC(void, ICU_CODE) eTPUB_CH26_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 26);
}

FUNC(void, ICU_CODE) eTPUB_CH27_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 27);
}

FUNC(void, ICU_CODE) eTPUB_CH28_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 28);
}

FUNC(void, ICU_CODE) eTPUB_CH29_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 29);
}

FUNC(void, ICU_CODE) eTPUB_CH30_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 30);
}

FUNC(void, ICU_CODE) eTPUB_CH31_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_B, 31);
}

FUNC(void, ICU_CODE) eTPUC_CH0_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 0);
}

FUNC(void, ICU_CODE) eTPUC_CH1_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 1);
}

FUNC(void, ICU_CODE) eTPUC_CH2_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 2);
}

FUNC(void, ICU_CODE) eTPUC_CH3_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 3);
}

FUNC(void, ICU_CODE) eTPUC_CH4_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 4);
}

FUNC(void, ICU_CODE) eTPUC_CH5_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 5);
}

FUNC(void, ICU_CODE) eTPUC_CH6_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 6);
}

FUNC(void, ICU_CODE) eTPUC_CH7_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 7);
}

FUNC(void, ICU_CODE) eTPUC_CH8_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 8);
}

FUNC(void, ICU_CODE) eTPUC_CH9_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 9);
}

FUNC(void, ICU_CODE) eTPUC_CH10_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 10);
}

FUNC(void, ICU_CODE) eTPUC_CH11_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 11);
}

FUNC(void, ICU_CODE) eTPUC_CH12_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 12);
}

FUNC(void, ICU_CODE) eTPUC_CH13_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 13);
}

FUNC(void, ICU_CODE) eTPUC_CH14_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 14);
}

FUNC(void, ICU_CODE) eTPUC_CH15_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 15);
}

FUNC(void, ICU_CODE) eTPUC_CH16_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 16);
}

FUNC(void, ICU_CODE) eTPUC_CH17_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 17);
}

FUNC(void, ICU_CODE) eTPUC_CH18_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 18);
}

FUNC(void, ICU_CODE) eTPUC_CH19_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 19);
}

FUNC(void, ICU_CODE) eTPUC_CH20_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 20);
}

FUNC(void, ICU_CODE) eTPUC_CH21_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 21);
}

FUNC(void, ICU_CODE) eTPUC_CH22_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 22);
}

FUNC(void, ICU_CODE) eTPUC_CH23_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 23);
}

FUNC(void, ICU_CODE) eTPUC_CH24_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 24);
}

FUNC(void, ICU_CODE) eTPUC_CH25_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 25);
}

FUNC(void, ICU_CODE) eTPUC_CH26_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 26);
}

FUNC(void, ICU_CODE) eTPUC_CH27_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 27);
}

FUNC(void, ICU_CODE) eTPUC_CH28_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 28);
}

FUNC(void, ICU_CODE) eTPUC_CH29_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 29);
}

FUNC(void, ICU_CODE) eTPUC_CH30_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 30);
}

FUNC(void, ICU_CODE) eTPUC_CH31_Handler(void)
{
    eTPU_LLD_IRQHandler((uint8)eTPU_C, 31);
}

#endif /*#RESOURCE_SUPPORT_ETPU*/

