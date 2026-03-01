# CC2640R2F Profile

## MCU Snapshot
- Core: ARM Cortex-M3 with 2.4 GHz RF subsystem
- Best for: BLE and low-power wireless sensing nodes
- Strength: integrated radio + low-power modes

## Baremetal Startup Order
1. Configure system clock and power domains
2. Initialize GPIO and board-level pin mapping
3. Initialize RF/driverlib blocks required by application
4. Configure interrupts and event routing
5. Enter low-power-aware main loop

## Toolchain
- TI ARM compiler or GCC-based ARM toolchains
- TI SimpleLink/driverlib headers often used in startup

## Flash + Debug
- Debug/program via XDS110 class probe or LaunchPad interface
- Validate CCFG/boot-related settings before deployment

## Pin/Peripheral Priorities
- DIO mapping must match board schematic
- RF coexistence and pin ownership checks are important
- UART for diagnostics during RF bring-up

## Bring-Up Checklist
- LED + button sanity test on DIO pins
- UART startup log confirmed
- Basic RF TX/RX smoke test passes
- Sleep/wake cycle verified without lockups

## References in Repo
- Peripheral docs: `peripherals/radio`, `peripherals/gpio`, `peripherals/uart`
- Driver skeletons: `drivers/*`