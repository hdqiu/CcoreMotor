#include "tester_wdg.h"
#include "Wdg_Cfg.h"
#include "Det.h"
#include "shell.h"
#include "Mcu_LLDriver.h"
#include "Wdg_Module.h"
#include "Gpt.h"
#include "Gpt_Cfg.h"
#include "Gpt_irq.h"
#include "Dio.h"
#include "wdg_176_ModId0.h"
#include "wdg_176_ModId1.h"
#include "wdg_176_ModId2.h"
#include "wdg_176_ModId3.h"
#include "wdg_176_ModId4.h"
#include "wdg_176_ModId5.h"
#include "wdg_176_ModId6.h"
#include "wdg_176_ModId7.h"
#include "wdg_irq.h"
#include <string.h>


FUNC(void, GPT_CODE) Wdg_Gpt_Stm_SetIRQ(void);

extern CONST(Gpt_ConfigType, GPT_CONST) GptChannelConfigSet;

#define WDG_TEST_CASE_MAX sizeof(wdg_funcs) / sizeof(WdgfuncMachine)

int testwdg_flag=10;
int testwdg_flagmutil[6]={10,10,10,10,10,10};
static WdgfuncMachine wdg_funcs[] = {
	{"1", testwdg0001},
	{"2", testwdg0002},
	{"3", testwdg0003},
	{"4", testwdg0004},
	{"5", testwdg0005},
    {"6", testwdg0006},
};

void SWT0_FixedAddr_Callbcak()
{
	PSPRINTF("WDG_CALLBACK_NOTIFT_TRIADD FixedAddr SWT0\n");
}
void SWT1_FixedAddr_Callbcak()
{
	PSPRINTF("WDG_CALLBACK_NOTIFT_TRIADD FixedAddr SWT1\n");
}
void SWT2_FixedAddr_Callbcak()
{
	PSPRINTF("WDG_CALLBACK_NOTIFT_TRIADD FixedAddr SWT2\n");
}
void SWT6_FixedAddr_Callbcak()
{
	PSPRINTF("WDG_CALLBACK_NOTIFT_TRIADD FixedAddr SWT6\n");
}
void SWT4_FixedAddr_Callbcak()
{
	PSPRINTF("WDG_CALLBACK_NOTIFT_TRIADD FixedAddr SWT4\n");
}
void SWT5_FixedAddr_Callbcak()
{
	PSPRINTF("WDG_CALLBACK_NOTIFT_TRIADD FixedAddr SWT5\n");
}

void WDG_CALLBACK_NOTIFT_INCREM()
{
	PSPRINTF("WDG_CALLBACK_NOTIFT_INCREM IncrementalAddr\n");
}

FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification0(void)
{
    WdgTrigger(SWT0);
}

FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification1(void)
{
    WdgTrigger(SWT1);
}

FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification2(void)
{
    WdgTrigger(SWT2);
}

FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification3(void)
{
    WdgTrigger(SWT3);
}

FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification4(void)
{

    WdgTrigger(SWT4);
}
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification5(void)
{
    WdgTrigger(SWT5);
}
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification6(void)
{
    WdgTrigger(SWT6);
}
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification7(void)
{
    WdgTrigger(SWT7_AO);
}

FUNC(void, WDG_CODE) SWT0_IRQFeedDog_Callbcak(void)
{

    WdgTrigger(SWT0);
}


FUNC(void, WDG_CODE) SWT1_IRQFeedDog_Callbcak(void)
{

    WdgTrigger(SWT1);
}

FUNC(void, WDG_CODE) SWT2_IRQFeedDog_Callbcak(void)
{

    WdgTrigger(SWT2);
}

FUNC(void, WDG_CODE) SWT3_IRQFeedDog_Callbcak(void)
{

    WdgTrigger(SWT3);
}

FUNC(void, WDG_CODE) SWT4_IRQFeedDog_Callbcak(void)
{

    WdgTrigger(SWT4);
}
FUNC(void, WDG_CODE) SWT5_IRQFeedDog_Callbcak(void)
{

    WdgTrigger(SWT5);
}
FUNC(void, WDG_CODE) SWT6_IRQFeedDog_Callbcak(void)
{

    WdgTrigger(SWT6);
}

