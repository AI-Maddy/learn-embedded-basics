AVR Baremetal Cheatsheet
========================

Target
------

* Family: AVR (example: ATmega328P)
* Typical first test: LED blink on PB5

Startup essentials
------------------

1. Confirm fuse-selected clock source.
2. Set GPIO direction using ``DDRx``.
3. Enable pull-ups via ``PORTx`` for inputs.
4. Enable interrupts using ``sei`` when ready.

Critical checks
---------------

* ``F_CPU`` matches actual clock.
* Watchdog behavior is understood.
* UART baud calculations match clock source.

Fast validation
---------------

* Blink interval is stable and predictable.
* UART banner is readable at configured baud.
* Button input with pull-up behaves consistently.
