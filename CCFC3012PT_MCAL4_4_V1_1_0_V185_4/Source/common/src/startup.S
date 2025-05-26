;#/**************************************************************************** 
;#* 
;#* Copyright (c) 2023  C*Core -   All Rights Reserved  
;#* 
;#* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
;#* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
;#* 
;#* @file     startup.S
;#* @version  1.0
;#* @date     2023 - 04 - 17
;#* @brief    Initial version.
;#*****************************************************************************/

#define  CPU_FIRST_BOOT_CORE 0

#ifdef __ghs__    /* GreenHills */
    .section    .startup, axv
    .vle

    .align 3  ;# 8 bytes

    .extern   main
    .extern   Mcore_Init
    .extern __SRAM_SIZE
    .extern __SRAM_BASE_ADDR
    .extern __SHARE_SRAM_SIZE
    .extern __SHARE_SRAM_BASE_ADDR
    .extern __CAL_SRAM_SIZE
    .extern __CAL_SRAM_BASE_ADDR
    .extern __LOCAL_DMEM_SIZE
    .extern __LOCAL_DMEM_BASE_ADDR
    .extern __LOCAL_IMEM_SIZE
    .extern __LOCAL_IMEM_BASE_ADDR
    .extern __VECTOR_SIZE
    .extern __VECTOR_ROM_ADDR
    .extern __VECTOR_SRAM_ADDR
    .extern __DATA_SIZE
    .extern __DATA_ROM_ADDR
    .extern __DATA_SRAM_ADDR
    .extern __DATA_SHARE_SIZE
    .extern __DATA_SHARE_ROM_ADDR
    .extern __DATA_SHARE_SRAM_ADDR
    .extern __SDATA_SIZE
    .extern __SDATA_ROM_ADDR
    .extern __SDATA_SRAM_ADDR
    .extern __BSS_START                 
    .extern __BSS_END                 
    .extern __BSS_SIZE
    .extern __SP_INIT
    .extern __SP_INIT_2
    .extern __SP_INIT_0
    .extern __SP_INIT_1
    .extern _SDA_BASE_
    .extern _SDA2_BASE_
#endif
#ifdef __GNUC__   /* GCC */
    .section .startup, "ax"
#endif
#ifdef __DCC__   /* Diab */
   .section ".startup",4,rx
#endif
#ifdef __HIGHTEC__ /* HighTec */
#define e_bdnz bdnz
#define e_beq  beq
#define e_subi subi
#define e_bne  bne
#endif


    .globl    _start
_start:

;#****************************** Turn off SWTs ********************************
#if defined(DISABLE_SWT0)
;#SWT0
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_bne       DISSWT2END
#endif

    e_lis r4, 0xFC05
    e_or2i r4, 0x0000

    e_li r3, 0xC520
    e_stw r3, 0x10(r4)

    e_li r3, 0xD928
    e_stw r3, 0x10(r4)

    e_lis r3, 0xFFFF
    e_or2i r3, 0x010A
    e_stw r3, 0(r4)
DISSWT2END:
#endif

;#********************************* Enable BTB ********************************
;# Flush & Enable BTB - Set BBFI bit in BUCSR
    e_li    r3, 0x201
    mtspr    1013, r3
    se_isync

;#**************************** Init Core Registers ****************************
;# The E200Z4 core needs its registers initialising before they are used
;# otherwise in Lock Step mode the two cores will contain different random data.
;# If this is stored to memory (e.g. stacked) it will cause a Lock Step error.

;# GPRs 0-31
    e_li    r0, 0
    e_li    r1, 0
    e_li    r2, 0
    e_li    r3, 0
    e_li    r4, 0
    e_li    r5, 0
    e_li    r6, 0
    e_li    r7, 0
    e_li    r8, 0
    e_li    r9, 0
    e_li    r10, 0
    e_li    r11, 0
    e_li    r12, 0
    e_li    r13, 0
    e_li    r14, 0
    e_li    r15, 0
    e_li    r16, 0
    e_li    r17, 0
    e_li    r18, 0
    e_li    r19, 0
    e_li    r20, 0
    e_li    r21, 0
    e_li    r22, 0
    e_li    r23, 0
    e_li    r24, 0
    e_li    r25, 0
    e_li    r26, 0
    e_li    r27, 0
    e_li    r28, 0
    e_li    r29, 0
    e_li    r30, 0
    e_li    r31, 0

