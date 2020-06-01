MCU = STM32F401xE
CORE = cortex-m4


OPTIMIZATION_LEVEL = -O0
ERRORS_LEVEL = -Wall


BUILD_DIR = ./build
SYSTEM_INCLUDE_DIR = ./system/include
SYSTEM_SOURCE_DIR = ./system/source
DRIVERS_INCLUDE_DIR = ./drivers/include
DRIVERS_SOURCE_DIR = ./drivers/source


SYSTEM_SOURCE_FILES = nvic_irq.c

DRIVERS_SOURCE_FILES = stm32f401xe_driver_gpio.c stm32f401xe_driver_syscfg.c

OBJECT_FILES = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, \
	$(basename $(SYSTEM_SOURCE_FILES))))
OBJECT_FILES += $(addprefix $(BUILD_DIR)/, $(addsuffix .o, \
	$(basename $(DRIVERS_SOURCE_FILES))))


CC = arm-none-eabi-gcc
CSTANDARD = gnu11
CFLAGS = -c -std=$(CSTANDARD) -mcpu=$(CORE) -D$(MCU) -mthumb
CFLAGS += $(OPTIMIZATION_LEVEL)
CFLAGS += -I$(SYSTEM_INCLUDE_DIR) -I$(DRIVERS_INCLUDE_DIR)
CFLAGS += $(ERRORS_LEVEL)
CFLAGS += -mfloat-abi=soft


LD = arm-none-eabi-gcc
LDFLAGS = -mcpu=$(CORE) -D$(MCU) -mthumb


ELF = $(BUILD_DIR)/program.elf
HEX = $(BUILD_DIR)/program.hex
BIN = $(BUILD_DIR)/program.bin


all: $(ELF)

$(ELF): $(OBJECT_FILES)
	$(LD) $(LDFLAGS) -o $@ $(OBJECT_FILES)

$(BUILD_DIR)/%.o: $(SYSTEM_SOURCE_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: $(DRIVERS_SOURCE_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

