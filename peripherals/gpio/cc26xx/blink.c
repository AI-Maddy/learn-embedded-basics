
// CC26xx Minimal LED Blink Example
// Board: CC2650 LaunchPad
#include <ti/devices/cc26xx/driverlib/gpio.h>
#include <ti/devices/cc26xx/driverlib/sys_ctrl.h>
#include <ti/devices/cc26xx/driverlib/cpu.h>
#include <stdint.h>
#define LED_PIN 6 // DIO6 (Red LED)

int main(void) {
	SysCtrlClockSet(false, false, SYSCTRL_SYSDIV_32MHZ);
	GPIO_setOutputEnableDio(LED_PIN, GPIO_OUTPUT_ENABLE);
	while (1) {
		GPIO_toggleDio(LED_PIN);
		CPUdelay(8000000); // ~0.5s delay
	}
	return 0;
}
