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
*   @file    Icu_eMIOS_HAL_Wrapper.c
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

/*===================================================================================================
                                        INCLUDE FILES
===================================================================================================*/
#include "Icu_eMIOS_HAL_Wrapper.h"
#include "eMIOS_LLDriver.h"
#include "Icu_eMIOS_LLDrivers.h"
#include "Icu.h"
#include "eMIOS_HAL_Irq.h"
#include "Icu_Irq.h"
/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
===================================================================================================*/

/*==================================================================================================
                                        FILE VERSION CHECKS
===================================================================================================*/
#define ICU_EMIOS_HAL_WRAPPER_VENDOR_ID_C                  176

#define ICU_EMIOS_HAL_WRAPPER_MAJOR_VER_C                  4
#define ICU_EMIOS_HAL_WRAPPER_MINOR_VER_C                  4
#define ICU_EMIOS_HAL_WRAPPER_REVISION_VER_C               0

#define ICU_EMIOS_HAL_WRAPPER_SW_MAJOR_VER_C               1
#define ICU_EMIOS_HAL_WRAPPER_SW_MINOR_VER_C               0
#define ICU_EMIOS_HAL_WRAPPER_SW_PATCH_VER_C               1

#if (ICU_EMIOS_HAL_WRAPPER_VENDOR_ID_C != ICU_EMIOS_HAL_WRAPPER_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_EMIOS_HAL_WRAPPER_MAJOR_VER_C != ICU_EMIOS_HAL_WRAPPER_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ICU_EMIOS_HAL_WRAPPER_MINOR_VER_C != ICU_EMIOS_HAL_WRAPPER_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ICU_EMIOS_HAL_WRAPPER_REVISION_VER_C != ICU_EMIOS_HAL_WRAPPER_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_EMIOS_HAL_WRAPPER_SW_MAJOR_VER_C != ICU_EMIOS_HAL_WRAPPER_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_EMIOS_HAL_WRAPPER_SW_MINOR_VER_C != ICU_EMIOS_HAL_WRAPPER_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_EMIOS_HAL_WRAPPER_SW_PATCH_VER_C != ICU_EMIOS_HAL_WRAPPER_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
static VAR(eMIOS_Channel_ConfigData, ICU_VAR) sIcu_eMios_ChConfig[ICU_CORE_NUM][EMIOS_CHANNEL_MAX];

static VAR(eMIOS_Module_ConfigData, ICU_VAR) sIcu_eMios_ModConfig[ICU_CORE_NUM][EMIOS_MODULE_MAX];

#if (ICU_EDGE_COUNT_API == STD_ON)
static VAR(uint32, ICU_VAR) sIcu_eMios_EdgeCurrent_Value[ICU_CORE_NUM][EMIOS_CHANNEL_MAX] =
    { {0} };
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
static VAR(Icu_ValueType,ICU_VAR) sIcu_eMios_ttBuffer[ICU_CORE_NUM][EMIOS_CHANNEL_MAX] = { {0} };
#endif

static VAR(uint8, ICU_VAR) sIcu_NumOverflowNotifyByMasterBus[ICU_CORE_NUM][EMIOS_CHANNEL_MAX] = { {0} };

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
static VAR(Icu_ValueType, ICU_VAR) sIcu_eMios_aInt_Counter[ICU_CORE_NUM][EMIOS_CHANNEL_MAX];
static VAR(Icu_ValueType, ICU_VAR) sIcu_eMios_CapturedActivePulseWidth[ICU_CORE_NUM][EMIOS_CHANNEL_MAX];
static VAR(Icu_ValueType, ICU_VAR) sIcu_eMios_TimeStart[ICU_CORE_NUM][EMIOS_CHANNEL_MAX];
#endif /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetModConfig \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint32,     AUTOMATIC) u32Mask, \
    VAR(uint32,     AUTOMATIC) u32Value \
);

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetModConfig \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint32,     AUTOMATIC) u32Mask \
);

#if (ICU_EDGE_COUNT_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetEdgeValue \
( \
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(Icu_ValueType,  AUTOMATIC) u32Value \
);

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetEdgeValue \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetTtBuffer \
( \
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(Icu_ValueType,  AUTOMATIC) u32Value \
);
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetIntCounter \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint8, AUTOMATIC) u8Value \
);

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetIntCounter \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetPulseWidth \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32Value \
);

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetPulseWidth \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetTimeStart \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32Value \
);

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetTimeStart \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#endif

LOCAL_INLINE FUNC(uint8, ICU_CODE) eMios_GetOverflow \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
);

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetOverflow \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint8, AUTOMATIC) u8Value \
);

LOCAL_INLINE FUNC(ICU_eMIOS_Types, ICU_CODE) eMios_GetOpMode(VAR(eMIOS_IC_ModeType, ICU_VAR) eMode );

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Wrapper_Channel_Timestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(uint8,      AUTOMATIC) u8Capture, \
    P2CONST(uint32, AUTOMATIC, ICU_APPL_CONST) pu32Value, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = ICU_ATS_eMios_Wapper_GetInstance(u8Module, u8Channel);

    ICU_AutoSAR_Wapper_Timestamp(Instance, u8Capture, pu32Value, bOverflow);
}

LOCAL_INLINE FUNC (void, ICU_CODE) eMios_Wrapper_Channel_SignalMeasurement \
( \
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(Icu_ValueType,  AUTOMATIC) activePulseWidth, \
    VAR(Icu_ValueType,  AUTOMATIC) period, \
    VAR(boolean,        AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = ICU_ATS_eMios_Wapper_GetInstance(u8Module, u8Channel);

    ICU_SignalMeasurement(Instance, activePulseWidth, period, bOverflow);

}

LOCAL_INLINE FUNC (void, ICU_CODE) eMios_Wrapper_Channel_ReportWakeupAndOverflow \
( \
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(boolean,        AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = ICU_ATS_eMios_Wapper_GetInstance(u8Module, u8Channel);

    ICU_ReportWakeupAndOverflow(Instance, bOverflow);
}

LOCAL_INLINE FUNC (void, ICU_CODE) eMios_Wrapper_Channel_ReportEvents \
( \
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(boolean,        AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ChannelType, ICU_VAR) Instance = ICU_ATS_eMios_Wapper_GetInstance(u8Module, u8Channel);

    ICU_AutoSAR_Wapper_ReportEvents(Instance, bOverflow);
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetModConfig \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint32,     AUTOMATIC) u32Mask, \
    VAR(uint32,     AUTOMATIC) u32Value \
)
{
    switch (u32Mask)
    {
    case EMIOS_MOD_CONFIG_DATA_INITED:
    {
        sIcu_eMios_ModConfig[GetCoreID()][u8Module].bits.inited = (uint8)u32Value;/* GetCoreID */
        break;
    }
    default:
    {
        /* do nothing */
        break;
    }
    }
}

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetModConfig \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint32,     AUTOMATIC) u32Mask \
)
{
    VAR(uint32,     AUTOMATIC) u32RetrunValue = (0xFFFFFFFFU);

    switch (u32Mask)
    {
    case EMIOS_MOD_CONFIG_DATA_INITED:
    {
        u32RetrunValue = sIcu_eMios_ModConfig[GetCoreID()][u8Module].bits.inited;/* GetCoreID */
        break;
    }
    default:
    {
        /* do nothing */
        break;
    }
    }

    return u32RetrunValue;
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetChConfig \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(uint32,     AUTOMATIC) u32Mask, \
    VAR(uint32,     AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    switch (u32Mask)
    {
    case EMIOS_CONFIG_DATA_INITED:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.inited = (uint8)u32Value;
        break;
    }
    case EMIOS_CONFIG_DATA_MEASMODE:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.mode = (uint8)u32Value;
        break;
    }
    case EMIOS_CONFIG_DATA_OPMODE:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.opmode = (uint8)u32Value;
        break;
    }
    case EMIOS_CONFIG_DATA_BUSCHANNEL:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.bus_channel = (uint8)u32Value;
        break;
    }
    case EMIOS_CONFIG_DATA_PROPERTY:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.property = (uint8)u32Value;
        break;
    }
    case EMIOS_CONFIG_DATA_SUBMODE:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.submode = (uint8)u32Value;
        break;
    }
    case EMIOS_CONFIG_DATA_CLEAR:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.data = u32Value;
        break;
    }
    case EMIOS_CONFIG_DATA_DESIRED:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].desirednum = u32Value;
        break;
    }
    case EMIOS_CONFIG_DATA_STARTTIME:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].startime = u32Value;
        break;
    }
    case EMIOS_CONFIG_DATA_ENDTIME:
    {
        sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].endtime = u32Value;
        break;
    }
    default:
        /*nothing*/
        break;
    }
}

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetChConfig \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(uint32,     AUTOMATIC) u32Mask \
)
{
    VAR(uint32,     AUTOMATIC) u32RetrunValue = (0xFFFFFFFFU);
    VAR(uint8,      AUTOMATIC) u8ChannelIdx = (uint8)0U;
    VAR(uint8,ICU_VAR) u8Icu_CoreId = (uint8)GetCoreID();

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    switch (u32Mask)
    {
    case EMIOS_CONFIG_DATA_INITED:
    {
        u32RetrunValue = sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.inited;
        break;
    }
    case EMIOS_CONFIG_DATA_MEASMODE:
    {
        u32RetrunValue = sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.mode;
        break;
    }
    case EMIOS_CONFIG_DATA_OPMODE:
    {
        u32RetrunValue = sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.opmode;
        break;
    }
    case EMIOS_CONFIG_DATA_BUSCHANNEL:
    {
        u32RetrunValue = sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.bus_channel;
        break;
    }
    case EMIOS_CONFIG_DATA_PROPERTY:
    {
        u32RetrunValue = sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.property;
        break;
    }
    case EMIOS_CONFIG_DATA_SUBMODE:
    {
        u32RetrunValue = sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].config.bits.submode;
        break;
    }
    case EMIOS_CONFIG_DATA_DESIRED:
    {
        u32RetrunValue = sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].desirednum;
        break;
    }
    case EMIOS_CONFIG_DATA_STARTTIME:
    {
        u32RetrunValue = sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].startime;
        break;
    }
    case EMIOS_CONFIG_DATA_ENDTIME:
    {
        u32RetrunValue = sIcu_eMios_ChConfig[u8Icu_CoreId][u8ChannelIdx].endtime;
        break;
    }
    default:
        /*nothing*/
        break;
    }

    return u32RetrunValue;
}

