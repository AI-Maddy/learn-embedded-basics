
// MSP430 GPIO Interrupt Example
// Button on P1.3 triggers interrupt, toggles LED on P1.0
#include <msp430.h>
volatile unsigned int led_state = 0;
void main(void) {
	WDTCTL = WDTPW | WDTHOLD;
	P1DIR |= 0x01;  // LED output
	P1DIR &= ~0x08; // Button input
	P1REN |= 0x08;  // Enable pull-up/down
	P1OUT |= 0x08;  // Pull-up
	P1IE  |= 0x08;  // Enable interrupt on P1.3
	P1IES |= 0x08;  // Falling edge
	P1IFG &= ~0x08; // Clear flag
	__bis_SR_register(GIE); // Enable global interrupts
	while (1) {
		// Main loop does nothing, LED toggled in ISR
	}
}
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void) {
	led_state ^= 1;
	if (led_state)
		P1OUT |= 0x01;
	else
		P1OUT &= ~0x01;
	P1IFG &= ~0x08; // Clear flag
}
