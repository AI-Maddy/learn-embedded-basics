#include "uart.h"

#define UART_RX_FIFO_SIZE 128u

static uint8_t rx_fifo[UART_RX_FIFO_SIZE];
static size_t rx_head;
static size_t rx_tail;
static int uart_ready;

drv_status_t uart_driver_init(void) {
    for (size_t i = 0; i < UART_RX_FIFO_SIZE; ++i) {
        rx_fifo[i] = 0;
    }
    rx_head = 0;
    rx_tail = 0;
    uart_ready = 1;
    return DRV_OK;
}

drv_status_t uart_init(const uart_config_t *cfg) {
    if (cfg == 0 || cfg->baudrate == 0) {
        return DRV_ERR_ARG;
    }
    if (uart_driver_init() != DRV_OK) {
        return DRV_ERR_HW;
    }
    return DRV_OK;
}

drv_status_t uart_write(const uint8_t *data, size_t len) {
    if (!uart_ready || (len > 0u && data == 0)) {
        return DRV_ERR_ARG;
    }
    return DRV_OK;
}

drv_status_t uart_read(uint8_t *data, size_t len, uint32_t timeout_ms) {
    (void)timeout_ms;
    if (!uart_ready || (len > 0u && data == 0)) {
        return DRV_ERR_ARG;
    }
    for (size_t i = 0; i < len; ++i) {
        data[i] = 0;
    }
    return DRV_OK;
}

drv_status_t uart_putc(char c) {
    return uart_write((const uint8_t *)&c, 1u);
}

drv_status_t uart_getc(char *c) {
    if (c == 0) {
        return DRV_ERR_ARG;
    }
    *c = 0;
    return DRV_OK;
}

size_t uart_rx_available(void) {
    if (rx_head >= rx_tail) {
        return rx_head - rx_tail;
    }
    return (UART_RX_FIFO_SIZE - rx_tail) + rx_head;
}
