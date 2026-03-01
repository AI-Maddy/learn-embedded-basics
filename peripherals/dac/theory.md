# 🎨 DAC Theory

🎵 **Digital-to-Analog Conversion**

A DAC takes a digital value and produces a proportional analog voltage. This is essential for audio, waveform generation, and analog control.

## 🏗️ Types of DACs
- **Resistor Ladder (R-2R)**
- **Sigma-Delta**
- **Current Steering**

## 📏 Key Parameters
- Resolution (bits)
- Linearity
- Settling time
- Output range

## 🧩 MCU Integration
- Some MCUs (e.g., STM32F1) have built-in DACs.
- Most 8-bit MCUs use external DACs via SPI/I2C.

## 🧪 Example: MCP4921 (SPI DAC)
- 12-bit resolution
- SPI interface
- Fast settling time

## 🧰 Tips
- Use a clean reference voltage
- Buffer output for driving loads
- Mind layout for analog signals

---

🌈 *DACs bridge the digital and analog worlds!*

🔑 **Mnemonic:** "D**A**C: **D**igital **A**nalog **C**onversion!"