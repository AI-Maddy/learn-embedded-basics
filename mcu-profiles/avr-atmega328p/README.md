# AVR ATmega328P Profile

## MCU Snapshot
- Core: 8-bit AVR
- Best for: simple control loops, GPIO-heavy projects, low-cost boards
- Common boards: Arduino Uno-class hardware

## Baremetal Startup Order
1. Confirm clock source (internal RC or external crystal via fuses)
2. Configure stack/runtime (usually startup file handles this)
3. Initialize GPIO directions and pull-ups
4. Initialize timers/UART/ADC as needed
5. Enable global interrupts (`sei`) when peripherals are ready

## Toolchain
- Compiler: `avr-gcc`
- Binary tools: `avr-objcopy`, `avr-size`
- Programmer: `avrdude`

## Flash + Debug
- Flash interface: ISP (SPI)
- Typical programmer: USBasp / Atmel-ICE
- Debug note: true on-chip debug depends on tool and fuse setup

## Pin/Peripheral Priorities
- GPIO: `DDRx`, `PORTx`, `PINx`
- Timers: PWM and timebase for periodic tasks
- UART: first choice for bring-up logs
- ADC: validate reference and channel setup early

## Bring-Up Checklist
- LED blink works on known output pin
- UART prints a startup banner
- Timer interrupt toggles at expected interval
- ADC returns stable values on fixed input

## References in Repo
- Peripheral docs: `peripherals/gpio`, `peripherals/uart`, `peripherals/adc`
- Driver skeletons: `drivers/*`