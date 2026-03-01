/*
 * radio_stm32f1.c
 * STM32F1 Radio (nRF24L01) Example Source File
 *
 * Demonstrates basic SPI-based radio module initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include "stm32f10x.h"

/**
 * @brief Initialize SPI1 for nRF24L01 radio module.
 */
void radio_spi_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN;
    GPIOA->CRL &= ~((0xF << 20) | (0xF << 16) | (0xF << 12));
    GPIOA->CRL |= (0xB << 20) | (0xB << 16) | (0x4 << 12); // SCK, MOSI: AF output, MISO: input
    SPI1->CR1 = SPI_CR1_MSTR | SPI_CR1_SSM | SPI_CR1_SSI | SPI_CR1_SPE | (0x1 << 3); // Master, software NSS, f/16
}

/**
 * @brief Transmit and receive a byte over SPI1 (to radio).
 * @param data Byte to transmit
 * @return Received byte
 */
uint8_t radio_spi_transfer(uint8_t data) {
    SPI1->DR = data;
    while (!(SPI1->SR & SPI_SR_RXNE));
    return SPI1->DR;
}
