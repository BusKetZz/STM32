## SWD - Serial Wire Debug
* Serial Wire Debug is a two-wire protocol for accessing the ARM debug
  interface.
* It is part of the ARM Debug Interface Specification v5 and is an alternative
  to JTAG.
* The physical layer of SWD consists of two lines:
  * SWDIO: a bidirectional data line,
  * SWCLK: a clock driven by the host (eg. ST-LINK).
* By using SWD interface, one should be able to program MCUs internal FLASH,
  access memory regions, add breakpoints, stop/run CPU.
* The other advantage of SWD is that one can use the Serial Wire Viewer (SWV)
  for printf() statements for debugging process.

## SWD and JTAG
* JTAG was the traditional mechanism for debug connections for ARM7/9 family,
  but with the Cortex-M family, ARM introduced the Serial Wire Debug (SWD)
  Interface. SWD is designed to reduce the pin count required for debug from
  the 4 used by JTAG (excluding GND) down to 2. In addition, SWD interface
  provides one more pin called SWO (Serial Wire Output) which is used for
  Single Wire Viewing (SWV), which is a low cost tracing technology.

