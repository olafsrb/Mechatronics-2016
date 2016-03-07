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
Mech2_delay.lss \

FLASH_IMAGE += \
Mech2_delay.hex \

EEPROM_IMAGE += \
Mech2_delay.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Mech2_delay.elf secondary-outputs

# Tool invocations
Mech2_delay.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Mech2_delay.map -mmcu=atmega328p -o "Mech2_delay.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Mech2_delay.lss: Mech2_delay.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Mech2_delay.elf  >"Mech2_delay.lss"
	@echo 'Finished building: $@'
	@echo ' '

Mech2_delay.hex: Mech2_delay.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Mech2_delay.elf  "Mech2_delay.hex"
	@echo 'Finished building: $@'
	@echo ' '

Mech2_delay.eep: Mech2_delay.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Mech2_delay.elf  "Mech2_delay.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Mech2_delay.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Mech2_delay.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Mech2_delay.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
