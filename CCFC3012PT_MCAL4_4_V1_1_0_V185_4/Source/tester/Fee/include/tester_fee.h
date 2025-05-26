#ifndef TESTER_FEE_H
#define TESTER_FEE_H

#include "Fee.h"
#include "Fls.h"
#include "console.h"
#include "Gpt_Stm_LLDriver.h"
#include "shell.h"

typedef void (*Feefunc)(void);
typedef struct _FeefuncMachine
{
    char *name;
    Feefunc func;
}FeefuncMachine;

void test_fee_001();
void test_fee_002();
void test_fee_003();


int tsc_fee_func(int argc, char *agrv[]);
#endif
