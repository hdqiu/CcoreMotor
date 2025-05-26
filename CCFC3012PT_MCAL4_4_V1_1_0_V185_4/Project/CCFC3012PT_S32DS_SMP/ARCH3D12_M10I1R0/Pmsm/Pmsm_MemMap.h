/*******************************************************************************
**                                                                            **
** Copyright (C) XXXXXXXX XXXXXXXXXXXX (2025)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Pmsm_MemMap.h                                              **
**                                                                            **
**  VERSION      : 0.0.1                                                      **
**                                                                            **
**  DATE         : 2025-03-26                                                 **
**                                                                            **
**  PLATFORM     : xxxx                                                       **
**                                                                            **
**  AUTHOR       : XXXX                                                       **
**                                                                            **
**  DESCRIPTION  : Memary mapping for Pmsm group                              **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
*******************************************************************************/
#define PMSM_MEMMAP_SECTION_NOTMATCH_ERROR "Pmsm_MemMap.h, start - stop section defined not match."
#define PMSM_MEMMAP_ERROR

/* TEXT */
#ifdef PMSM_START_TRUSTED_SEC_TEXT
    #undef PMSM_START_TRUSTED_SEC_TEXT
    #define ENTERED_PMSM_START_TRUSTED_SEC_TEXT
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_TRUSTED_SEC_TEXT
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_TRUSTED_SEC_TEXT
    #ifdef ENTERED_PMSM_START_TRUSTED_SEC_TEXT
        #undef ENTERED_PMSM_START_TRUSTED_SEC_TEXT
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_TRUSTED_SEC_TEXT
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* PSRAM TEXT */
#ifdef PMSM_START_SEC_PSRAM_TEXT
    #undef PMSM_START_SEC_PSRAM_TEXT
    #define ENTERED_PMSM_START_SEC_PSRAM_TEXT
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_PSRAM_TEXT
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        // __attribute__ ((section (".data.code")))
#endif

#ifdef PMSM_STOP_SEC_PSRAM_TEXT
    #ifdef ENTERED_PMSM_START_SEC_PSRAM_TEXT
        #undef ENTERED_PMSM_START_SEC_PSRAM_TEXT
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_PSRAM_TEXT
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/*******************************************************************************
**                      partII: user data                                     **
*******************************************************************************/
/* DATA 8BITS */
#ifdef PMSM_START_SEC_USER_DATA_8BITS
    #undef PMSM_START_SEC_USER_DATA_8BITS
    #define ENTERED_PMSM_START_SEC_USER_DATA_8BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_DATA_8BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_DATA_8BITS
    #ifdef ENTERED_PMSM_START_SEC_USER_DATA_8BITS
        #undef ENTERED_PMSM_START_SEC_USER_DATA_8BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_DATA_8BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA 16BITS */
#ifdef PMSM_START_SEC_USER_DATA_16BITS
    #undef PMSM_START_SEC_USER_DATA_16BITS
    #define ENTERED_PMSM_START_SEC_USER_DATA_16BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_DATA_16BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_DATA_16BITS
    #ifdef ENTERED_PMSM_START_SEC_USER_DATA_16BITS
        #undef ENTERED_PMSM_START_SEC_USER_DATA_16BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_DATA_16BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA 32BITS */
#ifdef PMSM_START_SEC_USER_DATA_32BITS
    #undef PMSM_START_SEC_USER_DATA_32BITS
    #define ENTERED_PMSM_START_SEC_USER_DATA_32BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_DATA_32BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_DATA_32BITS
    #ifdef ENTERED_PMSM_START_SEC_USER_DATA_32BITS
        #undef ENTERED_PMSM_START_SEC_USER_DATA_32BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_DATA_32BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA Unspecified */
#ifdef PMSM_START_SEC_USER_DATA_UNSPECIFIED
    #undef PMSM_START_SEC_USER_DATA_UNSPECIFIED
    #define ENTERED_PMSM_START_SEC_USER_DATA_UNSPECIFIED
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_DATA_UNSPECIFIED
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_DATA_UNSPECIFIED
    #ifdef ENTERED_PMSM_START_SEC_USER_DATA_UNSPECIFIED
        #undef ENTERED_PMSM_START_SEC_USER_DATA_UNSPECIFIED
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_DATA_UNSPECIFIED
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 8BITS */
#ifdef PMSM_START_SEC_USER_BSS_8BITS
    #undef PMSM_START_SEC_USER_BSS_8BITS
    #define ENTERED_PMSM_START_SEC_USER_BSS_8BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_BSS_8BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_BSS_8BITS
    #ifdef ENTERED_PMSM_START_SEC_USER_BSS_8BITS
        #undef ENTERED_PMSM_START_SEC_USER_BSS_8BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_BSS_8BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 16BITS */
