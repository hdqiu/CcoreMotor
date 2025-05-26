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
*   @file    Mcu_LLDriver.c
*   @version 1.0.1
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "devassert.h"
#include "Mcu_LLDriver.h"
#if (MCU_HARDVER == 3)
#include "libSwap.h"
#endif
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif
/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define MCU_LLD_VENDOR_ID_C                     176
#define MCU_LLD_AR_MAJOR_VER_C                  4
#define MCU_LLD_AR_MINOR_VER_C                  4
#define MCU_LLD_AR_PATCH_VER_C                  0
#define MCU_LLD_SW_MAJOR_VER_C                  1
#define MCU_LLD_SW_MINOR_VER_C                  0
#define MCU_LLD_SW_PATCH_VER_C                  1
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_LLD_VENDOR_ID != MCU_LLD_VENDOR_ID_C)
#error "NON-MATCHED DATA : MCU_LLD_VENDOR_ID_C"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_LLD_AR_MAJOR_VER != MCU_LLD_AR_MAJOR_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_AR_MAJOR_VER_C"
#endif
#if (MCU_LLD_AR_MINOR_VER != MCU_LLD_AR_MINOR_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_AR_MINOR_VER_C"
#endif
#if (MCU_LLD_AR_PATCH_VER != MCU_LLD_AR_PATCH_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_AR_PATCH_VER_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_LLD_SW_MAJOR_VER != MCU_LLD_SW_MAJOR_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_SW_MAJOR_VER_C"
#endif
#if (MCU_LLD_SW_MINOR_VER != MCU_LLD_SW_MINOR_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_SW_MINOR_VER_C"
#endif
#if (MCU_LLD_SW_PATCH_VER != MCU_LLD_SW_PATCH_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_SW_PATCH_VER_C"
#endif

#define MCU_START_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"
volatile VAR(Mcu_CoreStatusType, MCU_VAR) Mcu_gCoreStatus[MCU_CORE_COUNT];
volatile VAR(Mcu_CoreStatusType, MCU_VAR) Mcu_gCoreStatus[MCU_CORE_COUNT] = {0U};
#define MCU_STOP_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"
volatile VAR(uint32, MCU_VAR) Mcu_ReasonReg[2U];
volatile VAR(uint32, MCU_VAR) Mcu_ReasonReg[2U] = {0U};
#define MCU_STOP_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"
#define MCU_START_SEC_VAR_INIT
#include "Mcu_MemMap.h"

