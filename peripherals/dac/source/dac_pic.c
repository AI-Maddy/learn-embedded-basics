/*
 * dac_pic.c
 * PIC16F877A DAC Example (External MCP4921 via SPI)
 *
 * Demonstrates interfacing an external SPI DAC (MCP4921) with PIC.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <xc.h>

#define DAC_CS LATBbits.LATB0

void dac_spi_init(void) {
    TRISB0 = 0; // CS as output
    DAC_CS = 1;
    TRISC3 = 0; // SCK output
    TRISC5 = 0; // SDO output
    SSPCON = 0x21;
}

void dac_write(unsigned int value) {
    DAC_CS = 0;
    SSPBUF = (0x30 | ((value >> 8) & 0x0F));
    while (!SSPSTATbits.BF);
    SSPBUF = value & 0xFF;
    while (!SSPSTATbits.BF);
    DAC_CS = 1;
}
