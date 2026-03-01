.. _timers_stm32f1:

====================
STM32F1 Timers
====================

**Type:** 16-bit general-purpose, advanced, and basic timers

**How to Configure:**
- Enable timer clock (RCC)
- Set prescaler, auto-reload
- Configure mode (PWM, input capture, output compare)

**How to Use:**
- Start/stop timer
- Generate PWM, measure frequency, create delays
- Use interrupts or DMA

**What else to cover:**
- Advanced timer features (dead-time, complementary outputs)
- Example code snippets

**Bring-Up Sequence:**
- Enable timer RCC clock
- Configure PSC/ARR and mode
- Validate update/compare event timing

**Validation Checklist:**
- Update rate is correct
- IRQ or DMA events trigger reliably
- PWM/compare outputs match configuration
