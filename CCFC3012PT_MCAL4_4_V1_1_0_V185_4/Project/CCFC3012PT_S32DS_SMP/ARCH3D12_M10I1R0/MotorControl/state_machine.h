/**************************************************************************
Copyright 2024 NXP. This software is owned or controlled by NXP and may only
be used strictly in accordance with the applicable license terms. By expressly
accepting such terms or by downloading, installing, activating and/or otherwise
using the software, you are agreeing that you have read, and that you agree to
comply with and are bound by, such license terms.  If you do not agree to be
bound by the applicable license terms, then you may not retain, install,
activate or otherwise use the software.
**************************************************************************
*
* @file      state_machine.h
*
* @author    r63172
*
* @version   1.0.1.0
*
* @date      Mar-31-2009
*
* @brief     Header file for StateMachineFrame "c" project
*
*******************************************************************************
*
* Detailed Description of the file. If not used, remove the separator above.
*
******************************************************************************/

#ifndef _STATE_MACHINE_FRAME_H
#define _STATE_MACHINE_FRAME_H

/******************************************************************************
 * Includes
 ******************************************************************************/
#include "PMSM_struct.h"

/******************************************************************************
 * Constants
 ******************************************************************************/

typedef void (*PFCN_VOID_PARAM_PMSM)(pmsmFOC_t *ptr); /* pointer to function with parameter*/

extern PFCN_VOID_PARAM_PMSM state_table[13][7];

#endif /* _STATE_MACHINE_FRAME_H */
