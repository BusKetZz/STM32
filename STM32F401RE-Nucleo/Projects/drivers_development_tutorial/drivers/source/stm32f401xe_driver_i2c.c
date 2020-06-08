/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#include "stm32f401xe_driver_i2c.h"

#include "stm32f401xe.h"



/*****************************************************************************/
/* I2C CLOCK ENABLE AND DISABLE MACROS */
/*****************************************************************************/

#define I2C1_CLOCK_ENABLE() ( RCC->APB1ENR |= (1 << 21) )
#define I2C2_CLOCK_ENABLE() ( RCC->APB1ENR |= (1 << 22) )
#define I2C3_CLOCK_ENABLE() ( RCC->APB1ENR |= (1 << 23) )



#define I2C1_CLOCK_DISABLE()    ( RCC->APB1ENR &= ~(1 << 21) )
#define I2C2_CLOCK_DISABLE()    ( RCC->APB1ENR &= ~(1 << 22) )
#define I2C3_CLOCK_DISABLE()    ( RCC->APB1ENR &= ~(1 << 23) )

