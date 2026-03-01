# I2C Source Notes

Reusable I2C source snippets for bus init and transaction helpers.

## Purpose
- Capture known-good start/address/read/write sequences.
- Reuse timeout and error-handling patterns.

## Typical Contents
- Bus init timing setup
- Register read/write helper transactions
- Retry and timeout handling snippets

## Integration Steps
1. Configure SDA/SCL pins and pull-ups.
2. Reuse memory-read/write patterns.
3. Validate using a known sensor register.

## Validation Checklist
- Slave ACKs expected address
- Repeated start works reliably
- Timeout path recovers gracefully

## Adaptation Notes
- Tune bus speed for trace length and pull-ups.
- Add bus-recovery for stuck-low lines.
- Validate with known identity register reads.

## Debug Workflow
1. Start at 100 kHz with known pull-up values.
2. Verify START/address/ACK sequence on a logic analyzer.
3. Introduce repeated-start and multi-byte transfers next.
4. Preserve a known-good transaction trace for comparison.
