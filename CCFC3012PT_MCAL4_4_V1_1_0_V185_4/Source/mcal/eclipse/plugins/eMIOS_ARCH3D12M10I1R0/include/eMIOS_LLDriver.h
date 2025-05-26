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
*   @file    eMIOS_LLDriver.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eMIOS MCAL driver.
*
*   @addtogroup eMIOS
*   @{
*/

#ifndef EMIOS_LLDRIVER_H
#define EMIOS_LLDRIVER_H

#include "eMIOS_Cfg.h"
#include "derivative.h"
#include "status.h"
#include "devassert.h"

#define EMIOS_LLD_H_VENDOR_ID                     176
#define EMIOS_LLD_H_AR_REL_MAJOR_VER              4
#define EMIOS_LLD_H_AR_REL_MINOR_VER              4
#define EMIOS_LLD_H_AR_REL_REV_VER                0
#define EMIOS_LLD_H_SW_MAJOR_VER                  1
#define EMIOS_LLD_H_SW_MINOR_VER                  0
#define EMIOS_LLD_H_SW_PATCH_VER                  1
#define EMIOS_MODULE_ID                           250

#if (EMIOS_VENDOR_ID != EMIOS_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_VENDOR_ID "
#endif
#if (EMIOS_AR_REL_MAJOR_VER != EMIOS_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (EMIOS_AR_REL_MINOR_VER != EMIOS_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_AR_REL_MINOR_VER "
#endif
#if (EMIOS_AR_REL_REV_VER != EMIOS_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_AR_REL_REV_VER "
#endif
#if (EMIOS_SW_MAJOR_VER != EMIOS_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_SW_MAJOR_VER "
#endif
#if (EMIOS_SW_MINOR_VER != EMIOS_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_SW_MINOR_VER "
#endif
#if (EMIOS_SW_PATCH_VER != EMIOS_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_H_SW_PATCH_VER "
#endif

typedef struct eMIOS_tag eMIOS_Type;

#define EMIOS_DEV_ERR(x)            DEV_ASSERT(x)

/** Number of instances of the eMIOS module. */
#define EMIOS_INSTANCE_MAX                      (2U)

#define EMIOS_MODULE_CHANNEL_MAX                (32U)

/* eMIOS - Peripheral instance base addresses */
/** Peripheral eMIOS_0 base address */
#define EMIOS0_BASEADDR                         ((uint32_t)0xFFDEC000UL)
/** Peripheral eMIOS_0 base pointer */
#define EMIOS0_PTR                              ((eMIOS_Type *)EMIOS0_BASEADDR)
/** Peripheral eMIOS_1 base address */
#define EMIOS1_BASEADDR                         ((uint32_t)0xFBF78000UL)
/** Peripheral eMIOS_1 base pointer */
#define EMIOS1_PTR                              ((eMIOS_Type *)EMIOS1_BASEADDR)
/** Array initializer of eMIOS peripheral base addresses */
#define EMIOS_BASE_ADDR_ARRAY                   { EMIOS0_BASEADDR, EMIOS1_BASEADDR }
/** Array initializer of eMIOS peripheral base pointers */
#define EMIOS_BASE_PTR_ARRAY                    { EMIOS0_PTR, EMIOS1_PTR }

/** Interrupt vectors for the eMIOS peripheral type */

#define EMIOS_MCR_GPRE_MAX          (0xFFU)

/* Max/Min counter value (eMIOS CNT register in MC mode - 24 bit) */
#define EMIOS_MC_CNT_MAX            (0xFFFFFFUL)
#define EMIOS_MC_CNT_MIN            (0x00UL)
/* Max/Min counter value (eMIOS CNT register in MCB mode - 24 bit) */
#define EMIOS_MCB_CNT_MAX           (0xFFFFFFUL)
#define EMIOS_MCB_CNT_MIN           (0x01UL)
/* Max/Min counter value (eMIOS CNT register in OPWFMB mode - 24 bit) */
#define EMIOS_OPWFMB_CNT_MAX        (0xFFFFFFUL)
#define EMIOS_OPWFMB_CNT_MIN        (0x01UL)
/* Max/Min counter value (eMIOS CNT register in OPWMCB mode - 24 bit) */
#define EMIOS_OPWMCB_CNT_MAX        (0xFFFFFFUL)
#define EMIOS_OPWMCB_CNT_MIN        (0x00UL)

/* Modulus Counter Buffered MASK */
#define EMIOS_FILTER_MCB_MASK       (0xFCU)
/* Modulus Counter Buffered (Up counter) MASK */
#define EMIOS_MCB_UP_MASK           (0x50U)
/* Modulus Counter Buffered (Up/down counter) MASK */
#define EMIOS_MCB_UPDOWN_MASK       (0x54U)
/* Modulus Counter MASK */
#define EMIOS_FILTER_MC_MASK        (0xFCU)
/* Modulus Counter (Up counter) MASK */
#define EMIOS_MC_UP_MASK            (0x10U)
/* Modulus Counter (Up/down counter) MASK */
#define EMIOS_MC_UPDOWN_MASK        (0x14U)
/* Center Aligned Output Pulse Width Modulation Buffered */
#define EMIOS_OPWMCB_MASK           (0x5CU)
/* Center Aligned Output Pulse Width Modulation Buffered Filter mask */
#define EMIOS_FILTER_OPWMCB_MASK    (0xFCU)

#define GPIO_Mode_Mask              (0x770C00FFU)

#define GPIO_Mode_Out_PP            (0x320C0000U)    

#define GPIO_Mode_IPU               (0x308C0000U)    

#define GPIOM                       (0xC0)

/*******************************************************************************
 * @brief eMIOS instance base address pointer array
 ******************************************************************************/
extern CONSTP2VAR(eMIOS_Type, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_BasePtr[EMIOS_INSTANCE_MAX];

typedef enum
{
    EMIOS_INSTANCE_0,
    EMIOS_INSTANCE_1
} eMIOS_ModuleType;

typedef enum
{
    EMIOS_ETB_DIS_COUNTER_BUSA_TO_UC    = 0U,
    EMIOS_ETB_EN_COUNTER_BUSA_TO_STAC   = 1U
} eMIOS_MCR_ExtTimeBaseType;

typedef enum
{
    EMIOS_OUTPUT_DISABLE_INPUT_0        = 0x00U,
    EMIOS_OUTPUT_DISABLE_INPUT_1        = 0x01U,
    EMIOS_OUTPUT_DISABLE_INPUT_2        = 0x02U,
    EMIOS_OUTPUT_DISABLE_INPUT_3        = 0x03U
} eMIOS_UC_OutputDisSelType;

typedef enum
{
    EMIOS_UC_PRE_CLK_DIV_1              = 0x00U,
    EMIOS_UC_PRE_CLK_DIV_2              = 0x01U,
    EMIOS_UC_PRE_CLK_DIV_3              = 0x02U,
    EMIOS_UC_PRE_CLK_DIV_4              = 0x03U
} eMIOS_UC_PresClkDivType;

typedef enum
{
    EMIOS_C_REQ_INT                     = 0U,
    EMIOS_C_REQ_DMA                     = 1U
} eMIOS_UC_IntDmaType;

typedef enum
{
    EMIOS_INPUT_FILTER_BYPASS           = 0x00U,
    EMIOS_INPUT_FILTER_02               = 0x01U,
    EMIOS_INPUT_FILTER_04               = 0x02U,
    EMIOS_INPUT_FILTER_08               = 0x04U,
    EMIOS_INPUT_FILTER_16               = 0x08U
} eMIOS_UC_InputFilterType;

typedef enum
{
    EMIOS_C_FCK_PRESCALED_CLK           = 0U,
    EMIOS_C_FCK_EMIOS_MODULE_CLK        = 1U
} eMIOS_UC_FilterClkSelType;

typedef enum
{
    EMIOS_COUNTER_BUS_A                 = 0x00U,
    EMIOS_COUNTER_BUS_BCDE              = 0x01U,
    EMIOS_COUNTER_BUS_INTERNAL          = 0x03U
} eMIOS_UC_CounterBusSelType;

typedef enum
{
    EMIOS_TRIG_EDGE_FALLING             = 0x00U,
    EMIOS_TRIG_EDGE_RISING              = 0x01U,
    EMIOS_TRIG_EDGE_BOTH                = 0x02U,
    EMIOS_TRIG_EDGE_OPPOSITE            = 0x03U
} eMIOS_EdgeTrigModeType;

typedef enum
{
    EMIOS_NEGATIVE_PULSE                = 0x00U,
    EMIOS_POSITIVE_PULSE                = 0x01U
} eMIOS_PulsePolarityModeType;

typedef enum
{
    EMIOS_CNT_BUSB_DRIVEN_CHANNEL       = 0U,
    EMIOS_CNT_BUSC_DRIVEN_CHANNEL       = 8U,
    EMIOS_CNT_BUSD_DRIVEN_CHANNEL       = 16U,
    EMIOS_CNT_BUSA_DRIVEN_CHANNEL       = 23U,
    EMIOS_CNT_BUSE_DRIVEN_CHANNEL       = 24U,
    EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL   = 32U,
    EMIOS_CNT_NONE_DRIVEN_CHANNEL       = 0xFFU,
} eMIOS_BusDrivenType;

typedef enum
{
    EMIOS_UC_MODE_GPIO_INPUT                = 0x00U,
    EMIOS_UC_MODE_GPIO_OUTPUT               = 0x01U,
    EMIOS_UC_MODE_SAIC                      = 0x02U,
    EMIOS_UC_MODE_SAOC                      = 0x03U,
    EMIOS_UC_MODE_IPWM                      = 0x04U,
    EMIOS_UC_MODE_IPM                       = 0x05U,
    EMIOS_UC_MODE_DAOC_FLAG_MATCH_B         = 0x06U,
    EMIOS_UC_MODE_DAOC_BOTH_FLAG_MATCH      = 0x07U,
    EMIOS_UC_MODE_PEA_CONTIN                = 0x08U,
    EMIOS_UC_MODE_PEA_SINGLE                = 0x09U,
    EMIOS_UC_MODE_PEC_CONTIN                = 0x0AU,
    EMIOS_UC_MODE_PEC_SINGLE                = 0x0BU,
    EMIOS_UC_MODE_FOR_COUNT_DIRECT_QDEC     = 0x0CU,
    EMIOS_UC_MODE_QDEC_A_B_FOR_PHASE        = 0x0DU,
    EMIOS_UC_MODE_WPTA                      = 0x0EU,
    EMIOS_UC_MODE_MC                        = 0x40U,
    EMIOS_UC_MODE_MCB_INT                   = 0x50U,
    EMIOS_UC_MODE_MCB_EXT                   = 0x51U
} eMIOS_UC_ModeType;

typedef struct
{
    VAR(boolean, ADC_VAR) LowPowerModeEn;
    VAR(boolean, ADC_VAR) FreezeInDebugMode;
    VAR(uint16, ADC_VAR) GlobalPreClkDiv;
    VAR(eMIOS_MCR_ExtTimeBaseType, ADC_VAR) ExternalTimeBaseSel;
    VAR(uint8, ADC_VAR) ServerTimeSlotSel;
} eMIOS_GlobalParamType;

typedef enum
{
    EMIOS_UC_MODE_MC_UP_CNT_CLR_START_INT_CLK       = 0x10U,     /* Modulus Counter (Up counter with clear on match start), internal clock */
    EMIOS_UC_MODE_MC_UP_START_EXT_CLK_CNT_CLR       = 0x11U,     /* Modulus Counter (Up counter with clear on match start), external clock */
    EMIOS_UC_MODE_MC_UP_CNT_CLR_END_INT_CLK         = 0x12U,     /* Modulus Counter (Up counter with clear on match end), internal clock */
    EMIOS_UC_MODE_MC_UP_CNT_EXT_CLR_END_CLK         = 0x13U,     /* Modulus Counter (Up counter with clear on match end), external clock */

    EMIOS_UC_MODE_MC_UPDOWN_CNT_FLAGX1_INT_CLK      = 0x14U,     /* Modulus Counter (Up/Down counter), internal clock */
    MC_UPDOWN_CNT_FLAGX1_EXT_CLK                    = 0x15U,     /* Modulus Counter (Up/Down counter), external clock */
    EMIOS_UC_MODE_MC_FLAGX2_UPDOWN_CNT_INT_CLK      = 0x16U,     /* Modulus Counter (Up/Down counter), internal clock */
    EMIOS_UC_MODE_MC_UPDOWN_FLAGX2_CNT_EXT_CLK      = 0x17U,     /* Modulus Counter (Up/Down counter), external clock */

    EMIOS_UC_MODE_MCB_UP_COUNTER_INT_CLK            = 0x50U,     /* Modulus Counter Buffered (Up counter), using internal clock */
    EMIOS_UC_MODE_MCB_UP_COUNTER_EXT_CLK            = 0x51U,     /* Modulus Counter Buffered (Up counter), using external clock */

    EMIOS_UC_MODE_MCB_UPDOWN_CNT_FLAGX1_INT_CLK     = 0x54U,     /* Modulus Counter Buffered (Up/Down counter), Flags are generated only at A1 match start, Using internal clock */
    EMIOS_UC_MODE_MCB_UPDOWN_FLAGX1_CNT_EXT_CLK     = 0x55U,     /* Modulus Counter Buffered (Up/Down counter), Flags are generated only at A1 match start, Using external clock */
    EMIOS_UC_MODE_MCB_UPDOWN_CNT_INT_CLK_FLAGX2     = 0x56U,     /* Modulus Counter Buffered (Up/Down counter), Flags are generated at A1 match start and cycle boundary, Using internal clock */
    EMIOS_UC_MODE_MCB_UPDOWN_FLAGX2_CNT_EXT_CLK     = 0x57U      /* Modulus Counter Buffered (Up/Down counter), Flags are generated at A1 match start and cycle boundary, Using external clock */
} eMIOS_UC_MC_ModeType;

typedef struct
{
    VAR(eMIOS_UC_MC_ModeType, ADC_VAR) mode;
    VAR(uint32, ADC_VAR) period;
    VAR(uint8, ADC_VAR) divid;
    VAR(eMIOS_UC_InputFilterType, ADC_VAR) filter;
    VAR(eMIOS_EdgeTrigModeType, ADC_VAR) trigger;
} eMIOS_MC_ParamType;

//LOCAL_INLINE FUNC(void, EMIOS_CODE) GPIO_ConfigIdx(VAR(uint32, AUTOMATIC) u32eMIOS_Idx, VAR(uint32, AUTOMATIC) u32eMIOS_Mode)
//{
//    SIUL2.MSCR_IO[u32eMIOS_Idx].R = (SIUL2.MSCR_IO[u32eMIOS_Idx].R & (~GPIO_Mode_Mask)) | ((u32eMIOS_Mode) & GPIO_Mode_Mask);
//}
/*******************************************************************************/
/****************eMIOS Module Configuration Register (eMIOS_MCR)****************/

/******eMIOS_MCR bit fields: GPRE***********************************************/

/* @brief Get Module configuration register: Global Prescaler bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]Global Prescaler bits(8 bits)
 *                  0b00000000: 1(divide)
 *                  0b00000001: 2(divide)
 *                  0b11111111: 256(divide)
 *
 * @note  The GPRE[0:7] bits select the clock divider value for the
 *          global prescaler.
 * */
LOCAL_INLINE uint8_t eMIOS_MCR_GetGPRE(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    return ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPRE));
}

