/*
 * cc26xx_adc.c
 *
 * TI CC26xx ADC Example Source File
 *
 * Demonstrates basic configuration and usage of the 12-bit SAR ADC.
 *
 * Features:
 *  - Single conversion
 *  - Low-power sampling
 *  - Interrupt-driven conversion
 *
 * Author: Your Name
 * Date: 2026-02-27
 */

#include <ti/devices/cc26x0/driverlib/aux_adc.h>
#include <stdint.h>

/**
 * @brief Initialize the ADC for single-ended input, 12-bit resolution.
 */
void adc_init_cc26xx(void) {
    AUXADCEnable();
    AUXADCSelectInput(ADC_COMPB_IN_AUXIO0);
}

/**
 * @brief Start a single ADC conversion.
 */
void adc_start_conversion_cc26xx(void) {
    AUXADCGenManualTrigger();
}

/**
 * @brief Read the result of the last ADC conversion (blocking).
 * @return 12-bit ADC result
 */
uint32_t adc_read_cc26xx(void) {
    while (!AUXADCGetFIFOLvl());
    return AUXADCReadFifo();
}

/**
 * @brief Example: Read ADC value from AUXIO0.
 */
void example_adc_read_cc26xx(void) {
    adc_init_cc26xx();
    adc_start_conversion_cc26xx();
    uint32_t value = adc_read_cc26xx();
    // Use 'value' as needed
}

/**
 * @brief (Optional) Enable interrupt-driven conversion (see TI driverlib docs).
 */
// ... Interrupt setup code would go here ...
