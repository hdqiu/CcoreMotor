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
*   @file    Mcu.h
*   @version 1.0.1
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifndef MCU_H
#define MCU_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
INCLUDE FILES
====================================================================================================*/
#include "Mcu_Cfg.h"
/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define MCU_VENDOR_ID                     176
#define MCU_AR_MAJOR_VER                  4
#define MCU_AR_MINOR_VER                  4
#define MCU_AR_PATCH_VER                  0
#define MCU_SW_MAJOR_VER                  1
#define MCU_SW_MINOR_VER                  0
#define MCU_SW_PATCH_VER                  1
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_CFG_VENDOR_ID)
#error "NON-MATCHED DATA : MCU_CFG_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_AR_MAJOR_VER != MCU_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_MAJOR_VER"
#endif
#if (MCU_AR_MINOR_VER != MCU_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_MINOR_VER"
#endif
#if (MCU_AR_PATCH_VER != MCU_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_SW_MAJOR_VER != MCU_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_MAJOR_VER"
#endif
#if (MCU_SW_MINOR_VER != MCU_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_MINOR_VER"
#endif
#if (MCU_SW_PATCH_VER != MCU_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_PATCH_VER"
#endif

/*====================================================================================================
DEFINES
====================================================================================================*/

#define MCU_INSTANCE_ID                 0x00

#define MCU_INIT_ID                     0x00
#define MCU_INITRAMSECTION_ID           0x01
#define MCU_INITCLOCK_ID                0x02
#define MCU_DISTRIBUTEPLLCLOCK_ID       0x03
#define MCU_GETPLLSTATUS_ID             0x04
#define MCU_GETRESETREASON_ID           0x05
#define MCU_GETRESETRAWVALUE_ID         0x06
#define MCU_PERFORMRESET_ID             0x07
#define MCU_SETMODE_ID                  0x08
#define MCU_GETVERSIONINFO_ID           0x09
#define MCU_GETRAMSTATE_ID              0x0A
#define MCU_FCCUINIT_ID                 0x0B
#define MCU_CORESYNC_ID                 0x0C
#define MCU_PERIMODESET_ID              0x0D
#define MCU_PERIRESETPEND_ID            0x0E
#define MCU_PERIRESETCLOSE_ID           0x0F
#define MCU_FCCUINIT_CLEARFAULT_ID      0x10

// [SWS_Mcu_00012]: The following errors and exceptions shall be detectable by the MCU module depending on its build version (development/production mode):
#define MCU_E_PARAM_CONFIG              0x0A
#define MCU_E_PARAM_CLOCK               0x0B
#define MCU_E_PARAM_MODE                0x0C
#define MCU_E_PARAM_RAMSECTION          0x0D
#define MCU_E_PLL_NOT_LOCKED            0x0E
#define MCU_E_UNINIT                    0x0F
#define MCU_E_PARAM_POINTER             0x10
#define MCU_E_INIT_FAILED               0x11
#define MCU_E_PARAM_ERR                 0x12

#define MCU_SEMA42_OFFSET               0x08U
#define MCU_CORE_COUNT                  0x04U

#define CORE_ID_0                       0x00U
#define CORE_ID_1                       0x01U
#define CORE_ID_2                       0x02U
#define CORE_ID_3                       0x02U
#define CORE_ID_4                       0x02U
#define CORE_ID_5                       0x02U

#define CORE_NOT_READY                  0x00U
#define CORE_READY                      0x01U

#define MCU_MCME_SAFE                   0x00000004U
#define MCU_MCME_DRUN                   0x00000008U
#define MCU_MCME_RUN0                   0x00000010U
#define MCU_MCME_RUN1                   0x00000020U
#define MCU_MCME_RUN2                   0x00000040U
#define MCU_MCME_RUN3                   0x00000080U
#define MCU_MCME_HALT                   0x00000100U
#define MCU_MCME_STOP                   0x00000400U
#define MCU_MCME_STANDBY                0x00002000U

/* RGM0 */
#define MCU_RGM_PIT_RTC_1               0x80000000U
#define MCU_RGM_PIT_RTC_0               0x40000000U
#define MCU_RGM_SIUL                    0x00008000U
#define MCU_RGM_SIPI_0                  0x00000800U
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
#define MCU_RGM_LFAST_0                 0x00000200U
#define MCU_RGM_EBI_0                   0x00000008U
#endif

/* RGM1 */
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
#define MCU_RGM_MCAN_12                 0x80000000U
#endif
#if ((MCU_HARDVER == 5))
#define MCU_RGM_CAN_RAM2_CTR            0x40000000U
#endif
#define MCU_RGM_ADCSD_0                 0x10000000U
#define MCU_RGM_ADCSD_2                 0x08000000U
#define MCU_RGM_ADCSD_4                 0x04000000U
#define MCU_RGM_ADCSD_6                 0x02000000U
#define MCU_RGM_ADCSD_8                 0x01000000U
#if ((MCU_HARDVER == 5))
#define MCU_RGM_ADCSD_10                0x00800000U
#define MCU_RGM_ADCSD_12                0x00400000U
#define MCU_RGM_TTCAN0                  0x00200000U
#define MCU_RGM_TTCAN1                  0x00100000U
#endif
#define MCU_RGM_CRC_0                   0x00000040U
#define MCU_RGM_DMAMUX_0                0x00000010U


/* RGM2 */
#if ((MCU_HARDVER == 5))
#define MCU_RGM_DSPI_8                  0x80000000U
#define MCU_RGM_DSPI_10                 0x40000000U
#endif
#define MCU_RGM_DSPI_12                 0x20000000U
#define MCU_RGM_LINFlexD_0              0x10000000U
#define MCU_RGM_LINFlexD_1              0x08000000U
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
#define MCU_RGM_LINFlexD_3              0x04000000U
#endif
#define MCU_RGM_LINFlexD_14             0x00200000U
#define MCU_RGM_LINFlexD_16             0x00100000U
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
#define MCU_RGM_TTCAN2                  0x00020000U
#define MCU_RGM_MCAN_9                  0x00010000U
#define MCU_RGM_MCAN_10                 0x00008000U
#endif
#define MCU_RGM_MCAN_8                  0x00004000U
#define MCU_RGM_MCAN_7                  0x00002000U
#define MCU_RGM_MCAN_6                  0x00001000U
#define MCU_RGM_MCAN_5                  0x00000800U
#define MCU_RGM_CAN_RAM0_CTR            0x00000400U
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 3) || (MCU_HARDVER == 4))
#define MCU_RGM_TTCAN0                  0x00000100U
#endif
#if ((MCU_HARDVER == 3))
#define MCU_RGM_TTCAN1                  0x00000080U
#endif
#define MCU_RGM_MCAN_1                  0x00000040U
#define MCU_RGM_MCAN_2                  0x00000020U
#define MCU_RGM_MCAN_3                  0x00000010U
#define MCU_RGM_MCAN_4                  0x00000008U
#define MCU_RGM_CAN_RAM1_CTR            0x00000004U
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
#define MCU_RGM_MCAN_11                 0x00000001U
#endif

/* RGM3 */
#define MCU_RGM_ADCSAR_0                0x80000000U
#if ((MCU_HARDVER == 5))
#define MCU_RGM_ADCSAR_11               0x80000000U
#define MCU_RGM_ADCSAR_12               0x80000000U
#endif
#define MCU_RGM_ADCSAR_4                0x08000000U
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 3) || (MCU_HARDVER == 4))
#define MCU_RGM_ADCSAR_b                0x00010000U
#endif
#if ((MCU_HARDVER == 5))
#define MCU_RGM_ACMP0                   0x00200000U
#define MCU_RGM_ACMP1                   0x00100000U
#define MCU_RGM_ACMP2                   0x00080000U
#define MCU_RGM_ACMP3                   0x00040000U
#define MCU_RGM_DAC_0                   0x00020000U
#endif
#define MCU_RGM_PSI5_0                  0x00008000U
#if ((MCU_HARDVER == 5))
#define MCU_RGM_DSPI_19                 0x00004000U
#define MCU_RGM_DSPI_20                 0x00002000U
#define MCU_RGM_DSPI_21                 0x00001000U
#endif
#define MCU_RGM_FLEXRAY_0               0x00000800U
#define MCU_RGM_SENT_0                  0x00000100U
#if ((MCU_HARDVER == 5))
#define MCU_RGM_DSPI_14                 0x00000080U
#define MCU_RGM_DSPI_15                 0x00000040U
#endif
#define MCU_RGM_IIC_0                   0x00000020U
#define MCU_RGM_DSPI_0                  0x00000008U
#define MCU_RGM_DSPI_1                  0x00000004U
#define MCU_RGM_DSPI_4                  0x00000002U
#define MCU_RGM_DSPI_6                  0x00000001U

/* RGM4 */
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
#define MCU_RGM_CANFD12                 0x80000000U
#define MCU_RGM_CANFD11                 0x40000000U
#define MCU_RGM_CANFD10                 0x20000000U
#define MCU_RGM_CANFD9                  0x10000000U
#define MCU_RGM_CANFD8                  0x08000000U
#define MCU_RGM_CANFD7                  0x04000000U
#define MCU_RGM_CANFD6                  0x02000000U
#define MCU_RGM_CANFD5                  0x01000000U
#define MCU_RGM_CANFD4                  0x00800000U
#define MCU_RGM_CANFD3                  0x00400000U
#define MCU_RGM_CANFD2                  0x00200000U
#define MCU_RGM_CANFD1                  0x00100000U
#endif
#if ((MCU_HARDVER == 5))
#define MCU_RGM_DSPI_16                 0x00008000U
#define MCU_RGM_DSPI_17                 0x00004000U
#define MCU_RGM_DSPI_18                 0x00002000U
#define MCU_RGM_DSPI_7                  0x00001000U
#define MCU_RGM_DSPI_9                  0x00000800U
#define MCU_RGM_DSPI_11                 0x00000400U
#define MCU_RGM_DSPI_13                 0x00000200U
#define MCU_RGM_SPORT                   0x00000020U
#endif
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
#define MCU_RGM_EMIOS1                  0x00000010U
#define MCU_RGM_EMIOS0                  0x00000008U
#define MCU_RGM_ETPU_C                  0x00000004U
#define MCU_RGM_ETPU                    0x00000002U
#endif
#define MCU_RGM_GTMINT                  0x00000001U

