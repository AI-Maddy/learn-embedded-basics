# Interrupt Source Notes

Reusable interrupt setup and ISR structure examples.

## Purpose
- Keep vector setup and flag-clear patterns centralized.
- Provide quick ISR templates for peripheral modules.

## Typical Contents
- ISR skeleton templates
- NVIC/INT controller setup helpers
- Pending-flag clear examples

## Integration Steps
1. Configure interrupt source and priority.
2. Register/declare ISR using target syntax.
3. Validate event-triggered ISR entry with breakpoint.

## Validation Checklist
- ISR fires on correct edge/event
- Pending flag is cleared correctly
- Main loop remains responsive under interrupt load

## Adaptation Notes
- Keep ISR minimal and defer heavy work.
- Define clear priority policy per subsystem.
- Measure worst-case ISR latency on real hardware.

## Debug Workflow
1. Trigger one interrupt source in isolation first.
2. Confirm vector entry and pending-flag clear sequence.
3. Stress with burst events to expose latency bottlenecks.
4. Track missed-event counters during long-run tests.
