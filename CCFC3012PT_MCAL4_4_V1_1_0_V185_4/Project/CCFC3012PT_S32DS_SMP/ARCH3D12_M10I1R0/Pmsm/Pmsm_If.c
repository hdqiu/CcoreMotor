/*******************************************************************************
**                                                                            **
** Copyright (C) XXXXXXXX XXXXXXXXXXXX (2025)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Pmsm_If.c                                                  **
**                                                                            **
**  VERSION      : 0.0.1                                                      **
**                                                                            **
**  DATE         : 2025-03-26                                                 **
**                                                                            **
**  PLATFORM     : xxxx                                                       **
**                                                                            **
**  AUTHOR       : XXXX                                                       **
**                                                                            **
**  DESCRIPTION  : PMSM Integrated Interface                                  **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Pmsm_Public.h"
#include "Pmsm_If.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
// Bss 8Bits
// #define PMSM_START_SEC_TRUSTED_BSS_8BITS
// #include "Pmsm_MemMap.h"

// #define PMSM_STOP_SEC_TRUSTED_BSS_8BITS
// #include "Pmsm_MemMap.h"

// Bss 16Bits
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurrBuff_U[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN];
#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurrBuff_V[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN];
#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurrBuff_W[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN];
#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

// Bss 32Bits
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_PhyVs;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_PhyVd;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_PhyVq;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_RdceTheta_Rad;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_RdceThetaOffset_Rad;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

// Bss Unspecified
// #define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED
// #include "Pmsm_MemMap.h"

// #define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED
// #include "Pmsm_MemMap.h"

// Data 8Bits
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
uint8 Pmsm_u8_MotCmdSel = 3u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
volatile uint8 Pmsm_u8_MotCmdSelIn = 3u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
boolean Pmsm_bl_InitEnd = PMSM_FALSE;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
uint8 Pmsm_u8_State = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
volatile boolean Cdd_bl_ZeroCurrStudyDoneFlg = PMSM_FALSE;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
volatile boolean Cdd_bl_ZeroCurrStudyErrFlg = PMSM_FALSE;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
uint8 Cdd_u16_ZeroCurrStudySteps = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
uint8 Cdd_u8_ZeroCurrStudyErrCnt = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"

// Data 16Bits
#define PMSM_START_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"
uint16 dbg_delay_cnt = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"
uint16 Cdd_bl_ZeroCurrCnt = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurr_U = 2048u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurr_V = 2048u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurr_W = 2048u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"

// Data 32Bits
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
volatile float32 Pmsm_f32_ManuVdRef_Volt = 0.0F;
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
volatile float32 Pmsm_f32_ManuVqRef_Volt = 0.0F;
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
volatile float32 Pmsm_f32_DbgTheta_Rad = 0.0F;
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
volatile float32 Pmsm_f32_RdcThetaOffset_Rad = 0.0F;
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

// Data Unspecified
// #define PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED
// #include "Pmsm_MemMap.h"

// #define PMSM_STOP_SEC_TRUSTED_DATA_UNSPECIFIED
// #include "Pmsm_MemMap.h"

// MOTOR B /////////////////////////////////////////////////////////////
// Bss 8Bits
// #define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
// #include "Pmsm_MemMap.h"

// #define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
// #include "Pmsm_MemMap.h"

// Bss 16Bits
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurrBuff_U_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN];
#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurrBuff_V_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN];
#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurrBuff_W_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN];
#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

// Bss 32Bits
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_PhyVs_B;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_PhyVd_B;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_PhyVq_B;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_RdceTheta_Rad_B;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
float32 Pmsm_f32_RdceThetaOffset_Rad_B;
#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

// Bss Unspecified
// #define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
// #include "Pmsm_MemMap.h"

// #define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
// #include "Pmsm_MemMap.h"

// Data 8Bits
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
uint8 Pmsm_u8_MotCmdSel_B = 3u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
volatile uint8 Pmsm_u8_MotCmdSelIn_B = 6u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
boolean Pmsm_bl_InitEnd_B = PMSM_FALSE;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
uint8 Pmsm_u8_State_B = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
volatile boolean Cdd_bl_ZeroCurrStudyDoneFlg_B = PMSM_FALSE;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
volatile boolean Cdd_bl_ZeroCurrStudyErrFlg_B = PMSM_FALSE;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
uint8 Cdd_u16_ZeroCurrStudySteps_B = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
uint8 Cdd_u8_ZeroCurrStudyErrCnt_B = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

// Data 16Bits
#define PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"
uint16 dbg_delay_cnt_b = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"
uint16 Cdd_bl_ZeroCurrCnt_B = 0u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurr_U_B = 2048u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurr_V_B = 2048u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"
uint16 Cdd_u16_ZeroCurr_W_B = 2048u;
#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"

// Data 32Bits
// #define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
// #include "Pmsm_MemMap.h"
// volatile float32 Pmsm_f32_MotCmdSelIn_B = 2.0F;
// #define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
// #include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
volatile float32 Pmsm_f32_ManuVdRef_Volt_B = 0.0F;
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
volatile float32 Pmsm_f32_ManuVqRef_Volt_B = 0.0F;
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
volatile float32 Pmsm_f32_DbgTheta_Rad_B = 0.0F;
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
volatile float32 Pmsm_f32_RdcThetaOffset_Rad_B = 0.0F;
#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

// Data Unspecified
// #define PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
// #include "Pmsm_MemMap.h"

// #define PMSM_STOP_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
// #include "Pmsm_MemMap.h"


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Functon Definitions                            **
*******************************************************************************/
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_Init(void);
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
uint8 Pmsm_GetStatus(void);
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_PhaseCurrent(uint16 phas_u, uint16 phas_v, uint16 phas_w);
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_RdcAngSpd(uint16 angle, float32 speed);
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_Foc_Runnable(float32 vdc, uint16 *dc_u, uint16 *dc_v, uint16 *dc_w);
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"

