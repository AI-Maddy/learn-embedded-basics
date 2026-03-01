#ifndef UART_H
#define UART_H

#include <stddef.h>
#include <stdint.h>
#include "../common/drv_status.h"

typedef struct {
    uint32_t baudrate;
    uint8_t parity;
    uint8_t stop_bits;
} uart_config_t;

drv_status_t uart_driver_init(void);
drv_status_t uart_init(const uart_config_t *cfg);
drv_status_t uart_write(const uint8_t *data, size_t len);
drv_status_t uart_read(uint8_t *data, size_t len, uint32_t timeout_ms);
drv_status_t uart_putc(char c);
drv_status_t uart_getc(char *c);
size_t uart_rx_available(void);

#endif
