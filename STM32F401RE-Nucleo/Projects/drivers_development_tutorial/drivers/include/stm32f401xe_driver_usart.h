/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef STM32F401XE_DRIVER_USART_H
#define STM32F401XE_DRIVER_USART_H

#include "stm32f401xe.h"



/*****************************************************************************/
/* USART CONFIGURATION SETTINGS */
/*****************************************************************************/

typedef enum usart_mode {
    usart_mode_only_tx = 0,
    usart_mode_only_rx,
    usart_mode_tx_rx
}usart_mode_t;



/*****************************************************************************/
/* USART CONFIGURATION STRUCTURES */
/*****************************************************************************/

typedef struct {
    usart_mode_t mode;
    uint32_t baudrate;
    uint8_t stop_bits_count;
    uint8_t word_length;
    uint8_t parity_control;
    uint8_t hardware_flow_control;
}usart_config_t;



/*****************************************************************************/
/* USART API PROTOTYPES */
/*****************************************************************************/

void usart_clock_enable(usart_registers_t *usart_port);
void usart_clock_disable(usart_registers_t *usart_port);



#endif /* STM32F401XE_DRIVER_USART_H */

