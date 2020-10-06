/*
 * Author: Jakub Standarski
 * Email: jstand.jakub.standarski@gmail.com
 *
 * Date: 30.09.2020
 *
 */

/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "led.h"
#include "system_clock.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"



/*****************************************************************************/
/* PUBLIC EXTERN VARIABLES */
/*****************************************************************************/

extern uint32_t SystemCoreClock;



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void system_clock_init(void)
{
    LL_RCC_HSE_Enable();
    while (LL_RCC_HSE_IsReady() != 1) {
        ;
    }

    LL_FLASH_SetLatency(LL_FLASH_LATENCY_5);

    LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_8, 336,
        LL_RCC_PLLP_DIV_2);
    LL_RCC_PLL_Enable();
    while (LL_RCC_PLL_IsReady() != 1) {
        ;
    }

    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_2);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL) {
        ;
    }

    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);

    SystemCoreClock = 84000000;
}

