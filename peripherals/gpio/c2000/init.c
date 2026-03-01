
// C2000 GPIO Initialization Example
// Set GPIO0 as output, GPIO1 as input
#include "F2802x_Device.h"
void gpio_init(void) {
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0; // GPIO0 as GPIO
	GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;  // Output
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0; // GPIO1 as GPIO
	GpioCtrlRegs.GPADIR.bit.GPIO1 = 0;  // Input
	EDIS;
}
void main(void) {
	InitSysCtrl();
	gpio_init();
	while (1) {
		// ... main loop ...
	}
}
