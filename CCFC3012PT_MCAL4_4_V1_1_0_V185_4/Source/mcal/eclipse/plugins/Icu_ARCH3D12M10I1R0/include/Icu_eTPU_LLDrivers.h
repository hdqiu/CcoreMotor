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
*   @file    Icu_eTPU_LLDriver.h
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
#ifndef ICU_ETPU_LLDRIVER_H
#define ICU_ETPU_LLDRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "StandardTypes.h"
#include "Compiler.h"
#ifdef RESOURCE_SUPPORT_ETPU
#include "eTPU_LLDrivers.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_ETPU_LLDRIVERS_VENDOR_ID_H                   176

#define ICU_ETPU_LLDRIVERS_MAJOR_VER_H                   4
#define ICU_ETPU_LLDRIVERS_MINOR_VER_H                   4
#define ICU_ETPU_LLDRIVERS_REVISION_VER_H                0

#define ICU_ETPU_LLDRIVERS_SW_MAJOR_VER_H                1
#define ICU_ETPU_LLDRIVERS_SW_MINOR_VER_H                0
#define ICU_ETPU_LLDRIVERS_SW_PATCH_VER_H                1

#if (ICU_ETPU_LLDRIVERS_VENDOR_ID_H != STANDARD_VENDOR_ID)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_ETPU_LLDRIVERS_MAJOR_VER_H != STANDARD_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ICU_ETPU_LLDRIVERS_MINOR_VER_H != STANDARD_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ICU_ETPU_LLDRIVERS_REVISION_VER_H != STANDARD_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_ETPU_LLDRIVERS_SW_MAJOR_VER_H != STANDARD_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_ETPU_LLDRIVERS_SW_MINOR_VER_H != STANDARD_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_ETPU_LLDRIVERS_SW_PATCH_VER_H != STANDARD_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ETPU_INSTANCE_MAX               2U
#define ETPU_MODULE_CHANNEL_MAX         32U
#define ETPU_PASSAGE_MAX                96U

/* Function Configuration Information */
#define ETPU_IC_FUNCTION_NUMBER         1U
#define ETPU_IC_TABLE_SELECT            0U
#define ETPU_IC_NUM_PARMS               0x0020U

/* Host Service Request Definitions */
#define ETPU_IC_INIT_TCR1               7U
#define ETPU_IC_INIT_TCR2               6U
#define ETPU_IC_INIT_PRAM               5U

/* Parameter Definitions */
#define ETPU_IC_FLAGS_OFFSET            0x0000U
#define ETPU_IC_MAXCOUNT_OFFSET         0x0001U
#define ETPU_IC_TRANSCOUNT_OFFSET       0x0005U
#define ETPU_IC_FINAL_OFFSET            0x0009U
#define ETPU_IC_LAST_OFFSET             0x000DU
#define ETPU_IC_ADDRESS_OFFSET          0x0011U
#define ETPU_IC_LINK1_OFFSET            0x0014U
#define ETPU_IC_LINK2_OFFSET            0x0018U

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef enum
{
    ETPU_IC_FALLING_EDGE            = 0x00U,
    ETPU_IC_RISING_EDGE             = 0x01U,
    ETPU_IC_ANY_EDGE                = 0x02U,
    ETPU_IC_OPPOSITE                = 0x03U
} eTPU_EdgeTrigModeType;

typedef struct             /*PRQA S 3630 EOF*/
{
    VAR(uint8_t, ICU_VAR)   priority;
    VAR(uint8_t, ICU_VAR)   mode;
    VAR(uint8_t, ICU_VAR)   timebase;
    VAR(uint8_t, ICU_VAR)   edge;
    VAR(uint32_t, ICU_VAR)  max_count;
    VAR(uint32_t, ICU_VAR)  *address;
    VAR(uint32_t, ICU_VAR)  link1;
    VAR(uint32_t, ICU_VAR)  link2;
} etpu_ic_param_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/* IC channel initialization */
FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Init
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    P2CONST(etpu_ic_param_t, ICU_VAR, ICU_APPL_CONST) parameter \
);

FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Init_Ram
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    P2CONST(etpu_ic_param_t, ICU_VAR, ICU_APPL_CONST) parameter \
);

FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Init_Link
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    P2CONST(etpu_ic_param_t, ICU_VAR, ICU_APPL_CONST) parameter \
);

FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Init_Link_Ram
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    P2CONST(etpu_ic_param_t, ICU_VAR, ICU_APPL_CONST) parameter \
);

FUNC(void, ICU_CODE) ETPU_LLD_IC_DeInit
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel \
);

FUNC(void, ICU_CODE) ETPU_LLD_IC_SetTriggerMode
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    VAR(eTPU_EdgeTrigModeType, ICU_VAR) eEdge \
);

FUNC(eTPU_EdgeTrigModeType, ICU_CODE) ETPU_LLD_IC_GetTriggerMode
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel \
);

FUNC(void, ICU_CODE) ETPU_LLD_IC_SetIterCount
(
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    VAR(uint32, ICU_VAR) count \
);

/* Data read functions */
FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Read_Trans_Count
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel
);

FUNC(uint32, ICU_CODE) ETPU_LLD_IC_Read_Final_Time
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel
);

FUNC(uint32, ICU_CODE) ETPU_LLD_IC_Read_Last_Time
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel
);

FUNC(uint32, ICU_CODE) ETPU_LLD_IC_GetCountAddress
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel
);

FUNC(void, ICU_CODE) ETPU_LLD_IC_SetTransCount
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel,
    VAR(uint32,ICU_VAR) u32Value
);

FUNC(void, ICU_CODE) ETPU_LLD_IC_SetFinalTime
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel,
    VAR(uint32,ICU_VAR) u32Value
);

FUNC(void, ICU_CODE) ETPU_LLD_IC_SetLastTime
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel,
    VAR(uint32,ICU_VAR) u32Value
);


#ifdef __cplusplus
}
#endif

#endif /* ICU_ETPU_LLDRIVER_H */

#endif /*#RESOURCE_SUPPORT_ETPU*/

