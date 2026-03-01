# MSP430 GPIO Examples

GPIO examples for MSP430 targets.

## Files
- `init.c`, `blink.c`, `button.c`, `interrupt.c`

Use these to verify pull-up/down configuration and port interrupts.

## Assumptions
- Watchdog disabled or serviced in startup.
- Pin mapping aligns with board LED/button wiring.

## Bring-Up Flow
1. Confirm `init.c` direction/pull setup.
2. Validate `blink.c` timing and stable toggling.
3. Check `button.c` input and debounce behavior.
4. Run `interrupt.c` to validate port interrupt ISR.

## Validation
- No unintended resets from watchdog.
- Button events map correctly to LED action.
- Port interrupt flag is cleared correctly in ISR.

## Adaptation Notes
- Stop or service watchdog early in startup.
- Confirm pull resistor direction via PxOUT/PxREN.
- Keep ISR short and flag-driven.

## Extension Ideas
- Add long-press and double-press detection in software.
- Create a board-specific pin-map header for portability.
- Add a simple self-test mode that reports pin states over UART.
