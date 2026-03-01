Reference Manuals
=================

Detailed register-level manuals used for low-level firmware implementation.

Recommended usage
-----------------

1. Read peripheral overview block diagram.
2. Read register descriptions and reset values.
3. Follow documented programming sequence exactly.

High-value chapters
-------------------

* Memory map
* Clock/reset controller
* Interrupt controller
* Peripheral chapters used by your firmware

Validation habit
----------------

After coding each register sequence, read back registers in debugger and compare with manual-defined expected values.

Workflow suggestion
-------------------

1. Start from reset/clock chapter and confirm peripheral clock enable path.
2. Build a minimal init sequence from official pseudocode or reference flow.
3. Apply one setting at a time and verify with readback or signal capture.
4. Record register deltas in commit message for easier review.

Troubleshooting strategy
------------------------

* If a peripheral is silent, verify gate clocks and reset bits first.
* If flags never set, confirm trigger sources and interrupt routing.
* If timing is off, revisit prescalers and upstream source clocks.

Team convention
---------------

When documenting low-level code, cite chapter/section names so future readers can quickly locate the same rules in the manual revision used.
