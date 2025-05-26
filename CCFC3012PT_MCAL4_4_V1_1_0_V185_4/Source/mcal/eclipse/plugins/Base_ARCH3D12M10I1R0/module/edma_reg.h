#ifndef EDMA_REG_H_
#define EDMA_REG_H_

/* ============================================================================
   =============================== Module: eDMA ===============================
   ============================================================================ */

typedef union eDMA_CR_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t CX:1;
    vuint32_t ECX:1;
    vuint32_t GRP3PRI:2;
    vuint32_t GRP2PRI:2;
    vuint32_t GRP1PRI:2;
    vuint32_t GRP0PRI:2;
    vuint32_t EMLM:1;
    vuint32_t CLM:1;
    vuint32_t HALT:1;
    vuint32_t HOE:1;
    vuint32_t ERGA:1;
    vuint32_t ERCA:1;
    vuint32_t EDBG:1;
    vuint32_t  :1;
  } B;
} eDMA_CR_tag;

typedef union eDMA_ES_union_tag {      /* Error Status */
  vuint32_t R;
  struct {
    vuint32_t VLD:1;
    vuint32_t  :13;
    vuint32_t UCE:1;
    vuint32_t ECX:1;
    vuint32_t GPE:1;
    vuint32_t CPE:1;
    vuint32_t ERRCHN:6;
    vuint32_t SAE:1;
    vuint32_t SOE:1;
    vuint32_t DAE:1;
    vuint32_t DOE:1;
    vuint32_t NCE:1;
    vuint32_t SGE:1;
    vuint32_t SBE:1;
    vuint32_t DBE:1;
  } B;
} eDMA_ES_tag;

typedef union eDMA_ERQH_union_tag {    /* Enable Request Register High */
  vuint32_t R;
  struct {
    vuint32_t ERQ63:1;
    vuint32_t ERQ62:1;
    vuint32_t ERQ61:1;
    vuint32_t ERQ60:1;
    vuint32_t ERQ59:1;
    vuint32_t ERQ58:1;
    vuint32_t ERQ57:1;
    vuint32_t ERQ56:1;
    vuint32_t ERQ55:1;
    vuint32_t ERQ54:1;
    vuint32_t ERQ53:1;
    vuint32_t ERQ52:1;
    vuint32_t ERQ51:1;
    vuint32_t ERQ50:1;
    vuint32_t ERQ49:1;
    vuint32_t ERQ48:1;
    vuint32_t ERQ47:1;
    vuint32_t ERQ46:1;
    vuint32_t ERQ45:1;
    vuint32_t ERQ44:1;
    vuint32_t ERQ43:1;
    vuint32_t ERQ42:1;
    vuint32_t ERQ41:1;
    vuint32_t ERQ40:1;
    vuint32_t ERQ39:1;
    vuint32_t ERQ38:1;
    vuint32_t ERQ37:1;
    vuint32_t ERQ36:1;
    vuint32_t ERQ35:1;
    vuint32_t ERQ34:1;
    vuint32_t ERQ33:1;
    vuint32_t ERQ32:1;
  } B;
} eDMA_ERQH_tag;

typedef union eDMA_ERQL_union_tag {    /* Enable Request Register Low */
  vuint32_t R;
  struct {
    vuint32_t ERQ31:1;
    vuint32_t ERQ30:1;
    vuint32_t ERQ29:1;
    vuint32_t ERQ28:1;
    vuint32_t ERQ27:1;
    vuint32_t ERQ26:1;
    vuint32_t ERQ25:1;
    vuint32_t ERQ24:1;
    vuint32_t ERQ23:1;
    vuint32_t ERQ22:1;
    vuint32_t ERQ21:1;
    vuint32_t ERQ20:1;
    vuint32_t ERQ19:1;
    vuint32_t ERQ18:1;
    vuint32_t ERQ17:1;
    vuint32_t ERQ16:1;
    vuint32_t ERQ15:1;
    vuint32_t ERQ14:1;
    vuint32_t ERQ13:1;
    vuint32_t ERQ12:1;
    vuint32_t ERQ11:1;
    vuint32_t ERQ10:1;
    vuint32_t ERQ9:1;
    vuint32_t ERQ8:1;
    vuint32_t ERQ7:1;
    vuint32_t ERQ6:1;
    vuint32_t ERQ5:1;
    vuint32_t ERQ4:1;
    vuint32_t ERQ3:1;
    vuint32_t ERQ2:1;
    vuint32_t ERQ1:1;
    vuint32_t ERQ0:1;
  } B;
} eDMA_ERQL_tag;

