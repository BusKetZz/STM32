## Clock sources used to drive the system clock (SYSCLK)
* HSI (High Speed Internal) oscillator clock.
* HSE (High Speed External) oscillator clock.
* Main PLL (Phase Locked Loop) clock.

## Secondary clock sources
* 32 [kHz] LSI RC (Low Speed Internal RC).
* 32.768 [kHz] LSE crystal (Low Speed External).

## How to set HSE as a system clock
* Enable the HSE clock using HSE ON bit in RCC clock control register (RCC_CR).
* Wait until HSE clock from the external crystal stabilizes. To do this, just
  wait until HSE RDY bit in RCC clock control register (RCC_CR) is set - this
  bit is set by the hardware.
* Switch the system clock to HSE by setting the proper value in RCC clock
  configuration register (RCC_CFGR).

