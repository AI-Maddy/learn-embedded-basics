#include "pwm.h"

int main(void) {
    // Configure according to timer clock and channel availability on target MCU.
    pwm_config_t cfg = {
        .base_frequency_hz = 1000,
        .channels = 2
    };

    if (pwm_driver_init() != DRV_OK) return -1;
    if (pwm_init(&cfg) != DRV_OK) return -1;
    if (pwm_set_frequency(2000) != DRV_OK) return -1;
    if (pwm_set_duty(0, 50.0f) != DRV_OK) return -1;
    if (pwm_start(0) != DRV_OK) return -1;

    for (;;) {
        // Extend with duty sweep or closed-loop update logic.
    }
}
