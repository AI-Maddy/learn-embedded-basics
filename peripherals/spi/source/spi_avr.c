/*
 * spi_avr.c
 * AVR ATmega328P SPI Example Source File
 *
 * Demonstrates basic SPI initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <avr/io.h>

/**
 * @brief Initialize SPI as master.
 */
void spi_init(void) {
    DDRB |= (1 << PB5) | (1 << PB7) | (1 << PB4); // SCK, MOSI, SS as output
    DDRB &= ~(1 << PB6); // MISO as input
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, Master, f/16
}

/**
 * @brief Transmit and receive a byte over SPI.
 * @param data Byte to transmit
 * @return Received byte
 */
unsigned char spi_transfer(unsigned char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}
