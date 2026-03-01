# ⚙️ PWM Peripheral Overview

🔊 **Pulse Width Modulation (PWM)**

PWM lets you control power, brightness, and speed by rapidly switching a signal on and off. Used for motors, LEDs, and more!

## 🌟 Key Concepts
- Duty cycle
- Frequency
- Resolution
- Dead time

## 🛠️ Typical Usage
- Configure timer for PWM mode
- Set frequency and duty cycle
- Update duty cycle as needed

## 🧩 MCU Support
- **AVR, STM32F1, PIC, MSP430**: Each has unique PWM features—see their `.rst` files for details!

## 📚 Resources
- [theory.md](theory.md)
- [motor-control-basics.md](motor-control-basics.md)
- [servo-control.md](servo-control.md)

---

✨ *Remember: PWM is like a dimmer switch for electronics!*

🔑 **Mnemonic:** "P**W**M: **P**ulse **W**idth **M**agic!"

## ✅ Validation Checklist
- Confirm period and duty on oscilloscope.
- Verify runtime duty updates are glitch-free.
- Check output polarity and dead-time assumptions.

## 🚨 Common Pitfalls
- Timer clock mismatch causing wrong frequency.
- Limited resolution at high PWM frequencies.
- Output stage not sized for target load.