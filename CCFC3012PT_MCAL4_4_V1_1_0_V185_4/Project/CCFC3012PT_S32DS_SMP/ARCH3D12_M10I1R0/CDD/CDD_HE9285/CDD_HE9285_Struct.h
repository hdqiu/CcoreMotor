/*
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, GELU Tech, 2024. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 ************************************************************************************************
 * Component : CDD_HE9285_Struct.h
 * Date      : Oct 16 2024
 * Author	 : David
 * Version   : 0.5
 * Description  : 	This module interfaces HE9285 function and diagnostic
 * 					HE9285 -->KKChips-->Functional safety PMIC
 ***********************************************************************************************
*/

#ifndef CDD_HE9285_STRUCT_H
#define CDD_HE9285_STRUCT_H

/****************************************************************************\
* Addresses of the L9908 registers
\****************************************************************************/
typedef enum
{
	HE9285_REG_DEVCFG0  = 0x00u, /* Device configuration 0 *R2) , Reset 08H */
	HE9285_REG_DEVCFG1  = 0x01u, /* Device configuration 1 *R0) , Reset 06H */
	HE9285_REG_DEVCFG2  = 0x02u, /* Device configuration 2 *R2) , Reset 00H */
	HE9285_REG_PROTCFG  = 0x03u, /* Protection register *R2) , Reset 00H */
	HE9285_REG_SYSPCFG0  = 0x04u, /* Protected System configuration request 0 *R1) , Reset 01H */
	HE9285_REG_SYSPCFG1  = 0x05u, /* Protected System configuration request 1 *R2) , Reset 00H */
	HE9285_REG_WDCFG0  = 0x06u, /* Protected Watchdog configuration request 0 *R2) , Reset 9BH */
	HE9285_REG_WDCFG1  = 0x07u, /* Protected Watchdog configuration request 1 *R2) , Reset 09H */
	HE9285_REG_FWDCFG  = 0x08u, /* Protected Functional watchdog configuration request *R2), Reset 0BH */
	HE9285_REG_WWDCFG0  = 0x09u, /* Protected Window watchdog configuration request 0 *R2), Reset 06H */
	HE9285_REG_WWDCFG1  = 0x0Au, /* Protected Window watchdog configuration request 1 *R2), Reset 0BH */
	HE9285_REG_RSYSPCFG0  = 0x0Bu, /* System configuration 0 status *R0) , Reset 01H */
	HE9285_REG_RSYSPCFG1  = 0x0Cu, /* System configuration 1 status *R3) 1) , Reset 00H */
	HE9285_REG_RWDCFG0  = 0x0Du, /* Watchdog configuration 0 status *R3) , Reset 9BH */
	HE9285_REG_RWDCFG1  = 0x0Eu, /* Watchdog configuration 1 status *R3) , Reset 09H */
	HE9285_REG_RFWDCFG  = 0x0Fu, /* Functional watchdog configuration status *R3) , Reset 0BH */
	HE9285_REG_RWWDCFG0  = 0x10u, /* Window watchdog configuration 0 status *R3) , Reset 06H */
	HE9285_REG_RWWDCFG1  = 0x11u, /* Window watchdog configuration 1 status *R3) , Reset 09H */
	HE9285_REG_WKTIMCFG0  = 0x12u, /* Wake timer configuration 0 *R2) , Reset 00H */
	HE9285_REG_WKTIMCFG1  = 0x13u, /* Wake timer configuration 1 *R2) , Reset 00H */
	HE9285_REG_WKTIMCFG2  = 0x14u, /* Wake timer configuration 2 *R2) , Reset 00H */
	HE9285_REG_DEVCTRL  = 0x15u, /* Device control request *R2) , Reset 00H */
	HE9285_REG_DEVCTRLN  = 0x16u, /* Device control inverted request *R2) , Reset 00H */
	HE9285_REG_WWDSCMD  = 0x17u, /* Window watchdog service command *R2) , Reset 00H */
	HE9285_REG_FWDRSP  = 0x18u, /* Functional watchdog response command *R2) , Reset 00H */
	HE9285_REG_FWDRSPSYNC  = 0x19u, /* Functional watchdog response command with synchronization *R2), Reset 00H */
	HE9285_REG_SYSFAIL  = 0x1Au, /* Failure status flags *R1) , Reset 00H */
	HE9285_REG_INITERR  = 0x1Bu, /* Init error status flags *R2) , Reset 00H */
	HE9285_REG_IF  = 0x1Cu, /* Interrupt flags *R2) , Reset 00H */
	HE9285_REG_SYSSF  = 0x1Du, /* System status flags *R2) , Reset 00H */
	HE9285_REG_WKSF  = 0x1Eu, /* Wakeup status flags *R2) , Reset 00H */
	HE9285_REG_SPISF  = 0x1Fu, /* SPI status flags *R2) , Reset 00H */
	HE9285_REG_MONSF0  = 0x20u, /* Monitor status flags 0 *R1) , Reset 00H */
	HE9285_REG_MONSF1  = 0x21u, /* Monitor status flags 1 *R1) , Reset 00H */
	HE9285_REG_MONSF2  = 0x22u, /* Monitor status flags 2 *R2) , Reset 00H */
	HE9285_REG_MONSF3  = 0x23u, /* Monitor status flags 3 *R1) , Reset 00H */
	HE9285_REG_OTFAIL  = 0x24u, /* Over temperature failure status flags *R1) , Reset 00H */
	HE9285_REG_OTWRNSF  = 0x25u, /* Over temperature warning status flags *R2) , Reset 00H */
	HE9285_REG_VMONSTAT  = 0x26u, /* Voltage monitor status *R2) , Reset 00H */
	HE9285_REG_DEVSTAT  = 0x27u, /* Device status *R2) , Reset 00H */
	HE9285_REG_PROTSTAT  = 0x28u, /* Protection status *R1) , Reset 01H */
	HE9285_REG_WWDSTAT  = 0x29u, /* Window watchdog status *R3) , Reset 00H */
	HE9285_REG_FWDSTAT0  = 0x2Au, /* Functional watchdog status 0 *R3) , Reset 30H */
	HE9285_REG_FWDSTAT1  = 0x2Bu, /* Functional watchdog status 1 *R3) , Reset 00H */
	HE9285_REG_ABIST_CTRL0  = 0x2Cu, /* ABIST control0 *R2) 1) , Reset 00H */
	HE9285_REG_ABIST_CTRL1  = 0x2Du, /* ABIST control1 *R2) , Reset 00H */
	HE9285_REG_ABIST_SELECT0  = 0x2Eu, /* ABIST select 0 *R2) , Reset 00H */
	HE9285_REG_ABIST_SELECT1  = 0x2Fu, /* ABIST select 1 *R2) , Reset 00H */
	HE9285_REG_ABIST_SELECT2  = 0x30u, /* ABIST select 2 *R2) , Reset 00H */
	HE9285_REG_GTM  = 0x3Fu, /* Global testmode *R2) , Reset 02H */
	HE9285_REG_BCK_FREQ_CHANGE  = 0x31u, /* Buck switching frequency change *R2) , Reset 00H */
	HE9285_REG_BCK_FRE_SPREAD  = 0x32u, /* Buck Frequency spread *R2) , Reset 00H */
	HE9285_REG_BCK_MAIN_CTRL  = 0x33u, /* Buck main control *R2) , Reset 00H */

	HE9285_REG_NUM = 0x40
} HE9285_Reg_t;


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define HE9285_RESPONSE_TABLE_SIZE             (16u) /*!< Size of Functional watchdog response table. */
#define HE9285_SHIFT_WWD_STAT_TO_CMD            (7u) /*!< Operand for shifting the WWD status bit to cmd bit. */
#define HE9285_NUMBER_OF_PROTECTED_REGISTERS    (7u) /*!< Defines the number of protected registers. */


