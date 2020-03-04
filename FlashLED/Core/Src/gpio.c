#include "gpio.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"



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
