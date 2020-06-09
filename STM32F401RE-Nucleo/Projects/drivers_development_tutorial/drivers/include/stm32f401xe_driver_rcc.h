/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef STM32F401XE_DRIVER_RCC_H
#define STM32F401XE_DRIVER_RCC_H

#include "stm32f401xe.h"



/*****************************************************************************/
/* RCC CONFIGURATION SETTINGS */
/*****************************************************************************/

typedef enum rcc_system_clock_source {
    rcc_system_clock_source_hsi = 0,
    rcc_system_clock_source_hse,
    rcc_system_clock_source_pll
}rcc_system_clock_source_t;



/*****************************************************************************/
/* RCC API PROTOTYPES */
/*****************************************************************************/

uint32_t rcc_get_system_clock_source(void);



#endif /* STM32F401XE_DRIVER_RCC_H */   