/* RGM5 */
#define MCU_RGM_ADCSD_1                 0x10000000U
#define MCU_RGM_ADCSD_3                 0x08000000U
#define MCU_RGM_ADCSD_5                 0x04000000U
#define MCU_RGM_ADCSD_7                 0x02000000U
#define MCU_RGM_ADCSD_9                 0x01000000U
#if ((MCU_HARDVER == 5))
#define MCU_RGM_ADCSD_11                0x00800000U
#define MCU_RGM_ADCSD_13                0x00400000U
#endif
#define MCU_RGM_FCCU                    0x00000200U
#define MCU_RGM_CRC_1                   0x00000040U
#define MCU_RGM_PSI5_S_0                0x00000004U

/* RGM6 */
#define MCU_RGM_LINFlexD_2              0x10000000U
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
#define MCU_RGM_LINFlexD_7              0x08000000U
#define MCU_RGM_LINFlexD_8              0x04000000U
#define MCU_RGM_LINFlexD_9              0x02000000U
#define MCU_RGM_LINFlexD_10             0x01000000U
#define MCU_RGM_LINFlexD_11             0x00800000U
#define MCU_RGM_LINFlexD_12             0x00400000U
#endif
#define MCU_RGM_LINFlexD_15             0x00200000U
#if ((MCU_HARDVER == 5))
#define MCU_RGM_ACMP4                   0x00100000U
#define MCU_RGM_ACMP5                   0x00080000U
#define MCU_RGM_ACMP6                   0x00040000U
#define MCU_RGM_ACMP7                   0x00020000U
#define MCU_RGM_DAC_1                   0x00010000U
#endif


/* RGM7 */
#define MCU_RGM_ADCSAR_1                0x40000000U
#define MCU_RGM_ADCSAR_2                0x20000000U
#define MCU_RGM_ADCSAR_3                0x10000000U
#define MCU_RGM_ADCSAR_5                0x04000000U
#define MCU_RGM_ADCSAR_6                0x02000000U
#define MCU_RGM_ADCSAR_7                0x01000000U
#define MCU_RGM_ADCSAR_8                0x00800000U
#define MCU_RGM_ADCSAR_9                0x00400000U
#define MCU_RGM_ADCSAR_10               0x00200000U
#define MCU_RGM_PSI5_1                  0x00008000U
#define MCU_RGM_FLEXRAY_1               0x00000800U
#define MCU_RGM_SENT_1                  0x00000100U
#define MCU_RGM_IIC_1                   0x00000020U
#define MCU_RGM_DSPI_2                  0x00000008U
#define MCU_RGM_DSPI_3                  0x00000004U
#define MCU_RGM_DSPI_5                  0x00000002U

/*====================================================================================================
ENUMS
====================================================================================================*/

/* [SWS_Mcu_00250] */
typedef enum
{
    MCU_PLL_STATUS_UNDEFINED = 0,
    MCU_PLL_LOCKED,
    MCU_PLL_UNLOCKED,
}Mcu_PllStatusType;
// [SWS_Mcu_00230]: The type Mcu_PllStatusType is the type of the return value of the function Mcu_GetPllStatus.()
// [SWS_Mcu_00231]: The type of Mcu_PllStatusType is an enumeration with the following values: MCU_PLL_LOCKED, MCU_PLL_UNLOCKED, MCU_PLL_STATUS_UNDEFINED.()

typedef enum
{
    MCU_FUNC_RESET = 0x0U,      /**<  Functional Reset type. */
    MCU_DEST_RESET              /**<  Destructive Reset type. */
} Mcu_Rgm_ResetType;

/* [SWS_Mcu_00253] */
typedef enum
{
    /* 'Destructive' Event Status Register (RGM_DES) */
    MCU_POWER_ON_RESET=0x00U,   /**<  Power-On reset RGM_DES[F_POR]. */
    MCU_EXT_POWER_ON_RESET,     /**<  External power-on reset RGM_DES[F_PORST]. */
    MCU_SOFT_DEST_RESET,        /**<  Software 'destructive' reset RGM_DES[F_SOFT_DEST]. */
    MCU_FFRR_RESET,             /**<  FCCU failure to react reset RGM_DES[F_FFRR]. */
    MCU_SUF_RESET,              /**<  STCU unrecoverable fault RGM_DES[F_SUF]. */
    MCU_EDR_RESET,              /**<  Functional reset escalation RGM_DES[F_EDR]. */
    MCU_FIF_RESET,              /**<  Flash initialization failure reset RGM_DES[F_FIF]. */
    MCU_JTAG_DEST_RESET,        /**<  JTAG 'destructive' reset RGM_DES[F_JTAG_DEST]. */
    MCU_SSCM_DEST_RESET,        /**<  HSM 'destructive' reset RGM_DES[F_SSCM_DEST]. */
    MCU_HSM_DEST_RESET,         /**<  HSM 'destructive' reset RGM_DES[F_HSM_DEST]. */
    MCU_TSR_DEST_RESET,         /**<  Temperature sensor 'destructive' reset RGM_DES[F_TSR_DEST]. */
    MCU_VOR_DEST_RESET,         /**<  Voltage out of range 'destructive' reset RGM_DES[F_VOR_DEST]. */
    /* 'Functional' Event Status Register (RGM_FES) */
    /* MCU_ESR0_RESET, */             /**<  ESR0 External Reset. RGM_FES[F_ESR0]. */
    /* MCU_ESR1_RESET, */             /**<  ESR1 External Reset. RGM_FES[F_ESR1]. */
    /* MCU_ST_DONE_RESET, */          /**<  Self test completed. RGM_FES[F_ST_DONE]. */
    MCU_SOFT_FUNC_RESET,        /**<  Software 'functional' reset. RGM_FES[F_SOFT_FUNC]. */
    MCU_FCCU_HARD_RESET,        /**<  FCCU hard reaction reset. RGM_FES[F_FCCU_HARD]. */
    MCU_FCCU_SOFT_RESET,        /**<  FCCU soft reaction. RGM_FES[F_FCCU_SOFT]. */
    MCU_JTAG_FUNC_RESET,        /**<  JTAG 'functional' reset. RGM_FES[F_JTAG_FUNC]. */
    MCU_HSM_FUNC_RESET,         /**<  HSM 'functional' reset. RGM_FES[F_HSM_FUNC]. */
    MCU_TSR_FUNC_RESET,         /**<  Temperature sensor 'functional' reset. RGM_FES[F_TSR_FUNC]. */
    MCU_VOR_FUNC_RESET,         /**<  Voltage out of range 'functional' reset. RGM_FES[F_VOR_FUNC]. */
    MCU_NO_RESET_REASON,                 /**<  No reset reason found */
    MCU_MULTIPLE_RESET_REASON,           /**<  More than one reset events are logged except "Power on event" */
    MCU_RESET_UNDEFINED         /**<  Undefined reset source. */
} Mcu_ResetType;

// [SWS_Mcu_00234]: The type Mcu_ResetType, represents the different reset that a specified MCU can have.()
// [SWS_Mcu_00134]: The MCU module shall provide at least the values MCU_POWER_ON_RESET and MCU_RESET_UNDEFINED for the enumeration Mcu_ResetType.()


/* [SWS_Mcu_00256] */
typedef enum
{
    MCU_RAMSTATE_INVALID = 0U,
    MCU_RAMSTATE_VALID
}Mcu_RamStateType;

