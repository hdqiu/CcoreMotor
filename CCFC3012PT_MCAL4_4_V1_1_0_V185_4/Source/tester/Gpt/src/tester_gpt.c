#include "StandardTypes.h"
#include "tester_gpt.h"
#include "Gpt_cfg.h"
#include "shell.h"
#include "Gpt_Stm_LLDriver.h"
#include "Gpt_Rtc_LLDriver.h"
#include "Gpt_Irq.h"
#include "Gpt_AutoSar_Wrapper.h"
#include "console.h"
#include "SchM_Gpt.h"
#include <string.h>
#include "tester_canfd.h"
#include "motor_gtm4.h"
#include "tester_adc.h"
#include "Adc_Cfg.h"
#include "Pmsm_If.h"

static void RTC_SetupIrq(void);
GPT_CONFIG_DECLARATION
#define GPT_TEST_CASE_MAX 172
#define GPT_CHANNEL_ERGODIC 104

#define API_INT_NUM                              API_IRQn
#define RTC_INT_NUM                              RTC_IRQn


static const GptfuncMachine gpt_funcs[] = {
    {"GPT_0001", testgpt0001},
    {"GPT_0002", testgpt0002},
    {"GPT_0003", testgpt0003},
    {"GPT_0004", testgpt0004},
    {"GPT_0005", testgpt0005},
    {"GPT_0006", testgpt0006},
    {"GPT_0007", testgpt0007},
	{"GPT_0008", testgpt0008},
	{"GPT_0009", testgpt0009},
	{"GPT_0010", testgpt0010},
	{"GPT_0011", testgpt0011},
    {"GPT_0012", testgpt0012},
    {"GPT_0013", testgpt0013},
    {"GPT_0014", testgpt0014},
    {"GPT_0015", testgpt0015},
    {"GPT_0016", testgpt0016},
    {"GPT_0017", testgpt0017},
    {"GPT_0018", testgpt0018},
    {"GPT_0019", testgpt0019},
	{"GPT_0020", testgpt0020}
};

#define GPT_PIT_CON_INSTANCE		0
#define GPT_STM_CON_INSTANCE		1
#define GPT_GTM_CON_INSTANCE		2
#define GPT_STM_ONE_INSTANCE		3
#define GPT_GTM_ONE_INSTANCE		4
#define GPT_PIT_ONE_INSTANCE		5
#define GPT_RTI_ONE_INSTANCE		6

#define GPT_TOM_FXCLK0_INSTANCE		7
#define GPT_TOM_FXCLK1_INSTANCE		8
#define GPT_TOM_FXCLK2_INSTANCE		9
#define GPT_TOM_FXCLK3_INSTANCE		10
#define GPT_TOM_FXCLK4_INSTANCE		11
#define GPT_PIT_NONOTIFICATION_INSTANCE		12

#define GptChannel_PIT0CH0_Core0	0
#define GptChannel_STM1CH2_Core1 	1
#define GptChannel_GTM0CH2_Core2 	2
#define GptChannel_PIT0CH3_Core01 	3
#define GptChannel_PIT1CH0_Core2 	4
#define GptChannel_PITRTI_Core1 	5
#define GptChannel_GTM1CH2_Core0 	6
#define GptChannel_GTM3CH10_Core1 	7
#define GptChannel_STM0CH3_Core0 	8
#define GptChannel_STM2CH1_Core2 	9
#define GptChannel_RTCCore1 		10

#define GPT_RTC_CON_INSTANCE		13
#define GPT_RTC_ONE_INSTANCE		7

#define GPT_API_CON_INSTANCE		0
#define GPT_API_ONE_INSTANCE		0

#define GPT_MULTICORE_PIT_INSTANCE	0
#define GPT_MULTICORE_STM_INSTANCE	1
#define GPT_MULTICORE_GTM_INSTANCE	2
#define GPT_MULTICORE_RTC_INSTANCE	3
#define GPT_MULTICORE_INSTANCE		4

#define GptChannel_TimeCheck_GTM   11
#define GptChannel_TimeCheck_STM   12
#define GptChannel_TimeCheck_PIT   13

#define GPT_ERROR_INSTANCE 255

