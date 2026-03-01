#ifndef I2C_H
#define I2C_H

#include <stddef.h>
#include <stdint.h>
#include "../common/drv_status.h"

typedef struct {
    uint32_t bitrate_hz;
    uint8_t address_7bit;
} i2c_config_t;

drv_status_t i2c_driver_init(void);
drv_status_t i2c_init(const i2c_config_t *cfg);
drv_status_t i2c_write(uint8_t addr, const uint8_t *data, size_t len);
drv_status_t i2c_read(uint8_t addr, uint8_t *data, size_t len);
drv_status_t i2c_mem_write(uint8_t addr, uint8_t reg, const uint8_t *data, size_t len);
drv_status_t i2c_mem_read(uint8_t addr, uint8_t reg, uint8_t *data, size_t len);

#endif
