#ifndef DSPI_REG_H_
#define DSPI_REG_H_
/* ============================================================================
   =============================== Module: DSPI ===============================
   ============================================================================ */

typedef union DSPI_MCR_union_tag {     /* DSPI Module Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t MSTR:1;
    vuint32_t CONT_SCKE:1;
    vuint32_t DCONF:2;
    vuint32_t FRZ:1;
    vuint32_t MTFE:1;
    vuint32_t PCSSE:1;
    vuint32_t ROOE:1;
    vuint32_t PCSIS:8;
    vuint32_t  :1;
    vuint32_t MDIS:1;
    vuint32_t DIS_TXF:1;
    vuint32_t DIS_RXF:1;
    vuint32_t CLR_TXF:1;
    vuint32_t CLR_RXF:1;
    vuint32_t SMPL_PT:2;
    vuint32_t  :4;
    vuint32_t XSPI:1;
    vuint32_t FCPCS:1;
    vuint32_t PES:1;
    vuint32_t HALT:1;
  } B;
} DSPI_MCR_tag;

typedef union DSPI_TCR_union_tag {     /* DSPI Transfer Count Register */
  vuint32_t R;
  struct {
    vuint32_t SPI_TCNT:16;
    vuint32_t  :16;
  } B;
} DSPI_TCR_tag;

typedef union DSPI_MODE_CTAR_union_tag { /* DSPI Clock and Transfer Attributes Register (In Master Mode) */
  vuint32_t R;
  struct {
    vuint32_t DBR:1;
    vuint32_t FMSZ:4;
    vuint32_t CPOL:1;
    vuint32_t CPHA:1;
    vuint32_t LSBFE:1;
    vuint32_t PCSSCK:2;
    vuint32_t PASC:2;
    vuint32_t PDT:2;
    vuint32_t PBR:2;
    vuint32_t CSSCK:4;
    vuint32_t ASC:4;
    vuint32_t DT:4;
    vuint32_t BR:4;
  } B;
} DSPI_MODE_CTAR_tag;

typedef union DSPI_MODE_CTAR_SLAVE_union_tag { /* DSPI Clock and Transfer Attributes Register (In Slave Mode) */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t FMSZ:4;                  /* Frame Size */
    vuint32_t CPOL:1;
    vuint32_t CPHA:1;
    vuint32_t PE:1;
    vuint32_t PP:1;
    vuint32_t  :1;
    vuint32_t  :22;
  } B;
} DSPI_MODE_CTAR_SLAVE_tag;

typedef union DSPI_MODE_union_tag {
  DSPI_MODE_CTAR_tag CTAR[8];          /* DSPI Clock and Transfer Attributes Register (In Master Mode) */
  DSPI_MODE_CTAR_SLAVE_tag CTAR_SLAVE[2]; /* DSPI Clock and Transfer Attributes Register (In Slave Mode) */
} DSPI_MODE_tag;

typedef union DSPI_SR_union_tag {      /* DSPI Status Register */
  vuint32_t R;
  struct {
    vuint32_t TCF:1;
    vuint32_t TXRXS:1;
    vuint32_t SPITCF:1;
    vuint32_t EOQF:1;
    vuint32_t TFUF:1;
    vuint32_t DSITCF:1;
    vuint32_t TFFF:1;
    vuint32_t BSYF:1;
    vuint32_t CMDTCF:1;
    vuint32_t DPEF:1;
    vuint32_t SPEF:1;
    vuint32_t DDIF:1;
    vuint32_t RFOF:1;
    vuint32_t TFIWF:1;
    vuint32_t RFDF:1;
    vuint32_t CMDFFF:1;
    vuint32_t TXCTR:4;
    vuint32_t TXNXTPTR:4;
    vuint32_t RXCTR:4;
    vuint32_t POPNXTPTR:4;
  } B;
} DSPI_SR_tag;

