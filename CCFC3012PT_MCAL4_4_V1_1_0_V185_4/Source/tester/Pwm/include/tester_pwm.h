#ifndef TSTER_PWM_H
#define TSTER_PWM_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm.h"
#include "Pwm_Cfg.h"

typedef void (*Pwmfunc)(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr);
typedef struct _PwmfuncMachine
{
    char *name;
    Pwmfunc pwmfunc;
}PwmfuncMachine;

void Atom3_2_3_IRQ_Handle(void);
void Tom0_0_1IRQ_Handle(void);
void Emios0_5_IRQ_Handle(void);

void Pwm_Notification_0(void);
void Pwm_Notification_1(void);
void Pwm_Notification_2(void);

int tsc_pwm_func(int argc, char *agrv[]);

void TSC_Pwm_0001(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr);
void TSC_Pwm_0002(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr);
void TSC_Pwm_0003(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr);
void TSC_Pwm_0004(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr);
void TSC_Pwm_0005(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr);
void TSC_Pwm_0006(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr);

#ifdef __cplusplus
}
#endif

#endif //TSTER_PWM_H
