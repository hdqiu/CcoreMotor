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
*   @file    Icu_AutoSAR_Wrapper.h
*   @version 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

#ifndef ICU_AUTOSAR_WRAPPER_H
#define ICU_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_eMIOS_Wrapper.h"
#include "Icu_Gtm_Wrapper.h"
#include "Icu_eTPU_Wrapper.h"
#include "Icu_Wkpu_Wrapper.h"
#include "eDma.h"
/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_AUTOSAR_WRAPPER_VENDOR_ID_H                   176

#define ICU_AUTOSAR_WRAPPER_MAJOR_VER_H                   4
#define ICU_AUTOSAR_WRAPPER_MINOR_VER_H                   4
#define ICU_AUTOSAR_WRAPPER_REVISION_VER_H                0

#define ICU_AUTOSAR_WRAPPER_SW_MAJOR_VER_H                1
#define ICU_AUTOSAR_WRAPPER_SW_MINOR_VER_H                0
#define ICU_AUTOSAR_WRAPPER_SW_PATCH_VER_H                1

#if (ICU_AUTOSAR_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_AUTOSAR_WRAPPER_MAJOR_VER_H != ICU_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ICU_AUTOSAR_WRAPPER_MINOR_VER_H != ICU_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ICU_AUTOSAR_WRAPPER_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_AUTOSAR_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_AUTOSAR_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_AUTOSAR_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ICU_MEASUREMENT_LOOP                ((uint32)4U)
#define ICU_CAPTURE_REGISTER_MASK           ((Icu_ValueType)0xFFFFFFU)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef struct
{
    /**< Array for saving value of DMA */
    VAR(Icu_ValueType, ICU_VAR) Icu_aDmaBuffer[ICU_MEASUREMENT_LOOP];
    /**< Array for saving the interrupt step */
    VAR(Icu_ValueType, ICU_VAR) Icu_aIsSecondInterrupt;
    /**< Save for start measurement counter */
    VAR(Icu_ValueType, ICU_VAR) Icu_aFirstEdgeTimeStamp;
} Icu_MeasurementInfo;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_Init \
( \
    P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);

#if (ICU_DEINIT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_DeInit \
( \
    P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_SetActivationCondition \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    VAR(Icu_ActivationType, AUTOMATIC) eIcu_Activation, \
    VAR(Icu_MeasurementModeType, AUTOMATIC) eIcu_Channelmode, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);

#if (ICU_STARTTIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_StartTimestamp \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    VAR(boolean,         AUTOMATIC) bDmaSupport, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_STOPTIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_StopTimestamp \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_GETTIMESTAMPINDEX_API == STD_ON)
FUNC(Icu_IndexType, ICU_CODE) Icu_Autosar_Wrapper_GetTimestampIndex \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_RESETEDGECOUNT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_ResetEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_ENABLEEDGECOUNT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_EnableEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_DISABLEEDGECOUNT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_DisableEdgeCount \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_GETEDGENUMBERS_API == STD_ON)
FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_Autosar_Wrapper_GetEdgeNumbers \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_ENABLEEDGEDETECTION_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_EnableEdgeDetection \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_DISABLEEDGEDETECTION_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_DisableEdgeDetection \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_STARTSIGNALMEASUREMENT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_StartSignalMeasurement \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    VAR(boolean,         AUTOMATIC) bDmaSupport, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_STOPSIGNALMEASUREMENT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_StopSignalMeasurement \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_GETTIMEELAPSED_API == STD_ON)
FUNC(Icu_ValueType, ICU_CODE) Icu_Autosar_Wrapper_GetTimeElapsed \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_GETDUTYCYCLEVALUES_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_GetDutyCycleValues \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    P2VAR(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_DATA) sIcu_DutyCycleValues, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_CHECKWAKEUP_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_CheckWakeup \
( \
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource, \
    VAR(Icu_ChannelType, AUTOMATIC)u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif /* (ICU_CHECKWAKEUP_API == STD_ON) */

#if (ICU_GETVERSIONINFO_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, ICU_APPL_DATA) versioninfo \
);
#endif /* (ICU_GETVERSIONINFO_API == STD_ON) */

#if (ICU_GETINPUTSTATE_API == STD_ON)
FUNC(Icu_InputStateType, ICU_CODE) Icu_Autosar_Wrapper_GetInputState \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

FUNC(Icu_LevelType, ICU_CODE) Icu_Autosar_Wrapper_GetInputLevel \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
FUNC(boolean, ICU_CODE) Icu_Autosar_Wrapper_GetOverFlow \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);

#if (ICU_CAPTURERGISTER_API == STD_ON)
FUNC(Icu_ValueType, ICU_CODE) Icu_Autosar_Wrapper_GetCaptureRegisterValue \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
FUNC(EcuM_WakeupSourceType, ICU_CODE) Icu_Autosar_Wrapper_GetWakeupSource \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif /* ICU_REPORT_WAKEUP_SOURCE */

#if (ICU_STARTTIMESTAMP_API == STD_ON)
FUNC(Icu_TimestampBufferType, ICU_CODE) Icu_Autosar_Wrapper_GetTimestampBufferType \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);
#endif /* (ICU_STARTTIMESTAMP_API == STD_ON) */

FUNC(Std_ReturnType, ICU_CODE) Icu_Autosar_Wrapper_StartTimestampDMA \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);

FUNC(Std_ReturnType, ICU_CODE) Icu_Autosar_Wrapper_StartSignalMeasurementDMA \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    CONSTP2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr \
);

FUNC(void,ICU_CODE) Icu_Autosar_Wrapper_TimestampDmaProcess \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel \
);

FUNC(void,ICU_CODE) Icu_Autosar_Wrapper_SignalMeasurementDmaProcess \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel \
);

FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_IrqConfig \
( \
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
    P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) sIcu_WrapperConfigPtr, \
    VAR(boolean, AUTOMATIC) IsEnable
);
#if (ICU_MULTI_CORE == STD_ON)
FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_SetMultiCoreIrqEnableState
(
	VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
	VAR(uint32, ICU_VAR) state
);

FUNC(void, ICU_CODE) Icu_Autosar_Wrapper_SetMultiCoreIrqCompleteState
(
	VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel, \
	VAR(uint32, ICU_VAR) state
);

FUNC(boolean, ICU_CODE) Icu_Autosar_Wrapper_MultiCoreIrqCompleteState
(
    VAR(Icu_ChannelType, AUTOMATIC) u16Icu_Channel
);
#endif

#ifdef __cplusplus
}
#endif

#endif /* ICU_AUTOSAR_WRAPPER_H */
