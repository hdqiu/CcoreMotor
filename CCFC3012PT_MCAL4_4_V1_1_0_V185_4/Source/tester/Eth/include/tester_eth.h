#ifndef _TESTER_ETH_H_
#define _TESTER_ETH_H_

#include "Eth.h"

typedef void (*Ethfunc)(void);
typedef struct _EthfuncMachine
{
    char *name;
    Ethfunc ethfunc;
}EthfuncMachine;
FUNC(void, ETH_CODE) Eth_IRQ_Priority(void);
void Gmac_LLD_Init_Port(GmacId gmac_id, const GmacCfg *gmac_cfg);
status_t Gmac_LLD_Transceiver_Cfg(VAR(GmacId, AUTOMATIC) gmac_id, const GmacCfg *gmac_cfg);
void ETH_0001();
void ETH_0002();
void ETH_0003();
void ETH_0004();
void ETH_0005();
void ETH_0006();
void ETH_0007();
void ETH_0008();
void ETH_0009();
void ETH_0010();
void ETH_0011();
void ETH_0012();
int eth_func(int argc, char *agrv[]);

#endif

