# 🕹️ GPIO Debounce Techniques

Mechanical switches bounce! Debouncing ensures clean, reliable digital signals.

## 🧰 Hardware Debounce
- RC low-pass filter (resistor + capacitor)
- Schmitt trigger buffer

## 🧰 Software Debounce
- Wait for signal to stabilize (delay)
- Sample multiple times, accept only stable value
- Use state machines for robust handling

## 🧪 Practical Firmware Pattern
1. Read raw pin state each loop tick (or timer ISR).
2. If raw state differs from stable state, increment a counter.
3. When counter reaches threshold (for example 5–20 ms), accept new stable state.
4. Generate a button event once per clean transition.

This approach avoids repeated press/release events during bounce windows.

## ⚠️ Common Mistakes
- Using long blocking delays in the main loop and missing other tasks.
- Triggering on both edges without filtering, causing duplicate events.
- Debouncing inside a high-priority ISR with heavy logic.
- Forgetting pull-up/pull-down configuration, which causes floating input noise.

## 🔬 Validation Checklist
- Probe the switch with a logic analyzer and inspect bounce duration.
- Confirm one physical press produces exactly one logical event.
- Test short taps, long holds, and rapid repeated presses.
- Verify behavior at different supply voltages and temperatures if relevant.

## 🧠 Tips
- Combine hardware and software for best results
- Use interrupts with care—debounce in ISR or main loop

---

✨ *Debouncing: The "noise-cancelling headphones" for your buttons!*

🔑 **Mnemonic:** "D**E**B**O**U**N**C**E: **D**elay, **E**xamine, **B**lock **O**ut **U**nwanted **N**oise, **C**lean **E**dge!"