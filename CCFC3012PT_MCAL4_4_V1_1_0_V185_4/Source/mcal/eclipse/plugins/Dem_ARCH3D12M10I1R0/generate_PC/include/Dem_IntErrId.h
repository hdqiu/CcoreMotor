/**
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
#ifndef DEM_INTERRID_H
#define DEM_INTERRID_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*=====================================SOURCE FILE VERSION INFORMATION========================*/

#define DEM_INTERRID_VENDOR_ID                      176
#define DEM_INTERRID_MODULE_ID                      54
#define DEM_INTERRID_AR_RELEASE_MAJOR_VERSION       4
#define DEM_INTERRID_AR_RELEASE_MINOR_VERSION       4
#define DEM_INTERRID_AR_RELEASE_REVISION_VERSION    0
#define DEM_INTERRID_SW_MAJOR_VERSION               1
#define DEM_INTERRID_SW_MINOR_VERSION               0
#define DEM_INTERRID_SW_PATCH_VERSION               1

/*======================================FILE VERSION CHECKS=======================================*/

#include "Dem_Types.h"

/*======================================== CONSTANTS=============================================*/
                                          


/*===================================== DEFINES AND MACROS========================================*/

[!LOOP " DemConfigSet"!]  
 [!LOOP " DemEventParameter/*"!]
/** @brief Identifier for DEM error [!"node:name('.')"!]*/
#define DemConf_DemEventParameter_[!"node:name('.')"!]   ((Dem_EventIdType) [!"num:inttohex(node:value('./DemEventId'))"!])
[!ENDLOOP!]
[!ENDLOOP!]
/*=======================================  ENUMS==============================================*/


/*================================ STRUCTURES AND OTHER TYPEDEFS==================================*/


/*================================GLOBAL VARIABLE DECLARATIONS=====================================*/


/*===================================FUNCTION PROTOTYPES=========================================*/

#ifdef __cplusplus
}
#endif

#endif /* DEM_INTERRID_H */
