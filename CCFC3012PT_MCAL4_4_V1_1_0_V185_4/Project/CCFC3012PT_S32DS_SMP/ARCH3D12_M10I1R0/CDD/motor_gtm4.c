#include "motor_gtm4.h"
#include "eDma_LLDriver.h"
#include "intc_lld.h"
#ifdef RESOURCE_SUPPORT_EIOMUX
#include "eiomux_lld.h"
#endif
#ifdef RESORUCE_SUPPORT_GTM410
typedef float float32_t;		 /*PRQA S 0631 */

#define FIFO_SIZE	64  /* 50 entries to generate cosine */

extern const uint32_t EXC_CARDIG_Buffer[FIFO_SIZE];

const GTM_TOUT_MUX_t GTM_TOUT_MUX[] = {
            {0   ,    9     ,    32  },     // PC[0]
            {1   ,    8     ,    33  },     // PC[1]
            {2   ,    6     ,    34  },     // PC[2]
            {3   ,    11    ,    35  },     // PC[3]
            {4   ,    11    ,    36  },     // PC[4]
            {5   ,    10    ,    37  },     // PC[5]
            {6   ,    13    ,    38  },     // PC[6]
            {7   ,    13    ,    39  },     // PC[7]
            {8   ,    13    ,    40  },     // PC[8]
            {9   ,    8     ,    0   },     // PA[0]
            {10  ,    14    ,    1   },     // PA[1]
            {11  ,    8     ,    2   },     // PA[2]
            {12  ,    14    ,    3   },     // PA[3]
            {13  ,    13    ,    4   },     // PA[4]
            {14  ,    12    ,    5   },     // PA[5]
            {15  ,    11    ,    6   },     // PA[6]
            {16  ,    12    ,    7   },     // PA[7]
            {17  ,    13    ,    8   },     // PA[8]
            {18  ,    13    ,    9   },     // PA[9]
            {19  ,    7     ,    10  },     // PA[10]
            {20  ,    9     ,    11  },     // PA[11]
            {21  ,    10    ,    12  },     // PA[12]
            {22  ,    8     ,    241 },     // PP[1]
            {23  ,    11    ,    242 },     // PP[2]
            {24  ,    8     ,    243 },     // PP[3]
            {25  ,    8     ,    244 },     // PP[4]
            {26  ,    11    ,    245 },     // PP[5]
            {27  ,    13    ,    246 },     // PP[6]
            {28  ,    11    ,    247 },     // PP[7]
            {29  ,    8     ,    248 },     // PP[8]
            {30  ,    6     ,    249 },     // PP[9]
            {31  ,    4     ,    250 },     // PP[10]
            {32  ,    9     ,    251 },     // PP[11]
            {33  ,    4     ,    252 },     // PP[12]
            {34  ,    6     ,    253 },     // PP[13]
            {35  ,    9     ,    254 },     // PP[14]
            {36  ,    3     ,    233 },     // PO[9]
            {37  ,    2     ,    234 },     // PO[10]
            {38  ,    7     ,    235 },     // PO[11]
            {39  ,    3     ,    236 },     // PO[12]
            {40  ,    5     ,    237 },     // PO[13]
            {41  ,    5     ,    160 },     // PK[0]
            {42  ,    7     ,    161 },     // PK[1]
            {43  ,    6     ,    162 },     // PK[2]
            {44  ,    9     ,    163 },     // PK[3]
            {45  ,    4     ,    164 },     // PK[4]
            {46  ,    4     ,    165 },     // PK[5]
            {47  ,    7     ,    148 },     // PJ[4]
            {48  ,    7     ,    149 },     // PJ[5]
            {49  ,    5     ,    150 },     // PJ[6]
            {50  ,    7     ,    151 },     // PJ[7]
            {51  ,    9     ,    140 },     // PI[12]
            {52  ,    9     ,    141 },     // PI[13]
            {53  ,    12    ,    142 },     // PI[14]
            {54  ,    9     ,    143 },     // PI[15]
            {55  ,    4     ,    144 },     // PJ[0]
            {56  ,    6     ,    145 },     // PJ[1]
            {57  ,    9     ,    146 },     // PJ[2]
            {58  ,    7     ,    147 },     // PJ[3]
            {59  ,    10    ,    127 },     // PH[15]
            {60  ,    6     ,    128 },     // PI[0]
            {61  ,    7     ,    130 },     // PI[2]
            {62  ,    7     ,    131 },     // PI[3]
            {63  ,    10    ,    132 },     // PI[4]
            {64  ,    5     ,    133 },     // PI[5]
            {65  ,    9     ,    134 },     // PI[6]
            {66  ,    4     ,    135 },     // PI[7]
            {67  ,    5     ,    136 },     // PI[8]
            {68  ,    5     ,    137 },     // PI[9]
            {69  ,    5     ,    138 },     // PI[10]
            {70  ,    5     ,    139 },     // PI[11]
            {71  ,    4     ,    112 },     // PH[0]
            {72  ,    8     ,    113 },     // PH[1]
            {73  ,    7     ,    114 },     // PH[2]
            {74  ,    9     ,    115 },     // PH[3]
            {75  ,    7     ,    116 },     // PH[4]
            {76  ,    8     ,    117 },     // PH[5]
            {77  ,    5     ,    118 },     // PH[6]
            {78  ,    6     ,    119 },     // PH[7]
            {79  ,    5     ,    120 },     // PH[8]
            {80  ,    4     ,    96  },     // PG[0]
            {81  ,    11    ,    97  },     // PG[1]
            {82  ,    4     ,    98  },     // PG[2]
            {83  ,    8     ,    99  },     // PG[3]
            {84  ,    5     ,    100 },     // PG[4]
            {85  ,    6     ,    101 },     // PG[5]
            {86  ,    4     ,    102 },     // PG[6]
            {87  ,    10    ,    103 },     // PG[7]
            {88  ,    8     ,    104 },     // PG[8]
            {89  ,    7     ,    105 },     // PG[9]
            {90  ,    5     ,    106 },     // PG[10]
            {91  ,    5     ,    81  },     // PF[1]
            {92  ,    7     ,    82  },     // PF[2]
            {93  ,    5     ,    83  },     // PF[3]
            {94  ,    3     ,    84  },     // PF[4]
            {95  ,    3     ,    65  },     // PE[1]
            {96  ,    5     ,    66  },     // PE[2]
            {97  ,    4     ,    69  },     // PE[5]
            {98  ,    6     ,    72  },     // PE[8]
            {99  ,    12    ,    73  },     // PE[9]
            {100 ,    8     ,    74  },     // PE[10]
            {101 ,    6     ,    75  },     // PE[11]
            {102 ,    9     ,    48  },     // PD[0]
            {103 ,    7     ,    49  },     // PD[1]
            {104 ,    10    ,    50  },     // PD[2]
            {105 ,    7     ,    51  },     // PD[3]
            {106 ,    9     ,    52  },     // PD[4]
            {107 ,    7     ,    53  },     // PD[5]
            {108 ,    9     ,    54  },     // PD[6]
            {109 ,    8     ,    55  },     // PD[7]
            {110 ,    11    ,    56  },     // PD[8]
            {111 ,    6     ,    19  },     // PB[3]
            {112 ,    6     ,    20  },     // PB[4]
            {113 ,    8     ,    21  },     // PB[5]
            {114 ,    6     ,    22  },     // PB[6]
            {115 ,    7     ,    23  },     // PB[7]
            {116 ,    7     ,    41  },     // PC[9]
            {117 ,    10    ,    42  },     // PC[10]
            {118 ,    5     ,    43  },     // PC[11]
            {119 ,    7     ,    63  },     // PD[15]
            {120 ,    4     ,    64  },     // PE[0]
            {121 ,    5     ,    67  },     // PE[3]
            {122 ,    5     ,    68  },     // PE[4]
            {123 ,    5     ,    70  },     // PE[6]
            {124 ,    5     ,    71  },     // PE[7]
            {125 ,    6     ,    76  },     // PE[12]
            {126 ,    8     ,    77  },     // PE[13]
            {127 ,    4     ,    78  },     // PE[14]
            {128 ,    7     ,    79  },     // PE[15]
            {129 ,    5     ,    80  },     // PF[0]
            {130 ,    5     ,    152 },     // PJ[8]
            {131 ,    4     ,    153 },     // PJ[9]
            {132 ,    6     ,    154 },     // PJ[10]
            {133 ,    4     ,    155 },     // PJ[11]
            {134 ,    4     ,    156 },     // PJ[12]
            {135 ,    8     ,    157 },     // PJ[13]
            {136 ,    4     ,    158 },     // PJ[14]
            {137 ,    4     ,    159 },     // PJ[15]
            {138 ,    5     ,    166 },     // PK[6]
            {139 ,    5     ,    167 },     // PK[7]
            {140 ,    5     ,    238 },     // PO[14]
            {141 ,    11    ,    239 },     // PO[15]
            {142 ,    7     ,    240 },     // PP[0]
            {143 ,    6     ,    255 },     // PP[15]
            {144 ,    5     ,    256 },     // PQ[0]
            {146 ,    4     ,    257 },     // PQ[1]
            {147 ,    8     ,    258 },     // PQ[2]
            {148 ,    4     ,    259 },     // PQ[3]
            {149 ,    5     ,    260 },     // PQ[4]
            {150 ,    7     ,    261 },     // PQ[5]
            {151 ,    7     ,    44  },     // PC[12]
            {152 ,    6     ,    47  },     // PC[15]
            {153 ,    7     ,    45  },     // PC[13]
            {154 ,    8     ,    46  },     // PC[14]
            {155 ,    9     ,    16  },     // PB[0]
            {156 ,    4     ,    18  },     // PB[2]
            {157 ,    7     ,    31  },     // PB[15]
            {158 ,    6     ,    28  },     // PB[12]
            {159 ,    6     ,    17  },     // PB[1]
            {160 ,    6     ,    25  },     // PB[9]
            {161 ,    6     ,    29  },     // PB[13]
            {162 ,    13    ,    24  },     // PB[8]
            {163 ,    9     ,    26  },     // PB[10]
            {164 ,    6     ,    30  },     // PB[14]
            {165 ,    9     ,    27  },     // PB[11]
            {166 ,    5     ,    14  },     // PA[14]
            {167 ,    5     ,    13  },     // PA[13]
            {168 ,    5     ,    15  },     // PA[15]
            {174 ,    4     ,    217 },     // PN[9]
            {175 ,    4     ,    218 },     // PN[10]
            {176 ,    4     ,    219 },     // PN[11]
            {177 ,    4     ,    220 },     // PN[12]
            {178 ,    4     ,    221 },     // PN[13]
            {179 ,    4     ,    222 },     // PN[14]
            {180 ,    4     ,    223 },     // PN[15]
            {181 ,    4     ,    224 },     // PO[0]
            {182 ,    5     ,    225 },     // PO[1]
            {183 ,    5     ,    226 },     // PO[2]
            {184 ,    5     ,    227 },     // PO[3]
            {185 ,    5     ,    228 },     // PO[4]
            {186 ,    5     ,    229 },     // PO[5]
            {187 ,    4     ,    230 },     // PO[6]
            {188 ,    4     ,    231 },     // PO[7]
            {189 ,    4     ,    232 },     // PO[8]
            {190 ,    4     ,    201 },     // PM[9]
            {191 ,    4     ,    202 },     // PM[10]
            {192 ,    4     ,    203 },     // PM[11]
            {193 ,    4     ,    204 },     // PM[12]
            {194 ,    4     ,    205 },     // PM[13]
            {195 ,    4     ,    206 },     // PM[14]
            {196 ,    4     ,    207 },     // PM[15]
            {197 ,    4     ,    208 },     // PN[0]
            {198 ,    4     ,    209 },     // PN[1]
            {199 ,    4     ,    210 },     // PN[2]
            {200 ,    4     ,    211 },     // PN[3]
            {201 ,    4     ,    212 },     // PN[4]
            {202 ,    4     ,    213 },     // PN[5]
            {203 ,    4     ,    214 },     // PN[6]
            {204 ,    4     ,    215 },     // PN[7]
            {205 ,    4     ,    216 },     // PN[8]
            {206 ,    3     ,    184 },     // PL[8]
            {207 ,    4     ,    185 },     // PL[9]
            {208 ,    4     ,    186 },     // PL[10]
            {209 ,    4     ,    187 },     // PL[11]
            {210 ,    4     ,    188 },     // PL[12]
            {211 ,    4     ,    189 },     // PL[13]
            {212 ,    4     ,    190 },     // PL[14]
            {212 ,    4     ,    200 },     // PM[8]
            {213 ,    4     ,    191 },     // PL[15]
            {214 ,    3     ,    192 },     // PM[0]
            {215 ,    3     ,    193 },     // PM[1]
            {216 ,    3     ,    194 },     // PM[2]
            {217 ,    3     ,    195 },     // PM[3]
            {218 ,    3     ,    196 },     // PM[4]
            {219 ,    3     ,    197 },     // PM[5]
            {220 ,    3     ,    198 },     // PM[6]
            {221 ,    2     ,    199 },     // PM[7]
            {222 ,    4     ,    168 },     // PK[8]
            {223 ,    4     ,    169 },     // PK[9]
            {224 ,    4     ,    170 },     // PK[10]
            {225 ,    4     ,    171 },     // PK[11]
            {226 ,    4     ,    172 },     // PK[12]
            {227 ,    4     ,    173 },     // PK[13]
            {228 ,    4     ,    174 },     // PK[14]
            {229 ,    4     ,    175 },     // PK[15]
            {230 ,    4     ,    176 },     // PL[0]
            {231 ,    4     ,    177 },     // PL[1]
            {232 ,    4     ,    178 },     // PL[2]
            {233 ,    4     ,    179 },     // PL[3]
            {234 ,    4     ,    180 },     // PL[4]
            {235 ,    4     ,    181 },     // PL[5]
            {236 ,    5     ,    182 },     // PL[6]
            {237 ,    4     ,    183 },     // PL[7]
            {242 ,    5     ,    121 },     // PH[9]
            {243 ,    5     ,    122 },     // PH[10]
            {244 ,    4     ,    123 },     // PH[11]
            {245 ,    4     ,    124 },     // PH[12]
            {246 ,    5     ,    125 },     // PH[13]
            {247 ,    5     ,    126 },     // PH[14]
            {248 ,    5     ,    89  },     // PF[9]
            {249 ,    8     ,    92  },     // PF[12]
            {250 ,    9     ,    91  },     // PF[11]
            {251 ,    6     ,    90  },     // PF[10]
            {252 ,    4     ,    94  },     // PF[14]
            {253 ,    4     ,    85  },     // PF[5]
            {254 ,    5     ,    86  },     // PF[6]
            {255 ,    4     ,    87  },     // PF[7]
            {256 ,    4     ,    88  },     // PF[8]
            {258 ,    5     ,    107 },     // PG[11]
            {259 ,    5     ,    110 },     // PG[14]
            {260 ,    5     ,    109 },     // PG[13]
            {261 ,    5     ,    108 },     // PG[12]
            {262 ,    6     ,    93  },     // PF[13]
            {263 ,    11    ,    111 },     // PG[15]
            {264 ,    4     ,    95  },     // PF[15]
            {265 ,    7     ,    57  },     // PD[9]
            {266 ,    5     ,    58  },     // PD[10]
            {267 ,    5     ,    61  },     // PD[13]
            {268 ,    5     ,    60  },     // PD[12]
            {269 ,    5     ,    59  },     // PD[11]
            {270 ,    4     ,    62  },     // PD[14]

            {0x5a5a,  0     ,    0   },
};



