
// STM32F1 Minimal LED Blink Example
// Board: Blue Pill, LED on PC13
#include "stm32f10x.h"
void delay(void) {
	for (volatile int i = 0; i < 1000000; i++);
}
int main(void) {
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
	GPIOC->CRH |= GPIO_CRH_MODE13_0;
	while (1) {
		GPIOC->BSRR = GPIO_BSRR_BR13;
		delay();
		GPIOC->BSRR = GPIO_BSRR_BS13;
		delay();
	}
}
