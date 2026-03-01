
// CC26xx Button Input + Debounce Example
// Button: DIO13, LED: DIO6
#include <ti/devices/cc26xx/driverlib/gpio.h>
#include <ti/devices/cc26xx/driverlib/sys_ctrl.h>
#include <ti/devices/cc26xx/driverlib/cpu.h>
#include <stdint.h>
#define LED_PIN 6
#define BTN_PIN 13

int main(void) {
	SysCtrlClockSet(false, false, SYSCTRL_SYSDIV_32MHZ);
	GPIO_setOutputEnableDio(LED_PIN, GPIO_OUTPUT_ENABLE);
	GPIO_setOutputEnableDio(BTN_PIN, GPIO_OUTPUT_DISABLE);
	GPIO_setDio(BTN_PIN);
	while (1) {
		if (!GPIO_readDio(BTN_PIN)) {
			CPUdelay(160000); // debounce
			if (!GPIO_readDio(BTN_PIN)) {
				GPIO_setDio(LED_PIN);
			}
		} else {
			GPIO_clearDio(LED_PIN);
		}
	}
	return 0;
}
