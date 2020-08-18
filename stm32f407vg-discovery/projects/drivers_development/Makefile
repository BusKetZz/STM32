#
# Author: Jakub Standarski
# Date: 14.08.2020
#



#-----------------------------------------------------------------------------#
# PROJECT INFORMATION #
#-----------------------------------------------------------------------------#

PROJECT_NAME = drivers_development



#-----------------------------------------------------------------------------#
# TOOLCHAIN INFORMATION #
#-----------------------------------------------------------------------------#

TOOLCHAIN_VERSION = 9-2020-q2-update
TOOLCHAIN_PATH = /usr/local/gcc-arm-none-eabi/$(TOOLCHAIN_VERSION)/

TOOLCHAIN_BIN_PATH = $(TOOLCHAIN_PATH)bin/



#-----------------------------------------------------------------------------#
# MCU DETAILS #
#-----------------------------------------------------------------------------#

CPU = cortex-m4
MCU = STM32F407xx



#-----------------------------------------------------------------------------#
# SYSTEM SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

SYSTEM_SOURCE_DIR = ./system/source/
SYSTEM_INCLUDE_DIR = ./system/include/

SYSTEM_SOURCE_FILES =


 
#-----------------------------------------------------------------------------#
# DRIVERS SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#
 
DRIVERS_SOURCE_DIR = ./drivers/source/
DRIVERS_INCLUDE_DIR = ./drivers/include/

DRIVERS_SOURCE_FILES =



#-----------------------------------------------------------------------------#
# COMPILER SETTINGS #
#-----------------------------------------------------------------------------#

CC = $(TOOLCHAIN_BIN_PATH)arm-none-eabi-gcc
CC_STANDARD = -std=gnu11
CC_ERROR_LEVEL = -Wall -Werror -Wextra
CC_OPTIMIZATION_LEVEL = -O0
CC_ENDIANNESS = -mlittle-endian
CC_STATE = -mthumb
CC_CPU = -mcpu=$(CPU)
CC_MCU = -D$(MCU)

CC_FLAGS = $(CC_STANDARD) $(CC_ERROR_LEVEL) $(CC_OPTIMIZATION_LEVEL)
CC_FLAGS += $(CC_ENDIANNESS) $(CC_STATE) $(CC_CPU) $(CC_MCU)
CC_FLAGS += -I$(SYSTEM_INCLUDE_DIR) -I$(DRIVERS_INCLUDE_DIR)



#-----------------------------------------------------------------------------#
# LINKER SETTINGS #
#-----------------------------------------------------------------------------#

LD_SCRIPT =
LD_MEMORY_MAP = -Wl,-Map=$(BUILD_DIR)$(PROJECT_NAME).map
LD_GARBAGE_COLLECTION = -Wl,--gc-sections

LD_FLAGS = -T$(LD_SCRIPT) $(LD_MEMORY_MAP) $(LD_GARBAGE_COLLECTION)



#-----------------------------------------------------------------------------#
# OBJCOPY SETTINGS #
#-----------------------------------------------------------------------------#

OBJCOPY = $(TOOLCHAIN_BIN_PATH)arm-none-eabi-objcopy



#-----------------------------------------------------------------------------#
# BUILD PROCEDURE #
#-----------------------------------------------------------------------------#

BUILD_DIR = ./build/
ELF_FILE = $(addprefix $(BUILD_DIR), $(PROJECT_NAME).elf)
HEX_FILE = $(addprefix $(BUILD_DIR), $(PROJECT_NAME).hex)

SOURCE_FILES = $(addprefix $(SYSTEM_SOURCE_DIR), $(SYSTEM_SOURCE_FILES))
SOURCE_FILES += $(addprefix $(DRIVERS_SOURCE_DIR), $(DRIVERS_SOURCE_FILES)) 



all: $(HEX_FILE)

$(HEX_FILE): $(ELF_FILE)
	$(OBJCOPY) -Oihex $< $@

$(ELF_FILE): $(SOURCE_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(LD_FLAGS) $^ --output $@

clean:
	rm -rf $(BUILD_DIR)

