#include "adc_temperature_regulator.h"

#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_bus.h"



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void ADC1_TEMPERATURE_REGULATOR_Clock_Config(void)
{
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC1);
}
