# Datasheet Reading

Reading datasheets effectively is a core embedded skill. This guide helps you find critical information fast and avoid common mistakes.

## Why Datasheet Reading Matters
- Register-level code depends on exact bit definitions and reset values.
- Electrical limits determine whether your hardware is safe and reliable.
- Timing and clock details affect peripheral correctness.

## Fast Navigation Strategy
1. Start with the **feature summary** and **pinout** sections.
2. Jump to **electrical characteristics** before driving external hardware.
3. Read **clock system** and **memory map** early.
4. Use **peripheral chapter + register table** while coding.
5. Always check **errata** for known silicon issues.

## Sections You Should Never Skip
- Absolute maximum ratings
- Recommended operating conditions
- Power and clock tree
- Reset and boot configuration
- Interrupt/vector behavior
- Flash and SRAM organization
- Peripheral register descriptions

## Register Reading Checklist
For each register, confirm:
- Address offset and access type (R/W/RO/W1C)
- Reset value
- Bitfield meaning and valid values
- Side effects when reading/writing
- Required write sequence or unlock key

## Practical Workflow While Coding
- Keep datasheet PDF open with bookmarks.
- Search by register name, then verify chapter context.
- Copy constants into header files using exact naming conventions.
- Validate write order from examples/reference manual.

## Common Mistakes
- Using absolute max values as normal operating values.
- Ignoring default pin multiplexing at reset.
- Missing write-protect or unlock requirements.
- Confusing similarly named registers across peripherals.
- Not checking if a bit is write-1-to-clear.

## Electrical Sanity Checks
- Ensure GPIO voltage/current stay within limits.
- Check input threshold compatibility with external devices.
- Validate ADC reference range and sampling constraints.
- Confirm oscillator startup and tolerance requirements.

## Debug-Driven Reading
When behavior is wrong, re-check:
- Reset values after boot
- Clock enable bits and peripheral gating
- Interrupt pending/enable/priority registers
- Flag clear behavior and sequencing notes

## High-Value Habit
Keep a short personal “MCU profile note” with:
- core clock setup sequence
- important pin defaults
- must-set boot bits
- 5 most-used registers per peripheral

## Related Docs
- `docs/memory-mapped-io.md`
- `docs/startup-code.md`
- `docs/linker-scripts.md`
