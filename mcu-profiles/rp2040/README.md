# RP2040 Profile

## MCU Snapshot
- Core: Dual-core ARM Cortex-M0+
- Best for: education, rapid prototyping, mixed I/O projects
- Strength: flexible GPIO and PIO subsystem

## Baremetal Startup Order
1. Let boot ROM/startup initialize baseline clocks
2. Initialize board pins (LED/UART/debug pins first)
3. Configure timers/PWM/SPI/I2C/UART based on app needs
4. Set up interrupt callbacks
5. Enter loop or multicore task scheduling pattern

## Toolchain
- ARM GCC with Pico SDK-style headers/tooling
- CMake-based builds are common in RP2040 flows

## Flash + Debug
- UF2 drag-and-drop for quick flashing
- SWD debug via Picoprobe/J-Link class tools

## Pin/Peripheral Priorities
- Confirm GPIO function select when using alternate peripherals
- PIO can offload timing-sensitive protocols
- USB/UART logging helps early bring-up significantly

## Bring-Up Checklist
- Onboard LED blink test
- UART print or USB serial output
- One peripheral loopback test (SPI or I2C)
- Interrupt callback path validated

## References in Repo
- Peripheral docs: `peripherals/spi`, `peripherals/i2c`, `peripherals/pwm`
- Driver skeletons: `drivers/*`