
// CC26xx GPIO Initialization Example
// Set DIO6 as output, DIO13 as input
#include <ti/devices/cc26xx/driverlib/gpio.h>
#include <stdint.h>

void gpio_init(void) {
	GPIO_setOutputEnableDio(6, GPIO_OUTPUT_ENABLE);   // LED output
	GPIO_setOutputEnableDio(13, GPIO_OUTPUT_DISABLE); // Button input
}

int main(void) {
	gpio_init();
	while (1) {
		// ... main loop ...
	}
	return 0;
}
