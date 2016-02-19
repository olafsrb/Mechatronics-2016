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
serialYoutube.lss \

FLASH_IMAGE += \
serialYoutube.hex \

EEPROM_IMAGE += \
serialYoutube.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: serialYoutube.elf secondary-outputs

# Tool invocations
serialYoutube.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,serialYoutube.map -mmcu=atmega16 -o "serialYoutube.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

serialYoutube.lss: serialYoutube.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S serialYoutube.elf  >"serialYoutube.lss"
	@echo 'Finished building: $@'
	@echo ' '

serialYoutube.hex: serialYoutube.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex serialYoutube.elf  "serialYoutube.hex"
	@echo 'Finished building: $@'
	@echo ' '

serialYoutube.eep: serialYoutube.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex serialYoutube.elf  "serialYoutube.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: serialYoutube.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 serialYoutube.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) serialYoutube.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
