.. _gpio_pic:

====================
PIC GPIO (PIC16F877A)
====================

**Type:** Digital I/O, open-drain, weak pull-up

**How to Configure:**
- Set TRISx for direction
- Use LATx/PORTx for output/input
- Enable pull-ups via OPTION_REG

**How to Read/Write:**
- Write: Set/clear LATx/PORTx
- Read: Read PORTx

**What else to cover:**
- Interrupt-on-change
- Debouncing
- Alternate functions
- Example code snippets

**Bring-Up Sequence:**
- Configure TRIS and output defaults
- Validate blink and input read paths
- Enable interrupt-on-change if required

**Validation Checklist:**
- Direction bits align with hardware wiring
- Input logic is stable after debounce
- IOC flag handling is robust