/*! @brief Clock names. */
typedef enum {
    /* peripheral name */
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 3) || (MCU_HARDVER == 4))
    MC_ME_PCTL_EBI0_INDEX                    = 3U,
    MC_ME_PCTL_LFAST_INDEX                   = 9U,
    #endif
    MC_ME_PCTL_SIPI0_INDEX                   = 11U,/*PS0*/
    MC_ME_PCTL_SIUL_INDEX                    = 15U,/*PS0*/
    MC_ME_PCTL_PIT_RTC_0_INDEX               = 30U,/*PS0*/
    MC_ME_PCTL_PIT_RTC_1_INDEX               = 31U,/*PS0*/
    MC_ME_PCTL_DMAMUX0_INDEX                 = 36U,/*PS1*/
    MC_ME_PCTL_CRC_0_INDEX                   = 38U,/*PS1*/
    #if ((MCU_HARDVER == 5))
    MC_ME_PCTL_GMAC_INDEX                    = 44U,/*PS1*/
    MC_ME_PCTL_ADCSD_12_INDEX                = 54U,/*PS1*/
    MC_ME_PCTL_ADCSD_10_INDEX                = 55U,/*PS1*/
    #endif
    MC_ME_PCTL_ADCSD_8_INDEX                 = 56U,/*PS1*/
    MC_ME_PCTL_ADCSD_6_INDEX                 = 57U,/*PS1*/
    MC_ME_PCTL_ADCSD_4_INDEX                 = 58U,/*PS1*/
    MC_ME_PCTL_ADCSD_2_INDEX                 = 59U,/*PS1*/
    MC_ME_PCTL_ADCSD_0_INDEX                 = 60U,/*PS1*/
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    MC_ME_PCTL_CAM_RAM_2_INDEX               = 62U,/*PS1*/
    MC_ME_PCTL_MCAN12_INDEX                  = 63U,/*PS1*/
    MC_ME_PCTL_MCAN11_INDEX                  = 64U,/*PS2*/
    MC_ME_PCTL_CAM_RAM_1_INDEX               = 66U,/*PS2*/
    #endif
    MC_ME_PCTL_MCAN4_INDEX                   = 67U,/*PS2*/
    MC_ME_PCTL_MCAN3_INDEX                   = 68U,/*PS2*/
    MC_ME_PCTL_MCAN2_INDEX                   = 69U,/*PS2*/
    MC_ME_PCTL_MCAN1_INDEX                   = 70U,/*PS2*/
    MC_ME_PCTL_TTCAN_1_INDEX                 = 71U,/*PS2*/
    MC_ME_PCTL_TTCAN_0_INDEX                 = 72U,/*PS2*/
    MC_ME_PCTL_CAN_RAM_1_CTRL_INDEX          = 73U,/*PS2*/
    MC_ME_PCTL_CAN_RAM_0_CTRL_INDEX          = 74U,/*PS2*/
    MC_ME_PCTL_MCAN5_INDEX                   = 75U,/*PS2*/
    MC_ME_PCTL_MCAN6_INDEX                   = 76U,/*PS2*/
    MC_ME_PCTL_MCAN7_INDEX                   = 77U,/*PS2*/
    MC_ME_PCTL_MCAN8_INDEX                   = 78U,/*PS2*/
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    MC_ME_PCTL_MCAN10_INDEX                  = 79U,/*PS2*/
    MC_ME_PCTL_MCAN9_INDEX                   = 80U,/*PS2*/
    MC_ME_PCTL_TTCAN_2_INDEX                 = 81U,/*PS2*/
    MC_ME_PCTL_CAN_SAMPLER_INDEX             = 82U,/*PS2*/
    MC_ME_PCTL_RTC_INDEX                     = 83U,/*PS2*/
    #endif
    MC_ME_PCTL_LINFlexD_16_INDEX             = 84U,/*PS2*/
    MC_ME_PCTL_LINFlexD_14_INDEX             = 85U,/*PS2*/
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    MC_ME_PCTL_LINFlexD_6_INDEX              = 87U,/*PS2*/
    MC_ME_PCTL_LINFlexD_5_INDEX              = 88U,/*PS2*/
    MC_ME_PCTL_LINFlexD_4_INDEX              = 89U,/*PS2*/
    MC_ME_PCTL_LINFlexD_3_INDEX              = 90U,/*PS2*/
    #endif
    MC_ME_PCTL_LINFlexD_1_INDEX              = 91U,/*PS2*/
    MC_ME_PCTL_LINFlexD_0_INDEX              = 92U,/*PS2*/
    MC_ME_PCTL_DSPI_12_INDEX                 = 93U,/*PS2*/
    #if ((MCU_HARDVER == 5))
    MC_ME_PCTL_DSPI_10_INDEX                 = 94U,/*PS2*/
    MC_ME_PCTL_DSPI_8_INDEX                  = 95U,/*PS2*/
    #endif
    MC_ME_PCTL_DSPI_6_INDEX                  = 96U,/*PS3*/
    MC_ME_PCTL_DSPI_4_INDEX                  = 97U,/*PS3*/
    MC_ME_PCTL_DSPI_1_INDEX                  = 98U,/*PS3*/
    MC_ME_PCTL_DSPI_0_INDEX                  = 99U,/*PS3*/
    MC_ME_PCTL_IIC_0_INDEX                   = 101U,/*PS3*/
    #if ((MCU_HARDVER == 5))
    MC_ME_PCTL_DSPI_15_INDEX                 = 102U,/*PS3*/
    MC_ME_PCTL_DSPI_14_INDEX                 = 103U,/*PS3*/
    #endif
    MC_ME_PCTL_SENT_0_INDEX                  = 104U,/*PS3*/
    MC_ME_PCTL_FLEXRAY_0_INDEX               = 107U,/*PS3*/
    #if ((MCU_HARDVER == 5))
    MC_ME_PCTL_DSPI_21_INDEX                 = 108U,/*PS3*/
    MC_ME_PCTL_DSPI_20_INDEX                 = 109U,/*PS3*/
    MC_ME_PCTL_DSPI_19_INDEX                 = 110U,/*PS3*/
    #endif
    MC_ME_PCTL_PSI5_0_INDEX                  = 111U,/*PS3*/
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 3) || (MCU_HARDVER == 4))
    MC_ME_PCTL_ADCSAR_b_INDEX                = 112U,
    #endif
    #if ((MCU_HARDVER == 5))
    MC_ME_PCTL_DAC_0_INDEX                   = 113U,/*PS3*/
    MC_ME_PCTL_ACMP3_INDEX                   = 114U,/*PS3*/
    MC_ME_PCTL_ACMP2_INDEX                   = 115U,/*PS3*/
    MC_ME_PCTL_ACMP1_INDEX                   = 116U,/*PS3*/
    MC_ME_PCTL_ACMP0_INDEX                   = 117U,/*PS3*/
    #endif
    MC_ME_PCTL_ADCSAR_4_INDEX                = 123U,/*PS3*/
    MC_ME_PCTL_ADCSAR_12_INDEX               = 125U,/*PS3*/
    MC_ME_PCTL_ADCSAR_10_INDEX               = 126U,/*PS3*/
    MC_ME_PCTL_ADCSAR_0_INDEX                = 127U,/*PS3*/
    MC_ME_PCTL_GTMINT_INDEX                  = 128U,/*PS4*/
//    MC_ME_PCTL_ETPU_INDEX                    = 129U,/*PS4*/
//    MC_ME_PCTL_ETPU_C_INDEX                  = 130U,/*PS4*/
    MC_ME_PCTL_EMIOS_0_INDEX                 = 131U,/*PS4*/
//    MC_ME_PCTL_EMIOS_1_INDEX                 = 132U,/*PS4*/
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
//    MC_ME_PCTL_I2S_0_INDEX                   = 133U,/*PS4*/
//    MC_ME_PCTL_I2S_1_INDEX                   = 134U,/*PS4*/
	MC_ME_PCTL_SPORT_INDEX                   = 133U,/*PS4*/
	MC_ME_PCTL_SDEMMC_INDEX                  = 135U,/*PS4*/
	MC_ME_PCTL_DPSI_13_INDEX                 = 137U,/*PS4*/
	MC_ME_PCTL_DPSI_11_INDEX                 = 138U,/*PS4*/
	MC_ME_PCTL_DPSI_9_INDEX                  = 139U,/*PS4*/
	MC_ME_PCTL_DPSI_7_INDEX                  = 140U,/*PS4*/
	MC_ME_PCTL_DPSI_18_INDEX                 = 141U,/*PS4*/
	MC_ME_PCTL_DPSI_17_INDEX                 = 142U,/*PS4*/
	MC_ME_PCTL_DPSI_16_INDEX                 = 143U,/*PS4*/

    MC_ME_PCTL_CMU_INDEX                     = 147U,/*PS4*/
    MC_ME_PCTL_CANFD_1_INDEX                 = 148U,/*PS4*/
//    MC_ME_PCTL_CANFD_2_INDEX                 = 149U,/*PS4*/
//    MC_ME_PCTL_CANFD_3_INDEX                 = 150U,/*PS4*/
//    MC_ME_PCTL_CANFD_4_INDEX                 = 151U,/*PS4*/
//    MC_ME_PCTL_CANFD_5_INDEX                 = 152U,/*PS4*/
//    MC_ME_PCTL_CANFD_6_INDEX                 = 153U,/*PS4*/
//    MC_ME_PCTL_CANFD_7_INDEX                 = 154U,/*PS4*/
//    MC_ME_PCTL_CANFD_8_INDEX                 = 155U,/*PS4*/
    MC_ME_PCTL_CANFD_9_INDEX                 = 156U,/*PS4*/
//    MC_ME_PCTL_CANFD_10_INDEX                = 157U,/*PS4*/
//    MC_ME_PCTL_CANFD_11_INDEX                = 158U,/*PS4*/
//    MC_ME_PCTL_CANFD_12_INDEX                = 159U,/*PS4*/
    #endif
    MC_ME_PCTL_PSI5_S_0_INDEX                = 162U,/*PS5*/
    MC_ME_PCTL_CRC_1_INDEX                   = 166U,/*PS5*/
    MC_ME_PCTL_ADCSD_13_INDEX                = 182U,/*PS5*/
    MC_ME_PCTL_ADCSD_11_INDEX                = 183U,/*PS5*/
    MC_ME_PCTL_ADCSD_9_INDEX                 = 184U,/*PS5*/
    MC_ME_PCTL_ADCSD_7_INDEX                 = 185U,/*PS5*/
    MC_ME_PCTL_ADCSD_5_INDEX                 = 186U,/*PS5*/
    MC_ME_PCTL_ADCSD_3_INDEX                 = 187U,/*PS5*/
    MC_ME_PCTL_ADCSD_1_INDEX                 = 188U,/*PS5*/
    MC_ME_PCTL_DAC_1_INDEX                   = 208U,/*PS6*/
    MC_ME_PCTL_ACMP_7_INDEX                  = 209U,/*PS6*/
	MC_ME_PCTL_ACMP_6_INDEX                  = 210U,/*PS6*/
	MC_ME_PCTL_ACMP_5_INDEX                  = 211U,/*PS6*/
	MC_ME_PCTL_ACMP_4_INDEX                  = 212U,/*PS6*/
    MC_ME_PCTL_LINFlexD_15_INDEX             = 213U,/*PS6*/
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    MC_ME_PCTL_LINFlexD_12_INDEX             = 214U,/*PS6*/
    MC_ME_PCTL_LINFlexD_11_INDEX             = 215U,/*PS6*/
    MC_ME_PCTL_LINFlexD_10_INDEX             = 216U,/*PS6*/
    MC_ME_PCTL_LINFlexD_9_INDEX              = 217U,/*PS6*/
    MC_ME_PCTL_LINFlexD_8_INDEX              = 218U,/*PS6*/
    MC_ME_PCTL_LINFlexD_7_INDEX              = 219U,/*PS6*/
    #endif
    MC_ME_PCTL_LINFlexD_2_INDEX              = 220U,/*PS6*/
    MC_ME_PCTL_DSPI_5_INDEX                  = 225U,/*PS7*/
    MC_ME_PCTL_DSPI_3_INDEX                  = 226U,/*PS7*/
    MC_ME_PCTL_DSPI_2_INDEX                  = 227U,/*PS7*/
    MC_ME_PCTL_IIC_1_INDEX                   = 229U,/*PS7*/
    MC_ME_PCTL_SENT_1_INDEX                  = 232U,/*PS7*/
    MC_ME_PCTL_FLEXRAY_1_INDEX               = 235U,/*PS7*/
