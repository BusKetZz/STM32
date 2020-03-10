#include "main.h"

#include "cmsis_os.h"

#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_utils.h"


osThreadId_t IdleTaskHandle;
const osThreadAttr_t IdleTask_attributes = {
  .name = "IdleTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DECLARATIONS                        */
/*****************************************************************************/

static void SYSCFG_PWR_Clock_Enable(void);
static void NVIC_PendSV_SysTick_IRQn_Config(void);
static void SystemClock_Config(void);

void StartIdleTask(void *argument);



/*****************************************************************************/
/*                                 MAIN                                      */
/*****************************************************************************/

int main(void)
{
  SYSCFG_PWR_Clock_Enable();
  NVIC_PendSV_SysTick_IRQn_Config();
  SystemClock_Config();


  osKernelInitialize();

  IdleTaskHandle = osThreadNew(StartIdleTask, NULL, &IdleTask_attributes);

  osKernelStart();
 
  while(1);

  return 0;
}



/*****************************************************************************/
/*                     PRIVATE FUNCTIONS DEFINITIONS                         */
/*****************************************************************************/

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



void StartIdleTask(void *argument)
{
  for(;;)
  {
    osDelay(1);
  }
}



void Error_Handler(void)
{

}
