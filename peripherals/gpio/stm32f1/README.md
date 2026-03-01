# STM32F1 GPIO Examples

GPIO examples for STM32F1 targets.

## Files
- `init.c`, `blink.c`, `button.c`, `interrupt.c`

Use these to validate RCC/GPIO setup and EXTI interrupt mapping.

## Assumptions
- RCC clock for used ports is enabled.
- Pin mapping matches board hardware (for example Blue Pill LED pin).

## Bring-Up Flow
1. Verify `init.c` mode and clock config.
2. Run `blink.c` and confirm output polarity.
3. Test `button.c` with expected input edge.
4. Validate EXTI mapping/IRQ in `interrupt.c`.

## Validation
- GPIO registers reflect configured mode.
- EXTI pending flag clears in handler.
- Repeated button presses trigger stable interrupts.

## Adaptation Notes
- Verify RCC/AFIO clock enables before EXTI setup.
- Check input floating vs pull mode selection.
- Confirm IRQ priority and handler mapping in NVIC.

## Extension Ideas
- Add long-press and double-press detection in software.
- Create a board-specific pin-map header for portability.
- Add a simple self-test mode that reports pin states over UART.
