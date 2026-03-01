nRF52 Baremetal Cheatsheet
==========================

Target
------

* Family: nRF52 (example: nRF52832)
* Typical first test: LED + button + timer callback

Startup essentials
------------------

1. Configure HFCLK/LFCLK as required.
2. Initialize GPIO and optional GPIOTE events.
3. Bring up UART logging path.
4. Enable interrupts and verify event loop behavior.

Critical checks
---------------

* SWD debug attach is stable.
* Clock source matches radio/timer needs.
* Interrupt flags are cleared with correct semantics.

Fast validation
---------------

* GPIO event routing behaves as configured.
* Timer-driven callback cadence is stable.
* Radio prep sequence passes basic smoke test.
