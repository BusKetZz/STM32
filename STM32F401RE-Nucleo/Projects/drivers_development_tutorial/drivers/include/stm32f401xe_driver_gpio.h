/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef STM32F401XE_DRIVER_GPIO_H
#define STM32F401XE_DRIVER_GPIO_H

#include "stm32f401xe.h"

#include <stdint.h>



/*****************************************************************************/
/* GPIO register settings */
/*****************************************************************************/

typedef enum gpio_mode {
    gpio_mode_input = 0,
    gpio_mode_output,
    gpio_mode_alternate_function,
    gpio_mode_analog
}gpio_mode_t;



typedef enum gpio_output_type {
    gpio_output_type_pushpull = 0,
    gpio_output_type_opendrain
}gpio_output_type_t;



typedef enum gpio_output_speed {
    gpio_output_speed_low = 0,
    gpio_output_speed_medium,
    gpio_output_speed_high,
    gpio_output_speed_very_high
}gpio_output_speed_t;



typedef enum gpio_pull {
    gpio_no_pull = 0,
    gpio_pull_up,
    gpio_pull_down
}gpio_pull_t;




/*****************************************************************************/
/* GPIO configuration structures */
/*****************************************************************************/

/* GPIO pin configuration structure */

typedef struct {
    uint8_t pin_number;
    gpio_mode_t pin_mode;
    gpio_output_speed_t pin_speed;
    uint8_t pin_pullup_pulldown_control;
    gpio_output_type_t pin_output_type;
    uint8_t pin_alternate_function_mode;
}gpio_pin_config_t;



/* GPIO handle structure */

typedef struct {
    gpio_registers_t *gpio_port;
    gpio_pin_config_t gpio_pin_config;
}gpio_handle_t;



/*****************************************************************************/
/* GPIO API prototypes */
/*****************************************************************************/

void gpio_clock_enable(gpio_registers_t *gpio_port);
void gpio_clock_disable(gpio_registers_t *gpio_port);

void gpio_pin_init_config(gpio_handle_t *gpio_handle);
void gpio_pin_clear_config(gpio_handle_t *gpio_handle);

void gpio_port_reset(gpio_registers_t *gpio_port);

uint8_t gpio_pin_read(gpio_registers_t *gpio_port, uint8_t pin_number);
uint16_t gpio_port_read(gpio_registers_t *gpio_port);

void gpio_pin_set(gpio_registers_t *gpio_port, uint8_t pin_number);
void gpio_pin_reset(gpio_registers_t *gpio_port, uint8_t pin_number);
void gpio_pin_toggle(gpio_registers_t *gpio_port, uint8_t pin_number);






#endif /* STM32F401XE_DRIVER_GPIO_H */

