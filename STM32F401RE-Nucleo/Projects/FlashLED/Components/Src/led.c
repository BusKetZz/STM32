#include "led.h"

#include "cmsis_os.h"

#include "stm32f4xx_ll_gpio.h"



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
/*****************************************************************************/

#define LED2_Pin         LL_GPIO_PIN_5
#define LED2_GPIO_Port   GPIOA

#define LONG_BLINKS_AMOUNT_DEFAULT 3
#define SHORT_BLINKS_AMOUNT_DEFAULT 7

#define LONG_DELAY_MS 1000
#define SHORT_DELAY_MS 250



/*****************************************************************************/
/*                             PRIVATE MACROS                                */
/*****************************************************************************/

#define LED2_ON()  LL_GPIO_SetOutputPin(LED2_GPIO_Port, LED2_Pin)
#define LED2_OFF() LL_GPIO_ResetOutputPin(LED2_GPIO_Port, LED2_Pin)



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

static uint8_t longBlinksAmount  = LONG_BLINKS_AMOUNT_DEFAULT;
static uint8_t shortBlinksAmount = SHORT_BLINKS_AMOUNT_DEFAULT;



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void LED2_UpdateBlinkPattern(const uint8_t newLongBlinksAmount, 
                             const uint8_t newShortBlinksAmount)
{
  longBlinksAmount = newLongBlinksAmount;
  shortBlinksAmount = newShortBlinksAmount;
}



/*****************************************************************************/
/*                         RTOS TASK DEFINITION                              */
/*****************************************************************************/

void StartLed2Task(void *argument)
{
  uint32_t longBlinksCount;
  uint32_t shortBlinksCount;

  LED2_OFF();

  for(;;)
  {
    longBlinksCount = longBlinksAmount;
    shortBlinksCount = shortBlinksAmount;

    for(uint32_t longBlinks=0; longBlinks < longBlinksCount; longBlinks++)
    {
      LED2_ON();
      osDelay(LONG_DELAY_MS);
      LED2_OFF();
      osDelay(LONG_DELAY_MS);
    }

    for(uint32_t shortBlinks=0; shortBlinks < shortBlinksCount; shortBlinks++)
    {
      LED2_ON();
      osDelay(SHORT_DELAY_MS);
      LED2_OFF();
      osDelay(SHORT_DELAY_MS);
    }

    osDelay(LONG_DELAY_MS);
  }

  osThreadTerminate(NULL);
}
