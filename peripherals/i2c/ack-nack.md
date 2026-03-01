# 👍 I2C ACK/NACK Explained

I2C uses ACK (acknowledge) and NACK (not acknowledge) to manage data flow between master and slave.

## 🟢 ACK (Acknowledge)
- Sent by receiver after each byte
- Means "I got it, send more!"

## 🔴 NACK (Not Acknowledge)
- Sent by receiver to stop transfer
- Means "I'm done, or error occurred"

## 🧠 Tips
- Always check for ACK after address and data
- Use NACK to end reads

---

✨ *ACK/NACK: The "thumbs up/down" of I2C!*

🔑 **Mnemonic:** "A**C**K: **A**ll **C**omms **K**eepgoing!"

## 🔍 Where ACK/NACK Appears
- Address phase: slave ACK confirms device presence.
- Data phase: receiver ACK means continue transfer.
- Final byte read: master NACK indicates end-of-read.

## 🚨 Debug Clues
- Immediate NACK after address: wrong address or wiring issue.
- Random NACK during data: timing/noise/pull-up problem.
- No ACK at all: bus stuck or target not powered.

## ✅ Practical Checks
- Scope SDA/SCL around address phase.
- Confirm pull-up values and rise times.
- Retry transaction with timeout + bus recovery.