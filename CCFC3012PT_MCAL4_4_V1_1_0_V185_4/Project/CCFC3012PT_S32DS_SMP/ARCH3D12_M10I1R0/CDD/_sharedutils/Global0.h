/*
 * File: Global0.h
 *
 * Code generated for Simulink model 'MDCC'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Feb 03 11:15:13 2020
 */

#ifndef RTW_HEADER_Global0_h_
#define RTW_HEADER_Global0_h_

typedef enum {
  TOP_OFF_BOTTOM_OFF = 0,              /* Default value */
  TOP_OFF_BOTTOM_ON,
  TOP_ON_BOTTOM_OFF,
  NORMAL
} MDCC_PWMOUTMODE;

typedef enum {
  MDPM_IDLE = 0,                       /* Default value */
  MDPM_PRECHARGE,
  MDPM_PRECHARGEOK,
  MDPM_AFTERRUN1,
  MDPM_AFTERRUN2,
  MDPM_AFTERRUN3,
  MDPM_AFTERRUN4
} MDPM_MCUStatus;

typedef enum {
  MDSM_IdIqMODE = 1,                   /* Default value */
  MDSM_UdUqMODE,
  MDSM_UaUbMODE,
  MDSM_UuvwMODE,
  MDSM_AUTODraw0MODE,
  MDSM_UsMODE
} MDSM_DEBUG;

typedef enum {
  MDSM_INIT = 1,                       /* Default value */
  MDSM_Ready,
  MDSM_FailureHandle,
  MDSM_TorqueControl,
  MDSM_SpeedControl,
  MDSM_DebugHandle,
  MDSM_ACShortControl
} MDSM_MCUStatus;

#endif                                 /* RTW_HEADER_Global0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
