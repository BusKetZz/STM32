/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef STM32F401XE_DRIVER_GPIO_H
#define STM32F401XE_DRIVER_GPIO_H

#include "stm32f401xe.h"



/*****************************************************************************/
/* GPIO configuration structures */
/*****************************************************************************/

/* GPIO pin configuration structure */

typedef struct {
    uint8_t pin_number;
    uint8_t pin_mode;
    uint8_t pin_speed;
    uint8_t pin_pullup_pulldown_control;
    uint8_t pin_output_type;
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

void gpio_pin_set_configuration(gpio_handle_t *gpio_handle);
void gpio_pin_clear_configuration(gpio_handle_t *gpio_handle);



#endif /* STM32F401XE_DRIVER_GPIO_H */

