# MSP430 Baremetal Startup Cheat Sheet

🚀 **Getting Started with MSP430G2553**

## 1. Clock Setup
- DCO (Digitally Controlled Oscillator) runs by default.
- For external crystal, configure `BCSCTLx` registers.

## 2. Stack Pointer
- Set by startup code.

## 3. GPIO Configuration
```c
P1DIR |= 0x01; // Set P1.0 as output
```

## 4. Peripheral Enable
- Most peripherals enabled by default.

## 5. Interrupts
```c
__bis_SR_register(GIE); // Enable global interrupts
```

## 6. Main Loop
```c
while (1) {
    // Application code
}
```

## 7. Minimal Startup Flow
1. Configure clocks (if needed)
2. Initialize GPIO and peripherals
3. Enable interrupts (if needed)
4. Enter main loop

---
🧠 **Tip:** Use Code Composer Studio or Energia for quick start. Check datasheet for pin mapping.

## Bring-Up Flow
1. Stop watchdog early in startup.
2. Configure one GPIO output and verify expected polarity.
3. Add port interrupts after stable input reads.

## Validation Checklist
- Watchdog does not reset application during bring-up.
- PxDIR/PxOUT/PxREN settings match intent.
- IFG flags are cleared correctly in ISR path.

## Common Pitfalls
- Forgetting watchdog disable/service during debug.
- Incorrect pull resistor direction configuration.
- Doing heavy processing inside ISR routines.
