DAC on MSP430G2553
==================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- MSP430G2553 does not have a built-in DAC.
- External DACs (e.g., MCP4921) can be interfaced via SPI.

Registers/Interface
-------------------
- USCI_B0: UCB0CTL0/1, UCB0TXBUF

Initialization
--------------
- Configure USCI_B0 for SPI
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
