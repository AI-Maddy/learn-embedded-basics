/*
 * gpio_avr.c
 * AVR ATmega328P GPIO Example Source File
 *
 * Demonstrates basic configuration and usage of GPIO pins.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <avr/io.h>

/**
 * @brief Initialize PD2 as output, PD3 as input with pull-up.
 */
void gpio_init(void) {
    DDRD |= (1 << PD2); // PD2 output
    DDRD &= ~(1 << PD3); // PD3 input
    PORTD |= (1 << PD3); // Enable pull-up on PD3
}

/**
 * @brief Set PD2 high.
 */
void gpio_set_led(void) {
    PORTD |= (1 << PD2);
}

/**
 * @brief Clear PD2 (set low).
 */
void gpio_clear_led(void) {
    PORTD &= ~(1 << PD2);
}

/**
 * @brief Read PD3 input.
 * @return 1 if high, 0 if low
 */
uint8_t gpio_read_button(void) {
    return (PIND & (1 << PD3)) ? 1 : 0;
}
