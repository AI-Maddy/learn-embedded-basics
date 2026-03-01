.. _pic_adc:

====================
PIC ADC (PIC16F877A)
====================

**Type:** 10-bit SAR ADC

**How to Configure:**
- Select analog input channel (CHS bits)
- Set reference voltages (Vref+ / Vref-)
- Configure acquisition time
- Set ADC clock source
- Enable ADC module (ADON)

**How to Read:**
- Start conversion (GO/DONE bit)
- Wait for conversion complete (GO/DONE = 0)
- Read result from ADRESH/ADRESL

**What else to cover:**
- Acquisition time calculation
- Interrupt-driven conversion
- Input impedance and recommended source resistance
- Example code snippets

**Bring-Up Sequence:**
- Configure analog pin and conversion clock
- Select channel and reference
- Start conversion and poll completion bit
- Verify result formatting and scaling

**Validation Checklist:**
- ADCON settings match target channel/reference
- Result registers read in correct order
- Timing stable across repeated reads

**Common Pitfalls:**
- Acquisition delay too short
- Wrong result alignment handling
- Analog pin not enabled correctly
