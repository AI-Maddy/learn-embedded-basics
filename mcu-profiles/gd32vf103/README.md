# GD32VF103 Profile

## MCU Snapshot
- Core: 32-bit RISC-V MCU
- Best for: learning RISC-V baremetal and general embedded control
- Common board: Longan Nano class boards

## Baremetal Startup Order
1. Run startup/system init and set core clock
2. Enable peripheral clocks via RCU
3. Configure GPIO modes and default states
4. Configure timer/UART/EXTI according to app
5. Enable interrupts and enter superloop

## Toolchain
- `riscv-none-elf-gcc` toolchain
- Linker script defines flash/RAM placement

## Flash + Debug
- Typical debug: JTAG/SWD-compatible probe depending on board
- Flash using board tooling or OpenOCD workflows

## Pin/Peripheral Priorities
- RCU clock enable before peripheral register access
- EXTI mapping must match selected port/pin
- UART first for runtime diagnostics

## Bring-Up Checklist
- Blink test on board LED pin
- UART baud confirmed with terminal
- External interrupt toggles output reliably
- Timer tick interval measured and stable

## References in Repo
- Peripheral docs: `peripherals/gpio`, `peripherals/timers`, `peripherals/uart`
- Driver skeletons: `drivers/*`