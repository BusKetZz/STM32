#include "adc_temperature_regulator.h"

#include "cmsis_os2.h"

#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_bus.h"



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

#define NEGATIVE_TEMPERATURE_COUNT 30
#define POSITIVE_TEMPERATURE_COUNT 50
#define THERMISTOR_RESISTANCE_COUNT (NEGATIVE_TEMPERATURE_COUNT\
                                     + POSITIVE_TEMPERATURE_COUNT + 1)



/*****************************************************************************/
/*                             PRIVATE MACROS                                */
/*****************************************************************************/

#define ADC1_IS_CONVERSION_COMPLETE() LL_ADC_IsActiveFlag_EOCS(ADC1)



/*****************************************************************************/
/*                             PRIVATE ENUMS                                 */
/*****************************************************************************/

enum isAdc1Enabled
{
  ADC1_Disabled = 0,
  ADC1_Enabled  = 1
};



enum isAdc1ConversionComplete
{
  ADC1_Conversion_NotComplete = 0,
  ADC1_Conversion_Complete   = 1
};



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

static const int negativeTemperature[NEGATIVE_TEMPERATURE_COUNT] = {0};
static const int positiveTemperature[POSITIVE_TEMPERATURE_COUNT] = {0};
static const float thermistorResistance[THERMISTOR_RESISTANCE_COUNT] = {0};



/*****************************************************************************/
/*                     PUBLIC FUNCTIONS DEFINITIONS                          */
/*****************************************************************************/

void ADC1_TEMPERATURE_REGULATOR_Clock_Config(void)
{
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC1);
}



void ADC1_TEMPERATURE_REGULATOR_Settings_Config(void)
{
  LL_ADC_InitTypeDef ADC1_TEMPERATURE_REGULATOR_InitStruct =
  {
    .Resolution         = LL_ADC_RESOLUTION_12B,
    .DataAlignment      = LL_ADC_DATA_ALIGN_RIGHT,
    .SequencersScanMode = LL_ADC_SEQ_SCAN_DISABLE
  };
  LL_ADC_Init(ADC1, &ADC1_TEMPERATURE_REGULATOR_InitStruct);
  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_0,
                                LL_ADC_SAMPLINGTIME_480CYCLES);

  LL_ADC_REG_InitTypeDef ADC1_TEMPERATURE_REGULATOR_REG_InitStruct =
  {
    .TriggerSource    = LL_ADC_REG_TRIG_SOFTWARE,
    .SequencerLength  = LL_ADC_REG_SEQ_SCAN_DISABLE,
    .SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE,
    .ContinuousMode   = LL_ADC_REG_CONV_SINGLE,
    .DMATransfer      = LL_ADC_REG_DMA_TRANSFER_NONE 
  };
  LL_ADC_REG_Init(ADC1, &ADC1_TEMPERATURE_REGULATOR_REG_InitStruct);
  LL_ADC_REG_SetFlagEndOfConversion(ADC1, LL_ADC_REG_FLAG_EOC_UNITARY_CONV);
  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_0);

  LL_ADC_CommonInitTypeDef ADC1_TEMPERATURE_REGULATOR_CommonInitStruct =
  {
    .CommonClock = LL_ADC_CLOCK_SYNC_PCLK_DIV8
  };
  LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC1),
                    &ADC1_TEMPERATURE_REGULATOR_CommonInitStruct);

  LL_ADC_DisableIT_EOCS(ADC1);

  LL_ADC_Enable(ADC1);
  while(LL_ADC_IsEnabled(ADC1) != ADC1_Enabled)
  {
    ;
  }
}



/*****************************************************************************/
/*                         RTOS TASK DEFINITION                              */
/*****************************************************************************/

void StartAdc1TemperatureRegulatorTask(void *argument)
{
  uint32_t adcReadValue = 0;

  LL_ADC_REG_StartConversionSWStart(ADC1);

  for(;;)
  {
    while(ADC1_IS_CONVERSION_COMPLETE() != ADC1_Conversion_Complete)
    {
      ;
    }
    adcReadValue = LL_ADC_REG_ReadConversionData12(ADC1);


    osDelay(1000);
  }
}
