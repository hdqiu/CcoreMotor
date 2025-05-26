#ifndef MAIN_H__
#define MAIN_H__

#include "derivative.h"

typedef void (*BootFunc) (void);

extern const uint32_t IntcIsrVectorTable[];/*PRQA S 3684*/

extern void VTABLE(void);

void Intc_Init(void);

#if defined(MCORE_INIT)
extern void Mcore_Init(void);
#endif

void Core0Main(void);
void Core1Main(void);
void Core2Main(void);
void Core3Main(void);
void Core4Main(void);
void Core5Main(void);


#endif
