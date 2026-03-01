#include <stdint.h>
#include "adc.h"

int main(void) {
    // Adjust resolution and alignment to match your MCU ADC capabilities.
    adc_config_t cfg = {
        .resolution_bits = 12,
        .right_aligned = true
    };

    uint16_t raw = 0;
    uint16_t mv = 0;

    if (adc_driver_init() != DRV_OK) return -1;
    if (adc_init(&cfg) != DRV_OK) return -1;
    if (adc_config_channel(0, ADC_SAMPLE_MEDIUM) != DRV_OK) return -1;
    if (adc_start_conversion(0) != DRV_OK) return -1;

    while (!adc_is_conversion_done()) {
        // Polling path; use ISR/DMA path for higher throughput systems.
    }

    if (adc_read_raw(&raw) != DRV_OK) return -1;
    if (adc_read_mv(3300, &mv) != DRV_OK) return -1;

    // In real projects, log/stream these values or feed control logic.
    (void)raw;
    (void)mv;
    return 0;
}
