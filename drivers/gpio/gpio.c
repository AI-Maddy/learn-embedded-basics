#include "gpio.h"

#define GPIO_MAX_PORTS 8u
#define GPIO_MAX_PINS  32u

static bool gpio_state[GPIO_MAX_PORTS][GPIO_MAX_PINS];
static bool gpio_ready;

drv_status_t gpio_driver_init(void) {
    for (uint8_t port = 0; port < GPIO_MAX_PORTS; ++port) {
        for (uint8_t pin = 0; pin < GPIO_MAX_PINS; ++pin) {
            gpio_state[port][pin] = false;
        }
    }
    gpio_ready = true;
    return DRV_OK;
}

drv_status_t gpio_init(const gpio_pin_t *pin, gpio_mode_t mode, gpio_pull_t pull) {
    (void)mode;
    (void)pull;
    if (!gpio_ready) {
        return DRV_ERR_BUSY;
    }
    if (pin == 0 || pin->port >= GPIO_MAX_PORTS || pin->pin >= GPIO_MAX_PINS) {
        return DRV_ERR_ARG;
    }
    gpio_state[pin->port][pin->pin] = false;
    return DRV_OK;
}

drv_status_t gpio_write(const gpio_pin_t *pin, bool state) {
    if (!gpio_ready) {
        return DRV_ERR_BUSY;
    }
    if (pin == 0 || pin->port >= GPIO_MAX_PORTS || pin->pin >= GPIO_MAX_PINS) {
        return DRV_ERR_ARG;
    }
    gpio_state[pin->port][pin->pin] = state;
    return DRV_OK;
}

drv_status_t gpio_read(const gpio_pin_t *pin, bool *out_state) {
    if (!gpio_ready) {
        return DRV_ERR_BUSY;
    }
    if (pin == 0 || out_state == 0 || pin->port >= GPIO_MAX_PORTS || pin->pin >= GPIO_MAX_PINS) {
        return DRV_ERR_ARG;
    }
    *out_state = gpio_state[pin->port][pin->pin];
    return DRV_OK;
}

drv_status_t gpio_toggle(const gpio_pin_t *pin) {
    bool state;
    drv_status_t status = gpio_read(pin, &state);
    if (status != DRV_OK) {
        return status;
    }
    return gpio_write(pin, !state);
}

drv_status_t gpio_attach_irq(const gpio_pin_t *pin, gpio_irq_edge_t edge, gpio_irq_cb_t cb, void *ctx) {
    (void)edge;
    (void)ctx;
    if (!gpio_ready) {
        return DRV_ERR_BUSY;
    }
    if (pin == 0 || cb == 0 || pin->port >= GPIO_MAX_PORTS || pin->pin >= GPIO_MAX_PINS) {
        return DRV_ERR_ARG;
    }
    return DRV_OK;
}
