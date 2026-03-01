# Cheatsheets

Fast-reference notes for common baremetal bring-up tasks across supported MCU families.

## What You’ll Find Here
- Per-MCU startup checklist
- Clock/GPIO first-configuration notes
- Interrupt enable pattern reminders
- Minimal “first firmware” flow (blink, UART, timer)

## How to Use
1. Pick your MCU cheatsheet before writing startup code.
2. Confirm clock and reset assumptions.
3. Validate GPIO direction and pull configuration.
4. Follow interrupt and main-loop sequence.

## Available Families
- AVR, C2000, CC26xx, GD32VF103
- MSP430, nRF52, PIC, RP2040, STM32F1

## Best Practice
- Keep the cheatsheet open while editing register-level code.
- Cross-check values with datasheet + reference manual for your exact part revision.

## Related Folders
- `resources/datasheets/`
- `resources/reference-manuals/`
- `mcu-profiles/`
- `docs/toolchain-setup/`

Update these cheatsheets whenever a recurring bring-up issue is discovered in real hardware testing.

## Bring-Up Flow
1. Start with the MCU-specific cheatsheet for your target.
2. Validate clock/reset assumptions before enabling peripherals.
3. Run one GPIO and one timer/UART smoke test before scaling.

## Validation Checklist
- Clock source and divider assumptions are documented.
- First peripheral tests pass on real hardware.
- Interrupt enable sequence follows peripheral setup order.

## Common Pitfalls
- Mixing examples from different MCU families without adapting registers.
- Skipping board-level pin mapping verification.
- Enabling interrupts before clearing pending source flags.