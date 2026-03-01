
// nRF52 GPIO Initialization Example
// Set P0.17 as output, P0.13 as input
#include "nrf.h"
void gpio_init(void) {
	NRF_P0->DIRSET = (1 << 17); // LED output
	NRF_P0->DIRCLR = (1 << 13); // Button input
	NRF_P0->PIN_CNF[13] = (1 << 1); // Pull-up
}
int main(void) {
	gpio_init();
	while (1) {
		// ... main loop ...
	}
}
