# Peripherals Index

This folder contains theory, registers, and implementation examples for each peripheral group.

## Peripheral Groups
- `adc/`, `dac/`, `gpio/`, `i2c/`, `interrupts/`, `pwm/`, `radio/`, `spi/`, `timers/`, `uart/`

## Typical Structure
- conceptual docs (`README.md`, theory/register notes)
- practical examples in family-specific files
- optional `source/` for reusable implementation snippets

## Learning Flow
1. Read peripheral theory docs.
2. Study register descriptions.
3. Run family-specific examples.
4. Integrate with `drivers/` abstractions.

## Validation Flow
1. Start with polling-mode smoke test.
2. Add interrupt or DMA path.
3. Validate timing on analyzer/scope.
4. Add timeout and error-path checks.

## Common Pitfalls
- Missing peripheral clock enable.
- Wrong pin mux/alternate function.
- Improper interrupt flag clearing.
- Overlooking startup/reset defaults.

Use this folder as the implementation bridge between conceptual docs and reusable `drivers/` interfaces.
