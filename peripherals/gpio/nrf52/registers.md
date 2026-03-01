# 📓 nRF52 GPIO Registers

nRF52 MCUs are designed for Bluetooth Low Energy and have advanced GPIO features.

## 🗂️ Key Registers
- **PIN_CNF[n]**: Pin configuration
- **IN/OUT**: Read/write pin value
- **DIR**: Direction
- **LATCH**: Latch input events

## 🧠 Tips
- Use PIN_CNF for mode, pull, drive
- LATCH for event detection
- IN/OUT for fast access

---

✨ *nRF52: Wireless GPIOs for IoT!*

🔑 **Mnemonic:** "C**N**F: **C**onfigure, **N**etwork, **F**unction!"

## ✅ Register Bring-Up Sequence
1. Configure `PIN_CNF[n]` mode/pull/drive.
2. Set direction via `DIR` and initialize output.
3. Use `LATCH`/events for interrupt-style behavior.

## 🔍 Validation Checklist
- Pin configuration matches electrical requirements.
- Direction and output states are correct after init.
- Event-latch behavior is repeatable.

## ⚠️ Common Pitfalls
- Overlooking default drive-strength settings.
- Not clearing event-related flags/latches.