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
/* PRIVATE DEFINES */
/*****************************************************************************/

#define SYSTICKS_COUNT    SYSTEM_CLOCK_HSI_VALUE



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void system_clock_init(void)
{
    LL_RCC_HSI_Enable();
    while (LL_RCC_HSI_IsReady() != 1) {
        ;
    }

    LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI) {
        ;
    }

    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
}



void system_clock_systick_config_init(void)
{
    SysTick_Config(SYSTICKS_COUNT);
}



/*****************************************************************************/
/* INTERRUPT HANDLERS DEFINITIONS */
/*****************************************************************************/

void SysTick_Handler(void)
{
    led_toggle(LED_PIN_BOARD_GREEN);
}