//void GTM_TOM_PWM_Init(GTM_TOM_Type GTM_TOMn, GTM_TOM_Channel_Type CHn, uint32_t freq, uint32_t duty)
//{
//	uint32_t sys_clk = 0U;
//	GTM_TOM_ClockSource_Type fxclk_sel = TOM_CLK_SRC_CMU_FXCLK0;
//	float32_t out_clk = 0.0F;
//	float32_t Numerator = 0.0F;
//	float32_t Denominator = 0.0F;
//	float32_t Multiplier = 0.0F;
//	float32_t t = 0.0F;
//	float32_t d = 0.0F;
//	uint32_t cnt1 = 0U;
//	uint32_t cnt2 = 0U;
//
////	(void)CLOCK_GetModuleClockFreq(PER_CLK,&sys_clk);
//	Numerator = (float32_t)GTM_CMU_LLD_GetGlobalClockNumerator();
//	Denominator = (float32_t)GTM_CMU_LLD_GetGlobalClockDenominator();
//	Multiplier = Numerator / Denominator;
//
//	fxclk_sel = GTM_TOM_LLD_Channel_GetClockSource_lld(GTM_TOMn, CHn);
//
//	switch(fxclk_sel)
//	{
//		case TOM_CLK_SRC_CMU_FXCLK0:
//			out_clk = ((float32_t)sys_clk * Multiplier);
//			break;
//		case TOM_CLK_SRC_CMU_FXCLK1:
//			out_clk = ((float32_t)sys_clk * Multiplier) / 16.0F;
//			break;
//		case TOM_CLK_SRC_CMU_FXCLK2:
//			out_clk = ((float32_t)sys_clk * Multiplier) / 256.0F;
//			break;
//		case TOM_CLK_SRC_CMU_FXCLK3:
//			out_clk = ((float32_t)sys_clk * Multiplier) / 4096.0F;
//			break;
//		case TOM_CLK_SRC_CMU_FXCLK4:
//			out_clk = ((float32_t)sys_clk * Multiplier) / 65536.0F;
//			break;
//		default:
//			break;
//	}
//
//	t = (out_clk / (float32_t)freq);
//	cnt1 = (uint32_t)t;
//
//	if((t - (float32_t)cnt1) > 0.5F)
//	{
//		cnt1++;
//	}
//
//	d = (float32_t)duty / 100.0F * (float32_t)cnt1;
//	cnt2 = (uint32_t)(d);
//	(void)GTM_TOM_LLD_Channel_SetCompareRegister_lld(GTM_TOMn,CHn,(uint16_t)cnt1,(uint16_t)cnt2);
//}
volatile uint32_t cnt1_ATOM4;
void GTM_ATOM_PWM_Init(GTM_ATOM_Type GTM_ATOMn, GTM_ATOM_Channel_Type CHn, uint32_t freq, uint32_t duty)
{
//	uint32_t sys_clk = 0U;
//	GTM_ATOM_ClockSource_Type fxclk_sel = ATOM_CLK_SRC_CMU_CLK0;
	float32_t out_clk = 200000000.0F;
//	float32_t Numerator = 0.0F;
//	float32_t Denominator =  0.0F;
//	float32_t Multiplier =  0.0F;
	float32_t t = 0.0F;
	float32_t d =  0.0F;
	uint32_t cnt1 = 0U;
	uint32_t cnt2 = 0U;

//	(void)CLOCK_GetModuleClockFreq_lld(PER_CLK,&sys_clk);
//	Numerator = (float32_t)GTM_CMU_LLD_GetGlobalClockNumerator();
//	Denominator = (float32_t)GTM_CMU_LLD_GetGlobalClockDenominator();
//	Multiplier = Numerator / Denominator;
//
//	fxclk_sel = GTM_ATOM_LLD_Channel_GetClockSource_lld(GTM_ATOMn, CHn);
//
//	switch(fxclk_sel)
//	{
//		case ATOM_CLK_SRC_CMU_CLK0:
//			out_clk = ((float32_t)sys_clk * Multiplier) / ((float32_t)GTM_CMU_LLD_GetClockCount(CMU_CLK0) + 1.0F);
//			break;
//		case ATOM_CLK_SRC_CMU_CLK1:
//			out_clk = ((float32_t)sys_clk * Multiplier) / ((float32_t)GTM_CMU_LLD_GetClockCount(CMU_CLK1) + 1.0F);
//			break;
//		case ATOM_CLK_SRC_CMU_CLK2:
//			out_clk = ((float32_t)sys_clk * Multiplier) / ((float32_t)GTM_CMU_LLD_GetClockCount(CMU_CLK2) +  1.0F);
//			break;
//		case ATOM_CLK_SRC_CMU_CLK3:
//			out_clk = ((float32_t)sys_clk * Multiplier) / ((float32_t)GTM_CMU_LLD_GetClockCount(CMU_CLK3) +  1.0F);
//			break;
//		case ATOM_CLK_SRC_CMU_CLK4:
//			out_clk = ((float32_t)sys_clk * Multiplier) / ((float32_t)GTM_CMU_LLD_GetClockCount(CMU_CLK4) +  1.0F);
//			break;
//		case ATOM_CLK_SRC_CMU_CLK5:
//			out_clk = ((float32_t)sys_clk * Multiplier) / ((float32_t)GTM_CMU_LLD_GetClockCount(CMU_CLK5) +  1.0F);
//			break;
//		case ATOM_CLK_SRC_CMU_CLK6:
//			out_clk = ((float32_t)sys_clk * Multiplier) / ((float32_t)GTM_CMU_LLD_GetClockCount(CMU_CLK6) +  1.0F);
//			break;
//		case ATOM_CLK_SRC_CMU_CLK7:
//			out_clk = ((float32_t)sys_clk * Multiplier) / ((float32_t)GTM_CMU_LLD_GetClockCount(CMU_CLK7) +  1.0F);
//			break;
//		default:
//			break;
//	}
//
	t = (out_clk / (float32_t)freq);
	cnt1 = (uint32_t)t;

	if((t - (float32_t)cnt1) > 0.5F)
	{
		cnt1++;
	}

	d = (float32_t)duty / 100.0F * (float32_t)(cnt1);
	cnt1++;
	cnt1_ATOM4 = cnt1;
	cnt2 = (uint32_t)(d);
//	(void)GTM_ATOM_LLD_Channel_SetCompareRegister_lld(GTM_ATOMn,CHn,cnt1,cnt2);

	GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOMn,CHn,cnt1,cnt2);
}


