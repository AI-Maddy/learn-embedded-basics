
// AVR GPIO Initialization Example
// Set PB0 as output, PD2 as input with pull-up
#include <avr/io.h>

void gpio_init(void) {
	DDRB |= (1 << DDB0);    // PB0 output
	DDRD &= ~(1 << DDD2);   // PD2 input
	PORTD |= (1 << PORTD2); // Enable pull-up on PD2
}

int main(void) {
	gpio_init();
	while (1) {
		// ... main loop ...
	}
	return 0;
}
