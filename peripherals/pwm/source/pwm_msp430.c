/*
 * pwm_msp430.c
 * MSP430G2553 PWM Example Source File
 *
 * Demonstrates basic PWM initialization and duty cycle update.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <msp430.h>

/**
 * @brief Initialize Timer_A for PWM output on P1.2 (TA0.1).
 */
void pwm_init(void) {
    P1DIR |= BIT2;
    P1SEL |= BIT2;
    TA0CCR0 = 255; // Period
    TA0CCTL1 = OUTMOD_7; // Reset/set
    TA0CCR1 = 0; // Initial duty cycle
    TA0CTL = TASSEL_2 + MC_1; // SMCLK, up mode
}

/**
 * @brief Set PWM duty cycle (0-255).
 * @param value Duty cycle value
 */
void pwm_set_duty(unsigned char value) {
    TA0CCR1 = value;
}
