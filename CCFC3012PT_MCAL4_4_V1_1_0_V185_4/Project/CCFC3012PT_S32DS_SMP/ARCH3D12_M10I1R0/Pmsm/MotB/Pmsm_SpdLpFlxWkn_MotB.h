/*
 * File: Pmsm_SpdLpFlxWkn_MotB.h
 *
 * Code generated for Simulink model 'Pmsm_SpdLpFlxWkn_MotB'.
 *
 * Model version                  : 1.141
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 17 21:18:51 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Execution efficiency
 *    3. Safety precaution
 *    4. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pmsm_SpdLpFlxWkn_MotB_h_
#define RTW_HEADER_Pmsm_SpdLpFlxWkn_MotB_h_
#ifndef Pmsm_SpdLpFlxWkn_MotB_COMMON_INCLUDES_
#define Pmsm_SpdLpFlxWkn_MotB_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                              /* Pmsm_SpdLpFlxWkn_MotB_COMMON_INCLUDES_ */

#include "Pmsm_SpdLpFlxWkn_MotB_types.h"
#include <string.h>

/* Storage class 'PmsmDefault', for system '<Root>' */
typedef struct {
  real32_T Merge[2];                   /* '<S2>/Merge' */
  real32_T Switch;                     /* '<S23>/Switch' */
  real32_T Delay_DSTATE;               /* '<S7>/Delay' */
  real32_T Delay1_DSTATE_g;            /* '<S25>/Delay1' */
  real32_T Delay_DSTATE_g;             /* '<S18>/Delay' */
  real32_T Delay_DSTATE_p;             /* '<S17>/Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S17>/Delay1' */
  boolean_T icLoad;                    /* '<S25>/Delay1' */
  boolean_T icLoad_f;                  /* '<S17>/Delay' */
  boolean_T Volt_Shift_Func_MODE;      /* '<S10>/Volt_Shift_Func' */
  boolean_T SpeedLoop_MODE;            /* '<S1>/SpeedLoop' */
} Pmsm_SpdLpFlxWkn_MotB_PmsmDefault;

