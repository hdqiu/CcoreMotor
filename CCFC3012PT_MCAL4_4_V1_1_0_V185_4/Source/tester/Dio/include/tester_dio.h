#include "mcu.h"
#include "port.h"
#include "Port_Cfg.h"
#include "Dio_cfg.h"
#include "Dio.h"
typedef void (*Diofunc)(void);
typedef struct _DiofuncMachine
{
    char *name;
    Diofunc diofunc;
}DiofuncMachine;

void testdio0001();
void testdio0002();
void testdio0003();
void testdio0004();

void DIO_GPT_Callback_10ms_Function(void);
void DIO_GPT_Callback_20ms_Function(void);
void DIO_GPT_Callback_30ms_Function(void);
int dio_func(int argc, char *agrv[]);
