# Timing Diagrams

Timing diagrams visualize signal relationships and are essential for validating communication protocols.

## What to Store Here
- UART frame timing (start/data/parity/stop)
- SPI clock/data phase diagrams (CPOL/CPHA)
- I2C start/stop/ACK timing references
- PWM period/duty waveform examples

## Why They Matter
- Help debug scope/logic-analyzer captures.
- Clarify protocol setup before writing firmware.
- Reduce integration issues with external devices.

## Practical Workflow
1. Capture real signals with scope/logic analyzer.
2. Compare against known-good timing diagram.
3. Adjust clock polarity/phase or bus speed.
4. Re-capture and verify setup/hold margins.

## Common Timing Pitfalls
- SPI mode mismatch between master/slave
- I2C rise-time issues due to weak/strong pull-ups
- UART baud mismatch causing framing errors
- PWM frequency drift due to wrong timer clock source

## Related Folders
- `peripherals/spi/`, `peripherals/i2c/`, `peripherals/uart/`
- `docs/debugging/openocd.md`
