RP2040 Baremetal Cheatsheet
===========================

Target
------

* Family: RP2040
* Typical first test: onboard LED blink + UART banner

Startup essentials
------------------

1. Confirm SDK/boot setup and board target.
2. Initialize GPIO function and direction.
3. Configure timers or PWM for periodic tasks.
4. Add interrupt callback path if needed.

Critical checks
---------------

* ``PICO_SDK_PATH`` and board config are valid.
* UF2 flashing workflow works reliably.
* SWD debug attach works with chosen probe.

Fast validation
---------------

* UF2 build and flash cycle is repeatable.
* GPIO + UART smoke tests pass after reboot.
* Callback/IRQ behavior remains stable under load.