#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Pmsm_Init_MotB(void);
#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
uint8 Pmsm_GetStatus_MotB(void);
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Pmsm_PhaseCurrent_MotB(uint16 phas_u, uint16 phas_v, uint16 phas_w);
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Pmsm_RdcAngSpd_MotB(uint16 angle, float32 speed);
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Pmsm_Foc_Runnable_MotB(float32 vdc, uint16 *dc_u, uint16 *dc_v, uint16 *dc_w);
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
void Cdd_AdcZeroCurrInitStudy(uint16 zero_u, uint16 zero_v, uint16 zero_w);
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
uint8 Cdd_RtnZeroCurrStudyStatus(void);
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
void Cdd_BubbleSortU16(uint16 *arr, uint16 StartPos, uint16 EndPos);
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Cdd_AdcZeroCurrInitStudy_MotB(uint16 zero_u, uint16 zero_v, uint16 zero_w);
#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
uint8 Cdd_RtnZeroCurrStudyStatus_MotB(void);
#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"


#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_Init(void)
{
    Pmsm_RdcCalcThetaSpeed_initialize();
    Pmsm_Foc_initialize();
    Pmsm_PhasCurrCalc_initialize();
    Pmsm_SpdLpFlxWkn_initialize();
    Pmsm_f32_DbgIqRef = 0.0F;
    Pmsm_f32_DeadBand = 0.0F;
    Pmsm_f32_D_PGain = 0.05F;
    Pmsm_f32_D_IGain = 0.005F;
    Pmsm_f32_Q_PGain = 0.05F;
    Pmsm_f32_Q_IGain = 0.005F;
#ifndef PMSM_DEBUG_MODE
    Pmsm_f32_RdcThetaOffset_Rad = 3.61866F;
    Pmsm_u16_RdceThetaOffset_C = Pmsm_f32_RdcThetaOffset_Rad * 10430.37835F;
#else
    Pmsm_u16_RdceThetaOffset_C = 0u;
#endif
    Pmsm_f32_PhsCurrUGain = 0.009765625F; /* 5/4096/25/0.005 */
    Pmsm_f32_PhsCurrVGain = 0.009765625F;
    Pmsm_f32_PhsCurrWGain = 0.009765625F;
    Pmsm_bl_FlxWknEnable = PMSM_FALSE;
//    Pmsm_bl_FlxWknEnable = PMSM_TRUE;
    Pmsm_f32_SpdLp_OutMax = 0.34F;

Pmsm_u8_MotCmdSelIn = 3u;
Pmsm_f32_DnSelSvm7Val = 0.64F;
Pmsm_f32_Flux = 0.00755555555F;
Pmsm_f32_Kt = 0.034F;
Pmsm_f32_Ld = 0.000101F;
Pmsm_f32_Lq = 0.000101F;
Pmsm_f32_Rpm2eRads = 0.314159274F;
Pmsm_f32_SvpwmRMax = 0.84F;
Pmsm_f32_UpSelSvm5Val = 0.74F;
Pmsm_f32_VfAngIncStep_C = 0.32768F;
Pmsm_f32_AngCompCoeff = 0.0F;
Pmsm_f32_DQ_IRefFdbErrLimit_MAX = 500.0F;
Pmsm_f32_DeadZoneCompVal = 0.04F;
Pmsm_f32_EmfVoltCompCoeff = 0.7F;
Pmsm_f32_EmfVoltCompLimited = 0.8F;
Pmsm_f32_MotSpdLimit_MAX = 15000.0F;
Pmsm_f32_VBus2VdVqLimited = 0.8F;
Pmsm_f32_VBusCurrGain = 1.0F;
Pmsm_f32_VBusCurrOffset = 0.0F;
Pmsm_f32_VBusLimit_MAX = 16.0F;
Pmsm_f32_VBusLimit_MIN = 9.0F;
Pmsm_f32_VbusFiltCoeff = 0.3F;
Pmsm_f32_VfSpeed_C = 0.0F;
Pmsm_bl_AngCompEnable = false;
Pmsm_bl_DeadZoneCompEnable = false;
Pmsm_bl_EmfVoltCompEnable = false;
Pmsm_bl_Svm5ForcEnb = false;
Pmsm_bl_Svm5or7SelEnable = false;
Pmsm_f32_RdcMSpdCalcCoeff_C = 0.305175781F;
Pmsm_f32_RdcMSpdCalcFiltCoeff_C = 0.2F;
Pmsm_f32_RdcSpdFiltCoeff_C = 0.2F;
Pmsm_f32_FlxWkn_LkupTabVoltage = 12.0F;
Pmsm_f32_FlxWkn_SpdShiftPerVolt = 100.0F;
Pmsm_f32_invKt = 29.4117641F;
Pmsm_f32_DdgTorqStepper = 0.01F;
Pmsm_f32_FlxWkb_VbusFiltCoeff = 0.2F;
Pmsm_f32_SpdLpFdbLpfCoeff_C = 1.0F;
Pmsm_f32_SpdLpfCoeff_C = 0.05F;
Pmsm_f32_SpdLpRefMax = 5000.0F;
Pmsm_f32_SpdLp_Ki = 0.0001F;
Pmsm_f32_SpdLp_Kp = 0.001F;
Pmsm_f32_SpdLp_OutMax = 0.34F;
Pmsm_f32_SpdRefStepper = 1.0F;
Pmsm_bl_DbgTorqStepEnable = true;
// Pmsm_bl_FlxWknEnable = true;
Pmsm_bl_FlxWkn_VoltShiftEnable = false;
Pmsm_bl_SpdRefStepEnable = true;
Pmsm_bl_TorqLookupEnable = true;
Pmsm_f32_SpdLpDeadband = 5.0F;
Pmsm_f32_IdFdbLpfCoeff_C = 1.0F;
Pmsm_f32_IqFdbLpfCoeff_C = 1.0F;
    Pmsm_bl_InitEnd = PMSM_TRUE;
}
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Pmsm_Init_MotB(void)
{
    Pmsm_RdcCalcThetaSpeed_MotB_initialize();
    Pmsm_Foc_MotB_initialize();
    Pmsm_PhasCurrCalc_MotB_initialize();
    Pmsm_SpdLpFlxWkn_MotB_initialize();
    Pmsm_f32_DbgIqRef_B = 0.0F;
    Pmsm_f32_DeadBand_B = 0.0F;
    Pmsm_f32_D_PGain_B = 0.05F;
    Pmsm_f32_D_IGain_B = 0.005F;
    Pmsm_f32_Q_PGain_B = 0.05F;
    Pmsm_f32_Q_IGain_B = 0.005F;
#ifndef PMSM_DEBUG_MODE
    Pmsm_f32_RdcThetaOffset_Rad_B = 3.61866F;
    Pmsm_u16_RdceThetaOffset_C_B = (uint16)(Pmsm_f32_RdcThetaOffset_Rad_B * 10430.37835F);
#else
    Pmsm_u16_RdceThetaOffset_C_B = 0u;
#endif
    Pmsm_f32_PhsCurrUGain_B = 0.009765625F; /* 5/4096/25/0.005 */
    Pmsm_f32_PhsCurrVGain_B = 0.009765625F;
    Pmsm_f32_PhsCurrWGain_B = 0.009765625F;
    Pmsm_bl_FlxWknEnable_B = PMSM_FALSE;
//    Pmsm_bl_FlxWknEnable_B = PMSM_TRUE;
    Pmsm_f32_SpdLp_OutMax_B = 0.34F;
    Pmsm_f32_DbgIqRef_B = 0.0F;

Pmsm_u8_MotCmdSelIn_B = 3u;
Pmsm_f32_DnSelSvm7Val_B = 0.64F;
Pmsm_f32_Flux_B = 0.00755555555F;
Pmsm_f32_Kt_B = 0.034F;
Pmsm_f32_Ld_B = 0.000101F;
Pmsm_f32_Lq_B = 0.000101F;
Pmsm_f32_Rpm2eRads_B = 0.314159274F;
Pmsm_f32_SvpwmRMax_B = 0.84F;
Pmsm_f32_UpSelSvm5Val_B = 0.74F;
Pmsm_f32_VfAngIncStep_C_B = 0.32768F;
Pmsm_f32_AngCompCoeff_B = 0.0F;
Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B = 500.0F;
Pmsm_f32_DeadZoneCompVal_B = 0.04F;
Pmsm_f32_EmfVoltCompCoeff_B = 0.7F;
Pmsm_f32_EmfVoltCompLimited_B = 0.8F;
Pmsm_f32_MotSpdLimit_MAX_B = 15000.0F;
Pmsm_f32_VBus2VdVqLimited_B = 0.8F;
Pmsm_f32_VBusCurrGain_B = 1.0F;
Pmsm_f32_VBusCurrOffset_B = 0.0F;
Pmsm_f32_VBusLimit_MAX_B = 16.0F;
Pmsm_f32_VBusLimit_MIN_B = 9.0F;
Pmsm_f32_VbusFiltCoeff_B = 0.3F;
Pmsm_f32_VfSpeed_C_B = 0.0F;
Pmsm_bl_AngCompEnable_B = false;
Pmsm_bl_DeadZoneCompEnable_B = false;
Pmsm_bl_EmfVoltCompEnable_B = false;
Pmsm_bl_Svm5ForcEnb_B = false;
Pmsm_bl_Svm5or7SelEnable_B = false;
Pmsm_f32_RdcMSpdCalcCoeff_C_B = 0.305175781F;
Pmsm_f32_RdcMSpdCalcFiltCoeff_C_B = 0.2F;
Pmsm_f32_RdcSpdFiltCoeff_C_B = 0.2F;
Pmsm_f32_FlxWkn_LkupTabVoltage_B = 12.0F;
Pmsm_f32_FlxWkn_SpdShiftPerVolt_B = 100.0F;
Pmsm_f32_invKt_B = 29.4117641F;
Pmsm_f32_DdgTorqStepper_B = 0.01F;
Pmsm_f32_FlxWkb_VbusFiltCoeff_B = 0.2F;
Pmsm_f32_SpdLpFdbLpfCoeff_C_B = 1.0F;
Pmsm_f32_SpdLpfCoeff_C_B = 0.05F;
Pmsm_f32_SpdLpRefMax_B = 5000.0F;
Pmsm_f32_SpdLp_Ki_B = 0.0001F;
Pmsm_f32_SpdLp_Kp_B = 0.001F;
Pmsm_f32_SpdLp_OutMax_B = 0.34F;
Pmsm_f32_SpdRefStepper_B = 1.0F;
Pmsm_bl_DbgTorqStepEnable_B = true;
// Pmsm_bl_FlxWknEnable_B = true;
Pmsm_bl_FlxWkn_VoltShiftEnable_B = false;
Pmsm_bl_SpdRefStepEnable_B = true;
Pmsm_bl_TorqLookupEnable_B = true;
Pmsm_f32_SpdLpDeadband_B = 5.0F;
Pmsm_f32_IdFdbLpfCoeff_C_B = 1.0F;
Pmsm_f32_IqFdbLpfCoeff_C_B = 1.0F;
    Pmsm_bl_InitEnd_B = PMSM_TRUE;
}
#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_1ms_Task(void)
{
#ifndef PMSM_DEBUG_MODE
    float32 vbus_scaled, iv_vbus_scaled;
#endif
    if (dbg_delay_cnt < 5000) {
        dbg_delay_cnt++;
        return;
    }
    if (Pmsm_bl_InitEnd == PMSM_FALSE) {
        Pmsm_Init();
        return;
    }
    Pmsm_f32_FlxWknMotSpd = Pmsm_f32_RdcEAng2MSpd; // Pmsm_f32_RdcMSpd
    Pmsm_f32_FlxWknVBus = Pmsm_f32_VBus;
    Pmsm_SpdLpFlxWkn_step();
#ifndef PMSM_DEBUG_MODE
    vbus_scaled = 1.7320508F / Pmsm_f32_VBus;
    iv_vbus_scaled = Pmsm_f32_VBus * 0.57735F;
    Pmsm_f32_PhyVs = Pmsm_f32_PIVoltCmd;
    Pmsm_f32_PhyVd = iv_vbus_scaled * Pmsm_f32_VdCmd;
    Pmsm_f32_PhyVq = iv_vbus_scaled * Pmsm_f32_VqCmd;
    Pmsm_f32_RdceTheta_Rad = ((float32)Pmsm_u16_RdcEAngle) * 9.5873799242852576857380474343247e-5F; /* 2 * PI / 65536 */
    Pmsm_f32_RdceThetaOffset_Rad = ((float32)Pmsm_u16_RdceThetaOffset_C) * 9.5873799242852576857380474343247e-5F; /* 2 * PI / 65536 */
    Pmsm_u16_DbgTheta = (uint16)(Pmsm_f32_DbgTheta_Rad  * 10430.37835F);
    Pmsm_u16_RdceThetaOffset_C = (uint16)(Pmsm_f32_RdcThetaOffset_Rad * 10430.37835F);
    Pmsm_f32_DbgVdRef = vbus_scaled * Pmsm_f32_ManuVdRef_Volt;
    Pmsm_f32_DbgVqRef = vbus_scaled * Pmsm_f32_ManuVqRef_Volt;
#endif
}
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Pmsm_1ms_Task_MOTB(void)
{
#ifndef PMSM_DEBUG_MODE
    float32 vbus_scaled_b, iv_vbus_scaled_b;
#endif
    if (dbg_delay_cnt_b < 5000) {
        dbg_delay_cnt_b++;
        return;
    }
    if (Pmsm_bl_InitEnd_B == PMSM_FALSE) {
        Pmsm_Init_MotB();
        return;
    }
    Pmsm_f32_FlxWknMotSpd_B = Pmsm_f32_RdcEAng2MSpd_B; // Pmsm_f32_RdcMSpd_B
    Pmsm_f32_FlxWknVBus_B = Pmsm_f32_VBus_B;
    Pmsm_SpdLpFlxWkn_MotB_step();
#ifndef PMSM_DEBUG_MODE
    vbus_scaled_b = 1.7320508F / Pmsm_f32_VBus_B;
    iv_vbus_scaled_b = Pmsm_f32_VBus_B * 0.57735F;
    Pmsm_f32_PhyVs_B = Pmsm_f32_PIVoltCmd_B;
    Pmsm_f32_PhyVd_B = iv_vbus_scaled_b * Pmsm_f32_VdCmd_B;
    Pmsm_f32_PhyVq_B = iv_vbus_scaled_b * Pmsm_f32_VqCmd_B;
    Pmsm_f32_RdceTheta_Rad_B = ((float32)Pmsm_u16_RdcEAngle_B) * 9.5873799242852576857380474343247e-5F; /* 2 * PI / 65536 */
    Pmsm_f32_RdceThetaOffset_Rad_B = ((float32)Pmsm_u16_RdceThetaOffset_C_B) * 9.5873799242852576857380474343247e-5F; /* 2 * PI / 65536 */
    Pmsm_u16_DbgTheta_B = (uint16)(Pmsm_f32_DbgTheta_Rad_B  * 10430.37835F);
    Pmsm_u16_RdceThetaOffset_C_B = (uint16)(Pmsm_f32_RdcThetaOffset_Rad_B * 10430.37835F);
    Pmsm_f32_DbgVdRef_B = vbus_scaled_b * Pmsm_f32_ManuVdRef_Volt_B;
    Pmsm_f32_DbgVqRef_B = vbus_scaled_b * Pmsm_f32_ManuVqRef_Volt_B;
#endif
}
#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_100us_Task(uint16 phas_u, uint16 phas_v, uint16 phas_w, uint16 angle, float32 speed, \
                    float32 vdc, uint16 *dc_u, uint16 *dc_v, uint16 *dc_w)
{
    if (Pmsm_bl_InitEnd == PMSM_FALSE) {
        return;
    }
    if (Cdd_bl_ZeroCurrStudyDoneFlg == PMSM_FALSE) {
        Cdd_AdcZeroCurrInitStudy(phas_u, phas_v, phas_w);
        return;
    }
    Pmsm_PhaseCurrent(phas_u, phas_v, phas_w);
    Pmsm_RdcAngSpd(angle, speed);
    Pmsm_Foc_Runnable(vdc, dc_u, dc_v, dc_w);
}
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
uint8 Pmsm_GetStatus(void)
{
    Pmsm_u8_State = 0u;
    if (Pmsm_bl_InitEnd == PMSM_FALSE) {
        Pmsm_u8_State |= 0x01u;
    }
    if (Cdd_RtnZeroCurrStudyStatus() != 0u) {
        Pmsm_u8_State |= 0x04u;
    }
    return (Pmsm_u8_State);
}
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_PhaseCurrent(uint16 phas_u, uint16 phas_v, uint16 phas_w)
{
    Pmsm_u16_AdcSampInPhasU = phas_u;
    Pmsm_u16_AdcSampInPhasV = phas_v;
    Pmsm_u16_AdcSampInPhasW = phas_w;
    Pmsm_u16_AdcSampInZeroU = Cdd_u16_ZeroCurr_U;
    Pmsm_u16_AdcSampInZeroV = Cdd_u16_ZeroCurr_V;
    Pmsm_u16_AdcSampInZeroW = Cdd_u16_ZeroCurr_W;
    Pmsm_bl_ZeroIVld = Pmsm_bl_ZeroIVldSvpwmOut;
    Pmsm_PhasCurrCalc_step();
}
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_RdcAngSpd(uint16 angle, float32 speed)
{
    Pmsm_u16_RdcEAngleCnt = angle;
    Pmsm_f32_RdcMSpd_Radps = speed;
    Pmsm_RdcCalcThetaSpeed_step();
}
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"
void Pmsm_Foc_Runnable(float32 vdc, uint16 *dc_u, uint16 *dc_v, uint16 *dc_w)
{
    Pmsm_bl_FlxCtrlCmdFlgIn = Pmsm_bl_FlxWknCmdFlg;
    Pmsm_f32_FlxIdRefIn = Pmsm_f32_FlxWknIdRefOut;
    Pmsm_f32_FlxIqRefIn = Pmsm_f32_FlxWknIqRefOut;
    Pmsm_f32_IU = Pmsm_f32_PhasSampCurrU;
    Pmsm_f32_IV = Pmsm_f32_PhasSampCurrV;
    // Pmsm_f32_IW = Pmsm_f32_PhasSampCurrW;
    Pmsm_f32_IW = -(Pmsm_f32_PhasSampCurrU + Pmsm_f32_PhasSampCurrV);
    Pmsm_u16_SensorTheta = Pmsm_u16_RdcEAngle;
    Pmsm_f32_MotorSpeed = Pmsm_f32_RdcMSpd;
    Pmsm_f32_VBus = vdc;
    Pmsm_GetStatus();
    if (Pmsm_u8_State == 0u) {
        Pmsm_u8_MotCmdSel = Pmsm_u8_MotCmdSelIn;
    } else {
        Pmsm_f32_DbgVdRef = 0.0f;
        Pmsm_f32_DbgVqRef = 0.0f;
        Pmsm_u8_MotCmdSel = 3u;
    }
    Pmsm_Foc_step();
    *dc_u = (uint16) ((1.0F - Pmsm_f32_DutyU) * CN_GTM_PWM_PERIOD_CNT);
    *dc_v = (uint16) ((1.0F - Pmsm_f32_DutyV) * CN_GTM_PWM_PERIOD_CNT);
    *dc_w = (uint16) ((1.0F - Pmsm_f32_DutyW) * CN_GTM_PWM_PERIOD_CNT);
}
#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"


