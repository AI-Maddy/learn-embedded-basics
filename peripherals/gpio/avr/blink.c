
// AVR Minimal LED Blink Example
// Board: ATmega328P (e.g., Arduino Uno)
// LED on PB5 (Digital Pin 13)
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	// Set PB5 as output
	DDRB |= (1 << DDB5);
	while (1) {
		// Toggle LED
		PORTB ^= (1 << PORTB5);
		_delay_ms(500); // 500ms delay
	}
	return 0;
}
