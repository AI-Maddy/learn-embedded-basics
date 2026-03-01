
// C2000 Minimal LED Blink Example
// Device: F28027, LED on GPIO0
#include "F2802x_Device.h"
void delay(void) {
	volatile long i;
	for (i = 0; i < 1000000; i++);
}
void main(void) {
	InitSysCtrl();
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0; // GPIO0 as GPIO
	GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;  // Output
	EDIS;
	while (1) {
		GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;
		delay();
	}
}
