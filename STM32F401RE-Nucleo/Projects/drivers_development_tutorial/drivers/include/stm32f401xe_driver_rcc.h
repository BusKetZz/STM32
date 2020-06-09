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



typedef enum rcc_ahb_prescaler {
    rcc_ahb_prescaler_1 = 1,
    rcc_ahb_prescaler_2 = 2,
    rcc_ahb_prescaler_4 = 4,
    rcc_ahb_prescaler_8 = 8,
    rcc_ahb_prescaler_16 = 16,
    rcc_ahb_prescaler_64 = 64,
    rcc_ahb_prescaler_128 = 128,
    rcc_ahb_prescaler_256 = 256,
    rcc_ahb_prescaler_512 = 512
}rcc_ahb_prescaler_t;



typedef enum rcc_apb1_prescaler {
    rcc_apb1_prescaler_1 = 1,
    rcc_apb1_prescaler_2 = 2,
    rcc_apb1_prescaler_4 = 4,
    rcc_apb1_prescaler_8 = 8,
    rcc_apb1_prescaler_16 = 16
}rcc_apb1_prescaler_t;



/*****************************************************************************/
/* RCC API PROTOTYPES */
/*****************************************************************************/

rcc_system_clock_source_t rcc_get_system_clock_source(void);
rcc_system_clock_source_speed_t rcc_get_system_clock_source_speed(
    rcc_system_clock_source_t clock_source);

rcc_ahb_prescaler_t rcc_get_ahb_prescaler(void);



#endif /* STM32F401XE_DRIVER_RCC_H */   

