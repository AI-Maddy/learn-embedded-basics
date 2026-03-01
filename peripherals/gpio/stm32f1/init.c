
// STM32F1 GPIO Initialization Example
// Set PC13 as output, PA0 as input
#include "stm32f10x.h"
void gpio_init_example(void) {
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN;
	GPIOA->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);
	GPIOA->CRL |= GPIO_CRL_CNF0_1; // Input floating
	GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
	GPIOC->CRH |= GPIO_CRH_MODE13_0;
}
int main(void) {
	gpio_init_example();
	while (1) {
		// ... main loop ...
	}
}
