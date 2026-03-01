/*
 * i2c_pic.c
 * PIC16F877A I2C Example Source File
 *
 * Demonstrates basic I2C master initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <xc.h>

/**
 * @brief Initialize MSSP as I2C master.
 * @param sspadd Baud rate register value
 */
void i2c_init(unsigned char sspadd) {
    SSPCON = 0x28; // I2C Master mode
    SSPADD = sspadd;
    SSPSTAT = 0x00;
}

/**
 * @brief Send START condition.
 */
void i2c_start(void) {
    SEN = 1;
    while (SEN);
}

/**
 * @brief Send STOP condition.
 */
void i2c_stop(void) {
    PEN = 1;
    while (PEN);
}

/**
 * @brief Write a byte to I2C bus.
 * @param data Byte to write
 */
void i2c_write(unsigned char data) {
    SSPBUF = data;
    while (SSPSTATbits.BF);
    while ((SSPCON2 & 0x1F) || (SSPSTATbits.R_nW));
}

/**
 * @brief Read a byte from I2C bus.
 * @return Received byte
 */
unsigned char i2c_read(void) {
    RCEN = 1;
    while (!SSPSTATbits.BF);
    return SSPBUF;
}
