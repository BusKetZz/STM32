#
# Author: Jakub Standarski
# Email: jstand.jakub.standarski@gmail.com
#
# Date: 22.09.2020
#

#-----------------------------------------------------------------------------#
# GENERAL SETTINGS #
#-----------------------------------------------------------------------------#

DEPENDENCIES_PATH = ../../../../../dependencies

TOOLCHAIN_VERSION = 9-2020-q2-update
TOOLCHAIN_PATH = /opt/gcc-arm-none-eabi/$(TOOLCHAIN_VERSION)



#-----------------------------------------------------------------------------#
# APPLICATION SETTINGS #
#-----------------------------------------------------------------------------#

APPLICATION_PATH = ./application

APPLICATION_INCLUDE_PATH = $(APPLICATION_PATH)/include
APPLICATION_SOURCE_PATH = $(APPLICATION_PATH)/source
APPLICATION_SOURCE_FILES = main.c



#-----------------------------------------------------------------------------#
# PERIPHERALS DRIVERS SETTINGS #
#-----------------------------------------------------------------------------#

PERIPHERALS_DRIVERS_PATH = $(DEPENDENCIES_PATH)/peripherals_drivers/low_layer

PERIPHERALS_DRIVERS_INCLUDE_PATH = $(PERIPHERALS_DRIVERS_PATH)/include
PERIPHERALS_DRIVERS_SOURCE_PATH = $(PERIPHERALS_DRIVERS_PATH)/source
PERIPHERALS_DRIVERS_SOURCE_FILES =



#-----------------------------------------------------------------------------#
# CMSIS SETTINGS #
#-----------------------------------------------------------------------------#

CMSIS_PATH = $(DEPENDENCIES_PATH)/cmsis

CMSIS_COMPILER_PATH = $(CMSIS_PATH)/compiler

CMSIS_CORE_PATH = $(CMSIS_PATH)/core

CMSIS_SYSTEM_INCLUDE_PATH = $(CMSIS_PATH)/system/include
CMSIS_SYSTEM_SOURCE_PATH = $(CMSIS_PATH)/system/source
CMSIS_SYSTEM_SOURCE_FILE = system_stm32f4xx.c

CMSIS_STARTUP_PATH = $(CMSIS_PATH)/startup
CMSIS_STARTUP_SOURCE_FILE = startup_stm32f407xx.s



#-----------------------------------------------------------------------------#
# LINKER SETTINGS #
#-----------------------------------------------------------------------------#

LINKER_SCRIPT_PATH = $(DEPENDENCIES_PATH)/linker_scripts

LINKER_SCRIPT_FILE = stm32f407vgtx_flash.ld

LINKER_FLAGS = --gc-sections --print-gc-sections


#-----------------------------------------------------------------------------#
# COMPILER SETTINGS #
#-----------------------------------------------------------------------------#

WARNING_FLAGS = -Wall -Wextra -Werror -Wdouble-promotion -Wconversion
WARNING_FLAGS += -Wformat=2 -Wformat-truncation

DEBUG_LVL = -g3

OPTIMIZATION_LVL = -Os

SECTIONS_FLAGS = -ffunction-sections -fdata-sections

ISA_TYPE = -mthumb

FPU_TYPE = -mfloat-abi=soft

CPU = -mcpu=cortex-m4

MCU = -DSTM32F407xx

PERIPHERALS_DRIVERS_TYPE = USE_FULL_LL_DRIVER


COMPILER_BIN = $(TOOLCHAIN_PATH)/bin/arm-none-eabi-gcc
COMPILER_FLAGS = $(WARNING_FLAGS) $(DEBUG_LVL) $(OPTIMIZATION_LVL)
COMPILER_FLAGS += $(SECTIONS_FLAGS) $(ISA_TYPE) $(FPU_TYPE) $(CPU) $(MCU)
COMPILER_FLAGS += $(PERIPHERALS_DRIVERS_TYPE)