LOCAL_INLINE FUNC(uint8, ICU_CODE) eMios_GetMasterBusChannel \
( \
    VAR(uint8, AUTOMATIC) u8bus,    \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ReturnValue = (uint8)0U;

    if (u8bus == (uint8)EMIOS_COUNTER_BUS_A)
    {
        u8ReturnValue = EMIOS_CNTBUS_A_CHANNEL_23;
    }
    else if (u8bus == (uint8)EMIOS_COUNTER_BUS_BCDE)
    {
        if (u8Module == (uint8)eMIOS_0)
        {
            if (u8Channel <= EMIOS_CNTBUS_B_CHANNEL_7)
            {
                u8ReturnValue = EMIOS_CNTBUS_B_CHANNEL_0;
            }
            else if (u8Channel <= EMIOS_CNTBUS_C_CHANNEL_15)
            {
                u8ReturnValue = EMIOS_CNTBUS_C_CHANNEL_8;
            }
            else if (u8Channel <= EMIOS_CNTBUS_D_CHANNEL_23)
            {
                u8ReturnValue = EMIOS_CNTBUS_D_CHANNEL_16;
            }
            else if (u8Channel <= EMIOS_CNTBUS_E_CHANNEL_31)
            {
                u8ReturnValue = EMIOS_CNTBUS_E_CHANNEL_24;
            }
            else
            {
                /* Error Channel, do nothing */
                u8ReturnValue = u8Channel;
            }
        }
#if defined(RESOURCE_SUPPORT_EMIOS1)
        else if (u8Module == (uint8)eMIOS_1)
        {
            if (u8Channel <= EMIOS_CNTBUS_B_CHANNEL_7)
            {
                u8ReturnValue = EMIOS_CNTBUS_B_CHANNEL_0;
            }
            else if (u8Channel <= EMIOS_CNTBUS_C_CHANNEL_15)
            {
                u8ReturnValue = EMIOS_CNTBUS_C_CHANNEL_8;
            }
            else if (u8Channel <= EMIOS_CNTBUS_D_CHANNEL_23)
            {
                u8ReturnValue = EMIOS_CNTBUS_D_CHANNEL_16;
            }
            else if (u8Channel <= EMIOS_CNTBUS_E_CHANNEL_31)
            {
                u8ReturnValue = EMIOS_CNTBUS_E_CHANNEL_24;
            }
            else
            {
                /* Error Channel, do nothing */
                u8ReturnValue = u8Channel;
            }
        }
#endif
        else
        {
            /*nothing*/
        }
    }
    else
    {
        /* Error Channel, do nothing */
    }

    return u8ReturnValue;
}

#if (ICU_EDGE_COUNT_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetEdgeValue \
( \
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(Icu_ValueType,  AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_eMios_EdgeCurrent_Value[GetCoreID()][u8ChannelIdx] = u32Value;/* GetCoreID */
}

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetEdgeValue \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = (uint8)((u8Module << 3) + u8Channel);

    return sIcu_eMios_EdgeCurrent_Value[GetCoreID()][u8ChannelIdx];/* GetCoreID */
}
#endif /* ICU_EDGE_COUNT_API */

#if (ICU_TIMESTAMP_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetTtBuffer \
( \
    VAR(uint8,          AUTOMATIC) u8Module, \
    VAR(uint8,          AUTOMATIC) u8Channel, \
    VAR(Icu_ValueType,  AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = (uint8)((u8Module << 3) + u8Channel);

    sIcu_eMios_ttBuffer[GetCoreID()][u8ChannelIdx] = u32Value;/* GetCoreID */
}

FUNC(Icu_ValueType, ICU_CODE) eMios_GetTtBuffer \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_eMios_ttBuffer[GetCoreID()][u8ChannelIdx];/* GetCoreID */
}
#endif /* ICU_TIMESTAMP_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetIntCounter \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint8, AUTOMATIC) u8Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_eMios_aInt_Counter[GetCoreID()][u8ChannelIdx] = u8Value;/* GetCoreID */
}

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetIntCounter \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_eMios_aInt_Counter[GetCoreID()][u8ChannelIdx];/* GetCoreID */
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetPulseWidth \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_eMios_CapturedActivePulseWidth[GetCoreID()][u8ChannelIdx] = u32Value;/* GetCoreID */
}

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetPulseWidth \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_eMios_CapturedActivePulseWidth[GetCoreID()][u8ChannelIdx];/* GetCoreID */
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetTimeStart \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_eMios_TimeStart[GetCoreID()][u8ChannelIdx] = u32Value;/* GetCoreID */
}

LOCAL_INLINE FUNC(uint32, ICU_CODE) eMios_GetTimeStart \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_eMios_TimeStart[GetCoreID()][u8ChannelIdx];/* GetCoreID */
}
#endif /* (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

LOCAL_INLINE FUNC(uint8, ICU_CODE) eMios_GetOverflow \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    return sIcu_NumOverflowNotifyByMasterBus[GetCoreID()][u8ChannelIdx];/* GetCoreID */
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_SetOverflow \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(uint8, AUTOMATIC) u8Value \
)
{
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)0U;

    u8ChannelIdx = EMIOS_MODU_CHAN_COMBIN(u8Module, u8Channel);

    sIcu_NumOverflowNotifyByMasterBus[GetCoreID()][u8ChannelIdx] = u8Value;/* GetCoreID */
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_EnableMasterBusInterrupt \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) nChConfig = (uint32)0U;
    VAR(uint8,  AUTOMATIC) u8MasterBusChannel = (uint8)0U;
    VAR(uint8,  AUTOMATIC) u8OverFlowCounter = (uint8)0U;

    nChConfig = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_BUSCHANNEL);
    if (nChConfig != (uint32)EMIOS_COUNTER_BUS_INTERNAL)
    {
        u8MasterBusChannel = eMios_GetMasterBusChannel( \
            (uint8)nChConfig, \
            u8Module, \
            u8Channel);

        u8OverFlowCounter = eMios_GetOverflow(u8Module, u8MasterBusChannel);

        SchM_Enter_ICU_EXCLUSIVE_AREA_35();

        if (u8OverFlowCounter == (uint8)0U)
        {
            /* Clear time base channel interrupt */
            /* Clear INT flag */
            eMIOS_UC_Sn_ClearFLAG(u8Module, u8MasterBusChannel);
            /* Clear overrun bit */
            eMIOS_UC_Sn_ClearOVR(u8Module, u8MasterBusChannel);
            /* Clear overflow bit */
            eMIOS_UC_Sn_ClearOVFL(u8Module, u8MasterBusChannel);
            /* Enable Master bus Interrupt */
            eMIOS_UC_Cn_SetFEN(u8Module, u8MasterBusChannel, (boolean)TRUE);
        }

        eMios_SetOverflow(u8Module, u8MasterBusChannel, ++u8OverFlowCounter);

        SchM_Exit_ICU_EXCLUSIVE_AREA_35();
    }
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_DisableMasterBusInterrupt \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) nChConfig = (uint32)0U;
    VAR(uint8,  AUTOMATIC) u8MasterBusChannel = (uint8)0U;
    VAR(uint8,  AUTOMATIC) u8OverFlowCounter = (uint8)0U;

    nChConfig = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_BUSCHANNEL);
    if (nChConfig != (uint32)EMIOS_COUNTER_BUS_INTERNAL)
    {
        u8MasterBusChannel = eMios_GetMasterBusChannel( \
            (uint8)nChConfig, \
            u8Module, \
            u8Channel);

        SchM_Enter_ICU_EXCLUSIVE_AREA_36();

        u8OverFlowCounter = eMios_GetOverflow(u8Module, u8MasterBusChannel);
        u8OverFlowCounter --;
        eMios_SetOverflow(u8Module, u8MasterBusChannel, u8OverFlowCounter);
        if (u8OverFlowCounter == (uint8)0U)
        {
            /* Disable Master bus Interrupt */
            eMIOS_UC_Cn_SetFEN(u8Module, u8MasterBusChannel, (boolean)FALSE);
        }

        SchM_Exit_ICU_EXCLUSIVE_AREA_36();
    }
}