typedef union eDMA_EEIH_union_tag {    /* Enable Error Interrupt Register High */
  vuint32_t R;
  struct {
    vuint32_t EEI63:1;
    vuint32_t EEI62:1;
    vuint32_t EEI61:1;
    vuint32_t EEI60:1;
    vuint32_t EEI59:1;
    vuint32_t EEI58:1;
    vuint32_t EEI57:1;
    vuint32_t EEI56:1;
    vuint32_t EEI55:1;
    vuint32_t EEI54:1;
    vuint32_t EEI53:1;
    vuint32_t EEI52:1;
    vuint32_t EEI51:1;
    vuint32_t EEI50:1;
    vuint32_t EEI49:1;
    vuint32_t EEI48:1;
    vuint32_t EEI47:1;
    vuint32_t EEI46:1;
    vuint32_t EEI45:1;
    vuint32_t EEI44:1;
    vuint32_t EEI43:1;
    vuint32_t EEI42:1;
    vuint32_t EEI41:1;
    vuint32_t EEI40:1;
    vuint32_t EEI39:1;
    vuint32_t EEI38:1;
    vuint32_t EEI37:1;
    vuint32_t EEI36:1;
    vuint32_t EEI35:1;
    vuint32_t EEI34:1;
    vuint32_t EEI33:1;
    vuint32_t EEI32:1;
  } B;
} eDMA_EEIH_tag;

typedef union eDMA_EEIL_union_tag {    /* Enable Error Interrupt Register Low */
  vuint32_t R;
  struct {
    vuint32_t EEI31:1;
    vuint32_t EEI30:1;
    vuint32_t EEI29:1;
    vuint32_t EEI28:1;
    vuint32_t EEI27:1;
    vuint32_t EEI26:1;
    vuint32_t EEI25:1;
    vuint32_t EEI24:1;
    vuint32_t EEI23:1;
    vuint32_t EEI22:1;
    vuint32_t EEI21:1;
    vuint32_t EEI20:1;
    vuint32_t EEI19:1;
    vuint32_t EEI18:1;
    vuint32_t EEI17:1;
    vuint32_t EEI16:1;
    vuint32_t EEI15:1;
    vuint32_t EEI14:1;
    vuint32_t EEI13:1;
    vuint32_t EEI12:1;
    vuint32_t EEI11:1;
    vuint32_t EEI10:1;
    vuint32_t EEI9:1;
    vuint32_t EEI8:1;
    vuint32_t EEI7:1;
    vuint32_t EEI6:1;
    vuint32_t EEI5:1;
    vuint32_t EEI4:1;
    vuint32_t EEI3:1;
    vuint32_t EEI2:1;
    vuint32_t EEI1:1;
    vuint32_t EEI0:1;
  } B;
} eDMA_EEIL_tag;

typedef union eDMA_SERQ_union_tag {    /* Set Enable Request Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t SAER:1;
    vuint8_t SERQ:6;
  } B;
} eDMA_SERQ_tag;

typedef union eDMA_CERQ_union_tag {    /* Clear Enable Request Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CAER:1;
    vuint8_t CERQ:6;
  } B;
} eDMA_CERQ_tag;

typedef union eDMA_SEEI_union_tag {    /* Set Enable Error Interrupt Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t SAEE:1;
    vuint8_t SEEI:6;
  } B;
} eDMA_SEEI_tag;

typedef union eDMA_CEEI_union_tag {    /* Clear Enable Error Interrupt Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CAEE:1;
    vuint8_t CEEI:6;
  } B;
} eDMA_CEEI_tag;

typedef union eDMA_CINT_union_tag {    /* Clear Interrupt Request Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CAIR:1;
    vuint8_t CINT:6;
  } B;
} eDMA_CINT_tag;

typedef union eDMA_CERR_union_tag {    /* Clear Error Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CAEI:1;
    vuint8_t CERR:6;
  } B;
} eDMA_CERR_tag;

typedef union eDMA_SSRT_union_tag {    /* Set START Bit Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t SAST:1;
    vuint8_t SSRT:6;
  } B;
} eDMA_SSRT_tag;

typedef union eDMA_CDNE_union_tag {    /* Clear DONE Status Bit Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CADN:1;
    vuint8_t CDNE:6;
  } B;
} eDMA_CDNE_tag;

typedef union eDMA_INTH_union_tag {    /* Interrupt Request Register High */
  vuint32_t R;
  struct {
    vuint32_t INT63:1;
    vuint32_t INT62:1;
    vuint32_t INT61:1;
    vuint32_t INT60:1;
    vuint32_t INT59:1;
    vuint32_t INT58:1;
    vuint32_t INT57:1;
    vuint32_t INT56:1;
    vuint32_t INT55:1;
    vuint32_t INT54:1;
    vuint32_t INT53:1;
    vuint32_t INT52:1;
    vuint32_t INT51:1;
    vuint32_t INT50:1;
    vuint32_t INT49:1;
    vuint32_t INT48:1;
    vuint32_t INT47:1;
    vuint32_t INT46:1;
    vuint32_t INT45:1;
    vuint32_t INT44:1;
    vuint32_t INT43:1;
    vuint32_t INT42:1;
    vuint32_t INT41:1;
    vuint32_t INT40:1;
    vuint32_t INT39:1;
    vuint32_t INT38:1;
    vuint32_t INT37:1;
    vuint32_t INT36:1;
    vuint32_t INT35:1;
    vuint32_t INT34:1;
    vuint32_t INT33:1;
    vuint32_t INT32:1;
  } B;
} eDMA_INTH_tag;