/**********************************************************************************************************************
 *  HARDWARE SOFTWARE INTERFACE
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */



/*! Read / Write masks */
#define HE9285_MASK_SPIADDR                    (0x3Fu)     /*!< Masks address from address byte (1 Byte) */
#define HE9285_MASK_SPIADDR_RAW                (0x7E00u)   /*!< Masks address from complete SPI sequence (2 Bytes) */
#define HE9285_MASK_SPIDATA_RAW                (0x01FEu)   /*!< Masks data from complete SPI sequence (2 Bytes) */
#define HE9285_MASK_CMD_WRITE_RAW              (0x8000u)   /*!< Masks CMD bit from complete SPI sequence (2 Bytes) */
#define HE9285_MASK_ALL_FLAGS                  (0xFFu)     /*!< Mask that selects all flags (i.e. to clear all pending event flags) */
#define HE9285_OFFSET_SPIADDR                  (9u)        /*!< Offset of address bits in SPI command */
#define HE9285_OFFSET_SPIDATA                  (1u)        /*!< Offset of data bits in SPI command */

/*! Protected registers addresses */
#define HE9285_REG_ADDR_SYSPCFG0               (0x04u)     /*!< Protected System configuration request 0 */
#define HE9285_REG_ADDR_SYSPCFG1               (0x05u)     /*!< Protected System configuration request 1 */
#define HE9285_REG_ADDR_WDCFG0                 (0x06u)     /*!< Protected Watchdog configuration request 0 */
#define HE9285_REG_ADDR_WDCFG1                 (0x07u)     /*!< Protected Watchdog configuration request 1 */
#define HE9285_REG_ADDR_FWDCFG                 (0x08u)     /*!< Protected Functional watchdog configuration request */
#define HE9285_REG_ADDR_WWDCFG0                (0x09u)     /*!< Protected Window watchdog configuration request 0 */
#define HE9285_REG_ADDR_WWDCFG1                (0x0Au)     /*!< Protected Window watchdog configuration request 1 */

