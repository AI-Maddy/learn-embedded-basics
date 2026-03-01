/*
 * spi_pic.c
 * PIC16F877A SPI Example Source File
 *
 * Demonstrates basic SPI initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <xc.h>

/**
 * @brief Initialize SPI as master.
 */
void spi_init(void) {
    TRISC3 = 0; // SCK output
    TRISC4 = 1; // SDI input
    TRISC5 = 0; // SDO output
    SSPSTAT = 0x40; // SMP=1
    SSPCON = 0x21; // SSPEN=1, Master mode, Fosc/16
}

/**
 * @brief Transmit and receive a byte over SPI.
 * @param data Byte to transmit
 * @return Received byte
 */
unsigned char spi_transfer(unsigned char data) {
    SSPBUF = data;
    while (!SSPSTATbits.BF);
    return SSPBUF;
}
