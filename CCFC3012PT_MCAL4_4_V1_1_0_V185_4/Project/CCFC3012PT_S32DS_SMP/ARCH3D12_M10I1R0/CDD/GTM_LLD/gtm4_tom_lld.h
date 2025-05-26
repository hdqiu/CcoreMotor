
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM TOM low level drivers h file
* HISTORY     : Initial version
* @file     gtm_tom_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0777,0779,3472 EOF*/
#ifndef GTM4_TOM_LLD_H_
#define GTM4_TOM_LLD_H_
#include "derivative.h"
#ifdef RESORUCE_SUPPORT_GTM410

#include "status.h"
#include "gtm4_lld.h"

#define GTM4_TOM_DET_ERR(x)                         DEV_ASSERT(x)

#ifdef RESORUCE_SUPPORT_GTM410_2CLS
#define GTM4_TOM_INSTANCE_NUM                       (2U)
#endif
#ifdef RESORUCE_SUPPORT_GTM410_8CLS
#define GTM4_TOM_INSTANCE_NUM                       (6U)
#endif

#define GTM4_TOM_CHANNEL_NUM                        (16U)

#define GTM4_TOM_TGC_GLB_CTRL_UPEN_CTRL0_OFF        (16u)
#define GTM4_TOM_TGC_GLB_CTRL_RST_CH0_OFF           (8u)
#define GTM4_TOM_TGC_FUPD_CTRL_RSTCN0_CH0_OFF       (16u)
#define GTM4_TOM_TGC_FUPD_CTRL_FUPD_CTRL0_OFF       (0u)
#define GTM4_TOM_TGC_INT_TRIG_INT_TRIG0_OFF         (0u)
#define GTM4_TOM_TGC_ENDIS_CTRL_ENDIS_CTRL0_OFF     (0u)
#define GTM4_TOM_TGC_ENDIS_STAT_ENDIS_STAT0_OFF     (0u)
#define GTM4_TOM_TGC_OUTEN_CTRL_OUTEN_CTRL0_OFF     (0u)
#define GTM4_TOM_TGC_OUTEN_STAT_OUTEN_STAT0_OFF     (0u)

typedef enum{
	GTM_TOM0 = 0,
	GTM_TOM1,
	GTM_TOM2,
	GTM_TOM3,
	GTM_TOM4,
	GTM_TOM5
}GTM_TOM_Type;


typedef enum{
	GTM_TOM_CH0 = 0,
	GTM_TOM_CH1,
	GTM_TOM_CH2,
	GTM_TOM_CH3,
	GTM_TOM_CH4,
	GTM_TOM_CH5,
	GTM_TOM_CH6,
	GTM_TOM_CH7,
	GTM_TOM_CH8,
	GTM_TOM_CH9,
	GTM_TOM_CH10,
	GTM_TOM_CH11,
	GTM_TOM_CH12,
	GTM_TOM_CH13,
	GTM_TOM_CH14,
	GTM_TOM_CH15
}GTM_TOM_Channel_Type;

typedef enum{
	TOM_TRIGOUT_X_1 = 0,
	TOM_TRIGOUT_CCU0
}GTM_TOM_TriggerOutput_Type;

typedef enum{
	TOM_RST_CCU0_CM0 = 0,
	TOM_RST_CCU0_TRIG
}GTM_TOM_CCU0ResetSource_Type;

typedef enum{
	TOM_CLK_SRC_CMU_FXCLK0 = 0,
	TOM_CLK_SRC_CMU_FXCLK1,
	TOM_CLK_SRC_CMU_FXCLK2,
	TOM_CLK_SRC_CMU_FXCLK3,
	TOM_CLK_SRC_CMU_FXCLK4,
	TOM_CLK_SRC_NO_CMU_FXCLK,
	TOM_CLK_SRC_RESOLUTION_0 = 12,
	TOM_CH_TRIGOUT_X_1,
	TOM_EXIT_TRIGIN_X
}GTM_TOM_ClockSource_Type;

