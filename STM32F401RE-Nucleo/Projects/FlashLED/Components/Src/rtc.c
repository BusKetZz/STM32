#include "rtc.h"

#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_rtc.h"



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

#define RTC_SYNCH_PREDIV           ((uint32_t)0xF9)
#define RTC_ASYNCH_PREDIV          ((uint32_t)0x7F)


#define RTC_BKP_DATE_TIME_UPDATED ((uint32_t)0x32F2)



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

    LL_RTC_DateTypeDef RTC_DateStruct =
    {
      .WeekDay = LL_RTC_WEEKDAY_WEDNESDAY,
      .Month   = LL_RTC_MONTH_JANUARY,
      .Day     = 0x01,
      .Year    = 0x20
    };
    LL_RTC_DATE_Config(RTC, RTC_DateStruct.WeekDay, RTC_DateStruct.Day,
                       RTC_DateStruct.Month, RTC_DateStruct.Year);

    LL_RTC_TimeTypeDef RTC_TimeStruct =
    {
      .TimeFormat = LL_RTC_TIME_FORMAT_AM_OR_24,
      .Hours      = 0x12,
      .Minutes    = 0x00,
      .Seconds    = 0x00
    };
    LL_RTC_TIME_Config(RTC, RTC_TimeStruct.TimeFormat, RTC_TimeStruct.Hours,
                       RTC_TimeStruct.Minutes, RTC_TimeStruct.Seconds);

    LL_RTC_SetHourFormat(RTC, LL_RTC_HOURFORMAT_24HOUR);

    RTC_ExitInitMode();

    LL_RTC_EnableWriteProtection(RTC);

    LL_RTC_BAK_SetRegister(RTC, LL_RTC_BKP_DR0, RTC_BKP_DATE_TIME_UPDATED);
  }
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
