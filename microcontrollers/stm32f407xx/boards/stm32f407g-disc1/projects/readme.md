# Projects

- [Overview](#overview)
    - [Goal](#goal)
    - [Bare metal programming](#bare-metal-programming)
    - [Peripherals drivers low layer API](#peripherals-drivers-low-layer-api)



## Overview


### Goal

Goal of each project is to introduce the user into bare-metal embedded systems
programming by the means of CMSIS package and peripherals drivers low-layer 
API.

Each project should "make sense" in some way and presents real life
application like temperature or light controller, movement detection system,
etc.


### Bare metal programming

Bare metal programming means that there is lack of any operating system like
Embedded Linux, FreeRTOS or Zephyr.

In other words programs are written in C programming language (sometimes C++
or assembly language are used), compiled into binary format and flash straight
into Flash memory of a microcontroller.

Nowadays, popularity of bare-metal programming falls down, but it is still
crucial tool in the hands of every embedded systems developer/programmer.


### Peripherals drivers low layer API

Peripherals drivers low layer API allows programmers to write code which is
very close to register level. Usage of this API makes application better
optimized and increases its performance. Also code written in low-layer API
gives better understanding of peripherals and "guts" of a microcontroller.

Nevertheless most of the apps written by means of low-layer API are not
easily portable between different platforms. To make your software much more
portable, the better choice is the usage of HAL (Hardware Abstraction Layer).

