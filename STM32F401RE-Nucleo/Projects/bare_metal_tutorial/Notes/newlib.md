## Newlib
* Newlib is a 'C' standard library implementation inteded for use on embedded
  systems, and it is introduced by Cygnus Solutions (now Red Hat).
* "Newlib" is written as a Glibc (GNU libc) replacement for embedded systems.
  It can be used with no OS ("bare metal") or with lightweight RTOS.
* "Newlib" ships with GNU ARM toolchain installation as the default C standard
  library.
* GNU libc (Glibc) includes ISO C, POSIX, System V, and XPG interfaces.
  uClibc provides ISO C, POSIX and System V, while Newlib provides only ISO C.

## Newlib-nano
* Due to the increased feature set in Newlib, it has become too bloated to use
  on the systems where the amount of memory is very much limited.
* To provide a C library with a minimal memory footprint, suited for use with
  microcontrollers, ARM introduced Newlib-nano based on Newlib.

## Low-level system calls
* The idea of Newlib is to implement the hardware-independent parts of the
  standard C library and rely on a few low-level system calls that must be
  implemented with the target hardware in mind.
* When one uses Newlib, one must implement the system calls appropriately to
  support devices, file-systems, and memory management.

