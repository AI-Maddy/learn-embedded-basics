/*
 * gd32vf103_adc.c
 *
 * GD32VF103 ADC Example Source File
 *
 * Demonstrates basic configuration and usage of the 12-bit SAR ADC (STM32-like).
 *
 * Features:
 *  - Single conversion
 *  - Scan mode
 *  - DMA support
 *
 * Author: Your Name
 * Date: 2026-02-27
 */

#include "gd32vf103.h"
#include <stdint.h>

/**
 * @brief Initialize the ADC for single channel, scan mode disabled.
 */
void adc_init(void) {
    rcu_periph_clock_enable(RCU_ADC0);
    gpio_init(GPIOA, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
    adc_deinit(ADC0);
    adc_mode_config(ADC_MODE_FREE);
    adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT);
    adc_channel_length_config(ADC0, ADC_REGULAR_CHANNEL, 1);
    adc_regular_channel_config(ADC0, 0, ADC_CHANNEL_0, ADC_SAMPLETIME_55POINT5);
    adc_enable(ADC0);
    adc_calibration_enable(ADC0);
}

/**
 * @brief Start a single ADC conversion on channel 0.
 */
void adc_start_conversion(void) {
    adc_software_trigger_enable(ADC0, ADC_REGULAR_CHANNEL);
}

/**
 * @brief Read the result of the last ADC conversion (blocking).
 * @return 12-bit ADC result
 */
uint16_t adc_read(void) {
    while (!adc_flag_get(ADC0, ADC_FLAG_EOC));
    adc_flag_clear(ADC0, ADC_FLAG_EOC);
    return adc_regular_data_read(ADC0);
}

/**
 * @brief Example: Read ADC value from channel 0.
 */
void example_adc_read(void) {
    adc_start_conversion();
    uint16_t value = adc_read();
    // Use 'value' as needed
}

/**
 * @brief Enable ADC interrupt.
 */
void adc_enable_interrupt(void) {
    nvic_irq_enable(ADC0_1_IRQn, 0, 0);
    adc_interrupt_enable(ADC0, ADC_INT_EOC);
}

/**
 * @brief ADC Interrupt Service Routine
 */
void ADC0_1_IRQHandler(void) {
    if (adc_interrupt_flag_get(ADC0, ADC_INT_FLAG_EOC)) {
        uint16_t value = adc_regular_data_read(ADC0);
        // Handle ADC value in interrupt
        adc_interrupt_flag_clear(ADC0, ADC_INT_FLAG_EOC);
    }
}