/* @brief Set Module configuration register: Global Prescaler bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_GlobalPreDiv: Global Prescaler bits(8 bits)
 *                  0b00000000: 1(divide)
 *                  0b00000001: 2(divide)
 *                  0b11111111: 256(divide)
 *
 * @note  The GPRE[0:7] bits select the clock divider value for the
 *          global prescaler.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_MCR_SetGPRE(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_GlobalPreDiv)
{
    peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPRE = (uint32)u8eMIOS_GlobalPreDiv;
}

/******eMIOS_MCR bit fields: SRV************************************************/

/* @brief Get Module configuration register: Server Time Slot bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]Server Time Slot bits(4 bits)
 *
 * @note  The SRV bits select the address of a specific STAC server to which
 *          the STAC is assigned.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_MCR_GetSRV(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    return ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.SRV));
}

/* @brief Set Module configuration register: Server Time Slot bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ServerTimeSlot: Server Time Slot bits(4 bits)
 *
 * @note  The SRV bits select the address of a specific STAC server to which
 *          the STAC is assigned.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_MCR_SetSRV(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ServerTimeSlot)
{
    peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.SRV = (uint32)u8eMIOS_ServerTimeSlot;
}

/******eMIOS_MCR bit fields: GPREN**********************************************/

/* @brief Get Module configuration register: Global Prescaler Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]Global Prescaler Enable bit(1 bit)
 *          0: Prescaler disabled (no clock) and prescaler counter is cleared
 *          1: Prescaler enabled
 *
 * @note  The GPREN bit enables the prescaler counter.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetGPREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPREN) == 1U) ? TRUE : FALSE);
    }
    return beMIOS_ret;
}

/* @brief Set Module configuration register: Global Prescaler Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_GlobalPreEnDis: Global Prescaler Enable bit(1 bit)
 *          0: Prescaler disabled (no clock) and prescaler counter is cleared
 *          1: Prescaler enabled
 *
 * @note  The GPREN bit enables the prescaler counter.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_MCR_SetGPREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_GlobalPreEnDis)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPREN = ((beMIOS_GlobalPreEnDis == TRUE)?1U:0U);
    }
}

/******eMIOS_MCR bit fields: ETB************************************************/

