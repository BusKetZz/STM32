#include "led.h"
#include "usart.h"

#include "stm32f401xe.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_usart.h"



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void USART1_Clock_Config(void)
{
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);
}



void USART1_RX_Config(void)
{
  LL_USART_InitTypeDef USART1_RX_InitStructure =
  {
    .BaudRate = 115200,
    .DataWidth = LL_USART_DATAWIDTH_8B,
    .StopBits = LL_USART_STOPBITS_1,
    .Parity = LL_USART_PARITY_NONE,
    .TransferDirection = LL_USART_DIRECTION_RX,
    .HardwareFlowControl = LL_USART_HWCONTROL_NONE,
    .OverSampling = LL_USART_OVERSAMPLING_16
  };

  LL_USART_Init(USART1, &USART1_RX_InitStructure);
  LL_USART_ConfigAsyncMode(USART1);
  LL_USART_EnableDMAReq_RX(USART1);

  LL_USART_Enable(USART1);
}
