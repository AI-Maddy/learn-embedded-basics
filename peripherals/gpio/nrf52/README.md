# nRF52 GPIO Examples

GPIO examples for nRF52 targets.

## Files
- `init.c`, `blink.c`, `button.c`, `interrupt.c`

Use these to validate GPIO + GPIOTE style interrupt workflows.

## Assumptions
- Selected P0 pins map to board LED/button.
- Clock and debug access are stable.

## Bring-Up Flow
1. Run `init.c` to verify direction/pull states.
2. Validate `blink.c` output behavior.
3. Test `button.c` active-level handling.
4. Confirm `interrupt.c` event/flag handling.

## Validation
- GPIO reads/writes match expected logic levels.
- Debounce behavior prevents false toggles.
- GPIOTE interrupt route works repeatedly.

## Adaptation Notes
- Confirm pin function ownership for shared peripherals.
- Review event/interrupt clear semantics carefully.
- Use a logic analyzer for edge-trigger verification.

## Extension Ideas
- Add long-press and double-press detection in software.
- Create a board-specific pin-map header for portability.
- Add a simple self-test mode that reports pin states over UART.
