#ifndef MC_REG_H_
#define MC_REG_H_
/* ============================================================================
   =============================== Module: MC_CGM =============================
   ============================================================================ */

typedef union MC_CGM_AC5_CDC0_union_tag { /* Auxiliary Clock 5 Cascaded Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC0_tag;

typedef union MC_CGM_AC5_CDC1_union_tag { /* Auxiliary Clock 5 Cascaded Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC1_tag;

typedef union MC_CGM_AC5_CDC2_union_tag { /* Auxiliary Clock 5 Cascaded Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC2_tag;

typedef union MC_CGM_AC5_CDC10_union_tag { /* Auxiliary Clock 5 Cascaded Divider 10 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC10_tag;

typedef union MC_CGM_AC5_CDC11_union_tag { /* Auxiliary Clock 5 Cascaded Divider 11 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC11_tag;

typedef union MC_CGM_AC5_CDC12_union_tag { /* Auxiliary Clock 5 Cascaded Divider 12 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC12_tag;

typedef union MC_CGM_AC5_CDC13_union_tag { /* Auxiliary Clock 5 Cascaded Divider 13 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC13_tag;

typedef union MC_CGM_AC5_CDC20_union_tag { /* Auxiliary Clock 5 Cascaded Divider 20 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC20_tag;

typedef union MC_CGM_AC5_CDC21_union_tag { /* Auxiliary Clock 5 Cascaded Divider 21 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC21_tag;

typedef union MC_CGM_AC5_CDC22_union_tag { /* Auxiliary Clock 5 Cascaded Divider 22 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC22_tag;

typedef union MC_CGM_AC5_CDC23_union_tag { /* Auxiliary Clock 5 Cascaded Divider 23 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_CDC23_tag;

typedef union MC_CGM_PCS_SDUR_union_tag { /* PCS Switch Duration Register */
  vuint8_t R;
  struct {
    vuint8_t SDUR:8;
  } B;
} MC_CGM_PCS_SDUR_tag;

typedef union MC_CGM_PCS_DIVC1_union_tag { /* PCS Divider Change Register 1 */
  vuint32_t R;
  struct {
    vuint32_t INIT:16;
    vuint32_t  :8;
    vuint32_t RATE:8;
  } B;
} MC_CGM_PCS_DIVC1_tag;

typedef union MC_CGM_PCS_DIVE1_union_tag { /* PCS Divider End Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVE:20;
  } B;
} MC_CGM_PCS_DIVE1_tag;

typedef union MC_CGM_PCS_DIVS1_union_tag { /* PCS Divider Start Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVS:20;
  } B;
} MC_CGM_PCS_DIVS1_tag;

typedef union MC_CGM_PCS_DIVC2_union_tag { /* PCS Divider Change Register 2 */
  vuint32_t R;
  struct {
    vuint32_t INIT:16;
    vuint32_t  :8;
    vuint32_t RATE:8;
  } B;
} MC_CGM_PCS_DIVC2_tag;

typedef union MC_CGM_PCS_DIVE2_union_tag { /* PCS Divider End Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVE:20;
  } B;
} MC_CGM_PCS_DIVE2_tag;

typedef union MC_CGM_PCS_DIVS2_union_tag { /* PCS Divider Start Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVS:20;
  } B;
} MC_CGM_PCS_DIVS2_tag;

typedef union MC_CGM_PCS_DIVC4_union_tag { /* PCS Divider Change Register 4 */
  vuint32_t R;
  struct {
    vuint32_t INIT:16;
    vuint32_t  :8;
    vuint32_t RATE:8;
  } B;
} MC_CGM_PCS_DIVC4_tag;

typedef union MC_CGM_PCS_DIVE4_union_tag { /* PCS Divider End Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVE:20;
  } B;
} MC_CGM_PCS_DIVE4_tag;

typedef union MC_CGM_PCS_DIVS4_union_tag { /* PCS Divider Start Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  :12;
    vuint32_t DIVS:20;
  } B;
} MC_CGM_PCS_DIVS4_tag;

typedef union MC_CGM_SC_DIV_RC_union_tag { /* System Clock Divider Ratio Change Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t SYS_DIV_RATIO_CHNG:1;
  } B;
} MC_CGM_SC_DIV_RC_tag;

typedef union MC_CGM_DIV_UPD_TYPE_union_tag { /* Divider Update Type Register */
  vuint32_t R;
  struct {
    vuint32_t SYS_UPD_TYPE:1;
    vuint32_t  :31;
  } B;
} MC_CGM_DIV_UPD_TYPE_tag;

typedef union MC_CGM_DIV_UPD_TRIG_union_tag { /* Divider Update Trigger Register */
  vuint32_t R;
  struct {
    vuint32_t DIV_UPD_TRIGGER:32;
  } B;
} MC_CGM_DIV_UPD_TRIG_tag;

typedef union MC_CGM_DIV_UPD_STAT_union_tag { /* Divider Update Status Register */
  vuint32_t R;
  struct {
    vuint32_t SYS_UPD_STAT:1;
    vuint32_t  :31;
  } B;
} MC_CGM_DIV_UPD_STAT_tag;

