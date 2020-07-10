#include "gpio.h"

#include "stm32f4xx.h"
#include "stm32f401xe.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
/*****************************************************************************/

#define ADC1_IN0_GPIO_PIN       LL_GPIO_PIN_0
#define ADC1_IN0_GPIO_PORT      GPIOA

#define RELAY_HEATER_GPIO_PIN   LL_GPIO_PIN_8
#define RELAY_HEATER_GPIO_PORT  GPIOA

#define LED2_GPIO_PIN           LL_GPIO_PIN_5
#define LED2_GPIO_PORT          GPIOA

#define USART1_RX_GPIO_PIN      LL_GPIO_PIN_10
#define USART1_TX_GPIO_PIN      LL_GPIO_PIN_9
#define USART1_GPIO_PORT        GPIOA



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void GPIOA_Clock_Config(void)
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
}



void GPIOA_TEMPERATURE_REGULATOR_Config(void)
{
  LL_GPIO_InitTypeDef ADC1_GPIO_ReadTemperature_InitStruct =
  {
    .Pin  = ADC1_IN0_GPIO_PIN,
    .Mode = LL_GPIO_MODE_ANALOG,
    .Pull = LL_GPIO_PULL_NO 
  };
  LL_GPIO_Init(ADC1_IN0_GPIO_PORT, &ADC1_GPIO_ReadTemperature_InitStruct);

  LL_GPIO_InitTypeDef RelayHeater_GPIO_InitStruct =
  {
    .Pin        = RELAY_HEATER_GPIO_PIN,
    .Mode       = LL_GPIO_MODE_OUTPUT,
    .Speed      = LL_GPIO_SPEED_FREQ_LOW,
    .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
    .Pull       = LL_GPIO_PULL_NO
  };
  LL_GPIO_Init(RELAY_HEATER_GPIO_PORT, &RelayHeater_GPIO_InitStruct);
}



void GPIOA_LED2_Config(void)
{
  LL_GPIO_ResetOutputPin(LED2_GPIO_PORT, LED2_GPIO_PIN);

  LL_GPIO_InitTypeDef LED2_GPIO_InitStruct =
  {
    .Pin = LED2_GPIO_PIN,
    .Mode = LL_GPIO_MODE_OUTPUT,
    .Speed = LL_GPIO_SPEED_FREQ_LOW,
    .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
    .Pull = LL_GPIO_PULL_NO
  };
  LL_GPIO_Init(LED2_GPIO_PORT, &LED2_GPIO_InitStruct);
}



void GPIOA_USART1_TX_RX_Config(void)
{
  /*
    PA9  ---> USART1_TX
    PA10 ---> USART1_RX
  */
  LL_GPIO_InitTypeDef USART1_TX_RX_GPIO_InitStruct =
  {
    .Pin = USART1_TX_GPIO_PIN | USART1_RX_GPIO_PIN,
    .Mode = LL_GPIO_MODE_ALTERNATE,
    .Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH,
    .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
    .Pull = LL_GPIO_PULL_NO,
    .Alternate = LL_GPIO_AF_7
  };

  LL_GPIO_Init(USART1_GPIO_PORT, &USART1_TX_RX_GPIO_InitStruct);
}
