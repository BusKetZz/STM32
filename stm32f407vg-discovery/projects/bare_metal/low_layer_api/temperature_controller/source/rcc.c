/*
 * Author: Jakub Standarski
 * Date: 11.08.2020
 *
 */



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "rcc.h"

#include "stm32f4xx.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_rcc.h"



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void rcc_set_ahb_prescaler(void)
{
    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
}



void rcc_set_apb1_prescaler(void)
{
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
}




void rcc_system_clock_init(void)
{
    LL_RCC_HSI_SetCalibTrimming(16);

    LL_RCC_HSI_Enable();
    while (LL_RCC_HSI_IsReady != 1) {
        ;
    }

    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI) {
        ;
    }
}

