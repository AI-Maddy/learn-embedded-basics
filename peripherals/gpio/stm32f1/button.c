
// STM32F1 Button Input + Debounce Example
// Button on PA0, LED on PC13
#include "stm32f10x.h"
void delay(void) {
	for (volatile int i = 0; i < 100000; i++);
}
int main(void) {
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;
	GPIOA->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);
	GPIOA->CRL |= GPIO_CRL_CNF0_1; // Input floating
	GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
	GPIOC->CRH |= GPIO_CRH_MODE13_0;
	while (1) {
		if (!(GPIOA->IDR & GPIO_IDR_IDR0)) {
			delay();
			if (!(GPIOA->IDR & GPIO_IDR_IDR0)) {
				GPIOC->BSRR = GPIO_BSRR_BR13;
			}
		} else {
			GPIOC->BSRR = GPIO_BSRR_BS13;
		}
	}
}
