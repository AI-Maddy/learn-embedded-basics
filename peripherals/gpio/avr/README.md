# AVR GPIO Examples

GPIO examples for AVR targets.

## Files
- `init.c`, `blink.c`, `button.c`, `interrupt.c`

Use these as starter templates for register-level GPIO bring-up.

## Assumptions
- Target family similar to ATmega328P.
- LED and button pins must be mapped to your board wiring.

## Bring-Up Flow
1. Run `init.c` baseline first.
2. Validate `blink.c` timing.
3. Verify `button.c` pull-up and debounce behavior.
4. Confirm `interrupt.c` toggles output from ISR.

## Validation
- LED toggles consistently.
- Button press reads stable logic.
- External interrupt triggers reliably.

## Adaptation Notes
- Map pins to actual board schematic before compile.
- Confirm clock/fuse assumptions for delay accuracy.
- Validate interrupt edge polarity per button wiring.

## Extension Ideas
- Add long-press and double-press detection in software.
- Create a board-specific pin-map header for portability.
- Add a simple self-test mode that reports pin states over UART.
