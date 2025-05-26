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
*   @file    Fls_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Cfg.h"

#define FLS_VENDOR_ID_PLUGIN_CFG_C          176
#define FLS_AR_REL_MAJOR_VER_CFG_C          4
#define FLS_AR_REL_MINOR_VER_CFG_C          4
#define FLS_AR_REL_REVISION_VER_CFG_C       0
#define FLS_SW_MAJOR_VERSION_CFG_C          1
#define FLS_SW_MINOR_VERSION_CFG_C          0
#define FLS_SW_PATCH_VERSION_CFG_C          1

#if (MCAL_VENDOR_ID != FLS_VENDOR_ID_PLUGIN_CFG_C)
    #error " NON-MATCHED DATA : FLS_VENDOR_ID_PLUGIN_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != FLS_AR_REL_MAJOR_VER_CFG_C)
    #error " NON-MATCHED DATA : FLS_AR_REL_MAJOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != FLS_AR_REL_MINOR_VER_CFG_C)
    #error " NON-MATCHED DATA : FLS_AR_REL_MINOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != FLS_AR_REL_REVISION_VER_CFG_C)
    #error " NON-MATCHED DATA : FLS_AR_REL_REVISION_VER_CFG_C "
#endif
#if (MCAL_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FLS_SW_MAJOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FLS_SW_MINOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FLS_SW_PATCH_VERSION_CFG_C "
#endif

extern FUNC( void, FLS_CODE ) Fee_JobEndNotification( void );

extern FUNC( void, FLS_CODE ) Fee_JobErrorNotification( void );

VAR(Fls_AddressType, FLS_VAR) gFls_JobAddrIt = 0UL;

VAR(Fls_AddressType, FLS_VAR) gFls_JobAddrEnd = 0UL;

VAR(volatile Fls_SectorIndex_Type, FLS_VAR) gFls_JobSectorIt = 0UL;

VAR(Fls_SectorIndex_Type, FLS_VAR) gFls_JobSectorEnd = 0UL;

VAR(uint8, FLS_VAR) gFls_JobStart = 0U;

VAR(uint32, FLS_VAR) gFls_MaxRead = 0UL;

VAR(uint32, FLS_VAR) gFls_MaxWrite = 0UL;

VAR(MemIf_StatusType, FLS_VAR) gFls_ModuleStatus = MEMIF_UNINIT;

VAR(MemIf_JobResultType, FLS_VAR) gFls_JobResult = MEMIF_JOB_OK;

VAR(Fls_Job_Type, FLS_VAR) gFls_Job = FLS_JOB_ERASE;

VAR(volatile MemIf_JobResultType, FLS_VAR) gFls_LLDJobResult = MEMIF_JOB_OK;

VAR(Fls_LLDJob_Type, FLS_VAR) gFls_LLDJob = FLASH_JOB_NONE;

