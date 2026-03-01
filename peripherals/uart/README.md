# 📨 UART Peripheral Overview

💬 **Universal Asynchronous Receiver/Transmitter (UART)**

UART is the classic way to send and receive data—debugging, communication, and more!

## 🌟 Key Concepts
- Baud rate
- Parity, stop bits
- Framing errors
- Interrupt-driven vs. polling

## 🛠️ Typical Usage
- Configure baud rate and frame format
- Enable transmitter/receiver
- Send/receive bytes
- Handle errors

## 🧩 MCU Support
- **AVR, STM32F1, PIC, MSP430**: Each has unique UART modules—see their `.rst` files for details!

## 📚 Resources
- [theory.md](theory.md)
- [baudrate-calculation.md](baudrate-calculation.md)
- [interrupt-driven-uart.md](interrupt-driven-uart.md)

---

✨ *Remember: UART is your MCU's "voice"—use it to debug and communicate!*

🔑 **Mnemonic:** "U**A**R**T: **U**niversal **A**synchronous **R**eceive **T**ransmit!"