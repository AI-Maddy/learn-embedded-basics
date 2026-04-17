# :material-chip: AVR ATmega328P — 8-bit AVR

!!! abstract "MCU Snapshot"
    8-bit AVR, 16MHz, 32KB flash, 2KB SRAM, 1KB EEPROM, Arduino Uno MCU

---

## :material-memory: Memory Map

| Region | Start Address | Notes |
|--------|-------------|-------|
| Flash | `0x0000` | Code and const data |
| RAM | `0x0100 (SRAM)` | .data, .bss, stack, heap |
| Peripherals | Vendor-specific | See reference manual |

---

## :material-tools: Toolchain

- **Compiler:** `avr-gcc`
- **Flash/Debug:** avrdude + USBasp/AVRISP

---

## :material-led-on: GPIO Quick Reference

!!! info "GPIO Note"
    DDRx register controls direction; PORTx output; PINx input

---

## :material-list-box: Bring-Up Checklist

!!! success "Verified Working"
    - [ ] LED output toggles at expected rate
    - [ ] UART banner at 115200 baud on cold reset
    - [ ] Button input with pull-up reads correctly
    - [ ] Timer 1ms tick fires reliably
    - [ ] GDB breakpoint hits in main()

---

## :material-check-circle: Summary

See the [peripheral guides](../peripherals/index.md) for register-level details. This MCU's specifics are in the reference manual; this page captures the bring-up essentials.
