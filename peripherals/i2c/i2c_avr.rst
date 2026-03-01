I2C on AVR ATmega328P
=====================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- TWI (Two-Wire Interface) compatible with I2C
- Master/Slave operation
- Multi-master support

Registers
---------
- TWBR: Bit Rate Register
- TWSR: Status Register
- TWCR: Control Register
- TWDR: Data Register
- TWAR: Address Register

Initialization
--------------
- Set bit rate
- Set own address (if slave)
- Enable TWI

Transmit/Receive
----------------
- Start/stop conditions
- Addressing
- Data transfer
- Polling or interrupt-driven

Advanced Topics
---------------
- Arbitration
- Clock stretching
- Error handling
