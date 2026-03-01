
// RP2040 GPIO Initialization Example
// Set GPIO25 as output, GPIO14 as input
#include "pico/stdlib.h"
void gpio_init_example(void) {
	gpio_init(25);
	gpio_set_dir(25, GPIO_OUT);
	gpio_init(14);
	gpio_set_dir(14, GPIO_IN);
	gpio_pull_up(14);
}
int main() {
	stdio_init_all();
	gpio_init_example();
	while (1) {
		// ... main loop ...
	}
}
