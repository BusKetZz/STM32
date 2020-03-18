#include "gpio.h"

#include "stm32f4xx.h"
#include "stm32f401xe.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
/*****************************************************************************/

#define LED2_Pin         LL_GPIO_PIN_5
#define LED2_GPIO_Port   GPIOA

#define USART1_RX_Pin      LL_GPIO_PIN_10
#define USART1_TX_Pin      LL_GPIO_PIN_9
#define USART1_GPIO_Port   GPIOA



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void GPIOA_Clock_Config(void)
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
}



void GPIOA_LED2_Config(void)
{
  LL_GPIO_ResetOutputPin(LED2_GPIO_Port, LED2_Pin);

  LL_GPIO_InitTypeDef LED2_GPIO_InitStruct =
  {
    .Pin = LED2_Pin,
    .Mode = LL_GPIO_MODE_OUTPUT,
    .Speed = LL_GPIO_SPEED_FREQ_LOW,
    .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
    .Pull = LL_GPIO_PULL_NO
  };
  LL_GPIO_Init(LED2_GPIO_Port, &LED2_GPIO_InitStruct);
}



void GPIOA_USART1_TX_RX_Config(void)
{
  /*
    PA9  ---> USART1_TX
    PA10 ---> USART1_RX
  */
  LL_GPIO_InitTypeDef USART1_TX_RX_GPIO_InitStruct =
  {
    .Pin = USART1_TX_Pin | USART1_RX_Pin,
    .Mode = LL_GPIO_MODE_ALTERNATE,
    .Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH,
    .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
    .Pull = LL_GPIO_PULL_NO,
    .Alternate = LL_GPIO_AF_7
  };

  LL_GPIO_Init(USART1_GPIO_Port, &USART1_TX_RX_GPIO_InitStruct);
}