typedef union DSPI_RSER_union_tag {    /* DSPI DMA/Interrupt Request Select and Enable Register */
  vuint32_t R;
  struct {
    vuint32_t TCF_RE:1;
    vuint32_t CMDFFF_RE:1;
    vuint32_t SPITCF_RE:1;
    vuint32_t EOQF_RE:1;
    vuint32_t TFUF_RE:1;
    vuint32_t DSITCF_RE:1;
    vuint32_t TFFF_RE:1;
    vuint32_t TFFF_DIRS:1;
    vuint32_t CMDTCF_RE:1;
    vuint32_t DPEF_RE:1;
    vuint32_t SPEF_RE:1;
    vuint32_t DDIF_RE:1;
    vuint32_t RFOF_RE:1;
    vuint32_t TFIWF_RE:1;
    vuint32_t RFDF_RE:1;
    vuint32_t RFDF_DIRS:1;
    vuint32_t CMDFFF_DIRS:1;
    vuint32_t DDIF_DIRS:1;
    vuint32_t  :14;
  } B;
} DSPI_RSER_tag;

typedef union DSPI_PUSHR_PUSHR_union_tag { /* DSPI PUSH FIFO Register In Master Mode */
  vuint32_t R;
  struct {
    vuint32_t CONT:1;
    vuint32_t CTAS:3;
    vuint32_t EOQ:1;
    vuint32_t CTCNT:1;
    vuint32_t PE_MASC:1;
    vuint32_t PP_MCSC:1;
    vuint32_t PCS:8;
    vuint32_t TXDATA:16;
  } B;
} DSPI_PUSHR_PUSHR_tag;

typedef union DSPI_PUSHR_PUSHR_XSPI_union_tag { /* DSPI PUSH FIFO Register In Master Mode */
  vuint32_t R;
  struct {
	  vuint16_t CMD:16;
	  vuint16_t TXDATA:16;
  } B;
} DSPI_PUSHR_PUSHR_XSPI_tag;

typedef union DSPI_PUSHR_PUSHR_SLAVE_union_tag { /* DSPI PUSH FIFO Register In Slave Mode */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TXDATA:16;
  } B;
} DSPI_PUSHR_PUSHR_SLAVE_tag;

typedef union DSPI_PUSHR_union_tag {
  DSPI_PUSHR_PUSHR_tag PUSHR;          /* DSPI PUSH FIFO Register In Master Mode */
  DSPI_PUSHR_PUSHR_SLAVE_tag PUSHR_SLAVE; /* DSPI PUSH FIFO Register In Slave Mode */
  DSPI_PUSHR_PUSHR_XSPI_tag PUSHR_XSPI;  /* DSPI PUSH FIFO Register In XSPI Mode */
} DSPI_PUSHR_tag;

typedef union DSPI_POPR_union_tag {    /* DSPI POP FIFO Register */
  vuint32_t R;
  struct {
    vuint32_t RXDATA:32;
  } B;
} DSPI_POPR_tag;

typedef union DSPI_TXFR_union_tag {    /* DSPI Transmit FIFO Registers */
  vuint32_t R;
  struct {
    vuint32_t TXCMD_TXDATA:16;
    vuint32_t TXDATA:16;
  } B;
} DSPI_TXFR_tag;

typedef union DSPI_RXFR_union_tag {    /* DSPI Receive FIFO Registers */
  vuint32_t R;
  struct {
    vuint32_t RXDATA:32;
  } B;
} DSPI_RXFR_tag;

typedef union DSPI_DSICR0_union_tag {  /* DSPI DSI Configuration Register 0 */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t FMSZ4:1;
    vuint32_t  :6;
    vuint32_t  :1;
    vuint32_t  :1;
    vuint32_t ITSB:1;
    vuint32_t TSBC:1;
    vuint32_t TXSS:1;
    vuint32_t TPOL:1;
    vuint32_t  :1;
    vuint32_t CID:1;
    vuint32_t DCONT:1;
    vuint32_t DSICTAS:3;
    vuint32_t DMS:1;
    vuint32_t PES:1;
    vuint32_t PE:1;
    vuint32_t PP:1;
    vuint32_t DPCSx:8;
  } B;
} DSPI_DSICR0_tag;

typedef union DSPI_SDR0_union_tag {    /* DSPI DSI Serialization Data Register 0 */
  vuint32_t R;
  struct {
    vuint32_t SER_DATA:32;
  } B;
} DSPI_SDR0_tag;

typedef union DSPI_ASDR0_union_tag {   /* DSPI DSI Alternate Serialization Data Register 0 */
  vuint32_t R;
  struct {
    vuint32_t ASER_DATA:32;
  } B;
} DSPI_ASDR0_tag;

typedef union DSPI_COMPR0_union_tag {  /* DSPI DSI Transmit Comparison Register 0 */
  vuint32_t R;
  struct {
    vuint32_t COMP_DATA:32;
  } B;
} DSPI_COMPR0_tag;

