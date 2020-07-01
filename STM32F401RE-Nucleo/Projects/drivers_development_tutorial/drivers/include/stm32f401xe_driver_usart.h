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



typedef enum usart_baudrate {
    usart_baudrate_1200 = 1200,
    usart_baudrate_2400 = 2400,
    usart_baudrate_9600 = 9600,
    usart_baudrate_19200 = 19200,
    usart_baudrate_38400 = 38400,
    usart_baudrate_57600 = 57600,
    usart_baudrate_115200 = 115200
}usart_baudrate_t;



typedef enum usart_stop_bits_count {
    usart_stop_bits_count_0_5 = 1,
    usart_stop_bits_count_1 = 0,
    usart_stop_bits_count_1_5 = 3,
    usart_stop_bits_count_2 = 2
}usart_stop_bits_count_t;



typedef enum usart_word_length_t {
    usart_word_length_8bits = 0,
    usart_word_length_9bits
}usart_word_length_t;



typedef enum usart_parity_control {
    usart_parity_control_disable = 0,
    usart_parity_control_even,
    usart_parity_control_odd
}usart_parity_control_t;



typedef enum usart_hardware_flow_control {
    usart_hardware_flow_control_disable = 0,
    usart_hardware_flow_control_cts,
    usart_hardware_flow_control_rts,
    usart_hardware_flow_control_cts_rts
}usart_hardware_flow_control_t;



/*****************************************************************************/
/* USART CONFIGURATION STRUCTURES */
/*****************************************************************************/

typedef struct {
    usart_mode_t mode;
    usart_baudrate_t baudrate;
    usart_stop_bits_count_t stop_bits_count;
    usart_word_length_t word_length;
    usart_parity_control_t parity_control;
    usart_hardware_flow_control_t hardware_flow_control;
}usart_config_t;



/*****************************************************************************/
/* USART API PROTOTYPES */
/*****************************************************************************/

void usart_clock_enable(usart_registers_t *usart_port);
void usart_clock_disable(usart_registers_t *usart_port);

void usart_config_init(usart_registers_t *usart_port,
    usart_config_t *usart_config);



#endif /* STM32F401XE_DRIVER_USART_H */

