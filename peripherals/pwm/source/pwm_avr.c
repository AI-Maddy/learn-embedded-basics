/*
 * pwm_avr.c
 * AVR ATmega328P PWM Example Source File
 *
 * Demonstrates basic PWM initialization and duty cycle update.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <avr/io.h>

/**
 * @brief Initialize Timer0 for Fast PWM on OC0A (PB3).
 */
void pwm_init(void) {
    DDRB |= (1 << PB3); // OC0A as output
    TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // Fast PWM, non-inverting
    TCCR0B = (1 << CS01); // Prescaler 8
    OCR0A = 0; // Initial duty cycle 0%
}

/**
 * @brief Set PWM duty cycle (0-255).
 * @param value Duty cycle value
 */
void pwm_set_duty(uint8_t value) {
    OCR0A = value;
}
