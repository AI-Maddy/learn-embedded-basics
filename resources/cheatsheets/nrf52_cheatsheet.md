# nRF52 Baremetal Startup Cheat Sheet

🚀 **Getting Started with nRF52832**

## 1. Clock Setup
- HFINT (internal) or HFXO (external) selected in `CLOCK` registers.

## 2. Stack Pointer
- Set by startup code (linker script).

## 3. GPIO Configuration
```c
NRF_P0->DIRSET = (1 << 17); // Set P0.17 as output
```

## 4. Peripheral Enable
- Enable modules in `POWER` and `CLOCK` registers as needed.

## 5. Interrupts
```c
__enable_irq(); // Enable global interrupts
```

## 6. Main Loop
```c
while (1) {
    // Application code
}
```

## 7. Minimal Startup Flow
1. Configure clocks (if needed)
2. Initialize GPIO and peripherals
3. Enable interrupts (if needed)
4. Enter main loop

---
🧠 **Tip:** Use Nordic SDK or baremetal. Check datasheet for pin mapping and power domains.

## Bring-Up Flow
1. Confirm HFCLK strategy and startup timing.
2. Validate one GPIO output on a known board pin.
3. Add GPIOTE/interrupt flow after baseline pin checks.

## Validation Checklist
- PIN_CNF settings are explicit (dir/pull/drive/sense).
- GPIO ownership does not conflict with other peripherals.
- Event and interrupt clear sequence is validated.

## Common Pitfalls
- Assuming SoftDevice behavior in baremetal builds.
- Misconfigured pull or sense mode causing false edges.
- Starting radio/peripherals before clock readiness.
