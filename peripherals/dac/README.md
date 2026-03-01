# 🎚️ DAC Peripheral Overview

🌟 **Digital-to-Analog Converter (DAC)**

A DAC transforms digital values into smooth analog voltages. Essential for audio, waveform generation, and analog control!

## 🧠 Key Concepts
- Resolution (bits)
- Reference voltage
- Output range
- Settling time

## 🛠️ Typical Usage
- Configure interface (SPI/I2C)
- Write digital value to DAC
- Buffer output if needed

## 🧩 MCU Support
- **STM32F1**: Built-in DAC (on some variants)
- **AVR, PIC, MSP430**: Use external DAC (e.g., MCP4921 via SPI)

## 📚 Resources
- [theory.md](theory.md)
- [datasheets/](../../resources/datasheets/)
- [spi-driver-template.md](../spi/spi-driver-template.md)

---

✨ *Remember: DAC output is only as good as your reference and layout!*

🔑 **Mnemonic:** "D**A**C: **D**igital **A**nalog **C**onversion!"