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



#define USART1_CLOCK_DISABLE()  ( RCC->APB2RSTR |= (1 << 4) )
#define USART2_CLOCK_DISABLE()  ( RCC->APB1RSTR |= (1 << 17) )
#define USART6_CLOCK_DISABLE()  ( RCC->APB2RSTR |= (1 << 5) )



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



void usart_clock_disable(usart_registers_t *usart_port)
{
    if(usart_port == USART1) {
        USART1_CLOCK_DISABLE();
    } else if(usart_port == USART2) {
        USART2_CLOCK_DISABLE();
    } else if(usart_port == USART6) {
        USART6_CLOCK_DISABLE();
    }
}



void usart_config_init(usart_registers_t *usart_port,
    usart_config_t *usart_config)
{
    uint32_t cr1_register_settings = 0;
    if(usart_config->mode == usart_mode_tx_rx) {
        cr1_register_settings |= (1 << 2);
        cr1_register_settings |= (1 << 3);
    } else if(usart_config->mode == usart_mode_tx_only) {
        cr1_register_settings |= (1 << 3);
    } else if(usart_config->mode == usart_mode_rx_only) {
        cr1_register_settings |= (1 << 2);
    }
    
    if(usart_config->word_length == usart_word_length_9bits) {
        cr1_register_settings |= (1 << 12);
    }

    if(usart_config->parity_control == usart_parity_control_even) {
        cr1_register_settings |= (1 << 10);
    } else if(usart_config->parity_control == usart_parity_control_odd) {
        cr1_register_settings |= (1 << 9);
        cr1_register_settings |= (1 << 10);
    }
    
    usart_port->CR1 = cr1_register_settings;



}

