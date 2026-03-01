.. _interrupts_stm32f1:

====================
STM32F1 Interrupts
====================

**Type:** NVIC, EXTI, peripheral interrupts

**How to Configure:**
- Enable interrupt in NVIC
- Configure EXTI for external interrupts
- Enable interrupt in peripheral

**How to Use:**
- Write IRQ handler
- Clear interrupt flag

**What else to cover:**
- Interrupt priorities
- Nested interrupts
- Example code snippets

**Bring-Up Sequence:**
- Configure NVIC priority and enable
- Configure EXTI/peripheral routing
- Trigger event and verify IRQ handler

**Validation Checklist:**
- Priority behavior matches expectation
- Pending bits clear correctly
- No unintended default handler hits
