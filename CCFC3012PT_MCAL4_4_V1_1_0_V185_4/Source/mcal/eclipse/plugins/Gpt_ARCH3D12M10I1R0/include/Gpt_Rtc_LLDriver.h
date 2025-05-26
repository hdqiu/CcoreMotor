#ifndef GPT_RTC_LLDRIVER_H
#define GPT_RTC_LLDRIVER_H

#include "StandardTypes.h"
#include "Gpt_Cfg.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define GPT_VENDOR_ID_H                     176
#define GPT_MODULE_ID_H                     100
#define GPT_AR_MAJOR_VER_H                  4
#define GPT_AR_MINOR_VER_H                  4
#define GPT_AR_PATCH_VER_H                  0
#define GPT_SW_MAJOR_VER_H                  1
#define GPT_SW_MINOR_VER_H                  0
#define GPT_SW_PATCH_VER_H                  1

/*============================================FILE VERSION CHECKS===================================*/

#if (GPT_VENDOR_ID_H != GPT_VENDOR_ID)
#error "NON-MATCHED DATA : GPT_CFG_VENDOR_ID"
#endif

#if (GPT_AR_MAJOR_VER_H != GPT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER"
#endif
#if (GPT_AR_MINOR_VER_H != GPT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER"
#endif
#if (GPT_AR_PATCH_VER_H != GPT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER"
#endif

#if (GPT_SW_MAJOR_VER_H != GPT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER"
#endif
#if (GPT_SW_MINOR_VER_H != GPT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER"
#endif
#if (GPT_SW_PATCH_VER_H != GPT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER"
#endif

/**
* @internal
* @brief RTC Channels defines
*/
#define     SECONDS_IN_A_DAY           (86400UL)
#define     SECONDS_IN_A_HOUR          (3600U)
#define     SECONDS_IN_A_MIN           (60U)
#define     MINS_IN_A_HOUR             (60U)
#define     HOURS_IN_A_DAY             (24U)
#define     DAYS_IN_A_YEAR             (365U)
#define     DAYS_IN_A_LEAP_YEAR        (366U)
#define     YEAR_RANGE_START           (1970U)
#define     YEAR_RANGE_END             (2099U)

typedef void (*RTC_Callback_Type)(void);

typedef void (*API_Callback_Type)(void);

/**
* @internal
* @brief   RTC Time Date structure
* @details RTCAPI_RTCTimedateType
*
*/
typedef struct
{
    VAR(uint16, AUTOMATIC)                  year;      /**< @brief Year       */
    VAR(uint16, AUTOMATIC)                  month;     /**< @brief Month      */
    VAR(uint16, AUTOMATIC)                  day;       /**< @brief Day        */
    VAR(uint16, AUTOMATIC)                  hour;      /**< @brief Hour       */
    VAR(uint16, AUTOMATIC)                  minutes;   /**< @brief Minutes    */
    VAR(uint8, AUTOMATIC)                   seconds;   /**< @brief Seconds    */
} RTCAPI_RTCTimedateType;

typedef enum
{
    RTCAPI_RTC = 0U,
    RTCAPI_API
} RTCAPI_ModuleID_Type;

typedef enum
{
    RTC_12BIT_COUNTER_MODE = 0U,
    RTC_LIFETIMER_MODE     = 1U,
    RTC_MODE_RESERVED      = 2U
} rtcapi_rtc_mode_t;

typedef enum
{
    RTCAPI_RTC_FALG  = 0U,
    RTCAPI_API_FALG  = 1U,
    RTCAPI_ROVR_FALG = 2U,
} rtcapi_flag_t;

typedef enum
{
    RTC_SIRC_CLK = 1U,
    RTC_FIRC_CLK = 2U,
} rtcapi_clk_t;

typedef enum
{
    RTC_DIV32 = 0,
    RTC_DIV512,
    RTC_DIV32_512,
    RTC_DIV0
} rtcapi_div_t;

