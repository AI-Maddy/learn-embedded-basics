.. _interrupts_msp430:

====================
MSP430 Interrupts
====================

**Type:** Port, timer, peripheral interrupts

**How to Configure:**
- Enable interrupt in peripheral
- Enable global interrupts (GIE)

**How to Use:**
- Write ISR function
- Clear interrupt flag

**What else to cover:**
- Interrupt vector table
- Example code snippets

**Bring-Up Sequence:**
- Configure interrupt source and edge
- Enable peripheral and global interrupt bits
- Trigger event and inspect ISR behavior

**Validation Checklist:**
- Correct vector is hit
- IFG flags clear correctly
- Main loop remains stable under ISR activity
- Interrupt enable bits are only set after source configuration is complete
