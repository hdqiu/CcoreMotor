#ifndef SSCM_REG_H_
#define SSCM_REG_H_

/* ============================================================================
   =============================== Module: SSCM ===============================
   ============================================================================ */

typedef union SSCM_STATUS_union_tag {  /* SSCM System Status */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t CER:1;                   /* Configuration Error */
    vuint16_t  :1;
    vuint16_t NXEN1:1;                 /* Processor 1 Nexus enable status */
    vuint16_t NXEN:1;                  /* Processor 0 Nexus enable status */
    vuint16_t  :1;
    vuint16_t  :1;
    vuint16_t  :1;
    vuint16_t BMODE:3;                 /* Device Boot Mode */
    vuint16_t VLE:1;                   /* Variable Length Instruction Mode */
    vuint16_t  :1;
    vuint16_t  :1;
    vuint16_t  :2;
  } B;
} SSCM_STATUS_tag;

typedef union SSCM_MEMCONFIG_union_tag { /* SSCM System Memory and ID Register */
  vuint16_t R;
  struct {
    vuint16_t JPIN:10;
    vuint16_t  :1;
    vuint16_t MREV:4;                  /* Minor Mask Revision */
    vuint16_t  :1;
  } B;
} SSCM_MEMCONFIG_tag;

typedef union SSCM_ERROR_union_tag {   /* SSCM Error Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t  :14;
    vuint16_t PAE:1;                   /* Peripheral Bus Abort Enable. */
    vuint16_t RAE:1;                   /* Register Bus Abort Enable. */
  } B;
} SSCM_ERROR_tag;

typedef union SSCM_PWCMPH_union_tag {  /* Password comparison register low word */
  vuint32_t R;
  struct {
    vuint32_t PWD_HI:32;
  } B;
} SSCM_PWCMPH_tag;

typedef union SSCM_PWCMPL_union_tag {  /* Password comparison register low word */
  vuint32_t R;
  struct {
    vuint32_t PWD_LO:32;
  } B;
} SSCM_PWCMPL_tag;

typedef union SSCM_UOPS_union_tag {    /* SSCM HSM and User Option Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :28;
    vuint32_t HSB:3;                   /* HSM Boot Configuration */
    vuint32_t HSE:1;                   /* HSM Enabled */
  } B;
} SSCM_UOPS_tag;

typedef union SSCM_PSA_union_tag {     /* Processor Start Address Register */
  vuint32_t R;
  struct {
    vuint32_t SADR:32;                 /* Processor Start Address */
  } B;
} SSCM_PSA_tag;

typedef union SSCM_HSA_union_tag {     /* SSCM HSM Start Address Register */
  vuint32_t R;
  struct {
    vuint32_t HADR:32;                 /* HSM Start Address */
  } B;
} SSCM_HSA_tag;

typedef union SSCM_LCSTAT_union_tag {  /* Life Cycle Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t  :2;
    vuint32_t  :5;
    vuint32_t LC:3;                    /* Life Cycle */
  } B;
} SSCM_LCSTAT_tag;

typedef union SSCM_TEMP_union_tag {  /* Temperature Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t GMAC_PHY_SEL:3;
    vuint32_t  :18;
    vuint32_t CLAMP:1;
    vuint32_t  :4;
    vuint32_t EN_SDADC_BIAS:1;
    vuint32_t EN_TEMP:1;
    vuint32_t EN_VREF:1;
    vuint32_t  :2;
  } B;
} SSCM_TEMP_tag;

struct SSCM_tag {
  SSCM_STATUS_tag STATUS;              /* SSCM System Status */
  SSCM_MEMCONFIG_tag MEMCONFIG;        /* SSCM System Memory and ID Register */
  uint8_t SSCM_reserved0[2];
  SSCM_ERROR_tag ERROR;                /* SSCM Error Configuration Register */
  uint8_t SSCM_reserved1[4];
  SSCM_PWCMPH_tag PWCMPH;              /* Password comparison register low word */
  SSCM_PWCMPL_tag PWCMPL;              /* Password comparison register low word */
  uint8_t SSCM_reserved2[12];
  SSCM_UOPS_tag UOPS;                  /* SSCM HSM and User Option Status Register */
  uint8_t SSCM_reserved3[4];
  SSCM_PSA_tag PSA;                    /* Processor Start Address Register */
  uint8_t SSCM_reserved4[4];
  SSCM_HSA_tag HSA;                    /* SSCM HSM Start Address Register */
  SSCM_LCSTAT_tag LCSTAT;              /* Life Cycle Status Register */
  SSCM_TEMP_tag TEMP;                  /* Temperature Register (Offset: 0x38) */
};

#endif
