
// nRF52 Button Input + Debounce Example
// Button on P0.13, LED on P0.17
#include "nrf.h"
void delay(void) {
	for (volatile int i = 0; i < 100000; i++);
}
int main(void) {
	NRF_P0->DIRSET = (1 << 17); // LED output
	NRF_P0->DIRCLR = (1 << 13); // Button input
	NRF_P0->PIN_CNF[13] = (1 << 1); // Pull-up
	while (1) {
		if (!(NRF_P0->IN & (1 << 13))) {
			delay();
			if (!(NRF_P0->IN & (1 << 13))) {
				NRF_P0->OUTCLR = (1 << 17);
			}
		} else {
			NRF_P0->OUTSET = (1 << 17);
		}
	}
}
