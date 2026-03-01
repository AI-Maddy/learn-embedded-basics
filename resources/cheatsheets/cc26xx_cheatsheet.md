# CC26xx Baremetal Startup Cheat Sheet

🚀 **Getting Started with CC26xx (e.g., CC2650)**

## 1. Clock Setup
- System clock is set by `SysCtrlClockSet()`.

## 2. Stack Pointer
- Set by startup file (linker script).

## 3. GPIO Configuration
```c
GPIO_setOutputEnableDio(6, GPIO_OUTPUT_ENABLE); // Set DIO6 as output
```

## 4. Peripheral Enable
- Enable clocks for peripherals as needed.

## 5. Interrupts
```c
IntMasterEnable(); // Enable global interrupts
```

## 6. Main Loop
```c
while (1) {
    // Application code
}
```

## 7. Minimal Startup Flow
1. Configure system clock
2. Initialize GPIO and peripherals
3. Enable interrupts (if needed)
4. Enter main loop

---
🧠 **Tip:** Use TI DriverLib for register access. Check datasheet for pin mapping.

## Bring-Up Flow
1. Confirm power/clock domain readiness.
2. Bring up one DIO output and verify active level.
3. Add interrupt-driven behavior after polling validation.

## Validation Checklist
- DIO mapping matches board revision.
- Pull configuration produces stable button reads.
- Interrupt flags are cleared in expected order.

## Common Pitfalls
- GPIO path disabled by low-power configuration.
- Incorrect active-high/active-low assumptions.
- Skipping IOC configuration details for edge sensing.
