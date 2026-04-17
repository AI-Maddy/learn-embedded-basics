# :material-bug: Embedded Debugging

!!! abstract "What You'll Learn"
    - Use GDB + OpenOCD for source-level debugging
    - Set breakpoints, inspect registers, and step through code
    - Use JTAG/SWD for flashing and real-time debug

---

## :material-lightbulb-on: Intuition

!!! info "Embedded Debugging Mental Model"
    You have three windows into the hardware: **GDB** (software state), **logic analyser** (bus traffic), and **oscilloscope** (analog signals). Learn to use all three.

---

## :material-vector-polyline: Diagram

```mermaid
flowchart LR
    GDB["GDB Client
(source-level debug)"] <-->|"RSP protocol
tcp:3333"| OpenOCD["OpenOCD
(debug server)"]
    OpenOCD <-->|"JTAG/SWD"| Probe["Debug Probe
(ST-Link, J-Link)"]
    Probe <-->|"SWD pins
SWDIO, SWDCLK"| MCU["Target MCU"]
```

---

## :material-code-tags: Code Examples

=== "GDB Quick Reference"
    ```bash
    # Connect GDB to OpenOCD
    arm-none-eabi-gdb firmware.elf
    (gdb) target remote :3333
    (gdb) monitor reset halt   # reset and halt at reset vector

    # Breakpoints
    (gdb) break main           # break at function
    (gdb) break gpio.c:42      # break at file:line
    (gdb) watch *0x40010C0C    # break on register write

    # Stepping
    (gdb) continue    # run until breakpoint
    (gdb) next        # step over (source line)
    (gdb) step        # step into
    (gdb) finish      # run until function returns

    # Inspect
    (gdb) print variable
    (gdb) x/4wx 0x40010800    # read 4 words from address
    (gdb) info registers       # all CPU registers
    ```

=== "Hard Fault Debugging"
    ```c
    // Hard fault handler to capture CPU state
    void HardFault_Handler(void) {
        __asm volatile (
            "tst lr, #4
"
            "ite eq
"
            "mrseq r0, msp
"
            "mrsne r0, psp
"
            "b HardFault_HandlerC
"
        );
    }
    void HardFault_HandlerC(uint32_t *sp) {
        // sp[0]=r0, sp[1]=r1, sp[2]=r2, sp[3]=r3
        // sp[4]=r12, sp[5]=lr, sp[6]=pc, sp[7]=xpsr
        uint32_t pc = sp[6]; // fault address
        while (1); // breakpoint here, inspect pc
    }
    ```

---

## :material-alert: Pitfalls

!!! warning "Common Mistakes"
    - OpenOCD must be running before GDB connects
    - Hard faults with garbage PC usually mean stack overflow or corrupted vector table

---

## :material-help-circle: Flashcards

???+ question "What does SWD stand for and what pins does it use?"
    **Serial Wire Debug** — uses 2 pins: SWDIO (data) and SWDCLK (clock). Lower pin count than JTAG's 4+ pins.

???+ question "How to find a hard fault cause without a debugger?"
    Toggle a GPIO before each major code section. The last toggled LED tells you where the fault occurred.

???+ question "What is ITM (Instrumentation Trace Macrocell)?"
    A hardware debug channel on Cortex-M3/M4. Allows printf-style output via SWO pin without UART. Zero overhead compared to UART debug.

---

## :material-check-circle: Summary

Debugging: GDB + OpenOCD + debug probe. Key commands: break, watch, print, x. Hard fault: capture stacked PC. SWD = 2-pin debug interface.
