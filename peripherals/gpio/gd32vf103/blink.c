
// GD32VF103 Minimal LED Blink Example
// Board: Longan Nano, LED on PC13
#include "gd32vf103.h"
void delay(void) {
	for (volatile int i = 0; i < 1000000; i++);
}
int main(void) {
	rcu_periph_clock_enable(RCU_GPIOC);
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
	while (1) {
		gpio_bit_write(GPIOC, GPIO_PIN_13, RESET);
		delay();
		gpio_bit_write(GPIOC, GPIO_PIN_13, SET);
		delay();
	}
}
