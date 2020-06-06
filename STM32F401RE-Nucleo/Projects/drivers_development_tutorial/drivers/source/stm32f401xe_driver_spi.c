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
/* SPI RESET MACROS */
/*****************************************************************************/

#define SPI1_RESET()    do{ (RCC->APB2RSTR |= (1 << 12));\
    (RCC->APB2RSTR &= ~(1 << 12)); }while(0)
#define SPI2_RESET()    do{ (RCC->APB1RSTR |= (1 << 14));\
    (RCC->APB1RSTR &= ~(1 << 14)); }while(0)
#define SPI3_RESET()    do{ (RCC->APB1RSTR |= (1 << 15));\
    (RCC->APB1RSTR &= ~(1 << 15)); }while(0)
#define SPI4_RESET()    do{ (RCC->APB2RSTR |= (1 << 13));\
    (RCC->APB2RSTR &= ~(1 << 13)); }while(0)



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

    register_settings |= (spi_handle->spi_config.clock_polarity << 1);

    register_settings |= (spi_handle->spi_config.clock_phase << 0);

    register_settings |= (spi_handle->spi_config.data_frame_format << 11);

    register_settings |= (spi_handle->spi_config.software_slave_management <<
        9);

    spi_handle->spi_port->CR1 |= register_settings;
}



void spi_clear_config(spi_registers_t *spi_port)
{
    if(spi_port == SPI1) {
        SPI1_RESET();
    } else if(spi_port == SPI2) {
        SPI2_RESET();
    } else if(spi_port == SPI3) {
        SPI3_RESET();
    } else if(spi_port == SPI4) {
        SPI4_RESET();
    }
}



void spi_enable(spi_registers_t *spi_port)
{
    spi_port->CR1 |= (1 << 6);
}



void spi_disable(spi_registers_t *spi_port)
{
    spi_port->CR1 &= ~(1 << 6);
}



void spi_send_data(spi_registers_t *spi_port, uint8_t *tx_buffer,
    uint32_t bytes_to_send)
{
    while(bytes_to_send > 0) {
        while( (spi_port->SR & (1 << 1)) == 0 ) {
            ;
        }

        if( (spi_port->CR1 & (1 << 11)) == 0 ) {
            spi_port->DR = *tx_buffer;
            bytes_to_send -= 1;
            tx_buffer++;
        } else {
            spi_port->DR = *((uint16_t *)tx_buffer);
            bytes_to_send -= 2;
            (uint16_t *)tx_buffer++;
        }
    }
}



void spi_read_data(spi_registers_t *spi_port, uint8_t *rx_buffer,
    uint32_t bytes_to_read)
{
    while(bytes_to_read > 0) {
        while( (spi_port->SR & (1 << 0)) == 0) {
            ;
        }

        if( (spi_port->CR1 & (1 << 11)) == 0) {
            *rx_buffer = spi_port->DR;
            bytes_to_read -= 1;
            rx_buffer++;
        } else {
            *((uint16_t *)rx_buffer) = spi_port->DR;
            bytes_to_read -= 2;
            (uint16_t *)rx_buffer++;
        }
    }
}



void spi_tx_irq_enable(spi_registers_t *spi_port)
{
    spi_port->CR2 |= (1 << 7);
}



void spi_tx_irq_disable(spi_registers_t *spi_port)
{
    spi_port->CR2 &= ~(1 << 7);
}



void spi_rx_irq_enable(spi_registers_t *spi_port)
{
    spi_port->CR2 |= (1 << 6);
}



void spi_rx_irq_disable(spi_registers_t *spi_port)
{
    spi_port->CR2 &= ~(1 << 6);
}



void spi_tx_irq_handler(spi_registers_t *spi_port, uint8_t *tx_buffer,
    uint32_t *bytes_to_send)
{
    if( (spi_port->CR1 & ( 1 << 11)) == 0 ) {
        spi_port->DR = *tx_buffer;
        *bytes_to_send -= 1;
        tx_buffer++;
    } else {
        spi_port->DR = *((uint16_t*)tx_buffer);
        *bytes_to_send -= 2;
        (uint16_t *)tx_buffer++;
    }
    
    if(*bytes_to_send == 0) {
        spi_tx_irq_disable(spi_port);
    }
}

