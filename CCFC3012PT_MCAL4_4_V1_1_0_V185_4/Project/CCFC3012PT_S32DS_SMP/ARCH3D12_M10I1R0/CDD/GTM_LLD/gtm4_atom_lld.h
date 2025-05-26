
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM ATOM low level drivers h file
* HISTORY     : Initial version
* @file     gtm4_atom_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
#ifndef GTM4_ATOM_LLD_H_
#define GTM4_ATOM_LLD_H_
#include "derivative.h"
#ifdef RESORUCE_SUPPORT_GTM410

 /*PRQA S 0654,0777,0779,3472 EOF*/
#include "status.h"
#include "gtm4_lld.h"

#define GTM4_ATOM_DET_ERR(x)                         DEV_ASSERT(x)

#ifdef RESORUCE_SUPPORT_GTM410_2CLS
#define GTM4_ATOM_INSTANCE_NUM                       (2U)
#endif
#ifdef RESORUCE_SUPPORT_GTM410_8CLS
#define GTM4_ATOM_INSTANCE_NUM                       (8U)
#endif

#define GTM4_ATOM_CHANNEL_NUM                        (8U)

#define GTM4_ATOM_AGC_GLB_CTRL_UPEN_CTRL0_OFF        (16u)
#define GTM4_ATOM_AGC_GLB_CTRL_RST_CH0_OFF           (8u)
#define GTM4_ATOM_AGC_FUPD_CTRL_RSTCN0_CH0_OFF       (16u)
#define GTM4_ATOM_AGC_FUPD_CTRL_FUPD_CTRL0_OFF       (0u)
#define GTM4_ATOM_AGC_INT_TRIG_INT_TRIG0_OFF         (0u)
#define GTM4_ATOM_AGC_ENDIS_CTRL_ENDIS_CTRL0_OFF     (0u)
#define GTM4_ATOM_AGC_ENDIS_STAT_ENDIS_STAT0_OFF     (0u)
#define GTM4_ATOM_AGC_OUTEN_CTRL_OUTEN_CTRL0_OFF     (0u)
#define GTM4_ATOM_AGC_OUTEN_STAT_OUTEN_STAT0_OFF     (0u)

typedef enum{
	GTM_ATOM0 = 0,
	GTM_ATOM1,
	GTM_ATOM2,
	GTM_ATOM3,
	GTM_ATOM4,
	GTM_ATOM5,
	GTM_ATOM6,
	GTM_ATOM7,
}GTM_ATOM_Type;


typedef enum{
	GTM_ATOM_CH0 = 0,
	GTM_ATOM_CH1,
	GTM_ATOM_CH2,
	GTM_ATOM_CH3,
	GTM_ATOM_CH4,
	GTM_ATOM_CH5,
	GTM_ATOM_CH6,
	GTM_ATOM_CH7
}GTM_ATOM_Channel_Type;

typedef enum{
	ATOM_TRIGOUT_X_1 = 0,
	ATOM_TRIGOUT_CCU0
}GTM_ATOM_TriggerOutput_Type;

typedef enum{
	ATOM_RST_CCU0_CM0 = 0,
	ATOM_RST_CCU0_TRIG
}GTM_ATOM_ResetSource_Type;

typedef enum{
	ATOM_CLK_SRC_CMU_CLK0 = 0,
	ATOM_CLK_SRC_CMU_CLK1,
	ATOM_CLK_SRC_CMU_CLK2,
	ATOM_CLK_SRC_CMU_CLK3,
	ATOM_CLK_SRC_CMU_CLK4,
	ATOM_CLK_SRC_CMU_CLK5,
	ATOM_CLK_SRC_CMU_CLK6,
	ATOM_CLK_SRC_CMU_CLK7,
	ATOM_CLK_SRC_NO_CMU_CLK
}GTM_ATOM_ClockSource_Type;

typedef enum{
	ATOM_SL_HIGH = 0,
	ATOM_SL_LOW
}GTM_ATOM_SignalLevel_Type;

typedef enum{
	ATOM_CMP_GreaterOrEqual  = 0,
	ATOM_CMP_LessOrEqual
}GTM_ATOM_CompareStrategy_Type;

