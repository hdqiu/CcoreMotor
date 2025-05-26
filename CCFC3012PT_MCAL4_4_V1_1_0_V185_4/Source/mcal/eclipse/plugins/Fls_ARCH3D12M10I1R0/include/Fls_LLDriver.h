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
*   @file    Fls_LLDriver.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

#ifndef FLS_LLDRIVER_H
#define FLS_LLDRIVER_H

#include "Fls_Cfg.h"
#include "derivative.h"
#include "intc_lld.h"

#define FLS_LLD_WRA_H_VENDOR_ID                     176
#define FLS_LLD_WRA_H_AR_REL_MAJOR_VER              4
#define FLS_LLD_WRA_H_AR_REL_MINOR_VER              4
#define FLS_LLD_WRA_H_AR_REL_REV_VER                0
#define FLS_LLD_WRA_H_SW_MAJOR_VER                  1
#define FLS_LLD_WRA_H_SW_MINOR_VER                  0
#define FLS_LLD_WRA_H_SW_PATCH_VER                  1

#if (FLS_VENDOR_ID_OUTPUT != FLS_LLD_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_H_VENDOR_ID "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_LLD_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_LLD_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_H_AR_REL_MINOR_VER "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_LLD_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_H_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_LLD_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_H_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_LLD_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_H_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_LLD_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_H_SW_PATCH_VER "
#endif

#define RESET_TIMEOUT_COUNTER 0x00000000U

#define FLS_LLD_DATA_BUS_WIDTH_TYPE   uint32

#define FLS_AC_LOAD

// #ifdef FLS_AC_LOAD
// #ifndef CCFC3012PT
// typedef void (* fls_acload_t)(void);
// #else
// typedef void (* fls_acload_t)(volatile struct C55FMC_tag *fmc);
// #endif // CCFC3012PT
// #endif // FLS_AC_LOAD



#define FLS_SDK_PROGRAMABLE_SIZE        (0x80U)

#define NUM_WORD_FOR_BLANK_CHECK    (0x90)  /* Number of word for blank check */

#define NUM_WORD_FOR_PGM_VERIFY     (0x80)  /* Number of word for program verify */
/* The number of word to calculate sum in each cycle. */
#define NUM_WORD_FOR_CHECK_SUM      (0x120)

#define FLS_OP_SYNC                 (0x00U)   /* flash sync operate(erase or program)  */
#define FLS_OP_ASYNC                (0x01U)   /* flash async operate(erase or program) */

#define FLS_BLK_LOW             (0x00U)   /* low flash block */
#define FLS_BLK_MID             (0x01U)   /* mid flash block */
#define FLS_BLK_HIGH            (0x02U)   /* high flash block */

#ifndef RESOURCE_SUPPORT_PFI
    #define FLS_BLK_FIRST_256K      (0x03U)   /* first of 256K flash block */
    #define FLS_BLK_SECOND_256K     (0x04U)   /* second of 256K flash block */
#else
    #ifdef RESOURCE_SUPPORT_PFI0
    #define FLS_BLK_LARGE0_256K     (0x03U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI0
    #ifdef RESOURCE_SUPPORT_PFI1
    #define FLS_BLK_LARGE1_256K     (0x04U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI1
    #ifdef RESOURCE_SUPPORT_PFI2
    #define FLS_BLK_LARGE2_256K     (0x05U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI2
    #ifdef RESOURCE_SUPPORT_PFI3
    #define FLS_BLK_LARGE3_256K     (0x06U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI3
    #ifdef RESOURCE_SUPPORT_PFI4
    #define FLS_BLK_LARGE4_256K     (0x07U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI4
    #ifdef RESOURCE_SUPPORT_PFI5
    #define FLS_BLK_LARGE5_256K     (0x08U)   /* large0 of 256k flash block */
	 #endif // RESOURCE_SUPPORT_PFI5
#endif // CCFC3012PT

#define FLS_ERS_MAIN_SPACE      (0x00U)   /* erase flash main space */

/*
 * Define for flash status of flash operate.
 */
#define FLS_OK                  (0x00U)   /* Flash operate successful status  */

