#ifndef _TESTER_EDMA_H_
#define _TESTER_EDMA_H_
#include "eDma.h"
#include "eDma_LLDriver.h"

typedef void (*Edmafunc)(void);
typedef struct _EdmafuncMachine
{
    char *name;
    Edmafunc edmafunc;
}EdmafuncMachine;

FUNC(void, EDMA_CODE) EDMA_HW_IrqInstall(VAR(uint32, AUTOMATIC) mappedChannel);
void EDMA_0001();
void EDMA_0002();
void EDMA_0003();
void EDMA_0004();
void EDMA_IRQ_Priority();
int edma_func(int argc, char *agrv[]);
FUNC(uint8, EDMA_CODE) EDMA_Getchpriority \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance, \
    VAR(uint8, AUTOMATIC) channel \
);
FUNC(uint8, EDMA_CODE) EDMA_GetCR_GRP0PRI \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance
);

FUNC(uint8, EDMA_CODE) EDMA_GetCR_GRP1PRI \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance
);
FUNC(uint8, EDMA_CODE) EDMA_GetCR_GRP2PRI \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance 
);
FUNC(uint8, EDMA_CODE) EDMA_GetCR_GRP3PRI \
(\
    VAR(eDMAIstanceNumType, AUTOMATIC) instance 
);
#endif
