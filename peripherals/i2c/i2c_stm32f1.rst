I2C on STM32F1
==============

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- I2C1/I2C2 peripherals
- Master/Slave operation
- 7/10-bit addressing
- DMA and interrupt support

Registers
---------
- I2Cx_CR1/CR2: Control Registers
- I2Cx_SR1/SR2: Status Registers
- I2Cx_DR: Data Register
- I2Cx_CCR: Clock Control Register
- I2Cx_TRISE: TRISE Register

Initialization
--------------
- Enable peripheral clock
- Configure GPIO pins (SCL, SDA)
- Set clock, addressing mode
- Enable I2C

Transmit/Receive
----------------
- Start/stop conditions
- Addressing
- Data transfer
- Polling, interrupt, or DMA

Advanced Topics
---------------
- Dual addressing
- General call
- Error handling