;# Init any other CPU register which might be stacked (before being used).

    mtspr    1, r1         ;#XER
    mtcrf    0xFF, r1
    mtspr    CTR, r1
    mtspr    272, r1        ;#SPRG0
    mtspr    273, r1        ;#SPRG1
    mtspr    274, r1        ;#SPRG2
    mtspr    275, r1        ;#SPRG3
    mtspr    58, r1         ;#CSRR0
    mtspr    59, r1         ;#CSRR1
    mtspr    570, r1        ;#MCSRR0
    mtspr    571, r1        ;#MCSRR1
    mtspr    61, r1         ;#DEAR
    mtspr    63, r1         ;#IVPR
    mtspr    256, r1        ;#USPRG0
    mtspr    62, r1         ;#ESR
    mtspr    8,r31          ;#LR

;# if SMP, only the BOOT_CORE need to init outer core SRAM
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, CPU_FIRST_BOOT_CORE
    e_beq       _init_outer_core_sram_start
    e_bne       _init_outer_core_sram_end
#else
    e_b       _init_outer_core_sram_start
#endif

_init_outer_core_sram_start:
;#***************************** Initialise NORMAL SRAM ECC ***************************/
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __SRAM_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __SRAM_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the internal SRAM
    e_lis       r5, __SRAM_BASE_ADDR@h
    e_or2i      r5, __SRAM_BASE_ADDR@l

;# Fill SRAM with writes of 32GPRs    
sram_loop:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      sram_loop           # Loop for all of SRAM

;# only the BOOT_CORE need to init share SRAM
#ifdef CPU_FIRST_BOOT_CORE
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, CPU_FIRST_BOOT_CORE
    e_beq       _init_share_sram_start
    e_bne       _init_share_sram_end
#else
    e_b       _init_share_sram_end
#endif

_init_share_sram_start:
;#***************************** Initialise SHARE SRAM ECC ***************************/
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __SHARE_SRAM_SIZE@h  # Initialize r5 to size of SHARE SRAM (Bytes)
    e_or2i      r5, __SHARE_SRAM_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide SHARE SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the SHARE SRAM
    e_lis       r5, __SHARE_SRAM_BASE_ADDR@h
    e_or2i      r5, __SHARE_SRAM_BASE_ADDR@l

;# Fill SHARE SRAM with writes of 32GPRs
share_sram_loop:
    e_stmw      r0,0(r5)            # Write all 32 registers to SHARE SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      share_sram_loop     # Loop for all of SHARE SRAM

;#***************************** Initialise Calibration SRAM (used for FLASH) ECC ***************************/
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __CAL_SRAM_SIZE@h  # Initialize r5 to size of Calibration SRAM (Bytes)
    e_or2i      r5, __CAL_SRAM_SIZE@l
    e_srwi      r5, r5, 0x7         # Divide Calibration SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Calibration SRAM
    e_lis       r5, __CAL_SRAM_BASE_ADDR@h
    e_or2i      r5, __CAL_SRAM_BASE_ADDR@l

;# Fill Calibration SRAM with writes of 32GPRs
cal_sram_loop:
    e_stmw      r0,0(r5)            # Write all 32 registers to Calibration SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      cal_sram_loop       # Loop for all of Calibration SRAM

_init_share_sram_end:
_init_outer_core_sram_end:
_init_inner_core_sram_start:
;#************************ Initialise Local Data SRAM ECC *********************/
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_beq       _set_dtcm_attr_0
    e_cmp16i    r9, 1
    e_beq       _set_dtcm_attr_1
    e_cmp16i    r9, 2
    e_beq       _set_dtcm_attr_2
    e_cmp16i    r9, 3
    e_beq       _set_dtcm_attr_3
    e_cmp16i    r9, 4
    e_beq       _set_dtcm_attr_4
    e_cmp16i    r9, 5
    e_beq       _set_dtcm_attr_5
    ;#
_set_dtcm_attr_0:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __DTCM_SIZE_CORE_0@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __DTCM_SIZE_CORE_0@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __DTCM_BASE_ADDR_CORE_0@h
    e_or2i      r5, __DTCM_BASE_ADDR_CORE_0@l
    e_b     _set_dtcm_attr_end