#ifdef PMSM_START_SEC_USER_BSS_16BITS
    #undef PMSM_START_SEC_USER_BSS_16BITS
    #define ENTERED_PMSM_START_SEC_USER_BSS_16BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_BSS_16BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_BSS_16BITS
    #ifdef ENTERED_PMSM_START_SEC_USER_BSS_16BITS
        #undef ENTERED_PMSM_START_SEC_USER_BSS_16BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_BSS_16BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 32BITS */
#ifdef PMSM_START_SEC_USER_BSS_32BITS
    #undef PMSM_START_SEC_USER_BSS_32BITS
    #define ENTERED_PMSM_START_SEC_USER_BSS_32BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_BSS_32BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_BSS_32BITS
    #ifdef ENTERED_PMSM_START_SEC_USER_BSS_32BITS
        #undef ENTERED_PMSM_START_SEC_USER_BSS_32BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_BSS_32BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS Unspecified */
#ifdef PMSM_START_SEC_USER_BSS_UNSPECIFIED
    #undef PMSM_START_SEC_USER_BSS_UNSPECIFIED
    #define ENTERED_PMSM_START_SEC_USER_BSS_UNSPECIFIED
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_BSS_UNSPECIFIED
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_BSS_UNSPECIFIED
    #ifdef ENTERED_PMSM_START_SEC_USER_BSS_UNSPECIFIED
        #undef ENTERED_PMSM_START_SEC_USER_BSS_UNSPECIFIED
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_BSS_UNSPECIFIED
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/*******************************************************************************
**                      partIII: trusted data                                 **
*******************************************************************************/
/* DATA 8BITS */
#ifdef PMSM_START_SEC_TRUSTED_DATA_8BITS
    #undef PMSM_START_SEC_TRUSTED_DATA_8BITS
    #define ENTERED_PMSM_START_SEC_TRUSTED_DATA_8BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_DATA_8BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
        __attribute__ ((section (".cpu0_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_DATA_8BITS
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_DATA_8BITS
        #undef ENTERED_PMSM_START_SEC_TRUSTED_DATA_8BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_DATA_8BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA 16BITS */
#ifdef PMSM_START_SEC_TRUSTED_DATA_16BITS
    #undef PMSM_START_SEC_TRUSTED_DATA_16BITS
    #define ENTERED_PMSM_START_SEC_TRUSTED_DATA_16BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_DATA_16BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu0_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_DATA_16BITS
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_DATA_16BITS
        #undef ENTERED_PMSM_START_SEC_TRUSTED_DATA_16BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_DATA_16BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA 32BITS */
#ifdef PMSM_START_SEC_TRUSTED_DATA_32BITS
    #undef PMSM_START_SEC_TRUSTED_DATA_32BITS
    #define ENTERED_PMSM_START_SEC_TRUSTED_DATA_32BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_DATA_32BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu0_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_DATA_32BITS
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_DATA_32BITS
        #undef ENTERED_PMSM_START_SEC_TRUSTED_DATA_32BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_DATA_32BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA Unspecified */
#ifdef PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED
    #undef PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED
    #define ENTERED_PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_DATA_UNSPECIFIED
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu0_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_DATA_UNSPECIFIED
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED
        #undef ENTERED_PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_DATA_UNSPECIFIED
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 8BITS */
#ifdef PMSM_START_SEC_TRUSTED_BSS_8BITS
    #undef PMSM_START_SEC_TRUSTED_BSS_8BITS
    #define ENTERED_PMSM_START_SEC_TRUSTED_BSS_8BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_BSS_8BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu0_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_BSS_8BITS
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_BSS_8BITS
        #undef ENTERED_PMSM_START_SEC_TRUSTED_BSS_8BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_BSS_8BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 16BITS */
#ifdef PMSM_START_SEC_TRUSTED_BSS_16BITS
    #undef PMSM_START_SEC_TRUSTED_BSS_16BITS
    #define ENTERED_PMSM_START_SEC_TRUSTED_BSS_16BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_BSS_16BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu0_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_BSS_16BITS
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_BSS_16BITS
        #undef ENTERED_PMSM_START_SEC_TRUSTED_BSS_16BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_BSS_16BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 32BITS */
#ifdef PMSM_START_SEC_TRUSTED_BSS_32BITS
    #undef PMSM_START_SEC_TRUSTED_BSS_32BITS
    #define ENTERED_PMSM_START_SEC_TRUSTED_BSS_32BITS
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_BSS_32BITS
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu0_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_BSS_32BITS
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_BSS_32BITS
        #undef ENTERED_PMSM_START_SEC_TRUSTED_BSS_32BITS
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_BSS_32BITS
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS Unspecified */
#ifdef PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED
    #undef PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED
    #define ENTERED_PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu0_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED
        #undef ENTERED_PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* Trusted Const UNSPECIFIED */
#ifdef PMSM_START_TRUSTED_CONST_UNSPECIFIED
    #undef PMSM_START_TRUSTED_CONST_UNSPECIFIED
    #define ENTERED_PMSM_START_TRUSTED_CONST_UNSPECIFIED
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_TRUSTED_CONST_UNSPECIFIED
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_TRUSTED_CONST_UNSPECIFIED
    #ifdef ENTERED_PMSM_START_TRUSTED_CONST_UNSPECIFIED
        #undef ENTERED_PMSM_START_TRUSTED_CONST_UNSPECIFIED
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_TRUSTED_CONST_UNSPECIFIED
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif







//////////////////////////////////////////////////////////////////////////////////////////////////////////////







/* Motor B */
/* TEXT */
#ifdef PMSM_START_TRUSTED_SEC_TEXT_MOTB
    #undef PMSM_START_TRUSTED_SEC_TEXT_MOTB
    #define ENTERED_PMSM_START_TRUSTED_SEC_TEXT_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
    #ifdef ENTERED_PMSM_START_TRUSTED_SEC_TEXT_MOTB
        #undef ENTERED_PMSM_START_TRUSTED_SEC_TEXT_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* PSRAM TEXT */
#ifdef PMSM_START_SEC_PSRAM_TEXT_MOTB
    #undef PMSM_START_SEC_PSRAM_TEXT_MOTB
    #define ENTERED_PMSM_START_SEC_PSRAM_TEXT_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_PSRAM_TEXT_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        // __attribute__ ((section (".data.code")))
#endif

#ifdef PMSM_STOP_SEC_PSRAM_TEXT_MOTB
    #ifdef ENTERED_PMSM_START_SEC_PSRAM_TEXT_MOTB
        #undef ENTERED_PMSM_START_SEC_PSRAM_TEXT_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_PSRAM_TEXT_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/*******************************************************************************
**                      partII: user data                                     **
*******************************************************************************/
/* DATA 8BITS */
#ifdef PMSM_START_SEC_USER_DATA_8BITS_MOTB
    #undef PMSM_START_SEC_USER_DATA_8BITS_MOTB
    #define ENTERED_PMSM_START_SEC_USER_DATA_8BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_DATA_8BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_DATA_8BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_USER_DATA_8BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_USER_DATA_8BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_DATA_8BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA 16BITS */
#ifdef PMSM_START_SEC_USER_DATA_16BITS_MOTB
    #undef PMSM_START_SEC_USER_DATA_16BITS_MOTB
    #define ENTERED_PMSM_START_SEC_USER_DATA_16BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_DATA_16BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_DATA_16BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_USER_DATA_16BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_USER_DATA_16BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_DATA_16BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA 32BITS */
#ifdef PMSM_START_SEC_USER_DATA_32BITS_MOTB
    #undef PMSM_START_SEC_USER_DATA_32BITS_MOTB
    #define ENTERED_PMSM_START_SEC_USER_DATA_32BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_DATA_32BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_DATA_32BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_USER_DATA_32BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_USER_DATA_32BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_DATA_32BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA Unspecified */
#ifdef PMSM_START_SEC_USER_DATA_UNSPECIFIED_MOTB
    #undef PMSM_START_SEC_USER_DATA_UNSPECIFIED_MOTB
    #define ENTERED_PMSM_START_SEC_USER_DATA_UNSPECIFIED_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_DATA_UNSPECIFIED_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_DATA_UNSPECIFIED_MOTB
    #ifdef ENTERED_PMSM_START_SEC_USER_DATA_UNSPECIFIED_MOTB
        #undef ENTERED_PMSM_START_SEC_USER_DATA_UNSPECIFIED_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_DATA_UNSPECIFIED_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 8BITS */
#ifdef PMSM_START_SEC_USER_BSS_8BITS_MOTB
    #undef PMSM_START_SEC_USER_BSS_8BITS_MOTB
    #define ENTERED_PMSM_START_SEC_USER_BSS_8BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_BSS_8BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_BSS_8BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_USER_BSS_8BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_USER_BSS_8BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_BSS_8BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 16BITS */
#ifdef PMSM_START_SEC_USER_BSS_16BITS_MOTB
    #undef PMSM_START_SEC_USER_BSS_16BITS_MOTB
    #define ENTERED_PMSM_START_SEC_USER_BSS_16BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_BSS_16BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_BSS_16BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_USER_BSS_16BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_USER_BSS_16BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_BSS_16BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 32BITS */
#ifdef PMSM_START_SEC_USER_BSS_32BITS_MOTB
    #undef PMSM_START_SEC_USER_BSS_32BITS_MOTB
    #define ENTERED_PMSM_START_SEC_USER_BSS_32BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_BSS_32BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_BSS_32BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_USER_BSS_32BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_USER_BSS_32BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_BSS_32BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS Unspecified */
#ifdef PMSM_START_SEC_USER_BSS_UNSPECIFIED_MOTB
    #undef PMSM_START_SEC_USER_BSS_UNSPECIFIED_MOTB
    #define ENTERED_PMSM_START_SEC_USER_BSS_UNSPECIFIED_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_USER_BSS_UNSPECIFIED_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_SEC_USER_BSS_UNSPECIFIED_MOTB
    #ifdef ENTERED_PMSM_START_SEC_USER_BSS_UNSPECIFIED_MOTB
        #undef ENTERED_PMSM_START_SEC_USER_BSS_UNSPECIFIED_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_USER_BSS_UNSPECIFIED_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/*******************************************************************************
**                      partIII: trusted data                                 **
*******************************************************************************/
/* DATA 8BITS */
#ifdef PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
    #undef PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
    #define ENTERED_PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu1_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA 16BITS */
#ifdef PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
    #undef PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
    #define ENTERED_PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu1_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA 32BITS */
#ifdef PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
    #undef PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
    #define ENTERED_PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu1_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* DATA Unspecified */
#ifdef PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
    #undef PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
    #define ENTERED_PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu1_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
        #undef ENTERED_PMSM_START_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_DATA_UNSPECIFIED_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 8BITS */
#ifdef PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
    #undef PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
    #define ENTERED_PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu1_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 16BITS */
#ifdef PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
    #undef PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
    #define ENTERED_PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu1_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS 32BITS */
#ifdef PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
    #undef PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
    #define ENTERED_PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu1_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
        #undef ENTERED_PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* BSS Unspecified */
#ifdef PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
    #undef PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
    #define ENTERED_PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
//        __attribute__ ((section (".data_share")))
		__attribute__ ((section (".cpu1_dtcm_data")))
#endif

#ifdef PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
    #ifdef ENTERED_PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
        #undef ENTERED_PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

/* Trusted Const UNSPECIFIED */
#ifdef PMSM_START_TRUSTED_CONST_UNSPECIFIED_MOTB
    #undef PMSM_START_TRUSTED_CONST_UNSPECIFIED_MOTB
    #define ENTERED_PMSM_START_TRUSTED_CONST_UNSPECIFIED_MOTB
    #ifndef PMSM_MEMMAP_MATCH_ERROR
        #define PMSM_MEMMAP_MATCH_ERROR
    #else
        #ifndef PMSM_STOP_TRUSTED_CONST_UNSPECIFIED_MOTB
            #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
        #endif
    #endif
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif

#ifdef PMSM_STOP_TRUSTED_CONST_UNSPECIFIED_MOTB
    #ifdef ENTERED_PMSM_START_TRUSTED_CONST_UNSPECIFIED_MOTB
        #undef ENTERED_PMSM_START_TRUSTED_CONST_UNSPECIFIED_MOTB
    #else
        #error PMSM_MEMMAP_SECTION_NOTMATCH_ERROR
    #endif
    #ifdef PMSM_MEMMAP_MATCH_ERROR
        #undef PMSM_MEMMAP_MATCH_ERROR
    #endif
    #undef PMSM_STOP_TRUSTED_CONST_UNSPECIFIED_MOTB
    #undef PMSM_MEMMAP_ERROR
        /* no definition -> default compiler settings are used */
#endif


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
