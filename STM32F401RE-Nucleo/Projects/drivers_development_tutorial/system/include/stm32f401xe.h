/*
 * Project: Drivers development tutorial
 * Target MCU: STM32F401XE
 * Author: Jakub Standarski 
 *
 */

#ifndef STM32F401XE_H
#define STM32F401XE_H



#include <stdint.h>



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
/* FLASH AND SRAM BASE ADDRESSES */
/*****************************************************************************/

#define FLASH_BASE_ADDRESS          (uint32_t)0x08000000
#define SRAM_BASE_ADDRESS           (uint32_t)0x20000000
#define SYSTEM_MEMORY_BASE_ADDRESS  (uint32_t)0x1FFF0000



/*****************************************************************************/
/* APB AND AHB BASE ADDRESSES */
/*****************************************************************************/

#define APB1_BASE_ADDRESS   (uint32_t)0x40000000
#define APB2_BASE_ADDRESS   (uint32_t)0x40010000


#define AHB1_BASE_ADDRESS   (uint32_t)0x40020000
#define AHB2_BASE_ADDRESS   (uint32_t)0x50000000



/*****************************************************************************/
/* APB1 PERIPHERALS */
/*****************************************************************************/

/* Base addresses of Timer2 to Timer5 */

#define TIM2_BASE_ADDRESS   (uint32_t)(APB1_BASE_ADDRESS + 0x0)
#define TIM3_BASE_ADDRESS   (uint32_t)(APB1_BASE_ADDRESS + 0x0400)
#define TIM4_BASE_ADDRESS   (uint32_t)(APB1_BASE_ADDRESS + 0x0800)
#define TIM5_BASE_ADDRESS   (uint32_t)(APB1_BASE_ADDRESS + 0x0C00)



/* Base address of RTC & BKP Registers */

#define RTC_AND_BKP_REGISTERS_BASE_ADDRESS  (uint32_t)(APB1_BASE_ADDRESS +\
    0x2800)



/* Base address of WWDG */

#define WWDG_BASE_ADDRESS   (uint32_t)(APB1_BASE_ADDRESS + 0x2C00)



/* Base address of IWDG */

#define IWDG_BASE_ADDRESS   (uint32_t)(APB1_BASE_ADDRESS + 0x3000)



/* Base address of I2S2ext */

#define I2S2EXT_BASE_ADDRESS    (uint32_t)(APB1_BASE_ADDRESS + 0x3400)



/* Base addresses of SPI2/I2S2 and SPI3/I2S3 */

#define SPI2_I2S2_BASE_ADDRESS  (uint32_t)(APB1_BASE_ADDRESS + 0x3800)
#define SPI3_I2S3_BASE_ADDRESS  (uint32_t)(APB1_BASE_ADDRESS + 0x3C00)



/* Base address of I2S3ext */

#define I2S3EXT_BASE_ADDRESS    (uint32_t)(APB1_BASE_ADDRESS + 0x4000)



/* Base address of USART2 */

#define USART2_BASE_ADDRESS (uint32_t)(APB1_BASE_ADDRESS + 0x4400)



/* Base addresses of I2C1 to I2C3 */

#define I2C1_BASE_ADDRESS   (uint32_t)(APB1_BASE_ADDRESS + 0x5400)
#define I2C2_BASE_ADDRESS   (uint32_t)(APB1_BASE_ADDRESS + 0x5800)
#define I2C3_BASE_ADDRESS   (uint32_t)(APB1_BASE_ADDRESS + 0x5C00)



/* Base address of PWR */

#define PWR_BASE_ADDRESS    (uint32_t)(APB1_BASE_ADDRESS + 0x7000)



/*****************************************************************************/
/* APB2 PERIPHERALS */
/*****************************************************************************/

/* Base address of Timer1 */

#define TIM1_BASE_ADDRESS   (uint32_t)(APB2_BASE_ADDRESS + 0x0)



/* Base addresses of USART1 and USART6 */

#define USART1_BASE_ADDRESS (uint32_t)(APB2_BASE_ADDRESS + 0x1000)
#define USART6_BASE_ADDRESS (uint32_t)(APB2_BASE_ADDRESS + 0x1400)



/* Base address of ADC1 */

#define ADC1_BASE_ADDRESS   (uint32_t)(APB2_BASE_ADDRESS + 0x2000)



/* Base address of SDIO */

#define SDIO_BASE_ADDRESS   (uint32_t)(APB2_BASE_ADDRESS + 0x2C00)



/* Base addresses of SPI1 and SPI4 */

