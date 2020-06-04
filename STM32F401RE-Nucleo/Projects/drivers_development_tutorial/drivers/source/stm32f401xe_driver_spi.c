/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#include "stm32f401xe_driver_spi.h"

#include "stm32f401xe.h"



/*****************************************************************************/
/* SPI CLOCK ENABLE AND DISABLE MACROS */
/*****************************************************************************/

#define SPI1_CLOCK_ENABLE() ( RCC->APB2ENR |= (1 << 12) )
#define SPI2_CLOCK_ENABLE() ( RCC->APB1ENR |= (1 << 14) )
#define SPI3_CLOCK_ENABLE() ( RCC->APB1ENR |= (1 << 15) )
#define SPI4_CLOCK_ENABLE() ( RCC->APB2ENR |= (1 << 13) )



#define SPI1_CLOCK_DISABLE() ( RCC->APB2ENR &= ~(1 << 12) )
#define SPI2_CLOCK_DISABLE() ( RCC->APB1ENR &= ~(1 << 14) )
#define SPI3_CLOCK_DISABLE() ( RCC->APB1ENR &= ~(1 << 15) )
#define SPI4_CLOCK_DISABLE() ( RCC->APB2ENR &= ~(1 << 13) )



/*****************************************************************************/
/* SPI API DEFINITIONS */
/*****************************************************************************/

void spi_clock_enable(spi_registers_t *spi_port)
{
    if(spi_port == SPI1) {
        SPI1_CLOCK_ENABLE();
    } else if(spi_port == SPI2) {
        SPI2_CLOCK_ENABLE();
    } else if(spi_port == SPI3) {
        SPI3_CLOCK_ENABLE();
    } else if(spi_port == SPI4) {
        SPI4_CLOCK_ENABLE();
    }
}



void spi_clock_disable(spi_registers_t *spi_port)
{
    if(spi_port == SPI1) {
        SPI1_CLOCK_DISABLE();
    } else if(spi_port == SPI2) {
        SPI2_CLOCK_DISABLE();
    } else if(spi_port == SPI3) {
        SPI3_CLOCK_DISABLE();
    } else if(spi_port == SPI4) {
        SPI4_CLOCK_DISABLE();
    } 
}



void spi_init_config(spi_handle_t *spi_handle)
{
    uint32_t register_settings = 0;

    register_settings |= (spi_handle->spi_config.device_mode << 2);

    if(spi_handle->spi_config.transfer_mode == spi_transfer_mode_full_duplex) {
        register_settings &= ~(1 << 15);
    } else if(spi_handle->spi_config.transfer_mode ==
        spi_transfer_mode_half_duplex) {
        register_settings |= (1 << 15);
    } else if(spi_handle->spi_config.transfer_mode ==
        spi_transfer_mode_simplex_rxonly) {
        register_settings &= ~(1 << 15);
        register_settings |= (1 << 10);
    }

    register_settings |= (spi_handle->spi_config.baudrate << 3);

    if(spi_handle->spi_config.clock_polarity ==
        spi_clock_polarity_low_idle_state) {
        register_settings &= ~(1 << 1);
    } else if(spi_handle->spi_config.clock_polarity ==
        spi_clock_polarity_high_idle_state) {
        register_settings |= (1 << 1);
    }

    if(spi_handle->spi_config.clock_phase == spi_clock_phase_first) {
        register_settings &= ~(1 << 0);
    } else if(spi_handle->spi_config.clock_phase == spi_clock_phase_second) {
        register_settings |= (1 << 0);
    }

    if(spi_handle->spi_config.data_frame_format ==
        spi_data_frame_format_8bits) {
        register_settings &= ~(1 << 11);
    } else if(spi_handle->spi_config.data_frame_format ==
        spi_data_frame_format_16bits) {
        register_settings |= (1 << 11);
    }

    if(spi_handle->spi_config.software_slave_management ==
        spi_software_slave_management_disabled) {
        register_settings &= ~(1 << 9);
    } else if(spi_handle->spi_config.software_slave_management ==
        spi_software_slave_management_enabled) {
        register_settings |= (1 << 9);
    }

    spi_handle->spi_port->CR1 = register_settings;
}

