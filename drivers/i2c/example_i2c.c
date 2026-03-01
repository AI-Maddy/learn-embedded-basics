#include <stdint.h>
#include "i2c.h"

int main(void) {
    // Replace with your target bus speed and own-address requirements.
    i2c_config_t cfg = {
        .bitrate_hz = 100000,
        .address_7bit = 0x00
    };

    uint8_t who_am_i = 0;

    if (i2c_driver_init() != DRV_OK) return -1;
    if (i2c_init(&cfg) != DRV_OK) return -1;
    // Example: read a known identity register from a typical sensor.
    if (i2c_mem_read(0x68, 0x75, &who_am_i, 1) != DRV_OK) return -1;

    // Verify expected device ID value in target-specific integration tests.
    (void)who_am_i;
    return 0;
}