typedef enum{
	ATOM_TB12_SELTS1 = 0,
	ATOM_TB12_SELTS2
}GTM_ATOM_TB12TimeBase_Type;

typedef enum{
	ATOM_MODE_SOMI = 0,
	ATOM_MODE_SOMC,
	ATOM_MODE_SOMP,
	ATOM_MODE_SOMS
}GTM_ATOM_Mode_Type;

typedef enum{
	ATOM_TBU_TS0 = 0,
	ATOM_TBU_TS1,
	ATOM_TBU_TS2,
	ATOM_TBU_TS3
}GTM_ATOM_TimeBase_Type;

typedef enum{
	ATOM_IRQ_CCU0TC = 0,
	ATOM_IRQ_CCU1TC
}GTM_ATOM_Interrupt_Type;


status_t GTM_ATOM_LLD_Channel_SetReadAddress_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint16_t ReadAddress0,uint16_t ReadAddress1);

status_t GTM_ATOM_LLD_Channel_IsEnableARUBlockMode_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_IsEnableOneShotMode_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_SelectTriggerOutput_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_TriggerOutput_Type TriggerOutput);

status_t GTM_ATOM_LLD_Channel_SelectCCU0ResetSource_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_ResetSource_Type ResetSource);

status_t GTM_ATOM_LLD_Channel_SelectClockSource_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_ClockSource_Type ClockSource);

GTM_ATOM_ClockSource_Type GTM_ATOM_LLD_Channel_GetClockSource_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn);

status_t GTM_ATOM_LLD_Channel_SelectSignalLevel_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_SignalLevel_Type SignalLevel);

status_t GTM_ATOM_LLD_Channel_SelectCompareStrategy_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_CompareStrategy_Type CompareStrategy);

status_t GTM_ATOM_LLD_Channel_SetACBbits_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint8_t ACBbits);

status_t GTM_ATOM_LLD_Channel_IsEnableARU_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_SelectTB12TimeBase_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_TB12TimeBase_Type TimeBase);

status_t GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Mode_Type Mode);

status_t GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint32_t SR0,uint32_t SR1);

status_t GTM_ATOM_LLD_Channel_SetCompareRegister_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint32_t CM0,uint32_t CM1);

status_t GTM_ATOM_LLD_Channel_SetCounter_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,uint32_t CN0);

uint8_t GTM_ATOM_LLD_Channel_GetOutputLevel_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn);

uint8_t GTM_ATOM_LLD_Channel_GetInterruptFlag_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Interrupt_Type Interrupt);

status_t GTM_ATOM_LLD_Channel_ClearInterruptFlag_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Interrupt_Type Interrupt);

status_t GTM_ATOM_LLD_Channel_IsEnableInterrupt_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Interrupt_Type Interrupt,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_ForceInterrupt_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_ATOM_Interrupt_Type Interrupt);

status_t GTM_ATOM_LLD_Channel_SelectInterruptMode_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_InterruptMode_Type InterruptMode);

status_t GTM_ATOM_LLD_Channel_IsEnableUpdate_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_ResetChannel_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn);

status_t GTM_ATOM_LLD_AGC_HostTrigger_lld(GTM_ATOM_Type GTM_ATOMn);

status_t GTM_ATOM_LLD_AGC_SelectTimeBase_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_TimeBase_Type TimeBase);

status_t GTM_ATOM_LLD_AGC_SetActionTime_lld(GTM_ATOM_Type GTM_ATOMn,uint32_t ActionTime);

status_t GTM_ATOM_LLD_Channel_IsEnableForceUpdateCN0Reset_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_IsEnableForceUpdate_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_IsEnableInternalTrigger_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_IsEnableUpdateValue_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

boolean GTM_ATOM_LLD_IsEnableChannel_lld(GTM_ATOM_Type GTM_ATOMn);

status_t GTM_ATOM_LLD_Channel_IsEnableChannel_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_IsEnableOutUpdateValue_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_ATOM_LLD_Channel_IsEnableOut_lld(GTM_ATOM_Type GTM_ATOMn,GTM_ATOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);
#endif /* RESORUCE_SUPPORT_GTM410 */
#endif /* GTM4_ATOM_LLD_H_ */