static CONST(uint8, FLS_CONST) FlsConfig_FlsSectorFlags[90] =
{
    0U, /* (FlsSector_0) */
    0U, /* (FlsSector_1) */
    0U, /* (FlsSector_2) */
    0U, /* (FlsSector_3) */
    0U, /* (FlsSector_4) */
    0U, /* (FlsSector_5) */
    0U, /* (FlsSector_6) */
    0U, /* (FlsSector_7) */
    0U, /* (FlsSector_8) */
    0U, /* (FlsSector_9) */
    0U, /* (FlsSector_10) */
    0U, /* (FlsSector_11) */
    0U, /* (FlsSector_12) */
    0U, /* (FlsSector_13) */
    0U, /* (FlsSector_14) */
    0U, /* (FlsSector_15) */
    0U, /* (FlsSector_16) */
    0U, /* (FlsSector_17) */
    0U, /* (FlsSector_18) */
    0U, /* (FlsSector_19) */
    0U, /* (FlsSector_20) */
    0U, /* (FlsSector_21) */
    0U, /* (FlsSector_22) */
    0U, /* (FlsSector_23) */
    0U, /* (FlsSector_24) */
    0U, /* (FlsSector_25) */
    0U, /* (FlsSector_26) */
    0U, /* (FlsSector_27) */
    0U, /* (FlsSector_28) */
    0U, /* (FlsSector_29) */
    0U, /* (FlsSector_30) */
    0U, /* (FlsSector_31) */
    0U, /* (FlsSector_32) */
    0U, /* (FlsSector_33) */
    0U, /* (FlsSector_34) */
    0U, /* (FlsSector_35) */
    0U, /* (FlsSector_36) */
    0U, /* (FlsSector_37) */
    0U, /* (FlsSector_38) */
    0U, /* (FlsSector_39) */
    0U, /* (FlsSector_40) */
    0U, /* (FlsSector_41) */
    0U, /* (FlsSector_42) */
    0U, /* (FlsSector_43) */
    0U, /* (FlsSector_44) */
    0U, /* (FlsSector_45) */
    0U, /* (FlsSector_46) */
    0U, /* (FlsSector_47) */
    0U, /* (FlsSector_48) */
    0U, /* (FlsSector_49) */
    0U, /* (FlsSector_50) */
    0U, /* (FlsSector_51) */
    0U, /* (FlsSector_52) */
    0U, /* (FlsSector_53) */
    0U, /* (FlsSector_54) */
    0U, /* (FlsSector_55) */
    0U, /* (FlsSector_56) */
    0U, /* (FlsSector_57) */
    0U, /* (FlsSector_58) */
    0U, /* (FlsSector_59) */
    0U, /* (FlsSector_60) */
    0U, /* (FlsSector_61) */
    0U, /* (FlsSector_62) */
    0U, /* (FlsSector_63) */
    0U, /* (FlsSector_64) */
    0U, /* (FlsSector_65) */
    0U, /* (FlsSector_66) */
    0U, /* (FlsSector_67) */
    0U, /* (FlsSector_68) */
    0U, /* (FlsSector_69) */
    0U, /* (FlsSector_70) */
    0U, /* (FlsSector_71) */
    0U, /* (FlsSector_72) */
    0U, /* (FlsSector_73) */
    0U, /* (FlsSector_74) */
    0U, /* (FlsSector_75) */
    0U, /* (FlsSector_76) */
    0U, /* (FlsSector_77) */
    0U, /* (FlsSector_78) */
    0U, /* (FlsSector_79) */
    0U, /* (FlsSector_80) */
    0U, /* (FlsSector_81) */
    0U, /* (FlsSector_82) */
    0U, /* (FlsSector_83) */
    0U, /* (FlsSector_84) */
    0U, /* (FlsSector_85) */
    0U, /* (FlsSector_86) */
    0U, /* (FlsSector_87) */
    0U, /* (FlsSector_88) */
    0U /* (FlsSector_89) */
};

