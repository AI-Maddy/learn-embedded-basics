# 🌀 SPI Clock Polarity & Phase Explained

🔄 **CPOL & CPHA** are the two key settings that define how SPI data is sampled and shifted. Get these right for reliable communication!

## 🕰️ CPOL (Clock Polarity)
- **CPOL = 0:** Clock idle LOW
- **CPOL = 1:** Clock idle HIGH

## ⏱️ CPHA (Clock Phase)
- **CPHA = 0:** Data sampled on first clock edge
- **CPHA = 1:** Data sampled on second clock edge

## 🧩 SPI Modes Table
| Mode | CPOL | CPHA | Idle | Data Sampled |
|------|------|------|------|--------------|
| 0    | 0    | 0    | LOW  | Rising edge  |
| 1    | 0    | 1    | LOW  | Falling edge |
| 2    | 1    | 0    | HIGH | Falling edge |
| 3    | 1    | 1    | HIGH | Rising edge  |

## 🎨 Visual Mnemonic
- **"Polarity = Position, Phase = Pulse"**
- Imagine a wave: idle level (polarity), and which edge (phase) you "catch the ball" (sample data)

## 🧠 Tips
- Both master and slave must match mode
- Check device datasheets for correct settings
- If in doubt, try all 4 modes!

---

✨ *Remember: "SPI is picky about timing—CPOL and CPHA are the secret handshake!"*

🔑 **Mnemonic:** "C**P**O**L**/**C**P**H**A: **C**lock **P**osition, **C**lock **P**ulse **H**andshake **A**greement!"