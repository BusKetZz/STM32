## Importance of startup file
* The startup file is responsible for setting up the right environment for
  the main user code to run.
* Code written in startup file runs before main(). So, one can say startup file
  calls main().
* Some part of the startup code file is the target (processor) dependent.
* Startup code takes care of vector table placement in code memory as required
  by the ARM Cortex Mx processor.
* Startup code may also take care of stack reinitialization.
* Startup code is responsible of .data, .bss section initialization in main
  memory.

