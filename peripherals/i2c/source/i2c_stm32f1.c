/*
 * i2c_stm32f1.c
 * STM32F1 I2C Example Source File
 *
 * Demonstrates basic I2C master initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include "stm32f10x.h"

/**
 * @brief Initialize I2C1 as master.
 */
void i2c_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
    GPIOB->CRL |= (0xF << 8) | (0xF << 12); // PB6, PB7: open-drain
    I2C1->CR2 = 36; // APB1 freq in MHz
    I2C1->CCR = 180; // 100kHz
    I2C1->TRISE = 37;
    I2C1->CR1 = I2C_CR1_PE;
}

/**
 * @brief Send START condition.
 */
void i2c_start(void) {
    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB));
}

/**
 * @brief Send STOP condition.
 */
void i2c_stop(void) {
    I2C1->CR1 |= I2C_CR1_STOP;
}

/**
 * @brief Write a byte to I2C bus.
 * @param data Byte to write
 */
void i2c_write(uint8_t data) {
    while (!(I2C1->SR1 & I2C_SR1_TXE));
    I2C1->DR = data;
}

/**
 * @brief Read a byte from I2C bus.
 * @return Received byte
 */
uint8_t i2c_read(void) {
    while (!(I2C1->SR1 & I2C_SR1_RXNE));
    return I2C1->DR;
}