extern P2CONST(Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_gConfigPtr;
extern P2CONST(Mcu_ClockConfigType, MCU_VAR, MCU_APPL_DATA) Mcu_gClockConfigPtr;
extern VAR(Mcu_Rgm_ResetType, MCU_VAR) Mcu_gRgmConfiguration;

#if MCU_FCCU_ENABLE == STD_ON
static P2CONST(Mcu_FccuConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_gFccuConfigPtr = NULL_PTR;
#endif

#if (MCU_HARDVER == 3)
extern VAR( uint8_t, AUTOMATIC) g_swapStatus;
#endif
#define MCU_STOP_SEC_VAR_INIT
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/*******************************************************************************
 * @brief      Get current core id
 * @param[in]  None
 * @param[out] None
 * @retval     Mcu_CoreType
 * @notapi
 *******************************************************************************/
FUNC(Mcu_CoreType, MCU_CODE) Mcu_LLD_Get_Core_Id(void)
{
    return (Mcu_CoreType)MFSPR(SPR_PIR); /* PRQA S 0342, 1006, 4342 */
}

/*******************************************************************************
 * @brief      Launch specified core
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
static FUNC(void, MCU_CODE) Mcu_LLD_Launch_Core \
( \
    P2VAR(MC_ME_Type, AUTOMATIC, MCU_APPL_DATA) pMcu_Base, \
    P2CONST(Mcu_CoreConfigType, AUTOMATIC, MCU_APPL_DATA) Mcu_CoreMode_ptr \
)
{
    pMcu_Base->CCTL0.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl0_Config;
    pMcu_Base->CCTL1.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl1_Config;
    pMcu_Base->CCTL2.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl2_Config;
    pMcu_Base->CCTL3.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl3_Config;
    pMcu_Base->CCTL4.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl4_Config;
    #if (MCU_HARDVER == 5)
    pMcu_Base->CCTL6.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl6_Config;
    pMcu_Base->CCTL7.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl7_Config;
    pMcu_Base->CCTL8.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl8_Config;
    pMcu_Base->CCTL9.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl9_Config;
    pMcu_Base->CCTL10.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl10_Config;
    pMcu_Base->CCTL11.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl11_Config;
    #endif
    pMcu_Base->CADDR0.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr0_Config;
    pMcu_Base->CADDR1.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr1_Config;
    pMcu_Base->CADDR2.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr2_Config;
    pMcu_Base->CADDR3.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr3_Config;
    pMcu_Base->CADDR4.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr4_Config;
    #if (MCU_HARDVER == 5)
    pMcu_Base->CADDR6.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr6_Config;
    pMcu_Base->CADDR7.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr7_Config;
    pMcu_Base->CADDR8.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr8_Config;
    pMcu_Base->CADDR9.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr9_Config;
    pMcu_Base->CADDR10.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr10_Config;
    pMcu_Base->CADDR11.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr11_Config;
    #endif
}


/*!
 * @brief Enables clock sources from MC_ME
 *
 * This function enables/disables all clock sources from MC_ME
 *
 * @param[in] Mcu_SysClk Destination mode.
 * @param[in] Mcu_IrcEn   First IRCOSC clock source.
 * @param[in] Mcu_XoscEn  First XOSC clock source.
 * @param[in] Mcu_Pll0En   First PLL clock source.
 * @param[in] Mcu_Pll1En   Second PLL clock source.
 * @param[in] Mcu_ModeReg  register to be read/written
 */
LOCAL_INLINE FUNC(void, MCU_CODE) MC_ME_SetClockSources
(
    VAR(uint8, AUTOMATIC) Mcu_SysClk, \
    VAR(uint8, AUTOMATIC) Mcu_IrcEn, \
    VAR(uint8, AUTOMATIC) Mcu_XoscEn, \
    VAR(uint8, AUTOMATIC) Mcu_Pll0En, \
    VAR(uint8, AUTOMATIC) Mcu_Pll1En, \
    volatile P2VAR(uint32, AUTOMATIC, MCU_APPL_DATA) Mcu_ModeReg \
)
{
    VAR(uint32, MCU_VAR) regValue = *Mcu_ModeReg;

    regValue &= ~(MC_ME_GS_S_SYSCLK_MASK);
    regValue |= (Mcu_SysClk & MC_ME_GS_S_SYSCLK_MASK);

    if(Mcu_IrcEn == TRUE)
    {
        regValue |= MC_ME_GS_S_IRC(1U);
    }
    else
    {
        regValue &= ~MC_ME_GS_S_IRC(1U);
    }

    if(Mcu_XoscEn == TRUE)
    {
        regValue |= MC_ME_GS_S_XOSC(1U);
    }
    else
    {
        regValue &= ~MC_ME_GS_S_XOSC(1U);
    }

    if(Mcu_Pll0En == TRUE)
    {
        regValue |= MC_ME_GS_S_PLL0(1U);
    }
    else
    {
        regValue &= ~MC_ME_GS_S_PLL0(1U);
    }

    if(Mcu_Pll1En == TRUE)
    {
        regValue |= MC_ME_GS_S_PLL1(1U);
    }
    else
    {
        regValue &= ~MC_ME_GS_S_PLL1(1U);
    }

    *Mcu_ModeReg = regValue;
}

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_SetIrc
 * Description   : Configures IRC clock source
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_LLD_SetIrc \
( \
    P2CONST(Mcu_IrcConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_IrcConfigPtr \
)
{
    IRCOSC_StPtr->CTL.R = Mcu_IrcConfigPtr->Mcu_FircCfg;
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    IRCOSC_StPtr->SCTL.R = Mcu_IrcConfigPtr->Mcu_SircCfg;
    #endif
}

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_SetXosc
 * Description   : Configures XOSC clock source
 *END**************************************************************************/
static FUNC(void, MCU_CODE) Mcu_LLD_SetXosc \
( \
    P2CONST(Mcu_XoscConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_XoscConfig \
)
{
    if(pMcu_XoscConfig->bypassOption != XOSC_USE_CRYSTAL)
    {
    	XOSC_StPtr->CTL.B.OSCBYP = 1U;
    }
    else
    {
    	XOSC_StPtr->CTL.B.OSCBYP = 0U;
    }

    if(pMcu_XoscConfig->Mcu_xoscInterruptEn == TRUE)
    {
    	XOSC_StPtr->CTL.B.I_OSC = 1U;
        XOSC_StPtr->CTL.B.M_OSC = 1U;
    }
    else
    {
    	XOSC_StPtr->CTL.B.M_OSC = 0U;
    }

    XOSC_StPtr->CTL.B.EOCV = (uint32)pMcu_XoscConfig->startupDelay;
}


/*!
 * @brief Sets PLL Divider Register
 *
 * This function sets PLL Divider Register
 *
 * @param[in] pMcu_Base             Register pMcu_Base address for the PLLDIG u32Mcu_Instance.
 * @param[in] u32Mcu_Instance         Instance number
 * @param[in] u32Mcu_Phi0Divider      first output u32Mcu_Divider
 * @param[in] u32Mcu_Phi1Divider      second output u32Mcu_Divider
 * @param[in] u32Mcu_Predivider       Predivider
 * @param[in] u32Mcu_MulFactorDiv     Multiplier factor u32Mcu_Divider
 */
LOCAL_INLINE FUNC(void, MCU_CODE) CGMCS_PLLDivider \
( \
    P2VAR(PLLDIG_Type, AUTOMATIC, MCU_APPL_DATA) pMcu_Base, \
    VAR(uint32, AUTOMATIC) u32Mcu_Instance, \
    VAR(uint32, AUTOMATIC) u32Mcu_Phi0Divider, \
    VAR(uint32, AUTOMATIC) u32Mcu_Phi1Divider, \
    VAR(uint32, AUTOMATIC) u32Mcu_Predivider, \
    VAR(uint32, AUTOMATIC) u32Mcu_MulFactorDiv \
)
{
    /* Configure u32Mcu_Divider */
    if(u32Mcu_Instance == (uint32)0U)
    {
        pMcu_Base->PLL0DV.B.RFDPHI = u32Mcu_Phi0Divider;
        pMcu_Base->PLL0DV.B.RFDPHI1 = u32Mcu_Phi1Divider;
        pMcu_Base->PLL0DV.B.PREDIV = u32Mcu_Predivider;
        pMcu_Base->PLL0DV.B.MFD = u32Mcu_MulFactorDiv;
    }
    else 
    {
        pMcu_Base->PLL1DV.B.RFDPHI = u32Mcu_Phi0Divider;
        pMcu_Base->PLL1DV.B.MFD = u32Mcu_MulFactorDiv;
    }
}

/*!
 * @brief Sets PLL Fractional Divider
 *
 * This function sets PLL Fractional Divider
 *
 * @param[in] pMcu_Base              Register pMcu_Base address for the PLLDIG u32Mcu_Instance.
 * @param[in] bMcu_Enable            Enable fractional loop u32Mcu_Divider
 * @param[in] u32Mcu_FracDivider       Fractional loop u32Mcu_Divider value
 */
static FUNC(void, MCU_CODE) CGMCS_SetPLLFractionalDivider \
( \
    P2VAR(PLLDIG_Type, AUTOMATIC, MCU_APPL_DATA) pMcu_Base, \
    VAR(uint8, AUTOMATIC) bMcu_Enable, \
    VAR(uint32, AUTOMATIC) u32Mcu_FracDivider \
)
{
    pMcu_Base->PLL1FD.B.FDEN = ((bMcu_Enable == TRUE) ? 1UL : 0UL);
    pMcu_Base->PLL1FD.B.FRCDIV = u32Mcu_FracDivider;
}

/*!
 * @brief Configures PLL Modulation
 *
 * This function sets PLL Modulation
 *
 * @param[in] pMcu_Base              Register pMcu_Base address for the PLLDIG u32Mcu_Instance.
 * @param[in] bMcu_Enable            Enable fractional loop u32Mcu_Divider
 * @param[in] u32Mcu_FracDivider       Fractional loop u32Mcu_Divider value
 */
LOCAL_INLINE FUNC(void, MCU_CODE) CGMCS_ConfigurePllModulation \
( \
    P2VAR(PLLDIG_Type, AUTOMATIC, MCU_APPL_DATA) pMcu_Base, \
    VAR(uint8, AUTOMATIC) bMcu_Enable, \
    VAR(uint32, AUTOMATIC) u32Mcu_ModulationType, \
    VAR(uint32, AUTOMATIC) u32Mcu_ModulationPeriod, \
    VAR(uint32, AUTOMATIC) u32Mcu_IncrementStep \
)
{
    if(bMcu_Enable == TRUE)
    {
        pMcu_Base->PLL1FM.B.MODEN = 1UL;
        PLLDIG.PLL_CFG1 = 0xFFFFFFF2UL;
    }
    else
    {
        pMcu_Base->PLL1FM.B.MODEN = 0UL;
    }
    pMcu_Base->PLL1FM.B.MODSEL = u32Mcu_ModulationType;
    pMcu_Base->PLL1FM.B.MODPRD = u32Mcu_ModulationPeriod;
    pMcu_Base->PLL1FM.B.INCSTP = u32Mcu_IncrementStep;
}
/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_SetPll
 * Description   : Configures ARM PLL clock source
 *END**************************************************************************/
static FUNC(void, MCU_CODE) Mcu_LLD_SetPll \
( \
    P2CONST(Mcu_PlldigConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_Config, \
    P2CONST(Mcu_CgmConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_CgmConfig, \
    VAR(uint32, AUTOMATIC) u32Mcu_Instance \
)
{
    VAR(uint32, MCU_VAR) u32Mcu_Phi0Divider = 0U;
    VAR(uint32, MCU_VAR) u32Mcu_Phi1Divider = 0U;

    switch (u32Mcu_Instance)
    {
        case 0U:
        {
        	MC_CGM_StPtr->AC3_SC.R = pMcu_CgmConfig->ac3_sc;
            break;
        }
        case 1U:
        {
        	MC_CGM_StPtr->AC4_SC.R = pMcu_CgmConfig->ac4_sc;
            break;
        }
        default:
        {    
            /* Invalid PLL u32Mcu_Instance */
            break;
        }
    }

    u32Mcu_Phi0Divider = ((uint32)pMcu_Config->phi0Divider);
    u32Mcu_Phi1Divider = ((uint32)pMcu_Config->phi1Divider);

    /* Configure PLL */
    CGMCS_PLLDivider
    (
        PLLDIG_StPtr, \
        u32Mcu_Instance, \
        u32Mcu_Phi0Divider, \
        u32Mcu_Phi1Divider, \
        (uint32)pMcu_Config->predivider, \
        (uint32)pMcu_Config->mulFactorDiv \
    );

    if (u32Mcu_Instance == 1U)
    {
        /* Write FRCDIV - fractional u32Mcu_Divider. */
        CGMCS_SetPLLFractionalDivider \
        ( \
            PLLDIG_StPtr, \
            pMcu_Config->fracDivider, \
            pMcu_Config->fracDividerValue \
        );

        /* Configure modulation */
        CGMCS_ConfigurePllModulation \
        ( \
            PLLDIG_StPtr, pMcu_Config->modulation, (uint32)pMcu_Config->modulationType, \
            pMcu_Config->modulationPeriod, pMcu_Config->incrementStep \
        );
    }
}

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_ConfigureSystemClockDividers
 * Description   : Configures system clocks
 *END**************************************************************************/
static FUNC(void, MCU_CODE) Mcu_LLD_ConfigureSystemClockDividers \
( \
    P2CONST(Mcu_CgmConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_Config \
)
{
    /*! System clock u32Mcu_Divider ratios will change with next update.
     *  Not required for Cut 1.*/
    MC_CGM_StPtr->SC_DIV_RC.R = 0x00000001UL;
    /*! System clock u32Mcu_Divider ratios updated on writing MC_CGM_StPtr->DIV_UPD_TRIG.
     * Not required for Cut 1. */
    MC_CGM_StPtr->DIV_UPD_TYPE.R = 0x80000000UL;

    VAR(uint32, MCU_VAR)Mcu_Timeout;
    /* First system clock u32Mcu_Divider */
    MC_CGM_StPtr->SC_DC0.R = pMcu_Config->sc_dc0;
    MC_CGM_StPtr->SC_DC1.R = pMcu_Config->sc_dc1;
    MC_CGM_StPtr->SC_DC2.R = pMcu_Config->sc_dc2;
    MC_CGM_StPtr->SC_DC3.R = pMcu_Config->sc_dc3;
    MC_CGM_StPtr->SC_DC4.R = pMcu_Config->sc_dc4;
 // ! System clock u32Mcu_Divider ratio updates triggered.  Not required for Cut 1.
    MC_CGM_StPtr->DIV_UPD_TRIG.R = 0xfeedfaceUL;
 // ! Wait for System Clock Divider Update Status == 0. Not required for Cut 1.
    Mcu_Timeout = 0U;
    while ((MC_CGM_StPtr->DIV_UPD_STAT.B.SYS_UPD_STAT == 1U) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS))
    {
        Mcu_Timeout++;
    }
}

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_ConfigureAuxiliarySelectorsAndDividers
 * Description   : Configures auxiliary clocks
 *END**************************************************************************/
static FUNC(void, MCU_CODE) Mcu_LLD_ConfigureAuxiliarySelectorsAndDividers \
( \
    P2CONST(Mcu_CgmConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_Config \
)
{
	MC_CGM_StPtr->AC0_SC.R  = pMcu_Config->ac0_sc;
	MC_CGM_StPtr->AC0_DC0.R = pMcu_Config->ac0_dc0;
	MC_CGM_StPtr->AC0_DC1.R = pMcu_Config->ac0_dc1;
	MC_CGM_StPtr->AC0_DC2.R = pMcu_Config->ac0_dc2;
	MC_CGM_StPtr->AC0_DC3.R = pMcu_Config->ac0_dc3;
	MC_CGM_StPtr->AC0_DC4.R = pMcu_Config->ac0_dc4;

	MC_CGM_StPtr->AC1_SC.R  = pMcu_Config->ac1_sc;
	MC_CGM_StPtr->AC1_DC0.R = pMcu_Config->ac1_dc0;

	MC_CGM_StPtr->AC2_DC0.R = pMcu_Config->ac2_dc0;
	MC_CGM_StPtr->AC2_DC1.R = pMcu_Config->ac2_dc1;
#if (MCU_HARDVER == 5)
	MC_CGM_StPtr->AC2_DC2.R = pMcu_Config->ac2_dc2;
#endif

	MC_CGM_StPtr->AC5_DC0.R = pMcu_Config->ac5_dc0;
	MC_CGM_StPtr->AC5_DC1.R = pMcu_Config->ac5_dc1;
	MC_CGM_StPtr->AC5_DC2.R = pMcu_Config->ac5_dc2;

	MC_CGM_StPtr->AC5_CDC0.R = pMcu_Config->ac5_cdc0;
	MC_CGM_StPtr->AC5_CDC1.R = pMcu_Config->ac5_cdc1;
	MC_CGM_StPtr->AC5_CDC2.R = pMcu_Config->ac5_cdc2;

	MC_CGM_StPtr->AC5_CDC10.R = pMcu_Config->ac5_cdc10;
	MC_CGM_StPtr->AC5_CDC11.R = pMcu_Config->ac5_cdc11;
	MC_CGM_StPtr->AC5_CDC12.R = pMcu_Config->ac5_cdc12;
	MC_CGM_StPtr->AC5_CDC13.R = pMcu_Config->ac5_cdc13;

	MC_CGM_StPtr->AC5_CDC20.R = pMcu_Config->ac5_cdc20;
	MC_CGM_StPtr->AC5_CDC21.R = pMcu_Config->ac5_cdc21;
	MC_CGM_StPtr->AC5_CDC22.R = pMcu_Config->ac5_cdc22;
	MC_CGM_StPtr->AC5_CDC23.R = pMcu_Config->ac5_cdc23;

	MC_CGM_StPtr->AC6_SC.R  = pMcu_Config->ac6_sc;
	MC_CGM_StPtr->AC6_DC0.R = pMcu_Config->ac6_dc0;

	MC_CGM_StPtr->AC7_SC.R  = pMcu_Config->ac7_sc;
	MC_CGM_StPtr->AC7_DC0.R = pMcu_Config->ac7_dc0;

	MC_CGM_StPtr->AC8_SC.R  = pMcu_Config->ac8_sc;
	MC_CGM_StPtr->AC8_DC0.R = pMcu_Config->ac8_dc0;

	MC_CGM_StPtr->AC9_SC.R  = pMcu_Config->ac9_sc;
	MC_CGM_StPtr->AC9_DC0.R = pMcu_Config->ac9_dc0;

	MC_CGM_StPtr->AC10_SC.R  = pMcu_Config->ac10_sc;
	MC_CGM_StPtr->AC10_DC0.R = pMcu_Config->ac10_dc0;

    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
	MC_CGM_StPtr->AC11_SC.R  = pMcu_Config->ac11_sc;
	MC_CGM_StPtr->AC11_DC0.R = pMcu_Config->ac11_dc0;
    #endif
	#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
	MC_CGM_StPtr->AC12_SC.R  = pMcu_Config->ac12_sc;
    #endif
	#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
	MC_CGM_StPtr->AC12_DC0.R  = pMcu_Config->ac12_dc0;
	#endif
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
	MC_CGM_StPtr->AC12_DC1.R  = pMcu_Config->ac12_dc1;
    #endif
	#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
	MC_CGM_StPtr->AC12_DC2.R  = pMcu_Config->ac12_dc2;
	#endif
}

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_ConfigureCgmcs
 * Description   : Configures clock sources
 *END**************************************************************************/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_ConfigureCgmcs \
( \
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_Config \
)
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    if(pMcu_Config == NULL_PTR)
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        Mcu_LLD_SetIrc(&pMcu_Config->cgmcsConfig.ircConfig);

        Mcu_LLD_SetXosc(&pMcu_Config->cgmcsConfig.xosc0Config);

        Mcu_LLD_SetPll(&pMcu_Config->cgmcsConfig.pll0Config, &pMcu_Config->cgmConfig, 0U);

        Mcu_LLD_SetPll(&pMcu_Config->cgmcsConfig.pll1Config, &pMcu_Config->cgmConfig, 1U);
    }
    return Mcu_RetVal;
}

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_ConfigureCgm
 * Description   : Configures clock generation module
 *END**************************************************************************/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_ConfigureCgm \
( \
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_Config \
)
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    if(pMcu_Config == NULL_PTR)
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Configure system dividers */
        Mcu_LLD_ConfigureSystemClockDividers(&pMcu_Config->cgmConfig);

        /* Configure auxiliary u32Mcu_Selector and dividers */
        Mcu_LLD_ConfigureAuxiliarySelectorsAndDividers(&pMcu_Config->cgmConfig);
    }
    return Mcu_RetVal;
}

/*!
 * @brief Enables clock sources from MC_ME
 *
 * This function enables/disables all clock sources from MC_ME
 * @param[in] ModeEnable  register to be MC_ME.ME
 */
LOCAL_INLINE FUNC(void, MCU_CODE) MC_ME_SetModeEnable ( VAR(uint32, AUTOMATIC) ModeEnable )
{
    MC_ME_StPtr->ME.R = ModeEnable;
}

/*!
 * @brief Set run periheral configuration
 *
 * This function sets run periheral configuration
 *
 * @param[in]   RunModeConfig 
 */
LOCAL_INLINE FUNC(void, MCU_CODE) MC_ME_SetRunPeripheralConfig ( VAR(uint32, AUTOMATIC) RunIdx,
                                                                 VAR(uint32, AUTOMATIC) RunModeConfig )
{
    MC_ME_StPtr->RUN_PC[RunIdx].R = RunModeConfig;
}

/*!
 * @brief Set low periheral configuration
 *
 * This function sets low periheral configuration
 *
 * @param[in]   LpModeConfig
 */
LOCAL_INLINE FUNC(void, MCU_CODE) MC_ME_SetLowPeripheralConfig ( VAR(uint32, AUTOMATIC) RunIdx,
                                                                 VAR(uint32, AUTOMATIC) LpModeConfig )
{
    MC_ME_StPtr->LP_PC[RunIdx].R = LpModeConfig;
}

/*!
* @brief Sets Peripheral clock control register
*
* @param[in] pMcu_Base             mc_me pMcu_Base pointer
* @param[in] eMcu_McMePeriNameConfig        clock name
* @param[in] u8Mcu_RunConfigIndex   running configuration index
* @param[in] u8Mcu_LowConfigIndex   low configuration index
*/
#if 0
LOCAL_INLINE FUNC(void, MCU_CODE) MC_ME_SetPeripheralClockControl \
( \
    P2VAR(MC_ME_Type, AUTOMATIC, MCU_APPL_DATA) pMcu_Base, \
    VAR(Mcu_McMePeriNameType, AUTOMATIC) eMcu_PeripheralName, \
    VAR(uint8, AUTOMATIC) u8Mcu_RunConfigIndex, \
    VAR(uint8, AUTOMATIC) u8Mcu_LowConfigIndex \
)
{
   /* Configure the low and run configurations */
   if (eMcu_PeripheralName != MC_ME_INVALID_INDEX)
   {
       pMcu_Base->PCTL[eMcu_PeripheralName].R \
           = (uint8)((MC_ME_PCTLn_RUN_CFG(u8Mcu_RunConfigIndex) | MC_ME_PCTLn_LP_CFG(u8Mcu_LowConfigIndex)));
   }
}
#endif

LOCAL_INLINE FUNC(void, MCU_CODE) MC_ME_ChangeSysClk( P2VAR(MC_ME_Type, AUTOMATIC, MCU_APPL_DATA) Mcu_McmePtr, \
                                                                VAR(Mcu_CgmClkSelType, AUTOMATIC) Mcu_ClkSel )
{
    switch ((Mcu_McModeType)(Mcu_McmePtr->GS.B.S_CURRENT_MODE))
    {
        case me_mc_drun_mode:
        {
            Mcu_McmePtr->DRUN_MC.B.SYSCLK = (uint32) Mcu_ClkSel;
            break;
        }
        case me_mc_run0_mode:
        {
            Mcu_McmePtr->RUN_MC[0].B.SYSCLK = (uint32) Mcu_ClkSel;
            break;
        }
        case me_mc_run1_mode:
        {
            Mcu_McmePtr->RUN_MC[1].B.SYSCLK = (uint32) Mcu_ClkSel;
            break;
        }
        case me_mc_run2_mode:
        {
            Mcu_McmePtr->RUN_MC[2].B.SYSCLK = (uint32) Mcu_ClkSel;
            break;
        }
        case me_mc_run3_mode:
        {
            Mcu_McmePtr->RUN_MC[3].B.SYSCLK = (uint32) Mcu_ClkSel;
            break;
        }
        case me_mc_halt0_mode:
        {
            Mcu_McmePtr->HALT0_MC.B.SYSCLK = (uint32) Mcu_ClkSel;
            break;
        }
        default:
        {
            /* Do nothing */
            break;
        }
    }
}

/*!
 * @brief MC_ME mode change.
 *
 * This function is changing mode in MC_ME module
 *
 * @param[in] Mcu_McmePtr Register Mcu_McmePtr address for the MC_ME u32Mcu_Instance.
 * @param[in] Mcu_TargetMode Destination mode.
 */
LOCAL_INLINE FUNC(Std_ReturnType, MCU_CODE) MC_ME_ChangeMode( P2VAR(MC_ME_Type, AUTOMATIC, MCU_APPL_DATA) Mcu_McmePtr, \
                                                              VAR(Mcu_McModeType, AUTOMATIC) Mcu_TargetMode )
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    VAR(uint32, MCU_VAR) Mcu_CurrentMode = 0;
    VAR(uint32, MCU_VAR) Mcu_Timeout = 0;

    if (Mcu_TargetMode != me_mc_mode_notchange)
    {
         Mcu_CurrentMode = (uint32)Mcu_TargetMode;
    }
    else
    {
        Mcu_CurrentMode = Mcu_McmePtr->GS.B.S_CURRENT_MODE;
    }

    /* Change takes effect after mode transition. */
    Mcu_McmePtr->MCTL.R = MC_ME_MCTL_TARGET_MODE(Mcu_CurrentMode) \
                        | MC_ME_MCTL_KEY(FEATURE_MC_ME_KEY);
    Mcu_McmePtr->MCTL.R = MC_ME_MCTL_TARGET_MODE(Mcu_CurrentMode) \
                        | MC_ME_MCTL_KEY(FEATURE_MC_ME_KEY_INV);

    while ((Mcu_McmePtr->GS.B.S_MTRANS == 1U) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS))
    {
        Mcu_Timeout++;
    } //  Wait for mode transition to complete
    if(Mcu_Timeout >= MCU_TIMEOUT_LOOPS)
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return Mcu_RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_ChangeMode(VAR(Mcu_McModeType, AUTOMATIC) Mcu_TargetMode)
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    VAR(uint8, MCU_VAR) Mcu_Loop = 0U;
    for(Mcu_Loop = 0U; Mcu_Loop < 3U; Mcu_Loop++)
    {
        Mcu_RetVal = MC_ME_ChangeMode(MC_ME_StPtr, Mcu_TargetMode);
        if(Mcu_RetVal != E_OK)
        {
            Mcu_RetVal = MC_ME_ChangeMode(MC_ME_StPtr, me_mc_safe_mode);
            if(Mcu_RetVal != E_OK)
            {
                break;
            }
            else
            {
                /* Do Nothing */
            }
            Mcu_RetVal = MC_ME_ChangeMode(MC_ME_StPtr, me_mc_drun_mode);
            if(Mcu_RetVal != E_OK)
            {
                break;
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            break;
        }
    }

    if(Mcu_RetVal != E_OK)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuFailOfChangeModeNotification != NULL_PTR)
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuFailOfChangeModeNotification();
        }
    }
    else
    {
        /* Do Nothing */
    }

    return Mcu_RetVal;
}


