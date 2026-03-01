.. _avr_adc:

====================
AVR ADC (ATmega328P)
====================

**Type:** 10-bit Successive Approximation Register (SAR) ADC

**How to Configure:**
- Select reference voltage (AVcc, AREF, Internal)
- Set input channel (MUX bits)
- Enable ADC (ADEN)
- Set prescaler for ADC clock

**How to Read:**
- Start conversion (ADSC)
- Wait for conversion complete (ADIF)
- Read result from ADCL/ADCH

**What else to cover:**
- Free-running mode
- Interrupt-driven conversion
- Differential mode (if available)
- Input impedance considerations
- Power consumption tips
- Example code snippets

**Bring-Up Sequence:**
- Verify reference voltage source and decoupling
- Configure channel and prescaler
- Run one single-shot conversion and confirm range
- Add averaging/filtering for noisy signals

**Validation Checklist:**
- ADC reading changes with known input change
- Full-scale and zero-scale values are sensible
- Sampling frequency matches application needs

**Common Pitfalls:**
- ADC clock out of recommended range
- Floating analog inputs producing random values
- Inconsistent reference voltage assumptions
