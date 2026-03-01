#ifndef RADIO_H
#define RADIO_H

#include <stddef.h>
#include <stdint.h>
#include "../common/drv_status.h"

typedef struct {
    uint8_t channel;
    int8_t tx_power_dbm;
    uint32_t bitrate;
} radio_config_t;

drv_status_t radio_driver_init(void);
drv_status_t radio_init(const radio_config_t *cfg);
drv_status_t radio_set_channel(uint8_t channel);
drv_status_t radio_set_tx_power(int8_t dbm);
drv_status_t radio_tx(const uint8_t *payload, size_t len);
drv_status_t radio_rx_start(void);
drv_status_t radio_rx_read(uint8_t *buf, size_t *len);

#endif
