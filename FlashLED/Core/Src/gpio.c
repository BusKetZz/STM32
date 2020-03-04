#include "gpio.h"

#include "stm32f4xx.h"
#include "stm32f401xe.h"



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void GPIOA_ClockConfig(void)
{
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
}



void GPIOA_LED2_Config(void)
{
  SET_BIT(GPIOA->MODER, (1 << 10));
  CLEAR_BIT(GPIOA->OSPEEDR, (3 << 10));
  CLEAR_BIT(GPIOA->PUPDR, (3 << 10));
}
