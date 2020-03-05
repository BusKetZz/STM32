#include "gpio.h"

#include "stm32f4xx.h"
#include "stm32f401xe.h"

#include "stm32f4xx_ll_gpio.h"



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void GPIOA_Clock_Config(void)
{
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
}



void GPIOA_LED2_Config(void)
{
  SET_BIT(GPIOA->MODER, (1 << 10));
  CLEAR_BIT(GPIOA->OSPEEDR, (3 << 10));
  CLEAR_BIT(GPIOA->PUPDR, (3 << 10));
}



void GPIOA_USART1_RX_Config(void)
{
  /*
    PA10 ---> USART1_RX
  */
  LL_GPIO_InitTypeDef GPIOA_USART1_RX_InitStructure =
  {
    .Pin = LL_GPIO_PIN_10,
    .Mode = LL_GPIO_MODE_ALTERNATE,
    .Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH,
    .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
    .Pull = LL_GPIO_PULL_NO,
    .Alternate = LL_GPIO_AF_7
  };

  LL_GPIO_Init(GPIOA, &GPIOA_USART1_RX_InitStructure);
}
