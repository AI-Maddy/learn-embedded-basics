# 📻 Radio Module Registers

Radio modules (e.g., nRF24L01, CC1101) use registers for configuration and control.

## 🗂️ Common Registers
- **CONFIG:** Main settings (power, CRC, mode)
- **RF_CH:** Channel selection
- **RF_SETUP:** Data rate, power
- **STATUS:** Interrupts, data ready
- **TX_ADDR/RX_ADDR:** Addresses

## 🧠 Tips
- Always check datasheet for register map
- Set addresses and channels before transmit/receive
- Use STATUS to monitor events

---

✨ *Master the registers, master the airwaves!*

🔑 **Mnemonic:** "C**O**N**F**I**G: **C**ontrol, **O**ptions, **N**etwork, **F**requency, **I**nterrupts, **G**ain!"

## 🧪 Register Bring-Up Sequence
1. Program base config and CRC settings.
2. Configure channel/data rate/power.
3. Set TX/RX addresses and payload behavior.
4. Clear status and enable required interrupts.

## 🔍 Debug Checklist
- Read-back config registers after write.
- Verify status flags after TX/RX events.
- Validate channel and address symmetry across peers.