typedef union eDMA_INTL_union_tag {    /* Interrupt Request Register Low */
  vuint32_t R;
  struct {
    vuint32_t INT31:1;
    vuint32_t INT30:1;
    vuint32_t INT29:1;
    vuint32_t INT28:1;
    vuint32_t INT27:1;
    vuint32_t INT26:1;
    vuint32_t INT25:1;
    vuint32_t INT24:1;
    vuint32_t INT23:1;
    vuint32_t INT22:1;
    vuint32_t INT21:1;
    vuint32_t INT20:1;
    vuint32_t INT19:1;
    vuint32_t INT18:1;
    vuint32_t INT17:1;
    vuint32_t INT16:1;
    vuint32_t INT15:1;
    vuint32_t INT14:1;
    vuint32_t INT13:1;
    vuint32_t INT12:1;
    vuint32_t INT11:1;
    vuint32_t INT10:1;
    vuint32_t INT9:1;
    vuint32_t INT8:1;
    vuint32_t INT7:1;
    vuint32_t INT6:1;
    vuint32_t INT5:1;
    vuint32_t INT4:1;
    vuint32_t INT3:1;
    vuint32_t INT2:1;
    vuint32_t INT1:1;
    vuint32_t INT0:1;
  } B;
} eDMA_INTL_tag;

typedef union eDMA_ERRH_union_tag {    /* Error Register High */
  vuint32_t R;
  struct {
    vuint32_t ERR63:1;
    vuint32_t ERR62:1;
    vuint32_t ERR61:1;
    vuint32_t ERR60:1;
    vuint32_t ERR59:1;
    vuint32_t ERR58:1;
    vuint32_t ERR57:1;
    vuint32_t ERR56:1;
    vuint32_t ERR55:1;
    vuint32_t ERR54:1;
    vuint32_t ERR53:1;
    vuint32_t ERR52:1;
    vuint32_t ERR51:1;
    vuint32_t ERR50:1;
    vuint32_t ERR49:1;
    vuint32_t ERR48:1;
    vuint32_t ERR47:1;
    vuint32_t ERR46:1;
    vuint32_t ERR45:1;
    vuint32_t ERR44:1;
    vuint32_t ERR43:1;
    vuint32_t ERR42:1;
    vuint32_t ERR41:1;
    vuint32_t ERR40:1;
    vuint32_t ERR39:1;
    vuint32_t ERR38:1;
    vuint32_t ERR37:1;
    vuint32_t ERR36:1;
    vuint32_t ERR35:1;
    vuint32_t ERR34:1;
    vuint32_t ERR33:1;
    vuint32_t ERR32:1;
  } B;
} eDMA_ERRH_tag;

