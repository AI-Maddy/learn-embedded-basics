Datasheets
==========

Repository for official device datasheets.

Store guidance
--------------

* Keep vendor + part number in filenames.
* Preserve revision information when relevant.
* Prefer original PDF sources from vendor portals.

Use checklist
-------------

1. Confirm electrical limits before wiring.
2. Confirm pin and alternate-function mapping.
3. Confirm reset values for registers you touch.

Quality checks
--------------

* Prefer newest official revision unless constrained.
* Keep part-number variants separated clearly.
* Record source URL in commit notes when adding files.

Bring-up priority sections
--------------------------

* Absolute maximum ratings and recommended operating conditions
* Power sequencing and decoupling guidance
* GPIO electrical characteristics and drive limits
* Oscillator and clock source requirements

Review workflow
---------------

1. Extract critical constraints before schematic capture.
2. Confirm pin-level functions against package-specific tables.
3. Re-check peripheral limits before writing driver defaults.
4. Validate expected current and thermal limits for target environment.

Common failures prevented by this process
-----------------------------------------

* Incorrect I/O voltage domain assumptions
* Miswired boot/configuration pins
* Overdriven outputs exceeding sink/source capability
* Clock source mismatches causing unstable timing