LOCAL_INLINE FUNC(ICU_eMIOS_Types, ICU_CODE) eMios_GetOpMode \
( \
    VAR(eMIOS_IC_ModeType, ICU_VAR) eMode \
)
{
    VAR(ICU_eMIOS_Types, AUTOMATIC) returnMode = (ICU_eMIOS_Types)0U;
    switch (eMode)
    {
    case EMIOS_UC_MODE_SAIC_TRIGGER_EDGE_FALLING:
    case EMIOS_UC_MODE_SAIC_EDGE_RISING_TRIGGER:
    case EMIOS_UC_MODE_SAIC_EDGE_ANY_TRIGGER:
    {
        returnMode = EMIOS_IC_SAIC;
        break;
    }
    case EMIOS_UC_MODE_IPM_EDGE_RISING:
    case EMIOS_UC_MODE_IPM_EDGE_FALLING:
    {
        returnMode = EMIOS_IC_IPM;
        break;
    }
    case EMIOS_UC_MODE_IPWM_PERIOD_ON:
    case EMIOS_UC_MODE_IPWM_PERIOD_OFF:
    {
        returnMode = EMIOS_IC_IPWM;
        break;
    }
    case EMIOS_UC_MODE_PEA_CONTIN_EDGE_RISING:
    case EMIOS_UC_MODE_PEA_CONTIN_EDGE_FALLING:
    case EMIOS_UC_MODE_PEA_CONTIN_EDGE_ANY:
    case EMIOS_UC_MODE_PEA_SINGLE_EDGE_RISING:
    case EMIOS_UC_MODE_PEA_SINGLE_EDGE_FALLING:
    case EMIOS_UC_MODE_PEA_SINGLE_EDGE_ANY:
    {
        returnMode = EMIOS_IC_PEA;
        break;
    }
    case EMIOS_UC_MODE_PEC_CONTIN_EDGE_RISING:
    case EMIOS_UC_MODE_PEC_CONTIN_EDGE_FALLING:
    case EMIOS_UC_MODE_PEC_CONTIN_EDGE_ANY:
    case EMIOS_UC_MODE_PEC_SINGLE_EDGE_RISING:
    case EMIOS_UC_MODE_PEC_SINGLE_EDGE_FALLING:
    case EMIOS_UC_MODE_PEC_SINGLE_EDGE_ANY:
    {
        returnMode = EMIOS_IC_PEC;
        break;
    }
    case EMIOS_UC_MODE_QDEC_FOR_COUNT_DIRECT_EDGE_RISING:
    case EMIOS_UC_MODE_QDEC_EDGE_FALLING_FOR_COUNT_DIRECT:
    case EMIOS_UC_MODE_QDEC_FOR_PHASE_A_B_DIRECT_POSITIVE:
    case EMIOS_UC_MODE_QDEC_NEGATIVE_FOR_PHASE_A_B_DIRECT:
    {
        returnMode = EMIOS_IC_QDEC;
        break;
    }
    case EMIOS_UC_MODE_WPTA_PERIOD_ON:
    case EMIOS_UC_MODE_WPTA_PERIOD_OFF:
    {
        returnMode = EMIOS_IC_WPTA;
        break;
    }
    default:
    {
        /* do nothing */
        break;
    }
    }

    return returnMode;
}

LOCAL_INLINE FUNC(eMIOS_OpSubMode, ICU_CODE) eMios_GetOpSubMode \
( \
    VAR(eMIOS_IC_ModeType, ICU_VAR) eMode \
)
{
    VAR(eMIOS_OpSubMode, AUTOMATIC) returnMode = EMIOS_SUBMODE_SINGLE;
    switch (eMode)
    {
    case EMIOS_UC_MODE_PEA_CONTIN_EDGE_RISING:
    case EMIOS_UC_MODE_PEA_CONTIN_EDGE_FALLING:
    case EMIOS_UC_MODE_PEA_CONTIN_EDGE_ANY:
    {
        returnMode = EMISO_SUBMODE_CONTINUE;
        break;
    }
    case EMIOS_UC_MODE_PEA_SINGLE_EDGE_RISING:
    case EMIOS_UC_MODE_PEA_SINGLE_EDGE_FALLING:
    case EMIOS_UC_MODE_PEA_SINGLE_EDGE_ANY:
    {
        returnMode = EMIOS_SUBMODE_SINGLE;
        break;
    }
    case EMIOS_UC_MODE_PEC_CONTIN_EDGE_RISING:
    case EMIOS_UC_MODE_PEC_CONTIN_EDGE_FALLING:
    case EMIOS_UC_MODE_PEC_CONTIN_EDGE_ANY:
    {
        returnMode = EMISO_SUBMODE_CONTINUE;
        break;
    }
    case EMIOS_UC_MODE_PEC_SINGLE_EDGE_RISING:
    case EMIOS_UC_MODE_PEC_SINGLE_EDGE_FALLING:
    case EMIOS_UC_MODE_PEC_SINGLE_EDGE_ANY:
    {
        returnMode = EMIOS_SUBMODE_SINGLE;
        break;
    }
    case EMIOS_UC_MODE_QDEC_FOR_COUNT_DIRECT_EDGE_RISING:
    case EMIOS_UC_MODE_QDEC_EDGE_FALLING_FOR_COUNT_DIRECT:
    {
        returnMode = EMIOS_SUBMODE_SINGLE;
        break;
    }
    case EMIOS_UC_MODE_QDEC_FOR_PHASE_A_B_DIRECT_POSITIVE:
    case EMIOS_UC_MODE_QDEC_NEGATIVE_FOR_PHASE_A_B_DIRECT:
    {
        returnMode = EMISO_SUBMODE_CONTINUE;
        break;
    }
    default:
    {
        returnMode = EMIOS_SUBMODE_SINGLE;
        break;
    }
    }

    return returnMode;
}

FUNC(void, ICU_CODE) eMios_Module_Init \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint16, AUTOMATIC) u16PrescalClock \
)
{
    if (eMios_GetModConfig(u8Module, EMIOS_MOD_CONFIG_DATA_INITED) != (uint32)1U)
    {
        if (u16PrescalClock == (uint16)0U)
        {
            u16PrescalClock = (uint16)1U;
        }

        {
            VAR(eMIOS_GlobalParamType, AUTOMATIC) seMiosModuleConfig = { \
                (boolean)FALSE,                     /* LowPowerModeEn */
                (boolean)FALSE,                     /* FreezeInDebugMode */
                u16PrescalClock,                    /* GlobalPreClkDiv */
                EMIOS_ETB_DIS_COUNTER_BUSA_TO_UC,   /* ExternalTimeBaseSel */
                (uint8)0U                          /* ServerTimeSlotSel */
            };

            /* initialize eMIOS Global with Config */
            eMIOS_LLD_InitGlobalParam(u8Module, &seMiosModuleConfig);
        }

        /* Enable eMIOS Global */
        eMIOS_LLD_SetEnDisGlobal(u8Module, TRUE);

        eMios_SetModConfig(u8Module, EMIOS_MOD_CONFIG_DATA_INITED, (uint32)1U);
    }
}

FUNC(void, ICU_CODE) eMios_Channel_Init \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    P2CONST(eMIOS_Channel_Config, AUTOMATIC, ICU_APPL_CONST) peMiosChannelConfig \
)
{
    P2CONST(eMIOS_IC_ParamType, AUTOMATIC, ICU_APPL_DATA) spChannelConfig = NULL_PTR;
    VAR(uint8,              AUTOMATIC) u8MasterBusChannel = (uint8)0U;
    VAR(ICU_eMIOS_Types,    AUTOMATIC) eType;
    VAR(eMIOS_OpSubMode,    AUTOMATIC) eSubType;


    spChannelConfig = &peMiosChannelConfig->sChannelParam;
    /* Get emios mode */
    eType = eMios_GetOpMode(spChannelConfig->mode);
    eSubType = eMios_GetOpSubMode(spChannelConfig->mode);
    /* Init ic config */
    (void)eMIOS_LLD_IC_Init(u8Module, u8Channel, spChannelConfig);
    /* Set start edge */
    eMios_Channel_SetActivationCondition(u8Module, u8Channel, peMiosChannelConfig->eTrig);
    /* Set Channel Config */
    eMios_SetChConfig(u8Module, u8Channel, \
        EMIOS_CONFIG_DATA_OPMODE, (uint32)eType);

    eMios_SetChConfig(u8Module, u8Channel, \
        EMIOS_CONFIG_DATA_SUBMODE, (uint32)eSubType);

    eMios_SetChConfig(u8Module, u8Channel, \
        EMIOS_CONFIG_DATA_BUSCHANNEL, (uint32)spChannelConfig->timebase);

    eMios_SetChConfig(u8Module, u8Channel, \
        EMIOS_CONFIG_DATA_INITED, (uint32)1U);

    if ((eType == EMIOS_IC_PEA) || (eType == EMIOS_IC_QDEC))
    {
        eMios_SetChConfig(u8Module, u8Channel, \
            EMIOS_CONFIG_DATA_DESIRED, spChannelConfig->desirednum);
    }
    else if ((eType == EMIOS_IC_PEC) || (eType == EMIOS_IC_WPTA))
    {
        eMios_SetChConfig(u8Module, u8Channel, \
            EMIOS_CONFIG_DATA_STARTTIME, spChannelConfig->startime);
        eMios_SetChConfig(u8Module, u8Channel, \
            EMIOS_CONFIG_DATA_ENDTIME, spChannelConfig->endtime);
    }
    else
    {
        /* do nothing */
    }
    if (spChannelConfig->timebase != EMIOS_COUNTER_BUS_INTERNAL)
    {
        /* Used UC channel as time base */
        u8MasterBusChannel = eMios_GetMasterBusChannel( \
            (uint8)spChannelConfig->timebase, \
            u8Module, \
            u8Channel);

        eMios_SetChConfig(u8Module, u8MasterBusChannel, \
            EMIOS_CONFIG_DATA_INITED, (uint32)1U);

        /* Reset Master bus overflow */
        eMios_SetOverflow(u8Module, u8MasterBusChannel, (uint8)0U);
    }
}

FUNC(void, ICU_CODE) eMios_Channel_DeInit \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    /* GPIO mode used reset eMIOS module */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);

    eMIOS_LLD_UC_DeInitChannel(u8Module, u8Channel);

    /* Disable Clock */
    eMIOS_LLD_UC_SetChannelClkEnDis(u8Module, u8Channel, (boolean)FALSE);
#if (ICU_EDGE_COUNT_API == STD_ON)
    /* remove to emios_wrapper layer */
    eMios_SetEdgeValue(u8Module, u8Channel, (uint32)0U);
#endif
    /* Clear config data */
    eMios_SetChConfig(u8Module, u8Channel, \
        EMIOS_CONFIG_DATA_CLEAR, (uint32)0U);
}

FUNC(void, ICU_CODE) eMios_Channel_DisIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    /* Stop eMIOS channel */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)FALSE);
}

FUNC(void, ICU_CODE) eMios_Channel_EnIrq \
(
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) u32Value_CN_FEN = (uint32)0U;

    /* if interrupt not enable, then enable it */
    u32Value_CN_FEN  = (eMIOS_UC_Cn_GetFEN(u8Module, u8Channel) != 0U) ? (uint32)TRUE : (uint32)FALSE;
    if((uint32)0U == u32Value_CN_FEN)
    {
        eMIOS_UC_Sn_ClearFLAG(u8Module, u8Channel);
        eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)TRUE);
    }
}

