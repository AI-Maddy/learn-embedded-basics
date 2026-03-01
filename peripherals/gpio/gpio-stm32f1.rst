.. _gpio_stm32f1:

====================
STM32F1 GPIO
====================

**Type:** Digital I/O, alternate function, open-drain/push-pull

**How to Configure:**
- Set GPIOx_CRL/CRH for mode and configuration
- Use ODR/IDR for output/input
- Set alternate function for peripherals

**How to Read/Write:**
- Write: Set/clear ODR/BSRR/BRR
- Read: Read IDR

**What else to cover:**
- Atomic set/reset (BSRR)
- Alternate function mapping
- Interrupts (EXTI)
- Example code snippets

**Bring-Up Sequence:**
- Enable RCC clock and configure CRL/CRH
- Validate ODR/IDR access path
- Configure EXTI mapping and IRQ handler

**Validation Checklist:**
- BSRR operations are atomic as expected
- EXTI line maps to correct GPIO pin
- Pending bits clear reliably in ISR