void SWT_IRQ()
{
#ifdef USER_SWT0_IRQ
    (void)INTC_LLD_Set_IRQ_Priority(SWT0_IRQn, INTR_PRI_1);
    /*Install interrupt handler*/
    (void)INTC_LLD_Set_IRQ_Handle(SWT0_IRQn, &SWT0_ISR);
    /*Switch interrupt process to current core*/
    (void)INTC_LLD_Set_IRQ_Enable(SWT0_IRQn);
#endif
#ifdef USER_SWT1_IRQ
    /*Set interrupt priority*/
    (void)INTC_LLD_Set_IRQ_Priority(SWT1_IRQn, INTR_PRI_1);
    /*Install interrupt handler*/
    (void)INTC_LLD_Set_IRQ_Handle(SWT1_IRQn, &SWT1_ISR);
    /*Switch interrupt process to current core*/
    (void)INTC_LLD_Set_IRQ_Enable(SWT1_IRQn);
#endif
#ifdef USER_SWT2_IRQ

    /*Set interrupt priority*/
    (void)INTC_LLD_Set_IRQ_Priority(SWT2_IRQn, INTR_PRI_1);
    /*Install interrupt handler*/
    (void)INTC_LLD_Set_IRQ_Handle(SWT2_IRQn, &SWT2_ISR);
    /*Switch interrupt process to current core*/
    (void)INTC_LLD_Set_IRQ_Enable(SWT2_IRQn);
#endif
#ifdef USER_SWT3_IRQ
    /*Set interrupt priority*/
    (void)INTC_LLD_Set_IRQ_Priority(SWT3_IRQn, INTR_PRI_1);
    /*Install interrupt handler*/
    (void)INTC_LLD_Set_IRQ_Handle(SWT3_IRQn, &SWT3_ISR);
    /*Switch interrupt process to current core*/
    (void)INTC_LLD_Set_IRQ_Enable(SWT3_IRQn);
#endif
#ifdef USER_SWT4_IRQ
    /*Set interrupt priority*/
    (void)INTC_LLD_Set_IRQ_Priority(SWT4_IRQn, INTR_PRI_1);
    /*Install interrupt handler*/
    (void)INTC_LLD_Set_IRQ_Handle(SWT4_IRQn, &SWT4_ISR);
    /*Switch interrupt process to current core*/
    (void)INTC_LLD_Set_IRQ_Enable(SWT4_IRQn);
#endif
#ifdef USER_SWT5_IRQ
    /*Set interrupt priority*/
    (void)INTC_LLD_Set_IRQ_Priority(SWT5_IRQn, INTR_PRI_1);
    /*Install interrupt handler*/
    (void)INTC_LLD_Set_IRQ_Handle(SWT5_IRQn, &SWT5_ISR);
    /*Switch interrupt process to current core*/
    (void)INTC_LLD_Set_IRQ_Enable(SWT5_IRQn);
#endif
#ifdef USER_SWT6_IRQ
    /*Set interrupt priority*/
    (void)INTC_LLD_Set_IRQ_Priority(SWT6_IRQn, INTR_PRI_1);
    /*Install interrupt handler*/
    (void)INTC_LLD_Set_IRQ_Handle(SWT6_IRQn, &SWT6_ISR);
    /*Switch interrupt process to current core*/
    (void)INTC_LLD_Set_IRQ_Enable(SWT6_IRQn);
#endif
}

