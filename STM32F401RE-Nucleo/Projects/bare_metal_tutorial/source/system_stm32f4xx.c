#include <stm32f401xe.h>



#define SYSTEM_INIT_ERROR_FLASH  0x01
#define SYSTEM_INIT_ERROR_PLL    0x02
#define SYSTEM_INIT_ERROR_CLKSRC 0x04
#define SYSTEM_INIT_ERROR_HSI    0x08



void system_init_error(uint8_t system_init_error_code);



void SystemInit()
{
	// Enable Power Control clock
	RCC->APB1ENR |= RCC_APB1LPENR_PWRLPEN;
	
	// Regulator voltage scaling output selection: Scale 2
	PWR->CR |= PWR_CR_VOS_1;

	// Wait until HSI is ready
	while( ( RCC->CR & RCC_CR_HSIRDY ) == 0 ) {
		;
	}

	// Store calibration value
	PWR->CR |= (uint32_t)(16 << 3);

	// Disable main PLL
	RCC->CR &= ~(RCC_CR_PLLON);
	// Wait until PLL is ready (disabled)
	while( ( RCC->CR & RCC_CR_PLLRDY ) != 0 ) {
		;
	}

	/*
	 * Configure main PLL:
	 * HSI as clock input
	 * fvco = 336 [MHz]
	 * fpllout = 84 [MHz]
	 * fusb = 48 [MHz]
	 * PLLM = 16
	 * PLLN = 336
	 * PLLP = 4
	 * PLLQ = 7
	 */
	RCC->PLLCFGR = (uint32_t)( (uint32_t)0x20000000 | (uint32_t)(16 << 0) |
		(uint32_t)(336 << 6) | RCC_PLLCFGR_PLLP_0 | (uint32_t)(7 << 24) );

	// Turn on PLL
	RCC->CR |= RCC_CR_PLLON;
	// Wait until PLL is locked
	while( ( RCC->CR & RCC_CR_PLLRDY ) == 0 ) {
		;	
	}

	/*
	 * FLASH configuration block:
	 * enable instruction cache
	 * enable prefetch
	 * set latency to 2WS (3 CPU cycles)
	 */
	FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_2WS;

	// Check FLASH latency
	if( ( FLASH->ACR & FLASH_ACR_LATENCY ) != FLASH_ACR_LATENCY_2WS ) {
		system_init_error(SYSTEM_INIT_ERROR_FLASH);
	}

	// Set clock source to PLL
	RCC->CFGR &= ~(RCC_CFGR_HPRE);
	// Check clock source
	while( ( RCC->CFGR & RCC_CFGR_SWS_PLL ) != RCC_CFGR_SWS_PLL ) {
		;
	}

	// Set HCLK (AHB1) prescaler (DIV1)
	RCC->CFGR &= ~(RCC_CFGR_HPRE);

	// Set APB1 low speed prescaler DIV2
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

	// Set APB2 high speed prescaler DIV1
	RCC->CFGR &= ~(RCC_CFGR_PPRE2);
}



void system_init_error(uint8_t system_init_error_code)
{
	while(1) {
		;
	}
}

