# ⏳ Delay Generation Techniques

🕰️ **Delays** are essential for timing, debouncing, and protocol timing in embedded systems. There are two main approaches:

## 🛑 Blocking Delays
- CPU waits in a loop (busy-wait)
- Simple but wastes power and CPU time
- Example: `for` loop or `while` loop

## 🏃 Non-Blocking Delays
- Use timers or interrupts
- CPU can do other work while waiting
- More efficient and scalable

## 🧩 Example (Pseudocode)
```c
// Blocking
void delay_ms(uint32_t ms) { while(ms--) _delay(); }

// Non-blocking
volatile int flag = 0;
ISR(TIMER_ISR) { flag = 1; }
```

## 🧠 Tips
- Prefer non-blocking for multitasking
- Use hardware timers for accuracy
- Avoid long blocking delays in ISRs

---

✨ *Delays: The "pause button" of your MCU!*

🔑 **Mnemonic:** "D**E**L**A**Y: **D**on't **E**ver **L**et **A**ll **Y**ield!"