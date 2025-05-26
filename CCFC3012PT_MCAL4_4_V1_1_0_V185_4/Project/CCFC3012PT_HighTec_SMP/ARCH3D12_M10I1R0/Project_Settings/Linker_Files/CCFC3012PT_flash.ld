/* Entry Point */
ENTRY(_start)

MEMORY
{
    boot_header : org = 0x00FC0000, len = 0x4
    cpu0_reset_vector : org = (0x00FC0000 + 0x04), len = 0x4
    cpu0_reset_vector_addr : org = 0x01100000, len = 0
    cpu1_reset_vector : org = (0x00FC0000 + 0x08), len = 0x4
    cpu1_reset_vector_addr : org = 0x01100000, len = 0
    cpu2_reset_vector : org = (0x00FC0000 + 0x0C), len = 0x4
    cpu2_reset_vector_addr : org = 0x01100000, len = 0
    cpu3_reset_vector : org = (0x00FC0000 + 0x10), len = 0x4
    cpu3_reset_vector_addr : org = 0x01100000, len = 0
    cpu4_reset_vector : org = (0x00FC0000 + 0x14), len = 0x4
    cpu4_reset_vector_addr : org = 0x01100000, len = 0
    cpu5_reset_vector : org = (0x00FC0000 + 0x18), len = 0x4
    cpu5_reset_vector_addr : org = 0x01100000, len = 0

    hsm_parsave_addr : org = (0x00FC0000 + 0x1C), len = 4
    hsm_parstr_addr : org = (0x00FC0000 + 0x20), len = 48
    
    cal_data_flash : org = 0x01000000, len = 64K
    cal_data_ram : org = 0x400b0000, len = 64K

    m_text : org = 0x01100000, len = 2048K
    m_data : org = 0x40000000, len = 640K - 0x200
    m_data_share : org = 0x400a0000, len = 64K

    cpu0_local_imem : org = 0x50000000, len = 16K
    cpu0_local_dmem : org = 0x50800000, len = 304K
    cpu1_local_imem : org = 0x51000000, len = 16K
    cpu1_local_dmem : org = 0x51800000, len = 304K
    cpu2_local_imem : org = 0x52000000, len = 16K
    cpu2_local_dmem : org = 0x52800000, len = 160K
    cpu3_local_imem : org = 0x53000000, len = 16K
    cpu3_local_dmem : org = 0x53800000, len = 160K
    cpu4_local_imem : org = 0x54000000, len = 16K
    cpu4_local_dmem : org = 0x54800000, len = 160K
    cpu5_local_imem : org = 0x55000000, len = 16K
    cpu5_local_dmem : org = 0x55800000, len = 160K

    acload_memory : org = 0x40000000 + 640K - 0x200, len = 0x200
}

ENTRY(_start);

