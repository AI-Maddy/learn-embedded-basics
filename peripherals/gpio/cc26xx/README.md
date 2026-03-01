# CC26xx GPIO Examples

GPIO examples for CC26xx targets.

## Files
- `init.c`, `blink.c`, `button.c`, `interrupt.c`

Use these for DIO direction, pull config, and GPIO interrupt bring-up.

## Assumptions
- DIO numbers match board pin map.
- Clock and power domains are configured.

## Bring-Up Flow
1. Run `init.c` and confirm DIO directions.
2. Verify `blink.c` timing on selected DIO LED.
3. Check `button.c` with pull and debounce behavior.
4. Test `interrupt.c` event clear path.

## Validation
- DIO state transitions are stable.
- Button input does not chatter after debounce.
- IRQ flag clear prevents retrigger loops.

## Adaptation Notes
- Double-check DIO mapping against board revision.
- Verify active-low/active-high assumptions.
- Confirm power/sleep settings do not disable GPIO path.

## Extension Ideas
- Add long-press and double-press detection in software.
- Create a board-specific pin-map header for portability.
- Add a simple self-test mode that reports pin states over UART.
