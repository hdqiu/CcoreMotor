#ifndef _TESTER_ICU_H_
#define _TESTER_ICU_H_

typedef void (*Icufunc)(void);
typedef struct _IcufuncMachine
{
    char *name;
    Icufunc icufunc;
}IcufuncMachine;
FUNC(status_t, ICU_CODE) eMIOS_LLD_SetIRQ
(
    VAR(uint8_t, AUTOMATIC) emiosIndex, \
    VAR(uint8_t, AUTOMATIC) ChanNum \
);
FUNC(status_t, ICU_CODE) eTPU_LLD_SetIRQ
(
    VAR(uint8_t, AUTOMATIC) etpuIndex, \
    VAR(uint8_t, AUTOMATIC) ChanNum \
);
void ICU_GPT_Callback_10ms_Function(void);
void ICU_GPT_Callback_20ms_Function(void);
void ICU_GPT_Callback_30ms_Function(void);
void icu_de_init();
void Icu_Test_Demo(void);
void icuinit();
void icu_01(void);
void icu_02(void);
void icu_03(void);
void icu_04(void);

void wakeup_intc();
void IcuSignalNotification_0(void);
void IcuSignalNotification_1(void);
void IcuSignalNotification_2(void);
void IcuSignalNotification_3(void);
void IcuSignalNotification_4(void);
void IcuSignalNotification_5(void);
void IcuSignalNotification_6(void);
void IcuSignalNotification_7(void);
void IcuSignalNotification_8(void);
void IcuSignalNotification_9(void);
void IcuSignalNotification_10(void);
void IcuSignalNotification_11(void);
void IcuSignalNotification_12(void);
void IcuSignalNotification_13(void);
void IcuSignalNotification_14(void);
void IcuSignalNotification_15(void);
void IcuSignalNotification_16(void);
void IcuSignalNotification_17(void);
void IcuSignalNotification_18(void);
void IcuSignalNotification_19(void);
void IcuSignalNotification_20(void);
void IcuSignalNotification_21(void);
void IcuSignalNotification_22(void);
void IcuSignalNotification_23(void);
void IcuSignalNotification_24(void);
void IcuSignalNotification_25(void);
void IcuSignalNotification_26(void);
void IcuSignalNotification_27(void);
void IcuSignalNotification_28(void);
void IcuSignalNotification_29(void);
void IcuSignalNotification_30(void);
void IcuSignalNotification_31(void);
void IcuSignalNotification_32(void);
void IcuSignalNotification_33(void);
void IcuSignalNotification_34(void);
void IcuSignalNotification_35(void);
void IcuSignalNotification_36(void);
void IcuSignalNotification_37(void);
void IcuSignalNotification_38(void);
void IcuSignalNotification_39(void);
void IcuSignalNotification_40(void);
void IcuSignalNotification_41(void);
void IcuSignalNotification_42(void);
void IcuSignalNotification_43(void);
void IcuSignalNotification_44(void);
void IcuSignalNotification_45(void);
void IcuSignalNotification_46(void);
void IcuSignalNotification_47(void);
void IcuSignalNotification_48(void);
void IcuSignalNotification_49(void);
void IcuSignalNotification_50(void);
void IcuSignalNotification_51(void);
void IcuSignalNotification_52(void);
void IcuSignalNotification_53(void);
void IcuSignalNotification_54(void);
void IcuSignalNotification_55(void);
void IcuSignalNotification_56(void);
void IcuSignalNotification_57(void);
void IcuSignalNotification_58(void);
void IcuSignalNotification_59(void);
void IcuSignalNotification_60(void);
void IcuSignalNotification_61(void);
void IcuSignalNotification_62(void);
void IcuSignalNotification_63(void);
void IcuSignalNotification_64(void);
void IcuSignalNotification_65(void);
void IcuSignalNotification_66(void);
void IcuSignalNotification_67(void);
void IcuSignalNotification_68(void);
void IcuSignalNotification_69(void);
void IcuSignalNotification_70(void);
void IcuSignalNotification_71(void);
void IcuSignalNotification_72(void);
void IcuSignalNotification_73(void);
void IcuSignalNotification_74(void);
void IcuSignalNotification_75(void);
void IcuSignalNotification_76(void);
void IcuSignalNotification_77(void);
void IcuSignalNotification_78(void);
void IcuSignalNotification_79(void);
void IcuSignalNotification_80(void);
void IcuSignalNotification_81(void);
void IcuSignalNotification_82(void);
void IcuSignalNotification_83(void);
void IcuSignalNotification_84(void);
void IcuSignalNotification_85(void);
void IcuSignalNotification_86(void);
void IcuSignalNotification_87(void);
void IcuSignalNotification_88(void);
void IcuSignalNotification_89(void);
void IcuSignalNotification_90(void);
void IcuSignalNotification_91(void);
void IcuSignalNotification_92(void);
void IcuSignalNotification_93(void);
void IcuSignalNotification_94(void);
void IcuSignalNotification_95(void);
void IcuTimestampNotification_0(void);
void IcuTimestampNotification_1(void);
void IcuTimestampNotification_2(void);
void IcuTimestampNotification_3(void);
void IcuTimestampNotification_4(void);
void IcuTimestampNotification_5(void);
void IcueMiosignalNotification_0(void);
void ETPU_IC_Init(void);
int icu_func(int argc, char *agrv[]);

#endif //_TESTER_ICU_H_

