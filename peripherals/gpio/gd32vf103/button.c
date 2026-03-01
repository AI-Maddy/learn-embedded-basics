
// GD32VF103 Button Input + Debounce Example
// Button on PA0, LED on PC13
#include "gd32vf103.h"
void delay(void) {
	for (volatile int i = 0; i < 100000; i++);
}
int main(void) {
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOC);
	gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
	while (1) {
		if (gpio_input_bit_get(GPIOA, GPIO_PIN_0) == RESET) {
			delay();
			if (gpio_input_bit_get(GPIOA, GPIO_PIN_0) == RESET) {
				gpio_bit_write(GPIOC, GPIO_PIN_13, RESET);
			}
		} else {
			gpio_bit_write(GPIOC, GPIO_PIN_13, SET);
		}
	}
}
