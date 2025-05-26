
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM CMU low level drivers h file
* HISTORY     : Initial version
* @file     gtm4_cmu_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
#ifndef GTM4_CMU_LLD_H_
#define GTM4_CMU_LLD_H_
#include "derivative.h"
#ifdef RESORUCE_SUPPORT_GTM410

#include "status.h"
#include "gtm4_lld.h"
#include "Gpt_GTM410_LLDriver.h"

typedef enum{
	GTM4_CMU_CLK0 = 0,
	GTM4_CMU_CLK1,
	GTM4_CMU_CLK2,
	GTM4_CMU_CLK3,
	GTM4_CMU_CLK4,
	GTM4_CMU_CLK5,
	GTM4_CMU_CLK6,
	GTM4_CMU_CLK7,
	GTM4_CMU_ECLK0,
	GTM4_CMU_ECLK1,
	GTM4_CMU_ECLK2,
	GTM4_CMU_FXCLK
}GTM_CMU_Clock_Type;

typedef enum{
	CLK_SEL_Clock67 = 0,
	CLK_SEL_SUB_INC2,
}GTM_CMU_Clock67Source_Type;

//typedef enum{
//	CMU_FXCLKSource_GCLK = 0,
//	CMU_FXCLKSource_CLK0,
//	CMU_FXCLKSource_CLK1,
//	CMU_FXCLKSource_CLK2,
//	CMU_FXCLKSource_CLK3,
//	CMU_FXCLKSource_CLK4,
//	CMU_FXCLKSource_CLK5,
//	CMU_FXCLKSource_CLK6,
//	CMU_FXCLKSource_CLK7
//}GTM_CMU_FXCLKSource_Type;


status_t GTM_CMU_LLD_IsEnableClock(GTM_CMU_Clock_Type Clock,GTM_IsEnable_Type IsEnable);

status_t GTM_CMU_LLD_SetGlobalClockNumerator(uint32_t Numerator);

uint32_t GTM_CMU_LLD_GetGlobalClockNumerator(void);

status_t GTM_CMU_LLD_SetGlobalClockDenominator(uint32_t Denominator);

uint32_t GTM_CMU_LLD_GetGlobalClockDenominator(void);

status_t GTM_CMU_LLD_SetClockCount(GTM_CMU_Clock_Type Clock,uint32_t Count);

uint32_t GTM_CMU_LLD_GetClockCount(GTM_CMU_Clock_Type Clock);

status_t GTM_CMU_LLD_SelectClock6Source(GTM_CMU_Clock67Source_Type Clock6Source);

status_t GTM_CMU_LLD_SelectClock7Source(GTM_CMU_Clock67Source_Type Clock7Source);

status_t GTM_CMU_LLD_SetEclockNumerator(GTM_CMU_Clock_Type Clock,uint32_t Numerator);

status_t GTM_CMU_LLD_SetEclockDenominator(GTM_CMU_Clock_Type Clock,uint32_t Denominator);

status_t GTM_CMU_LLD_SelectFXCLKSource(GTM_CMU_FXCLKSource_Type FXCLKSource);

#endif /* RESORUCE_SUPPORT_GTM410 */
#endif /* GTM4_CMU_LLD_H_ */
