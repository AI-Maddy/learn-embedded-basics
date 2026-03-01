/*
 * gpio_stm32f1.c
 * STM32F1 GPIO Example Source File
 *
 * Demonstrates basic configuration and usage of GPIO pins.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include "stm32f10x.h"

/**
 * @brief Initialize PA0 as output, PA1 as input with pull-up.
 */
void gpio_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    GPIOA->CRL &= ~((0xF << (0 * 4)) | (0xF << (1 * 4)));
    GPIOA->CRL |= (0x1 << (0 * 4)); // PA0 output push-pull
    GPIOA->CRL |= (0x8 << (1 * 4)); // PA1 input with pull-up
    GPIOA->ODR |= (1 << 1); // Enable pull-up on PA1
}

/**
 * @brief Set PA0 high.
 */
void gpio_set_led(void) {
    GPIOA->BSRR = (1 << 0);
}

/**
 * @brief Clear PA0 (set low).
 */
void gpio_clear_led(void) {
    GPIOA->BRR = (1 << 0);
}

/**
 * @brief Read PA1 input.
 * @return 1 if high, 0 if low
 */
uint8_t gpio_read_button(void) {
    return (GPIOA->IDR & (1 << 1)) ? 1 : 0;
}
