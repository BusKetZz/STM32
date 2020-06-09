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



typedef enum rcc_system_clock_source_speed {
    rcc_system_clock_source_speed_hsi = 16000000,
    rcc_system_clock_source_speed_hse = 8000000
}rcc_system_clock_source_speed_t;



/*****************************************************************************/
/* RCC API PROTOTYPES */
/*****************************************************************************/

rcc_system_clock_source_t rcc_get_system_clock_source(void);
rcc_system_clock_source_speed_t rcc_get_system_clock_source_speed(
    rcc_system_clock_source_t clock_source);

rcc_ahb_prescaler_t rcc_get_ahb_prescaler(void);



#endif /* STM32F401XE_DRIVER_RCC_H */   

