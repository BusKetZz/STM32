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



/*****************************************************************************/
/* I2C RESET MACROS */
/*****************************************************************************/

#define I2C1_RESET()    do{ (RCC->APB1RSTR |= (1 << 21));\
    (RCC->APB1RSTR &= ~(1 << 21)); }while(0)
#define I2C2_RESET()    do{ (RCC->APB1RSTR |= (1 << 22));\
    (RCC->APB1RSTR &= ~(1 << 22)); }while(0)
#define I2C3_RESET()    do{ (RCC->APB1RSTR |= (1 << 23));\
    (RCC->APB1RSTR &= ~(1 << 23)); }while(0)



/*****************************************************************************/
/* I2C API DEFINITIONS */
/*****************************************************************************/

void i2c_clock_enable(i2c_registers_t *i2c_port)
{
    if(i2c_port == I2C1) {
        I2C1_CLOCK_ENABLE();
    } else if(i2c_port == I2C2) {
        I2C2_CLOCK_ENABLE();
    } else if(i2c_port == I2C3) {
        I2C3_CLOCK_ENABLE();
    }
}

