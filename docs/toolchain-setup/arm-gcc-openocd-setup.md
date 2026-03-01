# ARM GCC + OpenOCD Toolchain Setup

This setup targets Cortex-M development (for example STM32 class boards) using GCC + OpenOCD.

## 1) Install Required Packages (Linux)
```bash
sudo apt update
sudo apt install -y gcc-arm-none-eabi gdb-multiarch openocd make cmake
```

## 2) Verify Installation
```bash
arm-none-eabi-gcc --version
openocd --version
gdb-multiarch --version
```

## 3) Build Firmware (example flow)
```bash
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -g -O0 -ffreestanding -nostdlib \
	-T linker.ld startup.c main.c -o build/firmware.elf
arm-none-eabi-objcopy -O binary build/firmware.elf build/firmware.bin
```

## 4) Start OpenOCD
```bash
openocd -f interface/stlink.cfg -f target/stm32f1x.cfg
```

## 5) Debug with GDB
```bash
gdb-multiarch build/firmware.elf
```
Inside GDB:
```gdb
target remote :3333
monitor reset halt
load
break main
continue
```

## 6) Common Issues
- Probe not found: check USB cable/permissions (`udev` rules).
- Breakpoints not hit: ensure ELF with symbols (`-g`) is loaded.
- Flash errors: verify correct OpenOCD target config file.

## 7) Quick Success Criteria
- Firmware loads successfully.
- Breakpoint at `main` is hit.
- GPIO blink/UART print works after continue.
