#ifndef M_CAN_REG_H_
#define M_CAN_REG_H_

/* ============================================================================
   =============================== Module: M_CAN ==============================
   ============================================================================ */

typedef union M_CAN_CREL_union_tag {   /* Core Release Register */
  vuint32_t R;
  struct {
    vuint32_t REL:4;
    vuint32_t STEP:4;
    vuint32_t SUBSTEP:4;
    vuint32_t YEAR:4;
    vuint32_t MON:8;
    vuint32_t DAY:8;
  } B;
} M_CAN_CREL_tag;

typedef union M_CAN_ENDN_union_tag {   /* Endian Register */
  vuint32_t R;
  struct {
    vuint32_t ETV:32;
  } B;
} M_CAN_ENDN_tag;

typedef union M_CAN_DBTP_union_tag {
  vuint32_t R;
  struct {
    vuint32_t     :8;
    vuint32_t TDC :1;
    vuint32_t     :2;
    vuint32_t DBRP:5;
    vuint32_t     :3;
    vuint32_t DTSEG1:5;
    vuint32_t DTSEG2:4;
    vuint32_t DSJW  :4;
  } B;
} M_CAN_DBTP_tag;

typedef union M_CAN_TEST_union_tag {   /* Test Register */
  vuint32_t R;
  struct {
    vuint32_t     :10;
    vuint32_t SVAL :1;
    vuint32_t TXBNS:5;
    vuint32_t     :2;
    vuint32_t PVAL :1;
    vuint32_t TXBNP:5;
    vuint32_t RX   :1;
    vuint32_t TX   :2;
    vuint32_t LBCK :1;
    vuint32_t     :4;
  } B;
} M_CAN_TEST_tag;

typedef union M_CAN_RWD_union_tag {    /* RAM Watchdog Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t WDV:8;
    vuint32_t WDC:8;
  } B;
} M_CAN_RWD_tag;

typedef union M_CAN_CCCR_union_tag {   /* CC Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t NISO :1;
    vuint32_t TXP  :1;
    vuint32_t EFBI :1;
    vuint32_t PXHD :1;
    vuint32_t WMM  :1;
    vuint32_t UTSU :1;
    vuint32_t BRSE :1;
    vuint32_t FDOE :1;
    vuint32_t TEST :1;
    vuint32_t DAR  :1;
    vuint32_t MON  :1;
    vuint32_t CSR  :1;
    vuint32_t CSA  :1;
    vuint32_t ASM  :1;
    vuint32_t CCE  :1;
    vuint32_t INIT :1;
  } B;
} M_CAN_CCCR_tag;

typedef union M_CAN_NBTP_union_tag {    /* Bit Timing and Prescaler Register */
  vuint32_t R;
  struct {
    vuint32_t NSJW   :7;
    vuint32_t NBRP   :9;
    vuint32_t NTSEG1 :8;
    vuint32_t        :1;
    vuint32_t NTSEG2 :7;
  } B;
} M_CAN_NBTP_tag;

typedef union M_CAN_TSCC_union_tag {   /* Timestamp Counter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t TCP:4;
    vuint32_t  :14;
    vuint32_t TSS:2;
  } B;
} M_CAN_TSCC_tag;

typedef union M_CAN_TSCV_union_tag {   /* Timestamp Counter Value Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TSC:16;                  /* Timestamp Counter */
  } B;
} M_CAN_TSCV_tag;

typedef union M_CAN_TOCC_union_tag {   /* Timeout Counter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t TOP:16;
    vuint32_t  :13;
    vuint32_t TOS:2;
    vuint32_t ETOC:1;
  } B;
} M_CAN_TOCC_tag;

typedef union M_CAN_TOCV_union_tag {   /* Timeout Counter Value Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t TOC:16;
  } B;
} M_CAN_TOCV_tag;

typedef union M_CAN_ECR_union_tag {    /* Error Counter Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t CEL:8;
    vuint32_t RP:1;
    vuint32_t REC:7;
    vuint32_t TEC:8;
  } B;
} M_CAN_ECR_tag;

typedef union M_CAN_PSR_union_tag {    /* Protocol Status Register */
  vuint32_t R;
  struct {
    vuint32_t     :9;
    vuint32_t TDCV:7;
    vuint32_t     :1;
    vuint32_t PXE :1;
    vuint32_t RFDF:1;
    vuint32_t RBRS:1;
    vuint32_t RESI:1;
    vuint32_t DLEC:3;
    vuint32_t BO  :1;
    vuint32_t EW  :1;
    vuint32_t EP  :1;
    vuint32_t ACT :2;
    vuint32_t LEC :3;
  } B;
} M_CAN_PSR_tag;

