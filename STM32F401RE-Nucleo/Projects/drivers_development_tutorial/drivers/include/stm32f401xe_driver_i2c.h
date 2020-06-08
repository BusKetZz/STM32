/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef STM32F401XE_DRIVER_I2C_H
#define STM32F401XE_DRIVER_I2C_H

#include "stm32f401xe.h"



/*****************************************************************************/
/* I2C CONFIGURATION STRUCTURES */
/*****************************************************************************/

typedef struct {
    uint32_t clock_speed;
    uint8_t device_address;
    uint8_t ack_control;
    uint16_t fast_mode_duty_cycle;
}i2c_config_t;



typedef struct {
    i2c_registers_t *i2c_port;
    i2c_config_t i2c_config;
}i2c_handle_t;



/*****************************************************************************/
/* I2C API PROTOTYPES */
/*****************************************************************************/

void i2c_clock_enable(i2c_registers_t *i2c_port);
void i2c_clock_disable(i2c_registers_t *i2c_port);



#endif /* STM32F401XE_DRIVER_I2C_H */