typedef union DSPI_DDR0_union_tag {    /* DSPI DSI Deserialization Data Register 0 */
  vuint32_t R;
  struct {
    vuint32_t DESER_DATA:32;
  } B;
} DSPI_DDR0_tag;

typedef union DSPI_DSICR1_union_tag {  /* DSPI DSI Configuration Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t TSBCNT:5;
    vuint32_t  :5;
    vuint32_t  DSI64_EN:1;
    vuint32_t DSE1:1;
    vuint32_t DSE0:1;
    vuint32_t TRGPRD:8;
    vuint32_t DPCS1_x:8;
  } B;
} DSPI_DSICR1_tag;

typedef union DSPI_SSR0_union_tag {    /* DSPI DSI Serialization Source Select Register 0 */
  vuint32_t R;
  struct {
    vuint32_t SS:32;
  } B;
} DSPI_SSR0_tag;

typedef union DSPI_DIMR0_union_tag {   /* DSPI DSI Deserialized Data Interrupt Mask Register 0 */
  vuint32_t R;
  struct {
    vuint32_t MASK:32;
  } B;
} DSPI_DIMR0_tag;

typedef union DSPI_DPIR0_union_tag {   /* DSPI DSI Deserialized Data Polarity Interrupt Register 0 */
  vuint32_t R;
  struct {
    vuint32_t DP:32;
  } B;
} DSPI_DPIR0_tag;

typedef union DSPI_CTARE_union_tag {   /* DSPI Clock and Transfer Attributes Register Extended */
  vuint32_t R;
  struct {
    vuint32_t  :15;
    vuint32_t FMSZE:1;
    vuint32_t  :5;
    vuint32_t DTCP:11;
  } B;
} DSPI_CTARE_tag;

typedef union DSPI_SREX_union_tag {    /* DSPI Status Register Extended */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t CMDCTR:4;
    vuint32_t CMDNXTPTR:4;
  } B;
} DSPI_SREX_tag;

struct DSPI_tag {
  DSPI_MCR_tag MCR;                    /* DSPI Module Configuration Register */
  uint8_t DSPI_reserved0[4];
  DSPI_TCR_tag TCR;                    /* DSPI Transfer Count Register */
  DSPI_MODE_tag MODE;
  DSPI_SR_tag SR;                      /* DSPI Status Register */
  DSPI_RSER_tag RSER;                  /* DSPI DMA/Interrupt Request Select and Enable Register */
  DSPI_PUSHR_tag PUSHR;
  DSPI_POPR_tag POPR;                  /* DSPI POP FIFO Register */
  DSPI_TXFR_tag TXFR[4];               /* DSPI Transmit FIFO Registers */
  uint8_t DSPI_reserved1[48];
  DSPI_RXFR_tag RXFR[4];               /* DSPI Receive FIFO Registers */
  uint8_t DSPI_reserved2[48];
  DSPI_DSICR0_tag DSICR0;              /* DSPI DSI Configuration Register 0 */
  DSPI_SDR0_tag SDR0;                  /* DSPI DSI Serialization Data Register 0 */
  DSPI_ASDR0_tag ASDR0;                /* DSPI DSI Alternate Serialization Data Register 0 */
  DSPI_COMPR0_tag COMPR0;              /* DSPI DSI Transmit Comparison Register 0 */
  DSPI_DDR0_tag DDR0;                  /* DSPI DSI Deserialization Data Register 0 */
  DSPI_DSICR1_tag DSICR1;              /* DSPI DSI Configuration Register 1 */
  DSPI_SSR0_tag SSR0;                  /* DSPI DSI Serialization Source Select Register 0 */
  uint8_t DSPI_reserved3[16];
  DSPI_DIMR0_tag DIMR0;                /* DSPI DSI Deserialized Data Interrupt Mask Register 0 */
  DSPI_DPIR0_tag DPIR0;                /* DSPI DSI Deserialized Data Polarity Interrupt Register 0 */
  DSPI_SDR0_tag SDR1;                  /* DSPI DSI Serialization Data Register 1,only aviliable for 11-13-14-15 */
  uint8_t DSPI_reserved4[40];
  DSPI_CTARE_tag CTARE[8];             /* DSPI Clock and Transfer Attributes Register Extended */
  DSPI_SREX_tag SREX;                  /* DSPI Status Register Extended */
};

#endif
