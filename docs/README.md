# Docs Index

Central index for conceptual guides, debugging workflows, and toolchain setup.

## Core Concepts
- `datasheet-reading.md`
- `learning-path.md`
- `linker-scripts.md`
- `memory-mapped-io.md`
- `startup-code.md`

Use this section when you need conceptual clarity before touching code.

## Debugging
- `debugging/gdb-basics.md`
- `debugging/jtag-swd.md`
- `debugging/openocd.md`

Use this section for runtime triage, fault analysis, and probe setup.

## Toolchain Setup
- `toolchain-setup/arm-gcc-openocd-setup.md`
- `toolchain-setup/avr-gcc-setup.md`
- `toolchain-setup/cc26xx-driverlib-setup.md`
- `toolchain-setup/msp430-gcc-setup.md`
- `toolchain-setup/nrf52-baremetal-setup.md`
- `toolchain-setup/pic-mplabx-setup.md`
- `toolchain-setup/risc-v-toolchain-setup.md`
- `toolchain-setup/rp2040-sdk-setup.md`

Use this section when onboarding a new board, machine, or MCU family.

## Suggested Learning/Execution Order
1. Start with `learning-path.md`.
2. Read `startup-code.md` + `linker-scripts.md` together.
3. Complete one toolchain setup for your target.
4. Follow debugging docs to validate your first firmware.

## Documentation Quality Rules
- Every page should include: purpose, workflow, common failures, and verification checks.
- Prefer actionable commands and checklists over generic descriptions.
- Keep cross-links to related repo folders for fast context switching.
