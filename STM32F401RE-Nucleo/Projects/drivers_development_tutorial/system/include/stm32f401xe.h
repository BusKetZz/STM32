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



#endif /* STM32F401XE_SYSTEM_H */

