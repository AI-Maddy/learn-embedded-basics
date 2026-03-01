# Datasheets

This folder is for official MCU, sensor, and peripheral datasheets used during hardware/software bring-up.

## Why Datasheets Matter
- Define electrical limits and safe operating ranges.
- Provide register maps and reset values.
- Explain timing requirements and interface constraints.

## Recommended Organization
- Group files by vendor and device family.
- Use clear names: `vendor_partnumber_datasheet.pdf`.
- Keep revision in filename when multiple versions are needed.

## What to Check First in Any Datasheet
1. Absolute max ratings
2. Operating voltage/temperature range
3. Pin functions and alternate modes
4. Clock and reset behavior
5. Peripheral register overview

## Validation Workflow
- Confirm pin voltage compatibility before wiring.
- Verify current limits for GPIO-driven loads.
- Compare register defaults against debugger reads.

## Related Folders
- `resources/pinouts/`
- `resources/reference-manuals/`
- `docs/datasheet-reading.md`