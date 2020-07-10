## What are vectors?
* Vectors are pointers or addresses of exception handlers (system exceptions
  and hardware interrupts). In other words, Reset exception has an memory
  address of 0x00000004, under this memory address Reset Handler address is
  placed.

## What is a vectors table?
* It is a collection of vectors, i.e. collection of addresses of exception
  handlers.

## Exception handlers
* Exception handlers must handle 15 system exceptions and 240 interrupts.

## 0x00000000 address in vectors table
* This address stores stack pointer value.

