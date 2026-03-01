# RISC-V Toolchain Setup

This setup targets baremetal RISC-V MCUs (for example GD32VF103-class boards).

## 1) Install Toolchain
```bash
sudo apt update
sudo apt install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf gdb-multiarch make
```

If package names differ, install an equivalent `riscv-none-elf-gcc` distribution.

## 2) Verify Installation
```bash
riscv64-unknown-elf-gcc --version
gdb-multiarch --version
```

## 3) Build Minimal Firmware
```bash
riscv64-unknown-elf-gcc -march=rv32imac -mabi=ilp32 -g -O0 -ffreestanding -nostdlib \
	-T linker.ld startup.S main.c -o build/firmware.elf
```

## 4) Flash + Debug
- Use board-compatible OpenOCD config and JTAG/SWD probe.
- Start OpenOCD, then connect from GDB to `:3333`.

## 5) First Bring-Up
- LED blink on known GPIO.
- UART print at fixed baud.
- Interrupt test (button/EXTI) to verify vector setup.

## 6) Common Issues
- ABI/ISA mismatch (`-march`/`-mabi`) causes runtime faults.
- Wrong linker script leads to invalid reset behavior.
- Startup assembly not matching device memory map.

## 7) Quick Success Criteria
- ELF links successfully.
- Probe can halt/load target.
- Blink and UART smoke tests pass.
