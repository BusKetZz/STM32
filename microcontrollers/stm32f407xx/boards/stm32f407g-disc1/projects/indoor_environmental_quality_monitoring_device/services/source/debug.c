/*
 * Author: Jakub Standarski
 * Email: jstand.jakub.standarski@gmail.com
 *
 * Date: 14.10.2020
 *
 */

/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "debug.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_usart.h"



/*****************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES */
/*****************************************************************************/

static void debug_uart_gpio_init(void);
static void debug_uart_peripheral_init(void);



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void debug_uart_init(void)
{
    debug_uart_gpio_init();
    debug_uart_peripheral_init();
}



/*****************************************************************************/
/* PRIVATE FUNCTIONS DEFINITIONS */
/*****************************************************************************/

static void debug_uart_gpio_init(void)
{
    LL_AHB1_GRP1_EnableClock(DEBUG_UART_GPIO_PORT_CLOCK);

    LL_GPIO_InitTypeDef uart_gpio_settings = {
        .Pin = DEBUG_UART_GPIO_PIN_TX,
        .Mode = LL_GPIO_MODE_ALTERNATE,
        .Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH,
        .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
        .Pull = LL_GPIO_PULL_NO,
        .Alternate = LL_GPIO_AF_7
    };
    LL_GPIO_Init(DEBUG_UART_GPIO_PORT, &uart_gpio_settings);
}



static void debug_uart_peripheral_init(void)
{
    LL_APB2_GRP1_EnableClock(DEBUG_UART_PERIPHERAL_CLOCK);

    LL_USART_InitTypeDef uart_peripheral_settings = {
        .BaudRate = 9600,
        .DataWidth = LL_USART_DATAWIDTH_8B,
        .StopBits = LL_USART_STOPBITS_1,
        .Parity = LL_USART_PARITY_NONE,
        .TransferDirection = LL_USART_DIRECTION_TX,
        .HardwareFlowControl = LL_USART_HWCONTROL_NONE,
        .OverSampling = LL_USART_OVERSAMPLING_16
    };
    LL_USART_Init(DEBUG_UART_PERIPHERAL, &uart_peripheral_settings);


    LL_USART_ClockInitTypeDef uart_clock_settings = {
        .ClockOutput = LL_USART_CLOCK_DISABLE,
        .ClockPolarity = LL_USART_POLARITY_LOW,
        .ClockPhase = LL_USART_PHASE_1EDGE,
        .LastBitClockPulse = LL_USART_LASTCLKPULSE_NO_OUTPUT
    };
    LL_USART_ClockInit(DEBUG_UART_PERIPHERAL, &uart_clock_settings);
}

