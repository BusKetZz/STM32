CORE = cortex-m4

BUILD_DIR = ./build
INCLUDE_DIR = ./include
SOURCE_DIR = ./source

STARTUP_FILE = startup_stm32f401xe.s
SOURCE_FILES = main.c led.c syscalls.c system_stm32f4xx.c
OBJECT_FILES = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, \
				$(basename $(SOURCE_FILES))))
OBJECT_FILES += $(addprefix $(BUILD_DIR)/, $(addsuffix .o, \
				$(basename $(STARTUP_FILE))))

LD = arm-none-eabi-gcc
LDSCRIPT = stm32f401re_linker_script.ld
LDFLAGS = -mcpu=$(CORE) -mthumb --specs=nano.specs -T $(LDSCRIPT)
LDFLAGS += -mfloat-abi=soft
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/program.map

CC = arm-none-eabi-gcc
CSTANDARD = gnu11
CFLAGS = -c -mcpu=$(CORE) -mthumb -std=$(CSTANDARD) -Wall -I$(INCLUDE_DIR) -O0
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

