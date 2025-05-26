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
*   @file    EthTrcv.h
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EthTrcv
*
*   @addtogroup EthTrcv
*   @{
*/
#ifndef ETHTRCV_H
#define ETHTRCV_H
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section EthTrcv_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section [global] 
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character significance 
* and case  sensitivity are supported for external identifiers.
* All compilers used support more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. 
* All compilers used support more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by coding rules
* and must follow format <MSN>_<NAME> where MSN is equal to ETHTRCV.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eth.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETHTRCV_H_VENDOR_ID                    176
#define ETHTRCV_H_AR_REL_MAJOR_VER             4
#define ETHTRCV_H_AR_REL_MINOR_VER             4
#define ETHTRCV_H_AR_REL_REV_VER               0
#define ETHTRCV_H_SW_MAJOR_VER                 1
#define ETHTRCV_H_SW_MINOR_VER                 0
#define ETHTRCV_H_SW_PATCH_VER                 1
#define ETHTRCV_MODULE_ID                      73

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (ETH_CFG_H_VENDOR_ID != ETHTRCV_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETHTRCV_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETHTRCV_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETHTRCV_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETHTRCV_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETHTRCV_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETHTRCV_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETHTRCV_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETHTRCV_H_SW_PATCH_VER "
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

extern FUNC(void, ETHTRCV_CODE)EthTrcv_ReadMiiIndication \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx, \
    VAR(uint16, AUTOMATIC) RegVal \
);

extern FUNC(void, ETHTRCV_CODE)EthTrcv_WriteMiiIndication \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx \
);
#ifdef __cplusplus
}
#endif                                              

#endif /* ETHTRCV_H */
/** @} */
