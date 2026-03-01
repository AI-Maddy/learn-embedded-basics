# GD32VF103 GPIO Examples

GPIO examples for GD32VF103 targets.

## Files
- `init.c`, `blink.c`, `button.c`, `interrupt.c`

Use these to validate RCU + GPIO mode setup and EXTI behavior.

## Assumptions
- Board pinout matches selected LED/button pins.
- RCU clocks enabled before GPIO register access.

## Bring-Up Flow
1. Validate `init.c` clock + mode setup.
2. Run `blink.c` to verify output state changes.
3. Use `button.c` to confirm input behavior.
4. Validate EXTI mapping in `interrupt.c`.

## Validation
- PC13 (or configured LED pin) toggles correctly.
- Button press transitions are clean.
- EXTI handler runs and clears interrupt flag.

## Adaptation Notes
- Validate RCU clock enable order before GPIO access.
- Keep EXTI port-source mapping explicit in code.
- Verify pull configuration for floating inputs.

## Extension Ideas
- Add long-press and double-press detection in software.
- Create a board-specific pin-map header for portability.
- Add a simple self-test mode that reports pin states over UART.
