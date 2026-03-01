#include <stdint.h>
#include "uart.h"

int main(void) {
    // Update UART framing to match terminal/peer device requirements.
    uart_config_t cfg = {
        .baudrate = 115200,
        .parity = 0,
        .stop_bits = 1
    };

    static const uint8_t msg[] = "UART ready\r\n";

    if (uart_driver_init() != DRV_OK) return -1;
    if (uart_init(&cfg) != DRV_OK) return -1;
    if (uart_write(msg, sizeof(msg) - 1) != DRV_OK) return -1;

    for (;;) {
        // Add RX handling or command parser here.
    }
}
