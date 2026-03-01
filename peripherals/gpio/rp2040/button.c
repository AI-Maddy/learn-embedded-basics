
// RP2040 Button Input + Debounce Example
// Button on GPIO14, LED on GPIO25
#include "pico/stdlib.h"
int main() {
	stdio_init_all();
	gpio_init(25);
	gpio_set_dir(25, GPIO_OUT);
	gpio_init(14);
	gpio_set_dir(14, GPIO_IN);
	gpio_pull_up(14);
	while (1) {
		if (!gpio_get(14)) {
			sleep_ms(20); // Debounce
			if (!gpio_get(14)) {
				gpio_put(25, 1);
			}
		} else {
			gpio_put(25, 0);
		}
	}
}
