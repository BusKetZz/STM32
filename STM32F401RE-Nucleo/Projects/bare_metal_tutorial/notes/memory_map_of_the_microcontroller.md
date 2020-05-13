## Memory map of the microcontroller (STM32F401RE)
* Core - ARM Cortex M4.
* System bus width is 32 bits, which means that processor can provide 2^32
  (4GB) of different addresses from 0x00000000 to 0xFFFFFFFF.

## Base address of the FLASH memory
* 0x08000000

## Base address of the SRAM memory
* 0x20000000

## I-BUS (ICODE) memory interface
* If the instructions are present in between memory locations 0x00000000 to
  0x1FFFFFFC then Cortex processor will fetch the instructions using ICODE
  interface.


