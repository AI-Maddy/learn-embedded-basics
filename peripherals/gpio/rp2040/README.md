# RP2040 GPIO Examples

GPIO examples for RP2040 targets.

## Files
- `init.c`, `blink.c`, `button.c`, `interrupt.c`

Use these with Pico SDK style GPIO and callback-based interrupts.

## Assumptions
- Board pin mapping is correct (e.g., LED GPIO25 on Pico).
- SDK startup and clock setup are functional.

## Bring-Up Flow
1. Run `init.c` to verify GPIO init path.
2. Confirm `blink.c` output timing.
3. Validate `button.c` input + pull-up behavior.
4. Test `interrupt.c` callback registration and firing.

## Validation
- Output pin toggles at expected interval.
- Button logic level is interpreted correctly.
- Interrupt callback executes without lockups.

## Adaptation Notes
- Confirm SDK board definition and LED pin mapping.
- Keep callback handlers minimal and non-blocking.
- Validate pull-up/down config for external buttons.

## Extension Ideas
- Add long-press and double-press detection in software.
- Create a board-specific pin-map header for portability.
- Add a simple self-test mode that reports pin states over UART.
