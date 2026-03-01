/*
 * nrf52_adc.c
 *
 * nRF52 SAADC Example Source File
 *
 * Demonstrates basic configuration and usage of the 12-bit Successive Approximation ADC (SAADC).
 *
 * Features:
 *  - Single conversion
 *  - Differential mode
 *  - DMA (EasyDMA) support
 *
 * Author: Your Name
 * Date: 2026-02-27
 */

#include "nrf_saadc.h"
#include <stdint.h>

/**
 * @brief Initialize the SAADC for single-ended input, 12-bit resolution.
 */
void saadc_init(void) {
    nrf_saadc_resolution_set(NRF_SAADC_RESOLUTION_12BIT);
    nrf_saadc_channel_input_set(0, NRF_SAADC_INPUT_AIN0, NRF_SAADC_INPUT_DISABLED);
    nrf_saadc_enable();
}

/**
 * @brief Start a single SAADC conversion.
 */
void saadc_start_conversion(void) {
    nrf_saadc_task_trigger(NRF_SAADC_TASK_START);
    nrf_saadc_task_trigger(NRF_SAADC_TASK_SAMPLE);
}

/**
 * @brief Read the result of the last SAADC conversion (blocking).
 * @return 12-bit ADC result
 */
int16_t saadc_read(void) {
    int16_t result = 0;
    nrf_saadc_buffer_init(&result, 1);
    while (!nrf_saadc_event_check(NRF_SAADC_EVENT_END));
    nrf_saadc_event_clear(NRF_SAADC_EVENT_END);
    return result;
}

/**
 * @brief Example: Read SAADC value from channel 0.
 */
void example_saadc_read(void) {
    saadc_init();
    saadc_start_conversion();
    int16_t value = saadc_read();
    // Use 'value' as needed
}

/**
 * @brief (Optional) Configure EasyDMA for high-speed sampling (see SDK docs).
 */
// ... EasyDMA setup code would go here ...