void GTM_ATOM_PWM_OUTPUT(void)
{
	uint32_t freq = 0U;

	(void)GTM_LLD_IsEnableModule_lld(Enable);
	(void)GTM_LLD_IsEnableClsDiv_lld(GTM_CLS4, ClsEnableWithoutDiv);
	(void)GTM_LLD_IsEnableClsDiv_lld(GTM_CLS5, ClsEnableWithoutDiv);

#ifdef RESOURCE_SUPPORT_SIUL_IP
    /* ATOM4 CH0 PO12 */
    SIUL.PCR[GTM_TOUT_MUX[39].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[39].PAD_NUM].B.PA = GTM_TOUT_MUX[39].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[39].TOUT_NUM, 8);
    /* ATOM4 CH0_N PG7 */
    SIUL.PCR[GTM_TOUT_MUX[87].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[87].PAD_NUM].B.PA = GTM_TOUT_MUX[87].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[87].TOUT_NUM, 10);

    /* ATOM4 CH1 PK0 */
    SIUL.PCR[GTM_TOUT_MUX[41].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[41].PAD_NUM].B.PA = GTM_TOUT_MUX[41].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[41].TOUT_NUM, 9);
    /* ATOM4 CH1_N PK3 */
    SIUL.PCR[GTM_TOUT_MUX[44].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[44].PAD_NUM].B.PA = GTM_TOUT_MUX[44].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[44].TOUT_NUM, 10);

    /* ATOM4 CH2 PK1 */
    SIUL.PCR[GTM_TOUT_MUX[42].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[42].PAD_NUM].B.PA = GTM_TOUT_MUX[42].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[42].TOUT_NUM, 9);
    /* ATOM4 CH2_N PK4 */
    SIUL.PCR[GTM_TOUT_MUX[45].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[45].PAD_NUM].B.PA = GTM_TOUT_MUX[45].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[45].TOUT_NUM, 10);

    /* ATOM5 CH0 PD15 */
    SIUL.PCR[GTM_TOUT_MUX[119].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[119].PAD_NUM].B.PA = GTM_TOUT_MUX[119].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[119].TOUT_NUM, 2);
    /* ATOM5 CH0_N PE13 */
    SIUL.PCR[GTM_TOUT_MUX[126].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[126].PAD_NUM].B.PA = GTM_TOUT_MUX[126].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[126].TOUT_NUM, 8);
