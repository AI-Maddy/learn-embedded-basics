# 🔄 SPI Peripheral Overview

🔗 **Serial Peripheral Interface (SPI)**

SPI is a fast, full-duplex protocol for connecting MCUs to sensors, memory, displays, and more!

## 🌟 Key Concepts
- Master/slave roles
- Clock polarity (CPOL) & phase (CPHA)
- Chip select (CS/SS)
- Daisy-chaining

## 🛠️ Typical Usage
- Configure as master or slave
- Set CPOL/CPHA
- Select slave with CS
- Transfer data (full-duplex)

## 🧩 MCU Support
- **AVR, STM32F1, PIC, MSP430**: Each has unique SPI modules—see their `.rst` files for details!

## 📚 Resources
- [theory.md](theory.md)
- [cpol-cpha-explained.md](cpol-cpha-explained.md)
- [spi-driver-template.md](spi-driver-template.md)

---

✨ *Remember: SPI is like a high-speed conversation—everyone must listen and talk in sync!*

🔑 **Mnemonic:** "S**P**I: **S**ynchronous **P**eripheral **I**nterface!"