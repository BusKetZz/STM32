/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#include "stm32f401xe_driver_rcc.h"

#include "stm32f401xe.h"



/*****************************************************************************/
/* RCC API DEFINITIONS */
/*****************************************************************************/

rcc_system_clock_source_t rcc_get_system_clock_source(void)
{
   return ( (RCC->CFGR >> 2) & 0x3 );
}



rcc_system_clock_source_speed_t rcc_get_system_clock_source_speed(
    rcc_system_clock_source_t clock_source)
{
    if(clock_source == rcc_system_clock_source_hsi) {
        return rcc_system_clock_source_speed_hsi;
    } else if(clock_source == rcc_system_clock_source_hse) {
        return rcc_system_clock_source_speed_hse;
    }
}

