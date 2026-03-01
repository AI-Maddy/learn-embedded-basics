# Drivers Build & Usage Guide

This folder contains portable baremetal driver skeletons and per-driver example programs.

## Directory Layout
- `common/`: shared status types and helpers
- `adc/`, `gpio/`, `i2c/`, `pwm/`, `radio/`, `spi/`, `uart/`: driver API + implementation + example

## Initialization Pattern (Required)
All drivers now use a consistent two-step initialization sequence:

1. Call module-level bring-up: `*_driver_init()`
2. Call configuration init: `*_init(...)`

### Generic Pattern
```c
if (drv_init() != DRV_OK) return -1;
if (gpio_driver_init() != DRV_OK) return -1;
if (gpio_init(&pin, GPIO_MODE_OUTPUT, GPIO_PULL_NONE) != DRV_OK) return -1;
```

### Available Module Init APIs
- `drv_init()`
- `adc_driver_init()`
- `gpio_driver_init()`
- `i2c_driver_init()`
- `pwm_driver_init()`
- `radio_driver_init()`
- `spi_driver_init()`
- `uart_driver_init()`

## Quick Local Syntax Check
Run this from the repository root:

```bash
for f in drivers/common/drv_status.c drivers/adc/adc.c drivers/gpio/gpio.c drivers/i2c/i2c.c drivers/pwm/pwm.c drivers/radio/radio.c drivers/spi/spi.c drivers/uart/uart.c; do
  gcc -std=c11 -Wall -Wextra -I drivers/common -I drivers/adc -I drivers/gpio -I drivers/i2c -I drivers/pwm -I drivers/radio -I drivers/spi -I drivers/uart -fsyntax-only "$f"
done
```

## Build Commands Per Example
Each command compiles one example with its driver source and shared status source.

### Common
```bash
gcc -std=c11 -Wall -Wextra \
  drivers/common/example_status.c drivers/common/drv_status.c \
  -I drivers/common -o build/example_status
```

### ADC
```bash
gcc -std=c11 -Wall -Wextra \
  drivers/adc/example_adc.c drivers/adc/adc.c drivers/common/drv_status.c \
  -I drivers/adc -I drivers/common -o build/example_adc
```

### GPIO
```bash
gcc -std=c11 -Wall -Wextra \
  drivers/gpio/example_gpio.c drivers/gpio/gpio.c drivers/common/drv_status.c \
  -I drivers/gpio -I drivers/common -o build/example_gpio
```

### I2C
```bash
gcc -std=c11 -Wall -Wextra \
  drivers/i2c/example_i2c.c drivers/i2c/i2c.c drivers/common/drv_status.c \
  -I drivers/i2c -I drivers/common -o build/example_i2c
```

### PWM
```bash
gcc -std=c11 -Wall -Wextra \
  drivers/pwm/example_pwm.c drivers/pwm/pwm.c drivers/common/drv_status.c \
  -I drivers/pwm -I drivers/common -o build/example_pwm
```

### Radio
```bash
gcc -std=c11 -Wall -Wextra \
  drivers/radio/example_radio.c drivers/radio/radio.c drivers/common/drv_status.c \
  -I drivers/radio -I drivers/common -o build/example_radio
```

### SPI
```bash
gcc -std=c11 -Wall -Wextra \
  drivers/spi/example_spi.c drivers/spi/spi.c drivers/common/drv_status.c \
  -I drivers/spi -I drivers/common -o build/example_spi
```

### UART
```bash
gcc -std=c11 -Wall -Wextra \
  drivers/uart/example_uart.c drivers/uart/uart.c drivers/common/drv_status.c \
  -I drivers/uart -I drivers/common -o build/example_uart
```

## Notes
- These are portable skeletons intended as a starting point; hardware register mapping must be implemented per MCU backend.
- The examples use a generic `main()` and can be adapted to your board startup/runtime.
- New examples already follow the two-step init pattern (`*_driver_init()` then `*_init(...)`).
- Create the output folder first:

```bash
mkdir -p build
```
