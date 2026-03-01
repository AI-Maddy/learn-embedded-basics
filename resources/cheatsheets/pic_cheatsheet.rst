PIC Baremetal Cheatsheet
========================

Target
------

* Family: PIC16 (example: PIC16F877A)
* Typical first test: GPIO blink on PORTD

Startup essentials
------------------

1. Configure oscillator and config bits.
2. Set TRIS registers for direction.
3. Initialize PORT defaults and interrupts.
4. Validate UART/ADC timing against clock.

Critical checks
---------------

* Config bits match board oscillator hardware.
* TRIS and PORT usage are consistent.
* External interrupt flags are cleared correctly.

Fast validation
---------------

* Clock startup is reliable after power cycle.
* GPIO mode matches expected hardware behavior.
* Interrupt source fires only on intended edge.