_set_dtcm_attr_1:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __DTCM_SIZE_CORE_1@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __DTCM_SIZE_CORE_1@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __DTCM_BASE_ADDR_CORE_1@h
    e_or2i      r5, __DTCM_BASE_ADDR_CORE_1@l
    e_b     _set_dtcm_attr_end
_set_dtcm_attr_2:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __DTCM_SIZE_CORE_2@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __DTCM_SIZE_CORE_2@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __DTCM_BASE_ADDR_CORE_2@h
    e_or2i      r5, __DTCM_BASE_ADDR_CORE_2@l
    e_b     _set_dtcm_attr_end
_set_dtcm_attr_3:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __DTCM_SIZE_CORE_3@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __DTCM_SIZE_CORE_3@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __DTCM_BASE_ADDR_CORE_3@h
    e_or2i      r5, __DTCM_BASE_ADDR_CORE_3@l
    e_b     _set_dtcm_attr_end
_set_dtcm_attr_4:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __DTCM_SIZE_CORE_4@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __DTCM_SIZE_CORE_4@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __DTCM_BASE_ADDR_CORE_4@h
    e_or2i      r5, __DTCM_BASE_ADDR_CORE_4@l
    e_b     _set_dtcm_attr_end
_set_dtcm_attr_5:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __DTCM_SIZE_CORE_5@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __DTCM_SIZE_CORE_5@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __DTCM_BASE_ADDR_CORE_5@h
    e_or2i      r5, __DTCM_BASE_ADDR_CORE_5@l
    e_b     _set_dtcm_attr_end
_set_dtcm_attr_end:

;# Fill Local SRAM with writes of 32GPRs
ldmem_loop:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      ldmem_loop          # Loop for all of SRAM

;#************************ Initialise Local Instruction SRAM ECC **************/
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_beq       _set_itcm_attr_0
    e_cmp16i    r9, 1
    e_beq       _set_itcm_attr_1
    e_cmp16i    r9, 2
    e_beq       _set_itcm_attr_2
    e_cmp16i    r9, 3
    e_beq       _set_itcm_attr_3
    e_cmp16i    r9, 4
    e_beq       _set_itcm_attr_4
    e_cmp16i    r9, 5
    e_beq       _set_itcm_attr_5
    ;#
_set_itcm_attr_0:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __ITCM_SIZE_CORE_0@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __ITCM_SIZE_CORE_0@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __ITCM_BASE_ADDR_CORE_0@h
    e_or2i      r5, __ITCM_BASE_ADDR_CORE_0@l
    e_b     _set_itcm_attr_end
_set_itcm_attr_1:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __ITCM_SIZE_CORE_1@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __ITCM_SIZE_CORE_1@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __ITCM_BASE_ADDR_CORE_1@h
    e_or2i      r5, __ITCM_BASE_ADDR_CORE_1@l
    e_b     _set_itcm_attr_end
_set_itcm_attr_2:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __ITCM_SIZE_CORE_2@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __ITCM_SIZE_CORE_2@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __ITCM_BASE_ADDR_CORE_2@h
    e_or2i      r5, __ITCM_BASE_ADDR_CORE_2@l
    e_b     _set_itcm_attr_end
_set_itcm_attr_3:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __ITCM_SIZE_CORE_3@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __ITCM_SIZE_CORE_3@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __ITCM_BASE_ADDR_CORE_3@h
    e_or2i      r5, __ITCM_BASE_ADDR_CORE_3@l
    e_b     _set_itcm_attr_end
_set_itcm_attr_4:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __ITCM_SIZE_CORE_4@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __ITCM_SIZE_CORE_4@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __ITCM_BASE_ADDR_CORE_4@h
    e_or2i      r5, __ITCM_BASE_ADDR_CORE_4@l
    e_b     _set_itcm_attr_end
_set_itcm_attr_5:
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __ITCM_SIZE_CORE_5@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __ITCM_SIZE_CORE_5@l
    e_srwi      r5, r5, 0x7         # Divide SRAM size by 128
    mtctr       r5                  # Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
    e_lis       r5, __ITCM_BASE_ADDR_CORE_5@h
    e_or2i      r5, __ITCM_BASE_ADDR_CORE_5@l
    e_b     _set_itcm_attr_end
