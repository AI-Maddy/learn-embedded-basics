# nRF52832 Profile

## MCU Snapshot
- Core: ARM Cortex-M4F with 2.4 GHz radio
- Best for: BLE beacons, wearables, wireless sensors
- Strength: low-power operation with robust wireless stack options

## Baremetal Startup Order
1. Configure clock sources (HFCLK/LFCLK as required)
2. Initialize GPIO and debug UART
3. Set up timers and GPIOTE/interrupt plumbing
4. Configure radio or protocol stack entry points
5. Enter event-driven loop with power management

## Toolchain
- ARM GCC toolchain (or Nordic-compatible build systems)
- Device headers and linker scripts must match chip revision

## Flash + Debug
- J-Link/OpenOCD-based workflows are common
- SWD interface for flash + step debug

## Pin/Peripheral Priorities
- GPIO + GPIOTE event routing for responsive input handling
- Timer and RTC choices impact power profile
- Radio and clock setup must be consistent before RF activity

## Bring-Up Checklist
- LED/button GPIO sanity test
- UART log output at boot
- Timer event callback verified
- Simple RF packet TX/RX smoke test

## References in Repo
- Peripheral docs: `peripherals/radio`, `peripherals/gpio`, `peripherals/timers`
- Driver skeletons: `drivers/*`