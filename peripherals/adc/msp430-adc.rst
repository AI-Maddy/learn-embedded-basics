.. _msp430_adc:

====================
MSP430 ADC (ADC10/ADC12)
====================

**Type:** 10-bit or 12-bit SAR ADC

**How to Configure:**
- Select input channel (INCHx)
- Set reference voltage (V+ / V-)
- Configure sample-and-hold time
- Enable ADC module (ADC10ON/ADC12ON)

**How to Read:**
- Start conversion (ENC + ADC10SC/ADC12SC)
- Wait for conversion complete (ADC10IFG/ADC12IFG)
- Read result from ADC10MEM/ADC12MEM

**What else to cover:**
- Sequence-of-channels mode
- Interrupt-driven conversion
- Internal temperature sensor
- Example code snippets

**Bring-Up Sequence:**
- Configure ADC clock and sample-hold settings
- Select channel and reference source
- Trigger one-shot conversion and inspect result
- Add interrupt-based acquisition if needed

**Validation Checklist:**
- Conversion flag behavior is correct
- Readings are repeatable under static input
- Low-power mode transitions do not break ADC

**Common Pitfalls:**
- Incorrect reference stabilization delay
- Misconfigured sample-hold timing
- Not clearing/handling ADC interrupt flags