_set_itcm_attr_end:

;# Fill Local SRAM with writes of 32GPRs
limem_loop:
    e_stmw      r0,0(r5)            # Write all 32 registers to SRAM
    e_addi      r5,r5,128           # Increment the RAM pointer to next 128bytes
    e_bdnz      limem_loop          # Loop for all of SRAM

_init_inner_core_sram_end:


;#************************ Copy code to Local SRAM *********************/
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_beq       CPU0ITCMCOPY
    e_cmp16i    r9, 1
    e_beq       CPU1ITCMCOPY
    e_cmp16i    r9, 2
    e_beq       CPUITCMCOPYEND
    e_cmp16i    r9, 3
    e_beq       CPUITCMCOPYEND
    e_cmp16i    r9, 4
    e_beq       CPUITCMCOPYEND
    e_cmp16i    r9, 5
    e_beq       CPUITCMCOPYEND
    ;#

;# Initialised ITCM Data - ".itcm_data"
CPU0ITCMCOPY:
    e_lis       r9, __ITCM0_SIZE@h           # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __ITCM0_SIZE@l           # Load lower SRAM load size into R9
    e_cmp16i    r9,0                         # Compare to see if equal to 0
    e_beq       CPUITCMCOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                           # Store no. of bytes to be moved in counter

    e_lis       r10, __ITCM0_ROM_ADDR@h      # Load address of first SRAM load into R10
    e_or2i      r10, __ITCM0_ROM_ADDR@l      # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1                   # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __ITCM0_RAM_ADDR@h       # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __ITCM0_RAM_ADDR@l       # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1                    # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       CPUITCMCOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)
    e_b       CPUITCMCPYLOOP

;# Initialised ITCM Data - ".itcm_data"
CPU1ITCMCOPY:
    e_lis       r9, __ITCM1_SIZE@h           # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __ITCM1_SIZE@l           # Load lower SRAM load size into R9
    e_cmp16i    r9,0                         # Compare to see if equal to 0
    e_beq       CPUITCMCOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                           # Store no. of bytes to be moved in counter

    e_lis       r10, __ITCM1_ROM_ADDR@h      # Load address of first SRAM load into R10
    e_or2i      r10, __ITCM1_ROM_ADDR@l      # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1                   # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __ITCM1_RAM_ADDR@h       # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __ITCM1_RAM_ADDR@l       # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1                    # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       CPUITCMCOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)
    e_b       CPUITCMCPYLOOP

CPUITCMCPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      CPUITCMCPYLOOP          # Branch if more bytes to load from ROM

CPUITCMCOPYEND:


;#************************ Copy data to Local SRAM *********************/
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_beq       CPU0DTCMCOPY
    e_cmp16i    r9, 1
    e_beq       CPU1DTCMCOPY
    e_cmp16i    r9, 2
    e_beq       CPUDTCMCOPYEND
    e_cmp16i    r9, 3
    e_beq       CPUDTCMCOPYEND
    e_cmp16i    r9, 4
    e_beq       CPUDTCMCOPYEND
    e_cmp16i    r9, 5
    e_beq       CPUDTCMCOPYEND
    ;#

;# Initialised DTCM Data - ".dtcm_data"
CPU0DTCMCOPY:
    e_lis       r9, __DTCM0_DATA_SIZE@h           # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __DTCM0_DATA_SIZE@l           # Load lower SRAM load size into R9
    e_cmp16i    r9,0                         # Compare to see if equal to 0
    e_beq       CPUDTCMCOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                           # Store no. of bytes to be moved in counter

    e_lis       r10, __DTCM0_DATA_ROM_ADDR@h      # Load address of first SRAM load into R10
    e_or2i      r10, __DTCM0_DATA_ROM_ADDR@l      # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1                   # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __DTCM0_DATA_RAM_ADDR@h       # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __DTCM0_DATA_RAM_ADDR@l       # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1                    # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       CPUDTCMCOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)
    e_b       CPUDTCMCPYLOOP

