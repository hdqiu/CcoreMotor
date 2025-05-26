/**
*   @file    WdgIf.h
*   @version 1.0.1
*
*   @brief   AUTOSAR WdgIf - Interface header file.
*   @details Contains information about Interface header file.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup Wdg
*   @{
*/
/*==================================================================================================
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef WDGIF_H
#define WDGIF_H

#ifdef __cplusplus
extern "C"{
#endif



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


#include "WdgIf_Cfg.h"
#include "WdgIf_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/


#define WDGIF_H_VENDOR_ID                    176
#define WDGIF_MODULE_ID                      43
#define WDGIF_H_VERSION_MAJOR                4
#define WDGIF_H_VERSION_MINOR                4
#define WDGIF_H_VERSION_REVISION             0
#define WDGIF_H_SW_VERSION_MAJOR             1
#define WDGIF_H_SW_VERSION_MINOR             0
#define WDGIF_H_SW_VERSION_PATCH             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if ((WDGIF_H_VERSION_MAJOR    != WDGIF_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDGIF_H_VERSION_MINOR    != WDGIF_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDGIF_H_VERSION_REVISION != WDGIF_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of WdgIf.h and WdgIf_Cfg.h are different"
#endif
/* Check if current file and WDGIF configuration header file are of the same software version */
#if ((WDGIF_H_SW_VERSION_MAJOR != WDGIF_SW_MAJOR_VERSION_CFG) || \
     (WDGIF_H_SW_VERSION_MINOR != WDGIF_SW_MINOR_VERSION_CFG) || \
     (WDGIF_H_SW_VERSION_PATCH != WDGIF_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of WdgIf.h and WdgIf_Cfg.h are different"
#endif


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

extern const WdgIf_SetModeFctPtrType WdgIf_SetModeFctPtr[WDGIF_NUMBER_OF_DEVICES];
extern const WdgIf_SetTriggerFctPtrType WdgIf_SetTriggerConditionFctPtr[WDGIF_NUMBER_OF_DEVICES];

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*   @brief  This define indicates the error detectable by the Watchdog Driver Interface
*/
#define WDGIF_E_PARAM_DEVICE    (uint8)0x01

/**
*    @brief  Service id for the setmode function
*/
#define WDGIF_SETMODE_ID   (uint8)0x01

/**
*   @brief  Service id for the trigger function
*/
#define WDGIF_TRIGGER_ID   (uint8)0x02

/** 
*   @brief  Define the setmode function
*/  
#define WdgIf_SetMode(DeviceIndex, WdgMode)    WdgIf_SetModeFctPtr[(DeviceIndex)](WdgMode)
   
 
/** 
*   @brief  Define the setmode function
*/  
#define WdgIf_SetTriggerCondition(DeviceIndex, Timeout) WdgIf_SetTriggerConditionFctPtr[(DeviceIndex)](Timeout)

#if (WDGIF_VERSION_INFO_API==STD_ON)

/**
*   @brief  Service id for the trigger function
*/
    #define WDGIF_VERSION_ID   (uint8)0x03
    
/**
*   @brief  WdgIf_GetVersionInfo function
*/
    #define WdgIf_GetVersionInfo(versioninfo) { (versioninfo)->vendorID = WDGIF_VENDOR_ID; \
                                                (versioninfo)->moduleID = WDGIF_MODULE_ID; \
                                                (versioninfo)->sw_major_version = WDGIF_SW_MAJOR_VERSION; \
                                                (versioninfo)->sw_minor_version = WDGIF_SW_MINOR_VERSION; \
                                                (versioninfo)->sw_patch_version = WDGIF_SW_PATCH_VERSION; \
                                              }                                         
#endif /* WDGIF_VERSION_INFO_API==STD_ON */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*WDGIF_H*/