static FUNC(void, MCU_CODE) Mcu_LLD_ClockPCS_Init(void)
{
    VAR(uint32, MCU_VAR) Mcu_PWRLVL;
    if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_drun_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->DRUN_MC.B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->DRUN_MC.B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_safe_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->SAFE_MC.B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->SAFE_MC.B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_run0_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->RUN_MC[0U].B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->RUN_MC[0U].B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_run1_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->RUN_MC[1U].B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->RUN_MC[1U].B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_run2_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->RUN_MC[2U].B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->RUN_MC[2U].B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_run3_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->RUN_MC[3U].B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->RUN_MC[3U].B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_halt0_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->HALT0_MC.B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->HALT0_MC.B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE ==(uint32) me_mc_stop0_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->STOP0_MC.B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->STOP0_MC.B.PWRLVL = Mcu_PWRLVL;
    }
    else
    {
        /* Do nothing */
    }

    MC_CGM_StPtr->PCS_SDUR.R = 16U;

    MC_CGM_StPtr->PCS_DIVC1.R = 0x03E70008U;
    MC_CGM_StPtr->PCS_DIVE1.R = 0x000004E1U;

    MC_CGM_StPtr->PCS_DIVC2.R = 0x03E70008U;
    MC_CGM_StPtr->PCS_DIVE2.R = 0x00001869U;

    MC_CGM_StPtr->PCS_DIVC4.R = 0x0294000CU;
    MC_CGM_StPtr->PCS_DIVE4.R = 0x0000493DU;
    MC_CGM_StPtr->PCS_DIVS4.R = 0x00004C17U;
}


/*!
 * @brief Resets configuration of clock sources in MC_ME_StPtr->
 *
 * Resets configuration of clock sources in MC_ME_StPtr-> Enables IRC type clock sources and sets an IRC type clock source as system clock in all modes.
 *
 * @param[in] pMcu_Base   Register pMcu_Base address for the MC_ME u32Mcu_Instance.
 * @param[in] Mcu_SysClk Destination mode. */
static FUNC(void, MCU_CODE) MC_ME_ResetClockSourcesConfiguration \
( \
    P2VAR(MC_ME_Type, AUTOMATIC, MCU_APPL_DATA) pMcu_Base \
)
{
#if 0
   /* Enables IRC sources. Disables XOSC and PLL sources. Sets IRC source as system clock */
    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)&(pMcu_Base->DRUN_MC.R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)&(pMcu_Base->RUN_MC[0U].R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)&(pMcu_Base->RUN_MC[1U].R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)&(pMcu_Base->RUN_MC[2U].R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)&(pMcu_Base->RUN_MC[3U].R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)&(pMcu_Base->SAFE_MC.R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)&(pMcu_Base->TEST_MC.R));
#else
    (void)pMcu_Base;
#endif
}
/*!
 * @brief Resets configuration of McMePeripheral in MC_ME_StPtr->
 *
 * Resets configuration of McMePeripheral in MC_ME_StPtr-> Disables module clocks in all modes.
 *
 * @param[in] pMcu_Base   Register pMcu_Base address for the MC_ME u32Mcu_Instance. */
LOCAL_INLINE FUNC(void, MCU_CODE) MC_ME_ResetPeripheralsConfiguration( void )
{
#if 0
    VAR(uint32, MCU_VAR) index = 0U;
    /* Reset run peripheral configurations */
    for (index = (uint32)0U; index < ((uint32)MC_ME_RUN_CONFIG_COUNT); index++)
    {
        MC_ME_SetRunPeripheralConfig ( index, 0U );
    }
    /* Reset low peripheral configurations */
    for (index = (uint32)0U; index < ((uint32)MC_ME_LOWPOWER_CONFIG_COUNT); index++)
    {
        MC_ME_SetLowPeripheralConfig( index, 0U );
    }

    for (index = (uint32)0U; index < (uint32)255U; index++)
    {
        /* Set peripheral clock control */
        MC_ME_SetPeripheralClockControl(MC_ME_StPtr, (Mcu_McMePeriNameType)index, 0U, 0U);
    }
#endif
}

/*FUNCTION**********************************************************************
 * Function Name : CLOCK_SYS_Reset
 * Description   : Clears peripheral clock gating and all clock sources. Only an IRC
 * type clock source is enabled and u32Mcu_Set as system clock source.
 *END**************************************************************************/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Reset(void)
{
    VAR(Std_ReturnType, MCU_VAR) retValue = (Std_ReturnType)E_OK;

    FIRST_CMU->CSR.B.RCDIV = (uint32)3U;
    /* Resets configuration of clock sources in MC_ME_StPtr-> */
    MC_ME_ResetClockSourcesConfiguration(MC_ME_StPtr);

    /* Resets configuration of McMePeripheral in MC_ME_StPtr-> */
    MC_ME_ResetPeripheralsConfiguration();

    /* Clock sources are enabled after mode transition */
    retValue = Mcu_LLD_ChangeMode(me_mc_mode_notchange);

    return retValue;
}

static FUNC(void, MCU_CODE) Mcu_LLD_RgmInit(P2CONST(Mcu_RgmConfigType, AUTOMATIC, MCU_APPL_DATA) Mcu_RgmConfigPtr)
{
    #if(MCU_PERFORM_RESET_API == STD_ON)
    Mcu_gRgmConfiguration = Mcu_RgmConfigPtr->Mcu_RgmResetType;
    #endif
    /* Event Reset Disable Register (RGM_DERD) */
    MC_RGM.DERD.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_DestResetOpt;
    /* Event Alternate Request Register (RGM_DEAR) */
    MC_RGM.DEAR.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_DestSafeIsrOpt;
    /* Bidirectional Reset Enable Register (RGM_DBRE) */
    MC_RGM.DBRE.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_DestExtPinReset;
    /* Functional */
    MC_RGM.FERD.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_FuncResetOpt;
    MC_RGM.FEAR.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_FuncSafeIsrOpt;
    MC_RGM.FBRE.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_FuncExtPinReset;
    /* Event Short Sequence Register (RGM_FESS) */
    MC_RGM.FESS.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_FuncPhase1or3Opt;
    if(((uint32)1U<<(uint32)MCU_POWER_ON_RESET) == MC_RGM.DES.R)
    {
        /* Reset Escalation Threshold Register (RGM_FRET) */
        MC_RGM.FRET.R = (uint8)Mcu_RgmConfigPtr->Mcrgm_FuncThresholdReset;
        /* Reset Escalation Threshold Register (RGM_DRET) */
        MC_RGM.DRET.R = (uint8)Mcu_RgmConfigPtr->Mcrgm_DesThresholdReset;
    }
}

LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_LLD_PmcInit(P2CONST(Mcu_PmcConfigType, AUTOMATIC, MCU_APPL_DATA) Mcu_PmcConfigPtr)
{
    PMCDIG.IE_P.R = (uint32)(Mcu_PmcConfigPtr->Pmc_IerConfig | PMC_IER_IE_EN_MASK32);
    PMCDIG.REE_VD3.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD3ResetEventEn);
    PMCDIG.REE_VD4.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD4ResetEventEn);
    PMCDIG.REE_VD7.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD7ResetEventEn);
    PMCDIG.REE_VD8.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD8ResetEventEn);
    PMCDIG.REE_VD9.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD9ResetEventEn);
    PMCDIG.REE_VD10.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD10ResetEventEn);
    PMCDIG.REE_VD12.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD12ResetEventEn);
    PMCDIG.REE_VD13.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD13ResetEventEn);
    PMCDIG.REE_VD14.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD14ResetEventEn);
    PMCDIG.REE_VD15.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD15ResetEventEn);
    PMCDIG.REE_TD.R = (uint32)(Mcu_PmcConfigPtr->Pmc_TempResEventEn);
    PMCDIG.RES_VD3.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD3ResetEventSel);
    PMCDIG.RES_VD4.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD4ResetEventSel);
    PMCDIG.RES_VD7.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD7ResetEventSel);
    PMCDIG.RES_VD8.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD8ResetEventSel);
    PMCDIG.RES_VD9.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD9ResetEventSel);
    PMCDIG.RES_VD12.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD12ResetEventSel);
    PMCDIG.RES_VD13.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD13ResetEventSel);
    PMCDIG.RES_VD14.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD14ResetEventSel);
    PMCDIG.RES_VD15.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD15ResetEventSel);
    PMCDIG.RES_TD.R = (uint32)(Mcu_PmcConfigPtr->Pmc_TempResEventSel);
    PMCDIG.FEE_VD3.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD3FccuEventEn);
    PMCDIG.FEE_VD4.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD4FccuEventEn);
    PMCDIG.FEE_VD7.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD7FccuEventEn);
    PMCDIG.FEE_VD8.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD8FccuEventEn);
    PMCDIG.FEE_VD9.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD9FccuEventEn);
    PMCDIG.FEE_VD10.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD10FccuEventEn);
    PMCDIG.FEE_VD12.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD12FccuEventEn);
    PMCDIG.FEE_VD13.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD13FccuEventEn);
    PMCDIG.FEE_VD14.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD14FccuEventEn);
    PMCDIG.FEE_VD15.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD15FccuEventEn);
    PMCDIG.FEE_TD.R = (uint32)(Mcu_PmcConfigPtr->Pmc_TempFccuEventEn);
    PMCDIG.CTL_TD.R = (uint32)(Mcu_PmcConfigPtr->Pmc_TempDetConfig) | 0x00000040UL;
    PMCDIG.VSIO.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VoltageSupply);
}


LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_LLD_McMeIrqConfig(VAR(uint32, AUTOMATIC) Mcu_McMeIrqConfig)
{
    MC_ME_StPtr->IM.R = Mcu_McMeIrqConfig;
}

LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_LLD_McMeRunConfig(P2CONST(Mcu_McMeConfigType, AUTOMATIC, MCU_APPL_DATA) Mcu_McMeCfgPtr)
{
    VAR(uint32, MCU_VAR)  index = 0;
    /* Set run peripheral configurations */
    for (index = (uint32)0U; index < ((uint32)MC_ME_RUN_CONFIG_COUNT); index++)
    {
        MC_ME_SetRunPeripheralConfig (index, Mcu_McMeCfgPtr->McMeRunConfig[index]);
    }

    /* Set low peripheral configurations */
    for (index = (uint32)0U; index < ((uint32)MC_ME_LOWPOWER_CONFIG_COUNT); index++)
    {
        MC_ME_SetLowPeripheralConfig (index, Mcu_McMeCfgPtr->McMeLowPowerConfig[index]);
    }
}


FUNC(void, MCU_CODE) Mcu_LLD_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ConfigPtr)
{
    if(pMcu_ConfigPtr->Mcu_CtrlConfigPtr->Mcu_BootCore == Mcu_LLD_Get_Core_Id())
    {
        #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
        *((volatile uint32*)0xfffa059CU) |= (0x1000u | 0x800u);    /* Open PMU_CFG */
        #endif
        Mcu_LLD_Launch_Core(MC_ME_StPtr, pMcu_ConfigPtr->Mcu_CoreConfigPtr);
        (void)Mcu_LLD_ChangeMode(me_mc_mode_notchange);
    }

    if(pMcu_ConfigPtr->Mcu_CtrlConfigPtr->Mcu_InitCore == Mcu_LLD_Get_Core_Id())
    {
        Mcu_LLD_McMeIrqConfig(pMcu_ConfigPtr->Mcu_McMeConfigPtr->Mcu_McMeIrqCfg);
        MC_ME_SetModeEnable(pMcu_ConfigPtr->Mcu_McMeConfigPtr->McMeMe);
        (void)Mcu_LLD_ChangeMode(me_mc_mode_notchange);
        Mcu_LLD_McMeRunConfig(pMcu_ConfigPtr->Mcu_McMeConfigPtr);
        /* Infinite reset Contorl */
        Mcu_LLD_RgmInit(pMcu_ConfigPtr->Mcu_RgmConfigPtr);
        Mcu_LLD_PmcInit(pMcu_ConfigPtr->Mcu_PmcConfigPtr);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Mcu_LLD_Clock_Init
 * Description   : This function sets the system to target configuration, it
 * only sets the clock modules registers for clock mode change, but not send
 * notifications to drivers.
 *
 * Implements CLOCK_DRV_Init_Activity
 * END**************************************************************************/
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Clock_Init (
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ClockConfigPtr )
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
#ifdef MCU_FLASH_WAIT_STATUS_CONFIG
    VAR(uint32, MCU_VAR) RegValue;
#endif
    /* Clears peripheral clock gating and all clock sources in all power modes.
     * Only an IRC type clock source is enabled and u32Mcu_Set as system clock source. */
    Mcu_RetVal = Mcu_LLD_Reset();

    if ((Std_ReturnType)E_OK == Mcu_RetVal)
    {
        /* Configure clock sources. */
        Mcu_RetVal = Mcu_LLD_ConfigureCgmcs(pMcu_ClockConfigPtr);

        if ((Std_ReturnType)E_OK == Mcu_RetVal)
        {
            Mcu_LLD_ClockPCS_Init();
            /* Configure peripheral clocks. */
            (void)Mcu_LLD_ConfigureCgm(pMcu_ClockConfigPtr);
#ifdef MCU_FLASH_WAIT_STATUS_CONFIG
            RegValue = PFLASH.PFCR1.R;
            RegValue &= ( uint32)(~( uint32)(FLASHC_PFCR1_APC_MASK32 | FLASHC_PFCR1_RWSC_MASK32));
            RegValue |= ( uint32)((FLASHC_PFCR1_APC_MASK32 | FLASHC_PFCR1_RWSC_MASK32) & pMcu_ClockConfigPtr->Mcu_FlashWSConfig);
            /* Set the AddressPipelining/Write/Read Wait State Control. */
            PFLASH.PFCR1.R = (volatile uint32)RegValue;
#endif
            PRAMC.PRCR1.R = (uint32)pMcu_ClockConfigPtr->Mcu_SRamWSConfig;

            /* Configure peripheral clock gating, system clock source
             * and clock sources in all power modes. */
            Mcu_LLD_PeriModeSet(pMcu_ClockConfigPtr->PeriConfigPtr);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_mode_notchange);
        }
    }
    #if (MCU_HARDVER == 3)
    /* Get Flash Swap Status */
    g_swapStatus = FLASH_Get_Swap_Status();
    #endif
    return Mcu_RetVal;
}

FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_GetPllStatus(void)
{
    VAR(Std_ReturnType, MCU_VAR) RetResult = (Std_ReturnType)E_OK;
    VAR(uint32, MCU_VAR) unlock_Count = 0U;
    VAR(uint32, MCU_VAR) Pll_Flag = 0U;

    if (PLLDIG_StPtr->PLL0CR.B.CLKCFG == (uint32)MCU_PLLCR_CFG_MASK)
    {
        Pll_Flag++;
        if(PLLDIG_StPtr->PLL0SR.B.LOCK != (uint32)TRUE)
        {
            unlock_Count++;
        }
    }
    if (PLLDIG_StPtr->PLL1CR.B.CLKCFG == (uint32)MCU_PLLCR_CFG_MASK)
    {
        Pll_Flag++;
        if(PLLDIG_StPtr->PLL1SR.B.LOCK != (uint32)TRUE)
        {
            unlock_Count++;
        }
    }
    if(Pll_Flag == (uint32)0U)
    {
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if (unlock_Count > (uint32)0U)
        {
            /* at leas 1 pll that was ON is unlocked return that there are unlocked PLL's */
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* at leas 1 pll that was ON is unlocked return that there are unlocked PLL's */
            RetResult = (Std_ReturnType)E_OK;
        }
    }
    return RetResult;
}


FUNC(void, MCU_CODE) Mcu_LLD_DistributePllClock(void)
{
    if(Mcu_gClockConfigPtr == NULL_PTR)
    {
        /* do nothing */
    }
    else
    {
        MC_ME_ChangeSysClk(MC_ME_StPtr, Mcu_gClockConfigPtr->mode_configuration.sysclk);
        (void)Mcu_LLD_ChangeMode(me_mc_mode_notchange);
    }
}

static FUNC(void, MCU_CODE) Mcu_LLD_Wkpu_Reset(void)
{
    MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.R;
    XOSC_StPtr->CTL.B.I_OSC = XOSC_StPtr->CTL.B.I_OSC;
    /* Clear WKPU.WISR */
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    WKPU.WISR0.R  = 0xFFFFFFFFUL;
    WKPU.WISR1.R  = 0xFFFFFFFFUL;
    #endif
}

/*******************************************************************************
 * @brief      Set current chip mode
 * @param[in]  ChipMode chip_mode
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Set_Chip_Mode \
( \
    P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_ModeConfigPtr
)
{
    VAR(Std_ReturnType, MCU_CODE)Mcu_RetVal = (Std_ReturnType)E_OK;

    switch (pMcu_ModeConfigPtr->Mcu_ChipMode) 
    {
        case me_mc_reset_mode:
        {
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_reset_mode);
            break;
        }
        case me_mc_test_mode: 
        {
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_test_mode);
            break;
        }
        case me_mc_safe_mode:
        {
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_safe_mode);
            break;
        }
        case me_mc_drun_mode:
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->DRUN_MC.R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_drun_mode);
            break;
        }
        case me_mc_run0_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->RUN_MC[0].R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_run0_mode);
            break;
        }
        case me_mc_run1_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->RUN_MC[1].R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_run1_mode);
            break;
        }
        case me_mc_run2_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->RUN_MC[2].R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_run2_mode);
            break;
        }
        case me_mc_run3_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->RUN_MC[3].R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_run3_mode);
            break;
        }
        case me_mc_halt0_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->HALT0_MC.R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_halt0_mode);
            break;
        }
        case me_mc_stop0_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->STOP0_MC.R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_stop0_mode);
            break;
        }
        #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
        case me_mc_standby_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                 (volatile uint32 *) &MC_ME_StPtr->STANDBY_MC.R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_standby_mode);
            break;
        }
        #endif
        case me_mc_reset_des_mode: 
        {
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_reset_des_mode);
            break;
        }
        default: 
        { 
            /* PRQA S 2024 */
            Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    };
    return Mcu_RetVal;
}

