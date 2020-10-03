/*
 * Author: Jakub Standarski
 * Email: jstand.jakub.standarski@gmail.com
 *
 * Date: 30.09.2020
 *
 */

#ifndef LED_H
    #define LED_H

/*****************************************************************************/
/* PUBLIC ENUMS */
/*****************************************************************************/

typedef enum led_pin {
    LED_PIN_BOARD_GREEN,
    LED_PIN_BOARD_ORANGE,
    LED_PIN_BOARD_RED,
    LED_PIN_BOARD_BLUE
}led_pin_t;



/*****************************************************************************/
/* PUBLIC FUNCTIONS PROTOTYPES */
/*****************************************************************************/

void led_pin_init(led_pin_t led_pin);
void led_pin_turn_on(led_pin_t led_pin);
void led_pin_turn_off(led_pin_t led_pin);
void led_pin_toggle(led_pin_t led_pin);



#endif /* LED_H */

