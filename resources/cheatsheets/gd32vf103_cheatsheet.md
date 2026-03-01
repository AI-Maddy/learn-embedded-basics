# GD32VF103 Baremetal Startup Cheat Sheet

🚀 **Getting Started with GD32VF103 (Longan Nano Example)**

## 1. Clock Setup
- System clock set by `rcu_periph_clock_enable()` and `SystemInit()`.

## 2. Stack Pointer
- Set by startup code (linker script).

## 3. GPIO Configuration
```c
gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13); // PC13 output
```

## 4. Peripheral Enable
- Enable clocks for peripherals using `rcu_periph_clock_enable()`.

## 5. Interrupts
- Enable NVIC and EXTI as needed.

## 6. Main Loop
```c
while (1) {
    // Application code
}
```

## 7. Minimal Startup Flow
1. Call `SystemInit()`
2. Enable peripheral clocks
3. Initialize GPIO and peripherals
4. Enable interrupts (if needed)
5. Enter main loop

---
🧠 **Tip:** Use GigaDevice header files. Check board schematic for pinout.

## Bring-Up Flow
1. Enable RCU clocks for each port/peripheral in use.
2. Validate one GPIO output transition on scope.
3. Add EXTI configuration after basic I/O checks pass.

## Validation Checklist
- Clock-enable sequence precedes register access.
- Input pull mode is explicit for every button pin.
- EXTI mapping and pending-flag clear are verified.

## Common Pitfalls
- Accessing GPIO before clock enable.
- Incorrect EXTI source-to-port mapping.
- Port mode/speed settings not matching board load.
