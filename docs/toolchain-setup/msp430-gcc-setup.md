# MSP430 GCC Toolchain Setup

This setup targets MSP430 GCC-based baremetal development.

## 1) Install Toolchain (Linux)
```bash
sudo apt update
sudo apt install -y gcc-msp430 msp430-libc msp430mcu mspdebug make
```

## 2) Verify Tools
```bash
msp430-gcc --version
mspdebug --version
```

## 3) Build Minimal Firmware
```bash
msp430-gcc -mmcu=msp430g2553 -g -O0 -o build/main.elf main.c
msp430-objcopy -O ihex build/main.elf build/main.hex
```

## 4) Flash (example with LaunchPad interface)
```bash
mspdebug rf2500 "prog build/main.elf"
```

## 5) Recommended First Test
- Stop watchdog in startup code.
- Blink `P1.0` and verify visible output.

## 6) Common Issues
- Watchdog resets if not disabled early.
- Wrong `-mmcu` causes incorrect vector/device setup.
- Programmer transport mismatch in `mspdebug` command.

## 7) Quick Success Criteria
- ELF/HEX generated.
- Flash succeeds.
- Blink or UART proof-of-life works.