/*! Main registers addresses */
#define HE9285_REG_ADDR_PROTCFG                (0x03u)     /*!< Protected register */
#define HE9285_REG_ADDR_RSYSPCFG0              (0x0Bu)     /*!< System configuration 0 status */
#define HE9285_REG_ADDR_RSYSPCFG1              (0x0Cu)     /*!< System configuration 1 status */
#define HE9285_REG_ADDR_RWDCFG0                (0x0Du)     /*!< Watchdog configuration 0 status */
#define HE9285_REG_ADDR_RWDCFG1                (0x0Eu)     /*!< Watchdog configuration 1 status */
#define HE9285_REG_ADDR_RFWDCFG                (0x0Fu)     /*!< Functional watchdog configuration status */
#define HE9285_REG_ADDR_RWWDCFG0               (0x10u)     /*!< Window watchdog configuration status 0 */
#define HE9285_REG_ADDR_RWWDCFG1               (0x11u)     /*!< Window watchdog configuration status 1 */

/*! Device control register addresses */
#define HE9285_REG_ADDR_DEVCTRL                (0x15u)     /*!< Device control request */
#define HE9285_REG_ADDR_DEVCTRLN               (0x16u)     /*!< Device control inverted request */
#define HE9285_REG_ADDR_DEVSTAT                (0x27u)     /*!< Device status register */

/*! Device control register bitmasks */
#define HE9285_DEVCTRL_NORMAL                  (0x02u)     /*!< Go to device state NORMAL */
#define HE9285_DEVCTRL_STANDBY                 (0x04u)     /*!< Go to device state STANDBY */

#define HE9285_REG_ADDR_WWDSCMD                (0x17u)     /*!< Window watchdog service command */
#define HE9285_REG_ADDR_WWDSTAT                (0x29u)     /*!< Window watchdog status */

/*! Status flag registers */
#define HE9285_REG_ADDR_SYSFAIL                (0x1Au)     /*!< Failure status flags */
#define HE9285_REG_ADDR_IF                     (0x1Cu)     /*!< Interrupt flags */
#define HE9285_REG_ADDR_MONSF1                 (0x21u)     /*!< Monitor status flags 1 */
#define HE9285_REG_ADDR_MONSF2                 (0x22u)     /*!< Monitor status flags 2 */
#define HE9285_REG_ADDR_MONSF3                 (0x23u)     /*!< Monitor status flags 3 */
#define HE9285_REG_ADDR_OTFAIL                 (0x24u)     /*!< Over temperature failure status flags */

#define HE9285_REG_ADDR_INITERR                (0x1Bu)     /*!< Init error status flags */
#define HE9285_REG_ADDR_SYSSF                  (0x1Du)     /*!< System status flags */
#define HE9285_REG_ADDR_SPISF                  (0x1Fu)     /*!< SPI status flags */
#define HE9285_REG_ADDR_PROTSTAT               (0x28u)     /*!< Protection status */

/*! Status flag register bit masks */
#define HE9285_REG_MASK_SYSFAIL_VMONF          (0x04u)      /*!< SYSFAIL:2:2 Voltage monitor failure flag */
#define HE9285_REG_MASK_SYSFAIL_OTF            (0x02u)      /*!< SYSFAIL:1:1 Over temperature failure flag */

