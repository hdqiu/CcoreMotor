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
*   @file    smpu_cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of smpu MCAL driver.
*
*   @addtogroup smpu
*   @{
*/

#ifdef MPU_ENABLE

#include "cmpu_cfg.h"
#ifdef SMP_ONLY_ONE_ELF
#define MEM_SHARED_START          0x400a0000UL
#define MEM_SHARED_SIZE           0x10000UL
#else
#define MEM_SHARED_START
#define MEM_SHARED_SIZE
#endif

cmpu_module_cfg_t cmpu_Cfg = {
    .sBypass   = CMPU_BYPASS_ALL,
    .uBypass   = CMPU_BYPASS_ALL,
    .debugOpt  = CMPU_DEBUG_NONE,
    .tidCtrl   = 0U
};

/* Array of entry configurations */
cmpu_entry_cfg_t cmpu_EntryArray[] = {
    {
        /* Note:
         * If iprot is 1U: Entries will not be invalidated.
         * (For test, set iprot to 0U. ) */
        .iprot                  = 0U,
        /* Note:
         * If readOnly is 1U: The entry is no longer writable by software.
         * (For test, set readOnly to 0U. ) */
        .readOnly               = 0U,
        .debug                  = 0U,
        .regType                = CMPU_SHARED_DATA_REGION,
        .regId                  = 0U,
        .addrMask               = 0U,
        .uRight                 = CMPU_RW,
        .sRight                 = CMPU_RW,
        .cacheInhibitOverride   = 0U,
        .guardOverride          = 0U,
        .cacheInhibit           = 1U, //UN-CACHE
        .guard                  = 0U,
        .tid                    = 0U,
        .tidMask                = 0U,
        .startAddr              = MEM_SHARED_START,
        .endAddr                = MEM_SHARED_START + MEM_SHARED_SIZE,
    }
};

#endif /* MPU_ENABLE */
