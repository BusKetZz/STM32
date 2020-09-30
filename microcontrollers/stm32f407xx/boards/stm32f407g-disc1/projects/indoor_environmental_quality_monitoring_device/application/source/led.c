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

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void led_init(led_pin_t led_pin)
{
    LL_GPIO_InitTypeDef led_pin_config = {
        .Mode = LL_GPIO_MODE_OUTPUT,
        .Speed = LL_GPIO_SPEED_FREQ_LOW,
        .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
        .Pull = LL_GPIO_PULL_DOWN
    };

    switch (led_pin) {
        case LED_PIN_BOARD_GREEN:
            LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
            led_pin_config.Pin = LL_GPIO_PIN_12;
            LL_GPIO_Init(GPIOD, &led_pin_config);
            break;

        case LED_PIN_BOARD_ORANGE:
            LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
            led_pin_config.Pin = LL_GPIO_PIN_13;
            LL_GPIO_Init(GPIOD, &led_pin_config);
            break;

        case LED_PIN_BOARD_RED:
            LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
            led_pin_config.Pin = LL_GPIO_PIN_14;
            LL_GPIO_Init(GPIOD, &led_pin_config);
            break;

        case LED_PIN_BOARD_BLUE:
            LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
            led_pin_config.Pin = LL_GPIO_PIN_15;
            LL_GPIO_Init(GPIOD, &led_pin_config);
            break;
    }
}



void led_turn_on(led_pin_t led_pin)
{
    switch (led_pin) {
        case LED_PIN_BOARD_GREEN:
            LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_12);
            break;

        case LED_PIN_BOARD_ORANGE:
            LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_13);
            break;

        case LED_PIN_BOARD_RED:
            LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_14);
            break;

        case LED_PIN_BOARD_BLUE:
            LL_GPIO_SetOutputPin(GPIOD, LL_GPIO_PIN_15);
            break;
    }
}



void led_turn_off(led_pin_t led_pin)
{
    switch (led_pin) {
        case LED_PIN_BOARD_GREEN:
            LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_12);
            break;

        case LED_PIN_BOARD_ORANGE:
            LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_13);
            break;

        case LED_PIN_BOARD_RED:
            LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_14);
            break;

        case LED_PIN_BOARD_BLUE:
            LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_15);
            break;
    }
}

