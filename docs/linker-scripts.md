# Linker Scripts

Linker scripts define where code and data live in memory. In embedded systems, they are essential for correct boot and runtime behavior.

## What a Linker Script Controls
- Flash and SRAM memory regions
- Placement of `.text`, `.rodata`, `.data`, `.bss`, stack, heap
- Vector table location
- Symbol exports for startup code (`_sidata`, `_sdata`, `_edata`, `_sbss`, `_ebss`)

## Typical Memory Layout
- **Flash**: vector table, code, constants
- **SRAM**: initialized data, zeroed data, stack, heap

Example concept:
- Copy `.data` from Flash to SRAM on boot
- Zero `.bss` before entering `main`

## Minimal Script Skeleton
```ld
MEMORY {
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
	RAM   (rwx): ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS {
	.isr_vector : { KEEP(*(.isr_vector)) } > FLASH
	.text       : { *(.text*) *(.rodata*) } > FLASH
	.data       : { *(.data*) } > RAM AT > FLASH
	.bss        : { *(.bss*) *(COMMON) } > RAM
}
```

## Startup Code + Linker Script Relationship
Startup uses linker symbols to:
- know where `.data` initial values are stored in flash
- know where to copy `.data` in RAM
- know `.bss` range to clear

If symbols are wrong, firmware may crash before `main`.

## Common Mistakes
- Wrong flash origin for board/bootloader offset
- Stack/heap overlapping `.bss` silently
- Missing `KEEP()` for vector table or init arrays
- Incorrect alignment for sections
- Forgetting `AT > FLASH` for `.data`

## Practical Verification
- Inspect map file after each linker change
- Confirm section sizes fit memory regions
- Verify vector table address matches boot expectations
- Check `_estack` symbol and actual RAM size

## Debug Symptoms of Linker Problems
- Hard fault immediately after reset
- Breakpoint at `main` never reached
- Global variables with random values
- Interrupts jump to default handler

## Best Practices
- Keep linker script version-controlled per MCU family
- Document any bootloader offset clearly
- Add CI check for map size regressions if possible

## Related Docs
- `docs/startup-code.md`
- `docs/memory-mapped-io.md`
- `docs/datasheet-reading.md`
