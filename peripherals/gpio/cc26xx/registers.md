# 📙 CC26xx GPIO Registers

TI CC26xx MCUs have versatile, low-power GPIOs for wireless applications.

## 🗂️ Key Registers
- **IOC**: Input/output configuration
- **DIO**: Digital I/O data
- **GPIO**: Control and interrupt

## 🧠 Tips
- Use IOC to set pin function and drive strength
- DIO for fast pin access
- GPIO for interrupts and advanced features

---

✨ *CC26xx: Wireless GPIOs with power efficiency!*

🔑 **Mnemonic:** "I**O**C: **I**nput/**O**utput **C**ontrol!"

## ✅ Register Bring-Up Sequence
1. Configure IOC function and drive settings.
2. Set DIO direction and pull mode.
3. Validate interrupt/event behavior if enabled.

## 🔍 Validation Checklist
- DIO mapping matches board pinout.
- Pull-up/down settings stabilize inputs.
- Event/IRQ flags clear correctly.

## ⚠️ Common Pitfalls
- Wrong IOC function selection for desired pin role.
- Power-domain assumptions breaking GPIO behavior.