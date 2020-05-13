## Memory map of the microcontroller (STM32F401RE)
* Core - ARM Cortex M4.
* System bus width is 32 bits, which means that processor can provide 2^32
  (4GB) of different addresses from 0x00000000 to 0xFFFFFFFF.

## Base address of the FLASH memory
* 0x08000000

## Base address of the SRAM memory
* 0x20000000

## I-BUS (ICode) memory interface
* If the instructions are present in between memory locations 0x00000000 to
  0x1FFFFFFF then Cortex processor will fetch the instructions using ICode
  interface (S-BUS).

## D-BUS (DCode) memory interface
* If the data is present in between memory locations 0x00000000 to 0x1FFFFFFF
  then Cortex processor will fetch the data using DCode interface (D-BUS).

## S-BUS (System) interface
* If the instructions or data are present in between memory locations
  0x20000000 to 0xDFFFFFFF and 0xE0100000 to 0xFFFFFFFF then Cortex processor
  will fetch them over the System bus.

