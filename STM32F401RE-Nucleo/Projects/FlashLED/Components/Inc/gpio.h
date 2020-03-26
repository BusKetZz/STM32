#ifndef GPIO_H
#define GPIO_H

#ifdef  __cplusplus
extern "C"
{
#endif



/*****************************************************************************/
/*                    PUBLIC FUNCTIONS DECLARATIONS                          */
/*****************************************************************************/

void GPIOA_Clock_Config(void);
void GPIOA_TEMPERATURE_REGULATOR_Config(void);
void GPIOA_LED2_Config(void);
void GPIOA_USART1_TX_RX_Config(void);



#ifdef  __cplusplus
}
#endif
 
#endif  /* GPIO_H */
