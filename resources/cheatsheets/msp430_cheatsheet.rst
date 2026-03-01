MSP430 Baremetal Cheatsheet
===========================

Target
------

* Family: MSP430 (example: G2553)
* Typical first test: P1.0 blink

Startup essentials
------------------

1. Stop watchdog immediately in startup.
2. Configure DCO/clock source as needed.
3. Set GPIO direction and pull resistor settings.
4. Enable global interrupts when modules are configured.

Critical checks
---------------

* Watchdog is intentionally managed.
* Low-power wake source works correctly.
* Timer tick period matches expected clock.

Fast validation
---------------

* No watchdog resets during idle loop.
* Wake-up source reliably returns to active path.
* Timer event period measured and stable.
