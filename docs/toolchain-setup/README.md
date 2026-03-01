# Toolchain Setup Index

Setup entry points for each supported target/toolchain combination.

## Available Setup Guides
- `arm-gcc-openocd-setup.md`
- `avr-gcc-setup.md`
- `cc26xx-driverlib-setup.md`
- `msp430-gcc-setup.md`
- `nrf52-baremetal-setup.md`
- `pic-mplabx-setup.md`
- `risc-v-toolchain-setup.md`
- `rp2040-sdk-setup.md`

## How to Choose the Right Guide
- AVR/PIC/MSP430 classic 8/16-bit workflows: use MCU-specific compiler guides.
- ARM Cortex-M targets: prefer `arm-gcc-openocd-setup.md` (or nRF52/RP2040 specific guide).
- RISC-V targets: use `risc-v-toolchain-setup.md`.
- TI wireless targets: use `cc26xx-driverlib-setup.md`.

## Validation Tip
After setup, always run one minimal blink + UART test before starting full driver work.

## Post-Setup Checklist
1. Tool versions confirmed from CLI.
2. Minimal firmware builds without warnings.
3. Flash succeeds on hardware.
4. Debug attach + breakpoint at `main` works.
5. Rebuild is reproducible from a clean shell.

## Common Setup Pitfalls
- Wrong linker script for selected part.
- Hidden SDK path misconfiguration.
- USB permissions not configured for debug probe.
