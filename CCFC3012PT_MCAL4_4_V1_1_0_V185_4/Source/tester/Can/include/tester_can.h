#ifndef _TESTER_CAN_H_
#define _TESTER_CAN_H_
#include "Can.h"

#define CAN_TEST_FUN 0

typedef void (*Canfunc)(void);
typedef struct _CanfuncMachine
{
    char *name;
    Canfunc canfunc;
}CanfuncMachine;

#ifdef CanLPduReceiveCalloutFunction
FUNC(Std_ReturnType, CAN_CODE) Test_Function \
( \
    VAR(uint8, AUTOMATIC) u8Can_Hrh, \
    VAR(Can_IdType, AUTOMATIC) u32Can_CanId, \
    VAR(uint8, AUTOMATIC) u8Can_Dlc, \
    P2CONST(uint8, AUTOMATIC, CAN_APPL_CONST) u8Can_SduPtr \
);
#endif
void CAN_0001(void);
void CAN_0002(void);
void CAN_0003(void);
void CAN_0004(void);
void CAN_0005(void);
void CAN_0006(void);
int can_func(int argc, char *agrv[]);

#endif
