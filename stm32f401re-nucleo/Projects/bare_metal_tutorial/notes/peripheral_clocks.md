## Peripheral clock configuration
* In modern microcontrollers, before using any peripheral, you must enable its
  peripheral clock in peripheral clock registers.
* By default, most clocks of all peripherals will be disabled to save power.
* Any peripheral will not work until its peripheral clock is enabled. What is
  more one will not be able to configure any registers related to given
  peripheral.
* In STM32 microcontrollers, peripheral clocks are managed through RCC
  registers.

