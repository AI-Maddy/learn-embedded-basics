.. _nrf52_adc:

====================
nRF52 ADC (SAADC)
====================

**Type:** 12-bit Successive Approximation ADC, 8 channels, EasyDMA

**How to Configure:**
- Configure input channel and gain
- Set reference voltage
- Configure resolution and oversampling
- Enable SAADC

**How to Read:**
- Start conversion (task)
- Wait for END event
- Read result from result buffer

**What else to cover:**
- Differential mode
- Oversampling
- DMA (EasyDMA) for fast transfer
- Example code snippets

**Bring-Up Sequence:**
- Configure SAADC channel and gain/reference
- Initialize buffer for samples
- Start conversion and validate raw values
- Add oversampling/averaging as needed

**Validation Checklist:**
- Raw code range matches configured gain/reference
- Buffer events and callbacks are reliable
- Noise performance meets target

**Common Pitfalls:**
- Wrong gain/reference combination
- Uninitialized sample buffer
- Ignoring offset calibration step
