# PWM Source Notes

Reusable PWM setup, duty update, and timing helper examples.

## Purpose
- Keep timer-to-duty conversion snippets together.
- Document common waveform verification patterns.

## Typical Contents
- Timer base configuration helpers
- Duty-cycle update routines
- Frequency calculation snippets

## Integration Steps
1. Configure timer clock/prescaler.
2. Reuse compare-update helper logic.
3. Validate duty and frequency with scope.

## Validation Checklist
- Frequency error within acceptable range
- Duty updates are glitch-free
- Channel polarity matches hardware expectation

## Adaptation Notes
- Balance frequency versus effective resolution.
- Use preload/buffered updates to avoid glitches.
- Validate dead-time for half/full-bridge applications.

## Debug Workflow
1. Validate base frequency before changing duty dynamically.
2. Sweep duty values and confirm linear output behavior.
3. Check update edge alignment to avoid transient glitches.
4. Keep oscilloscope screenshots for baseline comparison.