//
    /* ATOM5 CH1 PE0 */
    SIUL.PCR[GTM_TOUT_MUX[120].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[120].PAD_NUM].B.PA = GTM_TOUT_MUX[120].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[120].TOUT_NUM, 2);
    /* ATOM5 CH1_N PE6 */
    SIUL.PCR[GTM_TOUT_MUX[123].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[123].PAD_NUM].B.PA = GTM_TOUT_MUX[123].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[123].TOUT_NUM, 8);

    /* ATOM5 CH2 PE3 */
    SIUL.PCR[GTM_TOUT_MUX[121].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[121].PAD_NUM].B.PA = GTM_TOUT_MUX[121].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[121].TOUT_NUM, 2);
    /* ATOM5 CH2_N PE7 */
    SIUL.PCR[GTM_TOUT_MUX[124].PAD_NUM].R = 0x0080;
    SIUL.PCR[GTM_TOUT_MUX[124].PAD_NUM].B.PA = GTM_TOUT_MUX[124].Alt_FUN;
    GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[124].TOUT_NUM, 8);

#endif
	(void)GTM_CMU_LLD_IsEnableClock(GTM4_CMU_FXCLK,Enable);
	(void)GTM_CMU_LLD_IsEnableClock(GTM4_CMU_CLK0,Enable);

	(void)GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM5,GTM_ATOM_CH0,ATOM_MODE_SOMP);
	(void)GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM5,GTM_ATOM_CH1,ATOM_MODE_SOMP);
	(void)GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM5,GTM_ATOM_CH2,ATOM_MODE_SOMP);
	(void)GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM5,GTM_ATOM_CH4,ATOM_MODE_SOMP);//TODO

	(void)GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM4,GTM_ATOM_CH0,ATOM_MODE_SOMP);
	(void)GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM4,GTM_ATOM_CH1,ATOM_MODE_SOMP);
	(void)GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM4,GTM_ATOM_CH2,ATOM_MODE_SOMP);
	(void)GTM_ATOM_LLD_Channel_SelectATOMMode_lld(GTM_ATOM4,GTM_ATOM_CH4,ATOM_MODE_SOMP);//TODO

    freq = 200000000/PWM_PERIOD;

	(void)GTM_ATOM_PWM_Init(GTM_ATOM5, GTM_ATOM_CH0, freq, 50);//20000
	(void)GTM_ATOM_PWM_Init(GTM_ATOM5, GTM_ATOM_CH1, freq, 50);
	(void)GTM_ATOM_PWM_Init(GTM_ATOM5, GTM_ATOM_CH2, freq, 50);

	(void)GTM_ATOM_PWM_Init(GTM_ATOM4, GTM_ATOM_CH0, freq, 50);//2000000ok//20000
	(void)GTM_ATOM_PWM_Init(GTM_ATOM4, GTM_ATOM_CH1, freq, 50);
	(void)GTM_ATOM_PWM_Init(GTM_ATOM4, GTM_ATOM_CH2, freq, 50);

	//CMU_CLK0, Duty cycle active high, Continuous running, SOMP, CN counts up then down, CMx are reloaded when CN0=0; ARU enabled
	GTM4.GLS[4].ATOM.CH[4].CN0.R = 0;
	GTM4.GLS[4].ATOM.CH[4].CM1.B.CM1 = 200; //PWM Duty (High Time)
	GTM4.GLS[4].ATOM.CH[4].CM0.B.CM0 = 20000; //PWM Period 10K
	GTM4.GLS[4].ATOM.CH[4].SR1.B.SR1 = 200; //PWM Duty (High Time)
	GTM4.GLS[4].ATOM.CH[4].SR0.B.SR0 = 20000; //PWM Period 10K

	//CMU_CLK0, Duty cycle active high, Continuous running, SOMP, CN counts up then down, CMx are reloaded when CN0=0; ARU enabled
	GTM4.GLS[5].ATOM.CH[4].CN0.R = 0;
	GTM4.GLS[5].ATOM.CH[4].CM1.B.CM1 = 200; //PWM Duty (High Time)
	GTM4.GLS[5].ATOM.CH[4].CM0.B.CM0 = 20000; //PWM Period 10K
	GTM4.GLS[5].ATOM.CH[4].SR1.B.SR1 = 200; //PWM Duty (High Time)
	GTM4.GLS[5].ATOM.CH[4].SR0.B.SR0 = 20000; //PWM Period 10K

	GTM4.GLS[5].CDTM.DTM[4].CH_DTV[0].B.RELRISE = 400U;
	GTM4.GLS[5].CDTM.DTM[4].CH_DTV[0].B.RELFALL = 400U;
	GTM4.GLS[5].CDTM.DTM[4].CH_DTV[1].B.RELRISE = 400U;
	GTM4.GLS[5].CDTM.DTM[4].CH_DTV[1].B.RELFALL = 400U;
	GTM4.GLS[5].CDTM.DTM[4].CH_DTV[2].B.RELRISE = 400U;
	GTM4.GLS[5].CDTM.DTM[4].CH_DTV[2].B.RELFALL = 400U;
	GTM4.GLS[5].CDTM.DTM[5].CH_DTV[0].B.RELRISE = 0;
	GTM4.GLS[5].CDTM.DTM[5].CH_DTV[0].B.RELFALL = 0;

	GTM4.GLS[4].CDTM.DTM[4].CH_DTV[0].B.RELRISE = 400U;
	GTM4.GLS[4].CDTM.DTM[4].CH_DTV[0].B.RELFALL = 400U;
	GTM4.GLS[4].CDTM.DTM[4].CH_DTV[1].B.RELRISE = 400U;
	GTM4.GLS[4].CDTM.DTM[4].CH_DTV[1].B.RELFALL = 400U;
	GTM4.GLS[4].CDTM.DTM[4].CH_DTV[2].B.RELRISE = 400U;
	GTM4.GLS[4].CDTM.DTM[4].CH_DTV[2].B.RELFALL = 400U;
	GTM4.GLS[4].CDTM.DTM[5].CH_DTV[0].B.RELRISE = 0;
	GTM4.GLS[4].CDTM.DTM[5].CH_DTV[0].B.RELFALL = 0;

	GTM4.GLS[5].CDTM.DTM[4].CH_CTRL2.B.DT0_0 = 1U;
	GTM4.GLS[5].CDTM.DTM[4].CH_CTRL2.B.DT1_0 = 1U;

	GTM4.GLS[5].CDTM.DTM[4].CH_CTRL2.B.DT0_1 = 1U;
	GTM4.GLS[5].CDTM.DTM[4].CH_CTRL2.B.DT1_1 = 1U;

	GTM4.GLS[5].CDTM.DTM[4].CH_CTRL2.B.DT0_2 = 1U;
	GTM4.GLS[5].CDTM.DTM[4].CH_CTRL2.B.DT1_2 = 1U;

	GTM4.GLS[5].CDTM.DTM[5].CH_CTRL2.B.DT0_0 = 1U;
	GTM4.GLS[5].CDTM.DTM[5].CH_CTRL2.B.DT1_0 = 1U;

	GTM4.GLS[4].CDTM.DTM[4].CH_CTRL2.B.DT0_0 = 1U;
	GTM4.GLS[4].CDTM.DTM[4].CH_CTRL2.B.DT1_0 = 1U;

	GTM4.GLS[4].CDTM.DTM[4].CH_CTRL2.B.DT0_1 = 1U;
	GTM4.GLS[4].CDTM.DTM[4].CH_CTRL2.B.DT1_1 = 1U;

	GTM4.GLS[4].CDTM.DTM[4].CH_CTRL2.B.DT0_2 = 1U;
	GTM4.GLS[4].CDTM.DTM[4].CH_CTRL2.B.DT1_2 = 1U;

	GTM4.GLS[4].CDTM.DTM[5].CH_CTRL2.B.DT0_0 = 1U;
	GTM4.GLS[4].CDTM.DTM[5].CH_CTRL2.B.DT1_0 = 1U;

	GTM4.GLS[4].ATOM.CH[0].CTRL_SR.B.SL_SR = 1u;
	GTM4.GLS[4].ATOM.CH[1].CTRL_SR.B.SL_SR = 1u;
	GTM4.GLS[4].ATOM.CH[2].CTRL_SR.B.SL_SR = 1u;
	GTM4.GLS[4].ATOM.CH[4].CTRL_SR.B.SL_SR = 1u;

	GTM4.GLS[4].ATOM.CH[0].CTRL.B.UDMODE = 1u;
	GTM4.GLS[4].ATOM.CH[1].CTRL.B.UDMODE = 1u;
	GTM4.GLS[4].ATOM.CH[2].CTRL.B.UDMODE = 1u;
	GTM4.GLS[4].ATOM.CH[4].CTRL.B.UDMODE = 0u;

	GTM4.GLS[4].ATOM.AGC.GLB_CTRL.R = 0x022a0000u;
	GTM4.GLS[4].ATOM.AGC.ENDIS_CTRL.R = 0x0000022au;
	GTM4.GLS[4].ATOM.AGC.OUTEN_CTRL.R =  0x0000022au;

	GTM4.GLS[5].ATOM.CH[0].CTRL_SR.B.SL_SR = 1u;
	GTM4.GLS[5].ATOM.CH[1].CTRL_SR.B.SL_SR = 1u;
	GTM4.GLS[5].ATOM.CH[2].CTRL_SR.B.SL_SR = 1u;
	GTM4.GLS[5].ATOM.CH[4].CTRL_SR.B.SL_SR = 1u;

	GTM4.GLS[5].ATOM.CH[0].CTRL.B.UDMODE = 1u;
	GTM4.GLS[5].ATOM.CH[1].CTRL.B.UDMODE = 1u;
	GTM4.GLS[5].ATOM.CH[2].CTRL.B.UDMODE = 1u;
	GTM4.GLS[5].ATOM.CH[4].CTRL.B.UDMODE = 0u;

	GTM4.GLS[5].ATOM.CH[0].CN0.R = freq/2;
	GTM4.GLS[5].ATOM.CH[1].CN0.R = freq/2;
	GTM4.GLS[5].ATOM.CH[2].CN0.R = freq/2;
	GTM4.GLS[5].ATOM.CH[4].CN0.R = freq/2;

	GTM4.GLS[5].ATOM.AGC.GLB_CTRL.R = 0x022a0000u;
	GTM4.GLS[5].ATOM.AGC.ENDIS_CTRL.R = 0x0000022au;
	GTM4.GLS[5].ATOM.AGC.OUTEN_CTRL.R =  0x0000022au;

	GTM4.GLS[4].ATOM.AGC.GLB_CTRL.B.HOST_TRIG = 1u;
	GTM4.GLS[5].ATOM.AGC.GLB_CTRL.B.HOST_TRIG = 1u;
}

#endif /* RESORUCE_SUPPORT_GTM410 */
