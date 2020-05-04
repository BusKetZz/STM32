CORE = cortex-m4

INCLUDE_PATH = ../include

CC = arm-none-eabi-gcc
CSTANDARD = gnu11
CFLAGS = -c -mcpu=$(CORE) -mthumb -std=$(CSTANDARD) -Wall -I$(INCLUDE_PATH) -O0
LDFLAGS = -nostdlib -T stm32f401re_linker_script.ld -Wl,-Map=final.map

all: main.o led.o stm32f401re_startup.o final.elf

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^

led.o: led.c
	$(CC) $(CFLAGS) -o $@ $^

stm32f401re_startup.o: stm32f401re_startup.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: main.o led.o stm32f401re_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf

