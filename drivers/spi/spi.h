#ifndef SPI_H
#define SPI_H

#include <stddef.h>
#include <stdint.h>
#include "../common/drv_status.h"

typedef enum {
    SPI_MODE_0 = 0,
    SPI_MODE_1,
    SPI_MODE_2,
    SPI_MODE_3
} spi_mode_t;

typedef struct {
    uint32_t bitrate_hz;
    spi_mode_t mode;
    uint8_t lsb_first;
} spi_config_t;

drv_status_t spi_driver_init(void);
drv_status_t spi_init(const spi_config_t *cfg);
drv_status_t spi_transfer(const uint8_t *tx, uint8_t *rx, size_t len);
drv_status_t spi_write(const uint8_t *tx, size_t len);
drv_status_t spi_read(uint8_t *rx, size_t len);

#endif
