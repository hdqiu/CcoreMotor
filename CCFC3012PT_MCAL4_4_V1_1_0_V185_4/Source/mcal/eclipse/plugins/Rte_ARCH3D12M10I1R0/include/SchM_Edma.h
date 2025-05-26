/**
* @file SchM_Edma.h
* @version 1.0.1
**@brief   AUTOSAR EDMA Rte - module interface.
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
*   @file    SchM_Edma.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Rte MCAL driver.
*
*   @addtogroup Rte
*   @{
*/
#ifndef SCHM_EDMA_H
#define SCHM_EDMA_H
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
#define EDMA_CORE_NUM                    RESOURCE_CHIP_CORE_NUM
#define MULTICORE_EDMA_TYPE              MULTICORE_TYPE_EXCLUSIVE
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
FUNC(void, RTE_CODE) SchM_Enter_EDMA_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n);
FUNC(void, RTE_CODE) SchM_Enter_EDMA_EXCLUSIVE_AREA_00(void);
FUNC(void, RTE_CODE) SchM_Enter_EDMA_EXCLUSIVE_AREA_01(void);
FUNC(void, RTE_CODE) SchM_Enter_EDMA_EXCLUSIVE_AREA_02(void);
FUNC(void, RTE_CODE) SchM_Enter_EDMA_EXCLUSIVE_AREA_03(void);
FUNC(void, RTE_CODE) SchM_Enter_EDMA_EXCLUSIVE_AREA_04(void);

FUNC(void, RTE_CODE) SchM_Exit_EDMA_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n);
FUNC(void, RTE_CODE) SchM_Exit_EDMA_EXCLUSIVE_AREA_00(void);
FUNC(void, RTE_CODE) SchM_Exit_EDMA_EXCLUSIVE_AREA_01(void);
FUNC(void, RTE_CODE) SchM_Exit_EDMA_EXCLUSIVE_AREA_02(void);
FUNC(void, RTE_CODE) SchM_Exit_EDMA_EXCLUSIVE_AREA_03(void);
FUNC(void, RTE_CODE) SchM_Exit_EDMA_EXCLUSIVE_AREA_04(void);

#ifdef __cplusplus
}
#endif
#endif /* SCHM_EDMA_H */

