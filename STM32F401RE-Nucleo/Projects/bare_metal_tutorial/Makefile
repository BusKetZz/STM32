CORE = cortex-m4

OPTIMIZATION_LEVEL = -O0

BUILD_DIR = ./build
INCLUDE_DIR = ./include
CMSIS_INCLUDE_DIR = ../../../Packages/STM32Cube_FW_F4_V1.25.0/Drivers/CMSIS/Include
SOURCE_DIR = ./source

STARTUP_FILE = startup_stm32f401xe.s
SOURCE_FILES = main.c led.c system_stm32f4xx.c
OBJECT_FILES = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, \
				$(basename $(SOURCE_FILES))))
OBJECT_FILES += $(addprefix $(BUILD_DIR)/, $(addsuffix .o, \
				$(basename $(STARTUP_FILE))))

LD = arm-none-eabi-gcc
LDSCRIPT = stm32f401re_linker_script.ld
LDFLAGS = -mcpu=$(CORE) -mthumb -T $(LDSCRIPT)
LDFLAGS += -mfloat-abi=soft -specs=rdimon.specs
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/program.map

CC = arm-none-eabi-gcc
CSTANDARD = gnu11
CFLAGS = -c -mcpu=$(CORE) -mthumb -std=$(CSTANDARD) -Wall -Wextra
CFLAGS += -I$(CMSIS_INCLUDE_DIR) -I$(INCLUDE_DIR)
CFLAGS += $(OPTIMIZATION_LEVEL)
CFLAGS += -mfloat-abi=soft

OBJCOPY = arm-none-eabi-objcopy

ELF = $(BUILD_DIR)/program.elf
HEX = $(BUILD_DIR)/program.hex
BIN = $(BUILD_DIR)/program.bin

all: $(ELF)

$(ELF): $(OBJECT_FILES)
	$(LD) $(LDFLAGS) -o $@ $(OBJECT_FILES)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.s
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

load:
	openocd -f board/st_nucleo_f4.cfg

