/*
 * interrupts_avr.c
 * AVR ATmega328P Interrupts Example Source File
 *
 * Demonstrates basic configuration and usage of external and timer interrupts.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <avr/io.h>
#include <avr/interrupt.h>

/**
 * @brief Initialize INT0 external interrupt on falling edge.
 */
void int0_init(void) {
    EICRA = (1 << ISC01); // Falling edge
    EIMSK = (1 << INT0); // Enable INT0
    sei(); // Enable global interrupts
}

/**
 * @brief INT0 Interrupt Service Routine
 */
ISR(INT0_vect) {
    // Handle external interrupt
}