/* @brief Get Module configuration register: External Time Base bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]External Time Base bit(1 bit)
 *                  0: Counter bus[A] assigned to Unified Channel.
 *                  1: Counter bus[A] assigned to STAC.
 *
 * @note  The ETB bit selects the time base source that drives counter bus[A].
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetETB(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    return (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.ETB) == 1U)? TRUE : FALSE);
}

/* @brief Set Module configuration register: External Time Base bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_ExtTimeBase: External Time Base bit(1 bit)
 *                  0: Counter bus[A] assigned to Unified Channel.
 *                  1: Counter bus[A] assigned to STAC.
 *
 * @note  The ETB bit selects the time base source that drives counter bus[A].
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_MCR_SetETB(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_ExtTimeBase)
{
    peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.ETB = ((beMIOS_ExtTimeBase == TRUE)?1U:0U);
}

/******eMIOS_MCR bit fields: GTBE***********************************************/

/* @brief Get Module configuration register: Global Time Base Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out] Global Time Base Enable bit(1 bit)
 *                  0: Global Time Base Enable Out signal negated.
 *                  1: Global Time Base Enable Out signal asserted.
 *
 * @note  The GTBE bit is used to export a Global Time Base Enable from the
 *          module and provide a method to start time bases of several blocks
 *          simultaneously.
 *        NOTE: The Global Time Base Enable input pin controls the internal
 *          counters. When asserted, Internal counters are enabled. When negated,
 *          Internal counters disabled.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetGTBE(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GTBE) == 1U) ? TRUE : FALSE);
    }
    return beMIOS_ret;
}

/* @brief Set Module configuration register: Global Time Base Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_GlobalTimeBaseEn: Global Time Base Enable bit(1 bit)
 *                  0: Global Time Base Enable Out signal negated.
 *                  1: Global Time Base Enable Out signal asserted.
 *
 * @note  The GTBE bit is used to export a Global Time Base Enable from the
 *          module and provide a method to start time bases of several blocks
 *          simultaneously.
 *        NOTE: The Global Time Base Enable input pin controls the internal
 *          counters. When asserted, Internal counters are enabled. When negated,
 *          Internal counters disabled.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_MCR_SetGTBE(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_GlobalTimeBaseEn)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GTBE = ((beMIOS_GlobalTimeBaseEn == TRUE)?1U:0U);
    }
    
}

/******eMIOS_MCR bit fields: FRZ************************************************/

