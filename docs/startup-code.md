# Startup Code

Startup code runs immediately after reset and prepares memory/runtime before `main()` executes.

## Responsibilities of Startup Code
- Set initial stack pointer
- Set vector table and reset handler entry
- Initialize `.data` and clear `.bss`
- Optionally configure early clock/watchdog behavior
- Call C runtime init functions, then `main`

## Typical Reset Sequence
1. CPU fetches reset vector address
2. Reset handler runs (assembly/C startup)
3. Copy initialized data from flash to RAM
4. Zero uninitialized data (`.bss`)
5. Run static constructors (if C++)
6. Branch to `main`

## Why It Matters
- If startup is wrong, firmware fails before application code.
- Debugging startup requires understanding linker symbols and vector layout.

## Common Startup Symbols
These are usually provided by linker script:
- `_sidata`: source of initialized data in flash
- `_sdata` / `_edata`: destination range in RAM
- `_sbss` / `_ebss`: zero-init range in RAM
- `_estack`: initial stack top

## Minimal Pseudocode
```c
void Reset_Handler(void) {
	copy_data_from_flash_to_ram();
	zero_bss();
	system_init();
	main();
	while (1) {}
}
```

## Interrupt Vector Table Notes
- Must be located at expected boot address.
- Handlers should be weak-aliased to default handlers initially.
- Wrong table placement causes random handler jumps.

## Common Failure Modes
- Hard fault before `main`
- Global variables not initialized correctly
- Interrupts landing in default handler
- Stack pointer pointing outside valid RAM

## Startup Debug Steps
1. Break at reset handler.
2. Inspect stack pointer and vector table base.
3. Verify `.data` copy loop boundaries.
4. Verify `.bss` clear loop boundaries.
5. Step into `main` and inspect key globals.

## Best Practices
- Keep startup file short and deterministic.
- Document any clock/watchdog changes done before `main`.
- Keep linker script and startup symbols synchronized.

## Related Docs
- `docs/linker-scripts.md`
- `docs/memory-mapped-io.md`
- `docs/debugging/gdb-basics.md`
