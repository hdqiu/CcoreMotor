/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3008PT
* DESCRIPTION : CCFC3008PT GTM CMU low level drivers code
* HISTORY     : Initial version
* @file     gtm_cmu_lld.c
* @version  1.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0380,1296,1317,1503,1338,1881,2016,2023,2024 EOF*/

#include "gtm4_cmu_lld.h"
#ifdef RESORUCE_SUPPORT_GTM410
/*
 * @brief Enable clock.
 *
 * @param[in] Clock Clock.
 * @param[in] IsEnable Enable state.
 *
 * @return Operation status
 */
status_t GTM_CMU_LLD_IsEnableClock(GTM_CMU_Clock_Type Clock,GTM_IsEnable_Type IsEnable)
{
	if(IsEnable  == 1)
	{
		IsEnable = 2;
	}
	else
	{
		IsEnable = 1;
	}

	switch(Clock)
	{
		case GTM4_CMU_CLK0:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK0 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK0 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK1:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK1 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK1 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK2:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK2 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK2 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK3:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK3 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK3 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK4:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK4 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK4 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK5:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK5 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK5 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK6:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK6 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK6 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK7:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK7 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK7 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_ECLK0:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_ECLK0 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_ECLK0 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_ECLK1:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_ECLK1 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_ECLK1 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_ECLK2:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_ECLK2 = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_ECLK2 != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_FXCLK:
		    GTM4.GLS[0].CMU.CLK_EN.B.EN_FXCLK = (uint8_t)IsEnable;
			if(GTM4.GLS[0].CMU.CLK_EN.B.EN_FXCLK != ((IsEnable == 1)?(0u):(3u)))
			{
				return STATUS_ERROR;
			}
		break;
		default:
			return STATUS_ERROR;
	}

//	switch(Clock)
//	{
//		case CMU_CLK0:
//			GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK0 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK0 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK1:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK1 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK1 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK2:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK2 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK2 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK3:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK3 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK3 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK4:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK4 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK4 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK5:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK5 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK5 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK6:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK6 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK6 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK7:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK7 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_CLK7 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_ECLK0:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_ECLK0 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_ECLK0 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_ECLK1:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_ECLK1 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_ECLK1 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_ECLK2:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_ECLK2 = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_ECLK2 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_FXCLK:
//		    GTM4.GLS[5].CMU.CLK_EN.B.EN_FXCLK = (uint8_t)IsEnable;
//			if(GTM4.GLS[5].CMU.CLK_EN.B.EN_FXCLK != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		default:
//			return STATUS_ERROR;
//	}
//	switch(Clock)
//	{
//		case CMU_CLK0:
//			GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK0 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK0 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK1:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK1 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK1 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK2:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK2 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK2 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK3:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK3 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK3 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK4:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK4 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK4 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK5:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK5 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK5 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK6:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK6 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK6 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_CLK7:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK7 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_CLK7 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_ECLK0:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_ECLK0 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_ECLK0 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_ECLK1:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_ECLK1 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_ECLK1 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_ECLK2:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_ECLK2 = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_ECLK2 != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		case CMU_FXCLK:
//		    GTM4.GLS[4].CMU.CLK_EN.B.EN_FXCLK = (uint8_t)IsEnable;
//			if(GTM4.GLS[4].CMU.CLK_EN.B.EN_FXCLK != ((IsEnable == 1)?(0u):(3u)))
//			{
//				return STATUS_ERROR;
//			}
//		break;
//		default:
//			return STATUS_ERROR;
//	}

	return STATUS_SUCCESS;
}

/*
 * @brief Numerator for global clock divider.
 *
 * @param[in] Numerator Defines numerator of the fractional divider.
 *
 * @return Operation status
 */
