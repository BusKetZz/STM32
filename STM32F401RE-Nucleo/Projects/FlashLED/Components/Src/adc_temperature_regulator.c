#include "adc_temperature_regulator.h"
#include "dma.h"
#include "rtc.h"

#include "cmsis_os2.h"

#include "stm32f4xx.h"

#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_gpio.h"

#include <stdio.h>
#include <string.h>



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

#define RELAY_HEATER_GPIO_PIN   LL_GPIO_PIN_8
#define RELAY_HEATER_GPIO_PORT  GPIOA

#define ADC_MEASUREMENT_MIN  201
#define ADC_MEASUREMENT_MAX  3975

#define TEMPERATURE_SET_POINT 35.0f
#define TEMPERATURE_ALLOWABLE_MARGIN 0.25f

#define TEMPERATURE_COUNT 156
#define THERMISTOR_RESISTANCE_COUNT TEMPERATURE_COUNT




/*****************************************************************************/
/*                             PRIVATE MACROS                                */
/*****************************************************************************/

#define ADC1_IS_CONVERSION_COMPLETE() LL_ADC_IsActiveFlag_EOCS(ADC1)

#define TURN_ON_HEATER()   LL_GPIO_ResetOutputPin(RELAY_HEATER_GPIO_PORT,\
                                                  RELAY_HEATER_GPIO_PIN)
#define TURN_OFF_HEATER()  LL_GPIO_SetOutputPin(RELAY_HEATER_GPIO_PORT,\
                                                RELAY_HEATER_GPIO_PIN)



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



typedef enum heaterState
{
  Heater_On  = 0,
  Heater_Off = 1
}heaterState_t;



/*****************************************************************************/
/*                           REFERENCE TABLES                                */
/*****************************************************************************/

static const uint32_t thermistorResistanceTable[THERMISTOR_RESISTANCE_COUNT] =
{
 193500, 181461, 170268, 159850, 150146,
 141100, 132659, 124779, 117418, 110537,
 104101,  98079,  92440,  87159,  82210,
  77571,  73219,  69137,  65305,  61707,
  58328,  55153,  52169,  49363,  46724,
  44241,  41904,  39704,  37633,  35681,
  33800,  32108,  30474,  28932,  27477,
  26104,  24807,  23583,  22426,  21333,
  20300,  19322,  18398,  17523,  16695,
  15912,  15169,  14466,  13799,  13167,
  12568,  11999,  11460,  10948,  10461,
  10000,   9561,   9144,   8747,   8370,
   8011,   7670,   7345,   7036,   6741,
   6461,   6193,   5938,   5695,   5464,
   5242,   5031,   4830,   4638,   4454,
   4279,   4111,   3951,   3797,   3651,
   3511,   3377,   3248,   3126,   3008,
   2896,   2788,   2684,   2585,   2490,
   2400,   2312,   2229,   2148,   2071,
   1997,   1927,   1858,   1793,   1730,
   1670,   1612,   1556,   1503,   1451,
   1402,   1354,   1309,   1265,   1222,
   1181,   1142,   1104,   1068,   1033,
   1000,    967,    936,    906,    877,
    849,    822,    796,    771,    747,
    723,    701,    679,    658,    638,
    600,    600,    582,    564,    548,
    531,    516,    500,    486,    472,
    458,    445,    432,    419,    407,
    396,    385,    374,    364,    353,
    344,    334,    325,    316,    308,
    300
};

static const int temperatureTable[TEMPERATURE_COUNT] =
{
  -30, -29, -28, -27, -26,
  -25, -24, -23, -22, -21,
  -20, -19, -18, -17, -16,
  -15, -14, -13, -12, -11,
  -10,  -9,  -8,  -7,  -6,
   -5,  -4,  -3,  -2,  -1,
    0,   1,   2,   3,   4,
    5,   6,   7,   8,   9,
   10,  11,  12,  13,  14,
   15,  16,  17,  18,  19,
   20,  21,  22,  23,  24,
   25,  26,  27,  28,  29,
   30,  31,  32,  33,  34,
   35,  36,  37,  38,  39,
   40,  41,  42,  43,  44,
   45,  46,  47,  48,  49,
   50,  51,  52,  53,  54,
   55,  56,  57,  58,  59,
   60,  61,  62,  63,  64,
   65,  66,  67,  68,  69,
   70,  71,  72,  73,  74,
   75,  76,  77,  78,  79,
   80,  81,  82,  83,  84,
   85,  86,  87,  88,  89,
   90,  91,  92,  93,  94,
   95,  96,  97,  98,  99,
  100, 101, 102, 103, 104,
  105, 106, 107, 108, 109,
  110, 111, 112, 113, 114,
  115, 116, 117, 118, 119,
  120, 121, 122, 123, 124,
  125
};



/*****************************************************************************/
/*                           PRIVATE STRUCTURES                              */
/*****************************************************************************/

static struct __attribute__((packed))
{
  char dataString[40];
}feedbackMessage;




/*****************************************************************************/
/*                     PRIVATE FUNCTIONS PROTOTYPES                          */
/*****************************************************************************/

