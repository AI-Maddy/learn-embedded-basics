# Debugging Docs

Quick navigation for embedded debugging workflows.

## Guides
- `gdb-basics.md`: day-to-day GDB commands and embedded sessions.
- `jtag-swd.md`: hardware debug interface wiring and diagnostics.
- `openocd.md`: OpenOCD setup, server flow, and troubleshooting.

## Suggested Order
1. `jtag-swd.md`
2. `openocd.md`
3. `gdb-basics.md`

## Quick Bring-Up Debug Flow
1. Confirm physical connection and target voltage.
2. Start debug server (OpenOCD or vendor server).
3. Attach GDB and halt at reset.
4. Load firmware and break at `main`.
5. Step into suspect module and inspect registers.

## Failure Triage Checklist
- No connect: check wiring, probe permissions, target power.
- No breakpoints: verify symbols and optimization level.
- Random resets: inspect watchdog, clock init, vector table.
- Peripheral dead: verify clock-enable and pin mux registers.

## Good Debug Session Outcome
- Reproducible steps documented.
- Root cause identified with register evidence.
- Fix validated with a rerun of the same debug script.
