/**
* @file SchM_Msc.c
* @version 1.0.1
**@brief   AUTOSAR MSC Rte - module interface.
* @details This file mainly contains reentrant interfaces and multi - core mutually exclusive interface definitions
*
* @addtogroup
* @{
*/
/****************************************************************************
*
* Copyright (c) 2022  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
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
*   @file    SchM_Msc.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Rte MCAL driver.
*
*   @addtogroup Rte
*   @{
*/
/*===================================================================================================
 *                                            INCLUDE FILES
 ====================================================================================================*/
#ifdef __cplusplus 
extern "C" {
#endif
#include "SchM_Msc.h"
#include "devassert.h"
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SEMAPHORE)
#include "sema42_lld.h"
#endif


/*===================================================================================================
 *                                            LOCAL MACROS
 ====================================================================================================*/
#define MULTICORE_MSC_GUARD_NUM             20U
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SEMAPHORE)
#ifndef RTE_MSC_SEMA42_GATE_ID
#define RTE_MSC_SEMA42_GATE_ID              (GATE_NUM)(RTE_DEFAULT_SEMA42_GATE_ID)
#endif
#endif
/*===================================================================================================
 *                                          LOCAL CONSTANTS
 ====================================================================================================*/
/*===================================================================================================
 *                               LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ====================================================================================================*/
/*===================================================================================================
 *                                          LOCAL VARIABLES
 ====================================================================================================*/
/* Guard for the module variable against overwrite */
#pragma pack (push, GUARD_TYPE_SIZE)
#define RTE_START_SEC_VAR_SHARED_NO_INIT
#include "Rte_MemMap.h"
static guard_type multi_core_msc_guard[20][MSC_CORE_NUM] = {{ 0 }};
#define RTE_STOP_SEC_VAR_SHARED_NO_INIT
#include "Rte_MemMap.h"
static guard_type *sp_guard = &multi_core_msc_guard[0][0];
#pragma pack (pop)
/*===================================================================================================
 *                                      LOCAL FUNCTION PROTOTYPES
 ====================================================================================================*/
/* allow module to enter the specific critical region */
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
LOCAL_INLINE FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA(VAR(uint16, RTE_VAR) n)
{
    VAR(uint32, RTE_VAR) u32CoreId = (uint32)GetCoreID();
    VAR(uint32, RTE_VAR) u32GuardId = (uint32)(u32CoreId + (n * MSC_CORE_NUM));
    if ((guard_type)0UL == sp_guard[u32GuardId])
    {
        SuspendAllInterrupts(); /* suspend All Interrupts */
    }
    sp_guard[u32GuardId] ++;
}
#endif

#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
LOCAL_INLINE FUNC(void, RTE_CODE) SchM_Enter_MSC_SPINLOCK_AREA(VAR(uint16, RTE_VAR) n)
{
    VAR(uint32, RTE_VAR) u32GuardId = (uint32)(n * MSC_CORE_NUM);
    while((guard_type)0UL != sp_guard[u32GuardId]);
    sp_guard[u32GuardId] = (guard_type)1UL; 
}
#endif

