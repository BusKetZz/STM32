#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"



/*****************************************************************************/
/*                             PUBLIC DEFINES                                */
/*****************************************************************************/

#define LED2_ON()  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET)
#define LED2_OFF() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET)



/*****************************************************************************/
/*                       FreeRTOS TASK DECLARATION                           */
/*****************************************************************************/

void vLEDTask(void *pvParameters);
