# UART Driver

Universal Asynchronous Receiver/Transmitter (UART) drivers provide serial communication for logs, CLI, and module control.

## Scope
- Baud/parity/stop-bit configuration
- Blocking and interrupt-driven TX/RX
- Ring-buffered receive path
- Optional line-oriented parsing for shell/AT commands

## Suggested Driver API
- `uart_init(const uart_config_t *cfg)`
- `uart_write(const uint8_t *data, size_t len)`
- `uart_read(uint8_t *data, size_t len, uint32_t timeout_ms)`
- `uart_putc(char c)` / `uart_getc(char *c)`
- `uart_rx_available(void)`

## Baremetal Bring-Up Order
1. Configure TX/RX pins and enable UART peripheral clock
2. Set baud-rate divisor from system clock
3. Enable TX/RX and validate loopback or terminal output
4. Add interrupt handler for robust RX buffering
5. Integrate protocol framing and timeout behavior

## Common Pitfalls
- Baud mismatch due to wrong core clock assumptions
- Missing FIFO/flag handling causing dropped bytes
- ISR too slow for high baud traffic bursts

## Validation Checklist
- Terminal receives clean startup banner
- Echo test passes at target baud rate
- Long burst transfer shows no framing or overrun errors