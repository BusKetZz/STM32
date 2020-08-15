#-----------------------------------------------------------------------------#
# PROJECT INFORMATION #
#-----------------------------------------------------------------------------#

PROJECT_NAME = temperature_regulator
BOARD_NAME = stm32f407vg-discovery

DEPENDENCIES_PATH = ../../../../dependencies/



#-----------------------------------------------------------------------------#
# TOOLCHAIN INFORMATION #
#-----------------------------------------------------------------------------#

TOOLCHAIN_VERSION = 9-2020-q2-update
TOOLCHAIN_PATH = /usr/local/gcc-arm-none-eabi/$(TOOLCHAIN_VERSION)/bin/



#-----------------------------------------------------------------------------#
# MCU DETAILS #
#-----------------------------------------------------------------------------#

CPU = cortex-m4
MCU = STM32F407xx



#-----------------------------------------------------------------------------#
# APPLICATION SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

APP_SOURCE_DIR = ./source/
APP_INCLUDE_DIR = ./include/

APP_SOURCE_FILES = main.c
APP_SOURCE_FILES += flash.c pwr.c rcc.c syscfg.c



#-----------------------------------------------------------------------------#
# LOW-LAYER DRIVERS SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

LL_DRIVERS_SOURCE_DIR = $(DEPENDENCIES_PATH)drivers/low_layer_api/source/
LL_DRIVERS_INCLUDE_DIR = $(DEPENDENCIES_PATH)drivers/low_layer_api/include/

LL_DRIVERS_SOURCE_FILES = 



#-----------------------------------------------------------------------------#
# CMSIS SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

CMSIS_SYSTEM_SOURCE_DIR = $(DEPENDENCIES_PATH)cmsis/system/source/
CMSIS_SYSTEM_INCLUDE_DIR = $(DEPENDENCIES_PATH)cmsis/system/include/

CMSIS_SYSTEM_SOURCE_FILES = system_stm32f4xx.c


CMSIS_STARTUP_SOURCE_DIR = $(DEPENDENCIES_PATH)cmsis/startup/source/

CMSIS_STARTUP_SOURCE_FILES = startup_stm32f407xx.s


CMSIS_CORE_INCLUDE_DIR = $(DEPENDENCIES_PATH)cmsis/core/include/



#-----------------------------------------------------------------------------#
# COMPILER SETTINGS #
#-----------------------------------------------------------------------------#

CC = $(TOOLCHAIN_PATH)arm-none-eabi-gcc
CC_STANDARD = -std=gnu11
CC_ERROR_LEVEL = -Wall -Werror -Wextra
CC_OPTIMIZATION_LEVEL = -O0
CC_STATE = -mthumb
CC_ENDIANNESS = -mlittle-endian
CC_CPU = -mcpu=$(CPU)
CC_MCU = -D$(MCU)
CC_DRIVER = -DUSE_FULL_LL_DRIVER

CC_FLAGS = $(CC_STANDARD) $(CC_ERROR_LEVEL) $(CC_OPTIMIZATION_LEVEL)
CC_FLAGS += $(CC_STATE) $(CC_ENDIANNESS) $(CC_CPU) $(CC_MCU) $(CC_DRIVER)
CC_FLAGS += -I$(APP_INCLUDE_DIR)
CC_FLAGS += -I$(LL_DRIVERS_INCLUDE_DIR)
CC_FLAGS += -I$(CMSIS_SYSTEM_INCLUDE_DIR)
CC_FLAGS += -I$(CMSIS_CORE_INCLUDE_DIR)



#-----------------------------------------------------------------------------#
# LINKER SETTINGS #
#-----------------------------------------------------------------------------#

LD_SCRIPT = $(DEPENDENCIES_PATH)linker_scripts/stm32f407vgtx_flash.ld
LD_GARBAGE_COLLECTION = -Wl,--gc-sections

LD_FLAGS = -T$(LD_SCRIPT) $(LD_GARBAGE_COLLECTION)



#-----------------------------------------------------------------------------#
# OBJCOPY SETTINGS #
#-----------------------------------------------------------------------------#

OBJCOPY = $(TOOLCHAIN_PATH)arm-none-eabi-objcopy



#-----------------------------------------------------------------------------#
# BUILD PROCEDURE #
#-----------------------------------------------------------------------------#

BUILD_DIR = ./build/
ELF_FILE = $(addprefix $(BUILD_DIR), $(PROJECT_NAME).elf)
HEX_FILE = $(addprefix $(BUILD_DIR), $(PROJECT_NAME).hex)

SOURCE_FILES = $(addprefix $(APP_SOURCE_DIR), $(APP_SOURCE_FILES))
SOURCE_FILES += $(addprefix $(LL_DRIVERS_SOURCE_DIR), \
	$(LL_DRIVERS_SOURCE_FILES))
SOURCE_FILES += $(addprefix $(CMSIS_SYSTEM_SOURCE_DIR), \
	$(CMSIS_SYSTEM_SOURCE_FILES))
SOURCE_FILES += $(addprefix $(CMSIS_STARTUP_SOURCE_DIR), \
	$(CMSIS_STARTUP_SOURCE_FILES))



all: $(HEX_FILE)

$(HEX_FILE): $(ELF_FILE)
	$(OBJCOPY) -Oihex $< $@

$(ELF_FILE): $(SOURCE_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(LD_FLAGS) $^ --output $@

clean:
	rm -rf $(BUILD_DIR)



#-----------------------------------------------------------------------------#
# FLASH PROCEDURE #
#-----------------------------------------------------------------------------#

OPENOCD = /opt/openocd/0.10.0-14/bin/openocd
OPENOCD_SCRIPT = /opt/openocd/0.10.0-14/scripts/board/stm32f4discovery.cfg
OPENOCD_CMD = "init;halt;flash write_image erase $(HEX_FILE);reset run;exit"



flash:
	$(OPENOCD) -f $(OPENOCD_SCRIPT) -c $(OPENOCD_CMD)

erase:

