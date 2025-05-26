INCLUDE "memory_smp.h"

/* Entry Point */
ENTRY(_start)

/* define CPU2 stack size */
__STACK_SIZE = CPU_CORE_X_STACK_SIZE;

/* define CPU2 heapsize */
__HEAP_SIZE = CPU_CORE_X_HEAP_SIZE;

/* Define CPU2 FLASH Size */
FLASH_SIZE = CPU_CORE_X_FLASH_SIZE;
/* Define CPU2 FLASH Base Address */
FLASH_BASE_ADDR = CPU_CORE_X_FLASH_BASE_ADDR;

/* Define CPU2 SRAM Size */
SRAM_SIZE = CPU_CORE_X_SRAM_SIZE - FLASH_AC_SIZE;
/* Define CPU2 SRAM Base Address */
SRAM_BASE_ADDR = CPU_CORE_X_SRAM_BASE_ADDR;

/* Define SHARE SRAM Size */
SHARE_SRAM_SIZE = MCORE_SHARE_SRAM_SIZE;
/* Define SHARE SRAM Base Address */
SHARE_SRAM_BASE_ADDR = MCORE_SHARE_BASE_ADDR;

/* Define Calibration FLASH Size */
CAL_FLASH_SIZE = MCORE_CAL_FLASH_SIZE;
/* Define Calibration FLASH Base Address */
CAL_FLASH_BASE_ADDR = MCORE_CAL_FLASH_BASE_ADDR;
/* Define Calibration SRAM Size */
CAL_SRAM_SIZE = MCORE_CAL_SRAM_SIZE;
/* Define Calibration SRAM Base Address */
CAL_SRAM_BASE_ADDR = MCORE_CAL_SRAM_BASE_ADDR;

/* Define CPU2 Local Instruction SRAM Allocation */  
LOCALIMEM_SIZE = CPU_CORE_X_LOCALIMEM_SIZE;
/* Define CPU2 Local Instruction SRAM Base Address */
LOCALIMEM_BASE_ADDR = CPU_CORE_X_LOCALIMEM_BASE_ADDR;



MEMORY
{
    boot_header : org = 0x00FC0000,  len = 0x4
    cpu0_reset_vec : org = (0x00FC0000 + 0x10), len = 0x4
    cpu1_reset_vec : org = (0x00FC0000 + 0x14), len = 0x4
    cpu2_reset_vec : org = (0x00FC0000 + 0x04), len = 0x4
    cpuc_reset_vec : org = (0x00FC0000 + 0x18), len = 0x4

    m_text : org = 0x1100000, len = 2048K
    m_data : org = 0x40000000, len = 768K
    m_data_share : org = 0x400C0000, len = 64K

    z4_2_local_imem  :   org = 0x52000000,      len = 16K
    z4_2_local_dmem  :   org = 0x52800000,      len = 64K

    z7_0_local_imem  :   org = 0x50000000,      len = 16K
    z7_0_local_dmem  :   org = 0x50800000,      len = 64K

    z7_1_local_imem  :   org = 0x51000000,      len = 16K
    z7_1_local_dmem  :   org = 0x51800000,      len = 64K
}

