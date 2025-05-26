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
*   @file    Fls_LLDriver.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

#include "Fls_LLDriver.h"
#include "Fls.h"
#include "Det.h"

#define FLS_LLD_WRA_C_VENDOR_ID                     176
#define FLS_LLD_WRA_C_AR_REL_MAJOR_VER              4
#define FLS_LLD_WRA_C_AR_REL_MINOR_VER              4
#define FLS_LLD_WRA_C_AR_REL_REV_VER                0
#define FLS_LLD_WRA_C_SW_MAJOR_VER                  1
#define FLS_LLD_WRA_C_SW_MINOR_VER                  0
#define FLS_LLD_WRA_C_SW_PATCH_VER                  1

#if (FLS_VENDOR_ID_OUTPUT != FLS_LLD_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_VENDOR_ID "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_LLD_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_LLD_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_AR_REL_MINOR_VER "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_LLD_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_LLD_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_LLD_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_LLD_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_SW_PATCH_VER "
#endif

#define Fls_ReportRuntimeError(ApiId, ErrorId) \
        (void)Det_ReportRuntimeError( (uint16)FLS_MODULE_ID, FLS_INSTANCE, (ApiId), (ErrorId) );

/* Flash EHV value */
#ifndef RESOURCE_SUPPORT_PFI
static VAR( uint32, AUTOMATIC) FLS_EHV_Val = 0U;
#else
static uint8_t FLS_EHV_Val_All[FLS_CONTROLLER_NUM] = {0U};
#endif // RESOURCE_SUPPORT_PFI
/* Flash Swap Status */
VAR( uint8, AUTOMATIC ) g_swapStatus = 0U; /* PRQA S 1533 */
VAR( uint8, AUTOMATIC ) g_flashSize = 1U; /* PRQA S 1533 */

#ifdef FLS_AC_LOAD
extern  VAR( fls_acload_t, AUTOMATIC) pFls_AcCodePtr;
#if defined(START_FROM_FLASH)
VAR( uint32, AUTOMATIC) FLS_AcCodeArea[128] = {0U};
#endif
#endif
static P2CONST( volatile uint8, FLS_VAR, FLS_APPL_CONST ) volatile gFls_ReadAddressPtr = NULL_PTR;

#ifdef RESOURCE_SUPPORT_PFI
/* The controller currently in operation */
//static fls_blksel_t FLS_OpBlk;
static volatile struct C55FMC_tag *FLS_OpEFMC[FLS_CONTROLLER_NUM] = {NULL};
static volatile struct C55FMC_tag *FLS_OpPFMC = NULL;

static volatile struct C55FMC_tag * const flashControllerList[FLS_CONTROLLER_NUM] = {
    &FLS_FMC,
    #ifdef RESOURCE_SUPPORT_PFI0
    &FLS_T40FMC0,
    #endif // RESOURCE_SUPPORT_PFI0
    #ifdef RESOURCE_SUPPORT_PFI1
    &FLS_T40FMC1,
    #endif // RESOURCE_SUPPORT_PFI1
    #ifdef RESOURCE_SUPPORT_PFI2
    &FLS_T40FMC2,
    #endif // RESOURCE_SUPPORT_PFI2
    #ifdef RESOURCE_SUPPORT_PFI3
    &FLS_T40FMC3,
    #endif // RESOURCE_SUPPORT_PFI3
    #ifdef RESOURCE_SUPPORT_PFI4
    &FLS_T40FMC4,
    #endif // RESOURCE_SUPPORT_PFI4
    #ifdef RESOURCE_SUPPORT_PFI5
    &FLS_T40FMC5,
    #endif // RESOURCE_SUPPORT_PFI5
};
#endif // RESOURCE_SUPPORT_PFI

LOCAL_INLINE FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_CheckEraseStatus \
( \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pFls_OpRet \
);

LOCAL_INLINE FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Erase \
( \
    VAR( uint8, AUTOMATIC ) u8Fls_EraseSpace, \
    P2VAR( fls_blksel_t, AUTOMATIC, FLS_APPL_DATA ) pFls_BlkSel, \
    VAR( uint32, AUTOMATIC) u32Fls_Mode \
);


#ifdef FLS_AC_LOAD
    #ifndef RESOURCE_SUPPORT_PFI
static void FLS_AccessCode(void) {
    /* Set MCR EHV bit, start operation */
    FLS_FMC.MCR.B.EHV = 1U;

    /* Wait MCR DONE bit is set */
    while (FLS_FMC.MCR.B.DONE == 0x0U)
    {
    }
}
#else
static void FLS_AccessCode(volatile struct C55FMC_tag *fmc) {
    /* Set MCR EHV bit, start operation */
    fmc->MCR.B.EHV = 1U;

    /* Wait MCR DONE bit is set */
    while (fmc->MCR.B.DONE == 0x0U)
    {
    }
}
#endif // RESOURCE_SUPPORT_PFI
#endif // FLS_AC_LOAD


/*
 * @brief Get the controller FLS_EHV_Val
 *
 * This function will return the FLS_EHV_Val depend on controller
 *
 * @param[in] fmc The controller.
 * @param[in] fmc The controller.
 * @return Operation status
 */
#ifdef RESOURCE_SUPPORT_PFI
  FUNC( status_t, FLS_CODE ) FLS_LLD_Get_FLS_EHV_Val
(
    volatile struct C55FMC_tag *fmc, 
    uint8_t **ehv_val
)
{
    VAR(uint32, AUTOMATIC) u32Fls_index = 0U;
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_ERROR;

    for (u32Fls_index = 0U; u32Fls_index < FLS_CONTROLLER_NUM;u32Fls_index++) {
        if (fmc == flashControllerList[u32Fls_index]) {
            sFls_Ret = STATUS_SUCCESS;
            *ehv_val = FLS_EHV_Val_All + u32Fls_index;

            break;
        }
    }

    return sFls_Ret;
}
#endif // RESOURCE_SUPPORT_PFI

/*****************************************************************************
** Service Name      : Fls_LLD_CalcInitDataLength                                              
** 
** 
**  Description      : Used to calculate the number of bytes read from flash 
**                     memory until the source pointer is aligned with the data 
**                     width and the optimized wide flash memory read can start.                         
**                                                                            
**  Parameters (in)  : u8Fls_SourceAddrPtr: Source pointer
**                     u32Fls_TotalBytes: Total number of bytes read                      
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : uint32: The length of the initial 8-bit flash read(in bytes)                                                  
**                                                                            
******************************************************************************/
LOCAL_INLINE FUNC( uint32, FLS_CODE ) Fls_LLD_CalcInitDataLength
( 
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) u8Fls_SourceAddrPtr,
    CONST(uint32, AUTOMATIC) u32Fls_TotalBytes 
)
{
    VAR(uint32, AUTOMATIC) u32Fls_length = 0UL;

    u32Fls_length = ( (uint32)u8Fls_SourceAddrPtr ) & ( sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) - 1UL );

    if ( u32Fls_length != 0U )
    {
        u32Fls_length = sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) - u32Fls_length;
    }

    if( u32Fls_length > u32Fls_TotalBytes ) 
    {
        u32Fls_length = u32Fls_TotalBytes;
    }
    
    return u32Fls_length;
}

/*****************************************************************************
** Service Name      : Fls_LLD_CalcWideDataLength                                              
** 
** 
**  Description      : Used to calculate the number of bytes read from flash 
**                     memory until the source pointer is misaligned with the 
**                     data bus width.                         
**                                                                            
**  Parameters (in)  : u32Fls_InitDataLength: Calculated by 
**                     Fls_LLD_CalcInitDataLength function
**                     u32Fls_TotalBytes: Total number of bytes read                      
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : uint32: The length of the initial 32-bit or 64-bit 
**                             flash read(in bytes)                                                  
**                                                                            
******************************************************************************/
LOCAL_INLINE FUNC( uint32, FLS_CODE ) Fls_LLD_CalcWideDataLength
(
    CONST(uint32, AUTOMATIC) u32Fls_InitDataLength,
    CONST(uint32, AUTOMATIC) u32Fls_TotalBytes 
)
{
    VAR(uint32, AUTOMATIC) u32Fls_length = 0UL;

    u32Fls_length = (( u32Fls_TotalBytes - u32Fls_InitDataLength ) & (~( sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) - 1UL )));

    return u32Fls_length;
}

FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Init \
( \
    P2CONST( uint8, FLS_VAR, FLS_APPL_CONST )  pFls_LockBlk \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC) u32Fls_Index = 0;

    /* unLock Flash Block*/
    FLS_FMC.LOCK0.B.LOWLOCK = 0U;
    FLS_FMC.LOCK0.B.MIDLOCK = 0U;
    FLS_FMC.LOCK1.B.HIGHLOCK = 0U;

#ifndef RESOURCE_SUPPORT_PFI
    FLS_FMC.LOCK2.B.A256KLOCK = 0U;
    FLS_FMC.LOCK3.B.A256KLOCK = 0U;

    /* lock Flash Block*/
    for (u32Fls_Index = 0; u32Fls_Index < FLS_BLOCK_ALL; u32Fls_Index++)
    {
        if (1U == pFls_LockBlk[u32Fls_Index])
        {
            VAR( uint8, AUTOMATIC) SelBit = (uint8)flashInfo[u32Fls_Index].lockSelBit;
            if (SelBit < 32U)
            {
	            if (0U == flashInfo[u32Fls_Index].lockSelReg)
	            {
	                FLS_FMC.LOCK0.R |= (1UL << SelBit);
	            }
	            else if (1U == flashInfo[u32Fls_Index].lockSelReg)
	            {
	                FLS_FMC.LOCK1.R |= (1UL << SelBit);
	            }
	            else if (2U == flashInfo[u32Fls_Index].lockSelReg)
	            {
	                FLS_FMC.LOCK2.R |= (1UL << SelBit);
	            }
	            else if (3U == flashInfo[u32Fls_Index].lockSelReg)
	            {
	                FLS_FMC.LOCK3.R |= (1UL << SelBit);
	            }
	            else
	            {
	                /* No operation */
				}			
			}        
		}
    }
