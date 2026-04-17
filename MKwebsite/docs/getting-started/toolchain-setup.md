# :material-tools: Toolchain Setup

!!! abstract "What You'll Learn"
    - Install arm-none-eabi-gcc cross-compiler
    - Set up OpenOCD for flashing and debugging
    - Use CMake for portable build configuration

---

## :material-lightbulb-on: Intuition

The toolchain is your forge. Getting it right once saves hours of debugging mysterious build errors.

---

## :material-vector-polyline: Diagram

```mermaid
flowchart LR
    A[Source .c/.h] --> B["arm-none-eabi-gcc
(compile)"]
    B --> C[".o object files"]
    C --> D["arm-none-eabi-ld
(link with .ld script)"]
    D --> E[".elf binary"]
    E --> F["objcopy → .bin/.hex"]
    F --> G["OpenOCD/ST-Link
(flash to MCU)"]
```

---

## :material-code-tags: Code Examples

=== "ARM GCC Install"
    ```bash
    # Ubuntu/Debian
    sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi

    # Verify
    arm-none-eabi-gcc --version
    ```

=== "Minimal Makefile"
    ```makefile
    CC      = arm-none-eabi-gcc
    CFLAGS  = -mcpu=cortex-m3 -mthumb -O2 -Wall
    LDFLAGS = -T linker.ld -nostartfiles

    all: firmware.elf

    firmware.elf: main.o startup.o
    	$(CC) $(LDFLAGS) -o $@ $^

    %.o: %.c
    	$(CC) $(CFLAGS) -c -o $@ $<
    ```

=== "OpenOCD Flash"
    ```bash
    # Flash STM32 via ST-Link
    openocd -f interface/stlink.cfg -f target/stm32f1x.cfg \
      -c "program firmware.elf verify reset exit"
    ```

---

## :material-alert: Pitfalls

!!! warning "Common Mistakes"
    - Use the right `-mcpu` flag for your MCU (cortex-m0, m3, m4, m4f). Wrong flag generates incompatible instructions
    - Always include `-nostartfiles` when supplying your own startup code

---

## :material-help-circle: Flashcards

???+ question "What flags are mandatory for Cortex-M?"
    `-mcpu=cortex-mX -mthumb` — Thumb instruction set is required. For M4F with FPU add `-mfpu=fpv4-sp-d16 -mfloat-abi=hard`.

???+ question "What does objcopy do?"
    Converts `.elf` (with debug info) to `.bin` or `.hex` (raw binary for flashing). Use `arm-none-eabi-objcopy -O binary firmware.elf firmware.bin`.

---

## :material-check-circle: Summary

Toolchain: arm-none-eabi-gcc + OpenOCD. Build pipeline: .c → .o → .elf → .bin → flash. CMake wraps this portably.
