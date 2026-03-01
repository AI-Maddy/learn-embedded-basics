# AVR GCC Toolchain Setup

This setup targets ATmega-class MCUs with AVR-GCC and `avrdude`.

## 1) Install Required Packages (Linux)
```bash
sudo apt update
sudo apt install -y gcc-avr avr-libc binutils-avr avrdude make
```

## 2) Verify Installation
```bash
avr-gcc --version
avrdude -v
```

## 3) Build Example Firmware
```bash
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -g \
	-o build/main.elf main.c
avr-objcopy -O ihex -R .eeprom build/main.elf build/main.hex
avr-size --mcu=atmega328p --format=avr build/main.elf
```

## 4) Flash to Target
```bash
avrdude -c usbasp -p m328p -U flash:w:build/main.hex:i
```

## 5) Recommended First Test
- Blink LED on known pin (for Uno boards: PB5 / D13).
- Confirm blink rate roughly matches expected delay.

## 6) Common Issues
- `initialization failed`: wrong programmer type or wiring.
- Clock mismatch timing issues: incorrect `F_CPU` or fuse settings.
- Permission denied USB: run with proper udev rules/group membership.

## 7) Quick Success Criteria
- HEX generated without errors.
- Flash command completes.
- Firmware behavior visible on board.
