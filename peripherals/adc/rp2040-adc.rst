.. _rp2040_adc:

====================
RP2040 ADC
====================

**Type:** 12-bit SAR ADC, 4 channels + internal temperature sensor

**How to Configure:**
- Enable ADC hardware
- Select input channel
- Configure FIFO (optional)

**How to Read:**
- Start conversion
- Wait for conversion complete
- Read result from result register

**What else to cover:**
- Free-running mode
- DMA for fast sampling
- Internal temperature sensor
- Example code snippets

**Bring-Up Sequence:**
- Initialize ADC block and GPIO analog pin
- Select input channel and FIFO settings
- Read baseline sample and validate scaling
- Add periodic sampling timer/task

**Validation Checklist:**
- Channel mapping is correct
- FIFO/interrupt behavior is reliable
- Temperature sensor channel (if used) reads plausibly

**Common Pitfalls:**
- Wrong GPIO-to-ADC channel mapping
- Forgetting to enable ADC block
- Misinterpreting raw count-to-voltage conversion