uint8 sgpt_init[GPT_MAX_PARTITION] = {0};
uint8 cnt = 0;
volatile uint32 pit_cnt = 0;
uint32 pit_oneshot_cnt = 0;
uint32 rti_oneshot_cnt = 0;
uint32 stm_cnt = 0;
uint32 stm_oneshot_cnt = 0;
uint32 gtm_oneshot_cnt = 0;
uint32 gtm_con_cnt = 0;
uint32 rtc_con_cnt = 0;
uint32 rtc_oneshot_cnt = 0;

uint32 gpt_ergodic_cnt = 0;
uint32 gpt_ergodic_continue_cnt = 0;
uint8 gpt_ergodic_continue_channel_cnt = 0;
uint8 gpt_ergodic_continue_flag = 0;

VAR(uint32, AUTOMATIC) CoreIndex;

static uint8 setIrqFlag[GPT_MAX_PARTITION] = {0};
volatile uint8 flag_2ms;
volatile uint8 flag_2ms_2;

volatile uint32 pit_total_cnt;

extern volatile uint8 initOk;
int16 speed_0 = 0;
int16 speed_1 = 0;
int16 speedTemp_0 = 0;
int16 speedTemp_1 = 0;
uint16 delaycoun_0 = 0;
uint16 delaycoun_1= 0;
struct state_params {
    int16 theta;
    int16 sin;
    int16 cos;
    int32_t  vd;          /* d轴电压 */
    int32_t  vq;          /* q轴电压 */
    int32_t  valpha;      /* alpha轴电压 */
    int32_t  vbeta;       /* beta轴电压 */
    int16_t  pwma;     /* A相PWM */
    int16_t  pwmb;     /* B相PWM */
    int16_t  pwmc;     /* C相PWM */
}gs_0,gs_1;
ADCSamp      ADCSampPare_0=ADCSamp_DEFAULTS;
ADCSamp      ADCSampPare_1=ADCSamp_DEFAULTS;
extern volatile uint32 cnt1_ATOM4;

volatile uint8 resolverInedex;

void Gpt_Pit_Cbk_Notification(void)
{
//    int32_t temp_int32;
    if(initOk == 0)
    {
    	return;
    }

	pit_total_cnt++;
   pit_cnt++;
   if(pit_cnt>=20)
   {
	   pit_cnt = 0;
	   flag_2ms = 1;
   }
}

void Gpt_RTI_OneShot_Cbk_Notification(void)
{
	rti_oneshot_cnt++;
    PSPRINTF("pit rti timer callback counter:%d\r\n", rti_oneshot_cnt);
}


void Gpt_Stm_Cbk_Notification(void)
{
   stm_cnt++;
//   PSPRINTF("stm timer callback counter:%d\r\n", stm_cnt);
}
#pragma GCC pop_options

volatile uint32 Stm_cnt = 0;
#pragma GCC push_options
//#pragma GCC optimize ("O0")
#pragma GCC diagnostic ignored "-Wmissing-declarations"
void Gpt_Pit_OneShot_Cbk_Notification(void)
{
	pit_oneshot_cnt++;
	if(pit_oneshot_cnt==10)
	{
	   flag_2ms_2 = 2;
	}
	else if(pit_oneshot_cnt>=20)
	{
	  pit_oneshot_cnt = 0;
	   flag_2ms_2 = 1;
	}

	if(initOk == 0)
	{
		return;
	}
}
#pragma GCC pop_options

void Gpt_Stm_OneShot_Cbk_Notification(void)
{

	stm_oneshot_cnt++;
	PSPRINTF("stm one-shot timer callback counter:%d\r\n", stm_oneshot_cnt);
}

void Gpt_Gtm_OneShot_Cbk_Notification(void)
{
	gtm_oneshot_cnt++;
	PSPRINTF("gtm one-shot timer callback counter:%d\r\n", gtm_oneshot_cnt);
}

void Gpt_Gtm_Con_Cbk_Notification(void)
{

	gtm_con_cnt++;
	PSPRINTF("gtm continuou timer callback counter:%d\r\n", gtm_con_cnt);
}

void Ergodic_Oneshot_Notification(void)
{
	PSPRINTF("Ergodic_Notification, gpt_ergodic_cnt:%d\r\n", gpt_ergodic_cnt);

	gpt_ergodic_cnt++;
}

void Gpt_Rtc_Cbk_Notification(void)
{
	rtc_con_cnt++;
	PSPRINTF("rtc timer callback counter:%d\r\n", rtc_con_cnt);
}

