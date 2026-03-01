/*
 * timers_pic.c
 * PIC16F877A Timers Example Source File
 *
 * Demonstrates basic configuration and usage of 8/16-bit timers.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <xc.h>

/**
 * @brief Initialize Timer0 for 1ms interrupt.
 */
void timer0_init(void) {
    OPTION_REG = 0x07; // Prescaler 1:256
    TMR0 = 6; // Preload for 1ms at 4MHz
    INTCONbits.TMR0IE = 1; // Enable Timer0 interrupt
    INTCONbits.GIE = 1; // Enable global interrupts
}

/**
 * @brief Timer0 Interrupt Service Routine
 */
void __interrupt() timer0_isr(void) {
    if (INTCONbits.TMR0IF) {
        TMR0 = 6; // Reload
        INTCONbits.TMR0IF = 0;
        // Handle 1ms event
    }
}
