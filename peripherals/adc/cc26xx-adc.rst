.. _cc26xx_adc:

====================
CC26xx ADC
====================

**Type:** 12-bit SAR ADC, ultra-low-power

**How to Configure:**
- Configure input channel
- Set reference voltage
- Configure sampling time
- Enable ADC

**How to Read:**
- Start conversion
- Wait for completion
- Read result from result register

**What else to cover:**
- Low-power sampling
- Interrupt-driven conversion
- Example code snippets

**Bring-Up Sequence:**
- Enable ADC and required power domains
- Select channel and reference
- Perform first conversion and sanity-check value
- Add periodic sampling strategy

**Validation Checklist:**
- Channel reads map to expected sensor behavior
- Noise within acceptable range
- Sleep/wake transitions preserve ADC behavior

**Common Pitfalls:**
- Wrong DIO-to-ADC mapping
- Power domain not enabled
- Sampling during noisy RF activity
