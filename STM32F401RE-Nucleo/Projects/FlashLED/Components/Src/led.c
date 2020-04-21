#include "dma.h"
#include "led.h"

#include "cmsis_os.h"

#include "stm32f4xx_ll_gpio.h"



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
/*****************************************************************************/

#define LED2_Pin         LL_GPIO_PIN_5
#define LED2_GPIO_Port   GPIOA

#define LONG_BLINKS_COUNT_DEFAULT  3
#define SHORT_BLINKS_COUNT_DEFAULT 7

#define LONG_BLINKS_INDEX  0
#define SHORT_BLINKS_INDEX 1

#define SHORT_DELAY_MS 200
#define LONG_DELAY_MS  (3 * SHORT_DELAY_MS)



/*****************************************************************************/
/*                             PRIVATE MACROS                                */
/*****************************************************************************/

#define LED2_ON()  LL_GPIO_SetOutputPin(LED2_GPIO_Port, LED2_Pin)
#define LED2_OFF() LL_GPIO_ResetOutputPin(LED2_GPIO_Port, LED2_Pin)



/*****************************************************************************/
/*                         RTOS TASK DEFINITION                              */
/*****************************************************************************/

void StartLed2Task(void *argument)
{
  uint8_t blinksCount[2] = {[LONG_BLINKS_INDEX] = LONG_BLINKS_COUNT_DEFAULT,
                            [SHORT_BLINKS_INDEX] = SHORT_BLINKS_COUNT_DEFAULT};
  uint8_t newBlinksCount[2];
  osStatus_t foundNewCounts = osError;

  LED2_OFF();

  for(;;)
  {
    foundNewCounts = osMessageQueueGet(GetQueueHandleForLed2Task(), 
                                       newBlinksCount, NULL, 1000);
    if(foundNewCounts == osOK)
    {
      blinksCount[LONG_BLINKS_INDEX] = newBlinksCount[LONG_BLINKS_INDEX];
      blinksCount[SHORT_BLINKS_INDEX] = newBlinksCount[SHORT_BLINKS_INDEX];
    }

    for(uint8_t longBlinks = 0; longBlinks < blinksCount[LONG_BLINKS_INDEX];
        longBlinks++)
    {
      LED2_ON();
      osDelay(LONG_DELAY_MS);
      LED2_OFF();
      osDelay(LONG_DELAY_MS);
    }

    for(uint8_t shortBlinks = 0; shortBlinks < blinksCount[SHORT_BLINKS_INDEX]; 
        shortBlinks++)
    {
      LED2_ON();
      osDelay(SHORT_DELAY_MS);
      LED2_OFF();
      osDelay(SHORT_DELAY_MS);
    }

    osDelay(500);
  }

  osThreadTerminate(NULL);
}
