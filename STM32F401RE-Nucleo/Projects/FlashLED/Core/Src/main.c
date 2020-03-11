#include "dma.h"
#include "gpio.h"
#include "led.h"
#include "main.h"
#include "idle_task.h"
#include "usart.h"

#include "cmsis_os.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_utils.h"



/*****************************************************************************/
/*                  PRIVATE RTOS VARIABLES DECLARATIONS                      */
/*****************************************************************************/

osThreadId_t IdleTaskHandle;
const osThreadAttr_t IdleTaskAttributes =
{
  .name = "IdleTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

osThreadId_t Led2TaskHandle;
const osThreadAttr_t Led2TaskAttributes =
{
  .name = "Led2Task",
  .priority = (osPriority_t)osPriorityNormal1,
  .stack_size = 128 * 4
};



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DECLARATIONS                        */
/*****************************************************************************/

static void HardwareInitialSetup(void);
static void SYSCFG_PWR_Clock_Enable(void);
static void NVIC_PendSV_SysTick_IRQn_Config(void);
static void SystemClock_Config(void);
static void ComponentsSetup(void);



/*****************************************************************************/
/*                                 MAIN                                      */
/*****************************************************************************/

int main(void)
{
  HardwareInitialSetup();
  ComponentsSetup();

  osKernelInitialize();

  IdleTaskHandle = osThreadNew(StartIdleTask, NULL, &IdleTaskAttributes);
  Led2TaskHandle = osThreadNew(StartLed2Task, NULL, &Led2TaskAttributes);

  osKernelStart();
 
  while(1);

  return 0;
}



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DEFINITIONS                         */
/*****************************************************************************/

static void HardwareInitialSetup(void)
{
  SYSCFG_PWR_Clock_Enable();
  NVIC_PendSV_SysTick_IRQn_Config();
  SystemClock_Config();
}



static void SYSCFG_PWR_Clock_Enable(void)
{
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
}



static void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

  if(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_0)
  {
  Error_Handler();  
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE2);
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_HSI_Enable();

  while(LL_RCC_HSI_IsReady() != 1)
  {
    
  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {
  
  }
  LL_Init1msTick(16000000);
  LL_SetSystemCoreClock(16000000);
  LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_TWICE);
}



static void NVIC_PendSV_SysTick_IRQn_Config(void)
{
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  NVIC_SetPriority(PendSV_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));
}



static void ComponentsSetup(void)
{
  GPIOA_Clock_Config();
  GPIOA_LED2_Config();

  DMA2_Clock_Config();
  DMA2_USART1_RX_Config();
  DMA2_USART1_RX_NVIC_Config();

  USART1_Clock_Config();
  USART1_RX_Config();
}



void Error_Handler(void)
{
  /* TODO */
}