//    MC_ME_PCTL_PSI5_1_INDEX                  = 239U,/*PS7*/
//    MC_ME_PCTL_ADCSAR_10_INDEX               = 245U,/*PS7*/
    MC_ME_PCTL_ADCSAR_9_INDEX                = 246U,/*PS7*/
    MC_ME_PCTL_ADCSAR_8_INDEX                = 247U,/*PS7*/
    MC_ME_PCTL_ADCSAR_7_INDEX                = 248U,/*PS7*/
    MC_ME_PCTL_ADCSAR_6_INDEX                = 249U,/*PS7*/
    MC_ME_PCTL_ADCSAR_5_INDEX                = 250U,/*PS7*/
    MC_ME_PCTL_ADCSAR_3_INDEX                = 252U,/*PS7*/
    MC_ME_PCTL_ADCSAR_2_INDEX                = 253U,/*PS7*/
    MC_ME_PCTL_ADCSAR_1_INDEX                = 254U,/*PS7*/

//    MC_ME_PCTL_TMEP0                         = 61U,/*PS2*/
//    MC_ME_PCTL_TMEP1                         = 65U,/*PS3*/

    MC_ME_PCTLn_COUNT                        = 256U,
} Mcu_McMePeriNameType;

typedef enum
{
    RGM_PIT_RTC_1,
    RGM_PIT_RTC_0,
    RGM_SIUL,
    RGM_SIPI_0,
    RGM_LFAST_0,
    RGM_EBI_0,
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    RGM_MCAN_12,
    #endif
    RGM_ADCSD_0,
    RGM_ADCSD_2,
    RGM_ADCSD_4,
    RGM_ADCSD_6,
    RGM_ADCSD_8,
    RGM_CRC_0,
    RGM_DMAMUX_0,
    RGM_DSPI_12,
    RGM_LINFlexD_0,
    RGM_LINFlexD_1,
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    RGM_LINFlexD_3,
    #endif
    RGM_LINFlexD_14,
    RGM_LINFlexD_16,
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    RGM_TTCAN2,
    RGM_MCAN_9,
    RGM_MCAN_10,
    #endif
    RGM_MCAN_8,
    RGM_MCAN_7,
    RGM_MCAN_6,
    RGM_MCAN_5,
    RGM_CAN_RAM_CTR,
    RGM_TTCAN,
    #if (MCU_HARDVER == 3)
    RGM_TTCAN1,
    #endif
    RGM_MCAN_1,
    RGM_MCAN_2,
    RGM_MCAN_3,
    RGM_MCAN_4,
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    RGM_CAN_RAM1_CTR,
    RGM_MCAN_11,
    #endif
    RGM_ADCSAR_0,
    RGM_ADCSAR_4,
    RGM_ADCSAR_b,
    RGM_PSI5_0,
    RGM_FLEXRAY_0,
    RGM_SENT_0,
    RGM_IIC_0,
    RGM_DSPI_0,
    RGM_DSPI_1,
    RGM_DSPI_4,
    RGM_DSPI_6,
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    RGM_CANFD12,
    RGM_CANFD11,
    RGM_CANFD10,
    RGM_CANFD9,
    RGM_CANFD8,
    RGM_CANFD7,
    RGM_CANFD6,
    RGM_CANFD5,
    RGM_CANFD4,
    RGM_CANFD3,
    RGM_CANFD2,
    RGM_CANFD1,
    RGM_EMIOS1,
    RGM_EMIOS0,
    RGM_ETPU_C,
    RGM_ETPU,
    #endif
    RGM_GTMINT,
    RGM_ADCSD_1,
    RGM_ADCSD_3,
    RGM_ADCSD_5,
    RGM_ADCSD_7,
    RGM_ADCSD_9,
    RGM_FCCU,
    RGM_CRC_1,
    RGM_PSI5_S_0,
    RGM_LINFlexD_2,
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    RGM_LINFlexD_7,
    RGM_LINFlexD_8,
    RGM_LINFlexD_9,
    RGM_LINFlexD_10,
    RGM_LINFlexD_11,
    RGM_LINFlexD_12,
    #endif
    RGM_LINFlexD_15,
    RGM_ADCSAR_1,
    RGM_ADCSAR_2,
    RGM_ADCSAR_3,
    RGM_ADCSAR_5,
    RGM_ADCSAR_6,
    RGM_ADCSAR_7,
    RGM_ADCSAR_8,
    RGM_ADCSAR_9,
    RGM_ADCSAR_10,
    RGM_PSI5_1,
    RGM_FLEXRAY_1,
    RGM_SENT_1,
    RGM_IIC_1,
    RGM_DSPI_2,
    RGM_DSPI_3,
    RGM_DSPI_5,
    MC_RGM_ALL
}Mcu_RgmPeriRstType;

typedef enum
{
    SELECT_LP_PC0 = 0U,
    SELECT_LP_PC1 = 1U,
    SELECT_LP_PC2 = 2U,
    SELECT_LP_PC3 = 3U,
    SELECT_LP_PC4 = 4U,
    SELECT_LP_PC5 = 5U,
    SELECT_LP_PC6 = 6U,
    SELECT_LP_PC7 = 7U,
} Mcu_McMeLPModeType;

typedef enum
{
    SELECT_RUN_PC0 = 0U,
    SELECT_RUN_PC1 = 1U,
    SELECT_RUN_PC2 = 2U,
    SELECT_RUN_PC3 = 3U,
    SELECT_RUN_PC4 = 4U,
    SELECT_RUN_PC5 = 5U,
    SELECT_RUN_PC6 = 6U,
    SELECT_RUN_PC7 = 7U,
} Mcu_McMeRunModeType;

/*!
 * @brief Peripheral configuration enum. Used to specify one of the available peripheral configurations.
 * Implements Mcu_McMePeriConfigType_Class
 */
typedef enum
{
    MC_ME_PERIPH_CONFIG_0,              /*!< Peripheral configuration 0 */
    MC_ME_PERIPH_CONFIG_1,              /*!< Peripheral configuration 1 */
    MC_ME_PERIPH_CONFIG_2,              /*!< Peripheral configuration 2 */
    MC_ME_PERIPH_CONFIG_3,              /*!< Peripheral configuration 3 */
    MC_ME_PERIPH_CONFIG_4,              /*!< Peripheral configuration 4 */
    MC_ME_PERIPH_CONFIG_5,              /*!< Peripheral configuration 5 */
    MC_ME_PERIPH_CONFIG_6,              /*!< Peripheral configuration 6 */
    MC_ME_PERIPH_CONFIG_7,              /*!< Peripheral configuration 7 */
} Mcu_McMePeriConfigType;

/*!
 * @brief XOSC bypass type.
 * Implements Mcu_XoscBypassType_Class
 */
typedef enum
{
    XOSC_USE_CRYSTAL              = 0U,
    XOSC_USE_EXTAL                = 1U,
    XOSC_SINGLE_ENDED_BYPASS_MODE = 2U,
    XOSC_DIFFERENTIAL_BYPASS_MODE = 3U,
}Mcu_XoscBypassType;

/*!
 * @brief Modulation mode.
 * Implements Mcu_PlldigModType_Class
 */
typedef enum
{
    CENTRE_SPREAD_MODULATION       = 0U,
    DOWN_SPREAD_MODULATION         = 1U,
}Mcu_PlldigModType;

typedef enum
{
    me_mc_reset_mode      = 0x0,
    me_mc_test_mode       = 0x1,
    me_mc_safe_mode       = 0x2,
    me_mc_drun_mode       = 0x3,
    me_mc_run0_mode       = 0x4,
    me_mc_run1_mode       = 0x5,
    me_mc_run2_mode       = 0x6,
    me_mc_run3_mode       = 0x7,
    me_mc_halt0_mode      = 0x8,
    me_mc_stop0_mode      = 0xA,
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    me_mc_standby_mode    = 0xD,
    #endif
    me_mc_reset_des_mode  = 0xF, 
    me_mc_mode_notchange  = 0xFF,
}Mcu_McModeType;

#if MCU_FCCU_ENABLE == STD_ON
/*
 * @brief FCCU lock type definitions
 */
typedef enum {
    FCCU_TRANSIENTLY_UNLOCK = 0U,    /* No lock on the configuration */
    FCCU_TRANSIENTLY_LOCK   = 1U,    /* Transiently lock on the configuration */
    FCCU_PERANENTLY_LOCK    = 2U     /* Permanently lock on the configuration */
} Mcu_FccuLockType;

/*
 * @brief FCCU IRQ type definitions
 */
typedef enum {
    FCCU_IRQ_NONE       = 0U,    /* No Interrupts are configured */
    FCCU_IRQ_CFG_TO_IEN = 1U,    /* Configuration time-out interrupt enabled */
} Mcu_FccuIrqType;

