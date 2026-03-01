UART on PIC16F877A
==================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- EUSART (Enhanced Universal Synchronous Asynchronous Receiver Transmitter)
- Baud rate, parity, stop bits, data bits configuration
- Interrupt-driven and polling modes

Registers
---------
- TXSTA: Transmit Status and Control
- RCSTA: Receive Status and Control
- SPBRG: Baud Rate Generator
- TXREG: Transmit Register
- RCREG: Receive Register

Initialization
--------------
- Set baud rate
- Configure TX/RX pins
- Enable transmitter/receiver

Transmit/Receive
----------------
- Polling vs. interrupt-driven
- Buffering

Advanced Topics
---------------
- 9-bit mode
- Auto-baud detect
- Error handling