void Gpt_RTC_OneShot_Cbk_Notification(void)
{
	rtc_oneshot_cnt++;
	PSPRINTF("rtc timer callback counter:%d\r\n", rtc_oneshot_cnt);
}

void Gpt_Api_Continuous_Cbk_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("api timer callback counter:%d\r\n", cnt);

}

void Gpt_Api_OneShot_Cbk_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("api timer callback counter:%d\r\n", cnt);
}

void Ergodic_Continuous_Notification(void)
{
	static uint8 channel_cnt = 0;
	if(channel_cnt++ >= 2)
	{
		gpt_ergodic_continue_flag = 1;
		channel_cnt = 0;
		Gpt_StopTimer(gpt_ergodic_continue_channel_cnt);
	}

	PSPRINTF("Ergodic_Continuous_Notification, channel_cnt:%d\r\n", gpt_ergodic_continue_cnt);

	gpt_ergodic_continue_cnt++;
}

void Gpt_Gtm_FXCLK0_Cbk_Notification(void)
{
	PSPRINTF("gtm one-shot Gpt_Gtm_FXCLK0_Cbk_Notification callback \r\n");
}

void Gpt_Gtm_FXCLK1_Cbk_Notification(void)
{
	PSPRINTF("gtm one-shot Gpt_Gtm_FXCLK1_Cbk_Notification callback \r\n");
}

void Gpt_Gtm_FXCLK2_Cbk_Notification(void)
{
	PSPRINTF("gtm one-shot Gpt_Gtm_FXCLK2_Cbk_Notification callback \r\n");
}

void Gpt_Gtm_FXCLK3_Cbk_Notification(void)
{
	PSPRINTF("gtm one-shot Gpt_Gtm_FXCLK3_Cbk_Notification callback \r\n");
}

void Gpt_Gtm_FXCLK4_Cbk_Notification(void)
{
	PSPRINTF("gtm one-shot Gpt_Gtm_FXCLK4_Cbk_Notification callback \r\n");
}


void Gpt_MultiCore_Pit_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}
void Gpt_MultiCore_Stm1Ch2_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}
void Gpt_MultiCore_Gtm_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}

void Gpt_MultiCore_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}

void Gpt_MultiCore_Pit1Ch0_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}

void Gpt_MultiCore_Rti_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}

void Gpt_MultiCore_Stm0Ch3_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}

void Gpt_MultiCore_Stm2Ch1_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}

void Gpt_MultiCore_Gtm1Ch2_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}

void Gpt_MultiCore_Gtm3Ch10_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}

void Gpt_MultiCore_Rtc_Con_Notification(void)
{
	static uint32 cnt = 0;
	cnt++;
	PSPRINTF("%s is E_OK, Count:%d \r\n", __FUNCTION__, cnt);
}

void Gpt_TimeCheck_Gtm_Notification(void)
{
#ifdef RESOURCE_SUPPORT_SIUL2_IP
	SIUL2.GPDO[0U].R ^= 1U;  //  PA[0] toggle
#else
	SIUL.GPDO[0U].R ^= 1U;  //  PA[0] toggle
#endif
	Gpt_StartTimer(GptChannel_TimeCheck_GTM, 375);
}
void Gpt_TimeCheck_Stm_Notification(void)
{
#ifdef RESOURCE_SUPPORT_SIUL2_IP
	SIUL2.GPDO[1U].R ^= 1U;  //  PA[1] toggle
#else
	SIUL.GPDO[1U].R ^= 1U;  //  PA[1] toggle
#endif
	Gpt_StartTimer(GptChannel_TimeCheck_STM, 100);
}

void Gpt_TimeCheck_Pit_Notification(void)
{
#ifdef RESOURCE_SUPPORT_SIUL2_IP
	SIUL2.GPDO[2U].R ^= 1U;  //  PA[2] toggle
#else
	SIUL.GPDO[2U].R ^= 1U;  //  PA[2] toggle
#endif
	Gpt_StartTimer(GptChannel_TimeCheck_PIT, 100);
}


