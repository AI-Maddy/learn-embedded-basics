# 📘 C2000 GPIO Registers

C2000 MCUs offer flexible GPIO control for real-time applications.

## 🗂️ Key Registers
- **GPxDIR**: Direction (input/output)
- **GPxDAT**: Data (read/write pin value)
- **GPxSET/GPxCLEAR**: Set/clear output
- **GPxMUX**: Pin function selection

## 🧠 Tips
- Use GPxMUX to select GPIO or peripheral function
- Use GPxSET/GPxCLEAR for atomic pin changes
- Check TRM for pin mapping

---

✨ *C2000 GPIOs: Real-time control at your fingertips!*

🔑 **Mnemonic:** "G**P**x: **G**eneral **P**urpose, x = port!"

## ✅ Register Bring-Up Sequence
1. Set pin mux to GPIO function.
2. Configure `GPxDIR` and default output state.
3. Use `GPxSET/GPxCLEAR` for atomic updates.

## 🔍 Validation Checklist
- Mux register points to GPIO, not peripheral mode.
- Direction and data registers match expectation.
- Atomic set/clear operations behave deterministically.

## ⚠️ Common Pitfalls
- Forgetting EALLOW-protected access requirements.
- Updating data register with read-modify-write races.