
// GD32VF103 GPIO Interrupt Example
// Button on PA0 triggers EXTI0, toggles LED on PC13
#include "gd32vf103.h"
void EXTI0_IRQHandler(void) {
	if (exti_interrupt_flag_get(EXTI_0) != RESET) {
		gpio_bit_toggle(GPIOC, GPIO_PIN_13);
		exti_interrupt_flag_clear(EXTI_0);
	}
}
int main(void) {
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOC);
	rcu_periph_clock_enable(RCU_AF);
	gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
	nvic_irq_enable(EXTI0_IRQn, 2, 0);
	syscfg_exti_line_config(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_0);
	exti_init(EXTI_0, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
	exti_interrupt_flag_clear(EXTI_0);
	while (1) {
		// Main loop does nothing, LED toggled in ISR
	}
}