static CONST(uint16, FLS_CONST) FlsConfig_FlsSectorUnlock[90] =
{
    1U, /* (FlsSector_0) */
    1U, /* (FlsSector_1) */
    1U, /* (FlsSector_2) */
    1U, /* (FlsSector_3) */
    1U, /* (FlsSector_4) */
    1U, /* (FlsSector_5) */
    1U, /* (FlsSector_6) */
    1U, /* (FlsSector_7) */
    1U, /* (FlsSector_8) */
    1U, /* (FlsSector_9) */
    1U, /* (FlsSector_10) */
    1U, /* (FlsSector_11) */
    1U, /* (FlsSector_12) */
    1U, /* (FlsSector_13) */
    1U, /* (FlsSector_14) */
    1U, /* (FlsSector_15) */
    1U, /* (FlsSector_16) */
    1U, /* (FlsSector_17) */
    1U, /* (FlsSector_18) */
    1U, /* (FlsSector_19) */
    1U, /* (FlsSector_20) */
    1U, /* (FlsSector_21) */
    1U, /* (FlsSector_22) */
    1U, /* (FlsSector_23) */
    1U, /* (FlsSector_24) */
    1U, /* (FlsSector_25) */
    1U, /* (FlsSector_26) */
    1U, /* (FlsSector_27) */
    1U, /* (FlsSector_28) */
    1U, /* (FlsSector_29) */
    1U, /* (FlsSector_30) */
    1U, /* (FlsSector_31) */
    1U, /* (FlsSector_32) */
    1U, /* (FlsSector_33) */
    1U, /* (FlsSector_34) */
    1U, /* (FlsSector_35) */
    1U, /* (FlsSector_36) */
    1U, /* (FlsSector_37) */
    1U, /* (FlsSector_38) */
    1U, /* (FlsSector_39) */
    1U, /* (FlsSector_40) */
    1U, /* (FlsSector_41) */
    1U, /* (FlsSector_42) */
    1U, /* (FlsSector_43) */
    1U, /* (FlsSector_44) */
    1U, /* (FlsSector_45) */
    1U, /* (FlsSector_46) */
    1U, /* (FlsSector_47) */
    1U, /* (FlsSector_48) */
    1U, /* (FlsSector_49) */
    1U, /* (FlsSector_50) */
    1U, /* (FlsSector_51) */
    1U, /* (FlsSector_52) */
    1U, /* (FlsSector_53) */
    1U, /* (FlsSector_54) */
    1U, /* (FlsSector_55) */
    1U, /* (FlsSector_56) */
    1U, /* (FlsSector_57) */
    1U, /* (FlsSector_58) */
    1U, /* (FlsSector_59) */
    1U, /* (FlsSector_60) */
    1U, /* (FlsSector_61) */
    1U, /* (FlsSector_62) */
    1U, /* (FlsSector_63) */
    1U, /* (FlsSector_64) */
    1U, /* (FlsSector_65) */
    1U, /* (FlsSector_66) */
    1U, /* (FlsSector_67) */
    1U, /* (FlsSector_68) */
    1U, /* (FlsSector_69) */
    1U, /* (FlsSector_70) */
    1U, /* (FlsSector_71) */
    1U, /* (FlsSector_72) */
    1U, /* (FlsSector_73) */
    1U, /* (FlsSector_74) */
    1U, /* (FlsSector_75) */
    1U, /* (FlsSector_76) */
    1U, /* (FlsSector_77) */
    1U, /* (FlsSector_78) */
    1U, /* (FlsSector_79) */
    1U, /* (FlsSector_80) */
    1U, /* (FlsSector_81) */
    1U, /* (FlsSector_82) */
    1U, /* (FlsSector_83) */
    1U, /* (FlsSector_84) */
    1U, /* (FlsSector_85) */
    1U, /* (FlsSector_86) */
    1U, /* (FlsSector_87) */
    1U, /* (FlsSector_88) */
    1U, /* (FlsSector_89) */
};

