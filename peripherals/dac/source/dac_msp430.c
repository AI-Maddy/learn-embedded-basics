/*
 * dac_msp430.c
 * MSP430G2553 DAC Example (External MCP4921 via SPI)
 *
 * Demonstrates interfacing an external SPI DAC (MCP4921) with MSP430.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <msp430.h>

#define DAC_CS_PORT P1OUT
#define DAC_CS_DIR  P1DIR
#define DAC_CS_PIN  BIT0

void dac_spi_init(void) {
    DAC_CS_DIR |= DAC_CS_PIN;
    DAC_CS_PORT |= DAC_CS_PIN; // CS high
    P1SEL |= BIT5 + BIT7;
    P1SEL2 |= BIT5 + BIT7;
    UCB0CTL1 |= UCSWRST;
    UCB0CTL0 = UCCKPH + UCMSB + UCMST + UCSYNC;
    UCB0CTL1 = UCSSEL_2 + UCSWRST;
    UCB0BR0 = 0x02;
    UCB0BR1 = 0;
    UCB0CTL1 &= ~UCSWRST;
}

void dac_write(unsigned int value) {
    DAC_CS_PORT &= ~DAC_CS_PIN;
    while (!(IFG2 & UCB0TXIFG));
    UCB0TXBUF = (0x30 | ((value >> 8) & 0x0F));
    while (!(IFG2 & UCB0TXIFG));
    UCB0TXBUF = value & 0xFF;
    while (!(IFG2 & UCB0TXIFG));
    DAC_CS_PORT |= DAC_CS_PIN;
}