;# Initialised Data Share - ".itcm_data"
CPU1DTCMCOPY:
    e_lis       r9, __DTCM1_DATA_SIZE@h           # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __DTCM1_DATA_SIZE@l           # Load lower SRAM load size into R9
    e_cmp16i    r9,0                         # Compare to see if equal to 0
    e_beq       CPUDTCMCOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                           # Store no. of bytes to be moved in counter

    e_lis       r10, __DTCM1_DATA_ROM_ADDR@h      # Load address of first SRAM load into R10
    e_or2i      r10, __DTCM1_DATA_ROM_ADDR@l      # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1                   # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __DTCM1_DATA_RAM_ADDR@h       # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __DTCM1_DATA_RAM_ADDR@l       # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1                    # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       CPUDTCMCOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)
    e_b       CPUDTCMCPYLOOP

CPUDTCMCPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      CPUDTCMCPYLOOP          # Branch if more bytes to load from ROM

CPUDTCMCOPYEND:

;# if SMP, only the BOOT_CORE need to copy data from FALSH to SRAM
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, CPU_FIRST_BOOT_CORE
    e_beq       _copy_data_from_flash_to_sram_start
    e_bne       _copy_data_from_flash_to_sram_end
#else
    e_b       _copy_data_from_flash_to_sram_start
#endif

_copy_data_from_flash_to_sram_start:
;#*************** Load Initialised Vector Table from Flash into RAM ************/
;# Initialised Vector - ".intc_vector_table"
VECTORCOPY:
    e_lis       r9, __VECTOR_SIZE@h       # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __VECTOR_SIZE@l       # Load lower SRAM load size into R9
    e_cmp16i    r9,0                      # Compare to see if equal to 0
    e_beq       VECTORCOPYEND             # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                      # Store no. of bytes to be moved in counter

    e_lis       r10, __VECTOR_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __VECTOR_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __VECTOR_SRAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __VECTOR_SRAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       VECTORCOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)

VECTORCPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      VECTORCPYLOOP             # Branch if more bytes to load from ROM

VECTORCOPYEND:
;#*************** Load Initialised Data Values from Flash into RAM ************/
;# Initialised Data - ".data"
DATACOPY:
    e_lis       r9, __DATA_SIZE@ha      # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __DATA_SIZE@l       # Load lower SRAM load size into R9                                     
    e_cmp16i    r9,0                    # Compare to see if equal to 0                                  
    e_beq       DATACOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)
                                        
    mtctr       r9                      # Store no. of bytes to be moved in counter
                                        
    e_lis       r10, __DATA_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __DATA_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __DATA_SRAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __DATA_SRAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       DATACOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)

DATACPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address 
    e_bdnz      DATACPYLOOP             # Branch if more bytes to load from ROM

DATACOPYEND:

;# Initialised Data Share - ".data_share"
DATASHARECOPY:
    e_lis       r9, __DATA_SHARE_SIZE@ha      # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __DATA_SHARE_SIZE@l       # Load lower SRAM load size into R9
    e_cmp16i    r9,0                    # Compare to see if equal to 0
    e_beq       DATASHARECOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)

    mtctr       r9                      # Store no. of bytes to be moved in counter

    e_lis       r10, __DATA_SHARE_ROM_ADDR@h  # Load address of first SRAM load into R10
    e_or2i      r10, __DATA_SHARE_ROM_ADDR@l  # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __DATA_SHARE_SRAM_ADDR@h  # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __DATA_SHARE_SRAM_ADDR@l  # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       DATASHARECOPYEND               # Skip to SDATA copy if addresses is equal (no need to copy data)

DATASHARECPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address
    e_bdnz      DATASHARECPYLOOP             # Branch if more bytes to load from ROM

DATASHARECOPYEND:

;#*************** Load Initialised Small Data Values from Flash into RAM ************/
;# Small Initialised Data - ".sdata"
SDATACOPY:    
    e_lis       r9, __SDATA_SIZE@ha     # Load upper SRAM load size (# of bytes) into R9
    e_or2i      r9, __SDATA_SIZE@l      # Load lower SRAM load size into R9                                     
    e_cmp16i    r9,0                    # Compare to see if equal to 0                                  
    e_beq       SDATACOPYEND               # Exit cfg_ROMCPY if size is zero (no data to initialise)
                                        
    mtctr       r9                      # Store no. of bytes to be moved in counter
                                        
    e_lis       r10, __SDATA_ROM_ADDR@h # Load address of first SRAM load into R10
    e_or2i      r10, __SDATA_ROM_ADDR@l # Load lower address of SRAM load into R10
    e_subi      r10,r10, 1              # Decrement address to prepare for ROMCPYLOOP

    e_lis       r5, __SDATA_SRAM_ADDR@h # Load upper SRAM address into R5 (from linker file)
    e_or2i      r5, __SDATA_SRAM_ADDR@l # Load lower SRAM address into R5 (from linker file)
    e_subi      r5, r5, 1               # Decrement address to prepare for ROMCPYLOOP
    cmp         cr0,r5, r10
    e_beq       SDATACOPYEND               # Skip copy if addresses is equal (no need to copy data)