#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Pmsm_100us_Task_MotB(uint16 phas_u, uint16 phas_v, uint16 phas_w, uint16 angle, float32 speed, \
                    float32 vdc, uint16 *dc_u, uint16 *dc_v, uint16 *dc_w)
{
    if (Pmsm_bl_InitEnd_B == PMSM_FALSE) {
        return;
    }
    if (Cdd_bl_ZeroCurrStudyDoneFlg_B == PMSM_FALSE) {
        Cdd_AdcZeroCurrInitStudy_MotB(phas_u, phas_v, phas_w);
        return;
    }
    Pmsm_PhaseCurrent_MotB(phas_u, phas_v, phas_w);
    Pmsm_RdcAngSpd_MotB(angle, speed);
    Pmsm_Foc_Runnable_MotB(vdc, dc_u, dc_v, dc_w);
}
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
uint8 Pmsm_GetStatus_MotB(void)
{
    Pmsm_u8_State_B = 0u;
    if (Pmsm_bl_InitEnd_B == PMSM_FALSE) {
        Pmsm_u8_State_B |= 0x01u;
    }
    // if (Predrv_A4911GetState() != 0u) {
    //     Pmsm_u8_State_B |= 0x02u;
    // }
    if (Cdd_RtnZeroCurrStudyStatus_MotB() != 0u) {
        Pmsm_u8_State_B |= 0x04u;
    }
    return (Pmsm_u8_State_B);
}
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Pmsm_PhaseCurrent_MotB(uint16 phas_u, uint16 phas_v, uint16 phas_w)
{
    Pmsm_u16_AdcSampInPhasU_B = phas_u;
    Pmsm_u16_AdcSampInPhasV_B = phas_v;
    Pmsm_u16_AdcSampInPhasW_B = phas_w;
    Pmsm_u16_AdcSampInZeroU_B = Cdd_u16_ZeroCurr_U_B;
    Pmsm_u16_AdcSampInZeroV_B = Cdd_u16_ZeroCurr_V_B;
    Pmsm_u16_AdcSampInZeroW_B = Cdd_u16_ZeroCurr_W_B;
    Pmsm_bl_ZeroIVld_B = Pmsm_bl_ZeroIVldSvpwmOut_B;
    Pmsm_PhasCurrCalc_MotB_step();
}
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Pmsm_RdcAngSpd_MotB(uint16 angle, float32 speed)
{
    Pmsm_u16_RdcEAngleCnt_B = angle;
    Pmsm_f32_RdcMSpd_Radps_B = speed;
    Pmsm_RdcCalcThetaSpeed_MotB_step();
}
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
volatile uint32 pmsm_valid_ok_cnt = 0;
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"
//#pragma GCC push_options
//#pragma GCC optimize ("O0")
void Pmsm_Foc_Runnable_MotB(float32 vdc, uint16 *dc_u, uint16 *dc_v, uint16 *dc_w)
{
    Pmsm_bl_FlxCtrlCmdFlgIn_B = Pmsm_bl_FlxWknCmdFlg_B;
    Pmsm_f32_FlxIdRefIn_B = Pmsm_f32_FlxWknIdRefOut_B;
    Pmsm_f32_FlxIqRefIn_B = Pmsm_f32_FlxWknIqRefOut_B;
    Pmsm_f32_IU_B = Pmsm_f32_PhasSampCurrU_B;
    Pmsm_f32_IV_B = Pmsm_f32_PhasSampCurrV_B;
    // Pmsm_f32_IW_B = Pmsm_f32_PhasSampCurrW_B;
    Pmsm_f32_IW_B = -(Pmsm_f32_PhasSampCurrU_B + Pmsm_f32_PhasSampCurrV_B);
    Pmsm_u16_SensorTheta_B = Pmsm_u16_RdcEAngle_B;
    Pmsm_f32_MotorSpeed_B = Pmsm_f32_RdcMSpd_B;
    Pmsm_f32_VBus_B = vdc;
    Pmsm_GetStatus_MotB();
    if (Pmsm_u8_State_B == 0u) {
        pmsm_valid_ok_cnt++;
        Pmsm_u8_MotCmdSel_B = Pmsm_u8_MotCmdSelIn_B;
    } else {
        Pmsm_f32_DbgVdRef_B = 0.0f;
        Pmsm_f32_DbgVqRef_B = 0.0f;
        Pmsm_u8_MotCmdSel_B = 3u;
    }
    Pmsm_Foc_MotB_step();
    *dc_u = (uint16) ((1.0F - Pmsm_f32_DutyU_B) * CN_GTM_PWM_PERIOD_CNT);
    *dc_v = (uint16) ((1.0F - Pmsm_f32_DutyV_B) * CN_GTM_PWM_PERIOD_CNT);
    *dc_w = (uint16) ((1.0F - Pmsm_f32_DutyW_B) * CN_GTM_PWM_PERIOD_CNT);
}
//#pragma GCC pop_options
#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
void Cdd_AdcZeroCurrInitStudy(uint16 zero_u, uint16 zero_v, uint16 zero_w)
{
    uint8 i;
    uint32 temp_u, temp_v, temp_w;

    if ((Cdd_bl_ZeroCurrStudyDoneFlg == PMSM_FALSE)) {
        switch (Cdd_u16_ZeroCurrStudySteps) {
            case 0u:
                if (Cdd_bl_ZeroCurrCnt < CN_ZERO_CURR_INIT_STUDY_BUFF_LEN) {
                    Cdd_u16_ZeroCurrBuff_U[Cdd_bl_ZeroCurrCnt] = zero_u;
                    Cdd_u16_ZeroCurrBuff_V[Cdd_bl_ZeroCurrCnt] = zero_v;
                    Cdd_u16_ZeroCurrBuff_W[Cdd_bl_ZeroCurrCnt] = zero_w;
                    Cdd_bl_ZeroCurrCnt++;
                } else {
                    Cdd_bl_ZeroCurrCnt = 0u;
                    Cdd_u16_ZeroCurrStudySteps = 1u;
                }
                break;
            case 1u:
                Cdd_BubbleSortU16(Cdd_u16_ZeroCurrBuff_U, 0, (CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1));
                Cdd_u16_ZeroCurrStudySteps = 2u;
                break;
            case 2u:
                Cdd_BubbleSortU16(Cdd_u16_ZeroCurrBuff_V, 0, (CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1));
                Cdd_u16_ZeroCurrStudySteps = 3u;
                break;
            case 3u:
                Cdd_BubbleSortU16(Cdd_u16_ZeroCurrBuff_W, 0, (CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1));
                Cdd_u16_ZeroCurrStudySteps = 4u;
                break;
            case 4u:
                if (((Cdd_u16_ZeroCurrBuff_U[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] - Cdd_u16_ZeroCurrBuff_U[0]) > 150)
                    || ((Cdd_u16_ZeroCurrBuff_V[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] - Cdd_u16_ZeroCurrBuff_V[0]) > 150)
                    || ((Cdd_u16_ZeroCurrBuff_W[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] - Cdd_u16_ZeroCurrBuff_W[0]) > 150)
                    || (Cdd_u16_ZeroCurrBuff_U[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_U[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_U[0] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_U[0] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_V[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_V[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_V[0] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_V[0] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_W[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_W[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_W[0] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_W[0] < 1948U)) {
                        if (Cdd_u8_ZeroCurrStudyErrCnt < 5u) {
                            Cdd_u8_ZeroCurrStudyErrCnt++;
                            Cdd_u16_ZeroCurrStudySteps = 0u;
                        } else {
                            Cdd_bl_ZeroCurrStudyErrFlg = 1u;
                            Cdd_u16_ZeroCurrStudySteps = 6u;
                        }
                        
                    } else {
                        Cdd_bl_ZeroCurrStudyErrFlg = 0u;
                        Cdd_u16_ZeroCurrStudySteps = 5u;
                    }
                break;
            case 5u:
                temp_u = 0ul;
                temp_v = 0ul;
                temp_w = 0ul;
                for (i = 8; i < (CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 8); i++) {
                    temp_u += Cdd_u16_ZeroCurrBuff_U[i];
                    temp_v += Cdd_u16_ZeroCurrBuff_V[i];
                    temp_w += Cdd_u16_ZeroCurrBuff_W[i];
                }
                Cdd_u16_ZeroCurr_U = (uint16)((uint32)temp_u >> 4);
                Cdd_u16_ZeroCurr_V = (uint16)((uint32)temp_v >> 4);
                Cdd_u16_ZeroCurr_W = (uint16)((uint32)temp_w >> 4);
                Cdd_u16_ZeroCurrStudySteps = 6u;
                break;
            case 6u:
                Cdd_bl_ZeroCurrStudyDoneFlg = PMSM_TRUE;
                Cdd_u8_ZeroCurrStudyErrCnt = 0u;
                Cdd_u16_ZeroCurrStudySteps = 0u;
                break;
        }
    }
}
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
uint8 Cdd_RtnZeroCurrStudyStatus(void)
{
    if ((Cdd_bl_ZeroCurrStudyDoneFlg == PMSM_TRUE) && (Cdd_bl_ZeroCurrStudyErrFlg == 0u)) {
        return (0u);
    } else {
        return (1u);
    }
}
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"
void Cdd_BubbleSortU16(uint16 *arr, uint16 StartPos, uint16 EndPos)
{
	uint16 i,j;
	for(i=StartPos;i<(EndPos-StartPos);i++)
	{
		for(j=StartPos;j<(EndPos-StartPos-i);j++)
		{
			if(arr[j]>arr[j+1])
			{
				arr[j] ^= arr[j+1];
				arr[j+1] ^= arr[j];
				arr[j] ^= arr[j+1];
			}
		}
	}
}
#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
void Cdd_AdcZeroCurrInitStudy_MotB(uint16 zero_u, uint16 zero_v, uint16 zero_w)
{
    uint8 i;
    uint32 temp_u, temp_v, temp_w;

    if ((Cdd_bl_ZeroCurrStudyDoneFlg_B == PMSM_FALSE)) {
        switch (Cdd_u16_ZeroCurrStudySteps_B) {
            case 0u:
                if (Cdd_bl_ZeroCurrCnt_B < CN_ZERO_CURR_INIT_STUDY_BUFF_LEN) {
                    Cdd_u16_ZeroCurrBuff_U_B[Cdd_bl_ZeroCurrCnt_B] = zero_u;
                    Cdd_u16_ZeroCurrBuff_V_B[Cdd_bl_ZeroCurrCnt_B] = zero_v;
                    Cdd_u16_ZeroCurrBuff_W_B[Cdd_bl_ZeroCurrCnt_B] = zero_w;
                    Cdd_bl_ZeroCurrCnt_B++;
                } else {
                    Cdd_bl_ZeroCurrCnt_B = 0u;
                    Cdd_u16_ZeroCurrStudySteps_B = 1u;
                }
                break;
            case 1u:
                Cdd_BubbleSortU16(Cdd_u16_ZeroCurrBuff_U_B, 0, (CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1));
                Cdd_u16_ZeroCurrStudySteps_B = 2u;
                break;
            case 2u:
                Cdd_BubbleSortU16(Cdd_u16_ZeroCurrBuff_V_B, 0, (CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1));
                Cdd_u16_ZeroCurrStudySteps_B = 3u;
                break;
            case 3u:
                Cdd_BubbleSortU16(Cdd_u16_ZeroCurrBuff_W_B, 0, (CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1));
                Cdd_u16_ZeroCurrStudySteps_B = 4u;
                break;
            case 4u:
                if (((Cdd_u16_ZeroCurrBuff_U_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] - Cdd_u16_ZeroCurrBuff_U_B[0]) > 50)
                    || ((Cdd_u16_ZeroCurrBuff_V_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] - Cdd_u16_ZeroCurrBuff_V_B[0]) > 50)
                    || ((Cdd_u16_ZeroCurrBuff_W_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] - Cdd_u16_ZeroCurrBuff_W_B[0]) > 50)
                    || (Cdd_u16_ZeroCurrBuff_U_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_U_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_U_B[0] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_U_B[0] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_V_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_V_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_V_B[0] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_V_B[0] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_W_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_W_B[CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 1] < 1948U)
                    || (Cdd_u16_ZeroCurrBuff_W_B[0] > 2148U)
                    || (Cdd_u16_ZeroCurrBuff_W_B[0] < 1948U)) {
                        if (Cdd_u8_ZeroCurrStudyErrCnt_B < 5u) {
                            Cdd_u8_ZeroCurrStudyErrCnt_B++;
                            Cdd_u16_ZeroCurrStudySteps_B = 0u;
                        } else {
                            Cdd_bl_ZeroCurrStudyErrFlg_B = 1u;
                            Cdd_u16_ZeroCurrStudySteps_B = 6u;
                        }
                        
                    } else {
                        Cdd_bl_ZeroCurrStudyErrFlg_B = 0u;
                        Cdd_u16_ZeroCurrStudySteps_B = 5u;
                    }
                break;
            case 5u:
                temp_u = 0ul;
                temp_v = 0ul;
                temp_w = 0ul;
                for (i = 8; i < (CN_ZERO_CURR_INIT_STUDY_BUFF_LEN - 8); i++) {
                    temp_u += Cdd_u16_ZeroCurrBuff_U_B[i];
                    temp_v += Cdd_u16_ZeroCurrBuff_V_B[i];
                    temp_w += Cdd_u16_ZeroCurrBuff_W_B[i];
                }
                Cdd_u16_ZeroCurr_U_B = (uint16)((uint32)temp_u >> 4);
                Cdd_u16_ZeroCurr_V_B = (uint16)((uint32)temp_v >> 4);
                Cdd_u16_ZeroCurr_W_B = (uint16)((uint32)temp_w >> 4);
                Cdd_u16_ZeroCurrStudySteps_B = 6u;
                break;
            case 6u:
                Cdd_bl_ZeroCurrStudyDoneFlg_B = PMSM_TRUE;
                Cdd_u8_ZeroCurrStudyErrCnt_B = 0u;
                Cdd_u16_ZeroCurrStudySteps_B = 0u;
                break;
        }
    }
}
#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"
uint8 Cdd_RtnZeroCurrStudyStatus_MotB(void)
{
    if ((Cdd_bl_ZeroCurrStudyDoneFlg_B == PMSM_TRUE) && (Cdd_bl_ZeroCurrStudyErrFlg_B == 0u)) {
        return (0u);
    } else {
        return (1u);
    }
}

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
