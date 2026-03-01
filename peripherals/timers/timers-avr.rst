.. _timers_avr:

====================
AVR Timers (ATmega328P)
====================

**Type:** 8/16-bit timers, compare/capture, PWM

**How to Configure:**
- Set TCCRnA/B for mode (normal, CTC, PWM)
- Set prescaler (CSn bits)
- Configure compare/capture registers (OCRn, ICRn)

**How to Use:**
- Start/stop timer
- Generate delays, PWM, or measure input
- Use interrupts for overflow/compare

**What else to cover:**
- Timer interrupts
- Input capture
- Example code snippets

**Bring-Up Sequence:**
- Configure mode and prescaler
- Set compare/overflow behavior
- Validate periodic event timing

**Validation Checklist:**
- Tick period matches calculation
- Overflow/compare flags handled correctly
- PWM output stable if enabled
