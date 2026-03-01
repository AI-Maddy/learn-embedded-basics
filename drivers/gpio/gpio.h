#ifndef GPIO_H
#define GPIO_H

#include <stdbool.h>
#include <stdint.h>
#include "../common/drv_status.h"

typedef enum {
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_ALT,
    GPIO_MODE_ANALOG
} gpio_mode_t;

typedef enum {
    GPIO_PULL_NONE = 0,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN
} gpio_pull_t;

typedef enum {
    GPIO_IRQ_RISING = 0,
    GPIO_IRQ_FALLING,
    GPIO_IRQ_BOTH
} gpio_irq_edge_t;

typedef struct {
    uint8_t port;
    uint8_t pin;
} gpio_pin_t;

typedef void (*gpio_irq_cb_t)(void *ctx);

drv_status_t gpio_driver_init(void);
drv_status_t gpio_init(const gpio_pin_t *pin, gpio_mode_t mode, gpio_pull_t pull);
drv_status_t gpio_write(const gpio_pin_t *pin, bool state);
drv_status_t gpio_read(const gpio_pin_t *pin, bool *out_state);
drv_status_t gpio_toggle(const gpio_pin_t *pin);
drv_status_t gpio_attach_irq(const gpio_pin_t *pin, gpio_irq_edge_t edge, gpio_irq_cb_t cb, void *ctx);

#endif
