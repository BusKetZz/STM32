#include "led.h"

#include "FreeRTOS.h"
#include "task.h"

#include "stm32f4xx.h"
#include "stm32f401xe.h"



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
/*****************************************************************************/

#define LONG_BLINK_AMOUNT_DEFAULT 3
#define SHORT_BLINK_AMOUNT_DEFAULT 7

#define LONG_DELAY_MS 1000
#define SHORT_DELAY_MS 250



/*****************************************************************************/
/*                             PRIVATE MACROS                                */
/*****************************************************************************/

#define LED2_ON()  SET_BIT(GPIOA->BSRR, (1 << 5))
#define LED2_OFF() SET_BIT(GPIOA->BSRR, (1 << 21))



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

static uint8_t longBlinkAmount  = LONG_BLINK_AMOUNT_DEFAULT;
static uint8_t shortBlinkAmount = SHORT_BLINK_AMOUNT_DEFAULT;



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void LED2_UpdateBlinkPattern(const uint8_t newLongBlinksAmount, 
                             const uint8_t newShortBlinksAmount)
{
  longBlinkAmount = newLongBlinksAmount;
  shortBlinkAmount = newShortBlinksAmount;
}



/*****************************************************************************/
/*                            FreeRTOS TASK                                  */
/*****************************************************************************/

void vLEDTask(void *pvParameters)
{
  LED2_OFF();

  for(;;)
  {
    for(uint8_t longBlinkCounter = 0; longBlinkCounter < longBlinkAmount;
        longBlinkCounter++)
    {
      LED2_ON();
      vTaskDelay(LONG_DELAY_MS / portTICK_RATE_MS);
      LED2_OFF();
      vTaskDelay(LONG_DELAY_MS / portTICK_RATE_MS);
    }

    for(uint8_t shortBlinkCounter = 0; shortBlinkCounter < shortBlinkAmount;
        shortBlinkCounter++)
    {
      LED2_ON();
      vTaskDelay(SHORT_DELAY_MS / portTICK_RATE_MS);
      LED2_OFF();
      vTaskDelay(SHORT_DELAY_MS / portTICK_RATE_MS);
    }

    vTaskDelay(LONG_DELAY_MS / portTICK_RATE_MS);
  }

  vTaskDelete(NULL);
}
