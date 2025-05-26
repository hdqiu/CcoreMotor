#ifndef _SHELL_PORT_H__
#define _SHELL_PORT_H__

#include "shell.h"

extern Shell shell[6U];
#if SWITCH_CORE_ENABLE
extern uint8_t shell_coreid;
#endif /* SWITCH_CORE_ENABLE */

extern void shell_init(void);

#endif
