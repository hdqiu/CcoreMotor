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
*   @file    Dem.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dem MCAL driver.
*
*   @addtogroup Dem
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Dem.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

/*============================================FILE VERSION CHECKS===================================*/

/*=================================================Constants========================================*/
#define DEM_MAX_NUMBER_OF_EVENTS (uint32)256
/*============================================DEFINES AND MACROS====================================*/

/*===================================================Enums==========================================*/

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

/*===========================================VARIABLE DECLARATIONS==================================*/
/**< @brief DEM byte array storing reported extended data */
VAR(Dem_EventIdType    , DEM_VAR) Dem_EventId[256];                 /**< @brief DEM event ID*/
VAR(Dem_EventStatusType, DEM_VAR) Dem_EventStatus[256];             /**< @brief DEM event status*/

static VAR(uint32, DEM_VAR)              Dem_numEventErrors = (uint32)0;  /**< @brief DEM event number of errors*/
/*============================================FUNCTION PROTOTYPES===================================*/
/** 
* @brief   This function reports the error status. 
* @details This is a function stub only. It loads Dem_EventId = EventId and 
*          Dem_EventStatus = EventStatus and increments Dem_numEventErrors
*     
* @param[in]     EventId      ID of the event
* @param[in]     EventStatus  status of the event
*   
*/
FUNC(void, DEM_CODE) Dem_ReportErrorStatus(VAR(Dem_EventIdType, AUTOMATIC) EventId, VAR(Dem_EventStatusType, AUTOMATIC) EventStatus)
{
        if(DEM_MAX_NUMBER_OF_EVENTS > Dem_numEventErrors)
        {
            Dem_EventId[Dem_numEventErrors] = EventId;
            Dem_EventStatus[Dem_numEventErrors] = EventStatus;
            Dem_numEventErrors++;
        }
        else
        {
            Dem_EventId[(Dem_numEventErrors-1U)] = EventId;
            Dem_EventStatus[(Dem_numEventErrors-1U)] = EventStatus;
        }
}

/*================================================================================================*/
/** 
* @brief   This function sets the error status. 
* @details This is a function stub only. It loads Dem_EventId2 = EventId and 
*          Dem_EventStatus2 = EventStatus and returns success.
*     
* @param[in]     EventId        ID of the event
* @param[in]     EventStatus    status of the event 
* @return        Std_ReturnType This function is always successful
*   
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(VAR(Dem_EventIdType, AUTOMATIC) EventId, VAR(Dem_EventStatusType, AUTOMATIC) EventStatus)
{
    if(DEM_MAX_NUMBER_OF_EVENTS > Dem_numEventErrors)
    {
        Dem_EventId[Dem_numEventErrors] = EventId;
        Dem_EventStatus[Dem_numEventErrors] = EventStatus;
        Dem_numEventErrors++;
    }
    else
    {
        Dem_EventId[(Dem_numEventErrors-1U)] = EventId;
        Dem_EventStatus[(Dem_numEventErrors-1U)] = EventStatus;
    }
    return(E_OK);
}


#ifdef __cplusplus
}
#endif
