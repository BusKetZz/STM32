/*
 * Author: Jakub Standarski
 * Email: jstand.jakub.standarski@gmail.com
 *
 * Date: 05.10.2020
 *
 */

/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "delay.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_tim.h"



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void delay_timer_init(void)
{
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
    
    LL_TIM_InitTypeDef  delay_timer_settings = {
        .Prescaler = 16 - 1,
        .CounterMode = LL_TIM_COUNTERMODE_UP,
        .Autoreload = 0xFFFFFFFF,
        .ClockDivision = LL_TIM_CLOCKDIVISION_DIV1,
        .RepetitionCounter = 0x0
    };
    LL_TIM_Init(TIM2, &delay_timer_settings);
}



void delay_us(uint32_t delay_time_us)
{
    LL_TIM_SetCounter(TIM2, (uint32_t)0);
    LL_TIM_EnableCounter(TIM2);

    while (LL_TIM_GetCounter(TIM2) < delay_time_us) {
        ;
    }
    LL_TIM_DisableCounter(TIM2);
}



void delay_ms(uint32_t delay_time_ms)
{
    LL_TIM_SetCounter(TIM2, (uint32_t)0);
    LL_TIM_EnableCounter(TIM2);
    
    delay_time_ms *= 1000;
    while (LL_TIM_GetCounter(TIM2) < delay_time_ms) {
        ;
    }
    LL_TIM_DisableCounter(TIM2);
}