static CONST(Fls_AddressType, FLS_CONST) FlsConfig_FlsSectorEndAddr[90] =
{
    0x3fff, /* (FlsSector_0) */
    0x7fff, /* (FlsSector_1) */
    0xbfff, /* (FlsSector_2) */
    0xffff, /* (FlsSector_3) */
    0x17fff, /* (FlsSector_4) */
    0x1ffff, /* (FlsSector_5) */
    0x2bfff, /* (FlsSector_6) */
    0x37fff, /* (FlsSector_7) */
    0x47fff, /* (FlsSector_8) */
    0x57fff, /* (FlsSector_9) */
    0x67fff, /* (FlsSector_10) */
    0x77fff, /* (FlsSector_11) */
    0x87fff, /* (FlsSector_12) */
    0x97fff, /* (FlsSector_13) */
    0xa7fff, /* (FlsSector_14) */
    0xb7fff, /* (FlsSector_15) */
    0xc7fff, /* (FlsSector_16) */
    0xd7fff, /* (FlsSector_17) */
    0xe7fff, /* (FlsSector_18) */
    0xf7fff, /* (FlsSector_19) */
    0x107fff, /* (FlsSector_20) */
    0x117fff, /* (FlsSector_21) */
    0x127fff, /* (FlsSector_22) */
    0x137fff, /* (FlsSector_23) */
    0x177fff, /* (FlsSector_24) */
    0x1b7fff, /* (FlsSector_25) */
    0x1f7fff, /* (FlsSector_26) */
    0x237fff, /* (FlsSector_27) */
    0x277fff, /* (FlsSector_28) */
    0x2b7fff, /* (FlsSector_29) */
    0x2f7fff, /* (FlsSector_30) */
    0x337fff, /* (FlsSector_31) */
    0x377fff, /* (FlsSector_32) */
    0x3b7fff, /* (FlsSector_33) */
    0x3f7fff, /* (FlsSector_34) */
    0x437fff, /* (FlsSector_35) */
    0x477fff, /* (FlsSector_36) */
    0x4b7fff, /* (FlsSector_37) */
    0x4f7fff, /* (FlsSector_38) */
    0x537fff, /* (FlsSector_39) */
    0x577fff, /* (FlsSector_40) */
    0x5b7fff, /* (FlsSector_41) */
    0x5f7fff, /* (FlsSector_42) */
    0x637fff, /* (FlsSector_43) */
    0x677fff, /* (FlsSector_44) */
    0x6b7fff, /* (FlsSector_45) */
    0x6f7fff, /* (FlsSector_46) */
    0x737fff, /* (FlsSector_47) */
    0x777fff, /* (FlsSector_48) */
    0x7b7fff, /* (FlsSector_49) */
    0x7f7fff, /* (FlsSector_50) */
    0x837fff, /* (FlsSector_51) */
    0x877fff, /* (FlsSector_52) */
    0x8b7fff, /* (FlsSector_53) */
    0x8f7fff, /* (FlsSector_54) */
    0x937fff, /* (FlsSector_55) */
    0x977fff, /* (FlsSector_56) */
    0x9b7fff, /* (FlsSector_57) */
    0x9f7fff, /* (FlsSector_58) */
    0xa37fff, /* (FlsSector_59) */
    0xa77fff, /* (FlsSector_60) */
    0xab7fff, /* (FlsSector_61) */
    0xaf7fff, /* (FlsSector_62) */
    0xb37fff, /* (FlsSector_63) */
    0xb77fff, /* (FlsSector_64) */
    0xbb7fff, /* (FlsSector_65) */
    0xbf7fff, /* (FlsSector_66) */
    0xc37fff, /* (FlsSector_67) */
    0xc77fff, /* (FlsSector_68) */
    0xcb7fff, /* (FlsSector_69) */
    0xcf7fff, /* (FlsSector_70) */
    0xd37fff, /* (FlsSector_71) */
    0xd77fff, /* (FlsSector_72) */
    0xdb7fff, /* (FlsSector_73) */
    0xdf7fff, /* (FlsSector_74) */
    0xe37fff, /* (FlsSector_75) */
    0xe77fff, /* (FlsSector_76) */
    0xeb7fff, /* (FlsSector_77) */
    0xef7fff, /* (FlsSector_78) */
    0xf37fff, /* (FlsSector_79) */
    0xf77fff, /* (FlsSector_80) */
    0xfb7fff, /* (FlsSector_81) */
    0xff7fff, /* (FlsSector_82) */
    0x1037fff, /* (FlsSector_83) */
    0x1077fff, /* (FlsSector_84) */
    0x10b7fff, /* (FlsSector_85) */
    0x10f7fff, /* (FlsSector_86) */
    0x1137fff, /* (FlsSector_87) */
    0x1177fff, /* (FlsSector_88) */
    0x11b7fff, /* (FlsSector_89) */
};