SDATACPYLOOP:
    e_lbzu      r4, 1(r10)              # Load data byte at R10 into R4,incrementing (update) ROM address
    e_stbu      r4, 1(r5)               # Store R4 data byte into SRAM at R5 and update SRAM address 
    e_bdnz      SDATACPYLOOP            # Branch if more bytes to load from ROM

SDATACOPYEND:
_copy_data_from_flash_to_sram_end:

#ifdef ICACHE_ENABLE
;#****************** Invalidate and Enable the Instruction cache **************
__icache_cfg:
    e_lis    r7, 0x0000
    e_or2i    r7, 0x03FF        #create mask for lower 11 bits
    mfspr    r5, 516            #in lower 11 bits we have icache size
    and.    r7, r7, r5        #check if we have icache
    e_beq    __icache_skip    #branch if not
    mfspr    r7, 1011
    e_li    r5, 0x2
    mtspr    1011,r5
    mfspr    r7, 1011
    e_li    r7, 0x4
    e_li    r8, 0x2
    e_lis    r11,0xFFFF
    e_or2i    r11,0xFFFB

__icache_inv:
    mfspr    r9, 1011
    and.    r10, r7, r9
    e_beq    __icache_no_abort
    and.    r10, r11, r9
    mtspr    1011, r10
    e_b        __icache_cfg

__icache_no_abort:
    and.    r10, r8, r9
    e_bne    __icache_inv

    mfspr    r5, 1011
    e_ori    r5, r5, 0x0001
    se_isync
    ;#msync
    mtspr    1011, r5
__icache_skip:
#endif

#ifdef DCACHE_ENABLE
;#****************** Invalidate and Enable the Data cache **************
__dcache_cfg:
    e_lis    r7, 0x0000
    e_or2i    r7, 0x03FF        #create mask for lower 11 bits
    mfspr    r5, 515            #in lower 11 bits we have dcache size
    and.    r7, r7, r5        #check if we have dcache
    e_beq    __dcache_skip    #branch if not

    e_li r5, 0x2
    mtspr 1010,r5

    e_li r7, 0x4
    e_li r8, 0x2
    e_lis    r11,0xFFFF
    e_or2i    r11,0xFFFB

__dcache_inv:
    mfspr r9, 1010
    and.  r10, r7, r9
    e_beq   __dcache_no_abort
    and.  r10, r11, r9
    mtspr 1010, r10
    e_b __dcache_cfg

__dcache_no_abort:
    and.  r10, r8, r9
    e_bne __dcache_inv

    mfspr r5, 1010
    e_ori   r5, r5, 0x0001
    se_isync
    msync
    mtspr 1010, r5

__dcache_skip:
#endif

;# if SMP, only the BOOT_CORE need to init blank section
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, CPU_FIRST_BOOT_CORE
    e_beq       _init_blank_section_start
    e_bne       _init_blank_section_end
#else
    e_b       _init_blank_section_start
#endif
_init_blank_section_start:
;#****************************** Initialize BSS section ******************************/
bss_Init:
    e_lis        r9, __BSS_SIZE@h       # Load upper BSS load size (# of bytes) into R9
    e_or2i       r9, __BSS_SIZE@l       # Load lower BSS load size into R9 and compare to zero
    e_cmp16i     r9,0
    e_beq        bss_Init_end           # Exit if size is zero (no data to initialise)

    mtctr        r9                     # Store no. of bytes to be moved in counter

    e_lis        r5, __BSS_START@h      # Load upper BSS address into R5 (from linker file)
    e_or2i       r5, __BSS_START@l      # Load lower BSS address into R5 (from linker file)
    e_subi       r5, r5, 1              # Decrement address to prepare for bss_Init_loop

    e_lis        r4, 0x0

