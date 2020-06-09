/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#include "stm32f401xe_driver_rcc.h"

#include "stm32f401xe.h"



/*****************************************************************************/
/* RCC API DEFINITIONS */
/*****************************************************************************/

rcc_system_clock_source_t rcc_get_system_clock_source(void)
{
   return ( (RCC->CFGR >> 2) & 0x3 );
}



rcc_system_clock_source_speed_t rcc_get_system_clock_source_speed(
    rcc_system_clock_source_t clock_source)
{
    if(clock_source == rcc_system_clock_source_hsi) {
        return rcc_system_clock_source_speed_hsi;
    } else if(clock_source == rcc_system_clock_source_hse) {
        return rcc_system_clock_source_speed_hse;
    }
}



rcc_ahb_prescaler_t rcc_get_ahb_prescaler(void)
{
    uint8_t hpre_register_value = ( (RCC->CFGR >> 4) & 0xF );

    if(hpre_register_value < 8) {
        return rcc_ahb_prescaler_1;
    } else if(hpre_register_value == 8) {
        return rcc_ahb_prescaler_2;
    } else if(hpre_register_value == 9) {
        return rcc_ahb_prescaler_4;
    } else if(hpre_register_value == 10) {
        return rcc_ahb_prescaler_8; 
    } else if(hpre_register_value == 11) {
        return rcc_ahb_prescaler_16;
    } else if(hpre_register_value == 12) {
        return rcc_ahb_prescaler_64;
    } else if(hpre_register_value == 13) {
        return rcc_ahb_prescaler_128;
    } else if(hpre_register_value == 14) {
        return rcc_ahb_prescaler_256;
    } else if(hpre_register_value == 15) {
        return rcc_ahb_prescaler_512;
    }
}

