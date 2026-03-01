.. _timers_msp430:

====================
MSP430 Timers
====================

**Type:** Timer_A, Timer_B, capture/compare, PWM

**How to Configure:**
- Set TACTL/TAxCTL for mode
- Set CCRx for compare/capture
- Configure prescaler

**How to Use:**
- Start/stop timer
- Generate PWM, measure frequency, create delays
- Use interrupts for overflow/compare

**What else to cover:**
- Timer interrupts
- Example code snippets

**Bring-Up Sequence:**
- Configure timer source and divider
- Set CCR values and mode
- Validate compare/overflow interrupt behavior

**Validation Checklist:**
- Timer interval remains stable
- Interrupt path clears flags correctly
- Low-power transitions preserve timing behavior