FUNC(void, MCU_CODE) Mcu_LLD_SetMode \
( \
    P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_ModeConfigPtr
)
{
    P2CONST(Mcu_ModeConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_TargetModeConfigPtr;
    VAR(Mcu_ModeConfigType, MCU_VAR) Mcu_CurrentModeConfig;
    VAR(Mcu_ModeConfigType, MCU_VAR) Mcu_LowPowerModeConfig;

    Mcu_TargetModeConfigPtr = pMcu_ModeConfigPtr;

    if  ( (Mcu_TargetModeConfigPtr->Mcu_ChipMode == me_mc_halt0_mode)
        || (Mcu_TargetModeConfigPtr->Mcu_ChipMode == me_mc_stop0_mode) )
    {
        /* The current clock mode, which needs to be restored after waking up */
        Mcu_CurrentModeConfig.Mcu_ChipMode = (Mcu_McModeType)MC_ME_StPtr->GS.B.S_CURRENT_MODE;
        Mcu_CurrentModeConfig.Mcu_IRC_En = MC_ME_StPtr->GS.B.S_IRC;
        Mcu_CurrentModeConfig.Mcu_XOSC_En = MC_ME_StPtr->GS.B.S_XOSC;
        Mcu_CurrentModeConfig.Mcu_PLL0_En = MC_ME_StPtr->GS.B.S_PLL0;
        Mcu_CurrentModeConfig.Mcu_PLL1_En = MC_ME_StPtr->GS.B.S_PLL1;
        Mcu_CurrentModeConfig.Mcu_TargetClock = MC_ME_StPtr->GS.B.S_SYSCLK;
        /* LowPwer Clock */
        /* Set current mode to the same clock configuration as low power mode */
        Mcu_LowPowerModeConfig.Mcu_ChipMode = (Mcu_McModeType)MC_ME_StPtr->GS.B.S_CURRENT_MODE;
        Mcu_LowPowerModeConfig.Mcu_IRC_En = Mcu_TargetModeConfigPtr->Mcu_IRC_En;
        Mcu_LowPowerModeConfig.Mcu_XOSC_En = Mcu_TargetModeConfigPtr->Mcu_XOSC_En;
        Mcu_LowPowerModeConfig.Mcu_PLL0_En = Mcu_TargetModeConfigPtr->Mcu_PLL0_En;
        Mcu_LowPowerModeConfig.Mcu_PLL1_En = Mcu_TargetModeConfigPtr->Mcu_PLL1_En;
        Mcu_LowPowerModeConfig.Mcu_TargetClock = Mcu_TargetModeConfigPtr->Mcu_TargetClock;
        Mcu_LowPowerModeConfig.PeriConfigPtr = Mcu_TargetModeConfigPtr->PeriConfigPtr;

        /* All peripherals need to be turned off before setting the clock configuration */
        /* Synchronous low power clock mode */
        Mcu_LLD_PeriModeSet(Mcu_LowPowerModeConfig.PeriConfigPtr);
        (void)Mcu_LLD_Set_Chip_Mode(&Mcu_LowPowerModeConfig);
        /* Turn off the interrupt flag that may affect wakeup */
        Mcu_LLD_Wkpu_Reset();
        /* Enter low power */
        (void)Mcu_LLD_Set_Chip_Mode(Mcu_TargetModeConfigPtr);

        Mcu_LLD_PeriModeSet(Mcu_gClockConfigPtr->PeriConfigPtr);
        (void)Mcu_LLD_Set_Chip_Mode(&Mcu_CurrentModeConfig);
    }
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5)) 
    else if (Mcu_TargetModeConfigPtr->Mcu_ChipMode == me_mc_standby_mode)
    {
        Mcu_LowPowerModeConfig.PeriConfigPtr = Mcu_TargetModeConfigPtr->PeriConfigPtr;
        /* All peripherals need to be turned off before setting the clock configuration */
        Mcu_LLD_PeriModeSet(Mcu_LowPowerModeConfig.PeriConfigPtr);

        Mcu_CurrentModeConfig.Mcu_ChipMode = (Mcu_McModeType)MC_ME_StPtr->GS.B.S_CURRENT_MODE;
        Mcu_CurrentModeConfig.Mcu_IRC_En = MC_ME_StPtr->GS.B.S_IRC;
        Mcu_CurrentModeConfig.Mcu_XOSC_En = MC_ME_StPtr->GS.B.S_XOSC;
        Mcu_CurrentModeConfig.Mcu_PLL0_En = MC_ME_StPtr->GS.B.S_PLL0;
        Mcu_CurrentModeConfig.Mcu_PLL1_En = MC_ME_StPtr->GS.B.S_PLL1;
        Mcu_CurrentModeConfig.Mcu_TargetClock = 0U;
        Mcu_LLD_Set_Chip_Mode(&Mcu_CurrentModeConfig);
        /* LowPwer Clock */
        /* Set current mode to the same clock configuration as low power mode */
        Mcu_LowPowerModeConfig.Mcu_ChipMode = me_mc_drun_mode;
        Mcu_LowPowerModeConfig.Mcu_IRC_En = Mcu_TargetModeConfigPtr->Mcu_IRC_En;
        Mcu_LowPowerModeConfig.Mcu_XOSC_En = Mcu_TargetModeConfigPtr->Mcu_XOSC_En;
        Mcu_LowPowerModeConfig.Mcu_PLL0_En = Mcu_TargetModeConfigPtr->Mcu_PLL0_En;
        Mcu_LowPowerModeConfig.Mcu_PLL1_En = Mcu_TargetModeConfigPtr->Mcu_PLL1_En;
        Mcu_LowPowerModeConfig.Mcu_TargetClock = Mcu_TargetModeConfigPtr->Mcu_TargetClock;
        /* Synchronous low power clock mode */
        (void)Mcu_LLD_Set_Chip_Mode(&Mcu_LowPowerModeConfig);
        /* PMU_CFG */
        *((volatile uint32*)0xfffa059CU) &= ~(0x1000u | 0x800u);   /* Close PMU_CFG */
        /* Turn off the interrupt flag that may affect wakeup */
        Mcu_LLD_Wkpu_Reset();
        /* Enter low power */
        (void)Mcu_LLD_Set_Chip_Mode(Mcu_TargetModeConfigPtr);
    }
    #endif
    else
    {
        Mcu_LLD_PeriModeSet(Mcu_TargetModeConfigPtr->PeriConfigPtr);
        (void)Mcu_LLD_Set_Chip_Mode(Mcu_TargetModeConfigPtr);
    }
}

FUNC(void, MCU_CODE)Mcu_LLD_PerformReset(void)
{
    VAR(Mcu_ModeConfigType, MCU_VAR) ResetModeConfig;
    if(Mcu_gRgmConfiguration == MCU_FUNC_RESET)
    {
        ResetModeConfig.Mcu_ChipMode = me_mc_reset_mode;
    }
    else
    {
        ResetModeConfig.Mcu_ChipMode = me_mc_reset_des_mode;
    }
    Mcu_LLD_Set_Chip_Mode(&ResetModeConfig);
}

FUNC(Mcu_ResetType, MCU_CODE) Mcu_LLD_GetResetReason(void)
{
    VAR(Mcu_ResetType, MCU_VAR) ResetReason = MCU_NO_RESET_REASON;
    VAR(uint32, MCU_VAR) RegValue = 0U;
    VAR(uint32, MCU_VAR) Index = 0U;
    VAR(uint32, MCU_VAR) ResetOffset = 0U;
    VAR(uint32, MCU_VAR) Count = 0U;
    RegValue = (MC_RGM.DES.R & RGM_DES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[0U] = RegValue;
    }
    RegValue = (MC_RGM.FES.R & RGM_FES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[1U] = RegValue;
    }

    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if(((uint32)(0x01UL << Index) & RGM_DES_RWBITS_MASK32) != 0U)
        {
            if((Mcu_ReasonReg[0U] & (uint32)(0x01UL << Index)) != 0U)
            {
                if(Count == 0U)
                {
                    ResetReason = (Mcu_ResetType) ResetOffset;
                    Count++;
                }
                else
                {
                    ResetReason = (Mcu_ResetType) MCU_MULTIPLE_RESET_REASON;
                    break;
                }
            }
            ResetOffset++;
        }
    }

    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if((((uint32)0x01UL << Index) & RGM_FES_RWBITS_MASK32) != 0U)
        {
            if((Mcu_ReasonReg[1U] & (uint32)(0x01UL << Index)) != 0U)
            {
                if(Count == 0U)
                {
                    ResetReason = (Mcu_ResetType) ResetOffset;
                    Count++;
                }
                else
                {
                    ResetReason = (Mcu_ResetType) MCU_MULTIPLE_RESET_REASON;
                    break;
                }
            }
            ResetOffset++;
        }
    }

    MC_RGM.DES.R = MC_RGM.DES.R;
    MC_RGM.FES.R = (MC_RGM.FES.R & RGM_FES_RWBITS_MASK32);
    return (Mcu_ResetType)ResetReason;
}

FUNC(Mcu_RawResetType, MCU_CODE) Mcu_LLD_GetResetRaw(void)
{
    VAR(Mcu_RawResetType, MCU_VAR) ResetRaw = (Mcu_RawResetType)0U;
    VAR(uint32, MCU_VAR) RegValue = 0U;
    VAR(uint32, MCU_VAR) ResetOffset = 0U;
    VAR(uint32, MCU_VAR) Index = 0U;

    RegValue = (uint32)(MC_RGM.DES.R & RGM_DES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[0U] = RegValue;
    }
    RegValue = (MC_RGM.FES.R & RGM_FES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[1U] = RegValue;
    }

    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if(((uint32)(0x01UL << Index) & RGM_DES_RWBITS_MASK32) != 0U)/*PRQA S 2896*/
        {
            if((Mcu_ReasonReg[0U] & (uint32)(0x01UL << Index)) != 0U)
            {
                if(ResetOffset < 32U)
                {
                    ResetRaw |= (uint32)(0x01UL << ResetOffset);
                }
            }
            ResetOffset++;
        }
    }
    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if(((uint32)(0x01UL << Index) & (uint32)RGM_FES_RWBITS_MASK32) != 0U)/*PRQA S 2896*/
        {
            if((Mcu_ReasonReg[1U] & (Mcu_RawResetType)(0x01UL << Index)) != 0U)
            {
                if(ResetOffset < 32U)
                {
                    ResetRaw |= (uint32)(0x01UL << ResetOffset);
                }
            }
            ResetOffset++;
        }
    }

    MC_RGM.DES.R = MC_RGM.DES.R;
    MC_RGM.FES.R = MC_RGM.FES.R;
    return (Mcu_RawResetType)ResetRaw;
}

FUNC(Mcu_RamStateType, MCU_CODE) Mcu_LLD_GetRamState(void)
{
    VAR(Mcu_RamStateType, MCU_VAR) RamState = MCU_RAMSTATE_INVALID;

    if(MEMU.ERR_FLAG.B.SR_CE == TRUE)
    {
    /* Do nothing */
    }
    else if(MEMU.ERR_FLAG.B.SR_UCE == TRUE)
    {
    /* Do nothing */
    }
    else if(MEMU.ERR_FLAG.B.PR_CE == TRUE)
    {
    /* Do nothing */
    }
    else if(MEMU.ERR_FLAG.B.PR_UCE == TRUE)
    {
    /* Do nothing */
    }
    else
    {
        RamState = MCU_RAMSTATE_VALID;
    }

    return (Mcu_RamStateType)RamState;
}


FUNC(void, MCU_CODE) Mcu_LLD_PeriModeSet (P2CONST(Mcu_PeriConfigType, AUTOMATIC, MCU_APPL_CONST) PeriConfigPtr)
{
    VAR(uint32, MCU_VAR) index;
    for(index = 0; index < MC_ME_PERIPH_INSTANCE_COUNT; index++)
    {
        MC_ME_StPtr->PCTL[(uint8)PeriConfigPtr[index].McMePeriNameConfig].R = (uint32)(
                                  (uint8)MC_ME_PCTLn_RUN_CFG(PeriConfigPtr[index].McMeRunConfig)
                                | (uint8)MC_ME_PCTLn_LP_CFG(PeriConfigPtr[index].McMeLowPowerConfig) );
    }
    Mcu_LLD_ChangeMode(me_mc_mode_notchange);
}

FUNC(void, MCU_CODE) Mcu_LLD_PeriResetPend 
    (P2CONST(Mcu_PeripheralResetType, AUTOMATIC, MCU_APPL_CONST) ResetConfigPtr)
{
    MC_RGM.PRST0.R = ResetConfigPtr->RgmGroup0;
    MC_RGM.PRST1.R = ResetConfigPtr->RgmGroup1;
    MC_RGM.PRST2.R = ResetConfigPtr->RgmGroup2;
    MC_RGM.PRST3.R = ResetConfigPtr->RgmGroup3;
    MC_RGM.PRST4.R = ResetConfigPtr->RgmGroup4;
    MC_RGM.PRST5.R = ResetConfigPtr->RgmGroup5;
    MC_RGM.PRST6.R = ResetConfigPtr->RgmGroup6;
    MC_RGM.PRST7.R = ResetConfigPtr->RgmGroup7;
}

