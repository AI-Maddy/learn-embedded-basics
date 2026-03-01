# 🔄 SPI Theory

🧠 **Serial Peripheral Interface**

SPI is a synchronous, full-duplex protocol for fast data exchange between MCUs and peripherals.

## 🏗️ How It Works
- 4 wires: SCK, MOSI, MISO, SS/CS
- Master controls clock
- Data shifted in/out simultaneously

## 📏 Key Parameters
- Clock speed
- CPOL/CPHA (timing)
- Number of slaves
- Daisy-chaining

## 🧰 Tips
- Match CPOL/CPHA on both ends
- Use short wires for high speed
- Pull CS high when idle
- Check datasheets for quirks

---

🌈 *SPI is the "express lane" of embedded communication!*

🔑 **Mnemonic:** "S**P**I: **S**ynchronous **P**eripheral **I**nterface!"

## 🧪 Validation Checklist
- Read known chip ID register.
- Verify CPOL/CPHA on logic analyzer.
- Confirm CS timing around transactions.
- Test at low and high SPI clock rates.

## 🚨 Common Pitfalls
- Wrong SPI mode causes shifted/misaligned data.
- CS held incorrectly across multi-byte commands.
- Clock too fast for device/wiring.

## ⚖️ Design Notes
- Blocking SPI is simple for low throughput.
- Interrupt/DMA SPI is better for sustained transfers.