.. _interrupts_avr:

====================
AVR Interrupts (ATmega328P)
====================

**Type:** External, timer, peripheral interrupts

**How to Configure:**
- Enable global interrupts (sei)
- Enable specific interrupt in peripheral (e.g., TIMSK, EIMSK)
- Set ISR vector

**How to Use:**
- Write ISR function
- Clear interrupt flag if needed

**What else to cover:**
- Interrupt priorities
- Nested interrupts
- Example code snippets

**Bring-Up Sequence:**
- Enable specific interrupt source
- Enable global interrupts
- Trigger event and verify ISR entry

**Validation Checklist:**
- ISR fires only for expected source
- Flags clear and retrigger correctly
- Shared variables use volatile where required