void gpt_stop_timer_all(void)
{
	uint8 i = 0;
	for(i=0; i<3;i++)
	{
		if (Gpt_GetChannelStatus(i) == 4) {// running
			Gpt_StopTimer(i); // stop timer, otherwise can't deinit
		}
	}
}
void gpt_init_test(void)
{
	if (sgpt_init[CoreIndex] == 0)
	{
		Gpt_Init(&GptChannelConfigSet);
		sgpt_init[CoreIndex] = 1;
	}
	else
	{
		gpt_stop_timer_all();
	}
}

void gpt_deinit_test(void)
{

    if (sgpt_init[CoreIndex] == 1){// if gpt init already, deinit for test
    	gpt_stop_timer_all();
#if (GPT_DEINIT_API == STD_ON)
		Gpt_DeInit();
#endif
		sgpt_init[CoreIndex] = 0;
	}
}

void testgpt0001(void)
{
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
	if (sgpt_init[CoreIndex] == 0){
		Gpt_Init(&GptChannelConfigSet);
		sgpt_init[CoreIndex] = 1;
	}
	Gpt_StartTimer(GPT_PIT_CON_INSTANCE, 1000*1000); //1000ms
	Gpt_EnableNotification(GPT_PIT_CON_INSTANCE);
#endif
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0002(void)
{
	Gpt_StopTimer(GPT_PIT_CON_INSTANCE); // stop
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0003(void)
{
	Gpt_StartTimer(GPT_PIT_CON_INSTANCE, 1000*1000); // 1000ms
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}


void testgpt0004(void)
{
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
	Gpt_SetMode(GPT_MODE_SLEEP);
#endif
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0005(void)
{
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
	Gpt_SetMode(GPT_MODE_NORMAL);
#endif
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0006(void)
{
	if (sgpt_init[CoreIndex] == 0){
		Gpt_Init(&GptChannelConfigSet);
		sgpt_init[CoreIndex] = 1;
	}
	Gpt_StartTimer(GPT_PIT_CON_INSTANCE, 2000*1000); // 2000ms
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
	Gpt_EnableNotification(GPT_PIT_CON_INSTANCE);
#endif
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
	Gpt_EnableWakeup(GPT_PIT_CON_INSTANCE);
#endif
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0007(void)
{
	gpt_init_test();

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
	Gpt_EnableNotification(GPT_STM_ONE_INSTANCE);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
	Gpt_SetMode(GPT_MODE_NORMAL);
#endif
	Gpt_StartTimer(GPT_STM_ONE_INSTANCE, 1000*1000); // 1000ms
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0008(void)
{
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
	gpt_init_test();

	Gpt_EnableNotification(GPT_STM_CON_INSTANCE);

	Gpt_StartTimer(GPT_STM_CON_INSTANCE, 1000*1000); // 1000ms

	Gpt_Stm_LLD_DelayMs(STM1, 50U);

	Gpt_DisableNotification(GPT_STM_CON_INSTANCE);

	Gpt_Stm_LLD_DelayMs(STM1, 50U);

	Gpt_EnableNotification(GPT_STM_CON_INSTANCE);
#endif
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0009(void)
{
	gpt_init_test();
	Gpt_StopTimer(GPT_STM_CON_INSTANCE);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0010(void)
{
	gpt_init_test();
	Gpt_StartTimer(GPT_STM_CON_INSTANCE, 1000*1000); // 1000ms
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0011(void)
{
	gpt_init_test();

	Gpt_StopTimer(GPT_GTM_CON_INSTANCE);

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
	Gpt_EnableWakeup(GPT_GTM_CON_INSTANCE);

#endif
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
	Gpt_EnableNotification(GPT_GTM_CON_INSTANCE);
#endif

	Gpt_StartTimer(GPT_GTM_CON_INSTANCE, 65534);

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
	Gpt_SetMode(GPT_MODE_SLEEP);
#endif
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0012(void)
{
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
	Gpt_DisableWakeup(GPT_GTM_CON_INSTANCE);
#endif
	PSPRINTF("%s is E_OK Gpt_DisableWakeup \r\n", __FUNCTION__);
}

void testgpt0013(void)
{
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
	Gpt_EnableWakeup(GPT_GTM_CON_INSTANCE);
#endif
	PSPRINTF("%s is E_OK Gpt_EnableWakeup \r\n", __FUNCTION__);
}

void testgpt0014(void)
{
	gpt_init_test();
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
	Gpt_EnableNotification(GPT_RTI_ONE_INSTANCE);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
	Gpt_SetMode(GPT_MODE_NORMAL);
#endif
	Gpt_StartTimer(GPT_RTI_ONE_INSTANCE, 1000*2000);

	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0015(void)
{
	gpt_init_test();
	Gpt_EnableNotification(GPT_RTC_CON_INSTANCE);
	Gpt_StartTimer(GPT_RTC_CON_INSTANCE, 500);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0016(void)
{
	Gpt_StopTimer(GPT_RTC_CON_INSTANCE);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0017(void)
{
	Gpt_StartTimer(GPT_RTC_CON_INSTANCE, 500);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0018(void)
{
	Gpt_DisableNotification(GPT_RTC_CON_INSTANCE);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0019(void)
{
	Gpt_EnableNotification(GPT_RTC_CON_INSTANCE);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void testgpt0020(void)
{
	gpt_init_test();
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
	Gpt_EnableNotification(GptChannel_TimeCheck_PIT);

#endif
	Gpt_StartTimer(GptChannel_TimeCheck_PIT, 500);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}


#if ( defined(CCFC3007PT) || defined(CCFC3008PT)||defined(CCFC3012PT))
FUNC(void, GPT_CODE) GPT_GTM_TOM_LLD_SetIRQ(void)
{
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_0_IRQn, &TOM0_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_0_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_0_IRQn, &TOM0_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_1_IRQn, &TOM0_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_1_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_1_IRQn, &TOM0_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_1_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_2_IRQn, &TOM0_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_2_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_2_IRQn, &TOM0_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_3_IRQn, &TOM0_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_3_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_3_IRQn, &TOM0_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_4_IRQn, &TOM0_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_4_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_4_IRQn, &TOM0_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_5_IRQn, &TOM0_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_5_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_5_IRQn, &TOM0_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_6_IRQn, &TOM0_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_6_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_6_IRQn, &TOM0_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_7_IRQn, &TOM0_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_7_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM0_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM0_7_IRQn, &TOM0_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM0_7_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_0_IRQn, &TOM1_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_0_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_0_IRQn, &TOM1_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_1_IRQn, &TOM1_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_1_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_1_IRQn, &TOM1_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_1_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_2_IRQn, &TOM1_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_2_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_2_IRQn, &TOM1_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_3_IRQn, &TOM1_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_3_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_3_IRQn, &TOM1_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_4_IRQn, &TOM1_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_4_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_4_IRQn, &TOM1_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_5_IRQn, &TOM1_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_5_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_5_IRQn, &TOM1_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_6_IRQn, &TOM1_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_6_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_6_IRQn, &TOM1_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_7_IRQn, &TOM1_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_7_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM1_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM1_7_IRQn, &TOM1_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM1_7_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_0_IRQn, &TOM2_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_0_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_0_IRQn, &TOM2_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_1_IRQn, &TOM2_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_1_IRQn);
	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_1_IRQn, &TOM2_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_1_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_2_IRQn, &TOM2_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_2_IRQn, &TOM2_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_3_IRQn, &TOM2_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_3_IRQn, &TOM2_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_4_IRQn, &TOM2_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_4_IRQn, &TOM2_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_5_IRQn, &TOM2_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_5_IRQn, &TOM2_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_6_IRQn, &TOM2_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_6_IRQn, &TOM2_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_7_IRQn, &TOM2_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_7_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM2_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM2_7_IRQn, &TOM2_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM2_7_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_0_IRQn, &TOM3_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_0_IRQn, &TOM3_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_1_IRQn, &TOM3_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_1_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_1_IRQn, &TOM3_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_1_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_2_IRQn, &TOM3_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_2_IRQn, &TOM3_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_3_IRQn, &TOM3_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_3_IRQn, &TOM3_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_4_IRQn, &TOM3_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_4_IRQn, &TOM3_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_5_IRQn, &TOM3_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_5_IRQn, &TOM3_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_6_IRQn, &TOM3_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_6_IRQn, &TOM3_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_7_IRQn, &TOM3_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_7_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM3_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM3_7_IRQn, &TOM3_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM3_7_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_0_IRQn, &TOM4_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_0_IRQn, &TOM4_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_1_IRQn, &TOM4_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_1_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_1_IRQn, &TOM4_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_1_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_2_IRQn, &TOM4_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_2_IRQn, &TOM4_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_3_IRQn, &TOM4_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_3_IRQn, &TOM4_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_4_IRQn, &TOM4_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_4_IRQn, &TOM4_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_5_IRQn, &TOM4_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_5_IRQn, &TOM4_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_6_IRQn, &TOM4_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_6_IRQn, &TOM4_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_7_IRQn, &TOM4_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_7_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM4_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM4_7_IRQn, &TOM4_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM4_7_IRQn);


	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_0_IRQn, &TOM5_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_0_IRQn, &TOM5_CH0_CH1_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_1_IRQn, &TOM5_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_1_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_1_IRQn, &TOM5_CH2_CH3_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_1_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_2_IRQn, &TOM5_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_2_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_2_IRQn, &TOM5_CH4_CH5_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_2_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_3_IRQn, &TOM5_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_3_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_3_IRQn, &TOM5_CH6_CH7_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_3_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_4_IRQn, &TOM5_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_4_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_4_IRQn, &TOM5_CH8_CH9_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_4_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_5_IRQn, &TOM5_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_5_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_5_IRQn, &TOM5_CH10_CH11_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_5_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_6_IRQn, &TOM5_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_6_IRQn, &TOM5_CH12_CH13_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_6_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_7_IRQn, &TOM5_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_7_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(GTM_TOM5_7_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(GTM_TOM5_7_IRQn, &TOM5_CH14_CH15_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(GTM_TOM5_7_IRQn);

}
#endif
FUNC(void, GPT_CODE) Gpt_Pit_SetIRQ(void)
{
//	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG0_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG0_IRQn, &PIT0_CH0_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG0_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG1_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG1_IRQn, &PIT0_CH1_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG1_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG2_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG2_IRQn, &PIT0_CH2_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG2_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG3_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG3_IRQn, &PIT0_CH3_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG3_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG4_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG4_IRQn, &PIT0_CH4_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG4_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG5_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG5_IRQn, &PIT0_CH5_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG5_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG6_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG6_IRQn, &PIT0_CH6_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG6_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG7_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG7_IRQn, &PIT0_CH7_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG7_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_RTI_TFLG_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_RTI_TFLG_IRQn, &RTI_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_RTI_TFLG_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(PIT_1_TFLG0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(PIT_1_TFLG0_IRQn, &PIT1_CH0_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(PIT_1_TFLG0_IRQn);

//	(void)INTC_LLD_Set_IRQ_Priority(PIT_1_TFLG1_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(PIT_1_TFLG1_IRQn, &PIT1_CH1_ISR);
//	(void)INTC_LLD_Set_IRQ_Enable(PIT_1_TFLG1_IRQn);
}
FUNC(void, GPT_CODE) Gpt_Pit2_SetIRQ(void)
{
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG0_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG0_IRQn, &PIT0_CH0_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG0_IRQn);
}
FUNC(void, GPT_CODE) Gpt_Pit0Ch6_SetIRQ(void)
{
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG6_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG6_IRQn, &PIT0_CH6_ISR);
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG6_IRQn);
}

FUNC(void, GPT_CODE) Gpt_Stm_SetIRQ(void)
{
//	(void)INTC_LLD_Set_IRQ_Priority(STM0_CH0_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM0_CH0_IRQn, &STM0_CH0_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM0_CH0_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM0_CH1_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM0_CH1_IRQn, &STM0_CH1_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM0_CH1_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM0_CH2_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM0_CH2_IRQn, &STM0_CH2_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM0_CH2_IRQn);
//
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM0_CH3_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM0_CH3_IRQn, &STM0_CH3_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM0_CH3_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM1_CH0_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM1_CH0_IRQn, &STM1_CH0_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM1_CH0_IRQn);

	(void)INTC_LLD_Set_IRQ_Priority(STM1_CH1_IRQn, INTR_PRI_38);
	(void)INTC_LLD_Set_IRQ_Handle(STM1_CH1_IRQn, &STM1_CH1_Handler);
	(void)INTC_LLD_Set_IRQ_Enable(STM1_CH1_IRQn);

//	(void)INTC_LLD_Set_IRQ_Priority(STM1_CH2_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM1_CH2_IRQn, &STM1_CH2_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM1_CH2_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM1_CH3_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM1_CH3_IRQn, &STM1_CH3_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM1_CH3_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM2_CH0_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM2_CH0_IRQn, &STM2_CH0_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM2_CH0_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM2_CH1_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM2_CH1_IRQn, &STM2_CH1_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM2_CH1_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM2_CH2_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM2_CH2_IRQn, &STM2_CH2_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM2_CH2_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM2_CH3_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM2_CH3_IRQn, &STM2_CH3_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM2_CH3_IRQn);
//
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM3_CH0_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM3_CH0_IRQn, &STM3_CH0_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM3_CH0_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM3_CH1_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM3_CH1_IRQn, &STM3_CH1_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM3_CH1_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM3_CH2_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM3_CH2_IRQn, &STM3_CH2_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM3_CH2_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM3_CH3_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM3_CH3_IRQn, &STM3_CH3_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM3_CH3_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM4_CH0_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM4_CH0_IRQn, &STM4_CH0_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM4_CH0_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM4_CH1_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM4_CH1_IRQn, &STM4_CH1_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM4_CH1_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM4_CH2_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM4_CH2_IRQn, &STM4_CH2_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM4_CH2_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM4_CH3_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM4_CH3_IRQn, &STM4_CH3_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM4_CH3_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM5_CH0_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM5_CH0_IRQn, &STM5_CH0_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM5_CH0_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM5_CH1_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM5_CH1_IRQn, &STM5_CH1_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM5_CH1_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM5_CH2_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM5_CH2_IRQn, &STM5_CH2_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM5_CH2_IRQn);
//
//	(void)INTC_LLD_Set_IRQ_Priority(STM5_CH3_IRQn, INTR_PRI_38);
//	(void)INTC_LLD_Set_IRQ_Handle(STM5_CH3_IRQn, &STM5_CH3_Handler);
//	(void)INTC_LLD_Set_IRQ_Enable(STM5_CH3_IRQn);
}

static void API_SetupIrq(void)
{
    (void)INTC_LLD_Set_IRQ_Priority(API_INT_NUM, INTR_PRI_38);
    (void)INTC_LLD_Set_IRQ_Handle(API_INT_NUM, &RTCAPI_LLD_APIIrqHandler);
    (void)INTC_LLD_Set_IRQ_Enable(API_INT_NUM);
}

static void RTC_SetupIrq(void)
{
    (void)INTC_LLD_Set_IRQ_Priority(RTC_INT_NUM, INTR_PRI_38);
    (void)INTC_LLD_Set_IRQ_Handle(RTC_INT_NUM, &RTCAPI_LLD_RTCIrqHandler);
    (void)INTC_LLD_Set_IRQ_Enable(RTC_INT_NUM);
}



int gpt_func(int argc, char *agrv[])
{
	CoreIndex = Gpt_GetCoreID();

	if(setIrqFlag[CoreIndex] == 0)
	{
		if(GPT_ENABLE_MULTICORE == STD_OFF)
		{
			Gpt_Stm_SetIRQ();
			Gpt_Pit_SetIRQ();
#if ( defined(CCFC3007PT) || defined(CCFC3008PT)||defined(CCFC3012PT))
			GPT_GTM_TOM_LLD_SetIRQ();
#endif
			RTC_SetupIrq();
			API_SetupIrq();
		}else
		{
			gpt_init_test();
		}
		setIrqFlag[CoreIndex] = 1;
	}

    if ((argc > 3) || (argc < 2)) {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\n");
    }
    else
    {
        if (argc == 2)
        {
            if (!strcmp(agrv[1], "help"))
            {
            	PSPRINTF("CCFC3007\n");
                PSPRINTF("[1 - %d] ----- CMD ------- ID of the test case\n", GPT_TEST_CASE_MAX);
            }
            else
            {
                uint32 id = (uint32)atoi(agrv[1]);
                PSPRINTF("%d\r\n", id);
                if ((id >= 1) && (id < GPT_TEST_CASE_MAX))
                {
                    if (gpt_funcs[id - 1].gptfunc != NULL_PTR)
                    {
                        gpt_funcs[id - 1].gptfunc();
                    }
                    else
                    {
                        PSPRINTF("error: The ID entered does not correspond to the test code\n");
                    }
                }
                else
                {
                    PSPRINTF("error: Input invalid parameters[%d], please output [1 - %d] range parameters\n", id, GPT_TEST_CASE_MAX);
                }
            }
        }
    }
	return 0;
}

#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), gpt_test, gpt_func, number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
