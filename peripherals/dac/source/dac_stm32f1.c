/*
 * dac_stm32f1.c
 * STM32F1 DAC Example Source File
 *
 * Demonstrates basic usage of built-in DAC (if available).
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include "stm32f10x.h"

void dac_init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_DACEN;
    DAC->CR = DAC_CR_EN1;
}

void dac_write(uint16_t value) {
    DAC->DHR12R1 = value & 0x0FFF;
}