#else
    FLS_OpPFMC = NULL;
    cc_memset((uint8_t *)(&FLS_OpEFMC), NULL, sizeof(FLS_OpEFMC));

    #ifdef RESOURCE_SUPPORT_PFI0
    FLS_T40FMC0.LOCK2.B.A256KLOCK = 0U;
    #endif // RESOURCE_SUPPORT_PFI0
    #ifdef RESOURCE_SUPPORT_PFI1
    FLS_T40FMC1.LOCK2.B.A256KLOCK = 0U;
    #endif // RESOURCE_SUPPORT_PFI1
    #ifdef RESOURCE_SUPPORT_PFI2
    FLS_T40FMC2.LOCK2.B.A256KLOCK = 0U;
    #endif // RESOURCE_SUPPORT_PFI2
    #ifdef RESOURCE_SUPPORT_PFI3
    FLS_T40FMC3.LOCK2.B.A256KLOCK = 0U;
    #endif // RESOURCE_SUPPORT_PFI3
    #ifdef RESOURCE_SUPPORT_PFI4
    FLS_T40FMC4.LOCK2.B.A256KLOCK = 0U;
    #endif // RESOURCE_SUPPORT_PFI4
    #ifdef RESOURCE_SUPPORT_PFI5
    FLS_T40FMC5.LOCK2.B.A256KLOCK = 0U;
    #endif // RESOURCE_SUPPORT_PFI5

    /* lock Flash Block*/
    for (u32Fls_Index = 0; u32Fls_Index < FLS_BLOCK_ALL; u32Fls_Index++)
    {
        if (0U == pFls_LockBlk[u32Fls_Index]) {
            continue;
        }

        if (u32Fls_Index < FLS_256K_LARGE0_OFFSET) { // C55FMC
            if (0U == flashInfo[u32Fls_Index].lockSelReg) {
                FLS_FMC.LOCK0.R |= (1UL << flashInfo[u32Fls_Index].lockSelBit);
            } else if (1U == flashInfo[u32Fls_Index].lockSelReg) {
                FLS_FMC.LOCK1.R |= (1UL << flashInfo[u32Fls_Index].lockSelBit);
            } else {
                // No operation
            }
        } else {                          // T40FMC
        #ifdef RESOURCE_SUPPORT_PFI0
            if (0U == flashInfo[u32Fls_Index].lockSelReg) {        // T40FMC0
                FLS_T40FMC0.LOCK2.R |= (1UL << flashInfo[u32Fls_Index].lockSelBit);
            } 
        #endif // RESOURCE_SUPPORT_PFI0
        #ifdef RESOURCE_SUPPORT_PFI1
            else if (1U == flashInfo[u32Fls_Index].lockSelReg) { // T40FMC1
                FLS_T40FMC1.LOCK2.R |= (1UL << flashInfo[u32Fls_Index].lockSelBit);
            } 
        #endif // RESOURCE_SUPPORT_PFI1
        #ifdef RESOURCE_SUPPORT_PFI2
            else if (2U == flashInfo[u32Fls_Index].lockSelReg) { // T40FMC2
                FLS_T40FMC2.LOCK2.R |= (1UL << flashInfo[u32Fls_Index].lockSelBit);
            } 
        #endif // RESOURCE_SUPPORT_PFI2
        #ifdef RESOURCE_SUPPORT_PFI3
            else if (3U == flashInfo[u32Fls_Index].lockSelReg) { // T40FMC3
                FLS_T40FMC3.LOCK2.R |= (1UL << flashInfo[u32Fls_Index].lockSelBit);
            } 
        #endif // RESOURCE_SUPPORT_PFI3
        #ifdef RESOURCE_SUPPORT_PFI4
            else if (4U == flashInfo[u32Fls_Index].lockSelReg) { // T40FMC4
                FLS_T40FMC4.LOCK2.R |= (1UL << flashInfo[u32Fls_Index].lockSelBit);
            } 
        #endif // RESOURCE_SUPPORT_PFI4
        #ifdef RESOURCE_SUPPORT_PFI5
            else if (5U == flashInfo[u32Fls_Index].lockSelReg) { // T40FMC5
                FLS_T40FMC5.LOCK2.R |= (1UL << flashInfo[u32Fls_Index].lockSelBit);
            } 
        #endif // RESOURCE_SUPPORT_PFI5
            else {
                // No operation
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI

    /* Clear error bits */
    FLS_FMC.MCR.B.EER = 1U;
    FLS_FMC.MCR.B.RWE = 1U;
    FLS_FMC.MCR.B.SBC = 1U;
    FLS_FMC.MCR.B.RVE = 1U;
    FLS_FMC.MCR.B.RRE = 1U;
    FLS_FMC.MCR.B.AEE = 1U;
    FLS_FMC.MCR.B.EEE = 1U;
	
#ifdef RESOURCE_SUPPORT_PFI0
	FLS_T40FMC0.MCR.B.EER = 1U;
	FLS_T40FMC0.MCR.B.RWE = 1U;
	FLS_T40FMC0.MCR.B.SBC = 1U;
	FLS_T40FMC0.MCR.B.RVE = 1U;
	FLS_T40FMC0.MCR.B.RRE = 1U;
	FLS_T40FMC0.MCR.B.AEE = 1U;
	FLS_T40FMC0.MCR.B.EEE = 1U;
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
	FLS_T40FMC1.MCR.B.EER = 1U;
	FLS_T40FMC1.MCR.B.RWE = 1U;
	FLS_T40FMC1.MCR.B.SBC = 1U;
	FLS_T40FMC1.MCR.B.RVE = 1U;
	FLS_T40FMC1.MCR.B.RRE = 1U;
	FLS_T40FMC1.MCR.B.AEE = 1U;
	FLS_T40FMC1.MCR.B.EEE = 1U;
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
	FLS_T40FMC2.MCR.B.EER = 1U;
	FLS_T40FMC2.MCR.B.RWE = 1U;
	FLS_T40FMC2.MCR.B.SBC = 1U;
	FLS_T40FMC2.MCR.B.RVE = 1U;
	FLS_T40FMC2.MCR.B.RRE = 1U;
	FLS_T40FMC2.MCR.B.AEE = 1U;
	FLS_T40FMC2.MCR.B.EEE = 1U;
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
	FLS_T40FMC3.MCR.B.EER = 1U;
	FLS_T40FMC3.MCR.B.RWE = 1U;
	FLS_T40FMC3.MCR.B.SBC = 1U;
	FLS_T40FMC3.MCR.B.RVE = 1U;
	FLS_T40FMC3.MCR.B.RRE = 1U;
	FLS_T40FMC3.MCR.B.AEE = 1U;
	FLS_T40FMC3.MCR.B.EEE = 1U;
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
	FLS_T40FMC4.MCR.B.EER = 1U;
	FLS_T40FMC4.MCR.B.RWE = 1U;
	FLS_T40FMC4.MCR.B.SBC = 1U;
	FLS_T40FMC4.MCR.B.RVE = 1U;
	FLS_T40FMC4.MCR.B.RRE = 1U;
	FLS_T40FMC4.MCR.B.AEE = 1U;
	FLS_T40FMC4.MCR.B.EEE = 1U;
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
	FLS_T40FMC5.MCR.B.EER = 1U;
	FLS_T40FMC5.MCR.B.RWE = 1U;
	FLS_T40FMC5.MCR.B.SBC = 1U;
	FLS_T40FMC5.MCR.B.RVE = 1U;
	FLS_T40FMC5.MCR.B.RRE = 1U;
	FLS_T40FMC5.MCR.B.AEE = 1U;
	FLS_T40FMC5.MCR.B.EEE = 1U;
#endif // RESOURCE_SUPPORT_PFI

    PFLASH.PFCR1.B.P0_BFEN = 0U;
    PFLASH.PFCR2.B.P1_BFEN = 0U;

    PFI0_PFLASH.PFCR1.B.P0_BFEN = 0U;
    PFI0_PFLASH.PFCR2.B.P1_BFEN = 0U;

    PFI1_PFLASH.PFCR1.B.P0_BFEN = 0U;
    PFI1_PFLASH.PFCR2.B.P1_BFEN = 0U;

    PFI2_PFLASH.PFCR1.B.P0_BFEN = 0U;
    PFI2_PFLASH.PFCR2.B.P1_BFEN = 0U;

    PFI3_PFLASH.PFCR1.B.P0_BFEN = 0U;
    PFI3_PFLASH.PFCR2.B.P1_BFEN = 0U;

    PFI4_PFLASH.PFCR1.B.P0_BFEN = 0U;
    PFI4_PFLASH.PFCR2.B.P1_BFEN = 0U;

    PFI5_PFLASH.PFCR1.B.P0_BFEN = 0U;
    PFI5_PFLASH.PFCR2.B.P1_BFEN = 0U;

#ifdef FLS_AC_LOAD
#if defined(START_FROM_FLASH)
    /* Copy Flash Access Code to SRAM */
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_RomPtr = (uint32 *)&FLS_AccessCode; /* PRQA S 0307,3678 */
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_RomEndPtr = pFls_RomPtr + (sizeof(FLS_AcCodeArea)/4U); /* PRQA S 3678 */
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_RamPtr = (uint32 *)FLS_AcCodeArea;

    for (; (uint32)pFls_RomPtr < (uint32)pFls_RomEndPtr; pFls_RomPtr++)
    {
        *pFls_RamPtr = *pFls_RomPtr;
        pFls_RamPtr++;
    }

    pFls_AcCodePtr = (fls_acload_t)&FLS_AcCodeArea; /* PRQA S 0307 */
#else
    /* If Flash Access Code in SRAM */
    pFls_AcCodePtr = (fls_acload_t)&FLS_AccessCode;
#endif
#endif

    /* Flash interrupt Initialize */
    sFls_Ret = INTC_LLD_Set_IRQ_Priority(FLASH_MCR_DONE_IRQn, INTR_PRI_1);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Handle(FLASH_MCR_DONE_IRQn, &FLASH_Cmd_Done_ISR);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Enable(FLASH_MCR_DONE_IRQn);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

#ifdef RESOURCE_SUPPORT_PFI0
    /* PFI0 Flash interrupt Initialize */
    sFls_Ret = INTC_LLD_Set_IRQ_Priority(CFLASH_PFI0_FGF_PECI_IRQn, INTR_PRI_1);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Handle(CFLASH_PFI0_FGF_PECI_IRQn, &FLASH_PFI0_Cmd_Done_ISR);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Enable(CFLASH_PFI0_FGF_PECI_IRQn);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
    /* PFI1 Flash interrupt Initialize */
    sFls_Ret = INTC_LLD_Set_IRQ_Priority(CFLASH_PFI1_FGF_PECI_IRQn, INTR_PRI_1);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Handle(CFLASH_PFI1_FGF_PECI_IRQn, &FLASH_PFI1_Cmd_Done_ISR);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Enable(CFLASH_PFI1_FGF_PECI_IRQn);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
    /* PFI2 Flash interrupt Initialize */
    sFls_Ret = INTC_LLD_Set_IRQ_Priority(CFLASH_PFI2_FGF_PECI_IRQn, INTR_PRI_1);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Handle(CFLASH_PFI2_FGF_PECI_IRQn, &FLASH_PFI2_Cmd_Done_ISR);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Enable(CFLASH_PFI2_FGF_PECI_IRQn);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
    /* PFI3 Flash interrupt Initialize */
    sFls_Ret = INTC_LLD_Set_IRQ_Priority(CFLASH_PFI3_FGF_PECI_IRQn, INTR_PRI_1);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Handle(CFLASH_PFI3_FGF_PECI_IRQn, &FLASH_PFI3_Cmd_Done_ISR);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Enable(CFLASH_PFI3_FGF_PECI_IRQn);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
    /* PFI4 Flash interrupt Initialize */
    sFls_Ret = INTC_LLD_Set_IRQ_Priority(CFLASH_PFI4_FGF_PECI_IRQn, INTR_PRI_1);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Handle(CFLASH_PFI4_FGF_PECI_IRQn, &FLASH_PFI4_Cmd_Done_ISR);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Enable(CFLASH_PFI4_FGF_PECI_IRQn);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
    /* PFI5 Flash interrupt Initialize */
    sFls_Ret = INTC_LLD_Set_IRQ_Priority(CFLASH_PFI5_FGF_PECI_IRQn, INTR_PRI_1);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Handle(CFLASH_PFI5_FGF_PECI_IRQn, &FLASH_PFI5_Cmd_Done_ISR);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }

    sFls_Ret = INTC_LLD_Set_IRQ_Enable(CFLASH_PFI5_FGF_PECI_IRQn);
    if (sFls_Ret != STATUS_SUCCESS)
    {
        return sFls_Ret;
    }
#endif // RESOURCE_SUPPORT_PFI
    return sFls_Ret;
}

#if( FLS_ERASE_VERIFICATION_ENABLED == STD_ON )
FUNC( status_t, FLS_CODE ) Fls_LLD_VerifyErase \
( \
    P2CONST(volatile uint32, AUTOMATIC, FLS_APPL_CONST ) u32Fls_FlashAreaPtr, \
	CONST( Fls_LengthType, AUTOMATIC) u32Fls_DataLength \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) u8Fls_FlashAreaEndPtr = NULL_PTR;

    u8Fls_FlashAreaEndPtr = ((volatile const uint8 *)u32Fls_FlashAreaPtr) + u32Fls_DataLength;
    gFls_ReadAddressPtr = ((volatile const uint8 *)u32Fls_FlashAreaPtr);
   
    while( (uint32)gFls_ReadAddressPtr < (uint32)u8Fls_FlashAreaEndPtr )
    {
      
        if( FLS_ERASED_VALUE != *((volatile const uint32*)gFls_ReadAddressPtr) )
        {
            break;
        }   

        gFls_ReadAddressPtr += sizeof(uint32);
    }
    
    if( gFls_ReadAddressPtr != u8Fls_FlashAreaEndPtr )
    {
        Fls_ReportRuntimeError(FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
        sFls_Ret = STATUS_ERROR;
    }

    return sFls_Ret;
}
#endif

#if( FLS_WRITE_VERIFICATION_ENABLED == STD_ON )
FUNC( status_t, FLS_CODE ) Fls_LLD_VerifyWrite \
( \
    P2CONST( volatile uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_FlashAreaPtr, \
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_UserBufferPtr, \
    CONST( Fls_LengthType, AUTOMATIC) u32Fls_DataLength \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) u8Fls_FlashAreaEndPtr = NULL_PTR;
    P2CONST( volatile uint8, FLS_VAR, FLS_APPL_CONST ) volatile gFls_CompareAddressPtr = NULL_PTR;

    u8Fls_FlashAreaEndPtr = ((volatile const uint8 *)pFls_FlashAreaPtr) + u32Fls_DataLength;
    gFls_CompareAddressPtr = ((const uint8 *)pFls_UserBufferPtr);
    gFls_ReadAddressPtr = ((volatile const uint8 *)pFls_FlashAreaPtr);

    while( (uint32)gFls_ReadAddressPtr < (uint32)u8Fls_FlashAreaEndPtr )
    {
        if( *((volatile const uint32*)gFls_ReadAddressPtr) != \
            *((volatile const uint32*)gFls_CompareAddressPtr) )
        {
            break;
        }
        
        gFls_CompareAddressPtr += sizeof(uint32);
        gFls_ReadAddressPtr += sizeof(uint32);
    }

    if( gFls_ReadAddressPtr != u8Fls_FlashAreaEndPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00314] */
        /* Specification of Flash Driver : [SWS_Fls_00056] */
        Fls_ReportRuntimeError(FLS_MAINFUNCTION_ID, FLS_E_VERIFY_WRITE_FAILED);
        sFls_Ret = STATUS_ERROR;
    }

    return sFls_Ret;
}
#endif