typedef union MC_CGM_SC_SS_union_tag { /* System Clock Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :4;
    vuint32_t SWTRG:3;
    vuint32_t SWIP:1;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_SS_tag;

typedef union MC_CGM_SC_DC0_union_tag { /* System Clock Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC0_tag;

typedef union MC_CGM_SC_DC1_union_tag { /* System Clock Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC1_tag;

typedef union MC_CGM_SC_DC2_union_tag { /* System Clock Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC2_tag;

typedef union MC_CGM_SC_DC3_union_tag { /* System Clock Divider 3 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC3_tag;

typedef union MC_CGM_SC_DC4_union_tag { /* System Clock Divider 4 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_SC_DC4_tag;

typedef union MC_CGM_AC0_SC_union_tag { /* Auxiliary Clock 0 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC0_SC_tag;

typedef union MC_CGM_AC0_SS_union_tag { /* Auxiliary Clock 0 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC0_SS_tag;

typedef union MC_CGM_AC0_DC0_union_tag { /* Auxiliary Clock 0 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :11;
    vuint32_t DIV:4;
    vuint32_t  :16;
  } B;
} MC_CGM_AC0_DC0_tag;

typedef union MC_CGM_AC0_DC1_union_tag { /* Auxiliary Clock 0 Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :8;
    vuint32_t DIV:7;
    vuint32_t  :16;
  } B;
} MC_CGM_AC0_DC1_tag;

typedef union MC_CGM_AC0_DC2_union_tag { /* Auxiliary Clock 0 Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :8;
    vuint32_t DIV:7;
    vuint32_t  :16;
  } B;
} MC_CGM_AC0_DC2_tag;

typedef union MC_CGM_AC0_DC3_union_tag { /* Auxiliary Clock 0 Divider 3 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :6;
    vuint32_t DIV:9;
    vuint32_t  :14;
    vuint32_t DIV_FMT:2;
  } B;
} MC_CGM_AC0_DC3_tag;

typedef union MC_CGM_AC0_DC4_union_tag { /* Auxiliary Clock 0 Divider 4 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :11;
    vuint32_t DIV:4;
    vuint32_t  :16;
  } B;
} MC_CGM_AC0_DC4_tag;

typedef union MC_CGM_AC1_SC_union_tag { /* Auxiliary Clock 1 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC1_SC_tag;

typedef union MC_CGM_AC1_SS_union_tag { /* Auxiliary Clock 1 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC1_SS_tag;

typedef union MC_CGM_AC1_DC0_union_tag { /* Auxiliary Clock 1 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :8;
    vuint32_t DIV:7;
    vuint32_t  :16;
  } B;
} MC_CGM_AC1_DC0_tag;

typedef union MC_CGM_AC2_DC0_union_tag { /* Auxiliary Clock 2 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC2_DC0_tag;

typedef union MC_CGM_AC2_DC1_union_tag { /* Auxiliary Clock 2 Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC2_DC1_tag;

typedef union MC_CGM_AC2_DC2_union_tag { /* Auxiliary Clock 2 Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC2_DC2_tag;

typedef union MC_CGM_AC3_SC_union_tag { /* Auxiliary Clock 3 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC3_SC_tag;

typedef union MC_CGM_AC3_SS_union_tag { /* Auxiliary Clock 3 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC3_SS_tag;

typedef union MC_CGM_AC4_SC_union_tag { /* Auxiliary Clock 4 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC4_SC_tag;

typedef union MC_CGM_AC4_SS_union_tag { /* Auxiliary Clock 4 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC4_SS_tag;

typedef union MC_CGM_AC5_DC0_union_tag { /* Auxiliary Clock 5 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :2;
    vuint32_t DIV:13;
    vuint32_t  :14;
    vuint32_t DIV_FMT:2;
  } B;
} MC_CGM_AC5_DC0_tag;

typedef union MC_CGM_AC5_DC1_union_tag { /* Auxiliary Clock 5 Divider 1 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :7;
    vuint32_t DIV:8;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_DC1_tag;

typedef union MC_CGM_AC5_DC2_union_tag { /* Auxiliary Clock 5 Divider 2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :5;
    vuint32_t DIV:10;
    vuint32_t  :16;
  } B;
} MC_CGM_AC5_DC2_tag;

typedef union MC_CGM_AC6_SC_union_tag { /* Auxiliary Clock 6 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC6_SC_tag;

typedef union MC_CGM_AC6_SS_union_tag { /* Auxiliary Clock 6 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC6_SS_tag;

typedef union MC_CGM_AC6_DC0_union_tag { /* Auxiliary Clock 6 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :6;
    vuint32_t DIV:9;
    vuint32_t  :16;
  } B;
} MC_CGM_AC6_DC0_tag;

typedef union MC_CGM_AC7_SC_union_tag { /* Auxiliary Clock 7 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC7_SC_tag;

typedef union MC_CGM_AC7_SS_union_tag { /* Auxiliary Clock 7 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC7_SS_tag;

typedef union MC_CGM_AC7_DC0_union_tag { /* Auxiliary Clock 7 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :6;
    vuint32_t DIV:9;
    vuint32_t  :16;
  } B;
} MC_CGM_AC7_DC0_tag;

typedef union MC_CGM_AC8_SC_union_tag { /* Auxiliary Clock 8 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC8_SC_tag;

typedef union MC_CGM_AC8_SS_union_tag { /* Auxiliary Clock 8 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC8_SS_tag;

typedef union MC_CGM_AC8_DC0_union_tag { /* Auxiliary Clock 8 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC8_DC0_tag;

typedef union MC_CGM_AC9_SC_union_tag { /* Auxiliary Clock 9 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC9_SC_tag;

typedef union MC_CGM_AC9_SS_union_tag { /* Auxiliary Clock 9 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC9_SS_tag;

typedef union MC_CGM_AC9_DC0_union_tag { /* Auxiliary Clock 9 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :9;
    vuint32_t DIV:6;
    vuint32_t  :16;
  } B;
} MC_CGM_AC9_DC0_tag;

typedef union MC_CGM_AC10_SC_union_tag { /* Auxiliary Clock 10 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC10_SC_tag;

typedef union MC_CGM_AC10_SS_union_tag { /* Auxiliary Clock 10 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC10_SS_tag;

typedef union MC_CGM_AC10_DC0_union_tag { /* Auxiliary Clock 10 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :11;
    vuint32_t DIV:4;
    vuint32_t  :16;
  } B;
} MC_CGM_AC10_DC0_tag;

#if defined(CCFC3008PT)
/* CCFC3008PT unsupported. */
#else
typedef union MC_CGM_AC11_SC_union_tag { /* Auxiliary Clock 11 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC11_SC_tag;

typedef union MC_CGM_AC11_SS_union_tag { /* Auxiliary Clock 11 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC11_SS_tag;

typedef union MC_CGM_AC11_DC0_union_tag { /* Auxiliary Clock 11 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :11;
    vuint32_t DIV:4;
    vuint32_t  :16;
  } B;
} MC_CGM_AC11_DC0_tag;

typedef union MC_CGM_AC12_SC_union_tag { /* Auxiliary Clock 11 Select Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELCTL:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC12_SC_tag;

typedef union MC_CGM_AC12_SS_union_tag { /* Auxiliary Clock 11 Select Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :4;
    vuint32_t SELSTAT:4;
    vuint32_t  :24;
  } B;
} MC_CGM_AC12_SS_tag;

typedef union MC_CGM_AC12_DC0_union_tag { /* Auxiliary Clock 11 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :2;
    vuint32_t DIV:13;
    vuint32_t  :16;
  } B;
} MC_CGM_AC12_DC0_tag;

typedef union MC_CGM_AC12_DC1_union_tag { /* Auxiliary Clock 11 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :2;
    vuint32_t DIV:13;
    vuint32_t  :16;
  } B;
} MC_CGM_AC12_DC1_tag;

typedef union MC_CGM_AC12_DC2_union_tag { /* Auxiliary Clock 11 Divider 0 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t DE:1;
    vuint32_t  :2;
    vuint32_t DIV:13;
    vuint32_t  :16;
  } B;
} MC_CGM_AC12_DC2_tag;
#endif

struct MC_CGM_tag {
  uint8_t MC_CGM_reserved0[1664];
  MC_CGM_AC5_CDC0_tag AC5_CDC0;        /* Auxiliary Clock 5 Cascaded Divider 0 Configuration Register */
  MC_CGM_AC5_CDC1_tag AC5_CDC1;        /* Auxiliary Clock 5 Cascaded Divider 1 Configuration Register */
  MC_CGM_AC5_CDC2_tag AC5_CDC2;        /* Auxiliary Clock 5 Cascaded Divider 2 Configuration Register */
  uint8_t MC_CGM_reserved1[4];
  MC_CGM_AC5_CDC10_tag AC5_CDC10;      /* Auxiliary Clock 5 Cascaded Divider 10 Configuration Register */
  MC_CGM_AC5_CDC11_tag AC5_CDC11;      /* Auxiliary Clock 5 Cascaded Divider 11 Configuration Register */
  MC_CGM_AC5_CDC12_tag AC5_CDC12;      /* Auxiliary Clock 5 Cascaded Divider 12 Configuration Register */
  MC_CGM_AC5_CDC13_tag AC5_CDC13;      /* Auxiliary Clock 5 Cascaded Divider 13 Configuration Register */
  MC_CGM_AC5_CDC20_tag AC5_CDC20;      /* Auxiliary Clock 5 Cascaded Divider 20 Configuration Register */
  MC_CGM_AC5_CDC21_tag AC5_CDC21;      /* Auxiliary Clock 5 Cascaded Divider 21 Configuration Register */
  MC_CGM_AC5_CDC22_tag AC5_CDC22;      /* Auxiliary Clock 5 Cascaded Divider 22 Configuration Register */
  MC_CGM_AC5_CDC23_tag AC5_CDC23;      /* Auxiliary Clock 5 Cascaded Divider 23 Configuration Register */
  uint8_t MC_CGM_reserved2[80];
  MC_CGM_PCS_SDUR_tag PCS_SDUR;        /* PCS Switch Duration Register */
  uint8_t MC_CGM_reserved3[3];
  MC_CGM_PCS_DIVC1_tag PCS_DIVC1;      /* PCS Divider Change Register 1 */
  MC_CGM_PCS_DIVE1_tag PCS_DIVE1;      /* PCS Divider End Register 1 */
  MC_CGM_PCS_DIVS1_tag PCS_DIVS1;      /* PCS Divider Start Register 1 */
  MC_CGM_PCS_DIVC2_tag PCS_DIVC2;      /* PCS Divider Change Register 2 */
  MC_CGM_PCS_DIVE2_tag PCS_DIVE2;      /* PCS Divider End Register 2 */
  MC_CGM_PCS_DIVS2_tag PCS_DIVS2;      /* PCS Divider Start Register 2 */
  uint8_t MC_CGM_reserved4[12];
  MC_CGM_PCS_DIVC4_tag PCS_DIVC4;      /* PCS Divider Change Register 4 */
  MC_CGM_PCS_DIVE4_tag PCS_DIVE4;      /* PCS Divider End Register 4 */
  MC_CGM_PCS_DIVS4_tag PCS_DIVS4;      /* PCS Divider Start Register 4 */
  uint8_t MC_CGM_reserved5[156];
  MC_CGM_SC_DIV_RC_tag SC_DIV_RC;      /* System Clock Divider Ratio Change Register */
  MC_CGM_DIV_UPD_TYPE_tag DIV_UPD_TYPE; /* Divider Update Type Register */
  MC_CGM_DIV_UPD_TRIG_tag DIV_UPD_TRIG; /* Divider Update Trigger Register */
  MC_CGM_DIV_UPD_STAT_tag DIV_UPD_STAT; /* Divider Update Status Register */
  uint8_t MC_CGM_reserved6[4];
  MC_CGM_SC_SS_tag SC_SS;              /* System Clock Select Status Register */
  MC_CGM_SC_DC0_tag SC_DC0;            /* System Clock Divider 0 Configuration Register */
  MC_CGM_SC_DC1_tag SC_DC1;            /* System Clock Divider 1 Configuration Register */
  MC_CGM_SC_DC2_tag SC_DC2;            /* System Clock Divider 2 Configuration Register */
  MC_CGM_SC_DC3_tag SC_DC3;            /* System Clock Divider 3 Configuration Register */
  MC_CGM_SC_DC4_tag SC_DC4;            /* System Clock Divider 4 Configuration Register */
  uint8_t MC_CGM_reserved7[4];
  MC_CGM_AC0_SC_tag AC0_SC;            /* Auxiliary Clock 0 Select Control Register */
  MC_CGM_AC0_SS_tag AC0_SS;            /* Auxiliary Clock 0 Select Status Register */
  MC_CGM_AC0_DC0_tag AC0_DC0;          /* Auxiliary Clock 0 Divider 0 Configuration Register */
  MC_CGM_AC0_DC1_tag AC0_DC1;          /* Auxiliary Clock 0 Divider 1 Configuration Register */
  MC_CGM_AC0_DC2_tag AC0_DC2;          /* Auxiliary Clock 0 Divider 2 Configuration Register */
  MC_CGM_AC0_DC3_tag AC0_DC3;          /* Auxiliary Clock 0 Divider 3 Configuration Register */
  MC_CGM_AC0_DC4_tag AC0_DC4;          /* Auxiliary Clock 0 Divider 4 Configuration Register */
  uint8_t MC_CGM_reserved8[4];
  MC_CGM_AC1_SC_tag AC1_SC;            /* Auxiliary Clock 1 Select Control Register */
  MC_CGM_AC1_SS_tag AC1_SS;            /* Auxiliary Clock 1 Select Status Register */
  MC_CGM_AC1_DC0_tag AC1_DC0;          /* Auxiliary Clock 1 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved9[28];
  MC_CGM_AC2_DC0_tag AC2_DC0;          /* Auxiliary Clock 2 Divider 0 Configuration Register */
  MC_CGM_AC2_DC1_tag AC2_DC1;          /* Auxiliary Clock 2 Divider 1 Configuration Register */
  MC_CGM_AC2_DC2_tag AC2_DC2;          /* Auxiliary Clock 2 Divider 2 Configuration Register */
  uint8_t MC_CGM_reserved10[12];
  MC_CGM_AC3_SC_tag AC3_SC;            /* Auxiliary Clock 3 Select Control Register */
  MC_CGM_AC3_SS_tag AC3_SS;            /* Auxiliary Clock 3 Select Status Register */
  uint8_t MC_CGM_reserved11[24];
  MC_CGM_AC4_SC_tag AC4_SC;            /* Auxiliary Clock 4 Select Control Register */
  MC_CGM_AC4_SS_tag AC4_SS;            /* Auxiliary Clock 4 Select Status Register */
  uint8_t MC_CGM_reserved12[32];
  MC_CGM_AC5_DC0_tag AC5_DC0;          /* Auxiliary Clock 5 Divider 0 Configuration Register */
  MC_CGM_AC5_DC1_tag AC5_DC1;          /* Auxiliary Clock 5 Divider 1 Configuration Register */
  MC_CGM_AC5_DC2_tag AC5_DC2;          /* Auxiliary Clock 5 Divider 2 Configuration Register */
  uint8_t MC_CGM_reserved13[12];
  MC_CGM_AC6_SC_tag AC6_SC;            /* Auxiliary Clock 6 Select Control Register */
  MC_CGM_AC6_SS_tag AC6_SS;            /* Auxiliary Clock 6 Select Status Register */
  MC_CGM_AC6_DC0_tag AC6_DC0;          /* Auxiliary Clock 6 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved14[20];
  MC_CGM_AC7_SC_tag AC7_SC;            /* Auxiliary Clock 7 Select Control Register */
  MC_CGM_AC7_SS_tag AC7_SS;            /* Auxiliary Clock 7 Select Status Register */
  MC_CGM_AC7_DC0_tag AC7_DC0;          /* Auxiliary Clock 7 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved15[20];
  MC_CGM_AC8_SC_tag AC8_SC;            /* Auxiliary Clock 8 Select Control Register */
  MC_CGM_AC8_SS_tag AC8_SS;            /* Auxiliary Clock 8 Select Status Register */
  MC_CGM_AC8_DC0_tag AC8_DC0;          /* Auxiliary Clock 8 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved16[20];
  MC_CGM_AC9_SC_tag AC9_SC;            /* Auxiliary Clock 9 Select Control Register */
  MC_CGM_AC9_SS_tag AC9_SS;            /* Auxiliary Clock 9 Select Status Register */
  MC_CGM_AC9_DC0_tag AC9_DC0;          /* Auxiliary Clock 9 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved17[20];
  MC_CGM_AC10_SC_tag AC10_SC;          /* Auxiliary Clock 10 Select Control Register */
  MC_CGM_AC10_SS_tag AC10_SS;          /* Auxiliary Clock 10 Select Status Register */
  MC_CGM_AC10_DC0_tag AC10_DC0;        /* Auxiliary Clock 10 Divider 0 Configuration Register */
#if defined(CCFC3008PT)
/* CCFC3008PT unsupported. */
#else
  uint8_t MC_CGM_reserved18[20];
  MC_CGM_AC11_SC_tag AC11_SC;          /* Auxiliary Clock 11 Select Control Register */
  MC_CGM_AC11_SS_tag AC11_SS;          /* Auxiliary Clock 11 Select Status Register */
  MC_CGM_AC11_DC0_tag AC11_DC0;        /* Auxiliary Clock 11 Divider 0 Configuration Register */
  uint8_t MC_CGM_reserved19[20];
  MC_CGM_AC12_SC_tag AC12_SC;          /* Auxiliary Clock 12 Select Control Register */
  MC_CGM_AC12_SS_tag AC12_SS;          /* Auxiliary Clock 12 Select Status Register */
  MC_CGM_AC12_DC0_tag AC12_DC0;        /* Auxiliary Clock 12 Divider 0 Configuration Register */
  MC_CGM_AC12_DC1_tag AC12_DC1;        /* Auxiliary Clock 12 Divider 1 Configuration Register */
  MC_CGM_AC12_DC2_tag AC12_DC2;        /* Auxiliary Clock 12 Divider 2 Configuration Register */
#endif
};


/* ============================================================================
   =============================== Module: MC_ME ==============================
   ============================================================================ */

#define MC_ME_MODE_RESET_FUNC   (0U)
#define MC_ME_MODE_TEST         (1U)
#define MC_ME_MODE_SAFE         (2U)
#define MC_ME_MODE_DRUN         (3U)
#define MC_ME_MODE_RUN0         (4U)
#define MC_ME_MODE_RUN1         (5U)
#define MC_ME_MODE_RUN2         (6U)
#define MC_ME_MODE_RUN3         (7U)
#define MC_ME_MODE_HALT         (8U)
#define MC_ME_MODE_STOP         (0xAU)
#if defined(CCFC3008PT)
/* CCFC3008PT unsupported. */
#else
#define MC_ME_MODE_STANDBY      (0xDU)
#endif
#define MC_ME_MODE_RESET_DEST   (0xFU)

typedef union MC_ME_GS_union_tag {     /* Global Status Register */
  vuint32_t R;
  struct {
    vuint32_t S_CURRENT_MODE:4;
    vuint32_t S_MTRANS:1;
    vuint32_t  :1;
    vuint32_t  :2;
    vuint32_t S_PDO:1;
    vuint32_t  :2;
    vuint32_t S_MVR:1;
    vuint32_t  :2;
    vuint32_t S_FLA:2;
    vuint32_t  :8;
    vuint32_t S_PLL1:1;
    vuint32_t S_PLL0:1;
    vuint32_t S_XOSC:1;
    vuint32_t S_IRC:1;
    vuint32_t S_SYSCLK:4;
  } B;
} MC_ME_GS_tag;

typedef union MC_ME_MCTL_union_tag {   /* Mode Control Register */
  vuint32_t R;
  struct {
    vuint32_t TARGET_MODE:4;
    vuint32_t  :12;
    vuint32_t KEY:16;
  } B;
} MC_ME_MCTL_tag;

typedef union MC_ME_ME_union_tag {     /* Mode Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t RESET_DEST:1;
#if defined(CCFC3008PT)
/* CCFC3008PT unsupported STANDBY. */
    vuint32_t  :4;
#else
    vuint32_t  :1;
    vuint32_t STANDBY:1;
    vuint32_t  :2;
#endif
    vuint32_t STOP0:1;
    vuint32_t  :1;
    vuint32_t HALT0:1;
    vuint32_t RUN3:1;
    vuint32_t RUN2:1;
    vuint32_t RUN1:1;
    vuint32_t RUN0:1;
    vuint32_t DRUN:1;
    vuint32_t SAFE:1;
    vuint32_t TEST:1;
    vuint32_t RESET_FUNC:1;
  } B;
} MC_ME_ME_tag;