void TriggerFeedwdg(void)
{
	 if(testwdg_flag==0)
	  {

	   Wdg_176_ModId0_SetTriggerCondition(2000);
	  }
	   else if(testwdg_flag==1)
	   {
		Wdg_176_ModId1_SetTriggerCondition(2000);
	   }
	   else if(testwdg_flag==2)
	   {
		Wdg_176_ModId2_SetTriggerCondition(2000);
	   }
	   else if(testwdg_flag==3)
	   {
		Wdg_176_ModId3_SetTriggerCondition(2000);
	   }
       else if(testwdg_flag==4)
	   {
        Wdg_176_ModId0_SetTriggerCondition(2000);
		Wdg_176_ModId1_SetTriggerCondition(2000);
        Wdg_176_ModId2_SetTriggerCondition(2000);
        Wdg_176_ModId3_SetTriggerCondition(2000);
	   }
#if ( defined(CCFC3012PT))
	   else if(testwdg_flag==5)
	   {
		Wdg_176_ModId5_SetTriggerCondition(2000);
	   }
	   else if(testwdg_flag==6)
	   {
		Wdg_176_ModId6_SetTriggerCondition(2000);
	   }
	   else if(testwdg_flag==7)
	   {
		Wdg_176_ModId7_SetTriggerCondition(2000);
	   }
	   else if(testwdg_flag==8)
	   {
		Wdg_176_ModId0_SetTriggerCondition(2000);
		Wdg_176_ModId1_SetTriggerCondition(2000);
		Wdg_176_ModId2_SetTriggerCondition(2000);
		Wdg_176_ModId3_SetTriggerCondition(2000);
		Wdg_176_ModId4_SetTriggerCondition(2000);
		Wdg_176_ModId5_SetTriggerCondition(2000);
		Wdg_176_ModId6_SetTriggerCondition(2000);
		Wdg_176_ModId7_SetTriggerCondition(2000);
	   }
       else if(testwdg_flag==9)
       {
        Wdg_176_ModId4_SetTriggerCondition(2000);
       }
#endif
}


void TriggerFeedwdgmuilt(void)
{
	 if(testwdg_flagmutil[GetCoreID()]==0)
	  {

	   Wdg_176_ModId0_SetTriggerCondition(2000);

	  }
	   else if(testwdg_flagmutil[GetCoreID()]==1)
	   {
		Wdg_176_ModId1_SetTriggerCondition(2000);

	   }
	   else if(testwdg_flagmutil[GetCoreID()]==2)
	   {

		Wdg_176_ModId2_SetTriggerCondition(2000);

	   }
#if ( defined(CCFC3012PT))
	   else if(testwdg_flagmutil[GetCoreID()]==5)
	   {

		Wdg_176_ModId5_SetTriggerCondition(2000);

	   }
	   else if(testwdg_flagmutil[GetCoreID()]==6)
	   {

		Wdg_176_ModId6_SetTriggerCondition(2000);

	   }
       else if(testwdg_flagmutil[GetCoreID()]==4)
       {

        Wdg_176_ModId4_SetTriggerCondition(2000);

       }
#endif
}
void fun_wdg_feed_dog(void)
{
#if(GPT_ENABLE_MULTICORE==STD_ON)
	{
		TriggerFeedwdgmuilt();
	}
#else
	{
		TriggerFeedwdg();
	}
#endif
}

void SWT_FCCU_Init(void)
{
    Mcu_FccuInit();

}

extern  VAR(Wdg_Status_Type, WDG_VAR) eWdg_DriverStatus[WDG_INSTANCES_NUM];

void testwdg0001()
{
    SWT_FCCU_Init();
    	uint32 tmp;
	tmp =*(uint32_t*)0xFFFA05D8ul;
	tmp |= (1u << 10);
	*(uint32_t*)0xFFFA05D8ul = tmp;
    Gpt_Init(&GptChannelConfigSet);
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_Init(&WdgSettingsConfig_0);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_Init(&WdgSettingsConfig_1);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_Init(&WdgSettingsConfig_2);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_Init(&WdgSettingsConfig_3);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_Init(&WdgSettingsConfig_4);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_Init(&WdgSettingsConfig_5);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_Init(&WdgSettingsConfig_6);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_Init(&WdgSettingsConfig_7);
#endif
    testwdg_flag=8;
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_SetMode(WDGIF_FAST_MODE);
#endif
}
void testwdg0002()
{
    SWT_FCCU_Init();
    	uint32 tmp;
	tmp =*(uint32_t*)0xFFFA05D8ul;
	tmp |= (1u << 10);
	*(uint32_t*)0xFFFA05D8ul = tmp;
    Gpt_Init(&GptChannelConfigSet);
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_Init(&WdgSettingsConfig_0);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_Init(&WdgSettingsConfig_1);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_Init(&WdgSettingsConfig_2);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_Init(&WdgSettingsConfig_3);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_Init(&WdgSettingsConfig_4);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_Init(&WdgSettingsConfig_5);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_Init(&WdgSettingsConfig_6);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_Init(&WdgSettingsConfig_7);
#endif
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_SetMode(WDGIF_FAST_MODE);
#endif
}

