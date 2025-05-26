/*
 * tester_gpt_multi.h
 *
 *  Created on: 2024��1��17��
 *      Author: pc
 */

#ifndef TESTER_GPT_INCLUDE_TESTER_GPT_MULTI_H_
#define TESTER_GPT_INCLUDE_TESTER_GPT_MULTI_H_

#include "tester_can.h"
#include "tester_icu.h"
#include "tester_pwm.h"
#include "tester_lin.h"

void Gpt_100us_task(void);
void Gpt2_100us_task(void);
void Gpt_10ms_task(void);
void Gpt_20ms_task(void);
void Gpt_30ms_task(void);
void Gpt6_100us_task(void);
void Gpt_STM_task(void);
void Gpt_Pit_10ms_Cbk_Notification(void);
void Gpt_Pit_20ms_Cbk_Notification(void);
void Gpt_Pit_30ms_Cbk_Notification(void);
int multi_func(int argc, char *agrv[]);

#endif /* TESTER_GPT_INCLUDE_TESTER_GPT_MULTI_H_ */
