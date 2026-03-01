# GDB Basics

This guide covers practical GDB commands and workflow for embedded baremetal projects.

## Typical Embedded Debug Flow
1. Build firmware with debug symbols (`-g`) and low optimization (`-O0` or `-Og`).
2. Start debug server (OpenOCD or vendor server).
3. Start GDB with your ELF file.
4. Connect to target, load firmware, set breakpoints.
5. Run, inspect registers/memory, step through code.

## Launch GDB
```bash
arm-none-eabi-gdb build/firmware.elf
```

## Essential Startup Commands
```gdb
target remote :3333
monitor reset halt
load
break main
continue
```

## Core Commands You Will Use Daily
- `break <symbol|file:line>`: set breakpoint
- `info breakpoints`: list breakpoints
- `delete <n>`: remove breakpoint by index
- `next`: step over
- `step`: step into
- `finish`: run until current function returns
- `continue`: resume execution
- `backtrace`: show call stack
- `info locals`: inspect local variables
- `print <expr>`: evaluate expression
- `x/<format> <addr>`: inspect memory

## Useful Memory/Register Commands
```gdb
info registers
x/16wx 0x20000000
set var counter = 0
watch sensor_value
```

## Breakpoint Strategies for Firmware
- Break at `main` first to confirm startup is sane.
- Add breakpoint in ISR entry when debugging interrupts.
- Use watchpoints on critical globals (state machine vars, flags).
- Prefer conditional breakpoints for fast loops.

## Troubleshooting
- **No symbols shown**: verify build uses `-g` and correct ELF.
- **Cannot connect target**: check debug server and port.
- **Breakpoints not hit**: ensure code is loaded and not optimized out.
- **Stepping looks odd**: reduce optimization to `-Og` or `-O0`.

## Quick Session Template
```gdb
target remote :3333
monitor reset halt
load
b main
c
```

## Pro Tips
- Use `layout src` (if enabled) for source view in terminal GDB.
- Save repetitive commands in `.gdbinit`.
- Keep map file and ELF together for faster issue triage.
