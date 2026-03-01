# GPIO Driver

General Purpose Input/Output (GPIO) drivers manage digital pin direction, state, pull configuration, and interrupts.

## Scope
- Pin mode setup: input, output, alternate, analog
- Output write/toggle and input read
- Pull-up/pull-down configuration
- Optional interrupt edge/level trigger setup

## Suggested Driver API
- `gpio_init(const gpio_pin_t *pin, gpio_mode_t mode, gpio_pull_t pull)`
- `gpio_write(const gpio_pin_t *pin, bool state)`
- `gpio_read(const gpio_pin_t *pin)`
- `gpio_toggle(const gpio_pin_t *pin)`
- `gpio_attach_irq(const gpio_pin_t *pin, gpio_irq_edge_t edge, gpio_irq_cb_t cb)`

## Baremetal Bring-Up Order
1. Enable GPIO peripheral clock for target port
2. Configure pin mode and electrical characteristics
3. Initialize default output/input state
4. If needed, configure EXTI/NVIC interrupt path
5. Verify with LED/button smoke test

## Common Pitfalls
- Missing peripheral clock enable before register access
- Wrong active level assumptions for LEDs/buttons
- Forgetting to clear interrupt pending flags in ISR

## Validation Checklist
- Output pin toggles at expected rate
- Input pin reads stable value with pull configuration
- Interrupt fires on correct edge and debounces correctly