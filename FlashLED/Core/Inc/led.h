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
