
// C2000 Button Input + Debounce Example
// Button on GPIO1, LED on GPIO0
#include "F2802x_Device.h"
void delay(void) {
	volatile long i;
	for (i = 0; i < 100000; i++);
}
void main(void) {
	InitSysCtrl();
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0; // LED output
	GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0; // Button input
	GpioCtrlRegs.GPADIR.bit.GPIO1 = 0;
	EDIS;
	while (1) {
		if (GpioDataRegs.GPADAT.bit.GPIO1 == 0) {
			delay(); // Debounce
			if (GpioDataRegs.GPADAT.bit.GPIO1 == 0) {
				GpioDataRegs.GPASET.bit.GPIO0 = 1;
			}
		} else {
			GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
		}
	}
}