/* @brief Get Module configuration register: Freeze bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out] Freeze bit(1 bit)
 *          0: Exit freeze state
 *          1: Stops Unified Channels operation when in Debug mode and
 *              the FREN bit is set in the eMIOS_UC_Cn register
 *
 * @note  This bit enables the eMIOS to freeze the registers of the
 *          Unified Channels when Debug Mode is requested at MCU level.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetFRZ(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.FRZ) == 1U) ? TRUE : FALSE);
    }
    return beMIOS_ret;
}

/* @brief Set Module configuration register: Freeze bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_FreezeEnDis: Freeze bit(1 bit)
 *          0: Exit freeze state
 *          1: Stops Unified Channels operation when in Debug mode and
 *              the FREN bit is set in the eMIOS_UC_Cn register
 *
 * @note  This bit enables the eMIOS to freeze the registers of the
 *          Unified Channels when Debug Mode is requested at MCU level.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_MCR_SetFRZ(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_FreezeEnDis)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.FRZ = ((beMIOS_FreezeEnDis == TRUE)?1u:0U);
    }
    
}

/******eMIOS_MCR bit fields: MDIS***********************************************/

/* @brief Get Module configuration register: Module Disable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]Module Disable bit(1 bit)
 *                  0: Clock is running
 *                  1: Enter low power mode
 *
 * @note  Puts the eMIOS into low power mode. The MDIS bit stops the clock of
 *          the block, except the access to registers EMIOSMCR and EMIOSOUDIS.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetMDIS(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.MDIS) == 1U) ? TRUE : FALSE);   
    }
    return beMIOS_ret;
}

/* @brief Set Module configuration register: Module Disable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_ModuleDis: Module Disable bit(1 bit)
 *                  0: Clock is running
 *                  1: Enter low power mode
 *
 * @note  Puts the eMIOS into low power mode. The MDIS bit stops the clock of
 *          the block, except the access to registers EMIOSMCR and EMIOSOUDIS.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_MCR_SetMDIS(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_ModuleDis)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.MDIS = ((beMIOS_ModuleDis == TRUE)?1U:0U);
    }
    
}

/*******************************************************************************/
/*******************eMIOS Global FLAG Register (eMIOS_GFLAG)********************/

/* @brief Get Global FLAG Register(read-only).
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        [out] Channel [n] mirrored FLAG bit(1 bit)
 *
 * @note  For Unified Channels these bits are mirrors of the FLAG bits
 *          in the eMIOS_UC_S[n] register.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_GFLAG_GetFLAGn(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    if(u8eMIOS_ChanNum <= 32U)
    {
        if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
        {
            return (((((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->GFLAG.R)) & ((uint32_t)(1UL << u8eMIOS_ChanNum))) == 0UL) ? FALSE : TRUE);
        }
        
    }

    return (boolean)FALSE;
}

LOCAL_INLINE FUNC(uint32, EMIOS_CODE) eMIOS_GFLAG_GetAllFLAG(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    return (((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->GFLAG.R)) & 0xFF00FFUL);
}

/*******************************************************************************/
/**************eMIOS Output Update Disable Register (eMIOS_OUDIS)***************/

/* @brief Get Output Update Disable Register: one bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        [out] Channel [n] Output Update Disable bit (1 bit)
 *          0(FALSE): disabled bit -> disable(Transfer enabled)
 *          1(TRUE): disabled bit -> enable(Transfers disabled)
 *
 * @note  When running MC, MCB or an output mode, values are written to
 *          registers A2 and B2. OU[n] bits are used to disable transfers
 *          from registers A2 to A1 and B2 to B1. Each bit controls one channel.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_OUDIS_GetChNumOutUPDDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    if(u8eMIOS_ChanNum <= 32U)
    {
        if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
        {
            return (((((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R)) & ((uint32_t)(1UL << u8eMIOS_ChanNum))) == 0UL) ? FALSE : TRUE);
        }
        
    }

    return (boolean)FALSE;
}

/* @brief Get Output Update Disable Register: all bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out] Channel [n] Output Update Disable bit(1 bit)
 *          0(FALSE): disabled bit -> disable(Transfer enabled)
 *          1(TRUE): disabled bit -> enable(Transfers disabled)
 *
 * @note  When running MC, MCB or an output mode, values are written to
 *          registers A2 and B2. OU[n] bits are used to disable transfers
 *          from registers A2 to A1 and B2 to B1. Each bit controls one channel.
 * */
LOCAL_INLINE FUNC(uint32, EMIOS_CODE) eMIOS_OUDIS_GetAllChOutUPDDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u32eMIOS_ret = (((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R)) & 0xFF00FFUL);
    }
    return u32eMIOS_ret;
}