#define FLS_PGM_WRITE           (0x10U)   /* Program sequence in inter_lock write stage. */
#define FLS_ERS_WRITE           (0x11U)   /* Erase sequence in inter_lock write stage. */
#define FLS_ERS_SUS_PGM_WRITE   (0x12U)   /* Erase-suspend program sequence in inter_lock write stage. */

#define FLS_NO_SUS              (0x20U)   /* There is no program/erase operate for suspend */
#define FLS_PGM_SUS             (0x21U)   /* Program operate is in suspend state */
#define FLS_ERS_SUS             (0x22U)   /* Erase operate is in suspend state */
#define FLS_ERS_SUS_PGM_SUS     (0x23U)   /* Erase-suspended program operate is in suspend state */

#define FLS_RES_NOTHING         (0x30U)   /* There is no suspended program/erase operate */
#define FLS_RES_PGM             (0x31U)   /* Program operate is resumed */
#define FLS_RES_ERS             (0x32U)   /* Erase operate is resumed */
#define FLS_RES_ERS_PGM         (0x33U)   /* Erase-suspended program operate is resumed */

#define FLS_SDK_WORD_SIZE               (4U)
#define FLS_SDK_DWORD_SIZE              (8U)

#define FLS_QPAGE_SIZE              (128U) /* PRQA S 1534 */


typedef struct /* PRQA S 3630 */
{
    uint32 lowBlkSel;              /* Select bits for low block */
    uint32 midBlkSel;              /* Select bits for mid block */
    uint32 highBlkSel;             /* Select bits for high block */
#ifndef RESOURCE_SUPPORT_PFI
    uint32 first256KBlkSel;        /* Select bits for first of 256K block */
    uint32 second256KBlkSel;       /* Select bits for second of 256K block */
#else
    #ifdef RESOURCE_SUPPORT_PFI0
    uint32 large0BlkSel;            /* Select bits for large0 block */
    #endif // RESOURCE_SUPPORT_PFI0
    #ifdef RESOURCE_SUPPORT_PFI1
    uint32 large1BlkSel;            /* Select bits for large1 block */
    #endif // RESOURCE_SUPPORT_PFI1
    #ifdef RESOURCE_SUPPORT_PFI2
    uint32 large2BlkSel;            /* Select bits for large2 block */
    #endif // RESOURCE_SUPPORT_PFI2
    #ifdef RESOURCE_SUPPORT_PFI3
    uint32 large3BlkSel;            /* Select bits for large3 block */
    #endif // RESOURCE_SUPPORT_PFI3
    #ifdef RESOURCE_SUPPORT_PFI4
    uint32 large4BlkSel;            /* Select bits for large4 block */
    #endif // RESOURCE_SUPPORT_PFI4
    #ifdef RESOURCE_SUPPORT_PFI5
    uint32 large5BlkSel;            /* Select bits for large5 block */
	 #endif // RESOURCE_SUPPORT_PFI5
#endif // CCFC3012PT
} fls_blksel_t;

typedef struct /* PRQA S 3630 */
{
    uint32 u32Fls_Dest;                   /* Destination address for flash operate */
    uint32 u32Fls_Src;                    /* Source address for flash operate */
    uint32 u32Fls_Size;                   /* Size of the flash operate */
    uint32 u32Fls_Mode;                   /* Operate u32Fls_Mode type(FLS_OP_SYNC or FLS_OP_ASYNC) */
} fls_ctxdata_t;

/* Flash Swap Status */
extern uint8 g_swapStatus;
extern uint8 g_flashSize;

extern P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) gFls_ConfigPtr;

extern P2VAR( uint8, FLS_VAR, FLS_APPL_DATA ) gFls_JobDataDestPtr;

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
extern VAR(uint32, FLS_VAR) u32Fls_TimerCounterAC;
#endif

#define SET_TIMEOUT_COUNTER_TO_ZERO   0x00000000U

