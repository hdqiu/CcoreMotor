#ifndef GTM4_TO_EQADC_INLINE_H_
#define GTM4_TO_EQADC_INLINE_H_
#include "derivative.h"
#ifdef RESORUCE_SUPPORT_GTM_TO_EQADC

/* Trigger register index(0 ~ 4) */
#define GTM_ADC_TRIG0                   (0U)
#define GTM_ADC_TRIG1                   (1U)
#define GTM_ADC_TRIG2                   (2U)
#define GTM_ADC_TRIG3                   (3U)
#define GTM_ADC_TRIG4                   (4U)

/* Trigger register member index(0 ~ 11) */
#define GTM_ADC_TRIG_MEMBER0            (0U)
#define GTM_ADC_TRIG_MEMBER1            (1U)
#define GTM_ADC_TRIG_MEMBER2            (2U)
#define GTM_ADC_TRIG_MEMBER3            (3U)
#define GTM_ADC_TRIG_MEMBER4            (4U)
#define GTM_ADC_TRIG_MEMBER5            (5U)
#define GTM_ADC_TRIG_MEMBER6            (6U)
#define GTM_ADC_TRIG_MEMBER7            (7U)
#define GTM_ADC_TRIG_MEMBER8            (8U)
#define GTM_ADC_TRIG_MEMBER9            (9U)
#define GTM_ADC_TRIG_MEMBER10           (10U)
#define GTM_ADC_TRIG_MEMBER11           (11U)

/* Trigger selection(0 ~ 15) */
#define GTM_ADC_TRIG_OUTSEL_NO_TRIG     (0x0U)
#define GTM_ADC_TRIG_OUTSEL_1           (0x1U)
#define GTM_ADC_TRIG_OUTSEL_2           (0x2U)
#define GTM_ADC_TRIG_OUTSEL_3           (0x3U)
#define GTM_ADC_TRIG_OUTSEL_4           (0x4U)
#define GTM_ADC_TRIG_OUTSEL_5           (0x5U)
#define GTM_ADC_TRIG_OUTSEL_6           (0x6U)
#define GTM_ADC_TRIG_OUTSEL_7           (0x7U)
#define GTM_ADC_TRIG_OUTSEL_8           (0x8U)
#define GTM_ADC_TRIG_OUTSEL_9           (0x9U)
#define GTM_ADC_TRIG_OUTSEL_10          (0xAU)
#define GTM_ADC_TRIG_OUTSEL_11          (0xBU)
#define GTM_ADC_TRIG_OUTSEL_12          (0xCU)
#define GTM_ADC_TRIG_OUTSEL_13          (0xDU)
#define GTM_ADC_TRIG_OUTSEL_14          (0xEU)
#define GTM_ADC_TRIG_OUTSEL_15          (0xFU)
#define GTM_ADC_TRIG_OUTSEL_MASK        (0xFU)


/*******************************************************************************
 * @brief GTM to EQADC Connections
 *
 * @param GtmInstance: GTM instance
 *        TrigRegIdx: Trigger register index(0 ~ 4)
 *        TrigRegMemberIdx: Trigger register member index(0 ~ 11)
 *        TrigSel: Trigger selection(0 ~ 15)
 *
 * @note  GTMi, i = instance;
 *          TRIGx[y], x = TrigRegIdx, y = TrigRegMemberIdx.
 *******************************************************************************/
static inline void GTM_to_EQADC_Connections(const uint8_t GtmInstance, uint8_t TrigRegIdx, uint8_t TrigRegMemberIdx, uint8_t TrigSel)
{
//    GTM4.GLS[GtmInstance].GTMINT.GTMMCR.R &= ~0x40000000UL; /* GTM Module Enable */

    if (TrigRegMemberIdx < 8u)  /* TrigRegMemberIdx: 0 ~ 7 */
    {
        GTM4.GLS[GtmInstance].ADCTRIG[TrigRegIdx].OUT0.R &= ~(uint32_t)(GTM_ADC_TRIG_OUTSEL_MASK << (TrigRegMemberIdx * 4u));
        GTM4.GLS[GtmInstance].ADCTRIG[TrigRegIdx].OUT0.R |= (uint32_t)((TrigSel & GTM_ADC_TRIG_OUTSEL_MASK) << (TrigRegMemberIdx * 4u));
    }
    else    /* TrigRegMemberIdx: 8 ~ 11 */
    {
        GTM4.GLS[GtmInstance].ADCTRIG[TrigRegIdx].OUT1.R &= ~(uint32_t)(GTM_ADC_TRIG_OUTSEL_MASK << ((TrigRegMemberIdx - 8u) * 4u));
        GTM4.GLS[GtmInstance].ADCTRIG[TrigRegIdx].OUT1.R |= (uint32_t)((TrigSel & GTM_ADC_TRIG_OUTSEL_MASK) << ((TrigRegMemberIdx - 8u) * 4u));
    }
}

#endif  /* RESORUCE_SUPPORT_GTM_TO_EQADC */
#endif /* GTM4_TO_EQADC_INLINE_H_ */
