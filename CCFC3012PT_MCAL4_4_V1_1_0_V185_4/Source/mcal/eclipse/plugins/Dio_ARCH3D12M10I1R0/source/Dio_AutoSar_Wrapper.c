/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
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
*****************************************************************************/
/**
*   @file    Dio.c
*   @version 1.0.0
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dio MCAL driver.
*   @addtogroup Dio
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Dio_AutoSar_Wrapper.h"
#include "SchM_Dio.h"
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define DIO_ATS_WRA_C_VENDOR_ID                     176
#define DIO_ATS_WRA_C_MAJOR_VERSION                 4
#define DIO_ATS_WRA_C_MINOR_VERSION                 4
#define DIO_ATS_WRA_C_patch_VERSION                 0
#define DIO_ATS_WRA_C_SW_MAJOR_VERSION              1
#define DIO_ATS_WRA_C_SW_MINOR_VERSION              0
#define DIO_ATS_WRA_C_SW_PATCH_VERSION              1

/*============================================FILE VERSION CHECKS===================================*/
#if (DIO_ATS_WRA_C_VENDOR_ID != DIO_ATS_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_C_VENDOR_ID "
#endif
#if (DIO_ATS_WRA_C_MAJOR_VERSION != DIO_ATS_WRA_H_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_C_MAJOR_VERSION "
#endif
#if (DIO_ATS_WRA_C_MINOR_VERSION != DIO_ATS_WRA_H_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_C_MINOR_VERSION "
#endif
#if (DIO_ATS_WRA_C_patch_VERSION != DIO_ATS_WRA_H_patch_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_C_patch_VERSION "
#endif
#if (DIO_ATS_WRA_C_SW_MAJOR_VERSION != DIO_ATS_WRAH_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_C_SW_MAJOR_VERSION "
#endif
#if (DIO_ATS_WRA_C_SW_MINOR_VERSION != DIO_ATS_WRA_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_C_SW_MINOR_VERSION "
#endif
#if (DIO_ATS_WRA_C_SW_PATCH_VERSION != DIO_ATS_WRA_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_ATS_WRA_C_SW_PATCH_VERSION "
#endif

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
/*****************************************************************************
** Service Name       : Dio_Auto_Wrap_ReadChannel                                              
** 
** 
**  Description      : Service to read a level of a channel                         
**                                                                            
**  Parameters (in)  : ChannelId: ID of Dio channel                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                  
**                                                                            
******************************************************************************/


/*****************************************************************************
** Service Name       : Dio_Auto_Wrap_WriteChanne                                              
** 
** 
**  Description      : Service to write a level of a channel                         
**                                                                            
**  Parameters (in)  : ChannelId: ID of Dio channel
**                     Level: Value to be written                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/


/*****************************************************************************
** Service Name       : Dio_Auto_Wrap_ReadPort                                              
** 
** 
**  Description      : Returns the Level of all channels of that port                          
**                                                                            
**  Parameters (in)  : PortlId: ID of Dio port                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/


/*****************************************************************************
** Service Name       : Dio_Auto_Wrap_WritePort                                              
** 
** 
**  Description      : Service to set a value of the port                           
**                                                                            
**  Parameters (in)  : portId: ID of Dio port
**                      Level: Value to be written                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/


/*****************************************************************************
** Service Name       : Dio_Auto_Wrap_ReadChannelGroup                                              
** 
** 
**  Description      : This seevice reads a subset of the adjoining bits of 
**      a port                     
**                                                                            
**  Parameters (in)  : ChannelGroupIdPtr: Pointer to channelgroup                                                          
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
FUNC (Dio_PortLevelType, DIO_CODE) Dio_Auto_Wrap_ReadChannelGroup \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) sDio_ChannelGroupIdPtr \
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask = sDio_ChannelGroupIdPtr->mask;
    VAR(uint8, AUTOMATIC)            u8Dio_ChannelGroupoffset = sDio_ChannelGroupIdPtr->offset;
    VAR(Dio_PortType, AUTOMATIC)       u8Dio_ChannelGroupport = sDio_ChannelGroupIdPtr->port;
    VAR(Dio_PortType, AUTOMATIC)           u8Dio_ChannelGroup = sDio_ChannelGroupIdPtr->portgroup;
    VAR(Dio_PortLevelType, AUTOMATIC)        u16Dio_PortLevel = (Dio_PortLevelType)STD_LOW;

    return Dio_LLDrivers_ReadChannelGroup(u8Dio_ChannelGroupport, \
                                          u8Dio_ChannelGroup, \
                                          u8Dio_ChannelGroupoffset, \
                                          u16Dio_ChannelGroupmask, \
                                          u16Dio_PortLevel);
}

/*****************************************************************************
** Service Name       : Dio_Auto_Wrap_WriteChanneGroup                                              
** 
** 
**  Description      : Service to set a subset of the adjoining bits of a port
**      to a specified level                     
**                                                                            
**  Parameters (in)  : ChannelGroupIdPtr: Pointer to channelgroup                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
FUNC (void, DIO_CODE) Dio_Auto_Wrap_WriteChanneGroup \
( \
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) sDio_ChannelGroupIdPtr,\
    CONST(Dio_PortLevelType, DIO_CONST) u16Dio_Level \
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) u16Dio_ChannelGroupmask = sDio_ChannelGroupIdPtr->mask;
    VAR(uint8, AUTOMATIC)            u8Dio_ChannelGroupoffset = sDio_ChannelGroupIdPtr->offset;
    VAR(Dio_PortType, AUTOMATIC)       u8Dio_ChannelGroupport = sDio_ChannelGroupIdPtr->portgroup;

    Dio_LLDrivers_WriteChannelGroup(u8Dio_ChannelGroupport, \
                                    u8Dio_ChannelGroupoffset, \
                                    u16Dio_ChannelGroupmask, \
                                    u16Dio_Level);
}

/*****************************************************************************
** Service Name       : Dio_Auto_Wrap_FlipChannel                                              
** 
** 
**  Description      : Service to flip(change from 1 to 0 or from 0 to 1)the 
**  level of a channel and return the lebel of the channel after flip.                         
**                                                                            
**  Parameters (in)  : ChannelId: ID of Dio channel                            
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
FUNC(Dio_LevelType, DIO_CODE) Dio_Auto_Wrap_FlipChannel \
( \
    CONST(Dio_ChannelType, AUTOMATIC) u16Dio_ChannelId \
)
{
    VAR(Dio_LevelType, DIO_VAR) u8Dio_ChannelLevel = (Dio_LevelType)STD_LOW;
SchM_Enter_DIO_EXCLUSIVE_AREA_00();
    if (SIUL.GPDO[u16Dio_ChannelId].B.PDO == (Dio_LevelType)STD_HIGH)
    {
        u8Dio_ChannelLevel = STD_LOW;  
    }
    else
    {
        u8Dio_ChannelLevel = STD_HIGH;
    }
SchM_Exit_DIO_EXCLUSIVE_AREA_00();
    return Dio_LLDrivers_FlipChannel(u16Dio_ChannelId, u8Dio_ChannelLevel);
}


#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
#ifdef __cplusplus
}
#endif
