#ifndef SSI_REG_H_
#define SSI_REG_H_

/* ============================================================================
   =============================== Module: SSI ================================
   ============================================================================ */

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t FRF:2	;
		vuint32_t :1;
		vuint32_t DFS:5;
		vuint32_t :1;
		vuint32_t SSTE:1;
		vuint32_t SSRL:1;
		vuint32_t :1;
		vuint32_t TMOD:2;
		vuint32_t SCPOL:1;
		vuint32_t SCPH:1;
		vuint32_t SPI_FRF:2;
		vuint32_t :2;
		vuint32_t CFS:4;
		vuint32_t:8;
	}B;

}SSI_CTRLR0_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t DNF_L:8;
		vuint32_t DNF_H:8;
		vuint32_t:16;
	}B;

}SSI_CTRLR1_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t SSIC_EN:1;
		vuint32_t:24;
	}B;

}SSI_SSIENR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t SCKDV_L:8;
		vuint32_t SCKDV_H:8;
		vuint32_t:16;
	}B;

}SSI_BAUDR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:3;
		vuint32_t TFT:5;
		vuint32_t:11;
		vuint32_t TXFTHR:5;
		vuint32_t:8;
	}B;

}SSI_TXFTLR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:3;
		vuint32_t RFT:5;
		vuint32_t:24;
	}B;

}SSI_RXFTLR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:2;
		vuint32_t TXFLR:6;
		vuint32_t:24;
	}B;

}SSI_TXFLR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:2;
		vuint32_t RXFLR:6;
		vuint32_t:24;
	}B;

}SSI_RXFLR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:3;
		vuint32_t RFF:1;
		vuint32_t RFNE:1;
		vuint32_t TFE:1;
		vuint32_t TFNF:1;
		vuint32_t BUSY:1;
		vuint32_t:24;
	}B;

}SSI_SR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:1;
		vuint32_t XRXOIM:1;
		vuint32_t:1;
		vuint32_t RXFIM:1;
		vuint32_t RXOIM:1;
		vuint32_t RXUIM:1;
		vuint32_t TXOIM:1;
		vuint32_t TXEIM:1;
		vuint32_t:24;
	}B;

}SSI_IMR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:1;
		vuint32_t XRXOIS:1;
		vuint32_t:1;
		vuint32_t RXFIS:1;
		vuint32_t RXOIS:1;
		vuint32_t RXUIS:1;
		vuint32_t TXOIS:1;
		vuint32_t TXEIS:1;
		vuint32_t:24;
	}B;

}SSI_ISR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:1;
		vuint32_t XRXOIR:1;
		vuint32_t:1;
		vuint32_t RXFIR:1;
		vuint32_t RXOIR:1;
		vuint32_t RXUIR:1;
		vuint32_t TXOIR:1;
		vuint32_t TXEIR:1;
		vuint32_t:24;
	}B;

}SSI_RISR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t TXOICR:1;
		vuint32_t:24;
	}B;

}SSI_TXOICR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t RXOICR:1;
		vuint32_t:24;
	}B;

}SSI_RXOICR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t RXUICR:1;
		vuint32_t:24;
	}B;

}SSI_RXUICR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t ICR:1;
		vuint32_t:24;
	}B;

}SSI_ICR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:6;
		vuint32_t TDMAE:1;
		vuint32_t RDMAE:1;
		vuint32_t:24;
	}B;

}SSI_DMACR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:3;
		vuint32_t DMATDL:5;
		vuint32_t:24;
	}B;

}SSI_DMATDL_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:3;
		vuint32_t DMARDL:5;
		vuint32_t:24;
	}B;

}SSI_DMARDL_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t DR7_0:8;
		vuint32_t DR15_8:8;
		vuint32_t DR23_16:8;
		vuint32_t DR31_24:8;
	}B;

}SSI_DR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t RSD:8;
		vuint32_t :8;
		vuint32_t :7;
		vuint32_t SE:1;
		vuint32_t :8;
	}B;

}SSI_RXSDR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t :2;
		vuint32_t ADDR_L:4;
		vuint32_t TRANS_TYPE:2;
		vuint32_t WAIT_CYCLES:5;
		vuint32_t :1;
		vuint32_t INST_L:2;
		vuint32_t :9;
		vuint32_t CLK_STRETCH:1;
		vuint32_t :6;
	}B;

}SPI_CTRLR0_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t XIP_MD_BITS_L:8;
		vuint32_t XIP_MD_BITS_H:8;
		vuint32_t :16;
	}B;

}SSI_XIPMBR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t INCR_INST_L:8;
		vuint32_t INCR_INST_H:8;
		vuint32_t :16;
	}B;

}SSI_XIPIIR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t ADDR_L:4;
		vuint32_t TRANS_TYPE:2;
		vuint32_t FRF:2;
		vuint32_t WAIT_CYCLES_2_0:3;
		vuint32_t MD_BITS_EN:1;
		vuint32_t :1;
		vuint32_t INST_L:2;
		vuint32_t :1;
		vuint32_t CONT_XFER_EN:1;
		vuint32_t INST_EN:1;
		vuint32_t :3;
		vuint32_t DFS_HC:1;
		vuint32_t WAIT_CYCLES_4_3:2;
		vuint32_t :2;
		vuint32_t XIP_PREFETCH_EN:1;
		vuint32_t :1;
		vuint32_t XIP_MBL:2;
		vuint32_t :2;
	}B;

}SSI_XIPCR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t :7;
		vuint32_t XRXOICR:1;
		vuint32_t :24;
	}B;

}SSI_XRXOICR_tag;

