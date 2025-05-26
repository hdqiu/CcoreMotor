/**
* @file SchM_Sent.h
* @version 1.0.1
**@brief   AUTOSAR SENT Rte - module interface.
* @details This file mainly contains reentrant interfaces and multi - core mutually exclusive interface definitions
*
* @addtogroup
* @{
*/
/****************************************************************************
*
* Copyright (c) 2022  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
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
*   @file    SchM_Sent.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Rte MCAL driver.
*
*   @addtogroup Rte
*   @{
*/
#ifndef SCHM_SENT_H
#define SCHM_SENT_H
/*===================================================================================================
 *                                           INCLUDE FILES
 ====================================================================================================*/
#ifdef __cplusplus 
extern "C" {
#endif
#include "Compiler.h"
#include "Mcal.h"
#include "Rte_MConfig.h"

/*===================================================================================================
 *                                            LOCAL MACROS
 ====================================================================================================*/
#define SENT_CORE_NUM                    RESOURCE_CHIP_CORE_NUM
#define MULTICORE_SENT_TYPE              MULTICORE_TYPE_EXCLUSIVE
/*===================================================================================================
 *                                          LOCAL CONSTANTS
 ====================================================================================================*/
/*===================================================================================================
 *                               LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ====================================================================================================*/
/*===================================================================================================
 *                                          LOCAL VARIABLES
 ====================================================================================================*/
/*===================================================================================================
 *                                        FUNCTION PROTOTYPES
 ====================================================================================================*/
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_00(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_01(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_02(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_03(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_04(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_05(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_06(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_07(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_08(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_09(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_10(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_11(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_12(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_13(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_14(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_15(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_16(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_17(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_18(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_19(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_20(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_21(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_22(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_23(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_24(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_25(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_26(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_27(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_28(void);
FUNC(void, RTE_CODE) SchM_Enter_SENT_EXCLUSIVE_AREA_29(void);

FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_00(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_01(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_02(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_03(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_04(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_05(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_06(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_07(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_08(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_09(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_10(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_11(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_12(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_13(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_14(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_15(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_16(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_17(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_18(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_19(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_20(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_21(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_22(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_23(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_24(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_25(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_26(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_27(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_28(void);
FUNC(void, RTE_CODE) SchM_Exit_SENT_EXCLUSIVE_AREA_29(void);

#ifdef __cplusplus
}
#endif
#endif /* SCHM_SENT_H */

