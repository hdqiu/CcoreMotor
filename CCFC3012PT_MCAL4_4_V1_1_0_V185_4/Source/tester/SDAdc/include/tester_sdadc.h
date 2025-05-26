#include "SDAdc.h"
#include "SDAdc_Irq.h"
#include "CCFC3012PT.h"
typedef volatile struct GTM_TOM_tag GTM_TOM_TagType;
typedef volatile struct GTM_ATOM_tag GTM_ATOM_TagType;

typedef void (*SDAdcfunc)(void);
typedef struct SDAdcfuncMachine
{
    char *name;
    SDAdcfunc sdadcfunc;
} SDAdcfuncMachine;

/* Trigger register index(0 ~ 4) */
#define GTM_SDADC_TRIG0                   (0U)
#define GTM_SDADC_TRIG1                   (1U)
#define GTM_SDADC_TRIG2                   (2U)
#define GTM_SDADC_TRIG3                   (3U)

/* Trigger register member index(0 ~ 11) */
#define GTM_SDADC_TRIG_MEMBER0            (0U)
#define GTM_SDADC_TRIG_MEMBER1            (1U)
#define GTM_SDADC_TRIG_MEMBER2            (2U)
#define GTM_SDADC_TRIG_MEMBER3            (3U)
#define GTM_SDADC_TRIG_MEMBER4            (4U)
#define GTM_SDADC_TRIG_MEMBER5            (5U)
#define GTM_SDADC_TRIG_MEMBER6            (6U)
#define GTM_SDADC_TRIG_MEMBER7            (7U)
#define GTM_SDADC_TRIG_MEMBER8            (8U)
#define GTM_SDADC_TRIG_MEMBER9            (9U)
#define GTM_SDADC_TRIG_MEMBER10            (10U)
#define GTM_SDADC_TRIG_MEMBER11            (11U)
#define GTM_SDADC_TRIG_MEMBER12            (12U)
#define GTM_SDADC_TRIG_MEMBER13            (13U)

/* Trigger selection(0 ~ 15) */
#define GTM_SDADC_TRIG_OUTSEL_0           (0x0U)
#define GTM_SDADC_TRIG_OUTSEL_1           (0x1U)
#define GTM_SDADC_TRIG_OUTSEL_2           (0x2U)
#define GTM_SDADC_TRIG_OUTSEL_3           (0x3U)
#define GTM_SDADC_TRIG_OUTSEL_4           (0x4U)
#define GTM_SDADC_TRIG_OUTSEL_5           (0x5U)
#define GTM_SDADC_TRIG_OUTSEL_6           (0x6U)
#define GTM_SDADC_TRIG_OUTSEL_7           (0x7U)
#define GTM_SDADC_TRIG_OUTSEL_8           (0x8U)
#define GTM_SDADC_TRIG_OUTSEL_9           (0x9U)
#define GTM_SDADC_TRIG_OUTSEL_10          (0xAU)
#define GTM_SDADC_TRIG_OUTSEL_11          (0xBU)
#define GTM_SDADC_TRIG_OUTSEL_12          (0xCU)
#define GTM_SDADC_TRIG_OUTSEL_13          (0xDU)
#define GTM_SDADC_TRIG_OUTSEL_14          (0xEU)
#define GTM_SDADC_TRIG_OUTSEL_15          (0xFU)
#define GTM_SDADC_TRIG_OUTSEL_MASK        (0xFU)

static inline void GTM_TrigSDADC(const uint8_t GtmInstance, uint8_t TrigRegIdx, uint8_t TrigRegMemberIdx, uint8_t TrigSel)
{
    if (TrigRegMemberIdx < 8u)  /* TrigRegMemberIdx: 0 ~ 7 */
    {
        GTM4.GLS[GtmInstance].DSADC[TrigRegIdx].OUTSEL0.R &= ~(uint32_t)(GTM_SDADC_TRIG_OUTSEL_MASK << (TrigRegMemberIdx * 4u));
        GTM4.GLS[GtmInstance].DSADC[TrigRegIdx].OUTSEL0.R |= (uint32_t)((TrigSel & GTM_SDADC_TRIG_OUTSEL_MASK) << (TrigRegMemberIdx * 4u));
    }
    else    /* TrigRegMemberIdx: 8 ~ 11 */
    {
        GTM4.GLS[GtmInstance].DSADC[TrigRegIdx].OUTSEL1.R &= ~(uint32_t)(GTM_SDADC_TRIG_OUTSEL_MASK << ((TrigRegMemberIdx - 8u) * 4u));
        GTM4.GLS[GtmInstance].DSADC[TrigRegIdx].OUTSEL1.R |= (uint32_t)((TrigSel & GTM_SDADC_TRIG_OUTSEL_MASK) << ((TrigRegMemberIdx - 8u) * 4u));
    }
}


