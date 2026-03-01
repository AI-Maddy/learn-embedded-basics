I2C on MSP430G2553
==================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- USCI_B0 module
- Master/Slave operation
- 7/10-bit addressing

Registers
---------
- UCB0CTL0/1: Control Registers
- UCB0BR0/1: Baud Rate Registers
- UCB0I2CSA: Slave Address Register
- UCB0TXBUF: Transmit Buffer
- UCB0RXBUF: Receive Buffer

Initialization
--------------
- Configure pins for I2C
- Set master/slave, clock, addressing mode
- Enable USCI_B0

Transmit/Receive
----------------
- Start/stop conditions
- Addressing
- Data transfer
- Polling or interrupt-driven

Advanced Topics
---------------
- Clock stretching
- Error handling
