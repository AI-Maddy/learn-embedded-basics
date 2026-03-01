# I2C Driver

Inter-Integrated Circuit (I2C) drivers support multi-device communication over SDA/SCL with addressing and ACK/NACK handling.

## Scope
- Master transmit/receive operations
- Register read/write helpers for sensors and EEPROMs
- Bus speed setup (100kHz/400kHz)
- Recovery path for stuck bus conditions

## Suggested Driver API
- `i2c_init(const i2c_config_t *cfg)`
- `i2c_write(uint8_t addr, const uint8_t *data, size_t len)`
- `i2c_read(uint8_t addr, uint8_t *data, size_t len)`
- `i2c_mem_write(uint8_t addr, uint8_t reg, const uint8_t *data, size_t len)`
- `i2c_mem_read(uint8_t addr, uint8_t reg, uint8_t *data, size_t len)`

## Baremetal Bring-Up Order
1. Configure GPIO alternate-function/open-drain for SDA/SCL
2. Enable I2C clock and timing registers
3. Issue a bus scan or known register read
4. Add timeout paths for start/address/data phases
5. Integrate retry or bus-recovery if needed

## Common Pitfalls
- Missing external pull-up resistors
- Incorrect timing value for system clock
- Not handling NACK and timeout states

## Validation Checklist
- Detect expected slave address
- Read stable WHO_AM_I/device-id register
- Repeated start operations work reliably