struct SSI_tag{
//typedef struct{
    SSI_CTRLR0_tag CTRLR0;          //0x00
    SSI_CTRLR1_tag CTRLR1;          //0x04
    SSI_SSIENR_tag SSIENR;         	//0x08
    uint32_t reserve_0c;       		//0x0c
    uint32_t reserve_10;       		//0x10
    SSI_BAUDR_tag BAUDR;           	//0x14
    SSI_TXFTLR_tag TXFTLR;          //0x18
    SSI_RXFTLR_tag RXFTLR;    	    //0x1c
    SSI_TXFLR_tag TXFLR;     	    //0x20
    SSI_RXFLR_tag RXFLR;     	    //0x24
    SSI_SR_tag SR;        	      	//0x28
    SSI_IMR_tag IMR;        	    //0x2c
    SSI_ISR_tag ISR;        	    //0x30
    SSI_RISR_tag RISR;       	    //0x34
    SSI_TXOICR_tag TXOICR;          //0x38
    SSI_RXOICR_tag RXOICR;          //0x3c
    SSI_RXUICR_tag RXUICR;          //0x40
    uint32_t reserve_44;       		//0x44
	SSI_ICR_tag ICR;             	//0x48
	SSI_DMACR_tag DMACR;           	//0x4c
	SSI_DMATDL_tag DMATDLR;         //0x50
	SSI_DMARDL_tag DMARDLR;         //0x54
    uint32_t reserve_58;       		//0x58
    uint32_t reserve_5c;	    	//0x5c
	SSI_DR_tag DR;              	//0x60
    uint32_t RESERVERED[35];	    //0x64~0xec
    SSI_RXSDR_tag RXSDR; 	        //0xf0
    SPI_CTRLR0_tag SPICTRLR0;      	//0xf4
    uint32_t reserve_f8;  	         //0xf8
    SSI_XIPMBR_tag XIPMBR;   	     //0xfc
    SSI_XIPIIR_tag XIPIIR;           //0x100
    uint32_t reserve_104;  	         //0x104
    SSI_XIPCR_tag XIPCR;             //0x108
    uint32_t reserve_10c;  	         //0x10c
    uint32_t reserve_110;  	         //0x110
    uint32_t reserve_114;      	 	 //0x114
};

#endif
