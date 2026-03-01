# C2000 GPIO Examples

GPIO examples for C2000 targets.

## Files
- `init.c`, `blink.c`, `button.c`, `interrupt.c`

Use these to validate GPIO mux, direction, and interrupt handling.

## Assumptions
- Device class similar to F28027.
- GPIO mux and EALLOW/EDIS access are required.

## Bring-Up Flow
1. Confirm system clock and GPIO mux setup.
2. Run `blink.c` and scope the output.
3. Test `button.c` input logic and debounce.
4. Validate `interrupt.c` ISR acknowledge path.

## Validation
- No protected-register access faults.
- Interrupt acknowledge prevents repeated false triggers.
- GPIO transitions are deterministic.

## Adaptation Notes
- Review GPIO mux registers before pin assignment.
- Keep EALLOW/EDIS blocks minimal and focused.
- Measure ISR timing in control-loop context.

## Extension Ideas
- Add long-press and double-press detection in software.
- Create a board-specific pin-map header for portability.
- Add a simple self-test mode that reports pin states over UART.
