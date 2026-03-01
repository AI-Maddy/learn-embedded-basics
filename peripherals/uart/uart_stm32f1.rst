UART on STM32F1
===============

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- USART1/2/3 peripherals
- Baud rate, parity, stop bits, data bits configuration
- Interrupt and DMA support

Registers
---------
- USARTx_SR: Status Register
- USARTx_DR: Data Register
- USARTx_BRR: Baud Rate Register
- USARTx_CR1/2/3: Control Registers

Initialization
--------------
- Enable peripheral clock
- Configure GPIO pins (TX/RX)
- Set baud rate and frame format
- Enable USART

Transmit/Receive
----------------
- Polling, interrupt, and DMA modes
- Buffering

Advanced Topics
---------------
- LIN, Smartcard, IrDA support
- Synchronous mode
- Error handling
