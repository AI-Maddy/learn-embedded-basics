
// RP2040 GPIO Interrupt Example
// Button on GPIO14 triggers interrupt, toggles LED on GPIO25
#include "pico/stdlib.h"
volatile bool led_state = false;
void button_callback(uint gpio, uint32_t events) {
	led_state = !led_state;
	gpio_put(25, led_state);
}
int main() {
	stdio_init_all();
	gpio_init(25);
	gpio_set_dir(25, GPIO_OUT);
	gpio_init(14);
	gpio_set_dir(14, GPIO_IN);
	gpio_pull_up(14);
	gpio_set_irq_enabled_with_callback(14, GPIO_IRQ_EDGE_FALL, true, &button_callback);
	while (1) {
		// Main loop does nothing, LED toggled in ISR
	}
}
