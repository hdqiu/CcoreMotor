/**
 * @file shell_cfg.h
 * @author Letter (nevermindzzt@gmail.com)
 * @brief shell config
 * @version 3.0.0
 * @date 2019-12-31
 * 
 * @copyright (c) 2019 Letter
 * 
 */

#ifndef __SHELL_CFG_H__
#define __SHELL_CFG_H__

#ifdef SHELL_CFG_USER
#include SHELL_CFG_USER
#endif

#ifndef SHELL_TASK_WHILE

#define     SHELL_TASK_WHILE            0
#endif /** SHELL_TASK_WHILE */

#ifndef SHELL_USING_CMD_EXPORT

#define     SHELL_USING_CMD_EXPORT      1
#endif /** SHELL_USING_CMD_EXPORT */

#ifndef SHELL_USING_COMPANION

#define     SHELL_USING_COMPANION       0
#endif /** SHELL_USING_COMPANION */

#ifndef SHELL_SUPPORT_END_LINE

#define     SHELL_SUPPORT_END_LINE      0
#endif /** SHELL_SUPPORT_END_LINE */

#ifndef SHELL_HELP_LIST_USER

#define     SHELL_HELP_LIST_USER        0
#endif /** SHELL_HELP_LIST_USER */

#ifndef SHELL_HELP_LIST_VAR

#define     SHELL_HELP_LIST_VAR         0
#endif /** SHELL_HELP_LIST_VAR */

#ifndef SHELL_HELP_LIST_KEY

#define     SHELL_HELP_LIST_KEY         0
#endif /** SHELL_HELP_LIST_KEY */

#ifndef SHELL_HELP_SHOW_PERMISSION

#define     SHELL_HELP_SHOW_PERMISSION  1
#endif /** SHELL_HELP_SHOW_PERMISSION */

#ifndef SHELL_ENTER_LF

#define     SHELL_ENTER_LF              1
#endif /** SHELL_ENTER_LF */

#ifndef SHELL_ENTER_CR

#define     SHELL_ENTER_CR              1
#endif /** SHELL_ENTER_CR */

#ifndef SHELL_ENTER_CRLF

#define     SHELL_ENTER_CRLF            0
#endif /** SHELL_ENTER_CRLF */

#ifndef SHELL_EXEC_UNDEF_FUNC

#define     SHELL_EXEC_UNDEF_FUNC       0
#endif /** SHELL_EXEC_UNDEF_FUNC */

#ifndef SHELL_PARAMETER_MAX_NUMBER

#define     SHELL_PARAMETER_MAX_NUMBER  8
#endif /** SHELL_PARAMETER_MAX_NUMBER */

#ifndef SHELL_HISTORY_MAX_NUMBER

#define     SHELL_HISTORY_MAX_NUMBER    5
#endif /** SHELL_HISTORY_MAX_NUMBER */

#ifndef SHELL_DOUBLE_CLICK_TIME

#define     SHELL_DOUBLE_CLICK_TIME     200
#endif /** SHELL_DOUBLE_CLICK_TIME */

#ifndef SHELL_QUICK_HELP

#define     SHELL_QUICK_HELP            1
#endif /** SHELL_QUICK_HELP */

#ifndef SHELL_KEEP_RETURN_VALUE

#define     SHELL_KEEP_RETURN_VALUE     0
#endif /** SHELL_KEEP_RETURN_VALUE */

#ifndef SHELL_MAX_NUMBER

#define     SHELL_MAX_NUMBER            15
#endif /** SHELL_MAX_NUMBER */

#ifndef SHELL_PRINT_BUFFER

#define     SHELL_PRINT_BUFFER          128
#endif /** SHELL_PRINT_BUFFER */

#ifndef SHELL_SCAN_BUFFER

#define     SHELL_SCAN_BUFFER          0
#endif /** SHELL_SCAN_BUFFER */

#ifndef SHELL_GET_TICK

#define     SHELL_GET_TICK()            0
#endif /** SHELL_GET_TICK */

#ifndef SHELL_USING_LOCK

#define     SHELL_USING_LOCK            0
#endif /** SHELL_USING_LOCK */

#ifndef SHELL_MALLOC

#define     SHELL_MALLOC(size)          0
#endif /** SHELL_MALLOC */

#ifndef SHELL_FREE

#define     SHELL_FREE(obj)             0
#endif /** SHELL_FREE */

#ifndef SHELL_SHOW_INFO

#define     SHELL_SHOW_INFO             1
#endif /** SHELL_SHOW_INFO */

#ifndef SHELL_CLS_WHEN_LOGIN

#define     SHELL_CLS_WHEN_LOGIN        1
#endif /** SHELL_CLS_WHEN_LOGIN */

#ifndef SHELL_DEFAULT_USER

#define     SHELL_DEFAULT_USER          "core"
#endif /** SHELL_DEFAULT_USER */

#ifndef SHELL_DEFAULT_USER_PASSWORD

#define     SHELL_DEFAULT_USER_PASSWORD ""
#endif /** SHELL_DEFAULT_USER_PASSWORD */

#ifndef SHELL_LOCK_TIMEOUT

#define     SHELL_LOCK_TIMEOUT          0 * 60 * 1000
#endif /** SHELL_LOCK_TIMEOUT */

#ifndef SHELL_USING_FUNC_SIGNATURE

#define     SHELL_USING_FUNC_SIGNATURE  0
#endif /** SHELL_USING_FUNC_SIGNATURE */

#endif
