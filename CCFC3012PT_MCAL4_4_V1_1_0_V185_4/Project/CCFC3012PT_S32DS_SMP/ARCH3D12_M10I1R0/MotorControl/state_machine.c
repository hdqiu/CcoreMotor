/*==================================================================================================
*   Copyright 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms. By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
==================================================================================================*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "state_machine.h"

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

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

extern void stateFault(pmsmFOC_t *ptr);
extern void stateReset(pmsmFOC_t *ptr);
extern void stateInit(pmsmFOC_t *ptr);
extern void stateReady(pmsmFOC_t *ptr);
extern void stateCalib(pmsmFOC_t *ptr);
extern void stateAlign(pmsmFOC_t *ptr);
extern void stateRun(pmsmFOC_t *ptr);

PFCN_VOID_PARAM_PMSM state_table[13][7] =
{
    /* Actual state ->       'Reset'     'Init'      'Fault'     'Ready'     'Calib'     'Align'     'Run'*/
    /* e_reset          */{ stateReset, stateReset, stateFault, stateReset, stateReset, stateReset, stateReset },
    /* e_reset_done     */{ stateInit,  stateFault, stateFault, stateFault, stateFault, stateFault, stateFault },
    /* e_fault          */{ stateFault, stateFault, stateFault, stateFault, stateFault, stateFault, stateFault },
    /* e_fault_clear    */{ stateFault, stateFault, stateInit,  stateFault, stateFault, stateFault, stateFault },
    /* e_init_done      */{ stateFault, stateReady, stateFault, stateFault, stateFault, stateFault, stateFault },
    /* e_ready          */{ stateFault, stateFault, stateFault, stateReady, stateFault, stateFault, stateFault },
    /* e_app_on         */{ stateFault, stateFault, stateFault, stateCalib, stateFault, stateFault, stateFault },
    /* e_calib          */{ stateFault, stateFault, stateFault, stateFault, stateCalib, stateFault, stateFault },
    /* e_calib_done     */{ stateFault, stateFault, stateFault, stateFault, stateAlign, stateFault, stateFault },
    /* e_align          */{ stateFault, stateFault, stateFault, stateFault, stateFault, stateAlign, stateFault },
    /* e_align_done     */{ stateFault, stateFault, stateFault, stateFault, stateFault, stateRun,   stateFault },
    /* e_run            */{ stateFault, stateFault, stateFault, stateFault, stateFault, stateFault, stateRun   },
    /* e_app_off        */{ stateFault, stateFault, stateFault, stateReady, stateInit,  stateInit,  stateInit  }
};

