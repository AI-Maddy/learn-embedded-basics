#ifndef ADC_H
#define ADC_H

#include <stdbool.h>
#include <stdint.h>
#include "../common/drv_status.h"

typedef enum {
    ADC_SAMPLE_SHORT = 0,
    ADC_SAMPLE_MEDIUM,
    ADC_SAMPLE_LONG
} adc_sample_time_t;

typedef struct {
    uint8_t resolution_bits;
    bool right_aligned;
} adc_config_t;

drv_status_t adc_driver_init(void);
drv_status_t adc_init(const adc_config_t *cfg);
drv_status_t adc_config_channel(uint8_t channel, adc_sample_time_t sample_time);
drv_status_t adc_start_conversion(uint8_t channel);
bool adc_is_conversion_done(void);
drv_status_t adc_read_raw(uint16_t *out_raw);
drv_status_t adc_read_mv(uint16_t vref_mv, uint16_t *out_mv);

#endif
