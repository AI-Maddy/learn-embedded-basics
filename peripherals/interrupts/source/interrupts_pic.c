/*
 * interrupts_pic.c
 * PIC16F877A Interrupts Example Source File
 *
 * Demonstrates basic configuration and usage of external and timer interrupts.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <xc.h>

/**
 * @brief Initialize INT0 external interrupt on falling edge.
 */
void int0_init(void) {
    OPTION_REGbits.INTEDG = 0; // Falling edge
    INTCONbits.INT0IE = 1; // Enable INT0
    INTCONbits.GIE = 1; // Enable global interrupts
}

/**
 * @brief INT0 Interrupt Service Routine
 */
void __interrupt() int0_isr(void) {
    if (INTCONbits.INT0IF) {
        INTCONbits.INT0IF = 0;
        // Handle external interrupt
    }
}
