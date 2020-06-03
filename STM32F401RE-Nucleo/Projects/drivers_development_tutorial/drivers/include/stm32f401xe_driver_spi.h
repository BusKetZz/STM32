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
/* SPI CONFIGURATION SETTINGS */
/*****************************************************************************/

typedef enum spi_device_mode {
    spi_device_mode_slave = 0,
    spi_device_mode_master
}spi_device_mode_t;



typedef enum spi_transfer_mode_t {
    spi_transfer_mode_full_duplex = 0,
    spi_transfer_mode_half_duplex,
    spi_tranfser_mode_simplex_txonly,
    spi_transfer_mode_simplex_rxonly
}spi_transfer_mode_t;



/*****************************************************************************/
/* SPI CONFIGURATION STRUCTURES */
/*****************************************************************************/

typedef struct {
    spi_device_mode_t device_mode;
    spi_transfer_mode_t transfer_mode;
    spi_clock_speed_t clock_speed;
    spi_clock_polarity_t clock_polarity;
    spi_clock_phase_t clock_phase;
    spi_data_frame_format_t data_frame_format;
    spi_software_slave_management_t software_slave_management;
}spi_config_t;



typedef struct {
    spi_registers_t *spi_port;
    spi_config_t spi_config;
}spi_handle_t;



/*****************************************************************************/
/* SPI API PROTOTYPES */
/*****************************************************************************/

void spi_clock_enable(spi_registers_t *spi_port);
void spi_clock_disable(spi_registers_t *spi_port);

void spi_init_config(spi_handle_t *spi_handle);



#endif /* STM32F401XE_DRIVER_SPI_H */

