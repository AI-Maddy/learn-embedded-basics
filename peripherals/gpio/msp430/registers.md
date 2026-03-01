# 📕 MSP430 GPIO Registers

MSP430 MCUs use simple, low-power GPIOs for ultra-low energy designs.

## 🗂️ Key Registers
- **PxDIR**: Direction (input/output)
- **PxOUT**: Output value
- **PxIN**: Input value
- **PxREN**: Pull-up/pull-down enable

## 🧠 Tips
- Set PxDIR for direction
- Use PxREN for pull-ups/pull-downs
- PxOUT sets output or enables pull-up

---

✨ *MSP430: GPIOs for battery-powered magic!*

🔑 **Mnemonic:** "P**x: **P**ort, x = number!"

## ✅ Register Bring-Up Sequence
1. Configure `PxDIR` first.
2. Set `PxREN` and `PxOUT` for pull behavior.
3. Verify input level via `PxIN`.

## 🔍 Validation Checklist
- Pull-up/down behavior matches button wiring.
- Output state persists across loop iterations.
- Interrupt edge/flag path works when enabled.

## ⚠️ Common Pitfalls
- Misordered `PxREN`/`PxOUT` setup.
- Watchdog resets masking GPIO test results.