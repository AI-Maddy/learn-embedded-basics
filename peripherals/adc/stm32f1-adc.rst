.. _stm32f1_adc:

====================
STM32F1 ADC
====================

**Type:** 12-bit SAR ADC, up to 3 units, scan mode, DMA support

**How to Configure:**
- Enable ADC clock (RCC)
- Configure GPIO pin as analog
- Set ADC parameters (resolution, scan mode, continuous mode)
- Configure sampling time
- Calibrate ADC
- Enable ADC

**How to Read:**
- Start conversion (software or external trigger)
- Wait for EOC (End of Conversion)
- Read result from ADC_DR

**What else to cover:**
- Multi-channel scan
- DMA for fast data transfer
- Analog watchdog
- Temperature sensor and Vrefint
- Example code snippets

**Bring-Up Sequence:**
- Enable RCC clock and analog pin mode
- Configure sample time and trigger mode
- Run calibration and first conversion
- Validate single and scan mode behavior

**Validation Checklist:**
- EOC flag handling is correct
- Conversion values are stable on static input
- DMA transfer (if used) aligns with sample count

**Common Pitfalls:**
- Skipping calibration
- Sample time too short for source impedance
- Incorrect scan/DMA configuration pairing
