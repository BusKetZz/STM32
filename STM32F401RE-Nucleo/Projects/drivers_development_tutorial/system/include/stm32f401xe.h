#ifndef STM32F401XE_SYSTEM_H
#define STM32F401XE_SYSTEM_H



/* Base addresses of FLASH and SRAM */

#define FLASH_BASE_ADDRESS          (uint32_t)0x08000000
#define SRAM_BASE_ADDRESS           (uint32_t)0x20000000
#define SYSTEM_MEMORY_BASE_ADDRESS  (uint32_t)0x1FFF0000



/* Base addresses of AHB buses */

#define AHB1_BASE_ADDRESS   (uint32_t)0x40020000
#define AHB2_BASE_ADDRESS   (uint32_t)0x50000000



/* Base addresses of APB buses */

#define APB1_BASE_ADDRESS   (uint32_t)0x40000000
#define APB2_BASE_ADDRESS   (uint32_t)0x40010000



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



/* Base address of USB OTG FS */

#define USB_OTG_FS_BASE_ADDRESS (uint32_t)(AHB2_BASE_ADDRESS + 0x0)



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




#endif /* STM32F401XE_SYSTEM_H */

