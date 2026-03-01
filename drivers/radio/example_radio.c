#include <stdint.h>
#include "radio.h"

int main(void) {
    // Tune channel, power, and bitrate to your regional and application constraints.
    radio_config_t cfg = {
        .channel = 10,
        .tx_power_dbm = 0,
        .bitrate = 1000000
    };

    uint8_t payload[] = { 0x4F, 0x4B };

    if (radio_driver_init() != DRV_OK) return -1;
    if (radio_init(&cfg) != DRV_OK) return -1;
    if (radio_set_channel(11) != DRV_OK) return -1;
    if (radio_set_tx_power(4) != DRV_OK) return -1;
    if (radio_tx(payload, sizeof(payload)) != DRV_OK) return -1;

    for (;;) {
        // Add retry/ack/link-quality handling in production firmware.
    }
}
