CORE = cortex-m4

INCLUDE_PATH = ../include

CC = arm-none-eabi-gcc
CSTANDARD = gnu11
CFLAGS = -c -mcpu=$(CORE) -mthumb -std=$(CSTANDARD) -I$(INCLUDE_PATH) -O0

all: main.o led.o

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^

led.o: led.c
	$(CC) $(CFLAGS) -o $@ $^
