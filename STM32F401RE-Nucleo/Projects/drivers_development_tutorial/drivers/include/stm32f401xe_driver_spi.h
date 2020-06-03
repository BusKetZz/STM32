/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef STM32F401XE_DRIVER_SPI_H
#define STM32F401XE_DRIVER_SPI_H

#include "stm32f401xe.h"



/*****************************************************************************/
/* SPI CONFIGURATION STRUCTURES */
/*****************************************************************************/

typedef struct {
    spi_device_mode_t device_mode;
    spi_bus_config_t bus_config;
    spi_clock_speed_t clock_speed;
    spi_clock_polarity_t clock_polarity;
    spi_clock_phase_t clock_phase;
    spi_data_frame_format_t data_frame_format;
    spi_software_slave_management_t software_slave_management;
}spi_config_t;





#endif /* STM32F401XE_DRIVER_SPI_H */

