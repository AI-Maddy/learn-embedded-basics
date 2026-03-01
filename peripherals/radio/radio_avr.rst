Radio (RF) on AVR ATmega328P
============================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- No built-in RF, but supports SPI/UART-based modules (e.g., nRF24L01, CC1101)
- Typical use: SPI interface

Common Modules
--------------
- nRF24L01 (2.4GHz, SPI)
- CC1101 (Sub-GHz, SPI)

Initialization
--------------
- Configure SPI
- Set module registers (address, channel, power, etc.)
- Enable interrupts (optional)

Transmit/Receive
----------------
- Write/read via SPI
- Use module-specific commands

Advanced Topics
---------------
- Power management
- Addressing and auto-ack
- Error handling
