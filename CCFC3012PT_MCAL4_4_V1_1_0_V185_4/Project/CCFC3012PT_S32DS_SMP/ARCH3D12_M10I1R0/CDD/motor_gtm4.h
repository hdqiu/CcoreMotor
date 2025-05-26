/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     gtm4_demo.h
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/
#ifndef MOTOR_GTM4_H_
#define MOTOR_GTM4_H_
#include "derivative.h"
#ifdef RESORUCE_SUPPORT_GTM410
/* PRQA S 2052,1534,1536 EOF */

#include "gtm4_tom_lld.h"
#include "gtm4_cmu_lld.h"
//#include "gtm4_fifo_lld.h"
//#include "gtm4_afd_lld.h"
//#include "gtm4_lld.h"
//#include "gtm4_f2a_lld.h"
#include "gtm4_atom_lld.h"
#include "gtm4_tim_lld.h"
//#include "mcu_lld.h"
#include "console.h"

//Init10000:20000ok,Init100000:2000NG,Init50000:4000doudong
#define PWM_PERIOD (10000)		//7500//20000:10k ok
#define GTM_PWM_CLK (200*1000*1000)
#define PWM_PERIOD_CNT GTM_PWM_CLK/PWM_PERIOD

//#define MOTOR_LEFT		0
//#define MOTOR_RIGHT		1
//#define MOTOR_SIDE		MOTOR_LEFT
#define MOTOR_DISABL	0
#define MOTOR_ENABLE	1
#define MOTOR_LEFT_EN	MOTOR_ENABLE
#define MOTOR_RIGHT_EN	MOTOR_ENABLE
#define CAN_CORE		2

#define GTM_TOM_TEST    0U
#define GTM_ATOM_TEST   1U

#define TOM_FEA     0x1
#define ATOM_FEA    0x2
#define CDTM_FEA    0x3
#define CDTM0       0x4
#define CDTM1       0x5
#define CDTM2       0x6
#define CDTM3       0x7
#define CDTM4       0x8
#define CDTM5       0x9
#define CDTM6       0xA
#define Reserved    0x55
#define DTM0        0
#define DTM1        1
#define DTM2        2
#define DTM3        3
#define DTM4        4
#define DTM5        5
#define N           0xAA

typedef struct GTM_TOUT_MUX_tag {
  uint16_t TOUT_NUM;
  uint8_t Alt_FUN;
  uint16_t PAD_NUM;
}GTM_TOUT_MUX_t;

typedef struct GTM_SEL_Value_tag {
    uint8_t module;
    uint8_t index;
    uint8_t ch;
    uint8_t inver;
}GTM_SEL_Value_t;

typedef struct GTM_TOUT_SEL_tag {
    uint16_t         TOUT_NUM;
    GTM_SEL_Value_t  SEL_Value[0xC];
}GTM_TOUT_SEL_t;

//void GTM_TOM_PWM_Init(GTM_TOM_Type GTM_TOMn, GTM_TOM_Channel_Type CHn, uint32_t freq, uint32_t duty);

void GTM_ATOM_PWM_Init(GTM_ATOM_Type GTM_ATOMn, GTM_ATOM_Channel_Type CHn, uint32_t freq, uint32_t duty);
FUNC(void, EDMA_CODE) GTM_ATOM4_3_IRQHandler(void);

//void GTM_TOM_PWM_OUTPUT(void);

void GTM_ATOM_PWM_OUTPUT(void);

void GTM_Demo(void);
#endif /* RESORUCE_SUPPORT_GTM410 */
#endif /* MOTOR_GTM4_H_ */

