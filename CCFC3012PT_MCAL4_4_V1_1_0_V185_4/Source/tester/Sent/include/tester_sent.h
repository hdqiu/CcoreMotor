/*
 * tester_sent.h
 *
 *  Created on: 2024Äê3ÔÂ12ÈÕ
 *      Author: pc
 */

#ifndef TESTER_SENT_TESTER_SENT_H_
#define TESTER_SENT_TESTER_SENT_H_

typedef void (*sentfunc)(void);
typedef struct _sentfuncMachine
{
    char *name;
    sentfunc sentfunc;
}SentfuncMachine;

void TEM00441_ReadIntFastMsg();
void TEM00441_ReadIntSlowMsg();
void Sensor0280B_ReadIntFastMsg();
void Sensor0280B_ReadIntSlowMsg();
void sent_test001(void);

#endif /* TESTER_SENT_TESTER_SENT_H_ */
