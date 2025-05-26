
#include "tester_sdadc.h"
#include "console.h"
#include "shell.h"
#include "common.h"
#include "SDAdc_Cfg.h"
#include "string.h"
#include "Det.h"
//#include "Pwm.h"
#include "Gpt.h"
#include "eDma.h"
#include "Gpt_Cfg.h"
#include "Pwm.h"

#ifdef RESOURCE_SUPPORT_SDADC_IP
EDMA_PB_CONFIG_DECLARATION

/*
 * SDADC_INSTANCE_0:
 * 		CH0:FALSE == diffEn: PB2
 *		    TRUE == diffEn: PB2 PB3
 *		CH1:FALSE == diffEn: PB3
 * SDADC_INSTANCE_1:
 *		CH0:FALSE == diffEn: PB0
 *			TRUE == diffEn: PB0 PB1
 *		CH1:FALSE == diffEn: PB1
 * SDADC_INSTANCE_2:
 *		CH0:FALSE == diffEn: PK0
 *			TRUE == diffEn: PK0 PK1
 *		CH1:FALSE == diffEn: PK1
 *			TRUE == diffEn: PK2 PK3
 *		CH2:FALSE == diffEn: PK2
 *		CH3:FALSE == diffEn: PK3
 * SDADC_INSTANCE_3:
 *		CH0:FALSE == diffEn: PB12
 *			TRUE == diffEn: PB12 PB13
 *		CH1:FALSE == diffEn: PB13
 *			TRUE == diffEn: PB14 PB15
 *		CH2:FALSE == diffEn: PB14
 *			TRUE == diffEn: PG4 PG3
 *		CH3:FALSE == diffEn: PB15
 *			TRUE == diffEn: PG2 PG1
 *		CH4:FALSE == diffEn: PG4
 *		CH5:FALSE == diffEn: PG3
 *		CH6:FALSE == diffEn: PG2
 *		CH7:FALSE == diffEn: PG1
 * SDADC_INSTANCE_4:
 *		CH0:FALSE == diffEn: PE3
 *			TRUE == diffEn: PE3 PD13
 *		CH1:FALSE == diffEn: PD13
 *			TRUE == diffEn: PC_0 PC1
 *		CH2:FALSE == diffEn: PC_0
 *		CH3:FALSE == diffEn: PC1
 * SDADC_INSTANCE_6:
 *		CH0:FALSE == diffEn: PR2
 *			TRUE == diffEn: PR2 PR3
 *		CH1:FALSE == diffEn: PR3
 *			TRUE == diffEn: PR4 PR5
 *		CH2:FALSE == diffEn: PR4
 *		CH3:FALSE == diffEn: PR5
 * SDADC_INSTANCE_7:
 *		CH0:FALSE == diffEn: PR8
 *			TRUE == diffEn: PR8 PR9
 *		CH1:FALSE == diffEn: PR9
 *			TRUE == diffEn: PY0 PY1
 *		CH2:FALSE == diffEn: PY0
 *		CH3:FALSE == diffEn: PY1
 * SDADC_INSTANCE_8:
 *		CH0:FALSE == diffEn: PR12
 *			TRUE == diffEn: PR12 PR13
 *		CH1:FALSE == diffEn: PR13
 *			TRUE == diffEn: PR14 PR15
 *		CH2:FALSE == diffEn: PR14
 *		CH3:FALSE == diffEn: PR15
 * */


#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
#endif
