#include <stdbool.h>
#include "gpio.h"

int main(void) {
    // Map these to board-specific LED and button pins.
    gpio_pin_t led = { .port = 0, .pin = 5 };
    gpio_pin_t button = { .port = 0, .pin = 13 };
    bool pressed = false;

    if (gpio_driver_init() != DRV_OK) return -1;
    if (gpio_init(&led, GPIO_MODE_OUTPUT, GPIO_PULL_NONE) != DRV_OK) return -1;
    if (gpio_init(&button, GPIO_MODE_INPUT, GPIO_PULL_UP) != DRV_OK) return -1;

    for (;;) {
        if (gpio_read(&button, &pressed) != DRV_OK) return -1;
        // Active-low assumption: invert if your hardware is active-high.
        if (gpio_write(&led, !pressed) != DRV_OK) return -1;
    }
}
