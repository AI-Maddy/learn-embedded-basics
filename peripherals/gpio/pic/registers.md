# 📔 PIC GPIO Registers

PIC MCUs use TRIS and PORT registers for simple, effective GPIO control.

## 🗂️ Key Registers
- **TRISx**: Data direction (input/output)
- **PORTx**: Read input value
- **LATx**: Latch output value (on some PICs)

## 🧠 Tips
- Set TRISx to 1 for input, 0 for output
- Write to LATx/PORTx to set output
- Read PORTx for input

---

✨ *PIC: The classic microcontroller GPIO!*

🔑 **Mnemonic:** "T**R**I**S: **T**oggle, **R**ead, **I**nput, **S**et!"

## ✅ Register Bring-Up Sequence
1. Configure `TRISx` direction.
2. Set output defaults via `LATx/PORTx`.
3. Read back pin state using `PORTx`.

## 🔍 Validation Checklist
- Direction bits match hardware plan.
- Output writes use recommended latch register path.
- Input read stability verified with pull setup.

## ⚠️ Common Pitfalls
- Writing `PORT` instead of `LAT` on supported parts.
- Oscillator/config issues misattributed to GPIO errors.