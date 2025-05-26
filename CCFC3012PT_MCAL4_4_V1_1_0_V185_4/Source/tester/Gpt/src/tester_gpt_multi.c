/*
 * tester_gpt_multi.c
 *
 *  Created on: 2024��1��17��
 *      Author: pc
 */

#include "tester_gpt_multi.h"
#include "StandardTypes.h"
#include "tester_gpt.h"
#include "Gpt_cfg.h"
#include "shell.h"
#include "Gpt_Stm_LLDriver.h"
#include "Gpt_Irq.h"
#include "Gpt_AUtoSAR_Wrapper.h"
#include "Spi_Test.h"
#include "tester_adc.h"
#include "tester_lin.h"
#include "tester_dio.h"

#define GPT_PIT_CON_10MS_INSTANCE 0
#define GPT_PIT_CON_20MS_INSTANCE 1
#define GPT_PIT_CON_30MS_INSTANCE 2

boolean TesterDemoADC = false;
boolean TesterDemoCAN = false;
boolean TesterDemoFEE = false;
boolean TesterDemoFLS = false;
boolean TesterDemoICU = false;
boolean TesterDemoLIN = false;
boolean TesterDemoPORT = false;
boolean TesterDemoPWM = false;
boolean TesterDemoSPI = false;
boolean TesterDemoWDG = false;
boolean TesterDemoDIO = false;

void Gpt_Pit_10ms_Cbk_Notification(void)
{
	if(TesterDemoADC == true)
	{
		static uint32 adc_runcount = 0;
		ADC_GPT_Callback_10ms_Function();
		adc_runcount++;
		if(adc_runcount >= 270U)
		{
			TesterDemoADC = false;
			adc_runcount = 0;
#if (ADC_DEINIT_API == STD_ON)
			Adc_DeInit();
#endif
		}
		//PSPRINTF("adc 10ms\r\n");
	}
	if(TesterDemoCAN == true)
	{
		PSPRINTF("can 10ms\r\n");
	}
	if(TesterDemoFEE == true)
	{
		PSPRINTF("fee 10ms\r\n");
	}
	if(TesterDemoFLS == true)
	{
		PSPRINTF("fls 10ms\r\n");
	}
	if(TesterDemoICU == true)
	{

		//PSPRINTF("icu 10ms\r\n");
	}
	if(TesterDemoLIN == true)
	{
		//LIN_GPT_Callback_10ms_Function();
		//PSPRINTF("lin 10ms\r\n");
	}
	if(TesterDemoPORT == true)
	{
		PSPRINTF("port 10ms\r\n");
	}
	if(TesterDemoPWM == true)
	{
		//PSPRINTF("pwm 10ms\r\n");
	}
	if(TesterDemoSPI == true)
	{
		PSPRINTF("spi 10ms\r\n");
	}
	if(TesterDemoWDG == true)
	{
		PSPRINTF("wdg 10ms\r\n");
	}
	if(TesterDemoDIO== true)
	{
		DIO_GPT_Callback_10ms_Function();
		//PSPRINTF("DIO 10ms\r\n");
	}
}

