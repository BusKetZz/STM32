#include "dma.h"
#include "rtc.h"
#include "usart.h"

#include "cmsis_os2.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_dma.h"

#include <string.h>



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

#define DMA2_BUFFER_SIZE 32

#define MAGIC_WORD_LENGTH  4
#define CONFIG_BYTES_COUNT 2

#define LED2TASK_QUEUE_MESSAGES_COUNT (uint32_t)1



/*****************************************************************************/
/*                             PRIVATE MACROS                                */
/*****************************************************************************/

#define ARRAY_LENGTH(x)    (sizeof(x) / sizeof((x)[0]))



/*****************************************************************************/
/*                             PRIVATE ENUMS                                 */
/*****************************************************************************/

typedef enum isMagicFound_t
{
  Magic_Found = 0,
  Magic_NotFound = -1,
}Magic_t;



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

static uint8_t dma2Usart1RxBuffer[DMA2_BUFFER_SIZE];

static const char MAGIC_WORD[MAGIC_WORD_LENGTH + 1] = "ABCD";

static osMessageQueueId_t queueHandleForLed2Task;



/*****************************************************************************/
/*                           PRIVATE STRUCTURES                              */
/*****************************************************************************/

static struct __attribute__((packed))
{
  char magicWord[MAGIC_WORD_LENGTH + 1];
  time_t rtcTime;
}feedbackMessage;



/*****************************************************************************/
/*                      PRIVATE FUNCTIONS PROTOTYPES                         */
/*****************************************************************************/

static size_t GetCurrentPositionInDma2Usart1RxBuffer(void);
static size_t CountBytesLeftToCheck(size_t currentPosition,
                                    size_t oldPosition);
static Magic_t FindMagic(size_t dma2BufferOffset, size_t magicWordOffset,
                         size_t magicWordLength); 
static size_t UpdateLed2BufferAndPosition(uint8_t *led2UpdatedBlinksCount,
                                          size_t positionIndex,
                                          size_t magicWordLength);
static void InitializeFeedbackMessage(void);
static void FeedbackMessageUpdateTime(void);



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



void DMA2_USART1_TX_Config(void)
{
  LL_DMA_SetChannelSelection(DMA2, LL_DMA_STREAM_7, LL_DMA_CHANNEL_4);
  LL_DMA_SetDataTransferDirection(DMA2, LL_DMA_STREAM_7, 
                                  LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
  LL_DMA_SetStreamPriorityLevel(DMA2, LL_DMA_STREAM_7, LL_DMA_PRIORITY_LOW);
  LL_DMA_SetMode(DMA2, LL_DMA_STREAM_7, LL_DMA_MODE_NORMAL);
  LL_DMA_SetPeriphIncMode(DMA2, LL_DMA_STREAM_7, LL_DMA_PERIPH_NOINCREMENT);
  LL_DMA_SetMemoryIncMode(DMA2, LL_DMA_STREAM_7, LL_DMA_MEMORY_INCREMENT);
  LL_DMA_SetPeriphSize(DMA2, LL_DMA_STREAM_7, LL_DMA_PDATAALIGN_BYTE);
  LL_DMA_SetMemorySize(DMA2, LL_DMA_STREAM_7, LL_DMA_MDATAALIGN_BYTE);
  LL_DMA_DisableFifoMode(DMA2, LL_DMA_STREAM_7);

  LL_DMA_SetPeriphAddress(DMA2, LL_DMA_STREAM_7, (uint32_t)&USART1->DR);
}



osMessageQueueId_t GetQueueHandleForLed2Task(void)
{
  return queueHandleForLed2Task;
}



void DMA2_USART1_TX_SendFeedbackMessage(void *objectAddress, size_t objectSize)
{
  LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_7, (uint32_t)objectAddress);
  LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_7, objectSize);

  if(!LL_DMA_IsEnabledStream(DMA2, LL_DMA_STREAM_7))
  {
    LL_DMA_ClearFlag_TC7(DMA2);
    LL_DMA_ClearFlag_HT7(DMA2);
    LL_DMA_ClearFlag_DME7(DMA2);
    LL_DMA_ClearFlag_FE7(DMA2);
    LL_DMA_ClearFlag_TE7(DMA2);

    LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_7);
  }
}



/*****************************************************************************/
/*                         RTOS TASK DEFINITION                              */
/*****************************************************************************/

