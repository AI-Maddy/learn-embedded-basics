# MCU Profiles Index

This index helps you compare supported MCU families and jump to their detailed baremetal profile pages.

## Quick Comparison

| MCU | Core | Word Size | Typical Strength | Common Debug/Flash | Profile |
|---|---|---:|---|---|---|
| AVR ATmega328P | AVR | 8-bit | Simple control + education | ISP / avrdude | [avr-atmega328p](avr-atmega328p/README.md) |
| C2000 F28027 | TI C28x | 32-bit | Motor/digital power control | CCS + XDS probe | [c2000-f28027](c2000-f28027/README.md) |
| CC2640R2F | Cortex-M3 + RF | 32-bit | Low-power BLE nodes | XDS/LaunchPad tools | [cc2640r2f](cc2640r2f/README.md) |
| GD32VF103 | RISC-V | 32-bit | RISC-V baremetal learning | OpenOCD/JTAG flows | [gd32vf103](gd32vf103/README.md) |
| MSP430G2553 | MSP430 | 16-bit | Ultra-low-power sensing | MSP-FET / LaunchPad | [msp430g2553](msp430g2553/README.md) |
| nRF52832 | Cortex-M4F + RF | 32-bit | BLE and wireless sensing | SWD / J-Link | [nrf52832](nrf52832/README.md) |
| PIC16F877A | PIC | 8-bit | Foundational register-level work | PICkit + MPLAB | [pic16f877a](pic16f877a/README.md) |
| RP2040 | Dual Cortex-M0+ | 32-bit | Fast prototyping + PIO | UF2 + SWD | [rp2040](rp2040/README.md) |
| STM32F103 | Cortex-M3 | 32-bit | General-purpose embedded | ST-Link + OpenOCD | [stm32f103](stm32f103/README.md) |

## How to Use This Folder
1. Pick an MCU profile from the table.
2. Follow its startup order and bring-up checklist.
3. Implement peripherals using `drivers/` skeletons.
4. Cross-check with protocol details under `peripherals/`.

## Suggested First Bring-Up (Any MCU)
- Blink a GPIO output
- Print UART startup banner
- Add timer-based heartbeat
- Read one ADC channel (if available)

## Related Paths
- Drivers: `drivers/`
- Peripheral docs: `peripherals/`
- Setup docs: `docs/toolchain-setup/`
- Quick references: `resources/cheatsheets/`
