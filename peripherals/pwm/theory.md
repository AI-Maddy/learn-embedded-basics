# ⚙️ PWM Theory

🧠 **Pulse Width Modulation**

PWM is a technique to control average voltage or power by switching a signal on and off rapidly.

## 🏗️ How It Works
- Timer generates periodic signal
- Duty cycle sets ON/OFF ratio
- Output filters to smooth voltage

## 📏 Key Parameters
- Frequency (Hz)
- Duty cycle (%)
- Resolution (bits)
- Dead time (for motor control)

## 🧰 Tips
- Use high frequency for LEDs (no flicker)
- Use low-pass filter for analog output
- Avoid shoot-through in H-bridges

---

🌈 *PWM is the "volume knob" of embedded systems!*

🔑 **Mnemonic:** "P**W**M: **P**ulse **W**idth **M**agic!"

## 🧪 Validation Checklist
- Frequency measured on scope matches configured value.
- Duty cycle maps linearly across command range.
- Output polarity matches expected hardware behavior.

## 🚨 Common Pitfalls
- Timer clock assumptions wrong.
- Duty update glitches due to non-buffered register writes.
- Too-low frequency causes visible flicker or audible noise.

## ⚖️ Design Tradeoffs
- Higher PWM frequency reduces ripple but may reduce resolution.
- Lower PWM frequency increases resolution but may create artifacts.