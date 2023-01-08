#include "adxl345_driver.h"

/**
===================================== VARIABLES =====================================
 */

#ifdef ADXL_345_USE_HAL_DRIVER
I2C_HandleTypeDef *i2c_handle;		//! Handle to be used with HAL driver, internal linkage
#endif

/**
===================================== FUNCTION DEFINITIONS =====================================
 */

void set_i2c_handle (void* i2c_handle_in)
{
	i2c_handle = i2c_handle_in;
}

uint8_t single_byte_write (uint8_t reg_adr, uint8_t data)
{
	uint8_t *txData = (uint8_t*) malloc( 2 * sizeof (uint8_t) );
	txData[0] = reg_adr;
	txData[1] = data;

	HAL_StatusTypeDef hal_result =
			HAL_I2C_Master_Transmit(i2c_handle, ADXL345_ADDRESS_W, txData, 2, I2C_POLLING_MODE_TIMEOUT);

	return (hal_result == HAL_OK);
}

uint8_t multi_byte_write (uint8_t reg_adr, uint8_t* data, uint16_t data_size)
{
	// TODO implement the operations
	return 0;
}

uint8_t single_byte_read (uint8_t reg_adr, uint8_t* result)
{
	// TODO implement the operations
	return 0;
}

uint8_t multi_byte_read (uint8_t reg_adr, uint8_t* result, uint16_t data_size)
{
	// TODO implement the operations
	return 0;
}
