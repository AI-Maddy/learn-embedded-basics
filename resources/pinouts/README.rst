Pinouts
=======

Pin mapping references for MCUs and boards.

What to include
---------------

* MCU package pin maps
* Board header maps
* Peripheral default pin mappings
* Debug connector pin references

Validation tips
---------------

* Cross-check against datasheet and board revision.
* Reserve boot/debug pins early in design.
* Mark voltage-domain-sensitive pins clearly.

Quality checks
--------------

* Include both MCU pin name and board header name.
* Note active-low labels explicitly.
* Highlight pins shared by multiple peripherals.

Board bring-up checklist
------------------------

1. Mark power, ground, reset, and clock pins before assigning peripherals.
2. Reserve SWD/JTAG/UART debug pins to avoid lockout.
3. Confirm boot strap pins have safe default pull states.
4. Verify alternate-function mapping against the exact package variant.

Documentation convention
------------------------

* Keep one canonical pinout sheet per board revision.
* Record net names used in schematic for cross-reference.
* Include a short "do-not-use" list for restricted pins.

Troubleshooting clues
---------------------

If a peripheral appears dead, first inspect mux setup and whether the expected alternate function is physically routed to that header/pad on the chosen package.