#define HE9285_REG_MASK_IF_OTF                 (0x20u)      /*!< IF:5:5 Over temperature failure interrupt flag */
#define HE9285_REG_MASK_IF_SPI                 (0x04u)      /*!< IF:2:2 SPI interrupt flag */
#define HE9285_REG_MASK_IF_SYSSF               (0x01u)      /*!< IF:0:0 System interrupt flag */

#define HE9285_REG_MASK_MONSF1_ALL             (0xFFu)      /*!< MONSF1:0:7 Selects all flags of MONSF1 */

#define HE9285_REG_MASK_MONSF2_ALL             (0xFFu)      /*!< MONSF2:0:7 Selects all flags of MONSF2 */

#define HE9285_REG_MASK_MONSF3_BG12OV          (0x20u)      /*!< IF:5:5 Bandgap comparator over voltage condition flag */
#define HE9285_REG_MASK_MONSF3_BG12UV          (0x10u)      /*!< IF:5:5 Bandgap comparator under voltage condition flag */
#define HE9285_REG_MASK_MONSF3_VBATOV          (0x01u)      /*!< IF:5:5 Supply voltage VSx over voltage flag */
#define HE9285_REG_MASK_MONSF3_OVFLAGS         (HE9285_REG_MASK_MONSF3_BG12OV \
                                                          | HE9285_REG_MASK_MONSF3_VBATOV)

#define HE9285_REG_MASK_OTFAIL_MON             (0x80u)      /*! OTFAIL:7:7 Monitoring over temperature flag */
#define HE9285_REG_MASK_OTFAIL_COM             (0x10u)      /*! OTFAIL:4:4 Communication LDO over temperature flag */
#define HE9285_REG_MASK_OTFAIL_UC              (0x02u)      /*! OTFAIL:1:1 uC LDO over temperature flag */
#define HE9285_REG_MASK_OTFAIL_PREG            (0x01u)      /*! OTFAIL:0:0 Pre-regulator over temperature flag */
#define HE9285_REG_MASK_OTFAIL_ALL             (HE9285_REG_MASK_OTFAIL_MON \
                                                          | HE9285_REG_MASK_OTFAIL_COM \
                                                          | HE9285_REG_MASK_OTFAIL_UC \
                                                          | HE9285_REG_MASK_OTFAIL_PREG)

#define HE9285_REG_MASK_INITERR_FWDF           (0x10u)      /*!< INITERR:4:4 FWD error counter overflow flag */
#define HE9285_REG_MASK_INITERR_WWDF           (0x08u)      /*!< INITERR:3:3 WWD error counter overflow flag */
#define HE9285_REG_MASK_INITERR_VMONF          (0x04u)      /*!< INITERR:2:2 Voltage monitor failure flag */
#define HE9285_REG_MASK_INITERR_WDFLAGS        (HE9285_REG_MASK_INITERR_FWDF \
                                                          | HE9285_REG_MASK_INITERR_WWDF)

#define HE9285_REG_MASK_SPISF_LOCK             (0x10u)      /*!< SPISF:4:4 LOCK or UNLOCK procedure error flag */
#define HE9285_REG_MASK_SPISF_DURE             (0x08u)      /*!< SPISF:3:3 SPI frame duration error flag */
#define HE9285_REG_MASK_SPISF_ADDRE            (0x04u)      /*!< SPISF:2:2 SPI address invalid flag */
#define HE9285_REG_MASK_SPISF_LENE             (0x02u)      /*!< SPISF:1:1 SPI frame length invalid flag */
#define HE9285_REG_MASK_SPISF_PARE             (0x01u)      /*!< SPISF:0:0 SPI frame length invalid flag */
#define HE9285_REG_MASK_SPISF_ALL              (HE9285_REG_MASK_SPISF_LOCK \
                                                          | HE9285_REG_MASK_SPISF_DURE \
                                                          | HE9285_REG_MASK_SPISF_ADDRE \
                                                          | HE9285_REG_MASK_SPISF_LENE \
                                                          | HE9285_REG_MASK_SPISF_PARE)

#define HE9285_REG_MASK_PROTSTAT_LOCK          (0x01u)      /*!< PROTSTAT:1:1 Protected register lock status */

/*! FWD registers */
#define HE9285_REG_ADDR_FWDRSP                 (0x18u)      /*!< Functional watchdog response command */
#define HE9285_REG_ADDR_FWDRSPSYNC             (0x19u)      /*!< Functional watchdog response command with synchronization */
#define HE9285_REG_ADDR_FWDSTAT                (0x2Au)      /*!< Functional watchdog status */

