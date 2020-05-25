MCU = STM32F401xE
CORE = cortex-m4

OPTIMIZATION_LEVEL = -O0


BUILD_DIR = ./build
SYSTEM_INCLUDE_DIR = ./system/include
DRIVERS_INCLUDE_DIR = ./drivers/include
DRIVERS_SOURCE_DIR = ./drivers/source


OBJECT_FILES = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, \
	$(basename $(DRIVERS_SOURCE_DIR))))

