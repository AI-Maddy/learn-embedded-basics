
// AVR GPIO Interrupt Example
// Button on PD2 triggers INT0, toggles LED on PB5
#include <avr/io.h>
#include <avr/interrupt.h>

void gpio_init(void) {
	DDRB |= (1 << DDB5);    // LED output
	DDRD &= ~(1 << DDD2);   // Button input
	PORTD |= (1 << PORTD2); // Enable pull-up
	EICRA |= (1 << ISC01);  // INT0 falling edge
	EIMSK |= (1 << INT0);   // Enable INT0
	sei();                  // Enable global interrupts
}

ISR(INT0_vect) {
	PORTB ^= (1 << PORTB5); // Toggle LED
}

int main(void) {
	gpio_init();
	while (1) {
		// Main loop does nothing, LED toggled in ISR
	}
	return 0;
}
