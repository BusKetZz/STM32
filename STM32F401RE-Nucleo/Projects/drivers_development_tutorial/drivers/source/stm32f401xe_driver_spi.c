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

