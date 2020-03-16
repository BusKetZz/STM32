#include "rtc.h"

#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_rtc.h"



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

#define RTC_BKP_DATE_TIME_UPDATED ((uint32_t)0x32F2)



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

  LL_RCC_ForceBackupDomainReset();
  LL_RCC_ReleaseBackupDomainReset();
  LL_RCC_SetRTCClockSource(LL_RCC_RTC_CLKSOURCE_LSI);
  LL_RCC_EnableRTC();
}



void RTC_Settings_Config(void)
{
  LL_RTC_InitTypeDef RTC_InitStruct =
  {
    .HourFormat = LL_RTC_HOURFORMAT_24HOUR,
    .AsynchPrescaler = 127,
    .SynchPrescaler = 255
  };
  LL_RTC_Init(RTC, &RTC_InitStruct);

  if(LL_RTC_BAK_GetRegister(RTC, LL_RTC_BKP_DR0) != RTC_BKP_DATE_TIME_UPDATED)
  {
    LL_RTC_TimeTypeDef RTC_TimeStruct =
    {
      .Hours = 0,
      .Minutes = 0,
      .Seconds = 0
    };
    LL_RTC_TIME_Init(RTC, LL_RTC_FORMAT_BCD, &RTC_TimeStruct);

    LL_RTC_DateTypeDef RTC_DateStruct =
    {
      .WeekDay = LL_RTC_WEEKDAY_MONDAY,
      .Month = LL_RTC_MONTH_MARCH,
      .Year = 20
    };
    LL_RTC_DATE_Init(RTC, LL_RTC_FORMAT_BCD, &RTC_DateStruct);

    LL_RTC_BAK_SetRegister(RTC, LL_RTC_BKP_DR0, RTC_BKP_DATE_TIME_UPDATED);
  }
}
