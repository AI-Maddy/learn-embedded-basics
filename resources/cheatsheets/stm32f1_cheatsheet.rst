STM32F1 Baremetal Cheatsheet
============================

Target
------

* Family: STM32F1 (example: STM32F103)
* Typical first test: PC13 LED blink + UART output

Startup essentials
------------------

1. Run startup and ``SystemInit`` sequence.
2. Enable RCC clocks before peripheral access.
3. Configure GPIO mode/alternate function.
4. Set up NVIC/EXTI for interrupt validation.

Critical checks
---------------

* Correct OpenOCD target config is used.
* Vector table location is correct.
* Peripheral clock source matches baud/timer math.

Fast validation
---------------

* Breakpoint at ``main`` is reached in debug session.
* GPIO/EXTI path works with expected polarity.
* Timer/UART timing aligns with configured clocks.
