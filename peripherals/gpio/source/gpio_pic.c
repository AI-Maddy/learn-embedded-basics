/*
 * gpio_pic.c
 * PIC16F877A GPIO Example Source File
 *
 * Demonstrates basic configuration and usage of GPIO pins.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <xc.h>

/**
 * @brief Initialize RD0 as output, RD1 as input with pull-up.
 */
void gpio_init(void) {
    TRISD &= ~(1 << 0); // RD0 output
    TRISD |= (1 << 1);  // RD1 input
    OPTION_REGbits.nRBPU = 0; // Enable PORTB pull-ups (if using PORTB)
}

/**
 * @brief Set RD0 high.
 */
void gpio_set_led(void) {
    LATD |= (1 << 0);
}

/**
 * @brief Clear RD0 (set low).
 */
void gpio_clear_led(void) {
    LATD &= ~(1 << 0);
}

/**
 * @brief Read RD1 input.
 * @return 1 if high, 0 if low
 */
uint8_t gpio_read_button(void) {
    return (PORTD & (1 << 1)) ? 1 : 0;
}
