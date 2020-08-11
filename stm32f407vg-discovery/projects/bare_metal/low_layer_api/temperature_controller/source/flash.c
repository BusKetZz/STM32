/*
 * Author: Jakub Standarski
 * Date: 11.08.2020
 *
 */



/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "flash.h"

#include "stm32f4xx.h"

#include "stm32f4xx_ll_system.h"



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void flash_set_latency(void)
{
    LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

    while (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_0) {
        ;
    }
}

