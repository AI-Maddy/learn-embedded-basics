C2000 Baremetal Cheatsheet
==========================

Target
------

* Family: TI C2000 (example: F28027)
* Typical first test: GPIO toggle + PWM output

Startup essentials
------------------

1. Run system control initialization.
2. Configure peripheral clocks and GPIO mux.
3. Use ``EALLOW/EDIS`` for protected registers.
4. Bring up PIE interrupts after peripheral init.

Critical checks
---------------

* PWM frequency measured on scope.
* ADC trigger synchronization verified.
* Interrupt acks are handled correctly.

Fast validation
---------------

* GPIO toggles without mux conflicts.
* PWM + ADC timing relationship is deterministic.
* ISR latency stays within control loop budget.
