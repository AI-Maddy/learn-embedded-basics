
// PIC GPIO Interrupt Example
// Button on RB0 triggers interrupt, toggles LED on RD0
#include <xc.h>
#define _XTAL_FREQ 4000000
volatile bit led_state @ ((unsigned)&PORTD*8+0);

void __interrupt() isr(void) {
	if (INTF) {
		led_state = !led_state;
		INTF = 0; // Clear interrupt flag
	}
}

void main(void) {
	TRISD0 = 0; // LED output
	TRISB0 = 1; // Button input
	RBPU = 0;   // Enable PORTB pull-ups
	INTE = 1;   // Enable RB0/INT external interrupt
	GIE = 1;    // Enable global interrupts
	while (1) {
		// Main loop does nothing, LED toggled in ISR
	}
}
