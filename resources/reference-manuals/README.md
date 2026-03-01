# Reference Manuals

Reference manuals contain detailed architecture and register-level descriptions beyond datasheet summaries.

## Typical Content
- Full peripheral register definitions
- Clock tree and reset controller details
- Interrupt controller behavior
- DMA, bus matrix, and debug subsystem notes

## When to Use Reference Manuals
- Writing/porting low-level drivers
- Debugging unexplained peripheral behavior
- Verifying reserved-bit and write-sequence rules

## Reading Strategy
1. Start with peripheral overview and block diagram.
2. Read register descriptions including access semantics.
3. Check programming sequence and timing notes.
4. Validate interrupt/flag clear behavior.

## High-Value Sections to Bookmark
- Memory map chapter
- RCC/clocking chapter
- Interrupt controller chapter
- Peripheral chapters you actively use

## Related Folders
- `resources/datasheets/`
- `resources/timing-diagrams/`
- `drivers/`