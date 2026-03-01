.. _timers_pic:

====================
PIC Timers (PIC16F877A)
====================

**Type:** 8/16-bit timers, CCP modules

**How to Configure:**
- Set TMRx registers for mode
- Set prescaler
- Configure CCP for capture/compare/PWM

**How to Use:**
- Start/stop timer
- Generate delays, PWM, or measure input
- Use interrupts for overflow/compare

**What else to cover:**
- Timer interrupts
- Example code snippets

**Bring-Up Sequence:**
- Configure TMRx mode and prescaler
- Set period and enable interrupt
- Validate delay/PWM behavior

**Validation Checklist:**
- Timing output matches expected period
- Overflow flags clear correctly
- No drift under sustained operation