#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SEMAPHORE)
LOCAL_INLINE FUNC(void, RTE_CODE) SchM_Enter_MSC_SEMAPHORE_AREA(VAR(uint16, RTE_VAR) n)
{
    VAR(status_t, RTE_VAR) status = STATUS_ERROR;
    VAR(uint32, RTE_VAR) u32GuardId = (uint32)(n * MSC_CORE_NUM);
    VAR(uint32,   RTE_VAR) u32TimeOut = (uint32)RTE_SEM42_GATE_TIMEOUT;
    VAR(uint8,    RTE_VAR) u8CoreID = (uint8)GetCoreID();
    do {
        if (STATUS_SUCCESS == SEMA42_LockGate((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_MSC_SEMA42_GATE_ID, u8CoreID))
        {
            if (STATUS_SUCCESS == SEMA42_CheckLock((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_MSC_SEMA42_GATE_ID, u8CoreID, RTE_SEM42_GATE_TIMEOUT))
            {
                if ((guard_type)0UL == sp_guard[u32GuardId])
                {
                    SuspendAllInterrupts(); /* suspend All Interrupts */
                    sp_guard[u32GuardId] = (guard_type)1UL;
                }
                status = STATUS_SUCCESS;
            }
            else
            {
                /* Check lock failed */
#if (RTE_SEM42_TIMEOUT_ENABLE == STD_ON) 
                if (RTE_SEM42GATE_TIMEOUT_HOOK != NULL_PTR) 
                {
                    RTE_SEM42GATE_TIMEOUT_HOOK((uint8)RTE_MSC_SEMA42_GATE_ID);
                }
#endif
                break;
            }
            (void)SEMA42_UnlockGate((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_MSC_SEMA42_GATE_ID, u8CoreID);
        }
        else
        {
            /* Get lock failed */
            u32TimeOut--;
            if (u32TimeOut == 0U)
            {
#if (RTE_SEM42_TIMEOUT_ENABLE == STD_ON) 
                if (RTE_SEM42GATE_TIMEOUT_HOOK != NULL_PTR) 
                {
                    RTE_SEM42GATE_TIMEOUT_HOOK((uint8)RTE_MSC_SEMA42_GATE_ID);
                }
#endif
                break;
            }
        }
    } while (status != STATUS_SUCCESS);
}
#endif


/* allow module to exit the specific critical region */
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
LOCAL_INLINE FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA(VAR(uint16, RTE_VAR) n)
{
    VAR(uint32, RTE_VAR) u32CoreId = (uint32)GetCoreID();
    VAR(uint32, RTE_VAR) u32GuardId = (uint32)(u32CoreId + (n * MSC_CORE_NUM));
    sp_guard[u32GuardId] --;
    if (sp_guard[u32GuardId] == (guard_type)0UL)
    {
        ResumeAllInterrupts(); /* resume All Interrupts */
    }
}
#endif

#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
LOCAL_INLINE FUNC(void, RTE_CODE) SchM_Exit_MSC_SPINLOCK_AREA(VAR(uint16, RTE_VAR) n)
{
    sp_guard[n * MSC_CORE_NUM] = (guard_type)0UL;
}
#endif

#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SEMAPHORE)
LOCAL_INLINE FUNC(void, RTE_CODE) SchM_Exit_MSC_SEMAPHORE_AREA(VAR(uint16, RTE_VAR) n)
{
    VAR(status_t, RTE_VAR) status = STATUS_ERROR;
    VAR(uint32,   RTE_VAR) u32GuardId = (uint32)(n * MSC_CORE_NUM);
    VAR(uint32,   RTE_VAR) u32TimeOut = (uint32)RTE_SEM42_GATE_TIMEOUT;
    VAR(uint8,    RTE_VAR) u8CoreID = (uint8)GetCoreID();
    do {
        if (STATUS_SUCCESS == SEMA42_LockGate((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_MSC_SEMA42_GATE_ID, u8CoreID))
        {
            if (STATUS_SUCCESS == SEMA42_CheckLock((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_MSC_SEMA42_GATE_ID, u8CoreID, RTE_SEM42_GATE_TIMEOUT))
            {
                sp_guard[u32GuardId] = (guard_type)0UL;
                ResumeAllInterrupts(); /* resume All Interrupts */
                status = STATUS_SUCCESS;
            }
            else
            {
                /* Check lock failed */
#if (RTE_SEM42_TIMEOUT_ENABLE == STD_ON) 
                if (RTE_SEM42GATE_TIMEOUT_HOOK != NULL_PTR) 
                {
                    RTE_SEM42GATE_TIMEOUT_HOOK((uint8)RTE_MSC_SEMA42_GATE_ID);
                }
#endif
                break;
            }
            (void)SEMA42_UnlockGate((SEMA42_Type *)SEMA42_BASE, (GATE_NUM)RTE_MSC_SEMA42_GATE_ID, u8CoreID);
        }
        else
        {
            /* Get lock failed */
            u32TimeOut--;
            if (u32TimeOut == 0U)
            {
#if (RTE_SEM42_TIMEOUT_ENABLE == STD_ON) 
                if (RTE_SEM42GATE_TIMEOUT_HOOK != NULL_PTR) 
                {
                    RTE_SEM42GATE_TIMEOUT_HOOK((uint8)RTE_MSC_SEMA42_GATE_ID);
                }
#endif
                break;
            }
        }
    } while (status != STATUS_SUCCESS);
}
#endif

/*===================================================================================================
 *                                       FUNCTION PROTOTYPES
 ====================================================================================================*/
/*================================================================================================*/
 /**
 * @brief   This function is called to allow msc to enter the specific critical region.
 * @details All critical region define.
 *
 * @param[in]     void     No input parameters
 * @return        void     No return
 *
 * @pre  None
 * @post None
 *
 *================================================================================================*/
FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n)
{
    DEV_ASSERT(n < MULTICORE_MSC_GUARD_NUM);
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(n);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(n);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(n);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_00(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(0);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(0);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(0);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_01(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(1);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(1);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(1);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_02(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(2);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(2);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(2);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_03(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(3);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(3);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(3);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_04(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(4);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(4);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(4);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_05(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(5);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(5);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(5);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_06(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(6);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(6);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(6);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_07(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(7);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(7);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(7);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_08(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(8);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(8);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(8);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_09(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(9);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(9);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(9);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_10(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(10);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(10);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(10);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_11(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(11);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(11);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(11);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_12(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(12);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(12);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(12);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_13(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(13);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(13);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(13);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_14(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(14);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(14);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(14);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_15(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(15);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(15);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(15);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_16(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(16);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(16);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(16);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_17(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(17);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(17);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(17);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_18(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(18);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(18);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(18);
#endif
}

FUNC(void, RTE_CODE) SchM_Enter_MSC_EXCLUSIVE_AREA_19(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Enter_MSC_SPINLOCK_AREA(19);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Enter_MSC_EXCLUSIVE_AREA(19);
#else
    SchM_Enter_MSC_SEMAPHORE_AREA(19);
#endif
}

/*================================================================================================*/
 /**
 * @brief   This function is called to allow msc to exit the specific critical region.
 * @details All critical region define.
 *
 * @param[in]     void     No input parameters
 * @return        void     No return
 *
 * @pre  None
 * @post None
 *
 *================================================================================================*/
FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n)
{
    DEV_ASSERT(n < MULTICORE_MSC_GUARD_NUM);
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(n);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(n);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(n);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_00(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(0);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(0);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(0);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_01(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(1);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(1);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(1);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_02(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(2);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(2);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(2);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_03(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(3);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(3);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(3);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_04(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(4);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(4);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(4);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_05(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(5);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(5);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(5);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_06(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(6);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(6);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(6);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_07(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(7);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(7);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(7);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_08(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(8);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(8);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(8);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_09(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(9);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(9);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(9);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_10(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(10);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(10);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(10);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_11(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(11);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(11);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(11);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_12(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(12);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(12);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(12);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_13(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(13);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(13);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(13);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_14(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(14);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(14);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(14);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_15(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(15);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(15);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(15);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_16(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(16);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(16);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(16);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_17(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(17);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(17);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(17);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_18(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(18);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(18);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(18);
#endif
}

FUNC(void, RTE_CODE) SchM_Exit_MSC_EXCLUSIVE_AREA_19(void)
{
#if (MULTICORE_MSC_TYPE == MULTICORE_TYPE_SPINLOCK)
    SchM_Exit_MSC_SPINLOCK_AREA(19);
#elif (MULTICORE_MSC_TYPE == MULTICORE_TYPE_EXCLUSIVE)
    SchM_Exit_MSC_EXCLUSIVE_AREA(19);
#else
    SchM_Exit_MSC_SEMAPHORE_AREA(19);
#endif
}

#ifdef __cplusplus
}
#endif

