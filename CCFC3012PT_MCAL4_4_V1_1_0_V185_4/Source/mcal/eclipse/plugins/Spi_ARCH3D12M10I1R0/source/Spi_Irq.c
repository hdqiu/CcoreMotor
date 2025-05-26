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
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Spi_Irq.c
*   @version 1.0.1
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of SPI MCAL driver.
*
*   @addtogroup Spi
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Spi_Irq.h"


/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IRQ_C_VENDOR_ID                   176
#define SPI_IRQ_C_AR_MAJOR_VER                4
#define SPI_IRQ_C_AR_MINOR_VER                4
#define SPI_IRQ_C_AR_PATCH_VER                0
#define SPI_IRQ_C_SW_MAJOR_VER                1
#define SPI_IRQ_C_SW_MINOR_VER                0
#define SPI_IRQ_C_SW_PATCH_VER                1
/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_IRQ_C_VENDOR_ID != SPI_CFG_VENDOR_ID)
#error "NON-MATCHED DATA : SPI_IRQ_C_VENDOR_ID"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (SPI_IRQ_C_AR_MAJOR_VER != SPI_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SPI_IRQ_C_AR_MAJOR_VER"
#endif
#if (SPI_IRQ_C_AR_MINOR_VER != SPI_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SPI_IRQ_C_AR_MINOR_VER"
#endif
#if (SPI_IRQ_C_AR_PATCH_VER != SPI_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SPI_IRQ_C_AR_PATCH_VER"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (SPI_IRQ_C_SW_MAJOR_VER != SPI_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SPI_IRQ_C_SW_MAJOR_VER"
#endif
#if (SPI_IRQ_C_SW_MINOR_VER != SPI_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SPI_IRQ_C_SW_MINOR_VER"
#endif
#if (SPI_IRQ_C_SW_PATCH_VER != SPI_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SPI_IRQ_C_SW_PATCH_VER"
#endif


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
ISR(dspi_0_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[0U]]);
}
ISR(dspi_1_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[1U]]);
}
ISR(dspi_2_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[2U]]);
}
ISR(dspi_3_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[3U]]);
}
ISR(dspi_4_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[4U]]);
}
ISR(dspi_5_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[5U]]);
}
ISR(dspi_6_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[6U]]);
}
ISR(dspi_7_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[7U]]);
}
ISR(dspi_8_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[8U]]);
}
ISR(dspi_9_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[9U]]);
}
ISR(dspi_10_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[10U]]);
}
ISR(dspi_11_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[11U]]);
}
ISR(dspi_12_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[12U]]);
}
ISR(dspi_13_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[13U]]);
}
ISR(dspi_14_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[14U]]);
}
ISR(dspi_15_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[15U]]);
}
ISR(dspi_16_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[16U]]);
}
ISR(dspi_17_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[17U]]);
}
ISR(dspi_18_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[18U]]);
}
ISR(dspi_19_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[19U]]);
}
ISR(dspi_20_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[20U]]);
}
ISR(dspi_21_Tcf_Irq)
{
    dspi_tcf(&Spi_gHandle[Spi_HandleMap[21U]]);
}

#endif

#ifdef __cplusplus
}
#endif
