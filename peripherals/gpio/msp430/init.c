
// MSP430 GPIO Initialization Example
// Set P1.0 as output, P1.3 as input
#include <msp430.h>
void gpio_init(void) {
	P1DIR |= 0x01;  // P1.0 output
	P1DIR &= ~0x08; // P1.3 input
	P1REN |= 0x08;  // Enable pull-up/down on P1.3
	P1OUT |= 0x08;  // Pull-up on P1.3
}
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;
	gpio_init();
	while (1) {
		// ... main loop ...
	}
}
