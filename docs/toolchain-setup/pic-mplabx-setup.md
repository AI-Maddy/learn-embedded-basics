# PIC MPLABX Toolchain Setup

This setup targets PIC16/PIC18 style development using MPLAB X IDE and XC8.

## 1) Install Required Tools
- Install MPLAB X IDE.
- Install XC8 compiler (matching PIC family).
- Install PICkit tools/drivers if using PICkit programmer.

## 2) Create Project
1. New standalone project.
2. Select exact device (example: PIC16F877A).
3. Choose PICkit/debug tool.
4. Select XC8 compiler.

## 3) Configure Device Settings
- Set oscillator mode/config bits.
- Set watchdog and reset options per board requirements.
- Confirm clock value used by delay macros.

## 4) Build + Flash
- Build project in MPLAB X.
- Program device via PICkit and verify no config-bit mismatch warnings.

## 5) First Bring-Up
- Toggle a GPIO pin (LED) in main loop.
- Add a simple UART TX test if available.

## 6) Common Issues
- Wrong config bits prevents boot/clock stability.
- Incorrect TRIS direction configuration gives no I/O activity.
- Programmer connection errors from target power or cable orientation.

## 7) Quick Success Criteria
- Build passes cleanly in XC8.
- Program/verify succeeds.
- LED blink confirms runtime execution.
