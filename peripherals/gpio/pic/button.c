
// PIC Button Input + Debounce Example
// Button on RB0, LED on RD0
#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
	TRISD0 = 0; // LED output
	TRISB0 = 1; // Button input
	RBPU = 0;   // Enable PORTB pull-ups
	while (1) {
		if (!RB0) { // Button pressed (active low)
			__delay_ms(20); // Debounce
			if (!RB0) {
				RD0 = 1;
			}
		} else {
			RD0 = 0;
		}
	}
}
