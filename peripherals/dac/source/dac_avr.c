/*
 * dac_avr.c
 * AVR ATmega328P DAC Example (External MCP4921 via SPI)
 *
 * Demonstrates interfacing an external SPI DAC (MCP4921) with AVR.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <avr/io.h>

#define DAC_CS_PORT PORTB
#define DAC_CS_DDR  DDRB
#define DAC_CS_PIN  PB2

void dac_spi_init(void) {
    DAC_CS_DDR |= (1 << DAC_CS_PIN);
    DAC_CS_PORT |= (1 << DAC_CS_PIN); // CS high
    DDRB |= (1 << PB5) | (1 << PB7); // SCK, MOSI as output
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void dac_write(uint16_t value) {
    DAC_CS_PORT &= ~(1 << DAC_CS_PIN); // CS low
    SPDR = (0x30 | ((value >> 8) & 0x0F));
    while (!(SPSR & (1 << SPIF)));
    SPDR = value & 0xFF;
    while (!(SPSR & (1 << SPIF)));
    DAC_CS_PORT |= (1 << DAC_CS_PIN); // CS high
}
