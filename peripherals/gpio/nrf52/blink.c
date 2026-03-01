
// nRF52 Minimal LED Blink Example
// Board: nRF52832 DK, LED1 on P0.17
#include "nrf.h"
void delay(void) {
	for (volatile int i = 0; i < 1000000; i++);
}
int main(void) {
	NRF_P0->DIRSET = (1 << 17); // P0.17 output
	while (1) {
		NRF_P0->OUTCLR = (1 << 17);
		delay();
		NRF_P0->OUTSET = (1 << 17);
		delay();
	}
}
