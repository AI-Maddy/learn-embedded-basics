# SPI Driver

Serial Peripheral Interface (SPI) drivers support high-speed full-duplex communication with sensors, displays, memory, and radio chips.

## Scope
- Master mode configuration (CPOL/CPHA, bit order, baud)
- Chip-select management (hardware or software CS)
- Blocking transfer APIs and optional interrupt/DMA variants
- Device-specific transaction framing

## Suggested Driver API
- `spi_init(const spi_config_t *cfg)`
- `spi_transfer(const uint8_t *tx, uint8_t *rx, size_t len)`
- `spi_write(const uint8_t *tx, size_t len)`
- `spi_read(uint8_t *rx, size_t len)`
- `spi_cs_assert(const gpio_pin_t *cs)` / `spi_cs_deassert(const gpio_pin_t *cs)`

## Baremetal Bring-Up Order
1. Configure SCK/MOSI/MISO pins in alternate mode
2. Enable SPI clock and program mode/baud settings
3. Validate communication with known register read
4. Add transaction-level timeout and error recovery
5. Optionally optimize with DMA for larger transfers

## Common Pitfalls
- CPOL/CPHA mismatch with slave device expectations
- CS timing violation between command and data phases
- Clock speed too high for wiring/layout quality

## Validation Checklist
- Read known chip ID register reliably
- Multi-byte transfer integrity verified
- Works across minimum and maximum supported SPI clocks