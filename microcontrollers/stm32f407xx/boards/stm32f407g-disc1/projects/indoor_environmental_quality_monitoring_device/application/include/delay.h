/*
 * Author: Jakub Standarski
 * Email: jstand.jakub.standarski@gmail.com
 *
 * Date: 05.10.2020
 *
 */

#ifndef DELAY_H
    #define DELAY_H

/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include <stdint.h>



/*****************************************************************************/
/* PUBLIC FUNCTIONS PROTOTYPES */
/*****************************************************************************/

/**
 * @brief   Initialize timer (timer 2) settings, responsible of delay
 *          functions.
 *
 * @param   None.
 *
 * @retval  None.
 */
void delay_timer_init(void);



/**
 * @brief   Wait desired amount of microseconds (blocking function).
 *
 * @param   delay_time_us - delay time given in microseconds.
 *
 * @retval  None.
 */
void delay_us(uint32_t delay_time_us);



/**
 * @brief   Wait desired amount of milliseconds (blocking function).
 *
 * @param   delay_time_ms - delay time given in milliseconds.
 *
 * @retval  None.
 */
void delay_ms(uint32_t delay_time_ms);



#endif /* DELAY_H */

