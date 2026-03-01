# ⚡ Interrupts Theory

🧠 **Interrupts**

Interrupts allow your MCU to respond to events instantly, pausing normal code to handle urgent tasks.

## 🏗️ Types of Interrupts
- External (pin change)
- Timer
- Peripheral (UART, ADC, etc.)
- Software

## 📏 Key Parameters
- Vector table
- Priority
- Masking
- Latency

## 🧰 Tips
- Keep ISRs short
- Clear interrupt flags
- Avoid heavy computation in ISRs
- Use volatile for shared variables

---

🌈 *Interrupts are the MCU's "reflexes"!*

🔑 **Mnemonic:** "I**N**T: **I**mmediate **N**otification **T**rigger!"

## 🧪 Validation Checklist
- Interrupt source flag is set on event.
- ISR entry occurs and exits cleanly.
- Pending flag is cleared correctly.
- Main loop state updates are race-safe.

## 🚨 Common Pitfalls
- Forgetting to clear pending interrupt flag.
- Wrong priority causing starvation.
- Excessive ISR work increasing latency.
- Missing `volatile` on shared flags.

## 🛠️ Practical Pattern
Use ISR only to capture event and set a flag; process heavy logic in the main loop.