void Gpt_Pit_20ms_Cbk_Notification(void)
{
//	static uint8 cnt = 0;
//	cnt++;
//	if(cnt >= 50)
//	{
//		cnt = 0;
//		PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
//	}
	if(TesterDemoADC == true)
	{
		ADC_GPT_Callback_20ms_Function();
		//PSPRINTF("adc 20ms\r\n");
	}
	if(TesterDemoCAN == true)
	{
		PSPRINTF("can 20ms\r\n");
	}
	if(TesterDemoFEE == true)
	{
		PSPRINTF("fee 20ms\r\n");
	}
	if(TesterDemoFLS == true)
	{
		PSPRINTF("fls 20ms\r\n");
	}
	if(TesterDemoICU == true)
	{

		//PSPRINTF("icu 20ms\r\n");
	}
	if(TesterDemoLIN == true)
	{
		//LIN_GPT_Callback_20ms_Function();
		//PSPRINTF("lin 20ms\r\n");
	}
	if(TesterDemoPORT == true)
	{
		PSPRINTF("port 20ms\r\n");
	}
	if(TesterDemoPWM == true)
	{
		// PSPRINTF("pwm 20ms\r\n");
	}
	if(TesterDemoSPI == true)
	{
		PSPRINTF("spi 20ms\r\n");
	}
	if(TesterDemoWDG == true)
	{
		PSPRINTF("wdg 20ms\r\n");
	}
	if(TesterDemoDIO == true)
	{
		DIO_GPT_Callback_20ms_Function();
		//PSPRINTF("dio 20ms\r\n");
	}

}
void Gpt_Pit_30ms_Cbk_Notification(void)
{
//	static uint8 cnt = 0;
//	cnt++;
//	if(cnt >= 33)
//	{
//		cnt = 0;
//		PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
//	}

	if(TesterDemoADC == true)
	{
		ADC_GPT_Callback_30ms_Function();
		//PSPRINTF("adc 30ms\r\n");
	}
	if(TesterDemoCAN == true)
	{
		PSPRINTF("can 30ms\r\n");
	}
	if(TesterDemoFEE == true)
	{
		PSPRINTF("fee 30ms\r\n");
	}
	if(TesterDemoFLS == true)
	{
		PSPRINTF("fls 30ms\r\n");
	}
	if(TesterDemoICU == true)
	{
		//ICU_GPT_Callback_30ms_Function();
		//PSPRINTF("icu 30ms\r\n");
	}
	if(TesterDemoLIN == true)
	{
		//PSPRINTF("lin 30ms\r\n");
	}
	if(TesterDemoPORT == true)
	{
		PSPRINTF("port 30ms\r\n");
	}
	if(TesterDemoPWM == true)
	{
		//PSPRINTF("pwm 30ms\r\n");
	}
	if(TesterDemoSPI == true)
	{
		PSPRINTF("spi 30ms\r\n");
	}
	if(TesterDemoWDG == true)
	{
		PSPRINTF("wdg 30ms\r\n");
	}
	if(TesterDemoDIO == true)
	{
		DIO_GPT_Callback_30ms_Function();
		//PSPRINTF("dio 20ms\r\n");
	}
}

void Gpt_100us_task(void)
{
	Gpt_EnableNotification(GPT_PIT_CON_10MS_INSTANCE);
	Gpt_StartTimer(GPT_PIT_CON_10MS_INSTANCE, 100);
//	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void Gpt2_100us_task(void)
{
	Gpt_EnableNotification(5);
	Gpt_StartTimer(5, 100);
//	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void Gpt_10ms_task(void)
{
	Gpt_EnableNotification(GPT_PIT_CON_10MS_INSTANCE);
	Gpt_StartTimer(GPT_PIT_CON_10MS_INSTANCE, 10*1000);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void Gpt_20ms_task(void)
{
	Gpt_EnableNotification(GPT_PIT_CON_20MS_INSTANCE);
	Gpt_StartTimer(GPT_PIT_CON_20MS_INSTANCE, 20*1000);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void Gpt_30ms_task(void)
{
	Gpt_EnableNotification(GPT_PIT_CON_30MS_INSTANCE);
	Gpt_StartTimer(GPT_PIT_CON_30MS_INSTANCE, 30*1000);
	PSPRINTF("%s is E_OK\r\n", __FUNCTION__);
}

void Gpt6_100us_task(void)
{
	Gpt_EnableNotification(12);
	Gpt_StartTimer(12, 10000);
}

void Gpt_STM_task(void)
{
	Gpt_EnableNotification(GptChannelConfiguration_1);
	Gpt_StartTimer(GptChannelConfiguration_1, 100*1000);
}

#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
