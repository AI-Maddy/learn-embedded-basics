SPI on AVR ATmega328P
=====================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- Master/Slave SPI support
- Full-duplex, synchronous communication
- Configurable clock polarity, phase, and speed

Registers
---------
- SPCR: SPI Control Register
- SPSR: SPI Status Register
- SPDR: SPI Data Register

Initialization
--------------
- Set MISO, MOSI, SCK, SS pins
- Configure as master/slave
- Set clock rate, polarity, phase
- Enable SPI

Transmit/Receive
----------------
- Write/read SPDR
- Polling or interrupt-driven

Advanced Topics
---------------
- Multi-slave support
- Double speed mode
- Error handling
