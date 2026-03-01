Cheatsheets
===========

Quick baremetal bring-up references for each supported MCU family.

Available sheets
----------------

* ``avr_cheatsheet.rst``
* ``c2000_cheatsheet.rst``
* ``cc26xx_cheatsheet.rst``
* ``gd32vf103_cheatsheet.rst``
* ``msp430_cheatsheet.rst``
* ``nrf52_cheatsheet.rst``
* ``pic_cheatsheet.rst``
* ``rp2040_cheatsheet.rst``
* ``stm32f1_cheatsheet.rst``

How to use
----------

* Validate clock assumptions first.
* Configure one GPIO output and one UART log path.
* Enable interrupts only after peripherals are stable.
* Confirm behavior with a blink + serial banner smoke test.

Validation checklist
--------------------

* Clock source and frequency confirmed.
* GPIO direction/pull states verified.
* First interrupt event handled correctly.
* Minimal app runs without unexpected resets.

Best practice
-------------

Use cheatsheets as launch guides, then move to datasheet and reference manual for exact register semantics.
