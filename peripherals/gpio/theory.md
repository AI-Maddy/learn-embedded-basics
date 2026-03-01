# 🔌 GPIO Theory

🧠 **General Purpose Input/Output**

GPIOs are the most basic and versatile microcontroller feature. They let you sense switches, drive LEDs, and communicate with the outside world!

## 🏗️ Modes
- Input (with/without pull-up)
- Output (push-pull/open-drain)
- Alternate function

## 📏 Key Parameters
- Drive strength
- Input threshold
- Pin multiplexing
- Debounce time

## 🧰 Tips
- Use pull-ups for switches
- Debounce mechanical inputs
- Avoid floating pins
- Use interrupts for responsiveness

---

🌈 *GPIOs are the "fingers" of your MCU!*

🔑 **Mnemonic:** "G**P**I**O**: **G**et **P**ins **I**n **O**rder!"

## 🧪 Validation Checklist
- Confirm pin mode register values after init.
- Verify output transitions with LED/scope.
- Validate input stability with pull-up/pull-down.
- Ensure interrupt flags clear correctly.

## 🚨 Common Failure Modes
- Missing peripheral clock enable for port.
- Wrong alternate-function mapping.
- Floating inputs causing random toggles.
- Debounce omitted for mechanical switches.

## 🛠️ Practical Pattern
Use GPIO for early bring-up first:
1. Set one output pin and blink.
2. Read one button input with pull-up.
3. Add interrupt only after polling path is stable.