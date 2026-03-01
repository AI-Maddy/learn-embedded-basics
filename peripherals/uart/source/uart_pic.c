/*
 * uart_pic.c
 * PIC16F877A UART Example Source File
 *
 * Demonstrates basic UART initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <xc.h>

/**
 * @brief Initialize UART with given baud rate.
 * @param spbrg Baud rate register value
 */
void uart_init(unsigned char spbrg) {
    SPBRG = spbrg;
    TXSTAbits.BRGH = 1; // High speed
    TXSTAbits.SYNC = 0; // Async mode
    RCSTAbits.SPEN = 1; // Enable serial port
    TXSTAbits.TXEN = 1; // Enable transmitter
    RCSTAbits.CREN = 1; // Enable receiver
}

/**
 * @brief Transmit a byte over UART.
 * @param data Byte to transmit
 */
void uart_transmit(unsigned char data) {
    while (!PIR1bits.TXIF);
    TXREG = data;
}

/**
 * @brief Receive a byte from UART.
 * @return Received byte
 */
unsigned char uart_receive(void) {
    while (!PIR1bits.RCIF);
    return RCREG;
}
