/*
 * interrupts_msp430.c
 * MSP430 Interrupts Example Source File
 *
 * Demonstrates basic configuration and usage of port and timer interrupts.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <msp430.h>

/**
 * @brief Initialize P1.1 interrupt on falling edge.
 */
void port1_int_init(void) {
    P1DIR &= ~BIT1; // Input
    P1IE |= BIT1; // Enable interrupt
    P1IES |= BIT1; // Falling edge
    P1IFG &= ~BIT1; // Clear flag
    __bis_SR_register(GIE); // Enable global interrupts
}

/**
 * @brief Port 1 Interrupt Service Routine
 */
#pragma vector=PORT1_VECTOR
__interrupt void Port_1_ISR(void) {
    if (P1IFG & BIT1) {
        P1IFG &= ~BIT1;
        // Handle external interrupt
    }
}
