#ifndef I2C_REG_H_
#define I2C_REG_H_

/* ============================================================================
   =============================== Module: I2C ================================
   ============================================================================ */

typedef union I2C_IBAD_union_tag {     /* I2C Bus Address Register */
  vuint8_t R;
  struct {
    vuint8_t ADR:7;
    vuint8_t  :1;
  } B;
} I2C_IBAD_tag;

typedef union I2C_IBFD_union_tag {     /* I2C Bus Frequency Divider Register */
  vuint8_t R;
  struct {
    vuint8_t IBC:8;
  } B;
} I2C_IBFD_tag;

typedef union I2C_IBCR_union_tag {     /* I2C Bus Control Register */
  vuint8_t R;
  struct {
    vuint8_t MDIS:1;
    vuint8_t IBIE:1;
    vuint8_t MSSL:1;
    vuint8_t TXRX:1;
    vuint8_t NOACK:1;
    vuint8_t RSTA:1;
    vuint8_t DMAEN:1;
    vuint8_t  :1;
  } B;
} I2C_IBCR_tag;

typedef union I2C_IBSR_union_tag {     /* I2C Bus Status Register */
  vuint8_t R;
  struct {
    vuint8_t TCF:1;
    vuint8_t IAAS:1;
    vuint8_t IBB:1;
    vuint8_t IBAL:1;
    vuint8_t  :1;
    vuint8_t SRW:1;
    vuint8_t IBIF:1;
    vuint8_t RXAK:1;
  } B;
} I2C_IBSR_tag;

typedef union I2C_IBDR_union_tag {     /* I2C Bus Data I/O Register */
  vuint8_t R;
  struct {
    vuint8_t DATA:8;
  } B;
} I2C_IBDR_tag;

typedef union I2C_IBIC_union_tag {     /* I2C Bus Interrupt Config Register */
  vuint8_t R;
  struct {
    vuint8_t BIIE:1;
    vuint8_t BYTERXIE:1;
    vuint8_t  :6;
  } B;
} I2C_IBIC_tag;

typedef union I2C_IBDBG_union_tag {    /* I2C Bus Debug Register */
  vuint8_t R;
  struct {
    vuint8_t  :6;
    vuint8_t IPG_DEBUG_HALTED:1;
    vuint8_t IPG_DEBUG_EN:1;
  } B;
} I2C_IBDBG_tag;

struct I2C_tag {
  I2C_IBAD_tag IBAD;                   /* I2C Bus Address Register */
  I2C_IBFD_tag IBFD;                   /* I2C Bus Frequency Divider Register */
  I2C_IBCR_tag IBCR;                   /* I2C Bus Control Register */
  I2C_IBSR_tag IBSR;                   /* I2C Bus Status Register */
  I2C_IBDR_tag IBDR;                   /* I2C Bus Data I/O Register */
  I2C_IBIC_tag IBIC;                   /* I2C Bus Interrupt Config Register */
  I2C_IBDBG_tag IBDBG;                 /* I2C Bus Debug Register */
};

#endif