/*
 * @brief FCCU recoverable fault definitions
 */
typedef enum {
    FCCU_RF_HW_RECOVERABLE_FAULT = 0U,
    FCCU_RF_SW_RECOVERABLE_FAULT = 1U
} Mcu_FccuRecoveryType;

/*
 * @brief FCCU recoverable fault state definitions
 */
typedef enum {
    FCCU_RFS_NO_RESET    = 0U,
    FCCU_RFS_SHORT_RESET = 1U,
    FCCU_RFS_LONG_RESET  = 2U
} Mcu_FccuReactionType;

/*
 * @brief FCCU EOUT control definitions
 */
typedef enum {
    FCCU_EP_INDEPENDENT_ABOVE_SW = 0U,
    FCCU_EP_FAULTY_STATE         = 1U,
    FCCU_EP_OK_STATE             = 3U
} fccu_ep_control_t;

/*
 * @brief FCCU EOUT output definitions
 */
typedef enum {
    FCCU_EP_OUTPUT_OPEN_DRAIN = 0U,
    FCCU_EP_OUTPUT_PUSH_PULL  = 1U
} fccu_ep_output_t;


typedef enum {
    FCCU_EOUT_FOP_VARIABLE    = 0U,
    FCCU_EOUT_FOP_FIXED_61HZ  = 1U
} fccu_eout_fop_t;

/*
 * @brief FCCU EOUT protocol definitions
 */
typedef enum {
    FCCU_EOUT_PROTOCOL_SLOW_SM = 0U,
    FCCU_EOUT_PROTOCOL_FAST_SM = 1U
} fccu_eout_sm_t;

/*
 * @brief FCCU EOUT polar select definitions
 */
typedef enum {
    FCCU_EOUT_0_LOW_1_HIGH  = 0U,
    FCCU_EOUT_0_HIGH_0_LOW  = 1U
} fccu_eout_ps_t;

/*
 * @brief FCCU EOUT Fom definitions
 */
typedef enum {
    FCCU_FOM_DUAL_RAIL      = 0U,
    FCCU_FOM_TIME_SWITCHING = 1U,
    FCCU_FOM_BI_STABLE      = 2U,
    FCCU_FOM_TEST_0         = 5U,
    FCCU_FOM_TEST_1         = 6U,
    FCCU_FOM_TEST_2         = 7U
} fccu_eout_fom_t;

/*
 * @brief FCCU EOUT output frequency definitions
 */
typedef enum {
    FCCU_EOUT_EOF_61HZ   = 63U,
    FCCU_EOUT_EOF_122HZ  = 63U,
    FCCU_EOUT_EOF_244HZ  = 31U,
    FCCU_EOUT_EOF_488HZ  = 15U,
    FCCU_EOUT_EOF_976HZ  = 7U,
    FCCU_EOUT_EOF_1952HZ = 3U,
    FCCU_EOUT_EOF_3904HZ = 1U,
    FCCU_EOUT_EOF_7808HZ = 0U
} fccu_eout_eof_t;

#endif
/*====================================================================================================
TYPEDEFS
====================================================================================================*/

/* [SWS_Mcu_00251] */
typedef uint32 Mcu_ClockType;
// [SWS_Mcu_00232]: The type Mcu_ClockType defines the identification (ID) for clock setting configured via the configuration structure.()
// [SWS_Mcu_00233]: The type shall be uint8, uint16 or uint32, depending on uC platform.()

/* [SWS_Mcu_00252] */
typedef uint32 Mcu_RawResetType;
// [SWS_Mcu_00235]: The type Mcu_RawResetType specifies the reset reason in raw register format, read from a reset status register.()
// [SWS_Mcu_00236]: The type shall be uint8, uint16 or uint32 based on best performance.()

/* [SWS_Mcu_00254] */
typedef uint32 Mcu_ModeType;
// [SWS_Mcu_00237]: The Mcu_ModeType specifies the identification (ID) for a MCU mode, configured via configuration structure.()
// [SWS_Mcu_00238]: The type shall be uint8, uint16 or uint32.()

/* [SWS_Mcu_00255] */
typedef uint32 Mcu_RamSectionType;
// [SWS_Mcu_00239]: The Mcu_RamSectionType specifies the identification (ID) for a RAM section, configured via the configuration structure.()
// [SWS_Mcu_00240]: The type shall be uint8, uint16 or uint32, based on best performance.()

typedef uint32 Mcu_RamSizeType;

typedef uint32 Mcu_PeriType;

typedef uint32 Mcu_RamWriteSizeType;
typedef uint32 Mcu_CgmClkDivType;
typedef uint32 Mcu_CgmClkSelType;
typedef uint8  Mcu_PlldigClkPredivType;
typedef uint32 Mcu_PlldigClkoutDivType;
typedef uint8  Mcu_CgmSysClkSrcType;
typedef uint32 Mcu_CoreType;
typedef uint32 Mcu_CoreStatusType;
typedef VAR(void, MCU_VAR) (*Mcu_NotifyType) (void);

/*! @brief MC_ME peripheral instance clock configuration.
 *  Implements Mcu_PeriConfigType_Class
 */
typedef struct
{
    /* McMePeriNameConfig   is the name of the peripheral clock
     *    must be one of the following values
     *    DMA0_CLK
     *    MPU0_CLK
     *    ...
     *    LPUART3_CLK
     */
    VAR(Mcu_McMePeriNameType, MCU_CONST)McMePeriNameConfig;
    VAR(Mcu_McMePeriConfigType, MCU_CONST)McMeRunConfig;               /*!< Peripheral clock gating in running mode. */
    VAR(Mcu_McMePeriConfigType, MCU_CONST)McMeLowPowerConfig;          /*!< Peripheral clock gating in low-power mode. */
}Mcu_PeriConfigType;

/*!
 * @brief CGM configuration structure.
 * Implements Mcu_CgmConfigType_Class
 */
typedef struct
{
    VAR(Mcu_CgmClkDivType, MCU_CONST)        sc_dc0;              /*!< CGM system clock divider 0.  */
    VAR(Mcu_CgmClkDivType, MCU_CONST)        sc_dc1;              /*!< CGM system clock divider 1.  */
    VAR(Mcu_CgmClkDivType, MCU_CONST)        sc_dc2;              /*!< CGM system clock divider 2.  */
    VAR(Mcu_CgmClkDivType, MCU_CONST)        sc_dc3;              /*!< CGM system clock divider 3.  */
    VAR(Mcu_CgmClkDivType, MCU_CONST)        sc_dc4;              /*!< CGM system clock divider 4.  */

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac0_sc;               /*!< CGM auxiliary clock selector 0.                 */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac0_dc0;              /*!< CGM auxiliary clock selector 0, first  divider  */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac0_dc1;              /*!< CGM auxiliary clock selector 0, second divider  */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac0_dc2;              /*!< CGM auxiliary clock selector 0, third  divider  */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac0_dc3;              /*!< CGM auxiliary clock selector 0, fourth divider  */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac0_dc4;              /*!< CGM auxiliary clock selector 0, fifth divider  */

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac1_sc;               /*!< CGM auxiliary clock selector 1.                 */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac1_dc0;              /*!< CGM auxiliary clock selector 1, first  divider  */

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac2_sc;               /*!< CGM auxiliary clock selector 2.                 */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac2_dc0;              /*!< CGM auxiliary clock selector 2, first  divider  */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac2_dc1;              /*!< CGM auxiliary clock selector 2, second divider  */
#if (MCU_HARDVER == 5)
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac2_dc2;              /*!< CGM auxiliary clock selector 2, third divider  */
#endif

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac3_sc;               /*!< CGM auxiliary clock selector 3.                 */

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac4_sc;               /*!< CGM auxiliary clock selector 4.                 */

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_dc0;              /*!< CGM auxiliary clock selector 5, first  divider  */ // PSI5_f189_CLK
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_dc1;              /*!< CGM auxiliary clock selector 5, second divider  */ // PSI5_f125_CLK
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_dc2;              /*!< CGM auxiliary clock selector 5, third divider   */ // PSI5_1us_CLK

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc0;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_TS_CLK :ENABLE PSI5_1us
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc1;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR_CLK :ENABLE PSI5_1us
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc2;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK :ENABLE PSI5_1us

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc10;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR0_CLK
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc11;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR1_CLK
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc12;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR2_CLK
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc13;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR3_CLK

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc20;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK0
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc21;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK1
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc22;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK2
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac5_cdc23;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK3

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac6_sc;               /*!< CGM auxiliary clock selector 6.                 */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac6_dc0;              /*!< CGM auxiliary clock selector 6, first  divider  */

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac7_sc;               /*!< CGM auxiliary clock selector 7.                 */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac7_dc0;              /*!< CGM auxiliary clock selector 7, first  divider  */

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac8_sc;               /*!< CGM auxiliary clock selector 8.                 */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac8_dc0;              /*!< CGM auxiliary clock selector 8, first  divider  */

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac9_sc;               /*!< CGM auxiliary clock selector 9.                 */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac9_dc0;              /*!< CGM auxiliary clock selector 9, first  divider  */

    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac10_sc;              /*!< CGM auxiliary clock selector 10.                */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac10_dc0;             /*!< CGM auxiliary clock selector 10, first  divider */

#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac11_sc;              /*!< CGM auxiliary clock selector 11.                */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac11_dc0;             /*!< CGM auxiliary clock selector 11, first  divider */
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac12_sc;              /*!< CGM auxiliary clock selector 12.                */
#endif
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac12_dc0;             /*!< CGM auxiliary clock selector 12, first divider  */
#endif
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac12_dc1;             /*!< CGM auxiliary clock selector 12, second divider  */
#endif
#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
    VAR(Mcu_CgmClkDivType, MCU_CONST)       ac12_dc2;             /*!< CGM auxiliary clock selector 12, third divider  */
#endif
} Mcu_CgmConfigType;

