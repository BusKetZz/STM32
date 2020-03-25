#include "adc_temperature_regulator.h"

#include "cmsis_os2.h"

#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_bus.h"



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
}



/*****************************************************************************/
/*                         RTOS TASK DEFINITION                              */
/*****************************************************************************/

void StartAdc1TemperatureRegulatorTask(void *argument)
{


  osDelay(1000);
}
