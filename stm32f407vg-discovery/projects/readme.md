# Projects



## Overview

* **Goal**: introduction into embedded systems by doing simple real-life
    projects, e.g. temperature regulator and light control system.

* **Topics**: bare-metal programming, low-layer API, microcontroller
    peripherals (e.g. timers, GPIO, ADC, I2C, SPI, UART and other).



## Bare-metal programming

Projects under this directory are based on bare-metal embedded systems
programming, which means that there is lack of any operating system like
Embedded Linux, FreeRTOS or Zephyr.

In other words programs are written in C programming language (sometimes C++
or assembly language are used), compiled into binary format and flash straight
into Flash memory of a microcontroller.

Nowadays, popularity of bare-metal programming falls down, but it is still
crucial tool in the hands of every embedded systems developer/programmer.


### Low-layer API

Low-layer API allows programmers to write code which is very close to register
level. Usage of this API makes application better optimized and increases its
performance. Also code written in low-layer API gives better understanding of
peripherals and "guts" of a microcontroller.

Nevertheless most of the apps written by means of low-layer API are not
easily portable between different platforms. To make your software much more
portable, the better choice is the usage of HAL (Hardware Abstraction Layer).

