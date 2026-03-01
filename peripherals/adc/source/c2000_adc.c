/*
 * c2000_adc.c
 *
 * TI C2000 F28027 ADC Example Source File
 *
 * Demonstrates basic configuration and usage of the 12/16-bit SAR ADC.
 *
 * Features:
 *  - Single conversion
 *  - Sequenced conversions
 *  - Interrupt-driven conversion
 *
 * Author: Your Name
 * Date: 2026-02-27
 */

#include "F2802x_Device.h"
#include <stdint.h>

/**
 * @brief Initialize the ADC for single channel, software trigger.
 */
void adc_init(void) {
    EALLOW;
    AdcRegs.ADCCTL1.bit.ADCBGPWD = 1; // Power up bandgap
    AdcRegs.ADCCTL1.bit.ADCREFSEL = 0; // Internal reference
    AdcRegs.ADCCTL1.bit.ADCPWDN = 1; // Power up ADC
    AdcRegs.ADCCTL1.bit.ADCENABLE = 1; // Enable ADC
    EDIS;
}

/**
 * @brief Start a single ADC conversion on SOC0.
 */
void adc_start_conversion(void) {
    AdcRegs.ADCSOCFRC1.all = 0x1; // Force SOC0
}

/**
 * @brief Read the result of the last ADC conversion (blocking).
 * @return 12/16-bit ADC result
 */
uint16_t adc_read(void) {
    while (AdcRegs.ADCINTFLG.bit.ADCINT1 == 0); // Wait for interrupt flag
    AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; // Clear flag
    return AdcResult.ADCRESULT0;
}

/**
 * @brief Example: Read ADC value from channel 0.
 */
void example_adc_read(void) {
    adc_start_conversion();
    uint16_t value = adc_read();
    // Use 'value' as needed
}

/**
 * @brief Enable ADC interrupt.
 */
void adc_enable_interrupt(void) {
    AdcRegs.ADCINTSOCSEL1.bit.SOC0 = 1; // Interrupt on SOC0
    PieCtrlRegs.PIEIER1.bit.INTx6 = 1; // Enable ADCINT1 in PIE
    IER |= M_INT1; // Enable CPU INT1
    EINT; // Enable global interrupts
}

/**
 * @brief ADC Interrupt Service Routine
 */
interrupt void adc_isr(void) {
    uint16_t value = AdcResult.ADCRESULT0;
    // Handle ADC value in interrupt
    AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1; // Clear flag
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