typedef union MC_ME_IS_union_tag {     /* Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t I_ICONF_CC:1;
    vuint32_t I_ICONF_CU:1;
    vuint32_t I_ICONF:1;
    vuint32_t I_IMODE:1;
    vuint32_t I_SAFE:1;
    vuint32_t I_MTC:1;
  } B;
} MC_ME_IS_tag;

typedef union MC_ME_IM_union_tag {     /* Interrupt Mask Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t M_ICONF_CC:1;
    vuint32_t M_ICONF_CU:1;
    vuint32_t M_ICONF:1;
    vuint32_t M_IMODE:1;
    vuint32_t M_SAFE:1;
    vuint32_t M_MTC:1;
  } B;
} MC_ME_IM_tag;

typedef union MC_ME_IMTS_union_tag {   /* Invalid Mode Transition Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :26;
    vuint32_t S_MRIG:1;
    vuint32_t S_MTI:1;
    vuint32_t S_MRI:1;
    vuint32_t S_DMA:1;
    vuint32_t S_NMA:1;
    vuint32_t S_SEA:1;
  } B;
} MC_ME_IMTS_tag;

typedef union MC_ME_DMTS_union_tag {   /* Debug Mode Transition Status Register */
  vuint32_t R;
  struct {
    vuint32_t PREVIOUS_MODE:4;
    vuint32_t  :4;
    vuint32_t MPH_BUSY:1;
    vuint32_t  :2;
    vuint32_t PMC_PROG:1;
    vuint32_t DBG_MODE:1;
    vuint32_t CCKL_PROG:1;
    vuint32_t PCS_PROG:1;
    vuint32_t SMR:1;
    vuint32_t  :1;
    vuint32_t VREG_CSRC_SC:1;
    vuint32_t CSRC_CSRC_SC:1;
    vuint32_t IRC_SC:1;
    vuint32_t SCSRC_SC:1;
    vuint32_t SYSCLK_SW:1;
    vuint32_t  :1;
    vuint32_t FLASH_SC:1;
    vuint32_t CDP_PRPH_224_255:1;
    vuint32_t CDP_PRPH_192_223:1;
    vuint32_t CDP_PRPH_160_191:1;
    vuint32_t CDP_PRPH_128_159:1;
    vuint32_t CDP_PRPH_96_127:1;
    vuint32_t CDP_PRPH_64_95:1;
    vuint32_t CDP_PRPH_32_63:1;
    vuint32_t CDP_PRPH_0_31:1;
  } B;
} MC_ME_DMTS_tag;