SECTIONS
{
    .boot_header   : 
    {
        KEEP(*(.boot_header))
    } > boot_header
    .cpu0_reset_vector  : 
    {
        KEEP(*(.cpu0_reset_vector))
    } > cpu0_reset_vector
    
    .cpu0_reset_vector_addr  : 
    {
        __CPU_CORE_0_RESET_VECTOR_ADDR = . ;
    } > cpu0_reset_vector_addr

    .cpu1_reset_vector  : 
    {
        KEEP(*(.cpu1_reset_vector))
    } > cpu1_reset_vector

    .cpu1_reset_vector_addr  : 
    {
        __CPU_CORE_1_RESET_VECTOR_ADDR = . ;
    } > cpu1_reset_vector_addr

    .cpu2_reset_vector  : 
    {
        KEEP(*(.cpu2_reset_vector))
    } > cpu2_reset_vector

    .cpu2_reset_vector_addr  : 
    {
        __CPU_CORE_2_RESET_VECTOR_ADDR = . ;
    } > cpu2_reset_vector_addr

    .cpu3_reset_vector  : 
    {
        KEEP(*(.cpu3_reset_vector))
    } > cpu3_reset_vector

    .cpu3_reset_vector_addr  : 
    {
        __CPU_CORE_3_RESET_VECTOR_ADDR = . ;
    } > cpu3_reset_vector_addr

    .cpu4_reset_vector  : 
    {
        KEEP(*(.cpu4_reset_vector))
    } > cpu4_reset_vector

    .cpu4_reset_vector_addr  : 
    {
        __CPU_CORE_4_RESET_VECTOR_ADDR = . ;
    } > cpu4_reset_vector_addr

    .cpu5_reset_vector  : 
    {
        KEEP(*(.cpu5_reset_vector))
    } > cpu5_reset_vector

    .cpu5_reset_vector_addr  : 
    {
        __CPU_CORE_5_RESET_VECTOR_ADDR = . ;
    } > cpu5_reset_vector_addr

     .hsm_param_save_addr  : 
    {
        KEEP(*(.hsm_param_save_addr))
    } > hsm_parsave_addr
    
     .hsm_param_store_addr  : 
    {
        __HSM_PARAM_BASE_ADDR = .;
        KEEP(*(.hsm_param_store_addr))
    } > hsm_parstr_addr

    .startup : ALIGN(0x400)
    {
        *(.startup)
    } > m_text
    
    .core_exceptions_table : ALIGN(4096)
    {
      __IVPR_VALUE = . ;
      KEEP(*(.core_exceptions_table))
    } > m_text

    .intc_vector_table : ALIGN(4096)
    {
      KEEP(*(.intc_vector_table))
    } > m_data AT>m_text

	 .cal_section :
    {
        KEEP(*(.cal_section))
        KEEP(*(.cal_section.*))
    } > cal_data_flash

    .text : 
    {
      *(.text.startup)
      *(.text)      
      *(.text_*)
      *(.text.*)
      KEEP (*(.init))
      KEEP (*(.fini)) 
      _shell_command_start = .;
      KEEP (*(shellCommand))
      _shell_command_end = .;           
      . = ALIGN(16);
    } > m_text

    .ctors :
    {
      __CTOR_LIST__ = .;
      /* gcc uses crtbegin.o to find the start of
         the constructors, so we make sure it is
         first.  Because this is a wildcard, it
         doesn't matter if the user does not
         actually link against crtbegin.o; the
         linker won't look for a file to match a
         wildcard.  The wildcard also means that it
         doesn't matter which directory crtbegin.o
         is in.  */
      KEEP (*crtbegin.o(.ctors))
      KEEP (*crtbegin?.o(.ctors))
      /* We don't want to include the .ctor section from
         from the crtend.o file until after the sorted ctors.
         The .ctor section from the crtend file contains the
         end of ctors marker and it must be last */
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors))
      KEEP (*(SORT(.ctors.*)))
      KEEP (*(.ctors))
      __CTOR_END__ = .;
    } > m_text

    .dtors :
    {
      __DTOR_LIST__ = .;
      KEEP (*crtbegin.o(.dtors))
      KEEP (*crtbegin?.o(.dtors))
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
      KEEP (*(SORT(.dtors.*)))
      KEEP (*(.dtors))
      __DTOR_END__ = .;
    } > m_text
        
    .preinit_array :
    {
      PROVIDE_HIDDEN (__preinit_array_start = .);
      KEEP (*(.preinit_array*))
      PROVIDE_HIDDEN (__preinit_array_end = .);
    } > m_text

    .init_array :
    {
      PROVIDE_HIDDEN (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array*))
      PROVIDE_HIDDEN (__init_array_end = .);
    } > m_text

    .fini_array :
    {
      PROVIDE_HIDDEN (__fini_array_start = .);
      KEEP (*(SORT(.fini_array.*)))
      KEEP (*(.fini_array*))
      PROVIDE_HIDDEN (__fini_array_end = .);
    } > m_text
          
    .rodata :
    {
      *(.rodata)
      *(.rodata.*)
    } > m_text
    
    .eh_frame_hdr : { *(.eh_frame_hdr) } > m_text
    .eh_frame     : { KEEP (*(.eh_frame)) } > m_text    
   
    .data : 
    {
      *(.data)
      *(.data.*)
    }  > m_data AT>m_text
    
    .data_share : 
    {
	  __DATA_SHARE_START = .;
      *(.data_share)
	  __DATA_SHARE_END = .;
    }  > m_data_share AT>m_text

    .sdata2 :
    {  
      *(.sdata2)
      *(.sdata2.*)
    } > m_data AT>m_text

    .sbss2    (NOLOAD)   :
    {
      /* _SDA2_BASE_ = .; */ 
      *(.sbss2)
      *(.sbss2.*)
    } > m_data
    
    .sdata  :
    {
      *(.sdata)
      *(.sdata.*)
    } > m_data AT>m_text
    
    .bss   (NOLOAD)  :
    {
      __BSS_START = .;
      *(.sbss)
      *(.sbss.*)    
      *(.bss)
      *(.bss.*)
      *(COMMON)
      __BSS_END = .;
    } > m_data

    .stack_0 (NOLOAD) : ALIGN(16) 
    {
      __HEAP = . ;         
      . += 1024 ;
      __HEAP_END = . ;
      . +=  4096 ;
      __SP_ENTRY_0 = . ;
    } > cpu0_local_dmem

    .stack_1 (NOLOAD) : ALIGN(16) 
    {
      __HEAP = . ;         
      . += 1024 ;
      __HEAP_END = . ;
      . +=  4096 ;
      __SP_ENTRY_1 = . ;
    } > cpu1_local_dmem
    
    .stack_2 (NOLOAD) : ALIGN(16) 
    {
      __HEAP = . ;         
      . += 1024 ;
      __HEAP_END = . ;
      . +=  4096 ;
      __SP_ENTRY_2 = . ;
    } > cpu2_local_dmem

    .stack_3 (NOLOAD) : ALIGN(16) 
    {
      __HEAP = . ;         
      . += 1024 ;
      __HEAP_END = . ;
      . +=  4096 ;
      __SP_ENTRY_3 = . ;
    } > cpu3_local_dmem
    
    .stack_4 (NOLOAD) : ALIGN(16) 
    {
      __HEAP = . ;         
      . += 1024 ;
      __HEAP_END = . ;
      . +=  4096 ;
      __SP_ENTRY_4 = . ;
    } > cpu4_local_dmem

    .stack_5 (NOLOAD) : ALIGN(16) 
    {
      __HEAP = . ;         
      . += 1024 ;
      __HEAP_END = . ;
      . +=  4096 ;
      __SP_ENTRY_5 = . ;
    } > cpu5_local_dmem

