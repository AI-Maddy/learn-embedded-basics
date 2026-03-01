.. _gpio_msp430:

====================
MSP430 GPIO
====================

**Type:** Digital I/O, pull-up/pull-down, interrupt-on-change

**How to Configure:**
- Set PxDIR for direction
- Use PxOUT for output value
- Use PxREN for pull-up/pull-down

**How to Read/Write:**
- Write: Set/clear PxOUT
- Read: Read PxIN

**What else to cover:**
- Interrupts
- Alternate functions
- Debouncing
- Example code snippets

**Bring-Up Sequence:**
- Configure PxDIR/PxREN/PxOUT defaults
- Validate LED output and button input
- Enable and test port interrupt behavior

**Validation Checklist:**
- Pull-up/down behavior is stable
- Edge selection triggers expected ISR
- Port flags clear in ISR correctly
