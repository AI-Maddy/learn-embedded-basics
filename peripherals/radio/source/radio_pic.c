/*
 * radio_pic.c
 * PIC16F877A Radio (nRF24L01) Example Source File
 *
 * Demonstrates basic SPI-based radio module initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <xc.h>

/**
 * @brief Initialize SPI for nRF24L01 radio module.
 */
void radio_spi_init(void) {
    TRISC3 = 0; // SCK output
    TRISC4 = 1; // SDI input
    TRISC5 = 0; // SDO output
    SSPSTAT = 0x40; // SMP=1
    SSPCON = 0x21; // SSPEN=1, Master mode, Fosc/16
}

/**
 * @brief Transmit and receive a byte over SPI (to radio).
 * @param data Byte to transmit
 * @return Received byte
 */
unsigned char radio_spi_transfer(unsigned char data) {
    SSPBUF = data;
    while (!SSPSTATbits.BF);
    return SSPBUF;
}
