/*
 * msp430_adc.c
 *
 * MSP430 ADC10/ADC12 Example Source File
 *
 * Demonstrates basic configuration and usage of the 10/12-bit SAR ADC.
 *
 * Features:
 *  - Single conversion
 *  - Sequence-of-channels mode
 *  - Interrupt-driven conversion
 *
 * Author: Your Name
 * Date: 2026-02-27
 */

#include <msp430.h>
#include <stdint.h>

/**
 * @brief Initialize the ADC10 for single channel, Vcc reference.
 */
void adc10_init(void) {
    ADC10CTL1 = INCH_0; // Input channel A0
    ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON; // Vcc/Vss, 64x sample, ADC on
}

/**
 * @brief Start a single ADC10 conversion.
 */
void adc10_start_conversion(void) {
    ADC10CTL0 |= ENC | ADC10SC; // Enable and start conversion
}

/**
 * @brief Read the result of the last ADC10 conversion (blocking).
 * @return 10-bit ADC result
 */
uint16_t adc10_read(void) {
    while (ADC10CTL1 & ADC10BUSY); // Wait for conversion
    return ADC10MEM;
}

/**
 * @brief Example: Read ADC value from channel 0.
 */
void example_adc10_read(void) {
    adc10_start_conversion();
    uint16_t value = adc10_read();
    // Use 'value' as needed
}

/**
 * @brief Enable ADC10 interrupt.
 */
void adc10_enable_interrupt(void) {
    ADC10CTL0 |= ADC10IE; // Enable ADC10 interrupt
    __bis_SR_register(GIE); // Enable global interrupts
}

/**
 * @brief ADC10 Interrupt Service Routine
 */
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
    uint16_t value = ADC10MEM;
    // Handle ADC value in interrupt
}
