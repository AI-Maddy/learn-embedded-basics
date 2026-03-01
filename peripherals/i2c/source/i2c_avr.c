/*
 * i2c_avr.c
 * AVR ATmega328P I2C (TWI) Example Source File
 *
 * Demonstrates basic I2C master initialization and transmit/receive routines.
 *
 * Author: Your Name
 * Date: 2026-02-27
 */
#include <avr/io.h>

/**
 * @brief Initialize TWI (I2C) as master.
 * @param twbr Bit rate value
 */
void i2c_init(unsigned char twbr) {
    TWBR = twbr;
    TWSR = 0x00;
    TWCR = (1 << TWEN);
}

/**
 * @brief Send START condition.
 */
void i2c_start(void) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

/**
 * @brief Send STOP condition.
 */
void i2c_stop(void) {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

/**
 * @brief Write a byte to I2C bus.
 * @param data Byte to write
 */
void i2c_write(unsigned char data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

/**
 * @brief Read a byte from I2C bus (ACK).
 * @return Received byte
 */
unsigned char i2c_read_ack(void) {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

/**
 * @brief Read a byte from I2C bus (NACK).
 * @return Received byte
 */
unsigned char i2c_read_nack(void) {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}
