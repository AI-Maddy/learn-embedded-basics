.. _gd32vf103_adc:

====================
GD32VF103 ADC
====================

**Type:** 12-bit SAR ADC, STM32-like

**How to Configure:**
- Enable ADC clock
- Configure GPIO as analog
- Set ADC parameters (resolution, scan mode, continuous mode)
- Configure sampling time
- Calibrate ADC
- Enable ADC

**How to Read:**
- Start conversion
- Wait for EOC
- Read result from data register

**What else to cover:**
- Multi-channel scan
- DMA support
- Analog watchdog
- Example code snippets

**Bring-Up Sequence:**
- Enable ADC and GPIO clocks
- Configure analog input mode
- Calibrate ADC and run test conversion
- Validate multi-sample consistency

**Validation Checklist:**
- Reference and channel config match expected range
- Conversion complete flag handled correctly
- Data register reads are consistent

**Common Pitfalls:**
- Missing ADC calibration step
- Wrong channel selection bits
- Insufficient sample time for sensor source
