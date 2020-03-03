#include "gpio.h"

#include "FreeRTOS.h"
#include "task.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
/*****************************************************************************/

#define LONG_DELAY_MS 1000
#define SHORT_DELAY_MS 250

#define LED_ON(GPIOx,GPIO_PIN_x) HAL_GPIO_WritePin(GPIOx, GPIO_PIN_x, GPIO_PIN_SET)
#define LED_OFF(GPIOx,GPIO_PIN_x) HAL_GPIO_WritePin(GPIOx, GPIO_PIN_x, GPIO_PIN_RESET)


/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void GPIOA_ClockConfig(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
}



void GPIOA_LED2_Config(void)
{
  GPIO_InitTypeDef gpioA;
  gpioA.Pin = GPIO_PIN_5;
  gpioA.Mode = GPIO_MODE_OUTPUT_PP;
  gpioA.Pull = GPIO_NOPULL;
  gpioA.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &gpioA);
}



/*****************************************************************************/
/*                            FreeRTOS TASK                                  */
/*****************************************************************************/

void vLEDTask(void *pvParameters)
{
  uint8_t longBlinkAmount = 3;
  uint8_t shortBlinkAmount = 7;

  LED_OFF(GPIOA, GPIO_PIN_5);

  for(;;)
  {
    for(uint8_t longBlinkCounter = 0; longBlinkCounter < longBlinkAmount;
        longBlinkCounter++)
    {
      LED_ON(GPIOA, GPIO_PIN_5);
      vTaskDelay(LONG_DELAY_MS / portTICK_RATE_MS);
      LED_OFF(GPIOA, GPIO_PIN_5);
      vTaskDelay(LONG_DELAY_MS / portTICK_RATE_MS);
    }

    for(uint8_t shortBlinkCounter = 0; shortBlinkCounter < shortBlinkAmount;
        shortBlinkCounter++)
    {
      LED_ON(GPIOA, GPIO_PIN_5);
      vTaskDelay(SHORT_DELAY_MS / portTICK_RATE_MS);
      LED_OFF(GPIOA, GPIO_PIN_5);
      vTaskDelay(SHORT_DELAY_MS / portTICK_RATE_MS);
    }

    vTaskDelay(LONG_DELAY_MS / portTICK_RATE_MS);
  }

  vTaskDelete(NULL);
}