static CONST(Fls_AddressType, FLS_CONST) FlsConfig_FlsSectorStartAddr[90] = 
{
    0x0, /* (FlsSector_0) */
    0x4000, /* (FlsSector_1) */
    0x8000, /* (FlsSector_2) */
    0xc000, /* (FlsSector_3) */
    0x10000, /* (FlsSector_4) */
    0x18000, /* (FlsSector_5) */
    0x20000, /* (FlsSector_6) */
    0x2c000, /* (FlsSector_7) */
    0x38000, /* (FlsSector_8) */
    0x48000, /* (FlsSector_9) */
    0x58000, /* (FlsSector_10) */
    0x68000, /* (FlsSector_11) */
    0x78000, /* (FlsSector_12) */
    0x88000, /* (FlsSector_13) */
    0x98000, /* (FlsSector_14) */
    0xa8000, /* (FlsSector_15) */
    0xb8000, /* (FlsSector_16) */
    0xc8000, /* (FlsSector_17) */
    0xd8000, /* (FlsSector_18) */
    0xe8000, /* (FlsSector_19) */
    0xf8000, /* (FlsSector_20) */
    0x108000, /* (FlsSector_21) */
    0x118000, /* (FlsSector_22) */
    0x128000, /* (FlsSector_23) */
    0x138000, /* (FlsSector_24) */
    0x178000, /* (FlsSector_25) */
    0x1b8000, /* (FlsSector_26) */
    0x1f8000, /* (FlsSector_27) */
    0x238000, /* (FlsSector_28) */
    0x278000, /* (FlsSector_29) */
    0x2b8000, /* (FlsSector_30) */
    0x2f8000, /* (FlsSector_31) */
    0x338000, /* (FlsSector_32) */
    0x378000, /* (FlsSector_33) */
    0x3b8000, /* (FlsSector_34) */
    0x3f8000, /* (FlsSector_35) */
    0x438000, /* (FlsSector_36) */
    0x478000, /* (FlsSector_37) */
    0x4b8000, /* (FlsSector_38) */
    0x4f8000, /* (FlsSector_39) */
    0x538000, /* (FlsSector_40) */
    0x578000, /* (FlsSector_41) */
    0x5b8000, /* (FlsSector_42) */
    0x5f8000, /* (FlsSector_43) */
    0x638000, /* (FlsSector_44) */
    0x678000, /* (FlsSector_45) */
    0x6b8000, /* (FlsSector_46) */
    0x6f8000, /* (FlsSector_47) */
    0x738000, /* (FlsSector_48) */
    0x778000, /* (FlsSector_49) */
    0x7b8000, /* (FlsSector_50) */
    0x7f8000, /* (FlsSector_51) */
    0x838000, /* (FlsSector_52) */
    0x878000, /* (FlsSector_53) */
    0x8b8000, /* (FlsSector_54) */
    0x8f8000, /* (FlsSector_55) */
    0x938000, /* (FlsSector_56) */
    0x978000, /* (FlsSector_57) */
    0x9b8000, /* (FlsSector_58) */
    0x9f8000, /* (FlsSector_59) */
    0xa38000, /* (FlsSector_60) */
    0xa78000, /* (FlsSector_61) */
    0xab8000, /* (FlsSector_62) */
    0xaf8000, /* (FlsSector_63) */
    0xb38000, /* (FlsSector_64) */
    0xb78000, /* (FlsSector_65) */
    0xbb8000, /* (FlsSector_66) */
    0xbf8000, /* (FlsSector_67) */
    0xc38000, /* (FlsSector_68) */
    0xc78000, /* (FlsSector_69) */
    0xcb8000, /* (FlsSector_70) */
    0xcf8000, /* (FlsSector_71) */
    0xd38000, /* (FlsSector_72) */
    0xd78000, /* (FlsSector_73) */
    0xdb8000, /* (FlsSector_74) */
    0xdf8000, /* (FlsSector_75) */
    0xe38000, /* (FlsSector_76) */
    0xe78000, /* (FlsSector_77) */
    0xeb8000, /* (FlsSector_78) */
    0xef8000, /* (FlsSector_79) */
    0xf38000, /* (FlsSector_80) */
    0xf78000, /* (FlsSector_81) */
    0xfb8000, /* (FlsSector_82) */
    0xff8000, /* (FlsSector_83) */
    0x1038000, /* (FlsSector_84) */
    0x1078000, /* (FlsSector_85) */
    0x10b8000, /* (FlsSector_86) */
    0x10f8000, /* (FlsSector_87) */
    0x1138000, /* (FlsSector_88) */
    0x1178000, /* (FlsSector_89) */
};

