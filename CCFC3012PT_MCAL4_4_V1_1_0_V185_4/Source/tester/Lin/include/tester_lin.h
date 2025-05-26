
#ifndef TESTER_LIN_H
#define TESTER_LIN_H

#include "Lin.h"

typedef void (*Linfunc)(const Lin_ConfigType *LinDriverConfig);
typedef struct _LinfuncMachine
{
    char *name;
    Linfunc linfunc;
}LinfuncMachine;

FUNC(void, LIN_CODE) Lin_LLD_Init_IrqIsrEnable(void);

void TSC_Lin_0001(const Lin_ConfigType *LinDriverConfig);
void TSC_Lin_0002(const Lin_ConfigType *LinDriverConfig);
void TSC_Lin_0003(const Lin_ConfigType *LinDriverConfig);

void TSC_Lin_main(const Lin_ConfigType *LinDriverConfig);

#endif //TESTER_LIN_H
