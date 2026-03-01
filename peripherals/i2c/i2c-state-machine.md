# 🔄 I2C State Machine

I2C communication is managed by a state machine that controls start, address, data, and stop conditions.

## 🏗️ Key States
- **Idle:** Bus is free
- **Start:** Begin communication
- **Address:** Master sends address, waits for ACK
- **Data:** Send/receive bytes, ACK/NACK after each
- **Stop:** End communication

## 🧠 Tips
- Always check for ACK/NACK at each step
- Use interrupts for efficient state handling
- Handle errors and bus arbitration

---

✨ *The I2C state machine keeps your data flowing smoothly!*

🔑 **Mnemonic:** "S**T**A**T**E: **S**tart, **T**ransfer, **A**cknowledge, **T**erminate, **E**nd!"

## 🧩 Error States to Model
- Bus busy timeout
- Arbitration lost
- NACK on address or data
- Stuck-low line recovery path

## 🛠️ Implementation Pattern
1. Explicit state enum in driver.
2. Transition on hardware flags/events.
3. Exit on timeout with clear error code.
4. Reset state machine before retry.

## ✅ Verification Checklist
- State transitions follow expected sequence.
- Error path always terminates transfer.
- Retry path restores bus to idle state.