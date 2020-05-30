/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef STM32F401XE_DRIVER_SYSCFG_H
#define STM32F401XE_DRIVER_SYSCFG_H

#include "stm32f401xe.h"



/*****************************************************************************/
/* SYSCFG register settings */
/*****************************************************************************/

typedef enum syscfg_exti_port_code {
    syscfg_exti_port_code_gpio_a = 0,
    syscfg_exti_port_code_gpio_b,
    syscfg_exti_port_code_gpio_c,
    syscfg_exti_port_code_gpio_d,
    syscfg_exti_port_code_gpio_e,
    syscfg_exti_port_code_gpio_h = 7
}syscfg_exti_port_code_t;




#endif /* STM32F401XE_DRIVER_SYSCFG_H */

