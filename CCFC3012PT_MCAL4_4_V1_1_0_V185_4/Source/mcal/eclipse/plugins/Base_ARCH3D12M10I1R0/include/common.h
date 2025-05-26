/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : common h file
* HISTORY     : Initial version
* @file     common.h
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/
#ifndef COMMON_INC_COMMON_H_
#define COMMON_INC_COMMON_H_

#include "typedefs.h"

/* extern  */void cc_memcpy(uint8_t *dest, const uint8_t *src, const uint32_t bytes);
/* extern  */void cc_memset(uint8_t *dest, const uint8_t val, const uint32_t bytes);
/* extern  */uint8_t cc_memcmp(const uint8_t *src1, const uint8_t *src2, uint32_t len);
/* extern  */uint32_t cc_strlen(const uint8_t * s);
/* extern  */uint8_t halfword_swap(const uint32_t * src,const uint32_t * dest, uint32_t n);
/* extern  */void delay(volatile uint32_t x);
/* extern  */void delay_ms(uint32_t ms);

#endif /* COMMON_INC_COMMON_H_ */
