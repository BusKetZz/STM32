#include "idle_task.h"

#include "cmsis_os.h"



/*****************************************************************************/
/*                         RTOS TASK DEFINITION                              */
/*****************************************************************************/

void StartIdleTask(void *argument)
{
  for(;;)
  {
    osDelay(1);
  }
}
