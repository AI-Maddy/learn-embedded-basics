# 📗 AVR GPIO Registers

AVR microcontrollers use simple, powerful registers for GPIO control.

## 🗂️ Key Registers
- **DDRx**: Data Direction Register (input/output)
- **PORTx**: Output value or pull-up enable
- **PINx**: Read input value

## 🧠 Tips
- Set DDRx to 1 for output, 0 for input
- Write to PORTx to set output or enable pull-up
- Read PINx to get input value

---

✨ *Master the registers, master the pins!*

🔑 **Mnemonic:** "D**D**R: **D**irection, **D**rive, **R**ead!"

## ✅ Register Bring-Up Sequence
1. Configure `DDRx` direction first.
2. Set initial `PORTx` output/pull-up state.
3. Read back `PINx` to verify hardware level.

## 🔍 Validation Checklist
- Direction bits match intended input/output map.
- Pull-up behavior is correct on button pins.
- Output transitions are visible on scope/LED.

## ⚠️ Common Pitfalls
- Writing PORT before DDR assumptions are clear.
- Floating inputs due to missing pull configuration.