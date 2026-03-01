
// C2000 GPIO Interrupt Example
// Button on GPIO1 triggers interrupt, toggles LED on GPIO0
#include "F2802x_Device.h"
interrupt void gpio_isr(void) {
	GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
void main(void) {
	InitSysCtrl();
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0; // LED output
	GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0; // Button input
	GpioCtrlRegs.GPADIR.bit.GPIO1 = 0;
	GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 1; // GPIO1
	EDIS;
	XIntruptRegs.XINT1CR.bit.POLARITY = 0; // Falling edge
	XIntruptRegs.XINT1CR.bit.ENABLE = 1;
	PieVectTable.XINT1 = &gpio_isr;
	PieCtrlRegs.PIEIER1.bit.INTx4 = 1;
	IER |= M_INT1;
	EINT;
	while (1) {
		// Main loop does nothing, LED toggled in ISR
	}
}