typedef union MC_ME_RESET_MC_union_tag { /* RESET Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_RESET_MC_tag;

typedef union MC_ME_TEST_MC_union_tag { /* TEST Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_TEST_MC_tag;

typedef union MC_ME_SAFE_MC_union_tag { /* SAFE Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_SAFE_MC_tag;

typedef union MC_ME_DRUN_MC_union_tag { /* DRUN Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_DRUN_MC_tag;

typedef union MC_ME_RUN_MC_union_tag { /* RUN0 Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_RUN_MC_tag;

typedef union MC_ME_HALT0_MC_union_tag { /* HALT0 Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_HALT0_MC_tag;

typedef union MC_ME_STOP0_MC_union_tag { /* STOP0 Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_STOP0_MC_tag;

#if defined(CCFC3008PT)
/* CCFC3008PT unsupported STANDBY. */
#else
typedef union MC_ME_STANDBY_MC_union_tag {  /* STANDBY Mode Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PWRLVL:3;
    vuint32_t  :4;
    vuint32_t PDO:1;
    vuint32_t  :2;
    vuint32_t MVRON:1;
    vuint32_t  :2;
    vuint32_t FLAON:2;
    vuint32_t  :8;
    vuint32_t PLL1ON:1;
    vuint32_t PLL0ON:1;
    vuint32_t XOSCON:1;
    vuint32_t IRCON:1;  /* r/w */
    vuint32_t SYSCLK:4;
  } B;
} MC_ME_STANDBY_MC_tag;
#endif

typedef union MC_ME_PS0_union_tag {    /* Peripheral Status Register 0 */
  vuint32_t R;
  struct {
    vuint32_t S_PIT_RTC_1:1;
    vuint32_t S_PIT_RTC_0:1;
    vuint32_t  :14;
    vuint32_t S_SIUL:1;
    vuint32_t  :3;
    vuint32_t S_SIPI_0:1;
    vuint32_t  :1;
    vuint32_t S_LFAST_0:1;
    vuint32_t  :5;
    vuint32_t S_EBI_0:1;
    vuint32_t  :3;
  } B;
} MC_ME_PS0_tag;

typedef union MC_ME_PS1_union_tag {    /* Peripheral Status Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t S_ADCSD_0:1;
    vuint32_t S_ADCSD_2:1;
    vuint32_t S_ADCSD_4:1;
    vuint32_t S_ADCSD_6:1;
    vuint32_t S_ADCSD_8:1;
    vuint32_t  :17;
    vuint32_t S_CRC_0:1;
    vuint32_t  :1;
    vuint32_t S_DMAMUX_0:1;
    vuint32_t  :4;
  } B;
} MC_ME_PS1_tag;

typedef union MC_ME_PS2_union_tag {    /* Peripheral Status Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t S_DSPI_12:1;
    vuint32_t S_LINFlexD_0:1;
    vuint32_t S_LINFlexD_1:1;
    vuint32_t  :5;
    vuint32_t S_LINFlexD_14:1;
    vuint32_t S_LINFlexD_16:1;
    vuint32_t  :9;
    vuint32_t S_CAN_RAM_CTRL:1;
    vuint32_t  :1;
    vuint32_t S_TTCAN:1;
    vuint32_t  :1;
    vuint32_t S_MCAN_1:1;
    vuint32_t S_MCAN_2:1;
    vuint32_t S_MCAN_3:1;
    vuint32_t S_MCAN_4:1;
    vuint32_t  :3;
  } B;
} MC_ME_PS2_tag;

typedef union MC_ME_PS3_union_tag {    /* Peripheral Status Register 3 */
  vuint32_t R;
  struct {
    vuint32_t S_ADCSAR_0:1;
    vuint32_t  :3;
    vuint32_t S_ADCSAR_4:1;
    vuint32_t  :10;
    vuint32_t S_ADCSAR_b:1;
    vuint32_t S_PSI5_0:1;
    vuint32_t  :3;
    vuint32_t S_FLEXRAY_0:1;
    vuint32_t  :2;
    vuint32_t S_SENT_0:1;
    vuint32_t  :2;
    vuint32_t S_IIC_0:1;
    vuint32_t  :1;
    vuint32_t S_DSPI_0:1;
    vuint32_t S_DSPI_1:1;
    vuint32_t S_DSPI_4:1;
    vuint32_t S_DSPI_6:1;
  } B;
} MC_ME_PS3_tag;

typedef union MC_ME_PS4_union_tag {    /* Peripheral Status Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t S_GTMINT:1;
  } B;
} MC_ME_PS4_tag;

typedef union MC_ME_PS5_union_tag {    /* Peripheral Status Register 5 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t S_ADCSD_1:1;
    vuint32_t S_ADCSD_3:1;
    vuint32_t S_ADCSD_5:1;
    vuint32_t S_ADCSD_7:1;
    vuint32_t S_ADCSD_9:1;
    vuint32_t  :17;
    vuint32_t S_CRC_1:1;
    vuint32_t  :3;
    vuint32_t S_PSI5S_0:1;
    vuint32_t  :2;
  } B;
} MC_ME_PS5_tag;

typedef union MC_ME_PS6_union_tag {    /* Peripheral Status Register 6 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t S_LINFlexD_2:1;
    vuint32_t  :6;
    vuint32_t S_LINFlexD_15:1;
    vuint32_t  :21;
  } B;
} MC_ME_PS6_tag;

typedef union MC_ME_PS7_union_tag {    /* Peripheral Status Register 7 */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t S_ADCSAR_1:1;
    vuint32_t S_ADCSAR_2:1;
    vuint32_t S_ADCSAR_3:1;
    vuint32_t  :1;
    vuint32_t S_ADCSAR_5:1;
    vuint32_t S_ADCSAR_6:1;
    vuint32_t S_ADCSAR_7:1;
    vuint32_t S_ADCSAR_8:1;
    vuint32_t S_ADCSAR_9:1;
    vuint32_t S_ADCSAR_10:1;
    vuint32_t  :5;
    vuint32_t S_PSI5_1:1;
    vuint32_t  :3;
    vuint32_t S_FLEXRAY_1:1;
    vuint32_t  :2;
    vuint32_t S_SENT_1:1;
    vuint32_t  :2;
    vuint32_t S_IIC_1:1;
    vuint32_t  :1;
    vuint32_t S_DSPI_2:1;
    vuint32_t S_DSPI_3:1;
    vuint32_t S_DSPI_5:1;
    vuint32_t  :1;
  } B;
} MC_ME_PS7_tag;

