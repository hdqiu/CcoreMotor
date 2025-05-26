#ifndef _TESTER_WDG_H_
#define _TESTER_WDG_H_

#include "mcu.h"
#include "Wdg_Module.h"
typedef void (*Wdgfunc)(void);
typedef struct _WdgfuncMachine
{
    char *name;
    Wdgfunc wdgfunc;
}WdgfuncMachine;

#define WDG_FEED_FUN 0
void fun_wdg_feed_dog(void);
void TriggerFeedwdgmuilt(void);

void SWT_IRQ();
void SWT_FCCU_Init(void);
#if ( defined(CCFC3012PT) || defined(CCFC3008PT)|| defined(CCFC3007PT))
FUNC(void, GPT_CODE) Wdg_GPT_GTM_TOM_LLD_SetIRQ(void);
#endif
FUNC(void, GPT_CODE) Wdg_Gpt_Pit_SetIRQ(void);
void TriggerFeedwdg(void);

void SWT2_FixedAddr_Callbcak();
void SWT0_FixedAddr_Callbcak();
void SWT1_FixedAddr_Callbcak();
void SWT6_FixedAddr_Callbcak();
void SWT4_FixedAddr_Callbcak();
void SWT5_FixedAddr_Callbcak();

void WDG_CALLBACK_NOTIFT_INCREM();
FUNC(void, WDG_CODE) SWT0_IRQFeedDog_Callbcak(void);
FUNC(void, WDG_CODE) SWT1_IRQFeedDog_Callbcak(void);
FUNC(void, WDG_CODE) SWT2_IRQFeedDog_Callbcak(void);
FUNC(void, WDG_CODE) SWT3_IRQFeedDog_Callbcak(void);
FUNC(void, WDG_CODE) SWT4_IRQFeedDog_Callbcak(void);
FUNC(void, WDG_CODE) SWT5_IRQFeedDog_Callbcak(void);
FUNC(void, WDG_CODE) SWT6_IRQFeedDog_Callbcak(void);

FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification0(void);
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification1(void);
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification2(void);
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification3(void);
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification4(void);
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification5(void);
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification6(void);
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification7(void);
int wdg_func(int argc, char *agrv[]);

void testwdg0001();
void testwdg0002();
void testwdg0003();
void testwdg0004();
void testwdg0005();
void testwdg0006();

void wdg_irq_handler();
#endif