void testwdg0003()
{
    SWT_FCCU_Init();
    	uint32 tmp;
	tmp =*(uint32_t*)0xFFFA05D8ul;
	tmp |= (1u << 10);
	*(uint32_t*)0xFFFA05D8ul = tmp;
    Gpt_Init(&GptChannelConfigSet);
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_Init(&WdgSettingsConfig_0);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_Init(&WdgSettingsConfig_1);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_Init(&WdgSettingsConfig_2);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_Init(&WdgSettingsConfig_3);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_Init(&WdgSettingsConfig_4);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_Init(&WdgSettingsConfig_5);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_Init(&WdgSettingsConfig_6);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_Init(&WdgSettingsConfig_7);
#endif
    testwdg_flag=8;
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_SetMode(WDGIF_FAST_MODE);
#endif
}
void testwdg0004()
{
    SWT_FCCU_Init();
    	uint32 tmp;
	tmp =*(uint32_t*)0xFFFA05D8ul;
	tmp |= (1u << 10);
	*(uint32_t*)0xFFFA05D8ul = tmp;
    Gpt_Init(&GptChannelConfigSet);
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_Init(&WdgSettingsConfig_0);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_Init(&WdgSettingsConfig_1);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_Init(&WdgSettingsConfig_2);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_Init(&WdgSettingsConfig_3);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_Init(&WdgSettingsConfig_4);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_Init(&WdgSettingsConfig_5);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_Init(&WdgSettingsConfig_6);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_Init(&WdgSettingsConfig_7);
#endif
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_SetMode(WDGIF_FAST_MODE);
#endif
}

void testwdg0005()
{
    SWT_FCCU_Init();
    	uint32 tmp;
	tmp =*(uint32_t*)0xFFFA05D8ul;
	tmp |= (1u << 10);
	*(uint32_t*)0xFFFA05D8ul = tmp;
    Gpt_Init(&GptChannelConfigSet);
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_Init(&WdgSettingsConfig_0);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_Init(&WdgSettingsConfig_1);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_Init(&WdgSettingsConfig_2);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_Init(&WdgSettingsConfig_3);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_Init(&WdgSettingsConfig_4);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_Init(&WdgSettingsConfig_5);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_Init(&WdgSettingsConfig_6);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_Init(&WdgSettingsConfig_7);
#endif
    testwdg_flag=8;
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_SetMode(WDGIF_FAST_MODE);
#endif
}
void testwdg0006()
{
    SWT_FCCU_Init();
    	uint32 tmp;
	tmp =*(uint32_t*)0xFFFA05D8ul;
	tmp |= (1u << 10);
	*(uint32_t*)0xFFFA05D8ul = tmp;
    Gpt_Init(&GptChannelConfigSet);
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_Init(&WdgSettingsConfig_0);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_Init(&WdgSettingsConfig_1);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_Init(&WdgSettingsConfig_2);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_Init(&WdgSettingsConfig_3);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_Init(&WdgSettingsConfig_4);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_Init(&WdgSettingsConfig_5);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_Init(&WdgSettingsConfig_6);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_Init(&WdgSettingsConfig_7);
#endif
#if (WDGINSTANCE0==STD_ON)
    Wdg_176_ModId0_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE1==STD_ON)
    Wdg_176_ModId1_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE2==STD_ON)
    Wdg_176_ModId2_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE3==STD_ON)
    Wdg_176_ModId3_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE4==STD_ON)
    Wdg_176_ModId4_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE5==STD_ON)
    Wdg_176_ModId5_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE6==STD_ON)
    Wdg_176_ModId6_SetMode(WDGIF_FAST_MODE);
#endif
#if (WDGINSTANCE7_AO==STD_ON)
    Wdg_176_ModId7_SetMode(WDGIF_FAST_MODE);
#endif
}