#define ABT_OPT_TIMEOUT_COUNTER  450U
#if defined(__cplusplus)
extern "C" {
#endif





FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Init \
( \
    P2CONST( uint8, FLS_VAR, FLS_APPL_CONST )  pFls_LockBlk \
);

#if( FLS_ERASE_VERIFICATION_ENABLED == STD_ON )
FUNC( status_t, FLS_CODE ) Fls_LLD_VerifyErase \
( \
    P2CONST(volatile uint32, AUTOMATIC, FLS_APPL_CONST ) u32Fls_FlashAreaPtr, \
	CONST( Fls_LengthType, AUTOMATIC) u32Fls_DataLength \
);
#endif

#if( FLS_WRITE_VERIFICATION_ENABLED == STD_ON )
FUNC( status_t, FLS_CODE ) Fls_LLD_VerifyWrite \
( \
    P2CONST( volatile uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_FlashAreaPtr, \
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_UserBufferPtr, \
    CONST( Fls_LengthType, AUTOMATIC) u32Fls_DataLength \
);
#endif

FUNC( status_t, FLS_CODE ) FLS_SDK_Erase \
( \
    VAR( uint16, AUTOMATIC) u16Fls_FlashBlock, \
    VAR( uint32, AUTOMATIC) u32Fls_Index, \
    VAR( uint16, AUTOMATIC ) bFls_Mode \
);

FUNC( status_t, FLS_CODE ) FLS_SDK_Read  \
( \
    VAR( uint32, AUTOMATIC) u32Fls_dest, \
    VAR( uint32, AUTOMATIC) u32Fls_size,  \
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pDataPtr
);

FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_CheckProgramStatus \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData, \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pFls_OpRet \
);

FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Program \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData \
);

FUNC(status_t, FLS_CODE) FLASH_SDK_LLD_Abort(void);

FUNC( status_t, FLS_CODE ) FLASH_LLD_BlankCheck \
( \
    VAR( uint32, AUTOMATIC) u32Fls_Dest, \
    VAR( uint32, AUTOMATIC) u32Fls_Size, \
    VAR( uint32, AUTOMATIC) u32Fls_CheckWordSize, \
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_FailAddr \
);

FUNC( status_t, FLS_CODE ) FLASH_LLD_ProgramVerify \
( \
    VAR( uint32, AUTOMATIC) u32Fls_Dest, \
    VAR( uint32, AUTOMATIC) u32Fls_Size, \
    VAR( uint32, AUTOMATIC) u32Fls_Src, \
    VAR( uint32, AUTOMATIC) u32Fls_CheckWordSize, \
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_FailAddr \
);

FUNC( status_t, FLS_CODE ) Fls_LLD_Cancel \
( \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) u8Fls_SusStatus \
);



/*
 * @brief Enable flash command complete interrupt.
 *
 * This function will enable flash command complete interrupt.
 */
FUNC( void, FLS_CODE ) FLASH_LLD_EnableCmdCompleteInterupt(void);

/*
 * @brief Disable flash command complete interrupt.
 *
 * This function will disable flash command complete interrupt.
 *
 */
FUNC( void, FLS_CODE ) FLASH_LLD_DisableCmdCompleteInterupt(void);

/*
 * @brief Flash command complete interrupt handle function.
 *
 * The interrupt handle function for flash command complete interrupt.
 *
 */
FUNC( void, FLS_CODE ) FLASH_Cmd_Done_ISR(void);

#ifdef RESOURCE_SUPPORT_PFI0

FUNC( void, FLS_CODE ) FLASH_PFI0_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI0
#ifdef RESOURCE_SUPPORT_PFI1
FUNC( void, FLS_CODE ) FLASH_PFI1_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI1
#ifdef RESOURCE_SUPPORT_PFI2
FUNC( void, FLS_CODE ) FLASH_PFI2_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI2
#ifdef RESOURCE_SUPPORT_PFI3
FUNC( void, FLS_CODE ) FLASH_PFI3_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI3
#ifdef RESOURCE_SUPPORT_PFI4
FUNC( void, FLS_CODE ) FLASH_PFI4_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI4
#ifdef RESOURCE_SUPPORT_PFI5
FUNC( void, FLS_CODE ) FLASH_PFI5_Cmd_Done_ISR(void);
#endif // CCFC3012PT



#ifdef CCFC3012PT
 FUNC( status_t, FLS_CODE ) FLS_LLD_Get_FLS_EHV_Val
(
    volatile struct C55FMC_tag *fmc,
    uint8_t **ehv_val
);
#endif

 void cc_memset(uint8_t *dest, const uint8_t val, const uint32_t bytes);

#if defined(__cplusplus)
}
#endif
#endif /* FLS_LLDRIVER_H */
