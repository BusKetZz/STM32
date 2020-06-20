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
/* I2C CONFIGURATION SETTINGS */
/*****************************************************************************/

typedef enum i2c_clock_speed {
    i2c_clock_speed_standard_mode = 100000,
    i2c_clock_speed_fast_mode = 400000
}i2c_clock_speed_t;



typedef enum i2c_ack_control_t {
    i2c_ack_control_disable = 0,
    i2c_ack_control_enable
}i2c_ack_control_t;



typedef enum i2c_fast_mode_duty_cycle {
    i2c_fast_mode_duty_cycle_2 = 0,
    i2c_fast_mode_duty_cycle_16_9
}i2c_fast_mode_duty_cycle_t;



/*****************************************************************************/
/* I2C CONFIGURATION STRUCTURES */
/*****************************************************************************/

typedef struct {
    i2c_clock_speed_t clock_speed;
    uint8_t device_address;
    i2c_ack_control_t ack_control;
    i2c_fast_mode_duty_cycle_t fast_mode_duty_cycle;
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

void i2c_config_init(i2c_handle_t *i2c_handle);

void i2c_master_send_data(i2c_handle_t *i2c_handle, uint8_t *tx_buffer,
    uint32_t bytes_to_send, uint8_t slave_address);
void i2c_master_read_data(i2c_handle_t *i2c_handle, uint8_t *rx_buffer,
    uint32_t bytes_to_read, uint8_t slave_address);

void i2c_event_irq_enable(i2c_registers_t *i2c_port);



#endif /* STM32F401XE_DRIVER_I2C_H */

