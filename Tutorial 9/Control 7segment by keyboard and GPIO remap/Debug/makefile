################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Control 7segment by keyboard and GPIO remap
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.elf \

MAP_FILES += \
Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.list \


# All Target
all: main-build

# Main-build Target
main-build: Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.elf secondary-outputs

# Tool invocations
Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.elf Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.map: $(OBJS) $(USER_OBJS) C:\Users\Anwar\Desktop\STM32F0\ Doc\Tutorial\ 9\Code\Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap\STM32F030F4PX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Control 7segment by keyboard and GPIO remap.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"C:\Users\Anwar\Desktop\STM32F0 Doc\Tutorial 9\Code\Control 7segment by keyboard and GPIO remap\STM32F030F4PX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Control 7segment by keyboard and GPIO remap.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Control 7segment by keyboard and GPIO remap.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.elf Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.list Control\ 7segment\ by\ keyboard\ and\ GPIO\ remap.map Control\\ 7segment\\ by\\ keyboard\\ and\\ GPIO\\ remap.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
