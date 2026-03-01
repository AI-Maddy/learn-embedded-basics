/*
 * timers_avr.c
 * AVR ATmega328P Timers Example Source File
 *
 * Demonstrates basic configuration and usage of 8/16-bit timers.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <avr/io.h>
#include <avr/interrupt.h>

/**
 * @brief Initialize Timer0 in CTC mode for 1ms interrupt.
 */
void timer0_init(void) {
    TCCR0A = (1 << WGM01); // CTC mode
    TCCR0B = (1 << CS01) | (1 << CS00); // Prescaler 64
    OCR0A = 249; // 1ms at 16MHz/64
    TIMSK0 = (1 << OCIE0A); // Enable compare interrupt
}

/**
 * @brief Timer0 Compare Match Interrupt Service Routine
 */
ISR(TIMER0_COMPA_vect) {
    // Handle 1ms event
}