/* @brief Set Output Update Disable Register: one bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        beMIOS_OutUpdateDisable_EnDis:
 *          0(FALSE): disabled bit -> disable(Transfer enabled)
 *          1(TRUE): disabled bit -> enable(Transfers disabled)
 *
 * @note  When running MC, MCB or an output mode, values are written to
 *          registers A2 and B2. OU[n] bits are used to disable transfers
 *          from registers A2 to A1 and B2 to B1. Each bit controls one channel.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_OUDIS_SetChNumOutUPDDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateDisable_EnDis \
)
{
    if(beMIOS_OutUpdateDisable_EnDis == TRUE)
    {
        /* Output Update Disable Register bit -> enable, Transfers disabled */
        if(u8eMIOS_ChanNum <= 32U)
        {
            if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
            {
                peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R |= (1UL << u8eMIOS_ChanNum);
            }
            
        }
    }
    else
    {
        /* Output Update Disable Register bit -> disable, Transfers enabled */
        if(u8eMIOS_ChanNum <= 32U)
        {
            if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
            {
                peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R &= ((1UL << u8eMIOS_ChanNum) ^ 0xFFFFFFFFUL);
            }
            
        }
    }
}

/* @brief Set Output Update Disable Register: all bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u32eMIOS_OutUpdateDisableVal:
 *      Bit 0  1  2  3  4  5  6  7  | 8    9    10   11   12   13   14   15
 *          (Reserved             )  Ch23 Ch22 Ch21 Ch20 Ch19 Ch18 Ch17 Ch16
 *      Bit 16 17 18 19 20 21 22 23 | 24   25   26   27   28   29   30   31
 *          (Reserved             )  Ch7  Ch6  Ch5  Ch4  Ch3  Ch2  Ch1  Ch0
 *          0(FALSE): disabled bit -> disable(Transfer enabled)
 *          1(TRUE): disabled bit -> enable(Transfers disabled)
 *
 * @note  When running MC, MCB or an output mode, values are written to
 *          registers A2 and B2. OU[n] bits are used to disable transfers
 *          from registers A2 to A1 and B2 to B1. Each bit controls one channel.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_OUDIS_SetAllChOutUPDDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint32, AUTOMATIC) u32eMIOS_OutUpdateDisableVal \
)
{
    /* Output Update Disable Register all bits -> enable, Transfers disabled */
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R = (u32eMIOS_OutUpdateDisableVal & 0xFF00FFUL);
    }
    
}

/*******************************************************************************/
/*******************eMIOS UC A register n (eMIOS_UC_An)*************************/

/* @brief Get A value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]A_value: internal registers A1[0:23] or A2[0:23]
 *
 * @note  Depending on the mode of operation, internal registers
 *          A1[0:23] or A2[0:23], used for matches and captures,
 *          can be assigned to address EMIOS_An.
 *        Both A1 and A2 are cleared by reset.
 * */
LOCAL_INLINE FUNC(uint32, EMIOS_CODE) eMIOS_UC_An_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u32eMIOS_ret = ((uint32_t)((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].A.R) & eMIOS_A_A_MASK));
    }
    return u32eMIOS_ret;
}

LOCAL_INLINE FUNC(uint32, EMIOS_CODE) eMIOS_UC_An_GetAddress(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((uint32_t)(&(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].A.R)));
}


/* @brief Set A value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u32eMIOS_A_value: internal registers A1[0:23] or A2[0:23]
 *
 * @note  Depending on the mode of operation, internal registers
 *          A1[0:23] or A2[0:23], used for matches and captures,
 *          can be assigned to address EMIOS_An.
 *        Both A1 and A2 are cleared by reset.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_An_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_A_value \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].A.R = ((uint32_t)(u32eMIOS_A_value & eMIOS_A_A_MASK));
    }
    
}

/*******************************************************************************/
/*******************eMIOS UC B register n (eMIOS_UC_Bn)*************************/

/* @brief Get B value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]B_value: internal registers B1[0:23] or B2[0:23]
 *
 * @note  Depending on the mode of operation, internal registers
 *          B1[0:23] or B2[0:23] can be assigned to address EMIOS_Bn.
 *        Both B1 and B2 are cleared by reset.
 * */
LOCAL_INLINE FUNC(uint32, EMIOS_CODE) eMIOS_UC_Bn_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u32eMIOS_ret = ((uint32_t)((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].B.R) & eMIOS_B_B_MASK));
    }
    return u32eMIOS_ret;
}

/* @brief Set B value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u32eMIOS_B_value: internal registers B1[0:23] or B2[0:23]
 *
 * @note  Depending on the mode of operation, internal registers
 *          B1[0:23] or B2[0:23] can be assigned to address EMIOS_Bn.
 *        Both B1 and B2 are cleared by reset.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Bn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_B_value \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].B.R = ((uint32_t)(u32eMIOS_B_value & eMIOS_B_B_MASK));
    }
    
}

/*******************************************************************************/
/*******************eMIOS UC CNT register n (eMIOS_UC_CNTn)*********************/

/* @brief Get CNT value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]C_value: The C field contains the value of the internal counter.
 *
 * @note  EMIOS_CNTn register is required for the following modes:
 *          OPWFM, OPWFMB, OPWMC, OPWMCB, PEA, PEC, WPTA, QDEC, MC, MCB.
 * */
LOCAL_INLINE FUNC(uint32, EMIOS_CODE) eMIOS_UC_CNTn_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u32eMIOS_ret = ((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].CNT.R & eMIOS_CNT_C_MASK));

    }
    return u32eMIOS_ret;
}

/* @brief Set CNT value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u32eMIOS_C_value: The C field contains the value of the internal counter.
 *
 * @note  EMIOS_CNTn register is required for the following modes:
 *          OPWFM, OPWFMB, OPWMC, OPWMCB, PEA, PEC, WPTA, QDEC, MC, MCB.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_CNTn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_C_value \
)
{
    peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].CNT.R = ((uint32_t)(u32eMIOS_C_value & eMIOS_CNT_C_MASK));
}

/*******************************************************************************/
/*******************eMIOS UC Control register n (eMIOS_UC_Cn)*******************/

LOCAL_INLINE FUNC(uint32, EMIOS_CODE) eMIOS_UC_Cn_GetCtrlCfg(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u32eMIOS_ret = ((uint32_t)((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.R) & 0xFFFFFFFFU));
    }
    return u32eMIOS_ret;
}

LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetCtrlCfg \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_C_value \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.R = ((uint32_t)(u32eMIOS_C_value & 0xFFFFFFFFU));
    }
    
}

/******eMIOS_UC_Cn bit fields: MODE*********************************************/

