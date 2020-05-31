/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef CORTEX_M4_H
#define CORTEX_M4_H



/*****************************************************************************/
/* NVIC REGISTERS BASE ADDRESSES */
/*****************************************************************************/

#define NVIC_ISER0_BASE_ADDRESS (volatile uint32_t *)0xE000E100
#define NVIC_ISER1_BASE_ADDRESS (volatile uint32_t *)0xE000E104
#define NVIC_ISER2_BASE_ADDRESS (volatile uint32_t *)0xE000E108
#define NVIC_ISER3_BASE_ADDRESS (volatile uint32_t *)0xE000E10C



#endif /* CORTEX_M4_H */ 

