# STM32F103 Profile

## MCU Snapshot
- Core: ARM Cortex-M3
- Best for: general-purpose embedded control and communication nodes
- Common boards: Blue Pill and similar STM32F1 dev boards

## Baremetal Startup Order
1. Execute startup + `SystemInit` clock baseline
2. Enable GPIO/peripheral clocks in RCC
3. Configure pin modes (input/output/alternate)
4. Initialize UART timer and required buses
5. Configure NVIC/EXTI and start main loop

## Toolchain
- `arm-none-eabi-gcc` toolchain
- OpenOCD + GDB workflows are common

## Flash + Debug
- SWD interface via ST-Link class probes
- Confirm flash option bytes when debugging startup issues

## Pin/Peripheral Priorities
- RCC clock enable is required before peripheral access
- Alternate-function pin mapping must be verified
- Timer + UART are strong first peripherals for bring-up

## Bring-Up Checklist
- LED output toggles at expected rate
- UART banner appears at configured baud
- EXTI interrupt on button/input works
- Timer tick or PWM measured on scope

## References in Repo
- Peripheral docs: `peripherals/gpio`, `peripherals/uart`, `peripherals/timers`
- Driver skeletons: `drivers/*`