typedef union eDMA_ERRL_union_tag {    /* Error Register Low */
  vuint32_t R;
  struct {
    vuint32_t ERR31:1;
    vuint32_t ERR30:1;
    vuint32_t ERR29:1;
    vuint32_t ERR28:1;
    vuint32_t ERR27:1;
    vuint32_t ERR26:1;
    vuint32_t ERR25:1;
    vuint32_t ERR24:1;
    vuint32_t ERR23:1;
    vuint32_t ERR22:1;
    vuint32_t ERR21:1;
    vuint32_t ERR20:1;
    vuint32_t ERR19:1;
    vuint32_t ERR18:1;
    vuint32_t ERR17:1;
    vuint32_t ERR16:1;
    vuint32_t ERR15:1;
    vuint32_t ERR14:1;
    vuint32_t ERR13:1;
    vuint32_t ERR12:1;
    vuint32_t ERR11:1;
    vuint32_t ERR10:1;
    vuint32_t ERR9:1;
    vuint32_t ERR8:1;
    vuint32_t ERR7:1;
    vuint32_t ERR6:1;
    vuint32_t ERR5:1;
    vuint32_t ERR4:1;
    vuint32_t ERR3:1;
    vuint32_t ERR2:1;
    vuint32_t ERR1:1;
    vuint32_t ERR0:1;
  } B;
} eDMA_ERRL_tag;

typedef union eDMA_HRSH_union_tag {    /* Hardware Request Status Register High */
  vuint32_t R;
  struct {
    vuint32_t HRS63:1;
    vuint32_t HRS62:1;
    vuint32_t HRS61:1;
    vuint32_t HRS60:1;
    vuint32_t HRS59:1;
    vuint32_t HRS58:1;
    vuint32_t HRS57:1;
    vuint32_t HRS56:1;
    vuint32_t HRS55:1;
    vuint32_t HRS54:1;
    vuint32_t HRS53:1;
    vuint32_t HRS52:1;
    vuint32_t HRS51:1;
    vuint32_t HRS50:1;
    vuint32_t HRS49:1;
    vuint32_t HRS48:1;
    vuint32_t HRS47:1;
    vuint32_t HRS46:1;
    vuint32_t HRS45:1;
    vuint32_t HRS44:1;
    vuint32_t HRS43:1;
    vuint32_t HRS42:1;
    vuint32_t HRS41:1;
    vuint32_t HRS40:1;
    vuint32_t HRS39:1;
    vuint32_t HRS38:1;
    vuint32_t HRS37:1;
    vuint32_t HRS36:1;
    vuint32_t HRS35:1;
    vuint32_t HRS34:1;
    vuint32_t HRS33:1;
    vuint32_t HRS32:1;
  } B;
} eDMA_HRSH_tag;

typedef union eDMA_HRSL_union_tag {    /* Hardware Request Status Register Low */
  vuint32_t R;
  struct {
    vuint32_t HRS31:1;
    vuint32_t HRS30:1;
    vuint32_t HRS29:1;
    vuint32_t HRS28:1;
    vuint32_t HRS27:1;
    vuint32_t HRS26:1;
    vuint32_t HRS25:1;
    vuint32_t HRS24:1;
    vuint32_t HRS23:1;
    vuint32_t HRS22:1;
    vuint32_t HRS21:1;
    vuint32_t HRS20:1;
    vuint32_t HRS19:1;
    vuint32_t HRS18:1;
    vuint32_t HRS17:1;
    vuint32_t HRS16:1;
    vuint32_t HRS15:1;
    vuint32_t HRS14:1;
    vuint32_t HRS13:1;
    vuint32_t HRS12:1;
    vuint32_t HRS11:1;
    vuint32_t HRS10:1;
    vuint32_t HRS9:1;
    vuint32_t HRS8:1;
    vuint32_t HRS7:1;
    vuint32_t HRS6:1;
    vuint32_t HRS5:1;
    vuint32_t HRS4:1;
    vuint32_t HRS3:1;
    vuint32_t HRS2:1;
    vuint32_t HRS1:1;
    vuint32_t HRS0:1;
  } B;
} eDMA_HRSL_tag;

typedef union eDMA_DCHPRI_union_tag {  /* Channel Priority Register */
  vuint8_t R;
  struct {
    vuint8_t ECP:1;
    vuint8_t DPA:1;
    vuint8_t GRPPRI:2;
    vuint8_t CHPRI:4;
  } B;
} eDMA_DCHPRI_tag;

typedef union eDMA_DCHMID_union_tag {  /* Channel Master ID Register */
  vuint8_t R;
  struct {
    vuint8_t EMI:1;
    vuint8_t PAL:1;
    vuint8_t  :2;
    vuint8_t MID:4;
  } B;
} eDMA_DCHMID_tag;

typedef union eDMA_TCD_SADDR_union_tag { /* TCD Source Address */
  vuint32_t R;
  struct {
    vuint32_t SADDR:32;
  } B;
} eDMA_TCD_SADDR_tag;

