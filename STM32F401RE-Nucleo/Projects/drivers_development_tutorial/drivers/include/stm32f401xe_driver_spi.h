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
    spi_transfer_mode_simplex_rxonly
}spi_transfer_mode_t;



typedef enum spi_baudrate {
    spi_baudrate_div2 = 0,
    spi_baudrate_div4,
    spi_baudrate_div8,
    spi_baudrate_div16,
    spi_baudrate_div32,
    spi_baudrate_div64,
    spi_baudrate_div128,
    spi_baudrate_div256
}spi_baudrate_t;



typedef enum spi_clock_polarity {
    spi_clock_polarity_low_idle_state = 0,
    spi_clock_polarity_high_idle_state
}spi_clock_polarity_t;



typedef enum spi_clock_phase {
    spi_clock_phase_first = 0,
    spi_clock_phase_second
}spi_clock_phase_t;



typedef enum spi_data_frame_format {
    spi_data_frame_format_8bits = 0,
    spi_data_frame_format_16bits
}spi_data_frame_format_t;



typedef enum spi_software_slave_management {
    spi_software_slave_management_disabled = 0,
    spi_software_slave_management_enabled
}spi_software_slave_management_t;



/*****************************************************************************/
/* SPI CONFIGURATION STRUCTURES */
/*****************************************************************************/

typedef struct {
    spi_device_mode_t device_mode;
    spi_transfer_mode_t transfer_mode;
    spi_baudrate_t baudrate;
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
void spi_clear_config(spi_registers_t *spi_port);

void spi_enable(spi_registers_t *spi_port);

void spi_send_data(spi_registers_t *spi_port, uint8_t *tx_buffer,
    uint32_t bytes_to_transmit);



#endif /* STM32F401XE_DRIVER_SPI_H */

