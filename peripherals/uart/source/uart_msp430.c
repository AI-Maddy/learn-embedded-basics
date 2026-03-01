/*
 * uart_msp430.c
 * MSP430G2553 UART Example Source File
 *
 * Demonstrates basic UART initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <msp430.h>

/**
 * @brief Initialize UART with given baud rate settings.
 */
void uart_init(void) {
    P1SEL |= BIT1 + BIT2; // Set P1.1 = RXD, P1.2=TXD
    P1SEL2 |= BIT1 + BIT2;
    UCA0CTL1 |= UCSSEL_2; // SMCLK
    UCA0BR0 = 104; // 9600 baud for 1MHz
    UCA0BR1 = 0;
    UCA0MCTL = UCBRS0;
    UCA0CTL1 &= ~UCSWRST; // Initialize USCI state machine
    IE2 |= UCA0RXIE; // Enable RX interrupt (optional)
}

/**
 * @brief Transmit a byte over UART.
 * @param data Byte to transmit
 */
void uart_transmit(unsigned char data) {
    while (!(IFG2 & UCA0TXIFG));
    UCA0TXBUF = data;
}

/**
 * @brief Receive a byte from UART.
 * @return Received byte
 */
unsigned char uart_receive(void) {
    while (!(IFG2 & UCA0RXIFG));
    return UCA0RXBUF;
}