SECTIONS
{
    .boot_header   : 
    {
        KEEP(*(.boot_header))
    } > boot_header

    .cpu0_reset_vector  : 
    {
        KEEP(*(.cpu0_reset_vector))
    } > cpu0_reset_vec

    .cpu1_reset_vector  : 
    {
        KEEP(*(.cpu1_reset_vector))
    } > cpu1_reset_vec

    .cpu2_reset_vector  : 
    {
        KEEP(*(.cpu2_reset_vector))
    } > cpu2_reset_vec

    .cpuc_reset_vector  : 
    {
        KEEP(*(.cpuc_reset_vector))
    } > cpuc_reset_vec

    .cpu0_reset_vector_s  :
    {
        __CPU_Z7_0_FLASH_BASE_ADDR = .;
    } > cpu0_reset_vec_s
    
    .cpu1_reset_vector_s  :
    {
        __CPU_Z7_1_FLASH_BASE_ADDR = .;
    } > cpu1_reset_vec_s

    .startup : ALIGN(0x400)
    {
        __CPU_CORE_X_FLASH_BASE_ADDR = .;
	__start = . ;
        *(.startup)
    } > m_text
    
    .core_exceptions_table   : ALIGN(4096)
    {
      __IVPR_VALUE = . ;
      KEEP(*(.core_exceptions_table))
    } > m_text

    .intc_vector_table   : ALIGN(4096)
    {
      KEEP(*(.intc_vector_table))
    } > m_data AT>m_text
      
    .text : FLAGS(axv)
    {
      *(.text.startup)
      *(.text)      
      *(.text.*)
      *(.text_vle*)
      _shell_command_start = .;
      KEEP (*(shellCommand))
      _shell_command_end = .;
      KEEP (*(.init))
      KEEP (*(.fini))            
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
    
    .stack (NOLOAD) : ALIGN(16) 
    {
      __HEAP = . ;
      PROVIDE (_end = . );
      PROVIDE (end = . );            
      . += __HEAP_SIZE ;
      __HEAP_END = . ;
      _stack_end = . ;
      . +=  __STACK_SIZE ;
      _stack_addr = . ;
      __SP_INIT = . ;
      . += 4;
    } > z4_2_local_dmem  /* local_dmem */

    .stack_0 (NOLOAD) : ALIGN(16) 
    {
      _stack_end_0 = . ;
      . +=  __STACK_SIZE ;
      _stack_addr_0 = . ;
      __SP_INIT_0 = . ;
      . += 4;
    } > z7_0_local_dmem  /* local_dmem */

    .stack_1 (NOLOAD) : ALIGN(16) 
    {
      _stack_end_1 = . ;
      . +=  __STACK_SIZE ;
      _stack_addr_1 = . ;
      __SP_INIT_1 = . ;
      . += 4;
    } > z7_1_local_dmem  /* local_dmem */
 
/*-------- LABELS USED IN CODE -------------------------------*/
        
/* Labels for Copying Initialised Data from Flash to RAM */
__VECTOR_SRAM_ADDR  = ADDR(.intc_vector_table);
__DATA_SRAM_ADDR  = ADDR(.data);
__SDATA_SRAM_ADDR = ADDR(.sdata);

__VECTOR_SIZE   = SIZEOF(.intc_vector_table);
__DATA_SIZE   = SIZEOF(.data);
__SDATA_SIZE  = SIZEOF(.sdata);

__VECTOR_ROM_ADDR  = LOADADDR(.intc_vector_table);
__DATA_ROM_ADDR  = LOADADDR(.data);
__SDATA_ROM_ADDR = LOADADDR(.sdata);
   
/* Labels Used for Initialising SRAM ECC */
__SRAM_SIZE = SRAM_SIZE;
__SRAM_BASE_ADDR = SRAM_BASE_ADDR;

__SHARE_SRAM_SIZE = SHARE_SRAM_SIZE;
__SHARE_SRAM_BASE_ADDR = SHARE_SRAM_BASE_ADDR;

__CAL_SRAM_SIZE = CAL_SRAM_SIZE;
__CAL_SRAM_BASE_ADDR = CAL_SRAM_BASE_ADDR;

__Z4_2_LOCAL_DMEM_SIZE =      CPU_CORE_X_LOCALDMEM_SIZE;
__Z4_2_LOCAL_DMEM_BASE_ADDR = CPU_CORE_X_LOCALDMEM_BASE_ADDR;

__Z4_2_LOCAL_IMEM_SIZE =      CPU_CORE_X_LOCALIMEM_SIZE;
__Z4_2_LOCAL_IMEM_BASE_ADDR = CPU_CORE_X_LOCALIMEM_BASE_ADDR;

__Z7_0_LOCAL_DMEM_SIZE =      CPU_Z7_0_LOCALDMEM_SIZE;
__Z7_0_LOCAL_DMEM_BASE_ADDR = CPU_Z7_0_LOCALDMEM_BASE_ADDR;

__Z7_0_LOCAL_IMEM_SIZE =      CPU_Z7_0_LOCALIMEM_SIZE;
__Z7_0_LOCAL_IMEM_BASE_ADDR = CPU_Z7_0_LOCALIMEM_BASE_ADDR;

__Z7_1_LOCAL_DMEM_SIZE =      CPU_Z7_1_LOCALDMEM_SIZE;
__Z7_1_LOCAL_DMEM_BASE_ADDR = CPU_Z7_1_LOCALDMEM_BASE_ADDR;

__Z7_1_LOCAL_IMEM_SIZE =      CPU_Z7_1_LOCALIMEM_SIZE;
__Z7_1_LOCAL_IMEM_BASE_ADDR = CPU_Z7_1_LOCALIMEM_BASE_ADDR;

__BSS_SIZE    = __BSS_END - __BSS_START;      
__DATA_SHARE_SIZE    = __DATA_SHARE_END - __DATA_SHARE_START;   
}