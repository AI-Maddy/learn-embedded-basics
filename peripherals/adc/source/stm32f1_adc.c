/*
 * stm32f1_adc.c
 *
 * STM32F1 ADC Example Source File
 *
 * Demonstrates basic configuration and usage of the 12-bit SAR ADC.
 *
 * Features:
 *  - Single conversion
 *  - Scan mode
 *  - DMA support
 *
 * Author: Your Name
 * Date: 2026-02-27
 */

#include "stm32f10x.h"
#include <stdint.h>

/**
 * @brief Initialize the ADC1 for single channel, scan mode disabled.
 */
void adc1_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; // Enable ADC1 clock
    GPIOA->CRL &= ~(0xF << (0 * 4)); // Set PA0 as analog input
    ADC1->SQR1 = 0; // 1 conversion
    ADC1->SMPR2 |= ADC_SMPR2_SMP0; // Sample time for channel 0
    ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC
    // Calibration
    ADC1->CR2 |= ADC_CR2_CAL;
    while (ADC1->CR2 & ADC_CR2_CAL);
}

/**
 * @brief Start a single ADC conversion on channel 0.
 */
void adc1_start_conversion(void) {
    ADC1->SQR3 = 0; // Channel 0
    ADC1->CR2 |= ADC_CR2_ADON; // Start conversion
}

/**
 * @brief Read the result of the last ADC conversion (blocking).
 * @return 12-bit ADC result
 */
uint16_t adc1_read(void) {
    while (!(ADC1->SR & ADC_SR_EOC)); // Wait for conversion
    return ADC1->DR;
}

/**
 * @brief Example: Read ADC value from channel 0.
 */
void example_adc1_read(void) {
    adc1_start_conversion();
    uint16_t value = adc1_read();
    // Use 'value' as needed
}

/**
 * @brief Enable ADC1 end-of-conversion interrupt.
 */
void adc1_enable_interrupt(void) {
    ADC1->CR1 |= ADC_CR1_EOCIE;
    NVIC_EnableIRQ(ADC1_2_IRQn);
}

/**
 * @brief ADC1 Interrupt Service Routine
 */
void ADC1_2_IRQHandler(void) {
    if (ADC1->SR & ADC_SR_EOC) {
        uint16_t value = ADC1->DR;
        // Handle ADC value in interrupt
        ADC1->SR &= ~ADC_SR_EOC;
    }
}
