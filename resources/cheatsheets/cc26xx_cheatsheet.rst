CC26xx Baremetal Cheatsheet
===========================

Target
------

* Family: TI CC26xx
* Typical first test: DIO blink + low-power loop

Startup essentials
------------------

1. Configure system clock and power domains.
2. Initialize DIO direction and pull configuration.
3. Bring up UART debug output early.
4. Enable interrupts after driver setup.

Critical checks
---------------

* Board pin mapping matches DIO selection.
* Sleep/wake path does not deadlock.
* RF-related clocks are enabled before radio use.

Fast validation
---------------

* DIO blink test runs before low-power entry.
* Wake event restores expected GPIO behavior.
* UART diagnostics continue after wake cycles.
