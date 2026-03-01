SPI on PIC16F877A
=================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- Master/Slave SPI support
- Full-duplex, synchronous communication
- Configurable clock polarity, phase, and speed

Registers
---------
- SSPCON: Synchronous Serial Port Control
- SSPSTAT: Status Register
- SSPBUF: Buffer Register

Initialization
--------------
- Set SCK, SDI, SDO, SS pins
- Configure as master/slave
- Set clock rate, polarity, phase
- Enable SPI

Transmit/Receive
----------------
- Write/read SSPBUF
- Polling or interrupt-driven

Advanced Topics
---------------
- Multi-slave support
- Error handling