static uint32_t StartAndReadAdcConversion(void);
static uint32_t CalculateThermistorResistance(uint32_t adcMeasurement);
static float FindTemperature(uint32_t thermistorResistance);
static uint32_t FindTableIndex(uint32_t thermistorResistance);
static heaterState_t CheckHeaterState(void);
static void UpdateFeedbackMessage(heaterState_t heaterState,
  uint32_t adcMeasurement, float temperature);


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
  uint32_t adcMeasurement = 0;
  uint32_t thermistorResistance = 0;
  float temperature = 0;

  TURN_OFF_HEATER();

  for(;;)
  {
    adcMeasurement = StartAndReadAdcConversion();
    if(adcMeasurement < ADC_MEASUREMENT_MIN ||
      adcMeasurement > ADC_MEASUREMENT_MAX)
    {
      TURN_OFF_HEATER();
      osDelay(1000);
      continue;
    }

    thermistorResistance = CalculateThermistorResistance(adcMeasurement);
    temperature = FindTemperature(thermistorResistance);
    if(temperature <= TEMPERATURE_SET_POINT - TEMPERATURE_ALLOWABLE_MARGIN
      && CheckHeaterState() == Heater_Off) {
      TURN_ON_HEATER();
    }
    else if(temperature >= TEMPERATURE_SET_POINT + TEMPERATURE_ALLOWABLE_MARGIN
      && CheckHeaterState() == Heater_On) {
      TURN_OFF_HEATER();
    }
    

    UpdateFeedbackMessage(CheckHeaterState(), adcMeasurement, temperature);
    DMA2_USART1_TX_SendFeedbackMessage(&feedbackMessage,
      sizeof(feedbackMessage));

    osDelay(1000);
  }
}



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DEFINITIONS                         */
/*****************************************************************************/

static uint32_t StartAndReadAdcConversion(void)
{
  LL_ADC_REG_StartConversionSWStart(ADC1);
  while(ADC1_IS_CONVERSION_COMPLETE() == ADC1_Conversion_NotComplete)
  {
    ;
  }

  return LL_ADC_REG_ReadConversionData12(ADC1);
}



static uint32_t CalculateThermistorResistance(uint32_t adcMeasurement)
{
  const float adcResolution = 4095.0f;
  const float resistanceOfVoltageDividerResistor = 10000.0f;

  uint32_t thermistorResistance = resistanceOfVoltageDividerResistor *
                                  (adcResolution/adcMeasurement - 1.0f);
  return thermistorResistance;
}



static float FindTemperature(uint32_t thermistorResistance)
{
  uint32_t tableIndex = FindTableIndex(thermistorResistance);
  uint32_t referenceResistance = thermistorResistanceTable[tableIndex];
  int referenceTemperature = temperatureTable[tableIndex];

  const uint32_t interpolationStepsCount = 10;
  uint32_t interpolationStep = (thermistorResistanceTable[tableIndex] -
    thermistorResistanceTable[tableIndex + 1]) / interpolationStepsCount;

  uint32_t step;
  for(step = 1; step <= interpolationStepsCount; ++step){
    referenceResistance -= interpolationStep;
    if(referenceResistance <= thermistorResistance){
      break;
    }
  } 
  
  return referenceTemperature + 0.1*step;
}



static uint32_t FindTableIndex(uint32_t thermistorResistance)
{
  uint32_t tableIndex;
  for(tableIndex = 0; tableIndex < THERMISTOR_RESISTANCE_COUNT; ++tableIndex){
    if(thermistorResistance >= thermistorResistanceTable[tableIndex + 1]){
      break;
    }
  }

  return tableIndex;
}



static heaterState_t CheckHeaterState(void)
{
  if(LL_GPIO_IsInputPinSet(RELAY_HEATER_GPIO_PORT, RELAY_HEATER_GPIO_PIN) == 0)
  {
    return Heater_On;
  }
  else
  {
    return Heater_Off;
  }
}



static void UpdateFeedbackMessage(heaterState_t heaterState,
  uint32_t adcMeasurement, float temperature)
{
  memset(feedbackMessage.dataString, 0, sizeof(feedbackMessage.dataString));
  size_t dataStringOffset = 0;

  if(heaterState == Heater_On)
  {
    sprintf(feedbackMessage.dataString, "ON");
    dataStringOffset += strlen("ON");
  }
  else
  {
    sprintf(feedbackMessage.dataString, "OFF");
    dataStringOffset += strlen("OFF");
  }
  feedbackMessage.dataString[dataStringOffset] = ' ';
  ++dataStringOffset;

  sprintf(feedbackMessage.dataString + dataStringOffset, "%u", adcMeasurement);
  dataStringOffset += strlen(feedbackMessage.dataString);
  feedbackMessage.dataString[dataStringOffset] = ' ';
  ++dataStringOffset;

  int temperatureIntegerPart = temperature;
  float temperatureFraction = temperature - temperatureIntegerPart;
  int temperatureFractionalPart = temperatureFraction * 10;
  sprintf(feedbackMessage.dataString + dataStringOffset, "%d.%d",
    temperatureIntegerPart, temperatureFractionalPart);
  dataStringOffset += strlen(feedbackMessage.dataString);
  feedbackMessage.dataString[dataStringOffset] = ' ';
  ++dataStringOffset;

  time_t timeInSeconds = RTC_GetTimeInSeconds();
  sprintf(feedbackMessage.dataString + dataStringOffset, "%ld", timeInSeconds);

  feedbackMessage.dataString[sizeof(feedbackMessage.dataString) - 1] = '\n';
}