/*
 * @brief Execute suspend operation
 *
 * This function will suspend the program, erase activities
 *
 * @param[out] u8Fls_SusStatus The status of suspend after calling the function.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
LOCAL_INLINE FUNC( void, FLS_CODE ) FLS_LLD_SusExec_Cancel \
( \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) u8Fls_SusStatus \
)
{
    VAR( uint16, AUTOMATIC) u16Fls_SusDelay = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Index = ABT_OPT_TIMEOUT_COUNTER;

    if (FLS_FMC.MCR.B.EHV == 0U)
    {
        if (FLS_FMC.MCR.B.PGM != 0U)
        {
            *u8Fls_SusStatus = FLS_PGM_WRITE;

            if (FLS_FMC.MCR.B.ERS != 0U)
            {
                *u8Fls_SusStatus = FLS_ERS_SUS_PGM_WRITE;
            }
        }
        else
        {
            *u8Fls_SusStatus = FLS_ERS_WRITE;
        }
        /* Wait MCR DONE bit is set */
        while ((FLS_FMC.MCR.B.DONE == 0x0U) && (u32Fls_Index > 0U))
        {
            u32Fls_Index--;
        }
    }
    else
    {
        if (FLS_FMC.MCR.B.PGM != 0x0U)
        {
            /* Set MCR_PSUS bit */
            FLS_FMC.MCR.B.PSUS = 1U;
            for (u16Fls_SusDelay = 0U; u16Fls_SusDelay < 160U; u16Fls_SusDelay++)
            {}
        }
        else
        {
            /* Set MCR-ESUS bit */
            FLS_FMC.MCR.B.ESUS = 1U;
            for (u16Fls_SusDelay = 0U; u16Fls_SusDelay < 320U; u16Fls_SusDelay++)
            {}
        }
    }
}
#else
LOCAL_INLINE FUNC( void, FLS_CODE ) FLS_LLD_SusExec_Cancel
(
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) u8Fls_SusStatus, \
     volatile struct C55FMC_tag *fmc
)
{   
    VAR( uint16, AUTOMATIC) u16Fls_SusDelay = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Index = ABT_OPT_TIMEOUT_COUNTER;

    if (fmc->MCR.B.EHV == 0U)
    {
        if (fmc->MCR.B.PGM != 0U)
        {
            *u8Fls_SusStatus = FLS_PGM_WRITE;

            if (fmc->MCR.B.ERS != 0U)
            {
                *u8Fls_SusStatus = FLS_ERS_SUS_PGM_WRITE;
            }
        }
        else
        {
            *u8Fls_SusStatus = FLS_ERS_WRITE;
        }
        /* Wait MCR DONE bit is set */
        while ((fmc->MCR.B.DONE == 0x0U) && (u32Fls_Index > 0U))
        {
            u32Fls_Index--;
        }
    }
    else
    {
        if (fmc->MCR.B.PGM != 0x0U)
        {
            /* Set MCR_PSUS bit */
            fmc->MCR.B.PSUS = 1U;
            for (u16Fls_SusDelay = 0U; u16Fls_SusDelay < 160U; u16Fls_SusDelay++)
            {}
        }
        else
        {
            /* Set MCR-ESUS bit */
            fmc->MCR.B.ESUS = 1U;
            for (u16Fls_SusDelay = 0U; u16Fls_SusDelay < 320U; u16Fls_SusDelay++)
            {}
        }
    }
}
       
#endif // RESOURCE_SUPPORT_PFI


#if (FLS_CANCEL_API == STD_ON )
/*****************************************************************************
** Service Name      : Fls_LLD_Cancel                                              
** 
** 
**  Description      : Used to cancel the last working operation of the driver layer.                     
**                                                                            
**  Parameters (in)  : None                       
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                 
**                                                                            
******************************************************************************/
FUNC( status_t, FLS_CODE ) Fls_LLD_Cancel(P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) u8Fls_SusStatus)
{
    VAR( uint32, AUTOMATIC) u32Fls_Count = ABT_OPT_TIMEOUT_COUNTER;

#ifdef RESOURCE_SUPPORT_PFI
    uint32 u32fls_index = 0U;
#endif // RESOURCE_SUPPORT_PFI
    if ( u8Fls_SusStatus == NULL)
    {
        return STATUS_ERROR;
    }

    *u8Fls_SusStatus = FLS_NO_SUS;

#ifndef RESOURCE_SUPPORT_PFI
    /* No program/erase sequence */
    if ((FLS_FMC.MCR.B.PGM == 0U) && (FLS_FMC.MCR.B.ERS == 0U))
    {
        /* Nothing to do */
    }
    else
    {
        if (((FLS_FMC.MCR.B.PGM != 0U) && (FLS_FMC.MCR.B.PSUS == 0U))\
             || ((FLS_FMC.MCR.B.ERS != 0U) && (FLS_FMC.MCR.B.ESUS == 0U)))
        {
            FLS_LLD_SusExec_Cancel(u8Fls_SusStatus);
        }

        /* Check the high voltage is cleared or not */
        if ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U))
        {
            if (FLS_FMC.MCR.B.PSUS != 0U)
            {
                *u8Fls_SusStatus = FLS_PGM_SUS;

                if (FLS_FMC.MCR.B.ESUS != 0U)
                {
                    *u8Fls_SusStatus = FLS_ERS_SUS_PGM_SUS;
                }
            }
            else
            {
                *u8Fls_SusStatus = FLS_ERS_SUS;
            }

            /* Wait MCR DONE bit is set */
            while ((FLS_FMC.MCR.B.DONE == 0U) && (u32Fls_Count > 0U))
            {
                u32Fls_Count--;
            }

            /* Set MCR_EHV to 0 */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
        }
    }
