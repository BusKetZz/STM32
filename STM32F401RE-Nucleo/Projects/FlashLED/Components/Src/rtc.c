#include "rtc.h"

#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_rtc.h"

#include <time.h>



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

#define RTC_SYNCH_PREDIV           ((uint32_t)127)
#define RTC_ASYNCH_PREDIV          ((uint32_t)255)

#define RTC_BKP_DATE_TIME_UPDATED ((uint32_t)0x32F2)

#define EPOCH_OFFSET 100



/*****************************************************************************/
/*                       PRIVATE FUNCTIONS PROTOTYPES                        */
/*****************************************************************************/

static void RTC_EnterInitMode(void);
static void RTC_ExitInitMode(void);



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void RTC_Clock_Config(void)
{
  LL_PWR_EnableBkUpAccess();

  LL_RCC_LSE_Enable();
  while(LL_RCC_LSE_IsReady() != 1)
  {
    
  }

  if(LL_RCC_GetRTCClockSource() != LL_RCC_RTC_CLKSOURCE_LSE)
  {
    LL_RCC_ForceBackupDomainReset();
    LL_RCC_ReleaseBackupDomainReset();
    LL_RCC_SetRTCClockSource(LL_RCC_RTC_CLKSOURCE_LSE);
  }

  LL_RCC_EnableRTC();
}



void RTC_InitialSettings_Config(void)
{
  if(LL_RTC_BAK_GetRegister(RTC, LL_RTC_BKP_DR0) != RTC_BKP_DATE_TIME_UPDATED)
  {
    LL_RTC_DisableWriteProtection(RTC);

    RTC_EnterInitMode();

    LL_RTC_SetSynchPrescaler(RTC, RTC_SYNCH_PREDIV);
    LL_RTC_SetAsynchPrescaler(RTC, RTC_ASYNCH_PREDIV);

    LL_RTC_DateTypeDef rtcDateStruct =
    {
      .WeekDay = LL_RTC_WEEKDAY_MONDAY,
      .Month   = LL_RTC_MONTH_APRIL,
      .Day     = 0x20,
      .Year    = 0x20
    };
    LL_RTC_DATE_Config(RTC, rtcDateStruct.WeekDay, rtcDateStruct.Day,
                       rtcDateStruct.Month, rtcDateStruct.Year);

    LL_RTC_TimeTypeDef rtcTimeStruct =
    {
      .TimeFormat = LL_RTC_TIME_FORMAT_AM_OR_24,
      .Hours      = 0x18,
      .Minutes    = 0x0,
      .Seconds    = 0x0
    };
    LL_RTC_TIME_Config(RTC, rtcTimeStruct.TimeFormat, rtcTimeStruct.Hours,
                       rtcTimeStruct.Minutes, rtcTimeStruct.Seconds);

    LL_RTC_SetHourFormat(RTC, LL_RTC_HOURFORMAT_24HOUR);

    RTC_ExitInitMode();

    LL_RTC_EnableWriteProtection(RTC);

    LL_RTC_BAK_SetRegister(RTC, LL_RTC_BKP_DR0, RTC_BKP_DATE_TIME_UPDATED);
  }
}



time_t RTC_GetTimeInSeconds(void)
{
  LL_RTC_TimeTypeDef rtcTimeStruct =
  {
    .Hours   = LL_RTC_TIME_GetHour(RTC),
    .Minutes = LL_RTC_TIME_GetMinute(RTC),
    .Seconds = LL_RTC_TIME_GetSecond(RTC) 
  };

  LL_RTC_DateTypeDef rtcDateStruct =
  {
    .WeekDay = LL_RTC_DATE_GetWeekDay(RTC),
    .Month   = LL_RTC_DATE_GetMonth(RTC),
    .Day     = LL_RTC_DATE_GetDay(RTC),
    .Year    = LL_RTC_DATE_GetYear(RTC)
  };

  struct tm timeDataFromRTC =
  {
    .tm_wday = __LL_RTC_CONVERT_BCD2BIN(rtcDateStruct.WeekDay),
    .tm_mday = __LL_RTC_CONVERT_BCD2BIN(rtcDateStruct.Day),
    .tm_mon  = __LL_RTC_CONVERT_BCD2BIN(rtcDateStruct.Month) - 1,
    .tm_year = __LL_RTC_CONVERT_BCD2BIN(rtcDateStruct.Year) + EPOCH_OFFSET,
    .tm_hour = __LL_RTC_CONVERT_BCD2BIN(rtcTimeStruct.Hours),
    .tm_min  = __LL_RTC_CONVERT_BCD2BIN(rtcTimeStruct.Minutes),
    .tm_sec  = __LL_RTC_CONVERT_BCD2BIN(rtcTimeStruct.Seconds)
  };

  return mktime(&timeDataFromRTC);
}



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DEFINITIONS                         */
/*****************************************************************************/

static void RTC_EnterInitMode(void)
{
  LL_RTC_EnableInitMode(RTC);

  while(LL_RTC_IsActiveFlag_INIT(RTC) != 1)
  {

  }
}



static void RTC_ExitInitMode(void)
{
  LL_RTC_DisableInitMode(RTC);

  LL_RTC_WaitForSynchro(RTC);
}