typedef union eDMA_TCD_ATTR_union_tag { /* TCD Transfer Attributes */
  vuint16_t R;
  struct {
    vuint16_t SMOD:5;
    vuint16_t SSIZE:3;
    vuint16_t DMOD:5;
    vuint16_t DSIZE:3;
  } B;
} eDMA_TCD_ATTR_tag;

typedef union eDMA_TCD_SOFF_union_tag { /* TCD Signed Source Address Offset */
  vuint16_t R;
  struct {
    vuint16_t SOFF:16;
  } B;
} eDMA_TCD_SOFF_tag;

typedef union eDMA_TCD_NBYTES_MLNO_union_tag { /* TCD Minor Byte Count Minor Loop Disabled */
  vuint32_t R;
  struct {
    vuint32_t NBYTES:32;
  } B;
} eDMA_TCD_NBYTES_MLNO_tag;

typedef union eDMA_TCD_NBYTES_MLOFFNO_union_tag { /* TCD Signed Minor Loop Offset Minor Loop Enabled and Offset Disabled */
  vuint32_t R;
  struct {
    vuint32_t SMLOE:1;
    vuint32_t DMLOE:1;
    vuint32_t NBYTES:30;
  } B;
} eDMA_TCD_NBYTES_MLOFFNO_tag;

typedef union eDMA_TCD_NBYTES_MLOFFYES_union_tag { /* TCD Signed Minor Loop Offset Minor Loop and Offset Enabled */
  vuint32_t R;
  struct {
    vuint32_t SMLOE:1;
    vuint32_t DMLOE:1;
    vuint32_t MLOFF:20;
    vuint32_t NBYTES:10;
  } B;
} eDMA_TCD_NBYTES_MLOFFYES_tag;

typedef union eDMA_TCD_NBYTES_union_tag {
  eDMA_TCD_NBYTES_MLNO_tag MLNO;       /* TCD Minor Byte Count Minor Loop Disabled */
  eDMA_TCD_NBYTES_MLOFFNO_tag MLOFFNO; /* TCD Signed Minor Loop Offset Minor Loop Enabled and Offset Disabled */
  eDMA_TCD_NBYTES_MLOFFYES_tag MLOFFYES; /* TCD Signed Minor Loop Offset Minor Loop and Offset Enabled */
} eDMA_TCD_NBYTES_tag;

typedef union eDMA_TCD_SLAST_union_tag { /* TCD Last Source Address Adjustment */
  vuint32_t R;
  struct {
    vuint32_t SLAST:32;
  } B;
} eDMA_TCD_SLAST_tag;

typedef union eDMA_TCD_DADDR_union_tag { /* TCD Destination Address */
  vuint32_t R;
  struct {
    vuint32_t DADDR:32;
  } B;
} eDMA_TCD_DADDR_tag;

typedef union eDMA_TCD_CITER_ELINKNO_union_tag { /* TCD Current Minor Loop Link, Major Loop Count Channel Linking Disabled */
  vuint16_t R;
  struct {
    vuint16_t ELINK:1;
    vuint16_t CITER:15;
  } B;
} eDMA_TCD_CITER_ELINKNO_tag;

typedef union eDMA_TCD_CITER_ELINKYES_union_tag { /* TCD Current Minor Loop Link, Major Loop Count Channel Linking Enabled */
  vuint16_t R;
  struct {
    vuint16_t ELINK:1;
    vuint16_t LINKCH:6;
    vuint16_t CITER:9;
  } B;
} eDMA_TCD_CITER_ELINKYES_tag;

typedef union eDMA_TCD_CITER_union_tag {
  eDMA_TCD_CITER_ELINKNO_tag ELINKNO;  /* TCD Current Minor Loop Link, Major Loop Count Channel Linking Disabled */
  eDMA_TCD_CITER_ELINKYES_tag ELINKYES; /* TCD Current Minor Loop Link, Major Loop Count Channel Linking Enabled */
} eDMA_TCD_CITER_tag;

typedef union eDMA_TCD_DOFF_union_tag { /* TCD Signed Destination Address Offset */
  vuint16_t R;
  struct {
    vuint16_t DOFF:16;
  } B;
} eDMA_TCD_DOFF_tag;

typedef union eDMA_TCD_DLASTSGA_union_tag { /* TCD Last Destination Address Adjustment/Scatter Gather Address */
  vuint32_t R;
  struct {
    vuint32_t DLASTSGA:32;
  } B;
} eDMA_TCD_DLASTSGA_tag;

