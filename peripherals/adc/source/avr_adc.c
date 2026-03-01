/*
 * avr_adc.c
 *
 * AVR ATmega328P ADC Example Source File
 *
 * Demonstrates basic configuration and usage of the 10-bit SAR ADC.
 *
 * Features:
 *  - Single conversion
 *  - Free-running mode
 *  - Interrupt-driven conversion
 *
 * Author: Your Name
 * Date: 2026-02-27
 */

#include <avr/io.h>
#include <avr/interrupt.h>

/**
 * @brief Initialize the ADC with AVcc as reference, prescaler 128, and channel 0.
 */
void adc_init(void) {
    // Select Vref=AVcc, input channel ADC0
    ADMUX = (1 << REFS0);
    // Enable ADC, set prescaler to 128 (16MHz/128 = 125kHz)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

/**
 * @brief Start a single ADC conversion on the selected channel.
 * @param channel ADC channel (0-7)
 */
void adc_start_conversion(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // Select channel
    ADCSRA |= (1 << ADSC); // Start conversion
}

/**
 * @brief Read the result of the last ADC conversion (blocking).
 * @return 10-bit ADC result
 */
uint16_t adc_read(void) {
    while (ADCSRA & (1 << ADSC)); // Wait for conversion to finish
    return ADC;
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
 * @brief Enable free-running mode and interrupt-driven conversion.
 */
void adc_enable_freerun_interrupt(void) {
    ADCSRA |= (1 << ADATE) | (1 << ADIE); // Auto trigger, interrupt enable
    sei(); // Enable global interrupts
    ADCSRA |= (1 << ADSC); // Start first conversion
}

/**
 * @brief ADC Conversion Complete Interrupt Service Routine
 */
ISR(ADC_vect) {
    uint16_t value = ADC;
    // Handle ADC value in interrupt
}