/* @brief Get Control register: mode selection.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]ModeSel: Mode selection bits(7 bits).
 *
 * @note  The MODE bits select the mode of operation of the Unified Channel.
 *        NOTE: If a reserved value is written to the mode bit field,
 *          the results are unpredictable.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
            u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.MODE));
        
    }
    return u8eMIOS_ret;
}

/* @brief Set Control register: mode selection.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_ModeSel: Mode selection bits(7 bits).
 *
 * @note  The MODE bits select the mode of operation of the Unified Channel.
 *        NOTE: If a reserved value is written to the mode bit field,
 *          the results are unpredictable.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ModeSel \
)
{
    peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.MODE = (uint32)u8eMIOS_ModeSel;
}

/******eMIOS_UC_Cn bit fields: EDPOL********************************************/

/* @brief Get Control register: Edge Polarity bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]u8eMIOS_EdgePolar: Edge Polarity bit(1 bit).
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetEDPOL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.EDPOL));
}

/* @brief Set Control register: Edge Polarity bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_EdgePolar: Edge Polarity bit(1 bit).
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetEDPOL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgePolar \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.EDPOL = (uint32)u8eMIOS_EdgePolar;
    }
    
}

/******eMIOS_UC_Cn bit fields: EDSEL********************************************/

/* @brief Get Control register: Edge Selection bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]EdgeSel: Edge Selection bit(1 bit).
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetEDSEL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.EDSEL));
}

/* @brief Set Control register: Edge Selection bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_EdgeSel: Edge Selection bit(1 bit).
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetEDSEL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgeSel \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.EDSEL = (uint8)u8eMIOS_EdgeSel;
    }
    
}

/******eMIOS_UC_Cn bit fields: BSL**********************************************/

/* @brief Get Control register: Bus Select bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]BusSel: Bus Select bits(2 bits).
 *
 * @note  The BSL[0:1] bits are used to select either one of the counter buses
 *          or the internal counter to be used by the Unified Channel.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetBSL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.BSL));
}

/* @brief Set Control register: Bus Select bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_BusSel: Bus Select bits(2 bits).
 *
 * @note  The BSL[0:1] bits are used to select either one of the counter buses
 *          or the internal counter to be used by the Unified Channel.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetBSL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_BusSel \
)
{
    peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.BSL = (uint32)u8eMIOS_BusSel;
}

/******eMIOS_UC_Cn bit fields: FORCMB*******************************************/

/* @brief Set Control register: Force Match B bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_ForceMatchB: Force Match B bit(1 bit),
 *                     0: Has not effect,
 *                     1: Force a match at comparator B.
 *
 * @note  For output modes, the FORCMB bit is equivalent to a successful
 *          comparison on comparator B (except that the FLAG bit is not set).
 *        This bit is cleared by reset and is always read as zero.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFORCMB \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ForceMatchB \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FORCMB = ((beMIOS_ForceMatchB == TRUE)?1U:0U);
    }
    
}

/******eMIOS_UC_Cn bit fields: FORCMA*******************************************/

/* @brief Set Control register: Force Match A bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_ForceMatchA: Force Match A bit(1 bit),
 *                     0: Has not effect,
 *                     1: Force a match at comparator A.
 *
 * @note  For output modes, the FORCMA bit is equivalent to a successful
 *          comparison on comparator A (except that the FLAG bit is not set).
 *        This bit is cleared by reset and is always read as zero.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFORCMA \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ForceMatchA \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FORCMA = ((beMIOS_ForceMatchA == TRUE)?1U:0U);
    }
    
}

/******eMIOS_UC_Cn bit fields: FEN**********************************************/

/* @brief Get Control register: FLAG Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]FlagEN: FLAG Enable bit(1 bit),
 *                0: Disable(FLAG does not generate an interrupt request)
 *                1: Enable(FLAG generates an interrupt request)
 *
 * @note  The FEN bit allows the Unified Channel FLAG bit to generate an
 *          interrupt signal or a DMA request signal (the type of signal
 *          to be generated is defined by the DMA bit).
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetFEN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FEN == 1U)? TRUE:FALSE);
}

/* @brief Set Control register: FLAG Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_FlagEN: FLAG Enable bit(1 bit),
 *                0: Disable(FLAG does not generate an interrupt request)
 *                1: Enable(FLAG generates an interrupt request)
 *
 * @note  The FEN bit allows the Unified Channel FLAG bit to generate an
 *          interrupt signal or a DMA request signal (the type of signal
 *          to be generated is defined by the DMA bit).
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFEN \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_FlagEN \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FEN = ((beMIOS_FlagEN == TRUE)?1U:0U);
    }
    
}

/******eMIOS_UC_Cn bit fields: FCK**********************************************/

/* @brief Get Control register: Filter Clock select bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]FilterClkSel: Filter Clock select bit(1 bit),
 *                0: Prescaled clock
 *                1: eMIOS module clock
 *
 * @note  The FCK bit selects the clock source for the programmable input filter.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetFCK(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FCK));
}

/* @brief Set Control register: Filter Clock select bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_FilterClkSel: Filter Clock select bit(1 bit),
 *                0: Prescaled clock
 *                1: eMIOS module clock
 *
 * @note  The FCK bit selects the clock source for the programmable input filter.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFCK \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_FilterClkSel \
)
{
    peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FCK = (uint32)u8eMIOS_FilterClkSel;
}

/******eMIOS_UC_Cn bit fields: IF***********************************************/

/* @brief Get Control register: Input Filter bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]InputFilter: Input Filter bits(4 bits)
 *                  IF      *   Minimum input Pulse width [filter clock periods]
 *                  0b0000  *   bypassed
 *                  0b0001  *   2
 *                  0b0010  *   4
 *                  0b0100  *   8
 *                  0b1000  *   16
 *
 * @note  The IF[0:3] bits control the programmable input filter, selecting the
 *          minimum input pulse width that can pass through the filter.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetIF(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.IF));
}

/* @brief Set Control register: Input Filter bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_InputFilter: Input Filter bits(4 bits)
 *                  IF      *   Minimum input Pulse width [filter clock periods]
 *                  0b0000  *   bypassed
 *                  0b0001  *   2
 *                  0b0010  *   4
 *                  0b0100  *   8
 *                  0b1000  *   16
 *
 * @note  The IF[0:3] bits control the programmable input filter, selecting the
 *          minimum input pulse width that can pass through the filter.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetIF \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_InputFilter \
)
{
    peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.IF = (uint32)u8eMIOS_InputFilter;
}

/******eMIOS_UC_Cn bit fields: DMA**********************************************/

