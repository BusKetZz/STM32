#ifndef ADC_TEMPERATURE_REGULATOR_H
#define ADC_TEMPERATURE_REGULATOR_H

#ifdef  __cplusplus
extern "C"
{
#endif



/*****************************************************************************/
/*                    PUBLIC FUNCTIONS DECLARATIONS                          */
/*****************************************************************************/

void ADC1_TEMPERATURE_REGULATOR_Clock_Config(void);
void ADC1_TEMPERATURE_REGULATOR_Settings_Config(void);



/*****************************************************************************/
/*                         RTOS TASK DECLARATION                             */
/*****************************************************************************/

void StartAdc1TemperatureRegulatorTask(void *argument);



#ifdef  __cplusplus
}
#endif

#endif  /* ADC_TEMPERATURE_REGULATOR_H */