void StartDma2Usart1RxTask(void *argument)
{
  size_t oldPosition = 0;
  size_t currentPosition = 0;
  Magic_t isMagicFound = Magic_NotFound;
  uint8_t led2UpdatedBlinksCount[2] = {0};

  queueHandleForLed2Task = osMessageQueueNew(LED2TASK_QUEUE_MESSAGES_COUNT, 
                                      sizeof(led2UpdatedBlinksCount), NULL);
  InitializeFeedbackMessage();

  for(;;)
  {
    currentPosition = GetCurrentPositionInDma2Usart1RxBuffer();
    if(currentPosition != oldPosition)
    {
      while(isMagicFound == Magic_NotFound 
            && CountBytesLeftToCheck(currentPosition, oldPosition) 
            >= (MAGIC_WORD_LENGTH + CONFIG_BYTES_COUNT))
      {
        if((ARRAY_LENGTH(dma2Usart1RxBuffer)-oldPosition) >= MAGIC_WORD_LENGTH)
        {
          isMagicFound = FindMagic(oldPosition, 0, MAGIC_WORD_LENGTH);
          if(isMagicFound == Magic_Found)
          {
            oldPosition = UpdateLed2BufferAndPosition(led2UpdatedBlinksCount,
                                                      oldPosition,
                                                      MAGIC_WORD_LENGTH);
            break;
          }
        }
        else if((ARRAY_LENGTH(dma2Usart1RxBuffer) - oldPosition) != 0)
        {
          size_t offset = ARRAY_LENGTH(dma2Usart1RxBuffer) - oldPosition;
          Magic_t isPartOfMagicFound = Magic_NotFound;
          isPartOfMagicFound = FindMagic(oldPosition, 0, offset);
          if(isPartOfMagicFound == Magic_Found)
          {
            size_t leftBytes = MAGIC_WORD_LENGTH - offset;
            isMagicFound = FindMagic(0, offset, leftBytes);
            if(isMagicFound == Magic_Found)
            {
              oldPosition = leftBytes;
              oldPosition = UpdateLed2BufferAndPosition(led2UpdatedBlinksCount,
                                                        oldPosition, 0);
              break;
            }
          }
        }
        
        oldPosition++;
        if(oldPosition == ARRAY_LENGTH(dma2Usart1RxBuffer))
          oldPosition = 0;
      }
    }

    if(oldPosition == ARRAY_LENGTH(dma2Usart1RxBuffer))
          oldPosition = 0;

    if(isMagicFound == Magic_Found)
    {
      osMessageQueuePut(queueHandleForLed2Task, led2UpdatedBlinksCount, 0, 0);
      
      FeedbackMessageUpdateTime();
      DMA2_USART1_TX_SendFeedbackMessage(&feedbackMessage,
                                         sizeof(feedbackMessage));
    }

    isMagicFound = Magic_NotFound;

    osDelay(1000);
  }
}



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DEFINITIONS                         */
/*****************************************************************************/

static void InitializeFeedbackMessage(void)
{
  strncpy(feedbackMessage.magicWord, MAGIC_WORD, MAGIC_WORD_LENGTH + 1);
  feedbackMessage.rtcTime = 0;
}



static size_t GetCurrentPositionInDma2Usart1RxBuffer(void)
{
  return ARRAY_LENGTH(dma2Usart1RxBuffer) - 
         LL_DMA_GetDataLength(DMA2, LL_DMA_STREAM_2);
}



static size_t CountBytesLeftToCheck(size_t currentPosition,
                                    size_t oldPosition)
{
  if(currentPosition > oldPosition)
    return currentPosition - oldPosition;
  else if(currentPosition < oldPosition)
    return (ARRAY_LENGTH(dma2Usart1RxBuffer) - oldPosition) + currentPosition;
  else
    return 0;
}




static Magic_t FindMagic(size_t dma2BufferOffset, size_t magicWordOffset,
                         size_t magicWordLength)
{
  int isMagicFound;
  isMagicFound = memcmp(dma2Usart1RxBuffer + dma2BufferOffset,
                        MAGIC_WORD + magicWordOffset, magicWordLength);
  if(isMagicFound == 0)
    return Magic_Found;
  else
    return Magic_NotFound;
}



static size_t UpdateLed2BufferAndPosition(uint8_t *led2UpdatedBlinksCount,
                                          size_t positionIndex,
                                          size_t magicWordLength)
                                       
{
  size_t newPosition = positionIndex + magicWordLength;
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



static void FeedbackMessageUpdateTime(void)
{
  time_t rtcTimeInSeconds = RTC_GetTimeInSeconds();
  feedbackMessage.rtcTime = rtcTimeInSeconds;
}