/*!
 * @brief CGM Clock Source IRC configuration structure.
 * Implements Mcu_IrcConfigType_Class
 */
typedef struct
{
    VAR(uint32, MCU_CONST)Mcu_FircCfg;
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5))
    VAR(uint32, MCU_CONST)Mcu_SircCfg;
    #endif
} Mcu_IrcConfigType;

/*!
 * @brief CGM Clock Source XOSC configuration structure.
 * Implements Mcu_XoscConfigType_Class
 */
typedef struct
{
    VAR(uint32, MCU_CONST) freq;                           /*!< External oscillator frequency. */             
    VAR(uint16, MCU_CONST) startupDelay;                   /*!< Startup stabilization time. */
    VAR(Mcu_XoscBypassType, MCU_CONST) bypassOption;       /*!< XOSC option */
    VAR(uint8, MCU_CONST) Mcu_xoscInterruptEn;
} Mcu_XoscConfigType;

/*!
 * @brief CGM Clock Source PLLDIG configuration structure.
 * Implements Mcu_PlldigConfigType_Class
 */
typedef struct
{
    VAR(Mcu_PlldigClkPredivType, MCU_CONST) predivider;                     /*!< Input clock predivider. (PREDIV) */
    VAR(uint8, MCU_CONST) mulFactorDiv;                                     /*!< Multiplication factor divider (MFD) */
    VAR(Mcu_PlldigClkoutDivType, MCU_CONST) phi0Divider;                    /*!< Divider for clockout0 - PHI (RFDPHI) */
    VAR(Mcu_PlldigClkoutDivType, MCU_CONST) phi1Divider;                    /*!< Divider for clockout1 - PHI1 (RFDPHI1) */

    VAR(uint8, MCU_CONST) modulation;                                     /*!< Enable/disable (MODEN)modulation */
    VAR(Mcu_PlldigModType, MCU_CONST) modulationType;                       /*!< Modulation type(MODSEL) */
    VAR(uint16, MCU_CONST) modulationPeriod;                                /*!< Stepsize(MODPRD) - modulation period */
    VAR(uint16, MCU_CONST) incrementStep;                                   /*!< Stepno(INCSTP)  - step no */

    VAR(uint8, MCU_CONST) fracDivider;                                    /*!< Enable fractional divider(FDEN) */
    VAR(uint16, MCU_CONST) fracDividerValue;                                /*!< Fractional divider value(FRCDIV) */
} Mcu_PlldigConfigType;
/*!
 * @brief CGM Clock Sources configuration structure.
 * Implements Mcu_CgmSourcesConfigType_Class
 */
typedef struct
{
    VAR(Mcu_IrcConfigType, MCU_CONST)ircConfig;
    VAR(Mcu_XoscConfigType, MCU_CONST)xosc0Config;
    VAR(Mcu_PlldigConfigType, MCU_CONST)pll0Config;
    VAR(Mcu_PlldigConfigType, MCU_CONST)pll1Config;
} Mcu_CgmSourcesConfigType;

/*!
 * @brief Enabled clock sources structure. Indicates what clock sources are enabled for a particular power mode.
 * Implements Mcu_McMeClkSrcType_Class
 */
typedef struct
{
    VAR(uint8, MCU_CONST) irc0;                                      /*!< Internal RC oscillator 0 is switched on */
    VAR(uint8, MCU_CONST) xosc0;                                     /*!< External RC oscillator 0 is switched on */
    VAR(uint8, MCU_CONST) pll0;                                      /*!< PLL0 is switched on */
    VAR(uint8, MCU_CONST) pll1;                                      /*!< PLL1 is switched on */
} Mcu_McMeClkSrcType;

/*!
 * @brief Mode configuration structure. System clock source and enabled clock sources for a mode.
 * Implements Mcu_McMeModeConfigType_Class
 */
typedef struct
{
    VAR(Mcu_CgmSysClkSrcType, MCU_CONST)sysclk;         /*!< System clock source */
    VAR(Mcu_McMeClkSrcType, MCU_CONST)clocksEnabled;  /*!< Enabled clock sources (struct) */
} Mcu_McMeModeConfigType;

#if MCU_FCCU_ENABLE == STD_ON
/*
 * @brief FCC recoverable faults Mcu_FccuRfReactionEnCfg type definitions
 */
typedef struct {
    uint8 irq_alarm_en;
    uint8 nmi_en;
    uint8 eout_sig_en;
} Mcu_FccuRfReactionCfgType;

/*
 * @brief FCCU Eout configurations
 */
typedef struct
{
    uint8 set_after_reset; /* TRUE:  EOUT Signals controled bt FCCU,
                              * FALSE: EOUT Signals are in High-Z state */
    fccu_ep_control_t control;
    fccu_ep_output_t output;
    fccu_eout_fop_t fop;
    fccu_eout_sm_t switch_mode;
    fccu_eout_ps_t polarity_sel;
    fccu_eout_fom_t mode;
    fccu_eout_eof_t eof;
    uint16 delta_t_value;
} Mcu_FccuEoutConfigType;
#endif
/*====================================================================================================
STRUCT
====================================================================================================*/

typedef struct
{
    VAR(Mcal_DemErrorType, MCU_CONST) Mcu_E_ClockFailureCfg;
} Mcu_DemConfigType;
/* [SWS_Mcu_00053]: If clock failure notification is enabled in the configuration set and a clock source failure error occurs,
the error code MCU_E_CLOCK_FAILURE shall be reported. (See also SWS_Mcu_00051).() */

typedef struct
{
    VAR( uint16, MCU_VAR ) Mcme_Cctrl0_Config;
    VAR( uint16, MCU_VAR ) Mcme_Cctrl1_Config;
    VAR( uint16, MCU_VAR ) Mcme_Cctrl2_Config;
    VAR( uint16, MCU_VAR ) Mcme_Cctrl3_Config;
    VAR( uint16, MCU_VAR ) Mcme_Cctrl4_Config;
    #if (MCU_HARDVER == 5)
    VAR( uint16, MCU_VAR ) Mcme_Cctrl6_Config;
    VAR( uint16, MCU_VAR ) Mcme_Cctrl7_Config;
    VAR( uint16, MCU_VAR ) Mcme_Cctrl8_Config;
    VAR( uint16, MCU_VAR ) Mcme_Cctrl9_Config;
    VAR( uint16, MCU_VAR ) Mcme_Cctrl10_Config;
    VAR( uint16, MCU_VAR ) Mcme_Cctrl11_Config;
    #endif
    VAR( uint32, MCU_VAR ) Mcme_Caddr0_Config;
    VAR( uint32, MCU_VAR ) Mcme_Caddr1_Config;
    VAR( uint32, MCU_VAR ) Mcme_Caddr2_Config;
    VAR( uint32, MCU_VAR ) Mcme_Caddr3_Config;
    VAR( uint32, MCU_VAR ) Mcme_Caddr4_Config;
    #if (MCU_HARDVER == 5)
    VAR( uint32, MCU_VAR ) Mcme_Caddr6_Config;
    VAR( uint32, MCU_VAR ) Mcme_Caddr7_Config;
    VAR( uint32, MCU_VAR ) Mcme_Caddr8_Config;
    VAR( uint32, MCU_VAR ) Mcme_Caddr9_Config;
    VAR( uint32, MCU_VAR ) Mcme_Caddr10_Config;
    VAR( uint32, MCU_VAR ) Mcme_Caddr11_Config;
    #endif
}Mcu_CoreConfigType;

/*! @brief MC_ME configuration.
 *  Implements Mcu_McMeConfigType_Class
 */
typedef struct
{
    VAR(uint32, MCU_CONST) McMeMe;                                                       /*!< MODE ENABLE.   */
    VAR(uint32, MCU_CONST) Mcu_McMeIrqCfg;
    VAR(uint32, MCU_CONST) McMeRunConfig[MC_ME_RUN_CONFIG_COUNT];                        /*!< Run peripheral configurations */
    VAR(uint32, MCU_CONST) McMeLowPowerConfig[MC_ME_LOWPOWER_CONFIG_COUNT];              /*!< Low power peripheral configurations    */ 
    /*!< Number of McMePeripheral to be configured. */
    P2CONST(Mcu_PeriConfigType, MCU_CONST, MCU_APPL_CONST)McMePeripheralConfig[MC_ME_PERIPH_CONFIG_COUNT];
} Mcu_McMeConfigType;


typedef struct
{
    VAR( uint32, MCU_CONST ) RgmGroup0;
    VAR( uint32, MCU_CONST ) RgmGroup1;
    VAR( uint32, MCU_CONST ) RgmGroup2;
    VAR( uint32, MCU_CONST ) RgmGroup3;
    VAR( uint32, MCU_CONST ) RgmGroup4;
    VAR( uint32, MCU_CONST ) RgmGroup5;
    VAR( uint32, MCU_CONST ) RgmGroup6;
    VAR( uint32, MCU_CONST ) RgmGroup7;
}Mcu_PeripheralResetType;


typedef struct
{
    #if(MCU_PERFORM_RESET_API == STD_ON)
    VAR(Mcu_Rgm_ResetType, MCU_CONST) Mcu_RgmResetType;
    #endif
    VAR( uint8, MCU_CONST) Mcrgm_FuncThresholdReset;
    VAR( uint8, MCU_CONST) Mcrgm_DesThresholdReset;
    VAR( uint32, MCU_CONST ) Mcrgm_DestResetOpt;
    VAR( uint32, MCU_CONST ) Mcrgm_DestSafeIsrOpt;
    VAR( uint32, MCU_CONST ) Mcrgm_DestExtPinReset;
    VAR( uint32, MCU_CONST ) Mcrgm_FuncResetOpt;
    VAR( uint32, MCU_CONST ) Mcrgm_FuncSafeIsrOpt;
    VAR( uint32, MCU_CONST ) Mcrgm_FuncExtPinReset;
    VAR( uint32, MCU_CONST ) Mcrgm_FuncPhase1or3Opt;
    #if (MCU_PERIRESET_COUNT != 0)
    P2CONST( Mcu_PeripheralResetType, MCU_CONST, MCU_APPL_CONST) PeriResetConfig[MCU_PERIRESET_COUNT];
    #endif
}Mcu_RgmConfigType;

