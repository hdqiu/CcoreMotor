#ifndef __TESTER_PORT_H_
#define __TESTER_PORT_H_

typedef void (*Portfunc)(void);
typedef struct _PortfuncMachine
{
    char *name;
    Portfunc portfunc;
}PortfuncMachine;

#if (PORT_SET_SIUL2_API == STD_ON)
void SIUL2_EIRQ_0_IRQHandler(void);
void SIUL2_EIRQ_1_IRQHandler(void);
void SIUL2_EIRQ_2_IRQHandler(void);
#endif

void port_test_0000(void);
void port_test_0001(void);
void port_test_0002(void);
void port_test_0003(void);
void port_test_0004(void);
void port_test_0005(void);
void port_test_0006(void);
void port_test_0007(void);
void port_test_0008(void);
void port_test_0009(void);
void port_test_0010(void);

#endif
