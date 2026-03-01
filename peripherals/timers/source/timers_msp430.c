/*
 * timers_msp430.c
 * MSP430 Timers Example Source File
 *
 * Demonstrates basic configuration and usage of Timer_A.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <msp430.h>

/**
 * @brief Initialize Timer_A for 1ms interrupt.
 */
void timer_a_init(void) {
    TA0CCR0 = 999; // 1ms at 1MHz
    TA0CTL = TASSEL_2 | MC_1 | TACLR; // SMCLK, up mode
    TA0CCTL0 = CCIE; // Enable interrupt
}

/**
 * @brief Timer_A Interrupt Service Routine
 */
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A_ISR(void) {
    // Handle 1ms event
}
