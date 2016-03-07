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
Analog_PWM.lss \

FLASH_IMAGE += \
Analog_PWM.hex \

EEPROM_IMAGE += \
Analog_PWM.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Analog_PWM.elf secondary-outputs

# Tool invocations
Analog_PWM.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Analog_PWM.map -mmcu=atmega328p -o "Analog_PWM.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Analog_PWM.lss: Analog_PWM.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Analog_PWM.elf  >"Analog_PWM.lss"
	@echo 'Finished building: $@'
	@echo ' '

Analog_PWM.hex: Analog_PWM.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Analog_PWM.elf  "Analog_PWM.hex"
	@echo 'Finished building: $@'
	@echo ' '

Analog_PWM.eep: Analog_PWM.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Analog_PWM.elf  "Analog_PWM.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Analog_PWM.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Analog_PWM.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Analog_PWM.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
