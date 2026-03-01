
// AVR Button Input + Debounce Example
// Button on PD2, LED on PB5
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB |= (1 << DDB5);    // LED output
	DDRD &= ~(1 << DDD2);   // Button input
	PORTD |= (1 << PORTD2); // Enable pull-up
	while (1) {
		if (!(PIND & (1 << PIND2))) { // Button pressed (active low)
			_delay_ms(20); // Debounce
			if (!(PIND & (1 << PIND2))) {
				PORTB |= (1 << PORTB5); // LED on
			}
		} else {
			PORTB &= ~(1 << PORTB5); // LED off
		}
	}
	return 0;
}
