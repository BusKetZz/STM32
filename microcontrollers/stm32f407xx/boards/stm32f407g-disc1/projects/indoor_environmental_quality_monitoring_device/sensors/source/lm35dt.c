/*
 * Author: Jakub Standarski
 * Email: jstand.jakub.standarski@gmail.com
 *
 * Date: 03.10.2020
 *
 */

/*****************************************************************************/
/* HEADERS */
/*****************************************************************************/

#include "lm35dt.h"

#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"



/*****************************************************************************/
/* PRIVATE DEFINES */
/*****************************************************************************/

#define LM35DT_ADC_GPIO_PORT_CLOCK     LL_AHB1_GRP1_PERIPH_GPIOC
#define LM35DT_ADC_GPIO_PORT           GPIOC
#define LM35DT_ADC_GPIO_PIN            LL_GPIO_PIN_0

#define LM35DT_ADC_PERIPHERAL_CLOCK    LL_APB2_GRP1_PERIPH_ADC1
#define LM35DT_ADC_PERIPHERAL          ADC1



/*****************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES */
/*****************************************************************************/

static void lm35dt_adc_gpio_pin_init(void);

static void lm35dt_adc_peripheral_init(void);



/*****************************************************************************/
/* PUBLIC FUNCTIONS DEFINITIONS */
/*****************************************************************************/

void lm35dt_init(void)
{
    lm35dt_adc_gpio_pin_init();

    lm35dt_adc_peripheral_init();
}



/*****************************************************************************/
/* PRIVATE FUNCTIONS DEFINITIONS */
/*****************************************************************************/

static void lm35dt_adc_gpio_pin_init(void)
{
    LL_AHB1_GRP1_EnableClock(LM35DT_ADC_GPIO_PORT_CLOCK);

    LL_GPIO_InitTypeDef lm35dt_adc_gpio_pin_settings = {
        .Pin = LM35DT_ADC_GPIO_PIN,
        .Mode = LL_GPIO_MODE_ANALOG,
        .Speed = LL_GPIO_SPEED_FREQ_HIGH,
        .Pull = LL_GPIO_PULL_NO
    };
    LL_GPIO_Init(LM35DT_ADC_GPIO_PORT, &lm35dt_adc_gpio_pin_settings);
}



static void lm35dt_adc_peripheral_init(void)
{
    LL_APB2_GRP1_EnableClock(LM35DT_ADC_PERIPHERAL_CLOCK);

    LL_ADC_CommonInitTypeDef adc_common_settings = {
        .CommonClock = LL_ADC_CLOCK_SYNC_PCLK_DIV8
    };
    LL_ADC_CommonInit(ADC123_COMMON, &adc_common_settings);


    LL_ADC_InitTypeDef adc_instance_settings = {
        .Resolution = LL_ADC_RESOLUTION_12B,
        .DataAlignment = LL_ADC_DATA_ALIGN_RIGHT,
        .SequencersScanMode = LL_ADC_SEQ_SCAN_DISABLE
    };
    LL_ADC_Init(LM35DT_ADC_PERIPHERAL, &adc_instance_settings);


    LL_ADC_REG_InitTypeDef adc_regular_settings = {
        .TriggerSource = LL_ADC_REG_TRIG_SOFTWARE,
        .ContinuousMode = LL_ADC_REG_CONV_CONTINUOUS
    };
    LL_ADC_REG_Init(LM35DT_ADC_PERIPHERAL, &adc_regular_settings);

    LL_ADC_EnableIT_EOCS(LM35DT_ADC_PERIPHERAL);
    LL_ADC_Enable(LM35DT_ADC_PERIPHERAL);
}

