#-----------------------------------------------------------------------------#
# MCU DETAILS #
#-----------------------------------------------------------------------------#

CPU = cortex-m4
MCU = STM32F407VG



#-----------------------------------------------------------------------------#
# APPLICATION SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

APP_SOURCE_DIR = ./source/
APP_INCLUDE_DIR = ./include/

APP_SOURCE_FILES = main.c



#-----------------------------------------------------------------------------#
# LOW-LAYER DRIVERS SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

LL_DRIVERS_SOURCE_DIR = ../../../../drivers/low_layer_api/source/
LL_DRIVERS_INCLUDE_DIR = ../../../../drivers/low_layer_api/include/

LL_DRIVERS_SOURCE_FILES =



#-----------------------------------------------------------------------------#
# CMSIS SOURCE & HEADER FILES #
#-----------------------------------------------------------------------------#

CMSIS_SYSTEM_SOURCE_DIR = ../../../../cmsis/system/source/
CMSIS_SYSTEM_INCLUDE_DIR = ../../../../cmsis/system/include/

CMSIS_SYSTEM_SOURCE_FILES = system_stm32f4xx.c


CMSIS_STARTUP_SOURCE_DIR = ../../../../cmsis/startup/source/

CMSIS_STARTUP_SOURCE_FILES = startup_stm32f407xx.s


CMSIS_CORE_INCLUDE_DIR = ../../../../cmsis/core/include/



#-----------------------------------------------------------------------------#
# COMPILER SETTINGS #
#-----------------------------------------------------------------------------#

CC = /usr/local/gcc-arm-none-eabi/9-2020-q2-update/bin/arm-none-eabi-gcc
CC_ERROR_LEVEL = -Wall -Werror -Wextra
CC_OPTIMIZATION_LEVEL = -O0
CC_STATE = -mthumb
CC_ENDIANNESS = -mlittle-endian

CC_FLAGS = $(CC_ERROR_LEVEL) $(CC_OPTIMIZATION_LEVEL)
CC_FLAGS += $(CC_STATE) $(CC_ENDIANNESS)



#-----------------------------------------------------------------------------#
# LINKER SETTINGS #
#-----------------------------------------------------------------------------#

LD_SCRIPT =
LD_GARBAGE_COLLECTION = -Wl,--gc-sections



#-----------------------------------------------------------------------------#
# BUILD PROCEDURE #
#-----------------------------------------------------------------------------#



#-----------------------------------------------------------------------------#
# FLASH PROCEDURE #
#-----------------------------------------------------------------------------#



