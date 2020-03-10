#include "dma.h"
#include "usart.h"

#include "stm32f401xe.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_dma.h"



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

#define FRAME_SIZE 6



/*****************************************************************************/
/*                             PRIVATE MACROS                                */
/*****************************************************************************/

#define ARRAY_LENGTH(x)    (sizeof(x) / sizeof((x)[0]))



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

static uint8_t dma2Usart1RxBuffer[FRAME_SIZE];



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void DMA2_Clock_Config(void)
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);
}



void DMA2_USART1_RX_Config(void)
{
  LL_DMA_SetChannelSelection(DMA2, LL_DMA_STREAM_2, LL_DMA_CHANNEL_4);
  LL_DMA_SetDataTransferDirection(DMA2, LL_DMA_STREAM_2,
                                  LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  LL_DMA_SetStreamPriorityLevel(DMA2, LL_DMA_STREAM_2, LL_DMA_PRIORITY_LOW);
  LL_DMA_SetMode(DMA2, LL_DMA_STREAM_2, LL_DMA_MODE_CIRCULAR);
  LL_DMA_SetPeriphIncMode(DMA2, LL_DMA_STREAM_2, LL_DMA_PERIPH_NOINCREMENT);
  LL_DMA_SetMemoryIncMode(DMA2, LL_DMA_STREAM_2, LL_DMA_MEMORY_INCREMENT);
  LL_DMA_SetPeriphSize(DMA2, LL_DMA_STREAM_2, LL_DMA_PDATAALIGN_BYTE);
  LL_DMA_SetMemorySize(DMA2, LL_DMA_STREAM_2, LL_DMA_MDATAALIGN_BYTE);
  LL_DMA_DisableFifoMode(DMA2, LL_DMA_STREAM_2);

  LL_DMA_SetPeriphAddress(DMA2, LL_DMA_STREAM_2, (uint32_t)&USART1->DR);
  LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_2, (uint32_t)dma2Usart1RxBuffer);
  LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_2, ARRAY_LENGTH(dma2Usart1RxBuffer));

  LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_2);

  LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_2);
}



void DMA2_USART1_RX_NVIC_Config(void)
{
  NVIC_SetPriority(DMA2_Stream2_IRQn, 
                   NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(DMA2_Stream2_IRQn);
}



void DMA2_Stream2_IRQHandler(void)
{
  if(LL_DMA_IsEnabledIT_TC(DMA2, LL_DMA_STREAM_2) && 
     LL_DMA_IsActiveFlag_TC2(DMA2))
  {
    LL_DMA_ClearFlag_TC2(DMA2);
    USART1_RX_ProcessData(dma2Usart1RxBuffer);
  }
}
