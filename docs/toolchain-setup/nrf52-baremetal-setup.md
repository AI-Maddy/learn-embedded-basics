# nRF52 Baremetal Setup

This setup targets nRF52 baremetal firmware using ARM GCC and SWD debug tools.

## 1) Install Required Tools
```bash
sudo apt update
sudo apt install -y gcc-arm-none-eabi gdb-multiarch openocd make
```

Optional (commonly used): J-Link tools from Segger.

## 2) Verify Installation
```bash
arm-none-eabi-gcc --version
openocd --version
```

## 3) Build Basics
- Use nRF52 device headers/startup file.
- Use correct linker script for chip and flash/RAM size.
- Build with debug info (`-g`) for easier bring-up.

## 4) Flash + Debug Flow
1. Connect SWD probe to target.
2. Start OpenOCD (or J-Link server) with nRF52 target config.
3. Launch GDB and connect to remote target.
4. `reset halt`, `load`, breakpoint at `main`, continue.

## 5) Early Bring-Up Tests
- LED blink on known board pin.
- Timer tick or RTC interrupt test.
- UART boot banner (if pins available).

## 6) Common Issues
- LFCLK/HFCLK misconfiguration can break radio/timing behavior.
- Wrong linker script causes immediate hard fault.
- SWD wiring or target voltage mismatch prevents attach.

## 7) Quick Success Criteria
- Target connects and halts.
- Firmware loads and executes to `main`.
- First peripheral smoke test passes.
