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
*   @file    Dem.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dem MCAL driver.
*
*   @addtogroup Dem
*   @{
*/


#ifndef DEM_H
#define DEM_H

#ifdef __cplusplus
extern "C"{
#endif


/*==============================================INCLUDE FILES=======================================*/
#include "StandardTypes.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define DEM_VENDOR_ID                     176
#define DEM_AR_RELEASE_MAJOR_VERSION      4
#define DEM_AR_RELEASE_MINOR_VERSION      4
#define DEM_AR_RELEASE_REVISION_VERSION   0
#define DEM_SW_MAJOR_VERSION              1
#define DEM_SW_MINOR_VERSION              0
#define DEM_SW_PATCH_VERSION              1
/*============================================FILE VERSION CHECKS===================================*/

/*=================================================Constants========================================*/

/*============================================DEFINES AND MACROS====================================*/

#define DEM_MAX_EXTENDED_DATA_LENGTH_U8         (uint8)(100U)
#define DEM_EVENT_STATUS_PASSED     (Dem_EventStatusType)0x00U  /**< @brief dem event passed */
#define DEM_EVENT_STATUS_FAILED     (Dem_EventStatusType)0x01U  /**< @brief dem event failed */
#define DEM_EVENT_STATUS_PREPASSED  (Dem_EventStatusType)0x02U  /**< @brief dem event pre-passed */
#define DEM_EVENT_STATUS_PREFAILED  (Dem_EventStatusType)0x03U  /**< @brief dem event pre-failed */
/*===================================================Enums==========================================*/

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/
/* Specification of Lin Driver : [SWS_Lin_00226] */
typedef uint16 Dem_EventIdType;                              /**< @brief dem event ID type */

typedef uint8 Dem_EventStatusType;                           /**< @brief dem event status type */
/*===========================================VARIABLE DECLARATIONS==================================*/
extern VAR(Dem_EventIdType    , DEM_VAR) Dem_EventId[256];      /**< @brief DEM event ID*/
extern VAR(Dem_EventStatusType, DEM_VAR) Dem_EventStatus[256];  /**< @brief DEM event status*/




/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern VAR(Dem_EventIdType    , DEM_VAR) Dem_EventId[256];      /**< @brief DEM event ID*/
extern VAR(Dem_EventStatusType, DEM_VAR) Dem_EventStatus[256];  /**< @brief DEM event status*/
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
 
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern VAR(Dem_EventIdType    , DEM_VAR) Dem_EventId[256];      /**< @brief DEM event ID*/
extern VAR(Dem_EventStatusType, DEM_VAR) Dem_EventStatus[256];  /**< @brief DEM event status*/
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

/*============================================FUNCTION PROTOTYPES===================================*/
FUNC(void, DEM_CODE) Dem_ReportErrorStatus       (VAR(Dem_EventIdType, AUTOMATIC) EventId, VAR(Dem_EventStatusType, AUTOMATIC) EventStatus);
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(VAR(Dem_EventIdType, AUTOMATIC) EventId, VAR(Dem_EventStatusType, AUTOMATIC) EventStatus);

#ifdef __cplusplus
}
#endif

#endif
