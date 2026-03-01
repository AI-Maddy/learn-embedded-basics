# 🔗 I2C Theory

🧠 **Inter-Integrated Circuit**

I2C is a simple, robust, and widely used protocol for connecting chips. It uses just two wires: SDA (data) and SCL (clock).

## 🏗️ How It Works
- Master initiates communication
- Address phase selects slave
- Data transfer (read/write)
- ACK/NACK for flow control

## 📏 Key Parameters
- Bus speed (Standard, Fast, Fast+, High-Speed)
- Address width (7/10 bits)
- Pull-up resistors
- Bus capacitance

## 🧰 Tips
- Use proper pull-ups (1k–10k)
- Keep traces short for high speed
- Handle clock stretching
- Watch for address conflicts

---

🌈 *I2C lets your MCU talk to the world!*

🔑 **Mnemonic:** "I**2**C: **I**nter-**2**-Chip Communication!"

## 🧪 Validation Checklist
- Detect expected slave address with scanner.
- Read fixed ID register consistently.
- Confirm repeated-start works correctly.
- Verify recovery from NACK/timeout.

## 🚨 Common Failure Modes
- Missing or wrong pull-up resistors.
- Wrong bus speed timing registers.
- Clock stretching not handled.
- Address conflicts on shared bus.

## ⚖️ Design Tradeoffs
- Lower speed improves robustness on long/noisy traces.
- Higher speed improves throughput but tightens signal constraints.
- Interrupt/DMA path reduces CPU load for frequent transfers.