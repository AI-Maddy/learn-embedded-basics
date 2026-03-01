
// PIC Minimal LED Blink Example
// Device: PIC16F877A, LED on RD0
#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
	TRISD0 = 0; // RD0 output
	while (1) {
		RD0 = 1;
		__delay_ms(500);
		RD0 = 0;
		__delay_ms(500);
	}
}
