# STM32F1 Baremetal Startup Cheat Sheet

🚀 **Getting Started with STM32F103 (Blue Pill Example)**

## 1. Clock Setup
- System clock set by `SystemInit()` and `RCC` registers.

## 2. Stack Pointer
- Set by startup code (linker script).

## 3. GPIO Configuration
```c
RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
GPIOC->CRH |= GPIO_CRH_MODE13_0; // PC13 output
```

## 4. Peripheral Enable
- Enable clocks for peripherals in `RCC->APB2ENR`.

## 5. Interrupts
```c
__enable_irq(); // Enable global interrupts
```

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
🧠 **Tip:** Use STM32CubeMX for clock tree. Check datasheet for pin mapping.

## Bring-Up Flow
1. Enable RCC clocks for GPIO and AFIO first.
2. Validate one output pin with known polarity.
3. Add EXTI routing and IRQ enable after baseline checks.

## Validation Checklist
- CRL/CRH mode bits match intended pin function.
- AFIO EXTI mapping is correct for chosen input port.
- Pending flags clear correctly in interrupt handler.

## Common Pitfalls
- Forgetting AFIO clock before EXTI mapping writes.
- Using wrong input mode (floating vs pull-up/down).
- Incorrect IRQ priority assumptions for concurrent sources.
