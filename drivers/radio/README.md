# Radio Driver

Radio drivers provide low-level control for RF peripherals (e.g., sub-GHz, 2.4GHz BLE/Proprietary transceivers).

## Scope
- Radio core initialization and channel configuration
- TX/RX packet setup and buffering
- Power level and data rate configuration
- IRQ handling for packet done/error events

## Suggested Driver API
- `radio_init(const radio_config_t *cfg)`
- `radio_set_channel(uint8_t channel)`
- `radio_set_tx_power(int8_t dbm)`
- `radio_tx(const uint8_t *payload, size_t len)`
- `radio_rx_start(void)` / `radio_rx_read(uint8_t *buf, size_t *len)`

## Baremetal Bring-Up Order
1. Configure clocks and RF front-end dependencies
2. Initialize radio state machine and packet format
3. Program channel, address, CRC, whitening (if applicable)
4. Enable radio interrupts and test loopback/pair communication
5. Add timeout/retry logic and link-quality reporting

## Common Pitfalls
- Region-specific frequency/channel misuse
- Missing antenna matching assumptions in board design
- Interrupt race conditions around TX/RX state transitions

## Validation Checklist
- TX/RX works with known-good peer device
- Packet CRC failures handled and counted
- Range test confirms expected link margin