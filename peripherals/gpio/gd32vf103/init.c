
// GD32VF103 GPIO Initialization Example
// Set PC13 as output, PA0 as input
#include "gd32vf103.h"
void gpio_init(void) {
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOC);
	gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
}
int main(void) {
	gpio_init();
	while (1) {
		// ... main loop ...
	}
}
