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

