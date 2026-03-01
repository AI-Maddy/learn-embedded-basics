# 🚦 Interrupt-Driven UART

💡 **Interrupt-driven UART** allows your MCU to send and receive data in the background, freeing up CPU time for other tasks.

## 🧠 How It Works
- UART triggers an interrupt when data is received or ready to send
- ISR (Interrupt Service Routine) handles the data
- Main code continues running without waiting

## 🧩 Example (Pseudocode)
```c
ISR(UART_RX_ISR) {
  uint8_t data = UART_Read();
  // Process received data
}

ISR(UART_TX_ISR) {
  UART_Write(next_byte);
}
```

## 🧰 Tips
- Use ring buffers for smooth data flow
- Keep ISRs short and fast
- Enable/disable interrupts as needed

---

✨ *Interrupts: The "autopilot" for your UART!*

🔑 **Mnemonic:** "I**N**T**-UART: **I**nterrupts **N**avigate **T**ransfers!"