typedef struct
{
    VAR( uint32, MCU_CONST ) Pmc_IerConfig;
    VAR( uint32, MCU_CONST ) Pmc_VD3ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD4ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD7ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD8ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD9ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD10ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD12ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD13ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD14ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD15ResetEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD3ResetEventSel;
    VAR( uint32, MCU_CONST ) Pmc_VD4ResetEventSel;
    VAR( uint32, MCU_CONST ) Pmc_VD7ResetEventSel;
    VAR( uint32, MCU_CONST ) Pmc_VD8ResetEventSel;
    VAR( uint32, MCU_CONST ) Pmc_VD9ResetEventSel;
    VAR( uint32, MCU_CONST ) Pmc_VD12ResetEventSel;
    VAR( uint32, MCU_CONST ) Pmc_VD13ResetEventSel;
    VAR( uint32, MCU_CONST ) Pmc_VD14ResetEventSel;
    VAR( uint32, MCU_CONST ) Pmc_VD15ResetEventSel;
    VAR( uint32, MCU_CONST ) Pmc_VD3FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD4FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD7FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD8FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD9FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD10FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD12FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD13FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD14FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VD15FccuEventEn;
    VAR( uint32, MCU_CONST ) Pmc_VoltageSupply;
    VAR( uint32, MCU_CONST ) Pmc_TempResEventEn;
    VAR( uint32, MCU_CONST ) Pmc_TempResEventSel;
    VAR( uint32, MCU_CONST ) Pmc_TempDetConfig;
    VAR( uint32, MCU_CONST ) Pmc_TempFccuEventEn;
}Mcu_PmcConfigType;

#if MCU_FCCU_ENABLE == STD_ON
/*
 * @brief FCCU recoverable faults configurations
 */
typedef struct /* PRQA S 3630 */
{
    VAR(uint8, MCU_CONST) Mcu_FccuChannel;
    VAR(Mcu_FccuRecoveryType, MCU_CONST) Mcu_FccuRecoveryConfig;
    VAR(Mcu_FccuReactionType, MCU_CONST) Mcu_FccuReactionConfig;
    VAR(uint8, MCU_CONST) Mcu_FccuToAlarmEn;
    VAR(Mcu_FccuRfReactionCfgType, MCU_CONST)Mcu_FccuRfReactionEnCfg;
} Mcu_FccuRfConfigType;

/*
 * @brief FCCU module configuration
 */
