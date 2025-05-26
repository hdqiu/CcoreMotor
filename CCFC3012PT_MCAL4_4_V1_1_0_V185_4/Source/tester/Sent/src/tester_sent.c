#include "Sent.h"
#include "Sent_LLDriver.h"
#include "derivative.h"
#include "intc_lld.h"
#include "Sent_Irq.h"
#include "tester_sent.h"
#include "shell.h"
#include "console.h"
#include "common.h"
#include <string.h>

#define SENT_PORT_TEST 0

#ifndef FEATURE_SRX_HAS_COMBINED_IRQ
#define FEATURE_SRX_IRQS {{{SENT0_CH0_FAST_IRQn, SENT0_CH0_SLOW_IRQn, SENT0_CH0_ERR_IRQn},   \
                           {SENT0_CH1_FAST_IRQn, SENT0_CH1_SLOW_IRQn, SENT0_CH1_ERR_IRQn},   \
						   {SENT0_CH2_FAST_IRQn, SENT0_CH2_SLOW_IRQn, SENT0_CH2_ERR_IRQn},   \
						   {SENT0_CH3_FAST_IRQn, SENT0_CH3_SLOW_IRQn, SENT0_CH3_ERR_IRQn},   \
						   {SENT0_CH4_FAST_IRQn, SENT0_CH4_SLOW_IRQn, SENT0_CH4_ERR_IRQn},   \
						   {SENT0_CH5_FAST_IRQn, SENT0_CH5_SLOW_IRQn, SENT0_CH5_ERR_IRQn},   \
						   {SENT0_CH6_FAST_IRQn, SENT0_CH6_SLOW_IRQn, SENT0_CH6_ERR_IRQn},   \
						   {SENT0_CH7_FAST_IRQn, SENT0_CH7_SLOW_IRQn, SENT0_CH7_ERR_IRQn},}, \
                          {{SENT1_CH0_FAST_IRQn, SENT1_CH0_SLOW_IRQn, SENT1_CH0_ERR_IRQn},   \
						   {SENT1_CH1_FAST_IRQn, SENT1_CH1_SLOW_IRQn, SENT1_CH1_ERR_IRQn},   \
						   {SENT1_CH2_FAST_IRQn, SENT1_CH2_SLOW_IRQn, SENT1_CH2_ERR_IRQn},   \
						   {SENT1_CH3_FAST_IRQn, SENT1_CH3_SLOW_IRQn, SENT1_CH3_ERR_IRQn},   \
						   {SENT1_CH4_FAST_IRQn, SENT1_CH4_SLOW_IRQn, SENT1_CH4_ERR_IRQn},   \
						   {SENT1_CH5_FAST_IRQn, SENT1_CH5_SLOW_IRQn, SENT1_CH5_ERR_IRQn},   \
						   {SENT1_CH6_FAST_IRQn, SENT1_CH6_SLOW_IRQn, SENT1_CH6_ERR_IRQn},   \
                           {NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn}}}
/**
 * Array containing interrupt mappings.
 */
static const IntrId s_srxInterruptMappings[SRX_INSTANCE_COUNT][8U][3U] = FEATURE_SRX_IRQS;
#else
#define FEATURE_SRX_COMBINED_IRQS  {{SENT0_COMBINED_FAST_IRQn,SENT0_COMBINED_SLOW_IRQn,SENT0_COMBINED_ERR_IRQn},\
                                    {SENT1_COMBINED_FAST_IRQn,SENT1_COMBINED_SLOW_IRQn,SENT1_COMBINED_ERR_IRQn}}

/**
 * Array containing interrupt mappings.
 */
static const IntrId s_srxInterruptMappings[SRX_INSTANCE_COUNT][3U] = FEATURE_SRX_COMBINED_IRQS;
#endif

LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_IRQ_EnableIRQ(CONST(uint32, AUTOMATIC) instance, CONST(uint32, AUTOMATIC) channel, CONST(srx_interrupt_id_t, AUTOMATIC) id);
void Sensor_srxNotification(uint8_t channel, srx_callback_type_t type);
int sent_func(int argc, char *agrv[]);

#define SENT_TEST_CASE_MAX 2
static SentfuncMachine sent_funcs[] = {
    {"Sent_001", sent_test001}
};

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_IRQ_EnableIRQ
 * Description   : Enabler for SRX_LLD_IRQ_EnableIRQ interrupt
 *
 *END**************************************************************************/
