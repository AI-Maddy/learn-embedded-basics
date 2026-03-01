# AVR Baremetal Startup Cheat Sheet

🚀 **Getting Started with AVR (ATmega328P Example)**

## 1. Clock Setup
- Default internal RC oscillator is used after reset.
- For external crystal: set fuse bits and configure `CLKPR` if needed.

## 2. Stack Pointer
- Automatically initialized after reset.

## 3. GPIO Configuration
```c
DDRB |= (1 << DDB5); // Set PB5 as output
PORTB |= (1 << PORTB5); // Set PB5 high
```

## 4. Peripheral Enable
- Enable modules by setting bits in PRR (Power Reduction Register) if needed.

## 5. Interrupts
```c
sei(); // Enable global interrupts
```

## 6. Main Loop
```c
while (1) {
    // Application code
}
```

## 7. Minimal Startup Flow
1. Set up stack (done by hardware)
2. Configure clocks (if needed)
3. Initialize GPIO and peripherals
4. Enable interrupts (if needed)
5. Enter main loop

---
🧠 **Tip:** Use datasheet for register details. Fuses must be set for clock source.

## Bring-Up Flow
1. Confirm clock source and fuse assumptions.
2. Configure one LED GPIO as first hardware proof.
3. Bring up one peripheral at a time with register readback.

## Validation Checklist
- Blink timing matches expected clock configuration.
- GPIO direction/pull settings match schematic intent.
- Interrupt enable is done after source configuration.

## Common Pitfalls
- Wrong fuse configuration causing unexpected CPU clock.
- Floating button inputs due to missing pull-up/down.
- Mixing register names across AVR subfamilies.
