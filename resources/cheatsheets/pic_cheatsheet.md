# PIC Baremetal Startup Cheat Sheet

🚀 **Getting Started with PIC16F877A**

## 1. Clock Setup
- Set oscillator type in configuration bits (fuses).

## 2. Stack Pointer
- Managed by hardware.

## 3. GPIO Configuration
```c
TRISD0 = 0; // Set RD0 as output
PORTD = 0;  // Clear PORTD
```

## 4. Peripheral Enable
- Enable modules by clearing bits in `PCON` or `PIE` registers.

## 5. Interrupts
```c
GIE = 1; // Enable global interrupts
```

## 6. Main Loop
```c
while (1) {
    // Application code
}
```

## 7. Minimal Startup Flow
1. Set configuration bits (oscillator, watchdog, etc.)
2. Initialize GPIO and peripherals
3. Enable interrupts (if needed)
4. Enter main loop

---
🧠 **Tip:** Use MPLAB X IDE to set config bits. Check TRIS/PORT registers for I/O.

## Bring-Up Flow
1. Set config bits and oscillator assumptions first.
2. Validate one output pin and one input pin path.
3. Add interrupt sources after stable GPIO behavior.

## Validation Checklist
- TRIS/PORT usage is correct for each pin direction.
- Analog-capable pins are forced to digital where needed.
- GIE/PEIE and source bits are set in proper sequence.

## Common Pitfalls
- Leaving pins in analog mode when digital is expected.
- Misconfigured oscillator bits affecting timing math.
- Not clearing interrupt flags before ISR exit.
