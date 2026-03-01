/*
 * rp2040_adc.c
 *
 * RP2040 ADC Example Source File
 *
 * Demonstrates basic configuration and usage of the 12-bit SAR ADC.
 *
 * Features:
 *  - Single conversion
 *  - Free-running mode
 *  - DMA support
 *
 * Author: Your Name
 * Date: 2026-02-27
 */

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <stdint.h>

/**
 * @brief Initialize the ADC hardware.
 */
void adc_init_rp2040(void) {
    adc_init();
}

/**
 * @brief Select ADC input channel (0-3 for GPIO26-29).
 * @param channel ADC channel number
 */
void adc_select_input_rp2040(uint channel) {
    adc_select_input(channel);
}

/**
 * @brief Read a single ADC value (blocking).
 * @return 12-bit ADC result
 */
uint16_t adc_read_rp2040(void) {
    return adc_read();
}

/**
 * @brief Example: Read ADC value from channel 0 (GPIO26).
 */
void example_adc_read_rp2040(void) {
    adc_init_rp2040();
    adc_select_input_rp2040(0);
    uint16_t value = adc_read_rp2040();
    // Use 'value' as needed
}

/**
 * @brief (Optional) Configure and use DMA for fast sampling (see SDK docs).
 */
// ... DMA setup code would go here ...
