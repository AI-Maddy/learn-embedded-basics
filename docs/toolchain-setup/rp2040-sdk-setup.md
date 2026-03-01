# RP2040 SDK Setup

This setup covers Raspberry Pi Pico / RP2040 development with Pico SDK.

## 1) Install Dependencies (Linux)
```bash
sudo apt update
sudo apt install -y cmake gcc-arm-none-eabi build-essential git
```

## 2) Get Pico SDK
```bash
git clone https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
```

Set environment variable:
```bash
export PICO_SDK_PATH=$PWD
```

## 3) Create/Build Project
```bash
mkdir -p build
cd build
cmake ..
make -j
```

## 4) Flash Firmware
- Hold BOOTSEL and connect board via USB.
- Copy generated `.uf2` to mounted RPI-RP2 drive.

## 5) Debug Option
- Use Picoprobe or SWD probe with OpenOCD + GDB.

## 6) Common Issues
- `PICO_SDK_PATH` not set or wrong.
- Missing submodules causing CMake errors.
- Wrong board target in CMake cache/settings.

## 7) Quick Success Criteria
- Build generates UF2 successfully.
- Board boots and runs blink test.
- Optional debug session attaches over SWD.
