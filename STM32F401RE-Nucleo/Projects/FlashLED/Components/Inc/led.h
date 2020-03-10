#ifndef LED_H
#define LED_H

#ifdef  __cplusplus
extern "C"
{
#endif



#include <stdint.h>



/*****************************************************************************/
/*                    PUBLIC FUNCTIONS DECLARATIONS                          */
/*****************************************************************************/

void LED2_UpdateBlinkPattern(const uint8_t newLongBlinksAmount, 
                             const uint8_t newShortBlinksAmount);



/*****************************************************************************/
/*                       FreeRTOS TASK DECLARATION                           */
/*****************************************************************************/

void vLEDTask(void *pvParameters);



#ifdef  __cplusplus
}
#endif
 
#endif  /* LED_H */