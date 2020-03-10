#ifndef DMA_H
#define DMA_H

#ifdef  __cplusplus
extern "C"
{
#endif



/*****************************************************************************/
/*                    PUBLIC FUNCTIONS DECLARATIONS                          */
/*****************************************************************************/

void DMA2_Clock_Config(void);
void DMA2_USART1_RX_Config(void);
void DMA2_USART1_RX_NVIC_Config(void);



#ifdef  __cplusplus
}
#endif
 
#endif  /* DMA_H */
