PWM on PIC16F877A
=================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- CCP (Capture/Compare/PWM) modules
- 10-bit PWM resolution
- Single/dual output

Registers
---------
- CCPxCON: CCP Control Register
- PR2: Period Register
- T2CON: Timer2 Control
- CCPRxL: Duty Cycle Register

Initialization
--------------
- Set PWM mode
- Set frequency and duty cycle
- Configure output pins
- Enable timer

Operation
---------
- Update duty cycle
- Start/stop PWM

Advanced Topics
---------------
- Multiple PWM channels
- Dead time insertion
- Frequency/duty cycle adjustment