typedef union MC_ME_RUN_PC_union_tag { /* Run Peripheral Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :24;
    vuint32_t RUN3:1;
    vuint32_t RUN2:1;
    vuint32_t RUN1:1;
    vuint32_t RUN0:1;
    vuint32_t DRUN:1;
    vuint32_t SAFE:1;
    vuint32_t TEST:1;
    vuint32_t RESET:1;
  } B;
} MC_ME_RUN_PC_tag;

typedef union MC_ME_LP_PC_union_tag {  /* Low-Power Peripheral Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t STOP0:1;
    vuint32_t  :1;
    vuint32_t HALT0:1;
    vuint32_t  :8;
  } B;
} MC_ME_LP_PC_tag;

typedef union MC_ME_PCTL_union_tag {  /* Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL_tag;

#if 0u
typedef union MC_ME_PCTL3_union_tag {  /* EBI_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL3_tag;

typedef union MC_ME_PCTL9_union_tag {  /* LFAST_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL9_tag;

typedef union MC_ME_PCTL11_union_tag { /* SIPI_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL11_tag;

typedef union MC_ME_PCTL15_union_tag { /* SIUL Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL15_tag;

typedef union MC_ME_PCTL30_union_tag { /* PIT_RTC_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL30_tag;

typedef union MC_ME_PCTL31_union_tag { /* PIT_RTC_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL31_tag;

typedef union MC_ME_PCTL36_union_tag { /* DMAMUX_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL36_tag;

typedef union MC_ME_PCTL38_union_tag { /* CRC_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL38_tag;

typedef union MC_ME_PCTL56_union_tag { /* ADCSD_8 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL56_tag;

typedef union MC_ME_PCTL57_union_tag { /* ADCSD_6 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL57_tag;

typedef union MC_ME_PCTL58_union_tag { /* ADCSD_4 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL58_tag;

typedef union MC_ME_PCTL59_union_tag { /* ADCSD_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL59_tag;

typedef union MC_ME_PCTL60_union_tag { /* ADCSD_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL60_tag;

typedef union MC_ME_PCTL67_union_tag { /* MCAN_4 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL67_tag;

typedef union MC_ME_PCTL68_union_tag { /* MCAN_3 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL68_tag;

typedef union MC_ME_PCTL69_union_tag { /* MCAN_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL69_tag;

typedef union MC_ME_PCTL70_union_tag { /* MCAN_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL70_tag;

typedef union MC_ME_PCTL72_union_tag { /* TTCAN Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL72_tag;

typedef union MC_ME_PCTL74_union_tag { /* CAN_RAM_CTRL Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL74_tag;

typedef union MC_ME_PCTL84_union_tag { /* LINFlexD_16 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL84_tag;

typedef union MC_ME_PCTL85_union_tag { /* LINFlexD_14 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL85_tag;

typedef union MC_ME_PCTL91_union_tag { /* LINFlexD_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL91_tag;

typedef union MC_ME_PCTL92_union_tag { /* LINFlexD_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL92_tag;

typedef union MC_ME_PCTL93_union_tag { /* DSPI_12 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL93_tag;

typedef union MC_ME_PCTL96_union_tag { /* DSPI_6 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL96_tag;

typedef union MC_ME_PCTL97_union_tag { /* DSPI_4 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL97_tag;

typedef union MC_ME_PCTL98_union_tag { /* DSPI_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL98_tag;

typedef union MC_ME_PCTL99_union_tag { /* DSPI_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL99_tag;

typedef union MC_ME_PCTL101_union_tag { /* IIC_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL101_tag;

typedef union MC_ME_PCTL104_union_tag { /* SENT_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL104_tag;

typedef union MC_ME_PCTL107_union_tag { /* FLEXRAY_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL107_tag;

typedef union MC_ME_PCTL111_union_tag { /* PSI5_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL111_tag;

typedef union MC_ME_PCTL112_union_tag { /* ADCSAR_b Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL112_tag;

typedef union MC_ME_PCTL123_union_tag { /* ADCSAR_4 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL123_tag;

typedef union MC_ME_PCTL127_union_tag { /* ADCSAR_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL127_tag;

typedef union MC_ME_PCTL128_union_tag { /* GTMINT Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL128_tag;

typedef union MC_ME_PCTL162_union_tag { /* PSI5_S_0 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL162_tag;

typedef union MC_ME_PCTL166_union_tag { /* CRC_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL166_tag;

typedef union MC_ME_PCTL184_union_tag { /* ADCSD_9 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL184_tag;

typedef union MC_ME_PCTL185_union_tag { /* ADCSD_7 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL185_tag;

typedef union MC_ME_PCTL186_union_tag { /* ADCSD_5 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL186_tag;

typedef union MC_ME_PCTL187_union_tag { /* ADCSD_3 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL187_tag;

typedef union MC_ME_PCTL188_union_tag { /* ADCSD_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL188_tag;

typedef union MC_ME_PCTL213_union_tag { /* LINFlexD_15 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL213_tag;

typedef union MC_ME_PCTL220_union_tag { /* LINFlexD_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL220_tag;

typedef union MC_ME_PCTL225_union_tag { /* DSPI_5 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL225_tag;

typedef union MC_ME_PCTL226_union_tag { /* DSPI_3 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL226_tag;

typedef union MC_ME_PCTL227_union_tag { /* DSPI_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL227_tag;

typedef union MC_ME_PCTL229_union_tag { /* IIC_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL229_tag;

typedef union MC_ME_PCTL232_union_tag { /* SENT_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL232_tag;

typedef union MC_ME_PCTL235_union_tag { /* FLEXRAY_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL235_tag;

typedef union MC_ME_PCTL239_union_tag { /* PSI5_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL239_tag;

typedef union MC_ME_PCTL245_union_tag { /* ADCSAR_10 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL245_tag;

typedef union MC_ME_PCTL246_union_tag { /* ADCSAR_9 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL246_tag;

typedef union MC_ME_PCTL247_union_tag { /* ADCSAR_8 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL247_tag;

typedef union MC_ME_PCTL248_union_tag { /* ADCSAR_7 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL248_tag;

typedef union MC_ME_PCTL249_union_tag { /* ADCSAR_6 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL249_tag;

typedef union MC_ME_PCTL250_union_tag { /* ADCSAR_5 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL250_tag;

typedef union MC_ME_PCTL252_union_tag { /* ADCSAR_3 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL252_tag;

typedef union MC_ME_PCTL253_union_tag { /* ADCSAR_2 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL253_tag;

typedef union MC_ME_PCTL254_union_tag { /* ADCSAR_1 Peripheral Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :1;
    vuint8_t  :1;
    vuint8_t LP_CFG:3;
    vuint8_t RUN_CFG:3;
  } B;
} MC_ME_PCTL254_tag;
#endif

typedef union MC_ME_CS_union_tag {     /* Core Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t S_CORE4:1;
    vuint32_t S_CORE3:1;
    vuint32_t S_CORE2:1;
    vuint32_t S_CORE1:1;
    vuint32_t S_CORE0:1;
  } B;
} MC_ME_CS_tag;

typedef union MC_ME_CCTL0_union_tag {  /* CORE0 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL0_tag;

typedef union MC_ME_CCTL1_union_tag {  /* CORE1 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL1_tag;

typedef union MC_ME_CCTL2_union_tag {  /* CORE2 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL2_tag;

typedef union MC_ME_CCTL3_union_tag {  /* CORE3 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL3_tag;

typedef union MC_ME_CCTL4_union_tag {  /* CORE4 Core Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL4_tag;

typedef union MC_ME_CCTL5_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL5_tag;

typedef union MC_ME_CCTL6_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL6_tag;

typedef union MC_ME_CCTL7_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL7_tag;

typedef union MC_ME_CCTL8_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL8_tag;

typedef union MC_ME_CCTL9_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL9_tag;

typedef union MC_ME_CCTL10_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL10_tag;

typedef union MC_ME_CCTL11_union_tag {
  vuint16_t R;
  struct {
    vuint16_t  :5;
    vuint16_t STOP0:1;
    vuint16_t  :1;
    vuint16_t HALT0:1;
    vuint16_t RUN3:1;
    vuint16_t RUN2:1;
    vuint16_t RUN1:1;
    vuint16_t RUN0:1;
    vuint16_t DRUN:1;
    vuint16_t SAFE:1;
    vuint16_t TEST:1;
    vuint16_t RESET:1;
  } B;
} MC_ME_CCTL11_tag;
typedef union MC_ME_CADDR0_union_tag { /* CORE0 Core Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR0_tag;

typedef union MC_ME_CADDR1_union_tag { /* CORE1 Core Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR1_tag;

typedef union MC_ME_CADDR2_union_tag { /* CORE2 Core Address Register */
  vuint32_t R;
  struct {
	vuint32_t ADDR:30;
	vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR2_tag;

typedef union MC_ME_CADDR3_union_tag { /* CORE3 Core Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR3_tag;

typedef union MC_ME_CADDR4_union_tag { /* CORE4 Core Address Register */
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR4_tag;

typedef union MC_ME_CADDR5_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR5_tag;

typedef union MC_ME_CADDR6_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR6_tag;

typedef union MC_ME_CADDR7_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR7_tag;

typedef union MC_ME_CADDR8_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR8_tag;

typedef union MC_ME_CADDR9_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR9_tag;

typedef union MC_ME_CADDR10_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR10_tag;

typedef union MC_ME_CADDR11_union_tag {
  vuint32_t R;
  struct {
    vuint32_t ADDR:30;
    vuint32_t  :1;
    vuint32_t RMC:1;
  } B;
} MC_ME_CADDR11_tag;
struct MC_ME_tag {
  MC_ME_GS_tag GS;                     /* Global Status Register */
  MC_ME_MCTL_tag MCTL;                 /* Mode Control Register */
  MC_ME_ME_tag ME;                     /* Mode Enable Register */
  MC_ME_IS_tag IS;                     /* Interrupt Status Register */
  MC_ME_IM_tag IM;                     /* Interrupt Mask Register */
  MC_ME_IMTS_tag IMTS;                 /* Invalid Mode Transition Status Register */
  MC_ME_DMTS_tag DMTS;                 /* Debug Mode Transition Status Register */
  uint8_t MC_ME_reserved0[4];
  MC_ME_RESET_MC_tag RESET_MC;         /* RESET Mode Configuration Register */
  MC_ME_TEST_MC_tag TEST_MC;           /* TEST Mode Configuration Register */
  MC_ME_SAFE_MC_tag SAFE_MC;           /* SAFE Mode Configuration Register */
  MC_ME_DRUN_MC_tag DRUN_MC;           /* DRUN Mode Configuration Register */
  MC_ME_RUN_MC_tag RUN_MC[4];          /* RUN0 Mode Configuration Register */
  MC_ME_HALT0_MC_tag HALT0_MC;         /* HALT0 Mode Configuration Register */
  uint8_t MC_ME_reserved1[4];
  MC_ME_STOP0_MC_tag STOP0_MC;         /* STOP0 Mode Configuration Register */
#if defined(CCFC3008PT)
/* CCFC3008PT unsupported STANDBY. */
  uint8_t MC_ME_reserved2[20];
#else
  uint8_t MC_ME_reserved2[8];
  MC_ME_STANDBY_MC_tag STANDBY_MC;     /* STANDBY Mode Configuration Register */
  uint8_t MC_ME_reserved3[8];
#endif
  MC_ME_PS0_tag PS_0;                  /* Peripheral Status Register 0 */
  MC_ME_PS1_tag PS_1;                  /* Peripheral Status Register 1 */
  MC_ME_PS2_tag PS_2;                  /* Peripheral Status Register 2 */
  MC_ME_PS3_tag PS_3;                  /* Peripheral Status Register 3 */
  MC_ME_PS4_tag PS_4;                  /* Peripheral Status Register 4 */
  MC_ME_PS5_tag PS_5;                  /* Peripheral Status Register 5 */
  MC_ME_PS6_tag PS_6;                  /* Peripheral Status Register 6 */
  MC_ME_PS7_tag PS_7;                  /* Peripheral Status Register 7 */
  MC_ME_RUN_PC_tag RUN_PC[8];          /* Run Peripheral Configuration Register */
  MC_ME_LP_PC_tag LP_PC[8];            /* Low-Power Peripheral Configuration Register */

  MC_ME_PCTL_tag PCTL[255];            /* Peripheral Control Registers 0 ~ 254 */
  uint8_t MC_ME_reserved35[1];
  MC_ME_CS_tag CS;                     /* Core Status Register */
#if defined(CCFC3012PT) || defined(CCFC3011PT)
  MC_ME_CCTL0_tag CCTL0;               /* CORE0 Core Control Register */
  MC_ME_CCTL1_tag CCTL1;               /* CORE0 Checker Core Control Register */
  MC_ME_CCTL2_tag CCTL2;               /* CORE1 Core Control Register */
  MC_ME_CCTL3_tag CCTL3;               /* CORE1 Checker Core Control Register */
  MC_ME_CCTL4_tag CCTL4;               /* HSM Core Control Register */
  MC_ME_CCTL5_tag CCTL5;                           /* Reserved */
  MC_ME_CCTL6_tag CCTL6;               /* CORE2 Core Control Register */
  MC_ME_CCTL7_tag CCTL7;               /* CORE2 Checker Core Control Register */
  MC_ME_CCTL8_tag CCTL8;               /* CORE3 Core Control Register */
  MC_ME_CCTL9_tag CCTL9;               /* CORE3 Checker Core Control Register */
  MC_ME_CCTL10_tag CCTL10;             /* CORE4 Core Control Register */
  MC_ME_CCTL11_tag CCTL11;             /* CORE5 Core Control Register */
  uint8_t MC_ME_reserved36[36];
  MC_ME_CADDR0_tag CADDR0;             /* CORE0 Core Address Register */
  MC_ME_CADDR1_tag CADDR1;             /* CORE0 Checker Core Address Register */
  MC_ME_CADDR2_tag CADDR2;             /* CORE1 Core Address Register */
  MC_ME_CADDR3_tag CADDR3;             /* CORE1 Checker Core Address Register */
  MC_ME_CADDR4_tag CADDR4;             /* HSM Core Address Register */
  MC_ME_CADDR5_tag CADDR5;             /* Reserved */
  MC_ME_CADDR6_tag CADDR6;             /* CORE2 Core Address Register */
  MC_ME_CADDR7_tag CADDR7;             /* CORE2 Checker Core Address Register */
  MC_ME_CADDR8_tag CADDR8;             /* CORE3 Core Address Register */
  MC_ME_CADDR9_tag CADDR9;             /* CORE3 Checker Core Address Register */
  MC_ME_CADDR10_tag CADDR10;            /* CORE4 Core Address Register */
  MC_ME_CADDR11_tag CADDR11;            /* CORE5 Core Address Register */
#else
  MC_ME_CCTL0_tag CCTL0;               /* CORE0 Core Control Register */
  MC_ME_CCTL1_tag CCTL1;               /* CORE1 Core Control Register */
  MC_ME_CCTL2_tag CCTL2;               /* CORE2 Core Control Register */
  MC_ME_CCTL3_tag CCTL3;               /* CORE3 Core Control Register */
  MC_ME_CCTL4_tag CCTL4;               /* CORE4 Core Control Register */
  uint8_t MC_ME_reserved36[18];
  MC_ME_CADDR0_tag CADDR0;             /* CORE0 Core Address Register */
  MC_ME_CADDR1_tag CADDR1;             /* CORE1 Core Address Register */
  MC_ME_CADDR2_tag CADDR2;             /* CORE2 Core Address Register */
  MC_ME_CADDR3_tag CADDR3;             /* CORE3 Core Address Register */
  MC_ME_CADDR4_tag CADDR4;             /* CORE4 Core Address Register */
#endif
};


/* ============================================================================
   =============================== Module: MC_PCU =============================
   ============================================================================ */

typedef union MC_PCU_PSTAT_union_tag { /* Power Domain Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t PD_0:1;
  } B;
} MC_PCU_PSTAT_tag;

struct MC_PCU_tag {
  uint8_t MC_PCU_reserved0[64];
  MC_PCU_PSTAT_tag PSTAT;              /* Power Domain Status Register */
};


/* ============================================================================
   =============================== Module: MC_RGM =============================
   ============================================================================ */

typedef union MC_RGM_DES_union_tag {   /* 'Destructive' Event Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t F_VOR_DEST:1;
    vuint32_t F_TSR_DEST:1;
    vuint32_t  :7;
    vuint32_t F_HSM_DEST:1;
    vuint32_t F_SSCM_DEST:1;
    vuint32_t  :3;
    vuint32_t F_JTAG_DEST:1;
    vuint32_t F_FIF:1;
    vuint32_t F_EDR:1;
    vuint32_t  :2;
    vuint32_t F_SUF:1;
    vuint32_t F_FFRR:1;
    vuint32_t F_SOFT_DEST:1;
    vuint32_t  :1;
    vuint32_t F_PORST:1;
    vuint32_t F_POR:1;
  } B;
} MC_RGM_DES_tag;

typedef union MC_RGM_DERD_union_tag {  /* 'Destructive' Event Reset Disable Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t D_VOR_DEST:1;
    vuint32_t  :8;
    vuint32_t D_HSM_DEST:1;
    vuint32_t D_SSCM_DEST:1;
    vuint32_t  :3;
    vuint32_t D_JTAG_DEST:1;
    vuint32_t D_FIF:1;
    vuint32_t D_EDR:1;
    vuint32_t  :2;
    vuint32_t D_SUF:1;
    vuint32_t D_FFRR:1;
    vuint32_t D_SOFT_DEST:1;
    vuint32_t  :1;
    vuint32_t D_PORST:1;
    vuint32_t D_POR:1;
  } B;
} MC_RGM_DERD_tag;

typedef union MC_RGM_DEAR_union_tag {  /* 'Destructive' Event Alternate Request Register */
  vuint32_t R;
  struct {
    vuint32_t  :30;
    vuint32_t AR_PORST:1;
    vuint32_t  :1;
  } B;
} MC_RGM_DEAR_tag;

typedef union MC_RGM_DBRE_union_tag {  /* 'Destructive' Bidirectional Reset Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t BE_VOR_DEST:1;
    vuint32_t BE_TSR_DEST:1;
    vuint32_t  :7;
    vuint32_t BE_HSM_DEST:1;
    vuint32_t BE_SSCM_DEST:1;
    vuint32_t  :3;
    vuint32_t BE_JTAG_DEST:1;
    vuint32_t BE_FIF:1;
    vuint32_t BE_EDR:1;
    vuint32_t  :2;
    vuint32_t BE_SUF:1;
    vuint32_t BE_FFRR:1;
    vuint32_t BE_SOFT_DEST:1;
    vuint32_t  :1;
    vuint32_t BE_PORST:1;
    vuint32_t BE_POR:1;
  } B;
} MC_RGM_DBRE_tag;

typedef union MC_RGM_FES_union_tag {   /* 'Functional' Event Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t F_VOR_FUNC:1;
    vuint32_t F_TSR_FUNC:1;
    vuint32_t  :7;
    vuint32_t F_HSM_FUNC:1;
    vuint32_t  :4;
    vuint32_t F_JTAG_FUNC:1;
    vuint32_t  :3;
    vuint32_t F_FCCU_SOFT:1;
    vuint32_t F_FCCU_HARD:1;
    vuint32_t  :1;
    vuint32_t F_SOFT_FUNC:1;
    vuint32_t F_ST_DONE:1;
    vuint32_t F_ESR1:1;
    vuint32_t F_ESR0:1;
  } B;
} MC_RGM_FES_tag;

typedef union MC_RGM_FERD_union_tag {  /* 'Functional' Event Reset Disable Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t D_VOR_FUNC:1;
    vuint32_t D_TSR_FUNC:1;
    vuint32_t  :7;
    vuint32_t D_HSM_FUNC:1;
    vuint32_t  :4;
    vuint32_t D_JTAG_FUNC:1;
    vuint32_t  :3;
    vuint32_t D_FCCU_SOFT:1;
    vuint32_t D_FCCU_HARD:1;
    vuint32_t D_SOFT_FUNC:1;
    vuint32_t  :1;
    vuint32_t D_ST_DONE:1;
    vuint32_t D_ESR1:1;
    vuint32_t D_ESR0:1;
  } B;
} MC_RGM_FERD_tag;

typedef union MC_RGM_FEAR_union_tag {  /* 'Functional' Event Alternate Request Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t AR_VOR_FUNC:1;
    vuint32_t AR_TSR_FUNC:1;
    vuint32_t  :21;
    vuint32_t AR_ESR1:1;
    vuint32_t  :1;
  } B;
} MC_RGM_FEAR_tag;

typedef union MC_RGM_FBRE_union_tag {  /* 'Functional' Bidirectional Reset Enable Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t BE_VOR_FUNC:1;
    vuint32_t BE_TSR_FUNC:1;
    vuint32_t  :7;
    vuint32_t BE_HSM_FUNC:1;
    vuint32_t  :4;
    vuint32_t BE_JTAG_FUNC:1;
    vuint32_t  :3;
    vuint32_t BE_FCCU_SOFT:1;
    vuint32_t BE_FCCU_HARD:1;
    vuint32_t  :1;
    vuint32_t BE_SOFT_FUNC:1;
    vuint32_t BE_ST_DONE:1;
    vuint32_t BE_ESR1:1;
    vuint32_t BE_ESR0:1;
  } B;
} MC_RGM_FBRE_tag;

typedef union MC_RGM_FESS_union_tag {  /* 'Functional' Event Short Sequence Register */
  vuint32_t R;
  struct {
    vuint32_t  :7;
    vuint32_t SS_VOR_FUNC:1;
    vuint32_t SS_TSR_FUNC:1;
    vuint32_t  :7;
    vuint32_t SS_HSM_FUNC:1;
    vuint32_t  :4;
    vuint32_t SS_JTAG_FUNC:1;
    vuint32_t  :3;
    vuint32_t SS_FCCU_SOFT:1;
    vuint32_t SS_FCCU_HARD:1;
    vuint32_t  :1;
    vuint32_t SS_SOFT_FUNC:1;
    vuint32_t SS_ST_DONE:1;
    vuint32_t SS_ESR1:1;
    vuint32_t SS_ESR0:1;
  } B;
} MC_RGM_FESS_tag;

typedef union MC_RGM_FRET_union_tag {  /* 'Functional' Reset Escalation Threshold Register */
  vuint8_t R;
  struct {
    vuint8_t  :4;
    vuint8_t FRET:4;
  } B;
} MC_RGM_FRET_tag;

typedef union MC_RGM_DRET_union_tag {  /* 'Destructive' Reset Escalation Threshold Register */
  vuint8_t R;
  struct {
    vuint8_t  :4;
    vuint8_t DRET:4;
  } B;
} MC_RGM_DRET_tag;

typedef union MC_RGM_EROEC_union_tag { /* External Reset Output Extension Control Register */
  vuint8_t R;
  struct {
    vuint8_t  :6;
    vuint8_t ERIS:1;
    vuint8_t EROEC:1;
  } B;
} MC_RGM_EROEC_tag;

typedef union MC_RGM_PRST0_union_tag { /* Peripheral Reset Register 0 */
  vuint32_t R;
  struct {
    vuint32_t PIT_RTC_1_RST:1;
    vuint32_t PIT_RTC_0_RST:1;
    vuint32_t  :14;
    vuint32_t SIUL_RST:1;
    vuint32_t  :3;
    vuint32_t SIPI_0_RST:1;
    vuint32_t  :1;
    vuint32_t LFAST_0_RST:1;
    vuint32_t  :5;
    vuint32_t EBI_0_RST:1;
    vuint32_t  :3;
  } B;
} MC_RGM_PRST0_tag;

#if defined(CCFC3008PT)
typedef union MC_RGM_PRST1_union_tag { /* Peripheral Reset Register 1 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t ADCSD_0_RST:1;
    vuint32_t ADCSD_2_RST:1;
    vuint32_t ADCSD_4_RST:1;
    vuint32_t ADCSD_6_RST:1;
    vuint32_t ADCSD_8_RST:1;
    vuint32_t  :17;
    vuint32_t CRC_0_RST:1;
    vuint32_t  :1;
    vuint32_t DMAMUX_0_RST:1;
    vuint32_t  :4;
  } B;
} MC_RGM_PRST1_tag;
#else
typedef union MC_RGM_PRST1_union_tag { /* Peripheral Reset Register 1 */
  vuint32_t R;
  struct {
	vuint32_t  MCAN_12_RST:1;
    vuint32_t  :2;
    vuint32_t ADCSD_0_RST:1;
    vuint32_t ADCSD_2_RST:1;
    vuint32_t ADCSD_4_RST:1;
    vuint32_t ADCSD_6_RST:1;
    vuint32_t ADCSD_8_RST:1;
    vuint32_t  :17;
    vuint32_t CRC_0_RST:1;
    vuint32_t  :1;
    vuint32_t DMAMUX_0_RST:1;
    vuint32_t  :4;
  } B;
} MC_RGM_PRST1_tag;
#endif

#if defined(CCFC3008PT)
typedef union MC_RGM_PRST2_union_tag { /* Peripheral Reset Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t DSPI_12_RST:1;
    vuint32_t LINFlexD_0_RST:1;
    vuint32_t LINFlexD_1_RST:1;
    vuint32_t  :5;
    vuint32_t LINFlexD_14_RST:1;
    vuint32_t LINFlexD_16_RST:1;
    vuint32_t  :9;
    vuint32_t CAN_RAM_CTR_RST:1;
    vuint32_t  :1;
    vuint32_t TTCAN_RST:1;
    vuint32_t  :1;
    vuint32_t MCAN_1_RST:1;
    vuint32_t MCAN_2_RST:1;
    vuint32_t MCAN_3_RST:1;
    vuint32_t MCAN_4_RST:1;
    vuint32_t  :3;
  } B;
} MC_RGM_PRST2_tag;
#else
typedef union MC_RGM_PRST2_union_tag { /* Peripheral Reset Register 2 */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t DSPI_12_RST:1;
    vuint32_t LINFlexD_0_RST:1;
    vuint32_t LINFlexD_1_RST:1;
    vuint32_t LINFlexD_3_RST:1;
    vuint32_t  :4;
    vuint32_t LINFlexD_14_RST:1;
    vuint32_t LINFlexD_16_RST:1;
    vuint32_t  :2;
    vuint32_t TTCAN_2_RST:1;
    vuint32_t MCAN_9_RST:1;
    vuint32_t MCAN_10_RST:1;
    vuint32_t MCAN_8_RST:1;
    vuint32_t MCAN_7_RST:1;
    vuint32_t MCAN_6_RST:1;
    vuint32_t MCAN_5_RST:1;
    vuint32_t CAN_RAM_CTR_RST:1;
    vuint32_t  :1;
    vuint32_t TTCAN_RST:1;
    vuint32_t  :1;
    vuint32_t MCAN_1_RST:1;
    vuint32_t MCAN_2_RST:1;
    vuint32_t MCAN_3_RST:1;
    vuint32_t MCAN_4_RST:1;
    vuint32_t CAN_RAM1_CTR_RST:1;
    vuint32_t  :1;
    vuint32_t MCAN_11_RST:1;
  } B;
} MC_RGM_PRST2_tag;
#endif

typedef union MC_RGM_PRST3_union_tag { /* Peripheral Reset Register 3 */
  vuint32_t R;
  struct {
    vuint32_t ADCSAR_0_RST:1;
    vuint32_t  :3;
    vuint32_t ADCSAR_4_RST:1;
    vuint32_t  :10;
    vuint32_t ADCSAR_b_RST:1;
    vuint32_t PSI5_0_RST:1;
    vuint32_t  :3;
    vuint32_t FLEXRAY_0_RST:1;
    vuint32_t  :2;
    vuint32_t SENT_0_RST:1;
    vuint32_t  :2;
    vuint32_t IIC_0_RST:1;
    vuint32_t  :1;
    vuint32_t DSPI_0_RST:1;
    vuint32_t DSPI_1_RST:1;
    vuint32_t DSPI_4_RST:1;
    vuint32_t DSPI_6_RST:1;
  } B;
} MC_RGM_PRST3_tag;

#if defined(CCFC3008PT)
typedef union MC_RGM_PRST4_union_tag { /* Peripheral Reset Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t GTMINT_RST:1;
  } B;
} MC_RGM_PRST4_tag;
#else
typedef union MC_RGM_PRST4_union_tag { /* Peripheral Reset Register 4 */
  vuint32_t R;
  struct {
    vuint32_t  CANFD12:1;
    vuint32_t  CANFD11:1;
    vuint32_t  CANFD10:1;
    vuint32_t  CANFD9:1;
    vuint32_t  CANFD8:1;
    vuint32_t  CANFD7:1;
    vuint32_t  CANFD6:1;
    vuint32_t  CANFD5:1;
    vuint32_t  CANFD4:1;
    vuint32_t  CANFD3:1;
    vuint32_t  CANFD2:1;
    vuint32_t  CANFD1:1;
    vuint32_t  :13;
    vuint32_t  I2S0:1;
    vuint32_t  I2S1:1;
    vuint32_t  EMIOS1:1;
    vuint32_t  EMIOS0:1;
    vuint32_t  ETPU_C:1;
    vuint32_t  ETPU:1;
    vuint32_t GTMINT_RST:1;
  } B;
} MC_RGM_PRST4_tag;
#endif

typedef union MC_RGM_PRST5_union_tag { /* Peripheral Reset Register 5 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t ADCSD_1_RST:1;
    vuint32_t ADCSD_3_RST:1;
    vuint32_t ADCSD_5_RST:1;
    vuint32_t ADCSD_7_RST:1;
    vuint32_t ADCSD_9_RST:1;
    vuint32_t  :14;
    vuint32_t FCCU_RST:1;
    vuint32_t  :2;
    vuint32_t CRC_1_RST:1;
    vuint32_t  :3;
    vuint32_t PSI5_S_0_RST:1;
    vuint32_t  :2;
  } B;
} MC_RGM_PRST5_tag;

#if defined(CCFC3008PT)
typedef union MC_RGM_PRST6_union_tag { /* Peripheral Reset Register 6 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t LINFlexD_2_RST:1;
    vuint32_t  :6;
    vuint32_t LINFlexD_15_RST:1;
    vuint32_t  :21;
  } B;
} MC_RGM_PRST6_tag;
#else
typedef union MC_RGM_PRST6_union_tag { /* Peripheral Reset Register 6 */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t LINFlexD_2_RST:1;
    vuint32_t LINFlexD_7_RST:1;
    vuint32_t LINFlexD_8_RST:1;
    vuint32_t LINFlexD_9_RST:1;
    vuint32_t LINFlexD_10_RST:1;
    vuint32_t LINFlexD_11_RST:1;
    vuint32_t LINFlexD_12_RST:1;
    vuint32_t LINFlexD_15_RST:1;
    vuint32_t  :21;
  } B;
} MC_RGM_PRST6_tag;
#endif

typedef union MC_RGM_PRST7_union_tag { /* Peripheral Reset Register 7 */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t ADCSAR_1_RST:1;
    vuint32_t ADCSAR_2_RST:1;
    vuint32_t ADCSAR_3_RST:1;
    vuint32_t  :1;
    vuint32_t ADCSAR_5_RST:1;
    vuint32_t ADCSAR_6_RST:1;
    vuint32_t ADCSAR_7_RST:1;
    vuint32_t ADCSAR_8_RST:1;
    vuint32_t ADCSAR_9_RST:1;
    vuint32_t ADCSAR_10_RST:1;
    vuint32_t  :5;
    vuint32_t PSI5_1_RST:1;
    vuint32_t  :3;
    vuint32_t FLEXRAY_1_RST:1;
    vuint32_t  :2;
    vuint32_t SENT_1_RST:1;
    vuint32_t  :2;
    vuint32_t IIC_1_RST:1;
    vuint32_t  :1;
    vuint32_t DSPI_2_RST:1;
    vuint32_t DSPI_3_RST:1;
    vuint32_t DSPI_5_RST:1;
    vuint32_t  :1;
  } B;
} MC_RGM_PRST7_tag;

