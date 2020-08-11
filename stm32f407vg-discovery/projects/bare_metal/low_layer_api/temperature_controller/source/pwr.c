/*
 * Author: Jakub Standarski
 * Date: 11.08.2020
 *
 */



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "pwr.h"

#include "stm32f4xx.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_pwr.h"



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void pwr_clock_enable(void)
{
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
}



void pwr_set_regulator_voltage_scalling(void)
{
    LL_PWR_SetRegulVoltageScalling(LL_PWR_REGU_VOLTAGE_SCALE2);
}

