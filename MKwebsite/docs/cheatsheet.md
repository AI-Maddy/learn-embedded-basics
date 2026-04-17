# :material-table: Embedded Quick Reference

## :material-chip: Register Bit Operations

```c
/* Set bit N */      REG |=  (1u << N);
/* Clear bit N */    REG &= ~(1u << N);
/* Toggle bit N */   REG ^=  (1u << N);
/* Read bit N */     bool b = (REG >> N) & 1u;
/* Write field */    REG = (REG & ~MASK) | (value << SHIFT);
/* Atomic set */     GPIO->BSRR = (1u << N);        // set
/* Atomic clear */   GPIO->BSRR = (1u << (N + 16)); // reset
```

---

## :material-memory: Typical ARM Cortex-M Memory Map

| Address Range | Region |
|--------------|--------|
| 0x00000000–0x1FFFFFFF | Code (flash, ROM) |
| 0x20000000–0x3FFFFFFF | SRAM |
| 0x40000000–0x5FFFFFFF | Peripheral registers (APB, AHB) |
| 0xE0000000+ | System (NVIC, SysTick, DWT) |

---

## :material-timer: Peripheral Init Checklist

!!! info "Universal Peripheral Init Order"
    1. Enable **peripheral clock** (RCC/CMU/CLK register)
    2. Configure **GPIO** pins (mode, AF, pull, speed)
    3. Configure **peripheral** registers (baud, mode, etc.)
    4. Enable **interrupts** if needed (peripheral IE + NVIC)
    5. **Start** the peripheral (UE/EN bit)

---

## :material-serial-port: UART Baud Rate Formula

```
BRR = PCLK_Hz / baud_rate

Example: 72MHz / 115200 = 625
```

---

## :material-sine-wave: PWM Period & Duty

```
Timer frequency = PCLK / (PSC + 1)
PWM period      = Timer freq / (ARR + 1)
Duty cycle      = CCR / (ARR + 1) × 100%
```

---

## :material-bug: Common Embedded Bugs

| Symptom | Likely Cause |
|---------|-------------|
| Hard fault on reset | Missing peripheral clock, wrong stack pointer |
| GPIO doesn't toggle | Peripheral clock not enabled |
| UART garbage output | Wrong baud rate, missing pin AF config |
| I2C hangs | Missing pull-up resistors, wrong device address |
| ADC reads 0 or 4095 always | Wrong reference, analog pin configured as digital |
| Timer ISR fires too fast/slow | PSC/ARR formula error |
| Global variable has wrong value | .data not copied from flash (startup bug) |

---

## :material-table-key: GPIO Mode Bits (STM32F4+)

| MODER | Mode | OTYPER | Type |
|-------|------|--------|------|
| 00 | Input | 0 | Push-pull |
| 01 | Output | 1 | Open-drain |
| 10 | Alternate function | | |
| 11 | Analog | | |
