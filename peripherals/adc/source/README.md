# ADC Source Notes

Reusable ADC source examples and helper implementations.

## Purpose
- Keep low-level ADC sample code and helper logic in one place.
- Reuse snippets across MCU-specific examples where possible.

## Typical Contents
- Channel setup helpers
- Sample trigger and completion checks
- Raw-to-engineering conversion utilities

## Integration Steps
1. Configure ADC clock and GPIO analog mode.
2. Reuse init and read helper patterns from this folder.
3. Validate conversion stability with fixed reference input.

## Validation Checklist
- Stable values for fixed voltage
- Correct channel switching behavior
- No lockup on repeated conversions

## Adaptation Notes
- Confirm ADC reference source and scaling constants.
- Adjust sampling time for sensor source impedance.
- Prefer timer-triggered sampling for periodic workloads.

## Debug Workflow
1. Start with one known-good channel and static input.
2. Log raw register values before applying conversion math.
3. Add one advanced feature at a time (interrupt, DMA, averaging).
4. Keep minimal repro snippets in this folder for regression checks.
