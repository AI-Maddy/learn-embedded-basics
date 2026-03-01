/*
 * uart_avr.c
 * AVR ATmega328P UART Example Source File
 *
 * Demonstrates basic UART initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <avr/io.h>

/**
 * @brief Initialize UART with given baud rate.
 * @param ubrr Baud rate register value
 */
void uart_init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0); // Enable RX, TX
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 data bits, 1 stop bit
}

/**
 * @brief Transmit a byte over UART.
 * @param data Byte to transmit
 */
void uart_transmit(unsigned char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

/**
 * @brief Receive a byte from UART.
 * @return Received byte
 */
unsigned char uart_receive(void) {
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}