typedef union M_CAN_TDCR_union_tag {
  vuint32_t R;
  struct {
    vuint32_t     :17;
    vuint32_t TDCO:7;
    vuint32_t     :1;
    vuint32_t TDCF:7;
  } B;
} M_CAN_TDCR_tag;
typedef union M_CAN_IR_union_tag {     /* Interrupt Register */
  vuint32_t R;
  struct {
    vuint32_t    :2;
    vuint32_t ARA:1;
    vuint32_t PED:1;
    vuint32_t PEA:1;
    vuint32_t WDI:1;
    vuint32_t BO:1;
    vuint32_t EW:1;
    vuint32_t EP:1;
    vuint32_t ELO:1;
    vuint32_t BEU:1;
    vuint32_t BEC:1;
    vuint32_t DRX:1;                   /* Message stored to Dedicated Rx Buffer */
    vuint32_t TOO:1;
    vuint32_t MRAF:1;                  /* Message RAM Access Failure */
    vuint32_t TSW:1;
    vuint32_t TEFL:1;
    vuint32_t TEFF:1;
    vuint32_t TEFW:1;
    vuint32_t TEFN:1;
    vuint32_t TFE:1;
    vuint32_t TCF:1;
    vuint32_t TC:1;
    vuint32_t HPM:1;
    vuint32_t RF1L:1;
    vuint32_t RF1F:1;
    vuint32_t RF1W:1;
    vuint32_t RF1N:1;
    vuint32_t RF0L:1;
    vuint32_t RF0F:1;
    vuint32_t RF0W:1;
    vuint32_t RF0N:1;
  } B;
} M_CAN_IR_tag;

typedef union M_CAN_IE_union_tag {     /* Interrupt Enable Register */
  vuint32_t R;
  struct {
    vuint32_t    :2;
    vuint32_t ARAE:1;
    vuint32_t PEDE:1;
    vuint32_t PEAE:1;
    vuint32_t WDIE:1;
    vuint32_t BOE:1;
    vuint32_t EWE:1;
    vuint32_t EPE:1;
    vuint32_t ELOE:1;
    vuint32_t BEUE:1;
    vuint32_t BECE:1;
    vuint32_t DRXE:1;                  /* Message stored to Dedicated Rx Buffer Interrupt Enable */
    vuint32_t TOOE:1;
    vuint32_t MRAFE:1;
    vuint32_t TSWE:1;
    vuint32_t TEFLE:1;
    vuint32_t TEFFE:1;
    vuint32_t TEFWE:1;
    vuint32_t TEFNE:1;
    vuint32_t TFEE:1;
    vuint32_t TCFE:1;
    vuint32_t TCE:1;
    vuint32_t HPME:1;
    vuint32_t RF1LE:1;
    vuint32_t RF1FE:1;
    vuint32_t RF1WE:1;
    vuint32_t RF1NE:1;
    vuint32_t RF0LE:1;
    vuint32_t RF0FE:1;
    vuint32_t RF0WE:1;
    vuint32_t RF0NE:1;
  } B;
} M_CAN_IE_tag;

typedef union M_CAN_ILS_union_tag {    /* Interrupt Line Select Register */
  vuint32_t R;
  struct {
    vuint32_t    :2;
    vuint32_t ARAL:1;
    vuint32_t PEDL:1;
    vuint32_t PEAL:1;
    vuint32_t WDIL:1;
    vuint32_t BOL:1;
    vuint32_t EWL:1;
    vuint32_t EPL:1;
    vuint32_t ELOL:1;
    vuint32_t BEUL:1;
    vuint32_t BECL:1;
    vuint32_t DRXL:1;                  /* Message stored to Dedicated Rx Buffer Interrupt Line */
    vuint32_t TOOL:1;
    vuint32_t MRAFL:1;
    vuint32_t TSWL:1;
    vuint32_t TEFLL:1;
    vuint32_t TEFFL:1;
    vuint32_t TEFWL:1;
    vuint32_t TEFNL:1;
    vuint32_t TFEL:1;
    vuint32_t TCFL:1;
    vuint32_t TCL:1;
    vuint32_t HPML:1;
    vuint32_t RF1LL:1;
    vuint32_t RF1FL:1;
    vuint32_t RF1WL:1;
    vuint32_t RF1NL:1;
    vuint32_t RF0LL:1;
    vuint32_t RF0FL:1;
    vuint32_t RF0WL:1;
    vuint32_t RF0NL:1;
  } B;
} M_CAN_ILS_tag;

