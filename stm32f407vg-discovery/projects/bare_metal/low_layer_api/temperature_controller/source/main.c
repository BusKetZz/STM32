/*
 * Author: Jakub Standarski
 * Date: 11.08.2020
 *
 */



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "flash.h"
#include "pwr.h"
#include "rcc.h"
#include "syscfg.h"



/*****************************************************************************/
/* MAIN */
/*****************************************************************************/

int main(void)
{
    rcc_system_clock_init();
    rcc_set_ahb_prescaler();
    rcc_set_apb1_prescaler();
    rcc_set_apb2_prescaler();

    pwr_clock_enable();
    pwr_set_regulator_voltage_scaling();

    syscfg_clock_enable();

    flash_set_latency();


    while (1) {
        ;
    }

    return 0;
}

