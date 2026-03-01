/*
 * interrupts_stm32f1.c
 * STM32F1 Interrupts Example Source File
 *
 * Demonstrates basic configuration and usage of EXTI and NVIC interrupts.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include "stm32f10x.h"

/**
 * @brief Initialize EXTI0 interrupt on PA0.
 */
void exti0_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
    GPIOA->CRL &= ~(0xF << (0 * 4));
    GPIOA->CRL |= (0x4 << (0 * 4)); // Input floating
    AFIO->EXTICR[0] = 0x0; // EXTI0 on PA0
    EXTI->IMR |= EXTI_IMR_MR0;
    EXTI->FTSR |= EXTI_FTSR_TR0; // Falling edge
    NVIC_EnableIRQ(EXTI0_IRQn);
}

/**
 * @brief EXTI0 Interrupt Handler
 */
void EXTI0_IRQHandler(void) {
    if (EXTI->PR & EXTI_PR_PR0) {
        EXTI->PR = EXTI_PR_PR0;
        // Handle external interrupt
    }
}
