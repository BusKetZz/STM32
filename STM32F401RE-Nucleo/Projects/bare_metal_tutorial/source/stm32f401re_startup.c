#include <stdint.h>



#define SRAM_START 0x20000000U
#define SRAM_SIZE  (96 * 1024)
#define SRAM_END   ((SRAM_START) + (SRAM_SIZE))

#define STACK_START	SRAM_END

#define RESERVED 0



void reset_handler(void);

void nmi_handler(void)               __attribute__((weak, alias("default_handler")));
void hardfault_handler(void)         __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void)        __attribute__((weak, alias("default_handler")));
void busfault_handler(void)          __attribute__((weak, alias("default_handler")));
void usagefault_handler(void)        __attribute__((weak, alias("default_handler")));
void svcall_handler(void)            __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void)     __attribute__((weak, alias("default_handler")));
void pendsv_handler(void)            __attribute__((weak, alias("default_handler")));
void systick_handler(void)           __attribute__((weak, alias("default_handler")));
void wwdg_irq_handler(void)          __attribute__((weak, alias("default_handler")));
void pvd_irq_handler(void)           __attribute__((weak, alias("default_handler")));
void tamp_stamp_irq_handler(void)    __attribute__((weak, alias("default_handler")));
void rtc_wkup_irq_handler(void)      __attribute__((weak, alias("default_handler")));
void flash_irq_handler(void)         __attribute__((weak, alias("default_handler")));
void rcc_irq_handler(void)           __attribute__((weak, alias("default_handler")));
void exti0_irq_handler(void)         __attribute__((weak, alias("default_handler")));
void exti1_irq_handler(void)         __attribute__((weak, alias("default_handler")));
void exti2_irq_handler(void)         __attribute__((weak, alias("default_handler")));
void exti3_irq_handler(void)         __attribute__((weak, alias("default_handler")));
void exti4_irq_handler(void)         __attribute__((weak, alias("default_handler")));
void dma1_stream0_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma1_stream1_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma1_stream2_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma1_stream3_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma1_stream4_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma1_stream5_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma1_stream6_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void adc_irq_handler(void)           __attribute__((weak, alias("default_handler")));
void exti9_5_irq_handler(void)       __attribute__((weak, alias("default_handler")));
void tim1_brk_tim9_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_up_tim10_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_trg_com_tim11_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_cc_irq_handler(void)            __attribute__((weak, alias("default_handler")));
void tim2_irq_handler(void)          __attribute__((weak, alias("default_handler")));
void tim3_irq_handler(void)          __attribute__((weak, alias("default_handler")));
void tim4_irq_handler(void)          __attribute__((weak, alias("default_handler")));
void i2c1_ev_irq_handler(void)       __attribute__((weak, alias("default_handler")));
void i2c1_er_irq_handler(void)       __attribute__((weak, alias("default_handler")));
void i2c2_ev_irq_handler(void)       __attribute__((weak, alias("default_handler")));
void i2c2_er_irq_handler(void)       __attribute__((weak, alias("default_handler")));
void spi1_irq_handler(void)          __attribute__((weak, alias("default_handler")));
void spi2_irq_handler(void)          __attribute__((weak, alias("default_handler")));
void usart1_irq_handler(void)        __attribute__((weak, alias("default_handler")));
void usart2_irq_handler(void)        __attribute__((weak, alias("default_handler")));
void exti15_10_irq_handler(void)     __attribute__((weak, alias("default_handler")));
void rtc_alarm_irq_handler(void)     __attribute__((weak, alias("default_handler")));
void otg_fs_wkup_irq_handler(void)   __attribute__((weak, alias("default_handler")));
void dma1_stream7_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void sdio_irq_handler(void)          __attribute__((weak, alias("default_handler")));
void tim5_irq_handler(void)          __attribute__((weak, alias("default_handler")));
void spi3_irq_handler(void)          __attribute__((weak, alias("default_handler")));
void dma2_stream0_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma2_stream1_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma2_stream2_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma2_stream3_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma2_stream4_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void otg_fs_irq_handler(void)        __attribute__((weak, alias("default_handler")));
void dma2_stream5_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma2_stream6_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void dma2_stream7_irq_handler(void)  __attribute__((weak, alias("default_handler")));
void usart6_irq_handler(void)        __attribute__((weak, alias("default_handler")));
void i2c3_ev_irq_handler(void)       __attribute__((weak, alias("default_handler")));
void i2c3_er_irq_handler(void)       __attribute__((weak, alias("default_handler")));
void fpu_irq_handler(void)           __attribute__((weak, alias("default_handler")));
void spi4_irq_handler(void)          __attribute__((weak, alias("default_handler")));



