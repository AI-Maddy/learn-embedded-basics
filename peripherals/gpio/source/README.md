# GPIO Source Notes

Reusable GPIO source snippets shared across board examples.

## Purpose
- Consolidate init/read/write/toggle patterns.
- Keep small portable helpers for quick bring-up.

## Typical Contents
- Pin mode configuration helpers
- Input read and output control snippets
- Interrupt attach/clear patterns

## Integration Steps
1. Enable port clock and configure mode.
2. Reuse write/toggle helper pattern.
3. Validate button/LED pair for input-output sanity.

## Validation Checklist
- Output toggles predictably
- Input logic level is stable with pull config
- Interrupt flag clear sequence is correct

## Adaptation Notes
- Keep pin mapping centralized per board.
- Prefer atomic set/reset registers where available.
- Reserve debug and boot pins early.

## Debug Workflow
1. Start with one output pin and one input pin sanity test.
2. Validate register write/readback before adding abstractions.
3. Add interrupt behavior only after polling path is stable.
4. Keep a tiny board smoke-test file in this folder.