typedef union M_CAN_ILE_union_tag {    /* Interrupt Line Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :30;
    vuint32_t EINT1:1;
    vuint32_t EINT0:1;
  } B;
} M_CAN_ILE_tag;

typedef union M_CAN_GFC_union_tag {    /* Global Filter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t ANFS:2;
    vuint32_t ANFE:2;
    vuint32_t RRFS:1;
    vuint32_t RRFE:1;
  } B;
} M_CAN_GFC_tag;

typedef union M_CAN_SIDFC_union_tag {  /* Standard ID Filter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t LSS:8;
    vuint32_t FLSSA:14;
    vuint32_t  :2;
  } B;
} M_CAN_SIDFC_tag;

typedef union M_CAN_XIDFC_union_tag {  /* Extended ID Filter Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :9;
    vuint32_t LSE:7;
    vuint32_t FLESA:14;
    vuint32_t  :2;
  } B;
} M_CAN_XIDFC_tag;

typedef union M_CAN_XIDAM_union_tag {  /* Extended ID and Mask Register */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t EIDM:29;
  } B;
} M_CAN_XIDAM_tag;

typedef union M_CAN_HPMS_union_tag {   /* High Priority Message Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t FLST:1;
    vuint32_t FIDX:7;
    vuint32_t MSI:2;
    vuint32_t BIDX:6;
  } B;
} M_CAN_HPMS_tag;

typedef union M_CAN_NDAT1_union_tag {  /* New Data 1 Register */
  vuint32_t R;
  struct {
    vuint32_t ND1:32;                  /* New Data[0:31] */
  } B;
} M_CAN_NDAT1_tag;

typedef union M_CAN_NDAT2_union_tag {  /* New Data 2 Register */
  vuint32_t R;
  struct {
    vuint32_t ND2:32;                  /* New Data[32:63] */
  } B;
} M_CAN_NDAT2_tag;

typedef union M_CAN_RXF0C_union_tag {  /* Rx FIFO 0 Configuration */
  vuint32_t R;
  struct {
    vuint32_t F0OM:1;                  /* FIFO 0 Operation Mode */
    vuint32_t F0WM:7;
    vuint32_t  :1;
    vuint32_t F0S:7;
    vuint32_t F0SA:14;
    vuint32_t  :2;
  } B;
} M_CAN_RXF0C_tag;

typedef union M_CAN_RXF0S_union_tag {  /* Rx FIFO 0 Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t RF0L:1;
    vuint32_t F0F:1;
    vuint32_t  :2;
    vuint32_t F0PI:6;                  /* Rx FIFO 0 Put Index */
    vuint32_t  :2;
    vuint32_t F0GI:6;
    vuint32_t  :1;
    vuint32_t F0FL:7;
  } B;
} M_CAN_RXF0S_tag;

typedef union M_CAN_RXF0A_union_tag {  /* Rx FIFO 0 Acknowledge Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t F0AI:6;
  } B;
} M_CAN_RXF0A_tag;

typedef union M_CAN_RXBC_union_tag {   /* Rx Buffer Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t RBSA:14;                 /* Rx Buffer Start Address */
    vuint32_t  :2;
  } B;
} M_CAN_RXBC_tag;

typedef union M_CAN_RXF1C_union_tag {  /* Rx FIFO 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t F1OM:1;                  /* FIFO 1 Operation Mode */
    vuint32_t F1WM:7;
    vuint32_t  :1;
    vuint32_t F1S:7;
    vuint32_t F1SA:14;
    vuint32_t  :2;
  } B;
} M_CAN_RXF1C_tag;

typedef union M_CAN_RXF1S_union_tag {  /* Rx FIFO 1 Status Register */
  vuint32_t R;
  struct {
    vuint32_t DMS:2;
    vuint32_t  :4;
    vuint32_t RF1L:1;
    vuint32_t F1F:1;
    vuint32_t  :2;
    vuint32_t F1PI:6;                  /* Rx FIFO 1 Put Index */
    vuint32_t  :2;
    vuint32_t F1G1:6;
    vuint32_t  :1;
    vuint32_t F1FL:7;
  } B;
} M_CAN_RXF1S_tag;

