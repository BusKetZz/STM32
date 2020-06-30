/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#include "stm32f401xe_driver_usart.h"

#include "stm32f401xe.h"



/*****************************************************************************/
/* USART API DEFINITIONS */
/*****************************************************************************/

void usart_clock_enable(usart_registers_t *usart_port)
{
    if(usart_port == USART1) {
        USART1_CLOCK_ENABLE();
    } else if(usart_port == USART2) {
        USART2_CLOCK_ENABLE();
    } else if(usart_port == USART6) {
        USART6_CLOCK_ENABLE();
    }
}