typedef union eDMA_TCD_BITER_ELINKNO_union_tag { /* TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Disabled */
  vuint16_t R;
  struct {
    vuint16_t ELINK:1;
    vuint16_t BITER:15;
  } B;
} eDMA_TCD_BITER_ELINKNO_tag;

typedef union eDMA_TCD_BITER_ELINKYES_union_tag { /* TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Enabled */
  vuint16_t R;
  struct {
    vuint16_t ELINK:1;
    vuint16_t LINKCH:6;
    vuint16_t BITER:9;
  } B;
} eDMA_TCD_BITER_ELINKYES_tag;

typedef union eDMA_TCD_BITER_union_tag {
  eDMA_TCD_BITER_ELINKNO_tag ELINKNO;  /* TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Disabled */
  eDMA_TCD_BITER_ELINKYES_tag ELINKYES; /* TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Enabled */
} eDMA_TCD_BITER_tag;

typedef union eDMA_TCD_CSR_union_tag { /* TCD Control and Status */
  vuint16_t R;
  struct {
    vuint16_t BWC:2;
    vuint16_t MAJORLINKCH:6;
    vuint16_t DONE:1;
    vuint16_t ACTIVE:1;
    vuint16_t MAJORELINK:1;
    vuint16_t ESG:1;
    vuint16_t DREQ:1;
    vuint16_t INTHALF:1;
    vuint16_t INTMAJOR:1;
    vuint16_t START:1;
  } B;
} eDMA_TCD_CSR_tag;

typedef struct eDMA_TCD_struct_tag {
  eDMA_TCD_SADDR_tag SADDR;            /* TCD Source Address */
  eDMA_TCD_ATTR_tag ATTR;              /* TCD Transfer Attributes */
  eDMA_TCD_SOFF_tag SOFF;              /* TCD Signed Source Address Offset */
  eDMA_TCD_NBYTES_tag NBYTES;
  eDMA_TCD_SLAST_tag SLAST;            /* TCD Last Source Address Adjustment */
  eDMA_TCD_DADDR_tag DADDR;            /* TCD Destination Address */
  eDMA_TCD_CITER_tag CITER;
  eDMA_TCD_DOFF_tag DOFF;              /* TCD Signed Destination Address Offset */
  eDMA_TCD_DLASTSGA_tag DLASTSGA;      /* TCD Last Destination Address Adjustment/Scatter Gather Address */
  eDMA_TCD_BITER_tag BITER;
  eDMA_TCD_CSR_tag CSR;                /* TCD Control and Status */
} eDMA_TCD_tag;

struct eDMA_tag {
  eDMA_CR_tag CR;                      /* Control Register */
  eDMA_ES_tag ES;                      /* Error Status */
  eDMA_ERQH_tag ERQH;                  /* Enable Request Register High */
  eDMA_ERQL_tag ERQL;                  /* Enable Request Register Low */
  eDMA_EEIH_tag EEIH;                  /* Enable Error Interrupt Register High */
  eDMA_EEIL_tag EEIL;                  /* Enable Error Interrupt Register Low */
  eDMA_SERQ_tag SERQ;                  /* Set Enable Request Register */
  eDMA_CERQ_tag CERQ;                  /* Clear Enable Request Register */
  eDMA_SEEI_tag SEEI;                  /* Set Enable Error Interrupt Register */
  eDMA_CEEI_tag CEEI;                  /* Clear Enable Error Interrupt Register */
  eDMA_CINT_tag CINT;                  /* Clear Interrupt Request Register */
  eDMA_CERR_tag CERR;                  /* Clear Error Register */
  eDMA_SSRT_tag SSRT;                  /* Set START Bit Register */
  eDMA_CDNE_tag CDNE;                  /* Clear DONE Status Bit Register */
  eDMA_INTH_tag INTH;                  /* Interrupt Request Register High */
  eDMA_INTL_tag INTL;                  /* Interrupt Request Register Low */
  eDMA_ERRH_tag ERRH;                  /* Error Register High */
  eDMA_ERRL_tag ERRL;                  /* Error Register Low */
  eDMA_HRSH_tag HRSH;                  /* Hardware Request Status Register High */
  eDMA_HRSL_tag HRSL;                  /* Hardware Request Status Register Low */
  uint8_t eDMA_reserved0[200];
  eDMA_DCHPRI_tag DCHPRI[64];          /* Channel Priority Register */
  eDMA_DCHMID_tag DCHMID[64];          /* Channel Master ID Register */
  uint8_t eDMA_reserved1[3712];
  eDMA_TCD_tag TCD[64];
};

#endif
