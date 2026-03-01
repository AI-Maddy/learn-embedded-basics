PWM on AVR ATmega328P
=====================

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- 8/16-bit Timer/Counter PWM modes
- Fast PWM, Phase Correct PWM
- Output Compare pins (OCnA/B)

Registers
---------
- TCCRnA/B: Timer/Counter Control
- OCRnA/B: Output Compare Register
- TCNTn: Counter Register
- DDRx: Data Direction Register

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
- Dead time insertion
- Complementary outputs
- Frequency/duty cycle adjustment