#define SPI1_BASE_ADDRESS   (uint32_t)(APB2_BASE_ADDRESS + 0x3000)
#define SPI4_BASE_ADDRESS   (uint32_t)(APB2_BASE_ADDRESS + 0x3400)



/* Base address of SYSCFG */

#define SYSCFG_BASE_ADDRESS (uint32_t)(APB2_BASE_ADDRESS + 0x3800)



/* Base address of EXTI */

#define EXTI_BASE_ADDRESS   (uint32_t)(APB2_BASE_ADDRESS + 0x3C00)



/* Base addresses of TIM9 to TIM11 */

#define TIM9_BASE_ADDRESS   (uint32_t)(APB2_BASE_ADDRESS + 0x4000)
#define TIM10_BASE_ADDRESS  (uint32_t)(APB2_BASE_ADDRESS + 0x4400)
#define TIM11_BASE_ADDRESS  (uint32_t)(APB2_BASE_ADDRESS + 0x4800)



/*****************************************************************************/
/* AHB1 PERIPHERALS */
/*****************************************************************************/

/* Base addresses of GPIOs */

#define GPIOA_BASE_ADDRESS  (uint32_t)(AHB1_BASE_ADDRESS + 0x0)
#define GPIOB_BASE_ADDRESS  (uint32_t)(AHB1_BASE_ADDRESS + 0x0400)
#define GPIOC_BASE_ADDRESS  (uint32_t)(AHB1_BASE_ADDRESS + 0x0800)
#define GPIOD_BASE_ADDRESS  (uint32_t)(AHB1_BASE_ADDRESS + 0x0C00)
#define GPIOE_BASE_ADDRESS  (uint32_t)(AHB1_BASE_ADDRESS + 0x1000)
#define GPIOH_BASE_ADDRESS  (uint32_t)(AHB1_BASE_ADDRESS + 0x1C00)



/* Base address of CRC */

#define CRC_BASE_ADDRESS    (uint32_t)(AHB1_BASE_ADDRESS + 0x3000)



/* Base address of RCC */

#define RCC_BASE_ADDRESS    (uint32_t)(AHB1_BASE_ADDRESS + 0x3800)



/* Base address of Flash interface register */

#define FLASH_INTERFACE_REGISTER_BASE_ADDRESS   (uint32_t)(AHB1_BASE_ADDRESS +\
    0x3C00)



/* Base addresses of DMAs */

#define DMA1_BASE_ADDRESS   (uint32_t)(AHB1_BASE_ADDRESS + 0x6000)
#define DMA2_BASE_ADDRESS   (uint32_t)(AHB1_BASE_ADDRESS + 0x6400)



/*****************************************************************************/
/* AHB2 PERIPHERALS */
/*****************************************************************************/

/* Base address of USB OTG FS */

#define USB_OTG_FS_BASE_ADDRESS (uint32_t)(AHB2_BASE_ADDRESS + 0x0)



/*****************************************************************************/
/* Peripheral registers structures and definitions */
/*****************************************************************************/

/* GPIO registers structure */

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
}gpio_registers_t;

#define GPIOA   ( (gpio_registers_t *)GPIOA_BASE_ADDRESS )
#define GPIOB   ( (gpio_registers_t *)GPIOB_BASE_ADDRESS )
#define GPIOC   ( (gpio_registers_t *)GPIOC_BASE_ADDRESS )
#define GPIOD   ( (gpio_registers_t *)GPIOD_BASE_ADDRESS )
#define GPIOE   ( (gpio_registers_t *)GPIOE_BASE_ADDRESS )
#define GPIOH   ( (gpio_registers_t *)GPIOH_BASE_ADDRESS )



/* RCC registers structure */

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    uint32_t reserved0[2];
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t reserved1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    uint32_t reserved2[2];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t reserved3[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    uint32_t reserved4[2];
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t reserved5[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t reserved6[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t DCKCFGR;
}rcc_registers_t;

#define RCC ( (rcc_registers_t *)RCC_BASE_ADDRESS )



/* EXTI registers structure */

typedef struct {
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
}exti_registers_t;

#define EXTI    ( (exti_registers_t *)EXTI_BASE_ADDRESS )



/* SYSCFG registers structure */

typedef struct {
    volatile uint32_t MEMRMP;
    volatile uint32_t PMC;
    volatile uint32_t EXTICR1;
    volatile uint32_t EXTICR2;
    volatile uint32_t EXTICR3;
    volatile uint32_t EXTICR4;
    uint32_t reserved[2];
    volatile uint32_t CMPCR;
}syscfg_registers_t;

#define SYSCFG  ( (syscfg_registers_t *)SYSCFG_BASE_ADDRESS )



#endif /* STM32F401XE_H */

