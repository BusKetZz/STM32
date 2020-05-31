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

void nvic_irq_priority_config(nvic_irq_number_t irq_number,
    nvic_irq_priority_t irq_priority)
{
    const uint8_t priority_bits_amount = 4;

    uint8_t ipr_register_number = irq_number / 4;
    uint8_t ipr_register_section = irq_number % 4;

    uint8_t shift_in_register = (8 * ipr_register_section) + (8 -
        priority_bits_amount);

    *(NVIC_IPR0_BASE_ADDRESS + (ipr_register_number * 4)) |= (irq_priority <<
        shift_in_register);
}



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

