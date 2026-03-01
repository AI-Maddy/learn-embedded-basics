# Radio Source Notes

Reusable radio driver/source snippets for packet TX/RX bring-up.

## Purpose
- Capture channel/power/init sequences.
- Keep IRQ and state-machine helper patterns in one place.

## Typical Contents
- Radio init and channel config snippets
- TX/RX state transition helpers
- Packet event IRQ handlers

## Integration Steps
1. Configure clocks and radio prerequisites.
2. Reuse TX/RX initialization sequence.
3. Validate with known-good peer node.

## Validation Checklist
- Packet transmit completes successfully
- Receive path handles CRC/error cases
- Interrupt-driven state transitions are stable

## Adaptation Notes
- Keep channel/address plan documented by environment.
- Add retry/backoff policy for noisy links.
- Track packet error counters during field tests.

## Debug Workflow
1. Verify local loopback or two-node baseline communication.
2. Confirm packet format and CRC settings match on both peers.
3. Introduce controlled packet loss to validate retry policy.
4. Log RSSI/error counters during soak testing.