typedef struct{
    VAR(boolean, AUTOMATIC) supervisorAccess;
    VAR(boolean, AUTOMATIC) prescaler512;
    VAR(boolean, AUTOMATIC) prescaler32;
    VAR(boolean, AUTOMATIC) freezeMode;
    VAR(rtcapi_clk_t, AUTOMATIC) clockType;
} rtcapi_module_t;

typedef struct{
    VAR(boolean, AUTOMATIC) prescaler512;
    VAR(boolean, AUTOMATIC) prescaler32;
    VAR(rtcapi_clk_t, AUTOMATIC) clockType;
    VAR(rtcapi_rtc_mode_t, AUTOMATIC) rtcMode;
    VAR(boolean, AUTOMATIC) APIEnable;
    VAR(uint32, AUTOMATIC) startTime;
    volatile VAR(uint32, AUTOMATIC) runoverTime;
} rtcapi_state_t;

FUNC(void, GPT_CODE) RTC_API_LLD_ClearAPIF(void);

FUNC(void, GPT_CODE) RTC_API_LLD_SetAPIIE(VAR(boolean, AUTOMATIC) enable);

FUNC(uint8, GPT_CODE) RTC_API_LLD_GetRTCF(void);

FUNC(void, GPT_CODE) RTC_API_LLD_SetRTCVAL(VAR(uint32, AUTOMATIC) u32Value);

FUNC(void, GPT_CODE) RTC_API_LLD_SetAPIVAL(VAR(uint32, AUTOMATIC) u32Value);

FUNC(void, GPT_CODE) RTC_API_LLD_ClearRTCF(void);

FUNC(void, GPT_CODE) RTC_API_LLD_SetRTCIE(VAR(boolean, AUTOMATIC) enable);

FUNC(void, GPT_CODE) RTC_API_LLD_SetAPIEN(VAR(boolean, AUTOMATIC) enable);

FUNC(uint32, GPT_CODE) RTC_API_LLD_GetRTCVAL(void);

FUNC(Std_ReturnType, GPT_CODE) RTCAPI_LLD_ModuleInit                \
(                                                                   \
    CONSTP2CONST(rtcapi_module_t, GPT_CONST, GPT_APPL_CONST) config \
);

FUNC(void, GPT_CODE) RTCAPI_LLD_RTCInit(void);

FUNC(void, GPT_CODE) RTCAPI_LLD_APIInit(void);

FUNC(void, GPT_CODE) RTCAPI_LLD_StartCounter(void);

FUNC(Std_ReturnType, GPT_CODE) RTCAPI_LLD_StopCounter(void);

FUNC(uint32, GPT_CODE) RTCAPI_LLD_GetRunTime(void);

FUNC(void, GPT_CODE) RTCAPI_LLD_DeInit(void);

FUNC(void, GPT_CODE) RTCAPI_LLD_APIIrqHandler(void);

FUNC(void, GPT_CODE) RTCAPI_LLD_RTCIrqHandler(void);

FUNC(Std_ReturnType, GPT_CODE) RTCAPI_LLD_RTCSetTimeDate                \
(                                                                       \
    P2CONST(RTCAPI_RTCTimedateType, AUTOMATIC, GPT_APPL_CONST) timeDate \
);

FUNC(void, GPT_CODE) RTCAPI_LLD_RTCGetTimeDate                             \
(                                                                          \
    CONSTP2VAR(RTCAPI_RTCTimedateType, AUTOMATIC, GPT_APPL_CONST) timeDate \
);

FUNC(void, GPT_CODE) RTCAPI_LLD_RTCConvertSecondsToTimeDate                \
(                                                                          \
    P2CONST(uint32, AUTOMATIC, GPT_APPL_CONST) seconds,                    \
    CONSTP2VAR(RTCAPI_RTCTimedateType, AUTOMATIC, GPT_APPL_CONST) timeDate \
);

FUNC(void, GPT_CODE) RTCAPI_LLD_RTCConvertTimeDateToSeconds              \
(                                                                        \
    P2CONST(RTCAPI_RTCTimedateType, AUTOMATIC, GPT_APPL_CONST) timeDate, \
    CONSTP2VAR(uint32, AUTOMATIC, GPT_APPL_CONST) seconds                \
);

#endif
