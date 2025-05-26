#ifndef __TESTER_GPT_H_
#define __TESTER_GPT_H_

#include "Gpt.h"

typedef void (*Gptfunc)(void);
typedef struct _GptfuncMachine
{
    char *name;
    Gptfunc gptfunc;
}GptfuncMachine;

typedef struct {
    int32_t   BUS_Curr ;
    int32_t   PhaseU_Curr;
    int32_t   PhaseV_Curr;
    int32_t   BUS_Voltage ;
    int32_t   RP_speed_Voltage ;
    int32_t   OffsetBUS_Curr ;
    int32_t   OffsetPhaseU_Curr;
    int32_t   OffsetPhaseV_Curr;
    int32_t   OffsetPhaseW_Curr;
    int32_t   Coeff_filterK1;
    int32_t   Coeff_filterK2;
}ADCSamp;

#define  ADCSamp_DEFAULTS  {0,0,0,0,0,0,0,0,0,268,756}

void Offset_CurrentReading(void);

void testgpt0001(void);
void testgpt0002(void);
void testgpt0003(void);
void testgpt0004(void);
void testgpt0005(void);
void testgpt0006(void);
void testgpt0007(void);
void testgpt0008(void);
void testgpt0009(void);
void testgpt0010(void);
void testgpt0011(void);
void testgpt0012(void);
void testgpt0013(void);
void testgpt0014(void);
void testgpt0015(void);
void testgpt0016(void);
void testgpt0017(void);
void testgpt0018(void);
void testgpt0019(void);
void testgpt0020(void);

FUNC(void, GPT_CODE) GPT_GTM_TOM_LLD_SetIRQ(void);
FUNC(void, GPT_CODE) Gpt_Pit_SetIRQ(void);
FUNC(void, GPT_CODE) Gpt_Pit2_SetIRQ(void);
FUNC(void, GPT_CODE) Gpt_Pit0Ch6_SetIRQ(void);
FUNC(void, GPT_CODE) Gpt_Stm_SetIRQ(void);
void Gpt_Pit_Cbk_Notification(void);
void Gpt_RTI_OneShot_Cbk_Notification(void);
void Gpt_Stm_Cbk_Notification(void);
void Gpt_Pit_OneShot_Cbk_Notification(void);
void Gpt_Stm_OneShot_Cbk_Notification(void);
void Gpt_Gtm_OneShot_Cbk_Notification(void);
void Gpt_Gtm_Con_Cbk_Notification(void);
void Ergodic_Oneshot_Notification(void);
void Gpt_Rtc_Cbk_Notification(void);
void Gpt_RTC_OneShot_Cbk_Notification(void);
void Gpt_Api_Continuous_Cbk_Notification(void);
void Gpt_Api_OneShot_Cbk_Notification(void);
void Ergodic_Continuous_Notification(void);
void Gpt_Gtm_FXCLK0_Cbk_Notification(void);
void Gpt_Gtm_FXCLK1_Cbk_Notification(void);
void Gpt_Gtm_FXCLK2_Cbk_Notification(void);
void Gpt_Gtm_FXCLK3_Cbk_Notification(void);
void Gpt_Gtm_FXCLK4_Cbk_Notification(void);
void Gpt_MultiCore_Pit_Con_Notification(void);
void Gpt_MultiCore_Stm1Ch2_Con_Notification(void);
void Gpt_MultiCore_Gtm_Con_Notification(void);
void Gpt_MultiCore_Con_Notification(void);
void Gpt_MultiCore_Pit1Ch0_Con_Notification(void);
void Gpt_MultiCore_Rti_Con_Notification(void);
void Gpt_MultiCore_Stm0Ch3_Con_Notification(void);
void Gpt_MultiCore_Stm2Ch1_Con_Notification(void);
void Gpt_MultiCore_Gtm1Ch2_Con_Notification(void);
void Gpt_MultiCore_Gtm3Ch10_Con_Notification(void);
void Gpt_MultiCore_Rtc_Con_Notification(void);
void Gpt_TimeCheck_Gtm_Notification(void);
void Gpt_TimeCheck_Stm_Notification(void);
void Gpt_TimeCheck_Pit_Notification(void);
void gpt_stop_timer_all(void);
void gpt_init_test(void);
void gpt_deinit_test(void);
int gpt_func(int argc, char *agrv[]);
void foc_do_0(void);
void foc_do_1(void);

void invPark(int32_t vd, int32_t vq, int16 sin, int16 cos, int32_t *valpha, int32_t *vbeta);
uint8 svpwm(int32_t valpha, int32_t vbeta, int16 *pwma, int16 *pwmb, int16 *pwmc);

// int testStage;

#endif
