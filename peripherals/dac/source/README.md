# DAC Source Notes

Reusable DAC source examples and helper implementations.

## Purpose
- Store baseline DAC init/output patterns.
- Keep voltage output examples easy to port.

## Typical Contents
- DAC enable and channel config routines
- Output value update helpers
- Waveform generation snippets

## Integration Steps
1. Enable DAC clock and output pin mode.
2. Apply known-good init sequence.
3. Sweep output values and measure analog output.

## Validation Checklist
- Output pin tracks commanded value
- Reference voltage assumptions are documented
- Update rate matches timer trigger expectations

## Adaptation Notes
- Verify output buffer/drive capability for load.
- Match numeric range to DAC resolution.
- Confirm settling time meets application needs.

## Debug Workflow
1. Validate one fixed DAC code and measure output voltage.
2. Confirm monotonic stepping with a small ramp sequence.
3. Add timer-triggered updates only after static output is stable.
4. Keep minimal waveform examples here for quick regression.