FUNC(void, ICU_CODE) eMios_Channel_SetActivationCondition \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel, \
    CONST(eMIOS_EdgeTrigModeType, AUTOMATIC) eActivation
)
{
    SchM_Enter_ICU_EXCLUSIVE_AREA_37();

    switch (eActivation)
    {
    case EMIOS_TRIG_EDGE_RISING:
    {
        eMIOS_UC_Cn_SetEDSEL(u8Module, u8Channel, (uint8)0U);
        eMIOS_UC_Cn_SetEDPOL(u8Module, u8Channel, (uint8)1U);
        break;
    }
    case EMIOS_TRIG_EDGE_FALLING:
    {
        eMIOS_UC_Cn_SetEDSEL(u8Module, u8Channel, (uint8)0U);
        eMIOS_UC_Cn_SetEDPOL(u8Module, u8Channel, (uint8)0U);
        break;
    }
    case EMIOS_TRIG_EDGE_BOTH:
    {
        eMIOS_UC_Cn_SetEDSEL(u8Module, u8Channel, (uint8)1U);
        eMIOS_UC_Cn_SetEDPOL(u8Module, u8Channel, (uint8)0U);
        break;
    }
    case EMIOS_TRIG_EDGE_OPPOSITE:
    {
        uint8 edpol = eMIOS_UC_Cn_GetEDPOL(u8Module, u8Channel);
        eMIOS_UC_Cn_SetEDPOL(u8Module, u8Channel, (edpol == 0U) ? 1U : 0U);
        break;
    }
    default:
        /*nothing*/
        break;
    }

    SchM_Exit_ICU_EXCLUSIVE_AREA_37();
}

FUNC(void, ICU_CODE) eMios_Channel_EnableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) u32ConfigData = (uint32)0U;

    SchM_Enter_ICU_EXCLUSIVE_AREA_38();

    /* GPIO mode used reset eMIOS module */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);

    /* Enable SAIC mode */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_SAIC);

    /* Clear interrupt flag */
    eMIOS_UC_Sn_ClearFLAG(u8Module, u8Channel);

    /* Enable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)TRUE);

    /* Set Channel Config */
    u32ConfigData = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_MEASMODE);
    u32ConfigData |= (uint32)EMIOS_MODE_SIGNAL_EDGE_DETECT;
    eMios_SetChConfig(u8Module, u8Channel, \
        (uint32)EMIOS_CONFIG_DATA_MEASMODE, \
        (uint32)u32ConfigData);

    SchM_Exit_ICU_EXCLUSIVE_AREA_38();
}

FUNC(void, ICU_CODE) eMios_Channel_DisableEdgeDetection \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    SchM_Enter_ICU_EXCLUSIVE_AREA_39();

    /* Disable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)FALSE);

    /* Set to GPIO mode */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);

    /* Clear meas mode */
    (void)eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_MEASMODE);
    (void)EMIOS_MODE_SIGNAL_EDGE_DETECT;
    eMios_SetChConfig(u8Module, u8Channel, \
        (uint32)EMIOS_CONFIG_DATA_MEASMODE, \
        (uint32)0);

    SchM_Exit_ICU_EXCLUSIVE_AREA_39();
}

#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) eMios_Channel_StartTimestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bDmaSupport \
)
{
    VAR(uint32, AUTOMATIC) u32ConfigData = (uint32)0U;

    /* Reset aBufferPtr */
    eMios_SetTtBuffer(u8Module, u8Channel, (Icu_ValueType)0);

    SchM_Enter_ICU_EXCLUSIVE_AREA_40();

    /* Reset opmode */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);

    /* Clear INT flag */
    eMIOS_UC_Sn_ClearFLAG(u8Module, u8Channel);
    /* Clear overrun bit */
    eMIOS_UC_Sn_ClearOVR(u8Module, u8Channel);
    /* Clear overflow bit */
    eMIOS_UC_Sn_ClearOVFL(u8Module, u8Channel);
    /* Enable SAIC mode */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_SAIC);

    u32ConfigData = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_MEASMODE);
    if (bDmaSupport == (boolean)TRUE)
    {
        eMIOS_LLD_UC_SetDMARequestEn(u8Module, u8Channel);

        u32ConfigData |= (uint32)EMIOS_MODE_TIMESTAMP_WITH_DMA;
        eMios_SetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);
    }
    else
    {
        u32ConfigData |= (uint32)EMIOS_MODETIMESTAMP_WITHOUT_DMA;
        eMios_SetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);
    }

    /* Enable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)TRUE);

#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Enable Interrupt for masterbus*/
    eMios_EnableMasterBusInterrupt(u8Module, u8Channel);
#endif

    SchM_Exit_ICU_EXCLUSIVE_AREA_40();
}

FUNC(void, ICU_CODE) eMios_Channel_StopTimestamp \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) u32ConfigData = (uint32)0U;

    SchM_Enter_ICU_EXCLUSIVE_AREA_41();

    /* Disable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)FALSE);
    /* Reset opmode */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);

    u32ConfigData = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_MEASMODE);
    u32ConfigData &= ~(EMIOS_MODE_TIMESTAMP_WITH_DMA|EMIOS_MODETIMESTAMP_WITHOUT_DMA);
    eMios_SetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Disable Interrupt for masterbus*/
    eMios_DisableMasterBusInterrupt(u8Module, u8Channel);
#endif

    SchM_Exit_ICU_EXCLUSIVE_AREA_41();
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_Timestamp \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(uint8, AUTOMATIC) u8CapturedWords = (uint8)1U;
    VAR(uint32, AUTOMATIC) u32CapturedVaule = (uint32)0U;

    u32CapturedVaule = eMIOS_UC_An_GetValue(u8Module, u8Channel);
    /* Reset aBufferPtr */
    eMios_SetTtBuffer(u8Module, u8Channel, u32CapturedVaule);

    eMios_Wrapper_Channel_Timestamp(u8Module, u8Channel, \
        u8CapturedWords, &u32CapturedVaule, bOverflow);
}
#endif /* ICU_TIMESTAMP_API */

FUNC(uint32, ICU_CODE) eMios_Channel_GetStartAddress \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    return (eMIOS_UC_An_GetAddress(u8Module, u8Channel));
}

#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC(void, ICU_CODE) eMios_Channel_ResetEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint8, AUTOMATIC) u8PrevMode = eMIOS_UC_Cn_GetMode(u8Module, u8Channel);

    SchM_Enter_ICU_EXCLUSIVE_AREA_42();

    /* Disable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)FALSE);
    /* Clear opmode */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);
    /* Reset counter */
    eMIOS_UC_CNTn_SetValue(u8Module, u8Channel, (uint32)0U);

    eMIOS_UC_An_SetValue(u8Module, u8Channel, (uint32)0x00FFFFFFU);
    /* Clear INT flag */
    eMIOS_UC_Sn_ClearFLAG(u8Module, u8Channel);
    /* Clear overrun bit */
    eMIOS_UC_Sn_ClearOVR(u8Module, u8Channel);
    /* Clear overflow bit */
    eMIOS_UC_Sn_ClearOVFL(u8Module, u8Channel);
    if(u8PrevMode < (uint8)255U)
    {
        eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)u8PrevMode);
    }
    /* Clear edge value */
    eMios_SetEdgeValue(u8Module, u8Channel, (uint32)0U);
    /* Enable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)TRUE);

    SchM_Exit_ICU_EXCLUSIVE_AREA_42();
}

FUNC(void, ICU_CODE) eMios_Channel_EnableEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) u32CurrentEdgeValue = (uint32)0U;
    VAR(uint32, AUTOMATIC) u32ConfigData = (uint32)0U;

    SchM_Enter_ICU_EXCLUSIVE_AREA_43();

    /* Clear opmode */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);

    eMIOS_UC_An_SetValue(u8Module, u8Channel, (uint32)0x00FFFFFFU);

    u32CurrentEdgeValue = eMios_GetEdgeValue(u8Module, u8Channel);
    /* Set counter */
    eMIOS_UC_CNTn_SetValue(u8Module, u8Channel, (uint32)u32CurrentEdgeValue);

    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_MCB_EXT);
    /* Clear INT flag */
    eMIOS_UC_Sn_ClearFLAG(u8Module, u8Channel);
    /* Clear overrun bit */
    eMIOS_UC_Sn_ClearOVR(u8Module, u8Channel);
    /* Clear overflow bit */
    eMIOS_UC_Sn_ClearOVFL(u8Module, u8Channel);
    /* Enable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)TRUE);

    u32ConfigData = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_MEASMODE);
    u32ConfigData |= EMIOS_MODE_EDGE_COUNTER;
    eMios_SetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

    SchM_Exit_ICU_EXCLUSIVE_AREA_43();
}

FUNC(void, ICU_CODE) eMios_Channel_DisableEdgeCount \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) u32CurrentEdgeValue = (uint32)0U;
    VAR(uint32, AUTOMATIC) u32ConfigData = (uint32)0U;

    SchM_Enter_ICU_EXCLUSIVE_AREA_44();

    /* Disable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)FALSE);
    /* Clear INT flag */
    eMIOS_UC_Sn_ClearFLAG(u8Module, u8Channel);
    /* Clear overrun bit */
    eMIOS_UC_Sn_ClearOVR(u8Module, u8Channel);
    /* Clear overflow bit */
    eMIOS_UC_Sn_ClearOVFL(u8Module, u8Channel);
    /* Get counter */
    u32CurrentEdgeValue = eMIOS_UC_CNTn_GetValue(u8Module, u8Channel);

    eMios_SetEdgeValue(u8Module, u8Channel, u32CurrentEdgeValue);
    /* Clear meas mode */
    u32ConfigData = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_MEASMODE);
    u32ConfigData &= ~EMIOS_MODE_EDGE_COUNTER;
    eMios_SetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

    SchM_Exit_ICU_EXCLUSIVE_AREA_44();
}