static CONST(Fls_LengthType, FLS_CONST) FlsConfig_FlsPageSize[90] =
{
    8UL, /* (FlsSector_0) */
    8UL, /* (FlsSector_1) */
    8UL, /* (FlsSector_2) */
    8UL, /* (FlsSector_3) */
    8UL, /* (FlsSector_4) */
    8UL, /* (FlsSector_5) */
    8UL, /* (FlsSector_6) */
    8UL, /* (FlsSector_7) */
    8UL, /* (FlsSector_8) */
    8UL, /* (FlsSector_9) */
    8UL, /* (FlsSector_10) */
    8UL, /* (FlsSector_11) */
    8UL, /* (FlsSector_12) */
    8UL, /* (FlsSector_13) */
    8UL, /* (FlsSector_14) */
    8UL, /* (FlsSector_15) */
    8UL, /* (FlsSector_16) */
    8UL, /* (FlsSector_17) */
    8UL, /* (FlsSector_18) */
    8UL, /* (FlsSector_19) */
    8UL, /* (FlsSector_20) */
    8UL, /* (FlsSector_21) */
    8UL, /* (FlsSector_22) */
    8UL, /* (FlsSector_23) */
    8UL, /* (FlsSector_24) */
    8UL, /* (FlsSector_25) */
    8UL, /* (FlsSector_26) */
    8UL, /* (FlsSector_27) */
    8UL, /* (FlsSector_28) */
    8UL, /* (FlsSector_29) */
    8UL, /* (FlsSector_30) */
    8UL, /* (FlsSector_31) */
    8UL, /* (FlsSector_32) */
    8UL, /* (FlsSector_33) */
    8UL, /* (FlsSector_34) */
    8UL, /* (FlsSector_35) */
    8UL, /* (FlsSector_36) */
    8UL, /* (FlsSector_37) */
    8UL, /* (FlsSector_38) */
    8UL, /* (FlsSector_39) */
    8UL, /* (FlsSector_40) */
    8UL, /* (FlsSector_41) */
    8UL, /* (FlsSector_42) */
    8UL, /* (FlsSector_43) */
    8UL, /* (FlsSector_44) */
    8UL, /* (FlsSector_45) */
    8UL, /* (FlsSector_46) */
    8UL, /* (FlsSector_47) */
    8UL, /* (FlsSector_48) */
    8UL, /* (FlsSector_49) */
    8UL, /* (FlsSector_50) */
    8UL, /* (FlsSector_51) */
    8UL, /* (FlsSector_52) */
    8UL, /* (FlsSector_53) */
    8UL, /* (FlsSector_54) */
    8UL, /* (FlsSector_55) */
    8UL, /* (FlsSector_56) */
    8UL, /* (FlsSector_57) */
    8UL, /* (FlsSector_58) */
    8UL, /* (FlsSector_59) */
    8UL, /* (FlsSector_60) */
    8UL, /* (FlsSector_61) */
    8UL, /* (FlsSector_62) */
    8UL, /* (FlsSector_63) */
    8UL, /* (FlsSector_64) */
    8UL, /* (FlsSector_65) */
    8UL, /* (FlsSector_66) */
    8UL, /* (FlsSector_67) */
    8UL, /* (FlsSector_68) */
    8UL, /* (FlsSector_69) */
    8UL, /* (FlsSector_70) */
    8UL, /* (FlsSector_71) */
    8UL, /* (FlsSector_72) */
    8UL, /* (FlsSector_73) */
    8UL, /* (FlsSector_74) */
    8UL, /* (FlsSector_75) */
    8UL, /* (FlsSector_76) */
    8UL, /* (FlsSector_77) */
    8UL, /* (FlsSector_78) */
    8UL, /* (FlsSector_79) */
    8UL, /* (FlsSector_80) */
    8UL, /* (FlsSector_81) */
    8UL, /* (FlsSector_82) */
    8UL, /* (FlsSector_83) */
    8UL, /* (FlsSector_84) */
    8UL, /* (FlsSector_85) */
    8UL, /* (FlsSector_86) */
    8UL, /* (FlsSector_87) */
    8UL, /* (FlsSector_88) */
    8UL, /* (FlsSector_89) */
};

