DAC on AVR ATmega328P
====================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- AVR ATmega328P does not have a built-in DAC.
- External DACs (e.g., MCP4921) can be interfaced via SPI.

Registers/Interface
-------------------
- SPI: SPCR, SPSR, SPDR

Initialization
--------------
- Configure SPI as master
- Set up control pins (CS, LDAC)

Operation
---------
- Write digital value to DAC via SPI
- Control output voltage

Advanced Topics
---------------
- Buffered output
- Power management
- Error handling