FUNC(void, MCU_CODE) Mcu_LLD_PeriResetClose (VAR(void, AUTOMATIC))
{
    MC_RGM.PRST0.R = 0x0U;
    MC_RGM.PRST1.R = 0x0U;
    MC_RGM.PRST2.R = 0x0U;
    MC_RGM.PRST3.R = 0x0U;
    MC_RGM.PRST4.R = 0x0U;
    MC_RGM.PRST5.R = 0x0U;
    MC_RGM.PRST6.R = 0x0U;
    MC_RGM.PRST7.R = 0x0U;
}

FUNC(void, MCU_CODE) Mcu_LLD_CoreSynchronise (VAR(void, AUTOMATIC))
{
    VAR(uint8, MCU_VAR) CoreId;
    VAR(uint8, MCU_VAR) CoreIdx;
    volatile VAR(uint8, MCU_VAR) CoreStatus = CORE_NOT_READY;
    CoreId = Mcu_LLD_Get_Core_Id();
    Mcu_gCoreStatus[CoreId] = CORE_READY;

    if(0)
    {
    	return;
    }

    while(CoreStatus == CORE_NOT_READY)
    {
        for(CoreIdx=0; CoreIdx < MCU_CORE_COUNT; CoreIdx++)
        {
            if(Mcu_gCoreStatus[CoreIdx] == CORE_NOT_READY)
            {
                break;
            }
        }
        if(CoreIdx == MCU_CORE_COUNT)
        {
            CoreStatus = CORE_READY;
        }
    }
}


#if MCU_FCCU_ENABLE == STD_ON
/*
 * @brief Clear Fault Status Register
 *
 * This function use to clear the rf fault status register
 *
 * @param[in] faultIndex: FCCU failure input signal index
 * @retval    E_OK: success clearing faults
 *            Std_ReturnTypeIMEOUT: timeout operation
 */
Std_ReturnType FCCU_LLD_ClearFaults(uint8 faultIndex) /* PRQA S 1505 */
{
    uint8 index, regIdx, bitPos;
    uint32 timeout;
    Std_ReturnType status = (Std_ReturnType)E_OK;

    if (faultIndex >= FCCU_MAX_FAULTS_NO)
    {
        for (index = 0U; index < FCCU_RF_MAX_GROUP; index++)
        {
            /* set recoverable fault key */
            FCCU.RFK.R = FCCU_RECOVERABLE_FAULT_KEY;
            /* clear all faults */
            FCCU.RF_S[index].R = 0xFFFFFFFFU;
            /* wait operation 12 done */
            timeout = FCCU_OP_TIMEOUT_CONFIG;

            while ((FCCU.CTRL.B.OPS == (uint8)FCCU_OPS_IN_PROGRESS) && (timeout > 0U))
            {
                timeout--;
            }

            /* timeout happen */
            if (timeout == 0U)
            {
                status = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }
    else
    {
        regIdx = faultIndex >> 5U;   /* divide by 32 */
        bitPos = faultIndex & 0x1FU; /* modulo by 32 */

        /* set recoverable fault key */
        FCCU.RFK.R = FCCU_RECOVERABLE_FAULT_KEY;
        if(bitPos < 32U)
        {
            /* clear all faults */
            FCCU.RF_S[regIdx].R = (uint32)(1UL << (uint32)bitPos);
        }
        /* wait operation 12 done */
        timeout = FCCU_OP_TIMEOUT_CONFIG;

        while ((FCCU.CTRL.B.OPS == (uint8)FCCU_OPS_IN_PROGRESS) && (timeout > 0U))
        {
            timeout--;
        }

        /* timeout happen */
        if (timeout == 0U)
        {
            status = (Std_ReturnType)E_NOT_OK;
        }


    }
    return status;
}

/*
 * @brief Run operation
 *
 * This function use to run fcc operation
 *
 * @param[in] opRun: operation run
 * @retval    E_OK: success run operation
 *            Std_ReturnTypeIMEOUT: timeout run operation
 */
static Std_ReturnType FCCU_LLD_RunOperation(const fccu_op_run_t opRun) /* PRQA S 1505 */
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
    uint32 timeout = FCCU_OP_TIMEOUT_CONFIG;

    /* wait for the last operation complete */
    while (((uint8)FCCU_OPS_IN_PROGRESS == FCCU.CTRL.B.OPS) && (timeout != 0U))
    {
        timeout--;
    }

    if (0U == timeout)
    {
        status = (Std_ReturnType)E_NOT_OK;
    }

    if (status == (Std_ReturnType)E_OK)
    {
        /* get operation status */
        switch (opRun)
        {
            case FCCU_RUN_OP1:
                FCCU.CTRLK.R = FCCU_UNLOCK_OP1_KEY;
                FCCU.CTRL.R = (uint32)FCCU_RUN_OP1;
                break;
            case FCCU_RUN_OP2:
                FCCU.CTRLK.R = FCCU_UNLOCK_OP2_KEY;
                FCCU.CTRL.R = (uint32)FCCU_RUN_OP2;
                break;
            default:
                FCCU.CTRL.R = (uint32)opRun;
                break;
        }

        timeout = FCCU_OP_TIMEOUT_CONFIG;
        /* wait for the last operation complete */
        while (((uint8)FCCU_OPS_IN_PROGRESS == FCCU.CTRL.B.OPS) && (timeout != 0U))
        {
            timeout--;
        }

        if (0U == timeout)
        {
            status = (Std_ReturnType)E_NOT_OK;
        }
    }
    return status;
}

/*
 * @brief Read Recoverable Faults
 *
 * This function update and read recoverable faults
 *
 * @param[in] flags: faults flags
 * @retval    E_OK: success run operation
 *            Std_ReturnTypeIMEOUT: timeout operation
 */
static Std_ReturnType FCCU_LLD_ReadFaults(fccu_faults_flags_t *flags) /* PRQA S 1505 */
{
    uint8 index;
    Std_ReturnType status = (Std_ReturnType)E_OK;

    for (index = 0; index < FCCU_RF_MAX_GROUP; index++)
    {
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP10);
        if ((Std_ReturnType)E_OK == status)
        {
            flags->faultsFlags[index] = FCCU.RF_S[index].R;
        }
        else
        {
            return status;
        }
    }

    return status;
}

/*
 * @brief Read FCCU state
 *
 * This function use to read fccu state
 *
 * @retval the state of fccu module
 */
static fccu_status_t FCCU_LLD_GetState(void) /* PRQA S 1505 */
{
    Std_ReturnType status;
    fccu_status_t fccuStatus = FCCU_UNKNOWN_STATE;

    status = FCCU_LLD_RunOperation(FCCU_RUN_OP3);
    if ((Std_ReturnType)E_OK == status)
    {
        switch (FCCU.STAT.B.STATUS)
        {
            case 0U:
                fccuStatus = FCCU_NORMAL_STATE;
                break;
            case 1U:
                fccuStatus = FCCU_CONFIG_STATE;
                break;
            case 2U:
                fccuStatus = FCCU_ALARM_STATE;
                break;
            default:
                fccuStatus = FCCU_FAULT_STATE;
                break;
        }
    }

    return fccuStatus;
}


static uint8 FCCU_LLD_CheckFaultFlags(const fccu_faults_flags_t *faultFlags)
{
    uint32_t index;
    uint32_t bits;
    uint8 ret = FALSE;

    for (index = 0U; index < FCCU_RF_MAX_GROUP; index++)
    {
        for (bits = 0; bits < 32U; bits++)
        {
            if (index == 0U)
            {
                if (bits != 3U) /* do not check FCCU channel 3 faults input */
                {
                    if ((faultFlags->faultsFlags[index] & (0x1UL << bits)) != 0U)
                    {
                        ret = TRUE;
                        break;
                    }
                }
            }
            else if (index == 1U)
            {
                if ((bits != 7U) && (bits != 11U) && (bits != 19U)) /* do not check FCCU channel 43,51,54 faults input */
                {
                    if ((faultFlags->faultsFlags[index] & (0x1UL << bits)) != 0U)
                    {
                        ret = TRUE;
                        break;
                    }
                }
            }
            else
            {
                if ((faultFlags->faultsFlags[index] & (0x1UL << bits)) != 0U)
                {
                    ret = TRUE;
                    break;
                }
            }
        }

        if (TRUE == ret)
        {
            break;
        }
    }

    return ret;
}
/* @brief Set FCCU into config state
 *
 * This function set fccu into config state
 *
 * @retval E_OK: success to set fccu in config state
 *         Std_ReturnTypeIMEOUT: timeout operation
 *         FCCU_ERROR_SET_CONFIG: fail to set fccu in config state
 */
static Std_ReturnType FCCU_LLD_SetConfigState(void) /* PRQA S 1505 */
{
    Std_ReturnType status = FCCU_ERROR_OTHER;
    fccu_status_t fccuStatus;
    fccu_faults_flags_t faultsFlags;
    uint8 isFaultExist = TRUE;
    uint32 timeout = FCCU_OP_TIMEOUT_CONFIG;
    uint8 fccuOpStatus;

    /* Unlock configuration */
    FCCU.TRANS_LOCK.R = FCCU_TRANSKEY_UNLOCK_VAL;

    fccuStatus = FCCU_LLD_GetState();
    if (fccuStatus == FCCU_NORMAL_STATE)
    {
        /* clear all faults */
        status = FCCU_LLD_ClearFaults(FCCU_MAX_FAULTS_NO);
        if ((Std_ReturnType)E_OK == status)
        {
            fccuOpStatus = (uint8)FCCU.CTRL.B.OPS;
            if ((uint8)FCCU_OPS_SUCCESSFUL != fccuOpStatus)
            {
                /* read FCCU state */
                (void)FCCU_LLD_RunOperation(FCCU_RUN_OP3);
            }

            /* set fccu to enter config state */
            (void)FCCU_LLD_RunOperation(FCCU_RUN_OP1);
        }
        fccuStatus = FCCU_LLD_GetState();
        if (FCCU_CONFIG_STATE == fccuStatus)
        {
            status = (Std_ReturnType)E_OK;
        }
        else
        {
            status = FCCU_ERROR_SET_CONFIG;
        }
    }
    else if (fccuStatus == FCCU_CONFIG_STATE)
    {
        status = (Std_ReturnType)E_OK;
    }
    else if (fccuStatus == FCCU_UNKNOWN_STATE)
    {
        status = FCCU_ERROR_SET_CONFIG;
    }
    else /* Alarm or Fault State */
    {
        do
        {
            status = FCCU_LLD_ClearFaults(FCCU_MAX_FAULTS_NO);
            if ((Std_ReturnType)E_OK == status)
            {
                status = FCCU_LLD_ReadFaults(&faultsFlags);
                if ((Std_ReturnType)E_OK == status)
                {
                    isFaultExist = FCCU_LLD_CheckFaultFlags(&faultsFlags);
                }
            }
            timeout--;
        } while ((isFaultExist == (uint8)TRUE) && (timeout != 0U));

        if (timeout == 0U)
        {
            status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* set fccu in noraml state */
            (void)FCCU_LLD_RunOperation(FCCU_RUN_OP2);
            if (FCCU_NORMAL_STATE != FCCU_LLD_GetState())
            {
                status = FCCU_ERROR_SET_CONFIG;
            }
            else
            {
                /* set fccu in config state */
                (void)FCCU_LLD_RunOperation(FCCU_RUN_OP1);
                if (FCCU_CONFIG_STATE != FCCU_LLD_GetState())
                {
                    status = FCCU_ERROR_SET_CONFIG;
                }
                else
                {
                    status = (Std_ReturnType)E_OK;
                }
            }
        }
    }

    return status;
}

/*
 * @brief Set FCCU into normal state
 *
 * @retval E_OK: set fccu successfully
 *         FCCU_ERROR_SET_NORMAL: fails to set fccu state
 *         Std_ReturnTypeIMEOUT: run operation timeout
 */
