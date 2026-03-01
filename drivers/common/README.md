# Common Drivers

Shared driver infrastructure used across all MCU families.

## Purpose
- Normalize APIs across platforms
- Keep board-specific differences isolated
- Provide reusable utilities for timing, error handling, and logging

## Recommended Common Modules
- `error.h/.c`: unified status codes and failure mapping
- `delay.h/.c`: delay primitives (us/ms) with backend abstraction
- `ring_buffer.h/.c`: UART/SPI/I2C buffering support
- `bitops.h`: register bit helpers and masks
- `assert.h`: lightweight debug assertions for bring-up

## Cross-Platform Design Rules
- Use opaque handles (`*_handle_t`) for peripheral instances
- Keep register-level code in platform backends
- Keep public headers hardware-agnostic where possible
- Prefer explicit init/config structures over global mutable state

## Error Model
- `DRV_OK`, `DRV_ERR_BUSY`, `DRV_ERR_TIMEOUT`, `DRV_ERR_ARG`, `DRV_ERR_HW`
- Convert peripheral-specific errors into common statuses at boundary layers

## Validation Checklist
- Same public API compiles on all supported MCU profiles
- Backend swap does not require application changes
- Common utilities are covered by small host-side tests when feasible