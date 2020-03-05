#include "dma.h"
#include "gpio.h"
#include "led.h"
#include "main.h"
#include "usart.h"

#include "FreeRTOS.h"
#include "task.h"




/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DECLARATIONS                        */
/*****************************************************************************/

static void prvSetupHardware(void);
static void SystemClock_Config(void);



/*****************************************************************************/
/*                             MAIN FUNCTION                                 */
/*****************************************************************************/

int main(void)
{
  prvSetupHardware();

  xTaskCreate(vLEDTask, "LEDTask", 100, NULL, 1, NULL);

  vTaskStartScheduler();

  while (1);

  return 0;
}



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DEFINITIONS                         */
/*****************************************************************************/

static void prvSetupHardware(void)
{
  HAL_Init();
  SystemClock_Config();

  GPIOA_Clock_Config();
  GPIOA_LED2_Config();
  GPIOA_USART1_RX_Config();

  DMA2_Clock_Config();
  DMA2_USART1_RX_Config();
  DMA2_USART1_RX_NVIC_Config();

  USART1_Clock_Config();
  USART1_RX_Config();
}



static void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}



void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}
