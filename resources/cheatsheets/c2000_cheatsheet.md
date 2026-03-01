# C2000 Baremetal Startup Cheat Sheet

🚀 **Getting Started with C2000 (F28027 Example)**

## 1. Clock Setup
- Call `InitSysCtrl()` to configure system clock.

## 2. Stack Pointer
- Set by startup code (linker script).

## 3. GPIO Configuration
```c
EALLOW;
GpioCtrlRegs.GPADIR.bit.GPIO0 = 1; // Set GPIO0 as output
EDIS;
```

## 4. Peripheral Enable
- Enable peripheral clocks in `PCLKCRx` registers.

## 5. Interrupts
```c
EINT; // Enable global interrupts
```

## 6. Main Loop
```c
while (1) {
    // Application code
}
```

## 7. Minimal Startup Flow
1. Call `InitSysCtrl()`
2. Initialize GPIO and peripherals
3. Enable interrupts (if needed)
4. Enter main loop

---
🧠 **Tip:** Use EALLOW/EDIS for protected register access. Refer to TI header files.

## Bring-Up Flow
1. Initialize system clock and disable watchdog as needed.
2. Verify one GPIO output before enabling control peripherals.
3. Add interrupts only after baseline polling path is stable.

## Validation Checklist
- EALLOW/EDIS access windows are minimal and correct.
- GPIO mux configuration matches target pin function.
- PIE interrupt acknowledge sequence is verified.

## Common Pitfalls
- Writing protected registers outside EALLOW region.
- Incorrect GPIO mux selection for peripheral route.
- Missing PIE ACK causing repeated ISR entry.