#else
    for (u32fls_index = 0U; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++) {
        volatile struct C55FMC_tag * const fmc = flashControllerList[u32fls_index];

        /* No program/erase sequence */
        if ((fmc->MCR.B.PGM == 0U) && (fmc->MCR.B.ERS == 0U)) {
            /* Nothing to do */
        } else {
            uint8_t *fls_ehv_val = 0;

            if (((fmc->MCR.B.PGM != 0U) && (fmc->MCR.B.PSUS == 0U)) ||
                ((fmc->MCR.B.ERS != 0U) && (fmc->MCR.B.ESUS == 0U))) {
                 FLS_LLD_SusExec_Cancel(u8Fls_SusStatus, fmc);
            }

            FLS_LLD_Get_FLS_EHV_Val(fmc, &fls_ehv_val);

            /* Check the high voltage is cleared or not */
            if ((fmc->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U)) {
                if (fmc->MCR.B.PSUS != 0U) {
                    *u8Fls_SusStatus = FLS_PGM_SUS;

                    if (fmc->MCR.B.ESUS != 0U) {
                        *u8Fls_SusStatus = FLS_ERS_SUS_PGM_SUS;
                    }
                } else {
                    *u8Fls_SusStatus = FLS_ERS_SUS;
                }

                /* Wait MCR DONE bit is set */
                while ((fmc->MCR.B.DONE == 0U) && (u32Fls_Count > 0U)) {
                    u32Fls_Count--;
                }

                /* Set MCR_EHV to 0 */
                fmc->MCR.B.EHV = 0U;
                *fls_ehv_val = 0U;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI
    return STATUS_SUCCESS;
}
#endif /* FLS_CANCEL_API == STD_ON */


/*
 * @brief FLS_Get_Offset_Select
 *
 * Flash get special block offset and select state.
 */
LOCAL_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_Get_Offset_Select \
( \
    VAR( uint16, AUTOMATIC) u16Fls_FlashBlock, \
    VAR( uint32, AUTOMATIC) u32Fls_Index, \
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) u32Fls_Offset, \
    P2VAR( fls_blksel_t, AUTOMATIC, FLS_APPL_DATA ) pFls_BlkSel)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;

    /* Check index */
    if (u32Fls_Index >= 32U)
    {
        
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }
    else
    {
        /*
        * clear pFls_BlkSel
        *
        *  */
        pFls_BlkSel->lowBlkSel = 0x0U;
        pFls_BlkSel->midBlkSel = 0x0U;
        pFls_BlkSel->highBlkSel = 0x0U;
    #ifndef RESOURCE_SUPPORT_PFI
        pFls_BlkSel->first256KBlkSel = 0x0U;
        pFls_BlkSel->second256KBlkSel = 0x0U;
    #else
        pFls_BlkSel->large0BlkSel = 0x0U;
        pFls_BlkSel->large1BlkSel = 0x0U;
        pFls_BlkSel->large2BlkSel = 0x0U;
        pFls_BlkSel->large3BlkSel = 0x0U;
        pFls_BlkSel->large4BlkSel = 0x0U;
        pFls_BlkSel->large5BlkSel = 0x0U;
    #endif // RESOURCE_SUPPORT_PFI

        /* Select flash block to erase */
        switch (u16Fls_FlashBlock)
        {
            case FLS_BLK_LOW:
            {
                 *u32Fls_Offset = FLS_LOW_OFFSET;
                pFls_BlkSel->lowBlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_MID:
            {
                *u32Fls_Offset = FLS_MID_OFFSET;
                pFls_BlkSel->midBlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_HIGH:
            {
                *u32Fls_Offset = FLS_HIGH_OFFSET;
                pFls_BlkSel->highBlkSel = (1UL << u32Fls_Index);
                break;
            }
        #ifndef RESOURCE_SUPPORT_PFI
            case FLS_BLK_FIRST_256K:
            {
                *u32Fls_Offset = FLS_256K_FIRST_OFFSET;
                pFls_BlkSel->first256KBlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_SECOND_256K:
            {
                *u32Fls_Offset = FLS_256K_SECOND_OFFSET;
                pFls_BlkSel->second256KBlkSel = (1UL << u32Fls_Index);
                break;
            }
        #else
         
            case FLS_BLK_LARGE0_256K:
            {
                *u32Fls_Offset = FLS_256K_LARGE0_OFFSET;
                pFls_BlkSel->large0BlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_LARGE1_256K:
            {
                *u32Fls_Offset = FLS_256K_LARGE1_OFFSET;
                pFls_BlkSel->large1BlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_LARGE2_256K: 
            {
                *u32Fls_Offset = FLS_256K_LARGE2_OFFSET;
                pFls_BlkSel->large2BlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_LARGE3_256K:  
            {
                *u32Fls_Offset = FLS_256K_LARGE3_OFFSET;
                pFls_BlkSel->large3BlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_LARGE4_256K:   
            {
                *u32Fls_Offset = FLS_256K_LARGE4_OFFSET;
                pFls_BlkSel->large4BlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_LARGE5_256K: 
            {
                *u32Fls_Offset = FLS_256K_LARGE5_OFFSET;
                pFls_BlkSel->large5BlkSel = (1UL << u32Fls_Index);
                break;
            }
        #endif // RESOURCE_SUPPORT_PFI
            default:
            {
                sFls_Ret = STATUS_ERROR;
                break;
            }
        }
    }

    return sFls_Ret;
}

LOCAL_INLINE FUNC( uint32, FLS_CODE ) FLS_SDK_LLD_GetInterWriteAddr(const fls_blksel_t * pFls_BlkSel)
{
    VAR( uint8, AUTOMATIC) u8Fls_Index = 0U;
    VAR( uint8, AUTOMATIC) u8Fls_Offset = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Addr = 0U;

    if (pFls_BlkSel->lowBlkSel > 0U)
    {
        u8Fls_Offset = FLS_LOW_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_LOW_BLOCK; u8Fls_Index++)
        {
            if (((pFls_BlkSel->lowBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart; /* PRQA S 2985 */
                break;
            }
        }
    }
    else if (pFls_BlkSel->midBlkSel > 0U)
    {
        u8Fls_Offset = FLS_MID_OFFSET; /* PRQA S 2983 */
        for (u8Fls_Index = 0U;u8Fls_Index < FLS_MID_BLOCK; u8Fls_Index++) /* PRQA S 2994, 2996 */
        {
            if (((pFls_BlkSel->midBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL) /* PRQA S 2880 */
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    else if (pFls_BlkSel->highBlkSel > 0U)
    {
        u8Fls_Offset = FLS_HIGH_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_HIGH_BLOCK; u8Fls_Index++)
        {
            if (((pFls_BlkSel->highBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
#ifndef RESOURCE_SUPPORT_PFI
    else if (pFls_BlkSel->first256KBlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_FIRST_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_FIRST; u8Fls_Index++)
        {
            if (((pFls_BlkSel->first256KBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
#if (FLS_256K_BLOCK_SECOND != 0U)
    else if (pFls_BlkSel->second256KBlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_SECOND_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_SECOND; u8Fls_Index++)
        {
            if (((pFls_BlkSel->second256KBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
#endif
#else
    #ifdef RESOURCE_SUPPORT_PFI0
    else if (pFls_BlkSel->large0BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE0_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE0; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large0BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI0
    #ifdef RESOURCE_SUPPORT_PFI1
    else if (pFls_BlkSel->large1BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE1_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE1; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large1BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI1
    #ifdef RESOURCE_SUPPORT_PFI2
    else if (pFls_BlkSel->large2BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE2_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE2; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large2BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI2
    #ifdef RESOURCE_SUPPORT_PFI3
    else if (pFls_BlkSel->large3BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE3_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE3; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large3BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI3
    #ifdef RESOURCE_SUPPORT_PFI4
    else if (pFls_BlkSel->large4BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE4_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE4; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large4BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI4
    #ifdef RESOURCE_SUPPORT_PFI5
    else if (pFls_BlkSel->large5BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE5_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE5; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large5BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI5
#endif // RESOURCE_SUPPORT_PFI
    else
    {
    }

    return u32Fls_Addr;
}

LOCAL_INLINE FUNC( uint32, FLS_CODE ) FLS_SDK_LLD_AddrInvalid(uint32 addr)
{
    VAR( uint32, AUTOMATIC) i = 0U;
    VAR( uint32, AUTOMATIC) valid = 0U;

    for (i = 0U; i < FLS_BLOCK_ALL; i++)
    {
        VAR( uint32, AUTOMATIC) addrStart = 0U;
        VAR( uint32, AUTOMATIC) addrEnd = 0U;

        addrStart = flashInfo[i].addrStart;
        addrEnd   = flashInfo[i].addrEnd;

        if ((addrStart <= addr) && (addr <= addrEnd))
        {
            volatile struct C55FMC_tag *fmc;

            VAR( uint32, AUTOMATIC) fmcSelReg = 0U;

            VAR( uint32, AUTOMATIC) lockSelReg = 0U;
            VAR( uint32, AUTOMATIC) lockSelBit = 0U;

            lockSelReg = flashInfo[i].lockSelReg;
            lockSelBit = flashInfo[i].lockSelBit;

            if (i < FLS_256K_LARGE0_OFFSET)
            {
                fmc = &FLS_FMC;
            }
            else if (i < FLS_256K_LARGE1_OFFSET)
            {
                lockSelReg = 2U;
                fmc = &FLS_T40FMC0;
            }
            else if (i < FLS_256K_LARGE2_OFFSET)
            {
                lockSelReg = 2U;
                fmc = &FLS_T40FMC1;
            }
            else if (i < FLS_256K_LARGE3_OFFSET)
            {
                lockSelReg = 2U;
                fmc = &FLS_T40FMC2;
            }
            else if (i < FLS_256K_LARGE4_OFFSET)
            {
                lockSelReg = 2U;
                fmc = &FLS_T40FMC3;
            }
            else if (i < FLS_256K_LARGE5_OFFSET)
            {
                lockSelReg = 2U;
                fmc = &FLS_T40FMC4;
            }
            else {
                lockSelReg = 2U;
                fmc = &FLS_T40FMC5;
            }

            switch (lockSelReg)
            {
                case 0U:
                {
                    fmcSelReg = fmc->SEL0.R;
                    break;
                }

                case 1U:
                {
                    fmcSelReg = fmc->SEL1.R;
                    break;
                }

                case 2U:
                {
                    fmcSelReg = fmc->SEL2.R;
                    break;
                }

                case 3U:
                {
                    fmcSelReg = fmc->SEL3.R;
                    break;
                }

                default:
                {
                    break;
                }
            }

            if (0U != (fmcSelReg & (1U << lockSelBit)))
            {
                valid = 1U;
            }

            break;
        }
    }

    return valid;
}

LOCAL_INLINE FUNC( void, FLS_CODE ) FLS_SDK_LLD_DCacheInvalid(void)
{
	VAR( uint32, AUTOMATIC) u32DCache_Way  = 0U;
    VAR( uint32, AUTOMATIC) u32DCache_Set  = 0U;

    for (u32DCache_Way = 0U; u32DCache_Way < 2U; u32DCache_Way++)
    {
        for (u32DCache_Set = 0U; u32DCache_Set < 64U; u32DCache_Set++)
        {
            VAR( uint32, AUTOMATIC) u32DCache_Temp = 0U;

            VAR( uint32, AUTOMATIC) u32DCache_Tag  = 0U;
            VAR( uint32, AUTOMATIC) u32DCache_Valid  = 0U;

            u32DCache_Temp = 0x80000005U | (u32DCache_Way << 28U) | (u32DCache_Set << 19U);

            MTDCR(351, u32DCache_Temp);
            u32DCache_Temp = MFDCR(350);

            u32DCache_Tag   = u32DCache_Temp & 0xFFFFF800U;
            u32DCache_Valid = (u32DCache_Temp & 0x100U) >> 8U;

            if ((u32DCache_Valid != 0U) && (0U != FLS_SDK_LLD_AddrInvalid(u32DCache_Tag)))
            {
                u32DCache_Temp = 0x5U | (u32DCache_Way << 24U) | (u32DCache_Set << 5U);

                MTSPR(1016, u32DCache_Temp);
            }
        }
    }
}

/*
 * @brief Execute program operation
 *
 * This function will do program operation
 *
 * @param[in] pFls_CtxData Storing context variables.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
LOCAL_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_PgmExec \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC) u32Fls_SrcIndex = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Temp = 0U;


    if (0U != pFls_CtxData->u32Fls_Size)
    {
        /* Set MCR_PGM to start program operation */
        FLS_FMC.MCR.B.PGM = 1U;

        if (FLS_FMC.MCR.B.PGM == 0U)
        {
            sFls_Ret = STATUS_FLASH_ERROR_ENABLE;
        }
        else
        {
            /* Compute the buffer u32Fls_Size used in the program cycle and calculate number of word for interlock write */
            if (pFls_CtxData->u32Fls_Size > FLS_SDK_PROGRAMABLE_SIZE)
            {
                u32Fls_Temp = FLS_SDK_PROGRAMABLE_SIZE / FLS_SDK_WORD_SIZE;
            }
            else
            {
                u32Fls_Temp = pFls_CtxData->u32Fls_Size / FLS_SDK_WORD_SIZE;
            }

            /* Program data */
            for (u32Fls_SrcIndex = 0U; u32Fls_SrcIndex < u32Fls_Temp; u32Fls_SrcIndex++)
            {
                /* Programming write */
                *(volatile uint32 *)(pFls_CtxData->u32Fls_Dest) \
                    = *(volatile uint32 *)(pFls_CtxData->u32Fls_Src);
                
                /* Update u32Fls_Dest, u32Fls_Size, source index */
                pFls_CtxData->u32Fls_Dest += FLS_SDK_WORD_SIZE;
                pFls_CtxData->u32Fls_Src += FLS_SDK_WORD_SIZE;
                pFls_CtxData->u32Fls_Size -= FLS_SDK_WORD_SIZE;

                /* Is it time to do page programming?  */
                if (0U == (pFls_CtxData->u32Fls_Dest % FLS_SDK_PROGRAMABLE_SIZE))
                {
                    break;
                }
            }
            
            /* Set MCR_EHV bit */
            if (FLS_OP_SYNC == pFls_CtxData->u32Fls_Mode)
            {
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )                   
                pFls_AcCodePtr(&u32Fls_TimerCounterAC);
                if( 0U == u32Fls_TimerCounterAC )
                {
                    sFls_Ret = STATUS_TIMEOUT;
                    Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                }
            #else
                pFls_AcCodePtr();
            #endif
            }
            else
            {
                FLS_FMC.MCR.B.EHV = 1U;
            }
        }
    }
    else
    {
    }
	return sFls_Ret;
}
#else
LOCAL_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_PgmExec
(
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData ,\
    volatile struct C55FMC_tag *fmc
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC) u32Fls_SrcIndex = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Temp = 0U;

    if (0U != pFls_CtxData->u32Fls_Size)
    {
        /* Set MCR_PGM to start program operation */
        fmc->MCR.B.PGM = 1U;

        if (fmc->MCR.B.PGM == 0U)
        {
            sFls_Ret = STATUS_FLASH_ERROR_ENABLE;
        }
        else
        {
            /* Compute the buffer size used in the program cycle and calculate number of word for interlock write */
            if (pFls_CtxData->u32Fls_Size > FLS_SDK_PROGRAMABLE_SIZE)
            {
                u32Fls_Temp = FLS_SDK_PROGRAMABLE_SIZE / FLS_SDK_WORD_SIZE;
            }
            else
            {
                u32Fls_Temp = pFls_CtxData->u32Fls_Size / FLS_SDK_WORD_SIZE;
            }

            /* Program data */
            for (u32Fls_SrcIndex = 0U; u32Fls_SrcIndex < u32Fls_Temp; u32Fls_SrcIndex++)
            {
                /* Programming write */
                *(volatile uint32_t *)(pFls_CtxData->u32Fls_Dest) = *(volatile uint32_t *)(pFls_CtxData->u32Fls_Src);
                /* Update u32Fls_Dest, size, source index */
                pFls_CtxData->u32Fls_Dest += FLS_SDK_WORD_SIZE;
                pFls_CtxData->u32Fls_Src += FLS_SDK_WORD_SIZE;
                pFls_CtxData->u32Fls_Size -= FLS_SDK_WORD_SIZE;

                /* Is it time to do page programming?  */
                if (0U == (pFls_CtxData->u32Fls_Dest % FLS_SDK_PROGRAMABLE_SIZE))
                {
                    break;
                }
            }

            /* Set MCR_EHV bit */
            if (FLS_OP_SYNC == pFls_CtxData->u32Fls_Mode)
                {
                   #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )                   
                    pFls_AcCodePtr(&u32Fls_TimerCounterAC,fmc);
                    if( 0U == u32Fls_TimerCounterAC )
                    {
                        sFls_Ret = STATUS_TIMEOUT;
                        Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                    }
                    #else
                        pFls_AcCodePtr(fmc);
                    #endif
                }
            else
            {
                
                fmc->MCR.B.EHV = 1U;
               
            }
        }
    }
    else
    {
    }

    return sFls_Ret;
}
#endif // RESOURCE_SUPPORT_PFI


/*
 * @brief Check the status of flash erase operate
 *
 * This function will check the status of ongoing high voltage in erase
 *
 * @param[out] pFls_Status The status of flash erase after calling the function.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
LOCAL_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_CheckErsExec(uint8 * pFls_Status)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    *pFls_Status = FLS_OK;
    /* Check EGOOD (PEG) */
    if (FLS_FMC.MCR.B.PEG != 0U)
    {
        /* Clear EHV if it is high */
        if ( (FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U) )
        {
            /* Clear EHV */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
        }
        else
        {
            *pFls_Status = FLS_ERS_WRITE;
        }
    }
    else
    {
        /* EGOOD (PEG) is low */
        sFls_Ret = STATUS_ERROR;

        /* Clear EHV if it is high */
        if ( (FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U) )
        {
            /* Clear EHV */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
        }
    }

    if (*pFls_Status != FLS_ERS_WRITE)
    {
        /* Clear ERS */
        FLS_FMC.MCR.B.ERS = 0U;
    }
    return sFls_Ret;
}
#else
static status_t FLS_SDK_LLD_CheckErsExec(uint8_t * pFls_Status, volatile struct C55FMC_tag * fmc)
{
     VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    uint8_t *fls_ehv_val = 0;

    FLS_LLD_Get_FLS_EHV_Val(fmc, &fls_ehv_val);

    sFls_Ret = STATUS_SUCCESS;
    *pFls_Status = FLS_OK;

    /* Check EGOOD (PEG) */
    if (fmc->MCR.B.PEG != 0U)
    {
        /* Clear EHV if it is high */
        if ( (fmc->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U) )
        {
            /* Clear EHV */
            fmc->MCR.B.EHV = 0U;
            *fls_ehv_val = 0U;
        }
        else
        {
            *pFls_Status = FLS_ERS_WRITE;
        }
    }
    else
    {
        /* EGOOD (PEG) is low */
    	sFls_Ret = STATUS_ERROR;

        /* Clear EHV if it is high */
        if ( (fmc->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U) )
        {
            /* Clear EHV */
            fmc->MCR.B.EHV = 0U;
            *fls_ehv_val = 0U;
        }
    }

    if (*pFls_Status != FLS_ERS_WRITE)
    {
        /* Clear ERS */
        fmc->MCR.B.ERS = 0U;
    }

   
    return sFls_Ret;
}
#endif //RESOURCE_SUPPORT_PFI

/*
 * @brief Check the erase operation
 *
 * This function will check the status of ongoing erase operation.
 *
 * @param[out] pFls_OpRet: Return the state of flash.
 * @return Operation status
 */
LOCAL_INLINE FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_CheckEraseStatus \
( \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pFls_OpRet \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;

#ifdef RESOURCE_SUPPORT_PFI
    uint32 u32fls_index = 0U;
    uint32 u32fls_ers_num = 0U;
#endif // RESOURCE_SUPPORT_PFI
    if (pFls_OpRet == NULL)
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    *pFls_OpRet = FLS_OK;

#ifndef RESOURCE_SUPPORT_PFI
    /* There must be an erase operation */
    if (FLS_FMC.MCR.B.ERS != 0U)
    {
        /* If DONE bit goes high */
        if (FLS_FMC.MCR.B.DONE != 0U)
        {
            /* If the operation is suspended */
            if (FLS_FMC.MCR.B.ESUS != 0U)
            {
                *pFls_OpRet = FLS_ERS_SUS;
            }
            else
            {
                sFls_Ret = FLS_SDK_LLD_CheckErsExec(pFls_OpRet);
            }

        }
        else
        {
            /* DONE bit is still low means the operation is in-progress */
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
            u32Fls_TimerCounterAC--;
            if( 0U == u32Fls_TimerCounterAC )
            {
                /* Specification of Flash Driver : [SWS_Fls_00361] */
                /* Specification of Flash Driver : [SWS_Fls_00360] */
                sFls_Ret = STATUS_TIMEOUT;
                Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
				u32Fls_TimerCounterAC = FLS_ASYNC_ERASE_TIMEOUT_VALUE;
            }
			else
			{
			#endif
			    sFls_Ret = STATUS_FLASH_INPROGRESS;
			#if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )	
			}
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
           
        }
    }
#else
    for (u32fls_index = 0U; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++) {
        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[u32fls_index];

        if (fmc == NULL) {
        	u32fls_ers_num = u32fls_ers_num + 1;
            continue;
        }

        /* There must be an erase operation */
        if (fmc->MCR.B.ERS != 0U) {
            /* If DONE bit goes high */
            if (fmc->MCR.B.DONE != 0U) {
                /* If the operation is suspended */
                if (fmc->MCR.B.ESUS != 0U) 
				{
                    *pFls_OpRet = FLS_ERS_SUS;
					} 
				else 
				{
                    sFls_Ret = FLS_SDK_LLD_CheckErsExec(pFls_OpRet, fmc);

                    if (sFls_Ret != STATUS_SUCCESS) 
					{
                        break;
                    }
                }
            } else
            {
                /* DONE bit is still low means the operation is in-progress */
                 #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
                    u32Fls_TimerCounterAC--;
                    if( 0U == u32Fls_TimerCounterAC )
                    {
                        /* Specification of Flash Driver : [SWS_Fls_00361] */
                        /* Specification of Flash Driver : [SWS_Fls_00360] */
                        sFls_Ret = STATUS_TIMEOUT;
                        Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                        u32Fls_TimerCounterAC = FLS_ASYNC_ERASE_TIMEOUT_VALUE;
                        break;
                    }
                    else
                    {
                    #endif
                        sFls_Ret = STATUS_FLASH_INPROGRESS;
                        break;
                    #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )	
                    }
                    #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
               
            }
        }
        else
        {
            u32fls_ers_num = u32fls_ers_num + 1;
        }
    }

    if (u32fls_ers_num >= FLS_CONTROLLER_NUM)
    {
        sFls_Ret = STATUS_INITIALIZED;
    }
    else
    {
    }
#endif // RESOURCE_SUPPORT_PFI

    return sFls_Ret;
}

/*
 * @brief Program operation for flash
 *
 * This function is to do program operation for flash.
 *
 * @param[in] pFls_CtxData: Storing context variables.
 * @return Operation status
 */
FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Program \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;

#ifdef RESOURCE_SUPPORT_PFI
    VAR( uint32, AUTOMATIC) u32Fls_count = 0U;
#endif // RESOURCE_SUPPORT_PFI

    if ( (pFls_CtxData == NULL) || ((pFls_CtxData->u32Fls_Dest % FLS_SDK_DWORD_SIZE) != 0U) \
        || ((pFls_CtxData->u32Fls_Size % FLS_SDK_DWORD_SIZE) != 0U) )
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

#ifndef RESOURCE_SUPPORT_PFI
    if (((FLS_FMC.MCR.B.PGM != 0U) && ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_FMC.MCR.B.PSUS != 0U))) \
        || ((FLS_FMC.MCR.B.ERS != 0U) && (FLS_FMC.MCR.B.ESUS == 0U)))
    {
        /*
         * Return busy: program in progress, program in suspended, erase in progress
         * */
        sFls_Ret = STATUS_BUSY;
    }
    else
    {
        /*
         * Do program: no program and erase, erase_suspend and EHV is low
         * */
        sFls_Ret = FLS_SDK_LLD_PgmExec(pFls_CtxData);
    }

#else
    /* Obtain the controller corresponding to the target address */
    for (u32Fls_count = 0; u32Fls_count < FLS_BLOCK_ALL; u32Fls_count++) 
	{
        uint32_t addr_start = flashInfo[u32Fls_count].addrStart;
        uint32_t addr_end   = flashInfo[u32Fls_count].addrEnd;

        if ((addr_start <= pFls_CtxData->u32Fls_Dest) && ((pFls_CtxData->u32Fls_Dest ) <= addr_end))
         {  
            volatile struct C55FMC_tag *fmc = NULL;

            if (u32Fls_count < FLS_256K_LARGE0_OFFSET) 
			{
                fmc = &FLS_FMC;
            } 
			#ifdef RESOURCE_SUPPORT_PFI0
			else if (u32Fls_count < FLS_256K_LARGE1_OFFSET) 
			{
                fmc = &FLS_T40FMC0;
            }
			#endif // RESOURCE_SUPPORT_PFI0
            #ifdef RESOURCE_SUPPORT_PFI1
			 else if (u32Fls_count < FLS_256K_LARGE2_OFFSET) 
			 {
                fmc = &FLS_T40FMC1;
            } 
			#endif
			#ifdef RESOURCE_SUPPORT_PFI2
			else if (u32Fls_count < FLS_256K_LARGE3_OFFSET) 
			{
                fmc = &FLS_T40FMC2;
            } 
			#endif // RESOURCE_SUPPORT_PFI2
			#ifdef RESOURCE_SUPPORT_PFI3
			else if (u32Fls_count < FLS_256K_LARGE4_OFFSET) 
			{
                fmc = &FLS_T40FMC3;
            } 
			#endif
			#ifdef RESOURCE_SUPPORT_PFI4
			else if (u32Fls_count < FLS_256K_LARGE5_OFFSET) 
			{
                fmc = &FLS_T40FMC4;
            } 
			#endif // RESOURCE_SUPPORT_PFI4
			#ifdef RESOURCE_SUPPORT_PFI5
			else 
			{
                fmc = &FLS_T40FMC5;
            }
			#endif // RESOURCE_SUPPORT_PFI5
            if (((fmc->MCR.B.PGM != 0U) && ((fmc->MCR.B.EHV != 0U) || (fmc->MCR.B.PSUS != 0U))) ||
                 ((fmc->MCR.B.ERS != 0U) && (fmc->MCR.B.ESUS == 0U)))
            {
                /*
                * Return busy: program in progress, program in suspended, erase in progress
                * */
                sFls_Ret = STATUS_BUSY;
            }
            else
            {
                /*
                * Do program: no program and erase, erase_suspend and EHV is low
                * */
                if ((FLS_OpPFMC != NULL) && (FLS_OpPFMC != fmc)) {
                    FLS_OpPFMC->MCR.B.PGM = 0U;
                }

                FLS_OpPFMC = fmc;
                sFls_Ret = FLS_SDK_LLD_PgmExec(pFls_CtxData, fmc);
            }
            break;
        }
    }

    if (u32Fls_count == FLS_BLOCK_ALL) {
        sFls_Ret = STATUS_ERROR;
    }
#endif // RESOURCE_SUPPORT_PFI
    return sFls_Ret;
}

/*
 * @brief Check the status of flash program operate
 *
 * This function will check the status of ongoing high voltage in program
 *
 * @param[in] pFls_CtxData Storing context variables.
 * @param[out] pFls_Status The status of flash program after calling the function.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
LOCAL_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_CheckPgmExec \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData, \
    uint8 * pFls_Status \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    *pFls_Status = FLS_OK;

    /* check PEG */
    if (FLS_FMC.MCR.B.PEG != 0U) /* PEG is high */
    {
        /* Clear EHV if it is high */
        if ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U))
        {
            /* Clear EHV */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
            /* If there is remaining data needs to be programmed */
            if ((pFls_CtxData->u32Fls_Size) != 0x0U)
            {
                /* Call FLASH_LLD_Program to continue the operation */
                sFls_Ret = FLASH_SDK_LLD_Program(pFls_CtxData);

                if (sFls_Ret == STATUS_SUCCESS)
                {
                    sFls_Ret = STATUS_FLASH_INPROGRESS;
                }
            }
            else /* pFls_CtxData->u32Fls_Size == 0 */
            {
                /* Program finished successfully, clear PGM */
                FLS_FMC.MCR.B.PGM = 0U;
            }
        }
        else /* EHV == 0 */
        {
            if (FLS_FMC.MCR.B.ERS != 0U)
            {
                *pFls_Status = FLS_ERS_SUS_PGM_WRITE;
            }
            else
            {
                *pFls_Status = FLS_PGM_WRITE;
            }
        }
    }
    else /* PEG is low */
    {
        if ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U))
        {
            /* Clear EHV */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
        }
        else /* EHV == 0 */
        {
            /* PEG is invalid at this stage */
            if (FLS_FMC.MCR.B.ERS != 0U)
            {
                *pFls_Status = FLS_ERS_SUS_PGM_WRITE;
            }
            else
            {
                *pFls_Status = FLS_PGM_WRITE;
            }
        }
        /* Program finished unsuccessfully, clear PGM */
        FLS_FMC.MCR.B.PGM = 0U;
        sFls_Ret = STATUS_ERROR;
    }
    return  sFls_Ret;
}
#else
LOCAL_INLINE FUNC( status_t, FLS_CODE )  FLS_SDK_LLD_CheckPgmExec
(
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData, \
    uint8 * pFls_Status \
)
{
     VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    uint8_t *fls_ehv_val = 0;
    
    FLS_LLD_Get_FLS_EHV_Val(FLS_OpPFMC, &fls_ehv_val);
   
    sFls_Ret = STATUS_SUCCESS;
    *pFls_Status = FLS_OK;

    /* check PEG */
    if (FLS_OpPFMC->MCR.B.PEG != 0U) /* PEG is high */
    {
       
        /* Clear EHV if it is high */
        if ((FLS_OpPFMC->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U))
        {
            /* Clear EHV */
            FLS_OpPFMC->MCR.B.EHV = 0U;
            *fls_ehv_val = 0U;
            /* If there is remaining data needs to be programmed */
            if ((pFls_CtxData->u32Fls_Size) != 0x0U)
            {
                /* Call FLASH_LLD_Program to continue the operation */
                sFls_Ret = FLASH_SDK_LLD_Program(pFls_CtxData);

                if (sFls_Ret == STATUS_SUCCESS)
                {
                    sFls_Ret = STATUS_FLASH_INPROGRESS;
                }
            }
            else /* pFls_CtxData->u32Fls_Size == 0 */
            {
                /* Program finished successfully, clear PGM */
                FLS_OpPFMC->MCR.B.PGM = 0U;
            }
        }
        else /* EHV == 0 */
        {
            if (FLS_OpPFMC->MCR.B.ERS != 0U)
            {
                *pFls_Status = FLS_ERS_SUS_PGM_WRITE;
               
            }
            else
            {
                *pFls_Status = FLS_PGM_WRITE;
               
            }
        }
    }
    else /* PEG is low */
    {
        if ((FLS_OpPFMC->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U))
        {
            /* Clear EHV */
            FLS_OpPFMC->MCR.B.EHV = 0U;
            *fls_ehv_val = 0U;
        }
        else /* EHV == 0 */
        {
            /* PEG is invalid at this stage */
            if (FLS_OpPFMC->MCR.B.ERS != 0U)
            {
                *pFls_Status = FLS_ERS_SUS_PGM_WRITE;
              
            }
            else
            {
                *pFls_Status = FLS_PGM_WRITE;
               
            }
        }
        /* Program finished unsuccessfully, clear PGM */
        FLS_OpPFMC->MCR.B.PGM = 0U;
        sFls_Ret = STATUS_ERROR;
    }
         


    return sFls_Ret;
}
 
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Check the program operation
 *
 * This function will check the status of ongoing program operation.
 *
 * @param[in] pFls_CtxData: Storing context variables.
 * @param[out] pFls_OpRet: Return the status of flash.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_CheckProgramStatus \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData, \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pFls_OpRet \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;

    if ( (pFls_CtxData == NULL) || (pFls_OpRet == NULL))
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    *pFls_OpRet = FLS_OK;

    /* There must be a program operation */
    if (FLS_FMC.MCR.B.PGM != 0U)
    {
        /* If DONE bit goes high */
        if (FLS_FMC.MCR.B.DONE != 0U)
        {
            /* If the operation is suspended */
            if (FLS_FMC.MCR.B.PSUS != 0U)
            {
                /* Check if the suspended program is PGM_SUS or ERS_SUS_PGM_SUS */
                if (FLS_FMC.MCR.B.ERS != 0U)
                {
                    *pFls_OpRet = FLS_ERS_SUS_PGM_SUS;
                }
                else
                {
                    *pFls_OpRet = FLS_PGM_SUS;
                }
            }
            else
            {
                sFls_Ret = FLS_SDK_LLD_CheckPgmExec(pFls_CtxData, pFls_OpRet);
            }

        }
        else
        {
            /* DONE bit is still low means the operation is in-progress */
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
            u32Fls_TimerCounterAC--;
            if( 0U == u32Fls_TimerCounterAC )
            {
                /* Specification of Flash Driver : [SWS_Fls_00361] */
                /* Specification of Flash Driver : [SWS_Fls_00362] */
                sFls_Ret = STATUS_TIMEOUT;
                Fls_ReportRuntimeError(FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
				u32Fls_TimerCounterAC = FLS_ASYNC_WRITE_TIMEOUT_VALUE;
            }
			else
			{
			#endif
			    sFls_Ret = STATUS_FLASH_INPROGRESS;
			#if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )	
			}
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            
        }
    
    }
	return sFls_Ret;
	}
#else
FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_CheckProgramStatus \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData, \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pFls_OpRet \
)

{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;

    if ( (pFls_CtxData == NULL) || (pFls_OpRet == NULL))
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    *pFls_OpRet = FLS_OK;
    /* There must be a program operation */
    if ((FLS_OpPFMC != NULL) && (FLS_OpPFMC->MCR.B.PGM != 0U))
    {
        /* If DONE bit goes high */
        if (FLS_OpPFMC->MCR.B.DONE != 0U)
        {
            /* If the operation is suspended */
            if (FLS_OpPFMC->MCR.B.PSUS != 0U)
            {
                /* Check if the suspended program is PGM_SUS or ERS_SUS_PGM_SUS */
                if (FLS_OpPFMC->MCR.B.ERS != 0U)
                {
                    *pFls_OpRet = FLS_ERS_SUS_PGM_SUS;
                }
                else
                {
                    *pFls_OpRet = FLS_PGM_SUS;
                }
            }
            else
            {
                
            	sFls_Ret = FLS_SDK_LLD_CheckPgmExec(pFls_CtxData, pFls_OpRet);
               
            }
        }
        else
        {
            /* DONE bit is still low means the operation is in-progress */
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
            u32Fls_TimerCounterAC--;
            if( 0U == u32Fls_TimerCounterAC )
            {
                /* Specification of Flash Driver : [SWS_Fls_00361] */
                /* Specification of Flash Driver : [SWS_Fls_00362] */
                sFls_Ret = STATUS_TIMEOUT;
                Fls_ReportRuntimeError(FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                u32Fls_TimerCounterAC = FLS_ASYNC_WRITE_TIMEOUT_VALUE;
            }
            else
            {
            #endif
                sFls_Ret = STATUS_FLASH_INPROGRESS;
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )	
            }
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
        }
    }
    else
    {
        sFls_Ret = STATUS_INITIALIZED;
    }

    return sFls_Ret;
}
#endif // RESOURCE_SUPPORT_PFI
   
/*
 * @brief Erase the selected flash block
 *
 * This function is to do erase operation for selected flash block.
 *
 * @param[in] u8Fls_EraseSpace: Select flash main space.
 * @param[in] pFls_BlkSel: Select the special flash block for erasing.
 * @param[in] u32Fls_Mode: means the operate u32Fls_Mode of erase.
              FLS_OP_SYNC: means sync erase operate.
              FLS_OP_ASYNC: means async erase operate.
 * @return Operation status
 */
LOCAL_INLINE FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Erase \
( \
    VAR( uint8, AUTOMATIC ) u8Fls_EraseSpace, \
    P2VAR( fls_blksel_t, AUTOMATIC, FLS_APPL_DATA ) pFls_BlkSel, \
    VAR( uint32, AUTOMATIC) u32Fls_Mode \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC)  u32Fls_InterlockWriteAddress = 0U;

#ifdef RESOURCE_SUPPORT_PFI
    uint32 u32fls_index = 0U, u32fls_index1 = 0U;
#endif // RESOURCE_SUPPORT_PFI
    if (pFls_BlkSel == NULL)
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    /* Check for validity of erase option */
    if (u8Fls_EraseSpace == FLS_ERS_MAIN_SPACE)
    {
        u32Fls_InterlockWriteAddress = FLS_SDK_LLD_GetInterWriteAddr(pFls_BlkSel);
        if (0U == u32Fls_InterlockWriteAddress)
        {
            sFls_Ret = STATUS_ERROR;
            return sFls_Ret;
        }
    }
    else
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }
#ifndef RESOURCE_SUPPORT_PFI
    if ((FLS_FMC.MCR.B.PGM != 0U) || ((FLS_FMC.MCR.B.ERS != 0U) \
        && ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_FMC.MCR.B.ESUS != 0U))))
    {
        sFls_Ret = STATUS_BUSY;
    }
    else
    {
        /* Set MCR_ERS to start erase operation */
        FLS_FMC.MCR.B.ERS = 1U;

        if (FLS_FMC.MCR.B.ERS == 0U)
        {
            sFls_Ret = STATUS_FLASH_ERROR_ENABLE;
        }
        else
        {
            /* Correct the block selection for the case we erase Main array */

            /* Mask off reserved bits for low address space */
            pFls_BlkSel->lowBlkSel &= FLS_SEL_MASK_LOW;
            /* Mask off reserved bits for mid address space */
            pFls_BlkSel->midBlkSel &= FLS_SEL_MASK_MID; /* PRQA S 2984, 2790 */
            /* Mask off reserved bits for high address space */
            pFls_BlkSel->highBlkSel &= FLS_SEL_MASK_HIGH;
            /* Mask off reserved bits for first 256K address space */
            pFls_BlkSel->first256KBlkSel &= FLS_SEL_MASK_FIR256K;
            /* Mask off reserved bits for second 256K address space */
            pFls_BlkSel->second256KBlkSel &= FLS_SEL_MASK_SEC256K;

            /* No blocks to be selected for erase, just return */
            if ((pFls_BlkSel->lowBlkSel | pFls_BlkSel->midBlkSel | pFls_BlkSel->highBlkSel \
                | pFls_BlkSel->first256KBlkSel | pFls_BlkSel->second256KBlkSel) == 0U) /* PRQA S 2992, 2996 */
            {
                /* Return with STATUS_SUCCESS */
                FLS_FMC.MCR.B.ERS = 0U;
            }
            else
            {
                /* Set the block selection registers */
                FLS_FMC.SEL0.B.LOWSEL = pFls_BlkSel->lowBlkSel;
                FLS_FMC.SEL0.B.MIDSEL = pFls_BlkSel->midBlkSel;
                FLS_FMC.SEL1.R = pFls_BlkSel->highBlkSel;
                FLS_FMC.SEL2.R = pFls_BlkSel->first256KBlkSel;
                FLS_FMC.SEL3.R = pFls_BlkSel->second256KBlkSel;
            }

            /* Check if ERS bit is set */
            if (FLS_FMC.MCR.B.ERS != 0U)
            {
                /* Interlock write */
                *((volatile uint32*)u32Fls_InterlockWriteAddress) = FLS_ERASED_VALUE;
                /* Write a 1 to MCR_EHV */
                if (FLS_OP_SYNC == u32Fls_Mode)
                {
                #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )                   
                    pFls_AcCodePtr(&u32Fls_TimerCounterAC);
                    if( 0U == u32Fls_TimerCounterAC )
                    {
                        sFls_Ret = STATUS_TIMEOUT;
                        Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                    }
                #else
                    pFls_AcCodePtr();
                #endif
                }
                else
                {
                    FLS_FMC.MCR.B.EHV = 1U;
                }
                /* Not wait until MCR_DONE is set */
            }
        }
    }
#else
    pFls_BlkSel->lowBlkSel &= FLS_SEL_MASK_LOW;
    pFls_BlkSel->midBlkSel &= FLS_SEL_MASK_MID;
    pFls_BlkSel->highBlkSel &= FLS_SEL_MASK_HIGH;
    #ifdef RESOURCE_SUPPORT_PFI0
    pFls_BlkSel->large0BlkSel &= FLS_SEL_MASK_LARGE0_256K;
    #endif // RESOURCE_SUPPORT_PFI0
    #ifdef RESOURCE_SUPPORT_PFI1
    pFls_BlkSel->large1BlkSel &= FLS_SEL_MASK_LARGE1_256K;
    #endif // RESOURCE_SUPPORT_PFI1
    #ifdef RESOURCE_SUPPORT_PFI2
    pFls_BlkSel->large2BlkSel &= FLS_SEL_MASK_LARGE2_256K;
    #endif // RESOURCE_SUPPORT_PFI2
    #ifdef RESOURCE_SUPPORT_PFI3
    pFls_BlkSel->large3BlkSel &= FLS_SEL_MASK_LARGE3_256K;
    #endif // RESOURCE_SUPPORT_PFI3
    #ifdef RESOURCE_SUPPORT_PFI4
    pFls_BlkSel->large4BlkSel &= FLS_SEL_MASK_LARGE4_256K;
    #endif // RESOURCE_SUPPORT_PFI4
    #ifdef RESOURCE_SUPPORT_PFI5
    pFls_BlkSel->large5BlkSel &= FLS_SEL_MASK_LARGE5_256K;
    #endif // RESOURCE_SUPPORT_PFI5

    fls_blksel_t  blkSelTmp = *pFls_BlkSel;

    /* Get the controller that needs to be operated on */
    //FLS_OpBlk = *pFls_BlkSel;
    cc_memset((uint8_t *)(&FLS_OpEFMC), NULL, sizeof(FLS_OpEFMC));
    if ((pFls_BlkSel->lowBlkSel > 0U) || (pFls_BlkSel->midBlkSel > 0U) || (pFls_BlkSel->highBlkSel > 0U)) {
        FLS_OpEFMC[0] = &FLS_FMC;
    }

    #ifdef RESOURCE_SUPPORT_PFI0
    if (pFls_BlkSel->large0BlkSel > 0U) {
        FLS_OpEFMC[1] = &T40FMC0;
    }
    #endif // RESOURCE_SUPPORT_PFI0

    #ifdef RESOURCE_SUPPORT_PFI1
    if (pFls_BlkSel->large1BlkSel > 0U) {
        FLS_OpEFMC[2] = &T40FMC1;
    }
    #endif // RESOURCE_SUPPORT_PFI1

    #ifdef RESOURCE_SUPPORT_PFI2
    if (pFls_BlkSel->large2BlkSel > 0U) {
        FLS_OpEFMC[3] = &T40FMC2;
    }
    #endif // RESOURCE_SUPPORT_PFI2

    #ifdef RESOURCE_SUPPORT_PFI3
    if (pFls_BlkSel->large3BlkSel > 0U) {
        FLS_OpEFMC[4] = &T40FMC3;
    }
    #endif // RESOURCE_SUPPORT_PFI3

    #ifdef RESOURCE_SUPPORT_PFI4
    if (pFls_BlkSel->large4BlkSel > 0U) {
        FLS_OpEFMC[5] = &T40FMC4;
    }
    #endif // RESOURCE_SUPPORT_PFI4

    #ifdef RESOURCE_SUPPORT_PFI5
    if (pFls_BlkSel->large5BlkSel > 0U) {
        FLS_OpEFMC[6] = &T40FMC5;
    }
    #endif // RESOURCE_SUPPORT_PFI5
    /* Check parameters */
    for (u32fls_index = 0U; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++)
    {
        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[u32fls_index];

        if (fmc == NULL) {
            continue;
        }

        /* Check busy */
        if ((fmc->MCR.B.PGM != 0U) || ((fmc->MCR.B.ERS != 0U) && ((fmc->MCR.B.EHV != 0U) || (fmc->MCR.B.ESUS != 0U)))) {
            sFls_Ret = STATUS_BUSY;
            return sFls_Ret;
        }
        /* Set MCR_ERS to start erase operation */
        fmc->MCR.B.ERS = 1U;

        if (fmc->MCR.B.ERS == 0U) {
            for (u32fls_index1 = 0U; u32fls_index1 < u32fls_index; u32fls_index1++) {
                fmc = FLS_OpEFMC[u32fls_index1];

                if (fmc != NULL) {
                    fmc->MCR.B.ERS = 0U;
                }
            }

            sFls_Ret = STATUS_FLASH_ERROR_ENABLE;
            return sFls_Ret;
        }
    }
    /* Execute erase */
    for (u32fls_index = 0U; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++) 
    {
        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[u32fls_index];

        if (fmc == NULL) {
            continue;
        }

        u32Fls_InterlockWriteAddress = FLS_SDK_LLD_GetInterWriteAddr(&blkSelTmp);

        if (fmc == &FLS_FMC) {
            blkSelTmp.lowBlkSel = 0;
            blkSelTmp.midBlkSel = 0;
            blkSelTmp.highBlkSel = 0;

            /* Set the block selection registers */
            FLS_FMC.SEL0.B.LOWSEL = pFls_BlkSel->lowBlkSel;
            FLS_FMC.SEL0.B.MIDSEL = pFls_BlkSel->midBlkSel << FLS_LOCK_OFFSET_MID;
            FLS_FMC.SEL1.B.HIGHSEL = pFls_BlkSel->highBlkSel;
        } 
		#ifdef RESOURCE_SUPPORT_PFI0
		else if (fmc == & FLS_T40FMC0) 
		{
            blkSelTmp.large0BlkSel = 0;

            /* Set the block selection registers */
            T40FMC0.SEL2.B.A256KSEL = pFls_BlkSel->large0BlkSel;
        }
		 #endif // RESOURCE_SUPPORT_PFI0
		 #ifdef RESOURCE_SUPPORT_PFI1 
		 else if (fmc == & FLS_T40FMC1) 
		 {
            blkSelTmp.large1BlkSel = 0;

            /* Set the block selection registers */
            T40FMC1.SEL2.B.A256KSEL = pFls_BlkSel->large1BlkSel;
        } 
		 #endif // RESOURCE_SUPPORT_PFI1
		#ifdef RESOURCE_SUPPORT_PFI2
		else if (fmc == & FLS_T40FMC2) 
		{
            blkSelTmp.large2BlkSel = 0;

            /* Set the block selection registers */
            T40FMC2.SEL2.B.A256KSEL = pFls_BlkSel->large2BlkSel;
        } 
		  #endif // RESOURCE_SUPPORT_PFI2
		  #ifdef RESOURCE_SUPPORT_PFI3
		else if (fmc == & FLS_T40FMC3) 
		{
            blkSelTmp.large3BlkSel = 0;

            /* Set the block selection registers */
            T40FMC3.SEL2.B.A256KSEL = pFls_BlkSel->large3BlkSel;
        } 
		#endif // RESOURCE_SUPPORT_PFI3
		#ifdef RESOURCE_SUPPORT_PFI4
		else if (fmc == & FLS_T40FMC4)
		 {
            blkSelTmp.large4BlkSel = 0;

            /* Set the block selection registers */
            T40FMC4.SEL2.B.A256KSEL = pFls_BlkSel->large4BlkSel;
        } 
		#endif // RESOURCE_SUPPORT_PFI4
		#ifdef RESOURCE_SUPPORT_PFI5
		else if (fmc == & FLS_T40FMC5) 
		{
            blkSelTmp.large5BlkSel = 0;

            /* Set the block selection registers */
            T40FMC5.SEL2.B.A256KSEL = pFls_BlkSel->large5BlkSel;
        } 
		#endif // RESOURCE_SUPPORT_PFI5
		else 
		{
        }

        /* Interlock write */
        *((volatile uint32_t *)u32Fls_InterlockWriteAddress) = FLS_ERASED_VALUE;

        /* Write a 1 to MCR_EHV */
        if (FLS_OP_SYNC == u32Fls_Mode)
        {
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )                   
                pFls_AcCodePtr(&u32Fls_TimerCounterAC,fmc);
                if( 0U == u32Fls_TimerCounterAC )
                {
                    sFls_Ret = STATUS_TIMEOUT;
                    Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                }
            #else
                pFls_AcCodePtr(fmc);
            #endif
        }
        else {
            fmc->MCR.B.EHV = 1U;
        }

        /* Not wait until MCR_DONE is set */
    }
#endif // RESOURCE_SUPPORT_PFI
    return sFls_Ret;
}

/*
 * @brief FLS_Erase
 *
 * Flash erase special block.
 */
FUNC( status_t, FLS_CODE ) FLS_SDK_Erase \
( \
    VAR( uint16, AUTOMATIC) u16Fls_FlashBlock, \
    VAR( uint32, AUTOMATIC) u32Fls_Index, \
    VAR( uint16, AUTOMATIC ) bFls_Mode \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( fls_blksel_t, AUTOMATIC) pFls_BlkSel;
    VAR( uint8, AUTOMATIC)  u8Fls_OpRet;
    VAR( uint32, AUTOMATIC) u32Fls_Offset = 0U;

#ifndef RESOURCE_SUPPORT_PFI
    if (u16Fls_FlashBlock > FLS_BLK_SECOND_256K)
#else
    if (u16Fls_FlashBlock > FLS_BLK_LARGE5_256K)
#endif // RESOURCE_SUPPORT_PFI
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }
    
    /*
     * Flash erase operate
     *
     *  */
    sFls_Ret = FLASH_SDK_LLD_CheckEraseStatus(&u8Fls_OpRet);

    if(sFls_Ret == STATUS_SUCCESS && (FLS_OK == u8Fls_OpRet) )
    {
        FLS_SDK_LLD_DCacheInvalid();   // Make the erased flash space in Dcache invalid
        return sFls_Ret;	
    }
    else if(sFls_Ret == STATUS_INITIALIZED )
    {
    /* Get flash block offset and select state */
        sFls_Ret = FLS_SDK_Get_Offset_Select(u16Fls_FlashBlock, u32Fls_Index, &u32Fls_Offset, &pFls_BlkSel);
        if (STATUS_SUCCESS != sFls_Ret)
        {
            return sFls_Ret;
        }
        /* Call FLASH_LLD_Erase to start erase */
        sFls_Ret = FLASH_SDK_LLD_Erase(FLS_ERS_MAIN_SPACE, &pFls_BlkSel, bFls_Mode);
        if (STATUS_SUCCESS != sFls_Ret)
        {
            return sFls_Ret;
        }

        /* Call FLASH_LLD_CheckEraseStatus to confirm erase successful or not */

        sFls_Ret = FLASH_SDK_LLD_CheckEraseStatus(&u8Fls_OpRet);


        if ((STATUS_SUCCESS != sFls_Ret) || (FLS_OK != u8Fls_OpRet))
        {
            return sFls_Ret;
        }

        /* Check offset and index */
        if ((u32Fls_Offset + u32Fls_Index) >= FLS_BLOCK_ALL)
        {
            sFls_Ret = STATUS_ERROR;
            return sFls_Ret;
        }
    }
    else
    {
        return sFls_Ret;
    }

    return sFls_Ret;
}


FUNC( status_t, FLS_CODE ) FLS_SDK_Read  \
( \
    VAR( uint32, AUTOMATIC) u32Fls_dest, \
    VAR( uint32, AUTOMATIC) u32Fls_size,  \
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pDataPtr
)
{
    VAR(uint32, AUTOMATIC) u32Fls_InitDataLength = 0UL;
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) Fls_ReadEndAddressPtr = NULL_PTR;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) u8Fls_ReadBlockAddressEndPtr = NULL_PTR;

    gFls_ReadAddressPtr = (volatile const uint8 *)u32Fls_dest;
    Fls_ReadEndAddressPtr = gFls_ReadAddressPtr + u32Fls_size;

    u32Fls_InitDataLength = Fls_LLD_CalcInitDataLength( gFls_ReadAddressPtr, u32Fls_size );
    u8Fls_ReadBlockAddressEndPtr = gFls_ReadAddressPtr + u32Fls_InitDataLength;

    while( (uint32)gFls_ReadAddressPtr < (uint32)u8Fls_ReadBlockAddressEndPtr )   
    {
        *pDataPtr = *gFls_ReadAddressPtr;
        pDataPtr++;
        gFls_ReadAddressPtr++;
    }

    u8Fls_ReadBlockAddressEndPtr += Fls_LLD_CalcWideDataLength( u32Fls_InitDataLength, u32Fls_size );
    while( (uint32)gFls_ReadAddressPtr < (uint32)u8Fls_ReadBlockAddressEndPtr )   
    {
        *((FLS_LLD_DATA_BUS_WIDTH_TYPE*)pDataPtr) = \
        *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)gFls_ReadAddressPtr);
        pDataPtr += sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE);
        gFls_ReadAddressPtr += sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE);
    }

    while( (uint32)gFls_ReadAddressPtr < (uint32)Fls_ReadEndAddressPtr )    
    {
        *pDataPtr = *gFls_ReadAddressPtr;
        pDataPtr++;
        gFls_ReadAddressPtr++;
    }

    return sFls_Ret;
}

FUNC(status_t, FLS_CODE) FLASH_SDK_LLD_Abort(void)
{
    volatile VAR(uint32, AUTOMATIC) u32Fls_clearFlag = 0x0U;
    VAR( uint32, AUTOMATIC) u32Fls_count = 450U;

    volatile VAR(uint32, AUTOMATIC) u32Fls_erase = 0x0U;

    u32Fls_erase = FLS_FMC.MCR.B.ERS | FLS_T40FMC0.MCR.B.ERS | FLS_T40FMC1.MCR.B.ERS | FLS_T40FMC2.MCR.B.ERS | FLS_T40FMC3.MCR.B.ERS | FLS_T40FMC4.MCR.B.ERS | FLS_T40FMC5.MCR.B.ERS;

#ifndef RESOURCE_SUPPORT_PFI
    if (FLS_FMC.MCR.B.ESUS != 0U)
    {
        if (FLS_FMC.MCR.B.PSUS != 0U)
        {
            u32Fls_clearFlag = 0x3U;
        }
        else
        {
            u32Fls_clearFlag = 0x2U;
        }
    }
    else
    {
        if (FLS_FMC.MCR.B.PSUS != 0U)
        {
            u32Fls_clearFlag = 0x1U;
        }
    }

    if ((u32Fls_clearFlag & 0x1U) != 0x0U)  /* Program-suspended Erase-suspended or Program-suspended only */
    {
        /* Wait MCR DONE bit is set to program-suspended operation accomplish */
        while ((FLS_FMC.MCR.B.DONE == 0U) && (u32Fls_count > 0U))
        {
            u32Fls_count--;
        }
        /* Set MCR_EHV bit then clear MCR_PSUS to resume program operation */
        FLS_FMC.MCR.B.EHV = 1U;
        FLS_FMC.MCR.B.PSUS = 0U;
    }

    if ((u32Fls_clearFlag & 0x2U) != 0x0U)
    {
        /* Clear EHV to abort program operation and then clear MCR_PGM */
        FLS_FMC.MCR.B.EHV = 0U;
        /* Wait MCR DONE bit is set */
        while ((FLS_FMC.MCR.B.DONE == 0U) && (u32Fls_count > 0U))
        {
            u32Fls_count--;
        }
        FLS_FMC.MCR.B.PGM = 0U;
        /* Set MCR_EHV bit then clear MCR_PSUS to resume erase operation */
        FLS_FMC.MCR.B.EHV = 1U;
        FLS_FMC.MCR.B.ESUS = 0U;
    }

    /* Clear EHV bit to abort flash operation */
    FLS_FMC.MCR.B.EHV = 0U;
    /* Wait MCR DONE bit is set */
    while ((FLS_FMC.MCR.B.DONE == 0U) && (u32Fls_count > 0U))
    {
        u32Fls_count--;
    }

    /* Clear PGM, ERS bit */
    FLS_FMC.MCR.B.PGM = 0U;
    FLS_FMC.MCR.B.ERS = 0U;
#else
    uint32_t u32fls_index = 0U;

    for (u32fls_index = 0; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++) {
        volatile struct C55FMC_tag * const fmc = flashControllerList[u32fls_index];

        u32Fls_count = 450U;
        u32Fls_clearFlag = 0x0U;
        if (fmc->MCR.B.ESUS != 0U)
        {
            if (fmc->MCR.B.PSUS != 0U)
            {
                u32Fls_clearFlag = 0x3U;
            }
            else
            {
                u32Fls_clearFlag = 0x2U;
            }
        }
        else
        {
            if (fmc->MCR.B.PSUS != 0U)
            {
                u32Fls_clearFlag = 0x1U;
            }
        }

        if ((u32Fls_clearFlag & 0x1U) != 0x0U)  /* Program-suspended Erase-suspended or Program-suspended only */
        {
            /* Wait MCR DONE bit is set to program-suspended operation accomplish */
            while ((fmc->MCR.B.DONE == 0U) && (u32Fls_count > 0U))
            {
                u32Fls_count--;
            }
            /* Set MCR_EHV bit then clear MCR_PSUS to resume program operation */
            fmc->MCR.B.EHV = 1U;
            fmc->MCR.B.PSUS = 0U;
        }

        if ((u32Fls_clearFlag & 0x2U) != 0x0U)
        {
            /* Clear EHV to abort program operation and then clear MCR_PGM */
            fmc->MCR.B.EHV = 0U;
            /* Wait MCR DONE bit is set */
            while ((fmc->MCR.B.DONE == 0U) && (u32Fls_count > 0U))
            {
                u32Fls_count--;
            }
            fmc->MCR.B.PGM = 0U;
            /* Set MCR_EHV bit then clear MCR_PSUS to resume erase operation */
            fmc->MCR.B.EHV = 1U;
            fmc->MCR.B.ESUS = 0U;
        }

        /* Clear EHV bit to abort flash operation */
        fmc->MCR.B.EHV = 0U;
        /* Wait MCR DONE bit is set */
        while ((fmc->MCR.B.DONE == 0U) && (u32Fls_count > 0U))
        {
            u32Fls_count--;
        }

        /* Clear PGM, ERS bit */
        fmc->MCR.B.PGM = 0U;
        fmc->MCR.B.ERS = 0U;
    } 

#endif // RESOURCE_SUPPORT_PFI

    /* Make the erased flash space in DCache invalid */
    if (u32Fls_erase != 0x0U)
    {
        FLS_SDK_LLD_DCacheInvalid();
    }

    return STATUS_SUCCESS;
}

FUNC( status_t, FLS_CODE ) FLASH_LLD_BlankCheck \
( \
    VAR( uint32, AUTOMATIC) u32Fls_Dest, \
    VAR( uint32, AUTOMATIC) u32Fls_Size, \
    VAR( uint32, AUTOMATIC) u32Fls_CheckWordSize, \
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_FailAddr \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC) u32Fls_DestIndex = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Temp = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_DestTmp = u32Fls_Dest;
    VAR( uint32, AUTOMATIC) u32Fls_SizeTmp = u32Fls_Size;

    if (((u32Fls_DestTmp | u32Fls_SizeTmp) % FLS_SDK_WORD_SIZE) != 0U)
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    while ((u32Fls_SizeTmp > 0U) && (STATUS_SUCCESS == sFls_Ret))
    {
        /* Number of words needs to be checked for blank */
        u32Fls_Temp = u32Fls_SizeTmp / FLS_SDK_WORD_SIZE;

        /* In each blank check cycle, we take up to a certain words */
        if (u32Fls_Temp >= u32Fls_CheckWordSize)
        {
            u32Fls_Temp = u32Fls_CheckWordSize;
        }

        /* Word by word blank check */
        for (u32Fls_DestIndex = 0U; u32Fls_DestIndex < u32Fls_Temp; u32Fls_DestIndex++)
        {
            if ((*(volatile uint32 *)u32Fls_DestTmp) != 0xFFFFFFFFU)
            {
                sFls_Ret = STATUS_ERROR;
                *pFls_FailAddr = u32Fls_DestTmp;
                break;
            }
            u32Fls_DestTmp += FLS_SDK_WORD_SIZE;
            u32Fls_SizeTmp -= FLS_SDK_WORD_SIZE;
        }
    }

    return sFls_Ret;
}

FUNC( status_t, FLS_CODE ) FLASH_LLD_ProgramVerify \
( \
    VAR( uint32, AUTOMATIC) u32Fls_Dest, \
    VAR( uint32, AUTOMATIC) u32Fls_Size, \
    VAR( uint32, AUTOMATIC) u32Fls_Src, \
    VAR( uint32, AUTOMATIC) u32Fls_CheckWordSize, \
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_FailAddr \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC) u32Fls_DestIndex = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Temp = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_ValDest = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_DestTmp = u32Fls_Dest;
    VAR( uint32, AUTOMATIC) u32Fls_SizeTmp = u32Fls_Size;
    VAR( uint32, AUTOMATIC) u32Fls_SrcTmp = u32Fls_Src;

    if ( ((u32Fls_DestTmp | u32Fls_SizeTmp | u32Fls_Src) % FLS_SDK_WORD_SIZE) != 0U )
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    while ((u32Fls_SizeTmp > 0U) && (STATUS_SUCCESS == sFls_Ret))
    {
        /* Number of words needs to be verified */
        u32Fls_Temp = u32Fls_SizeTmp / FLS_SDK_WORD_SIZE;

        /* In each verify cycle, we take up to a certain words */
        if (u32Fls_Temp >= u32Fls_CheckWordSize)
        {
            u32Fls_Temp = u32Fls_CheckWordSize;
        }

        /* Word by word verify */
        for (u32Fls_DestIndex = 0U; u32Fls_DestIndex < u32Fls_Temp; u32Fls_DestIndex++)
        {
            u32Fls_ValDest = *(volatile uint32 *)u32Fls_DestTmp;
            if (u32Fls_ValDest != *(volatile uint32 *)u32Fls_SrcTmp)
            {
                sFls_Ret = STATUS_ERROR;
                *pFls_FailAddr = u32Fls_DestTmp;
                break;
            }

            u32Fls_DestTmp += FLS_SDK_WORD_SIZE;
            u32Fls_SrcTmp += FLS_SDK_WORD_SIZE;
            u32Fls_SizeTmp -= FLS_SDK_WORD_SIZE;
        }
    }

    return sFls_Ret;
}

/*
 * @brief Enable flash command complete interrupt.
 *
 * This function will enable flash command complete interrupt.
 */
FUNC( void, FLS_CODE ) FLASH_LLD_EnableCmdCompleteInterupt(void)
{
    /* Enable the command complete interrupt */
    FLS_FMC.MCR.B.PECIE = 1U;

#ifdef RESOURCE_SUPPORT_PFI
    FLS_T40FMC0.MCR.B.PECIE = 1U;
    FLS_T40FMC1.MCR.B.PECIE = 1U;
    FLS_T40FMC2.MCR.B.PECIE = 1U;
    FLS_T40FMC3.MCR.B.PECIE = 1U;
    FLS_T40FMC4.MCR.B.PECIE = 1U;
    FLS_T40FMC5.MCR.B.PECIE = 1U;
#endif // RESOURCE_SUPPORT_PFI
}

/*
 * @brief Disable flash command complete interrupt.
 *
 * This function will disable flash command complete interrupt.
 *
 */
FUNC( void, FLS_CODE ) FLASH_LLD_DisableCmdCompleteInterupt(void)
{
    /* Disable the command complete interrupt */
    FLS_FMC.MCR.B.PECIE = 0U;

#ifdef RESOURCE_SUPPORT_PFI
    FLS_T40FMC0.MCR.B.PECIE = 0U;
    FLS_T40FMC1.MCR.B.PECIE = 0U;
    FLS_T40FMC2.MCR.B.PECIE = 0U;
    FLS_T40FMC3.MCR.B.PECIE = 0U;
    FLS_T40FMC4.MCR.B.PECIE = 0U;
    FLS_T40FMC5.MCR.B.PECIE = 0U;
#endif // RESOURCE_SUPPORT_PFI
}

/*
 * @brief Flash command complete interrupt handle function.
 *
 * The interrupt handle function for flash command complete interrupt.
 *
 */
#ifndef RESOURCE_SUPPORT_PFI
FUNC( void, FLS_CODE ) FLASH_Cmd_Done_ISR(void)
{
    FLS_FMC.MCR.B.PECIE = 0U;
    if (FLS_FMC.MCR.B.EHV != 0U)
    {
        FLS_FMC.MCR.B.EHV = 0U;
        FLS_EHV_Val = 1U;
    }
    else
    {
        FLS_EHV_Val = 0U;
    }
}
#else
FUNC( void, FLS_CODE ) FLASH_Cmd_Done_ISR(void)
{
    FLS_FMC.MCR.B.PECIE = 0U;
    if (FLS_FMC.MCR.B.EHV != 0U)
    {
        FLS_FMC.MCR.B.EHV = 0U;
        FLS_EHV_Val_All[0] = 1U;
    }
    else
    {
        FLS_EHV_Val_All[0] = 0U;
    }
}


FUNC( void, FLS_CODE ) FLASH_PFI0_Cmd_Done_ISR(void) {
    FLS_T40FMC0.MCR.B.PECIE = 0U;
    if (FLS_T40FMC0.MCR.B.EHV != 0U)
    {
        FLS_T40FMC0.MCR.B.EHV = 0U;
        FLS_EHV_Val_All[1] = 1U;
    }
    else
    {
        FLS_EHV_Val_All[1] = 0U;
    }
}

FUNC( void, FLS_CODE ) FLASH_PFI1_Cmd_Done_ISR(void) {
    FLS_T40FMC1.MCR.B.PECIE = 0U;
    if (FLS_T40FMC1.MCR.B.EHV != 0U)
    {
        FLS_T40FMC1.MCR.B.EHV = 0U;
        FLS_EHV_Val_All[2] = 1U;
    }
    else
    {
        FLS_EHV_Val_All[2] = 0U;
    }
}

FUNC( void, FLS_CODE ) FLASH_PFI2_Cmd_Done_ISR(void) {
    FLS_T40FMC2.MCR.B.PECIE = 0U;
    if (FLS_T40FMC2.MCR.B.EHV != 0U)
    {
        FLS_T40FMC2.MCR.B.EHV = 0U;
        FLS_EHV_Val_All[3] = 1U;
    }
    else
    {
        FLS_EHV_Val_All[3] = 0U;
    }
}

FUNC( void, FLS_CODE ) FLASH_PFI3_Cmd_Done_ISR(void) {
    FLS_T40FMC3.MCR.B.PECIE = 0U;
    if (FLS_T40FMC3.MCR.B.EHV != 0U)
    {
        FLS_T40FMC3.MCR.B.EHV = 0U;
        FLS_EHV_Val_All[4] = 1U;
    }
    else
    {
        FLS_EHV_Val_All[4] = 0U;
    }
}

FUNC( void, FLS_CODE ) FLASH_PFI4_Cmd_Done_ISR(void) {
    FLS_T40FMC4.MCR.B.PECIE = 0U;
    if (FLS_T40FMC4.MCR.B.EHV != 0U)
    {
        FLS_T40FMC4.MCR.B.EHV = 0U;
        FLS_EHV_Val_All[5] = 1U;
    }
    else
    {
        FLS_EHV_Val_All[5] = 0U;
    }
}

FUNC( void, FLS_CODE ) FLASH_PFI5_Cmd_Done_ISR(void) {
    FLS_T40FMC5.MCR.B.PECIE = 0U;
    if (FLS_T40FMC5.MCR.B.EHV != 0U)
    {
        FLS_T40FMC5.MCR.B.EHV = 0U;
        FLS_EHV_Val_All[6] = 1U;
    }
    else
    {
        FLS_EHV_Val_All[6] = 0U;
    }
}
#endif // RESOURCE_SUPPORT_PFI







