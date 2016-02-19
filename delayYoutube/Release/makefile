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
delayYoutube.lss \

FLASH_IMAGE += \
delayYoutube.hex \

EEPROM_IMAGE += \
delayYoutube.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: delayYoutube.elf secondary-outputs

# Tool invocations
delayYoutube.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,delayYoutube.map -mmcu=atmega328p -o "delayYoutube.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

delayYoutube.lss: delayYoutube.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S delayYoutube.elf  >"delayYoutube.lss"
	@echo 'Finished building: $@'
	@echo ' '

delayYoutube.hex: delayYoutube.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex delayYoutube.elf  "delayYoutube.hex"
	@echo 'Finished building: $@'
	@echo ' '

delayYoutube.eep: delayYoutube.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex delayYoutube.elf  "delayYoutube.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: delayYoutube.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p delayYoutube.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) delayYoutube.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
