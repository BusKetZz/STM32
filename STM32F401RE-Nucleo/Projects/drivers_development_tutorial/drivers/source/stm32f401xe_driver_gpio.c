/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#include "stm32f401xe_driver_gpio.h"

#include "stm32f401xe.h"



/*****************************************************************************/
/* GPIO API definitions */
/*****************************************************************************/

void gpio_clock_enable(gpio_registers_t *gpio_port)
{
    if(gpio_port == GPIOA) {
        GPIOA_CLOCK_ENABLE();
    } else if(gpio_port == GPIOB) {
        GPIOB_CLOCK_ENABLE();
    } else if(gpio_port == GPIOC) {
        GPIOC_CLOCK_ENABLE();
    } else if(gpio_port == GPIOD) {
        GPIOD_CLOCK_ENABLE();
    } else if(gpio_port == GPIOE) {
        GPIOE_CLOCK_ENABLE();
    } else if(gpio_port == GPIOH) {
        GPIOH_CLOCK_ENABLE();
    } else {
        /* TODO */
    }
}



void gpio_clock_disable(gpio_registers_t *gpio_port)
{
    if(gpio_port == GPIOA) {
        GPIOA_CLOCK_DISABLE();
    } else if(gpio_port == GPIOB) {
        GPIOB_CLOCK_DISABLE();
    } else if(gpio_port == GPIOC) {
        GPIOC_CLOCK_DISABLE();
    } else if(gpio_port == GPIOD) {
        GPIOD_CLOCK_DISABLE();
    } else if(gpio_port == GPIOE) {
        GPIOE_CLOCK_DISABLE();
    } else if(gpio_port == GPIOH) {
        GPIOH_CLOCK_DISABLE();
    } else {
        /* TODO */
    }
}



void gpio_pin_init_config(gpio_handle_t *gpio_handle)
{
    uint32_t settings = 0;

    settings = gpio_handle->gpio_pin_config.pin_mode <<
        (2 * gpio_handle->gpio_pin_config.pin_number);
    gpio_handle->gpio_port->MODER |= settings;

    settings = 0;
    settings = gpio_handle->gpio_pin_config.pin_output_type <<
        gpio_handle->gpio_pin_config.pin_number;
    gpio_handle->gpio_port->OTYPER |= settings;

    settings = 0;
    settings |= gpio_handle->gpio_pin_config.pin_speed <<
        (2* gpio_handle->gpio_pin_config.pin_number);
    gpio_handle->gpio_port->OSPEEDR |= settings;

    settings = 0;
    settings |= gpio_handle->gpio_pin_config.pin_pullup_pulldown_control <<
        (2 * gpio_handle->gpio_pin_config.pin_number);
    gpio_handle->gpio_port->PUPDR |= settings;

    settings = 0;
    if(gpio_handle->gpio_pin_config.pin_mode == gpio_mode_alternate_function) {
        if(gpio_handle->gpio_pin_config.pin_number < gpio_pin_number_8) {
            settings |=
                gpio_handle->gpio_pin_config.pin_alternate_function_mode <<
                    (4 * gpio_handle->gpio_pin_config.pin_number);
            gpio_handle->gpio_port->AFRL |= settings;
        } else {
            uint8_t pin_number = gpio_handle->gpio_pin_config.pin_number % 8;
            settings |= 
                gpio_handle->gpio_pin_config.pin_alternate_function_mode <<
                    (4 * pin_number);
            gpio_handle->gpio_port->AFRH |= settings;
        }
    }
}



void gpio_pin_clear_config(gpio_handle_t *gpio_handle)
{
    gpio_handle->gpio_port->MODER &= ~(0x3 <<
        (2 * gpio_handle->gpio_pin_config.pin_number));

    gpio_handle->gpio_port->OTYPER &= ~(0x1 <<
        gpio_handle->gpio_pin_config.pin_number);

    gpio_handle->gpio_port->OSPEEDR &= ~(0x3 <<
        (2 * gpio_handle->gpio_pin_config.pin_number));

    gpio_handle->gpio_port->PUPDR &= ~(0x3 <<
        (2 * gpio_handle->gpio_pin_config.pin_number));

    if(gpio_handle->gpio_pin_config.pin_number < gpio_pin_number_8) {
        gpio_handle->gpio_port->AFRL &= ~(0xF << 
            (4 * gpio_handle->gpio_pin_config.pin_number));
    } else {
        uint8_t pin_number = gpio_handle->gpio_pin_config.pin_number % 8;
        gpio_handle->gpio_port->AFRH &= ~(0xF << (4 * pin_number));
    }
}

