SPI on STM32F1
==============

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- Multiple SPI peripherals (SPI1, SPI2)
- Full-duplex, synchronous communication
- Configurable clock polarity, phase, and speed
- Hardware NSS management

Registers
---------
- SPIx_CR1/CR2: Control Registers
- SPIx_SR: Status Register
- SPIx_DR: Data Register

Initialization
--------------
- Enable peripheral clock
- Configure GPIO pins (MISO, MOSI, SCK, NSS)
- Set master/slave, clock, polarity, phase
- Enable SPI

Transmit/Receive
----------------
- Write/read SPIx_DR
- Polling, interrupt, or DMA

Advanced Topics
---------------
- CRC calculation
- NSS pulse management
- Error handling
