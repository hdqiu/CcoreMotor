/*******************************************************************************
**                                                                            **
** Copyright (C) XXXXXXXX XXXXXXXXXXXX (2025)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Pmsm_If.h                                                  **
**                                                                            **
**  VERSION      : 0.0.1                                                      **
**                                                                            **
**  DATE         : 2025-03-26                                                 **
**                                                                            **
**  PLATFORM     : xxxx                                                       **
**                                                                            **
**  AUTHOR       : XXXX                                                       **
**                                                                            **
**  DESCRIPTION  : This is the header file of "Pmsm_If.c"                     **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
*******************************************************************************/
#ifndef PMSM_IF_H
#define PMSM_IF_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Platform_Types.h"
#include "rtwtypes.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
// #define PMSM_DEBUG_MODE

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
// Mot A, Control Signals INPUT
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
extern volatile uint8 Pmsm_u8_MotCmdSelIn; /* 0 - Torque Mode: Pmsm_f32_TorqCmd
                                  * 2 - Current Loop Mode: Pmsm_f32_DbgIdRef Pmsm_f32_DbgIqRef
                                  * 3 - Vd Vq Open Mode: Pmsm_f32_ManuVdRef_Volt Pmsm_f32_ManuVqRef_Volt
                                  * 4 - PWM Duty Open Mode: Pmsm_f32_DbgDutyU Pmsm_f32_DbgDutyV Pmsm_f32_DbgDutyW
                                  * 5 - Speed Loop Mode: Pmsm_f32_SpdRef
                                  * 6 - Vd Vq Open Mode with Constant E-angle: Pmsm_f32_ManuVdRef_Volt Pmsm_f32_ManuVqRef_Volt Pmsm_f32_DbgTheta_Rad
                                  * 7 - Vd Vq Open Mode with Constant M-speed: Pmsm_f32_ManuVdRef_Volt Pmsm_f32_ManuVqRef_Volt Pmsm_f32_VfSpeed_C
                                  * */
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_SpdRef; /* Speed Demand Input, unit: rpm */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_TorqCmd; /* Torque Demand Input, unit: Nm */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgIdRef; /* D-axis Current Input, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgIqRef; /* Q-axis Current Input, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgDutyU; /* PWM Input of Phase U, range:0~1 */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgDutyV; /* PWM Input of Phase V, range:0~1 */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgDutyW; /* PWM Input of Phase W, range:0~1 */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
extern volatile float32 Pmsm_f32_ManuVdRef_Volt; /* D-axis Voltage Input, unit:V */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
extern volatile float32 Pmsm_f32_ManuVqRef_Volt; /* Q-axis Voltage Input, unit:V */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
extern volatile float32 Pmsm_f32_DbgTheta_Rad; /* E-angle Input, unit:rad */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
extern volatile float32 Pmsm_f32_RdcThetaOffset_Rad; /* RDC Offset E-angle Input, unit:rad */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
extern volatile real32_T Pmsm_f32_VfSpeed_C; /* VF Speed Input, unit: rpm */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

// Mot A, Signals OUTPUT
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
extern uint8 Pmsm_u8_MotCmdSel;     /* Common with Pmsm_u8_MotCmdSelIn */
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_PhyVs; /* Vs Voltage, unit: V */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_PhyVd; /* Vd Voltage, unit: V */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_PhyVq; /* Vq Voltage, unit: V */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_IdRef; /* D-axis Current Demand, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_IqRef; /* Q-axis Current Demand, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_Id; /* D-axis Current Feedback, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_Iq; /* Q-axis Current Feedback, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_MotSpdFdb; /* M-speed Feedback, unit: rpm */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_RdceTheta_Rad; /* RDC E-angle, unit:rad */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_RdceThetaOffset_Rad; /* RDC E-angle Offset, unit:rad */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"



// MotB
// Mot B, Control Signals INPUTS
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
extern volatile uint8 Pmsm_u8_MotCmdSelIn_B; /* 0 - Torque Mode: Pmsm_f32_TorqCmd
                                  * 2 - Current Loop Mode: Pmsm_f32_DbgIdRef Pmsm_f32_DbgIqRef
                                  * 3 - Vd Vq Open Mode: Pmsm_f32_ManuVdRef_Volt Pmsm_f32_ManuVqRef_Volt
                                  * 4 - PWM Duty Open Mode: Pmsm_f32_DbgDutyU Pmsm_f32_DbgDutyV Pmsm_f32_DbgDutyW
                                  * 5 - Speed Loop Mode: Pmsm_f32_SpdRef
                                  * 6 - Vd Vq Open Mode with Constant E-angle: Pmsm_f32_ManuVdRef_Volt Pmsm_f32_ManuVqRef_Volt Pmsm_f32_DbgTheta_Rad
                                  * 7 - Vd Vq Open Mode with Constant M-speed: Pmsm_f32_ManuVdRef_Volt Pmsm_f32_ManuVqRef_Volt Pmsm_f32_VfSpeed_C
                                  * */
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_SpdRef_B; /* Speed Demand Input, unit: rpm */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_TorqCmd_B; /* Torque Demand Input, unit: Nm */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgIdRef_B; /* D-axis Current Input, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgIqRef_B; /* Q-axis Current Input, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgDutyU_B; /* PWM Input of Phase U, range:0~1 */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgDutyV_B; /* PWM Input of Phase V, range:0~1 */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_DbgDutyW_B; /* PWM Input of Phase W, range:0~1 */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern volatile float32 Pmsm_f32_ManuVdRef_Volt_B; /* D-axis Voltage Input, unit:V */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern volatile float32 Pmsm_f32_ManuVqRef_Volt_B; /* Q-axis Voltage Input, unit:V */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern volatile float32 Pmsm_f32_DbgTheta_Rad_B; /* E-angle Input, unit:rad */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern volatile float32 Pmsm_f32_RdcThetaOffset_Rad_B; /* RDC Offset E-angle Input, unit:rad */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern volatile real32_T Pmsm_f32_VfSpeed_C_B; /* VF Speed Input, unit: rpm */
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

// Mot B, Signals OUTPUT
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
extern uint8 Pmsm_u8_MotCmdSel_B;     /* Common with Pmsm_u8_MotCmdSelIn_B */
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_PhyVs_B; /* Vs Voltage, unit: V */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_PhyVd_B; /* Vd Voltage, unit: V */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_PhyVq_B; /* Vq Voltage, unit: V */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_IdRef_B; /* D-axis Current Demand, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_IqRef_B; /* Q-axis Current Demand, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_Id_B; /* D-axis Current Feedback, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_Iq_B; /* Q-axis Current Feedback, unit: A */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern real32_T Pmsm_f32_MotSpdFdb_B; /* M-speed Feedback, unit: rpm */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_RdceTheta_Rad_B; /* RDC E-angle, unit:rad */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
extern float32 Pmsm_f32_RdceThetaOffset_Rad_B; /* RDC E-angle Offset, unit:rad */
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
extern void Pmsm_1ms_Task(void);
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
extern void Pmsm_1ms_Task_MOTB(void);
#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
extern void Pmsm_100us_Task(uint16 phas_u, uint16 phas_v, uint16 phas_w, uint16 angle, float32 speed, \
                    float32 vdc, uint16 *dc_u, uint16 *dc_v, uint16 *dc_w);
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
extern void Pmsm_100us_Task_MotB(uint16 phas_u, uint16 phas_v, uint16 phas_w, uint16 angle, float32 speed, \
                    float32 vdc, uint16 *dc_u, uint16 *dc_v, uint16 *dc_w);
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

#endif /* #ifndef PMSM_IF_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
