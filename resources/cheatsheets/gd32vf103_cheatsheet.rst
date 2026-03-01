GD32VF103 Baremetal Cheatsheet
==============================

Target
------

* Family: GD32VF103 (RISC-V)
* Typical first test: PC13 LED blink

Startup essentials
------------------

1. Run system initialization and clock setup.
2. Enable peripheral clocks via RCU.
3. Configure GPIO mode and output type.
4. Configure EXTI/NVIC for interrupt bring-up.

Critical checks
---------------

* Correct linker script for flash/RAM map.
* UART baud matches configured core clock.
* EXTI line mapping matches chosen GPIO port.

Fast validation
---------------

* LED output and button input both verified.
* EXTI handler fires and clears flag properly.
* Clock-dependent delays align with expectation.