/* @brief Get Control register: Direct Memory Access bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]IntDmaReqSel: Direct Memory Access bit(1 bit)
 *                      0: Flag/overrun assigned to Interrupt request.
 *                      1: Flag/overrun assigned to DMA request.
 *
 * @note  The DMA bit selects if FLAG generation will be used as
 *          an interrupt or as a DMA request.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetDMA(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.DMA));
    }
    return u8eMIOS_ret;
}

/* @brief Set Control register: Direct Memory Access bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_IntDmaReqSel: Direct Memory Access bit(1 bit)
 *                      0: Flag/overrun assigned to Interrupt request.
 *                      1: Flag/overrun assigned to DMA request.
 *
 * @note  The DMA bit selects if FLAG generation will be used as
 *          an interrupt or as a DMA request.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetDMA \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_IntDmaReqSel \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.DMA = ((u8eMIOS_IntDmaReqSel == TRUE)?1U:0U);
    }
    
}

/******eMIOS_UC_Cn bit fields: UCPREN*******************************************/

/* @brief Get Control register: Prescaler Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]ClkPreEnDis: Prescaler Enable bit(1 bit)
 *                      0: Prescaler disabled (no clock).
 *                      1: Prescaler enabled.
 *
 * @note  The UCPREN bit enables the prescaler counter.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetUCPREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.UCPREN == 1U) ? TRUE : FALSE);
    }
    return beMIOS_ret;
}

/* @brief Set Control register: Prescaler Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_ClkPreEnDis: Prescaler Enable bit(1 bit)
 *                      0: Prescaler disabled (no clock).
 *                      1: Prescaler enabled.
 *
 * @note  The UCPREN bit enables the prescaler counter.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetUCPREN \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ClkPreEnDis \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.UCPREN = ((beMIOS_ClkPreEnDis == TRUE)?1U:0U);
    }
    
}

/******eMIOS_UC_Cn bit fields: UCPRE********************************************/

/* @brief Get Control register: Prescaler bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]ClkPreDiv: Prescaler bits(2 bits)
 *                  0b00: 1(DIV), 0b01: 2(DIV), 0b10: 3(DIV), 0b11: 4(DIV)
 *
 * @note  The UCPRE[0:1] bits select the clock divider value for the
 *          internal prescaler of Unified Channel.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetUCPRE(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.UCPRE));
}

/* @brief Set Control register: Prescaler bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_ClkPreDiv: Prescaler bits(2 bits)
 *                  0b00: 1(DIV), 0b01: 2(DIV), 0b10: 3(DIV), 0b11: 4(DIV)
 *
 * @note  The UCPRE[0:1] bits select the clock divider value for the
 *          internal prescaler of Unified Channel.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetUCPRE \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ClkPreDiv \
)
{
    peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.UCPRE = (uint32)u8eMIOS_ClkPreDiv;
}

/******eMIOS_UC_Cn bit fields: ODISSL*******************************************/

/* @brief Get Control register: Output Disable select bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]OutDisSel: Output Disable select bits(2 bits)
 *                  0b00: Output Disable Input 0,
 *                  0b01: Output Disable Input 1,
 *                  0b10: Output Disable Input 2,
 *                  0b11: Output Disable Input 3
 *
 * @note  The ODISSL[0:1] bits select one of the four output disable input signals.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetODISSL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.ODISSL));
}

/* @brief Set Control register: Output Disable select bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_OutDisSel: Output Disable select bits(2 bits)
 *                  0b00: Output Disable Input 0,
 *                  0b01: Output Disable Input 1,
 *                  0b10: Output Disable Input 2,
 *                  0b11: Output Disable Input 3
 *
 * @note  The ODISSL[0:1] bits select one of the four output disable input signals.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetODISSL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_OutDisSel \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.ODISSL = ((u8eMIOS_OutDisSel == TRUE)?1U:0U);
    }
}

/******eMIOS_UC_Cn bit fields: ODIS*********************************************/

/* @brief Get Control register: Output Disable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]OutDis: Output Disable bit(1 bit)
 *
 * @note  The ODIS bit allows disabling the output pin when running any of
 *          the output modes with the exception of GPIO mode.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetODIS(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.ODIS == 1U)? TRUE:FALSE);
}

/* @brief Set Control register: Output Disable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_OutDis: Output Disable bit(1 bit)
 *
 * @note  The ODIS bit allows disabling the output pin when running any of
 *          the output modes with the exception of GPIO mode.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetODIS \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutDis \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.ODIS = ((beMIOS_OutDis == TRUE)?1U:0U);
    }
    
}

/******eMIOS_UC_Cn bit fields: FREN*********************************************/

/* @brief Get Control register: Freeze Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]FreezeEn: Freeze Enable bit(1 bit)
 *                  0: Normal operation,
 *                  1: Freeze UC registers values
 *
 * @note  The FREN bit, if set and validated by FRZ bit in EMIOS_MCR register
 *          allows the channel to enter freeze state, freezing all registers values
 *          when in debug mode and allowing the MCU to perform debug functions.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetFREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FREN == 1U)? TRUE:FALSE);
}

/* @brief Set Control register: Freeze Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_FreezeEn: Freeze Enable bit(1 bit)
 *                  0: Normal operation,
 *                  1: Freeze UC registers values
 *
 * @note  The FREN bit, if set and validated by FRZ bit in EMIOS_MCR register
 *          allows the channel to enter freeze state, freezing all registers values
 *          when in debug mode and allowing the MCU to perform debug functions.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFREN \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_FreezeEn \
)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FREN = ((beMIOS_FreezeEn == TRUE)?1U:0U);
    }
    
}

/*******************************************************************************/
/*******************eMIOS UC Status register n (eMIOS_UC_Sn)********************/

/******eMIOS_UC_Sn bit fields: FLAG*********************************************/

/* @brief Get Status register: FLAG bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]FLAG(1 bit)
 *              0: FLAG cleared,
 *              1: FLAG set event has occurred
 *
 * @note  The FLAG bit is set when an input capture or a match event
 *          in the comparators occurred.
 *        The FLAG bit must be cleared by writing a 1 to it.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_UC_Sn_GetFLAG(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.FLAG == 1U)? TRUE:FALSE);
}

/* @brief Clear Status register: FLAG bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *
 * @note  The FLAG bit is set when an input capture or a match event
 *          in the comparators occurred.
 *        The FLAG bit must be cleared by writing a 1 to it.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Sn_ClearFLAG(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.FLAG = (uint32)1U;
    }
    
}

/******eMIOS_UC_Sn bit fields: UCOUT********************************************/

