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




#endif /* STM32F401XE_SYSTEM_H */

