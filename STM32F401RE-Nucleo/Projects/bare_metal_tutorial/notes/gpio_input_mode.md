## When an I/O pin of GPIO is programmed as input mode
* The output buffer is disabled.
* The Schmitt trigger input is activated.
* The pull-up and pull-down resistors are activated depending on the value
  in the GPIOx_PUPDR register.
* The data present on the I/O pin are sampled into the input data register
  every AHB1 clock cycle.
* Reading input data register provides the I/O state of GPIO pin.

