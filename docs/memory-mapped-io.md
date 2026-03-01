# Memory-Mapped IO

Memory-mapped I/O means peripheral registers are accessed like memory addresses. You read/write registers with normal load/store operations.

## Core Idea
- CPU sees peripherals as address ranges.
- Register writes configure hardware behavior.
- Register reads return peripheral state/flags.

## Example Pattern (C)
```c
#define GPIOA_BASE 0x40020000u
#define GPIOA_ODR  (*(volatile unsigned int *)(GPIOA_BASE + 0x14u))

void led_on(void) {
	GPIOA_ODR |= (1u << 5);
}
```

`volatile` is required so compiler does not optimize away hardware access.

## Typical Register Categories
- Control registers (mode/config bits)
- Status registers (flags, readiness)
- Data registers (TX/RX/data values)
- Interrupt registers (enable/pending/clear)

## Read-Modify-Write Caution
Many operations need safe bit updates:
1. read register value
2. mask/modify target bits
3. write back

Use dedicated set/clear registers when available to avoid race issues.

## Access Type Semantics You Must Respect
- `RO`: read-only
- `RW`: normal read/write
- `W1C`: write 1 to clear flag
- `RC`: read clears flag (less common)

Misusing access type can break interrupt logic.

## Ordering and Barriers
On some architectures, memory barriers are needed around critical peripheral operations.
Use vendor-recommended barrier instructions/macros when dealing with:
- clock switching
- interrupt controller state
- DMA control updates

## Debug Checklist for MMIO Bugs
- Is peripheral clock enabled?
- Is pin mux/alternate function configured?
- Is register address for correct MCU variant?
- Are reserved bits preserved during writes?
- Are flags cleared with correct semantics?

## Common Pitfalls
- Missing `volatile`
- Wrong base address from a different MCU family
- Writing register fields before peripheral ready flag
- Ignoring reset value assumptions

## Best Practices
- Keep register definitions centralized in headers
- Prefer named masks/shifts over magic numbers
- Validate important register writes with debugger/watch window

## Related Docs
- `docs/datasheet-reading.md`
- `docs/startup-code.md`
- `docs/linker-scripts.md`
