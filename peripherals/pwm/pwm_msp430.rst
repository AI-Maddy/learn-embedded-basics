PWM on MSP430G2553
==================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- Timer_A PWM output
- Multiple PWM channels
- Edge/center-aligned modes

Registers
---------
- TA0CTL: Timer_A Control
- TA0CCR0: Period Register
- TA0CCR1/2: Duty Cycle Registers
- TA0CCTLx: Capture/Compare Control

Initialization
--------------
- Configure timer for PWM mode
- Set frequency and duty cycle
- Configure output pins
- Enable timer

Operation
---------
- Update duty cycle
- Start/stop PWM

Advanced Topics
---------------
- Multiple PWM outputs
- Dead time insertion
- Frequency/duty cycle adjustment
