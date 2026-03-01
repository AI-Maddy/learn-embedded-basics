# OpenOCD

OpenOCD (Open On-Chip Debugger) connects debug probes to target MCUs and bridges them to GDB.

## What OpenOCD Does
- Talks to hardware probe (ST-Link, J-Link, CMSIS-DAP, etc.)
- Initializes target (reset/halt/flash operations)
- Exposes GDB server (`localhost:3333` by default)

## Basic Command Pattern
```bash
openocd -f interface/<probe>.cfg -f target/<target>.cfg
```

## Example (STM32 + ST-Link)
```bash
openocd -f interface/stlink.cfg -f target/stm32f1x.cfg
```

## Typical End-to-End Flow
1. Start OpenOCD with correct interface/target config.
2. Open GDB with ELF file.
3. Connect GDB to OpenOCD (`target remote :3333`).
4. Reset/halt, load firmware, break at `main`, run.

## Useful OpenOCD Console Commands
From telnet (`localhost 4444`) or startup script:
```text
reset halt
flash write_image erase build/firmware.elf
verify_image build/firmware.elf
resume
```

## Logging and Diagnostics
- Increase verbosity:
```bash
openocd -d3 -f interface/stlink.cfg -f target/stm32f1x.cfg
```
- Watch for:
	- target voltage errors
	- cannot identify core
	- timed out while waiting for target halt

## Common Issues + Fixes
- **Config file not found**: verify OpenOCD scripts path/install.
- **Permission denied on USB probe**: add udev rules on Linux.
- **Target not halted**: try reset strategy change or connect under reset.
- **Flash verify mismatch**: ensure correct target config and memory map.

## Minimal GDB Pairing Snippet
```gdb
target remote :3333
monitor reset halt
load
b main
c
```

## Best Practices
- Keep a board-specific OpenOCD launch script in your project.
- Lock probe/target config in version control for team consistency.
- Use known-good reset sequence when debugging early startup failures.