typedef enum{
	TOM_SL_HIGH = 0,
	TOM_SL_LOW
}GTM_TOM_SignalLevel_Type;

typedef enum{
	TOM_TBU_TS0 = 0,
	TOM_TBU_TS1,
	TOM_TBU_TS2,
	TOM_TBU_TS3
}GTM_TOM_TimeBase_Type;

typedef enum{
	TOM_IRQ_CCU0TC = 0,
	TOM_IRQ_CCU1TC
}GTM_TOM_Interrupt_Type;


status_t GTM_TOM_LLD_Channel_IsEnableGatedCounterMode_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_IsEnableSPEMode_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_IsEnableOneShotMode_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_SelectTriggerOutput_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_TriggerOutput_Type TriggerOutput);

status_t GTM_TOM_LLD_Channel_SelectCCU0ResetSource_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_CCU0ResetSource_Type CCU0ResetSource);

status_t GTM_TOM_LLD_Channel_SelectClockSource_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_ClockSource_Type ClockSource);

GTM_TOM_ClockSource_Type GTM_TOM_LLD_Channel_GetClockSource_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn);

status_t GTM_TOM_LLD_Channel_SelectSignalLevel_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_SignalLevel_Type SignalLevel);

status_t GTM_TOM_LLD_Channel_SetShadowRegister_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,uint16_t SR0,uint16_t SR1);

status_t GTM_TOM_LLD_Channel_SetCompareRegister_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,uint16_t CM0,uint16_t CM1);

status_t GTM_TOM_LLD_Channel_SetCounter_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,uint16_t CN0);

uint16_t GTM_TOM_LLD_Channel_GetCounter_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn);

uint8_t GTM_TOM_LLD_Channel_GetOutputLevel_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn);

uint8_t GTM_TOM_LLD_Channel_GetInterruptFlag_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_Interrupt_Type Interrupt);

status_t GTM_TOM_LLD_Channel_ClearInterruptFlag_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_Interrupt_Type Interrupt);

status_t GTM_TOM_LLD_Channel_IsEnableInterrupt_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_Interrupt_Type Interrupt,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_ForceInterrupt_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_TOM_Interrupt_Type Interrupt);

status_t GTM_TOM_LLD_Channel_SelectInterruptMode_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_InterruptMode_Type InterruptMode);

status_t GTM_TOM_LLD_Channel_IsEnableUpdate_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_ResetChannel_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn);

status_t GTM_TOM_LLD_TGC0_HostTrigger_lld(GTM_TOM_Type GTM_TOMn);

status_t GTM_TOM_LLD_TGC1_HostTrigger_lld(GTM_TOM_Type GTM_TOMn);

status_t GTM_TOM_LLD_TGC0_SelectTimeBase_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_TimeBase_Type TimeBase);

status_t GTM_TOM_LLD_TGC1_SelectTimeBase_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_TimeBase_Type TimeBase);

status_t GTM_TOM_LLD_TGC0_SetActionTime_lld(GTM_TOM_Type GTM_TOMn,uint32_t ActionTime);

status_t GTM_TOM_LLD_TGC1_SetActionTime_lld(GTM_TOM_Type GTM_TOMn,uint32_t ActionTime);

status_t GTM_TOM_LLD_Channel_IsEnableForceUpdateCN0Reset_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_IsEnableForceUpdate_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_IsEnableInternalTrigger_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_IsEnableUpdateValue_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_IsEnableChannel_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_IsEnableOutUpdateValue_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

status_t GTM_TOM_LLD_Channel_IsEnableOut_lld(GTM_TOM_Type GTM_TOMn,GTM_TOM_Channel_Type CHn,GTM_IsEnable_Type IsEnable);

#endif /* RESORUCE_SUPPORT_GTM410 */
#endif /* GTM4_TOM_LLD_H_ */

