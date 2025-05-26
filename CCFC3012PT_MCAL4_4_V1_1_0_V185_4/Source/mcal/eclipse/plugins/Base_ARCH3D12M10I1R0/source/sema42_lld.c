/**
* @file sema42_lld.c
* @version 1.0.1
**@brief   AUTOSAR ADC Rte - module interface.
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
*   @file    sema42_lld.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Rte MCAL driver.
*
*   @addtogroup Rte
*   @{
*/

/*===================================================================================================
 *                                       INCLUDE FILES
 ====================================================================================================*/
#include "sema42_lld.h"

/*===================================================================================================
 *                                       LOCAL MACROS
 ====================================================================================================*/

/*===================================================================================================
 *                                       LOCAL CONSTANTS
 ====================================================================================================*/
 
/*===================================================================================================
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ====================================================================================================*/
/* Table of base addresses for SEMA42 instances. */
static P2VAR(SEMA42_Type,   RTE_VAR, RTE_APPL_DATA) s_sema42Base[SEMA42_INSTANCE_COUNT] = SEMA42_BASE;
static VAR(uint8,         RTE_VAR) s_CoreArr[NUMBER_OF_CORES] = \
    { \
        (uint8)Z7_0, \
        (uint8)Z7_1, \
        (uint8)Z4_2, \
        (uint8)Z7_3_Check, \
        (uint8)Z0_4_HSM \
    };

/*===================================================================================================
 *                                       FUNCTION PROTOTYPES
 ====================================================================================================*/
/*!
 * @brief Reset all the gate registers.
 *
 */
LOCAL_INLINE FUNC(void, RTE_CODE) SEMA42_ResetAllGates
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base \
)
{
    base->RSTGT.W.R = (uint16) SEMA42_RSTGT_W_RSTGDP(SEMA42_RSTGT_FIRST_WRITE_DATA);
    base->RSTGT.W.R = (uint16) (SEMA42_RSTGT_W_RSTGDP(SEMA42_RSTGT_SECOND_WRITE_DATA) | \
        SEMA42_RSTGT_W_RSTGTN(SEMA42_RESET_GATE_ALL));
}

/*!
 * @brief Try to lock a gate.
 * return:
 *      STATUS_SUCCESS - if opperation succeded
 *      STATUS_ERROR - if opperation failed, gate is locked by some other core
 *
 */
FUNC(status_t, RTE_CODE) SEMA42_LockGate
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base, \
    CONST(GATE_NUM,     RTE_VAR) gatenum, \
    CONST(uint8,        RTE_VAR) processor_num \
)
{
    VAR(status_t, AUTOMATIC) return_value = STATUS_SUCCESS;

    if (base->GATE[gatenum].R == SEMA42_UNLOCKED_GATE)
    {
        base->GATE[gatenum].R = SEMA42_GATE_GTFSM(processor_num + 1U);
    }
    else
    {
        if (base->GATE[gatenum].R != (processor_num + 1U))
        {
            return_value = STATUS_ERROR;
        }
    }
    return return_value;
}

/*!
 * @brief Try to unlock a gate.
 * return:
 *      STATUS_SUCCESS - if opperation succeded
 *      STATUS_ERROR - if opperation failed, gate is locked by some other core
 *
 */
FUNC(status_t, RTE_CODE) SEMA42_UnlockGate
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base, \
    CONST(GATE_NUM,     RTE_VAR) gatenum, \
    CONST(uint8,        RTE_VAR) processor_num \
)
{
    VAR(status_t, AUTOMATIC) return_value = STATUS_SUCCESS;

    if (base->GATE[gatenum].R == SEMA42_UNLOCKED_GATE)
    {
        return_value = STATUS_SUCCESS;
    }
    else
    {
        if (base->GATE[gatenum].R == (processor_num + 1U))
        {
            base->GATE[gatenum].R = ((uint8) SEMA42_GATE_GTFSM(SEMA42_UNLOCKED_GATE));
        }
        else
        {
            return_value = STATUS_ERROR;
        }
    }

    return return_value;
}

FUNC(status_t, RTE_CODE) SEMA42_CheckLock
(
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base, \
    CONST(GATE_NUM,     RTE_VAR) gatenum, \
    CONST(uint8,        RTE_VAR) processor_num, \
    VAR(uint32,         RTE_VAR) timeout \
)
{
    VAR(status_t, AUTOMATIC) status = STATUS_ERROR;

    while ((status == STATUS_ERROR) && (timeout != 0U))
    {
        if ((uint8)(base->GATE[gatenum].R) == (uint8)(processor_num + 1U))
        {
            status = STATUS_SUCCESS;
        }
        timeout --;
    }

    return status;
}

/*!
 * @brief Get gate locker.
 * return:
 *      Number of the core that locked the gate
 *
 */
LOCAL_INLINE FUNC(uint8, RTE_CODE) SEMA42_GetGateLocker
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
)
{
    return (base->GATE[gatenum].R);
}

/*!
 * @brief Reset the specified gate.
 *
 */
LOCAL_INLINE FUNC(void, RTE_CODE) SEMA42_ResetGate
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
)
{
    base->RSTGT.W.R = (uint16) SEMA42_RSTGT_W_RSTGDP(SEMA42_RSTGT_FIRST_WRITE_DATA);
    base->RSTGT.W.R = (uint16)(SEMA42_RSTGT_W_RSTGDP(SEMA42_RSTGT_SECOND_WRITE_DATA) | (SEMA42_RSTGT_W_RSTGTN(gatenum)));
}

/*!
 * @brief Reads the RSTGSM bitfield from the RSTGT register.
 * return:
 *      true    - if state is IDLE
 *      false   - for any other state
 *
 */
LOCAL_INLINE FUNC(boolean, RTE_CODE) SEMA42_IsResetGateStateIdle
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base \
)
{
    return (((base->RSTGT.R.R & SEMA42_RSTGT_R_RSTGSM_MASK) == 0U) ? (boolean)TRUE : (boolean)FALSE);
}

/*!
 * @brief Reads the Gate Master number from the RSTGT register
 *
 */
LOCAL_INLINE FUNC(uint8, RTE_CODE) SEMA42_GetResetGateBusMaster
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base \
)
{
    return ((uint8)((base->RSTGT.R.R & ((uint16_t)SEMA42_RSTGT_R_RSTGMS_MASK)) >> SEMA42_RSTGT_R_RSTGMS_SHIFT));
}

/*!
 * @brief Reads the latest gate intended to be reset from the RSTGT register
 *
 */
LOCAL_INLINE FUNC(uint8, RTE_CODE) SEMA42_GetResetGateIndex
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base \
)
{
    return ((uint8)((base->RSTGT.R.R & ((uint16_t)SEMA42_RSTGT_R_RSTGTN_MASK)) >> SEMA42_RSTGT_R_RSTGTN_SHIFT));
}

/*FUNCTION*********************************************************************
 *
 * Function Name : SEMA42_LLD_Init
 * Description   : Initialize the SEMA42 module.
 * It resets all gate registers.
 * The caller must ensure that there is no overlap between any reset operations
 * executing from different cores - otherwise the reset may not succeed.
 *
 * Implements : SEMA42_LLD_Init_Activity
 *END*************************************************************************/
FUNC(void, RTE_CODE) SEMA42_LLD_Init
( \
    CONST(SEMA42_ID,    RTE_VAR) instance \
)
{
    DEV_ASSERT((uint32)instance < SEMA42_INSTANCE_COUNT);

    P2VAR(SEMA42_Type, RTE_VAR, RTE_APPL_DATA) base = s_sema42Base[instance];
    /* Reset all gates */
    SEMA42_ResetAllGates(base);
}

/*FUNCTION*********************************************************************
 *
 * Function Name : SEMA42_LLD_LockGate
 * Description   : Attempt to lock a selected gate and return the status of the operation.
 * This function attempts to lock a selected gate and checks if the operations was successful.
 *
 * Implements : SEMA42_LLD_LockGate_Activity
 *END*************************************************************************/
FUNC(status_t, RTE_CODE) SEMA42_LLD_LockGate
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
)
{
    DEV_ASSERT((uint32)instance < SEMA42_INSTANCE_COUNT);
    DEV_ASSERT((uint32)gatenum < SEMA42_GATE_COUNT);

    P2VAR(SEMA42_Type, RTE_VAR, RTE_APPL_DATA) base = s_sema42Base[instance];

    /* Get number of processor_num */
    CONST(uint8, RTE_CONST) processor_num = s_CoreArr[GetCoreID()];

    /* Lock gate selected */
    VAR(status_t, RTE_VAR) status = SEMA42_LockGate(base, gatenum, processor_num);

    return status;
}

FUNC(status_t, RTE_CODE) SEMA42_LLD_CheckLock
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum, \
    VAR(uint32,         RTE_VAR) timeout \
)
{
    VAR(status_t, AUTOMATIC) status = STATUS_ERROR;
    P2VAR(SEMA42_Type, RTE_VAR, RTE_APPL_DATA) base = s_sema42Base[instance];

    while ((status == STATUS_ERROR) && (timeout != 0U))
    {
        if (SEMA42_GetGateLocker(base, gatenum) == (uint8)(GetCoreID() + 1U))/*read MSR (to store interrupts state)*/
        {
            status = STATUS_SUCCESS;
        }
        timeout --;
    }

    return status;
}
/*FUNCTION*********************************************************************
 *
 * Function Name : SEMA42_LLD_UnlockGate
 * Description   : Unlock a selected gate.
 * This function is used to unlock a selected gate. This operation is possible only
 * if the selected gate has been locked by the same processor that tries to unlock
 * the gate.
 *
 * Implements : SEMA42_LLD_UnlockGate_Activity
 *END*************************************************************************/
