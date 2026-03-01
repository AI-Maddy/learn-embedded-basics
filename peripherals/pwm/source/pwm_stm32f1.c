/*
 * pwm_stm32f1.c
 * STM32F1 PWM Example Source File
 *
 * Demonstrates basic PWM initialization and duty cycle update.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include "stm32f10x.h"

/**
 * @brief Initialize TIM2 Channel 1 for PWM output.
 */
void pwm_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    GPIOA->CRL &= ~(0xF << 0);
    GPIOA->CRL |= (0xB << 0); // PA0: AF output
    TIM2->PSC = 71; // Prescaler
    TIM2->ARR = 255; // Period
    TIM2->CCR1 = 0; // Initial duty cycle
    TIM2->CCMR1 = (6 << 4); // PWM mode 1
    TIM2->CCER = 1; // Enable output
    TIM2->CR1 = 1; // Enable timer
}

/**
 * @brief Set PWM duty cycle (0-255).
 * @param value Duty cycle value
 */
void pwm_set_duty(uint16_t value) {
    TIM2->CCR1 = value;
}