/* @brief Get Status register: Unified Channel Output pin bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]UCOUT(1 bit)
 *
 * @note  The UCOUT bit reflects the output pin state.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Sn_GetUCOUT(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.UCOUT));
    }
    return u8eMIOS_ret;
}

/******eMIOS_UC_Sn bit fields: UCIN*********************************************/

/* @brief Get Status register: Unified Channel Input pin bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]UCIN(1 bit)
 *
 * @note  The UCIN bit reflects the input pin state after being filtered
 *          and synchronized.
 * */
LOCAL_INLINE FUNC(uint8, EMIOS_CODE) eMIOS_UC_Sn_GetUCIN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.UCIN));
    }
    return u8eMIOS_ret;
}

/******eMIOS_UC_Sn bit fields: OVFL*********************************************/

/* @brief Get Status register: Overflow bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]Overflow bit(1 bit)
 *              0: No overflow,
 *              1: An overflow had occurred
 *
 * @note  The OVFL bit indicates that an overflow has occurred in the
 *          internal counter.
 *        The OVFL bit must be cleared by software writing a 1 to it.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_UC_Sn_GetOVFL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.OVFL == 1U) ? TRUE : FALSE);
    }
    return beMIOS_ret;
}

/* @brief Clear Status register: Overflow bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *
 * @note  The OVFL bit indicates that an overflow has occurred in the
 *          internal counter.
 *        The OVFL bit must be cleared by software writing a 1 to it.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Sn_ClearOVFL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    /* OVR bit, OVFL bit & FLAG bit can be cleared when write 1 to them */
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.OVFL = (uint32)1U;
    }
}

/******eMIOS_UC_Sn bit fields: OVR**********************************************/

/* @brief Get Status register: Overrun bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]Overrun(1 bit)
 *              0: Overrun has not occurred,
 *              1: Overrun has occurred
 *
 * @note  The OVR bit indicates that FLAG generation occurred when the FLAG bit
 *          was already set.
 *        The OVR bit can be cleared either by clearing the FLAG bit or by
 *          writing a 1 to the OVR bit.
 * */
LOCAL_INLINE FUNC(boolean, EMIOS_CODE) eMIOS_UC_Sn_GetOVR(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.OVR == 1U)?TRUE:FALSE);
}

/* @brief Clear Status register: Overrun bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *
 * @note  The OVR bit indicates that FLAG generation occurred when the FLAG bit
 *          was already set.
 *        The OVR bit can be cleared either by clearing the FLAG bit or by
 *          writing a 1 to the OVR bit.
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_Sn_ClearOVR(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.OVR = (uint32)1U;
}

/*******************************************************************************/
/**************eMIOS UC Alternate Address register n (eMIOS_UC_ALTAn)***********/

/* @brief Get Alternate Address register: ALTA value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]ALTA_Value(24 bits)
 * */
LOCAL_INLINE FUNC(uint32, EMIOS_CODE) eMIOS_UC_ALTAn_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    return ((uint32_t)((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].ALTA.R) & eMIOS_ALTA_ALTA_MASK));
}

/* @brief Set Alternate Address register: ALTA value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u32eMIOS_ALTA_Value(24 bits)
 * */
LOCAL_INLINE FUNC(void, EMIOS_CODE) eMIOS_UC_ALTAn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_ALTA_Value \
)
{
    peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].ALTA.R = ((uint32_t)(u32eMIOS_ALTA_Value & eMIOS_ALTA_ALTA_MASK));
}

/*******************************************************************************
 * API Function declaration.
 *******************************************************************************/

FUNC(status_t, EMIOS_CODE) eMIOS_LLD_MC_Init \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    P2CONST(eMIOS_MC_ParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_ParamPtr \
);

FUNC(status_t, EMIOS_CODE) eMIOS_LLD_MC_SetPeriod \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_Period \
);

FUNC(uint32, EMIOS_CODE) eMIOS_LLD_MC_GetPeriod \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(uint32, EMIOS_CODE) eMIOS_LLD_MC_GetInternalCounter \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

/*******************************************************************************
 * API Function declaration.
 *******************************************************************************/
FUNC(boolean, EMIOS_CODE) eMIOS_DevError_Instance(VAR(uint8, AUTOMATIC) u8eMIOS_Index);

FUNC(boolean, EMIOS_CODE) eMIOS_DevError_ChanNum(VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum);

FUNC(void, EMIOS_CODE) eMIOS_LLD_InitGlobalParam \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    P2CONST(eMIOS_GlobalParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_GlobalParam \
);

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetEnDisGlobal \
(\
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_EnDisGlobal \
);

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetGLOTimebaseEnDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index);

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetGLOPrescalerEnDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index);

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetLowPowerMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_SwitchOnOff \
);

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetLowPowerMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index);

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetFreezeInDebugMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_FreezeStatus \
);

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetFreezeInDebugMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index);

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetFlagSts_Ch \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetChOutputUPDEnDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateEnDis \
);

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetChNumOutUpdateDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(void, EMIOS_CODE) eMIOS_LLD_SetAllChOutUPDEnDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateEnDis \
);

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetAllChOutUpdateDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index);

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_DeInitChannel \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(status_t, EMIOS_CODE) eMIOS_LLD_UC_SetDebugMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_UcFreezeStatus \
);

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetChannelClkEnDis \
(\
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ClkEnDis \
);

FUNC(boolean, EMIOS_CODE) eMIOS_LLD_UC_GetChannelClkDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetDMARequestEn \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(eMIOS_UC_IntDmaType, EMIOS_CODE) eMIOS_LLD_UC_GetDMAModeStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetIntcRequestEn \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetOutputLevel \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgeSel, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgePol \
);

FUNC(uint8, EMIOS_CODE) eMIOS_LLD_UC_GetInputPinStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(uint8, EMIOS_CODE) eMIOS_LLD_UC_GetOutputPinStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_ClearFlag \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
);

#endif /* EMIOS_LLDRIVER_H */

/** @} */
