/*
 * uart_stm32f1.c
 * STM32F1 UART Example Source File
 *
 * Demonstrates basic UART initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include "stm32f10x.h"

/**
 * @brief Initialize USART1 with given baud rate.
 * @param baud Baud rate value
 */
void uart_init(uint32_t baud) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_USART1EN;
    GPIOA->CRH &= ~((0xF << 4) | (0xF << 8));
    GPIOA->CRH |= (0xB << 4) | (0x4 << 8); // PA9: AF output, PA10: input
    USART1->BRR = SystemCoreClock / baud;
    USART1->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

/**
 * @brief Transmit a byte over USART1.
 * @param data Byte to transmit
 */
void uart_transmit(uint8_t data) {
    while (!(USART1->SR & USART_SR_TXE));
    USART1->DR = data;
}

/**
 * @brief Receive a byte from USART1.
 * @return Received byte
 */
uint8_t uart_receive(void) {
    while (!(USART1->SR & USART_SR_RXNE));
    return USART1->DR;
}
