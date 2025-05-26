#ifndef TESTER_FLS_H
#define TESTER_FLS_H

#include "Fls.h"
#include "console.h"

typedef void (*Flsfunc)(const Fls_ConfigType *Fls_Config);

typedef struct _FlsfuncMachine
{
    char *name;
    Flsfunc flsfunc;
}FlsfuncMachine;
 

void test_fls_0001(const Fls_ConfigType *Fls_Config);
void test_fls_0002(const Fls_ConfigType *Fls_Config);

uint32 Fls_Get_PhyStartAddress();
int tsc_fls_func(int argc, char *agrv[]);

#endif 
