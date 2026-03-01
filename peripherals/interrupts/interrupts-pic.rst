.. _interrupts_pic:

====================
PIC Interrupts (PIC16F877A)
====================

**Type:** External, timer, peripheral interrupts

**How to Configure:**
- Enable global (GIE) and peripheral (PEIE) interrupts
- Enable specific interrupt (e.g., INTCON, PIE1)

**How to Use:**
- Write ISR function
- Clear interrupt flag

**What else to cover:**
- Interrupt priorities (if available)
- Example code snippets

**Bring-Up Sequence:**
- Enable GIE/PEIE and source-specific bits
- Trigger source and verify ISR entry
- Clear source flags before exit

**Validation Checklist:**
- Correct source bit enables are set
- No spurious ISR retriggers
- Latency acceptable for application needs
- Source flags are cleared in the expected peripheral-specific order
