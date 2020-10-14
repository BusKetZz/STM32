/*
 * Author: Jakub Standarski
 * Email: jstand.jakub.standarski@gmail.com
 *
 * Date: 14.10.2020
 *
 */

#ifndef DEBUG_H
    #define DEBUG_H

/*****************************************************************************/
/* PUBLIC DEFINES */
/*****************************************************************************/

#define DEBUG_UART_GPIO_PORT        GPIOB
#define DEBUG_UART_GPIO_PORT_CLOCK  LL_AHB1_GRP1_PERIPH_GPIOB
#define DEBUG_UART_GPIO_PIN_TX      LL_GPIO_PIN_6

#define DEBUG_UART_PERIPHERAL       USART1
#define DEBUG_UART_PERIPHERAL_CLOCK LL_APB2_GRP1_PERIPH_USART1



/*****************************************************************************/
/* PUBLIC FUNCTIONS PROTOTYPES */
/*****************************************************************************/

void debug_uart_init(void);



#endif /* DEBUG_H */

