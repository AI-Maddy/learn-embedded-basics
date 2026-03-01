/*
 * pic_adc.c
 *
 * PIC16F877A ADC Example Source File
 *
 * Demonstrates basic configuration and usage of the 10-bit SAR ADC.
 *
 * Features:
 *  - Single conversion
 *  - Acquisition time configuration
 *  - Interrupt-driven conversion
 *
 * Author: Your Name
 * Date: 2026-02-27
 */

#include <xc.h>
#include <stdint.h>

/**
 * @brief Initialize the ADC with Vref+, channel 0, and Fosc/32 clock.
 */
void adc_init(void) {
    ADCON0 = 0x01; // Select channel 0, turn on ADC
    ADCON1 = 0x80; // Vref+ = VDD, Vref- = VSS, right justify
    // Set acquisition time if needed (see datasheet)
}

/**
 * @brief Start a single ADC conversion on the selected channel.
 * @param channel ADC channel (0-7)
 */
void adc_start_conversion(uint8_t channel) {
    ADCON0 = (ADCON0 & 0xC5) | ((channel << 3) & 0x38); // Select channel
    __delay_us(5); // Acquisition time (adjust as needed)
    GO_nDONE = 1; // Start conversion
}

/**
 * @brief Read the result of the last ADC conversion (blocking).
 * @return 10-bit ADC result
 */
uint16_t adc_read(void) {
    while (GO_nDONE); // Wait for conversion to finish
    return ((ADRESH << 8) | ADRESL);
}

/**
 * @brief Example: Read ADC value from channel 0.
 */
void example_adc_read(void) {
    adc_start_conversion(0);
    uint16_t value = adc_read();
    // Use 'value' as needed
}

/**
 * @brief Enable ADC interrupt.
 */
void adc_enable_interrupt(void) {
    PIE1bits.ADIE = 1; // Enable ADC interrupt
    INTCONbits.PEIE = 1; // Enable peripheral interrupts
    INTCONbits.GIE = 1; // Enable global interrupts
}

/**
 * @brief ADC Interrupt Service Routine
 */
void __interrupt() adc_isr(void) {
    if (PIR1bits.ADIF) {
        uint16_t value = ((ADRESH << 8) | ADRESL);
        // Handle ADC value in interrupt
        PIR1bits.ADIF = 0; // Clear interrupt flag
    }
}