bss_Init_loop:
    e_stbu       r4, 1(r5)              # Store zero byte into BSS at R5 and update BSS address
    e_bdnz       bss_Init_loop          # Branch if more bytes to load

bss_Init_end:
;# only the BOOT_CORE need to init share SRAM
#ifdef CPU_FIRST_BOOT_CORE
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, CPU_FIRST_BOOT_CORE
    e_beq       data_share_Init
    e_bne       data_share_end
#else
    e_b       data_share_end
#endif

data_share_Init:
;#    e_lis        r9, __DATA_SHARE_SIZE@h       # Load upper BSS load size (# of bytes) into R9
;#    e_or2i       r9, __DATA_SHARE_SIZE@l       # Load lower BSS load size into R9 and compare to zero
;#    e_cmp16i     r9,0
;#    e_beq        data_share_end           # Exit if size is zero (no data to initialise)

;#    mtctr        r9                     # Store no. of bytes to be moved in counter

;#    e_lis        r5, __DATA_SHARE_START@h      # Load upper BSS address into R5 (from linker file)
;#    e_or2i       r5, __DATA_SHARE_START@l      # Load lower BSS address into R5 (from linker file)
;#    e_subi       r5, r5, 1              # Decrement address to prepare for bss_Init_loop

;#    e_lis        r4, 0x0

;#data_share_loop:
;#    e_stbu       r4, 1(r5)              # Store zero byte into BSS at R5 and update BSS address
;#    e_bdnz       data_share_loop          # Branch if more bytes to load

data_share_end:
_init_blank_section_end:
;#****************************** Configure Stack ******************************/
#ifdef SMP_ONLY_ONE_ELF
    mfspr       r9, 286             ;# Save coreid to r9
    e_cmp16i    r9, 0
    e_beq       _set_sp_init_0
    e_cmp16i    r9, 1
    e_beq       _set_sp_init_1
    e_cmp16i    r9, 2
    e_beq       _set_sp_init_2
    e_cmp16i    r9, 3
    e_beq       _set_sp_init_3
    e_cmp16i    r9, 4
    e_beq       _set_sp_init_4
    e_cmp16i    r9, 5
    e_beq       _set_sp_init_5
    ;#
_set_sp_init_0:
    e_lis    r1, __SP_ENTRY_0@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_0@l    ;# value in linker command file.
    e_b     _set_sp_init_end
_set_sp_init_1:
    e_lis    r1, __SP_ENTRY_1@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_1@l    ;# value in linker command file.
    e_b     _set_sp_init_end
_set_sp_init_2:
    e_lis    r1, __SP_ENTRY_2@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_2@l    ;# value in linker command file.
    e_b     _set_sp_init_end
_set_sp_init_3:
    e_lis    r1, __SP_ENTRY_3@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_3@l    ;# value in linker command file.
    e_b     _set_sp_init_end
_set_sp_init_4:
    e_lis    r1, __SP_ENTRY_4@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_4@l    ;# value in linker command file.
    e_b     _set_sp_init_end
_set_sp_init_5:
    e_lis    r1, __SP_ENTRY_5@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_ENTRY_5@l    ;# value in linker command file.
    e_b     _set_sp_init_end
_set_sp_init_end:
#else
    e_lis    r1, __SP_INIT@h    ;# Initialize stack pointer r1 to
    e_or2i    r1, __SP_INIT@l    ;# value in linker command file.
#endif
    e_stwu    r0,-64(r1)            ;# Terminate stack.

#ifndef __HIGHTEC__
    e_lis    r13, _SDA_BASE_@h    ;# Initialize r13 to sdata base
    e_or2i    r13, _SDA_BASE_@l    ;# (provided by linker).

    e_lis    r2, _SDA2_BASE_@h    ;# Initialize r2 to sdata2 base
    e_or2i    r2, _SDA2_BASE_@l    ;# (provided by linker).
#endif

;#*************************** Enable ME Bit in MSR *****************************
    mfmsr    r6
    e_or2i   r6,0x1000
    mtmsr    r6

#ifdef __DCC__ /* Diab */
    e_bl    __init_main
#endif

#ifdef MCORE_INIT
;# launch slave cores
    e_bl    Mcore_Init
#endif

;# Jump to Main
    e_bl    main

