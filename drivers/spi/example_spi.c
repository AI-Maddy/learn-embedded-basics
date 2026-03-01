#include <stdint.h>
#include "spi.h"

int main(void) {
    // Adjust mode/bitrate according to the connected SPI peripheral datasheet.
    spi_config_t cfg = {
        .bitrate_hz = 1000000,
        .mode = SPI_MODE_0,
        .lsb_first = 0
    };

    uint8_t tx[2] = { 0x9F, 0x00 };
    uint8_t rx[2] = { 0 };

    if (spi_driver_init() != DRV_OK) return -1;
    if (spi_init(&cfg) != DRV_OK) return -1;
    if (spi_transfer(tx, rx, 2) != DRV_OK) return -1;

    // Validate received bytes against expected device response.
    (void)rx;
    return 0;
}
