# Temperature Controller

- [Overview](#overview)
    - [Goal](#goal)
    - [Peripherals](#peripherals)
- [Build & Flash](#build-&-flash)
    - [Build](#build)
    - [Flash](#flash)



## Overview

### Goal

Implementation of simple temperature controller.


### Peripherals

* ADC
* GPIO
* Timer



## Build & Flash

### Build

To build a project You need to run one simple command:

```sh
$ make all
```

If You want to delete `./build/` directory, run:

```sh
$ make clean
```


### Flash

To flash your board perform following steps:

1. Connect board via miniUSB-USB cable to the computer.

2. Run the command:

```sh
$ make flash
```