static CONST(Fls_PhysicalSector_Type, FLS_CONST) FlsConfig_FlsPhysicalSector[90] =
{
    FLS_DATA_L1, /* (FlsSector_0) */
    FLS_DATA_L2, /* (FlsSector_1) */
    FLS_DATA_L3, /* (FlsSector_2) */
    FLS_DATA_L4, /* (FlsSector_3) */
    FLS_DATA_L6, /* (FlsSector_4) */
    FLS_DATA_L7, /* (FlsSector_5) */
    FLS_DATA_M0, /* (FlsSector_6) */
    FLS_DATA_M1, /* (FlsSector_7) */
    FLS_DATA_H0, /* (FlsSector_8) */
    FLS_DATA_H1, /* (FlsSector_9) */
    FLS_DATA_H2, /* (FlsSector_10) */
    FLS_DATA_H3, /* (FlsSector_11) */
    FLS_DATA_H4, /* (FlsSector_12) */
    FLS_DATA_H5, /* (FlsSector_13) */
    FLS_DATA_H6, /* (FlsSector_14) */
    FLS_DATA_H7, /* (FlsSector_15) */
    FLS_DATA_H8, /* (FlsSector_16) */
    FLS_DATA_H9, /* (FlsSector_17) */
    FLS_DATA_H10, /* (FlsSector_18) */
    FLS_DATA_H11, /* (FlsSector_19) */
    FLS_DATA_H12, /* (FlsSector_20) */
    FLS_DATA_H13, /* (FlsSector_21) */
    FLS_DATA_H14, /* (FlsSector_22) */
    FLS_DATA_H15, /* (FlsSector_23) */
    FLS_DATA_B0, /* (FlsSector_24) */
    FLS_DATA_B1, /* (FlsSector_25) */
    FLS_DATA_B2, /* (FlsSector_26) */
    FLS_DATA_B3, /* (FlsSector_27) */
    FLS_DATA_B4, /* (FlsSector_28) */
    FLS_DATA_B5, /* (FlsSector_29) */
    FLS_DATA_B6, /* (FlsSector_30) */
    FLS_DATA_B7, /* (FlsSector_31) */
    FLS_DATA_B8, /* (FlsSector_32) */
    FLS_DATA_B9, /* (FlsSector_33) */
    FLS_DATA_B10, /* (FlsSector_34) */
    FLS_DATA_B11, /* (FlsSector_35) */
    FLS_DATA_B12, /* (FlsSector_36) */
    FLS_DATA_B13, /* (FlsSector_37) */
    FLS_DATA_B14, /* (FlsSector_38) */
    FLS_DATA_B15, /* (FlsSector_39) */
    FLS_DATA_B16, /* (FlsSector_40) */
    FLS_DATA_B17, /* (FlsSector_41) */
    FLS_DATA_B18, /* (FlsSector_42) */
    FLS_DATA_B19, /* (FlsSector_43) */
    FLS_DATA_B20, /* (FlsSector_44) */
    FLS_DATA_B21, /* (FlsSector_45) */
    FLS_DATA_B22, /* (FlsSector_46) */
    FLS_DATA_B23, /* (FlsSector_47) */
    FLS_DATA_B24, /* (FlsSector_48) */
    FLS_DATA_B25, /* (FlsSector_49) */
    FLS_DATA_B26, /* (FlsSector_50) */
    FLS_DATA_B27, /* (FlsSector_51) */
    FLS_DATA_B28, /* (FlsSector_52) */
    FLS_DATA_B29, /* (FlsSector_53) */
    FLS_DATA_B30, /* (FlsSector_54) */
    FLS_DATA_B31, /* (FlsSector_55) */
    FLS_DATA_B32, /* (FlsSector_56) */
    FLS_DATA_B33, /* (FlsSector_57) */
    FLS_DATA_B34, /* (FlsSector_58) */
    FLS_DATA_B35, /* (FlsSector_59) */
    FLS_DATA_B36, /* (FlsSector_60) */
    FLS_DATA_B37, /* (FlsSector_61) */
    FLS_DATA_B38, /* (FlsSector_62) */
    FLS_DATA_B39, /* (FlsSector_63) */
    FLS_DATA_B40, /* (FlsSector_64) */
    FLS_DATA_B41, /* (FlsSector_65) */
    FLS_DATA_B42, /* (FlsSector_66) */
    FLS_DATA_B43, /* (FlsSector_67) */
    FLS_DATA_B44, /* (FlsSector_68) */
    FLS_DATA_B45, /* (FlsSector_69) */
    FLS_DATA_B46, /* (FlsSector_70) */
    FLS_DATA_B47, /* (FlsSector_71) */
    FLS_DATA_B48, /* (FlsSector_72) */
    FLS_DATA_B49, /* (FlsSector_73) */
    FLS_DATA_B50, /* (FlsSector_74) */
    FLS_DATA_B51, /* (FlsSector_75) */
    FLS_DATA_B52, /* (FlsSector_76) */
    FLS_DATA_B53, /* (FlsSector_77) */
    FLS_DATA_B54, /* (FlsSector_78) */
    FLS_DATA_B55, /* (FlsSector_79) */
    FLS_DATA_B56, /* (FlsSector_80) */
    FLS_DATA_B57, /* (FlsSector_81) */
    FLS_DATA_B58, /* (FlsSector_82) */
    FLS_DATA_B59, /* (FlsSector_83) */
    FLS_DATA_B60, /* (FlsSector_84) */
    FLS_DATA_B61, /* (FlsSector_85) */
    FLS_DATA_B62, /* (FlsSector_86) */
    FLS_DATA_B63, /* (FlsSector_87) */
    FLS_DATA_B64, /* (FlsSector_88) */
    FLS_DATA_B65, /* (FlsSector_89) */
};


