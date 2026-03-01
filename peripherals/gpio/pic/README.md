# PIC GPIO Examples

GPIO examples for PIC targets.

## Files
- `init.c`, `blink.c`, `button.c`, `interrupt.c`

Use these as templates for TRIS/PORT setup and external interrupts.

## Assumptions
- Config bits and oscillator mode are correct.
- TRIS/PORT pin mapping matches board wiring.

## Bring-Up Flow
1. Apply `init.c` for base I/O direction.
2. Validate `blink.c` on output pin.
3. Run `button.c` and verify active-low/active-high logic.
4. Test `interrupt.c` external interrupt path.

## Validation
- GPIO direction is correct on all used pins.
- Button path is stable after debounce.
- External interrupt flag handling is robust.

## Adaptation Notes
- Confirm oscillator config bits before timing tests.
- Re-check TRIS/PORT defaults after reset.
- Validate active level for external interrupt source.

## Extension Ideas
- Add long-press and double-press detection in software.
- Create a board-specific pin-map header for portability.
- Add a simple self-test mode that reports pin states over UART.