static Std_ReturnType FCCU_LLD_SetNormalState(void) /* PRQA S 1505 */
{
    uint8 isFaultExist = TRUE;
    uint32 timeout = FCCU_OP_TIMEOUT_CONFIG;
    Std_ReturnType status = FCCU_ERROR_OTHER;
    fccu_status_t fccuStatus;
    fccu_faults_flags_t faultsFlags;

    fccuStatus = FCCU_LLD_GetState();
    if (FCCU_NORMAL_STATE == fccuStatus)
    {
        /* fccu already in normal state */
        status = (Std_ReturnType)E_OK;
    }
    else if (FCCU_CONFIG_STATE == fccuStatus)
    {
        /* set fccu into noraml state */
        (void)FCCU_LLD_RunOperation(FCCU_RUN_OP2);
        if (FCCU_NORMAL_STATE == FCCU_LLD_GetState())
        {
            status = (Std_ReturnType)E_OK;
        }
        else
        {
            status = FCCU_ERROR_SET_NORMAL;
        }
    }
    else if ((FCCU_ALARM_STATE == fccuStatus) || (FCCU_FAULT_STATE == fccuStatus))
    {
        do
        {
            status = FCCU_LLD_ClearFaults(FCCU_MAX_FAULTS_NO);
            if ((Std_ReturnType)E_OK == status)
            {
                status = FCCU_LLD_ReadFaults(&faultsFlags);
                if ((Std_ReturnType)E_OK == status)
                {
                    isFaultExist = FCCU_LLD_CheckFaultFlags(&faultsFlags);
                }
            }
            timeout--;
        } while ((isFaultExist == TRUE) && (timeout != 0U));

        if (timeout == 0U)
        {
            status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            (void)FCCU_LLD_RunOperation(FCCU_RUN_OP2);
            if (FCCU_NORMAL_STATE == FCCU_LLD_GetState())
            {
                status = (Std_ReturnType)E_OK;
            }
            else
            {
                status = FCCU_ERROR_SET_NORMAL;
            }
        }
    }
    else
    {
        status = FCCU_ERROR_SET_NORMAL;
    }

    return status;
}

/*
 * @brief Defines the preset value of the watchdog timer for the
 *        recovery from the CONFIG state
 *
 *
 * @param[in] to: configuration time-out value
 * @retval E_OK: set configuration timeout successfully
 *         FCCU_ERROR_CONFIG_TIMEOUT: fail to set configuration timeout
 */
Std_ReturnType FCCU_LLD_SetCfgTimeout(uint8 to) /* PRQA S 1503 */
{
    fccu_status_t fccuState;
    Std_ReturnType status;

    fccuState = FCCU_LLD_GetState();
    if (FCCU_CONFIG_STATE == fccuState)
    {
        status = FCCU_LLD_SetNormalState();
        if ((Std_ReturnType)E_OK != status)
        {
            status = FCCU_ERROR_CONFIG_TIMEOUT;
        }
        else
        {
            FCCU.CFG_TO.R = to;
        }
    }
    else
    {
        FCCU.CFG_TO.R = to;
        status = (Std_ReturnType)E_OK;
    }

    return status;
}

/*
 * @brief Lock the fccu configuration
 *
 *
 * @param[in] lock: type of lock
 * @retval None
 */
static void FCCU_LLD_LockConfig(const Mcu_FccuLockType lock) /* PRQA S 1505 */
{
    switch (lock)
    {
        case FCCU_TRANSIENTLY_UNLOCK:
            FCCU.TRANS_LOCK.B.TRANSKEY = FCCU_TRANSKEY_UNLOCK_VAL;
            break;
        case FCCU_TRANSIENTLY_LOCK:
            FCCU.TRANS_LOCK.B.TRANSKEY = FCCU_TRANSKEY_LOCK_VAL;
            break;
        case FCCU_PERANENTLY_LOCK:
            FCCU.PERMNT_LOCK.B.PERMNTKEY = FCCU_PERMENTKEY_LOCK_VAL;
            break;
        default:
            /* Do nothing */
            break;
    }
}

/*
 * @brief Check fccu IRQ_STAT register
 *
 *
 * @param[in] intStatus: status of interrupt
 * @retval 1: int bit occurs in IRQ_STAT register
 *         0: int bit nor occurs
 */
uint8 FCCU_LLD_CheckIntStatus(fccu_int_status_t intStatus) /* PRQA S 1505 */
{
    uint32 regIrqStat = (uint32)FCCU.IRQ_STAT.R;
    if((uint32)intStatus < 32U)
    {
        regIrqStat &= (1UL << (uint32)intStatus);
    }
    return (regIrqStat != 0UL) ? 1U : 0U;
}

/*
 * @brief Clear fccu interrupt flag
 *
 *
 * @param[in] intStatus: status of interrupt
 * @retval None
 */
static void FCCU_LLD_ClearIntFlag(fccu_int_status_t intStatus) /* PRQA S 1505 */
{
    uint32 regIrqStat = 0U;
    if((uint32)intStatus < 32U)
    {
        FCCU.IRQ_STAT.R = FCCU.IRQ_STAT.R & ~(1UL << (uint32)intStatus);
        regIrqStat = (uint32)(1UL << (uint32)intStatus);
    }
    FCCU.IRQ_STAT.R = regIrqStat;
}

/*
 * @brief FCCU Alarm Interrupt Callback function
 *
 */
static void FCCU_LLD_AlarmIrqCallback(void)
{
    uint8 index;
    uint8 reg_index, bit_pos;
    VAR(uint32, MCU_VAR)Mcu_FccuRf;
    /* Update faults status */
    (void)FCCU_LLD_RunOperation(FCCU_RUN_OP10);

    for (index = 0U; index < Mcu_gFccuConfigPtr->Mcu_FccuRfCfgNumber; index++)
    {
        reg_index = Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel >> 5U; /* divide by 32 */
        bit_pos = Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel & 0x1FU; /* modulo by 32 */
        if(bit_pos < 32U)
        {
            Mcu_FccuRf = (uint32)FCCU.RF_S[reg_index].R;
            Mcu_FccuRf = (Mcu_FccuRf & (1UL << (uint32)bit_pos));
            if ((reg_index < FCCU_RF_MAX_GROUP) && ( Mcu_FccuRf != 0UL))
            {
                if((Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_FM_PLL_0_CH_29) 
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_FM_PLL_1_CH_30)
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_CMU_0_OSC_CH_31)
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_CMU_0_PLL_CH_32)
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33)
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_CMU_OTHER_CH_34))
                {
                    Mcu_ClockFailureCmu_ISR();
                }
                /* Clear Fault */
                (void)FCCU_LLD_ClearFaults(Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel);
            }
        }
    }
}

/*
 * @brief Set the recoverable fault configuration
 *
 *
 * @param[in] cfg: recoverable fault configuration
 * @retval E_OK: set recoverable configuration successfully
 *         FCCU_ERROR_SET_NORMAL: fail to set fccu in noraml state
 *         FCCU_ERROR_SET_CONFIG: fail to set fccu in config state
 *         Std_ReturnTypeIMEOUT: run operation timeout
 */
static Std_ReturnType FCCU_LLD_SetRfConfig(const Mcu_FccuRfConfigType *cfg) /* PRQA S 1505 */
{
    uint8 regIdx;
    uint8 bitPos;
    Std_ReturnType status = (Std_ReturnType)E_OK;

    status = FCCU_LLD_SetConfigState();
    if ((Std_ReturnType)E_OK == status)
    {
        /* set rf configurations */
        regIdx = cfg->Mcu_FccuChannel >> 5U;   /* divide by 32 */
        bitPos = cfg->Mcu_FccuChannel & 0x1FU; /* modulo by 32 */
        if(bitPos < 32U)
        {
            /* recoverable fault configuration */
            FCCU.RF_CFG[regIdx].R = ((uint32)(FCCU.RF_CFG[regIdx].R & ~((uint32)1UL << bitPos))) | ((uint32)(((uint32)cfg->Mcu_FccuRecoveryConfig) << bitPos));

            /* allow fccu moves ALARM or FAULT state */
            FCCU.RF_E[regIdx].R = (FCCU.RF_E[regIdx].R & ~(1UL << bitPos)) | (1UL << bitPos);

            /* set timeout enable
            * 0 FCCU moves into the FAULT state if the respective fault is enabled
            * 1 FCCU moves into the ALARM state if the respective fault is enabled
            */
            FCCU.RF_TOE[regIdx].R = (FCCU.RF_TOE[regIdx].R & ~(1UL << bitPos)) \
                                    | (((cfg->Mcu_FccuToAlarmEn == TRUE) ? 1UL : 0UL) << bitPos);

            /* set irq alarm en */
            FCCU.IRQ_ALARM_EN[regIdx].R = (FCCU.IRQ_ALARM_EN[regIdx].R & ~(1UL << bitPos)) \
                                        | (((cfg->Mcu_FccuRfReactionEnCfg.irq_alarm_en == TRUE) ? 1UL : 0UL) << bitPos);
            /* set nmi en */
            FCCU.NMI_EN[regIdx].R = (FCCU.NMI_EN[regIdx].R & ~(1UL << bitPos)) \
                                | (((cfg->Mcu_FccuRfReactionEnCfg.nmi_en == TRUE) ? 1UL : 0UL) << bitPos);

            /* set eout signaling enable */
            FCCU.EOUT_SIG_EN[regIdx].R = (FCCU.EOUT_SIG_EN[regIdx].R & ~(1UL << bitPos))
                                    | (((cfg->Mcu_FccuRfReactionEnCfg.eout_sig_en == TRUE) ? 1UL : 0UL) << bitPos);

            /* set reset Mcu_FccuRfReactionEnCfg */
            regIdx = cfg->Mcu_FccuChannel >> 4U;   /* divide by 16 */
            bitPos = (uint8)((cfg->Mcu_FccuChannel & 0xFU) << 1U); /* modulo by 16 */

            FCCU.RFS_CFG[regIdx].R = (FCCU.RFS_CFG[regIdx].R & ~(3UL << bitPos)) | (((uint32)cfg->Mcu_FccuReactionConfig ) << bitPos);
        }

        status = (Std_ReturnType)FCCU_LLD_SetNormalState();
    }
    else
    {
        status = (Std_ReturnType)E_NOT_OK;
    }

    return status;
}

/*
 * @brief Set fccu eout configuration
 *
 *
 * @param[in] eoutCfg: configuration of errpin out
 * @retval E_OK: set fccu eout configuration successfully
 *         FCCU_ERROR_SET_EOUT: fail to set fccu eout configuration
 */
static Std_ReturnType FCCU_LLD_SetEout(const Mcu_FccuEoutConfigType *eoutCfg) /* PRQA S 1505,3673 */
{
    Std_ReturnType status;

    status = FCCU_LLD_SetConfigState();
    if ((Std_ReturnType)E_OK == status)
    {
        FCCU.CFG.B.FCCU_SET_AFTER_RESET = (eoutCfg->set_after_reset == TRUE) ? 1U : 0U;
        FCCU.CFG.B.FCCU_SET_CLEAR = (uint8_t)eoutCfg->control;
        FCCU.CFG.B.OD = (uint8_t)eoutCfg->output;
        #if (MCU_HARDVER == 5)
        FCCU.CFG.B.FOP = (uint8_t)eoutCfg->fop;
        FCCU.CFG.B.EOFS = (uint8_t)eoutCfg->eof;
        #endif
        FCCU.CFG.B.SM = (uint8)eoutCfg->switch_mode;
        FCCU.CFG.B.PS = (uint8)eoutCfg->polarity_sel;
        FCCU.CFG.B.FOM = (uint8)eoutCfg->mode;
        FCCU.DELTA_T.B.DELTA_T = eoutCfg->delta_t_value;
    }
    else
    {
         status = FCCU_ERROR_SET_EOUT;
    }

    return status;
}

/*
 * @brief Read the FCCU frozen status flags
 *
 *
 * @param[in] frozenType: type of frozen status
 * @param[in] frozenStatus: pointer to frozen status address
 * @retval E_OK: read status successfully
 *         FCCU_ERROR_UPDATE_FREEZE: fail to read frozen status
 */
