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

#include "system_stm32f4xx.h"



/*****************************************************************************/
/* PUBLIC EXTERNAL VARIABLES */
/*****************************************************************************/

extern uint32_t SystemCoreClock;



/*****************************************************************************/
/* PRIVATE VARIABLES */
/*****************************************************************************/

static volatile uint32_t delay_time = 0;



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void delay_timer_init(void)
{
    while (SysTick_Config(SystemCoreClock / 1000) != 0) {
        ;
    }
}



void delay_ms(uint32_t delay_time_ms)
{
    delay_time = delay_time_ms;
    while (delay_time != 0) {
        ;
    }
}



/*****************************************************************************/
/* INTERRUPT HANDLER */
/*****************************************************************************/

void SysTick_Handler(void)
{
    if (delay_time != 0) {
        delay_time--;
    }
}

