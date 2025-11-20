#ifndef _USER_I2C_DRV_HH_
#define _USER_I2C_DRV_HH_

#ifdef __cplusplus
extern "C" {
#endif

#include "defines.h"   ///< Include general definitions
#include "port_def.h"  ///< Include port-specific definitions

/**
 * @brief Initializes the I2C interface.
 *
 * This function sets up the necessary configurations to prepare the I2C 
 * hardware for communication.
 */
ext void user_i2c_init(void);

/**
 * @brief Reads data from an I2C device.
 *
 * @param params Pointer to a TwoWireParams structure containing the I2C 
 *               address, register address, and buffer for storing the read data.
 * @return Status of the read operation, typically 0 for success or an error code.
 *
 * This function performs a read operation on the I2C bus, accessing the
 * specified register of a slave device and storing the read data into the
 * provided buffer.
 */
ext uint32_t user_i2c_read(TwoWireParams *params);

/**
 * @brief Writes data to an I2C device.
 *
 * @param params Pointer to a TwoWireParams structure containing the I2C 
 *               address, register address, and buffer with data to be written.
 * @return Status of the write operation, typically 0 for success or an error code.
 *
 * This function performs a write operation on the I2C bus, sending data to the
 * specified register of a slave device from the provided buffer.
 */
ext uint32_t user_i2c_write(TwoWireParams *params);


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
ext uint8_t user_i2c_is_device_ready(uint8_t slaveAddr);

#ifdef __cplusplus
}
#endif
#endif // _USER_I2C_DRV_HH_
