# Pinouts

Pinout references for MCUs, development boards, and common modules used in this project.

## Why Pinouts Are Critical
- Avoid wiring mistakes during bring-up.
- Confirm alternate-function mapping for peripherals.
- Prevent voltage-level and current-limit violations.

## Recommended Contents
- MCU package pin maps (QFP/QFN/DIP variants)
- Board-level labels (header pin names)
- Interface examples (UART/SPI/I2C default pins)
- Notes on 5V/3.3V compatibility

## Usage Checklist
1. Confirm board revision and package type.
2. Match pinout with datasheet alternate-function table.
3. Verify debug pins (SWD/JTAG) remain accessible.
4. Mark reserved/boot pins before routing signals.

## Common Mistakes to Avoid
- Using board silk labels without checking MCU pin mapping.
- Assigning two peripherals to the same alternate-function pin.
- Ignoring boot strap pin requirements.

## Related Folders
- `resources/datasheets/`
- `resources/reference-manuals/`
- `docs/memory-mapped-io.md`