/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#include "stm32f401_driver_gpio.h"

#include "stm32f401xe.h"



/*****************************************************************************/
/* GPIO API definitions */
/*****************************************************************************/

void gpio_clock_enable(gpio_registers_t *gpio_port)
{
    switch(gpio_port) {
        case GPIOA:
            GPIOA_CLOCK_ENABLE();
            break;
        case GPIOB:
            GPIOB_CLOCK_ENABLE();
            break;
        case GPIOC:
            GPIOC_CLOCK_ENABLE();
            break;
        case GPIOD:
            GPIOD_CLOCK_ENABLE();
            break;
        case GPIOE:
            GPIOE_CLOCK_ENABLE();
            break;
        case GPIOH:
            GPIOH_CLOCK_ENABLE();
            break;
        default:
            /* TODO */
    }
}

