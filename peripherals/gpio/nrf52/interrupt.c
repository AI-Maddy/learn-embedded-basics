
// nRF52 GPIO Interrupt Example
// Button on P0.13 triggers GPIOTE, toggles LED on P0.17
#include "nrf.h"
volatile int led_state = 0;
void GPIOTE_IRQHandler(void) {
	if (NRF_GPIOTE->EVENTS_PORT) {
		if (!(NRF_P0->IN & (1 << 13))) {
			led_state ^= 1;
			if (led_state)
				NRF_P0->OUTCLR = (1 << 17);
			else
				NRF_P0->OUTSET = (1 << 17);
		}
		NRF_GPIOTE->EVENTS_PORT = 0;
	}
}
int main(void) {
	NRF_P0->DIRSET = (1 << 17); // LED output
	NRF_P0->DIRCLR = (1 << 13); // Button input
	NRF_P0->PIN_CNF[13] = (1 << 1); // Pull-up
	NRF_GPIOTE->INTENSET = (1 << 0); // Enable PORT event
	NVIC_EnableIRQ(GPIOTE_IRQn);
	while (1) {
		// Main loop does nothing, LED toggled in ISR
	}
}
