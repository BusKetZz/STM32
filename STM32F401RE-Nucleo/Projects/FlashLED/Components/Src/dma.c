#include "dma.h"
#include "usart.h"

#include "cmsis_os2.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_dma.h"

#include <string.h>



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

#define DMA2_BUFFER_SIZE 8

#define LED2TASK_QUEUE_MESSAGES_COUNT (uint32_t)1

#define MAGIC_FOUND 0
#define MAGIC_NOT_FOUND -1

#define PART_OF_MAGIC_FOUND MAGIC_FOUND

#define CONFIGURATION_BYTES_COUNT 2



/*****************************************************************************/
/*                             PRIVATE MACROS                                */
/*****************************************************************************/

#define ARRAY_LENGTH(x)    (sizeof(x) / sizeof((x)[0]))



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

static uint8_t dma2Usart1RxBuffer[DMA2_BUFFER_SIZE];

static const char *MAGIC_WORD = "ABCD";

static osMessageQueueId_t queueHandleForLed2Task;



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DECLARATIONS                        */
/*****************************************************************************/

static int GetCurrentPositionInDma2Usart1RxBuffer(void);
static int UpdateLed2BufferAndPosition(const int magicWordLength,
                                       uint8_t *led2UpdatedBlinksCount,
                                       int positionIndex);


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

  LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_2);
}



osMessageQueueId_t GetQueueHandleForLed2Task(void)
{
  return queueHandleForLed2Task;
}



/*****************************************************************************/
/*                         RTOS TASK DEFINITION                              */
/*****************************************************************************/

void StartDma2Usart1RxTask(void *argument)
{
  int oldPosition = 0;
  int currentPosition = 0;
  const int magicWordLength = strlen(MAGIC_WORD);
  int isMagicFound = MAGIC_NOT_FOUND;
  uint8_t led2UpdatedBlinksCount[2] = {0};

  queueHandleForLed2Task = osMessageQueueNew(LED2TASK_QUEUE_MESSAGES_COUNT, 
                                      sizeof(led2UpdatedBlinksCount), NULL);

  for(;;)
  {
    currentPosition = GetCurrentPositionInDma2Usart1RxBuffer();
    if(currentPosition != oldPosition)
    {
      while(isMagicFound == MAGIC_NOT_FOUND)
      {
        if((ARRAY_LENGTH(dma2Usart1RxBuffer)-oldPosition) >= magicWordLength)
        {
          isMagicFound = memcmp(dma2Usart1RxBuffer + oldPosition, MAGIC_WORD,
                                magicWordLength);
          if(isMagicFound == MAGIC_FOUND)
          {
            oldPosition = UpdateLed2BufferAndPosition(magicWordLength,
                                                      led2UpdatedBlinksCount,
                                                      oldPosition);
            break;
          }
        }
        else if((ARRAY_LENGTH(dma2Usart1RxBuffer) - oldPosition) != 0)
        {
          size_t offset = ARRAY_LENGTH(dma2Usart1RxBuffer) - oldPosition;
          int isPartOfMagicFound = MAGIC_NOT_FOUND;
          isPartOfMagicFound = memcmp(dma2Usart1RxBuffer + oldPosition, MAGIC_WORD,
                                      offset);
          if(isPartOfMagicFound == PART_OF_MAGIC_FOUND)
          {
            size_t leftBytes = magicWordLength - offset;
            isMagicFound = memcmp(dma2Usart1RxBuffer, MAGIC_WORD + offset,
                                  leftBytes);
            if(isMagicFound == MAGIC_FOUND)
            {
              oldPosition = leftBytes;
              oldPosition = UpdateLed2BufferAndPosition(0, led2UpdatedBlinksCount,
                                                        oldPosition);
              break;
            }
          }
        }
        
        oldPosition++;
        if(oldPosition == ARRAY_LENGTH(dma2Usart1RxBuffer))
          oldPosition = 0;
      }
    }

    if(isMagicFound == MAGIC_FOUND)
      osMessageQueuePut(queueHandleForLed2Task, led2UpdatedBlinksCount, 0, 0);
      
    isMagicFound = MAGIC_NOT_FOUND;

    osDelay(1);
  }
}



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DEFINITIONS                         */
/*****************************************************************************/

static int GetCurrentPositionInDma2Usart1RxBuffer(void)
{
  return ARRAY_LENGTH(dma2Usart1RxBuffer) - 
         LL_DMA_GetDataLength(DMA2, LL_DMA_STREAM_2);
}



static int UpdateLed2BufferAndPosition(const int magicWordLength,
                                       uint8_t *led2UpdatedBlinksCount,
                                       int positionIndex)
{
  int newPosition = positionIndex + magicWordLength;
  if(ARRAY_LENGTH(dma2Usart1RxBuffer) - newPosition == 1)
  {
    led2UpdatedBlinksCount[0] = dma2Usart1RxBuffer[newPosition];
    newPosition = 0;
    led2UpdatedBlinksCount[1] = dma2Usart1RxBuffer[newPosition++];
  }
  else if(ARRAY_LENGTH(dma2Usart1RxBuffer) - newPosition == 0)
  {
    newPosition = 0;
    led2UpdatedBlinksCount[0] = dma2Usart1RxBuffer[newPosition++];
    led2UpdatedBlinksCount[1] = dma2Usart1RxBuffer[newPosition++];
  }
  else
  {
    led2UpdatedBlinksCount[0] = dma2Usart1RxBuffer[newPosition++];
    led2UpdatedBlinksCount[1] = dma2Usart1RxBuffer[newPosition++];
  }

  return newPosition;
}
