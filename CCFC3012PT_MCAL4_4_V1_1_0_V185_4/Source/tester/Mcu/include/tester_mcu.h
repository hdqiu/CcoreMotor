
#ifndef MCU_TESTER_MCU_H_
#define MCU_TESTER_MCU_H_

#include "Mcu.h"

void Mcu_001(void);
void Mcu_002(void);
void Mcu_003(void);
void Mcu_004(void);
void Mcu_005(void);


FUNC(void, MCU_CODE)Mcu_ClockFailureCallback(void);
FUNC(void, MCU_CODE)Mcu_XoscCallback(void);
FUNC(void, MCU_CODE)Mcu_InvalidConfigCoreCallback(void);
FUNC(void, MCU_CODE)Mcu_InvalidConfigClockCallback(void);
FUNC(void, MCU_CODE)Mcu_InvalidConfigCallback(void);
FUNC(void, MCU_CODE)Mcu_InvalidModeCallback(void);
FUNC(void, MCU_CODE)Mcu_SafeModeCallback(void);
FUNC(void, MCU_CODE)Mcu_ModeCompleteCallback(void);
FUNC(void, MCU_CODE)Mcu_PmcVoltageErrorCallback(void); 
FUNC(void, MCU_CODE)Mcu_PmcTempErrorCallback(void);
FUNC(void, MCU_CODE)FccuAlarmCallback(void);
FUNC(void, MCU_CODE)FccuTimeoutCallback(void);
#endif /* MCU_TESTER_MCU_H_ */
