
// PIC GPIO Initialization Example
// Set RD0 as output, RB0 as input
#include <xc.h>

void gpio_init(void) {
	TRISD0 = 0; // RD0 output
	TRISB0 = 1; // RB0 input
	RBPU = 0;   // Enable PORTB pull-ups
}

void main(void) {
	gpio_init();
	while (1) {
		// ... main loop ...
	}
}
