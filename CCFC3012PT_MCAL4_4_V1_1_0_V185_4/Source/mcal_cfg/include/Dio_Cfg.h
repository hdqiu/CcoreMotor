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
*   @file    Dio_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dio MCAL driver.
*
*   @addtogroup Dio
*   @{
*/
#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Dio_Types.h"
/*=============================SOURCE FILE VERSION INFORMATION==================================*/
#define DIO_CFG_H_VENDOR_ID                     176
#define DIO_CFG_H_MAJOR_VERSION                 4
#define DIO_CFG_H_MINOR_VERSION                 4
#define DIO_CFG_H_patch_VERSION                 0
#define DIO_CFG_H_SW_MAJOR_VERSION              1
#define DIO_CFG_H_SW_MINOR_VERSION              0
#define DIO_CFG_H_SW_PATCH_VERSION              1
/*====================================FILE VERSION CHECKS=======================================*/
#if (DIO_CFG_H_VENDOR_ID != DIO_TYPES_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_CFG_H_VENDOR_ID "
#endif
#if (DIO_CFG_H_MAJOR_VERSION != DIO_TYPES_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_MAJOR_VERSION "
#endif
#if (DIO_CFG_H_MINOR_VERSION != DIO_TYPES_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_MINOR_VERSION "
#endif
#if (DIO_CFG_H_patch_VERSION != DIO_TYPES_patch_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_patch_VERSION "
#endif
#if (DIO_CFG_H_SW_MAJOR_VERSION != DIO_TYPES_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_SW_MAJOR_VERSION "
#endif
#if (DIO_CFG_H_SW_MINOR_VERSION != DIO_TYPES_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_SW_MINOR_VERSION "
#endif
#if (DIO_CFG_H_SW_PATCH_VERSION != DIO_TYPES_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_SW_PATCH_VERSION "
#endif

/*=========================================CONSTANTS============================================*/


#define DIO_DEV_ERROR_DETECT    (STD_ON)

#define DIO_VERSION_INFO_API    (STD_ON)

#define DIO_FLIP_CHANNEL_API    (STD_ON)

#define DIO_MASKEDWRITEPORT_API (STD_ON)

#define DIO_READZERO_UNDEFINEDPORTS (STD_ON)

#define DIO_MULTICORE_SUPPORT (STD_ON)
 
#define DIO_NUM_PORTS_U16 (uint16)(24)

#define DIO_NUM_CHANNELS_RIDE_PORT_U16 (uint16)0x10U

#define DIO_ZERO_U16 ((Dio_PortLevelType)0x0U)

#define DIO_NUM_CHANNELS_U16     ((uint16)DIO_NUM_PORTS_U16 * DIO_NUM_CHANNELS_RIDE_PORT_U16)

#define DIO_PRECOMPILE_SUPPORT



#define ncoreid  0

#define DIO_OFFSET_MAX_VALID_U8 ((uint8)0x1FU)
extern CONST(Dio_PortLevelType, DIO_CONST) Dio_ReadAvailablePins[DIO_NUM_PORTS_U16];
extern CONST(Dio_PortLevelType, DIO_CONST) Dio_WriteAvailablePins[DIO_NUM_PORTS_U16];
extern CONST(Dio_ConfigType, DIO_CONST) Dio_ConfigPC;


/**
* @brief          Symbolic name for the port DioPort_A.
*
*/
#define DioConf_DioPort_DioPort_A  ((uint8)0x00U/2)
#define DioConf_DioPort_Group_DioPort_A  ((uint8)0x00U)


/**
* @brief          Symbolic name for the port DioChannel_A0.
*/
#define DioConf_DioChannel_DioChannel_A0 ((uint16)0U)


/**
* @brief          Symbolic name for the port DioChannel_A1.
*/
#define DioConf_DioChannel_DioChannel_A1 ((uint16)1U)


/**
* @brief          Symbolic name for the port DioChannel_A2.
*/
#define DioConf_DioChannel_DioChannel_A2 ((uint16)2U)


/**
* @brief          Symbolic name for the port DioChannelGroup_A0.
*/
#define DioConf_DioChannelGroup_DioChannelGroup_A0    \
                    (&DioConf_aChannelGroupList[0])



/**
* @brief          Symbolic name for the port DioPort_B.
*
*/
#define DioConf_DioPort_DioPort_B  ((uint8)0x01U/2)
#define DioConf_DioPort_Group_DioPort_B  ((uint8)0x01U)


/**
* @brief          Symbolic name for the port DioChannel_B9.
*/
#define DioConf_DioChannel_DioChannel_B9 ((uint16)25U)




/**
* @brief          Symbolic name for the port DioPort_C.
*
*/
#define DioConf_DioPort_DioPort_C  ((uint8)0x02U/2)
#define DioConf_DioPort_Group_DioPort_C  ((uint8)0x02U)


/**
* @brief          Symbolic name for the port DioChannel_c0.
*/
#define DioConf_DioChannel_DioChannel_c0 ((uint16)32U)


/**
* @brief          Symbolic name for the port DioChannel_c1.
*/
#define DioConf_DioChannel_DioChannel_c1 ((uint16)33U)


/**
* @brief          Symbolic name for the port DioChannel_c2.
*/
#define DioConf_DioChannel_DioChannel_c2 ((uint16)34U)


/**
* @brief          Symbolic name for the port DioChannel_c3.
*/
#define DioConf_DioChannel_DioChannel_c3 ((uint16)35U)


/**
* @brief          Symbolic name for the port DioChannel_c4.
*/
#define DioConf_DioChannel_DioChannel_c4 ((uint16)36U)


/**
* @brief          Symbolic name for the port DioChannel_c5.
*/
#define DioConf_DioChannel_DioChannel_c5 ((uint16)37U)


/**
* @brief          Symbolic name for the port DioChannel_c6.
*/
#define DioConf_DioChannel_DioChannel_c6 ((uint16)38U)


/**
* @brief          Symbolic name for the port DioChannel_c7.
*/
#define DioConf_DioChannel_DioChannel_c7 ((uint16)39U)


/**
* @brief          Symbolic name for the port DioChannel_c8.
*/
#define DioConf_DioChannel_DioChannel_c8 ((uint16)40U)


/**
* @brief          Symbolic name for the port DioChannel_c9.
*/
#define DioConf_DioChannel_DioChannel_c9 ((uint16)41U)


/**
* @brief          Symbolic name for the port DioChannel_c10.
*/
#define DioConf_DioChannel_DioChannel_c10 ((uint16)42U)


/**
* @brief          Symbolic name for the port DioChannel_c11.
*/
#define DioConf_DioChannel_DioChannel_c11 ((uint16)43U)


/**
* @brief          Symbolic name for the port DioChannel_c12.
*/
#define DioConf_DioChannel_DioChannel_c12 ((uint16)44U)


/**
* @brief          Symbolic name for the port DioChannel_c13.
*/
#define DioConf_DioChannel_DioChannel_c13 ((uint16)45U)


/**
* @brief          Symbolic name for the port DioChannel_c14.
*/
#define DioConf_DioChannel_DioChannel_c14 ((uint16)46U)


/**
* @brief          Symbolic name for the port DioChannel_c15.
*/
#define DioConf_DioChannel_DioChannel_c15 ((uint16)47U)


/**
* @brief          Symbolic name for the port DioChannelGroup_0.
*/
#define DioConf_DioChannelGroup_DioChannelGroup_0    \
                    (&DioConf_aChannelGroupList[1])

/**
* @brief          Symbolic name for the port DioChannelGroup_1.
*/
#define DioConf_DioChannelGroup_DioChannelGroup_1    \
                    (&DioConf_aChannelGroupList[2])



/**
* @brief          Symbolic name for the port DioPort_H.
*
*/
#define DioConf_DioPort_DioPort_H  ((uint8)0x07U/2)
#define DioConf_DioPort_Group_DioPort_H  ((uint8)0x07U)


/**
* @brief          Symbolic name for the port DioChannel_H0.
*/
#define DioConf_DioChannel_DioChannel_H0 ((uint16)112U)


/**
* @brief          Symbolic name for the port DioChannel_H2.
*/
#define DioConf_DioChannel_DioChannel_H2 ((uint16)114U)


/**
* @brief          Symbolic name for the port DioChannel_H3.
*/
#define DioConf_DioChannel_DioChannel_H3 ((uint16)115U)


/**
* @brief          Symbolic name for the port DioChannel_H4.
*/
#define DioConf_DioChannel_DioChannel_H4 ((uint16)116U)


/**
* @brief          Symbolic name for the port DioChannel_H6.
*/
#define DioConf_DioChannel_DioChannel_H6 ((uint16)118U)


/**
* @brief          Symbolic name for the port DioChannel_H7.
*/
#define DioConf_DioChannel_DioChannel_H7 ((uint16)119U)


/**
* @brief          Symbolic name for the port DioChannel_H8.
*/
#define DioConf_DioChannel_DioChannel_H8 ((uint16)120U)


/**
* @brief          Symbolic name for the port DioChannel_H9.
*/
#define DioConf_DioChannel_DioChannel_H9 ((uint16)121U)


/**
* @brief          Symbolic name for the port DioChannel_H10.
*/
#define DioConf_DioChannel_DioChannel_H10 ((uint16)122U)


/**
* @brief          Symbolic name for the port DioChannel_H11.
*/
#define DioConf_DioChannel_DioChannel_H11 ((uint16)123U)


/**
* @brief          Symbolic name for the port DioChannel_H14.
*/
#define DioConf_DioChannel_DioChannel_H14 ((uint16)126U)


/**
* @brief          Symbolic name for the port DioChannel_H15.
*/
#define DioConf_DioChannel_DioChannel_H15 ((uint16)127U)




/**
* @brief          Symbolic name for the port DioPort_D.
*
*/
#define DioConf_DioPort_DioPort_D  ((uint8)0x03U/2)
#define DioConf_DioPort_Group_DioPort_D  ((uint8)0x03U)


/**
* @brief          Symbolic name for the port DioChannel_D0.
*/
#define DioConf_DioChannel_DioChannel_D0 ((uint16)48U)




/**
* @brief          Symbolic name for the port DioPort_E.
*
*/
#define DioConf_DioPort_DioPort_E  ((uint8)0x04U/2)
#define DioConf_DioPort_Group_DioPort_E  ((uint8)0x04U)


/**
* @brief          Symbolic name for the port DioChannel_E0.
*/
#define DioConf_DioChannel_DioChannel_E0 ((uint16)64U)




/**
* @brief          Symbolic name for the port DioPort_F.
*
*/
#define DioConf_DioPort_DioPort_F  ((uint8)0x05U/2)
#define DioConf_DioPort_Group_DioPort_F  ((uint8)0x05U)


/**
* @brief          Symbolic name for the port DioChannel_F1.
*/
#define DioConf_DioChannel_DioChannel_F1 ((uint16)81U)




/**
* @brief          Symbolic name for the port DioPort_G.
*
*/
#define DioConf_DioPort_DioPort_G  ((uint8)0x06U/2)
#define DioConf_DioPort_Group_DioPort_G  ((uint8)0x06U)


/**
* @brief          Symbolic name for the port DioChannel_G0.
*/
#define DioConf_DioChannel_DioChannel_G0 ((uint16)96U)




/**
* @brief          Symbolic name for the port DioPort_I.
*
*/
#define DioConf_DioPort_DioPort_I  ((uint8)0x08U/2)
#define DioConf_DioPort_Group_DioPort_I  ((uint8)0x08U)


/**
* @brief          Symbolic name for the port DioChannel_I8.
*/
#define DioConf_DioChannel_DioChannel_I8 ((uint16)136U)


/**
* @brief          Symbolic name for the port DioChannel_I9.
*/
#define DioConf_DioChannel_DioChannel_I9 ((uint16)137U)




/**
* @brief          Symbolic name for the port DioPort_J.
*
*/
#define DioConf_DioPort_DioPort_J  ((uint8)0x09U/2)
#define DioConf_DioPort_Group_DioPort_J  ((uint8)0x09U)


/**
* @brief          Symbolic name for the port DioChannel_J0.
*/
#define DioConf_DioChannel_DioChannel_J0 ((uint16)144U)


/**
* @brief          Symbolic name for the port DioChannel_J1.
*/
#define DioConf_DioChannel_DioChannel_J1 ((uint16)145U)




/**
* @brief          Symbolic name for the port DioPort_K.
*
*/
#define DioConf_DioPort_DioPort_K  ((uint8)0x0aU/2)
#define DioConf_DioPort_Group_DioPort_K  ((uint8)0x0aU)


/**
* @brief          Symbolic name for the port DioChannel_K15.
*/
#define DioConf_DioChannel_DioChannel_K15 ((uint16)175U)




/**
* @brief          Symbolic name for the port DioPort_L.
*
*/
#define DioConf_DioPort_DioPort_L  ((uint8)0x0bU/2)
#define DioConf_DioPort_Group_DioPort_L  ((uint8)0x0bU)


/**
* @brief          Symbolic name for the port DioChannel_L0.
*/
#define DioConf_DioChannel_DioChannel_L0 ((uint16)176U)




/**
* @brief          Symbolic name for the port DioPort_M.
*
*/
#define DioConf_DioPort_DioPort_M  ((uint8)0x0cU/2)
#define DioConf_DioPort_Group_DioPort_M  ((uint8)0x0cU)


/**
* @brief          Symbolic name for the port DioChannel_M0.
*/
#define DioConf_DioChannel_DioChannel_M0 ((uint16)192U)




/**
* @brief          Symbolic name for the port DioPort_N.
*
*/
#define DioConf_DioPort_DioPort_N  ((uint8)0x0dU/2)
#define DioConf_DioPort_Group_DioPort_N  ((uint8)0x0dU)


/**
* @brief          Symbolic name for the port DioChannel_N0.
*/
#define DioConf_DioChannel_DioChannel_N0 ((uint16)208U)




/**
* @brief          Symbolic name for the port DioPort_Q.
*
*/
#define DioConf_DioPort_DioPort_Q  ((uint8)0x10U/2)
#define DioConf_DioPort_Group_DioPort_Q  ((uint8)0x10U)



/**
* @brief          Symbolic name for the port DioChannel_Q0.
*/
#define DioConf_DioChannel_DioChannel_Q0 ((uint16)257U)



/**
* @brief          Symbolic name for the port DioChannel_Q1.
*/
#define DioConf_DioChannel_DioChannel_Q1 ((uint16)258U)




/**
* @brief          Symbolic name for the port DioPort_R.
*
*/
#define DioConf_DioPort_DioPort_R  ((uint8)0x11U/2)
#define DioConf_DioPort_Group_DioPort_R  ((uint8)0x11U)



/**
* @brief          Symbolic name for the port DioChannelr_0.
*/
#define DioConf_DioChannel_DioChannelr_0 ((uint16)283U)




/**
* @brief          Symbolic name for the port DioPort_S.
*
*/
#define DioConf_DioPort_DioPort_S  ((uint8)0x12U/2)
#define DioConf_DioPort_Group_DioPort_S  ((uint8)0x12U)



/**
* @brief          Symbolic name for the port DioChannel_S0.
*/
#define DioConf_DioChannel_DioChannel_S0 ((uint16)289U)




/**
* @brief          Symbolic name for the port DioPort_V.
*
*/
#define DioConf_DioPort_DioPort_V  ((uint8)0x15U/2)
#define DioConf_DioPort_Group_DioPort_V  ((uint8)0x15U)


/**
* @brief          Symbolic name for the port DioChannel_V0.
*/
#define DioConf_DioChannel_DioChannel_V0 ((uint16)336U)


/**
* @brief          Symbolic name for the port DioChannel_V1.
*/
#define DioConf_DioChannel_DioChannel_V1 ((uint16)337U)




#define DIO_CHANNEL_GROUPS_AVAILABLE




extern CONST(Dio_ChannelGroupType, DIO_CONST) DioConf_aChannelGroupList[3];
extern P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) u32ChannelGroupsListForEachPartition[6][3];





#endif  /* DIO_CFG_H */