#ifndef FEATURE_SRX_HAS_COMBINED_IRQ
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_IRQ_EnableIRQ(CONST(uint32, AUTOMATIC) instance, CONST(uint32, AUTOMATIC) channel, CONST(srx_interrupt_id_t, AUTOMATIC) id)
{
    (void)id; /* Shared */

    (void)INTC_LLD_Set_IRQ_Enable(s_srxInterruptMappings[instance][channel][id]);
    (void)INTC_LLD_Set_IRQ_Priority(s_srxInterruptMappings[instance][channel][id], INTR_PRI_15);
    if(instance == 0U)
    {
        switch (channel)
        {
        case 0U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX0_CH0_IRQHandler);//install IRQ handler
            break;
        case 1U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX0_CH1_IRQHandler);//install IRQ handler
            break;
        case 2U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX0_CH2_IRQHandler);//install IRQ handler
            break;
        case 3U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX0_CH3_IRQHandler);//install IRQ handler
            break;
        case 4U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX0_CH4_IRQHandler);//install IRQ handler
            break;
        case 5U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX0_CH5_IRQHandler);//install IRQ handler
            break;
        case 6U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX0_CH6_IRQHandler);//install IRQ handler
            break;				
		default:
			(void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX0_CH7_IRQHandler);//install IRQ handler
            break;
        }
    }
    else
    {
        switch (channel)
        {
        case 0U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX1_CH0_IRQHandler);//install IRQ handler
            break;
        case 1U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX1_CH1_IRQHandler);//install IRQ handler
            break;
        case 2U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX1_CH2_IRQHandler);//install IRQ handler
            break;
        case 3U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX1_CH3_IRQHandler);//install IRQ handler
            break;
        case 4U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX1_CH4_IRQHandler);//install IRQ handler
            break;
        case 5U:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX1_CH5_IRQHandler);//install IRQ handler
            break;
        default:
            (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][channel][id], &SRX1_CH6_IRQHandler);//install IRQ handler
            break;
        }
    }
}
#else
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_IRQ_EnableIRQ(const uint32 instance, const uint32 channel, const srx_interrupt_id_t id)
{
    (void)id; /* Shared */
    (void)channel;
    (void)INTC_LLD_Set_IRQ_Enable(s_srxInterruptMappings[instance][id]);
    (void)INTC_LLD_Set_IRQ_Priority(s_srxInterruptMappings[instance][id], INTR_PRI_15);
    if(instance == 0U)
    {
        (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][id], &SRX0_COMBINED_IRQHandler);//SENT1_COMBINED_ERR_IRQn or SENT1_COMBINED_SLOW_IRQn or SENT1_COMBINED_FAST_IRQn
    }
    else{
        (void)INTC_LLD_Set_IRQ_Handle(s_srxInterruptMappings[instance][id], &SRX1_COMBINED_IRQHandler);//SENT1_COMBINED_ERR_IRQn or SENT1_COMBINED_SLOW_IRQn or SENT1_COMBINED_FAST_IRQn
    }
}
#endif


typedef struct {
    float pressure;
    float temperature;
} tem00441_t;

typedef struct {
    float pressure;
    float temperature;
    float humidity;
    uint32 mass;
} sensor0280B_t;

typedef struct {
	uint32 fast_convert_state[15];
	uint32 slow_convert_state[15];
} convert_status;

tem00441_t result;
sensor0280B_t sensor_result;

static convert_status convert_sta;

static Sent_RxSerialDataType sentSlowSerialDataBuffer[1];
static Sent_RxSerialDataType sentMultiSlowSerialDataBuffer[2];

uint8 MultiChannelFlag = 0;

/* Active event flags */
//static uint32 srxActiveEvents;

uint32 SensorData = 0;
uint32 MultiSensorData[4] = {0};

void Sensor_srxNotification(uint8 channel, srx_callback_type_t type)
 {
//	uint8 u8SentModule = (uint8)(((channel) >> (uint8)5) & (uint8)0x7);
//	uint8 u8SentChannel = (uint8)((channel) & (uint8)0x1F);
     switch(type)
     {
     case SRX_CALLBACK_SLOW_DMA_RX_COMPLETE:
         /* Convert buffer to fast messages */
         //SRX_LLD_GetSlowMsgFromRaw(&srxSlowMessageBuffer[0], &srxRawMessageBuffer_slow[0]);
         convert_sta.slow_convert_state[channel] = STATUS_SUCCESS;
         break;

     case SRX_CALLBACK_FAST_DMA_RX_COMPLETE:
         /* Convert buffer to fast messages */
        //SRX_LLD_GetFastMsgFromRaw(&srxFastMessageBuffer, &srxRawMessageBuffer_fast[0]);
        convert_sta.fast_convert_state[channel] = STATUS_SUCCESS;
         break;

     case SRX_CALLBACK_SLOW_RX_COMPLETE:

    	 if(MultiChannelFlag == 1)
    	 {
        	 Sent_ReadSerialData(channel, &sentMultiSlowSerialDataBuffer[channel]);
    	 }
    	 else
    	 {
        	 Sent_ReadSerialData(channel, sentSlowSerialDataBuffer);
    	 }
         convert_sta.slow_convert_state[channel] = STATUS_SUCCESS;
         break;

     case SRX_CALLBACK_FAST_RX_COMPLETE:
     {
    	 if(MultiChannelFlag == 1)
    	 {
    		 MultiSensorData[channel] = Sent_ReadData(channel);
    	 }
    	 SensorData = Sent_ReadData(channel);
         convert_sta.fast_convert_state[channel] = STATUS_SUCCESS;
         break;
     }
     case SRX_CALLBACK_RX_ERROR:
         //(void)SRX_LLD_GetEvents(u8SentModule, u8SentChannel, &srxActiveEvents);
         break;

     default:
         //*(uint32*) param = (uint8)STATUS_ERROR;
         break;
     }
 }


