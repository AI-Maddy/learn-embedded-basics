/*
 * gpio_msp430.c
 * MSP430 GPIO Example Source File
 *
 * Demonstrates basic configuration and usage of GPIO pins.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <msp430.h>

/**
 * @brief Initialize P1.0 as output, P1.1 as input with pull-up.
 */
void gpio_init(void) {
    P1DIR |= BIT0; // P1.0 output
    P1DIR &= ~BIT1; // P1.1 input
    P1REN |= BIT1; // Enable pull-up/down on P1.1
    P1OUT |= BIT1; // Select pull-up
}

/**
 * @brief Set P1.0 high.
 */
void gpio_set_led(void) {
    P1OUT |= BIT0;
}

/**
 * @brief Clear P1.0 (set low).
 */
void gpio_clear_led(void) {
    P1OUT &= ~BIT0;
}

/**
 * @brief Read P1.1 input.
 * @return 1 if high, 0 if low
 */
uint8_t gpio_read_button(void) {
    return (P1IN & BIT1) ? 1 : 0;
}
