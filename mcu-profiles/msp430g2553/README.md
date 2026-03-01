# MSP430G2553 Profile

## MCU Snapshot
- Core: TI MSP430 16-bit ultra-low-power MCU
- Best for: battery devices, simple sensing/control tasks
- Strength: low-power modes and straightforward peripheral set

## Baremetal Startup Order
1. Stop watchdog timer early in `main`
2. Configure DCO/clock sources for target timing
3. Set GPIO direction + pull resistors
4. Configure Timer_A/UART/ADC as needed
5. Enable interrupts and enter low-power or loop mode

## Toolchain
- TI CCS toolchain or MSP430 GCC
- Linker/startup files should match exact device variant

## Flash + Debug
- MSP-FET / LaunchPad debug interfaces commonly used
- Ensure device signature matches flashing target

## Pin/Peripheral Priorities
- Port interrupt edge configuration for buttons/sensors
- Timer_A for periodic wakeups and PWM
- ADC reference/clock configuration for stable readings

## Bring-Up Checklist
- Watchdog disabled or serviced intentionally
- LED blink + button interrupt validated
- UART echo test successful
- Low-power wakeup source verified

## References in Repo
- Peripheral docs: `peripherals/interrupts`, `peripherals/timers`, `peripherals/adc`
- Driver skeletons: `drivers/*`