# 🧮 UART Baudrate Calculation

🔢 **Baudrate** is the speed of serial communication, measured in bits per second (bps). Calculating it correctly ensures reliable data transfer!

## 🧠 General Formula
- **Baudrate = F_CPU / (Prescaler × Divider)**
- Each MCU has its own registers and formula—check the datasheet!

## 🧩 AVR Example
- UBRR = (F_CPU / (16 × Baudrate)) - 1

## 🧩 STM32 Example
- USARTDIV = F_CPU / (16 × Baudrate)

## 🧩 PIC Example
- SPBRG = (Fosc / (64 × Baudrate)) - 1 (low speed)
- SPBRG = (Fosc / (16 × Baudrate)) - 1 (high speed)

## 🧩 MSP430 Example
- UCAxBR = F_BRCLK / Baudrate

## 🧰 Tips
- Use the closest possible value
- Double-check error percentage
- Use online calculators for convenience

---

✨ *Baudrate: The "speed limit" of your UART highway!*

🔑 **Mnemonic:** "B**A**U**D: **B**its **A**t **U**niform **D**elivery!"