struct MC_RGM_tag {
  MC_RGM_DES_tag DES;                  /* 'Destructive' Event Status Register */
  uint8_t MC_RGM_reserved0[12];
  MC_RGM_DERD_tag DERD;                /* 'Destructive' Event Reset Disable Register */
  uint8_t MC_RGM_reserved1[12];
  MC_RGM_DEAR_tag DEAR;                /* 'Destructive' Event Alternate Request Register */
  uint8_t MC_RGM_reserved2[12];
  MC_RGM_DBRE_tag DBRE;                /* 'Destructive' Bidirectional Reset Enable Register */
  uint8_t MC_RGM_reserved3[716];
  MC_RGM_FES_tag FES;                  /* 'Functional' Event Status Register */
  uint8_t MC_RGM_reserved4[12];
  MC_RGM_FERD_tag FERD;                /* 'Functional' Event Reset Disable Register */
  uint8_t MC_RGM_reserved5[12];
  MC_RGM_FEAR_tag FEAR;                /* 'Functional' Event Alternate Request Register */
  uint8_t MC_RGM_reserved6[12];
  MC_RGM_FBRE_tag FBRE;                /* 'Functional' Bidirectional Reset Enable Register */
  uint8_t MC_RGM_reserved7[12];
  MC_RGM_FESS_tag FESS;                /* 'Functional' Event Short Sequence Register */
  uint8_t MC_RGM_reserved8[704];
  MC_RGM_FRET_tag FRET;                /* 'Functional' Reset Escalation Threshold Register */
  uint8_t MC_RGM_reserved9[3];
  MC_RGM_DRET_tag DRET;                /* 'Destructive' Reset Escalation Threshold Register */
  uint8_t MC_RGM_reserved10[3];
  MC_RGM_EROEC_tag EROEC;              /* External Reset Output Extension Control Register */
  uint8_t MC_RGM_reserved11[3];
  MC_RGM_PRST0_tag PRST0;              /* Peripheral Reset Register 0 */
  MC_RGM_PRST1_tag PRST1;              /* Peripheral Reset Register 1 */
  MC_RGM_PRST2_tag PRST2;              /* Peripheral Reset Register 2 */
  MC_RGM_PRST3_tag PRST3;              /* Peripheral Reset Register 3 */
  MC_RGM_PRST4_tag PRST4;              /* Peripheral Reset Register 4 */
  MC_RGM_PRST5_tag PRST5;              /* Peripheral Reset Register 5 */
  MC_RGM_PRST6_tag PRST6;              /* Peripheral Reset Register 6 */
  MC_RGM_PRST7_tag PRST7;              /* Peripheral Reset Register 7 */
};
#endif