/*-------- LABELS USED IN CODE -------------------------------*/
        
/* Labels for Copying Initialised Data from Flash to RAM */
__VECTOR_SRAM_ADDR  = ADDR(.intc_vector_table);
__DATA_SRAM_ADDR  = ADDR(.data);
__SDATA_SRAM_ADDR = ADDR(.sdata);
__DATA_SHARE_SRAM_ADDR  = ADDR(.data_share);

__VECTOR_SIZE   = SIZEOF(.intc_vector_table);
__DATA_SIZE   = SIZEOF(.data);
__SDATA_SIZE  = SIZEOF(.sdata);
__DATA_SHARE_SIZE   = SIZEOF(.data_share);

__VECTOR_ROM_ADDR  = LOADADDR(.intc_vector_table);
__DATA_ROM_ADDR  = LOADADDR(.data);
__SDATA_ROM_ADDR = LOADADDR(.sdata);
__DATA_SHARE_ROM_ADDR  = LOADADDR(.data_share);

/* Labels Used for Initialising SRAM ECC */
__SRAM_SIZE = 640K - 0x200;
__SRAM_BASE_ADDR = 0x40000000;

__SHARE_SRAM_SIZE = 64K;
__SHARE_SRAM_BASE_ADDR = 0x400a0000;

__CAL_SRAM_SIZE = 0x200;
__CAL_SRAM_BASE_ADDR = 0x40000000 + 640K - 0x200;

__BSS_SIZE    = __BSS_END - __BSS_START;      
__DATA_SHARE_SIZE    = __DATA_SHARE_END - __DATA_SHARE_START;  

__DTCM_SIZE_CORE_0 = 304K;
__DTCM_BASE_ADDR_CORE_0 = 0x50800000;

__ITCM_SIZE_CORE_0 = 16K;
__ITCM_BASE_ADDR_CORE_0 = 0x50000000;

__DTCM_SIZE_CORE_1 = 304K;
__DTCM_BASE_ADDR_CORE_1 = 0x51800000;

__ITCM_SIZE_CORE_1 = 16K;
__ITCM_BASE_ADDR_CORE_1 = 0x51000000;

__DTCM_SIZE_CORE_2 = 160K;
__DTCM_BASE_ADDR_CORE_2 = 0x52800000;

__ITCM_SIZE_CORE_2 = 16K;
__ITCM_BASE_ADDR_CORE_2 = 0x52000000;

__DTCM_SIZE_CORE_3 = 160K;
__DTCM_BASE_ADDR_CORE_3 = 0x53800000;

__ITCM_SIZE_CORE_3 = 16K;
__ITCM_BASE_ADDR_CORE_3 = 0x53000000;

__DTCM_SIZE_CORE_4 = 160K;
__DTCM_BASE_ADDR_CORE_4 = 0x54800000;

__ITCM_SIZE_CORE_4 = 16K;
__ITCM_BASE_ADDR_CORE_4 = 0x54000000;

__DTCM_SIZE_CORE_5 = 160K;
__DTCM_BASE_ADDR_CORE_5 = 0x55800000;

__ITCM_SIZE_CORE_5 = 16K;
__ITCM_BASE_ADDR_CORE_5 = 0x55000000;
}


