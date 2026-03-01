# CC26xx DriverLib Setup

This setup prepares CC26xx development with TI DriverLib and GCC/TI toolchain workflows.

## 1) Install Core Tools
- Install Code Composer Studio (recommended for first bring-up).
- Install TI SimpleLink SDK matching your CC26xx device.

## 2) Locate DriverLib + Device Headers
- Confirm SDK path includes:
	- device headers
	- startup/linker files
	- DriverLib source and includes

## 3) Project Setup Essentials
- Include paths: DriverLib + device include directories
- Linker file: select exact device memory map
- Startup file: use SDK-provided startup for device variant

## 4) Build Verification
- Create minimal project toggling one DIO pin.
- Ensure compile links with no undefined DriverLib symbols.

## 5) Flash + Debug
- Use LaunchPad onboard debugger or XDS probe.
- Verify attach, load, halt, and breakpoint at `main`.

## 6) Common Issues
- Wrong SDK/device combination causes header/register mismatch.
- Missing startup or linker script causes reset faults.
- Pin mapping confusion: always cross-check board schematic.

## 7) Quick Success Criteria
- GPIO toggle runs on selected DIO.
- UART log (if enabled) prints startup message.
- Debug session can halt/resume reliably.