typedef struct /* PRQA S 3630 */
{
    VAR(uint8, MCU_CONST) Mcu_FccuFilterBypassEn;
    VAR(uint8, MCU_VAR) Mcu_FccuFilterWidth;
    VAR(Mcu_FccuEoutConfigType, MCU_VAR) Mcu_FccuEoutConfig;
    VAR(Mcu_FccuLockType, MCU_CONST) Mcu_FccuLockTypeConfig;
    VAR(uint32, MCU_CONST) Mcu_FccuCfgTimeout;
    VAR(Mcu_FccuIrqType, MCU_CONST) Mcu_FccuIrqTypeConfig;
    VAR(uint8, MCU_CONST) Mcu_FccuRfCfgNumber;
    P2CONST(Mcu_FccuRfConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_FccuRfConfigPtr;
} Mcu_FccuConfigType;
#endif

typedef struct Mcu_ClockConfig
{
    VAR(Mcu_CgmConfigType, MCU_CONST)cgmConfig;
    VAR(Mcu_CgmSourcesConfigType, MCU_CONST)cgmcsConfig;
    VAR(uint32, MCU_CONST) Mcu_SRamWSConfig;
    #ifdef MCU_FLASH_WAIT_STATUS_CONFIG
    VAR(uint32, MCU_CONST) Mcu_FlashWSConfig;
    #endif
    VAR(Mcu_McMeModeConfigType, MCU_CONST)mode_configuration;
    P2CONST(Mcu_PeriConfigType, MCU_CONST, MCU_APPL_CONST) PeriConfigPtr;
}Mcu_ClockConfigType;

typedef struct Mcu_ModeConfig
{
    VAR( Mcu_ModeType, MCU_CONST) Mcu_ModeConfigId;
    VAR( Mcu_CgmClkSelType, MCU_CONST) Mcu_TargetClock;
    VAR( Mcu_McModeType, MCU_CONST) Mcu_ChipMode;
    VAR( uint8, MCU_CONST) Mcu_IRC_En;
    VAR( uint8, MCU_CONST) Mcu_XOSC_En;
    VAR( uint8, MCU_CONST) Mcu_PLL0_En;
    VAR( uint8, MCU_CONST) Mcu_PLL1_En;
    P2CONST(Mcu_PeriConfigType, MCU_CONST, MCU_APPL_CONST) PeriConfigPtr;
}Mcu_ModeConfigType;

typedef struct
{
    VAR(Mcu_RamSectionType, MCU_CONST) Mcu_RamSectorId;
    P2VAR(uint8, MCU_CONST, MCU_APPL_DATA) Mcu_RamBaseAddrPtr;
    VAR(Mcu_RamSizeType, MCU_CONST) Mcu_RamSize;
    VAR(uint64, MCU_CONST) Mcu_RamDefaultValue;
    VAR(Mcu_RamWriteSizeType, MCU_CONST) Mcu_RamWriteSize;
}Mcu_RamConfigType;



typedef struct
{
    VAR(Mcu_CoreType, MCU_VAR) Mcu_BootCore;
    VAR(Mcu_CoreType, MCU_VAR) Mcu_InitCore;
}Mcu_CtrlConfigType;

typedef struct
{
    #if (MCU_CLOCKS_FAILURE_EN == STD_ON)
    VAR( Mcu_NotifyType, MCU_CONST) Mcu_ClockFailureNotification;
    #endif
    VAR( Mcu_NotifyType, MCU_CONST ) Mcu_XoscStartupNotification;
    VAR( Mcu_NotifyType, MCU_CONST ) McuFailOfChangeModeNotification;
    VAR( Mcu_NotifyType, MCU_CONST ) Mcu_InvalidConfigNotification_Core;
    VAR( Mcu_NotifyType, MCU_CONST ) Mcu_InvalidConfigNotification_Clock;
    VAR( Mcu_NotifyType, MCU_CONST ) Mcu_InvalidConfigNotification;
    VAR( Mcu_NotifyType, MCU_CONST ) Mcu_InvalidModeNotification;
    VAR( Mcu_NotifyType, MCU_CONST ) Mcu_SafeModeNotification;
    VAR( Mcu_NotifyType, MCU_CONST ) Mcu_ModeCompleteNotification;
    VAR( Mcu_NotifyType, MCU_CONST ) McuVoltageErrorNotification;
    VAR( Mcu_NotifyType, MCU_CONST ) McuTemperatureErrorNotification;
    VAR( Mcu_NotifyType, MCU_CONST ) Mcu_FccuAlarmNotification;
    VAR( Mcu_NotifyType, MCU_CONST ) Mcu_FccuCfgToNotification;
}Mcu_NotifyConfigType;

/* [SWS_Mcu_00249] */
typedef struct Mcu_Config
{
    #if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    P2CONST( Mcu_DemConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_DemConfigPtr;
    #endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
    P2CONST( Mcu_NotifyConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_NotifyConfigPtr;
    P2CONST( Mcu_CtrlConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_CtrlConfigPtr;
    P2CONST( Mcu_CoreConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_CoreConfigPtr;
    P2CONST( Mcu_McMeConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_McMeConfigPtr;
    P2CONST( Mcu_RgmConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_RgmConfigPtr;
    P2CONST( Mcu_PmcConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_PmcConfigPtr;
    #if (MCU_FCCU_ENABLE == STD_ON)
    P2CONST( Mcu_FccuConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_FccuConfigPtr;
    #endif
    #if (MCU_INIT_CLOCK == STD_ON)
    VAR( Mcu_ClockType, MCU_CONST) NoClockConfig;
    P2CONST( Mcu_ClockConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_ClockConfigPtr;
    #endif
    VAR( Mcu_ModeType, MCU_CONST) NoModeConfig;
    P2CONST( Mcu_ModeConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_ModeConfigPtr;
    VAR( Mcu_RamSectionType, MCU_CONST) NoRamSectionConfig;
    P2CONST( Mcu_RamConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_RamConfigPtr;
}Mcu_ConfigType;
// [SWS_Mcu_00131]: The structure Mcu_ConfigType is an external data structure (i.e. implementation specific) and shall contain the initialization data for the MCU module. It shall contain:
//  MCU dependent properties
//  Reset Configuration
//  Definition of MCU modes
//  Definition of Clock settings
//  Definition of RAM sections()

// [SWS_Mcu_00054]: The structure Mcu_ConfigType shall provide a configurable (enable/disable) clock failure notification if the MCU provides an interrupt for such detection.()

// [SWS_Mcu_00035]: The definitions for each MCU mode within the structure Mcu_ConfigType shall contain: (depending on MCU)
//  MCU specific properties
//  Change of CPU clock
//  Change of Peripheral clock
//  Change of PLL settings
//  Change of MCU power supply()

// [SWS_Mcu_00031]: The definitions for each Clock setting within the structure Mcu_ConfigType shall contain:
//  MCU specific properties as, e.g., clock safety features and special clock distribution settings
//  PLL settings /start lock options
//  Internal oscillator setting()

// [SWS_Mcu_00030]: The definitions for each RAM section within the structure Mcu_ConfigType shall contain:
//  RAM section base address
//  Section size
//  Data pre-setting to be initialized
//  RAM write size()



/*====================================================================================================
FUNCTION DECLARATION
====================================================================================================*/

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/* [SWS_Mcu_00153] */
FUNC(void, MCU_CODE) Mcu_Init
(
    P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr
);
// [SWS_Mcu_00026]: The function Mcu_Init shall initialize the MCU module, i.e. make the configuration settings for power down, clock and RAM sections visible within the MCU module.
// [SWS_Mcu_00116]: If the hardware allows for only one usage of the register, the driver module implementing that functionality is responsible for initializing the register.()
// [SWS_Mcu_00244]: If the register can affect several hardware modules and if it is an I/O register, it shall be initialised by the PORT driver.()
// [SWS_Mcu_00245]: If the register can affect several hardware modules and if it is not an I/O register, it shall be initialised by this MCU driver.()
// [SWS_Mcu_00246]: One-time writable registers that require initialisation directly after reset shall be initialised by the startup code.()
// [SWS_Mcu_00247]: All other registers not mentioned before shall be initialised by the start-up code.()

// [SWS_Mcu_00125]: If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called before Mcu_Init function, the error code MCU_E_UNINIT shall be reported to the DET.()

/* [SWS_Mcu_00154] */
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection
(
    VAR(Mcu_RamSectionType, AUTOMATIC) RamSection
);
/* [SWS_Mcu_00011]: The function Mcu_InitRamSection shall fill the memory from address McuRamSectionBaseAddress up to address McuRamSectionBaseAddress + McuRamSectionSize-1 with
the byte-value contained in McuRamDefaultValue and by writing at once a number of bytes defined by McuRamSectionWriteSize, where McuRamSectionBaseAddress, McuRamSectionSize, 
McuRamDefaultValue and McuRamSectionWriteSize are the values of the configuration parameters for each RamSection (see SWS_Mcu_00030). */
// [SWS_Mcu_00136]: The MCU module's environment shall call the function Mcu_InitRamSection only after the MCU module has been initialized using the function Mcu_Init.()

// [SWS_Mcu_00021]: RamSection shall be within the sections defined in the configuration data structure. Related error value: MCU_E_PARAM_RAMSECTION()


/* [SWS_Mcu_00155] */
#if (MCU_INIT_CLOCK == STD_ON)
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock( VAR(Mcu_ClockType, AUTOMATIC) ClockSetting );
#endif /* (MCU_INIT_CLOCK == STD_ON) */
// [SWS_Mcu_00137]: The function Mcu_InitClock shall initialize the PLL and other MCU specific clock options. The clock configuration parameters are provided via the configuration structure.()
// [SWS_Mcu_00138]: The function Mcu_InitClock shall start the PLL lock procedure (if PLL shall be initialized) and shall return without waiting until the PLL is locked.()
// [SWS_Mcu_00139]: The MCU module's environment shall only call the function Mcu_InitClock after the MCU module has been initialized using the function Mcu_Init.()
// [SWS_Mcu_00210]: The function Mcu_InitClock shall be disabled if the parameter McuInitClock is set to FALSE. Instead this function is available if the former parameter is set to TRUE (see also ECUC_Mcu_00118 : ).()

// [SWS_Mcu_00019]: ClockSetting shall be within the settings defined in the configuration data structure. Related error value: MCU_E_PARAM_CLOCK()

/* [SWS_Mcu_00156] */
#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock( VAR(void, AUTOMATIC) );
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */
// [SWS_Mcu_00140]: The function Mcu_DistributePllClock shall activate the PLL clock to the MCU clock distribution.()
// [SWS_Mcu_00141]: The function Mcu_DistributePllClock shall remove the current clock source (for example internal oscillator clock) from MCU clock distribution.()
// [SWS_Mcu_00056]: The function Mcu_DistributePllClock shall return without affecting the MCU hardware if the PLL clock has been automatically activated by the MCU hardware.()
// [SWS_Mcu_00142]: If the function Mcu_DistributePllClock is called before PLL has locked, this function shall return E_NOT_OK immediately, without any further action.()
// [SWS_Mcu_00205]: The function Mcu_DistributePllClock shall be available if the pre-compile parameter McuNoPll is set to FALSE. Otherwise, this Api has to be disabled (see also ECUC_Mcu_00180 : ).()

// [SWS_Mcu_00122]: All error shall be reported if the status of the PLL is detected as not locked with the function Mcu_DistributePllClock(). The DET error reporting shall be used. Related error value: MCU_E_PLL_NOT_LOCKED.()

/* [SWS_Mcu_00157] */
#if (MCU_INIT_CLOCK == STD_ON)
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus( VAR(void, AUTOMATIC) );
#endif /* (MCU_INIT_CLOCK == STD_ON) */
// [SWS_Mcu_00008]: The function Mcu_GetPllStatus shall return the lock status of the PLL.()
// [SWS_Mcu_00132]: The function Mcu_GetPllStatus shall return MCU_PLL_STATUS_UNDEFINED if this function is called prior to calling of the function Mcu_Init.()
// [SWS_Mcu_00206]: The function Mcu_GetPllStatus shall also return MCU_PLL_STATUS_UNDEFINED if the pre-compile parameter McuNoPll is set to TRUE (see also ECUC_Mcu_00180 : ).()


/* [SWS_Mcu_00158] */
FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason( VAR(void, AUTOMATIC) );
/* [SWS_Mcu_00005]: The function Mcu_GetResetReason shall read the reset reason from the hardware and return this reason if supported by the hardware.
If the hardware does not support the hardware detection of the reset reason, the return value from the function Mcu_GetResetReason shall always be MCU_POWER_ON_RESET.() */
// [SWS_Mcu_00133]: The function Mcu_GetResetReason shall return MCU_RESET_UNDEFINED if this function is called prior to calling of the function Mcu_Init, and if supported by the hardware.()


/* [SWS_Mcu_00159] */
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue( VAR( void, AUTOMATIC) );
/* [SWS_Mcu_00135]: The function Mcu_GetResetRawValue shall return an implementation specific value which does not correspond to a valid value of the reset status register and is not equal to 0
if this function is called prior to calling of the function Mcu_Init, and if supported by the hardware.() */
// [SWS_Mcu_00006]: The function Mcu_GetResetRawValue shall read the reset raw value from the hardware register if the hardware supports this. If the hardware does not have a reset status register, the return value shall be 0x0.()


/* [SWS_Mcu_00160] */
#if (MCU_PERFORM_RESET_API == STD_ON)
FUNC(void, MCU_CODE) Mcu_PerformReset( VAR(void, AUTOMATIC) );
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */
// [SWS_Mcu_00143]: The function Mcu_PerformReset shall perform a microcontroller reset by using the hardware feature of the microcontroller.()
// [SWS_Mcu_00144]: The function Mcu_PerformReset shall perform the reset type which is configured in the configuration set.()
// [SWS_Mcu_00145]: The MCU module's environment shall only call the function Mcu_PerformReset after the MCU module has been initialized by the function Mcu_Init.()
// [SWS_Mcu_00146]: The function Mcu_PerformReset is only available if the pre-compile parameter McuPerformResetApi is set to TRUE. If set to FALSE, the function Mcu_PerformReset is not applicable. (see Section 10.2.2).()


/* [SWS_Mcu_00161] */
FUNC(void, MCU_CODE) Mcu_SetMode( VAR(Mcu_ModeType, AUTOMATIC) McuMode );
// [SWS_Mcu_00147]: The function Mcu_SetMode shall set the MCU power mode. In case of CPU power down mode, the function Mcu_SetMode returns after it has performed a wake-up.()
// [SWS_Mcu_00148]: The MCU module's environment shall only call the function Mcu_SetMode after the MCU module has been initialized by the function Mcu_Init.()

// [SWS_Mcu_00020]: McuMode shall be within the modes defined in the configuration data structure. Related error value: MCU_E_PARAM_MODE()

/* [SWS_Mcu_00162] */
FUNC(void, MCU_CODE) Mcu_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) versioninfo
);

/* [SWS_Mcu_00207] */
#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_GetRamState( VAR(void, AUTOMATIC) );
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */
// [SWS_Mcu_00208]: The MCU module's environment shall call this function only if the MCU module has been already initialized using the function MCU_Init.()
/* [SWS_Mcu_00209]: The function Mcu_GetRamState shall be available to the user if the pre-compile parameter McuGetRamStateApi is set to TRUE. Instead, if the former parameter is set to FALSE, this function shall be disabled
(e.g. the hardware does not support this functionality).() */

#if (MCU_FCCU_ENABLE == STD_ON)
FUNC(Std_ReturnType, MCU_CODE)Mcu_FccuInit( VAR(void, AUTOMATIC) );
FUNC(Std_ReturnType, MCU_CODE)Mcu_FccuClearFault( VAR(uint8, AUTOMATIC)faultIndex );
#endif

FUNC(void, MCU_CODE)Mcu_PeriModeSet( VAR(Mcu_PeriType, AUTOMATIC)PeriConfig );

#if (MCU_PERIRESET_COUNT != 0)
FUNC(void, MCU_CODE)Mcu_PeriResetPend( VAR(Mcu_PeriType, AUTOMATIC)PeriConfig );

FUNC(void, MCU_CODE)Mcu_PeriResetClose( VAR(void, AUTOMATIC) );
#endif

FUNC(void, MCU_CODE)Mcu_CoreSynchronise( void );

extern CONST(Mcu_ConfigType, MCU_CONST) McuModuleConfiguration;

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_H */