typedef union M_CAN_RXF1A_union_tag {  /* Rx FIFO 1 Acknowledge Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t F1AI:6;
  } B;
} M_CAN_RXF1A_tag;

typedef union M_CAN_RXESC_union_tag {  /* Rx Buffer / FIFO Element Size Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t RBDS:3;                  /* Rx Buffer Data Field Size */
    vuint32_t  :1;
    vuint32_t F1DS:3;                  /* Rx FIFO 1 Data Field Size */
    vuint32_t  :1;
    vuint32_t F0DS:3;                  /* Rx FIFO 0 Data Field Size */
  } B;
} M_CAN_RXESC_tag;

typedef union M_CAN_TXBC_union_tag {   /* Tx Buffer Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t TQFM:1;
    vuint32_t TQFS:6;
    vuint32_t  :2;
    vuint32_t NDTB:6;
    vuint32_t TBSA:14;
    vuint32_t  :2;
  } B;
} M_CAN_TXBC_tag;

typedef union M_CAN_TXFQS_union_tag {  /* Tx FIFO/Queue Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :10;
    vuint32_t TFQF:1;
    vuint32_t TFQPI:5;
    vuint32_t  :3;
    vuint32_t TFGI:5;                  /* Tx FIFO Get Index */
    vuint32_t  :2;
    vuint32_t TFFL:6;
  } B;
} M_CAN_TXFQS_tag;

typedef union M_CAN_TXESC_union_tag {  /* Tx Buffer Element Size Configuration */
  vuint32_t R;
  struct {
    vuint32_t  :29;
    vuint32_t TBDS:3;
  } B;
} M_CAN_TXESC_tag;

typedef union M_CAN_TXBRP_union_tag {  /* Tx Buffer Request Pending Register */
  vuint32_t R;
  struct {
    vuint32_t TRP:32;                  /* Transmission Request Pending */
  } B;
} M_CAN_TXBRP_tag;

typedef union M_CAN_TXBAR_union_tag {  /* Tx Buffer Add Request register */
  vuint32_t R;
  struct {
    vuint32_t AR:32;                   /* Add Request */
  } B;
} M_CAN_TXBAR_tag;

typedef union M_CAN_TXBCR_union_tag {  /* Tx Buffer Cancellation Request register */
  vuint32_t R;
  struct {
    vuint32_t CR:32;                   /* Cancellation Request */
  } B;
} M_CAN_TXBCR_tag;

typedef union M_CAN_TXBTO_union_tag {  /* Tx Buffer Transmission Occurred register */
  vuint32_t R;
  struct {
    vuint32_t TO:32;                   /* Transmission Occurred */
  } B;
} M_CAN_TXBTO_tag;

typedef union M_CAN_TXBCF_union_tag {  /* Tx Buffer Cancellation Finished register */
  vuint32_t R;
  struct {
    vuint32_t CF:32;                   /* Cancellation Finished */
  } B;
} M_CAN_TXBCF_tag;

typedef union M_CAN_TXBTIE_union_tag { /* Tx Buffer Transmission Interrupt Enable register */
  vuint32_t R;
  struct {
    vuint32_t TIE:32;
  } B;
} M_CAN_TXBTIE_tag;

typedef union M_CAN_TXBCIE_union_tag { /* Tx Buffer Cancellation Finished Interrupt Enable register */
  vuint32_t R;
  struct {
    vuint32_t CFIE:32;
  } B;
} M_CAN_TXBCIE_tag;