FUNC (uint32, ICU_CODE) eMios_Channel_GetEdgeNumbers \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) u32Mode;
    VAR(uint32, AUTOMATIC) u32CurrentEdgeValue = (uint32)0U;

    u32Mode = eMIOS_UC_Cn_GetMode(u8Module, u8Channel);
    if (u32Mode == (uint32)EMIOS_UC_MODE_GPIO_INPUT)
    {
        u32CurrentEdgeValue = eMios_GetEdgeValue(u8Module, u8Channel);
    }
    else
    {
        u32CurrentEdgeValue = eMIOS_UC_CNTn_GetValue(u8Module, u8Channel);
    }

    return u32CurrentEdgeValue;
}
#endif /* ICU_EDGE_COUNT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC(void, ICU_CODE) eMios_Ch_StartSignalMeasurement \
( \
    VAR(uint8,                    AUTOMATIC) u8Module, \
    VAR(uint8,                    AUTOMATIC) u8Channel, \
    VAR(eMIOS_EdgeTrigModeType,   AUTOMATIC) eActivation, \
    VAR(uint16,                   AUTOMATIC) nMeasProperty, \
    VAR(boolean,                  AUTOMATIC) bDmaSupport, \
    VAR(boolean,                  AUTOMATIC) bWithoutInterrupt \
)
{
    VAR(ICU_eMIOS_Types, AUTOMATIC) eMiosOperationMode;
    VAR(eMIOS_OpSubMode, AUTOMATIC) eMiosSubMode;
    VAR(uint32, AUTOMATIC) u32ConfigData = (uint32)0U;
    VAR(uint32, AUTOMATIC) u32Desired;
    VAR(uint32, AUTOMATIC) u32StartTime;
    VAR(uint32, AUTOMATIC) u32EndTime;

    /* Reset capture and timestart */
    eMios_SetPulseWidth(u8Module, u8Channel, (uint32)0U);
    eMios_SetTimeStart(u8Module, u8Channel, (uint32)0U);
    /* Disable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)FALSE);
    /* Clear opmode */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);
    /* Set edge trigger mode */
    eMios_Channel_SetActivationCondition(u8Module, u8Channel, eActivation);

    /* Check dma mode */
    if((boolean)TRUE == bDmaSupport)
    {
        eMIOS_UC_Cn_SetDMA(u8Module, u8Channel, (uint8)1U);
    }

    eMiosOperationMode = (ICU_eMIOS_Types)eMios_GetChConfig(u8Module, u8Channel,\
        (uint32)EMIOS_CONFIG_DATA_OPMODE);

    eMiosSubMode = (eMIOS_OpSubMode)eMios_GetChConfig(u8Module, u8Channel, \
        (uint32)EMIOS_CONFIG_DATA_SUBMODE);

    SchM_Enter_ICU_EXCLUSIVE_AREA_45();

    switch (eMiosOperationMode)
    {
    case EMIOS_IC_IPM:
    {
        /* Set IPM mode */
        eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_IPM);
        break;
    }
    case EMIOS_IC_IPWM:
    {
        /* Set IPWM mode */
        eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_IPWM);
        break;
    }
    case EMIOS_IC_PEA:
    {
        eMIOS_MC_ParamType eMIOS_Mc1_CntChnConfig = \
        { \
            .mode                   = EMIOS_UC_MODE_MCB_UP_COUNTER_INT_CLK, \
            .period                 = 0xFFFFFFU, \
            .divid                  = 0U, \
            .filter                 = EMIOS_INPUT_FILTER_BYPASS, \
            .trigger                = EMIOS_TRIG_EDGE_FALLING \
        };
        if((uint8)EMIOS_CNTBUS_A_CHANNEL_23 != u8Channel)
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSA_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*B_bus*/
        else if(u8Channel<=EMIOS_CNTBUS_B_CHANNEL_7)
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSB_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*C_bus*/
        else if((u8Channel>=EMIOS_CNTBUS_C_CHANNEL_8)&&(u8Channel<=EMIOS_CNTBUS_C_CHANNEL_15))
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSC_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*D_bus*/
        else if((u8Channel>=EMIOS_CNTBUS_D_CHANNEL_16)&&(u8Channel<=EMIOS_CNTBUS_D_CHANNEL_23))
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSD_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*E_bus*/
        else if((u8Channel>=EMIOS_CNTBUS_E_CHANNEL_24)&&(u8Channel<=EMIOS_CNTBUS_E_CHANNEL_31))
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSE_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        else
        {
            /*do_Nothing*/
        }
        u32Desired = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_DESIRED);

        if (eMiosSubMode == EMIOS_SUBMODE_SINGLE)
        {
            eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_PEA_SINGLE);
        }
        else
        {
            eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_PEA_CONTIN);
        }

        eMIOS_UC_An_SetValue(u8Module, u8Channel, u32Desired);
        break;
    }
    case EMIOS_IC_QDEC:
    {
        u32Desired = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_DESIRED);

        if (eMiosSubMode == EMIOS_SUBMODE_SINGLE)
        {
            eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_FOR_COUNT_DIRECT_QDEC);
        }
        else
        {
            eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_QDEC_A_B_FOR_PHASE);
        }

        eMIOS_UC_An_SetValue(u8Module, u8Channel, u32Desired);
        break;
    }
    case EMIOS_IC_PEC:
    {
        eMIOS_MC_ParamType eMIOS_Mc1_CntChnConfig = \
        { \
            .mode                   = EMIOS_UC_MODE_MCB_UP_COUNTER_INT_CLK, \
            .period                 = 0xFFFFFFU, \
            .divid                  = 0U, \
            .filter                 = EMIOS_INPUT_FILTER_BYPASS, \
            .trigger                = EMIOS_TRIG_EDGE_FALLING \
        };
        if((uint8)EMIOS_CNTBUS_A_CHANNEL_23 != u8Channel)
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSA_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*B_bus*/
        else if(u8Channel<=EMIOS_CNTBUS_B_CHANNEL_7)
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSB_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*C_bus*/
        else if((u8Channel>=EMIOS_CNTBUS_C_CHANNEL_8)&&(u8Channel<=EMIOS_CNTBUS_C_CHANNEL_15))
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSC_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*D_bus*/
        else if((u8Channel>=EMIOS_CNTBUS_D_CHANNEL_16)&&(u8Channel<=EMIOS_CNTBUS_D_CHANNEL_23))
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSD_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*E_bus*/
        else if((u8Channel>=EMIOS_CNTBUS_E_CHANNEL_24)&&(u8Channel<=EMIOS_CNTBUS_E_CHANNEL_31))
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSE_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        else
        {
            /*do_Nothing*/
        }
        u32StartTime = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_STARTTIME);
        u32EndTime = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_ENDTIME);

        if (eMiosSubMode == EMIOS_SUBMODE_SINGLE)
        {
            eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_PEC_SINGLE);
        }
        else
        {
            eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_PEC_CONTIN);
        }

        eMIOS_UC_Bn_SetValue(u8Module, u8Channel, u32EndTime);
        eMIOS_UC_An_SetValue(u8Module, u8Channel, u32StartTime);
        break;
    }
    case EMIOS_IC_WPTA:
    {
        eMIOS_MC_ParamType eMIOS_Mc1_CntChnConfig = \
        { \
            .mode                   = EMIOS_UC_MODE_MCB_UP_COUNTER_INT_CLK, \
            .period                 = 0xFFFFFFU, \
            .divid                  = 0U, \
            .filter                 = EMIOS_INPUT_FILTER_BYPASS, \
            .trigger                = EMIOS_TRIG_EDGE_FALLING \
        };
        if((uint8)EMIOS_CNTBUS_A_CHANNEL_23 != u8Channel)
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSA_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*B_bus*/
        else if(u8Channel<=EMIOS_CNTBUS_B_CHANNEL_7)
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSB_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*C_bus*/
        else if((u8Channel>=EMIOS_CNTBUS_C_CHANNEL_8)&&(u8Channel<=EMIOS_CNTBUS_C_CHANNEL_15))
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSC_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*D_bus*/
        else if((u8Channel>=EMIOS_CNTBUS_D_CHANNEL_16)&&(u8Channel<=EMIOS_CNTBUS_D_CHANNEL_23))
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSD_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        /*E_bus*/
        else if((u8Channel>=EMIOS_CNTBUS_E_CHANNEL_24)&&(u8Channel<=EMIOS_CNTBUS_E_CHANNEL_31))
        {
            (void)eMIOS_LLD_MC_Init(u8Module, (uint8_t)EMIOS_CNT_BUSE_DRIVEN_CHANNEL, &eMIOS_Mc1_CntChnConfig);
        }
        else
        {
            /*do_Nothing*/
        }
        u32StartTime = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_STARTTIME);
        u32EndTime = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_ENDTIME);

        eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_WPTA);
        eMIOS_UC_Bn_SetValue(u8Module, u8Channel, u32EndTime);
        eMIOS_UC_An_SetValue(u8Module, u8Channel, u32StartTime);
        break;
    }
    default:
    {
        /* Set SAIC mode */
        eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8)EMIOS_UC_MODE_SAIC);
        break;
    }
    }

    /* Clear INT flag */
    eMIOS_UC_Sn_ClearFLAG(u8Module, u8Channel);
    /* Clear overrun bit */
    eMIOS_UC_Sn_ClearOVR(u8Module, u8Channel);
    /* Clear overflow bit */
    eMIOS_UC_Sn_ClearOVFL(u8Module, u8Channel);

    /* Clear the counter for signal measurement */
    eMios_SetIntCounter(u8Module, u8Channel, (uint8)0U);

    if ((boolean)TRUE != bWithoutInterrupt)
    {
        /* Enable Interrupt */
        eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)TRUE);
    }

#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Enable Interrupt for masterbus*/
    eMios_EnableMasterBusInterrupt(u8Module, u8Channel);
#endif

    /* Set Channel meas mode */
    u32ConfigData = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_MEASMODE);
    u32ConfigData |= EMIOS_MODE_SIGNAL_MEASUREMENT;
    eMios_SetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

    eMios_SetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_PROPERTY, \
            (uint32)nMeasProperty);

    SchM_Exit_ICU_EXCLUSIVE_AREA_45();
}