uint32_t vector_table[] __attribute__((section(".isr_vectors"))) = {
	STACK_START,
	(uint32_t)&reset_handler,
	(uint32_t)&nmi_handler,
	(uint32_t)&hardfault_handler,
	(uint32_t)&mem_manage_handler,
	(uint32_t)&busfault_handler,
	(uint32_t)&usagefault_handler,
	RESERVED,
	RESERVED,
	RESERVED,
	RESERVED,
	(uint32_t)&svcall_handler,
	(uint32_t)&debug_monitor_handler,
	RESERVED,
	(uint32_t)&pendsv_handler,
	(uint32_t)&systick_handler,
	(uint32_t)&wwdg_irq_handler,
	(uint32_t)&pvd_irq_handler,
	(uint32_t)&tamp_stamp_irq_handler,
	(uint32_t)&rtc_wkup_irq_handler,
	(uint32_t)&flash_irq_handler,
	(uint32_t)&rcc_irq_handler,
	(uint32_t)&exti0_irq_handler,
	(uint32_t)&exti1_irq_handler,
	(uint32_t)&exti2_irq_handler,
	(uint32_t)&exti3_irq_handler,
	(uint32_t)&exti4_irq_handler,
	(uint32_t)&dma1_stream0_irq_handler,
	(uint32_t)&dma1_stream1_irq_handler,
	(uint32_t)&dma1_stream2_irq_handler,
	(uint32_t)&dma1_stream3_irq_handler,
	(uint32_t)&dma1_stream4_irq_handler,
	(uint32_t)&dma1_stream5_irq_handler,
	(uint32_t)&dma1_stream6_irq_handler,
	(uint32_t)&adc_irq_handler,
	(uint32_t)&exti9_5_irq_handler,
	(uint32_t)&tim1_brk_tim9_irq_handler,
	(uint32_t)&tim1_up_tim10_irq_handler,
	(uint32_t)&tim1_trg_com_tim11_irq_handler,
	(uint32_t)&tim1_cc_irq_handler,
	(uint32_t)&tim2_irq_handler,
	(uint32_t)&tim3_irq_handler,
	(uint32_t)&tim4_irq_handler,
	(uint32_t)&i2c1_ev_irq_handler,
	(uint32_t)&i2c1_er_irq_handler,
	(uint32_t)&i2c2_ev_irq_handler,
	(uint32_t)&i2c2_er_irq_handler,
	(uint32_t)&spi1_irq_handler,
	(uint32_t)&spi2_irq_handler,
	(uint32_t)&usart1_irq_handler,
	(uint32_t)&usart2_irq_handler,
	(uint32_t)&exti15_10_irq_handler,
	(uint32_t)&rtc_alarm_irq_handler,
	(uint32_t)&otg_fs_wkup_irq_handler,
	(uint32_t)&dma1_stream7_irq_handler,
	(uint32_t)&sdio_irq_handler,
	(uint32_t)&tim5_irq_handler,
	(uint32_t)&spi3_irq_handler,
	(uint32_t)&dma2_stream0_irq_handler,
	(uint32_t)&dma2_stream1_irq_handler,
	(uint32_t)&dma2_stream2_irq_handler,
	(uint32_t)&dma2_stream3_irq_handler,
	(uint32_t)&dma2_stream4_irq_handler,
	(uint32_t)&otg_fs_irq_handler,
	(uint32_t)&dma2_stream5_irq_handler,
	(uint32_t)&dma2_stream6_irq_handler,
	(uint32_t)&dma2_stream7_irq_handler,
	(uint32_t)&usart6_irq_handler,
	(uint32_t)&i2c3_ev_irq_handler,
	(uint32_t)&i2c3_er_irq_handler,
	(uint32_t)&fpu_irq_handler,
	(uint32_t)&spi4_irq_handler
};



void reset_handler(void)
{
	
}



void default_handler(void)
{
	while(1) {
		;
	}
}

