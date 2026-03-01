PWM on STM32F1
==============

.. contents:: Table of Contents
   :depth: 2

Overview
--------
- 16-bit general-purpose timers
- Multiple PWM channels per timer
- Edge/center-aligned modes

Registers
---------
- TIMx_CR1/CR2: Control Registers
- TIMx_CCMR1/2: Capture/Compare Mode
- TIMx_CCER: Capture/Compare Enable
- TIMx_ARR: Auto-Reload Register
- TIMx_CCRx: Capture/Compare Register

Initialization
--------------
- Enable timer and GPIO clocks
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
- Complementary outputs
- Dead time insertion
- DMA/PWM synchronization
