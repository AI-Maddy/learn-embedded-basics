I2C on PIC16F877A
=================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- MSSP (Master Synchronous Serial Port) module
- Master/Slave operation
- 7/10-bit addressing

Registers
---------
- SSPCON: Control Register
- SSPSTAT: Status Register
- SSPBUF: Buffer Register
- SSPADD: Address Register

Initialization
--------------
- Set SCL, SDA pins
- Configure as master/slave
- Set clock, addressing mode
- Enable MSSP

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