FUNC(void, ICU_CODE) eMios_Ch_StopSignalMeasurement \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) u32ConfigData = (uint32)0U;

    SchM_Enter_ICU_EXCLUSIVE_AREA_46();

    /* Disable Interrupt */
    eMIOS_UC_Cn_SetFEN(u8Module, u8Channel, (boolean)FALSE);
    /* Reset to GPIO mode */
    eMIOS_UC_Cn_SetMode(u8Module, u8Channel, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);
    /* GPIO mode, No FLAG is generated */
    eMIOS_UC_Cn_SetEDSEL(u8Module, u8Channel, (uint8)1U);

    /* Clear Channel meas mode */
    u32ConfigData = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_MEASMODE);
    u32ConfigData &= ~EMIOS_MODE_SIGNAL_MEASUREMENT;
    eMios_SetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_MEASMODE, \
            (uint32)u32ConfigData);

    /* Clear Channel Property */
    eMios_SetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_PROPERTY, \
            (uint32)0);

#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Disable Interrupt for masterbus*/
    eMios_DisableMasterBusInterrupt(u8Module, u8Channel);
#endif

    SchM_Exit_ICU_EXCLUSIVE_AREA_46();
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

FUNC (boolean, ICU_CODE) eMios_Channel_GetInputState \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(boolean, AUTOMATIC) bRetrunValue = (boolean)FALSE;
    VAR(boolean, AUTOMATIC) bValueCCRFEN = (boolean)FALSE;
    VAR(boolean, AUTOMATIC) bValueCSRFLAG = (boolean)FALSE;

    bValueCCRFEN = eMIOS_UC_Cn_GetFEN(u8Module, u8Channel);
    bValueCSRFLAG = eMIOS_UC_Sn_GetFLAG(u8Module, u8Channel);

    if ((bValueCCRFEN == (boolean)FALSE) && (bValueCSRFLAG == (boolean)TRUE))
    {
        /* Clear FLAG */
        eMIOS_UC_Sn_ClearFLAG(u8Module, u8Channel);

        bRetrunValue = (boolean)TRUE;
    }

    return bRetrunValue;
}

FUNC (boolean, ICU_CODE) eMios_Channel_GetOverflow \
( \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(boolean, AUTOMATIC) bRetrunValue = (boolean)FALSE;

    /* Read OVFL status */
    bRetrunValue = eMIOS_UC_Sn_GetOVFL(u8Module, u8Channel);

    /* Clear OVFL status */
    eMIOS_UC_Sn_ClearOVFL(u8Module, u8Channel);

    return bRetrunValue;
}

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_SetPrescaler \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32ChannelPrescaler \
)
{
    SchM_Enter_ICU_EXCLUSIVE_AREA_47();

    /* Disabled Global Prescaler (no clock) and prescaler counter is cleared */
    eMIOS_MCR_SetGPREN(u8Module, (boolean)FALSE);

    /* Disabled Channel Prescaler (no clock) */
    eMIOS_UC_Cn_SetUCPREN(u8Module, u8Channel, (boolean)FALSE);

    /* Set Channel div1 */
    eMIOS_UC_Cn_SetUCPRE(u8Module, u8Channel, (uint8)0U);
    /* Set Channel div */
    eMIOS_UC_Cn_SetUCPRE(u8Module, u8Channel, (uint8)u32ChannelPrescaler);

    /* Enabled Channel Prescaler */
    eMIOS_UC_Cn_SetUCPREN(u8Module, u8Channel, (boolean)TRUE);

    /* Enable Gloabl Prescaler */
    eMIOS_MCR_SetGPREN(u8Module, (boolean)TRUE);

    SchM_Exit_ICU_EXCLUSIVE_AREA_47();
}

FUNC (void, ICU_CODE) eMios_Channel_SetClockMode \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel, \
    VAR(uint32, AUTOMATIC) u32Prescaler \
)
{
    VAR(uint8, AUTOMATIC) u8MasterBusChannel;
    VAR(uint32, AUTOMATIC) u32ChBus = eMios_GetChConfig(u8Module, u8Channel, \
        (uint32)EMIOS_CONFIG_DATA_BUSCHANNEL);

    if (u32ChBus == (uint32)EMIOS_COUNTER_BUS_INTERNAL)
    {
        eMios_Channel_SetPrescaler(u8Module, u8Channel, u32Prescaler);
    }
    else
    {
        u8MasterBusChannel = eMios_GetMasterBusChannel( \
            (uint8)u32ChBus, \
            u8Module, \
            u8Channel);
        eMios_Channel_SetPrescaler(u8Module, u8MasterBusChannel, u32Prescaler);
    }
}
#endif /* ICU_DUAL_CLOCK_MODE_API */

FUNC(boolean, ICU_CODE) eMios_Channel_GetInputLevel \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(boolean, AUTOMATIC) bRetrunValue = (boolean)FALSE;

    bRetrunValue = (eMIOS_UC_Sn_GetUCIN(u8Module, u8Channel) != 0U) ? (boolean)TRUE : (boolean)FALSE;

    return bRetrunValue;
}

FUNC(uint32, ICU_CODE) eMios_Channel_GetCaptureRegisterValue \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(uint32, AUTOMATIC) u32RetrunValue = (uint32)0U;

    u32RetrunValue = eMIOS_UC_An_GetValue(u8Module, u8Channel);

    return u32RetrunValue;
}

LOCAL_INLINE FUNC (uint32, ICU_CODE) eMios_Channel_GetCaptureRegister \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(uint32,     AUTOMATIC) u32BusChannelClockMode = (uint32)0U;
    VAR(uint32,     AUTOMATIC) u32Counter = (uint32)0U;

    u32BusChannelClockMode = eMIOS_UC_Cn_GetMode(u8Module, u8Channel);

    /* eMIOS Counter nHwChannel Channel is in Modulous counter buffer or Modulous counter mode */
    if (((uint32)EMIOS_UC_MODE_MCB_INT == u32BusChannelClockMode) || \
        ((uint32)EMIOS_UC_MODE_MC == u32BusChannelClockMode))
    {
        u32Counter = (uint32)eMIOS_UC_An_GetValue(u8Module, u8Channel);
    }
    else
    {
        u32Counter = (uint32)eMIOS_UC_Bn_GetValue(u8Module, u8Channel);
    }

    return u32Counter;
}

LOCAL_INLINE FUNC (uint32, ICU_CODE) eMios_Channel_ReadBusCounter \
( \
    VAR(uint8,                      AUTOMATIC) u8Module, \
    VAR(uint8,                      AUTOMATIC) u8Channel, \
    VAR(eMIOS_UC_CounterBusSelType, AUTOMATIC) eBusType
)
{
    VAR(uint32,     AUTOMATIC) u32Counter = (uint32)0U;

    switch (eBusType)
    {
    case EMIOS_COUNTER_BUS_A:
    {
        u32Counter = eMios_Channel_GetCaptureRegister((uint8)eMIOS_0, EMIOS_CNTBUS_A_CHANNEL_23);
        break;
    }
    case EMIOS_COUNTER_BUS_BCDE:
    {
        /* B bus */
        if      (u8Channel <= EMIOS_CNTBUS_B_CHANNEL_7)
        {
            if(u8Module == (uint8)eMIOS_0)
            {
                u32Counter = eMios_Channel_GetCaptureRegister((uint8)eMIOS_0, EMIOS_CNTBUS_B_CHANNEL_0);
            }
            else
            {
#if defined(RESOURCE_SUPPORT_EMIOS1)
                u32Counter = eMios_Channel_GetCaptureRegister((uint8)eMIOS_1, EMIOS_CNTBUS_B_CHANNEL_0);
#endif
            }
        }
        /* C bus */
        else if (u8Channel <= EMIOS_CNTBUS_C_CHANNEL_15)
        {
            if(u8Module == (uint8)eMIOS_0)
            {
                u32Counter = eMios_Channel_GetCaptureRegister((uint8)eMIOS_0, EMIOS_CNTBUS_C_CHANNEL_8);
            }
            else
            {
#if defined(RESOURCE_SUPPORT_EMIOS1)
                u32Counter = eMios_Channel_GetCaptureRegister((uint8)eMIOS_1, EMIOS_CNTBUS_C_CHANNEL_8);
#endif
            }
        }
        /* D bus */
        else if (u8Channel <= EMIOS_CNTBUS_D_CHANNEL_23)
        {
            if(u8Module == (uint8)eMIOS_0)
            {
                u32Counter = eMios_Channel_GetCaptureRegister((uint8)eMIOS_0, EMIOS_CNTBUS_D_CHANNEL_16);
            }
            else
            {
#if defined(RESOURCE_SUPPORT_EMIOS1)
                u32Counter = eMios_Channel_GetCaptureRegister((uint8)eMIOS_1, EMIOS_CNTBUS_D_CHANNEL_16);
#endif
            }
        }
        /* E bus */
        else if (u8Channel <= EMIOS_CNTBUS_E_CHANNEL_31)
        {
            if(u8Module == (uint8)eMIOS_0)
            {
                u32Counter = eMios_Channel_GetCaptureRegister((uint8)eMIOS_0, EMIOS_CNTBUS_E_CHANNEL_24);
            }
            else
            {
#if defined(RESOURCE_SUPPORT_EMIOS1)
                u32Counter = eMios_Channel_GetCaptureRegister((uint8)eMIOS_1, EMIOS_CNTBUS_E_CHANNEL_24);
#endif
            }
        }
        else
        {
            /* do nothing */
        }
        break;
    }
    case EMIOS_COUNTER_BUS_INTERNAL:
    {
        u32Counter = EMIOS_COUNTER_MAX;
        break;
    }
    default:
        /* Error bus type, do nothing */
        break;
    }

    return u32Counter;
}

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_IPWMSignalMeasurement \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ValueType, AUTOMATIC) nActivePulseWidth;
    VAR(Icu_ValueType, AUTOMATIC) nPeriod;
    VAR(Icu_ValueType, AUTOMATIC) nBusCounter;
    VAR(Icu_ValueType, AUTOMATIC) nChannelTempA;
    VAR(Icu_ValueType, AUTOMATIC) nChannelTempB;
    VAR(Icu_ValueType, AUTOMATIC) nTimeStart;

    VAR(uint32, AUTOMATIC) u32SignalMeasurementProperty = \
        eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_PROPERTY);

    /* Read captured values */
    nChannelTempA = eMIOS_UC_An_GetValue(u8Module, u8Channel);
    nChannelTempB = eMIOS_UC_Bn_GetValue(u8Module, u8Channel);

    if ((u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_LOW_TIME) || \
        (u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_HIGH_TIME))
    {
        if (nChannelTempA > nChannelTempB)
        {
            nActivePulseWidth = (Icu_ValueType)(nChannelTempA - nChannelTempB);
        }
        /* If Counter overflow */
        else
        {
            uint32 nChBus = eMios_GetChConfig(u8Module, u8Channel, \
                (uint32)EMIOS_CONFIG_DATA_BUSCHANNEL);

            nBusCounter = eMios_Channel_ReadBusCounter(u8Module, u8Channel, (eMIOS_UC_CounterBusSelType)nChBus);
            nActivePulseWidth = \
                (Icu_ValueType)(nChannelTempA + ((uint32)nBusCounter - nChannelTempB) + (uint32)1U);
        }

        eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
            u8Channel, \
            nActivePulseWidth, \
            (Icu_ValueType)0, \
            bOverflow);
    }
    /* cycle mode */
    else
    {
        if (eMios_GetIntCounter(u8Module, u8Channel) == (uint32)0U)
        {
            eMios_SetIntCounter(u8Module, u8Channel, (uint8)1U);
            eMios_Wrapper_Channel_ReportWakeupAndOverflow( \
                u8Module, u8Channel, bOverflow);
        }
        else
        {
            nTimeStart = eMios_GetTimeStart(u8Module, u8Channel);
            if (nChannelTempB > nTimeStart)
            {
                nPeriod = nChannelTempB - nTimeStart;
            }
            /* Counter overflow */
            else
            {
                uint32 nChBus = eMios_GetChConfig(u8Module, u8Channel, \
                    (uint32)EMIOS_CONFIG_DATA_BUSCHANNEL);
                nBusCounter = eMios_Channel_ReadBusCounter(u8Module, u8Channel, (eMIOS_UC_CounterBusSelType)nChBus);
                nPeriod = (uint32)(((nChannelTempB + nBusCounter) - nTimeStart) + (uint32)1U);
            }

            nActivePulseWidth = eMios_GetPulseWidth(u8Module, u8Channel);

            if (u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_DUTY_CYCLE)
            {
                eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
                    u8Channel, \
                    nActivePulseWidth, \
                    nPeriod, \
                    bOverflow);
            }
            else if (u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_PERIOD_TIME)
            {
                eMios_Wrapper_Channel_SignalMeasurement(u8Module,
                    u8Channel, \
                    (Icu_ValueType)0, \
                    nPeriod, \
                    bOverflow);
            }
            else
            {
                /* do nothing */
            }
        }
    }

    if (nChannelTempA > nChannelTempB)
    {
        eMios_SetPulseWidth(u8Module, u8Channel, (uint32)(nChannelTempA - nChannelTempB));
    }
    /* Counter overflow */
    else
    {
        uint32 nChBus = eMios_GetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_BUSCHANNEL);
        nBusCounter = eMios_Channel_ReadBusCounter(u8Module, u8Channel, (eMIOS_UC_CounterBusSelType)nChBus);
        eMios_SetPulseWidth(u8Module, u8Channel, \
            (uint32)(nChannelTempA + ((uint32)(nBusCounter - nChannelTempB)) + (uint32)1U));
    }

    eMios_SetTimeStart(u8Module, u8Channel, nChannelTempB);
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_IPMSignalMeasurement \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ValueType, AUTOMATIC) nPeriod;
    VAR(Icu_ValueType, AUTOMATIC) nBusCounter;
    VAR(Icu_ValueType, AUTOMATIC) nChannelTempA;
    VAR(Icu_ValueType, AUTOMATIC) nChannelTempB;
    VAR(uint32, AUTOMATIC) u32SignalMeasurementProperty = \
        eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_PROPERTY);

    if (u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_PERIOD_TIME)
    {
        /* Read captured values */
        nChannelTempA = eMIOS_UC_An_GetValue(u8Module, u8Channel);
        nChannelTempB = eMIOS_UC_Bn_GetValue(u8Module, u8Channel);

        if (nChannelTempA > nChannelTempB)
        {
            nPeriod = (Icu_ValueType)(nChannelTempA - nChannelTempB);
        }
        /* If Counter overflow */
        else
        {
            uint32 nChBus = eMios_GetChConfig(u8Module, u8Channel, \
                (uint32)EMIOS_CONFIG_DATA_BUSCHANNEL);

            nBusCounter = eMios_Channel_ReadBusCounter(u8Module, u8Channel, (eMIOS_UC_CounterBusSelType)nChBus);
            nPeriod = \
                (Icu_ValueType)(nChannelTempA + ((uint32)nBusCounter - nChannelTempB) + (uint32)1U);
        }

        eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
            u8Channel, \
            (Icu_ValueType)0, \
            (Icu_ValueType)nPeriod, \
            bOverflow);
    }
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_SAICSignalMeasurement \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ValueType, AUTOMATIC) nActivePulseWidth;
    VAR(Icu_ValueType, AUTOMATIC) nPeriod;
    VAR(Icu_ValueType, AUTOMATIC) nBusCounter;
    VAR(Icu_ValueType, AUTOMATIC) nChannelTempA;
    VAR(Icu_ValueType, AUTOMATIC) nPreviousValue;
    VAR(Icu_ValueType, AUTOMATIC) nPulseWidth;
    VAR(uint32, AUTOMATIC) u32SignalMeasurementProperty = \
        eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_PROPERTY);

    /* Read captured values */
    nChannelTempA = eMIOS_UC_An_GetValue(u8Module, u8Channel);

    if (eMios_GetIntCounter(u8Module, u8Channel) == (uint32)0U)
    {
        eMios_SetIntCounter(u8Module, u8Channel, (uint8)1U);
        eMios_SetTimeStart(u8Module, u8Channel, nChannelTempA);
        eMios_Channel_SetActivationCondition(u8Module, u8Channel, EMIOS_TRIG_EDGE_BOTH);
    }
    else
    {
        nPreviousValue = eMios_GetTimeStart(u8Module, u8Channel);
        /* Store for next time */
        eMios_SetTimeStart(u8Module, u8Channel, nChannelTempA);
        if(nPreviousValue > nChannelTempA)
        {
            uint32 nChBus = eMios_GetChConfig(u8Module, u8Channel, \
                (uint32)EMIOS_CONFIG_DATA_BUSCHANNEL);
            nBusCounter = eMios_Channel_ReadBusCounter(u8Module, u8Channel, (eMIOS_UC_CounterBusSelType)nChBus);
            nPulseWidth = (nBusCounter - nPreviousValue) + nChannelTempA + (uint32)1U;
        }
        else
        {
            nPulseWidth = nChannelTempA - nPreviousValue;
        }

        if ((u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_LOW_TIME) || \
            (u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_HIGH_TIME))
        {
            nActivePulseWidth = nPulseWidth;
            eMios_SetIntCounter(u8Module, u8Channel, (uint8)0U);
            eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
                u8Channel, \
                (Icu_ValueType)nActivePulseWidth, \
                (Icu_ValueType)0, \
                bOverflow);
        }
        /* cycle */
        else
        {
            if (eMios_GetIntCounter(u8Module, u8Channel) == (uint32)1U)
            {
                eMios_SetPulseWidth(u8Module, u8Channel, nPulseWidth);
                eMios_SetIntCounter(u8Module, u8Channel, (uint8)2U);
                eMios_Wrapper_Channel_ReportWakeupAndOverflow( \
                    u8Module, u8Channel, bOverflow);
            }
            /* counter = 2 */
            else
            {
                nActivePulseWidth = eMios_GetPulseWidth(u8Module, u8Channel);
                nPeriod = nActivePulseWidth + nPulseWidth;
                eMios_SetIntCounter(u8Module, u8Channel, (uint8)1);

                if (u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_DUTY_CYCLE)
                {
                    eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
                            u8Channel, \
                            (Icu_ValueType)nActivePulseWidth, \
                            (Icu_ValueType)nPeriod, \
                            bOverflow);
                }
                else if (u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_PERIOD_TIME)
                {
                    eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
                            u8Channel, \
                            (Icu_ValueType)0, \
                            (Icu_ValueType)nPeriod, \
                            bOverflow);
                }
                else
                {
                    /* do nothing */
                }
            }
        }

    }
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_PEASignalMeasurement \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ValueType, AUTOMATIC) nBusCounter;
    VAR(Icu_ValueType, AUTOMATIC) nChannelTempA;
    VAR(Icu_ValueType, AUTOMATIC) nChannelTempB;
    VAR(Icu_ValueType, AUTOMATIC) nActivePulseWidth;

    nChannelTempA = eMIOS_UC_An_GetValue(u8Module, u8Channel);
    nChannelTempB = eMIOS_UC_Bn_GetValue(u8Module, u8Channel);

    if(nChannelTempB > nChannelTempA)
    {
        uint32 nChBus = eMios_GetChConfig(u8Module, u8Channel, \
            (uint32)EMIOS_CONFIG_DATA_BUSCHANNEL);
        nBusCounter = eMios_Channel_ReadBusCounter(u8Module, u8Channel, (eMIOS_UC_CounterBusSelType)nChBus);
        nActivePulseWidth = (nBusCounter - nChannelTempB) + nChannelTempA + (uint32)1U;
    }
    else
    {
        nActivePulseWidth = nChannelTempA - nChannelTempB;
    }

    eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
                u8Channel, \
                (Icu_ValueType)nActivePulseWidth, \
                (Icu_ValueType)0, \
                bOverflow);
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_PECSignalMeasurement \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ValueType, AUTOMATIC) nPulseCounter;

    nPulseCounter = eMIOS_UC_CNTn_GetValue(u8Module, u8Channel);
    eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
                u8Channel, \
                (Icu_ValueType)nPulseCounter, \
                (Icu_ValueType)0U, \
                bOverflow);
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_WPTASignalMeasurement \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ValueType, AUTOMATIC) nActivePulseWidth;
    VAR(uint32, AUTOMATIC) u32SignalMeasurementProperty = \
            eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_PROPERTY);

    if ((u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_LOW_TIME) || \
        (u32SignalMeasurementProperty == EMIOS_MEAS_TYPE_HIGH_TIME))
    {
        nActivePulseWidth = eMIOS_UC_ALTAn_GetValue(u8Module, u8Channel);
        eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
                    u8Channel, \
                    (Icu_ValueType)nActivePulseWidth, \
                    (Icu_ValueType)0, \
                    bOverflow);
    }
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_QDECSignalMeasurement \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(Icu_ValueType, AUTOMATIC) nPulseCounter;
    (void)bOverflow;

    nPulseCounter = eMIOS_UC_CNTn_GetValue(u8Module, u8Channel);
    eMios_Wrapper_Channel_SignalMeasurement(u8Module, \
                u8Channel, \
                (Icu_ValueType)nPulseCounter, \
                (Icu_ValueType)0U, \
                (boolean)TRUE);
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_SignalMeasurement \
( \
    VAR(uint8,      AUTOMATIC) u8Module, \
    VAR(uint8,      AUTOMATIC) u8Channel, \
    VAR(boolean,    AUTOMATIC) bOverflow \
)
{
    VAR(ICU_eMIOS_Types, AUTOMATIC) eOperationMode = \
        (ICU_eMIOS_Types)eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_OPMODE);

    switch(eOperationMode)
    {
    case EMIOS_IC_IPWM:
    {
        eMios_Channel_IPWMSignalMeasurement(u8Module, u8Channel, bOverflow);
        break;
    }
    case EMIOS_IC_IPM:
    {
        eMios_Channel_IPMSignalMeasurement(u8Module, u8Channel, bOverflow);
        break;
    }
    case EMIOS_IC_SAIC:
    {
        eMios_Channel_SAICSignalMeasurement(u8Module, u8Channel, bOverflow);
        break;
    }
    case EMIOS_IC_PEA:
    {
        eMios_Channel_PEASignalMeasurement(u8Module, u8Channel, bOverflow);
        break;
    }
    case EMIOS_IC_PEC:
    {
        eMios_Channel_PECSignalMeasurement(u8Module, u8Channel, bOverflow);
        break;
    }
    case EMIOS_IC_WPTA:
    {
        eMios_Channel_WPTASignalMeasurement(u8Module, u8Channel, bOverflow);
        break;
    }
    case EMIOS_IC_QDEC:
    {
        eMios_Channel_QDECSignalMeasurement(u8Module, u8Channel, bOverflow);
        break;
    }
    default:
    {
        /* Error Emios mode, do nothing */
        break;
    }
    }

#if (ICU_MULTI_CORE == STD_ON)
    if (Icu_Autosar_Wrapper_MultiCoreIrqCompleteState(\
        ICU_ATS_eMios_Wapper_GetInstance(u8Module, u8Channel)) == (boolean)TRUE)
    {
        /* Clear INT flag */
        eMIOS_UC_Sn_ClearFLAG(u8Module, u8Channel);
    }
#endif
}

FUNC(void, ICU_CODE) eMios_Channel_GetPulseWidth \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    eMios_Channel_SignalMeasurement(u8Module, u8Channel, (boolean)FALSE);
}
#endif /* (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Group_ProcessCommonIrq \
( \
    VAR(uint8,                      AUTOMATIC) u8Module, \
    VAR(uint8,                      AUTOMATIC) u8Channel, \
    VAR(eMIOS_UC_CounterBusSelType, AUTOMATIC) sBusType \
)
{
    VAR(uint8, AUTOMATIC)  u8Counter = (uint8)0U;
    VAR(uint8, AUTOMATIC)  u8GroupChannel = (uint8)0U;
    VAR(uint32, AUTOMATIC) u32ChBus = (uint32)0U;
    VAR(uint32, AUTOMATIC) u32Inited = (uint32)0U;
    VAR(uint32, AUTOMATIC) nMeasMode = (uint32)0U;
    VAR(boolean, AUTOMATIC) bOverflowUsingMasterbus = (boolean)FALSE;

    for(u8Counter = (uint8)0U; u8Counter < (uint8)8U; u8Counter++)
    {
        bOverflowUsingMasterbus = (boolean)FALSE;
        u8GroupChannel = (uint8)(u8Channel + u8Counter);
        u32Inited = eMios_GetChConfig(u8Module, u8GroupChannel, EMIOS_CONFIG_DATA_INITED);
        u32ChBus = eMios_GetChConfig(u8Module, u8GroupChannel, EMIOS_CONFIG_DATA_BUSCHANNEL);

        if (u32Inited == (uint32)1U)
        {
            if (u32ChBus == (uint32)sBusType)
            {
                bOverflowUsingMasterbus = (boolean)TRUE;
            }
        }

        if (bOverflowUsingMasterbus == (boolean)TRUE)
        {
            nMeasMode = eMios_GetChConfig(u8Module, u8GroupChannel, EMIOS_CONFIG_DATA_MEASMODE);
            if ((EMIOS_MODE_SIGNAL_MEASUREMENT == nMeasMode) || \
                (EMIOS_MODE_TIMESTAMP_WITH_DMA == nMeasMode) || \
                (EMIOS_MODETIMESTAMP_WITHOUT_DMA == nMeasMode))
            {
                eMios_Wrapper_Channel_ReportWakeupAndOverflow( \
                    u8Module, u8GroupChannel, (boolean)TRUE);
            }
        }
    }
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_ProcessMasterBCDEBusIrq \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    if ((u8Channel % (uint8)8U) == (uint8)0U)
    {
        eMios_Group_ProcessCommonIrq(u8Module, u8Channel, EMIOS_COUNTER_BUS_BCDE);
    }
}

LOCAL_INLINE FUNC(void, ICU_CODE) eMios_Channel_ProcessMasterABusIrq \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    if ((u8Channel) == (uint8)EMIOS_CNTBUS_A_CHANNEL_23)
    {
        /* B Group */
        eMios_Group_ProcessCommonIrq(u8Module, EMIOS_CNTBUS_B_CHANNEL_0, EMIOS_COUNTER_BUS_A);

        /* C Group */
        eMios_Group_ProcessCommonIrq(u8Module, EMIOS_CNTBUS_C_CHANNEL_8, EMIOS_COUNTER_BUS_A);

        /* D Group */
        eMios_Group_ProcessCommonIrq(u8Module, EMIOS_CNTBUS_D_CHANNEL_16, EMIOS_COUNTER_BUS_A);

        /* E Group */
        eMios_Group_ProcessCommonIrq(u8Module, EMIOS_CNTBUS_E_CHANNEL_24, EMIOS_COUNTER_BUS_A);
    }
}

FUNC(void, ICU_CODE) eMios_Channel_ProcessCommonIrq \
( \
    VAR(uint8,  AUTOMATIC) u8Module, \
    VAR(uint8,  AUTOMATIC) u8Channel \
)
{
    VAR(uint8,  AUTOMATIC) u8OpMode = eMIOS_UC_Cn_GetMode(u8Module, u8Channel);
    VAR(boolean, AUTOMATIC) bOverflow = (boolean)FALSE;
    VAR(uint32, AUTOMATIC) u32ChConfig = (uint32)0U;

    if(((EMIOS_BALLS_CHANNEL_0  == u8Channel) || (EMIOS_BALLS_CHANNEL_8  == u8Channel) || \
        (EMIOS_BALLS_CHANNEL_16 == u8Channel) || (EMIOS_BALLS_CHANNEL_24 == u8Channel)) && \
        ((uint8)EMIOS_UC_MODE_MCB_INT == u8OpMode))
    {
        eMios_Channel_ProcessMasterBCDEBusIrq(u8Module, u8Channel);
    }
    else if (((uint8)eMIOS_0 == u8Module) && (EMIOS_BALLS_CHANNEL_23 == u8Channel) && \
        ((uint8)EMIOS_UC_MODE_MCB_INT == u8OpMode))
    {
        eMios_Channel_ProcessMasterABusIrq(u8Module, u8Channel);
    }
    else
    {
        bOverflow = eMIOS_UC_Sn_GetOVFL(u8Module, u8Channel);
        u32ChConfig = eMios_GetChConfig(u8Module, u8Channel, (uint32)EMIOS_CONFIG_DATA_MEASMODE);
        switch (u32ChConfig)
        {
        case EMIOS_MODE_SIGNAL_EDGE_DETECT:
        {
            eMios_Wrapper_Channel_ReportEvents(u8Module, u8Channel, bOverflow);
            break;
        }
        case EMIOS_MODE_SIGNAL_MEASUREMENT:
        {
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
            eMios_Channel_SignalMeasurement(u8Module, u8Channel, bOverflow);
#endif
            break;
        }
        case EMIOS_MODETIMESTAMP_WITHOUT_DMA:
        {
            eMios_Channel_Timestamp(u8Module, u8Channel, bOverflow);
            break;
        }
        case EMIOS_MODE_TIMESTAMP_WITH_DMA:
        {
            eMios_Wrapper_Channel_ReportWakeupAndOverflow(u8Module, u8Channel, bOverflow);
            break;
        }
        case EMIOS_MODE_EDGE_COUNTER:
        {
            eMios_Wrapper_Channel_ReportWakeupAndOverflow(u8Module, u8Channel, (boolean)TRUE);
            break;
        }
        default:
        {
            /* Error meas mode, do nothing */
            break;
        }
        }
    }
}

