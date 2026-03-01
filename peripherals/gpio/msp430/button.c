
// MSP430 Button Input + Debounce Example
// Button on P1.3, LED on P1.0
#include <msp430.h>
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;
	P1DIR |= 0x01;  // LED output
	P1DIR &= ~0x08; // Button input
	P1REN |= 0x08;  // Enable pull-up/down
	P1OUT |= 0x08;  // Pull-up
	while (1) {
		if (!(P1IN & 0x08)) { // Button pressed (active low)
			__delay_cycles(20000); // Debounce
			if (!(P1IN & 0x08)) {
				P1OUT |= 0x01;
			}
		} else {
			P1OUT &= ~0x01;
		}
	}
}
