# RP2040 Baremetal Startup Cheat Sheet

🚀 **Getting Started with RP2040 (Raspberry Pi Pico)**

## 1. Clock Setup
- Clocks are set up by bootrom and SDK startup code.

## 2. Stack Pointer
- Set by startup code (linker script).

## 3. GPIO Configuration
```c
gpio_init(25);
gpio_set_dir(25, GPIO_OUT); // Set GPIO25 as output
```

## 4. Peripheral Enable
- Most peripherals enabled by default.

## 5. Interrupts
```c
enable_irq(); // Enable global interrupts (SDK)
```

## 6. Main Loop
```c
while (1) {
    // Application code
}
```

## 7. Minimal Startup Flow
1. Clocks and stack set by SDK
2. Initialize GPIO and peripherals
3. Enable interrupts (if needed)
4. Enter main loop

---
🧠 **Tip:** Use Pico SDK for easy startup. Check datasheet for pin mapping.

## Bring-Up Flow
1. Confirm board definition and LED/button pin map.
2. Validate GPIO output toggle in minimal loop.
3. Add interrupt callbacks only after polling path is stable.

## Validation Checklist
- IO bank function selection matches intended use.
- Pull-up/down settings produce deterministic input reads.
- Callback and IRQ behavior remains non-blocking.

## Common Pitfalls
- Wrong board pin mapping assumptions.
- Blocking work inside GPIO interrupt callbacks.
- Mixing SDK helper behavior with raw register expectations.
