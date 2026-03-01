# SPI Source Notes

Reusable SPI source snippets for mode setup and data transfers.

## Purpose
- Keep CPOL/CPHA-safe transaction templates.
- Reuse chip-select and transfer helper routines.

## Typical Contents
- SPI mode and bitrate setup helpers
- Full-duplex transfer routines
- Chip-select timing patterns

## Integration Steps
1. Configure SCK/MOSI/MISO pin modes.
2. Apply known-good mode/clock settings.
3. Read fixed ID register from target device.

## Validation Checklist
- Correct SPI mode confirmed on analyzer
- Multi-byte transfer integrity verified
- CS timing matches device datasheet

## Adaptation Notes
- Validate CPOL/CPHA against each slave device.
- Add transfer timeout and error paths.
- Separate bus-locking concerns in shared SPI designs.

## Debug Workflow
1. Start with low clock rate and single-byte transfers.
2. Confirm mode and CS timing on logic analyzer captures.
3. Scale to burst transfers after ID-read path is stable.
4. Keep per-device configuration notes near source snippets.
