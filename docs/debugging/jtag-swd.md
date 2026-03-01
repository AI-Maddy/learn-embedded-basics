# JTAG & SWD

JTAG and SWD are hardware debug interfaces used to flash and debug MCUs at register level.

## Quick Comparison

| Interface | Pins | Typical Use | Notes |
|---|---:|---|---|
| JTAG | 4-5 signal pins + GND | Legacy/complex debug chains | Supports boundary scan, daisy-chain devices |
| SWD | 2 signal pins + GND | Most ARM Cortex-M debugging | Simpler wiring, very common on dev boards |

## Signal Basics
- **JTAG**: TCK, TMS, TDI, TDO, (optional TRST)
- **SWD**: SWCLK, SWDIO
- Shared practical signals: `GND`, `VTref`, optional `NRST`

## Wiring Checklist
- Target and probe must share **ground**.
- Match target I/O voltage (`VTref`) with probe expectations.
- Keep wires short and clean to avoid signal integrity issues.
- Include reset line for reliable attach-on-boot debugging.

## Common Probe Examples
- ST-Link (STM32)
- J-Link (broad MCU support)
- CMSIS-DAP probes
- XDS family (TI devices)

## Bring-Up Procedure
1. Connect debug probe to target header.
2. Verify power and reference voltage.
3. Start debug tool (OpenOCD/vendor IDE).
4. Halt core and read IDCODE/target info.
5. Flash firmware and set breakpoint at `main`.

## Frequent Failure Modes
- **Cannot detect target**: wrong pinout, missing ground, wrong voltage.
- **Unstable debug session**: long wires or noisy power rails.
- **Attach works, flash fails**: readout protection or wrong flash algorithm.
- **Immediate hard fault**: bad vector table/clock init/startup code.

## SWD vs JTAG Selection Rule
- Choose **SWD** for Cortex-M unless project specifically requires JTAG chain features.
- Choose **JTAG** when board already routes it or boundary scan is required.

## Field Debug Tips
- Add a dedicated debug header on custom boards.
- Keep BOOT/RESET pins accessible.
- Document header pinout directly in hardware docs.
