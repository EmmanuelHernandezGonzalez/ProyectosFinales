################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include board/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Tema03Proyecto03_AlarmaDeCasa.axf

# Tool invocations
Tema03Proyecto03_AlarmaDeCasa.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="Tema03Proyecto03_AlarmaDeCasa.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T "Tema03Proyecto03_AlarmaDeCasa_Debug.ld" -o "Tema03Proyecto03_AlarmaDeCasa.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Tema03Proyecto03_AlarmaDeCasa.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Tema03Proyecto03_AlarmaDeCasa.axf"; # arm-none-eabi-objcopy -v -O binary "Tema03Proyecto03_AlarmaDeCasa.axf" "Tema03Proyecto03_AlarmaDeCasa.bin" ; # checksum -p MKL25Z128xxx4 -d "Tema03Proyecto03_AlarmaDeCasa.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
