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

