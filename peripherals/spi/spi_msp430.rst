SPI on MSP430G2553
==================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- USCI_B0 module
- Master/Slave SPI support
- Full-duplex, synchronous communication
- Configurable clock polarity, phase, and speed

Registers
---------
- UCB0CTL0/1: Control Registers
- UCB0BR0/1: Baud Rate Registers
- UCB0TXBUF: Transmit Buffer
- UCB0RXBUF: Receive Buffer

Initialization
--------------
- Configure pins for SPI
- Set master/slave, clock, polarity, phase
- Enable USCI_B0

Transmit/Receive
----------------
- Write/read UCB0TXBUF/UCB0RXBUF
- Polling or interrupt-driven

Advanced Topics
---------------
- Multi-slave support
- Error handling