FUNC(status_t, RTE_CODE) SEMA42_LLD_UnlockGate
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
)
{
    DEV_ASSERT((uint32)instance < SEMA42_INSTANCE_COUNT);
    DEV_ASSERT((uint32)gatenum < SEMA42_GATE_COUNT);

    P2VAR(SEMA42_Type, RTE_VAR, RTE_APPL_DATA) base = s_sema42Base[instance];

    /* Get number of processor_num */
    CONST(uint8, RTE_CONST) processor_num = s_CoreArr[GetCoreID()];

    /* Unlock gate selected */
    VAR(status_t, AUTOMATIC) status = SEMA42_UnlockGate(base, gatenum, processor_num);

    return status;
}

/*FUNCTION*********************************************************************
 *
 * Function Name : SEMA42_LLD_GetGateLocker
 * Description   : Get the index of the core locking the selected gate.
 * This function returns the index of the core which locked the selected gate
 * or a special value if the gate is not locked.
 *
 * Implements : SEMA42_LLD_GetGateLocker_Activity
 *END*************************************************************************/
FUNC(uint8, RTE_CODE) SEMA42_LLD_GetGateLocker
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
)
{
    DEV_ASSERT((uint32)instance < SEMA42_INSTANCE_COUNT);
    DEV_ASSERT((uint32)gatenum < SEMA42_GATE_COUNT);

    P2VAR(SEMA42_Type, RTE_VAR, RTE_APPL_DATA) base = s_sema42Base[instance];

    /* Get gate locked */
    return SEMA42_GetGateLocker(base, gatenum);
}

/*FUNCTION*********************************************************************
 *
 * Function Name : SEMA42_LLD_ResetGate
 * Description   : Reset a selected gate register.
 * This function resets a selected gate register.
 * The caller must ensure that there is no overlap between any reset operations
 * executing from different cores - otherwise the reset may not succeed.
 *
 * Implements : SEMA42_LLD_ResetGate_Activity
 *END*************************************************************************/
FUNC(void, RTE_CODE) SEMA42_LLD_ResetGate
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
)
{
    DEV_ASSERT((uint32)instance < SEMA42_INSTANCE_COUNT);
    DEV_ASSERT((uint32)gatenum < SEMA42_GATE_COUNT);

    P2VAR(SEMA42_Type, RTE_VAR, RTE_APPL_DATA) base = s_sema42Base[instance];
    /* Reset gate index */
    SEMA42_ResetGate(base, gatenum);
}

/*FUNCTION*********************************************************************
 *
 * Function Name : SEMA42_LLD_IsResetGateStateIdle
 * Description   : Check if the current state of the reset gate state machine is idle.
 * This function retrieves the current state of the reset gate state machine.
 *
 * Implements : SEMA42_LLD_IsResetGateStateIdle_Activity
 *END*************************************************************************/
FUNC(boolean, RTE_CODE) SEMA42_LLD_IsResetGateStateIdle
( \
    CONST(SEMA42_ID,    RTE_VAR) instance \
)
{
    DEV_ASSERT((uint32)instance < SEMA42_INSTANCE_COUNT);

    P2VAR(SEMA42_Type, RTE_VAR, RTE_APPL_DATA) base = s_sema42Base[instance];
    /* Check Reset gate state idle */
    return SEMA42_IsResetGateStateIdle(base);
}

/*FUNCTION*********************************************************************
 *
 * Function Name : SEMA42_LLD_GetResetGateBusMaster
 * Description   : Get the bus master which initiated the most recent write
 * operation on the reset register.
 * This function returns the bus master index which initiated the most recent
 * write operation on the reset register.
 * A write operation on the reset register is equivalent with a reset attempt.
 *
 * Implements : SEMA42_LLD_GetResetGateBusMaster_Activity
 *END*************************************************************************/
FUNC(uint8, RTE_CODE) SEMA42_LLD_GetResetGateBusMaster
( \
    CONST(SEMA42_ID,    RTE_VAR) instance \
)
{
    DEV_ASSERT((uint32)instance < SEMA42_INSTANCE_COUNT);

    P2VAR(SEMA42_Type, RTE_VAR, RTE_APPL_DATA) base = s_sema42Base[instance];
    /* Get reset gate bus master */
    return SEMA42_GetResetGateBusMaster(base);
}

/*FUNCTION*********************************************************************
 *
 * Function Name : SEMA42_LLD_GetResetGateIndex
 * Description   : Get the index of the gate targetted by the most recent reset attempt.
 * This function returns the index of the gate targetted by the most recent reset attempt
 * or a special value if all gates have been targetted.
 *
 * Implements : SEMA42_LLD_GetResetGateIndex_Activity
 *END*************************************************************************/
FUNC(uint8, RTE_CODE) SEMA42_LLD_GetResetGateIndex
( \
    CONST(SEMA42_ID,    RTE_VAR) instance \
)
{
    DEV_ASSERT((uint32)instance < SEMA42_INSTANCE_COUNT);

    P2VAR(SEMA42_Type, RTE_VAR, RTE_APPL_DATA) base = s_sema42Base[instance];
    /* Get reset gate index */
    return SEMA42_GetResetGateIndex(base);
}
