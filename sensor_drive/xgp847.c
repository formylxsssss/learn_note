#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "stm32f1xx_hal.h"
#include "i2c.h"
#include "SEGGER_RTT.h"
#include "xgp847.h"
uint8_t iic_xgp847_buffer[6];
/**
 * @brief  初始化xgp847传感器
 * @return int
 * @retval 0 成功
 * @retval -1 失败
 */
int iic_xgp847_init(void)
{
    HAL_StatusTypeDef init_status;
    init_status = HAL_I2C_Mem_Read(&hi2c1, XPG_847_ADDER, 0xA5, I2C_MEMADD_SIZE_8BIT, iic_xgp847_buffer, 1, sizeof(iic_xgp847_buffer) * 2);
    iic_xgp847_buffer[0] &= 0xfd;
    init_status = HAL_I2C_Mem_Write(&hi2c1, XPG_847_ADDER, 0xA5, I2C_MEMADD_SIZE_8BIT, iic_xgp847_buffer, 1, sizeof(iic_xgp847_buffer) * 2);
    iic_xgp847_buffer[0] = 0x0A;
    init_status = HAL_I2C_Mem_Write(&hi2c1, XPG_847_ADDER, 0x30, I2C_MEMADD_SIZE_8BIT, iic_xgp847_buffer, 1, sizeof(iic_xgp847_buffer) * 2);
    if (init_status == HAL_OK)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
/**
 * @brief  获取xgp847数据
 * 
 * @param data  获取的数据 为float型
 * @return int 
 * @retval 0 成功
 * @retval -1 失败
 */
int iic_xgp847_get_data(float *data)
{
    HAL_StatusTypeDef get_data_status;
    get_data_status = HAL_I2C_Mem_Read(&hi2c1, XPG_847_ADDER, 0x06, I2C_MEMADD_SIZE_8BIT, iic_xgp847_buffer, 3, sizeof(iic_xgp847_buffer) * 2);
    float xgp847_value;
    xgp847_value = iic_xgp847_buffer[0] * 65536 + iic_xgp847_buffer[1] * 256 + iic_xgp847_buffer[2];
    xgp847_value = (xgp847_value / 8388608) * 100;
    *data = xgp847_value;
    get_data_status = HAL_I2C_Mem_Write(&hi2c1, XPG_847_ADDER, 0x30, I2C_MEMADD_SIZE_8BIT, iic_xgp847_buffer, 1, sizeof(iic_xgp847_buffer) * 2);
    if (get_data_status == HAL_OK)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}