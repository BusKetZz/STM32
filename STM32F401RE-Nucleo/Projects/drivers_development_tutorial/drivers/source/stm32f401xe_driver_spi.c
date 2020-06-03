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

