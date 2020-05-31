/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */



#include "nvic_irq.h"



/*****************************************************************************/
/* NVIC IRQ API DEFINITIONS */
/*****************************************************************************/

void nvic_irq_enable(nvic_irq_number_t irq_number)
{
    if(irq_number <= 31) {
        *NVIC_ISER0_BASE_ADDRESS |= (1 << irq_number);
    } else if(irq_number > 31 && irq_number <= 63) {
        *NVIC_ISER1_BASE_ADDRESS |= (1 << (irq_number % 32));
    } else if(irq_number > 63 && irq_number <= 95) {
        *NVIC_ISER2_BASE_ADDRESS |= (1 << (irq_number % 64));
    }
}



void nvic_irq_disable(nvic_irq_number_t irq_number)
{
    if(irq_number <= 31) {
        *NVIC_ICER0_BASE_ADDRESS |= (1 << irq_number);
    } else if(irq_number > 31 && irq_number <= 63) {
        *NVIC_ICER1_BASE_ADDRESS |= (1 << (irq_number % 32));
    } else if(irq_number > 63 && irq_number <= 95) {
        *NVIC_ICER2_BASE_ADDRESS |= (1 << (irq_number % 64));
    } 
}

