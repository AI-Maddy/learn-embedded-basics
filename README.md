# 🚀 learn-embedded-basics

> **A multi‑MCU, bare‑metal learning repository for embedded systems.**

---

## 🎯 Supported MCU Families

- 🟦 **AVR ATmega** (Arduino Uno)
- 🟨 **PIC16/PIC18** (PIC16F877A board)
- 🟩 **MSP430** (MSP430 LaunchPad)
- 🟦 **STM32F1** (STM32 Blue Pill)
- 🟥 **TI C2000** (C2000 LaunchPad)
- 🟧 **GD32VF103** (RISC‑V board)
- 🟪 **RP2040** (Raspberry Pi Pico)
- 🟦 **Nordic nRF52** (nRF52 DK)
- 🟧 **TI CC26xx** (CC26xx LaunchPad)

---

## 📚 What You Will Learn

### 🛠️ Core Embedded Concepts
- 🟢 GPIO configuration & debouncing
- ⏲️ Timers, counters, capture/compare
- ⚡ Interrupts and NVIC
- 🔌 UART, SPI, I2C
- 📶 PWM generation
- 🎚️ ADC/DAC sampling
- ⏰ Clock systems and PLLs
- 🗂️ Linker scripts & startup code
- 🧩 Memory‑mapped I/O
- 🐞 Bare‑metal debugging (GDB, OpenOCD)

### 🚀 Advanced Domains
- 🌀 Motor control (TI C2000)
- ⚡ Digital power conversion
- 📡 BLE radio fundamentals (nRF52)
- 🌐 BLE + Zigbee/Thread mesh (CC26xx)
- 🦄 RISC‑V architecture
- 🧬 PIO‑based protocol emulation (RP2040)

---

## 💡 Repository Philosophy

**1️⃣ Learn once, apply everywhere**
- Theory, register‑level explanation, minimal example, multi‑MCU implementations, exercises + solutions

**2️⃣ MCU‑agnostic theory, MCU‑specific practice**
- Shared theory, unique MCU folders for real-world differences

**3️⃣ Real hardware, real datasheets**
- All examples tested on real dev boards

---

## 🗂️ Folder Overview

- 📖 `/docs/` — Toolchain setup, datasheet reading, linker scripts, startup code, debugging guides
- 🧩 `/peripherals/` — Each peripheral, all MCUs, with theory, register maps, code examples
- 🛠️ `/drivers/` — Minimal drivers for each MCU family
- 🧬 `/mcu-profiles/` — Architecture notes, memory maps, clock trees, pinouts, errata
- 📚 `/resources/` — Datasheets, reference manuals, timing diagrams, cheatsheets

---

## 🏁 Learning Path

1. 🟢 GPIO basics
2. ⏲️ Timers and delays
3. ⚡ Interrupts
4. 🔌 UART
5. 🔄 SPI
6. 🧲 I2C
7. 📶 PWM
8. 🎚️ ADC/DAC
9. 🗂️ Bare‑metal startup + linker scripts
10. 🚀 Advanced domains:
    - 🌀 Motor control (C2000)
    - 📡 BLE radio (nRF52)
    - 🌐 Mesh networking (CC26xx)
    - 🧬 PIO (RP2040)
    - 🦄 RISC‑V architecture

---

## 🧩 Example: GPIO Module Structure

```
peripherals/gpio/
│
├── theory.md
├── avr/
│   ├── registers.md
│   ├── blink.c
│   └── debounce.c
├── pic/
├── msp430/
├── stm32f1/
├── c2000/
├── gd32vf103/
├── rp2040/
├── nrf52/
└── cc26xx/
```
Each folder includes:
- 🗺️ Register map
- ⚙️ Initialization code
- 💡 Example applications
- ⚠️ Notes and pitfalls

---

## 📡 Example: PAN Radio Module

```
peripherals/radio/
├── nrf52/
│   ├── radio-registers.md
│   ├── ble-advertising.c
│   ├── ble-scanner.c
│   └── low-power.md
└── cc26xx/
    ├── rf-core-overview.md
    ├── ble-simple-broadcaster.c
    ├── zigbee-frame-basics.md
    └── sensor-controller.md
```

---

## 📝 License
MIT License (recommended for educational repos)

---

## 🤝 Contribution Guidelines
- Keep code minimal and register‑level
- Include references to datasheets
- Maintain consistent folder structure
- Add MCU‑specific notes when behavior differs

---

> **Memorize this:**
> 
> "Learn once, apply everywhere. Real hardware, real datasheets, real understanding."

✨ Happy hacking! ✨
