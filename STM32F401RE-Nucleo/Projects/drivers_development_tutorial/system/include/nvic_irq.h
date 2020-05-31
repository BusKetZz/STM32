/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef CORTEX_M4_H
#define CORTEX_M4_H



/*****************************************************************************/
/* NVIC IRQ NUMBERS */
/*****************************************************************************/

typedef enum nvic_irq_number {
    nvic_irq_wwdg = 0,
    nvic_irq_pvd,
    nvic_irq_tamp_stamp,
    nvic_irq_rtc_wkup,
    nvic_irq_flash,
    nvic_irq_rcc,
    nvic_irq_exti0,
    nvic_irq_exti1,
    nvic_irq_exti2,
    nvic_irq_exti3,
    nvic_irq_exti4,
    nvic_irq_dma1_stream0,
    nvic_irq_dma1_stream1,
    nvic_irq_dma1_stream2,
    nvic_irq_dma1_stream3,
    nvic_irq_dma1_stream4,
    nvic_irq_dma1_stream5,
    nvic_irq_dma1_stream6,
    nvic_irq_adc,
    nvic_irq_exti9_5 = 23,
    nvic_irq_tim1_brk_tim9,
    nvic_irq_tim1_up_tim10,
    nvic_irq_tim1_trg_com_tim11,
    nvic_irq_tim1_cc,
    nvic_irq_tim2,
    nvic_irq_tim3,
    nvic_irq_tim4,
    nvic_irq_i2c1_ev,
    nvic_irq_i2c1_er,
    nvic_irq_i2c2_ev,
    nvic_irq_i2c2_er,
    nvic_irq_spi1,
    nvic_irq_spi2,
    nvic_irq_usart1,
    nvic_irq_usart2,
    nvic_irq_exti15_10 = 40,
    nvic_irq_rtc_alarm,
    nvic_irq_otg_fs_wkup,
    nvic_irq_dma1_stream7 = 47,
    nvic_irq_sdio = 49,
    nvic_irq_tim5,
    nvic_irq_spi3,
    nvic_irq_dma2_stream0 = 56,
    nvic_irq_dma2_stream1,
    nvic_irq_dma2_stream2,
    nvic_irq_dma2_stream3,
    nvic_irq_dma2_stream4,
    nvic_irq_otg_fs = 67,
    nvic_irq_dma2_stream5,
    nvic_irq_dma2_stream6,
    nvic_irq_dma2_stream7,
    nvic_irq_usart6,
    nvic_irq_i2c3_ev,
    nvic_irq_i2c3_er,
    nvic_irq_fpu = 81,
    nvic_irq_spi4 = 84
}nvic_irq_number_t;



typedef enum nvic_irq_priority {
    nvic_irq_priority_7 = 7,
    nvic_irq_priority_8,
    nvic_irq_priority_9,
    nvic_irq_priority_10,
    nvic_irq_priority_11,
    nvic_irq_priority_12,
    nvic_irq_priority_13,
    nvic_irq_priority_14,
    nvic_irq_priority_15,
    nvic_irq_priority_16,
    nvic_irq_priority_17,
    nvic_irq_priority_18,
    nvic_irq_priority_19,
    nvic_irq_priority_20,
    nvic_irq_priority_21,
    nvic_irq_priority_22,
    nvic_irq_priority_23,
    nvic_irq_priority_24,
    nvic_irq_priority_25,
    nvic_irq_priority_30 = 30,
    nvic_irq_priority_31,
    nvic_irq_priority_32,
    nvic_irq_priority_33,
    nvic_irq_priority_34,
    nvic_irq_priority_35,
    nvic_irq_priority_36,
    nvic_irq_priority_37,
    nvic_irq_priority_38,
    nvic_irq_priority_39,
    nvic_irq_priority_40,
    nvic_irq_priority_41,
    nvic_irq_priority_42,
    nvic_irq_priority_43,
    nvic_irq_priority_44,
    nvic_irq_priority_45,
    nvic_irq_priority_47 = 47,
    nvic_irq_priority_48,
    nvic_irq_priority_49,
    nvic_irq_priority_54 = 54,
    nvic_irq_priority_56 = 56,
    nvic_irq_priority_57,
    nvic_irq_priority_58,
    nvic_irq_priority_63 = 63,
    nvic_irq_priority_64,
    nvic_irq_priority_65,
    nvic_irq_priority_66,
    nvic_irq_priority_67,
    nvic_irq_priority_74 = 74,
    nvic_irq_priority_75,
    nvic_irq_priority_76,
    nvic_irq_priority_77,
    nvic_irq_priority_78,
    nvic_irq_priority_79,
    nvic_irq_priority_80,
    nvic_irq_priority_88 = 88,
    nvic_irq_priority_91 = 91
}nvic_irq_priority_t;



/*****************************************************************************/
/* NVIC REGISTERS BASE ADDRESSES */
/*****************************************************************************/

#define NVIC_ISER0_BASE_ADDRESS (volatile uint32_t *)0xE000E100
#define NVIC_ISER1_BASE_ADDRESS (volatile uint32_t *)0xE000E104
#define NVIC_ISER2_BASE_ADDRESS (volatile uint32_t *)0xE000E108
#define NVIC_ISER3_BASE_ADDRESS (volatile uint32_t *)0xE000E10C



#define NVIC_ICER0_BASE_ADDRESS (volatile uint32_t *)0xE000E180
#define NVIC_ICER1_BASE_ADDRESS (volatile uint32_t *)0xE000E184
#define NVIC_ICER2_BASE_ADDRESS (volatile uint32_t *)0xE000E188
#define NVIC_ICER3_BASE_ADDRESS (volatile uint32_t *)0xE000E18C



/*****************************************************************************/
/* NVIC IRQ API PROTOTYPES */
/*****************************************************************************/

void nvic_irq_priority_config(nvic_irq_number_t irq_number,
    nvic_irq_priority_t irq_priority);
void nvic_irq_enable(nvic_irq_number_t);
void nvic_irq_disable(nvic_irq_number_t);



#endif /* CORTEX_M4_H */ 

