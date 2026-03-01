#include "i2c.h"

static i2c_config_t i2c_cfg;
static int i2c_ready;

drv_status_t i2c_driver_init(void) {
    i2c_cfg.bitrate_hz = 0;
    i2c_cfg.address_7bit = 0;
    i2c_ready = 1;
    return DRV_OK;
}

drv_status_t i2c_init(const i2c_config_t *cfg) {
    if (cfg == 0 || cfg->bitrate_hz == 0) {
        return DRV_ERR_ARG;
    }
    if (i2c_driver_init() != DRV_OK) {
        return DRV_ERR_HW;
    }
    i2c_cfg = *cfg;
    return DRV_OK;
}

drv_status_t i2c_write(uint8_t addr, const uint8_t *data, size_t len) {
    (void)data;
    if (!i2c_ready || addr > 0x7Fu || (len > 0u && data == 0)) {
        return DRV_ERR_ARG;
    }
    return DRV_OK;
}

drv_status_t i2c_read(uint8_t addr, uint8_t *data, size_t len) {
    if (!i2c_ready || addr > 0x7Fu || (len > 0u && data == 0)) {
        return DRV_ERR_ARG;
    }
    for (size_t i = 0; i < len; ++i) {
        data[i] = 0;
    }
    return DRV_OK;
}

drv_status_t i2c_mem_write(uint8_t addr, uint8_t reg, const uint8_t *data, size_t len) {
    (void)reg;
    return i2c_write(addr, data, len);
}

drv_status_t i2c_mem_read(uint8_t addr, uint8_t reg, uint8_t *data, size_t len) {
    (void)reg;
    return i2c_read(addr, data, len);
}
