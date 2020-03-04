#include "led.h"

#include "FreeRTOS.h"
#include "task.h"

#include "stm32f4xx.h"
#include "stm32f401xe.h"



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
/*****************************************************************************/

#define LONG_DELAY_MS 1000
#define SHORT_DELAY_MS 250



/*****************************************************************************/
/*                             PRIVATE MACROS                                */
/*****************************************************************************/

#define LED2_ON()  SET_BIT(GPIOA->BSRR, (1 << 5))
#define LED2_OFF() SET_BIT(GPIOA->BSRR, (1 << 21))



/*****************************************************************************/
/*                            FreeRTOS TASK                                  */
/*****************************************************************************/

void vLEDTask(void *pvParameters)
{
  uint8_t longBlinkAmount = 3;
  uint8_t shortBlinkAmount = 7;

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
