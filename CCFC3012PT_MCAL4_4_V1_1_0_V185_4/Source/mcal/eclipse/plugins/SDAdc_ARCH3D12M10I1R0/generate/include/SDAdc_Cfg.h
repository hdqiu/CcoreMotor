/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc_Cfg.h
* @version  1.0
* @date     2024 - 03 - 06
* @brief    Initial version.
*
*****************************************************************************/

#ifndef SDADC_CFG_H
#define SDADC_CFG_H

#include "Compiler.h"
#include "StandardTypes.h"
#include "eDma_LLDriver.h"
#include "Mcal.h"
#ifdef RESOURCE_SUPPORT_SDADC_IP
#define SDADC_CFG_H_VENDOR_ID                       176
#define SDADC_MODULE_ID                             252
#define SDADC_CFG_H_AR_REL_MAJOR_VER                4
#define SDADC_CFG_H_AR_REL_MINOR_VER                4
#define SDADC_CFG_H_AR_REL_REV_VER                  0
#define SDADC_CFG_H_SW_MAJOR_VER                    1
#define SDADC_CFG_H_SW_MINOR_VER                    0
#define SDADC_CFG_H_SW_PATCH_VER                    1

#if (MCAL_VENDOR_ID               != SDADC_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_CFG_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION    != SDADC_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION    != SDADC_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != SDADC_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION        != SDADC_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION        != SDADC_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION        != SDADC_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_CFG_H_SW_PATCH_VER "
#endif

[!AUTOSPACING!]
#define SDADC_PRECOMPILE_SUPPORT[!WS "1"!][!//
[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]

[!SELECT "SDAdcGeneral"!]
#define SDADC_DEV_ERROR_DETECT [!WS "1"!][!//
[!IF "SDAdcDevErrorDetect = 'true'"!][!//
    (STD_ON)[!//
[!ELSE!][!//
    (STD_OFF)[!//
[!ENDIF!][!//

#define SDADC_ENABLE_MULTICORE[!WS "1"!][!//
[!IF "SdAdcMulticoreSupport = 'true'"!][!//
    (STD_ON)[!//
[!ELSE!][!//
    (STD_OFF)[!//
[!ENDIF!][!//
[!ENDSELECT!]

#define SDADC_DEFAULT_COREID [!"num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]U

[!SELECT "SDAdcConfigSet"!]
#define SDADC_INSTANCE_CDG_NUM [!"(num:i(count(./SDAdcInstance/*)))"!]U
[!LOOP "./SDAdcInstance/*"!]
#define SDADC_CFG_CHANNEL_ID_[!"num:i(@index)"!]   [!"num:i(@index)"!]U
[!IF "./SDAdcNewResultNotify != 'NULL_PTR'  and ./SDadcSelIntOrDma = 'INTERRUPT'"!]
/* SDADC_CFG_CHANNEL_ID_[!"num:i(@index)"!]: [!"./InstanceId"!]_SDAdcNewResultNotify */
extern FUNC(void, SDADC_CODE) [!"./SDAdcNewResultNotify"!](void);
[!ENDIF!]
[!IF "./SDAdcBufferFullNotify != 'NULL_PTR'  and ./SDadcSelIntOrDma = 'INTERRUPT' and ./SDAdcBufferMode = 'SDADC_STREAM_LINEAR_BUFFER'"!]
/* SDADC_CFG_CHANNEL_ID_[!"num:i(@index)"!]: [!"./InstanceId"!]_SDAdcBufferFullNotify */
extern FUNC(void, SDADC_CODE) [!"./SDAdcBufferFullNotify"!](void);
[!ENDIF!]
[!IF "./SDadcSelIntOrDma = 'DMA'"!]
[!IF "node:ref(SDAdcDmaCh)/eDmaChCallbaceFunction != 'NULL_PTR'"!]
/* SDADC_CFG_CHANNEL_ID_[!"num:i(@index)"!]: [!"node:ref(SDAdcDmaCh)/eDmaChannelId"!]_CallBack */
extern FUNC(void, SDADC_CODE) [!"node:ref(SDAdcDmaCh)/eDmaChCallbaceFunction"!](const void *parameter, eDMAChnStatusType status, uint8 mappedChannel);
[!ENDIF!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDSELECT!]


#endif /*RESOURCE_SUPPORT_SDADC_IP*/

#endif /* SDADC_CFG_H */

/** @} */

