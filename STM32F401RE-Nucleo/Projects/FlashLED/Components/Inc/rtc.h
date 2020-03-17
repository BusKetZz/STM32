#ifndef RTC_H
#define RTC_H

#ifdef  __cplusplus
extern "C"
{
#endif



#include <time.h>



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DECLARATIONS                         */
/*****************************************************************************/

void RTC_Clock_Config(void);
void RTC_InitialSettings_Config(void);
time_t RTC_GetTimeInSeconds(void);








#ifdef  __cplusplus
}
#endif
 
#endif  /* RTC_H */
