/*
 * i2c_msp430.c
 * MSP430G2553 I2C Example Source File
 *
 * Demonstrates basic I2C master initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <msp430.h>

/**
 * @brief Initialize USCI_B0 as I2C master.
 */
void i2c_init(void) {
    P1SEL |= BIT6 + BIT7; // P1.6=SDA, P1.7=SCL
    P1SEL2 |= BIT6 + BIT7;
    UCB0CTL1 |= UCSWRST;
    UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC; // Master, I2C, sync
    UCB0CTL1 = UCSSEL_2 + UCSWRST; // SMCLK
    UCB0BR0 = 12; // 100kHz
    UCB0BR1 = 0;
    UCB0CTL1 &= ~UCSWRST; // Start USCI
}

/**
 * @brief Send START condition.
 */
void i2c_start(void) {
    UCB0CTL1 |= UCTXSTT;
    while (UCB0CTL1 & UCTXSTT);
}

/**
 * @brief Send STOP condition.
 */
void i2c_stop(void) {
    UCB0CTL1 |= UCTXSTP;
    while (UCB0CTL1 & UCTXSTP);
}

/**
 * @brief Write a byte to I2C bus.
 * @param data Byte to write
 */
void i2c_write(unsigned char data) {
    while (!(IFG2 & UCB0TXIFG));
    UCB0TXBUF = data;
}

/**
 * @brief Read a byte from I2C bus.
 * @return Received byte
 */
unsigned char i2c_read(void) {
    while (!(IFG2 & UCB0RXIFG));
    return UCB0RXBUF;
}
