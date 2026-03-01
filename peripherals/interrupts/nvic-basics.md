# 🧩 NVIC Basics (Nested Vectored Interrupt Controller)

The NVIC is the brain behind ARM Cortex-M interrupt handling!

## 🏗️ Key Features
- Prioritized interrupts
- Nested interrupt support
- Vector table for fast dispatch
- Individual enable/disable

## 🧠 Tips
- Assign priorities carefully
- Use CMSIS functions for NVIC config
- Keep ISRs short for fast nesting

---

✨ *NVIC: The "traffic cop" for your interrupts!*

🔑 **Mnemonic:** "N**V**I**C: **N**ested, **V**ectored, **I**nterrupt **C**ontrol!"

## 🛠️ Practical NVIC Setup Flow
1. Clear pending IRQ.
2. Set interrupt priority.
3. Enable IRQ line.
4. Verify handler fires with test event.

## ⚠️ Priority Design Notes
- Lower numerical value often means higher priority on Cortex-M.
- Reserve top priorities for time-critical interrupts.
- Avoid too many equal-priority high-frequency sources.

## ✅ Verification
- `main` remains responsive under interrupt load.
- Higher-priority IRQ preempts lower-priority as expected.
- No unhandled default ISR jumps.