/* Model entry point functions */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_SpdLpFlxWkn_MotB_initialize(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_SpdLpFlxWkn_MotB_step(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_SpdLpFlxWkn_MotB_terminate(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

extern Pmsm_SpdLpFlxWkn_MotB_PmsmDefault PmsmDefault_Pmsm_SpdLpFlxWkn_MotB;/* '<S2>/Merge' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Exported data declaration */

/* pmsm trusted bss 32bits */
/* Declaration for custom storage class: TRUSTED_BSS_32BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgTorqCmd_B; /* '<Root>/Dbg_TorqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxWknIdRefOut_B;/* '<S1>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxWknIqRefOut_B;/* '<S1>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxWknMotSpd_B;/* '<Root>/MotSpd' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxWknTorqRef_B;/* '<S9>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxWknVBus_B; /* '<Root>/VBus' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxWkn_IsRef_B;/* '<S11>/Sqrt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_MotSpdFdb_B;  /* '<S4>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_SpdCtrlSpdFdb_B;/* '<S3>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_SpdRef_B;     /* '<Root>/SpdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_TorqCmd_B;    /* '<Root>/TorqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 8bits */
/* Declaration for custom storage class: TRUSTED_BSS_8BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_FlxWknCmdFlg_B;/* '<S5>/Logical Operator1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Declaration for custom storage class: TRUSTED_DATA_32BITS */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_FlxWkn_LkupTabVoltage_B;/* Referenced by: '<S23>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_FlxWkn_SpdShiftPerVolt_B;/* Referenced by: '<S23>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_invKt_B;/* Referenced by: '<S12>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Declaration for custom storage class: TRUSTED_DATA_32BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_DdgTorqStepper_B;/* Referenced by: '<S7>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_FlxWkb_VbusFiltCoeff_B;/* Referenced by: '<S25>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SpdLpDeadband_B;/* Referenced by: '<S17>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SpdLpFdbLpfCoeff_C_B;/* Referenced by: '<S3>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SpdLpRefMax_B;/* Referenced by: '<S6>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SpdLp_Ki_B;/* Referenced by: '<S17>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SpdLp_Kp_B;/* Referenced by: '<S17>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SpdLp_OutMax_B;/* Referenced by: '<S17>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SpdLpfCoeff_C_B;/* Referenced by: '<S4>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SpdRefStepper_B;/* Referenced by: '<S18>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 8bits */
/* Declaration for custom storage class: TRUSTED_DATA_8BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_DbgTorqStepEnable_B;/* Referenced by: '<S7>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_FlxWknEnable_B;/* Referenced by:
                                                  * '<S2>/Constant'
                                                  * '<S9>/Constant1'
                                                  */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_FlxWkn_VoltShiftEnable_B;/* Referenced by: '<S10>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_SpdRefStepEnable_B;/* Referenced by: '<S18>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_TorqLookupEnable_B;/* Referenced by: '<S9>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted const unspecified */
#define PMSM_START_TRUSTED_CONST_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Declaration for custom storage class: TRUSTED_CONST_UNSPECIFIED_B */
extern const real32_T Pmsm_f32_FlxWknAxis_SpeedRef_B[21];/* Referenced by:
                                                          * '<S9>/Prelookup_speed'
                                                          * '<S11>/Prelookup_speed'
                                                          */
extern const real32_T Pmsm_f32_FlxWknAxis_TorqRef_B[20];
                                   /* Referenced by: '<S11>/Prelookup_torque' */
extern const int16_T Pmsm_s16p10_FlxWknTab_TeMax_B[21];
                       /* Referenced by: '<S9>/Interpolation Using Prelookup' */
extern const int16_T Pmsm_s16p7_FlxWknTab_IdRef_B[420];
                      /* Referenced by: '<S11>/Interpolation Using Prelookup' */
extern const int16_T Pmsm_s16p7_FlxWknTab_IqRef_B[420];
                     /* Referenced by: '<S11>/Interpolation Using Prelookup1' */

#define PMSM_STOP_TRUSTED_CONST_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S11>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<S25>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Pmsm_SpdLpFlxWkn_MotB'
 * '<S1>'   : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB'
 * '<S2>'   : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/FlxWknLookup'
 * '<S3>'   : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/LPF'
 * '<S4>'   : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/LPF1'
 * '<S5>'   : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/MotCmdSelect'
 * '<S6>'   : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/SpeedLoop'
 * '<S7>'   : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/Subsystem'
 * '<S8>'   : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/TorqCmd_Sel'
 * '<S9>'   : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/TorqLookup'
 * '<S10>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/Voltage_Shift'
 * '<S11>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/FlxWknLookup/If Action Subsystem'
 * '<S12>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/FlxWknLookup/If Action Subsystem1'
 * '<S13>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/MotCmdSelect/Compare To Constant1'
 * '<S14>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/MotCmdSelect/Compare To Constant4'
 * '<S15>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/MotCmdSelect/Compare To Constant5'
 * '<S16>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/SpeedLoop/Saturation Dynamic1'
 * '<S17>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/SpeedLoop/SpeedLoopPIController'
 * '<S18>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/SpeedLoop/Subsystem'
 * '<S19>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/SpeedLoop/SpeedLoopPIController/DeadZone'
 * '<S20>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/SpeedLoop/SpeedLoopPIController/Saturation Dynamic1'
 * '<S21>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/SpeedLoop/Subsystem/Compare To Constant'
 * '<S22>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/Subsystem/Compare To Constant'
 * '<S23>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/Voltage_Shift/Volt_Shift_Func'
 * '<S24>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/Voltage_Shift/Volt_Shift_Func/Compare To Zero'
 * '<S25>'  : 'Pmsm_SpdLpFlxWkn_MotB/Pmsm_SpdLpFlxWkn_MotB/Voltage_Shift/Volt_Shift_Func/Subsystem'
 */
#endif                                 /* RTW_HEADER_Pmsm_SpdLpFlxWkn_MotB_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
