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

/**
 * @brief   Initialize LED pin configuration and its clock.
 *
 * @param   led_pin - LED pin being a member of @ref led_pin_t.
 *
 * @retval  None.
 */
void led_pin_init(led_pin_t led_pin);



/**
 * @brief   Turn on LED pin.
 *
 * @param   led_pin - LED pin being a member of @ref led_pin_t.
 *
 * @retval  None.
 */
void led_pin_turn_on(led_pin_t led_pin);



/**
 * @brief   Turn off LED pin.
 *
 * @param   led_pin - LED pin being a member of @ref led_pin_t.
 *
 * @retval  None.
 */
void led_pin_turn_off(led_pin_t led_pin);



/**
 * @brief   Toggle LED pin.
 *
 * @param   led_pin - LED pin being a member of @ref led_pin_t.
 *
 * @retval  None.
 */
void led_pin_toggle(led_pin_t led_pin);



#endif /* LED_H */

