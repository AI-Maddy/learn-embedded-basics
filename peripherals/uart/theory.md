# 📨 UART Theory

🧠 **Universal Asynchronous Receiver/Transmitter**

UART is a simple, robust protocol for serial communication—no clock required!

## 🏗️ How It Works
- Start bit signals beginning of data
- Data bits sent LSB first
- Optional parity bit for error checking
- Stop bit(s) mark end of frame

## 📏 Key Parameters
- Baud rate (bps)
- Parity (even/odd/none)
- Stop bits (1/2)
- Data bits (7/8/9)

## 🧰 Tips
- Match baud rates on both ends
- Use interrupts for efficient RX/TX
- Watch for framing errors
- Use level shifters for voltage mismatch

---

🌈 *UART is the "walkie-talkie" of embedded systems!*

🔑 **Mnemonic:** "U**A**R**T: **U**niversal **A**synchronous **R**eceive **T**ransmit!"

## 🧪 Validation Checklist
- TX startup banner visible in terminal.
- RX echo path works at target baud.
- Framing/parity errors monitored and handled.

## 🚨 Common Pitfalls
- Wrong core clock causes baud mismatch.
- Missing level shifting between 3.3V and 5V devices.
- Blocking reads causing system stalls.

## ⚖️ Design Notes
- Interrupt-driven RX scales better than polling.
- Ring buffers help avoid data loss during bursts.