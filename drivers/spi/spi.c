#include "spi.h"

static spi_config_t spi_cfg;
static int spi_ready;

drv_status_t spi_driver_init(void) {
    spi_cfg.bitrate_hz = 0;
    spi_cfg.mode = SPI_MODE_0;
    spi_cfg.lsb_first = 0;
    spi_ready = 1;
    return DRV_OK;
}

drv_status_t spi_init(const spi_config_t *cfg) {
    if (cfg == 0 || cfg->bitrate_hz == 0) {
        return DRV_ERR_ARG;
    }
    if (spi_driver_init() != DRV_OK) {
        return DRV_ERR_HW;
    }
    spi_cfg = *cfg;
    return DRV_OK;
}

drv_status_t spi_transfer(const uint8_t *tx, uint8_t *rx, size_t len) {
    if (!spi_ready || len == 0) {
        return DRV_ERR_ARG;
    }
    for (size_t i = 0; i < len; ++i) {
        uint8_t v = tx ? tx[i] : 0xFFu;
        if (rx) {
            rx[i] = v;
        }
    }
    return DRV_OK;
}

drv_status_t spi_write(const uint8_t *tx, size_t len) {
    return spi_transfer(tx, 0, len);
}

drv_status_t spi_read(uint8_t *rx, size_t len) {
    return spi_transfer(0, rx, len);
}
