# 📙 STM32F1 GPIO Registers

STM32F1 MCUs have powerful, flexible GPIOs for advanced applications.

## 🗂️ Key Registers
- **GPIOx_CRL/CRH**: Pin mode/config
- **GPIOx_IDR/ODR**: Input/output data
- **GPIOx_BSRR/BRR**: Bit set/reset
- **GPIOx_LCKR**: Pin lock

## 🧠 Tips
- Use CRL/CRH for pin mode (input/output/AF)
- BSRR/BRR for atomic pin changes
- LCKR to lock pin config

---

✨ *STM32F1: Industrial-grade GPIOs!*

🔑 **Mnemonic:** "C**R**L/**C**R**H: **C**onfigure **R**ight, **L**ock/**H**old!"

## ✅ Register Bring-Up Sequence
1. Enable RCC clock for target GPIO port.
2. Configure mode in `CRL/CRH`.
3. Use `BSRR/BRR` for atomic set/reset.

## 🔍 Validation Checklist
- Pin mode bits match intended role.
- IDR/ODR behavior matches expected logic.
- EXTI mapping and pending clear are correct.

## ⚠️ Common Pitfalls
- Missing APB2 clock enable before register access.
- Incorrect CNF/MODE combination for input/output.