Std_ReturnType FCCU_LLD_GetFrozenStatus(fccu_frozen_type_t frozenType, uint16 *frozenStatus) /* PRQA S 1503 */
{
    Std_ReturnType status = FCCU_ERROR_UPDATE_FREEZE;

    switch (frozenType)
    {
    case FCCU_FROZEN_N2AF_STATUS:
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP4);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = (uint16)FCCU.N2AF_STATUS.B.NAFS;
            status = (Std_ReturnType)E_OK;
        }
        break;
    case FCCU_FROZEN_A2FF_STATUS:
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP5);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = (uint16)FCCU.A2FF_STATUS.B.AFFS;
            status = (Std_ReturnType)E_OK;
        }
        break;
    case FCCU_FROZEN_N2FF_STATUS:
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP6);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = (uint16)FCCU.N2FF_STATUS.B.NFFS;
            status = (Std_ReturnType)E_OK;
        }
        break;
    case FCCU_FROZEN_F2AF_STATUS:
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP7);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = (uint16)FCCU.F2A_STATUS.B.FAFS;
            status = (Std_ReturnType)E_OK;
        }
        break;
    default:
        status = FCCU_ERROR_UPDATE_FREEZE;
        break;
    }

    return status;
}

/*
 * @brief Clear the freeze status register
 *
 *
 * @retval E_OK: clear status register successfully
 *         E_OK: fail to clear status register
 */
Std_ReturnType FCCU_LLD_ClearFreezeStatus(void) /* PRQA S 1503 */
{
    Std_ReturnType status;

    (void)FCCU_LLD_RunOperation(FCCU_RUN_OP13);
    if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
    {
        status = (Std_ReturnType)E_OK;
    }
    else
    {
        status = FCCU_ERROR_CLEAR_FREEZE;
    }

    return status;
}

/*
 * @brief Return the XTMR register value
 *
 *
 * @param[in] xtmrType: type of xtmr value
 * @retval the value of XTMR register
 */
uint32 FCCU_LLD_GetXtmrValue(fccu_xtmr_type_t xtmrType) /* PRQA S 1503 */
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
    uint32 value = 0U;

    switch (xtmrType)
    {
        case FCCU_XTMR_ALARM:
            status = FCCU_LLD_RunOperation(FCCU_RUN_OP17);
            break;
        case FCCU_XTMR_CFG:
            status = FCCU_LLD_RunOperation(FCCU_RUN_OP19);
            break;
        case FCCU_XTMR_ETMR:
            status = FCCU_LLD_RunOperation(FCCU_RUN_OP20);
            break;
        default:
            value = 0U;
            break;
    }

    if ((Std_ReturnType)E_OK == status)
    {
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            value = FCCU.XTMR.R;
        }
    }

    return value;
}

/*
 * @brief Trigger a recoverable fault fake to test
 *
 *
 * @param[in] fakeCode: trogger fake fault Mcu_FccuChannel
 * @retval None
 */
void FCCU_LLD_SetRfFake(fccu_failure_inputs_t fakeCode)
{
    FCCU.RFF.B.FRFC = (uint8)fakeCode;
}


/*
 * @brief Initializes the fccu module
 *
 *
 * @param[in] config: fccu module configuration
 * @param[in] rfConfig: fccu recoverable faults configuration
 * @retval    E_OK: init successfully
 *            FCCU_ERROR_SET_NORMAL: fail to set fccu goto normal state
 *            FCCU_ERROR_SET_CONFIG: fail to set fccu goto config state
 *            Std_ReturnTypeIMEOUT: in case of a timeout operation
 */

VAR(Std_ReturnType, MCU_CODE)Mcu_LLD_FccuInit
(
    P2CONST( Mcu_FccuConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_FccuConfigPtr
)
{
    Std_ReturnType status = FCCU_ERROR_OTHER;\
    VAR(uint8, MCU_VAR)Mcu_Idx;
    Mcu_gFccuConfigPtr = Mcu_FccuConfigPtr;
    /* set debug mode */
    FCCU.CTRL.B.DEBUG = (uint32)FALSE;
    /* set filter bypass and width */
    FCCU.CTRL.B.FILTER_BYPASS = (uint32)Mcu_gFccuConfigPtr->Mcu_FccuFilterBypassEn;
    if (TRUE == Mcu_gFccuConfigPtr->Mcu_FccuFilterBypassEn)
    {
        FCCU.CTRL.B.FILTER_WIDTH = Mcu_gFccuConfigPtr->Mcu_FccuFilterWidth;
    }
    /* enable timeout interrupt */
    if (Mcu_gFccuConfigPtr->Mcu_FccuIrqTypeConfig == FCCU_IRQ_CFG_TO_IEN)
    {
        FCCU.IRQ_EN.B.CFG_TO_IEN = 0x1U;
    }

    /* set fccu goto config state */
    status = FCCU_LLD_SetConfigState();
    if ((Std_ReturnType)E_OK == status)
    {
        FCCU.CFG_TO.B.TO = Mcu_gFccuConfigPtr->Mcu_FccuCfgTimeout;

        status = FCCU_LLD_SetEout(&Mcu_gFccuConfigPtr->Mcu_FccuEoutConfig);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }

        for (Mcu_Idx = 0U; Mcu_Idx < Mcu_gFccuConfigPtr->Mcu_FccuRfCfgNumber; Mcu_Idx++)
        {
            status = FCCU_LLD_SetRfConfig(&Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[Mcu_Idx]);
            if ((Std_ReturnType)E_OK != status)
            {
                break;
            }
        }
    }

    if ((Std_ReturnType)E_OK == status)
    {
        status = FCCU_LLD_SetNormalState();
        if ((Std_ReturnType)E_OK == status)
        {
            FCCU_LLD_LockConfig(Mcu_gFccuConfigPtr->Mcu_FccuLockTypeConfig);
        }
    }
    return status;
}
#endif

FUNC(void, MCU_CODE) Mcu_ClockFailureCmu_ISR(void)
{
    VAR(uint32, MCU_VAR) IndexCmu = 0U;
    CONSTP2VAR(CMU_Type, MCU_CONST, MCU_APPL_CONST) Mcu_CmuPtr[] = CMU_BASE_PTRS;
    #if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    (void)Dem_SetEventStatus(Mcu_gConfigPtr->Mcu_DemConfigPtr->Mcu_E_ClockFailureCfg.id, Mcu_gConfigPtr->Mcu_DemConfigPtr->Mcu_E_ClockFailureCfg.id);
    #endif

    #if (MCU_CLOCKS_FAILURE_EN == STD_ON)
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_ClockFailureNotification != NULL_PTR)
    {
        (void)Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_ClockFailureNotification();
    }
    #endif

    for(IndexCmu = (uint32)0U; IndexCmu < (uint32)CMU_INSTANCE_COUNT; IndexCmu++)
    {
        if(Mcu_CmuPtr[IndexCmu]->ISR.R != (uint32)0U)
        {
            Mcu_CmuPtr[IndexCmu]->ISR.R = Mcu_CmuPtr[IndexCmu]->ISR.R;
        }
    }
}


FUNC(void, MCU_CODE) Mcu_LLD_XoscISR(void)
{
    if(Mcu_gConfigPtr != NULL_PTR)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_XoscStartupNotification != NULL_PTR)
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_XoscStartupNotification();
        }
    }
    if(XOSC_StPtr->CTL.B.I_OSC == (uint32)TRUE)
    {
        XOSC_StPtr->CTL.B.I_OSC = (uint32)TRUE;
    }
}


FUNC(void, MCU_CODE)Mcu_LLD_InvalidConfig_ISR(void)
{
    if(MC_ME_StPtr->IS.B.I_ICONF_CC == TRUE)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification_Core != NULL_PTR)
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification_Core();
        }
        MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_ICONF_CC;
    }else if(MC_ME_StPtr->IS.B.I_ICONF_CU == TRUE)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification_Clock != NULL_PTR)
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification_Clock();
        }
        MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_ICONF_CU;
    }
    else if(MC_ME_StPtr->IS.B.I_ICONF == TRUE)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification != NULL_PTR)
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification();
        }
        MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_ICONF;
    }
    else
    {
        /* Do nothing */
    }
}

FUNC(void, MCU_CODE)Mcu_LLD_InvalidMode_ISR(void)
{
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidModeNotification != NULL_PTR)
    {
        Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidModeNotification();
    }
    MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_IMODE;
}

FUNC(void, MCU_CODE)Mcu_LLD_SafeMode_ISR(void)
{
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_SafeModeNotification != NULL_PTR)
    {
        Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_SafeModeNotification();
    }
    MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_SAFE;
}

FUNC(void, MCU_CODE)Mcu_LLD_ModeComplete_ISR(void)
{
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_ModeCompleteNotification != NULL_PTR)
    {
        Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_ModeCompleteNotification();
    }
    MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_MTC;
}

FUNC(void, MCU_CODE)Mcu_LLD_VoltageError_ISR(void)
{
    VAR(uint16, MCU_VAR) VoltageIsrFlag = 0U;
    if(PMCDIG.EPR_VD3.R != (uint32)0U)
    {
        PMCDIG.EPR_VD3.R = PMCDIG.EPR_VD3.R;
        VoltageIsrFlag |= ((uint16)1<<3U);
    }
    if(PMCDIG.EPR_VD4.R != (uint32)0U)
    {
        PMCDIG.EPR_VD4.R = PMCDIG.EPR_VD4.R;
        VoltageIsrFlag |= ((uint16)1U<<4U);
    }
    if(PMCDIG.EPR_VD7.R != (uint32)0U)
    {
        PMCDIG.EPR_VD7.R = PMCDIG.EPR_VD7.R;
        VoltageIsrFlag |= ((uint16)1U<<7U);
    }
    if(PMCDIG.EPR_VD8.R != (uint32)0U)
    {
        PMCDIG.EPR_VD8.R = PMCDIG.EPR_VD8.R;
        VoltageIsrFlag |= ((uint16)1U<<8U);
    }
    if(PMCDIG.EPR_VD9.R != (uint32)0U)
    {
        PMCDIG.EPR_VD9.R = PMCDIG.EPR_VD9.R;
        VoltageIsrFlag |= ((uint16)1U<<9U);
    }
    if(PMCDIG.EPR_VD10.R != (uint32)0U)
    {
        PMCDIG.EPR_VD10.R = PMCDIG.EPR_VD10.R;
        VoltageIsrFlag |= ((uint16)1U<<10U);
    }
    if(PMCDIG.EPR_VD12.R != (uint32)0U)
    {
        PMCDIG.EPR_VD12.R = PMCDIG.EPR_VD12.R;
        VoltageIsrFlag |= ((uint16)1U<<12U);
    }
    if(PMCDIG.EPR_VD13.R != (uint32)0U)
    {
        PMCDIG.EPR_VD13.R = PMCDIG.EPR_VD13.R;
        VoltageIsrFlag |= ((uint16)1U<<13U);
    }
    if(PMCDIG.EPR_VD14.R != (uint32)0U)
    {
        PMCDIG.EPR_VD14.R = PMCDIG.EPR_VD14.R;
        VoltageIsrFlag |= ((uint16)1U<<14U);
    }
    if(PMCDIG.EPR_VD15.R != (uint32)0U)
    {
        PMCDIG.EPR_VD15.R = PMCDIG.EPR_VD15.R;
        VoltageIsrFlag |= ((uint16)1U<<15U);
    }
    if(VoltageIsrFlag != (uint32)0U)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuVoltageErrorNotification != NULL_PTR)
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuVoltageErrorNotification();
        }
    }
}

FUNC(void, MCU_CODE)Mcu_LLD_TemperatureErrorError_ISR(void)
{
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuTemperatureErrorNotification != NULL_PTR)
    {
        Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuTemperatureErrorNotification();
    }
    PMCDIG.EPR_TD.R = PMCDIG.EPR_TD.R;
}

#if MCU_FCCU_ENABLE == STD_ON
FUNC(void, MCU_CODE) Mcu_LLD_Fccu_ISR(void)
{
    if(FCCU.IRQ_STAT.B.ALRM_STAT == (uint32)TRUE)
    {
        FCCU_LLD_AlarmIrqCallback();
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_FccuAlarmNotification != NULL_PTR)
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_FccuAlarmNotification();
        }
        FCCU_LLD_ClearIntFlag(FCCU_INT_ALARM);
    }
    if(FCCU.IRQ_STAT.B.CFG_TO_STAT == (uint32)TRUE)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_FccuCfgToNotification != NULL_PTR)
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_FccuCfgToNotification();
        }
        FCCU_LLD_ClearIntFlag(FCCU_INT_TIMEOUT);
    }
}
#endif


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif
