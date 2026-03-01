# Learning Path

This roadmap helps you move from beginner to confident baremetal developer with practical milestones.

## Phase 1: Core Foundations (Week 1-2)
Focus:
- C fundamentals for embedded (pointers, bitwise ops, structs)
- Number systems (hex/binary), endianness, and memory basics
- Basic digital electronics (voltage, pull-up/down, debounce)

Milestone:
- Explain how a GPIO register write toggles an LED.

## Phase 2: Baremetal Bring-Up (Week 3-4)
Focus:
- Startup code and vector tables
- Clock initialization and reset flow
- Memory-mapped I/O and register access patterns

Practice:
- Bring up LED blink and UART banner from reset.

Milestone:
- Build + flash a minimal firmware without vendor HAL.

## Phase 3: Peripheral Mastery (Week 5-7)
Focus:
- Timers, PWM, interrupts, UART, SPI, I2C, ADC
- Polling vs interrupt-driven design
- Error handling and timeout patterns

Practice:
- Read sensor over I2C and print via UART.
- Generate PWM and verify on oscilloscope.

Milestone:
- Build a small multi-peripheral app with stable timing.

## Phase 4: Tooling and Debugging (Week 8-9)
Focus:
- GDB breakpoints/watchpoints
- OpenOCD + JTAG/SWD workflows
- Fault triage using registers and call stacks

Practice:
- Diagnose a forced hard fault and identify root cause.

Milestone:
- Debug startup failure and patch it confidently.

## Phase 5: Architecture and Portability (Week 10-12)
Focus:
- Driver layering and hardware abstraction boundaries
- Linker scripts and memory section control
- Code organization for multi-MCU projects

Practice:
- Port one driver across two MCU families.

Milestone:
- Reuse same application logic on two boards with minimal changes.

## Suggested Weekly Routine
- 3 days coding labs
- 1 day datasheet deep reading
- 1 day debugging challenge + write-up

## Progress Checklist
- [ ] I can read/write registers without confusion.
- [ ] I can configure one timer and one interrupt.
- [ ] I can flash and debug with GDB/OpenOCD.
- [ ] I can explain startup + linker basics.
- [ ] I can implement and test a driver API.

## Where to Learn in This Repo
- Peripheral practice: `peripherals/`
- Driver structure: `drivers/`
- Board-specific context: `mcu-profiles/`
- Setup/debug docs: `docs/toolchain-setup/`, `docs/debugging/`
