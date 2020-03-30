#ifndef LED_H
#define LED_H

#ifdef  __cplusplus
extern "C"
{
#endif



#include <stdint.h>



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS PROTOTYPES                         */
/*****************************************************************************/

void LED2_UpdateBlinkPattern(const uint8_t newLongBlinksAmount, 
                             const uint8_t newShortBlinksAmount);



/*****************************************************************************/
/*                           RTOS TASK PROTOTYPE                             */
/*****************************************************************************/

void StartLed2Task(void *argument);



#ifdef  __cplusplus
}
#endif
 
#endif  /* LED_H */
