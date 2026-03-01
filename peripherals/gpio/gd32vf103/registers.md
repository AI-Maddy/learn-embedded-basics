# 📒 GD32VF103 GPIO Registers

GD32VF103 RISC-V MCUs provide flexible GPIO control for embedded projects.

## 🗂️ Key Registers
- **GPIOx_CTL0/CTL1**: Pin mode/config
- **GPIOx_ISTAT**: Input status
- **GPIOx_BOP/BC/LOCK**: Bit set/reset/lock

## 🧠 Tips
- Use CTL0/CTL1 for pin mode (input/output/AF)
- BOP/BC for atomic pin changes
- LOCK for pin security

---

✨ *GD32VF103: RISC-V GPIOs for the future!*

🔑 **Mnemonic:** "C**T**L: **C**onfigure, **T**oggle, **L**ock!"

## ✅ Register Bring-Up Sequence
1. Configure `CTL0/CTL1` for mode and speed.
2. Use `BOP/BC` for atomic output updates.
3. Apply lock only after final pin validation.

## 🔍 Validation Checklist
- Mode bits match intended IO direction/type.
- Output updates occur without read-modify races.
- Lock settings do not block needed runtime changes.

## ⚠️ Common Pitfalls
- Incorrect speed/mode pair causing unstable behavior.
- Using lock too early during bring-up.