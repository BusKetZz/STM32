/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#include "stm32f401xe_driver_syscfg.h"

#include "stm32f401xe.h"



/*****************************************************************************/
/* SYSCFG clock enable and disable macros */
/*****************************************************************************/

#define SYSCFG_CLOCK_ENABLE()   ( RCC->APB2ENR |= (1 << 14) )

#define SYSCFG_CLOCK_DISABLE()  ( RCC->APB2ENR &= ~(1 << 14) )

