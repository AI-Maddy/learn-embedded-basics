DAC on PIC16F877A
=================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- PIC16F877A does not have a built-in DAC.
- External DACs (e.g., MCP4921) can be interfaced via SPI.

Registers/Interface
-------------------
- SPI: SSPCON, SSPSTAT, SSPBUF

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
