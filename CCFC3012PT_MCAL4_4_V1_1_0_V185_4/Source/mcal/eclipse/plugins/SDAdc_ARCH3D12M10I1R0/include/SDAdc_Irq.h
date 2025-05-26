/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc_Irq.h
* @version  1.0
* @date     2024 - 03 - 22
* @brief    Initial version.
*
*****************************************************************************/
#ifndef SDADC_IRQ_H
#define SDADC_IRQ_H
#include "SDAdc_Cfg.h"
#include "SDAdc.h"

#ifdef RESOURCE_SUPPORT_SDADC_IP
#define SDADC_IRQ_H_VENDOR_ID                     176
#define SDADC_IRQ_H_AR_REL_MAJOR_VER              4
#define SDADC_IRQ_H_AR_REL_MINOR_VER              4
#define SDADC_IRQ_H_AR_REL_REV_VER                0
#define SDADC_IRQ_H_SW_MAJOR_VER                  1
#define SDADC_IRQ_H_SW_MINOR_VER                  0
#define SDADC_IRQ_H_SW_PATCH_VER                  1

#if (SDADC_CFG_H_VENDOR_ID               != SDADC_IRQ_H_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_IRQ_H_VENDOR_ID "
#endif
#if (SDADC_CFG_H_AR_REL_MAJOR_VER    != SDADC_IRQ_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_H_AR_REL_MAJOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_MINOR_VER    != SDADC_IRQ_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_H_AR_REL_MINOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_REV_VER != SDADC_IRQ_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_H_AR_REL_REV_VER "
#endif
#if (SDADC_CFG_H_SW_MAJOR_VER        != SDADC_IRQ_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_H_SW_MAJOR_VER "
#endif
#if (SDADC_CFG_H_SW_MINOR_VER        != SDADC_IRQ_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_H_SW_MINOR_VER "
#endif
#if (SDADC_CFG_H_SW_PATCH_VER        != SDADC_IRQ_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_H_SW_PATCH_VER "
#endif

FUNC(void, SDADC_CODE) Sdadc0_irq(void);
FUNC(void, SDADC_CODE) Sdadc1_irq(void);
FUNC(void, SDADC_CODE) Sdadc2_irq(void);
FUNC(void, SDADC_CODE) Sdadc3_irq(void);
FUNC(void, SDADC_CODE) Sdadc4_irq(void);
#ifdef RESOURCE_SUPPORT_SDADC5
FUNC(void, SDADC_CODE) Sdadc5_irq(void);
#endif
FUNC(void, SDADC_CODE) Sdadc6_irq(void);
FUNC(void, SDADC_CODE) Sdadc7_irq(void);
FUNC(void, SDADC_CODE) Sdadc8_irq(void);
#ifdef RESOURCE_SUPPORT_SDADC9
FUNC(void, SDADC_CODE) Sdadc9_irq(void);
#endif
#ifdef RESOURCE_SUPPORT_SDADC10
FUNC(void, SDADC_CODE) Sdadc10_irq(void);
#endif
#ifdef RESOURCE_SUPPORT_SDADC11
FUNC(void, SDADC_CODE) Sdadc11_irq(void);
#endif
#ifdef RESOURCE_SUPPORT_SDADC12
FUNC(void, SDADC_CODE) Sdadc12_irq(void);
#endif
#ifdef RESOURCE_SUPPORT_SDADC13
FUNC(void, SDADC_CODE) Sdadc13_irq(void);
#endif

#endif /*RESOURCE_SUPPORT_SDADC_IP*/

#endif /* SDADC_IRQ_H */