#if ( defined(CCFC3012PT) || defined(CCFC3008PT)|| defined(CCFC3007PT))
FUNC(void, GPT_CODE) Wdg_GPT_GTM_TOM_LLD_SetIRQ(void)
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

}
#endif
FUNC(void, GPT_CODE) Wdg_Gpt_Pit_SetIRQ(void)
{
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG0_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG0_IRQn, &PIT0_CH0_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG0_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG1_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG1_IRQn, &PIT0_CH1_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG1_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG2_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG2_IRQn, &PIT0_CH2_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG2_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG3_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG3_IRQn, &PIT0_CH3_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG3_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG4_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG4_IRQn, &PIT0_CH4_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG4_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG5_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG5_IRQn, &PIT0_CH5_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG5_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG6_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG6_IRQn, &PIT0_CH6_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG6_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_TFLG7_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_TFLG7_IRQn, &PIT0_CH7_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_TFLG7_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_0_RTI_TFLG_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_0_RTI_TFLG_IRQn, &RTI_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_0_RTI_TFLG_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_1_TFLG0_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_1_TFLG0_IRQn, &PIT1_CH0_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_1_TFLG0_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(PIT_1_TFLG1_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(PIT_1_TFLG1_IRQn, &PIT1_CH1_ISR);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(PIT_1_TFLG1_IRQn);
}

FUNC(void, GPT_CODE) Wdg_Gpt_Stm_SetIRQ(void)
{
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM0_CH0_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM0_CH0_IRQn, &STM0_CH0_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM0_CH0_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM0_CH1_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM0_CH1_IRQn, &STM0_CH1_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM0_CH1_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM0_CH2_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM0_CH2_IRQn, &STM0_CH2_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM0_CH2_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM0_CH3_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM0_CH3_IRQn, &STM0_CH3_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM0_CH3_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM1_CH0_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM1_CH0_IRQn, &STM1_CH0_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM1_CH0_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM1_CH1_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM1_CH1_IRQn, &STM1_CH1_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM1_CH1_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM1_CH2_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM1_CH2_IRQn, &STM1_CH2_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM1_CH2_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM1_CH3_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM1_CH3_IRQn, &STM1_CH3_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM1_CH3_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM2_CH0_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM2_CH0_IRQn, &STM2_CH0_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM2_CH0_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM2_CH1_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM2_CH1_IRQn, &STM2_CH1_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM2_CH1_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM2_CH2_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM2_CH2_IRQn, &STM2_CH2_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM2_CH2_IRQn);
	/*Set interrupt priority*/
	(void)INTC_LLD_Set_IRQ_Priority(STM2_CH3_IRQn, INTR_PRI_38);
	/*Install interrupt handler*/
	(void)INTC_LLD_Set_IRQ_Handle(STM2_CH3_IRQn, &STM2_CH3_Handler);
	/*Switch interrupt process to current core*/
	(void)INTC_LLD_Set_IRQ_Enable(STM2_CH3_IRQn);
}
int wdg_func(int argc, char *agrv[])
{
	static uint8 wdgsetIrqFlag[6] = {1,1,1,1,1,1};
	VAR(uint32, AUTOMATIC) CoreIndex = GetCoreID();
	if(wdgsetIrqFlag[CoreIndex]==1)
	{
        #if ( defined(CCFC3012PT) || defined(CCFC3008PT)|| defined(CCFC3007PT))
		Wdg_GPT_GTM_TOM_LLD_SetIRQ();
        #endif
		Wdg_Gpt_Pit_SetIRQ();
		Wdg_Gpt_Stm_SetIRQ();
		wdgsetIrqFlag[CoreIndex] = 0;
	}


    if (argc == 2)
    {
        if (!strcmp(agrv[1], "swt_irq"))
        {
            SWT_IRQ();
        }

        else if (!strcmp(agrv[1], "help"))
        {
            PSPRINTF( "swt_irq ----- CMD ------- SWT_IRQ()\r\n");
            PSPRINTF( "help ----- CMD ------- ID of the test case\r\n");

            for(uint16 i = 0; i < WDG_TEST_CASE_MAX; i++)
            {
                PSPRINTF("%s\n", wdg_funcs[i].name);
            }
        }
        else
        {
            uint32 id = (uint32)atoi(agrv[1]);
            PSPRINTF("%d\r\n", id);
            if((id >= 1) && (id <=WDG_TEST_CASE_MAX))
            {
                if(wdg_funcs[id-1].wdgfunc != NULL_PTR)
                {
                    wdg_funcs[id-1].wdgfunc();
                    return 0;
                }
                else if(wdg_funcs[id].wdgfunc == NULL_PTR)
                {
                    PSPRINTF("error: Test case is undefined\n");
                    return 0;
                }
            }
            PSPRINTF("error: Input invalid parameters[%s], please Use the 'wdg_test help' command to see the supported test instructions\n", agrv[1]);
        }
    }
    return 0;
}

#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), wdg_test , wdg_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif


