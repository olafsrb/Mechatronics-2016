################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
PWM_Library.lss \

FLASH_IMAGE += \
PWM_Library.hex \

EEPROM_IMAGE += \
PWM_Library.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: PWM_Library.elf secondary-outputs

# Tool invocations
PWM_Library.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PWM_Library.map -mmcu=atmega328p -o "PWM_Library.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PWM_Library.lss: PWM_Library.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PWM_Library.elf  >"PWM_Library.lss"
	@echo 'Finished building: $@'
	@echo ' '

PWM_Library.hex: PWM_Library.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PWM_Library.elf  "PWM_Library.hex"
	@echo 'Finished building: $@'
	@echo ' '

PWM_Library.eep: PWM_Library.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex PWM_Library.elf  "PWM_Library.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PWM_Library.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p PWM_Library.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PWM_Library.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
