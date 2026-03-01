
// CC26xx GPIO Interrupt Example
// Button on DIO13 triggers interrupt, toggles LED on DIO6
#include <ti/devices/cc26xx/driverlib/gpio.h>
#include <ti/devices/cc26xx/driverlib/interrupt.h>
#include <ti/devices/cc26xx/driverlib/sys_ctrl.h>
#include <stdint.h>
#define LED_PIN 6
#define BTN_PIN 13

void gpio_isr(void) {
	GPIO_toggleDio(LED_PIN);
	GPIO_clearEventDio(BTN_PIN);
}

int main(void) {
	SysCtrlClockSet(false, false, SYSCTRL_SYSDIV_32MHZ);
	GPIO_setOutputEnableDio(LED_PIN, GPIO_OUTPUT_ENABLE);
	GPIO_setOutputEnableDio(BTN_PIN, GPIO_OUTPUT_DISABLE);
	GPIO_setDio(BTN_PIN);
	GPIO_clearEventDio(BTN_PIN);
	GPIO_enableIntDio(BTN_PIN);
	IntRegister(INT_GPIO, gpio_isr);
	IntEnable(INT_GPIO);
	while (1) {
		// Main loop does nothing, LED toggled in ISR
	}
	return 0;
}
