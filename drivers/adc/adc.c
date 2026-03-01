#include "adc.h"

static bool adc_ready;
static uint16_t adc_last_raw;

drv_status_t adc_driver_init(void) {
    adc_ready = true;
    adc_last_raw = 0;
    return DRV_OK;
}

drv_status_t adc_init(const adc_config_t *cfg) {
    if (cfg == 0) {
        return DRV_ERR_ARG;
    }
    return adc_driver_init();
}

drv_status_t adc_config_channel(uint8_t channel, adc_sample_time_t sample_time) {
    (void)sample_time;
    if (!adc_ready || channel > 31u) {
        return DRV_ERR_ARG;
    }
    return DRV_OK;
}

drv_status_t adc_start_conversion(uint8_t channel) {
    if (!adc_ready || channel > 31u) {
        return DRV_ERR_ARG;
    }
    adc_last_raw = (uint16_t)(channel * 128u);
    return DRV_OK;
}

bool adc_is_conversion_done(void) {
    return adc_ready;
}

drv_status_t adc_read_raw(uint16_t *out_raw) {
    if (!adc_ready || out_raw == 0) {
        return DRV_ERR_ARG;
    }
    *out_raw = adc_last_raw;
    return DRV_OK;
}

drv_status_t adc_read_mv(uint16_t vref_mv, uint16_t *out_mv) {
    if (!adc_ready || out_mv == 0 || vref_mv == 0) {
        return DRV_ERR_ARG;
    }
    *out_mv = (uint16_t)((uint32_t)adc_last_raw * vref_mv / 4095u);
    return DRV_OK;
}
