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
*   @file    Fls_ac.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


#include "Fls.h"

#define FLS_AC_WRA_C_VENDOR_ID                     176
#define FLS_AC_WRA_C_AR_REL_MAJOR_VER              4
#define FLS_AC_WRA_C_AR_REL_MINOR_VER              4
#define FLS_AC_WRA_C_AR_REL_REV_VER                0
#define FLS_AC_WRA_C_SW_MAJOR_VER                  1
#define FLS_AC_WRA_C_SW_MINOR_VER                  0
#define FLS_AC_WRA_C_SW_PATCH_VER                  1

#if (FLS_VENDOR_ID_OUTPUT != FLS_AC_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_VENDOR_ID "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_AC_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_AC_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_AR_REL_MINOR_VER "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_AC_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_AC_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_AC_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_AC_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_SW_PATCH_VER "
#endif

#ifdef CCFC3012PT
extern volatile struct C55FMC_tag *FLS_CurC55FMC;
extern volatile struct T40FMC_tag *FLS_CurT40FMC;
#endif

/* Specification of Flash Driver : [SWS_Fls_00137] */
/* Specification of Flash Driver : [SWS_Fls_00215] */
/* Specification of Flash Driver : [SWS_Fls_00211] */


#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
#ifndef CCFC3012PT
FUNC( void, FLS_CODE ) FLS_AccessCode \
( \
    P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC \
);
#else
FUNC( void, FLS_CODE ) FLS_AccessCode
(
		P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC ,
		volatile struct C55FMC_tag *fmc
);
#endif // CCFC3012PT
#else
#ifndef CCFC3012PT
FUNC( void, FLS_CODE ) FLS_AccessCode(void);
#else
FUNC( void, FLS_CODE ) FLS_AccessCode(volatile struct C55FMC_tag *fmc);
#endif // CCFC3012PT
#endif /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */


/*****************************************************************************
** Service Name      : Fls_AccessCode                                              
** 
** 
**  Description      : Initializes the FLASH module                         
**                                                                            
**  Parameters (in)  : lockBlk: Indicating the lock status of flash module.
**                     pFls_TimerCounterAC: Time counting pointer
**                                          (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)                          
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                  
**                                                                            
******************************************************************************/
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
#ifndef CCFC3012PT
FUNC( void, FLS_CODE ) FLS_AccessCode \
( \
    P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC \
)
{

    /* Set MCR EHV bit, start operation */
    FLS_FMC.MCR.B.EHV = 1U;

    /* Wait MCR DONE bit is set */
    while ((FLS_FMC.MCR.B.DONE == 0x0U) && (0U < *pFls_TimerCounterAC))
    {
        (*pFls_TimerCounterAC)--;
    }
}
#else
FUNC( void, FLS_CODE ) FLS_AccessCode
(
		P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC ,
		volatile struct C55FMC_tag *fmc
)
{
    /* Set MCR EHV bit, start operation */
    fmc->MCR.B.EHV = 1U;

    /* Wait MCR DONE bit is set */
    while ((fmc->MCR.B.DONE == 0x0U) && (0U < *pFls_TimerCounterAC))
    {
		(*pFls_TimerCounterAC)--;
    }
}
   
#endif // CCFC3012PT

#else
/*
 * @brief Initializes the FLASH module
 *
 * This function will initialize flash module.
 *
 * @param[in] lockBlk: Indicating the lock status of flash module.
 * @return Operation status
 */
#ifndef CCFC3012PT
FUNC( void, FLS_CODE ) FLS_AccessCode(void)
{

    /* Set MCR EHV bit, start operation */
    FLS_FMC.MCR.B.EHV = 1U;

    /* Wait MCR DONE bit is set */
    while (FLS_FMC.MCR.B.DONE == 0x0U)
    {
  
    }
}
#else
FUNC( void, FLS_CODE ) FLS_AccessCode(volatile struct C55FMC_tag *fmc)
{
    /* Set MCR EHV bit, start operation */
    fmc->MCR.B.EHV = 1U;

    /* Wait MCR DONE bit is set */
    while (fmc->MCR.B.DONE == 0x0U)
    {
    }
}
#endif // CCFC3012PT


#endif /* FLS_TIMEOUT_HANDLING == STD_ON */


#ifdef __cplusplus
}
#endif
