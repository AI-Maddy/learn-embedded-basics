# PIC16F877A Profile

## MCU Snapshot
- Core: 8-bit PIC
- Best for: foundational embedded labs and simple automation logic
- Strength: mature ecosystem and easy register-level learning

## Baremetal Startup Order
1. Set configuration bits (oscillator, watchdog, power-up options)
2. Initialize TRIS/PORT state for all used pins
3. Configure Timer/UART/ADC modules
4. Configure interrupt masks and global enable
5. Enter superloop and service timing/events

## Toolchain
- MPLAB X + XC8 compiler
- Config bits usually set via pragmas or project settings

## Flash + Debug
- PICkit class programmers/debuggers commonly used
- Verify oscillator config matches board hardware before flash

## Pin/Peripheral Priorities
- TRIS registers decide direction; validate every used pin
- PORTB interrupt behavior requires careful flag handling
- ADC acquisition timing should match sensor source impedance

## Bring-Up Checklist
- Clock configuration boots reliably
- LED blink + button read working
- UART transmit test reaches terminal
- ADC fixed-input reading remains stable

## References in Repo
- Peripheral docs: `peripherals/gpio`, `peripherals/uart`, `peripherals/adc`
- Driver skeletons: `drivers/*`