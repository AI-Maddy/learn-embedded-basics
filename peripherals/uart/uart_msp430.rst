UART on MSP430G2553
===================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- USCI_A0 module
- Baud rate, parity, stop bits, data bits configuration
- Interrupt-driven and polling modes

Registers
---------
- UCA0CTL0/1: Control Registers
- UCA0BR0/1: Baud Rate Registers
- UCA0TXBUF: Transmit Buffer
- UCA0RXBUF: Receive Buffer

Initialization
--------------
- Configure pins for UART
- Set baud rate
- Enable USCI_A0

Transmit/Receive
----------------
- Polling vs. interrupt-driven
- Buffering

Advanced Topics
---------------
- Auto baud rate detection
- Low power operation
- Error handling