status_t GTM_CMU_LLD_SetGlobalClockNumerator(uint32_t Numerator)
{
	/*Value can only be modified when all clock enables EN_CLK[n] and the EN_FXCLK are disabled.*/
	if(GTM4.GLS[0].CMU.CLK_EN.R != 0u)
	{
		return STATUS_ERROR;
	}

	GTM4.GLS[0].CMU.GCLK_NUM.B.GCLK_NUM = Numerator;
	if(GTM4.GLS[0].CMU.GCLK_NUM.B.GCLK_NUM != Numerator)
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief GET Numerator for global clock divider.
 *
 * @param[in] None
 *
 * @return Numerator for global clock divider
 */
uint32_t GTM_CMU_LLD_GetGlobalClockNumerator(void)
{
	return (uint32_t)(GTM4.GLS[0].CMU.GCLK_NUM.B.GCLK_NUM);
}

/*
 * @brief Denominator for global clock divider.
 *
 * @param[in] Denominator Defines denominator of the fractional divider.
 *
 * @return Operation status
 */
status_t GTM_CMU_LLD_SetGlobalClockDenominator(uint32_t Denominator)
{
	/*Value can only be modified when all clock enables EN_CLK[n] and the EN_FXCLK are disabled.*/
	if(GTM4.GLS[0].CMU.CLK_EN.R != 0u)
	{
		return STATUS_ERROR;
	}

	GTM4.GLS[0].CMU.GCLK_DEN.B.GCLK_DEN = Denominator;
	if(GTM4.GLS[0].CMU.GCLK_DEN.B.GCLK_DEN != Denominator)
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief GET Denominator for global clock divider.
 *
 * @param[in] None.
 *
 * @return Denominator for global clock divider
 */
uint32_t GTM_CMU_LLD_GetGlobalClockDenominator(void)
{
	return (uint32_t)(GTM4.GLS[0].CMU.GCLK_DEN.B.GCLK_DEN);
}
/*
 * @brief Defines count value for the clock divider of clock source CMU_CLK[0:7].
 *
 * @param[in] Clock Clock.
 * @param[in] Count Clock count.
 *
 * @return Operation status
 */
status_t GTM_CMU_LLD_SetClockCount(GTM_CMU_Clock_Type Clock,uint32_t Count)
{
	/*Value can only be modified when corresponding clock enable EN_CLK[0:7] is disabled.*/
	if((GTM4.GLS[0].CMU.CLK_EN.R & (uint32_t)0xFFFF) != 0u)
	{
		return STATUS_ERROR;
	}

	switch(Clock)
	{
		case GTM4_CMU_CLK0:
		    GTM4.GLS[0].CMU.CLK[0].CTRL.B.CLK_CNT = Count;
			if(GTM4.GLS[0].CMU.CLK[0].CTRL.B.CLK_CNT != Count)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK1:
		    GTM4.GLS[0].CMU.CLK[1].CTRL.B.CLK_CNT = Count;
			if(GTM4.GLS[0].CMU.CLK[1].CTRL.B.CLK_CNT != Count)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK2:
		    GTM4.GLS[0].CMU.CLK[2].CTRL.B.CLK_CNT = Count;
			if(GTM4.GLS[0].CMU.CLK[2].CTRL.B.CLK_CNT != Count)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK3:
		    GTM4.GLS[0].CMU.CLK[3].CTRL.B.CLK_CNT = Count;
			if(GTM4.GLS[0].CMU.CLK[3].CTRL.B.CLK_CNT != Count)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK4:
		    GTM4.GLS[0].CMU.CLK[4].CTRL.B.CLK_CNT = Count;
			if(GTM4.GLS[0].CMU.CLK[4].CTRL.B.CLK_CNT != Count)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK5:
		    GTM4.GLS[0].CMU.CLK[5].CTRL.B.CLK_CNT = Count;
			if(GTM4.GLS[0].CMU.CLK[5].CTRL.B.CLK_CNT != Count)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK6:
		    GTM4.GLS[0].CMU.CLK_6.B.CLK_CNT = Count;
			if(GTM4.GLS[0].CMU.CLK_6.B.CLK_CNT != Count)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_CLK7:
		    GTM4.GLS[0].CMU.CLK_7.B.CLK_CNT = Count;
			if(GTM4.GLS[0].CMU.CLK_7.B.CLK_CNT != Count)
			{
				return STATUS_ERROR;
			}
		break;
		default:
			return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief GET count value for the clock divider of clock source CMU_CLK[0:7].
 *
 * @param[in] Clock Clock.
 * @return Count
 */
uint32_t GTM_CMU_LLD_GetClockCount(GTM_CMU_Clock_Type Clock)
{
	switch(Clock)
	{
		case GTM4_CMU_CLK0:
			return GTM4.GLS[0].CMU.CLK[0].CTRL.B.CLK_CNT;

		case GTM4_CMU_CLK1:
			return GTM4.GLS[0].CMU.CLK[1].CTRL.B.CLK_CNT;

		case GTM4_CMU_CLK2:
			return GTM4.GLS[0].CMU.CLK[2].CTRL.B.CLK_CNT;

		case GTM4_CMU_CLK3:
			return GTM4.GLS[0].CMU.CLK[3].CTRL.B.CLK_CNT;

		case GTM4_CMU_CLK4:
			return GTM4.GLS[0].CMU.CLK[4].CTRL.B.CLK_CNT;

		case GTM4_CMU_CLK5:
			return GTM4.GLS[0].CMU.CLK[5].CTRL.B.CLK_CNT;

		case GTM4_CMU_CLK6:
			return GTM4.GLS[0].CMU.CLK_6.B.CLK_CNT;

		case GTM4_CMU_CLK7:
			return GTM4.GLS[0].CMU.CLK_7.B.CLK_CNT;

		default:
			return STATUS_ERROR;		 /*PRQA S  4424*/

	}
}

/*
 * @brief Clock source selection for CMU_CLK6.
 *
 * @param[in] Clock6Source Clock source selection for CMU_CLK6.
 *
 * @return Operation status
 */
status_t GTM_CMU_LLD_SelectClock6Source(GTM_CMU_Clock67Source_Type Clock6Source)
{
	/*Value can be modified only when EN_CLK6 is disabled.*/
	if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK6 != 0u)
	{
		return STATUS_ERROR;
	}

	GTM4.GLS[0].CMU.CLK_6.B.CLK_SEL = (uint8_t)Clock6Source;
	if(GTM4.GLS[0].CMU.CLK_6.B.CLK_SEL != Clock6Source)
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief Clock source selection for CMU_CLK7.
 *
 * @param[in] Clock7Source Clock source selection for CMU_CLK7.
 *
 * @return Operation status
 */
status_t GTM_CMU_LLD_SelectClock7Source(GTM_CMU_Clock67Source_Type Clock7Source)
{
	/*Value can be modified only when EN_CLK7 is disabled.*/
	if(GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK7 != 0u)
	{
		return STATUS_ERROR;
	}

	GTM4.GLS[0].CMU.CLK_7.B.CLK_SEL = (uint8_t)Clock7Source;
	if(GTM4.GLS[0].CMU.CLK_7.B.CLK_SEL != Clock7Source)
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief Numerator for external clock divider.
 *
 * @param[in] Clock External Clock.
 * @param[in] Numerator Defines numerator of the fractional divider.
 *
 * @return Operation status
 */
status_t GTM_CMU_LLD_SetEclockNumerator(GTM_CMU_Clock_Type Clock,uint32_t Numerator)
{
	/*Value can only be modified when corresponding clock enable EN_ECLK[n] is disabled.*/
	if((GTM4.GLS[0].CMU.CLK_EN.R & (uint32_t)0x003F0000) != 0u)
	{
		return STATUS_ERROR;
	}

	switch(Clock)
	{
		case GTM4_CMU_ECLK0:
		    GTM4.GLS[0].CMU.ECLK[0].NUM.B.ECLK_NUM = Numerator;
			if(GTM4.GLS[0].CMU.ECLK[0].NUM.B.ECLK_NUM != Numerator)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_ECLK1:
		    GTM4.GLS[0].CMU.ECLK[1].NUM.B.ECLK_NUM = Numerator;
			if(GTM4.GLS[0].CMU.ECLK[1].NUM.B.ECLK_NUM != Numerator)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_ECLK2:
		    GTM4.GLS[0].CMU.ECLK[2].NUM.B.ECLK_NUM = Numerator;
			if(GTM4.GLS[0].CMU.ECLK[2].NUM.B.ECLK_NUM != Numerator)
			{
				return STATUS_ERROR;
			}
		break;
		default:
			return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief Denominator for external clock divider.
 *
 * @param[in] Clock External Clock.
 * @param[in] Denominator Defines numerator of the fractional divider.
 *
 * @return Operation status
 */
status_t GTM_CMU_LLD_SetEclockDenominator(GTM_CMU_Clock_Type Clock,uint32_t Denominator)
{
	/*Value can only be modified when corresponding clock enable EN_ECLK[n] is disabled.*/
	if((GTM4.GLS[0].CMU.CLK_EN.R & (uint32_t)0x003F0000) != 0u)
	{
		return STATUS_ERROR;
	}

	switch(Clock)
	{
		case GTM4_CMU_ECLK0:
		    GTM4.GLS[0].CMU.ECLK[0].DEN.B.ECLK_DEN = Denominator;
			if(GTM4.GLS[0].CMU.ECLK[0].DEN.B.ECLK_DEN != Denominator)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_ECLK1:
		    GTM4.GLS[0].CMU.ECLK[1].DEN.B.ECLK_DEN = Denominator;
			if(GTM4.GLS[0].CMU.ECLK[1].DEN.B.ECLK_DEN != Denominator)
			{
				return STATUS_ERROR;
			}
		break;
		case GTM4_CMU_ECLK2:
		    GTM4.GLS[0].CMU.ECLK[2].DEN.B.ECLK_DEN = Denominator;
			if(GTM4.GLS[0].CMU.ECLK[2].DEN.B.ECLK_DEN != Denominator)
			{
				return STATUS_ERROR;
			}
		break;
		default:
			return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief Input clock selection for EN_FXCLK line.
 *
 * @param[in] FXCLKSource FXCLK clock source.
 *
 * @return Operation status
 */
status_t GTM_CMU_LLD_SelectFXCLKSource(GTM_CMU_FXCLKSource_Type FXCLKSource)
{
	/*This value can only be written, when the CMU_FXCLK generation is disabled. */
	if(GTM4.GLS[0].CMU.CLK_EN.B.EN_FXCLK != 0u)
	{
		return STATUS_ERROR;
	}

	GTM4.GLS[0].CMU.FXCLK.CTRL.B.FXCLK_SEL = (uint8_t)FXCLKSource;
	if(GTM4.GLS[0].CMU.FXCLK.CTRL.B.FXCLK_SEL != FXCLKSource)
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}
#endif /* RESORUCE_SUPPORT_GTM410 */
