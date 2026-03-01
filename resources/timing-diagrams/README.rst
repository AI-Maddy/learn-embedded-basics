Timing Diagrams
===============

Signal timing references for protocol-level debugging.

Include examples for
--------------------

* UART frame timing
* SPI CPOL/CPHA modes
* I2C start/stop/ACK cycles
* PWM period and duty visualization

Practical use
-------------

1. Capture signals with logic analyzer.
2. Compare against expected timing diagram.
3. Adjust clock, phase, or pull-ups as required.

Validation checklist
--------------------

* Setup/hold timing margins look safe.
* Bus idle levels match protocol requirements.
* Repeated captures show consistent waveform shape.

Protocol-specific checks
------------------------

* UART: verify baud error, start-bit detection, and stop-bit width.
* SPI: confirm CPOL/CPHA choice and chip-select active window.
* I2C: inspect ACK/NACK timing and clock stretching behavior.
* PWM: measure period jitter and duty update synchronization.

Capture workflow
----------------

1. Trigger on start condition or chip-select edge.
2. Capture enough pre-trigger and post-trigger samples.
3. Annotate expected vs observed edges directly in notes.
4. Re-run after firmware timing changes to confirm improvement.

Common root causes
------------------

* Wrong peripheral clock source or divider value
* Pin mux mismatch between firmware and board routing
* Pull-up value issues (especially I2C rise time)
* ISR latency spikes affecting software-timed outputs