static void Sersor0280B_FastConvert(sensor0280B_t * sensor, uint32 data)
{
    /* Get status field */
//	tem->status = msg->statusField;

	data = data & (SRX_FMSG_DATA_DNIB1_MASK
				| SRX_FMSG_DATA_DNIB2_MASK
				| SRX_FMSG_DATA_DNIB3_MASK
				| SRX_FMSG_DATA_DNIB4_MASK
				| SRX_FMSG_DATA_DNIB5_MASK
				| SRX_FMSG_DATA_DNIB6_MASK);

	float pre = (float)((data) & 0x3FF);
	uint32 mass = ((data >> 10) & 0x3FFFU);

	sensor->pressure = (float)(((pre - 47) / 9.23f) + 15); /* Scale based on value */
	sensor->mass = mass;
}


extern CONST(Sent_ConfigType, SENT_CONST)SentChannelConfigSet;


void sent_test001(void)
{

	SRX_LLD_IRQ_EnableIRQ(0,3,(srx_interrupt_id_t)0);
	SRX_LLD_IRQ_EnableIRQ(0,3,(srx_interrupt_id_t)1);
	SRX_LLD_IRQ_EnableIRQ(0,3,(srx_interrupt_id_t)2);

	Sent_Init(&SentChannelConfigSet);
	Sent_SetChannel((Sent_ChannelType)3, SENT_ENABLE);

	while(1)
	{

		delay_ms(1000);
		while(convert_sta.fast_convert_state[3] == (uint8)STATUS_ERROR)/*PRQA S 2872*/
        {};

		/* In DMA mode a notification will be received on each successful transfer.
		 * Please see srxNotification function for more details. */
		/* Convert values */
		Sersor0280B_FastConvert(&sensor_result, SensorData);
		convert_sta.fast_convert_state[3] = (uint8)STATUS_ERROR;

		/* print out */
		PSPRINTF("Pressure: %3.3f Kpa uT\n mass: %d\n\n",
				(double)sensor_result.pressure,
				sensor_result.mass);
	}
	
}


int sent_func(int argc, char *agrv[])
{

	static uint8 setIrqFlag[3] = {0};

	uint8 temp =(uint8)(GetCoreID());
	if(setIrqFlag[temp] == 0)
	{
		for(uint8 i = 0; i < 15; i++)
		{
			convert_sta.slow_convert_state[i] = (uint8)STATUS_ERROR;
			convert_sta.fast_convert_state[i] = (uint8)STATUS_ERROR;
		}
		setIrqFlag[temp] = 1;
	}

    if ((argc > 3) || (argc < 2)) {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\n");
    }
    else
    {
        if (argc == 2)
        {
            if (!strcmp(agrv[1], "help"))
            {
            	PSPRINTF("CCFC3008\n");
                PSPRINTF("[1 - %d] ----- CMD ------- ID of the test case\n", SENT_TEST_CASE_MAX);
            }
            else
            {
                uint32 id = (uint32)atoi(agrv[1]);
                PSPRINTF("%d\r\n", id);
                if ((id >= 1) && (id < SENT_TEST_CASE_MAX))
                {
                    if (sent_funcs[id - 1].sentfunc != NULL_PTR)
                    {
                    	sent_funcs[id - 1].sentfunc();
                    }
                    else
                    {
                        PSPRINTF("error: The ID entered does not correspond to the test code\n");
                    }
                }
                else
                {
                    PSPRINTF("error: Input invalid parameters[%d], please output [1 - %d] range parameters\n", id, SENT_TEST_CASE_MAX);
                }
            }
        }
    }
	return 0;
}


#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), sent_test, sent_func, number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