CONST(Fls_ConfigType, FLS_CONST) Fls_Config =
{
    (Fls_AcErasePtrType)1074396672,/* FlsAcErase */
    (Fls_AcWritePtrType)1074396672,/* FlsAcWrite */
    0.0,/* FlsCallCycle */
    MEMIF_MODE_SLOW,/* FlsDefaultMode */
    1048576U,/* FlsMaxReadFastMode */
    1024U,/* FlsMaxReadNormalMode */
    256U,/* FlsMaxWriteFastMode */
    8U,/* FlsMaxWriteNormalMode */
    &Fee_JobEndNotification,/* FlsEndNotification */
    &Fee_JobErrorNotification,/* FlsErrorNotification */
    90U,/* FlsSectorCount */
    &FlsConfig_FlsSectorStartAddr,/* FlsSectorStartAddr */
    &FlsConfig_FlsSectorEndAddr,/* FlsSectorEndAddr */
    &FlsConfig_FlsPhysicalSector,/* FlsPhysicalSector */
    &FlsConfig_FlsSectorFlags,/* FlsSectorFlags */
    &FlsConfig_FlsSectorUnlock,/* FlsSectorUnlock */
    &FlsConfig_FlsPageSize,/* FlsPageSize */
};



#ifdef __cplusplus
}
#endif
