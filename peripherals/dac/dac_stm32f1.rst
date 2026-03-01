DAC on STM32F1
==============

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- STM32F103 has built-in 12-bit DAC (on some variants)
- 2 output channels

Registers
---------
- DAC_CR: Control Register
- DAC_DHR12R1/2: Data Holding Registers
- DAC_DOR1/2: Data Output Registers

Initialization
--------------
- Enable DAC clock
- Configure output pins
- Enable DAC channel

Operation
---------
- Write digital value to DAC_DHR12R1/2
- Control output voltage

Advanced Topics
---------------
- DMA support
- Waveform generation
- Error handling
