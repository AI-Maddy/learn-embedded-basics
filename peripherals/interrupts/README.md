# ⚡ Interrupts Peripheral Overview

🚨 **Interrupts**

Interrupts let your MCU react instantly to events—no more waiting in loops! Used for timers, external signals, and more.

## 🌟 Key Concepts
- Interrupt vector table
- Masking/enabling
- Priorities
- Nested interrupts

## 🛠️ Typical Usage
- Enable interrupt source
- Write ISR (Interrupt Service Routine)
- Clear interrupt flag
- Return from ISR

## 🧩 MCU Support
- **AVR, STM32F1, PIC, MSP430**: Each has unique interrupt features—see their `.rst` files for details!

## 📚 Resources
- [theory.md](theory.md)
- [isr-design.md](isr-design.md)
- [nvic-basics.md](nvic-basics.md)

---

✨ *Remember: ISRs should be short and fast!*

🔑 **Mnemonic:** "I**N**T: **I**mmediate **N**otification **T**rigger!"