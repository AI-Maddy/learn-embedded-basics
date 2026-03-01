#include "radio.h"

static radio_config_t radio_cfg;
static int radio_ready;

drv_status_t radio_driver_init(void) {
    radio_cfg.channel = 0;
    radio_cfg.tx_power_dbm = 0;
    radio_cfg.bitrate = 0;
    radio_ready = 1;
    return DRV_OK;
}

drv_status_t radio_init(const radio_config_t *cfg) {
    if (cfg == 0) {
        return DRV_ERR_ARG;
    }
    if (radio_driver_init() != DRV_OK) {
        return DRV_ERR_HW;
    }
    radio_cfg = *cfg;
    return DRV_OK;
}

drv_status_t radio_set_channel(uint8_t channel) {
    if (!radio_ready) {
        return DRV_ERR_ARG;
    }
    radio_cfg.channel = channel;
    return DRV_OK;
}

drv_status_t radio_set_tx_power(int8_t dbm) {
    if (!radio_ready) {
        return DRV_ERR_ARG;
    }
    radio_cfg.tx_power_dbm = dbm;
    return DRV_OK;
}

drv_status_t radio_tx(const uint8_t *payload, size_t len) {
    if (!radio_ready || (len > 0u && payload == 0)) {
        return DRV_ERR_ARG;
    }
    return DRV_OK;
}

drv_status_t radio_rx_start(void) {
    if (!radio_ready) {
        return DRV_ERR_ARG;
    }
    return DRV_OK;
}

drv_status_t radio_rx_read(uint8_t *buf, size_t *len) {
    if (!radio_ready || buf == 0 || len == 0) {
        return DRV_ERR_ARG;
    }
    *len = 0;
    return DRV_OK;
}
