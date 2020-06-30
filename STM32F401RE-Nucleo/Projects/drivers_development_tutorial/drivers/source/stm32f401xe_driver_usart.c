/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#include "stm32f401xe_driver_usart.h"

#include "stm32f401xe.h"



/*****************************************************************************/
/* USART CLOCK ENABLE AND DISABLE MACROS */
/*****************************************************************************/

#define USART1_CLOCK_ENABLE()   ( RCC->APB2ENR |= (1 << 4) )
#define USART2_CLOCK_ENABLE()   ( RCC->APB1ENR |= (1 << 17) )
#define USART6_CLOCK_ENABLE()   ( RCC->APB2ENR |= (1 << 5) )



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



