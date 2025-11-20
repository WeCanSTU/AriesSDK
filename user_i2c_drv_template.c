#include "defines.h"
#include "port_def.h"
#include "user_i2c_drv.h"

/**
 * @brief Initializes the I2C interface.
 *
 * This function sets up the I2C hardware with the appropriate configuration
 * parameters, such as clock speed and addressing mode.
 */
void user_i2c_init(void)
{
    // Todo: Implement the I2C initialization function
    // Example pseudocode:
    // - Configure I2C clock speed
    // - Set up I2C pins for SDA and SCL
    // - Enable the I2C peripheral
}

/**
 * @brief Reads data from an I2C device.
 *
 * @param params Pointer to a TwoWireParams structure containing the device
 *               address, register address (if applicable), and buffer to store
 *               the read data.
 * @return The number of bytes successfully read.
 */
uint32_t user_i2c_read(TwoWireParams *params)
{
    uint32_t cnt = 0;
    // Todo: Implement the I2C read function
    // Example pseudocode:
    // - Start I2C communication
    // - Send device address with read flag
    // - Read data from the device into params->buffer
    // - Stop I2C communication
    // - Return the number of bytes read
    return cnt;
}

/**
 * @brief Writes data to an I2C device.
 *
 * @param params Pointer to a TwoWireParams structure containing the device
 *               address, register address (if applicable), and buffer with 
 *               data to be written.
 * @return The number of bytes successfully written.
 */
uint32_t user_i2c_write(TwoWireParams *params)
{
    uint32_t cnt = 0;
    // Todo: Implement the I2C write function
    // Example pseudocode:
    // - Start I2C communication
    // - Send device address with write flag
    // - Write data from params->buffer to the device
    // - Stop I2C communication
    // - Return the number of bytes written
    return cnt;
}

/**
 * @brief Checks if an I2C device is ready to communicate.
 *
 * @param slaveAddr The 7-bit or 10-bit I2C slave address of the device to check.
 *                  For 7-bit addressing, the address should be in the range 0x00 to 0x7F.
 * @return Status of the device readiness:
 *         - 0: Device is ready (responds to the address).
 *         - Non-zero: Device is not ready or an error occurred (e.g., no ACK received).
 *
 * This function sends a start condition and the slave address on the I2C bus to
 * determine if the specified device is present and ready to respond. It does not
 * perform any data transfer beyond the address check. Typically used for device
 * detection or to verify communication before read/write operations.
 */
uint8_t user_i2c_is_device_ready(uint8_t slaveAddr)
{
    uint8_t status = 1;
    // Todo: Implement the I2C device ready check function
    // Example pseudocode:
    // - Start I2C communication
    // - Send device address with write flag (no data transfer, just address)
    // - Check for ACK from the device
    // - Stop I2C communication
    // - Return 0 if ACK received (device ready), non-zero if no ACK (device not ready)
    return status;
}
