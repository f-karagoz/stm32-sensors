#ifndef _ADXL_345_
#define _ADXL_345_

#ifdef __cplusplus
extern "C" {
#endif

/**
===================================== DRIVER CONFIGURATION =====================================
 */

//! Alternate address is used when ALT ADDRESS pin of the ADXL345 hardware if high
#define ADXL_345_USE_ALTERNATE_ADDRESS
//! Alternate address is used when ALT ADDRESS pin of the ADXL345 hardware if high
#define ADXL_345_USE_HAL_DRIVER
// #define ADXL_345_USE_LL_DRIVER		// TODO Not supported yet
// #define ADXL_345_USE_BARE_METAL		// TODO Not supported yet

/**
===================================== INCLUDES =====================================
 */

#ifdef ADXL_345_USE_HAL_DRIVER
// If I2C is not enabled before enable it to include the necessary HAL libraries
#ifndef HAL_I2C_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
#endif
// TODO change this according to the HAL Driver of the related controller series
#include "stm32f4xx_hal.h"
#endif

#include <stdint.h>
#include <stdlib.h>

/**
===================================== DEFINES =====================================
 */

#ifdef ADXL_345_USE_HAL_DRIVER
#define I2C_POLLING_MODE_TIMEOUT		100
#endif

#ifndef ADXL_345_USE_ALTERNATE_ADDRESS
#define ADXL345_ADDRESS					0x1D								//! Device address

#endif

#ifdef ADXL_345_USE_ALTERNATE_ADDRESS
#define ADXL345_ADDRESS					0x53								//! Device address
#endif

#define ADXL345_ADDRESS_W				( ADXL345_ADDRESS << 1 )			//! Device address with write access
#define ADXL345_ADDRESS_R				( ( ADXL345_ADDRESS << 1 ) | 0x01)	//! Device address with read access

/*!
 * @brief 	Register addresses of ADXL345 and register access types
 * @details Register access types:
 * 					R: 0x01,	W: 0x02,	R/W: 0x03
 *
 */
#define ADXL345_REG_DEVID				0x00								//! Device ID
#define ADXL345_REG_DEVID_ACC			0x01								//! DEVID register access type
#define ADXL345_REG_THRESH_TAP			0x1D								//! Tap threshold
#define ADXL345_REG_THRESH_TAP_ACC		0x03								//! REG_THRESH_TAP register access type
#define ADXL345_REG_OFSX				0x1E								//! X-axis offset
#define ADXL345_REG_OFSX_ACC			0x03								//! OFSX register access type
#define ADXL345_REG_OFSY				0x1F								//! Y-axis offset
#define ADXL345_REG_OFSY_ACC			0x03								//! OFSY register access type
#define ADXL345_REG_OFSZ				0x20								//! Z-axis offset
#define ADXL345_REG_OFSZ_ACC			0x03								//! OFSZ register access type
#define ADXL345_REG_DUR					0x21								//! Tap duration
#define ADXL345_REG_DUR_ACC				0x03								//! DUR register access type
#define ADXL345_REG_LATENT				0x22								//! Tap latency
#define ADXL345_REG_LATENT_ACC			0x03								//! LATENT register access type
#define ADXL345_REG_WINDOW				0x23								//! Tap window
#define ADXL345_REG_WINDOW_ACC			0x03								//! WINDOW register access type
#define ADXL345_REG_THRESH_ACT			0x24								//! Activity threshold
#define ADXL345_REG_THRESH_ACT_ACC		0x03								//! THRESH_ACT register access type
#define ADXL345_REG_THRESH_INACT		0x25								//! Inactivity threshold
#define ADXL345_REG_THRESH_INACT_ACC	0x03								//! THRESH_INACT register access type
#define ADXL345_REG_TIME_INACT			0x26								//! Inactivity time
#define ADXL345_REG_TIME_INACT_ACC		0x03								//! TIME_INACT register access type
#define ADXL345_REG_ACT_INACT_CTL		0x27								//! Axis enable control for activity and inactivity detection
#define ADXL345_REG_ACT_INACT_CTL_ACC	0x03								//! ACT_INACT_CTL register access type
#define ADXL345_REG_THRESH_FF			0x28								//! Free-fall threshold
#define ADXL345_REG_THRESH_FF_ACC		0x03								//! THRESH_FF register access type
#define ADXL345_REG_TIME_FF				0x29								//! Free-fall time
#define ADXL345_REG_TIME_FF_ACC			0x03								//! TIME_FF register access type
#define ADXL345_REG_TAP_AXES			0x2A								//! Axis control for single tap/double tap
#define ADXL345_REG_TAP_AXES_ACC		0x03								//! TAP_AXES register access type
#define ADXL345_REG_ACT_TAP_STATUS		0x2B								//! Source of single tap/double tap
#define ADXL345_REG_ACT_TAP_STATUS_ACC	0x03								//! ACT_TAP_STATUS register access type
#define ADXL345_REG_BW_RATE				0x2C								//! Data rate and power mode control
#define ADXL345_REG_BW_RATE_ACC			0x03								//! BW_RATE register access type
#define ADXL345_REG_POWER_CTL			0x2D								//! Power-saving features control
#define ADXL345_REG_POWER_CTL_ACC		0x03								//! REG_POWER_CTL register access type
#define ADXL345_REG_INT_ENABLE			0x2E								//! Interrupt enable control
#define ADXL345_REG_INT_ENABLE_ACC		0x03								//! INT_ENABLE register access type
#define ADXL345_REG_INT_MAP				0x2F								//! Interrupt mapping control
#define ADXL345_REG_INT_MAP_ACC			0x03								//! REG_INT_MAP register access type
#define ADXL345_REG_INT_SOURCE			0x30								//! Source of interrupts
#define ADXL345_REG_INT_SOURCE_ACC		0x01								//! INT_SOURCE register access type
#define ADXL345_REG_DATA_FORMAT			0x31								//! Data format control
#define ADXL345_REG_DATA_FORMAT_ACC		0x03								//! DATA_FORMAT register access type
#define ADXL345_REG_DATAX0				0x32								//! X-Axis Data 0
#define ADXL345_REG_DATAX0_ACC			0x01								//! DATAX0 register access type
#define ADXL345_REG_DATAX1				0x33								//! X-Axis Data 1
#define ADXL345_REG_DATAX1_ACC			0x01								//! DATAX1 register access type
#define ADXL345_REG_DATAY0				0x34								//! Y-Axis Data 0
#define ADXL345_REG_DATAY0_ACC			0x01								//! DATAY0 register access type
#define ADXL345_REG_DATAY1				0x35								//! Y-Axis Data 1
#define ADXL345_REG_DATAY1_ACC			0x01								//! DATAY1 register access type
#define ADXL345_REG_DATAZ0				0x36								//! Z-Axis Data 0
#define ADXL345_REG_DATAZ0_ACC			0x01								//! DATAZ0 register access type
#define ADXL345_REG_DATAZ1				0x37								//! Z-Axis Data 1
#define ADXL345_REG_DATAZ1_ACC			0x01								//! DATAZ1 register access type
#define ADXL345_REG_FIFO_CTL			0x38								//! FIFO control
#define ADXL345_REG_FIFO_CTL_ACC		0x03								//! FIFO_CTL register access type
#define ADXL345_REG_FIFO_STATUS			0x39								//! FIFO status
#define ADXL345_REG_FIFO_STATUS_ACC		0x01								//! FIFO_STATUS register access type

/**
===================================== FUNCTION DECLARATIONS =====================================
 */

/*!
 * @brief	Gets i2c HAL handle to use inside this driver
 * @details	This functions is needs to be called first in order to use the i2c communication functions.
 *
 * @param i2c_handle_in Address of I2C_HandleTypeDef instance
 */
void set_i2c_handle (void *i2c_handle_in);

/*!
 * @brief	Writes single byte to the device
 *
 * @param reg_adr	Register address
 * @param data		8-bit data to written to the register of the given
 * @return			1 success, 0 fail
 */
uint8_t single_byte_write (uint8_t reg_adr, uint8_t data);

/*!
 * @brief	Writes multiple bytes to the device
 *
 * @param reg_adr	Register address
 * @param data		Pointer to the 8-bit data array
 * @param data_size	Amount of bytes to written to the register of the device
 * @return			1 success, 0 fail
 */
uint8_t multi_byte_write (uint8_t reg_adr, uint8_t* data, uint16_t data_size);

/*!
 * @brief	Reads single byte from device
 *
 * @param reg_adr	Register address
 * @param result	Pointer to the location that the reading is written
 * @return			1 success, 0 fail
 */
uint8_t single_byte_read (uint8_t reg_adr, uint8_t* result);

/*!
 * @brief	Reads multiple bytes from device
 *
 * @param reg_adr	Register address
 * @param result	Pointer to the location that the reading is written
 * @param data_size	Amount of bytes to be read from the register of the device
 * @return			1 success, 0 fail
 */
uint8_t multi_byte_read (uint8_t reg_adr, uint8_t* result, uint16_t data_size);

#ifdef __cplusplus
}
#endif

#endif /* _ADXL_345_ */
