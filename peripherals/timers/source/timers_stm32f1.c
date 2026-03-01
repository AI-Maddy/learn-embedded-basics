/*
 * timers_stm32f1.c
 * STM32F1 Timers Example Source File
 *
 * Demonstrates basic configuration and usage of 16-bit timers.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include "stm32f10x.h"

/**
 * @brief Initialize TIM2 for 1ms interrupt.
 */
void tim2_init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    TIM2->PSC = 15999; // Prescaler (16MHz/16000 = 1kHz)
    TIM2->ARR = 0x01; // Auto-reload for 1ms
    TIM2->DIER |= TIM_DIER_UIE; // Update interrupt enable
    TIM2->CR1 |= TIM_CR1_CEN; // Enable timer
    NVIC_EnableIRQ(TIM2_IRQn);
}

/**
 * @brief TIM2 Interrupt Handler
 */
void TIM2_IRQHandler(void) {
    if (TIM2->SR & TIM_SR_UIF) {
        TIM2->SR &= ~TIM_SR_UIF;
        // Handle 1ms event
    }
}
