/*
 * radio_msp430.c
 * MSP430G2553 Radio (nRF24L01) Example Source File
 *
 * Demonstrates basic SPI-based radio module initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <msp430.h>

/**
 * @brief Initialize SPI for nRF24L01 radio module.
 */
void radio_spi_init(void) {
    P1SEL |= BIT5 + BIT6 + BIT7; // P1.5=CLK, P1.6=MISO, P1.7=MOSI
    P1SEL2 |= BIT5 + BIT6 + BIT7;
    UCB0CTL1 |= UCSWRST;
    UCB0CTL0 = UCCKPH + UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit, master
    UCB0CTL1 = UCSSEL_2 + UCSWRST; // SMCLK
    UCB0BR0 = 0x02; // f/2
    UCB0BR1 = 0;
    UCB0CTL1 &= ~UCSWRST; // Start USCI
}

/**
 * @brief Transmit and receive a byte over SPI (to radio).
 * @param data Byte to transmit
 * @return Received byte
 */
unsigned char radio_spi_transfer(unsigned char data) {
    while (!(IFG2 & UCB0TXIFG));
    UCB0TXBUF = data;
    while (!(IFG2 & UCB0RXIFG));
    return UCB0RXBUF;
}
