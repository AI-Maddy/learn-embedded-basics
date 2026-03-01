
// MSP430 Minimal LED Blink Example
// Device: MSP430G2553, LED on P1.0
#include <msp430.h>

static void delay_ms_approx(unsigned int ms) {
	while (ms--) {
		__delay_cycles(1000);
	}
}

void main(void) {
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog
	P1DIR |= 0x01;            // P1.0 output
	while (1) {
		P1OUT ^= 0x01;        // Toggle LED
		delay_ms_approx(500);
	}
}
