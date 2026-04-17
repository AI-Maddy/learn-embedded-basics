# :material-wrench: Driver Architecture

<div class="grid cards" markdown>

-   :material-led-on: **GPIO Driver** — Portable GPIO HAL [:octicons-arrow-right-24:](gpio-driver.md)
-   :material-serial-port: **UART Driver** — Ring-buffer async UART [:octicons-arrow-right-24:](uart-driver.md)
-   :material-transit-connection: **I2C Driver** — Master read/write API [:octicons-arrow-right-24:](i2c-driver.md)
-   :material-transfer: **SPI Driver** — Full-duplex SPI master [:octicons-arrow-right-24:](spi-driver.md)

</div>

!!! info "Driver Design Principles"
    - **Portable**: abstract MCU-specific registers behind a clean API
    - **Non-blocking**: use callbacks/flags, not polling loops
    - **Minimal coupling**: driver doesn't know about the application
