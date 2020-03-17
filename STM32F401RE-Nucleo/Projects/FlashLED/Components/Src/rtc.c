#include "rtc.h"

#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_rtc.h"

#include <time.h>



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

#define RTC_SYNCH_PREDIV           ((uint32_t)0xF9)
#define RTC_ASYNCH_PREDIV          ((uint32_t)0x7F)

#define RTC_BKP_DATE_TIME_UPDATED ((uint32_t)0x32F2)

#define EPOCH_OFFSET 100



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DECLARATIONS                        */
/*****************************************************************************/

static void RTC_EnterInitMode(void);
static void RTC_ExitInitMode(void);



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void RTC_Clock_Config(void)
{
  LL_PWR_EnableBkUpAccess();

  LL_RCC_LSI_Enable();
  while(LL_RCC_LSI_IsReady() != 1)
  {
    
  }

  if(LL_RCC_GetRTCClockSource() != LL_RCC_RTC_CLKSOURCE_LSI)
  {
    LL_RCC_ForceBackupDomainReset();
    LL_RCC_ReleaseBackupDomainReset();
    LL_RCC_SetRTCClockSource(LL_RCC_RTC_CLKSOURCE_LSI);
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
      .WeekDay = LL_RTC_WEEKDAY_WEDNESDAY,
      .Month   = LL_RTC_MONTH_JANUARY,
      .Day     = 0x01,
      .Year    = 0x20
    };
    LL_RTC_DATE_Config(RTC, rtcDateStruct.WeekDay, rtcDateStruct.Day,
                       rtcDateStruct.Month, rtcDateStruct.Year);

    LL_RTC_TimeTypeDef rtcTimeStruct =
    {
      .TimeFormat = LL_RTC_TIME_FORMAT_AM_OR_24,
      .Hours      = 0x12,
      .Minutes    = 0x00,
      .Seconds    = 0x00
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
    .tm_wday = rtcDateStruct.WeekDay,
    .tm_mday = rtcDateStruct.Day,
    .tm_mon  = rtcDateStruct.Month - 1,
    .tm_year = rtcDateStruct.Year + EPOCH_OFFSET,
    .tm_hour = rtcTimeStruct.Hours,
    .tm_min  = rtcTimeStruct.Minutes,
    .tm_sec  = rtcTimeStruct.Seconds
  };

  time_t timeInSeconds = mktime(&timeDataFromRTC);

  return timeInSeconds;
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
