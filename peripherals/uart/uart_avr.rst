UART on AVR ATmega328P
======================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- 8-bit USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
- Baud rate, parity, stop bits, data bits configuration
- Interrupt-driven and polling modes

Registers
---------
- UBRRn: Baud Rate Register
- UCSRnA/B/C: Control and Status Registers
- UDRn: Data Register

Initialization
--------------
- Set baud rate
- Configure frame format
- Enable transmitter/receiver

Transmit/Receive
----------------
- Polling vs. interrupt-driven
- Buffering

Advanced Topics
---------------
- Multi-processor communication
- Double speed mode
- Error handling