/*! FWDSTAT register bit masks */
#define HE9285_REG_MASK_FWDSTAT_FWDQUEST       (0x0Fu)      /*!< FWDSTAT:0:3 Functional watchdog question */

/*! PROTCFG register bit masks */
#define HE9285_REG_MASK_PROTCFG_KEY            (0xFFu)      /*!< PROTCFG:0:7 Key to lock/unlock protected registers */

/*! SYSPCFG1 register bit masks */
#define HE9285_REG_MASK_SYSPCFG1_ERREN         (0x08u)      /*!< SYSPCFG1:3:3 Enable ERR pin monitor */

/*! WDCFG0 register bit masks */
#define HE9285_REG_MASK_WDCFG0_WDCYC           (0x01u)      /*!< WDCFG0:0:0 Watchdog cycle time */
#define HE9285_REG_MASK_WDCFG0_WWDTSEL         (0x02u)      /*!< WDCFG0:1:1 Window watchdog trigger selection */
#define HE9285_REG_MASK_WDCFG0_FWDEN           (0x04u)      /*!< WDCFG0:3:3 Functional watchdog enable */
#define HE9285_REG_MASK_WDCFG0_WWDEN           (0x08u)      /*!< WDCFG0:3:3 Window watchdog enable */
#define HE9285_REG_MASK_WDCFG0_ERRTRH          (0xF0u)      /*!< WDCFG0:4:7 Window watchdog error threshold */

#define HE9285_WDCFG0_DEFAULT_VAL              (0x9Bu)      /*!< Default value of WDCFG0 */

/*! WWDSCMD register bit masks */
#define HE9285_REG_MASK_WWDSCMD_TRIG           (0x01u)      /*!< WWDSCMD:0:0 WWD trigger command to trigger WWD */
#define HE9285_REG_MASK_WWDSCMD_TRIG_STATUS    (0x80u)      /*!< WWDSCMD:7:7 Last internal trigger value received via SPI */

/*! Protection register values */
#define HE9285_REG_CMD_PROTCFG_UNLOCK_SEQ1     (0xABu)      /*!< First byte of consecutive unlock sequence */
#define HE9285_REG_CMD_PROTCFG_UNLOCK_SEQ2     (0xEFu)      /*!< Second byte of consecutive unlock sequence */
#define HE9285_REG_CMD_PROTCFG_UNLOCK_SEQ3     (0x56u)      /*!< Third byte of consecutive unlock sequence */
#define HE9285_REG_CMD_PROTCFG_UNLOCK_SEQ4     (0x12u)      /*!< Fourth byte of consecutive unlock sequence */

#define HE9285_REG_CMD_PROTCFG_LOCK_SEQ1       (0xDFu)      /*!< First byte of consecutive lock sequence */
#define HE9285_REG_CMD_PROTCFG_LOCK_SEQ2       (0x34u)      /*!< Second byte of consecutive lock sequence */
#define HE9285_REG_CMD_PROTCFG_LOCK_SEQ3       (0xBEu)      /*!< Third byte of consecutive lock sequence */
#define HE9285_REG_CMD_PROTCFG_LOCK_SEQ4       (0xCAu)      /*!< Fourth byte of consecutive lock sequence */





/*
 **********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************
 */

typedef union {
	uint8 R;
	struct {
		uint8 WDCYC:1;
		uint8 WWDTSEL:1;
		uint8 FWDEN:1;
		uint8 WWDEN:1;
		uint8 WWDETHR:4;
	} B;
} REG_WDCFG0_t;

typedef union {
	uint8 R;
	struct {
		uint8 WAK:1;
		uint8 ENA:1;
		uint8 CMON:1;
		uint8 WKTIM:1;
		uint8 WKSPI:1;
		uint8 NU:3;
	} B;
} REG_WKSF_t;

typedef union {
	uint8 R;
	struct {
		uint8 NU:2;
		uint8 VMONF:1;
		uint8 WWDF:1;
		uint8 FWDF:1;
		uint8 ERRF:1;
		uint8 SOFTRES:1;
		uint8 HARDRES:1;
	} B;
} REG_INITERR_t;

#endif /* CDD_HE9285_STRUCT_H */

/*
 **********************************************************************************************************************
 * End of the file
 **********************************************************************************************************************
 */