typedef union M_CAN_TXEFC_union_tag {  /* Tx Event FIFO Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t EFWM:6;
    vuint32_t  :2;
    vuint32_t EFS:6;
    vuint32_t EFSA:14;
    vuint32_t  :2;
  } B;
} M_CAN_TXEFC_tag;

typedef union M_CAN_TXEFS_union_tag {  /* Tx Event FIFO Status register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t TEFL:1;
    vuint32_t EFF:1;
    vuint32_t  :3;
    vuint32_t EFPI:5;
    vuint32_t  :3;
    vuint32_t EFGI:5;
    vuint32_t  :2;
    vuint32_t EFFL:6;
  } B;
} M_CAN_TXEFS_tag;

typedef union M_CAN_TXEFA_union_tag {  /* Tx Event FIFO Acknowledge register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t EFAI:5;
  } B;
} M_CAN_TXEFA_tag;

struct M_CAN_tag {
  M_CAN_CREL_tag CREL;                 /* Core Release Register */
  M_CAN_ENDN_tag ENDN;                 /* Endian Register */
  uint8_t M_CAN_reserved0[4];
  M_CAN_DBTP_tag DBTP;                 /* Fast Bit Timing and Prescaler Register */
  M_CAN_TEST_tag TEST;                 /* Test Register */
  M_CAN_RWD_tag RWD;                   /* RAM Watchdog Register */
  M_CAN_CCCR_tag CCCR;                 /* CC Control Register */
  M_CAN_NBTP_tag NBTP;                   /* Bit Timing and Prescaler Register */
  M_CAN_TSCC_tag TSCC;                 /* Timestamp Counter Configuration Register */
  M_CAN_TSCV_tag TSCV;                 /* Timestamp Counter Value Register */
  M_CAN_TOCC_tag TOCC;                 /* Timeout Counter Configuration Register */
  M_CAN_TOCV_tag TOCV;                 /* Timeout Counter Value Register */
  uint8_t M_CAN_reserved1[16];
  M_CAN_ECR_tag ECR;                   /* Error Counter Register */
  M_CAN_PSR_tag PSR;                   /* Protocol Status Register */
  M_CAN_TDCR_tag TDCR;
  uint8_t M_CAN_reserved2[4];
  M_CAN_IR_tag IR;                     /* Interrupt Register */
  M_CAN_IE_tag IE;                     /* Interrupt Enable Register */
  M_CAN_ILS_tag ILS;                   /* Interrupt Line Select Register */
  M_CAN_ILE_tag ILE;                   /* Interrupt Line Enable Register */
  uint8_t M_CAN_reserved3[32];
  M_CAN_GFC_tag GFC;                   /* Global Filter Configuration Register */
  M_CAN_SIDFC_tag SIDFC;               /* Standard ID Filter Configuration Register */
  M_CAN_XIDFC_tag XIDFC;               /* Extended ID Filter Configuration Register */
  uint8_t M_CAN_reserved4[4];
  M_CAN_XIDAM_tag XIDAM;               /* Extended ID and Mask Register */
  M_CAN_HPMS_tag HPMS;                 /* High Priority Message Status Register */
  M_CAN_NDAT1_tag NDAT1;               /* New Data 1 Register */
  M_CAN_NDAT2_tag NDAT2;               /* New Data 2 Register */
  M_CAN_RXF0C_tag RXF0C;               /* Rx FIFO 0 Configuration */
  M_CAN_RXF0S_tag RXF0S;               /* Rx FIFO 0 Status Register */
  M_CAN_RXF0A_tag RXF0A;               /* Rx FIFO 0 Acknowledge Register */
  M_CAN_RXBC_tag RXBC;                 /* Rx Buffer Configuration Register */
  M_CAN_RXF1C_tag RXF1C;               /* Rx FIFO 1 Configuration Register */
  M_CAN_RXF1S_tag RXF1S;               /* Rx FIFO 1 Status Register */
  M_CAN_RXF1A_tag RXF1A;               /* Rx FIFO 1 Acknowledge Register */
  M_CAN_RXESC_tag RXESC;               /* Rx Buffer / FIFO Element Size Configuration Register */
  M_CAN_TXBC_tag TXBC;                 /* Tx Buffer Configuration Register */
  M_CAN_TXFQS_tag TXFQS;               /* Tx FIFO/Queue Status Register */
  M_CAN_TXESC_tag TXESC;               /* Tx Buffer Element Size Configuration */
  M_CAN_TXBRP_tag TXBRP;               /* Tx Buffer Request Pending Register */
  M_CAN_TXBAR_tag TXBAR;               /* Tx Buffer Add Request register */
  M_CAN_TXBCR_tag TXBCR;               /* Tx Buffer Cancellation Request register */
  M_CAN_TXBTO_tag TXBTO;               /* Tx Buffer Transmission Occurred register */
  M_CAN_TXBCF_tag TXBCF;               /* Tx Buffer Cancellation Finished register */
  M_CAN_TXBTIE_tag TXBTIE;             /* Tx Buffer Transmission Interrupt Enable register */
  M_CAN_TXBCIE_tag TXBCIE;             /* Tx Buffer Cancellation Finished Interrupt Enable register */
  uint8_t M_CAN_reserved5[8];
  M_CAN_TXEFC_tag TXEFC;               /* Tx Event FIFO Configuration Register */
  M_CAN_TXEFS_tag TXEFS;               /* Tx Event FIFO Status register */
  M_CAN_TXEFA_tag TXEFA;               /* Tx Event FIFO Acknowledge register */
};

#endif
