# 📡 CC26xx Radio Overview

TI CC26xx MCUs feature integrated Sub-GHz and BLE radios for IoT and wireless sensor networks.

## 🌟 Key Features
- Multi-protocol support (BLE, Zigbee, Sub-GHz)
- Low power consumption
- Flexible packet engine

## 🧠 Tips
- Use SmartRF Studio for configuration
- Optimize power settings for battery life
- Leverage hardware AES for security

---

✨ *CC26xx: Wireless made easy!*

🔑 **Mnemonic:** "C**C**: **C**onnected **C**ommunication!"

## ✅ Validation Checklist
- Confirm channel/address settings match peer.
- Verify packet TX and RX events are observed.
- Check power mode transitions for stability.

## 🚨 Common Pitfalls
- Mismatched packet format fields.
- Incorrect RF front-end or antenna assumptions.
- Interrupt flags not cleared in expected order.

Capture over-the-air and local event logs together when debugging intermittent packet loss.