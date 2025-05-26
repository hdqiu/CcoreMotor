#ifndef ICU_WKPU_HAL_WRAPPER_H
#define ICU_WKPU_HAL_WRAPPER_H

#include "Icu.h"
#include "Icu_Wkpu_LLDrivers.h"

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_WKPU_HAL_WRAPPER_VENDOR_ID_H                   176

#define ICU_WKPU_HAL_WRAPPER_MAJOR_VER_H                   4
#define ICU_WKPU_HAL_WRAPPER_MINOR_VER_H                   4
#define ICU_WKPU_HAL_WRAPPER_REVISION_VER_H                0

#define ICU_WKPU_HAL_WRAPPER_SW_MAJOR_VER_H                1
#define ICU_WKPU_HAL_WRAPPER_SW_MINOR_VER_H                0
#define ICU_WKPU_HAL_WRAPPER_SW_PATCH_VER_H                1

#if (ICU_WKPU_HAL_WRAPPER_VENDOR_ID_H != ICU_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_WKPU_HAL_WRAPPER_MAJOR_VER_H != ICU_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ICU_WKPU_HAL_WRAPPER_MINOR_VER_H != ICU_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ICU_WKPU_HAL_WRAPPER_REVISION_VER_H != ICU_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_WKPU_HAL_WRAPPER_SW_MAJOR_VER_H != ICU_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_WKPU_HAL_WRAPPER_SW_MINOR_VER_H != ICU_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_WKPU_HAL_WRAPPER_SW_PATCH_VER_H != ICU_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif



#define Icu_Wkpu_HAL_Wrap_EnEdgeDetect(module, channel) \
    Icu_Wkpu_LLD_EnableInterrupt((module),(channel))

#define Icu_Wkpu_HAL_Wrap_DisEdgeDetect(module, channel) \
    Icu_Wkpu_LLD_DisableInterrupt((module),(channel))

#define Icu_Wkpu_HAL_Wrap_SetActCondition(module, channel, type) \
    Icu_Wkpu_LLD_SetActivationCondition((module), (channel), (type))

#define Icu_Wkpu_HAL_Wrapper_EnIrq(module, channel) \
    Icu_Wkpu_LLD_EnableInterrupt((module),(channel))

#define Icu_Wkpu_HAL_Wrapper_DisIrq(module, channel) \
    Icu_Wkpu_LLD_DisableInterrupt((module),(channel))

#define Icu_Wkpu_HAL_Wrapper_EnWkp(module, channel) \
    Icu_Wkpu_LLD_EnableWakeup((module),(channel))

#define Icu_Wkpu_HAL_Wrapper_DisWkp(module, channel) \
    Icu_Wkpu_LLD_DisableWakeup((module),(channel))

#if defined(CCFC3012PT)
FUNC(void, ICU_CODE)Icu_Wkpu_HAL_Wrapper_Init
(
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Wkpu_ConfigPtr
);

FUNC(void, ICU_CODE)Icu_Wkpu_HAL_Wrapper_DeInit
(
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Wkpu_ConfigPtr
);
#endif
FUNC(void, ICU_CODE)Icu_WkpuNMI_HAL_Wrapper_Init(
    P2CONST(ICU_Wkpu_NMIConfigType, AUTOMATIC, ICU_APPL_CONST) pWkpuNMIConfig
);

FUNC(void, ICU_CODE)Icu_WkpuNMI_HAL_Wrapper_DeInit( void );


#endif

