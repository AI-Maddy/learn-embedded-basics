/*
 * pwm_pic.c
 * PIC16F877A PWM Example Source File
 *
 * Demonstrates basic PWM initialization and duty cycle update.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <xc.h>

/**
 * @brief Initialize CCP1 for PWM output.
 */
void pwm_init(void) {
    TRISC2 = 0; // CCP1 output
    PR2 = 0xFF; // Period
    CCP1CON = 0x0C; // PWM mode
    T2CON = 0x04; // Timer2 on, prescaler 1:1
    CCPR1L = 0; // Initial duty cycle
}

/**
 * @brief Set PWM duty cycle (0-255).
 * @param value Duty cycle value
 */
void pwm_set_duty(unsigned char value) {
    CCPR1L = value;
}
