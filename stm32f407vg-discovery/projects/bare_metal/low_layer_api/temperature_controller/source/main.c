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
/* PRIVATE FUNCTIONS PROTOTYPES */
/*****************************************************************************/

static void system_init(void);



/*****************************************************************************/
/* MAIN */
/*****************************************************************************/

int main(void)
{
    system_init();


    while (1) {
        ;
    }

    return 0;
}



/*****************************************************************************/
/* PRIVATE FUNCTIONS DEFINITION */
/*****************************************************************************/

static void system_init(void)
{
    syscfg_clock_enable();

    pwr_clock_enable();
    pwr_set_regulator_voltage_scaling();

    flash_set_latency();

    rcc_set_ahb_prescaler();
    rcc_set_apb1_prescaler();
    rcc_set_apb2_prescaler();
    rcc_system_clock_init();
}

