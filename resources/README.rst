Resources
=========

Central library of reference material used during embedded firmware bring-up.

What this folder contains
-------------------------

* ``cheatsheets/``: quick-start notes per MCU family
* ``datasheets/``: vendor datasheets for devices and peripherals
* ``pinouts/``: package and board pin mappings
* ``reference-manuals/``: register-level architecture references
* ``timing-diagrams/``: protocol timing visuals and waveform guides

Recommended usage flow
----------------------

1. Start with the MCU cheatsheet.
2. Confirm electrical and pin constraints from datasheet.
3. Use reference manual while implementing registers.
4. Validate bus behavior with timing diagrams.

Related project areas
---------------------

* ``docs/`` for deeper explanations
* ``drivers/`` for portable driver skeletons
* ``mcu-profiles/`` for per-device bring-up guidance

Practical checklist
-------------------

1. Pick MCU family cheatsheet first.
2. Confirm pin and electrical constraints from datasheet.
3. Validate register-level sequence in reference manual.
4. Cross-check measured waveforms with timing diagrams.

Common mistakes
---------------

* Using board pin labels without checking MCU package mapping.
* Skipping errata notes for silicon-specific behavior.
* Mixing references from a different part number/revision.
