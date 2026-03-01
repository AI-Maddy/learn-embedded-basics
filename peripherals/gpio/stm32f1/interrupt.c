
// STM32F1 GPIO Interrupt Example
// Button on PA0 triggers EXTI0, toggles LED on PC13
#include "stm32f10x.h"
void EXTI0_IRQHandler(void) {
	if (EXTI->PR & EXTI_PR_PR0) {
		GPIOC->ODR ^= (1 << 13);
		EXTI->PR = EXTI_PR_PR0;
	}
}
int main(void) {
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN;
	GPIOA->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);
	GPIOA->CRL |= GPIO_CRL_CNF0_1; // Input floating
	GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
	GPIOC->CRH |= GPIO_CRH_MODE13_0;
	AFIO->EXTICR[0] &= ~AFIO_EXTICR1_EXTI0;
	AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI0_PA;
	EXTI->IMR |= EXTI_IMR_MR0;
	EXTI->FTSR |= EXTI_FTSR_TR0;
	NVIC_EnableIRQ(EXTI0_IRQn);
	while (1) {
		// Main loop does nothing, LED toggled in ISR
	}
}
