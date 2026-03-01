# 🔗 I2C Peripheral Overview

🔄 **Inter-Integrated Circuit (I2C)**

I2C is a two-wire, addressable bus for connecting multiple chips. Used for sensors, EEPROMs, RTCs, and more!

## 🌟 Key Concepts
- Master/slave roles
- 7/10-bit addressing
- Start/stop conditions
- ACK/NACK
- Clock stretching

## 🛠️ Typical Usage
- Configure as master or slave
- Send start condition
- Write/read data
- Handle ACK/NACK

## 🧩 MCU Support
- **AVR, STM32F1, PIC, MSP430**: Each has unique I2C modules—see their `.rst` files for details!

## 📚 Resources
- [theory.md](theory.md)
- [ack-nack.md](ack-nack.md)
- [i2c-state-machine.md](i2c-state-machine.md)

---

✨ *Remember: I2C is like a digital handshake!*

🔑 **Mnemonic:** "I**2**C: **I**nter-**2**-Chip Communication!"