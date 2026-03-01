.. _gpio_avr:

====================
AVR GPIO (ATmega328P)
====================

**Type:** Digital I/O, configurable as input/output, supports pull-up

**How to Configure:**
- Set DDRx for direction (input/output)
- Use PORTx for output value or pull-up enable
- Use PINx to read input value

**How to Read/Write:**
- Write: Set/clear PORTx bit
- Read: Read PINx bit

**What else to cover:**
- Debouncing
- Alternate functions
- Interrupt-on-change
- Example code snippets

**Bring-Up Sequence:**
- Configure DDR and pull-up defaults
- Validate output toggle then input read
- Add interrupt-on-change if needed

**Validation Checklist:**
- PIN reads match physical state
- Output toggles at expected timing
- Interrupt path clears flags reliably
